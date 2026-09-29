/*
 * FreeRTOSConfig.h — PY32L090 (Cortex-M0+, 72MHz, 256KB Flash / 32KB SRAM)
 * 配套：FreeRTOS Kernel V10.5.1
 *       编译器 AC5(armcc) → portable/RVDS/ARM_CM0
 *       编译器 AC6(armclang) → portable/GCC/ARM_CM0
 *       存储：D:\RTOS-Learn\01-FreeRTOS-Port\PY32L090_FreeRTOS\Config\FreeRTOSConfig.h
 *
 * 本文件里的每一个取值都对应手册《阶段1-FreeRTOS移植手册》§4 的说明，
 * 改任何一项前先回去看那一节的原因。
 */
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*===========================================================================
 * §1 时钟与节拍 —— 与 system_py32l090.c 的 72MHz 严格一致
 *=========================================================================*/
#define configCPU_CLOCK_HZ                  ( 72000000UL )
#define configSYSTICK_CLOCK_HZ              ( configCPU_CLOCK_HZ )  /* SysTick 用内核时钟，1:1 不分频 */
#define configTICK_RATE_HZ                  ( 1000 )                /* 1ms 一个节拍(1000Hz) */

/* ★★★ 开工前第一件事：把这个数字和你板子的真实主频对齐 ★★★
 *
 * 实测：Puya 官方 LL 模板的 APP_SystemClockConfig() 是
 *         LL_RCC_HSI_SetCalibFreq(LL_RCC_HSICALIBRATION_8MHz);
 *         LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSISYS);
 *         LL_SetSystemCoreClock(8000000);        ← 8MHz，HSI 直出，没开 PLL！
 *       而你自己的产品工程（WX_LowCost / 燃气报警器）是 72MHz（pll.c）。
 *
 * 这个数写错的后果：不是死机，是时间整体错 9 倍 —— 72MHz 的板子用 8MHz 配置，
 * 节拍会变成 9kHz，vTaskDelay(1000) 只等约 111ms。
 *
 * 对齐方法（二选一）：
 *   A) 用你现有工程的时钟配置（MCUPllCfg / Init_SysClk_Gen(1,72) + pll.c），
 *      主频 72MHz → 这里保持 72000000UL（默认值，推荐）
 *   B) 直接照官方 LL 模板建工程（HSI 8MHz）→ 把这里改成 8000000UL
 * 验证：调试器 Watch 窗口加 SystemCoreClock，它的值必须等于 configCPU_CLOCK_HZ。
 */

/*===========================================================================
 * §2 中断向量映射 —— ★CM0 端口必须手工挂钩，写错了会"编译过但一启动就死"
 *=========================================================================*/
/* FreeRTOS 的 PendSV / SysTick 服务函数，在 port.c 里叫 xPortPendSVHandler / xPortSysTickHandler。
   必须在这里把它们改名成 PY32L090 启动文件里的标准向量名（大小写必须一字不差）。 */
#define xPortPendSVHandler                  PendSV_Handler
#define xPortSysTickHandler                 SysTick_Handler

/* ★ 不要定义 vPortSVCHandler 映射：Cortex-M0+ 端口不使用 SVC，
   而 py32l090_it.c 里已经有一个空的 SVC_Handler，定义映射会撞符号(L6200E)。 */

/*===========================================================================
 * §3 调度器行为
 *=========================================================================*/
#define configUSE_PREEMPTION                       1   /* 抢占式调度 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION    0   /* ★CM0 没有 CLZ 指令，必须 0 */
#define configUSE_TICKLESS_IDLE                    0   /* ★阶段4 改 1（进 STOP 省电），现在先不要开 */
#define configUSE_IDLE_HOOK                        1
#define configUSE_TICK_HOOK                        1
#define configUSE_TIME_SLICING                     1   /* 同优先级任务轮转 */
#define configUSE_NEWLIB_REENTRANT                 0
#define configUSE_TASK_NOTIFICATIONS               1   /* 比信号量更省 RAM，优先用它 */
#define configMAX_PRIORITIES                       ( 8 )   /* 软件优先级，CM0 的 4 级硬件优先级只管中断，不管任务 */
#define configMAX_TASK_NAME_LEN                    ( 12 )  /* 只为调试用，短一点省 RAM */
#define configMINIMAL_STACK_SIZE                   ( 128 ) /* ★必定义：空闲任务栈，单位=字(128 字=512 字节) */
#define configUSE_16_BIT_TICKS                     0   /* 32 位节拍计数，不会溢出错乱 */
#define configIDLE_SHOULD_YIELD                    1
#define configUSE_MUTEXES                          1
#define configUSE_RECURSIVE_MUTEXES                1
#define configUSE_COUNTING_SEMAPHORES              1
#define configQUEUE_REGISTRY_SIZE                  8   /* Keil 的 RTOS 调试视图能显示队列/信号量 */
#define configUSE_QUEUE_SETS                       0
#define configUSE_TASK_FPU_SUPPORT                 0   /* CM0+ 无 FPU */

/*===========================================================================
 * §4 内存管理 —— heap_4 (带碎片合并)，堆在 .bss 里静态占 8KB
 *=========================================================================*/
#define configSUPPORT_STATIC_ALLOCATION            0
#define configSUPPORT_DYNAMIC_ALLOCATION           1
#define configTOTAL_HEAP_SIZE                      ( ( size_t ) ( 8 * 1024 ) )   /* ★32KB SRAM 的预算见手册 §4.4 */
#define configAPPLICATION_ALLOCATED_HEAP           0

/*===========================================================================
 * §5 断言与钩子 —— 调试期全部打开，跑通后再按需关
 *=========================================================================*/
#define configUSE_MALLOC_FAILED_HOOK               1
#define configCHECK_FOR_STACK_OVERFLOW             2   /* 2=哨兵值法，比 1 可靠。任务栈尾被改写就能抓到 */
#define configASSERT( x )                          \
    if( ( x ) == 0 ) { vApplicationAssertFailure( __FILE__, __LINE__ ); }
extern void vApplicationAssertFailure( const char * pcFile, unsigned long ulLine );

/*===========================================================================
 * §6 API 裁剪 —— 只开你真正用的，省 Flash（256KB 够用，但习惯要好）
 *=========================================================================*/
#define INCLUDE_vTaskPrioritySet                   1
#define INCLUDE_uxTaskPriorityGet                  1
#define INCLUDE_vTaskDelete                        1
#define INCLUDE_vTaskSuspend                       1
#define INCLUDE_xTaskDelayUntil                    1   /* V10.5.1 的新名字(vTaskDelayUntil 的开关) */
#define INCLUDE_vTaskDelay                         1
#define INCLUDE_xTaskGetSchedulerState             1
#define INCLUDE_xTaskGetCurrentTaskHandle          1
#define INCLUDE_xTaskGetIdleTaskHandle             1
#define INCLUDE_uxTaskGetStackHighWaterMark        1   /* ★调栈大小全靠它 */
#define INCLUDE_eTaskGetState                      1
#define INCLUDE_pcTaskGetTaskName                  1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle     1
#define INCLUDE_xTaskAbortDelay                    1
#define INCLUDE_xQueueGetMutexHolder               1
#define INCLUDE_xSemaphoreGetMutexHolder           1

/*===========================================================================
 * §7 软件定时器 —— 阶段1 先关（省 1 个任务栈 + 队列）
 *     要用：把 configUSE_TIMERS 改 1，并把 timers.c 加进 Keil 工程
 *=========================================================================*/
#define configUSE_TIMERS                           0
#define configTIMER_TASK_PRIORITY                  ( 2 )
#define configTIMER_QUEUE_LENGTH                   10
#define configTIMER_TASK_STACK_DEPTH               ( 128 )   /* 单位：字(4字节)，=512 字节 */

/*===========================================================================
 * §8 运行统计（可视化调试用；run time stats 需要额外一个定时器，阶段3 再说）
 *=========================================================================*/
#define configUSE_TRACE_FACILITY                   1   /* vTaskList / vTaskGetRunTimeStats 的前提 */
#define configUSE_STATS_FORMATTING_FUNCTIONS       1   /* 同上，配合上面那个才有用 */
#define configGENERATE_RUN_TIME_STATS              0

/*===========================================================================
 * §9 CM0 (ARMv6-M) 上"配了也白配"的宏 —— 保留注释，防止照抄 M3/M4 教程
 *=========================================================================*/
/* #define configKERNEL_INTERRUPT_PRIORITY        ← CM0 端口把内核优先级硬编码为最低，此宏不参与运算 */
/* #define configMAX_SYSCALL_INTERRUPT_PRIORITY   ← CM0 无 BASEPRI 寄存器，此宏不参与运算、
                                                   FreeRTOS 也不会用它做任何检查 */
/* #define configPRIO_BITS                        ← 只有 M3/M4 端口用它算优先级，CM0 不用 */

#endif /* FREERTOS_CONFIG_H */
