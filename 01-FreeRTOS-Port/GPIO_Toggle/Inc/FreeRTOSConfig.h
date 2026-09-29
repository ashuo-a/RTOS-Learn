/*
 * FreeRTOSConfig.h — PY32C882xC (Cortex-M0+, HSI 8MHz, 256KB Flash / 32KB SRAM)
 * 工程：D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle （原官方 GPIO_Toggle 裸机例程 + FreeRTOS）
 * 内核：FreeRTOS Kernel V10.5.1
 * 端口：portable\RVDS\ARM_CM0  ← 本工程用 AC5(V5.06 update 7)，必须选 RVDS 而非 GCC
 *       （AC6/armclang 才用 portable\GCC\ARM_CM0；RVDS 端口里的 __asm void 是 AC5 专有语法）
 *
 * ★★ 主频：本工程的 system_py32c882.c 里 SystemCoreClock = HSI_VALUE = 8000000，
 *    main() 也没有任何 PLL 配置 → 板子实际跑 8MHz，所以这里必须是 8000000UL。
 *    要升到 72MHz（像 WX_LowCost 产品那样）时：加 PLL 配置 + 把这里改成 72000000UL，
 *    并确认调试器里 SystemCoreClock == configCPU_CLOCK_HZ，否则所有延时按比例错。
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*===========================================================================
 * §1 时钟与节拍
 *=========================================================================*/
#define configCPU_CLOCK_HZ                  ( 8000000UL )   /* ★ = SystemCoreClock */
#define configSYSTICK_CLOCK_HZ              ( configCPU_CLOCK_HZ )  /* SysTick 用内核时钟，不分频 */
#define configTICK_RATE_HZ                  ( 1000 )        /* 1ms 一个节拍 → SysTick->LOAD 应为 7999 */

/*===========================================================================
 * §2 中断向量映射 —— ★CM0 端口必须手工挂钩（写错会"编译过但一启动就崩"）
 *=========================================================================*/
/* 把 FreeRTOS 的异常处理函数挂到 PY32C882 启动文件里的标准向量名上。
   同时必须把 Src\py32c882_it.c 里的空 PendSV_Handler/SysTick_Handler 注释掉，
   否则链接报 L6200E: Symbol multiply defined。 */
#define xPortPendSVHandler                  PendSV_Handler

/* ★★ xPortSysTickHandler 故意【不】映射到 SysTick_Handler（2026-09-24 实测 HardFault 根因）
 *
 * 为什么：HAL_Init() 会立刻打开 SysTick 并使能其中断；而在 vTaskStartScheduler()
 *   真正执行到之前，FreeRTOS 里 xNextTaskUnblockTime 还是 0（tasks.c:370 的初值，
 *   到 vTaskStartScheduler() 里（tasks.c:2036）才被改成 portMAX_DELAY）、
 *   pxDelayedTaskList 还是 NULL。这期间只要 SysTick 中断进来（main 里一行 printf
 *   就要 5~7ms，单步调试一步就超 1ms），就会走进 xTaskIncrementTick()：
 *        xConstTickCount = 0 + 1 = 1;  if( 1 >= xNextTaskUnblockTime(0) ) 成立
 *        → listLIST_IS_EMPTY( pxDelayedTaskList )   ← pxDelayedTaskList == NULL
 *        → HardFault
 *
 * 解决：这里不映射，port.c 就保留函数原名 xPortSysTickHandler，
 *   改由 Src\py32c882_it.c 的 SysTick_Handler 分派：
 *     调度器未启动 → HAL_IncTick()；已启动 → xPortSysTickHandler()。
 */
/* #define xPortSysTickHandler              SysTick_Handler */
/* ★故意不定义 vPortSVCHandler 映射：CM0 端口不使用 SVC 指令（启动第一个任务走
   prvPortStartFirstTask，纯软件设置 PSP/CONTROL 后 bx 跳转），把 it.c 里的空
   SVC_Handler 留着正好，也不会撞符号。 */

/*===========================================================================
 * §3 调度器行为
 *=========================================================================*/
#define configUSE_PREEMPTION                      1   /* 1=抢占式调度，0=协作式调度 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION   0   /* ★CM0 无 CLZ 指令，必须 0 */
#define configUSE_TICKLESS_IDLE                   0   /* 阶段4 做 STOP 低功耗时再改 1 */
#define configUSE_IDLE_HOOK                       1   /* ★必须 1：空闲任务里做低功耗，见 app_rtos_hooks.c */
#define configUSE_TICK_HOOK                       1   /* ★必须 1：HAL_IncTick() 挂在里面保活 HAL 时基 */
#define configUSE_TIME_SLICING                    1   /* 1=同优先级任务轮流执行，0=同优先级任务谁先就谁一直跑 */
#define configUSE_NEWLIB_REENTRANT                0   /* ★CM0+ 无 DWT CYCCNT，不能用 run-time stats 也就没必要开这个 */
#define configUSE_TASK_NOTIFICATIONS              1   /* 任务通知：轻量级事件/信号量，1 个任务最多 1 个通知值（可扩展成数组，见 FreeRTOS.h） */
#define configMAX_PRIORITIES                      ( 8 )     /* 软件优先级，不受 CM0 的 4 级硬件限制 */
#define configMAX_TASK_NAME_LEN                   ( 12 )    /* 任务名最大长度（含结尾 '\0'） */
#define configMINIMAL_STACK_SIZE                  ( 128 )   /* ★必定义：空闲任务栈，单位=字(128 字=512 字节) */
#define configUSE_16_BIT_TICKS                    0   /* 0=32位节拍计数，1=16位节拍计数（CM0+ 32位寄存器，必须 0） */      
#define configIDLE_SHOULD_YIELD                   1   /* 1=空闲任务让出 CPU，0=空闲任务不让出 CPU（同优先级任务轮流执行） */

#define configUSE_MUTEXES                         1      /* 互斥锁（优先级继承） */
#define configUSE_RECURSIVE_MUTEXES               1      /* 递归互斥锁 */
#define configUSE_COUNTING_SEMAPHORES             1      /* 计数信号量 */
#define configQUEUE_REGISTRY_SIZE                 8      /* Keil 的 RTOS 调试视图需要 */
#define configUSE_QUEUE_SETS                      0      /* 阶段4 做 STOP 低功耗时再改 1 */
#define configUSE_TASK_FPU_SUPPORT                0      /* CM0+ 无 FPU */

/*===========================================================================
 * §4 内存管理（32KB SRAM）
 *=========================================================================*/
#define configSUPPORT_STATIC_ALLOCATION           0      /* 0=不支持静态分配，1=支持静态分配（任务/队列/信号量/定时器） */
#define configSUPPORT_DYNAMIC_ALLOCATION          1      /* 0=不支持动态分配，1=支持动态分配（任务/队列/信号量/定时器） */
#define configTOTAL_HEAP_SIZE                     ( ( size_t ) ( 8 * 1024 ) )  /* 8KB，见 §7 预算 */
#define configAPPLICATION_ALLOCATED_HEAP          0      /* 0=内核自己分配 configTOTAL_HEAP_SIZE，1=应用自己分配 configTOTAL_HEAP_SIZE */

/*===========================================================================
 * §5 钩子与断言（调试期全开；这些钩子函数在 Src\app_rtos_hooks.c 里实现）
 *=========================================================================*/
#define configUSE_MALLOC_FAILED_HOOK              1      /* 内存分配失败时调用 vApplicationMallocFailedHook() */
#define configCHECK_FOR_STACK_OVERFLOW            2      /* 1=仅检查任务栈溢出，2=检查任务栈溢出+堆栈溢出（见 app_rtos_hooks.c） */
extern void vApplicationAssertFailure(const char *pcFile, unsigned long ulLine);
#define configASSERT( x ) \
    if( ( x ) == 0 ) { vApplicationAssertFailure( __FILE__, __LINE__ ); }

/*===========================================================================
 * §6 可选 API（用不到就 0，省 Flash/RAM）
 *=========================================================================*/
#define INCLUDE_vTaskPrioritySet                  1      /* 1=包含 vTaskPrioritySet() 函数 */
#define INCLUDE_uxTaskPriorityGet                 1      /* 1=包含 uxTaskPriorityGet() 函数 */
#define INCLUDE_vTaskDelete                       1      /* 1=包含 vTaskDelete() 函数 */
#define INCLUDE_vTaskSuspend                      1      /* 1=包含 vTaskSuspend() 函数 */
#define INCLUDE_vTaskDelay                        1      /* 1=包含 vTaskDelay() 函数 */
#define INCLUDE_xTaskDelayUntil                   1      /* V10.5.1 用这个名字（旧名 INCLUDE_vTaskDelayUntil 已废弃，两个都定义会 #error） */
#define INCLUDE_xTaskGetSchedulerState            1      /* 1=包含 xTaskGetSchedulerState() 函数 */
#define INCLUDE_xTaskGetCurrentTaskHandle         1      /* 1=包含 xTaskGetCurrentTaskHandle() 函数 */
#define INCLUDE_xTaskGetIdleTaskHandle            1      /* 1=包含 xTaskGetIdleTaskHandle() 函数 */
#define INCLUDE_uxTaskGetStackHighWaterMark       1      /* 1=包含 uxTaskGetStackHighWaterMark() 函数 */
#define INCLUDE_uxTaskGetNumberOfTasks            1      /* 1=包含 uxTaskGetNumberOfTasks() 函数 */
#define INCLUDE_pcTaskGetTaskName                 1      /* 1=包含 pcTaskGetTaskName() 函数 */
#define INCLUDE_eTaskGetState                     1      /* 1=包含 eTaskGetState() 函数 */
#define INCLUDE_xTaskAbortDelay                   1      /* 1=包含 xTaskAbortDelay() 函数 */
#define INCLUDE_xQueueGetMutexHolder              1      /* 1=包含 xQueueGetMutexHolder() 函数 */
#define INCLUDE_xSemaphoreGetMutexHolder          1      /* 1=包含 xSemaphoreGetMutexHolder() 函数 */

/*===========================================================================
 * §7 软件定时器（阶段1 先关；要用改 1，timers.c 已经在工程分组里了）
 *=========================================================================*/
#define configUSE_TIMERS                          0      /* 0=不启用软件定时器，1=启用软件定时器（timers.c） */
#define configTIMER_TASK_PRIORITY                 ( 2 )  /* ★定时器任务优先级，不能低于空闲任务（1） */
#define configTIMER_QUEUE_LENGTH                  10     /* ★定时器队列长度，够用就行，太大浪费 RAM */
#define configTIMER_TASK_STACK_DEPTH              ( 128 )/* ★定时器任务栈，单位=字(128 字=512 字节) */

/*===========================================================================
 * §8 统计与可视化调试
 *=========================================================================*/
#define configUSE_TRACE_FACILITY                  1   /* vTaskList/vTaskGetSystemState 需要 */
#define configUSE_STATS_FORMATTING_FUNCTIONS      1   /* vTaskList 内部用 sprintf，需 256 字栈 */
#define configGENERATE_RUN_TIME_STATS             0   /* ★CM0+ 无 DWT CYCCNT，要开得用空闲 TIM 做时基 */

/*===========================================================================
 * §9 CM0/CM0+ 上"配了也白配"的宏（留在注释里，防止照抄 M3/M4 教程）
 *=========================================================================*/
/* #define configKERNEL_INTERRUPT_PRIORITY ...    // CM0 端口硬编码内核异常优先级=最低(255)，不看这个宏
 * #define configMAX_SYSCALL_INTERRUPT_PRIORITY ... // CM0 无 BASEPRI，无法只屏蔽部分中断：临界区 = CPSID i 全屏蔽
 */

#endif /* FREERTOS_CONFIG_H */
