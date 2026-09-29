/**
  ******************************************************************************
  * @file    py32c882_ll_pwr.h
  * @author  MCU Application Team
  * @brief   Header file of PWR LL module.
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
#ifndef PY32C882_LL_PWR_H
#define PY32C882_LL_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c8xx.h"

/** @addtogroup PY32C882_LL_Driver
  * @{
  */

#if defined(PWR)

/** @defgroup PWR_LL PWR
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Constants PWR Exported Constants
  * @{
  */
/** @defgroup PWR_LL_EC_WAKEUP_HSION_MODE WAKEUP HSI ON MODE
  * @{
  */
#define LL_PWR_STOPWAKEUP_HSION_AFTER_MR       PWR_CR1_HSION_CTRL  /* Wake up from the STOP mode, after the MR becomes stable, enable HSI */
#define LL_PWR_STOPWAKEUP_HSION_IMMEDIATE      0x00000000U         /* Wake up from the STOP mode, Enable HSI immediately */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP_FLASH_MODE WAKEUP FLASH ON MODE
  * @{
  */
#define LL_PWR_STOPWAKEUP_FLASHON_AFTER_MSI     0x00000000U          /* Wake up from the STOP mode, after the MSI stable, enable Flash */
#define LL_PWR_STOPWAKEUP_FLASHON_IMMEDIATE     PWR_CR1_FLSSLP_CTRL  /* Wake up from the STOP mode, Enable Flash immediately */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP_FLASH_DELAY WAKEUP FLASH DELAY
  * @{
  */
/* #define LL_PWR_STOPWAKEUP_FLASH_DELAY_3US      (0x00000000U)                                   */ /* Wake up from the STOP mode, Delay 3us enable flash*/
#define LL_PWR_STOPWAKEUP_FLASH_DELAY_5US      (                      PWR_CR1_FLS_SLPTIME_0)  /* Wake up from the STOP mode, Delay 5us enable flash*/
/* #define LL_PWR_STOPWAKEUP_FLASH_DELAY_1US      (PWR_CR1_FLS_SLPTIME_1                      )   */ /* Wake up from the STOP mode, Delay 1us enable flash*/
/* #define LL_PWR_STOPWAKEUP_FLASH_DELAY_0US      (PWR_CR1_FLS_SLPTIME_1 | PWR_CR1_FLS_SLPTIME_0) */ /* Wake up from the STOP mode, Delay 0us enable flash*/
/**
  * @}
  */

/** @defgroup PWR_LL_EC_VOLTAGE_REGULATOR_MODE Voltage Regulator Mode
  * @{
  */  
#define LL_PWR_VOLTAGE_REGULATOR_MODE_MR        0x00000000U            /* MR mode */
#define LL_PWR_VOLTAGE_REGULATOR_MODE_LPR       PWR_CR1_VR_MODE_0      /* LPR mode */
#define LL_PWR_VOLTAGE_REGULATOR_MODE_DLPR      PWR_CR1_VR_MODE_1      /* DLPR mode */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP_FLASH_DELAY WAKEUP FLASH DELAY
  * @{
  */          
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_0US      (0x00000000U)                                             /* Wake up from the STANDBY mode, MR ready wait 0us*/
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_5US      (                             PWR_CR1_STDBY_MRRDY_WAIT_0) /* Wake up from the STANDBY mode, MR ready wait 5us*/
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_10US     (PWR_CR1_STDBY_MRRDY_WAIT_1                             ) /* Wake up from the STANDBY mode, MR ready wait 10us*/
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_20US     (PWR_CR1_STDBY_MRRDY_WAIT_1 | PWR_CR1_STDBY_MRRDY_WAIT_0) /* Wake up from the STANDBY mode, MR ready wait 20us*/
/**
  * @}
  */

/** @defgroup PWR_LL_EC_DLPR_Voltage_Mode DLPR Voltage Mode
  * @{
  */
#define LL_PWR_DLPR_VOLTAGE_HIGH         0x00000000                                   /*!< DLPR voltage mode selects high mode */
#define LL_PWR_DLPR_VOLTAGE_MEDIUM       PWR_CR1_DLPR_VSEL_0                          /*!< DLPR voltage mode selects medium mode */
/* #define LL_PWR_DLPR_VOLTAGE_MEDIUM_LOW   PWR_CR1_DLPR_VSEL_1                          */ /*!< DLPR voltage mode selects medium low mode */
/* #define LL_PWR_DLPR_VOLTAGE_LOW          (PWR_CR1_DLPR_VSEL_1 | PWR_CR1_DLPR_VSEL_0)  */ /*!< DLPR voltage mode selects low mode */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_LPR_Voltage_Mode LPR Voltage Mode
  * @{
  */
#define LL_PWR_LPR_VOLTAGE_HIGH         0x00000000                                  /*!< LPR voltage mode selects high mode */
#define LL_PWR_LPR_VOLTAGE_MEDIUM       PWR_CR1_LPR_VSEL_0                          /*!< LPR voltage mode selects medium mode */
#define LL_PWR_LPR_VOLTAGE_LOW          PWR_CR1_LPR_VSEL_1                          /*!< LPR voltage mode selects low mode */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_MR_Voltage_Mode MR Voltage Mode
  * @{
  */
#define LL_PWR_MR_VOLTAGE_STANDARD          0x00000000                                /*!< MR voltage mode selects standard mode */
#define LL_PWR_MR_VOLTAGE_OVERCLOCK         PWR_CR1_MR_VSEL_0                         /*!< MR voltage mode selects overclock mode */
#define LL_PWR_MR_VOLTAGE_LOW               PWR_CR1_MR_VSEL_1                         /*!< MR voltage mode selects low mode */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_MODE_PWR MODE PWR
  * @{
  */
#define LL_PWR_MODE_RUN                 0x00000000
#define LL_PWR_MODE_STOP0               PWR_CR1_LPMS_0
#define LL_PWR_MODE_STOP1               PWR_CR1_LPMS_1
#define LL_PWR_MODE_STOP2               (PWR_CR1_LPMS_1 | PWR_CR1_LPMS_0)
#define LL_PWR_MODE_STOP3               PWR_CR1_LPMS_2
#define LL_PWR_MODE_STANDBY             (PWR_CR1_LPMS_2 | PWR_CR1_LPMS_0)
#define LL_PWR_MODE_LOWPOWERRUN         (PWR_CR1_LPMS_2 | PWR_CR1_LPMS_1)
/**
  * @}
  */

/** @defgroup PWR_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with LL_PWR_WriteReg function
  * @{
  */
#define LL_PWR_SCR_CVCCPORF                 PWR_SCR_CVCCPORF
#define LL_PWR_SCR_CPINRSTWUF               PWR_SCR_CPINRSTWUF
#define LL_PWR_SCR_CIWDGRSTWUF              PWR_SCR_CIWDGRSTWUF
#define LL_PWR_SCR_CSBF                     PWR_SCR_CSBF
#define LL_PWR_SCR_CWUF                     PWR_SCR_CWUF
#define LL_PWR_SCR_CWUF7                    PWR_SCR_CWUF7
#define LL_PWR_SCR_CWUF6                    PWR_SCR_CWUF6
#define LL_PWR_SCR_CWUF5                    PWR_SCR_CWUF5
#define LL_PWR_SCR_CWUF4                    PWR_SCR_CWUF4
#define LL_PWR_SCR_CWUF3                    PWR_SCR_CWUF3
#define LL_PWR_SCR_CWUF2                    PWR_SCR_CWUF2
#define LL_PWR_SCR_CWUF1                    PWR_SCR_CWUF1
#define LL_PWR_SCR_CWUF0                    PWR_SCR_CWUF0
/**
  * @}
  */

/** @defgroup PWR_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_PWR_ReadReg function
  * @{
  */
#define LL_PWR_SR_WUF                     PWR_SR_WUF 
#define LL_PWR_SR_SBF                     PWR_SR_SBF 
#define LL_PWR_SR_PVDO                    PWR_SR_PVDO
#define LL_PWR_SR_WUF0                    PWR_SR_WUF0
#define LL_PWR_SR_WUF1                    PWR_SR_WUF1
#define LL_PWR_SR_WUF2                    PWR_SR_WUF2
#define LL_PWR_SR_WUF3                    PWR_SR_WUF3
#define LL_PWR_SR_WUF4                    PWR_SR_WUF4
#define LL_PWR_SR_WUF5                    PWR_SR_WUF5
#define LL_PWR_SR_WUF6                    PWR_SR_WUF6
#define LL_PWR_SR_WUF7                    PWR_SR_WUF7
#define LL_PWR_SR_MR_RDY                  PWR_SR_MR_RDY
#define LL_PWR_SR_LPRUN_RUN_SWF           PWR_SR_LPRUN_RUN_SWF
#define LL_PWR_SR_IWDGRST_WUF             PWR_SR_IWDGRST_WUF
#define LL_PWR_SR_PINRST_WUF              PWR_SR_PINRST_WUF
#define LL_PWR_SR_VCC_PORF                PWR_SR_VCC_PORF
/**
  * @}
  */

/** @defgroup PWR_LL_EC_PVDLEVEL Power Voltage Detector Level
  * @{
  */
#define LL_PWR_PVDLEVEL_0                  (PWR_CR2_PVDT_1V8)      /*!< Voltage threshold detected by PVD 1.8 V */
#define LL_PWR_PVDLEVEL_1                  (PWR_CR2_PVDT_2V0)      /*!< Voltage threshold detected by PVD 2.0 V */
#define LL_PWR_PVDLEVEL_2                  (PWR_CR2_PVDT_2V2)      /*!< Voltage threshold detected by PVD 2.2 V */
#define LL_PWR_PVDLEVEL_3                  (PWR_CR2_PVDT_2V4)      /*!< Voltage threshold detected by PVD 2.4 V */
#define LL_PWR_PVDLEVEL_4                  (PWR_CR2_PVDT_2V8)      /*!< Voltage threshold detected by PVD 2.8 V */
#define LL_PWR_PVDLEVEL_5                  (PWR_CR2_PVDT_3V1)      /*!< Voltage threshold detected by PVD 3.1 V */
#define LL_PWR_PVDLEVEL_6                  (PWR_CR2_PVDT_3V7)      /*!< Voltage threshold detected by PVD 3.7 V */
#define LL_PWR_PVDLEVEL_7                  (PWR_CR2_PVDT_4V2)      /*!< Voltage threshold detected by PVD 4.2 V */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_PVDFILTER PVDFILTER
  * @{
  */
#define LL_PWR_PVD_FILTER_1CLOCK          (0x00000000u)                                                   /*!< PVD filter 1    clock */
#define LL_PWR_PVD_FILTER_2CLOCK          (                                          PWR_CR2_FLT_TIME_0)  /*!< PVD filter 2    clock */
#define LL_PWR_PVD_FILTER_4CLOCK          (                     PWR_CR2_FLT_TIME_1                     )  /*!< PVD filter 2    clock */
#define LL_PWR_PVD_FILTER_16CLOCK         (                     PWR_CR2_FLT_TIME_1 | PWR_CR2_FLT_TIME_0)  /*!< PVD filter 4    clock */
#define LL_PWR_PVD_FILTER_64CLOCK         (PWR_CR2_FLT_TIME_2                                          )  /*!< PVD filter 16   clock */
#define LL_PWR_PVD_FILTER_128CLOCK        (PWR_CR2_FLT_TIME_2                      | PWR_CR2_FLT_TIME_0)  /*!< PVD filter 128  clock */
#define LL_PWR_PVD_FILTER_1024CLOCK       (PWR_CR2_FLT_TIME_2 | PWR_CR2_FLT_TIME_1                     )  /*!< PVD filter 1024 clock */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP_PIN  Wakeup Pins
  * @{
  */
#define LL_PWR_WAKEUP_PIN0                 (PWR_CR3_EWUP0)         /*!< WKUP pin 0 */
#define LL_PWR_WAKEUP_PIN1                 (PWR_CR3_EWUP1)         /*!< WKUP pin 1 */
#define LL_PWR_WAKEUP_PIN2                 (PWR_CR3_EWUP2)         /*!< WKUP pin 2  */
#define LL_PWR_WAKEUP_PIN3                 (PWR_CR3_EWUP3)         /*!< WKUP pin 3 */
#define LL_PWR_WAKEUP_PIN4                 (PWR_CR3_EWUP4)         /*!< WKUP pin 4 */
#define LL_PWR_WAKEUP_PIN5                 (PWR_CR3_EWUP5)         /*!< WKUP pin 5 */
#define LL_PWR_WAKEUP_PIN6                 (PWR_CR3_EWUP6)         /*!< WKUP pin 6 */
#define LL_PWR_WAKEUP_PIN7                 (PWR_CR3_EWUP7)         /*!< WKUP pin 7 */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_GPIO GPIO
  * @{
  */
#define LL_PWR_GPIO_A                      ((uint32_t)(&(PWR->PUCRA)))
#define LL_PWR_GPIO_B                      ((uint32_t)(&(PWR->PUCRB)))
#define LL_PWR_GPIO_C                      ((uint32_t)(&(PWR->PUCRC)))
#define LL_PWR_GPIO_D                      ((uint32_t)(&(PWR->PUCRD)))
/**
  * @}
  */

/** @defgroup PWR_LL_EC_GPIO_BIT GPIO BIT
  * @{
  */
#define LL_PWR_GPIO_BIT_0                  ((uint32_t)0x00000001)
#define LL_PWR_GPIO_BIT_1                  ((uint32_t)0x00000002)
#define LL_PWR_GPIO_BIT_2                  ((uint32_t)0x00000004)
#define LL_PWR_GPIO_BIT_3                  ((uint32_t)0x00000008)
#define LL_PWR_GPIO_BIT_4                  ((uint32_t)0x00000010)
#define LL_PWR_GPIO_BIT_5                  ((uint32_t)0x00000020)
#define LL_PWR_GPIO_BIT_6                  ((uint32_t)0x00000040)
#define LL_PWR_GPIO_BIT_7                  ((uint32_t)0x00000080)
#define LL_PWR_GPIO_BIT_8                  ((uint32_t)0x00000100)
#define LL_PWR_GPIO_BIT_9                  ((uint32_t)0x00000200)
#define LL_PWR_GPIO_BIT_10                 ((uint32_t)0x00000400)
#define LL_PWR_GPIO_BIT_11                 ((uint32_t)0x00000800)
#define LL_PWR_GPIO_BIT_12                 ((uint32_t)0x00001000)
#define LL_PWR_GPIO_BIT_13                 ((uint32_t)0x00002000)
#define LL_PWR_GPIO_BIT_14                 ((uint32_t)0x00004000)
#define LL_PWR_GPIO_BIT_15                 ((uint32_t)0x00008000)
/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Macros PWR Exported Macros
  * @{
  */

/** @defgroup PWR_LL_EM_WRITE_READ Common write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in PWR register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_PWR_WriteReg(__REG__, __VALUE__) WRITE_REG(PWR->__REG__, (__VALUE__))

/**
  * @brief  Read a value in PWR register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_PWR_ReadReg(__REG__) READ_REG(PWR->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Functions PWR Exported Functions
  * @{
  */

/** @defgroup PWR_LL_EF_Configuration Configuration
  * @{
  */
/**
  * @brief  Set the HSI turn on mode after wake up 
  * @rmtoll CR1           HSION_CTRL          LL_PWR_SetStopWakeUpHSIOnMode
  * @param  HsiOnMode This parameter can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_AFTER_MR
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_IMMEDIATE
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetStopWakeUpHSIOnMode(uint32_t HsiOnMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_HSION_CTRL, HsiOnMode);
}

/**
  * @brief  Get the HSI turn on mode after wake up
  * @rmtoll CR1          HSION_CTRL          LL_PWR_GetStopWakeUpHSIOnMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_AFTER_MR
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_IMMEDIATE
  */
__STATIC_INLINE uint32_t LL_PWR_GetStopWakeUpHSIOnMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_HSION_CTRL));
}

/**
  * @brief  Set the FLASH turn on mode after wake up 
  * @rmtoll CR1           FLSSLP_CTRL          LL_PWR_SetStopWakeUpFlashOnMode
  * @param  FlashOnMode This parameter can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASHON_AFTER_MSI
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASHON_IMMEDIATE
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetStopWakeUpFlashOnMode(uint32_t FlashOnMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_FLSSLP_CTRL, FlashOnMode);
}

/**
  * @brief  Get the FLASH turn on mode after wake up
  * @rmtoll CR1          FLSSLP_CTRL          LL_PWR_GetStopWakeUpFlashOnMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASHON_AFTER_MSI
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASHON_IMMEDIATE
  */
__STATIC_INLINE uint32_t LL_PWR_GetStopWakeUpFlashOnMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_FLSSLP_CTRL));
}

/**
  * @brief  Set the flash delay time after wake up 
  * @rmtoll CR1          STDBY_MRRDY_WAIT          LL_PWR_SetStandbyWakeUpMRReadyDelay
  * @param  FlashDelay This parameter can be one of the following values:
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_0US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_5US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_10US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_20US
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetStandbyWakeUpMRReadyDelay(uint32_t FlashDelay)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_STDBY_MRRDY_WAIT, FlashDelay);
}

/**
  * @brief  Get the flash delay time after wake up 
  * @rmtoll CR1          STDBY_MRRDY_WAIT          LL_PWR_GetStandbyWakeUpMRReadyDelay
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_0US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_5US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_10US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_20US
  */
__STATIC_INLINE uint32_t LL_PWR_GetStandbyWakeUpMRReadyDelay(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_STDBY_MRRDY_WAIT));
}

/**
  * @brief  Set DLPR Voltage
  * @rmtoll CR1          PWR_CR1_DLPR_VSEL          LL_PWR_SetDlprVoltageMode
  * @param  Voltage This parameter can be one of the following values:
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_LOW :        Low voltage
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_MEDIUM_LOW : Medium low voltage
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_MEDIUM :     Medium voltage
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_HIGH :       High voltage
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetDlprVoltageMode(uint32_t Voltage)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_DLPR_VSEL, Voltage);
}

/**
  * @brief  Get DLPR Voltage
  * @rmtoll CR1          PWR_CR1_DLPR_VSEL          LL_PWR_GetDlprVoltageMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_LOW :        Low voltage
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_MEDIUM_LOW : Medium low voltage
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_MEDIUM :     Medium voltage
  *         @arg @ref LL_PWR_DLPR_VOLTAGE_HIGH :       High voltage
  */
__STATIC_INLINE uint32_t LL_PWR_GetDlprVoltageMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_DLPR_VSEL));
}

/**
  * @brief  Set LPR Voltage
  * @rmtoll CR1          PWR_CR1_LPR_VSEL          LL_PWR_SetLprVoltageMode
  * @param  Voltage This parameter can be one of the following values:
  *         @arg @ref LL_PWR_LPR_VOLTAGE_LOW :        Low voltage
  *         @arg @ref LL_PWR_LPR_VOLTAGE_MEDIUM :     Medium voltage
  *         @arg @ref LL_PWR_LPR_VOLTAGE_HIGH :       High voltage
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetLprVoltageMode(uint32_t Voltage)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_LPR_VSEL, Voltage);
}

/**
  * @brief  Get LPR Voltage
  * @rmtoll CR1          PWR_CR1_LPR_VSEL          LL_PWR_GetLprVoltageMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_LPR_VOLTAGE_LOW :        Low voltage
  *         @arg @ref LL_PWR_LPR_VOLTAGE_MEDIUM :     Medium voltage
  *         @arg @ref LL_PWR_LPR_VOLTAGE_HIGH :       High voltage
  */
__STATIC_INLINE uint32_t LL_PWR_GetLprVoltageMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_LPR_VSEL));
}

/**
  * @brief  Set MR Voltage
  * @rmtoll CR1          PWR_CR1_MR_VSEL          LL_PWR_SetMrVoltageMode
  * @param  Voltage This parameter can be one of the following values:
  *         @arg @ref LL_PWR_MR_VOLTAGE_LOW :        Low voltage
  *         @arg @ref LL_PWR_MR_VOLTAGE_OVERCLOCK :  Overclock voltage
  *         @arg @ref LL_PWR_MR_VOLTAGE_STANDARD :   Standard voltage
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetMrVoltageMode(uint32_t Voltage)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_MR_VSEL, Voltage);
}

/**
  * @brief  Get MR Voltage
  * @rmtoll CR1          PWR_CR1_MR_VSEL          LL_PWR_GetMrVoltageMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_MR_VOLTAGE_LOW :        Low voltage
  *         @arg @ref LL_PWR_MR_VOLTAGE_OVERCLOCK :  Overclock voltage
  *         @arg @ref LL_PWR_MR_VOLTAGE_STANDARD :   Standard voltage
  */
__STATIC_INLINE uint32_t LL_PWR_GetMrVoltageMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_MR_VSEL));
}

/**
  * @brief  Set the flash delay time after wake up 
  * @rmtoll CR1          FLS_SLPTIME          LL_PWR_SetStopWakeUpFlashDelay
  * @param  FlashDelay This parameter can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_3US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_5US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_1US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_0US
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetStopWakeUpFlashDelay(uint32_t FlashDelay)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_FLS_SLPTIME, FlashDelay);
}

/**
  * @brief  Get the flash delay time after wake up 
  * @rmtoll CR          FLS_SLPTIME          LL_PWR_GetStopWakeUpFlashDelay
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_3US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_5US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_1US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_0US
  */
__STATIC_INLINE uint32_t LL_PWR_GetStopWakeUpFlashDelay(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_FLS_SLPTIME));
}

/**
  * @brief  Set Voltage Regulator mode 
  * @rmtoll CR1          VR_MODE          LL_PWR_SetVoltageRegulatorMode
  * @param  VRMode This parameter can be one of the following values:
  *         @arg @ref LL_PWR_VOLTAGE_REGULATOR_MODE_MR :   Voltage Regulator selects MR mode
  *         @arg @ref LL_PWR_VOLTAGE_REGULATOR_MODE_LPR :  Voltage Regulator selects LPR mode
*         @arg @ref LL_PWR_VOLTAGE_REGULATOR_MODE_DLPR : Voltage Regulator selects DLPR mode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetVoltageRegulatorMode(uint32_t VRMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, VRMode);
}

/**
  * @brief  Get the flash delay time after wake up 
  * @rmtoll CR1          VR_MODE          LL_PWR_GetVoltageRegulatorMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_VOLTAGE_REGULATOR_MODE_MR :   Voltage Regulator selects MR mode
  *         @arg @ref LL_PWR_VOLTAGE_REGULATOR_MODE_LPR :  Voltage Regulator selects LPR mode
  *         @arg @ref LL_PWR_VOLTAGE_REGULATOR_MODE_DLPR : Voltage Regulator selects DLPR mode
  */
__STATIC_INLINE uint32_t LL_PWR_GetVoltageRegulatorMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_VR_MODE));
}

/**
  * @brief  Enable access to the backup domain
  * @rmtoll CR1    DBP       LL_PWR_EnableBkUpAccess
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableBkUpAccess(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @brief  Disable access to the backup domain
  * @rmtoll CR1    DBP       LL_PWR_DisableBkUpAccess
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableBkUpAccess(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @brief  Check if the backup domain is enabled
  * @rmtoll CR1    DBP       LL_PWR_IsEnabledBkUpAccess
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBkUpAccess(void)
{
  return (READ_BIT(PWR->CR1, PWR_CR1_DBP) == (PWR_CR1_DBP));
}

/**
  * @brief  Set Low-Power mode
  * @rmtoll CR1          LPMS          LL_PWR_SetPowerMode
  * @param  LowPowerMode This parameter can be one of the following values:
  *         @arg @ref LL_PWR_MODE_RUN
  *         @arg @ref LL_PWR_MODE_STOP0
  *         @arg @ref LL_PWR_MODE_STOP1
  *         @arg @ref LL_PWR_MODE_STOP2
  *         @arg @ref LL_PWR_MODE_STOP3
  *         @arg @ref LL_PWR_MODE_STANDBY
  *         @arg @ref LL_PWR_MODE_LOWPOWERRUN
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPowerMode(uint32_t LowPowerMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, LowPowerMode);
}

/**
  * @brief  Get Low-Power mode
  * @rmtoll CR1          LPMS          LL_PWR_GetPowerMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_MODE_RUN
  *         @arg @ref LL_PWR_MODE_STOP0
  *         @arg @ref LL_PWR_MODE_STOP1
  *         @arg @ref LL_PWR_MODE_STOP2
  *         @arg @ref LL_PWR_MODE_STOP3
  *         @arg @ref LL_PWR_MODE_STANDBY
  *         @arg @ref LL_PWR_MODE_LOWPOWERRUN
  */
__STATIC_INLINE uint32_t LL_PWR_GetPowerMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_LPMS));
}

/**
  * @}
  */

/** @defgroup PWR_LL_EF_PVD_Management PVD_Management
  * @{
  */

/**
  * @brief  Configure the voltage threshold detected by the Power Voltage Detector
  * @rmtoll CR2    PVDT       LL_PWR_SetPVDLevel
  * @param  PVDLevel This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVDLEVEL_0
  *         @arg @ref LL_PWR_PVDLEVEL_1
  *         @arg @ref LL_PWR_PVDLEVEL_2
  *         @arg @ref LL_PWR_PVDLEVEL_3
  *         @arg @ref LL_PWR_PVDLEVEL_4
  *         @arg @ref LL_PWR_PVDLEVEL_5
  *         @arg @ref LL_PWR_PVDLEVEL_6
  *         @arg @ref LL_PWR_PVDLEVEL_7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPVDLevel(uint32_t PVDLevel)
{
  MODIFY_REG(PWR->CR2, PWR_CR2_PVDT, PVDLevel);
}

/**
  * @brief  Get the voltage threshold detection
  * @rmtoll CR2    PVDT       LL_PWR_GetPVDLevel
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_PVDLEVEL_0
  *         @arg @ref LL_PWR_PVDLEVEL_1
  *         @arg @ref LL_PWR_PVDLEVEL_2
  *         @arg @ref LL_PWR_PVDLEVEL_3
  *         @arg @ref LL_PWR_PVDLEVEL_4
  *         @arg @ref LL_PWR_PVDLEVEL_5
  *         @arg @ref LL_PWR_PVDLEVEL_6
  *         @arg @ref LL_PWR_PVDLEVEL_7
  */
__STATIC_INLINE uint32_t LL_PWR_GetPVDLevel(void)
{
  return (uint32_t)(READ_BIT(PWR->CR2, PWR_CR2_PVDT));
}

/**
  * @brief  Enable Power Voltage Detector
  * @rmtoll CR2    PVDE       LL_PWR_EnablePVD
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePVD(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief  Disable Power Voltage Detector
  * @rmtoll CR2    PVDE       LL_PWR_DisablePVD
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePVD(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief  Check if Power Voltage Detector is enabled
  * @rmtoll CR2    PVDE       LL_PWR_IsEnabledPVD
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVD(void)
{
  return (READ_BIT(PWR->CR2, PWR_CR2_PVDE) == (PWR_CR2_PVDE));
}

/**
  * @brief  Enable PVD Filter
  * @rmtoll CR2          FLTEN          LL_PWR_EnablePVDFilter
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePVDFilter(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_FLTEN);
}

/**
  * @brief  Disable PVD Filter
  * @rmtoll CR2          FLTEN          LL_PWR_DisablePVDFilter
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePVDFilter(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_FLTEN);
}

/**
  * @brief  Check if PVD Filter is enabled
  * @rmtoll CSR          FLTEN          LL_PWR_IsEnabledPVDFilter
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVDFilter(void)
{
  return (READ_BIT(PWR->CR2, PWR_CR2_FLTEN) == (PWR_CR2_FLTEN));
}

/**
  * @brief  Enable PVD digital output synchronous filter
  * @rmtoll CR2          PVD_OUT_SEL          LL_PWR_EnablePVDOutputSynchronousFilter
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePVDOutputSynchronousFilter(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_PVD_OUT_SEL);
}

/**
  * @brief  Disable PVD digital output synchronous filter
  * @rmtoll CR2          PVD_OUT_SEL          LL_PWR_DisablePVDOutputSynchronousFilter
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePVDOutputSynchronousFilter(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_PVD_OUT_SEL);
}

/**
  * @brief  Check if PVD digital output synchronous filter is enabled
  * @rmtoll CR2          PVD_OUT_SEL          LL_PWR_IsEnabledPVDOutputSynchronousFilter
  * @retval None
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVDOutputSynchronousFilter(void)
{
  return ((READ_BIT(PWR->CR2, PWR_CR2_PVD_OUT_SEL) == (PWR_CR2_PVD_OUT_SEL)) ? 1UL : 0UL);
}

/**
  * @brief  PVD detection power supply selection
  * @rmtoll CR2          FLT_TIME          LL_PWR_SetPVDFilter
  * @param  PVDFilter This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVD_FILTER_1CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_2CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_4CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_16CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_64CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_128CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_1024CLOCK
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPVDFilter(uint32_t PVDFilter)
{
  MODIFY_REG(PWR->CR2, PWR_CR2_FLT_TIME, PVDFilter);
}

/**
  * @brief  Get PVD detection power supply 
  * @rmtoll CSR          FLT_CTRL          LL_PWR_GetPVDFilter
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_PVD_FILTER_1CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_2CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_4CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_16CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_64CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_128CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_1024CLOCK
  */
__STATIC_INLINE uint32_t LL_PWR_GetPVDFilter(void)
{
  return (uint32_t)(READ_BIT(PWR->CR2, PWR_CR2_FLT_TIME));
}
/**
  * @}
  */

/** @defgroup PWR_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Enable SRAM1 content retention in Standby mode
  * @rmtoll CR3          SRAM1PDSTD           LL_PWR_EnableSRAM1Retention
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableSRAM1Retention(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_SRAM1PDSTD);
}

/**
  * @brief  Disable SRAM1 content retention in Standby mode
  * @rmtoll CR3          SRAM1PDSTD           LL_PWR_DisableSRAM1Retention
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableSRAM1Retention(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_SRAM1PDSTD);
}

/**
  * @brief  Check if SRAM1 content retention in Standby mode  is enabled
  * @rmtoll CR3          SRAM1PDSTD           LL_PWR_IsEnabledSRAM1Retention
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledSRAM1Retention(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->CR3, PWR_CR3_SRAM1PDSTD);

  return ((temp == (PWR_CR3_SRAM1PDSTD))?1U:0U);
}

/**
  * @brief  Enable pull-up and pull-down configuration
  * @rmtoll CR3          APC           LL_PWR_EnablePUPDCfg
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePUPDCfg(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_APC);
}

/**
  * @brief  Disable pull-up and pull-down configuration
  * @rmtoll CR3          APC           LL_PWR_DisablePUPDCfg
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePUPDCfg(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_APC);
}

/**
  * @brief  Check if pull-up and pull-down configuration  is enabled
  * @rmtoll CR3          APC           LL_PWR_IsEnabledPUPDCfg
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPUPDCfg(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->CR3, PWR_CR3_APC);

  return ((temp == (PWR_CR3_APC))?1U:0U);
}

/**
  * @brief  Enable power-on load
  * @rmtoll CR3          LD_EN           LL_PWR_EnablePowerOnLoad
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePowerOnLoad(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_LD_EN);
}

/**
  * @brief  Disable power-on load
  * @rmtoll CR3          LD_EN           LL_PWR_DisablePowerOnLoad
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePowerOnLoad(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_LD_EN);
}

/**
  * @brief  Check if power-on load  is enabled
  * @rmtoll CR3          LD_EN           LL_PWR_IsEnabledPowerOnLoad
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPowerOnLoad(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->CR3, PWR_CR3_LD_EN);

  return ((temp == (PWR_CR3_LD_EN))?1U:0U);
}

/**
  * @brief  Enable the WakeUp PINx functionality
  * @rmtoll CR3          EWUP0         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP1         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP2         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP3         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP4         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP5         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP6         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP7         LL_PWR_EnableWakeUpPin
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN0
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN6
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableWakeUpPin(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CR3, WakeUpPin);
}

/**
  * @brief  Disable the WakeUp PINx functionality
  * @rmtoll CR3          EWUP0         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP1         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP2         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP3         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP4         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP5         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP6         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP7         LL_PWR_DisableWakeUpPin
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN0
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN6
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableWakeUpPin(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CR3, WakeUpPin);
}

/**
  * @brief  Check if the WakeUp PINx functionality is enabled
  * @rmtoll CR3          EWUP0         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP1         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP2         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP3         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP4         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP5         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP6         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP7         LL_PWR_IsEnabledWakeUpPin
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN0
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN6
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledWakeUpPin(uint32_t WakeUpPin)
{
  uint32_t temp;
  temp = READ_BIT(PWR->CR3, WakeUpPin);

  return ((temp == (WakeUpPin))?1U:0U);
}

/**
  * @brief  Set the Wake-Up pin polarity low for the event detection
  * @rmtoll CR4          WP0           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP1           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP2           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP3           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP4           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP5           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP6           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP7           LL_PWR_SetWakeUpPinPolarityLow
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN0
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN6
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityLow(uint32_t WakeUpPin)
{
  uint32_t position = 0x00u;
  while(((WakeUpPin & (1uL << position)) == 0x00u) && (position < 8u))
  {
    position++;
  }
  MODIFY_REG(PWR->CR4, 0x3u << (2 * position), 0x1u << (2 * position));
}

/**
  * @brief  Set the Wake-Up pin polarity high for the event detection
  * @rmtoll CR4          WP0           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP1           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP2           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP3           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP4           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP5           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP6           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP7           LL_PWR_SetWakeUpPinPolarityHigh
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN0
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN6
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityHigh(uint32_t WakeUpPin)
{
  uint32_t position = 0x00u;
  while(((WakeUpPin & (1uL << position)) == 0x00u) && (position < 8u))
  {
    position++;
  }
  MODIFY_REG(PWR->CR4, 0x3u << (2 * position), 0x0u << (2 * position));
}

/**
  * @brief  Get the Wake-Up pin polarity for the event detection
  * @rmtoll CR4          WP0           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP1           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP2           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP3           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP4           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP5           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP6           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP7           LL_PWR_IsWakeUpPinPolarityLow
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN0
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN6
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsWakeUpPinPolarityLow(uint32_t WakeUpPin)
{
  uint32_t position = 0x00u;
  uint32_t temp;
  while(((WakeUpPin & (1uL << position)) == 0x00u) && (position < 8u))
  {
    position++;
  }
  temp = READ_BIT(PWR->CR4, 0x3u << (2 * position));

  return ((temp == (0x1u << (2 * position)))?1U:0U);
}

/**
  * @brief  Enable GPIO pull-up state in Standby modes
  * @rmtoll PUCRA        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRB        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRD        PU0-15        LL_PWR_EnableGPIOPullUp
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *
  *         (*) value not defined in all devices
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  SET_BIT(*((__IO uint32_t *)GPIO), GPIONumber);
}

/**
  * @brief  Disable GPIO pull-up state in Standby modes
  * @rmtoll PUCRA        PU0-15        LL_PWR_DisableGPIOPullUp\n
  *         PUCRB        PU0-15        LL_PWR_DisableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_DisableGPIOPullUp\n
  *         PUCRD        PU0-15        LL_PWR_DisableGPIOPullUp
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *
  *         (*) value not defined in all devices
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  CLEAR_BIT(*((__IO uint32_t *)GPIO), GPIONumber);
}

/**
  * @brief  Check if GPIO pull-up state is enabled
  * @rmtoll PUCRA        PU0-15        LL_PWR_IsEnabledGPIOPullUp\n
  *         PUCRB        PU0-15        LL_PWR_IsEnabledGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_IsEnabledGPIOPullUp\n
  *         PUCRD        PU0-15        LL_PWR_IsEnabledGPIOPullUp
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *
  *         (*) value not defined in all devices
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  return ((READ_BIT(*((__IO uint32_t *)GPIO), GPIONumber) == (GPIONumber)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIO pull-down state in Standby modes
  * @rmtoll PDCRA        PD0-15        LL_PWR_EnableGPIOPullDown\n
  *         PDCRB        PD0-15        LL_PWR_EnableGPIOPullDown\n
  *         PDCRC        PD0-15        LL_PWR_EnableGPIOPullDown\n
  *         PDCRD        PD0-15        LL_PWR_EnableGPIOPullDown
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *
  *         (*) value not defined in all devices
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  SET_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber);
}

/**
  * @brief  Disable GPIO pull-down state in Standby and Shutdown modes
  * @rmtoll PDCRA        PD0-15        LL_PWR_DisableGPIOPullDown\n
  *         PDCRB        PD0-15        LL_PWR_DisableGPIOPullDown\n
  *         PDCRC        PD0-15        LL_PWR_DisableGPIOPullDown\n
  *         PDCRD        PD0-15        LL_PWR_DisableGPIOPullDown
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *
  *         (*) value not defined in all devices
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  CLEAR_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber);
}

/**
  * @brief  Check if GPIO pull-down state is enabled
  * @rmtoll PDCRA        PD0-15        LL_PWR_IsEnabledGPIOPullDown\n
  *         PDCRB        PD0-15        LL_PWR_IsEnabledGPIOPullDown\n
  *         PDCRC        PD0-15        LL_PWR_IsEnabledGPIOPullDown\n
  *         PDCRD        PD0-15        LL_PWR_IsEnabledGPIOPullDown
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *
  *         (*) value not defined in all devices
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  return ((READ_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber) == (GPIONumber)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup PWR_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get Stand-By Flag
  * @rmtoll SR          SBF           LL_PWR_IsActiveFlag_SB
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_SB(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_SBF);

  return ((temp == (PWR_SR_SBF))?1U:0U);

}

/**
  * @brief  Indicate whether or not the main regulator is ready
  * @rmtoll SR          MR_RDY        LL_PWR_IsActiveFlag_MR_RDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_MR_RDY(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_MR_RDY);

  return ((temp == (PWR_SR_MR_RDY))?1U:0U);
}

/**
  * @brief  Indicate whether or not the core is in run mode
  * @rmtoll SR          LPRUN_RUN_SWF        LL_PWR_IsActiveFlag_LPRUN_RUN_SWF
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_LPRUN_RUN_SWF(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_LPRUN_RUN_SWF);

  return ((temp == (PWR_SR_LPRUN_RUN_SWF))?1U:0U);
}

/**
  * @brief  Indicate if the exit from Standby mode was caused by an IWDG reset
  * @rmtoll SR          IWDGRST_WUF        LL_PWR_IsActiveFlag_IWDGRST_WUF
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_IWDGRST_WUF(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_IWDGRST_WUF);

  return ((temp == (PWR_SR_IWDGRST_WUF))?1U:0U);
}

/**
  * @brief  Indicate whether or not the exit from Standby mode was caused by a PIN reset
  * @rmtoll SR          PINRST_WUF        LL_PWR_IsActiveFlag_PINRST_WUF
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PINRST_WUF(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_PINRST_WUF);

  return ((temp == (PWR_SR_PINRST_WUF))?1U:0U);
}

/**
  * @brief  Indicate whether or not the VCC power-on reset has occurred
  * @rmtoll SR          VCC_PORF        LL_PWR_IsActiveFlag_VCC_PORF
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_VCC_PORF(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_VCC_PORF);

  return ((temp == (PWR_SR_VCC_PORF))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 7
  * @rmtoll SR          WUF7          LL_PWR_IsActiveFlag_WU7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU7(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF7);

  return ((temp == (PWR_SR_WUF7))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 6
  * @rmtoll SR          WUF6          LL_PWR_IsActiveFlag_WU6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU6(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF6);

  return ((temp == (PWR_SR_WUF6))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 5
  * @rmtoll SR          WUF5          LL_PWR_IsActiveFlag_WU5
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU5(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF5);

  return ((temp == (PWR_SR_WUF5))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 4
  * @rmtoll SR          WUF4          LL_PWR_IsActiveFlag_WU4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU4(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF4);

  return ((temp == (PWR_SR_WUF4))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 3
  * @rmtoll SR          WUF3          LL_PWR_IsActiveFlag_WU3
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU3(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF3);

  return ((temp == (PWR_SR_WUF3))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 2
  * @rmtoll SR          WUF2          LL_PWR_IsActiveFlag_WU2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU2(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF2);

  return ((temp == (PWR_SR_WUF2))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 1
  * @rmtoll SR          WUF1          LL_PWR_IsActiveFlag_WU1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU1(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF1);

  return ((temp == (PWR_SR_WUF1))?1U:0U);
}

/**
  * @brief  Get Wake-up Flag 0
  * @rmtoll SR          WUF0          LL_PWR_IsActiveFlag_WU0
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU0(void)
{
  uint32_t temp;
  temp = READ_BIT(PWR->SR, PWR_SR_WUF0);

  return ((temp == (PWR_SR_WUF0))?1U:0U);
}

/**
  * @brief  Clear VCC power-on reset Flag
  * @rmtoll SCR          CVCCPORF          LL_PWR_ClearFlag_VCCPOR
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_VCCPOR(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CVCCPORF);
}

/**
  * @brief  Clear PIN reset wake-up Flag
  * @rmtoll SCR          CPINRSTWUF          LL_PWR_ClearFlag_PINRSTWU
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_PINRSTWU(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CPINRSTWUF);
}

/**
  * @brief  Clear IWDG reset wake-up Flag
  * @rmtoll SCR          CIWDGRSTWUF          LL_PWR_ClearFlag_IWDGRSTWU
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_IWDGRSTWU(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CIWDGRSTWUF);
}

/**
  * @brief  Clear Stand-By Flag
  * @rmtoll SCR          CSBF          LL_PWR_ClearFlag_SB
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_SB(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CSBF);
}

/**
  * @brief  Clear Wake-up Flags
  * @rmtoll SCR          CWUF          LL_PWR_ClearFlag_WU
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF);
}

/**
  * @brief  Clear Wake-up Flag 7
  * @rmtoll SCR          CWUF7         LL_PWR_ClearFlag_WU7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU7(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF7);
}

/**
  * @brief  Clear Wake-up Flag 6
  * @rmtoll SCR          CWUF6         LL_PWR_ClearFlag_WU6
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU6(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF6);
}

/**
  * @brief  Clear Wake-up Flag 5
  * @rmtoll SCR          CWUF5         LL_PWR_ClearFlag_WU5
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU5(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF5);
}

/**
  * @brief  Clear Wake-up Flag 4
  * @rmtoll SCR          CWUF4         LL_PWR_ClearFlag_WU4
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU4(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF4);
}

/**
  * @brief  Clear Wake-up Flag 3
  * @rmtoll SCR          CWUF3         LL_PWR_ClearFlag_WU3
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU3(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF3);
}

/**
  * @brief  Clear Wake-up Flag 2
  * @rmtoll SCR          CWUF2         LL_PWR_ClearFlag_WU2
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU2(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF2);
}

/**
  * @brief  Clear Wake-up Flag 1
  * @rmtoll SCR          CWUF1         LL_PWR_ClearFlag_WU1
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU1(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF1);
}

/**
  * @brief  Clear Wake-up Flag 0
  * @rmtoll SCR          CWUF0         LL_PWR_ClearFlag_WU0
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU0(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF0);
}

/**
  * @brief  Indicate whether VDD voltage is below or above the selected PVD threshold
  * @rmtoll SR          PVDO          LL_PWR_IsActiveFlag_PVDO
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVDO(void)
{
 uint32_t temp;
 temp = READ_BIT(PWR->SR, PWR_SR_PVDO);

 return ((temp == (PWR_SR_PVDO))?1U:0U);

}

/**
  * @}
  */

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PWR_LL_EF_Init De-initialization function
  * @{
  */
ErrorStatus LL_PWR_DeInit(void);
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

#endif /* defined(PWR) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32C882_LL_PWR_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
