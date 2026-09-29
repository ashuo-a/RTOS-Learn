/**
  ******************************************************************************
  * @file    py32c882_ll_pwm.h
  * @author  MCU Application Team
  * @brief   Header file of PWM LL module.
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
#ifndef __PY32C882_LL_PWM_H
#define __PY32C882_LL_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c8xx.h"

/** @addtogroup PY32C882_LL_Driver
  * @{
  */

#if defined (PWM)

/** @defgroup PWM_LL PWM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup PWM_LL_Private_Variables PWM Private Variables
  * @{
  */
static const uint8_t OFFSET_TAB_CMR[] =
{
  0x00U,   /* 0: PWMx_CH1  */
  0x00U,   /* 1: PWMx_CH1N */
  0x00U,   /* 2: PWMx_CH2  */
  0x00U,   /* 3: PWMx_CH2N */
  0x00U,   /* 4: PWMx_CH3  */
  0x00U    /* 5: PWMx_CH4  */
};

static const uint8_t SHIFT_TAB_OCxM[] =
{
  0U,            /* 0: OC1M */
  0U,            /* 1: - NA */
  2U,            /* 2: OC2M */
  2U,            /* 3: - NA */
  4U,            /* 4: OC3M */
  6U             /* 5: OC4M */
};

static const uint8_t SHIFT_TAB_OCxPE[] =
{
  0U,            /* 0: OC1PE */
  0U,            /* 1: - NA */
  1U,            /* 2: OC2PE */
  1U,            /* 3: - NA */
  2U,            /* 4: OC3PE */
  3U             /* 5: OC4PE */
};

static const uint8_t SHIFT_TAB_CxP[] =
{
  0U,            /* 0: C1P */
  2U,            /* 1: C1NP */
  4U,            /* 2: C2P */
  6U,            /* 3: C2NP */
  8U,            /* 4: C3P */
  12U            /* 5: C4P */
};

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup PWM_LL_Private_Constants PWM Private Constants
  * @{
  */

/* Defines used for the bit position in the register and perform offsets */
#define PWM_POSITION_BRK_SOURCE            (POSITION_VAL(Source) & 0x1FUL)

/* Generic bit definitions for PWMx_CR2 register */
#define PWMx_CR2_BKINP     PWM_CR2_BKINP     /*!< BRK BKIN input polarity */
#define PWMx_CR2_ETRSEL    PWM_CR2_ETRSEL    /*!< PWMx ETR source selection */

/* Mask used to set the TDG[x:0] of the DTG bits of the PWMx_BDTR register */
#define DT_DELAY_1 ((uint8_t)0x7F)
#define DT_DELAY_2 ((uint8_t)0x3F)
#define DT_DELAY_3 ((uint8_t)0x1F)
#define DT_DELAY_4 ((uint8_t)0x1F)

/* Mask used to set the DTG[7:5] bits of the DTG bits of the PWMx_BDTR register */
#define DT_RANGE_1 ((uint8_t)0x00)
#define DT_RANGE_2 ((uint8_t)0x80)
#define DT_RANGE_3 ((uint8_t)0xC0)
#define DT_RANGE_4 ((uint8_t)0xE0)

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup PWM_LL_Private_Macros PWM Private Macros
  * @{
  */
/** @brief  Convert channel id into channel index.
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH1N
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH2N
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval none
  */
#define PWM_GET_CHANNEL_INDEX( __CHANNEL__) \
  (((__CHANNEL__) == LL_PWM_CHANNEL_CH1) ? 0U :\
   ((__CHANNEL__) == LL_PWM_CHANNEL_CH1N) ? 1U :\
   ((__CHANNEL__) == LL_PWM_CHANNEL_CH2) ? 2U :\
   ((__CHANNEL__) == LL_PWM_CHANNEL_CH2N) ? 3U :\
   ((__CHANNEL__) == LL_PWM_CHANNEL_CH3) ? 4U : 5U)

/** @brief  Calculate the deadtime sampling period(in ps).
  * @param  __PWMCLK__ pwm input clock frequency (in Hz).
  * @param  __CKD__ This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV1
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV2
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV4
  * @retval none
  */
#define PWM_CALC_DTS(__PWMCLK__, __CKD__)                                                        \
  (((__CKD__) == LL_PWM_CLOCKDIVISION_DIV1) ? ((uint64_t)1000000000000U/(__PWMCLK__))         : \
   ((__CKD__) == LL_PWM_CLOCKDIVISION_DIV2) ? ((uint64_t)1000000000000U/((__PWMCLK__) >> 1U)) : \
   ((uint64_t)1000000000000U/((__PWMCLK__) >> 2U)))
/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PWM_LL_ES_INIT PWM Exported Init structure
  * @{
  */

/**
  * @brief  PWM Time Base configuration structure definition.
  */
typedef struct
{
  uint16_t Prescaler;         /*!< Specifies the prescaler value used to divide the PWM clock.
                                   This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                                   This feature can be modified afterwards using unitary function @ref LL_PWM_SetPrescaler().*/

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref PWM_LL_EC_COUNTERMODE.

                                   This feature can be modified afterwards using unitary function @ref LL_PWM_SetCounterMode().*/

  uint32_t Autoreload;        /*!< Specifies the auto reload value to be loaded into the active
                                   Auto-Reload Register at the next update event.
                                   This parameter must be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                                   This feature can be modified afterwards using unitary function @ref LL_PWM_SetAutoReload().*/

  uint32_t ClockDivision;     /*!< Specifies the clock division.
                                   This parameter can be a value of @ref PWM_LL_EC_CLOCKDIVISION.

                                   This feature can be modified afterwards using unitary function @ref LL_PWM_SetClockDivision().*/
} LL_PWM_InitTypeDef;

/**
  * @brief  PWM Output Compare configuration structure definition.
  */
typedef struct
{
  uint32_t OCMode;        /*!< Specifies the output mode.
                               This parameter can be a value of @ref PWM_LL_EC_OCMODE.

                               This feature can be modified afterwards using unitary function @ref LL_PWM_OC_SetMode().*/

  uint32_t OCState;       /*!< Specifies the PWM Output Compare state.
                               This parameter can be a value of @ref PWM_LL_EC_OCSTATE.

                               This feature can be modified afterwards using unitary functions @ref LL_PWM_OC_EnableChannel() or @ref LL_PWM_OC_DisableChannel().*/

  uint32_t OCNState;      /*!< Specifies the PWM complementary Output Compare state.
                               This parameter can be a value of @ref PWM_LL_EC_OCSTATE.

                               This feature can be modified afterwards using unitary functions @ref LL_PWM_OC_EnableChannel() or @ref LL_PWM_OC_DisableChannel().*/

  uint32_t CompareValue;  /*!< Specifies the Compare value to be loaded into the Capture Compare Register.
                               This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                               This feature can be modified afterwards using unitary function LL_PWM_OC_SetCompareCHx (x=1..4).*/

  uint32_t OCPolarity;    /*!< Specifies the output polarity.
                               This parameter can be a value of @ref PWM_LL_EC_OCPOLARITY.

                               This feature can be modified afterwards using unitary function @ref LL_PWM_OC_SetPolarity().*/

  uint32_t OCNPolarity;   /*!< Specifies the complementary output polarity.
                               This parameter can be a value of @ref PWM_LL_EC_OCPOLARITY.

                               This feature can be modified afterwards using unitary function @ref LL_PWM_OC_SetPolarity().*/
} LL_PWM_OC_InitTypeDef;

/**
  * @brief  BDTR (Break and Dead Time) structure definition
  */
typedef struct
{
  uint32_t LockLevel;            /*!< Specifies the LOCK level parameters.
                                      This parameter can be a value of @ref PWM_LL_EC_LOCKLEVEL

                                      @note The LOCK bits can be written only once after the reset. Once the PWMx_BDTR register
                                            has been written, their content is frozen until the next reset.*/

  uint8_t DeadTime;              /*!< Specifies the delay time between the switching-off and the
                                      switching-on of the outputs.
                                      This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF.

                                      This feature can be modified afterwards using unitary function @ref LL_PWM_OC_SetDeadTime()

                                      @note This bit-field can not be modified as long as LOCK level 1, 2 or 3 has been programmed. */

  uint16_t BreakState;           /*!< Specifies whether the PWM Break input is enabled or not.
                                      This parameter can be a value of @ref PWM_LL_EC_BREAK_ENABLE

                                      This feature can be modified afterwards using unitary functions @ref LL_PWM_EnableBRK() or @ref LL_PWM_DisableBRK()

                                      @note This bit-field can not be modified as long as LOCK level 1 has been programmed. */

  uint32_t BreakPolarity;        /*!< Specifies the PWM Break Input pin polarity.
                                      This parameter can be a value of @ref PWM_LL_EC_BREAK_POLARITY

                                      This feature can be modified afterwards using unitary function @ref LL_PWM_ConfigBRK()

                                      @note This bit-field can not be modified as long as LOCK level 1 has been programmed. */

  uint32_t AutomaticOutput;      /*!< Specifies whether the PWM Automatic Output feature is enabled or not.
                                      This parameter can be a value of @ref PWM_LL_EC_AUTOMATICOUTPUT_ENABLE

                                      This feature can be modified afterwards using unitary functions @ref LL_PWM_EnableAutomaticOutput() or @ref LL_PWM_DisableAutomaticOutput()

                                      @note This bit-field can not be modified as long as LOCK level 1 has been programmed. */
} LL_PWM_BDTR_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup PWM_LL_Exported_Constants PWM Exported Constants
  * @{
  */

/** @defgroup PWM_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_PWM_ReadReg function.
  * @{
  */
#define LL_PWM_SR_UIF                          PWM_SR_UIF           /*!< Update interrupt flag */
#define LL_PWM_SR_OC1IF                        PWM_SR_OC1IF         /*!< compare 1 interrupt flag */
#define LL_PWM_SR_OC2IF                        PWM_SR_OC2IF         /*!< compare 2 interrupt flag */
#define LL_PWM_SR_OC3IF                        PWM_SR_OC3IF         /*!< compare 3 interrupt flag */
#define LL_PWM_SR_OC4IF                        PWM_SR_OC4IF         /*!< compare 4 interrupt flag */
#define LL_PWM_SR_BIF                          PWM_SR_BIF           /*!< Break interrupt flag */
#define LL_PWM_SR_CCR1OK                       PWM_SR_CCR1OK        /*!< PWM_CCR1 register update completion flag */
#define LL_PWM_SR_CCR2OK                       PWM_SR_CCR2OK        /*!< PWM_CCR2 register update completion flag */
#define LL_PWM_SR_CCR3OK                       PWM_SR_CCR3OK        /*!< PWM_CCR3 register update completion flag */
#define LL_PWM_SR_CCR4OK                       PWM_SR_CCR4OK        /*!< PWM_CCR4 register update completion flag */
#define LL_PWM_SR_CNTOK                        PWM_SR_CNTOK         /*!< PWM_CNT register update completion flag */
#define LL_PWM_SR_PSCOK                        PWM_SR_PSCOK         /*!< PWM_PSC register update completion flag */
#define LL_PWM_SR_ARROK                        PWM_SR_ARROK         /*!< PWM_ARR register update completion flag */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PWM_LL_EC_BREAK_ENABLE Break Enable
  * @{
  */
#define LL_PWM_BREAK_DISABLE            0x00000000U             /*!< Break function disabled */
#define LL_PWM_BREAK_ENABLE             PWM_BDTR_BKE            /*!< Break function enabled */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_AUTOMATICOUTPUT_ENABLE Automatic output enable
  * @{
  */
#define LL_PWM_AUTOMATICOUTPUT_DISABLE         0x00000000U             /*!< MOE can be set only by software */
#define LL_PWM_AUTOMATICOUTPUT_ENABLE          PWM_BDTR_AOE            /*!< MOE can be set by software or automatically at the next update event */
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/** @defgroup PWM_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_PWM_ReadReg and  LL_PWM_WriteReg functions.
  * @{
  */
#define LL_PWM_DIER_UIE                        PWM_DIER_UIE         /*!< Update interrupt enable */
#define LL_PWM_DIER_OC1IE                      PWM_DIER_OC1IE       /*!< compare 1 interrupt enable */
#define LL_PWM_DIER_OC2IE                      PWM_DIER_OC2IE       /*!< compare 2 interrupt enable */
#define LL_PWM_DIER_OC3IE                      PWM_DIER_OC3IE       /*!< compare 3 interrupt enable */
#define LL_PWM_DIER_OC4IE                      PWM_DIER_OC4IE       /*!< compare 4 interrupt enable */
#define LL_PWM_DIER_BIE                        PWM_DIER_BIE         /*!< Break interrupt enable */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_UPDATESOURCE Update Source
  * @{
  */
#define LL_PWM_UPDATESOURCE_REGULAR            0x00000000U          /*!< Counter overflow/underflow, Setting the UG bit or Update generation through the slave mode controller generates an update request */
#define LL_PWM_UPDATESOURCE_COUNTER            PWM_CR1_URS          /*!< Only counter overflow/underflow generates an update request */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_COUNTERMODE Counter Mode
  * @{
  */
#define LL_PWM_COUNTERMODE_UP                  0x00000000U          /*!<Counter used as upcounter */
#define LL_PWM_COUNTERMODE_DOWN                PWM_CR1_DIR          /*!< Counter used as downcounter */
#define LL_PWM_COUNTERMODE_CENTER_DOWN         PWM_CR1_CMS_0        /*!< The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting down. */
#define LL_PWM_COUNTERMODE_CENTER_UP           PWM_CR1_CMS_1        /*!<The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting up */
#define LL_PWM_COUNTERMODE_CENTER_UP_DOWN      PWM_CR1_CMS          /*!< The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting up or down. */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_CLOCKDIVISION Clock Division
  * @{
  */
#define LL_PWM_CLOCKDIVISION_DIV1              0x00000000U          /*!< tDTS=tCK_INT */
#define LL_PWM_CLOCKDIVISION_DIV2              PWM_CR1_CKD_0        /*!< tDTS=2*tCK_INT */
#define LL_PWM_CLOCKDIVISION_DIV4              PWM_CR1_CKD_1        /*!< tDTS=4*tCK_INT */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_COUNTERDIRECTION Counter Direction
  * @{
  */
#define LL_PWM_COUNTERDIRECTION_UP             0x00000000U          /*!< Pwm counter counts up */
#define LL_PWM_COUNTERDIRECTION_DOWN           PWM_CR1_DIR          /*!< Pwm counter counts down */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_LOCKLEVEL Lock Level
  * @{
  */
#define LL_PWM_LOCKLEVEL_OFF                   0x00000000U          /*!< LOCK OFF - No bit is write protected */
#define LL_PWM_LOCKLEVEL_1                     PWM_BDTR_LOCK_0      /*!< LOCK Level 1 */
#define LL_PWM_LOCKLEVEL_2                     PWM_BDTR_LOCK_1      /*!< LOCK Level 2 */
#define LL_PWM_LOCKLEVEL_3                     PWM_BDTR_LOCK        /*!< LOCK Level 3 */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_CHANNEL Channel
  * @{
  */
#define LL_PWM_CHANNEL_CH1                     PWM_CER_C1E     /*!< Pwm input/output channel 1 */
#define LL_PWM_CHANNEL_CH1N                    PWM_CER_C1NE    /*!< Pwm complementary output channel 1 */
#define LL_PWM_CHANNEL_CH2                     PWM_CER_C2E     /*!< Pwm input/output channel 2 */
#define LL_PWM_CHANNEL_CH2N                    PWM_CER_C2NE    /*!< Pwm complementary output channel 2 */
#define LL_PWM_CHANNEL_CH3                     PWM_CER_C3E     /*!< Pwm input/output channel 3 */
#define LL_PWM_CHANNEL_CH4                     PWM_CER_C4E     /*!< Pwm input/output channel 4 */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PWM_LL_EC_OCSTATE Output Configuration State
  * @{
  */
#define LL_PWM_OCSTATE_DISABLE                 0x00000000U             /*!< OCx is not active */
#define LL_PWM_OCSTATE_ENABLE                  PWM_CER_C1E           /*!< OCx signal is output on the corresponding output pin */
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/** @defgroup PWM_LL_EC_OCMODE Output Configuration Mode
  * @{
  */
#define LL_PWM_OCMODE_PWM1                     (PWM_CMR_OC1M_1)                    /*!<In upcounting, channel y is active as long as PWMx_CNT<PWMx_CCRy else inactive.  In downcounting, channel y is inactive as long as PWMx_CNT>PWMx_CCRy else active.*/
#define LL_PWM_OCMODE_PWM2                     (PWM_CMR_OC1M_1 | PWM_CMR_OC1M_0)   /*!<In upcounting, channel y is inactive as long as PWMx_CNT<PWMx_CCRy else active.  In downcounting, channel y is active as long as PWMx_CNT>PWMx_CCRy else inactive*/
/**
  * @}
  */

/** @defgroup PWM_LL_EC_OCPOLARITY Output Configuration Polarity
  * @{
  */
#define LL_PWM_OCPOLARITY_HIGH                 0x00000000U                 /*!< OCxactive high*/
#define LL_PWM_OCPOLARITY_LOW                  PWM_CER_C1P               /*!< OCxactive low*/
/**
  * @}
  */

/** @defgroup PWM_LL_EC_CLOCKSOURCE Clock Source
  * @{
  */
#define LL_PWM_CLOCKSOURCE_INTERNAL            0x00000000U                                          /*!< The pwm is clocked by the internal clock provided from the RCC */
#define LL_PWM_CLOCKSOURCE_EXT_MODE           PWM_SMCR_ECE                                         /*!< Counter counts at each rising or falling edge on the external trigger input ETR */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_ETR_POLARITY External Trigger Polarity
  * @{
  */
#define LL_PWM_ETR_POLARITY_NONINVERTED        0x00000000U             /*!< ETR is non-inverted, active at high level or rising edge */
#define LL_PWM_ETR_POLARITY_INVERTED           PWM_SMCR_ETP            /*!< ETR is inverted, active at low level or falling edge */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_ETR_PRESCALER External Trigger Prescaler
  * @{
  */
#define LL_PWM_ETR_PRESCALER_DIV1              0x00000000U             /*!< ETR prescaler OFF */
#define LL_PWM_ETR_PRESCALER_DIV2              PWM_SMCR_ETPS_0         /*!< ETR frequency is divided by 2 */
#define LL_PWM_ETR_PRESCALER_DIV4              PWM_SMCR_ETPS_1         /*!< ETR frequency is divided by 4 */
#define LL_PWM_ETR_PRESCALER_DIV8              PWM_SMCR_ETPS           /*!< ETR frequency is divided by 8 */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_ETR_FILTER External Trigger Filter
  * @{
  */
#define LL_PWM_ETR_FILTER_FDIV1                0x00000000U                                          /*!< No filter, sampling is done at fDTS */
#define LL_PWM_ETR_FILTER_FDIV1_N2             PWM_SMCR_ETF_0                                       /*!< fSAMPLING=fCK_INT, N=2 */
#define LL_PWM_ETR_FILTER_FDIV1_N4             PWM_SMCR_ETF_1                                       /*!< fSAMPLING=fCK_INT, N=4 */
#define LL_PWM_ETR_FILTER_FDIV1_N8             (PWM_SMCR_ETF_1 | PWM_SMCR_ETF_0)                    /*!< fSAMPLING=fCK_INT, N=8 */
#define LL_PWM_ETR_FILTER_FDIV2_N6             PWM_SMCR_ETF_2                                       /*!< fSAMPLING=fDTS/2, N=6 */
#define LL_PWM_ETR_FILTER_FDIV2_N8             (PWM_SMCR_ETF_2 | PWM_SMCR_ETF_0)                    /*!< fSAMPLING=fDTS/2, N=8 */
#define LL_PWM_ETR_FILTER_FDIV4_N6             (PWM_SMCR_ETF_2 | PWM_SMCR_ETF_1)                    /*!< fSAMPLING=fDTS/4, N=6 */
#define LL_PWM_ETR_FILTER_FDIV4_N8             (PWM_SMCR_ETF_2 | PWM_SMCR_ETF_1 | PWM_SMCR_ETF_0)   /*!< fSAMPLING=fDTS/4, N=8 */
#define LL_PWM_ETR_FILTER_FDIV8_N6             PWM_SMCR_ETF_3                                       /*!< fSAMPLING=fDTS/8, N=8 */
#define LL_PWM_ETR_FILTER_FDIV8_N8             (PWM_SMCR_ETF_3 | PWM_SMCR_ETF_0)                    /*!< fSAMPLING=fDTS/16, N=5 */
#define LL_PWM_ETR_FILTER_FDIV16_N5            (PWM_SMCR_ETF_3 | PWM_SMCR_ETF_1)                    /*!< fSAMPLING=fDTS/16, N=6 */
#define LL_PWM_ETR_FILTER_FDIV16_N6            (PWM_SMCR_ETF_3 | PWM_SMCR_ETF_1 | PWM_SMCR_ETF_0)   /*!< fSAMPLING=fDTS/16, N=8 */
#define LL_PWM_ETR_FILTER_FDIV16_N8            (PWM_SMCR_ETF_3 | PWM_SMCR_ETF_2)                    /*!< fSAMPLING=fDTS/16, N=5 */
#define LL_PWM_ETR_FILTER_FDIV32_N5            (PWM_SMCR_ETF_3 | PWM_SMCR_ETF_2 | PWM_SMCR_ETF_0)   /*!< fSAMPLING=fDTS/32, N=5 */
#define LL_PWM_ETR_FILTER_FDIV32_N6            (PWM_SMCR_ETF_3 | PWM_SMCR_ETF_2 | PWM_SMCR_ETF_1)   /*!< fSAMPLING=fDTS/32, N=6 */
#define LL_PWM_ETR_FILTER_FDIV32_N8            PWM_SMCR_ETF                                         /*!< fSAMPLING=fDTS/32, N=8 */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_PWM_ETRSOURCE External Trigger Source PWM
  * @{
  */
#define LL_PWM_PWM_ETRSOURCE_GPIO_LS     0x00000000U                                                  /*!< ETR input is connected to GPIO_LS */
#define LL_PWM_PWM_ETRSOURCE_COMP1       PWM_CR2_ETRSEL_0                                             /*!< ETR input is connected to COMP1_OUT */
#define LL_PWM_PWM_ETRSOURCE_COMP2       PWM_CR2_ETRSEL_1                                             /*!< ETR input is connected to COMP2_OUT */
#define LL_PWM_PWM_ETRSOURCE_SYS_CLK     PWM_CR2_ETRSEL_2                                             /*!< ETR input is connected to System clock */
#define LL_PWM_PWM_ETRSOURCE_GPIO_HS     (PWM_CR2_ETRSEL_2 | PWM_CR2_ETRSEL_0)                        /*!< ETR input is connected to GPIO_HS */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_BREAK_POLARITY break polarity
  * @{
  */
#define LL_PWM_BREAK_POLARITY_LOW              0x00000000U               /*!< Break input BRK is active low */
#define LL_PWM_BREAK_POLARITY_HIGH             PWM_BDTR_BKP              /*!< Break input BRK is active high */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_BREAK_INPUT BREAK INPUT
  * @{
  */
#define LL_PWM_BREAK_INPUT_BKIN                0x00000000U  /*!< PWMx_BKIN input */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_BKIN_SOURCE BKIN SOURCE
  * @{
  */
#define LL_PWM_BKIN_SOURCE_BKIN                PWM_CR2_BKINE      /*!< BKIN input from AF controller */
#define LL_PWM_BKIN_SOURCE_BKCOMP1             PWM_CR2_BKCMP1E    /*!< internal signal: COMP1 output */
#define LL_PWM_BKIN_SOURCE_BKCOMP2             PWM_CR2_BKCMP2E    /*!< internal signal: COMP2 output */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_BKIN_POLARITY BKIN POLARITY
  * @{
  */
#define LL_PWM_BKIN_POLARITY_LOW               PWM_CR2_BKINP           /*!< BRK BKIN input is active low */
#define LL_PWM_BKIN_POLARITY_HIGH              0x00000000U              /*!< BRK BKIN input is active high */
/**
  * @}
  */

#if (defined(DMA) || defined(DMA1))
/** @defgroup PWM_LL_EC_DMABURST_BASEADDR DMA Burst Base Address
  * @{
  */
#define LL_PWM_DMABURST_BASEADDR_CR1           0x00000000U                                                      /*!< PWMx_CR1 register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CR2           PWM_DCR_DBA_0                                                    /*!< PWMx_CR2 register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_SMCR          PWM_DCR_DBA_1                                                    /*!< PWMx_SMCR register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_DIER          (PWM_DCR_DBA_1 |  PWM_DCR_DBA_0)                                 /*!< PWMx_DIER register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_SR            PWM_DCR_DBA_2                                                    /*!< PWMx_SR register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_EGR           (PWM_DCR_DBA_2 | PWM_DCR_DBA_0)                                  /*!< PWMx_EGR register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CMR           (PWM_DCR_DBA_2 | PWM_DCR_DBA_1)                                  /*!< PWMx_CMR register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CER           PWM_DCR_DBA_3                                                    /*!< PWMx_CER register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CNT           (PWM_DCR_DBA_3 | PWM_DCR_DBA_0)                                  /*!< PWMx_CNT register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_PSC           (PWM_DCR_DBA_3 | PWM_DCR_DBA_1)                                  /*!< PWMx_PSC register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_ARR           (PWM_DCR_DBA_3 | PWM_DCR_DBA_1 | PWM_DCR_DBA_0)                  /*!< PWMx_ARR register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CCR1          (PWM_DCR_DBA_3 | PWM_DCR_DBA_2 | PWM_DCR_DBA_0)                  /*!< PWMx_CCR1 register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CCR2          (PWM_DCR_DBA_3 | PWM_DCR_DBA_2 | PWM_DCR_DBA_1)                  /*!< PWMx_CCR2 register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CCR3          (PWM_DCR_DBA_3 | PWM_DCR_DBA_2 | PWM_DCR_DBA_1 | PWM_DCR_DBA_0)  /*!< PWMx_CCR3 register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_CCR4          PWM_DCR_DBA_4                                                    /*!< PWMx_CCR4 register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_BDTR          (PWM_DCR_DBA_4 | PWM_DCR_DBA_0)                                  /*!< PWMx_BDTR register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_DCR           (PWM_DCR_DBA_4 | PWM_DCR_DBA_1)                                  /*!< PWMx_DCR register is the DMA base address for DMA burst */
#define LL_PWM_DMABURST_BASEADDR_DMAR          (PWM_DCR_DBA_4 | PWM_DCR_DBA_1| PWM_DCR_DBA_0)                   /*!< PWMx_DMAR register is the DMA base address for DMA burst */
/**
  * @}
  */

/** @defgroup PWM_LL_EC_DMABURST_LENGTH DMA Burst Length
  * @{
  */
#define LL_PWM_DMABURST_LENGTH_1TRANSFER       0x00000000U                                                     /*!< Transfer is done to 1 register starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_2TRANSFERS      PWM_DCR_DBL_0                                                   /*!< Transfer is done to 2 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_3TRANSFERS      PWM_DCR_DBL_1                                                   /*!< Transfer is done to 3 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_4TRANSFERS      (PWM_DCR_DBL_1 |  PWM_DCR_DBL_0)                                /*!< Transfer is done to 4 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_5TRANSFERS      PWM_DCR_DBL_2                                                   /*!< Transfer is done to 5 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_6TRANSFERS      (PWM_DCR_DBL_2 | PWM_DCR_DBL_0)                                 /*!< Transfer is done to 6 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_7TRANSFERS      (PWM_DCR_DBL_2 | PWM_DCR_DBL_1)                                 /*!< Transfer is done to 7 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_8TRANSFERS      (PWM_DCR_DBL_2 | PWM_DCR_DBL_1 | PWM_DCR_DBL_0)                 /*!< Transfer is done to 1 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_9TRANSFERS      PWM_DCR_DBL_3                                                   /*!< Transfer is done to 9 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_10TRANSFERS     (PWM_DCR_DBL_3 | PWM_DCR_DBL_0)                                 /*!< Transfer is done to 10 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_11TRANSFERS     (PWM_DCR_DBL_3 | PWM_DCR_DBL_1)                                 /*!< Transfer is done to 11 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_12TRANSFERS     (PWM_DCR_DBL_3 | PWM_DCR_DBL_1 | PWM_DCR_DBL_0)                 /*!< Transfer is done to 12 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_13TRANSFERS     (PWM_DCR_DBL_3 | PWM_DCR_DBL_2)                                 /*!< Transfer is done to 13 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_14TRANSFERS     (PWM_DCR_DBL_3 | PWM_DCR_DBL_2 | PWM_DCR_DBL_0)                 /*!< Transfer is done to 14 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_15TRANSFERS     (PWM_DCR_DBL_3 | PWM_DCR_DBL_2 | PWM_DCR_DBL_1)                 /*!< Transfer is done to 15 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_16TRANSFERS     (PWM_DCR_DBL_3 | PWM_DCR_DBL_2 | PWM_DCR_DBL_1 | PWM_DCR_DBL_0) /*!< Transfer is done to 16 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_17TRANSFERS     PWM_DCR_DBL_4                                                   /*!< Transfer is done to 17 registers starting from the DMA burst base address */
#define LL_PWM_DMABURST_LENGTH_18TRANSFERS     (PWM_DCR_DBL_4 |  PWM_DCR_DBL_0)                                /*!< Transfer is done to 18 registers starting from the DMA burst base address */
/**
  * @}
  */
#endif

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PWM_LL_Exported_Macros PWM Exported Macros
  * @{
  */

/** @defgroup PWM_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */
/**
  * @brief  Write a value in PWM register.
  * @param  __INSTANCE__ PWM Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_PWM_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in PWM register.
  * @param  __INSTANCE__ PWM Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_PWM_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
/**
  * @}
  */

/** @defgroup PWM_LL_EM_Exported_Macros Exported_Macros
  * @{
  */

/**
  * @brief  HELPER macro calculating DTG[0:7] in the PWMx_BDTR register to achieve the requested dead time duration.
  * @note ex: @ref __LL_PWM_CALC_DEADTIME (80000000, @ref LL_PWM_GetClockDivision (), 120);
  * @param  __PWMCLK__ pwm input clock frequency (in Hz)
  * @param  __CKD__ This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV1
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV2
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV4
  * @param  __DT__ deadtime duration (in ns)
  * @retval DTG[0:7]
  */
#define __LL_PWM_CALC_DEADTIME(__PWMCLK__, __CKD__, __DT__)  \
  ( (((uint64_t)((__DT__)*1000U)) < ((DT_DELAY_1+1U) * PWM_CALC_DTS((__PWMCLK__), (__CKD__))))    ? (uint8_t)(((uint64_t)((__DT__)*1000U) / PWM_CALC_DTS((__PWMCLK__), (__CKD__)))  & DT_DELAY_1) :                                               \
    (((uint64_t)((__DT__)*1000U)) < ((64U + (DT_DELAY_2+1U)) * 2U * PWM_CALC_DTS((__PWMCLK__), (__CKD__))))  ? (uint8_t)(DT_RANGE_2 | ((uint8_t)((uint8_t)((((uint64_t)((__DT__)*1000U))/ PWM_CALC_DTS((__PWMCLK__), (__CKD__))) >> 1U) - (uint8_t) 64) & DT_DELAY_2)) :\
    (((uint64_t)((__DT__)*1000U)) < ((32U + (DT_DELAY_3+1U)) * 8U * PWM_CALC_DTS((__PWMCLK__), (__CKD__))))  ? (uint8_t)(DT_RANGE_3 | ((uint8_t)((uint8_t)(((((uint64_t)(__DT__)*1000U))/ PWM_CALC_DTS((__PWMCLK__), (__CKD__))) >> 3U) - (uint8_t) 32) & DT_DELAY_3)) :\
    (((uint64_t)((__DT__)*1000U)) < ((32U + (DT_DELAY_4+1U)) * 16U * PWM_CALC_DTS((__PWMCLK__), (__CKD__)))) ? (uint8_t)(DT_RANGE_4 | ((uint8_t)((uint8_t)(((((uint64_t)(__DT__)*1000U))/ PWM_CALC_DTS((__PWMCLK__), (__CKD__))) >> 4U) - (uint8_t) 32) & DT_DELAY_4)) :\
    0U)

/**
  * @brief  HELPER macro calculating the prescaler value to achieve the required counter clock frequency.
  * @note ex: @ref __LL_PWM_CALC_PSC (80000000, 1000000);
  * @param  __PWMCLK__ pwm input clock frequency (in Hz)
  * @param  __CNTCLK__ counter clock frequency (in Hz)
  * @retval Prescaler value  (between Min_Data=0 and Max_Data=65535)
  */
#define __LL_PWM_CALC_PSC(__PWMCLK__, __CNTCLK__)   \
  (((__PWMCLK__) >= (__CNTCLK__)) ? (uint32_t)(((__PWMCLK__)/(__CNTCLK__)) - 1U) : 0U)

/**
  * @brief  HELPER macro calculating the auto-reload value to achieve the required output signal frequency.
  * @note ex: @ref __LL_PWM_CALC_ARR (1000000, @ref LL_PWM_GetPrescaler (), 10000);
  * @param  __PWMCLK__ pwm input clock frequency (in Hz)
  * @param  __PSC__ prescaler
  * @param  __FREQ__ output signal frequency (in Hz)
  * @retval  Auto-reload value  (between Min_Data=0 and Max_Data=65535)
  */
#define __LL_PWM_CALC_ARR(__PWMCLK__, __PSC__, __FREQ__) \
  ((((__PWMCLK__)/((__PSC__) + 1U)) >= (__FREQ__)) ? (((__PWMCLK__)/((__FREQ__) * ((__PSC__) + 1U))) - 1U) : 0U)

/**
  * @brief  HELPER macro calculating the compare value required to achieve the required pwm output compare active/inactive delay.
  * @note ex: @ref __LL_PWM_CALC_DELAY (1000000, @ref LL_PWM_GetPrescaler (), 10);
  * @param  __PWMCLK__ pwm input clock frequency (in Hz)
  * @param  __PSC__ prescaler
  * @param  __DELAY__ pwm output compare active/inactive delay (in us)
  * @retval Compare value  (between Min_Data=0 and Max_Data=65535)
  */
#define __LL_PWM_CALC_DELAY(__PWMCLK__, __PSC__, __DELAY__)  \
  ((uint32_t)(((uint64_t)(__PWMCLK__) * (uint64_t)(__DELAY__)) \
              / ((uint64_t)1000000U * (uint64_t)((__PSC__) + 1U))))

/**
  * @brief  HELPER macro calculating the auto-reload value to achieve the required pulse duration (when the pwm operates in one pulse mode).
  * @note ex: @ref __LL_PWM_CALC_PULSE (1000000, @ref LL_PWM_GetPrescaler (), 10, 20);
  * @param  __PWMCLK__ pwm input clock frequency (in Hz)
  * @param  __PSC__ prescaler
  * @param  __DELAY__ pwm output compare active/inactive delay (in us)
  * @param  __PULSE__ pulse duration (in us)
  * @retval Auto-reload value  (between Min_Data=0 and Max_Data=65535)
  */
#define __LL_PWM_CALC_PULSE(__PWMCLK__, __PSC__, __DELAY__, __PULSE__)  \
  ((uint32_t)(__LL_PWM_CALC_DELAY((__PWMCLK__), (__PSC__), (__PULSE__)) \
              + __LL_PWM_CALC_DELAY((__PWMCLK__), (__PSC__), (__DELAY__))))


/**
  * @}
  */


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PWM_LL_Exported_Functions PWM Exported Functions
  * @{
  */

/** @defgroup PWM_LL_EF_Time_Base Time Base configuration
  * @{
  */
/**
  * @brief  Enable pwm counter.
  * @rmtoll CR1          CEN           LL_PWM_EnableCounter
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableCounter(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->CR1, PWM_CR1_CEN);
}

/**
  * @brief  Disable pwm counter.
  * @rmtoll CR1          CEN           LL_PWM_DisableCounter
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableCounter(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->CR1, PWM_CR1_CEN);
}

/**
  * @brief  Indicates whether the pwm counter is enabled.
  * @rmtoll CR1          CEN           LL_PWM_IsEnabledCounter
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledCounter(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->CR1, PWM_CR1_CEN) == (PWM_CR1_CEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable update event generation.
  * @rmtoll CR1          UDIS          LL_PWM_EnableUpdateEvent
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableUpdateEvent(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->CR1, PWM_CR1_UDIS);
}

/**
  * @brief  Disable update event generation.
  * @rmtoll CR1          UDIS          LL_PWM_DisableUpdateEvent
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableUpdateEvent(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->CR1, PWM_CR1_UDIS);
}

/**
  * @brief  Indicates whether update event generation is enabled.
  * @rmtoll CR1          UDIS          LL_PWM_IsEnabledUpdateEvent
  * @param  PWMx Pwm instance
  * @retval Inverted state of bit (0 or 1).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledUpdateEvent(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->CR1, PWM_CR1_UDIS) == (uint32_t)RESET) ? 1UL : 0UL);
}

/**
  * @brief  Set update event source
  * @note Update event source set to LL_PWM_UPDATESOURCE_REGULAR: any of the following events
  *       generate an update interrupt or DMA request if enabled:
  *        - Counter overflow/underflow
  *        - Setting the UG bit
  *        - Update generation through the slave mode controller
  * @note Update event source set to LL_PWM_UPDATESOURCE_COUNTER: only counter
  *       overflow/underflow generates an update interrupt or DMA request if enabled.
  * @note   Depending on devices and packages,DMA may not be available.
  *         Refer to device datasheet for DMA availability.
  * @rmtoll CR1          URS           LL_PWM_SetUpdateSource
  * @param  PWMx Pwm instance
  * @param  UpdateSource This parameter can be one of the following values:
  *         @arg @ref LL_PWM_UPDATESOURCE_REGULAR
  *         @arg @ref LL_PWM_UPDATESOURCE_COUNTER
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetUpdateSource(PWM_TypeDef *PWMx, uint32_t UpdateSource)
{
  MODIFY_REG(PWMx->CR1, PWM_CR1_URS, UpdateSource);
}

/**
  * @brief  Get actual event update source
  * @rmtoll CR1          URS           LL_PWM_GetUpdateSource
  * @param  PWMx Pwm instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWM_UPDATESOURCE_REGULAR
  *         @arg @ref LL_PWM_UPDATESOURCE_COUNTER
  */
__STATIC_INLINE uint32_t LL_PWM_GetUpdateSource(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_BIT(PWMx->CR1, PWM_CR1_URS));
}

/**
  * @brief  Set the pwm counter counting mode.
  * @note Macro IS_PWM_COUNTER_MODE_SELECT_INSTANCE(PWMx) can be used to
  *       check whether or not the counter mode selection feature is supported
  *       by a pwm instance.
  * @note Switching from Center Aligned counter mode to Edge counter mode (or reverse)
  *       requires a pwm reset to avoid unexpected direction
  *       due to DIR bit readonly in center aligned mode.
  * @rmtoll CR1          DIR           LL_PWM_SetCounterMode\n
  *         CR1          CMS           LL_PWM_SetCounterMode
  * @param  PWMx Pwm instance
  * @param  CounterMode This parameter can be one of the following values:
  *         @arg @ref LL_PWM_COUNTERMODE_UP
  *         @arg @ref LL_PWM_COUNTERMODE_DOWN
  *         @arg @ref LL_PWM_COUNTERMODE_CENTER_UP
  *         @arg @ref LL_PWM_COUNTERMODE_CENTER_DOWN
  *         @arg @ref LL_PWM_COUNTERMODE_CENTER_UP_DOWN
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetCounterMode(PWM_TypeDef *PWMx, uint32_t CounterMode)
{
  MODIFY_REG(PWMx->CR1, (PWM_CR1_DIR | PWM_CR1_CMS), CounterMode);
}

/**
  * @brief  Get actual counter mode.
  * @note Macro IS_PWM_COUNTER_MODE_SELECT_INSTANCE(PWMx) can be used to
  *       check whether or not the counter mode selection feature is supported
  *       by a pwm instance.
  * @rmtoll CR1          DIR           LL_PWM_GetCounterMode\n
  *         CR1          CMS           LL_PWM_GetCounterMode
  * @param  PWMx Pwm instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWM_COUNTERMODE_UP
  *         @arg @ref LL_PWM_COUNTERMODE_DOWN
  *         @arg @ref LL_PWM_COUNTERMODE_CENTER_UP
  *         @arg @ref LL_PWM_COUNTERMODE_CENTER_DOWN
  *         @arg @ref LL_PWM_COUNTERMODE_CENTER_UP_DOWN
  */
__STATIC_INLINE uint32_t LL_PWM_GetCounterMode(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_BIT(PWMx->CR1, PWM_CR1_DIR | PWM_CR1_CMS));
}

/**
  * @brief  Enable auto-reload (ARR) preload.
  * @rmtoll CR1          ARPE          LL_PWM_EnableARRPreload
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableARRPreload(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->CR1, PWM_CR1_ARPE);
}

/**
  * @brief  Disable auto-reload (ARR) preload.
  * @rmtoll CR1          ARPE          LL_PWM_DisableARRPreload
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableARRPreload(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->CR1, PWM_CR1_ARPE);
}

/**
  * @brief  Indicates whether auto-reload (ARR) preload is enabled.
  * @rmtoll CR1          ARPE          LL_PWM_IsEnabledARRPreload
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledARRPreload(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->CR1, PWM_CR1_ARPE) == (PWM_CR1_ARPE)) ? 1UL : 0UL);
}

/**
  * @brief  Set the division ratio between the pwm clock  and the sampling clock used by the dead-time generators (when supported) and the digital filters.
  * @note Macro IS_PWM_CLOCK_DIVISION_INSTANCE(PWMx) can be used to check
  *       whether or not the clock division feature is supported by the pwm
  *       instance.
  * @rmtoll CR1          CKD           LL_PWM_SetClockDivision
  * @param  PWMx Pwm instance
  * @param  ClockDivision This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV1
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV2
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV4
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetClockDivision(PWM_TypeDef *PWMx, uint32_t ClockDivision)
{
  MODIFY_REG(PWMx->CR1, PWM_CR1_CKD, ClockDivision);
}

/**
  * @brief  Get the actual division ratio between the pwm clock  and the sampling clock used by the dead-time generators (when supported) and the digital filters.
  * @note Macro IS_PWM_CLOCK_DIVISION_INSTANCE(PWMx) can be used to check
  *       whether or not the clock division feature is supported by the pwm
  *       instance.
  * @rmtoll CR1          CKD           LL_PWM_GetClockDivision
  * @param  PWMx Pwm instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV1
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV2
  *         @arg @ref LL_PWM_CLOCKDIVISION_DIV4
  */
__STATIC_INLINE uint32_t LL_PWM_GetClockDivision(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_BIT(PWMx->CR1, PWM_CR1_CKD));
}

/**
  * @brief  Set the counter value.
  * @note Macro IS_PWM_32B_COUNTER_INSTANCE(PWMx) can be used to check
  *       whether or not a pwm instance supports a 32 bits counter.
  * @note If dithering is activated, pay attention to the Counter value interpretation
  * @rmtoll CNT          CNT           LL_PWM_SetCounter
  * @param  PWMx Pwm instance
  * @param  Counter Counter value (between Min_Data=0 and Max_Data=0xFFFF or 0xFFFFFFFF)
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetCounter(PWM_TypeDef *PWMx, uint32_t Counter)
{
  WRITE_REG(PWMx->CNT, Counter);
}

/**
  * @brief  Get the counter value.
  * @note If dithering is activated, pay attention to the Counter value interpretation
  * @rmtoll CNT          CNT           LL_PWM_GetCounter
  * @param  PWMx Pwm instance
  * @retval Counter value (between Min_Data=0 and Max_Data=0xFFFF )
  */
__STATIC_INLINE uint32_t LL_PWM_GetCounter(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_REG(PWMx->CNT));
}

/**
  * @brief  Get the current direction of the counter
  * @rmtoll CR1          DIR           LL_PWM_GetDirection
  * @param  PWMx Pwm instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWM_COUNTERDIRECTION_UP
  *         @arg @ref LL_PWM_COUNTERDIRECTION_DOWN
  */
__STATIC_INLINE uint32_t LL_PWM_GetDirection(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_BIT(PWMx->CR1, PWM_CR1_DIR));
}

/**
  * @brief  Set the prescaler value.
  * @note The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
  * @note The prescaler can be changed on the fly as this control register is buffered. The new
  *       prescaler ratio is taken into account at the next update event.
  * @note Helper macro @ref __LL_PWM_CALC_PSC can be used to calculate the Prescaler parameter
  * @rmtoll PSC          PSC           LL_PWM_SetPrescaler
  * @param  PWMx Pwm instance
  * @param  Prescaler between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetPrescaler(PWM_TypeDef *PWMx, uint32_t Prescaler)
{
  WRITE_REG(PWMx->PSC, Prescaler);
}

/**
  * @brief  Get the prescaler value.
  * @rmtoll PSC          PSC           LL_PWM_GetPrescaler
  * @param  PWMx Pwm instance
  * @retval  Prescaler value between Min_Data=0 and Max_Data=65535
  */
__STATIC_INLINE uint32_t LL_PWM_GetPrescaler(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_REG(PWMx->PSC));
}

/**
  * @brief  Set the auto-reload value.
  * @note The counter is blocked while the auto-reload value is null.
  * @note Helper macro @ref __LL_PWM_CALC_ARR can be used to calculate the AutoReload parameter
  * @rmtoll ARR          ARR           LL_PWM_SetAutoReload
  * @param  PWMx Pwm instance
  * @param  AutoReload between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetAutoReload(PWM_TypeDef *PWMx, uint32_t AutoReload)
{
  WRITE_REG(PWMx->ARR, AutoReload);
}

/**
  * @brief  Get the auto-reload value.
  * @rmtoll ARR          ARR           LL_PWM_GetAutoReload
  * @param  PWMx Pwm instance
  * @retval Auto-reload value
  */
__STATIC_INLINE uint32_t LL_PWM_GetAutoReload(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_REG(PWMx->ARR));
}

/**
  * @}
  */

/** @defgroup PWM_LL_EF_Capture_Compare Capture Compare configuration
  * @{
  */

/**
  * @brief  Set the lock level to freeze the
  *         configuration of several compare parameters.
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       the lock mechanism is supported by a pwm instance.
  * @rmtoll BDTR         LOCK          LL_PWM_OC_SetLockLevel
  * @param  PWMx Pwm instance
  * @param  LockLevel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_LOCKLEVEL_OFF
  *         @arg @ref LL_PWM_LOCKLEVEL_1
  *         @arg @ref LL_PWM_LOCKLEVEL_2
  *         @arg @ref LL_PWM_LOCKLEVEL_3
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetLockLevel(PWM_TypeDef *PWMx, uint32_t LockLevel)
{
  MODIFY_REG(PWMx->BDTR, PWM_BDTR_LOCK, LockLevel);
}

/**
  * @brief  Enable compare channels.
  * @rmtoll CER         C1E          LL_PWM_OC_EnableChannel\n
  *         CER         C1NE         LL_PWM_OC_EnableChannel\n
  *         CER         C2E          LL_PWM_OC_EnableChannel\n
  *         CER         C2NE         LL_PWM_OC_EnableChannel\n
  *         CER         C3E          LL_PWM_OC_EnableChannel\n
  *         CER         C4E          LL_PWM_OC_EnableChannel
  * @param  PWMx Pwm instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH1N
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH2N
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_EnableChannel(PWM_TypeDef *PWMx, uint32_t Channels)
{
  SET_BIT(PWMx->CER, Channels);
}

/**
  * @brief  Disable compare channels.
  * @rmtoll CER         C1E          LL_PWM_OC_DisableChannel\n
  *         CER         C1NE         LL_PWM_OC_DisableChannel\n
  *         CER         C2E          LL_PWM_OC_DisableChannel\n
  *         CER         C2NE         LL_PWM_OC_DisableChannel\n
  *         CER         C3E          LL_PWM_OC_DisableChannel\n
  *         CER         C4E          LL_PWM_OC_DisableChannel
  * @param  PWMx Pwm instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH1N
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH2N
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_DisableChannel(PWM_TypeDef *PWMx, uint32_t Channels)
{
  CLEAR_BIT(PWMx->CER, Channels);
}

/**
  * @brief  Indicate whether channel(s) is(are) enabled.
  * @rmtoll CER         C1E          LL_PWM_OC_IsEnabledChannel\n
  *         CER         C1NE         LL_PWM_OC_IsEnabledChannel\n
  *         CER         C2E          LL_PWM_OC_IsEnabledChannel\n
  *         CER         C2NE         LL_PWM_OC_IsEnabledChannel\n
  *         CER         C3E          LL_PWM_OC_IsEnabledChannel\n
  *         CER         C4E          LL_PWM_OC_IsEnabledChannel
  * @param  PWMx Pwm instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH1N
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH2N
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_OC_IsEnabledChannel(PWM_TypeDef *PWMx, uint32_t Channels)
{
  return ((READ_BIT(PWMx->CER, Channels) == (Channels)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup PWM_LL_EF_Output_Channel Output channel configuration
  * @{
  */
/**
  * @brief  Configure an output channel.
  * @rmtoll CER         C1P          LL_PWM_OC_ConfigOutput\n
  *         CER         C2P          LL_PWM_OC_ConfigOutput\n
  *         CER         C3P          LL_PWM_OC_ConfigOutput\n
  *         CER         C4P          LL_PWM_OC_ConfigOutput\n
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @param  Configuration This parameter must be a combination of all the following values:
  *         @arg @ref LL_PWM_OCPOLARITY_HIGH or @ref LL_PWM_OCPOLARITY_LOW
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_ConfigOutput(PWM_TypeDef *PWMx, uint32_t Channel, uint32_t Configuration)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(PWMx->CER, (PWM_CER_C1P << SHIFT_TAB_CxP[iChannel]),
             (Configuration & PWM_CER_C1P) << SHIFT_TAB_CxP[iChannel]);
}

/**
  * @brief  Define the behavior of the output reference signal OCxREF from which
  *         OCx and OCxN (when relevant) are derived.
  * @rmtoll CMR        OC1M          LL_PWM_OC_SetMode\n
  *         CMR        OC2M          LL_PWM_OC_SetMode\n
  *         CMR        OC3M          LL_PWM_OC_SetMode\n
  *         CMR        OC4M          LL_PWM_OC_SetMode
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_PWM_OCMODE_PWM1
  *         @arg @ref LL_PWM_OCMODE_PWM2
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetMode(PWM_TypeDef *PWMx, uint32_t Channel, uint32_t Mode)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  register __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CMR) + OFFSET_TAB_CMR[iChannel]));
  MODIFY_REG(*pReg, ((PWM_CMR_OC1M) << SHIFT_TAB_OCxM[iChannel]),  Mode << SHIFT_TAB_OCxM[iChannel]);
}

/**
  * @brief  Get the output compare mode of an output channel.
  * @rmtoll CMR        OC1M          LL_PWM_OC_GetMode\n
  *         CMR        OC2M          LL_PWM_OC_GetMode\n
  *         CMR        OC3M          LL_PWM_OC_GetMode\n
  *         CMR        OC4M          LL_PWM_OC_GetMode
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWM_OCMODE_PWM1
  *         @arg @ref LL_PWM_OCMODE_PWM2
  */
__STATIC_INLINE uint32_t LL_PWM_OC_GetMode(PWM_TypeDef *PWMx, uint32_t Channel)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  register const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CMR) + OFFSET_TAB_CMR[iChannel]));
  return (READ_BIT(*pReg, ((PWM_CMR_OC1M) << SHIFT_TAB_OCxM[iChannel])) >> SHIFT_TAB_OCxM[iChannel]);
}

/**
  * @brief  Set the polarity of an output channel.
  * @rmtoll CER         C1P          LL_PWM_OC_SetPolarity\n
  *         CER         C1NP         LL_PWM_OC_SetPolarity\n
  *         CER         C2P          LL_PWM_OC_SetPolarity\n
  *         CER         C2NP         LL_PWM_OC_SetPolarity\n
  *         CER         C3P          LL_PWM_OC_SetPolarity\n
  *         CER         C4P          LL_PWM_OC_SetPolarity
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH1N
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH2N
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref LL_PWM_OCPOLARITY_HIGH
  *         @arg @ref LL_PWM_OCPOLARITY_LOW
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetPolarity(PWM_TypeDef *PWMx, uint32_t Channel, uint32_t Polarity)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(PWMx->CER, (PWM_CER_C1P << SHIFT_TAB_CxP[iChannel]),  Polarity << SHIFT_TAB_CxP[iChannel]);
}

/**
  * @brief  Get the polarity of an output channel.
  * @rmtoll CER         C1P          LL_PWM_OC_GetPolarity\n
  *         CER         C1NP         LL_PWM_OC_GetPolarity\n
  *         CER         C2P          LL_PWM_OC_GetPolarity\n
  *         CER         C2NP         LL_PWM_OC_GetPolarity\n
  *         CER         C3P          LL_PWM_OC_GetPolarity\n
  *         CER         C4P          LL_PWM_OC_GetPolarity
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH1N
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH2N
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWM_OCPOLARITY_HIGH
  *         @arg @ref LL_PWM_OCPOLARITY_LOW
  */
__STATIC_INLINE uint32_t LL_PWM_OC_GetPolarity(PWM_TypeDef *PWMx, uint32_t Channel)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  return (READ_BIT(PWMx->CER, (PWM_CER_C1P << SHIFT_TAB_CxP[iChannel])) >> SHIFT_TAB_CxP[iChannel]);
}

/**
  * @brief  Enable compare register (PWMx_CCRx) preload for the output channel.
  * @rmtoll CMR        OC1PE          LL_PWM_OC_EnablePreload\n
  *         CMR        OC2PE          LL_PWM_OC_EnablePreload\n
  *         CMR        OC3PE          LL_PWM_OC_EnablePreload\n
  *         CMR        OC4PE          LL_PWM_OC_EnablePreload
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_EnablePreload(PWM_TypeDef *PWMx, uint32_t Channel)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  register __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CMR) + OFFSET_TAB_CMR[iChannel]));
  SET_BIT(*pReg, (PWM_CMR_OC1PE << SHIFT_TAB_OCxPE[iChannel]));
}

/**
  * @brief  Disable compare register (PWMx_CCRx) preload for the output channel.
  * @rmtoll CMR        OC1PE          LL_PWM_OC_DisablePreload\n
  *         CMR        OC2PE          LL_PWM_OC_DisablePreload\n
  *         CMR        OC3PE          LL_PWM_OC_DisablePreload\n
  *         CMR        OC4PE          LL_PWM_OC_DisablePreload
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_DisablePreload(PWM_TypeDef *PWMx, uint32_t Channel)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  register __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CMR) + OFFSET_TAB_CMR[iChannel]));
  CLEAR_BIT(*pReg, (PWM_CMR_OC1PE << SHIFT_TAB_OCxPE[iChannel]));
}

/**
  * @brief  Indicates whether compare register (PWMx_CCRx) preload is enabled for the output channel.
  * @rmtoll CMR        OC1PE          LL_PWM_OC_IsEnabledPreload\n
  *         CMR        OC2PE          LL_PWM_OC_IsEnabledPreload\n
  *         CMR        OC3PE          LL_PWM_OC_IsEnabledPreload\n
  *         CMR        OC4PE          LL_PWM_OC_IsEnabledPreload\n
  * @param  PWMx Pwm instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_OC_IsEnabledPreload(PWM_TypeDef *PWMx, uint32_t Channel)
{
  register uint8_t iChannel = PWM_GET_CHANNEL_INDEX(Channel);
  register const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CMR) + OFFSET_TAB_CMR[iChannel]));
  register uint32_t bitfield = PWM_CMR_OC1PE << SHIFT_TAB_OCxPE[iChannel];
  return ((READ_BIT(*pReg, bitfield) == bitfield) ? 1UL : 0UL);
}

/**
  * @brief  Set the dead-time delay (delay inserted between the rising edge of the OCxREF signal and the rising edge of the Ocx and OCxN signals).
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       dead-time insertion feature is supported by a pwm instance.
  * @note Helper macro @ref __LL_PWM_CALC_DEADTIME can be used to calculate the DeadTime parameter
  * @rmtoll BDTR         DTG           LL_PWM_OC_SetDeadTime
  * @param  PWMx Pwm instance
  * @param  DeadTime between Min_Data=0 and Max_Data=255
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetDeadTime(PWM_TypeDef *PWMx, uint32_t DeadTime)
{
  MODIFY_REG(PWMx->BDTR, PWM_BDTR_DTG, DeadTime);
}

/**
  * @brief  Set compare value for output channel 1 (PWMx_CCR1).
  * @note Macro IS_PWM_OC1_INSTANCE(PWMx) can be used to check whether or not
  *       output channel 1 is supported by a pwm instance.
  * @rmtoll CCR1         CCR1          LL_PWM_OC_SetCompareCH1
  * @param  PWMx Pwm instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetCompareCH1(PWM_TypeDef *PWMx, uint32_t CompareValue)
{
  WRITE_REG(PWMx->CCR1, CompareValue);
}

/**
  * @brief  Set compare value for output channel 2 (PWMx_CCR2).
  * @note Macro IS_PWM_OC2_INSTANCE(PWMx) can be used to check whether or not
  *       output channel 2 is supported by a pwm instance.
  * @rmtoll CCR2         CCR2          LL_PWM_OC_SetCompareCH2
  * @param  PWMx Pwm instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetCompareCH2(PWM_TypeDef *PWMx, uint32_t CompareValue)
{
  WRITE_REG(PWMx->CCR2, CompareValue);
}

/**
  * @brief  Set compare value for output channel 3 (PWMx_CCR3).
  * @note Macro IS_PWM_OC3_INSTANCE(PWMx) can be used to check whether or not
  *       output channel is supported by a pwm instance.
  * @rmtoll CCR3         CCR3          LL_PWM_OC_SetCompareCH3
  * @param  PWMx Pwm instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetCompareCH3(PWM_TypeDef *PWMx, uint32_t CompareValue)
{
  WRITE_REG(PWMx->CCR3, CompareValue);
}

/**
  * @brief  Set compare value for output channel 4 (PWMx_CCR4).
  * @note Macro IS_PWM_OC4_INSTANCE(PWMx) can be used to check whether or not
  *       output channel 4 is supported by a pwm instance.
  * @rmtoll CCR4         CCR4          LL_PWM_OC_SetCompareCH4
  * @param  PWMx Pwm instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void LL_PWM_OC_SetCompareCH4(PWM_TypeDef *PWMx, uint32_t CompareValue)
{
  WRITE_REG(PWMx->CCR4, CompareValue);
}

/**
  * @brief  Get compare value (PWMx_CCR1) set for  output channel 1.
  * @note Macro IS_PWM_OC1_INSTANCE(PWMx) can be used to check whether or not
  *       output channel 1 is supported by a pwm instance.
  * @rmtoll CCR1         CCR1          LL_PWM_OC_GetCompareCH1
  * @param  PWMx Pwm instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint32_t LL_PWM_OC_GetCompareCH1(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_REG(PWMx->CCR1));
}

/**
  * @brief  Get compare value (PWMx_CCR2) set for  output channel 2.
  * @note Macro IS_PWM_OC2_INSTANCE(PWMx) can be used to check whether or not
  *       output channel 2 is supported by a pwm instance.
  * @rmtoll CCR2         CCR2          LL_PWM_OC_GetCompareCH2
  * @param  PWMx Pwm instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint32_t LL_PWM_OC_GetCompareCH2(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_REG(PWMx->CCR2));
}

/**
  * @brief  Get compare value (PWMx_CCR3) set for  output channel 3.
  * @note Macro IS_PWM_OC3_INSTANCE(PWMx) can be used to check whether or not
  *       output channel 3 is supported by a pwm instance.
  * @rmtoll CCR3         CCR3          LL_PWM_OC_GetCompareCH3
  * @param  PWMx Pwm instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint32_t LL_PWM_OC_GetCompareCH3(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_REG(PWMx->CCR3));
}

/**
  * @brief  Get compare value (PWMx_CCR4) set for  output channel 4.
  * @note Macro IS_PWM_OC4_INSTANCE(PWMx) can be used to check whether or not
  *       output channel 4 is supported by a pwm instance.
  * @rmtoll CCR4         CCR4          LL_PWM_OC_GetCompareCH4
  * @param  PWMx Pwm instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint32_t LL_PWM_OC_GetCompareCH4(PWM_TypeDef *PWMx)
{
  return (uint32_t)(READ_REG(PWMx->CCR4));
}

/**
  * @}
  */

/** @defgroup PWM_LL_EF_Clock_Selection Counter clock selection
  * @{
  */
/**
  * @brief  Enable external clock mode.
  * @note When external clock mode is enabled the counter is clocked by any active edge on the ETRF signal.
  * @note Macro IS_PWM_CLOCKSOURCE_ETRMODE_INSTANCE(PWMx) can be used to check
  *       whether or not a pwm instance supports external clock mode.
  * @rmtoll SMCR         ECE           LL_PWM_EnableExternalClock
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableExternalClock(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->SMCR, PWM_SMCR_ECE);
}

/**
  * @brief  Disable external clock mode.
  * @note Macro IS_PWM_CLOCKSOURCE_ETRMODE_INSTANCE(PWMx) can be used to check
  *       whether or not a pwm instance supports external clock mode.
  * @rmtoll SMCR         ECE           LL_PWM_DisableExternalClock
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableExternalClock(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->SMCR, PWM_SMCR_ECE);
}

/**
  * @brief  Indicate whether external clock mode is enabled.
  * @note Macro IS_PWM_CLOCKSOURCE_ETRMODE_INSTANCE(PWMx) can be used to check
  *       whether or not a pwm instance supports external clock mode.
  * @rmtoll SMCR         ECE           LL_PWM_IsEnabledExternalClock
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledExternalClock(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SMCR, PWM_SMCR_ECE) == (PWM_SMCR_ECE)) ? 1UL : 0UL);
}

/**
  * @brief  Set the clock source of the counter clock.
  * @note Macro IS_PWM_CLOCKSOURCE_ETRMODE_INSTANCE(PWMx) can be used to check
  *       whether or not a pwm instance supports external clock mode.
  * @rmtoll SMCR         ECE           LL_PWM_SetClockSource
  * @param  PWMx Pwm instance
  * @param  ClockSource This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CLOCKSOURCE_INTERNAL
  *         @arg @ref LL_PWM_CLOCKSOURCE_EXT_MODE
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetClockSource(PWM_TypeDef *PWMx, uint32_t ClockSource)
{
  MODIFY_REG(PWMx->SMCR, PWM_SMCR_ECE, ClockSource);
}

/**
  * @}
  */

/** @defgroup PWM_LL_EF_Pwm_Synchronization Pwm synchronisation configuration
  * @{
  */

/**
  * @brief  Configure the external trigger (ETR) input.
  * @note Macro IS_PWM_ETR_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides an external trigger input.
  * @rmtoll SMCR         ETP           LL_PWM_ConfigETR\n
  *         SMCR         ETPS          LL_PWM_ConfigETR\n
  *         SMCR         ETF           LL_PWM_ConfigETR
  * @param  PWMx Pwm instance
  * @param  ETRPolarity This parameter can be one of the following values:
  *         @arg @ref LL_PWM_ETR_POLARITY_NONINVERTED
  *         @arg @ref LL_PWM_ETR_POLARITY_INVERTED
  * @param  ETRPrescaler This parameter can be one of the following values:
  *         @arg @ref LL_PWM_ETR_PRESCALER_DIV1
  *         @arg @ref LL_PWM_ETR_PRESCALER_DIV2
  *         @arg @ref LL_PWM_ETR_PRESCALER_DIV4
  *         @arg @ref LL_PWM_ETR_PRESCALER_DIV8
  * @param  ETRFilter This parameter can be one of the following values:
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV1
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV1_N2
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV1_N4
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV1_N8
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV2_N6
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV2_N8
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV4_N6
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV4_N8
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV8_N6
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV8_N8
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV16_N5
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV16_N6
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV16_N8
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV32_N5
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV32_N6
  *         @arg @ref LL_PWM_ETR_FILTER_FDIV32_N8
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ConfigETR(PWM_TypeDef *PWMx, uint32_t ETRPolarity, uint32_t ETRPrescaler,
                                      uint32_t ETRFilter)
{
  MODIFY_REG(PWMx->SMCR, PWM_SMCR_ETP | PWM_SMCR_ETPS | PWM_SMCR_ETF, ETRPolarity | ETRPrescaler | ETRFilter);
}

/**
  * @brief  Select the external trigger (ETR) input source.
  * @rmtoll CR2          ETRSEL        LL_PWM_SetETRSource
  * @param  PWMx Pwm instance
  * @param  ETRSource This parameter can be one of the following values:
  *
  *         PWM: any combination of ETR_RMP where
  *
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_GPIO_LS
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_COMP1
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_COMP2
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_SYS_CLK
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_GPIO_HS
  *
  *         (*)  Value not defined in all devices. \n
  *         (**) Register not available in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetETRSource(PWM_TypeDef *PWMx, uint32_t ETRSource)
{
  MODIFY_REG(PWMx->CR2, PWMx_CR2_ETRSEL, ETRSource);
}

/**
  * @brief  Get the external trigger (ETR) input source.
  * @rmtoll CR2          ETRSEL        LL_PWM_GetETRSource
  * @param  PWMx Pwm instance
  * @retval ETRSource This parameter can be one of the following values:
  *
  *         PWM: any combination of ETR_RMP where
  *
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_GPIO_LS
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_COMP1
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_COMP2
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_SYS_CLK
  *            @arg @ref LL_PWM_PWM_ETRSOURCE_GPIO_HS
  *
  *         (*)  Value not defined in all devices. \n
  *         (**) Register not available in all devices.
  */
__STATIC_INLINE uint32_t LL_PWM_GetETRSource(PWM_TypeDef *PWMx)
{
  return ((uint32_t)(READ_REG(PWMx->CR2))) & PWMx_CR2_ETRSEL;
}

/**
  * @}
  */

/** @defgroup PWM_LL_EF_Break_Function Break function configuration
  * @{
  */
/**
  * @brief  Enable the break function.
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         BKE           LL_PWM_EnableBRK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableBRK(PWM_TypeDef *PWMx)
{
  __IO uint32_t tmpreg;
  SET_BIT(PWMx->BDTR, PWM_BDTR_BKE);
  /* Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective. */
  tmpreg = READ_REG(PWMx->BDTR);
  (void)(tmpreg);
}

/**
  * @brief  Disable the break function.
  * @rmtoll BDTR         BKE           LL_PWM_DisableBRK
  * @param  PWMx Pwm instance
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableBRK(PWM_TypeDef *PWMx)
{
  __IO uint32_t tmpreg;
  CLEAR_BIT(PWMx->BDTR, PWM_BDTR_BKE);
  /* Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective. */
  tmpreg = READ_REG(PWMx->BDTR);
  (void)(tmpreg);
}

/**
  * @brief  Configure the break input.
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         BKP           LL_PWM_ConfigBRK
  * @param  PWMx Pwm instance
  * @param  BreakPolarity This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BREAK_POLARITY_LOW
  *         @arg @ref LL_PWM_BREAK_POLARITY_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ConfigBRK(PWM_TypeDef *PWMx, uint32_t BreakPolarity)
{
  __IO uint32_t tmpreg;
  MODIFY_REG(PWMx->BDTR, PWM_BDTR_BKP, BreakPolarity);
  /* Note: Any write operation to BKP bit takes a delay of 1 APB clock cycle to become effective. */
  tmpreg = READ_REG(PWMx->BDTR);
  (void)(tmpreg);
}

/**
  * @brief  Enable automatic output (MOE can be set by software or automatically when a break input is active).
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         AOE           LL_PWM_EnableAutomaticOutput
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableAutomaticOutput(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->BDTR, PWM_BDTR_AOE);
}

/**
  * @brief  Disable automatic output (MOE can be set only by software).
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         AOE           LL_PWM_DisableAutomaticOutput
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableAutomaticOutput(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->BDTR, PWM_BDTR_AOE);
}

/**
  * @brief  Indicate whether automatic output is enabled.
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         AOE           LL_PWM_IsEnabledAutomaticOutput
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledAutomaticOutput(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->BDTR, PWM_BDTR_AOE) == (PWM_BDTR_AOE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the outputs (set the MOE bit in PWMx_BDTR register).
  * @note The MOE bit in PWMx_BDTR register allows to enable /disable the outputs by
  *       software and is reset in case of break or break2 event
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         MOE           LL_PWM_EnableAllOutputs
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableAllOutputs(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->BDTR, PWM_BDTR_MOE);
}

/**
  * @brief  Disable the outputs (reset the MOE bit in PWMx_BDTR register).
  * @note The MOE bit in PWMx_BDTR register allows to enable /disable the outputs by
  *       software and is reset in case of break or break2 event.
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         MOE           LL_PWM_DisableAllOutputs
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableAllOutputs(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->BDTR, PWM_BDTR_MOE);
}

/**
  * @brief  Indicates whether outputs are enabled.
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @rmtoll BDTR         MOE           LL_PWM_IsEnabledAllOutputs
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledAllOutputs(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->BDTR, PWM_BDTR_MOE) == (PWM_BDTR_MOE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the signals connected to the designated pwm break input.
  * @rmtoll CR2          BKINE         LL_PWM_EnableBreakInputSource\n
  *         CR2          BKCMP1E       LL_PWM_EnableBreakInputSource\n
  *         CR2          BKCMP2E       LL_PWM_EnableBreakInputSource\n
  * @param  PWMx Pwm instance
  * @param  BreakInput This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BREAK_INPUT_BKIN
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKIN
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKCOMP1
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKCOMP2
  *
  *         (*)  Value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableBreakInputSource(PWM_TypeDef *PWMx, uint32_t BreakInput, uint32_t Source)
{
   __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CR2) + BreakInput));
  SET_BIT(*pReg, Source);
}

/**
  * @brief  Disable the signals connected to the designated pwm break input.
  * @rmtoll CR2          BKINE         LL_PWM_DisableBreakInputSource\n
  *         CR2          BKCMP1E       LL_PWM_DisableBreakInputSource\n
  *         CR2          BKCMP2E       LL_PWM_DisableBreakInputSource\n
  * @param  PWMx Pwm instance
  * @param  BreakInput This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BREAK_INPUT_BKIN
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKIN
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKCOMP1
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKCOMP2
  *
  *         (*)  Value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableBreakInputSource(PWM_TypeDef *PWMx, uint32_t BreakInput, uint32_t Source)
{
   __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CR2) + BreakInput));
  CLEAR_BIT(*pReg, Source);
}

/**
  * @brief  Set the polarity of the break signal for the pwm break input.
  * @rmtoll CR2          BKINP         LL_PWM_SetBreakInputSourcePolarity\n
  *         CR2          BKCMP1P       LL_PWM_SetBreakInputSourcePolarity\n
  *         CR2          BKCMP2P       LL_PWM_SetBreakInputSourcePolarity\n
  * @param  PWMx Pwm instance
  * @param  BreakInput This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BREAK_INPUT_BKIN
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKIN
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKCOMP1
  *         @arg @ref LL_PWM_BKIN_SOURCE_BKCOMP2
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref LL_PWM_BKIN_POLARITY_LOW
  *         @arg @ref LL_PWM_BKIN_POLARITY_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_PWM_SetBreakInputSourcePolarity(PWM_TypeDef *PWMx, uint32_t BreakInput, uint32_t Source,
                                                        uint32_t Polarity)
{
   __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&PWMx->CR2) + BreakInput));
  MODIFY_REG(*pReg, (PWMx_CR2_BKINP << PWM_POSITION_BRK_SOURCE), (Polarity << PWM_POSITION_BRK_SOURCE));
}

/**
  * @}
  */

#if (defined(DMA) || defined(DMA1))
/** @defgroup PWM_LL_EF_DMA_Burst_Mode DMA burst mode configuration
  * @{
  */
/**
  * @brief  Configures the pwm DMA burst feature.
  * @note Macro IS_PWM_DMABURST_INSTANCE(PWMx) can be used to check whether or
  *       not a pwm instance supports the DMA burst mode.
  * @rmtoll DCR          DBL           LL_PWM_ConfigDMABurst\n
  *         DCR          DBA           LL_PWM_ConfigDMABurst
  * @param  PWMx Pwm instance
  * @param  DMABurstBaseAddress This parameter can be one of the following values:
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CR1
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CR2
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_SMCR
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_DIER
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_SR
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_EGR
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CMR
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CER
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CNT
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_PSC
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_ARR
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CCR1
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CCR2
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CCR3
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_CCR4
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_BDTR
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_DCR
  *         @arg @ref LL_PWM_DMABURST_BASEADDR_DMAR
  * @param  DMABurstLength This parameter can be one of the following values:
  *         @arg @ref LL_PWM_DMABURST_LENGTH_1TRANSFER
  *         @arg @ref LL_PWM_DMABURST_LENGTH_2TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_3TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_4TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_5TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_6TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_7TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_8TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_9TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_10TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_11TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_12TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_13TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_14TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_15TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_16TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_17TRANSFERS
  *         @arg @ref LL_PWM_DMABURST_LENGTH_18TRANSFERS
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ConfigDMABurst(PWM_TypeDef *PWMx, uint32_t DMABurstBaseAddress, uint32_t DMABurstLength)
{
  MODIFY_REG(PWMx->DCR, (PWM_DCR_DBL | PWM_DCR_DBA), (DMABurstBaseAddress | DMABurstLength));
}
#endif
/**
  * @}
  */

/** @defgroup PWM_LL_EF_FLAG_Management FLAG-Management
  * @{
  */
/**
  * @brief  Clear the update interrupt flag (UIF).
  * @rmtoll SR           UIF           LL_PWM_ClearFlag_UPDATE
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_UPDATE(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_UIF));
}

/**
  * @brief  Indicate whether update interrupt flag (UIF) is set (update interrupt is pending).
  * @rmtoll SR           UIF           LL_PWM_IsActiveFlag_UPDATE
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_UPDATE(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_UIF) == (PWM_SR_UIF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Compare 1 interrupt flag (OC1F).
  * @rmtoll SR           OC1IF         LL_PWM_ClearFlag_OC1
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_OC1(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_OC1IF));
}

/**
  * @brief  Indicate whether Compare 1 interrupt flag (OC1F) is set (Compare 1 interrupt is pending).
  * @rmtoll SR           OC1IF         LL_PWM_IsActiveFlag_OC1
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_OC1(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_OC1IF) == (PWM_SR_OC1IF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Compare 2 interrupt flag (OC2F).
  * @rmtoll SR           OC2IF         LL_PWM_ClearFlag_OC2
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_OC2(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_OC2IF));
}

/**
  * @brief  Indicate whether Compare 2 interrupt flag (OC2F) is set (Compare 2 interrupt is pending).
  * @rmtoll SR           OC2IF         LL_PWM_IsActiveFlag_OC2
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_OC2(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_OC2IF) == (PWM_SR_OC2IF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Compare 3 interrupt flag (OC3F).
  * @rmtoll SR           OC3IF         LL_PWM_ClearFlag_OC3
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_OC3(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_OC3IF));
}

/**
  * @brief  Indicate whether Compare 3 interrupt flag (OC3F) is set (Compare 3 interrupt is pending).
  * @rmtoll SR           OC3IF         LL_PWM_IsActiveFlag_OC3
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_OC3(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_OC3IF) == (PWM_SR_OC3IF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Compare 4 interrupt flag (OC4F).
  * @rmtoll SR           OC4IF         LL_PWM_ClearFlag_OC4
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_OC4(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_OC4IF));
}

/**
  * @brief  Indicate whether Compare 4 interrupt flag (OC4F) is set (Compare 4 interrupt is pending).
  * @rmtoll SR           OC4IF         LL_PWM_IsActiveFlag_OC4
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_OC4(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_OC4IF) == (PWM_SR_OC4IF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the break interrupt flag (BIF).
  * @rmtoll SR           BIF           LL_PWM_ClearFlag_BRK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_BRK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_BIF));
}

/**
  * @brief  Indicate whether break interrupt flag (BIF) is set (break interrupt is pending).
  * @rmtoll SR           BIF           LL_PWM_IsActiveFlag_BRK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_BRK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_BIF) == (PWM_SR_BIF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the PWM_CCR1 register update completion flag (CCR1OK).
  * @rmtoll SR           CCR1OK           LL_PWM_ClearFlag_CCR1OK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_CCR1OK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_CCR1OK));
}

/**
  * @brief  Indicate whether PWM_CCR1 register update completion flag (CCR1OK) is set.
  * @rmtoll SR           CCR1OK           LL_PWM_IsActiveFlag_CCR1OK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_CCR1OK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_CCR1OK) == (PWM_SR_CCR1OK)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the PWM_CCR2 register update completion flag (CCR2OK).
  * @rmtoll SR           CCR2OK           LL_PWM_ClearFlag_CCR2OK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_CCR2OK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_CCR2OK));
}

/**
  * @brief  Indicate whether PWM_CCR2 register update completion flag (CCR2OK) is set.
  * @rmtoll SR           CCR2OK           LL_PWM_IsActiveFlag_CCR2OK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_CCR2OK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_CCR2OK) == (PWM_SR_CCR2OK)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the PWM_CCR3 register update completion flag (CCR3OK).
  * @rmtoll SR           CCR3OK           LL_PWM_ClearFlag_CCR3OK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_CCR3OK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_CCR3OK));
}

/**
  * @brief  Indicate whether PWM_CCR3 register update completion flag (CCR3OK) is set.
  * @rmtoll SR           CCR3OK           LL_PWM_IsActiveFlag_CCR3OK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_CCR3OK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_CCR3OK) == (PWM_SR_CCR3OK)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the PWM_CCR4 register update completion flag (CCR4OK).
  * @rmtoll SR           CCR4OK           LL_PWM_ClearFlag_CCR4OK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_CCR4OK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_CCR4OK));
}

/**
  * @brief  Indicate whether PWM_CCR4 register update completion flag (CCR4OK) is set.
  * @rmtoll SR           CCR4OK           LL_PWM_IsActiveFlag_CCR4OK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_CCR4OK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_CCR4OK) == (PWM_SR_CCR4OK)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the PWM_CNT register update completion flag (CNTOK).
  * @rmtoll SR           CNTOK           LL_PWM_ClearFlag_CNTOK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_CNTOK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_CNTOK));
}

/**
  * @brief  Indicate whether PWM_CNT register update completion flag (CNTOK) is set.
  * @rmtoll SR           CNTOK           LL_PWM_IsActiveFlag_CNTOK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_CNTOK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_CNTOK) == (PWM_SR_CNTOK)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the PWM_PSC register update completion flag (PSCOK).
  * @rmtoll SR           PSCOK           LL_PWM_ClearFlag_PSCOK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_PSCOK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_PSCOK));
}

/**
  * @brief  Indicate whether PWM_PSC register update completion flag (PSCOK) is set.
  * @rmtoll SR           PSCOK           LL_PWM_IsActiveFlag_PSCOK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_PSCOK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_PSCOK) == (PWM_SR_PSCOK)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the PWM_ARR register update completion flag (ARROK).
  * @rmtoll SR           ARROK           LL_PWM_ClearFlag_ARROK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_ClearFlag_ARROK(PWM_TypeDef *PWMx)
{
  WRITE_REG(PWMx->SR, ~(PWM_SR_ARROK));
}

/**
  * @brief  Indicate whether PWM_ARR register update completion flag (ARROK) is set.
  * @rmtoll SR           ARROK           LL_PWM_IsActiveFlag_ARROK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsActiveFlag_ARROK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->SR, PWM_SR_ARROK) == (PWM_SR_ARROK)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup PWM_LL_EF_IT_Management IT-Management
  * @{
  */
/**
  * @brief  Enable update interrupt (UIE).
  * @rmtoll DIER         UIE           LL_PWM_EnableIT_UPDATE
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableIT_UPDATE(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_UIE);
}

/**
  * @brief  Disable update interrupt (UIE).
  * @rmtoll DIER         UIE           LL_PWM_DisableIT_UPDATE
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableIT_UPDATE(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_UIE);
}

/**
  * @brief  Indicates whether the update interrupt (UIE) is enabled.
  * @rmtoll DIER         UIE           LL_PWM_IsEnabledIT_UPDATE
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledIT_UPDATE(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_UIE) == (PWM_DIER_UIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 1 interrupt (OC1IE).
  * @rmtoll DIER         OC1IE         LL_PWM_EnableIT_OC1
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableIT_OC1(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC1IE);
}

/**
  * @brief  Disable compare 1  interrupt (OC1IE).
  * @rmtoll DIER         OC1IE         LL_PWM_DisableIT_OC1
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableIT_OC1(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC1IE);
}

/**
  * @brief  Indicates whether the compare 1 interrupt (OC1IE) is enabled.
  * @rmtoll DIER         OC1IE         LL_PWM_IsEnabledIT_OC1
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledIT_OC1(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC1IE) == (PWM_DIER_OC1IE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 2 interrupt (OC2IE).
  * @rmtoll DIER         OC2IE         LL_PWM_EnableIT_OC2
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableIT_OC2(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC2IE);
}

/**
  * @brief  Disable compare 2  interrupt (OC2IE).
  * @rmtoll DIER         OC2IE         LL_PWM_DisableIT_OC2
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableIT_OC2(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC2IE);
}

/**
  * @brief  Indicates whether the compare 2 interrupt (OC2IE) is enabled.
  * @rmtoll DIER         OC2IE         LL_PWM_IsEnabledIT_OC2
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledIT_OC2(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC2IE) == (PWM_DIER_OC2IE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 3 interrupt (OC3IE).
  * @rmtoll DIER         OC3IE         LL_PWM_EnableIT_OC3
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableIT_OC3(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC3IE);
}

/**
  * @brief  Disable compare 3  interrupt (OC3IE).
  * @rmtoll DIER         OC3IE         LL_PWM_DisableIT_OC3
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableIT_OC3(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC3IE);
}

/**
  * @brief  Indicates whether the compare 3 interrupt (OC3IE) is enabled.
  * @rmtoll DIER         OC3IE         LL_PWM_IsEnabledIT_OC3
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledIT_OC3(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC3IE) == (PWM_DIER_OC3IE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 4 interrupt (OC4IE).
  * @rmtoll DIER         OC4IE         LL_PWM_EnableIT_OC4
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableIT_OC4(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC4IE);
}

/**
  * @brief  Disable compare 4  interrupt (OC4IE).
  * @rmtoll DIER         OC4IE         LL_PWM_DisableIT_OC4
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableIT_OC4(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC4IE);
}

/**
  * @brief  Indicates whether the compare 4 interrupt (OC4IE) is enabled.
  * @rmtoll DIER         OC4IE         LL_PWM_IsEnabledIT_OC4
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledIT_OC4(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC4IE) == (PWM_DIER_OC4IE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable break interrupt (BIE).
  * @rmtoll DIER         BIE           LL_PWM_EnableIT_BRK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableIT_BRK(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_BIE);
}

/**
  * @brief  Disable break interrupt (BIE).
  * @rmtoll DIER         BIE           LL_PWM_DisableIT_BRK
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableIT_BRK(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_BIE);
}

/**
  * @brief  Indicates whether the break interrupt (BIE) is enabled.
  * @rmtoll DIER         BIE           LL_PWM_IsEnabledIT_BRK
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledIT_BRK(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_BIE) == (PWM_DIER_BIE)) ? 1UL : 0UL);
}

/**
  * @}
  */
#if (defined(DMA) || defined(DMA1))
/** @defgroup PWM_LL_EF_DMA_Management DMA-Management
  * @{
  */
/**
  * @brief  Enable update DMA request (UDE).
  * @rmtoll DIER         UDE           LL_PWM_EnableDMAReq_UPDATE
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableDMAReq_UPDATE(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_UDE);
}

/**
  * @brief  Disable update DMA request (UDE).
  * @rmtoll DIER         UDE           LL_PWM_DisableDMAReq_UPDATE
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableDMAReq_UPDATE(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_UDE);
}

/**
  * @brief  Indicates whether the update DMA request  (UDE) is enabled.
  * @rmtoll DIER         UDE           LL_PWM_IsEnabledDMAReq_UPDATE
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledDMAReq_UPDATE(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_UDE) == (PWM_DIER_UDE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 1 DMA request (OC1DE).
  * @rmtoll DIER         OC1DE         LL_PWM_EnableDMAReq_OC1
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableDMAReq_OC1(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC1DE);
}

/**
  * @brief  Disable compare 1  DMA request (OC1DE).
  * @rmtoll DIER         OC1DE         LL_PWM_DisableDMAReq_OC1
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableDMAReq_OC1(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC1DE);
}

/**
  * @brief  Indicates whether the compare 1 DMA request (OC1DE) is enabled.
  * @rmtoll DIER         OC1DE         LL_PWM_IsEnabledDMAReq_OC1
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledDMAReq_OC1(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC1DE) == (PWM_DIER_OC1DE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 2 DMA request (OC2DE).
  * @rmtoll DIER         OC2DE         LL_PWM_EnableDMAReq_OC2
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableDMAReq_OC2(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC2DE);
}

/**
  * @brief  Disable compare 2  DMA request (OC2DE).
  * @rmtoll DIER         OC2DE         LL_PWM_DisableDMAReq_OC2
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableDMAReq_OC2(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC2DE);
}

/**
  * @brief  Indicates whether the compare 2 DMA request (OC2DE) is enabled.
  * @rmtoll DIER         OC2DE         LL_PWM_IsEnabledDMAReq_OC2
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledDMAReq_OC2(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC2DE) == (PWM_DIER_OC2DE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 3 DMA request (OC3DE).
  * @rmtoll DIER         OC3DE         LL_PWM_EnableDMAReq_OC3
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableDMAReq_OC3(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC3DE);
}

/**
  * @brief  Disable compare 3  DMA request (OC3DE).
  * @rmtoll DIER         OC3DE         LL_PWM_DisableDMAReq_OC3
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableDMAReq_OC3(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC3DE);
}

/**
  * @brief  Indicates whether the compare 3 DMA request (OC3DE) is enabled.
  * @rmtoll DIER         OC3DE         LL_PWM_IsEnabledDMAReq_OC3
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledDMAReq_OC3(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC3DE) == (PWM_DIER_OC3DE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare 4 DMA request (OC4DE).
  * @rmtoll DIER         OC4DE         LL_PWM_EnableDMAReq_OC4
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_EnableDMAReq_OC4(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->DIER, PWM_DIER_OC4DE);
}

/**
  * @brief  Disable compare 4  DMA request (OC4DE).
  * @rmtoll DIER         OC4DE         LL_PWM_DisableDMAReq_OC4
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_DisableDMAReq_OC4(PWM_TypeDef *PWMx)
{
  CLEAR_BIT(PWMx->DIER, PWM_DIER_OC4DE);
}

/**
  * @brief  Indicates whether the compare 4 DMA request (OC4DE) is enabled.
  * @rmtoll DIER         OC4DE         LL_PWM_IsEnabledDMAReq_OC4
  * @param  PWMx Pwm instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWM_IsEnabledDMAReq_OC4(PWM_TypeDef *PWMx)
{
  return ((READ_BIT(PWMx->DIER, PWM_DIER_OC4DE) == (PWM_DIER_OC4DE)) ? 1UL : 0UL);
}

/**
  * @}
  */
#endif

/** @defgroup PWM_LL_EF_EVENT_Management EVENT-Management
  * @{
  */
/**
  * @brief  Generate an update event.
  * @rmtoll EGR          UG            LL_PWM_GenerateEvent_UPDATE
  * @param  PWMx Pwm instance
  * @retval None
  */
__STATIC_INLINE void LL_PWM_GenerateEvent_UPDATE(PWM_TypeDef *PWMx)
{
  SET_BIT(PWMx->EGR, PWM_EGR_UG);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PWM_LL_EF_Init Initialisation and deinitialisation functions
  * @{
  */

ErrorStatus LL_PWM_DeInit(PWM_TypeDef *PWMx);
void LL_PWM_StructInit(LL_PWM_InitTypeDef *PWM_InitStruct);
ErrorStatus LL_PWM_Init(PWM_TypeDef *PWMx, LL_PWM_InitTypeDef *PWM_InitStruct);
void LL_PWM_OC_StructInit(LL_PWM_OC_InitTypeDef *PWM_OC_InitStruct);
ErrorStatus LL_PWM_OC_Init(PWM_TypeDef *PWMx, uint32_t Channel, LL_PWM_OC_InitTypeDef *PWM_OC_InitStruct);
void LL_PWM_BDTR_StructInit(LL_PWM_BDTR_InitTypeDef *PWM_BDTRInitStruct);
ErrorStatus LL_PWM_BDTR_Init(PWM_TypeDef *PWMx, LL_PWM_BDTR_InitTypeDef *PWM_BDTRInitStruct);
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* PWM */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32C882_LL_PWM_H */
/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
