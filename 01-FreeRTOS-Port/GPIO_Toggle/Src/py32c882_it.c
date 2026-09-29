/**
  ******************************************************************************
  * @file    py32c882_it.c
  * @author  MCU Application Team
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "py32c882_it.h"
#include "FreeRTOS.h"
#include "task.h"

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*          Cortex-M0+ Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/* ==========================================================================
 * ★ 移植 FreeRTOS 后的改动（2026-09）：
 *   PendSV_Handler / SysTick_Handler 必须让位给 FreeRTOS 的 port.c
 *   （FreeRTOSConfig.h 里把 xPortPendSVHandler 映射为 PendSV_Handler、
 *     xPortSysTickHandler 映射为 SysTick_Handler），否则链接报
 *     L6200E: Symbol multiply defined。
 *   HAL_IncTick() 已迁移到 Src\app_rtos_hooks.c 的 vApplicationTickHook()，
 *   所以 HAL 时基照旧工作：HAL_GetTick() / HAL_Delay() / HAL_UART_Transmit 的超时都正常。
 * ========================================================================== */

/**
  * @brief This function handles System service call via SWI instruction.
  * @note  CM0+ 的 FreeRTOS 端口不使用 SVC 指令（启动第一个任务走 prvPortStartFirstTask，
  *        纯软件设置 PSP/CONTROL 后 bx 跳转），且 FreeRTOSConfig.h 里没有定义
  *        vPortSVCHandler 映射 —— 所以这个空函数保留即可，不会与 port.c 撞符号。
  */
void SVC_Handler(void)
{
}

/* ★ 原内容，请勿删除（回退裸机版时需要）：
void PendSV_Handler(void)
{
}
*/

/* ★★ SysTick 归属分派（2026-09-24 修复 HardFault 根因，详见 FreeRTOSConfig.h 的说明）
 *
 * 为什么不能让 port.c 直接接管 SysTick_Handler：
 *   HAL_Init() 已经打开 SysTick 并允许其中断，而 vTaskStartScheduler() 之前
 *   FreeRTOS 的 xNextTaskUnblockTime 还是 0、pxDelayedTaskList 还是 NULL；
 *   此时来一个 tick 就会进 xTaskIncrementTick() 解引用 NULL → HardFault。
 *   （main 里一行 printf 耗时 5~7ms、单步调试一步就 >1ms，必然踩中。）
 *
 * 分派策略：
 *   调度器未启动 → 只喂 HAL 时基（等价于原裸机版的 HAL_IncTick()）
 *   调度器已启动 → 交给 FreeRTOS 的节拍处理 xPortSysTickHandler()
 */
extern void xPortSysTickHandler(void);   /* 在 port.c 里；本工程未做名字映射，故保留原名 */

void SysTick_Handler(void)
{
  if (xTaskGetSchedulerState() == taskSCHEDULER_NOT_STARTED)
  {
    HAL_IncTick();            /* 裸机阶段：维持 HAL_GetTick / HAL_Delay / HAL 超时 */
  }
  else
  {
    xPortSysTickHandler();    /* 调度器已启动：交给 FreeRTOS */
  }
}

/******************************************************************************/
/* PY32C882 Peripheral Interrupt Handlers                                     */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file.                                          */
/******************************************************************************/

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
