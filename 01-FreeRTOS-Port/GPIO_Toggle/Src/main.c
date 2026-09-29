/**
 * main.c — 阶段1 实战：GPIO_Toggle 裸机例程 → FreeRTOS 多任务工程
 * 工程：D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\Src\main.c
 * 芯片：PY32C882xC (Cortex-M0+, HSI 8MHz, 256KB Flash / 32KB SRAM)
 *
 * 与原始裸机版本的对照（原版：while(1){ HAL_Delay(250); 翻转LED; }）
 *   原版                                  →  本版本
 *   ─────────────────────────────────────────────────────────────
 *   HAL_Delay(250) 死等占满 CPU           →  vTaskDelayUntil 阻塞让出 CPU
 *   SysTick_Handler 里调 HAL_IncTick()    →  vApplicationTickHook() 里调 HAL_IncTick()
 *   主循环里翻转 LED                      →  App_LedTask 任务（周期仍为 250ms = 2Hz，行为不变）
 *   没有任何观测手段                      →  App_LogTask 任务：串口 1s 打状态、5s 打任务表
 *
 * 验收：串口 115200 应能看到任务表，且 LED 仍以 2Hz 闪烁（与裸机版肉眼一致）。
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

/* 来自 Src\app_rtos_hooks.c 的调试接口 -------------------------------------*/
extern void RTOS_PrintTaskList(void);
extern void RTOS_PrintHeapInfo(void);

/* Private define ------------------------------------------------------------*/
#define LED_TASK_STACK        128U      /* 单位=字(word=4B) → 512 字节 */
#define LED_TASK_PRIORITY     2U        /* 数值越大优先级越高 */
#define LED_TOGGLE_MS         250U      /*250ms 翻转 = 2Hz */

#define LOG_TASK_STACK        256U      /* 含 printf，给足：1KB */
#define LOG_TASK_PRIORITY     1U
#define LOG_PERIOD_MS         1000U
#define TASKLIST_EVERY_N      5U        /* 每 5 次日志打一次任务表(=5s) */

/* Private variables ---------------------------------------------------------*/
static TaskHandle_t xLedTaskHandle = NULL;

/* Private function prototypes -----------------------------------------------*/
static void App_LedTask(void *argument);
static void App_LogTask(void *argument);

/**
  * @brief  Main program.
  * @retval int
  */
int main(void)
{
    BaseType_t xRet;

    /* ① HAL 初始化：内部会把 SysTick 配成 1ms（TICK_INT_PRIORITY = PRIORITY_LOWEST，
        与 FreeRTOS 内核异常要用的最低优先级一致）。此时还没启动调度器，
        随后 vTaskStartScheduler() 会用 configSYSTICK_CLOCK_HZ/configTICK_RATE_HZ 重新配置 SysTick，
        两者都是 1ms，所以 HAL 时基和 RTOS 节拍天然对齐。 */
    HAL_Init();

    /* ② 板级外设：LED(GPIOA PIN2) 与调试串口(UART1, PB9=TX/PB8=RX, 115200-8-N-1)
        BSP_UART_Config() 里已经做了 fputc 重定向 → 下面可以直接用 printf */
    BSP_LED_Init(LED3);
    BSP_UART_Config();

    printf("\r\n\r\n================ PY32C882xC + FreeRTOS V10.5.1 ================\r\n");
    printf("SystemCoreClock = %u Hz  (configCPU_CLOCK_HZ = %u Hz)\r\n",
        (unsigned)SystemCoreClock, (unsigned)configCPU_CLOCK_HZ);
    printf("闪灯周期 %u ms，日志周期 %u ms\r\n\r\n",
        (unsigned)LED_TOGGLE_MS, (unsigned)LOG_PERIOD_MS);

    /* ③ 创建任务（必须在启动调度器之前） */
    xRet = xTaskCreate(App_LedTask, "led", LED_TASK_STACK, NULL,
                    LED_TASK_PRIORITY, &xLedTaskHandle);
    if (xRet != pdPASS)
    {
        printf("[ERROR] xTaskCreate(led) 失败\r\n");
        APP_ErrorHandler();
    }

    xRet = xTaskCreate(App_LogTask, "log", LOG_TASK_STACK, NULL,
                    LOG_TASK_PRIORITY, NULL);
    if (xRet != pdPASS)
    {
        printf("[ERROR] xTaskCreate(log) 失败\r\n");
        APP_ErrorHandler();
    }

    /* ④ 启动调度器：永不返回。若返回，说明堆不够、连空闲任务都没建起来 */
    vTaskStartScheduler();

    printf("[FATAL] vTaskStartScheduler() 返回了 → 检查 configTOTAL_HEAP_SIZE\r\n");
    APP_ErrorHandler();

    return 0;
}

/**
  * @brief  LED 任务：每 250ms 翻转一次 LED3（行为与裸机版一致）
  * @note   用 vTaskDelayUntil 而非 vTaskDelay —— 前者以上次唤醒时刻为基准，
  *         不会累积漂移；周期任务一律用这个。
  */
static void App_LedTask(void *argument)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();

    (void)argument;

    for (;;)
    {
        BSP_LED_Toggle(LED3);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(LED_TOGGLE_MS));
    }
}

/**
  * @brief  日志任务：每秒打印系统状态；每 5 秒打印一次任务表
  * @note   所有 printf 都集中在这一个任务里 —— 多任务同时 printf 会串行错乱（不可重入）。
  */
static void App_LogTask(void *argument)
{
    uint32_t ulCount = 0U;

    (void)argument;

    for (;;)
    {
        ulCount++;

        printf("[t=%ums] tasks=%u freeHeap=%uB ledStackMinFree=%u words\r\n",
            (unsigned)xTaskGetTickCount(),
            (unsigned)uxTaskGetNumberOfTasks(),
            (unsigned)xPortGetFreeHeapSize(),
            (unsigned)uxTaskGetStackHighWaterMark(xLedTaskHandle));

        if ((ulCount % TASKLIST_EVERY_N) == 0U)
        {
            RTOS_PrintTaskList();
            RTOS_PrintHeapInfo();
        }

        vTaskDelay(pdMS_TO_TICKS(LOG_PERIOD_MS));
    }
}

/**
  * @brief  Error executing function.
  * @param  None
  * @retval None
  */
void APP_ErrorHandler(void)
{
    for (;;)
    {
    }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    printf("[HAL ASSERT] file %s line %u\r\n", (char *)file, (unsigned)line);
    for (;;)
    {
    }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
