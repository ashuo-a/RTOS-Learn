/**
 * app_rtos_hooks.c — FreeRTOS 应用层钩子 + 调试辅助（PY32L090 / CM0+）
 *
 * 位置：D:\RTOS-Learn\01-FreeRTOS-Port\PY32L090_FreeRTOS\Config\app_rtos_hooks.c
 *
 * 为什么必须自己实现这些函数？
 *   FreeRTOSConfig.h 里把 configUSE_MALLOC_FAILED_HOOK=1、
 *   configCHECK_FOR_STACK_OVERFLOW=2、configUSE_IDLE_HOOK=1、
 *   configUSE_TICK_HOOK=1 打开了，内核就会去调用下面这些函数名。
 *   你不实现 → 链接期报 L6218E: Undefined symbol vApplicationStackOverflowHook。
 *   这不是"可选增强"，是移植必做的最后一块拼图。
 */
#include "FreeRTOS.h"
#include "task.h"

/*===========================================================================
 * ★ 修改点（唯一一处）：接上你工程自己的串口打印
 *   PY32L090 的 LL 模板没有 printf 重定向，请换成你项目里现成的打印函数，
 *   例如 Debug_Printf / Uart1_SendString / fputc 重定向后的 printf。
 *   如果你现在还没有串口打印：把下面两行注释掉，并把 APP_LOG(...) 定义为空
 *   即  #define APP_LOG(...)   —— 钩子里改成点灯/死循环一样能定位问题。
 *=========================================================================*/
extern void Debug_Printf( const char * fmt, ... );
#define APP_LOG( ... )      Debug_Printf( __VA_ARGS__ )

/* vTaskList 的输出缓冲：静态数组，不占 FreeRTOS 堆。
   估算：任务数 × (configMAX_TASK_NAME_LEN + 约 28 字节) */
static char pcTaskStatsBuf[512];

/*===========================================================================
 * 钩子 1：断言失败
 *   内核里凡是有 configASSERT(xxx) 的地方，条件不成立就跳到这里。
 *   典型触发：往已满的队列写、用 NULL 句柄调 API、临界区嵌套计数错乱。
 *=========================================================================*/
void vApplicationAssertFailure( const char * pcFile, unsigned long ulLine )
{
    APP_LOG( "\r\n[ASSERT FAIL] %s : line %lu\r\n", pcFile, ulLine );

    /* 调试期：断在这里，用 Keil 的 Call Stack 看是谁把参数传错的。
       量产期：把下面的 while(1) 换成 NVIC_SystemReset(); 让它自己复位。 */
    portDISABLE_INTERRUPTS();
    for( ;; )
    {
    }
}

/*===========================================================================
 * 钩子 2：任务栈溢出
 *   configCHECK_FOR_STACK_OVERFLOW=2 会在切换任务时检查栈尾哨兵值，
 *   被改写就说明某个任务的栈给小了 —— 这里打印出是哪个任务，然后回去加大它。
 *=========================================================================*/
void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName )
{
    ( void ) xTask;
    APP_LOG( "\r\n[STACK OVERFLOW] task = %s\r\n", pcTaskName );

    portDISABLE_INTERRUPTS();
    for( ;; )
    {
    }
}

/*===========================================================================
 * 钩子 3：堆耗尽（pvPortMalloc 返回 NULL）
 *   说明 configTOTAL_HEAP_SIZE 给小了，或者你有内存泄漏（创建了任务/队列从不删）。
 *=========================================================================*/
void vApplicationMallocFailedHook( void )
{
    APP_LOG( "\r\n[MALLOC FAILED] free heap = %u bytes\r\n",
             ( unsigned int ) xPortGetFreeHeapSize() );

    portDISABLE_INTERRUPTS();
    for( ;; )
    {
    }
}

/*===========================================================================
 * 钩子 4：空闲任务钩子
 *   空闲任务在所有任务都阻塞时才跑。★这里绝对不能写 vTaskDelay / 阻塞调用，
 *   空闲任务是优先级最低的"兜底"，让它长时间不返回会饿死其他任务的清理工作。
 *   阶段4（tickless + STOP）会在这里下功夫，阶段1 保持轻量。
 *=========================================================================*/
void vApplicationIdleHook( void )
{
    /* 想做"空闲时统计"就放这里。留空也完全正确。 */
}

/*===========================================================================
 * 钩子 5：节拍钩子（在 SysTick 中断里被调用！）
 *   ★这是中断上下文：不能阻塞、不能调非 FromISR 的 API、printf 也要极短。
 *=========================================================================*/
void vApplicationTickHook( void )
{
    /* 留空。 */
}

/*===========================================================================
 * 工具：打印任务状态表 —— 阶段1 验收和后期调优的第一利器
 *   输出列：Name / State / Priority / Stack(剩余字) / Num
 *   Stack 列是"历史最小剩余"，越接近 0 说明栈给得越危险。
 *=========================================================================*/
void RTOS_PrintTaskList( void )
{
    vTaskList( pcTaskStatsBuf );
    APP_LOG( "\r\nTask            State  Prio  Stack  Num\r\n%s\r\n", pcTaskStatsBuf );
}

/*===========================================================================
 * 工具：打印堆的当前/历史最小值 + 各任务栈水位
 *=========================================================================*/
void RTOS_PrintStackWaterMark( void )
{
    APP_LOG( "\r\n--- heap: free=%u, minEver=%u ---\r\n",
             ( unsigned int ) xPortGetFreeHeapSize(),
             ( unsigned int ) xPortGetMinimumEverFreeHeapSize() );
    APP_LOG( "task=%s  minFreeStack=%u words\r\n",
             pcTaskGetName( NULL ),
             ( unsigned int ) uxTaskGetStackHighWaterMark( NULL ) );
}
