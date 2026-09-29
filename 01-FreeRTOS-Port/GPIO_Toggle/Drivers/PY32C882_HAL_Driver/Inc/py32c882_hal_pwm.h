/**
  ******************************************************************************
  * @file    py32c882_hal_pwm.h
  * @author  MCU Application Team
  * @brief   Header file of PWM HAL module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PY32C882_HAL_PWM_H
#define __PY32C882_HAL_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup PWM
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup PWM_Exported_Types PWM Exported Types
  * @{
  */

/**
  * @brief  PWM Time base Configuration Structure definition
  */
typedef struct
{
  uint32_t Prescaler;         /*!< Specifies the prescaler value used to divide the PWM clock.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref PWM_Counter_Mode */

  uint32_t Period;            /*!< Specifies the period value to be loaded into the active
                                   Auto-Reload Register at the next update event.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF.  */

  uint32_t ClockDivision;     /*!< Specifies the clock division.
                                   This parameter can be a value of @ref PWM_ClockDivision */
  
  uint32_t AutoReloadPreload;  /*!< Specifies the auto-reload preload.
                                   This parameter can be a value of @ref PWM_AutoReloadPreload */
} PWM_Base_InitTypeDef;

/**
  * @brief  PWM Output Compare Configuration Structure definition
  */
typedef struct
{
  uint32_t OCMode;        /*!< Specifies the PWM mode.
                               This parameter can be a value of @ref PWM_PWM_modes */

  uint32_t Pulse;         /*!< Specifies the pulse value to be loaded into the Capture Compare Register.
                               This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */

  uint32_t OCPolarity;    /*!< Specifies the output polarity.
                               This parameter can be a value of @ref PWM_Output_Compare_Polarity */

  uint32_t OCNPolarity;   /*!< Specifies the complementary output polarity.
                               This parameter can be a value of @ref PWM_Output_Compare_N_Polarity
                               @note This parameter is valid only for PWM instances supporting break feature. */

} PWM_OC_InitTypeDef;

/**
  * @brief  Clock Configuration Handle Structure definition
  */
typedef struct
{
  uint32_t ClockSource;     /*!< PWM clock sources
                                 This parameter can be a value of @ref PWM_Clock_Source */
  uint32_t ClockPolarity;   /*!< PWM clock polarity
                                 This parameter can be a value of @ref PWM_Clock_Polarity */
  uint32_t ClockPrescaler;  /*!< PWM clock prescaler
                                 This parameter can be a value of @ref PWM_Clock_Prescaler */
  uint32_t ClockFilter;     /*!< PWM clock filter
                                 This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
} PWM_ClockConfigTypeDef;

/**
  * @brief  PWM Break input and Dead time configuration Structure definition
  */
typedef struct
{
  uint32_t LockLevel;            /*!< PWM Lock level
                                      This parameter can be a value of @ref PWM_Lock_level */
  uint32_t DeadTime;             /*!< PWM dead Time
                                      This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF */
  uint32_t BreakState;           /*!< PWM Break State
                                      This parameter can be a value of @ref PWM_Break_Input_enable_disable */
  uint32_t BreakPolarity;        /*!< PWM Break input polarity
                                      This parameter can be a value of @ref PWM_Break_Polarity */
  uint32_t AutomaticOutput;      /*!< PWM Automatic Output Enable state
                                      This parameter can be a value of @ref PWM_AOE_Bit_Set_Reset */
} PWM_BreakDeadTimeConfigTypeDef;

/**
  * @brief  HAL State structures definition
  */
typedef enum
{
  HAL_PWM_STATE_RESET             = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
  HAL_PWM_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use    */
  HAL_PWM_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing              */
  HAL_PWM_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state                               */
  HAL_PWM_STATE_ERROR             = 0x04U     /*!< Reception process is ongoing                */
} HAL_PWM_StateTypeDef;

/**
  * @brief  HAL Active channel structures definition
  */
typedef enum
{
  HAL_PWM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< The active channel is 1     */
  HAL_PWM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< The active channel is 2     */
  HAL_PWM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< The active channel is 3     */
  HAL_PWM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< The active channel is 4     */
  HAL_PWM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
} HAL_PWM_ActiveChannel;

/**
  * @brief  PWM Time Base Handle Structure definition
  */
#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
typedef struct __PWM_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
{
  PWM_TypeDef                 *Instance;     /*!< Register base address             */
  PWM_Base_InitTypeDef        Init;          /*!< PWM Time Base required parameters */
  HAL_PWM_ActiveChannel       Channel;       /*!< Active channel                    */
#if (defined(DMA) || defined(DMA1))
  DMA_HandleTypeDef           *hdma[7];      /*!< DMA Handlers array
                                                  This array is accessed by a @ref PWM_DMA_Handle_index */
#endif
  HAL_LockTypeDef             Lock;          /*!< Locking object                    */
  __IO HAL_PWM_StateTypeDef   State;         /*!< PWM operation state               */

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  void (* Base_MspInitCallback)(struct __PWM_HandleTypeDef *hpwm);              /*!< PWM Base Msp Init Callback                              */
  void (* Base_MspDeInitCallback)(struct __PWM_HandleTypeDef *hpwm);            /*!< PWM Base Msp DeInit Callback                            */
  void (* PWM_MspInitCallback)(struct __PWM_HandleTypeDef *hpwm);               /*!< PWM PWM Msp Init Callback                               */
  void (* PWM_MspDeInitCallback)(struct __PWM_HandleTypeDef *hpwm);             /*!< PWM PWM Msp DeInit Callback                             */
  void (* PeriodElapsedCallback)(struct __PWM_HandleTypeDef *hpwm);             /*!< PWM Period Elapsed Callback                             */
  void (* PeriodElapsedHalfCpltCallback)(struct __PWM_HandleTypeDef *hpwm);     /*!< PWM Period Elapsed half complete Callback               */
  void (* PWM_PulseFinishedCallback)(struct __PWM_HandleTypeDef *hpwm);         /*!< PWM PWM Pulse Finished Callback                         */
  void (* PWM_PulseFinishedHalfCpltCallback)(struct __PWM_HandleTypeDef *hpwm); /*!< PWM PWM Pulse Finished half complete Callback           */
  void (* ErrorCallback)(struct __PWM_HandleTypeDef *hpwm);                     /*!< PWM Error Callback                                      */
  void (* BreakCallback)(struct __PWM_HandleTypeDef *hpwm);                     /*!< PWM Break Callback                                      */
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
} PWM_HandleTypeDef;

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL PWM Callback ID enumeration definition
  */
typedef enum
{
  HAL_PWM_BASE_MSPINIT_CB_ID            = 0x00U    /*!< PWM Base MspInit Callback ID                              */
  ,HAL_PWM_BASE_MSPDEINIT_CB_ID          = 0x01U    /*!< PWM Base MspDeInit Callback ID                            */
  ,HAL_PWM_PWM_MSPINIT_CB_ID             = 0x06U    /*!< PWM PWM MspInit Callback ID                               */
  ,HAL_PWM_PWM_MSPDEINIT_CB_ID           = 0x07U    /*!< PWM PWM MspDeInit Callback ID                             */
  ,HAL_PWM_PERIOD_ELAPSED_CB_ID          = 0x0EU    /*!< PWM Period Elapsed Callback ID                             */
  ,HAL_PWM_PERIOD_ELAPSED_HALF_CB_ID     = 0x0FU    /*!< PWM Period Elapsed half complete Callback ID               */
  ,HAL_PWM_PWM_PULSE_FINISHED_CB_ID      = 0x15U    /*!< PWM PWM Pulse Finished Callback ID           */
  ,HAL_PWM_PWM_PULSE_FINISHED_HALF_CB_ID = 0x16U    /*!< PWM PWM Pulse Finished half complete Callback ID           */
  ,HAL_PWM_ERROR_CB_ID                   = 0x17U    /*!< PWM Error Callback ID                                      */
  ,HAL_PWM_BREAK_CB_ID                   = 0x1AU    /*!< PWM Break Callback ID                                      */
} HAL_PWM_CallbackIDTypeDef;

/**
  * @brief  HAL PWM Callback pointer definition
  */
typedef  void (*pPWM_CallbackTypeDef)(PWM_HandleTypeDef *hpwm);  /*!< pointer to the PWM callback function */

#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup PWM_Exported_Constants PWM Exported Constants
  * @{
  */

#if (defined(DMA) || defined(DMA1))
/** @defgroup PWM_DMA_Base_address PWM DMA Base Address
  * @{
  */
#define PWM_DMABASE_CR1                    0x00000000U
#define PWM_DMABASE_CR2                    0x00000001U
#define PWM_DMABASE_SMCR                   0x00000002U
#define PWM_DMABASE_DIER                   0x00000003U
#define PWM_DMABASE_SR                     0x00000004U
#define PWM_DMABASE_EGR                    0x00000005U
#define PWM_DMABASE_CMR                    0x00000006U
#define PWM_DMABASE_CER                    0x00000008U
#define PWM_DMABASE_CNT                    0x00000009U
#define PWM_DMABASE_PSC                    0x0000000AU
#define PWM_DMABASE_ARR                    0x0000000BU
#define PWM_DMABASE_CCR1                   0x0000000DU
#define PWM_DMABASE_CCR2                   0x0000000EU
#define PWM_DMABASE_CCR3                   0x0000000FU
#define PWM_DMABASE_CCR4                   0x00000010U
#define PWM_DMABASE_BDTR                   0x00000011U
#define PWM_DMABASE_DCR                    0x00000012U
#define PWM_DMABASE_DMAR                   0x00000013U
/**
  * @}
  */
#endif

/** @defgroup PWM_Event_Source PWM Event Source
  * @{
  */
#define PWM_EVENTSOURCE_UPDATE              PWM_EGR_UG     /*!< Reinitialize the counter and generates an update of the registers */
/**
  * @}
  */

/** @defgroup PWM_ETR_Polarity PWM ETR Polarity
  * @{
  */
#define PWM_ETRPOLARITY_INVERTED              PWM_SMCR_ETP                      /*!< Polarity for ETR source */
#define PWM_ETRPOLARITY_NONINVERTED           0x00000000U                       /*!< Polarity for ETR source */
/**
  * @}
  */

/** @defgroup PWM_ETR_Prescaler PWM ETR Prescaler
  * @{
  */
#define PWM_ETRPRESCALER_DIV1                 0x00000000U                       /*!< No prescaler is used */
#define PWM_ETRPRESCALER_DIV2                 PWM_SMCR_ETPS_0                   /*!< ETR input source is divided by 2 */
#define PWM_ETRPRESCALER_DIV4                 PWM_SMCR_ETPS_1                   /*!< ETR input source is divided by 4 */
#define PWM_ETRPRESCALER_DIV8                 PWM_SMCR_ETPS                     /*!< ETR input source is divided by 8 */
/**
  * @}
  */

/** @defgroup PWM_Counter_Mode PWM Counter Mode
  * @{
  */
#define PWM_COUNTERMODE_UP                 0x00000000U                          /*!< Counter used as up-counter   */
#define PWM_COUNTERMODE_DOWN               PWM_CR1_DIR                          /*!< Counter used as down-counter */
#define PWM_COUNTERMODE_CENTERALIGNED1     PWM_CR1_CMS_0                        /*!< Center-aligned mode 1        */
#define PWM_COUNTERMODE_CENTERALIGNED2     PWM_CR1_CMS_1                        /*!< Center-aligned mode 2        */
#define PWM_COUNTERMODE_CENTERALIGNED3     PWM_CR1_CMS                          /*!< Center-aligned mode 3        */
/**
  * @}
  */

/** @defgroup PWM_ClockDivision PWM Clock Division
  * @{
  */
#define PWM_CLOCKDIVISION_DIV1             0x00000000U                          /*!< Clock division: tDTS=tCK_INT   */
#define PWM_CLOCKDIVISION_DIV2             PWM_CR1_CKD_0                        /*!< Clock division: tDTS=2*tCK_INT */
#define PWM_CLOCKDIVISION_DIV4             PWM_CR1_CKD_1                        /*!< Clock division: tDTS=4*tCK_INT */
/**
  * @}
  */

/** @defgroup PWM_Output_Compare_State PWM Output Compare State
  * @{
  */
#define PWM_OUTPUTSTATE_DISABLE            0x00000000U                          /*!< Compare 1 output disabled */
#define PWM_OUTPUTSTATE_ENABLE             PWM_CER_C1E                          /*!< Compare 1 output enabled */
/**
  * @}
  */

/** @defgroup PWM_AutoReloadPreload PWM Auto-Reload Preload
  * @{
  */
#define PWM_AUTORELOAD_PRELOAD_DISABLE                0x00000000U               /*!< PWMx_ARR register is not buffered */
#define PWM_AUTORELOAD_PRELOAD_ENABLE                 PWM_CR1_ARPE              /*!< PWMx_ARR register is buffered */

/**
  * @}
  */

/** @defgroup PWM_Output_Compare_N_State PWM Complementary Output Compare State
  * @{
  */
#define PWM_OUTPUTNSTATE_DISABLE           0x00000000U                          /*!< OCxN is disabled  */
#define PWM_OUTPUTNSTATE_ENABLE            PWM_CER_C1NE                         /*!< OCxN is enabled   */
/**
  * @}
  */

/** @defgroup PWM_Output_Compare_Polarity PWM Output Compare Polarity
  * @{
  */
#define PWM_OCPOLARITY_HIGH                0x00000000U                          /*!< Compare output polarity  */
#define PWM_OCPOLARITY_LOW                 PWM_CER_C1P                          /*!< Compare output polarity  */
/**
  * @}
  */

/** @defgroup PWM_Output_Compare_N_Polarity PWM Complementary Output Compare Polarity
  * @{
  */
#define PWM_OCNPOLARITY_HIGH               0x00000000U                          /*!< Compare complementary output polarity */
#define PWM_OCNPOLARITY_LOW                PWM_CER_C1NP                         /*!< Compare complementary output polarity */
/**
  * @}
  */

/** @defgroup PWM_Interrupt_definition PWM interrupt Definition
  * @{
  */
#define PWM_IT_UPDATE                      PWM_DIER_UIE                         /*!< Update interrupt            */
#define PWM_IT_OC1                         PWM_DIER_OC1IE                       /*!< Compare 1 interrupt */
#define PWM_IT_OC2                         PWM_DIER_OC2IE                       /*!< Compare 2 interrupt */
#define PWM_IT_OC3                         PWM_DIER_OC3IE                       /*!< Compare 3 interrupt */
#define PWM_IT_OC4                         PWM_DIER_OC4IE                       /*!< Compare 4 interrupt */
#define PWM_IT_BREAK                       PWM_DIER_BIE                         /*!< Break interrupt             */
/**
  * @}
  */

#if (defined(DMA) || defined(DMA1))
/** @defgroup PWM_DMA_sources PWM DMA Sources
  * @{
  */
#define PWM_DMA_UPDATE                     PWM_DIER_UDE                         /*!< DMA request is triggered by the update event */
#define PWM_DMA_OC1                        PWM_DIER_OC1DE                       /*!< DMA request is triggered by the compare macth 1 event */
#define PWM_DMA_OC2                        PWM_DIER_OC2DE                       /*!< DMA request is triggered by the compare macth 2 event */
#define PWM_DMA_OC3                        PWM_DIER_OC3DE                       /*!< DMA request is triggered by the compare macth 3 event */
#define PWM_DMA_OC4                        PWM_DIER_OC4DE                       /*!< DMA request is triggered by the compare macth 4 event */
/**
  * @}
  */
#endif

/** @defgroup PWM_Flag_definition PWM Flag Definition
  * @{
  */
#define PWM_FLAG_UPDATE                    PWM_SR_UIF                           /*!< Update interrupt flag */
#define PWM_FLAG_OC1                       PWM_SR_OC1IF                         /*!< Compare 1 interrupt flag */
#define PWM_FLAG_OC2                       PWM_SR_OC2IF                         /*!< Compare 2 interrupt flag */
#define PWM_FLAG_OC3                       PWM_SR_OC3IF                         /*!< Compare 3 interrupt flag */
#define PWM_FLAG_OC4                       PWM_SR_OC4IF                         /*!< Compare 4 interrupt flag */
#define PWM_FLAG_BREAK                     PWM_SR_BIF                           /*!< Break interrupt flag */
#define PWM_FLAG_CCR1OK                    PWM_SR_CCR1OK                        /*!< PWM_CCR1 register update completion flag */
#define PWM_FLAG_CCR2OK                    PWM_SR_CCR2OK                        /*!< PWM_CCR2 register update completion flag */
#define PWM_FLAG_CCR3OK                    PWM_SR_CCR3OK                        /*!< PWM_CCR3 register update completion flag */
#define PWM_FLAG_CCR4OK                    PWM_SR_CCR4OK                        /*!< PWM_CCR4 register update completion flag */
#define PWM_FLAG_CNTOK                     PWM_SR_CNTOK                         /*!< PWM_CNT register update completion flag */
#define PWM_FLAG_PSCOK                     PWM_SR_PSCOK                         /*!< PWM_PSC register update completion flag */
#define PWM_FLAG_ARROK                     PWM_SR_ARROK                         /*!< PWM_ARR register update completion flag */
/**
  * @}
  */

/** @defgroup PWM_Channel PWM Channel
  * @{
  */
#define PWM_CHANNEL_1                      0x00000000U                          /*!< compare channel 1 identifier      */
#define PWM_CHANNEL_2                      0x00000004U                          /*!< compare channel 2 identifier      */
#define PWM_CHANNEL_3                      0x00000008U                          /*!< compare channel 3 identifier      */
#define PWM_CHANNEL_4                      0x0000000CU                          /*!< compare channel 4 identifier      */
#define PWM_CHANNEL_ALL                    0x0000003CU                          /*!< Global compare channel identifier  */
/**
  * @}
  */

/** @defgroup PWM_Clock_Source PWM Clock Source
  * @{
  */
#define PWM_CLOCKSOURCE_ETRMODE     PWM_SMCR_ECE      /*!< External clock source mode                            */
#define PWM_CLOCKSOURCE_INTERNAL    0x00000000U       /*!< Internal clock source                                 */
/**
  * @}
  */

/** @defgroup PWM_Clock_Polarity PWM Clock Polarity
  * @{
  */
#define PWM_CLOCKPOLARITY_INVERTED           PWM_ETRPOLARITY_INVERTED           /*!< Polarity for ETRx clock sources */
#define PWM_CLOCKPOLARITY_NONINVERTED        PWM_ETRPOLARITY_NONINVERTED        /*!< Polarity for ETRx clock sources */
/**
  * @}
  */

/** @defgroup PWM_Clock_Prescaler PWM Clock Prescaler
  * @{
  */
#define PWM_CLOCKPRESCALER_DIV1                 PWM_ETRPRESCALER_DIV1           /*!< No prescaler is used                                                     */
#define PWM_CLOCKPRESCALER_DIV2                 PWM_ETRPRESCALER_DIV2           /*!< Prescaler for External ETR Clock: Capture performed once every 2 events. */
#define PWM_CLOCKPRESCALER_DIV4                 PWM_ETRPRESCALER_DIV4           /*!< Prescaler for External ETR Clock: Capture performed once every 4 events. */
#define PWM_CLOCKPRESCALER_DIV8                 PWM_ETRPRESCALER_DIV8           /*!< Prescaler for External ETR Clock: Capture performed once every 8 events. */
/**
  * @}
  */

/** @defgroup PWM_Lock_level  PWM Lock level
  * @{
  */
#define PWM_LOCKLEVEL_OFF                  0x00000000U                          /*!< LOCK OFF     */
#define PWM_LOCKLEVEL_1                    PWM_BDTR_LOCK_0                      /*!< LOCK Level 1 */
#define PWM_LOCKLEVEL_2                    PWM_BDTR_LOCK_1                      /*!< LOCK Level 2 */
#define PWM_LOCKLEVEL_3                    PWM_BDTR_LOCK                        /*!< LOCK Level 3 */
/**
  * @}
  */

/** @defgroup PWM_Break_Input_enable_disable PWM Break Input Enable
  * @{
  */
#define PWM_BREAK_ENABLE                   PWM_BDTR_BKE                         /*!< Break input BRK is enabled  */
#define PWM_BREAK_DISABLE                  0x00000000U                          /*!< Break input BRK is disabled */
/**
  * @}
  */

/** @defgroup PWM_Break_Polarity PWM Break Input Polarity
  * @{
  */
#define PWM_BREAKPOLARITY_LOW              0x00000000U                          /*!< Break input BRK is active low  */
#define PWM_BREAKPOLARITY_HIGH             PWM_BDTR_BKP                         /*!< Break input BRK is active high */
/**
  * @}
  */

/** @defgroup PWM_AOE_Bit_Set_Reset PWM Automatic Output Enable
  * @{
  */
#define PWM_AUTOMATICOUTPUT_DISABLE        0x00000000U                          /*!< MOE can be set only by software */
#define PWM_AUTOMATICOUTPUT_ENABLE         PWM_BDTR_AOE                         /*!< MOE can be set by software or automatically at the next update event 
                                                                                    (if none of the break inputs BRK and BRK2 is active) */
/**
  * @}
  */

/** @defgroup PWM_PWM_modes PWM Output Compare and PWM Modes
  * @{
  */
#define PWM_OCMODE_PWM1                     (PWM_CMR_OC1M_1 )                    /*!< PWM mode 1                             */
#define PWM_OCMODE_PWM2                     (PWM_CMR_OC1M_1 | PWM_CMR_OC1M_0)    /*!< PWM mode 2                             */
/**
  * @}
  */

#if (defined(DMA) || defined(DMA1))
/** @defgroup PWM_DMA_Burst_Length PWM DMA Burst Length
  * @{
  */
#define PWM_DMABURSTLENGTH_1TRANSFER       0x00000000U                          /*!< The transfer is done to 1 register starting from PWMx_CR1 + PWMx_DCR.DBA   */
#define PWM_DMABURSTLENGTH_2TRANSFERS      0x00000100U                          /*!< The transfer is done to 2 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_3TRANSFERS      0x00000200U                          /*!< The transfer is done to 3 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_4TRANSFERS      0x00000300U                          /*!< The transfer is done to 4 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_5TRANSFERS      0x00000400U                          /*!< The transfer is done to 5 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_6TRANSFERS      0x00000500U                          /*!< The transfer is done to 6 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_7TRANSFERS      0x00000600U                          /*!< The transfer is done to 7 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_8TRANSFERS      0x00000700U                          /*!< The transfer is done to 8 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_9TRANSFERS      0x00000800U                          /*!< The transfer is done to 9 registers starting from PWMx_CR1 + PWMx_DCR.DBA  */
#define PWM_DMABURSTLENGTH_10TRANSFERS     0x00000900U                          /*!< The transfer is done to 10 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_11TRANSFERS     0x00000A00U                          /*!< The transfer is done to 11 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_12TRANSFERS     0x00000B00U                          /*!< The transfer is done to 12 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_13TRANSFERS     0x00000C00U                          /*!< The transfer is done to 13 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_14TRANSFERS     0x00000D00U                          /*!< The transfer is done to 14 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_15TRANSFERS     0x00000E00U                          /*!< The transfer is done to 15 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_16TRANSFERS     0x00000F00U                          /*!< The transfer is done to 16 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_17TRANSFERS     0x00001000U                          /*!< The transfer is done to 17 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
#define PWM_DMABURSTLENGTH_18TRANSFERS     0x00001100U                          /*!< The transfer is done to 18 registers starting from PWMx_CR1 + PWMx_DCR.DBA */
/**
  * @}
  */

/** @defgroup PWM_DMA_Handle_index PWM DMA Handle Index
  * @{
  */
#define PWM_DMA_ID_UPDATE                ((uint16_t) 0x0000)       /*!< Index of the DMA handle used for Update DMA requests */
#define PWM_DMA_ID_OC1                   ((uint16_t) 0x0001)       /*!< Index of the DMA handle used for Compare 1 DMA requests */
#define PWM_DMA_ID_OC2                   ((uint16_t) 0x0002)       /*!< Index of the DMA handle used for Compare 2 DMA requests */
#define PWM_DMA_ID_OC3                   ((uint16_t) 0x0003)       /*!< Index of the DMA handle used for Compare 3 DMA requests */
#define PWM_DMA_ID_OC4                   ((uint16_t) 0x0004)       /*!< Index of the DMA handle used for Compare 4 DMA requests */
/**
  * @}
  */
#endif

/** @defgroup Channel_OC_State PWM Compare Channel State
  * @{
  */
#define PWM_OCx_ENABLE                   0x00000001U                            /*!< output channel is enabled */
#define PWM_OCx_DISABLE                  0x00000000U                            /*!< output channel is disabled */
#define PWM_OCxN_ENABLE                  0x00000004U                            /*!< Complementary output channel is enabled */
#define PWM_OCxN_DISABLE                 0x00000000U                            /*!< Complementary output channel is disabled */
/**
  * @}
  */

/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup PWM_Exported_Macros PWM Exported Macros
  * @{
  */

/** @brief  Reset PWM handle state.
  * @param  __HANDLE__ PWM handle.
  * @retval None
  */
#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
#define __HAL_PWM_RESET_HANDLE_STATE(__HANDLE__) do {                                                        \
                                                      (__HANDLE__)->State             = HAL_PWM_STATE_RESET; \
                                                      (__HANDLE__)->Base_MspInitCallback         = NULL;     \
                                                      (__HANDLE__)->Base_MspDeInitCallback       = NULL;     \
                                                      (__HANDLE__)->PWM_MspInitCallback          = NULL;     \
                                                      (__HANDLE__)->PWM_MspDeInitCallback        = NULL;     \
                                                     } while(0)
#else
#define __HAL_PWM_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_PWM_STATE_RESET)
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

/**
  * @brief  Enable the PWM peripheral.
  * @param  __HANDLE__ PWM handle
  * @retval None
  */
#define __HAL_PWM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(PWM_CR1_CEN))

/**
  * @brief  Enable the PWM main Output.
  * @param  __HANDLE__ PWM handle
  * @retval None
  */
#define __HAL_PWM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(PWM_BDTR_MOE))

/**
  * @brief  Disable the PWM peripheral.
  * @param  __HANDLE__ PWM handle
  * @retval None
  */
#define __HAL_PWM_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CER & PWM_CER_CxE_MASK) == 0UL) \
    { \
      if(((__HANDLE__)->Instance->CER & PWM_CER_CxNE_MASK) == 0UL) \
      { \
        (__HANDLE__)->Instance->CR1 &= ~(PWM_CR1_CEN); \
      } \
    } \
  } while(0)

/**
  * @brief  Disable the PWM main Output.
  * @param  __HANDLE__ PWM handle
  * @retval None
  * @note The Main Output Enable of a pwm instance is disabled only if all the Cx and CxN channels have been disabled
  */
#define __HAL_PWM_MOE_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CER & PWM_CER_CxE_MASK) == 0UL) \
    { \
      if(((__HANDLE__)->Instance->CER & PWM_CER_CxNE_MASK) == 0UL) \
      { \
        (__HANDLE__)->Instance->BDTR &= ~(PWM_BDTR_MOE); \
      } \
    } \
  } while(0)

/**
  * @brief  Disable the PWM main Output.
  * @param  __HANDLE__ PWM handle
  * @retval None
  * @note The Main Output Enable of a pwm instance is disabled unconditionally
  */
#define __HAL_PWM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(PWM_BDTR_MOE)

/** @brief  Enable the specified PWM interrupt.
  * @param  __HANDLE__ specifies the PWM Handle.
  * @param  __INTERRUPT__ specifies the PWM interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg PWM_IT_UPDATE: Update interrupt
  *            @arg PWM_IT_OC1:   Compare 1 interrupt
  *            @arg PWM_IT_OC2:  Compare 2 interrupt
  *            @arg PWM_IT_OC3:  Compare 3 interrupt
  *            @arg PWM_IT_OC4:  Compare 4 interrupt
  *            @arg PWM_IT_BREAK: Break interrupt
  * @retval None
  */
#define __HAL_PWM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))

/** @brief  Disable the specified PWM interrupt.
  * @param  __HANDLE__ specifies the PWM Handle.
  * @param  __INTERRUPT__ specifies the PWM interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg PWM_IT_UPDATE: Update interrupt
  *            @arg PWM_IT_OC1:   Compare 1 interrupt
  *            @arg PWM_IT_OC2:  Compare 2 interrupt
  *            @arg PWM_IT_OC3:  Compare 3 interrupt
  *            @arg PWM_IT_OC4:  Compare 4 interrupt
  *            @arg PWM_IT_BREAK: Break interrupt
  * @retval None
  */
#define __HAL_PWM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))

#if (defined(DMA) || defined(DMA1))
/** @brief  Enable the specified DMA request.
  * @param  __HANDLE__ specifies the PWM Handle.
  * @param  __DMA__ specifies the PWM DMA request to enable.
  *          This parameter can be one of the following values:
  *            @arg PWM_DMA_UPDATE: Update DMA request
  *            @arg PWM_DMA_OC1:   Compare 1 DMA request
  *            @arg PWM_DMA_OC2:  Compare 2 DMA request
  *            @arg PWM_DMA_OC3:  Compare 3 DMA request
  *            @arg PWM_DMA_OC4:  Compare 4 DMA request
  * @retval None
  */
#define __HAL_PWM_ENABLE_DMA(__HANDLE__, __DMA__)         ((__HANDLE__)->Instance->DIER |= (__DMA__))

/** @brief  Disable the specified DMA request.
  * @param  __HANDLE__ specifies the PWM Handle.
  * @param  __DMA__ specifies the PWM DMA request to disable.
  *          This parameter can be one of the following values:
  *            @arg PWM_DMA_UPDATE: Update DMA request
  *            @arg PWM_DMA_OC1:   Compare 1 DMA request
  *            @arg PWM_DMA_OC2:  Compare 2 DMA request
  *            @arg PWM_DMA_OC3:  Compare 3 DMA request
  *            @arg PWM_DMA_OC4:  Compare 4 DMA request
  * @retval None
  */
#define __HAL_PWM_DISABLE_DMA(__HANDLE__, __DMA__)        ((__HANDLE__)->Instance->DIER &= ~(__DMA__))
#endif

/** @brief  Check whether the specified PWM interrupt flag is set or not.
  * @param  __HANDLE__ specifies the PWM Handle.
  * @param  __FLAG__ specifies the PWM interrupt flag to check.
  *        This parameter can be one of the following values:
  *            @arg PWM_FLAG_UPDATE: Update interrupt flag
  *            @arg PWM_FLAG_OC1: Compare 1 interrupt flag
  *            @arg PWM_FLAG_OC2: Compare 2 interrupt flag
  *            @arg PWM_FLAG_OC3: Compare 3 interrupt flag
  *            @arg PWM_FLAG_OC4: Compare 4 interrupt flag
  *            @arg PWM_FLAG_BREAK: Break interrupt flag
  *            @arg PWM_FLAG_CCR1OK: PWM_CCR1 register update completion flag
  *            @arg PWM_FLAG_CCR2OK: PWM_CCR2 register update completion flag
  *            @arg PWM_FLAG_CCR3OK: PWM_CCR3 register update completion flag
  *            @arg PWM_FLAG_CCR4OK: PWM_CCR4 register update completion flag
  *            @arg PWM_FLAG_CNTOK: PWM_CNT register update completion flag
  *            @arg PWM_FLAG_PSCOK: PWM_PSC register update completion flag
  *            @arg PWM_FLAG_ARROK: PWM_ARR register update completion flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_PWM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))

/** @brief  Clear the specified PWM interrupt flag.
  * @param  __HANDLE__ specifies the PWM Handle.
  * @param  __FLAG__ specifies the PWM interrupt flag to clear.
  *        This parameter can be one of the following values:
  *            @arg PWM_FLAG_UPDATE: Update interrupt flag
  *            @arg PWM_FLAG_OC1: Compare 1 interrupt flag
  *            @arg PWM_FLAG_OC2: Compare 2 interrupt flag
  *            @arg PWM_FLAG_OC3: Compare 3 interrupt flag
  *            @arg PWM_FLAG_OC4: Compare 4 interrupt flag
  *            @arg PWM_FLAG_BREAK: Break interrupt flag
  *            @arg PWM_FLAG_CCR1OK: PWM_CCR1 register update completion flag
  *            @arg PWM_FLAG_CCR2OK: PWM_CCR2 register update completion flag
  *            @arg PWM_FLAG_CCR3OK: PWM_CCR3 register update completion flag
  *            @arg PWM_FLAG_CCR4OK: PWM_CCR4 register update completion flag
  *            @arg PWM_FLAG_CNTOK: PWM_CNT register update completion flag
  *            @arg PWM_FLAG_PSCOK: PWM_PSC register update completion flag
  *            @arg PWM_FLAG_ARROK: PWM_ARR register update completion flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_PWM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  Check whether the specified PWM interrupt source is enabled or not.
  * @param  __HANDLE__ PWM handle
  * @param  __INTERRUPT__ specifies the PWM interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg PWM_IT_UPDATE: Update interrupt
  *            @arg PWM_IT_OC1:  Compare 1 interrupt
  *            @arg PWM_IT_OC2:  Compare 2 interrupt
  *            @arg PWM_IT_OC3:  Compare 3 interrupt
  *            @arg PWM_IT_OC4:  Compare 4 interrupt
  *            @arg PWM_IT_BREAK: Break interrupt
  * @retval The state of PWM_IT (SET or RESET).
  */
#define __HAL_PWM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) \
                                                             == (__INTERRUPT__)) ? SET : RESET)

/** @brief Clear the PWM interrupt pending bits.
  * @param  __HANDLE__ PWM handle
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  *          This parameter can be one of the following values:
  *            @arg PWM_IT_UPDATE: Update interrupt
  *            @arg PWM_IT_OC1:  Compare 1 interrupt
  *            @arg PWM_IT_OC2:  Compare 2 interrupt
  *            @arg PWM_IT_OC3:  Compare 3 interrupt
  *            @arg PWM_IT_OC4:  Compare 4 interrupt
  *            @arg PWM_IT_BREAK: Break interrupt
  * @retval None
  */
#define __HAL_PWM_CLEAR_IT(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))

/**
  * @brief  Indicates whether or not the PWM Counter is used as downcounter.
  * @param  __HANDLE__ PWM handle.
  * @retval False (Counter used as upcounter) or True (Counter used as downcounter)
  * @note This macro is particularly useful to get the counting mode when the pwm operates in Center-aligned mode or Encoder mode.
  */
#define __HAL_PWM_IS_PWM_COUNTING_DOWN(__HANDLE__)    (((__HANDLE__)->Instance->CR1 &(PWM_CR1_DIR)) == (PWM_CR1_DIR))

/**
  * @brief  Set the PWM Prescaler on runtime.
  * @param  __HANDLE__ PWM handle.
  * @param  __PRESC__ specifies the Prescaler new value.
  * @retval None
  */
#define __HAL_PWM_SET_PRESCALER(__HANDLE__, __PRESC__)       ((__HANDLE__)->Instance->PSC = (__PRESC__))

/**
  * @brief  Set the PWM Counter Register value on runtime.
  * @param  __HANDLE__ PWM handle.
  * @param  __COUNTER__ specifies the Counter register new value.
  * @retval None
  */
#define __HAL_PWM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))

/**
  * @brief  Get the PWM Counter Register value on runtime.
  * @param  __HANDLE__ PWM handle.
  * @retval value of the pwm counter register 
  */
#define __HAL_PWM_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CNT)

/**
  * @brief  Set the PWM Autoreload Register value on runtime without calling another time any Init function.
  * @param  __HANDLE__ PWM handle.
  * @param  __AUTORELOAD__ specifies the Counter register new value.
  * @retval None
  */
#define __HAL_PWM_SET_AUTORELOAD(__HANDLE__, __AUTORELOAD__) \
  do{                                                    \
    (__HANDLE__)->Instance->ARR = (__AUTORELOAD__);  \
    (__HANDLE__)->Init.Period = (__AUTORELOAD__);    \
  } while(0)

/**
  * @brief  Get the PWM Autoreload Register value on runtime.
  * @param  __HANDLE__ PWM handle.
  * @retval value of the pwm auto-reload register(PWMx_ARR)
  */
#define __HAL_PWM_GET_AUTORELOAD(__HANDLE__)  ((__HANDLE__)->Instance->ARR)

/**
  * @brief  Set the PWM Clock Division value on runtime without calling another time any Init function.
  * @param  __HANDLE__ PWM handle.
  * @param  __CKD__ specifies the clock division value.
  *          This parameter can be one of the following value:
  *            @arg PWM_CLOCKDIVISION_DIV1: tDTS=tCK_INT
  *            @arg PWM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT
  *            @arg PWM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT
  * @retval None
  */
#define __HAL_PWM_SET_CLOCKDIVISION(__HANDLE__, __CKD__) \
  do{                                                   \
    (__HANDLE__)->Instance->CR1 &= (~PWM_CR1_CKD);  \
    (__HANDLE__)->Instance->CR1 |= (__CKD__);       \
    (__HANDLE__)->Init.ClockDivision = (__CKD__);   \
  } while(0)

/**
  * @brief  Get the PWM Clock Division value on runtime.
  * @param  __HANDLE__ PWM handle.
  * @retval The clock division can be one of the following values:
  *            @arg PWM_CLOCKDIVISION_DIV1: tDTS=tCK_INT
  *            @arg PWM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT
  *            @arg PWM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT
  */
#define __HAL_PWM_GET_CLOCKDIVISION(__HANDLE__)  ((__HANDLE__)->Instance->CR1 & PWM_CR1_CKD)

/**
  * @brief  Set the PWM Compare Register value on runtime without calling another time ConfigChannel function.
  * @param  __HANDLE__ PWM handle.
  * @param  __CHANNEL__ PWM Channels to be configured.
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @param  __COMPARE__ specifies the Capture Compare register new value.
  * @retval None
  */
#define __HAL_PWM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__) \
  (((__CHANNEL__) == PWM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1 = (__COMPARE__)) :\
   ((__CHANNEL__) == PWM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2 = (__COMPARE__)) :\
   ((__CHANNEL__) == PWM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3 = (__COMPARE__)) :\
   ((__HANDLE__)->Instance->CCR4 = (__COMPARE__)))

/**
  * @brief  Get the PWM Capture Compare Register value on runtime.
  * @param  __HANDLE__ PWM handle.
  * @param  __CHANNEL__ PWM Channel associated with the capture compare register
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: get compare 1 register value
  *            @arg PWM_CHANNEL_2: get compare 2 register value
  *            @arg PWM_CHANNEL_3: get compare 3 register value
  *            @arg PWM_CHANNEL_4: get compare 4 register value
  * @retval value of the compare register
  */
#define __HAL_PWM_GET_COMPARE(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == PWM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1) :\
   ((__CHANNEL__) == PWM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2) :\
   ((__CHANNEL__) == PWM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3) :\
   ((__HANDLE__)->Instance->CCR4))

/**
  * @brief  Set the PWM Output compare preload.
  * @param  __HANDLE__ PWM handle.
  * @param  __CHANNEL__ PWM Channels to be configured.
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval None
  */
#define __HAL_PWM_ENABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == PWM_CHANNEL_1) ? ((__HANDLE__)->Instance->CMR |= PWM_CMR_OC1PE) :\
   ((__CHANNEL__) == PWM_CHANNEL_2) ? ((__HANDLE__)->Instance->CMR |= PWM_CMR_OC2PE) :\
   ((__CHANNEL__) == PWM_CHANNEL_3) ? ((__HANDLE__)->Instance->CMR |= PWM_CMR_OC3PE) :\
   ((__HANDLE__)->Instance->CMR |= PWM_CMR_OC4PE))

/**
  * @brief  Reset the PWM Output compare preload.
  * @param  __HANDLE__ PWM handle.
  * @param  __CHANNEL__ PWM Channels to be configured.
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval None
  */
#define __HAL_PWM_DISABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == PWM_CHANNEL_1) ? ((__HANDLE__)->Instance->CMR &= ~PWM_CMR_OC1PE) :\
   ((__CHANNEL__) == PWM_CHANNEL_2) ? ((__HANDLE__)->Instance->CMR &= ~PWM_CMR_OC2PE) :\
   ((__CHANNEL__) == PWM_CHANNEL_3) ? ((__HANDLE__)->Instance->CMR &= ~PWM_CMR_OC3PE) :\
   ((__HANDLE__)->Instance->CMR &= ~PWM_CMR_OC4PE))

/**
  * @brief  Set the Update Request Source (URS) bit of the PWMx_CR1 register.
  * @param  __HANDLE__ PWM handle.
  * @note  When the URS bit of the PWMx_CR1 register is set, only counter
  *        overflow/underflow generates an update interrupt or DMA request (if
  *        enabled)
  * @note  Depending on devices and packages, DMA may not be available.
  *        Refer to device datasheet for DMA availability.
  * @retval None
  */
#define __HAL_PWM_URS_ENABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1|= PWM_CR1_URS)

/**
  * @brief  Reset the Update Request Source (URS) bit of the PWMx_CR1 register.
  * @param  __HANDLE__ PWM handle.
  * @note  When the URS bit of the PWMx_CR1 register is reset, any of the
  *        following events generate an update interrupt or DMA request (if
  *        enabled):
  *           _ Counter overflow underflow
  *           _ Setting the UG bit
  *           _ Update generation through the slave mode controller
  * @note  Depending on devices and packages, DMA may not be available.
  *        Refer to device datasheet for DMA availability.
  * @retval None
  */
#define __HAL_PWM_URS_DISABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1&=~PWM_CR1_URS)

/**
  * @}
  */
/* End of exported macros ----------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup PWM_Private_Constants PWM Private Constants
  * @{
  */
/* The counter of a pwm instance is disabled only if all the Cx and CxN
   channels have been disabled */
#define PWM_CER_CxE_MASK  ((uint32_t)(PWM_CER_C1E | PWM_CER_C2E | PWM_CER_C3E | PWM_CER_C4E))
#define PWM_CER_CxNE_MASK ((uint32_t)(PWM_CER_C1NE | PWM_CER_C2NE ))
/**
  * @}
  */
/* End of private constants --------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/** @defgroup PWM_Private_Macros PWM Private Macros
  * @{
  */
#if (defined(DMA) || defined(DMA1))
#define IS_PWM_DMA_BASE(__BASE__) (((__BASE__) == PWM_DMABASE_CR1)   || \
                                   ((__BASE__) == PWM_DMABASE_CR2)   || \
                                   ((__BASE__) == PWM_DMABASE_SMCR)  || \
                                   ((__BASE__) == PWM_DMABASE_DIER)  || \
                                   ((__BASE__) == PWM_DMABASE_SR)    || \
                                   ((__BASE__) == PWM_DMABASE_EGR)   || \
                                   ((__BASE__) == PWM_DMABASE_CMR)   || \
                                   ((__BASE__) == PWM_DMABASE_CER)   || \
                                   ((__BASE__) == PWM_DMABASE_CNT)   || \
                                   ((__BASE__) == PWM_DMABASE_PSC)   || \
                                   ((__BASE__) == PWM_DMABASE_ARR)   || \
                                   ((__BASE__) == PWM_DMABASE_CCR1)  || \
                                   ((__BASE__) == PWM_DMABASE_CCR2)  || \
                                   ((__BASE__) == PWM_DMABASE_CCR3)  || \
                                   ((__BASE__) == PWM_DMABASE_CCR4)  || \
                                   ((__BASE__) == PWM_DMABASE_BDTR)  || \
                                   ((__BASE__) == PWM_DMABASE_DCR)   || \
                                   ((__BASE__) == PWM_DMABASE_DMAR))
#endif

#define IS_PWM_EVENT_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFFFFFEU) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))

#define IS_PWM_COUNTER_MODE(__MODE__)      (((__MODE__) == PWM_COUNTERMODE_UP)              || \
                                            ((__MODE__) == PWM_COUNTERMODE_DOWN)            || \
                                            ((__MODE__) == PWM_COUNTERMODE_CENTERALIGNED1)  || \
                                            ((__MODE__) == PWM_COUNTERMODE_CENTERALIGNED2)  || \
                                            ((__MODE__) == PWM_COUNTERMODE_CENTERALIGNED3))

#define IS_PWM_CLOCKDIVISION_DIV(__DIV__)  (((__DIV__) == PWM_CLOCKDIVISION_DIV1) || \
                                            ((__DIV__) == PWM_CLOCKDIVISION_DIV2) || \
                                            ((__DIV__) == PWM_CLOCKDIVISION_DIV4))

#define IS_PWM_AUTORELOAD_PRELOAD(PRELOAD) (((PRELOAD) == PWM_AUTORELOAD_PRELOAD_DISABLE) || \
                                            ((PRELOAD) == PWM_AUTORELOAD_PRELOAD_ENABLE))

#define IS_PWM_OC_POLARITY(__POLARITY__)   (((__POLARITY__) == PWM_OCPOLARITY_HIGH) || \
                                            ((__POLARITY__) == PWM_OCPOLARITY_LOW))

#define IS_PWM_OCN_POLARITY(__POLARITY__)  (((__POLARITY__) == PWM_OCNPOLARITY_HIGH) || \
                                            ((__POLARITY__) == PWM_OCNPOLARITY_LOW))

#define IS_PWM_DMA_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFFE0FFU) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))

#define IS_PWM_CHANNELS(__CHANNEL__)       (((__CHANNEL__) == PWM_CHANNEL_1) || \
                                            ((__CHANNEL__) == PWM_CHANNEL_2) || \
                                            ((__CHANNEL__) == PWM_CHANNEL_3) || \
                                            ((__CHANNEL__) == PWM_CHANNEL_4) || \
                                            ((__CHANNEL__) == PWM_CHANNEL_ALL))

#define IS_PWM_PERIOD(__PERIOD__) (((__PERIOD__) > 0U) && ((__PERIOD__) <= 0x0000FFFFU))
                                               
#define IS_PWM_COMPLEMENTARY_CHANNELS(__CHANNEL__) (((__CHANNEL__) == PWM_CHANNEL_1) || \
                                                    ((__CHANNEL__) == PWM_CHANNEL_2))

#define IS_PWM_CLOCKSOURCE(__CLOCK__) (((__CLOCK__) == PWM_CLOCKSOURCE_INTERNAL) || \
                                       ((__CLOCK__) == PWM_CLOCKSOURCE_ETRMODE))

#define IS_PWM_CLOCKPOLARITY(__POLARITY__) (((__POLARITY__) == PWM_CLOCKPOLARITY_INVERTED)    || \
                                            ((__POLARITY__) == PWM_CLOCKPOLARITY_NONINVERTED))

#define IS_PWM_CLOCKPRESCALER(__PRESCALER__) (((__PRESCALER__) == PWM_CLOCKPRESCALER_DIV1) || \
                                              ((__PRESCALER__) == PWM_CLOCKPRESCALER_DIV2) || \
                                              ((__PRESCALER__) == PWM_CLOCKPRESCALER_DIV4) || \
                                              ((__PRESCALER__) == PWM_CLOCKPRESCALER_DIV8))

#define IS_PWM_CLOCKFILTER(__ICFILTER__)      ((__ICFILTER__) <= 0xFU)

#define IS_PWM_LOCK_LEVEL(__LEVEL__)       (((__LEVEL__) == PWM_LOCKLEVEL_OFF) || \
                                            ((__LEVEL__) == PWM_LOCKLEVEL_1)   || \
                                            ((__LEVEL__) == PWM_LOCKLEVEL_2)   || \
                                            ((__LEVEL__) == PWM_LOCKLEVEL_3))

#define IS_PWM_BREAK_STATE(__STATE__)      (((__STATE__) == PWM_BREAK_ENABLE) || \
                                            ((__STATE__) == PWM_BREAK_DISABLE))

#define IS_PWM_BREAK_POLARITY(__POLARITY__) (((__POLARITY__) == PWM_BREAKPOLARITY_LOW) || \
                                             ((__POLARITY__) == PWM_BREAKPOLARITY_HIGH))

#define IS_PWM_AUTOMATIC_OUTPUT_STATE(__STATE__) (((__STATE__) == PWM_AUTOMATICOUTPUT_ENABLE) || \
                                                  ((__STATE__) == PWM_AUTOMATICOUTPUT_DISABLE))

#define IS_PWM_MSM_STATE(__STATE__)      (((__STATE__) == PWM_MASTERSLAVEMODE_ENABLE) || \
                                          ((__STATE__) == PWM_MASTERSLAVEMODE_DISABLE))

#define IS_PWM_PWM_MODE(__MODE__) (((__MODE__) == PWM_OCMODE_PWM1)               || \
                                   ((__MODE__) == PWM_OCMODE_PWM2))

#if (defined(DMA) || defined(DMA1))
#define IS_PWM_DMA_LENGTH(__LENGTH__)      (((__LENGTH__) == PWM_DMABURSTLENGTH_1TRANSFER) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_2TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_3TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_4TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_5TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_6TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_7TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_8TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_9TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_10TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_11TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_12TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_13TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_14TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_15TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_16TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_17TRANSFERS) || \
                                            ((__LENGTH__) == PWM_DMABURSTLENGTH_18TRANSFERS))

#define IS_PWM_DMA_DATA_LENGTH(LENGTH) (((LENGTH) >= 0x1U) && ((LENGTH) < 0x10000U))
#endif

#define IS_PWM_DEADPWME(__DEADPWME__)    ((__DEADPWME__) <= 0xFFU)

/**
  * @}
  */
/* End of private macros -----------------------------------------------------*/

/* Include PWM HAL Extended module */
#include "py32c882_hal_pwm_ex.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PWM_Exported_Functions PWM Exported Functions
  * @{
  */

/** @addtogroup PWM_Exported_Functions_Group1 PWM Time Base functions
  *  @brief   Time Base functions
  * @{
  */
/* Time Base functions ********************************************************/
HAL_StatusTypeDef HAL_PWM_Base_Init(PWM_HandleTypeDef *hpwm);
HAL_StatusTypeDef HAL_PWM_Base_DeInit(PWM_HandleTypeDef *hpwm);
void HAL_PWM_Base_MspInit(PWM_HandleTypeDef *hpwm);
void HAL_PWM_Base_MspDeInit(PWM_HandleTypeDef *hpwm);
/* Blocking mode: Polling */
HAL_StatusTypeDef HAL_PWM_Base_Start(PWM_HandleTypeDef *hpwm);
HAL_StatusTypeDef HAL_PWM_Base_Stop(PWM_HandleTypeDef *hpwm);
/* Non-Blocking mode: Interrupt */
HAL_StatusTypeDef HAL_PWM_Base_Start_IT(PWM_HandleTypeDef *hpwm);
HAL_StatusTypeDef HAL_PWM_Base_Stop_IT(PWM_HandleTypeDef *hpwm);
#if (defined(DMA) || defined(DMA1))
/* Non-Blocking mode: DMA */
HAL_StatusTypeDef HAL_PWM_Base_Start_DMA(PWM_HandleTypeDef *hpwm, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_PWM_Base_Stop_DMA(PWM_HandleTypeDef *hpwm);
#endif
/**
  * @}
  */

/** @addtogroup PWM_Exported_Functions_Group2 PWM PWM functions
  *  @brief   PWM PWM functions
  * @{
  */
/* pwm PWM functions ********************************************************/
HAL_StatusTypeDef HAL_PWM_PWM_Init(PWM_HandleTypeDef *hpwm);
HAL_StatusTypeDef HAL_PWM_PWM_DeInit(PWM_HandleTypeDef *hpwm);
void HAL_PWM_PWM_MspInit(PWM_HandleTypeDef *hpwm);
void HAL_PWM_PWM_MspDeInit(PWM_HandleTypeDef *hpwm);
/* Blocking mode: Polling */
HAL_StatusTypeDef HAL_PWM_PWM_Start(PWM_HandleTypeDef *hpwm, uint32_t Channel);
HAL_StatusTypeDef HAL_PWM_PWM_Stop(PWM_HandleTypeDef *hpwm, uint32_t Channel);
/* Non-Blocking mode: Interrupt */
HAL_StatusTypeDef HAL_PWM_PWM_Start_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel);
HAL_StatusTypeDef HAL_PWM_PWM_Stop_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel);
#if (defined(DMA) || defined(DMA1))
/* Non-Blocking mode: DMA */
HAL_StatusTypeDef HAL_PWM_PWM_Start_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_PWM_PWM_Stop_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel);
#endif
/**
  * @}
  */

/** @addtogroup PWM_Exported_Functions_Group3 PWM IRQ handler management
  *  @brief   IRQ handler management
  * @{
  */
/* Interrupt Handler functions  ***********************************************/
void HAL_PWM_IRQHandler(PWM_HandleTypeDef *hpwm);
/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Group4 PWM Peripheral Control functions
  *  @brief   Peripheral Control functions
  * @{
  */
/* Control functions  *********************************************************/
HAL_StatusTypeDef HAL_PWM_PWM_ConfigChannel(PWM_HandleTypeDef *hpwm, PWM_OC_InitTypeDef *sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_PWM_ConfigClockSource(PWM_HandleTypeDef *hpwm, PWM_ClockConfigTypeDef *sClockSourceConfig);
#if (defined(DMA) || defined(DMA1))
HAL_StatusTypeDef HAL_PWM_DMABurst_WriteStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength);
HAL_StatusTypeDef HAL_PWM_DMABurst_MultiWriteStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t *BurstBuffer, uint32_t BurstLength,
    uint32_t DataLength);
HAL_StatusTypeDef HAL_PWM_DMABurst_WriteStop(PWM_HandleTypeDef *hpwm, uint32_t BurstRequestSrc);
HAL_StatusTypeDef HAL_PWM_DMABurst_ReadStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength);
HAL_StatusTypeDef HAL_PWM_DMABurst_MultiReadStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength,
    uint32_t  DataLength);
HAL_StatusTypeDef HAL_PWM_DMABurst_ReadStop(PWM_HandleTypeDef *hpwm, uint32_t BurstRequestSrc);
#endif
HAL_StatusTypeDef HAL_PWM_GenerateEvent(PWM_HandleTypeDef *hpwm, uint32_t EventSource);
/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Group5 PWM Callbacks functions
  *  @brief   PWM Callbacks functions
  * @{
  */
/* Callback in non blocking modes (Interrupt and DMA) *************************/
void HAL_PWM_PeriodElapsedCallback(PWM_HandleTypeDef *hpwm);
void HAL_PWM_PeriodElapsedHalfCpltCallback(PWM_HandleTypeDef *hpwm);
void HAL_PWM_PWM_PulseFinishedCallback(PWM_HandleTypeDef *hpwm);
void HAL_PWM_PWM_PulseFinishedHalfCpltCallback(PWM_HandleTypeDef *hpwm);
void HAL_PWM_ErrorCallback(PWM_HandleTypeDef *hpwm);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_PWM_RegisterCallback(PWM_HandleTypeDef *hpwm, HAL_PWM_CallbackIDTypeDef CallbackID,
    pPWM_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_PWM_UnRegisterCallback(PWM_HandleTypeDef *hpwm, HAL_PWM_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Group6 PWM Peripheral State functions
  *  @brief  Peripheral State functions
  * @{
  */
/* Peripheral State functions  ************************************************/
HAL_PWM_StateTypeDef HAL_PWM_Base_GetState(PWM_HandleTypeDef *hpwm);
HAL_PWM_StateTypeDef HAL_PWM_PWM_GetState(PWM_HandleTypeDef *hpwm);
/**
  * @}
  */

/**
  * @}
  */
/* End of exported functions -------------------------------------------------*/

/* Private functions----------------------------------------------------------*/
/** @defgroup PWM_Private_Functions PWM Private Functions
  * @{
  */
HAL_StatusTypeDef PWM_Base_SetConfig(PWM_TypeDef *PWMx, PWM_Base_InitTypeDef *Structure);
void PWM_ETR_SetConfig(PWM_TypeDef *PWMx, uint32_t PWM_ExtTRGPrescaler,
                       uint32_t PWM_ExtTRGPolarity, uint32_t ExtTRGFilter);
#if (defined(DMA) || defined(DMA1))
void PWM_DMADelayPulseCplt(DMA_HandleTypeDef *hdma);
void PWM_DMADelayPulseHalfCplt(DMA_HandleTypeDef *hdma);
void PWM_DMAError(DMA_HandleTypeDef *hdma);
#endif
void PWM_OCxChannelCmd(PWM_TypeDef *PWMx, uint32_t Channel, uint32_t ChannelState);

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
void PWM_ResetCallback(PWM_HandleTypeDef *hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* End of private functions --------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* py32c882_HAL_PWM_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
