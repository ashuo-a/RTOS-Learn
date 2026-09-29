/**
  ******************************************************************************
  * @file    py32c882_hal_pwm_ex.h
  * @author  MCU Application Team
  * @brief   Header file of PWM HAL Extended module.
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
#ifndef __PY32C882_HAL_PWM_EX_H
#define __PY32C882_HAL_PWM_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup PWMEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup PWMEx_Exported_Types PWM Extended Exported Types
  * @{
  */

/**
  * @brief  PWM Break input configuration
  */
typedef struct
{
  uint32_t Source;         /*!< Specifies the source of the pwm break input.
                                This parameter can be a value of @ref PWMEx_Break_Input_Source */
  uint32_t Enable;         /*!< Specifies whether or not the break input source is enabled.
                                This parameter can be a value of @ref PWMEx_Break_Input_Source_Enable */
  uint32_t Polarity;       /*!< Specifies the break input source polarity.
                                This parameter can be a value of @ref PWMEx_Break_Input_Source_Polarity */
} PWMEx_BreakInputConfigTypeDef;
/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup PWMEx_Exported_Constants PWM Extended Exported Constants
  * @{
  */

/** @defgroup PWMEx_Remap PWM Extended Remapping
  * @{
  */
#define PWM_PWM_ETR_GPIO_LS     0x00000000U                                                                     /*!< ETR input is connected to GPIO_LS */
#define PWM_PWM_ETR_COMP1       (                                                            PWM_CR2_ETRSEL_0)  /*!< ETR input is connected to COMP1_OUT */
#define PWM_PWM_ETR_COMP2       (                                        PWM_CR2_ETRSEL_1                    )  /*!< ETR input is connected to COMP2_OUT */
#define PWM_PWM_ETR_SYS_CLK     (                    PWM_CR2_ETRSEL_2                                        )  /*!< ETR input is connected to System clock */
#define PWM_PWM_ETR_GPIO_HS     (                    PWM_CR2_ETRSEL_2                     | PWM_CR2_ETRSEL_0)   /*!< ETR input is connected to GPIO_HS */

/**
  * @}
  */

/** @defgroup PWMEx_Break_Input PWM Extended Break input
  * @{
  */
#define PWM_BREAKINPUT_BRK     0x00000001U                                      /*!< PWM break input  */
/**
  * @}
  */

/** @defgroup PWMEx_Break_Input_Source PWM Extended Break input source
  * @{
  */
#define PWM_BREAKINPUTSOURCE_BKIN     0x00000001U                               /*!< An external source (GPIO) is connected to the BKIN pin  */
#define PWM_BREAKINPUTSOURCE_COMP1    0x00000002U                               /*!< The COMP1 output is connected to the break input */
#define PWM_BREAKINPUTSOURCE_COMP2    0x00000004U                               /*!< The COMP2 output is connected to the break input */

/**
  * @}
  */

/** @defgroup PWMEx_Break_Input_Source_Enable PWM Extended Break input source enabling
  * @{
  */
#define PWM_BREAKINPUTSOURCE_DISABLE     0x00000000U                            /*!< Break input source is disabled */
#define PWM_BREAKINPUTSOURCE_ENABLE      0x00000001U                            /*!< Break input source is enabled */
/**
  * @}
  */

/** @defgroup PWMEx_Break_Input_Source_Polarity PWM Extended Break input polarity
  * @{
  */
#define PWM_BREAKINPUTSOURCE_POLARITY_LOW     0x00000001U                       /*!< Break input source is active low */
#define PWM_BREAKINPUTSOURCE_POLARITY_HIGH    0x00000000U                       /*!< Break input source is active_high */
/**
  * @}
  */
/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PWMEx_Exported_Macros PWM Extended Exported Macros
  * @{
  */

/**
  * @}
  */
/* End of exported macro -----------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/** @defgroup PWMEx_Private_Macros PWM Extended Private Macros
  * @{
  */
#define IS_PWM_REMAP(__REMAP__) ((((__REMAP__) & 0xFFFF1FFFU) == 0x00000000U))

#define IS_PWM_BREAKINPUT(__BREAKINPUT__)  ((__BREAKINPUT__) == PWM_BREAKINPUT_BRK) 

#define IS_PWM_BREAKINPUTSOURCE(__SOURCE__)  (((__SOURCE__) == PWM_BREAKINPUTSOURCE_BKIN)  || \
                                              ((__SOURCE__) == PWM_BREAKINPUTSOURCE_COMP1) || \
                                              ((__SOURCE__) == PWM_BREAKINPUTSOURCE_COMP2))

#define IS_PWM_BREAKINPUTSOURCE_STATE(__STATE__)  (((__STATE__) == PWM_BREAKINPUTSOURCE_DISABLE)  || \
                                                   ((__STATE__) == PWM_BREAKINPUTSOURCE_ENABLE))

#define IS_PWM_BREAKINPUTSOURCE_POLARITY(__POLARITY__)  (((__POLARITY__) == PWM_BREAKINPUTSOURCE_POLARITY_LOW)  || \
                                                         ((__POLARITY__) == PWM_BREAKINPUTSOURCE_POLARITY_HIGH))

/**
  * @}
  */
/* End of private macro ------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PWMEx_Exported_Functions PWM Extended Exported Functions
  * @{
  */

/** @addtogroup PWMEx_Exported_Functions_Group1 Extended PWM Complementary PWM functions
  *  @brief    PWM Complementary PWM functions
  * @{
  */
/*  PWM Complementary PWM functions  ****************************************/
/* Blocking mode: Polling */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Start(PWM_HandleTypeDef *hpwm, uint32_t Channel);
HAL_StatusTypeDef HAL_PWMEx_PWMN_Stop(PWM_HandleTypeDef *hpwm, uint32_t Channel);

/* Non-Blocking mode: Interrupt */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Start_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel);
HAL_StatusTypeDef HAL_PWMEx_PWMN_Stop_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel);
/* Non-Blocking mode: DMA */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Start_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_PWMEx_PWMN_Stop_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup PWMEx_Exported_Functions_Group2 Extended Peripheral Control functions
  *  @brief    Peripheral Control functions
  * @{
  */
/* Extended Control functions  ************************************************/
HAL_StatusTypeDef HAL_PWMEx_ConfigBreakDeadTime(PWM_HandleTypeDef *hpwm,
    PWM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig);
HAL_StatusTypeDef HAL_PWMEx_ConfigBreakInput(PWM_HandleTypeDef *hpwm, uint32_t BreakInput,
                                             const PWMEx_BreakInputConfigTypeDef *sBreakInputConfig);
HAL_StatusTypeDef HAL_PWMEx_RemapConfig(PWM_HandleTypeDef *hpwm, uint32_t Remap);
HAL_StatusTypeDef HAL_PWMEx_ConfigDeadTime(PWM_HandleTypeDef *hpwm, uint32_t Deadtime);
/**
  * @}
  */

/** @addtogroup PWMEx_Exported_Functions_Group3 Extended Callbacks functions
  * @brief    Extended Callbacks functions
  * @{
  */
/* Extended Callback **********************************************************/
void HAL_PWMEx_BreakCallback(PWM_HandleTypeDef *hpwm);
/**
  * @}
  */

/**
  * @}
  */
/* End of exported functions -------------------------------------------------*/

/* Private functions----------------------------------------------------------*/
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


#endif /* __PY32C882_HAL_PWM_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
