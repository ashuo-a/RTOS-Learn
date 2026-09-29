/**
  ******************************************************************************
  * @file    py32c882_hal_rcc_ex.h
  * @author  MCU Application Team
  * @brief   Header file of RCC HAL Extended module.
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
#ifndef __PY32C882_HAL_RCC_EX_H
#define __PY32C882_HAL_RCC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup RCCEx
  * @{
  */

/* Private Constants ---------------------------------------------------------*/
/* Private Macros ------------------------------------------------------------*/
/** @addtogroup RCCEx_Private_Macros
 * @{
 */

#define IS_RCC_PLL_MUL(__MUL__) ((__MUL__) <= RCC_PLL_MUL18)
#if defined(RCC_LSE_SUPPORT) && defined(RCC_HSE_SUPPORT)
#define IS_RCC_MCOSOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCOSOURCE_NOCLOCK)   || ((__SOURCE__) == RCC_MCOSOURCE_SYSCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HSI10M) || ((__SOURCE__) == RCC_MCOSOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HSE)    || ((__SOURCE__) == RCC_MCOSOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_LSI)    || ((__SOURCE__) == RCC_MCOSOURCE_LSE) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HCLK)   || ((__SOURCE__) == RCC_MCOSOURCE_PCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_MSI)    || ((__SOURCE__) == RCC_MCOSOURCE_LCD_HSI10M))
#elif defined(RCC_HSE_SUPPORT) 
#define IS_RCC_MCOSOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCOSOURCE_NOCLOCK)   || ((__SOURCE__) == RCC_MCOSOURCE_SYSCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HSI10M) || ((__SOURCE__) == RCC_MCOSOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HSE)    || ((__SOURCE__) == RCC_MCOSOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_LSI) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HCLK)   || ((__SOURCE__) == RCC_MCOSOURCE_PCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_MSI)    || ((__SOURCE__) == RCC_MCOSOURCE_LCD_HSI10M))
#elif defined(RCC_LSE_SUPPORT) 
#define IS_RCC_MCOSOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCOSOURCE_NOCLOCK)   || ((__SOURCE__) == RCC_MCOSOURCE_SYSCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HSI10M) || ((__SOURCE__) == RCC_MCOSOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_LSI)    || ((__SOURCE__) == RCC_MCOSOURCE_LSE) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HCLK)   || ((__SOURCE__) == RCC_MCOSOURCE_PCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_MSI)    || ((__SOURCE__) == RCC_MCOSOURCE_LCD_HSI10M))
#else
#define IS_RCC_MCOSOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCOSOURCE_NOCLOCK)   || ((__SOURCE__) == RCC_MCOSOURCE_SYSCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HSI10M) || ((__SOURCE__) == RCC_MCOSOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_LSI)  \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_HCLK)   || ((__SOURCE__) == RCC_MCOSOURCE_PCLK) \
                                    || ((__SOURCE__) == RCC_MCOSOURCE_MSI)    || ((__SOURCE__) == RCC_MCOSOURCE_LCD_HSI10M))
#endif
#if defined(RCC_CCIPR_CANSEL)
#if defined(RCC_HSE_SUPPORT)
#define IS_RCC_CANCLKSOURCE(__CANCLK__)  (((__CANCLK__) == RCC_CANCLKSOURCE_PLL) || ((__CANCLK__) == RCC_CANCLKSOURCE_PCLK)   || \
                                          ((__CANCLK__) == RCC_CANCLKSOURCE_HSE))
#else
#define IS_RCC_CANCLKSOURCE(__CANCLK__)  (((__CANCLK__) == RCC_CANCLKSOURCE_PLL) || ((__CANCLK__) == RCC_CANCLKSOURCE_PCLK))
#endif
#endif
#define IS_RCC_PVDDETECTCLKSOURCE(__PVDDETECTCLK__)  (((__PVDDETECTCLK__) == RCC_PVDDETECTCLKSOURCE_PCLK) || ((__PVDDETECTCLK__) == RCC_PVDDETECTCLKSOURCE_LSC))

#define IS_RCC_COMP1CLKSOURCE(__COMP1CLK__)  (((__COMP1CLK__) == RCC_COMP1CLKSOURCE_PCLK) || ((__COMP1CLK__) == RCC_COMP1CLKSOURCE_LSC))

#define IS_RCC_COMP2CLKSOURCE(__COMP2CLK__)  (((__COMP2CLK__) == RCC_COMP2CLKSOURCE_PCLK) || ((__COMP2CLK__) == RCC_COMP2CLKSOURCE_LSC))
#if defined(RCC_LSE_SUPPORT) 
#define IS_RCC_LPUART1CLKSOURCE(__LPUART1CLK__) (((__LPUART1CLK__) == RCC_LPUART1CLKSOURCE_PCLK) || ((__LPUART1CLK__) == RCC_LPUART1CLKSOURCE_SYSCLK) || \
                                                 ((__LPUART1CLK__) == RCC_LPUART1CLKSOURCE_LSI)  || ((__LPUART1CLK__) == RCC_LPUART1CLKSOURCE_LSE))
#else
#define IS_RCC_LPUART1CLKSOURCE(__LPUART1CLK__) (((__LPUART1CLK__) == RCC_LPUART1CLKSOURCE_PCLK) || ((__LPUART1CLK__) == RCC_LPUART1CLKSOURCE_SYSCLK) || \
                                                 ((__LPUART1CLK__) == RCC_LPUART1CLKSOURCE_LSI))
#endif
#if defined(RCC_LSE_SUPPORT) 
#define IS_RCC_LPUART2CLKSOURCE(__LPUART2CLK__) (((__LPUART2CLK__) == RCC_LPUART2CLKSOURCE_PCLK) || ((__LPUART2CLK__) == RCC_LPUART2CLKSOURCE_SYSCLK) || \
                                                 ((__LPUART2CLK__) == RCC_LPUART2CLKSOURCE_LSI)  || ((__LPUART2CLK__) == RCC_LPUART2CLKSOURCE_LSE))
#else
#define IS_RCC_LPUART2CLKSOURCE(__LPUART2CLK__) (((__LPUART2CLK__) == RCC_LPUART2CLKSOURCE_PCLK) || ((__LPUART2CLK__) == RCC_LPUART2CLKSOURCE_SYSCLK) || \
                                                 ((__LPUART2CLK__) == RCC_LPUART2CLKSOURCE_LSI))
#endif

#if defined(RCC_LSE_SUPPORT) 
#define IS_RCC_LPTIM1CLKSOURCE(__LPTIM1CLK__)  (((__LPTIM1CLK__) == RCC_LPTIM1CLKSOURCE_PCLK) || ((__LPTIM1CLK__) == RCC_LPTIM1CLKSOURCE_LSI) || \
                                                ((__LPTIM1CLK__) == RCC_LPTIM1CLKSOURCE_LSE))
#else
#define IS_RCC_LPTIM1CLKSOURCE(__LPTIM1CLK__)  (((__LPTIM1CLK__) == RCC_LPTIM1CLKSOURCE_PCLK) || ((__LPTIM1CLK__) == RCC_LPTIM1CLKSOURCE_LSI))
#endif
#if defined(RCC_LSE_SUPPORT) 
#define IS_RCC_LPTIM2CLKSOURCE(__LPTIM2CLK__)  (((__LPTIM2CLK__) == RCC_LPTIM2CLKSOURCE_PCLK) || ((__LPTIM2CLK__) == RCC_LPTIM2CLKSOURCE_LSI) || \
                                                ((__LPTIM2CLK__) == RCC_LPTIM2CLKSOURCE_LSE))
#else
#define IS_RCC_LPTIM2CLKSOURCE(__LPTIM2CLK__)  (((__LPTIM2CLK__) == RCC_LPTIM2CLKSOURCE_PCLK) || ((__LPTIM2CLK__) == RCC_LPTIM2CLKSOURCE_LSI))
#endif
#define IS_RCC_ADCCLKSOURCE(__ADCCLK__) (((__ADCCLK__) == RCC_ADCCLKSOURCE_SYSCLK)  || ((__ADCCLK__) == RCC_ADCCLKSOURCE_PLL)   || \
                                         ((__ADCCLK__) == RCC_ADCCLKSOURCE_HSI))

#if defined(RCC_CCIPR_CANSEL)
#define IS_RCC_PERIPHCLOCK(PERIPHCLOCK)  (((PERIPHCLOCK) == RCC_PERIPHCLK_RTC) || ((PERIPHCLOCK) == RCC_PERIPHCLK_IWDG)        || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_CAN) || ((PERIPHCLOCK) == RCC_PERIPHCLK_PVD)      || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_COMP1) || ((PERIPHCLOCK) == RCC_PERIPHCLK_COMP2)  || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_LPUART1) || ((PERIPHCLOCK) == RCC_PERIPHCLK_LPUART2) || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_LPTIM1) || ((PERIPHCLOCK) == RCC_PERIPHCLK_LPTIM2) || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_ADC))
#else
#define IS_RCC_PERIPHCLOCK(PERIPHCLOCK)  (((PERIPHCLOCK) == RCC_PERIPHCLK_RTC) || ((PERIPHCLOCK) == RCC_PERIPHCLK_IWDG)        || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_PVD)      || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_COMP1) || ((PERIPHCLOCK) == RCC_PERIPHCLK_COMP2)  || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_LPUART1) || ((PERIPHCLOCK) == RCC_PERIPHCLK_LPUART2) || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_LPTIM1) || ((PERIPHCLOCK) == RCC_PERIPHCLK_LPTIM2) || \
                                          ((PERIPHCLOCK) == RCC_PERIPHCLK_ADC))
#endif

#if defined(RCC_LSE_SUPPORT) 
#define IS_RCC_LSCSOURCE(__LSCCLK__)  (((__LSCCLK__) == RCC_LSCSOURCE_LSI) || ((__LSCCLK__) == RCC_LSCSOURCE_LSE))
#else
#define IS_RCC_LSCSOURCE(__LSCCLK__)  (((__LSCCLK__) == RCC_LSCSOURCE_LSI))
#endif

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Types RCCEx Exported Types
  * @{
  */

/**
  * @brief  RCC extended clocks structure definition
  */
typedef struct
{
  uint32_t PeriphClockSelection;            /*!< The Extended Clock to be configured.
                                            This parameter can be a value of @ref RCCEx_Periph_Clock_Selection */

  uint32_t RTCClockSelection;              /*!< specifies the RTC clock source.
                                             This parameter can be a value of @ref RCC_RTC_Clock_Source */

  uint32_t IwdgClockSelection;              /*!< specifies the IWDG clock source.
                                             This parameter can be a value of @ref RCC_IWDG_Clock_Source */
#if defined(RCC_CCIPR_CANSEL)
  uint32_t CanClockSelection;              /*!< CAN clock source
                                            This parameter can be a value of @ref RCCEx_CAN_Clock_Source */
#endif
  uint32_t PvdDetectClockSelection;        /*!< PVD detect clock source
                                            This parameter can be a value of @ref RCCEx_PVD_Detect_Clock_Source */
  
  uint32_t Comp1ClockSelection;            /*!< COMP1 clock source
                                            This parameter can be a value of @ref RCCEx_COMP1_Clock_Source */
  
  uint32_t Comp2ClockSelection;            /*!< COMP2 clock source
                                            This parameter can be a value of @ref RCCEx_COMP2_Clock_Source */
  
  uint32_t Lpuart1ClockSelection;          /*!< LPUART1 clock source
                                            This parameter can be a value of @ref RCCEx_LPUART1_Clock_Source */
  
  uint32_t Lpuart2ClockSelection;          /*!< LPUART2 clock source
                                            This parameter can be a value of @ref RCCEx_LPUART2_Clock_Source */
  
  uint32_t Lptim1ClockSelection;            /*!< LPTIM1 clock source
                                            This parameter can be a value of @ref RCCEx_LPTIM1_Clock_Source */
  
  uint32_t Lptim2ClockSelection;            /*!< LPTIM2 clock source
                                            This parameter can be a value of @ref RCCEx_LPTIM2_Clock_Source */
  
  uint32_t AdcClockSelection;              /*!< ADC clock source
                                            This parameter can be a value of @ref RCCEx_ADC_Clock_Source */
} RCC_PeriphCLKInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCCEx_Exported_Constants RCCEx Exported Constants
  * @{
  */

/** @defgroup RCCEx_Periph_Clock_Selection Periph Clock Selection
  * @{
  */
#define RCC_PERIPHCLK_RTC           0x00000001U
#define RCC_PERIPHCLK_IWDG          0x00000002U
#if defined(RCC_CCIPR_CANSEL)
#define RCC_PERIPHCLK_CAN           0x00000004U
#endif
#define RCC_PERIPHCLK_PVD           0x00000008U
#define RCC_PERIPHCLK_COMP1         0x00000010U
#define RCC_PERIPHCLK_COMP2         0x00000020U
#define RCC_PERIPHCLK_LPUART1       0x00000040U
#define RCC_PERIPHCLK_LPUART2       0x00000080U
#define RCC_PERIPHCLK_LPTIM1        0x00000100U
#define RCC_PERIPHCLK_LPTIM2        0x00000200U
#define RCC_PERIPHCLK_ADC           0x00000400U
/**
  * @}
  */

/** @defgroup RCCEx_LSC_Clock_Source LSC Clock Source
  * @{
  */
#define RCC_LSCSOURCE_LSI              0x00000000U
#if defined(RCC_LSE_SUPPORT)
#define RCC_LSCSOURCE_LSE              RCC_BDCR_LSCSEL
#endif
/**
  * @}
  */

#if defined(RCC_CCIPR_CANSEL)
/** @defgroup RCCEx_CAN_Clock_Source CAN Clock Source
  * @{
  */
#define RCC_CANCLKSOURCE_PLL           0x00000000U
#define RCC_CANCLKSOURCE_PCLK          RCC_CCIPR_CANSEL_0
#if defined(RCC_HSE_SUPPORT)
#define RCC_CANCLKSOURCE_HSE           RCC_CCIPR_CANSEL_1
#endif
/**
  * @}
  */
#endif

/** @defgroup RCCEx_PVD_Detect_Clock_Source PVD Detect Clock Source
  * @{
  */
#define RCC_PVDDETECTCLKSOURCE_PCLK    0x00000000U
#define RCC_PVDDETECTCLKSOURCE_LSC     RCC_CCIPR_PVDSEL
/**
  * @}
  */

/** @defgroup RCCEx_COMP1_Clock_Source COMP1 Clock Source
  * @{
  */
#define RCC_COMP1CLKSOURCE_PCLK        0x00000000U
#define RCC_COMP1CLKSOURCE_LSC         RCC_CCIPR_COMP1SEL
/**
  * @}
  */

/** @defgroup RCCEx_COMP2_Clock_Source COMP2 Clock Source
  * @{
  */
#define RCC_COMP2CLKSOURCE_PCLK        0x00000000U
#define RCC_COMP2CLKSOURCE_LSC         RCC_CCIPR_COMP2SEL
/**
  * @}
  */

/** @defgroup RCCEx_LPUART1_Clock_Source LPUART1 Clock Source
  * @{
  */
#define RCC_LPUART1CLKSOURCE_PCLK      0x00000000U
#define RCC_LPUART1CLKSOURCE_SYSCLK    RCC_CCIPR_LPUART1SEL_0
#define RCC_LPUART1CLKSOURCE_LSI       RCC_CCIPR_LPUART1SEL_1
#if defined(RCC_LSE_SUPPORT)
#define RCC_LPUART1CLKSOURCE_LSE       (RCC_CCIPR_LPUART1SEL_0 | RCC_CCIPR_LPUART1SEL_1)
#endif
/**
  * @}
  */

/** @defgroup RCCEx_LPUART2_Clock_Source LPUART1 Clock Source
  * @{
  */
#define RCC_LPUART2CLKSOURCE_PCLK      0x00000000U
#define RCC_LPUART2CLKSOURCE_SYSCLK    RCC_CCIPR_LPUART2SEL_0
#define RCC_LPUART2CLKSOURCE_LSI       RCC_CCIPR_LPUART2SEL_1
#if defined(RCC_LSE_SUPPORT)
#define RCC_LPUART2CLKSOURCE_LSE       (RCC_CCIPR_LPUART2SEL_0 | RCC_CCIPR_LPUART2SEL_1)
#endif
/**
  * @}
  */

/** @defgroup RCCEx_LPTIM1_Clock_Source LPTIM1 Clock Source
  * @{
  */
#define RCC_LPTIM1CLKSOURCE_PCLK       0x00000000U
#define RCC_LPTIM1CLKSOURCE_LSI        RCC_CCIPR_LPTIM1SEL_0
#if defined(RCC_LSE_SUPPORT)
#define RCC_LPTIM1CLKSOURCE_LSE        RCC_CCIPR_LPTIM1SEL
#endif
/**
  * @}
  */
  
/** @defgroup RCCEx_LPTIM2_Clock_Source LPTIM2 Clock Source
  * @{
  */
#define RCC_LPTIM2CLKSOURCE_PCLK       0x00000000U
#define RCC_LPTIM2CLKSOURCE_LSI        RCC_CCIPR_LPTIM2SEL_0
#if defined(RCC_LSE_SUPPORT)
#define RCC_LPTIM2CLKSOURCE_LSE        RCC_CCIPR_LPTIM2SEL
#endif
/**
  * @}
  */
  
/** @defgroup RCCEx_ADC_Clock_Source ADC Clock Source
  * @{
  */
#define RCC_ADCCLKSOURCE_SYSCLK        0x00000000U
#define RCC_ADCCLKSOURCE_PLL           RCC_CCIPR_ADCSEL_0
#define RCC_ADCCLKSOURCE_HSI           RCC_CCIPR_ADCSEL_1
/**
  * @}
  */

/** @defgroup RCCEx_TIM_PCLK_Frequency_Control TIM PCLK Frequency Control
  * @{
  */
#define RCC_TIMPCLK_MUL2       0x00000000U              /*!< TIMER PCLK is twice the system PCLK, but the frequency will not exceed HCLK */
#define RCC_TIMPCLK_MUL1       RCC_CCIPR_TIMCLKCTRL     /*!< TIMER PCLK is the system PCLK */
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RCCEx_Exported_Macros RCCEx Exported Macros
 * @{
 */

/**
  * @}
  */

/** @defgroup RCCEx_HSE_Configuration HSE Configuration
  * @{
  */

/**
  * @}
  */

/** @defgroup RCCEx_Peripheral_Configuration Peripheral Configuration
  * @brief  Macros to configure clock source of different peripherals.
  * @{
  */
#if defined(RCC_CCIPR_CANSEL)
/** @brief  Macro to configure the CAN clock.
  * @param  __CANCLKSOURCE__ specifies the CAN clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_CANCLKSOURCE_PLL   PLL clock selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PCLK  PCLK clock selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_HSE   HSE selected as CAN clock
*/
#define __HAL_RCC_CAN_CONFIG(__CANCLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CANSEL, (uint32_t)(__CANCLKSOURCE__))

/** @brief  Macro to get the CAN clock.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_CANCLKSOURCE_PLL   PLL clock selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PCLK  PCLK clock selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_HSE   HSE selected as CAN clock
  */
#define __HAL_RCC_GET_CAN_SOURCE() ((uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_CANSEL)))
#endif

/** @brief  Macro to configure the PVD detect clock.
  * @param  __PVDDETECTCLKSOURCE__ specifies the CAN clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_PVDDETECTCLKSOURCE_PCLK  PCLK clock selected as PVD detect clock
  *            @arg @ref RCC_PVDDETECTCLKSOURCE_LSC   LSC clock selected as PVD detect clock
*/
#define __HAL_RCC_PVD_CONFIG(__PVDDETECTCLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_PVDSEL, (uint32_t)(__PVDDETECTCLKSOURCE__))

/** @brief  Macro to get the PVD detect clock.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_PVDDETECTCLKSOURCE_PCLK  PCLK clock selected as PVD detect clock
  *            @arg @ref RCC_PVDDETECTCLKSOURCE_LSC   LSC clock selected as PVD detect clock
  */
#define __HAL_RCC_GET_PVD_DETECT_SOURCE() ((uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_PVDSEL)))

/** @brief  Macro to configure the COMP1 clock (COMP1CLK).
  *
  * @param  __COMP1_CLKSOURCE__ specifies the COMP1 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_COMP1CLKSOURCE_PCLK  PCLK selected as COMP1 clock
  *            @arg @ref RCC_COMP1CLKSOURCE_LSC   LSC selected as COMP1 clock
  * @retval None
  */
#define __HAL_RCC_COMP1_CONFIG(__COMP1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP1SEL, (__COMP1_CLKSOURCE__))

/** @brief  Macro to get the COMP1 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_COMP1CLKSOURCE_PCLK  PCLK selected as COMP1 clock
  *            @arg @ref RCC_COMP1CLKSOURCE_LSC   LSC selected as COMP1 clock
  */
#define __HAL_RCC_GET_COMP1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP1SEL))

/** @brief  Macro to configure the COMP2 clock (COMP2CLK).
  *
  * @param  __COMP2_CLKSOURCE__ specifies the COMP2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_COMP2CLKSOURCE_PCLK  PCLK selected as COMP2 clock
  *            @arg @ref RCC_COMP2CLKSOURCE_LSC   LSC selected as COMP2 clock
  * @retval None
  */
#define __HAL_RCC_COMP2_CONFIG(__COMP2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP2SEL, (__COMP2_CLKSOURCE__))

/** @brief  Macro to get the COMP2 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_COMP2CLKSOURCE_PCLK  PCLK selected as COMP2 clock
  *            @arg @ref RCC_COMP2CLKSOURCE_LSC   LSC selected as COMP2 clock
  */
#define __HAL_RCC_GET_COMP2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP2SEL))

/** @brief  Macro to configure the LPUART1 clock (LPUART1CLK).
  *
  * @param  __LPUART1_CLKSOURCE__ specifies the LPUART1 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LPUART1CLKSOURCE_PCLK    PCLK selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_SYSCLK  SYSCLK selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_LSI     HSI selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_LSE     LSE selected as LPUART1 clock
  * @retval None
  */
#define __HAL_RCC_LPUART1_CONFIG(__LPUART1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPUART1SEL, (__LPUART1_CLKSOURCE__))

/** @brief  Macro to get the LPUART1 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_LPUART1CLKSOURCE_PCLK    PCLK selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_SYSCLK  SYSCLK selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_LSI     HSI selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_LSE     LSE selected as LPUART1 clock
  */
#define __HAL_RCC_GET_LPUART1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPUART1SEL))

/** @brief  Macro to configure the LPUART2 clock (LPUAT2CLK).
  *
  * @param  __LPUART2_CLKSOURCE__ specifies the LPUART2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LPUART2CLKSOURCE_PCLK    PCLK selected as LPUART2 clock
  *            @arg @ref RCC_LPUART2CLKSOURCE_SYSCLK  SYSCLK selected as LPUART2 clock
  *            @arg @ref RCC_LPUART2CLKSOURCE_LSI     HSI selected as LPUART2 clock
  *            @arg @ref RCC_LPUART2CLKSOURCE_LSE     LSE selected as LPUART2 clock
  * @retval None
  */
#define __HAL_RCC_LPUART2_CONFIG(__LPUART2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPUART2SEL, (__LPUART2_CLKSOURCE__))

/** @brief  Macro to get the LPUART2 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_LPUART2CLKSOURCE_PCLK    PCLK selected as LPUART2 clock
  *            @arg @ref RCC_LPUART2CLKSOURCE_SYSCLK  SYSCLK selected as LPUART2 clock
  *            @arg @ref RCC_LPUART2CLKSOURCE_LSI     HSI selected as LPUART2 clock
  *            @arg @ref RCC_LPUART2CLKSOURCE_LSE     LSE selected as LPUART2 clock
  */
#define __HAL_RCC_GET_LPUART2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPUART2SEL))

/** @brief  Macro to configure the LPTIM1 clock (LPTIM1CLK).
  *
  * @param  __LPTIM1_CLKSOURCE__ specifies the LPTIM1 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LPTIM1CLKSOURCE_PCLK  PCLK selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSI  HSI selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSE  LSE selected as LPTIM1 clock
  * @retval None
  */
#define __HAL_RCC_LPTIM1_CONFIG(__LPTIM1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL, (__LPTIM1_CLKSOURCE__))

/** @brief  Macro to get the LPTIM1 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_LPTIM1CLKSOURCE_PCLK  PCLK selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSI  HSI selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSE  LSE selected as LPTIM1 clock
  */
#define __HAL_RCC_GET_LPTIM1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL))

/** @brief  Macro to configure the LPTIM2 clock (LPTIM2CLK).
  *
  * @param  __LPTIM2_CLKSOURCE__ specifies the LPTIM2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LPTIM2CLKSOURCE_PCLK  PCLK selected as LPTIM2 clock
  *            @arg @ref RCC_LPTIM2CLKSOURCE_LSI  HSI selected as LPTIM2 clock
  *            @arg @ref RCC_LPTIM2CLKSOURCE_LSE  LSE selected as LPTIM2 clock
  * @retval None
  */
#define __HAL_RCC_LPTIM2_CONFIG(__LPTIM2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPTIM2SEL, (__LPTIM2_CLKSOURCE__))

/** @brief  Macro to get the LPTIM2 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_LPTIM2CLKSOURCE_PCLK  PCLK selected as LPTIM2 clock
  *            @arg @ref RCC_LPTIM2CLKSOURCE_LSI  HSI selected as LPTIM2 clock
  *            @arg @ref RCC_LPTIM2CLKSOURCE_LSE  LSE selected as LPTIM2 clock
  */
#define __HAL_RCC_GET_LPTIM2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPTIM2SEL))

/** @brief  Macro to configure the ADC clock (ADCCLK).
  *
  * @param  __ADC_CLKSOURCE__ specifies the ADC clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_ADCCLKSOURCE_SYSCLK  SYSCLK selected as ADC clock
  *            @arg @ref RCC_ADCCLKSOURCE_PLL  PLL selected as ADC clock
  *            @arg @ref RCC_ADCCLKSOURCE_HSI  HSI selected as ADC clock
  * @retval None
  */
#define __HAL_RCC_ADC_CONFIG(__ADC_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_ADCSEL, (__ADC_CLKSOURCE__))

/** @brief  Macro to get the ADC clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_ADCCLKSOURCE_SYSCLK  SYSCLK selected as ADC clock
  *            @arg @ref RCC_ADCCLKSOURCE_PLL  PLL selected as ADC clock
  *            @arg @ref RCC_ADCCLKSOURCE_HSI  HSI selected as ADC clock
  */
#define __HAL_RCC_GET_ADC_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_ADCSEL))

/** @brief  Macro to configure the TIMER PCLK frequency control.
  * @param  __TIMPCLK_MUL__ TIMPCLK multiple frequency factor.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_TIMPCLK_MUL2 TIMER PCLK is twice the system PCLK, but the frequency will not exceed HCLK
  *            @arg @ref RCC_TIMPCLK_MUL1 TIMER PCLK is the system PCLK
  */
#define __HAL_RCC_TIMPCLK_CONFIG(__TIMPCLK_MUL__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_TIMCLKCTRL, (uint32_t)(__TIMPCLK_MUL__))

/** @brief  Macro to get the TIMPCLK multiple frequency factor.
  * @retval The multiple frequency factor can be one of the following values:
  *            @arg @ref RCC_TIMPCLK_MUL2 TIMER PCLK is twice the system PCLK, but the frequency will not exceed HCLK
  *            @arg @ref RCC_TIMPCLK_MUL1 TIMER PCLK is the system PCLK
  */
#define __HAL_RCC_GET_TIMPCLK_MUL() ((uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_TIMCLKCTRL)))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCCEx_Exported_Functions
  * @{
  */

/** @addtogroup RCCEx_Exported_Functions_Group1
  * @{
  */

HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);
void HAL_RCCEx_SetLSCSource(uint32_t LSCSource);
uint32_t HAL_RCCEx_GetLSCSource(void);

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

#endif /* __PY32C882_HAL_RCC_EX_H */


/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

