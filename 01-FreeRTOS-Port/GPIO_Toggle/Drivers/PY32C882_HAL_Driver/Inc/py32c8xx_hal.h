/**
  ******************************************************************************
  * @file    py32c8xx_hal.h
  * @author  MCU Application Team
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
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
#ifndef __PY32C8xx_HAL_H
#define __PY32C8xx_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_conf.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup HAL
  * @{
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup HAL_Exported_Constants HAL Exported Constants
  * @{
  */

/** @defgroup HAL_TICK_FREQ Tick Frequency
  * @{
  */
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;
/**
  * @}
  */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
/** @addtogroup HAL_Exported_Variables
  * @{
  */
extern uint32_t uwTickPrio;
extern uint32_t uwTickFreq;
/**
  * @}
  */

/** @defgroup SYSCFG_Exported_Constants SYSCFG Exported Constants
  * @{
  */

/** @defgroup SYSCFG_BootMode Boot Mode
  * @{
  */
#define SYSCFG_BOOT_MAINFLASH            0x00000000U                      /*!< Main Flash memory mapped at 0x0000 0000   */
#define SYSCFG_BOOT_SYSTEMFLASH          SYSCFG_CFGR1_MEM_MODE_0          /*!< System Flash memory mapped at 0x0000 0000 */
#define SYSCFG_BOOT_SRAM                 (SYSCFG_CFGR1_MEM_MODE_1 | SYSCFG_CFGR1_MEM_MODE_0)  /*!< Embedded SRAM mapped at 0x0000 0000 */
/**
  * @}
  */

/** @defgroup SYSTEM_TK_LP_TRIG  TK Lowpower Wakeup Trigger Source
  * @{
  */
#define SYSCFG_TK_LP_TRIG_DISABLE        0x00000000U
#define SYSCFG_TK_LP_TRIG_RTC            SYSCFG_CFGR1_TK_LP_TRIG_0
#define SYSCFG_TK_LP_TRIG_LPTIM1         SYSCFG_CFGR1_TK_LP_TRIG_1
#define SYSCFG_TK_LP_TRIG_LPTIM2         (SYSCFG_CFGR1_TK_LP_TRIG_1 | SYSCFG_CFGR1_TK_LP_TRIG_0)
/**
  * @}
  */

/** @defgroup SYSTEM_RTC_TRIG_TK_SEL RTC Trigger TK Select
  * @{
  */
#define SYSCFG_RTC_TRIG_TK_SEL_WAKEUP_TIMER   0x00000000U
#define SYSCFG_RTC_TRIG_TK_SEL_ALARMA         SYSCFG_CFGR1_RTC_TRIG_TKSEL_0
#define SYSCFG_RTC_TRIG_TK_SEL_ALARMB         SYSCFG_CFGR1_RTC_TRIG_TKSEL_1
/**
  * @}
  */

/** @defgroup SYSCFG_Break Break
  * @{
  */
#define SYSCFG_BREAK_SP                SYSCFG_CFGR2_SPL    /*!< Enables and locks the SRAM Parity error signal with Break Input of TIM1/15/16/17/PWM */
#if defined(SYSCFG_CFGR2_PVDL)
#define SYSCFG_BREAK_PVD               SYSCFG_CFGR2_PVDL   /*!< Enables and locks the PVD connection with TIM1/15/16/17/PWM Break Input and also the PVDE bits of the Power Control Interface */
#endif /* SYSCFG_CFGR2_PVDL */
#define SYSCFG_BREAK_LOCKUP            SYSCFG_CFGR2_CLL    /*!< Enables and locks the LOCKUP output of CortexM0+ with Break Input of TIM1/15/16/17/PWM */
#define SYSCFG_BREAK_ECC               SYSCFG_CFGR2_ECCL   /*!< Enables and locks the ECC of CortexM0+ with Break Input of TIM1/15/16/17/PWM */
/**
  * @}
  */

/** @defgroup SYSCFG_EIIC I2C PIN SIGNAL
  * @{
  */
#define SYSCFG_EIIC_PA11    SYSCFG_IOCFG_PA_EIIC_0
#define SYSCFG_EIIC_PA12    SYSCFG_IOCFG_PA_EIIC_1
#define SYSCFG_EIIC_PA13    SYSCFG_IOCFG_PA_EIIC_2
#define SYSCFG_EIIC_PA14    SYSCFG_IOCFG_PA_EIIC_3

#define SYSCFG_EIIC_PB4     SYSCFG_IOCFG_PB_EIIC_0
#define SYSCFG_EIIC_PB5     SYSCFG_IOCFG_PB_EIIC_1
#define SYSCFG_EIIC_PB8     SYSCFG_IOCFG_PB_EIIC_2
#define SYSCFG_EIIC_PB9     SYSCFG_IOCFG_PB_EIIC_3
#define SYSCFG_EIIC_PB12    SYSCFG_IOCFG_PB_EIIC_4
#define SYSCFG_EIIC_PB13    SYSCFG_IOCFG_PB_EIIC_5

#define SYSCFG_EIIC_PD10    SYSCFG_IOCFG_PD_EIIC_10
#define SYSCFG_EIIC_PD11    SYSCFG_IOCFG_PD_EIIC_11

#define SYSCFG_EIIC_PC5     SYSCFG_IOCFG_PC_EIIC_0
#define SYSCFG_EIIC_PC6     SYSCFG_IOCFG_PC_EIIC_1
#define SYSCFG_EIIC_PC7     SYSCFG_IOCFG_PC_EIIC_2
#define SYSCFG_EIIC_PC9     SYSCFG_IOCFG_PC_EIIC_3
#define SYSCFG_EIIC_PC10    SYSCFG_IOCFG_PC_EIIC_4
#define SYSCFG_EIIC_PC12    SYSCFG_IOCFG_PC_EIIC_5
#define SYSCFG_EIIC_PC13    SYSCFG_IOCFG_PC_EIIC_6
#define SYSCFG_EIIC_PC14    SYSCFG_IOCFG_PC_EIIC_7
#define SYSCFG_EIIC_PC15    SYSCFG_IOCFG_PC_EIIC_8

#define SYSCFG_EIIC_PD6     SYSCFG_IOCFG_PD_EIIC_0
#define SYSCFG_EIIC_PD7     SYSCFG_IOCFG_PD_EIIC_1
#define SYSCFG_EIIC_PD14    SYSCFG_IOCFG_PD_EIIC_2
#define SYSCFG_EIIC_PD15    SYSCFG_IOCFG_PD_EIIC_3

/**
  * @}
  */

/** @defgroup SYSCFG_PU_IIC I2C PIN PULL-UP
  * @{
  */
#define SYSCFG_PU_IIC_PD14    SYSCFG_IOCFG_PD_PU_IIC_0
#define SYSCFG_PU_IIC_PD15    SYSCFG_IOCFG_PD_PU_IIC_1
/**
  * @}
  */

/** @defgroup SYSCFG_EHS LED PIN HIGH DRIVER SIGNAL
  * @{
  */
#define SYSCFG_SEGIS_EN_0    SYSCFG_LEDCFG_SEGIS_EN_0
#define SYSCFG_SEGIS_EN_1    SYSCFG_LEDCFG_SEGIS_EN_1
#define SYSCFG_SEGIS_EN_2    SYSCFG_LEDCFG_SEGIS_EN_2
#define SYSCFG_SEGIS_EN_3    SYSCFG_LEDCFG_SEGIS_EN_3

#define SYSCFG_EHS_PB2       SYSCFG_LEDCFG_PB_EHS_0
#define SYSCFG_EHS_PB3       SYSCFG_LEDCFG_PB_EHS_1
#define SYSCFG_EHS_PB4       SYSCFG_LEDCFG_PB_EHS_2
#define SYSCFG_EHS_PB5       SYSCFG_LEDCFG_PB_EHS_3
#define SYSCFG_EHS_PB6       SYSCFG_LEDCFG_PB_EHS_4
#define SYSCFG_EHS_PB7       SYSCFG_LEDCFG_PB_EHS_5
#define SYSCFG_EHS_PB8       SYSCFG_LEDCFG_PB_EHS_6
#define SYSCFG_EHS_PB9       SYSCFG_LEDCFG_PB_EHS_7

#define SYSCFG_ENSEG_PB2     SYSCFG_LEDCFG_PB_ENSEG_0
#define SYSCFG_ENSEG_PB3     SYSCFG_LEDCFG_PB_ENSEG_1
#define SYSCFG_ENSEG_PB4     SYSCFG_LEDCFG_PB_ENSEG_2
#define SYSCFG_ENSEG_PB5     SYSCFG_LEDCFG_PB_ENSEG_3
#define SYSCFG_ENSEG_PB6     SYSCFG_LEDCFG_PB_ENSEG_4
#define SYSCFG_ENSEG_PB7     SYSCFG_LEDCFG_PB_ENSEG_5
#define SYSCFG_ENSEG_PB8     SYSCFG_LEDCFG_PB_ENSEG_6
#define SYSCFG_ENSEG_PB9     SYSCFG_LEDCFG_PB_ENSEG_7
#define SYSCFG_ENSEG_PB10    SYSCFG_LEDCFG_PB_ENSEG_8
#define SYSCFG_ENSEG_PB11    SYSCFG_LEDCFG_PB_ENSEG_9
#define SYSCFG_ENSEG_PB12    SYSCFG_LEDCFG_PB_ENSEG_10
#define SYSCFG_ENSEG_PB13    SYSCFG_LEDCFG_PB_ENSEG_11
#define SYSCFG_ENSEG_PB14    SYSCFG_LEDCFG_PB_ENSEG_12
#define SYSCFG_ENSEG_PB15    SYSCFG_LEDCFG_PB_ENSEG_13

#define SYSCFG_ENSEG_PC0     SYSCFG_LEDCFG_PC_ENSEG_0
#define SYSCFG_ENSEG_PC1     SYSCFG_LEDCFG_PC_ENSEG_1
/**
  * @}
  */

/** @defgroup SYSCFG_SRAMWRP SRAM Write protection
  * @{
  */
#define SYSCFG_SRAMWRP_PAGE0          SYSCFG_SWPR_SRAM_P0WP  /*!< SRAM Write protection page 0 */
#define SYSCFG_SRAMWRP_PAGE1          SYSCFG_SWPR_SRAM_P1WP  /*!< SRAM Write protection page 1 */
#define SYSCFG_SRAMWRP_PAGE2          SYSCFG_SWPR_SRAM_P2WP  /*!< SRAM Write protection page 2 */
#define SYSCFG_SRAMWRP_PAGE3          SYSCFG_SWPR_SRAM_P3WP  /*!< SRAM Write protection page 3 */
#define SYSCFG_SRAMWRP_PAGE4          SYSCFG_SWPR_SRAM_P4WP  /*!< SRAM Write protection page 4 */
#define SYSCFG_SRAMWRP_PAGE5          SYSCFG_SWPR_SRAM_P5WP  /*!< SRAM Write protection page 5 */
#define SYSCFG_SRAMWRP_PAGE6          SYSCFG_SWPR_SRAM_P6WP  /*!< SRAM Write protection page 6 */
#define SYSCFG_SRAMWRP_PAGE7          SYSCFG_SWPR_SRAM_P7WP  /*!< SRAM Write protection page 7 */
#define SYSCFG_SRAMWRP_PAGE8          SYSCFG_SWPR_SRAM_P8WP  /*!< SRAM Write protection page 8 */
#define SYSCFG_SRAMWRP_PAGE9          SYSCFG_SWPR_SRAM_P9WP  /*!< SRAM Write protection page 9 */
#define SYSCFG_SRAMWRP_PAGE10         SYSCFG_SWPR_SRAM_P10WP /*!< SRAM Write protection page 10 */
#define SYSCFG_SRAMWRP_PAGE11         SYSCFG_SWPR_SRAM_P11WP /*!< SRAM Write protection page 11 */
#define SYSCFG_SRAMWRP_PAGE12         SYSCFG_SWPR_SRAM_P12WP /*!< SRAM Write protection page 12 */
#define SYSCFG_SRAMWRP_PAGE13         SYSCFG_SWPR_SRAM_P13WP /*!< SRAM Write protection page 13 */
#define SYSCFG_SRAMWRP_PAGE14         SYSCFG_SWPR_SRAM_P14WP /*!< SRAM Write protection page 14 */
#define SYSCFG_SRAMWRP_PAGE15         SYSCFG_SWPR_SRAM_P15WP /*!< SRAM Write protection page 15 */
#define SYSCFG_SRAMWRP_PAGE16         SYSCFG_SWPR_SRAM_P16WP /*!< SRAM Write protection page 16 */
#define SYSCFG_SRAMWRP_PAGE17         SYSCFG_SWPR_SRAM_P17WP /*!< SRAM Write protection page 17 */
#define SYSCFG_SRAMWRP_PAGE18         SYSCFG_SWPR_SRAM_P18WP /*!< SRAM Write protection page 18 */
#define SYSCFG_SRAMWRP_PAGE19         SYSCFG_SWPR_SRAM_P19WP /*!< SRAM Write protection page 19 */
#define SYSCFG_SRAMWRP_PAGE20         SYSCFG_SWPR_SRAM_P20WP /*!< SRAM Write protection page 20 */
#define SYSCFG_SRAMWRP_PAGE21         SYSCFG_SWPR_SRAM_P21WP /*!< SRAM Write protection page 21 */
#define SYSCFG_SRAMWRP_PAGE22         SYSCFG_SWPR_SRAM_P22WP /*!< SRAM Write protection page 22 */
#define SYSCFG_SRAMWRP_PAGE23         SYSCFG_SWPR_SRAM_P23WP /*!< SRAM Write protection page 23 */
#define SYSCFG_SRAMWRP_PAGE24         SYSCFG_SWPR_SRAM_P24WP /*!< SRAM Write protection page 24 */
#define SYSCFG_SRAMWRP_PAGE25         SYSCFG_SWPR_SRAM_P25WP /*!< SRAM Write protection page 25 */
#define SYSCFG_SRAMWRP_PAGE26         SYSCFG_SWPR_SRAM_P26WP /*!< SRAM Write protection page 26 */
#define SYSCFG_SRAMWRP_PAGE27         SYSCFG_SWPR_SRAM_P27WP /*!< SRAM Write protection page 27 */
#define SYSCFG_SRAMWRP_PAGE28         SYSCFG_SWPR_SRAM_P28WP /*!< SRAM Write protection page 28 */
#define SYSCFG_SRAMWRP_PAGE29         SYSCFG_SWPR_SRAM_P29WP /*!< SRAM Write protection page 29 */
#define SYSCFG_SRAMWRP_PAGE30         SYSCFG_SWPR_SRAM_P30WP /*!< SRAM Write protection page 30 */
#define SYSCFG_SRAMWRP_PAGE31         SYSCFG_SWPR_SRAM_P31WP /*!< SRAM Write protection page 31 */

/**
  * @}
  */

/** @defgroup SYSCFG_flags_definition Flags
  * @{
  */

#define SYSCFG_FLAG_SRAM_PE           SYSCFG_SCSR_SPF       /*!< SRAM parity error (SRAM1) */

/**
  * @}
  */

#if defined(VREFBUF)
/** @defgroup SYSCFG_VREFBUF_VoltageScale VREFBUF Voltage Scale
  * @{
  */
#define SYSCFG_VREFBUF_1P024V         (VREFBUF_CR_VREFBUF_EN)                                                                   /* Vrefbuf 1.024V */  
#define SYSCFG_VREFBUF_1P5V           (VREFBUF_CR_VREFBUF_EN | VREFBUF_CR_VREFBUF_OUT_SEL_0)                                    /* Vrefbuf 1.5V */  
#define SYSCFG_VREFBUF_2P048V         (VREFBUF_CR_VREFBUF_EN | VREFBUF_CR_VREFBUF_OUT_SEL_1)                                    /* Vrefbuf 2.048V */  
#define SYSCFG_VREFBUF_2P5V           (VREFBUF_CR_VREFBUF_EN | VREFBUF_CR_VREFBUF_OUT_SEL_1 | VREFBUF_CR_VREFBUF_OUT_SEL_0)     /* Vrefbuf 2.5V */  
#define SYSCFG_VREFBUF_0P6V           (VREFBUF_CR_VREFBUF_EN | VREFBUF_CR_VREFBUF_OUT_SEL_2)                                    /* Vrefbuf 0.6V */  

/**
  * @}
  */
#endif

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup HAL_Exported_Macros HAL Exported Macros
  * @{
  */

/** @defgroup HAL_Freeze_Unfreeze_Peripherals HAL Freeze Unfreeze Peripherals
  * @brief  Freeze/Unfreeze Peripherals in Debug mode
  * @{
  */
#if defined(DBGMCU_APB_FZ1_DBG_TIM2_STOP)
#define __HAL_DBGMCU_FREEZE_TIM2_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_TIM2_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM2_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_TIM2_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM2_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_TIM3_STOP)
#define __HAL_DBGMCU_FREEZE_TIM3_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_TIM3_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM3_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_TIM3_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM2_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_TIM6_STOP)
#define __HAL_DBGMCU_FREEZE_TIM6_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_TIM6_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM6_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_TIM6_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM6_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_TIM7_STOP)
#define __HAL_DBGMCU_FREEZE_TIM7_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_TIM7_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM7_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_TIM7_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM7_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_RTC_STOP)
#define __HAL_DBGMCU_FREEZE_RTC_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_RTC_STOP))
#define __HAL_DBGMCU_UNFREEZE_RTC_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_RTC_STOP))
#endif /* DBGMCU_APB_FZ_DBG_RTC_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_IWDG_STOP)
#define __HAL_DBGMCU_FREEZE_IWDG_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_IWDG_STOP))
#define __HAL_DBGMCU_UNFREEZE_IWDG_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_IWDG_STOP))
#endif /* DBGMCU_APB_FZ_DBG_IWDG_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_WWDG_STOP)
#define __HAL_DBGMCU_FREEZE_WWDG_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_WWDG_STOP))
#define __HAL_DBGMCU_UNFREEZE_WWDG_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_WWDG_STOP))
#endif /* DBGMCU_APB_FZ_DBG_WWDG_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_I2C1_STOP)
#define __HAL_DBGMCU_FREEZE_I2C1_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_I2C1_STOP))
#define __HAL_DBGMCU_UNFREEZE_I2C1_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_I2C1_STOP))
#endif /* DBGMCU_APB_FZ_DBG_I2C1_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_I2C2_STOP)
#define __HAL_DBGMCU_FREEZE_I2C2_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_I2C2_STOP))
#define __HAL_DBGMCU_UNFREEZE_I2C2_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_I2C2_STOP))
#endif /* DBGMCU_APB_FZ_DBG_I2C2_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_LPTIM1_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM1_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_LPTIM1_STOP))
#define __HAL_DBGMCU_UNFREEZE_LPTIM1_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_LPTIM1_STOP))
#endif /* DBGMCU_APB_FZ_DBG_LPTIM1_STOP */

#if defined(DBGMCU_APB_FZ1_DBG_LPTIM2_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM2_STOP()            (DBGMCU->APBFZ1 |= (DBGMCU_APB_FZ1_DBG_LPTIM2_STOP))
#define __HAL_DBGMCU_UNFREEZE_LPTIM2_STOP()          (DBGMCU->APBFZ1 &= ~(DBGMCU_APB_FZ1_DBG_LPTIM2_STOP))
#endif /* DBGMCU_APB_FZ_DBG_LPTIM2_STOP */

#if defined(DBGMCU_APB_FZ2_DBG_TIM1_STOP)
#define __HAL_DBGMCU_FREEZE_TIM1_STOP()            (DBGMCU->APBFZ2 |= (DBGMCU_APB_FZ2_DBG_TIM1_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM1_STOP()          (DBGMCU->APBFZ2 &= ~(DBGMCU_APB_FZ2_DBG_TIM1_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM1_STOP */

#if defined(DBGMCU_APB_FZ2_DBG_TIM15_STOP)
#define __HAL_DBGMCU_FREEZE_TIM15_STOP()            (DBGMCU->APBFZ2 |= (DBGMCU_APB_FZ2_DBG_TIM15_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM15_STOP()          (DBGMCU->APBFZ2 &= ~(DBGMCU_APB_FZ2_DBG_TIM15_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM15_STOP */

#if defined(DBGMCU_APB_FZ2_DBG_TIM16_STOP)
#define __HAL_DBGMCU_FREEZE_TIM16_STOP()            (DBGMCU->APBFZ2 |= (DBGMCU_APB_FZ2_DBG_TIM16_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM16_STOP()          (DBGMCU->APBFZ2 &= ~(DBGMCU_APB_FZ2_DBG_TIM16_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM16_STOP */

#if defined(DBGMCU_APB_FZ2_DBG_TIM17_STOP)
#define __HAL_DBGMCU_FREEZE_TIM17_STOP()            (DBGMCU->APBFZ2 |= (DBGMCU_APB_FZ2_DBG_TIM17_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM17_STOP()          (DBGMCU->APBFZ2 &= ~(DBGMCU_APB_FZ2_DBG_TIM17_STOP))
#endif /* DBGMCU_APB_FZ_DBG_TIM17_STOP */

#if defined(DBGMCU_APB_FZ2_DBG_PWM_STOP)
#define __HAL_DBGMCU_FREEZE_PWM_STOP()            (DBGMCU->APBFZ2 |= (DBGMCU_APB_FZ2_DBG_PWM_STOP))
#define __HAL_DBGMCU_UNFREEZE_PWM_STOP()          (DBGMCU->APBFZ2 &= ~(DBGMCU_APB_FZ2_DBG_PWM_STOP))
#endif /* DBGMCU_APB_FZ_DBG_PWM_STOP */

/**
  * @}
  */

/** @defgroup SYSCFG_Exported_Macros SYSCFG Exported Macros
  * @{
  */

/** @brief  SYSCFG Break Cortex-M0+ Lockup lock.
  *         Enables and locks the connection of Cortex-M0+ LOCKUP (Hardfault) output to TIM1/15/16/17/PWM Break input
  * @note   The selected configuration is locked and can be unlocked only by system reset.
  */
#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK()        SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL)

/** @brief  SYSCFG Break SRAM parity lock.
  *         Enable and lock the SRAM parity error (SRAM1) signal connection to TIM1/15/16/17/PWM Break input.
  * @note   The selected configuration is locked and can be unlocked by system reset.
  */
#define __HAL_SYSCFG_BREAK_SRAMPARITY_LOCK()    SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_SPL)

#if defined(SYSCFG_CFGR2_PVDL)
/** @brief  SYSCFG Break PVD lock.
  *         Enables and locks the PVD connection with TIM1/15/16/17/PWM Break input, as well as the PVDE in the PWR_CR register
  * @note   The selected configuration is locked and can be unlocked only by system reset
  */
#define __HAL_SYSCFG_BREAK_PVD_LOCK()           SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_PVDL)
#endif

/** @brief  SYSCFG Break ECC lock.
  *         Enable and lock the connection of Flash ECC error connection to TIM1/15/16/17/PWM Break input.
  * @note   The selected configuration is locked and can be unlocked only by system reset.
  */
#define __HAL_SYSCFG_BREAK_ECC_LOCK()           SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_ECCL)

/** @brief  System reset generated when an SRAM parity error occurs.
  */
#if defined(SYSCFG_SCSR_PERR_RSTEN)
#define __HAL_SYSCFG_SYSTEMRST_PERR()           SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_PERR_RSTEN)
#endif

/** @brief  Enable CPU AHB bus Access To GPIO Register.
  * @note   The default configuration is CPU FASTIO after reset.
  */
#if defined(SYSCFG_CFGR1_GPIO_AHB_SEL)
#define __HAL_SYSCFG_GPIO_AHB()                 SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_GPIO_AHB_SEL)
#endif

/** @brief  Set the SPF bit to clear the SRAM Parity Error Flag.
  */
#define __HAL_SYSCFG_CLEAR_FLAG()               SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_SPF)

/** @brief  Check SYSCFG flag is set or not.
  * @param  __FLAG__: specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg @ref SYSCFG_FLAG_SRAM_PE   SRAM Parity Error Flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_SYSCFG_GET_FLAG(__FLAG__)        ((((SYSCFG->CFGR2) & (__FLAG__)) != 0U) ? 1U : 0U)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup HAL_Private_Macros HAL Private Macros
  * @{
  */
#define IS_TICKFREQ(FREQ) (((FREQ) == HAL_TICK_FREQ_10HZ)  || \
                           ((FREQ) == HAL_TICK_FREQ_100HZ) || \
                           ((FREQ) == HAL_TICK_FREQ_1KHZ))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @addtogroup HAL_Exported_Functions
  * @{
  */

/** @addtogroup HAL_Exported_Functions_Group1
  * @{
  */

/* Initialization and de-initialization functions  ******************************/
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
/**
  * @}
  */

/** @addtogroup HAL_Exported_Functions_Group2
  * @{
  */
/* Peripheral Control functions  ************************************************/
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(uint32_t Freq);
uint32_t HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);
/**
  * @}
  */

/** @addtogroup HAL_Exported_Functions_Group3
  * @{
  */
/* HAL Debug functions  *********************************************************/
#if defined(DBGMCU_CR_DBG_SLEEP)
void HAL_DBGMCU_EnableDBGMCUSleepMode(void);
void HAL_DBGMCU_DisableDBGMCUSleepMode(void);
#endif
#if defined(DBGMCU_CR_DBG_STOP)
void HAL_DBGMCU_EnableDBGMCUStopMode(void);
void HAL_DBGMCU_DisableDBGMCUStopMode(void);
#endif
#if defined(DBGMCU_CR_DBG_STDBY)
void HAL_DBGMCU_EnableDBGStandbyMode(void);
void HAL_DBGMCU_DisableDBGStandbyMode(void);
#endif
/**
  * @}
  */

/** @addtogroup HAL_Exported_Functions_Group4
  * @{
  */
/* SYSCFG configuration functions  **********************************************/
void HAL_SYSCFG_SetRemapMemory(uint32_t Memory);
uint32_t HAL_SYSCFG_GetRemapMemory(void);
void HAL_SYSCFG_SetTKLPTRIG(uint32_t Source);
uint32_t HAL_SYSCFG_GetTKLPTRIG(void);
void HAL_SYSCFG_SetRTCTRIGTKSEL(uint32_t Source);
uint32_t HAL_SYSCFG_GetRTCTRIGTKSEL(void);

#if defined(SYSCFG_CFGR1_LPTIM1_TRIG_TKEN)
void HAL_SYSCFG_EnableLPTIM1TrigTK(void);
void HAL_SYSCFG_DisableLPTIM1TrigTK(void);
#endif

#if defined(SYSCFG_CFGR1_LPTIM2_TRIG_TKEN)
void HAL_SYSCFG_EnableLPTIM2TrigTK(void);
void HAL_SYSCFG_DisableLPTIM2TrigTK(void);
#endif

#if (defined(SYSCFG_PA_ENS_PA_ENS) || defined(SYSCFG_PB_ENS_PB_ENS) || defined(SYSCFG_PC_ENS_PC_ENS) || defined(SYSCFG_PD_ENS_PD_ENS))
void HAL_SYSCFG_EnableGPIONoiseFilter(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void HAL_SYSCFG_DisableGPIONoiseFilter(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
#endif

void HAL_SYSCFG_EnableGPIOAnalog2(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void HAL_SYSCFG_DisableGPIOAnalog2(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

void HAL_SYSCFG_EnableI2CPinSignal(uint32_t PORT_Pin);
void HAL_SYSCFG_DisableI2CPinSignal(uint32_t PORT_Pin);

void HAL_SYSCFG_EnableLEDPinHighDrvSignal(uint32_t PORT_Pin);
void HAL_SYSCFG_DisableLEDPinHighDrvSignal(uint32_t PORT_Pin);

void HAL_SYSCFG_EnableI2CPinPullUp(uint32_t PORT_Pin);
void HAL_SYSCFG_DisableI2CPinPullUp(uint32_t PORT_Pin);

void HAL_SYSCFG_EnableSEGConstantCurrentSource(uint32_t SEGx);
void HAL_SYSCFG_DisableSEGConstantCurrentSource(uint32_t SEGx);

void HAL_SYSCFG_EnableGPIOConstantCurrentSource(uint32_t GPIOx);
void HAL_SYSCFG_DisableGPIOConstantCurrentSource(uint32_t GPIOx);

void HAL_SYSCFG_SRAM_WriteProtectionEnable(uint32_t Page);

#if defined(VREFBUF)
void HAL_SYSCFG_EnableVREFBUF(void);
void HAL_SYSCFG_DisableVREFBUF(void);
void HAL_SYSCFG_VREFBUFConfig(uint32_t Vrefbuf);
#endif

/**
  * @}
  */

/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup HAL_Private_Variables HAL Private Variables
  * @{
  */
/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/** @defgroup HAL_Private_Constants HAL Private Constants
  * @{
  */
/**
  * @}
  */
/* Private macros ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32C8xx_HAL_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
