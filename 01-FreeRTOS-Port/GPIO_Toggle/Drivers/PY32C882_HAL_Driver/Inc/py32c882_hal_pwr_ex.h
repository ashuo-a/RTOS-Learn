/**
  ******************************************************************************
  * @file   py32c882_hal_pwr_ex.h
  * @author  MCU Application Team
  * @brief   Header file of PWR HAL Extension module.
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
#ifndef __PY32C882_HAL_PWR_EX_H
#define __PY32C882_HAL_PWR_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup PWREx
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/ 

/* Exported constants --------------------------------------------------------*/
/** @defgroup PWREx_Exported_Constants PWREx Exported Constants
  * @{
  */
/** @defgroup PWREx_GPIO_Bit_Number GPIO bit number for I/O setting in standby/shutdown mode
  * @{
  */
#define PWR_GPIO_BIT_0   PWR_PUCRA_PA_PU0    /*!< GPIO port I/O pin 0  */
#define PWR_GPIO_BIT_1   PWR_PUCRA_PA_PU1    /*!< GPIO port I/O pin 1  */
#define PWR_GPIO_BIT_2   PWR_PUCRA_PA_PU2    /*!< GPIO port I/O pin 2  */
#define PWR_GPIO_BIT_3   PWR_PUCRA_PA_PU3    /*!< GPIO port I/O pin 3  */
#define PWR_GPIO_BIT_4   PWR_PUCRA_PA_PU4    /*!< GPIO port I/O pin 4  */
#define PWR_GPIO_BIT_5   PWR_PUCRA_PA_PU5    /*!< GPIO port I/O pin 5  */
#define PWR_GPIO_BIT_6   PWR_PUCRA_PA_PU6    /*!< GPIO port I/O pin 6  */
#define PWR_GPIO_BIT_7   PWR_PUCRA_PA_PU7    /*!< GPIO port I/O pin 7  */
#define PWR_GPIO_BIT_8   PWR_PUCRA_PA_PU8    /*!< GPIO port I/O pin 8  */
#define PWR_GPIO_BIT_9   PWR_PUCRA_PA_PU9    /*!< GPIO port I/O pin 9  */
#define PWR_GPIO_BIT_10  PWR_PUCRA_PA_PU10   /*!< GPIO port I/O pin 10 */
#define PWR_GPIO_BIT_11  PWR_PUCRA_PA_PU11   /*!< GPIO port I/O pin 11 */
#define PWR_GPIO_BIT_12  PWR_PUCRA_PA_PU12   /*!< GPIO port I/O pin 12 */
#define PWR_GPIO_BIT_13  PWR_PUCRA_PA_PU13   /*!< GPIO port I/O pin 13 */
#define PWR_GPIO_BIT_14  PWR_PUCRA_PA_PU14   /*!< GPIO port I/O pin 14 */
#define PWR_GPIO_BIT_15  PWR_PUCRA_PA_PU15   /*!< GPIO port I/O pin 15 */
/**
  * @}
  */

/** @defgroup PWREx_MR_Voltage_Mode PWREx MR Voltage Mode
  * @{
  */
#define PWR_MR_VOLTAGE_STANDARD          0x00000000                                /*!< MR voltage mode selects standard mode */
#define PWR_MR_VOLTAGE_OVERCLOCK         PWR_CR1_MR_VSEL_0                         /*!< MR voltage mode selects overclock mode */
#define PWR_MR_VOLTAGE_LOW               PWR_CR1_MR_VSEL_1                         /*!< MR voltage mode selects low mode */
/**
  * @}
  */
  
/** @defgroup PWREx_LPR_Voltage_Mode PWREx LPR Voltage Mode
  * @{
  */
#define PWR_LPR_VOLTAGE_HIGH         0x00000000                                  /*!< LPR voltage mode selects high mode */
#define PWR_LPR_VOLTAGE_MEDIUM       PWR_CR1_LPR_VSEL_0                          /*!< LPR voltage mode selects medium mode */
#define PWR_LPR_VOLTAGE_LOW          PWR_CR1_LPR_VSEL_1                          /*!< LPR voltage mode selects low mode */
/**
  * @}
  */
  
/** @defgroup PWREx_DLPR_Voltage_Mode PWREx DLPR Voltage Mode
  * @{
  */
#define PWR_DLPR_VOLTAGE_HIGH         0x00000000                                   /*!< DLPR voltage mode selects high mode */
#define PWR_DLPR_VOLTAGE_MEDIUM       PWR_CR1_DLPR_VSEL_0                          /*!< DLPR voltage mode selects medium mode */
/* #define PWR_DLPR_VOLTAGE_MEDIUM_LOW   PWR_CR1_DLPR_VSEL_1                         */  /*!< DLPR voltage mode selects medium low mode */
/* #define PWR_DLPR_VOLTAGE_LOW          (PWR_CR1_DLPR_VSEL_1 | PWR_CR1_DLPR_VSEL_0) */  /*!< DLPR voltage mode selects low mode */
/**
  * @}
  */

/** @defgroup PWREx_GPIO GPIO port
  * @{
  */
#define PWR_GPIO_A   0x00000000U      /*!< GPIO port A */
#define PWR_GPIO_B   0x00000001U      /*!< GPIO port B */
#define PWR_GPIO_C   0x00000002U      /*!< GPIO port C */
#define PWR_GPIO_D   0x00000003U      /*!< GPIO port D */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PWREx_Exported_Macros PWREx Exported Macros
  *  @{
  */

/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup PWREx_Private_Constants PWREx Private Constants
  * @{
  */

/** @defgroup PWR_FLASH_WAKEUP_DELAY Flash wakeup delay time
  * @{
  */  
/* #define PWR_WAKEUP_FLASH_DELAY_3US  0x00000000U */
#define PWR_WAKEUP_FLASH_DELAY_5US  PWR_CR1_FLS_SLPTIME_0
/* #define PWR_WAKEUP_FLASH_DELAY_1US  PWR_CR1_FLS_SLPTIME_1 */
/* #define PWR_WAKEUP_FLASH_DELAY_0US  (PWR_CR1_FLS_SLPTIME_1 | PWR_CR1_FLS_SLPTIME_0) */

 /**
  * @}
  */

/** @defgroup PWR_MRREADY_WAKEUP_DELAY standby wakeup MR ready delay time
  * @{
  */  
#define PWR_WAKEUP_MRREADY_DELAY_0US   0x00000000U
#define PWR_WAKEUP_MRREADY_DELAY_5US   PWR_CR1_STDBY_MRRDY_WAIT_0
#define PWR_WAKEUP_MRREADY_DELAY_10US  PWR_CR1_STDBY_MRRDY_WAIT_1
#define PWR_WAKEUP_MRREADY_DELAY_20US  (PWR_CR1_STDBY_MRRDY_WAIT_1 | PWR_CR1_STDBY_MRRDY_WAIT_0)

 /**
  * @}
  */


/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup PWREx_Private_Macros PWREx Private Macros
  * @{
  */

/** @defgroup PWREx_IS_PWR_Definitions PWREx Private macros to check input parameters
  * @{
  */
#define IS_PWR_GPIO_BIT_NUMBER(BIT_NUMBER) (((BIT_NUMBER) & GPIO_PIN_MASK) != (uint32_t)0x00U)
#define IS_PWR_GPIO(GPIO) (((GPIO) == PWR_GPIO_A) ||\
                           ((GPIO) == PWR_GPIO_B) ||\
                           ((GPIO) == PWR_GPIO_C) ||\
                           ((GPIO) == PWR_GPIO_D))

/**
  * @}
  */

/**
  * @}
  */

/* Exported Functions --------------------------------------------------------*/
/** @defgroup PWREx_Exported_Functions PWREx Exported Functions
  *  @{
  */

/** @addtogroup PWREx_Exported_Functions_Group1
  * @{
  */
void HAL_PWREx_SetWakeupFlashDelay(uint32_t DelayTime);
uint32_t HAL_PWREx_GetWakeupFlashDelay(void);
void HAL_PWREx_SetWakeupMrReadyDelay(uint32_t DelayTime);
uint32_t HAL_PWREx_GetWakeupMrReadyDelay(void);
void HAL_PWREx_DisableHSIWakeupWait(void);
void HAL_PWREx_EnableHSIWakeupWait(void);
void HAL_PWREx_DisableFlashWakeupWait(void);
void HAL_PWREx_EnableFlashWakeupWait(void);
void HAL_PWREx_EnablePowerOnLoad(void);
void HAL_PWREx_DisablePowerOnLoad(void);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber);
void HAL_PWREx_EnablePullUpPullDownConfig(void);
void HAL_PWREx_DisablePullUpPullDownConfig(void);
void HAL_PWREx_EnableSRAM1ContentRetention(void);
void HAL_PWREx_DisableSRAM1ContentRetention(void);
void HAL_PWREx_SetMrVoltageMode(uint32_t Voltage);
uint32_t HAL_PWREx_GetMrVoltageMode(void);
void HAL_PWREx_SetLprVoltageMode(uint32_t Voltage);
uint32_t HAL_PWREx_GetLprVoltageMode(void);
void HAL_PWREx_SetDlprVoltageMode(uint32_t Voltage);
uint32_t HAL_PWREx_GetDlprVoltageMode(void);
void HAL_PWREx_SetVoltageRegulatorMode(uint32_t VRMode);
uint32_t HAL_PWREx_GetVoltageRegulatorMode(void);
void HAL_PWREx_EnterLowPowerRunMode(uint32_t Regulator);
HAL_StatusTypeDef HAL_PWREx_ExitLowPowerRunMode(void);
void HAL_PWREx_EnterSTOP0Mode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP1Mode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP2Mode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP3Mode(uint32_t Regulator, uint8_t STOPEntry);
/**
  * @}
  */
/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif


#endif /* __PY32C882_HAL_PWR_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
