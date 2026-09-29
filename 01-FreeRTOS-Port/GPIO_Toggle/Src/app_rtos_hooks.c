/**
 * app_rtos_hooks.c — FreeRTOS 钩子实现 + 调试打印（PY32C882xC / CM0+ / HSI 8MHz）
 * 工程：D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\Src\app_rtos_hooks.c
 *
 * 为什么要这个文件？
 *   FreeRTOSConfig.h 里开了 configCHECK_FOR_STACK_OVERFLOW / configUSE_MALLOC_FAILED_HOOK /
 *   configASSERT / configUSE_IDLE_HOOK / configUSE_TICK_HOOK —— 内核会去调用对应的
 *   vApplicationXxx 函数，不实现就链接报 L6218E: Undefined symbol。
 */

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "py32c882xx_Start_Kit.h"
#include <stdio.h>

/* vTaskList 的输出缓冲：静态分配（不占 FreeRTOS 堆）。
   每行约 40 字符，8 个任务约 350 字节，600 足够。 */
static char pcTaskListBuf[600];

/*===========================================================================
 * 1) ★★ 关键整合点：HAL 时基的交接
 *
 * 裸机时 HAL_IncTick() 在 Src\py32c882_it.c 的 SysTick_Handler 里被调用。
 * 现在 SysTick 变成了 FreeRTOS 的节拍中断（xPortSysTickHandler），it.c 里那个
 * 函数已经注释掉 —— 如果不在这里补上 HAL_IncTick()，则：
 *     HAL_GetTick() 永远返回 0  →  HAL_Delay() 死等不返回、
 *     HAL_UART_Transmit(..., timeout) 永远超时、HAL 那些基于 tick 的超时全废。
 * 放在 vApplicationTickHook() 里（configUSE_TICK_HOOK=1 时由 xPortSysTickHandler 调用）
 * 是最干净的做法：HAL 时基与 RTOS 节拍同源，永远同步。
 *=========================================================================*/
void vApplicationTickHook(void)
{
    HAL_IncTick();
}

/*===========================================================================
 * 2) 空闲钩子：所有任务都阻塞时才会执行
 *    ★禁止阻塞、禁止 vTaskDelay、禁止长打印（否则会把空闲任务拖住）
 *=========================================================================*/
void vApplicationIdleHook(void)
{
    /* 阶段4 的低功耗(STOP)入口就放这里；现在留空 */
}

/*===========================================================================
 * 3) 断言失败 / 栈溢出 / 堆耗尽：一律"停住 + 报出原因"，不要静默跑飞
 *=========================================================================*/
void vApplicationAssertFailure(const char *pcFile, unsigned long ulLine)
{
    printf("\r\n[ASSERT FAILED] %s : %lu\r\n", pcFile, ulLine);
    __disable_irq();
    for (;;)
    {
    }
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)xTask;
    printf("\r\n[STACK OVERFLOW] task = %s\r\n", pcTaskName);
    printf("  -> 把这个任务的 xTaskCreate() 栈参数(单位=字)加大\r\n");
    __disable_irq();
    for (;;)
    {
    }
}

void vApplicationMallocFailedHook(void)
{
    printf("\r\n[MALLOC FAILED] freeHeap = %u B\r\n", (unsigned)xPortGetFreeHeapSize());
    printf("  -> 加大 configTOTAL_HEAP_SIZE\r\n");
    __disable_irq();
    for (;;)
    {
    }
}

/*===========================================================================
 * 4) 调试辅助：任务表与内存水位
 *=========================================================================*/
void RTOS_PrintTaskList(void)
{
    /* 表头：Name=任务名 State=状态(X就绪/B阻塞/R就绪/S挂起/D已删) Prio=优先级 Stack=栈剩余(字) Num=编号 */
    printf("Name          State Prio  Stack  Num\r\n");
    vTaskList(pcTaskListBuf);          /* 需要 configUSE_TRACE_FACILITY=1 + configUSE_STATS_FORMATTING_FUNCTIONS=1 */
    printf("%s", pcTaskListBuf);       /* ★注意：只能在同一个任务里打印，printf 不可重入 */
}

void RTOS_PrintHeapInfo(void)
{
    printf("FreeRTOS heap: free = %u B, minEverFree = %u B, total = %u B\r\n",
           (unsigned)xPortGetFreeHeapSize(),
           (unsigned)xPortGetMinimumEverFreeHeapSize(),
           (unsigned)configTOTAL_HEAP_SIZE);
}
