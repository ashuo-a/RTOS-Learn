/**
  ******************************************************************************
  * @file    py32c882_hal_gpio_ex.h
  * @author  MCU Application Team
  * @brief   Header file of GPIO HAL Extended module.
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
#ifndef __PY32C882_HAL_GPIO_EX_H
#define __PY32C882_HAL_GPIO_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @defgroup GPIOEx GPIOEx
  * @brief GPIO Extended HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIOEx_Exported_Constants GPIOEx Exported Constants
  * @{
  */

/** @defgroup GPIOEx_Alternate_function_selection GPIOEx Alternate function selection
  * @{
  */
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_TIM1           ((uint8_t)0x00)  /*!< TIM1   Alternate Function mapping */
#define GPIO_AF0_TIM15          ((uint8_t)0x00)  /*!< TIM15  Alternate Function mapping */
#define GPIO_AF0_TIM2           ((uint8_t)0x00)  /*!< TIM2   Alternate Function mapping */
#define GPIO_AF0_USART1         ((uint8_t)0x00)  /*!< USART1 Alternate Function mapping */
#define GPIO_AF0_LPTIM2         ((uint8_t)0x00)  /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF0_SWJ            ((uint8_t)0x00)  /*!< SWJ    Alternate Function mapping */
#define GPIO_AF0_MCO            ((uint8_t)0x00)  /*!< MCO    Alternate Function mapping */
#define GPIO_AF0_TIM16          ((uint8_t)0x00)  /*!< TIM16  Alternate Function mapping */
#define GPIO_AF0_PWM            ((uint8_t)0x00)  /*!< PWM    Alternate Function mapping */
#define GPIO_AF0_LPTIM1         ((uint8_t)0x00)  /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF0_TIM3           ((uint8_t)0x00)  /*!< TIM3   Alternate Function mapping */
#define GPIO_AF0_I2C1           ((uint8_t)0x00)  /*!< I2C1   Alternate Function mapping */
#define GPIO_AF0_SPI2           ((uint8_t)0x00)  /*!< SPI2   Alternate Function mapping */
#define GPIO_AF0_I2S2           ((uint8_t)0x00)  /*!< I2S2   Alternate Function mapping */


/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01)  /*!< TIM1   Alternate Function mapping */
#define GPIO_AF1_LPTIM2        ((uint8_t)0x01)  /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF1_TIM15         ((uint8_t)0x01)  /*!< TIM15  Alternate Function mapping */
#define GPIO_AF1_USART1        ((uint8_t)0x01)  /*!< USART1 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01)  /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF1_I2C1          ((uint8_t)0x01)  /*!< I2C1   Alternate Function mapping */
#define GPIO_AF1_PWM           ((uint8_t)0x01)  /*!< PWM    Alternate Function mapping */
#define GPIO_AF1_UART1         ((uint8_t)0x01)  /*!< UART1  Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01)  /*!< TIM2   Alternate Function mapping */
#define GPIO_AF1_SPI1          ((uint8_t)0x01)  /*!< SPI1   Alternate Function mapping */
#define GPIO_AF1_I2S1          ((uint8_t)0x01)  /*!< I2S1   Alternate Function mapping */
#define GPIO_AF1_TIM16         ((uint8_t)0x01)  /*!< TIM16  Alternate Function mapping */
#define GPIO_AF1_TIM3          ((uint8_t)0x01)  /*!< TIM3   Alternate Function mapping */
#define GPIO_AF1_SPI2          ((uint8_t)0x01)  /*!< SPI2   Alternate Function mapping */
#define GPIO_AF1_I2S2          ((uint8_t)0x01)  /*!< I2S2   Alternate Function mapping */
#define GPIO_AF1_USART2        ((uint8_t)0x01)  /*!< USART2 Alternate Function mapping */
#define GPIO_AF1_TIM17         ((uint8_t)0x01)  /*!< TIM17  Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_LPTIM1        ((uint8_t)0x02)  /*!< LPTIM1  Alternate Function mapping */
#define GPIO_AF2_TIM16         ((uint8_t)0x02)  /*!< TIM16   Alternate Function mapping */
#define GPIO_AF2_TIM15         ((uint8_t)0x02)  /*!< TIM15   Alternate Function mapping */
#define GPIO_AF2_USART1        ((uint8_t)0x02)  /*!< USART1  Alternate Function mapping */
#define GPIO_AF2_I2C1          ((uint8_t)0x02)  /*!< I2C1    Alternate Function mapping */
#define GPIO_AF2_UART1         ((uint8_t)0x02)  /*!< UART1   Alternate Function mapping */
#define GPIO_AF2_LPTIM2        ((uint8_t)0x02)  /*!< LPTIM2  Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02)  /*!< TIM2    Alternate Function mapping */
#define GPIO_AF2_TIM1          ((uint8_t)0x02)  /*!< TIM1    Alternate Function mapping */
#define GPIO_AF2_SPI1          ((uint8_t)0x02)  /*!< SPI1    Alternate Function mapping */
#define GPIO_AF2_I2S1          ((uint8_t)0x02)  /*!< I2S1    Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02)  /*!< TIM3    Alternate Function mapping */
#define GPIO_AF2_SPI2          ((uint8_t)0x02)  /*!< SPI2    Alternate Function mapping */
#define GPIO_AF2_I2S2          ((uint8_t)0x02)  /*!< I2S2    Alternate Function mapping */
#define GPIO_AF2_USART2        ((uint8_t)0x02)  /*!< USART2  Alternate Function mapping */
#define GPIO_AF2_PWM           ((uint8_t)0x02)  /*!< PWM     Alternate Function mapping */
#define GPIO_AF2_LPUART1       ((uint8_t)0x02)  /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF2_I2C2          ((uint8_t)0x02)  /*!< I2C2    Alternate Function mapping */
#define GPIO_AF2_TIM17         ((uint8_t)0x02)  /*!< TIM17   Alternate Function mapping */


/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_LPTIM1         ((uint8_t)0x03U)  /*!< AF3: LPTIM1  Alternate Function mapping      */
#define GPIO_AF3_TIM15          ((uint8_t)0x03U)  /*!< AF3: TIM15   Alternate Function mapping      */
#define GPIO_AF3_TIM2           ((uint8_t)0x03U)  /*!< AF3: TIM2    Alternate Function mapping      */
#define GPIO_AF3_I2C1           ((uint8_t)0x03U)  /*!< AF3: I2C1    Alternate Function mapping      */
#define GPIO_AF3_I2C2           ((uint8_t)0x03U)  /*!< AF3: I2C2    Alternate Function mapping      */
#define GPIO_AF3_TIM2           ((uint8_t)0x03U)  /*!< AF3: TIM2    Alternate Function mapping      */
#define GPIO_AF3_LPUART1        ((uint8_t)0x03U)  /*!< AF3: LPUART1 Alternate Function mapping      */
#define GPIO_AF3_SPI2           ((uint8_t)0x03U)  /*!< AF3: SPI2    Alternate Function mapping      */
#define GPIO_AF3_I2S2           ((uint8_t)0x03U)  /*!< AF3: I2S2    Alternate Function mapping      */
#define GPIO_AF3_TIM1           ((uint8_t)0x03U)  /*!< AF3: TIM1    Alternate Function mapping      */
#define GPIO_AF3_UART1          ((uint8_t)0x03U)  /*!< AF3: UART1   Alternate Function mapping      */
#define GPIO_AF3_USART1         ((uint8_t)0x03U)  /*!< AF3: USART1  Alternate Function mapping      */
#define GPIO_AF3_USART2         ((uint8_t)0x03U)  /*!< AF3: USART2  Alternate Function mapping      */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1           ((uint8_t)0x04)  /*!< I2C1   Alternate Function mapping */
#define GPIO_AF4_I2C2           ((uint8_t)0x04)  /*!< I2C2   Alternate Function mapping */
#define GPIO_AF4_SPI2           ((uint8_t)0x04)  /*!< SPI2   Alternate Function mapping */
#define GPIO_AF4_I2S2           ((uint8_t)0x04)  /*!< I2S2   Alternate Function mapping */
#define GPIO_AF4_TIM1           ((uint8_t)0x04)  /*!< TIM1   Alternate Function mapping */
#define GPIO_AF4_TIM2           ((uint8_t)0x04)  /*!< TIM2   Alternate Function mapping */
#define GPIO_AF4_SPI1           ((uint8_t)0x04)  /*!< SPI1   Alternate Function mapping */
#define GPIO_AF4_I2S1           ((uint8_t)0x04)  /*!< I2S1   Alternate Function mapping */
#define GPIO_AF4_LPTIM2         ((uint8_t)0x04)  /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF4_USART1         ((uint8_t)0x04)  /*!< USART1 Alternate Function mapping */
#define GPIO_AF4_USART2         ((uint8_t)0x04)  /*!< USART2 Alternate Function mapping */
#define GPIO_AF4_UART1          ((uint8_t)0x04)  /*!< UART1  Alternate Function mapping */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_I2C2           ((uint8_t)0x05)  /*!< I2C2   Alternate Function mapping */
#define GPIO_AF5_SPI1           ((uint8_t)0x05)  /*!< SPI1   Alternate Function mapping */
#define GPIO_AF5_I2S1           ((uint8_t)0x05)  /*!< I2S1   Alternate Function mapping */
#define GPIO_AF5_I2C1           ((uint8_t)0x05)  /*!< I2C1   Alternate Function mapping */
#define GPIO_AF5_LPTIM2         ((uint8_t)0x05)  /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF5_LPTIM1         ((uint8_t)0x05)  /*!< LPTIM1 Alternate Function mapping */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_I2C2           ((uint8_t)0x06)  /*!< I2C2  Alternate Function mapping */
#define GPIO_AF6_SPI1           ((uint8_t)0x06)  /*!< SPI1  EVENTOUT Alternate Function mapping  */
#define GPIO_AF6_I2S1           ((uint8_t)0x06)  /*!< I2S1  Alternate Function mapping */
#define GPIO_AF6_I2C1           ((uint8_t)0x06)  /*!< I2C1  Alternate Function mapping */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_TIM1           ((uint8_t)0x07U)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF7_PWM            ((uint8_t)0x07)   /*!< PWM  Alternate Function mapping */
#define GPIO_AF7_I2C2           ((uint8_t)0x07U)  /*!< I2C2 Alternate Function mapping */
#define GPIO_AF7_I2C1           ((uint8_t)0x07U)  /*!< I2C1 Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_LPTIM2        ((uint8_t)0x08U)  /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF8_TIM15         ((uint8_t)0x08U)  /*!< TIM15  Alternate Function mapping */
#define GPIO_AF8_TIM1          ((uint8_t)0x08U)  /*!< TIM1   Alternate Function mapping */
#define GPIO_AF8_I2C1          ((uint8_t)0x08U)  /*!< I2C1   Alternate Function mapping */
#define GPIO_AF8_I2C2          ((uint8_t)0x08U)  /*!< I2C2   Alternate Function mapping */
#define GPIO_AF8_USART1        ((uint8_t)0x08U)  /*!< USART1 Alternate Function mapping */
#define GPIO_AF8_USART2        ((uint8_t)0x08U)  /*!< USART2 Alternate Function mapping */
#define GPIO_AF8_UART2         ((uint8_t)0x08U)  /*!< UART2  Alternate Function mapping */
#define GPIO_AF8_LPTIM1        ((uint8_t)0x08U)  /*!< LPTIM1 Alternate Function mapping */
/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_LPTIM1        ((uint8_t)0x09)  /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF9_TIM15         ((uint8_t)0x09)  /*!< TIM15  Alternate Function mapping */
#define GPIO_AF9_COMP2         ((uint8_t)0x09)  /*!< COMP2  Alternate Function mapping */
#define GPIO_AF9_TIM2          ((uint8_t)0x09)  /*!< TIM2   Alternate Function mapping */
#define GPIO_AF9_COMP1         ((uint8_t)0x09)  /*!< COMP1  Alternate Function mapping */
#define GPIO_AF9_I2C2          ((uint8_t)0x09)  /*!< I2C2   Alternate Function mapping */
#define GPIO_AF9_UART2         ((uint8_t)0x09)  /*!< UART2  Alternate Function mapping */
#define GPIO_AF9_PWM           ((uint8_t)0x09)  /*!< PWM    Alternate Function mapping */
#define GPIO_AF9_TIM1          ((uint8_t)0x09)  /*!< TIM1   Alternate Function mapping */

/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_TIM1         ((uint8_t)0x0A)  /*!< TIM1    Alternate Function mapping */
#define GPIO_AF10_USART1       ((uint8_t)0x0A)  /*!< USART1  Alternate Function mapping */
#define GPIO_AF10_USART2       ((uint8_t)0x0A)  /*!< USART2  Alternate Function mapping */
#define GPIO_AF10_LPUART1      ((uint8_t)0x0A)  /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF10_UART1        ((uint8_t)0x0A)  /*!< UART1   Alternate Function mapping */
#define GPIO_AF10_UART2        ((uint8_t)0x0A)  /*!< UART2   Alternate Function mapping */
#define GPIO_AF10_LPTIM2       ((uint8_t)0x0A)  /*!< LPTIM2  Alternate Function mapping */
#define GPIO_AF10_LPUART2      ((uint8_t)0x0A)  /*!< LPUART2 Alternate Function mapping */

/**
  * @brief   AF 11 selection
  */
#define GPIO_AF11_USART2       ((uint8_t)0x0B)  /*!< USART2  Alternate Function mapping */
#define GPIO_AF11_TIM2         ((uint8_t)0x0B)  /*!< TIM2    Alternate Function mapping */
#define GPIO_AF11_TIM3         ((uint8_t)0x0B)  /*!< TIM3    Alternate Function mapping */
#define GPIO_AF11_SPI1         ((uint8_t)0x0B)  /*!< SPI1    Alternate Function mapping */
#define GPIO_AF11_I2S1         ((uint8_t)0x0B)  /*!< I2S1    Alternate Function mapping */
#define GPIO_AF11_USART1       ((uint8_t)0x0B)  /*!< USART1  Alternate Function mapping */
#define GPIO_AF11_SPI2         ((uint8_t)0x0B)  /*!< SPI2    Alternate Function mapping */
#define GPIO_AF11_I2S2         ((uint8_t)0x0B)  /*!< I2S2    Alternate Function mapping */
#define GPIO_AF11_TIM1         ((uint8_t)0x0B)  /*!< TIM1    Alternate Function mapping */
#define GPIO_AF11_UART1        ((uint8_t)0x0B)  /*!< UART1   Alternate Function mapping */
#define GPIO_AF11_LPTIM1       ((uint8_t)0x0B)  /*!< LPTIM1  Alternate Function mapping */
#define GPIO_AF11_LPUART1      ((uint8_t)0x0B)  /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF11_LPUART2      ((uint8_t)0x0B)  /*!< LPUART2 Alternate Function mapping */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_COMP2         ((uint8_t)0x0C)  /*!< COMP2   Alternate Function mapping */
#define GPIO_AF12_TIM2          ((uint8_t)0x0C)  /*!< TIM2    Alternate Function mapping */
#define GPIO_AF12_LPTIM2        ((uint8_t)0x0C)  /*!< LPTIM2  Alternate Function mapping */
#define GPIO_AF12_TIM1          ((uint8_t)0x0C)  /*!< TIM1    Alternate Function mapping */
#define GPIO_AF12_TIM15         ((uint8_t)0x0C)  /*!< TIM15   Alternate Function mapping */
#define GPIO_AF12_PWM           ((uint8_t)0x0C)  /*!< PWM     Alternate Function mapping */
#define GPIO_AF12_LPUART1       ((uint8_t)0x0C)  /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF12_LPTIM1        ((uint8_t)0x0C)  /*!< LPTIM1  Alternate Function mapping */
#define GPIO_AF12_LPUART2       ((uint8_t)0x0C)  /*!< LPUART2 Alternate Function mapping */
#define GPIO_AF12_UART1         ((uint8_t)0x0C)  /*!< UART1   Alternate Function mapping */
#define GPIO_AF12_SPI1          ((uint8_t)0x0C)  /*!< SPI1    Alternate Function mapping */
#define GPIO_AF12_I2S1          ((uint8_t)0x0C)  /*!< I2S1    Alternate Function mapping */
#define GPIO_AF12_COMP1         ((uint8_t)0x0C)  /*!< COMP1   Alternate Function mapping */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_PWM           ((uint8_t)0x0D)  /*!< PWM    Alternate Function mapping */
#define GPIO_AF13_TIM17         ((uint8_t)0x0D)  /*!< TIM17  Alternate Function mapping */
#define GPIO_AF13_USART2        ((uint8_t)0x0D)  /*!< USART2 Alternate Function mapping */
#define GPIO_AF13_TIM15         ((uint8_t)0x0D)  /*!< TIM15  Alternate Function mapping */
#define GPIO_AF13_TIM1          ((uint8_t)0x0D)  /*!< TIM1   Alternate Function mapping */
#define GPIO_AF13_USART1        ((uint8_t)0x0D)  /*!< USART1 Alternate Function mapping */
#define GPIO_AF13_SPI1          ((uint8_t)0x0D)  /*!< SPI1   Alternate Function mapping */
#define GPIO_AF13_I2S1          ((uint8_t)0x0D)  /*!< I2S1   Alternate Function mapping */
#define GPIO_AF13_PVD           ((uint8_t)0x0D)  /*!< PVD    Alternate Function mapping */
#define GPIO_AF13_UART2         ((uint8_t)0x0D)  /*!< UART2  Alternate Function mapping */
#define GPIO_AF13_I2C2          ((uint8_t)0x0D)  /*!< I2C2   Alternate Function mapping */
#define GPIO_AF13_TIM3          ((uint8_t)0x0D)  /*!< TIM3   Alternate Function mapping */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_IR            ((uint8_t)0x0E)  /*!< IR     Alternate Function mapping */
#define GPIO_AF14_PVD           ((uint8_t)0x0E)  /*!< PVD    Alternate Function mapping */
#define GPIO_AF14_LPTIM1        ((uint8_t)0x0E)  /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF14_LPTIM2        ((uint8_t)0x0E)  /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF14_RTC           ((uint8_t)0x0E)  /*!< RTC    Alternate Function mapping */
#define GPIO_AF14_TIM1          ((uint8_t)0x0E)  /*!< TIM1   Alternate Function mapping */
#define GPIO_AF14_PWM           ((uint8_t)0x0E)  /*!< PWM    Alternate Function mapping */
#define GPIO_AF14_UART2         ((uint8_t)0x0E)  /*!< UART2  Alternate Function mapping */
#define GPIO_AF14_TIM17         ((uint8_t)0x0E)  /*!< TIM17  Alternate Function mapping */


/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_IR            ((uint8_t)0x0FU)  /*!< IR Alternate Function mapping */
#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)  /*!< EVENTOUT Alternate Function mapping  */

#define IS_GPIO_AF(AF)          ((AF) <= (uint8_t)0x0f)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIOEx_Exported_Macros GPIOEx Exported Macros
  * @{
  */

/** @defgroup GPIOEx_Get_Port_Index GPIOEx Get Port Index
  * @{
  */
#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA))? 0uL :\
                                      ((__GPIOx__) == (GPIOB))? 1uL :\
                                      ((__GPIOx__) == (GPIOC))? 2uL :3uL)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32C882_HAL_GPIO_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
