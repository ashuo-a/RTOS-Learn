/**
 * main_freertos_demo.c — 阶段1 第一个可跑的 FreeRTOS 工程（PY32L090 / CM0+ / 72MHz）
 *
 * 位置：D:\RTOS-Learn\01-FreeRTOS-Port\PY32L090_FreeRTOS\Config\main_freertos_demo.c
 *
 * 验收目标（见手册 §8）：
 *   1) 两个 LED 任务以各自周期独立闪烁，互不干扰、周期不漂移
 *   2) 串口每 2 秒打印一次任务状态表 + 堆余量 + 栈水位
 *   3) 第 10 秒时动态创建一个新任务，证明运行期调度器还活着
 *
 * ★ 这不是让你照抄替换你的 main.c，而是把"裸机 super-loop 变成任务"的
 *   标准骨架摆出来。你现有工程的初始化代码（时钟、GPIO、串口、传感器）
 *   原样保留，只需把大 while(1) 里的活拆成任务。
 */
#include "FreeRTOS.h"
#include "task.h"

/* ★ 改成你工程/板级的头文件（LED 宏、时钟函数声明等） */
#include "py32l090_hal.h"

extern void RTOS_PrintTaskList( void );
extern void RTOS_PrintStackWaterMark( void );

/* 你的工程里已有的打印函数（见 app_rtos_hooks.c 的同名声明） */
extern void Debug_Printf( const char * fmt, ... );

/* ==========================================================================
 * 任务 1：LED1 —— 500ms 周期翻转
 *   注意 vTaskDelay(pdMS_TO_TICKS(500)) 与裸机 LL_mDelay(500) 的本质区别：
 *   前者把 CPU 让出去（任务进入阻塞态，其他任务立刻能跑），
 *   后者是死等（CPU 空转，还会依赖 SysTick，在 RTOS 下已经不可靠）。
 * ==========================================================================*/
static void vLed1Task( void * pvParameters )
{
    ( void ) pvParameters;

    for( ;; )
    {
        LL_GPIO_TogglePin( LED1_GPIO_Port, LED1_Pin );

        /* 启动 LED 亮灭：TaskNum 无关，模板里默认关闭，按需打开 */
        Debug_Printf( "[led1] toggle @%u ms\r\n", ( unsigned int ) xTaskGetTickCount() );

        vTaskDelay( pdMS_TO_TICKS( 500 ) );
    }
}

/* ==========================================================================
 * 任务 2：LED2 —— 300ms 周期翻转
 *   和 LED1 同一优先级(1)，靠时间片轮转 + 各自的阻塞周期天然错开，
 *   这就是 RTOS 相对裸机"软件定时器排队"的直观好处。
 * ==========================================================================*/
static void vLed2Task( void * pvParameters )
{
    ( void ) pvParameters;

    for( ;; )
    {
        LL_GPIO_TogglePin( LED2_GPIO_Port, LED2_Pin );
        vTaskDelay( pdMS_TO_TICKS( 300 ) );
    }
}

/* ==========================================================================
 * 任务 3：监控 —— 每 2 秒打印一次系统状态（调栈大小的唯一依据）
 *   优先级最低(1 里再低一档就设 0，但 0 会被空闲任务挤)，这里给 1。
 * ==========================================================================*/
static void vMonitorTask( void * pvParameters )
{
    ( void ) pvParameters;

    for( ;; )
    {
        RTOS_PrintStackWaterMark();   /* 堆余量 + 本任务栈水位 */
        RTOS_PrintTaskList();         /* 全任务状态表 */

        vTaskDelay( pdMS_TO_TICKS( 2000 ) );
    }
}

/* ==========================================================================
 * 任务 4：演示"运行期动态创建任务"——裸机做不到的事
 * ==========================================================================*/
static TaskHandle_t xBornTask = NULL;

static void vNewBornTask( void * pvParameters )
{
    ( void ) pvParameters;

    Debug_Printf( "[born] 我是启动后动态创建的任务，说明调度器一直在跑\r\n" );

    for( ;; )
    {
        Debug_Printf( "[born] beat @%u ms\r\n", ( unsigned int ) xTaskGetTickCount() );
        vTaskDelay( pdMS_TO_TICKS( 3000 ) );
    }
}

static void vBirthTask( void * pvParameters )
{
    ( void ) pvParameters;

    vTaskDelay( pdMS_TO_TICKS( 10000 ) );   /* 等 10 秒 */

    Debug_Printf( "[birth] heap free before create = %u\r\n",
                  ( unsigned int ) xPortGetFreeHeapSize() );

    if( xTaskCreate( vNewBornTask,                    /* 任务函数   */
                     "born",                          /* 任务名     */
                     128,                             /* 栈：128 字 = 512 字节 */
                     NULL,                            /* 参数       */
                     1,                               /* 优先级     */
                     &xBornTask ) != pdPASS )
    {
        Debug_Printf( "[birth] xTaskCreate 失败（堆不够或参数错）\r\n" );
    }

    vTaskDelete( NULL );    /* 我自己的活儿干完了，删掉自己，顺便验证 vTaskDelete */
}

/* ==========================================================================
 * 主函数
 * ==========================================================================*/
int main( void )
{
    /*--------------------------------------------------------------
     * 第 1 步：时钟初始化 —— ★保持你现有工程的做法不动
     *   裸机工程一般是：启动文件调 SystemInit() → main 里配 PLL 到 72MHz。
     *   只要最终 SystemCoreClock == 72000000，就和 configCPU_CLOCK_HZ 对上了。
     *   ★ 千万不要在这里调 LL_Init1msTick()，见手册 §5。
     *-------------------------------------------------------------*/
    MCUPllCfg();                 /* ★ 换成你工程实际的时钟配置函数名 */

    /*--------------------------------------------------------------
     * 第 2 步：板级外设初始化（GPIO/UART/传感器……）—— 照旧
     *   唯一纪律：初始化顺序上排在 vTaskStartScheduler() 之前。
     *-------------------------------------------------------------*/
    BOARD_LED_Init();            /* ★ 换成你工程实际的 LED 初始化 */
    Debug_Uart_Init();           /* ★ 换成你工程实际的串口初始化 */

    Debug_Printf( "\r\n===== FreeRTOS %s on PY32L090 @ 72MHz =====\r\n",
                  tskKERNEL_VERSION_NUMBER );
    Debug_Printf( "heap total = %u bytes\r\n", ( unsigned int ) configTOTAL_HEAP_SIZE );

    /*--------------------------------------------------------------
     * 第 3 步：创建任务 —— ★必须在 vTaskStartScheduler() 之前
     *   栈大小单位是"字"(word=4字节)！128 就是 512 字节，这是新手最常错的地方。
     *-------------------------------------------------------------*/
    xTaskCreate( vLed1Task,    "led1",    128, NULL, 1, NULL );   /* 512B  */
    xTaskCreate( vLed2Task,    "led2",    128, NULL, 1, NULL );
    xTaskCreate( vMonitorTask, "monitor", 256, NULL, 1, NULL );   /* 256字=1KB，因为要调 vTaskList+打印 */
    xTaskCreate( vBirthTask,   "birth",   128, NULL, 1, NULL );

    Debug_Printf( "tasks created, starting scheduler...\r\n\r\n" );

    /*--------------------------------------------------------------
     * 第 4 步：启动调度器
     *   ★这个函数正常情况下【永不返回】。它内部会：
     *     - 创建空闲任务（用 configMINIMAL_STACK_SIZE）
     *     - 接管 SysTick（此时才第一次配置 SysTick 的 LOAD/优先级）
     *     - 把 PendSV/SysTick 优先级设为最低
     *     - 启动第一个任务
     *   如果它返回了 = 堆太小导致空闲任务创建失败，下面这句就是证据。
     *-------------------------------------------------------------*/
    vTaskStartScheduler();

    Debug_Printf( "[FATAL] 调度器竟然返回了！检查 configTOTAL_HEAP_SIZE 是否够创建空闲任务\r\n" );

    for( ;; )
    {
    }
}
