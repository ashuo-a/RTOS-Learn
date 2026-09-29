/**
  ******************************************************************************
  * @file    py32c882_hal_dac_ex.h
  * @author  MCU Application Team
  * @brief   Header file of DAC HAL Extended module.
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
#ifndef PY32C882_HAL_DAC_EX_H
#define PY32C882_HAL_DAC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

#ifdef HAL_DAC_MODULE_ENABLED

/** @addtogroup DACEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  HAL State structures definition
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DACEx_Exported_Constants DACEx Exported Constants
  * @{
  */

/** @defgroup DACEx_lfsrunmask_triangleamplitude DACEx lfsrunmask triangle amplitude
  * @{
  */
#define DAC_LFSRUNMASK_BIT0                0x00000000UL                                                        /*!< Unmask DAC channel LFSR bit0 for noise wave generation */
#define DAC_LFSRUNMASK_BITS1_0             (                                                   DAC_CR1_MAMP_0) /*!< Unmask DAC channel LFSR bit[1:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS2_0             (                                  DAC_CR1_MAMP_1                 ) /*!< Unmask DAC channel LFSR bit[2:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS3_0             (                                  DAC_CR1_MAMP_1 | DAC_CR1_MAMP_0) /*!< Unmask DAC channel LFSR bit[3:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS4_0             (                 DAC_CR1_MAMP_2                                  ) /*!< Unmask DAC channel LFSR bit[4:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS5_0             (                 DAC_CR1_MAMP_2                  | DAC_CR1_MAMP_0) /*!< Unmask DAC channel LFSR bit[5:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS6_0             (                 DAC_CR1_MAMP_2 | DAC_CR1_MAMP_1                 ) /*!< Unmask DAC channel LFSR bit[6:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS7_0             (                 DAC_CR1_MAMP_2 | DAC_CR1_MAMP_1 | DAC_CR1_MAMP_0) /*!< Unmask DAC channel LFSR bit[7:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS8_0             (DAC_CR1_MAMP_3                                                   ) /*!< Unmask DAC channel LFSR bit[8:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS9_0             (DAC_CR1_MAMP_3                                   | DAC_CR1_MAMP_0) /*!< Unmask DAC channel LFSR bit[9:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS10_0            (DAC_CR1_MAMP_3                  | DAC_CR1_MAMP_1                 ) /*!< Unmask DAC channel LFSR bit[10:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS11_0            (DAC_CR1_MAMP_3                  | DAC_CR1_MAMP_1 | DAC_CR1_MAMP_0) /*!< Unmask DAC channel LFSR bit[11:0] for noise wave generation */
#define DAC_TRIANGLEAMPLITUDE_1            0x00000000UL                                                        /*!< Select max triangle amplitude of 1 */
#define DAC_TRIANGLEAMPLITUDE_3            (                                                   DAC_CR1_MAMP_0) /*!< Select max triangle amplitude of 3 */
#define DAC_TRIANGLEAMPLITUDE_7            (                                  DAC_CR1_MAMP_1                 ) /*!< Select max triangle amplitude of 7 */
#define DAC_TRIANGLEAMPLITUDE_15           (                                  DAC_CR1_MAMP_1 | DAC_CR1_MAMP_0) /*!< Select max triangle amplitude of 15 */
#define DAC_TRIANGLEAMPLITUDE_31           (                 DAC_CR1_MAMP_2                                  ) /*!< Select max triangle amplitude of 31 */
#define DAC_TRIANGLEAMPLITUDE_63           (                 DAC_CR1_MAMP_2                  | DAC_CR1_MAMP_0) /*!< Select max triangle amplitude of 63 */
#define DAC_TRIANGLEAMPLITUDE_127          (                 DAC_CR1_MAMP_2 | DAC_CR1_MAMP_1                 ) /*!< Select max triangle amplitude of 127 */
#define DAC_TRIANGLEAMPLITUDE_255          (                 DAC_CR1_MAMP_2 | DAC_CR1_MAMP_1 | DAC_CR1_MAMP_0) /*!< Select max triangle amplitude of 255 */
#define DAC_TRIANGLEAMPLITUDE_511          (DAC_CR1_MAMP_3                                                   ) /*!< Select max triangle amplitude of 511 */
#define DAC_TRIANGLEAMPLITUDE_1023         (DAC_CR1_MAMP_3                                   | DAC_CR1_MAMP_0) /*!< Select max triangle amplitude of 1023 */
#define DAC_TRIANGLEAMPLITUDE_2047         (DAC_CR1_MAMP_3                  | DAC_CR1_MAMP_1                 ) /*!< Select max triangle amplitude of 2047 */
#define DAC_TRIANGLEAMPLITUDE_4095         (DAC_CR1_MAMP_3                  | DAC_CR1_MAMP_1 | DAC_CR1_MAMP_0) /*!< Select max triangle amplitude of 4095 */

/**
  * @}
  */

/** @defgroup DACEx_trigger_selection DAC trigger selection
  * @{
  */
#define DAC_TRIGGER_NONE           0x00000000U            /*!< Conversion is automatic once the DAC1_DHRxxxx register 
                                                                has been loaded, and not by external trigger */
                                                                       
#define DAC_TRIGGER_T6_TRGO        ((uint32_t)(                                                   DAC_CR1_TEN)) /*!< Conversion started by software trigger for DAC channel */                                                                      
#define DAC_TRIGGER_T3_TRGO        ((uint32_t)(                                  DAC_CR1_TSEL_0 | DAC_CR1_TEN))  /*!< TIM8 TRGO selected as external conversion trigger for DAC channel */
#define DAC_TRIGGER_T7_TRGO        ((uint32_t)(                 DAC_CR1_TSEL_1                  | DAC_CR1_TEN))  /*!< TIM7 TRGO selected as external conversion trigger for DAC channel */
#define DAC_TRIGGER_T15_TRGO       ((uint32_t)(                 DAC_CR1_TSEL_1 | DAC_CR1_TSEL_0 | DAC_CR1_TEN)) /*!< TIM15 TRGO selected as external conversion trigger for DAC channel */
#define DAC_TRIGGER_T2_TRGO        ((uint32_t)(DAC_CR1_TSEL_2                                   | DAC_CR1_TEN)) /*!< TIM2 TRGO selected as external conversion trigger for DAC channel */
#define DAC_TRIGGER_EXT_IT9        ((uint32_t)(DAC_CR1_TSEL_2 | DAC_CR1_TSEL_1                  | DAC_CR1_TEN)) /*!< EXTI Line9 event selected as external conversion trigger for DAC channel */
#define DAC_TRIGGER_SOFTWARE       ((uint32_t)(DAC_CR1_TSEL_2 | DAC_CR1_TSEL_1 | DAC_CR1_TSEL_0 | DAC_CR1_TEN)) /*!< TIM6 TRGO selected as external conversion trigger for DAC channel */

/**
  * @}
  */


/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DACEx_Exported_Macros DAC Exported Macros
  * @{
  */

/** @brief Enable the DAC calibretion via ADC.
  * @param  __HANDLE__ specifies the DAC handle.
  * @param  __DAC_Channel__ specifies the DAC channel
  * @retval None
  */
#define __HAL_DAC_ENABLE_CALI_ADC(__HANDLE__, __DAC_Channel__) \
  ((__HANDLE__)->Instance->CR1 |=  (DAC_CR1_DACCEN << ((__DAC_Channel__) & 0x10UL)))

/** @brief Enable the DAC calibretion via internal buffer.
  * @param  __HANDLE__ specifies the DAC handle.
  * @param  __DAC_Channel__ specifies the DAC channel
  * @retval None
  */
#define __HAL_DAC_ENABLE_CALI_BUFF(__HANDLE__, __DAC_Channel__) \
  ((__HANDLE__)->Instance->CR1 |=  (DAC_CR1_BUF_CAL << ((__DAC_Channel__) & 0x10UL)))

/** @brief Set the DAC trimming value (Vreference select VREFP).
  * @param  __HANDLE__ specifies the DAC handle.
  * @retval None
  */
#define __HAL_DAC_SET_VREFP_TRIMMING(__HANDLE__, __TRIM__) \
  MODIFY_REG((__HANDLE__)->Instance->CALR, DAC_CALR_DAC_OS_TRIMCR_VCC, (__TRIM__))

/** @brief Set the DAC trimming value (Vreference select VREFBUF).
  * @param  __HANDLE__ specifies the DAC handle.
  * @retval None
  */
#define __HAL_DAC_SET_VREFBUF_TRIMMING(__HANDLE__, __TRIM__) \
  MODIFY_REG((__HANDLE__)->Instance->CALR, DAC_CALR_DAC_OS_TRIMCR_VREFBUF, ((__TRIM__) << DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos))

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup DACEx_Private_Macros DACEx Private Macros
  * @{
  */

#define IS_DAC_TRIGGER(TRIGGER) (((TRIGGER) == DAC_TRIGGER_NONE)    || \
                                 ((TRIGGER) == DAC_TRIGGER_T6_TRGO) || \
                                 ((TRIGGER) == DAC_TRIGGER_T3_TRGO) || \
                                 ((TRIGGER) == DAC_TRIGGER_T7_TRGO) || \
                                 ((TRIGGER) == DAC_TRIGGER_T15_TRGO)|| \
                                 ((TRIGGER) == DAC_TRIGGER_T2_TRGO) || \
                                 ((TRIGGER) == DAC_TRIGGER_EXT_IT9) || \
                                 ((TRIGGER) == DAC_TRIGGER_SOFTWARE))


#define IS_DAC_LFSR_UNMASK_TRIANGLE_AMPLITUDE(VALUE) (((VALUE) == DAC_LFSRUNMASK_BIT0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS1_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS2_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS3_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS4_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS5_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS6_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS7_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS8_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS9_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS10_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS11_0) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_1) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_3) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_7) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_15) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_31) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_63) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_127) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_255) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_511) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_1023) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_2047) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_4095))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* Extended features functions ***********************************************/

/** @addtogroup DACEx_Exported_Functions
  * @{
  */

/** @addtogroup DACEx_Exported_Functions_Group1
  * @{
  */
/* IO operation functions *****************************************************/

HAL_StatusTypeDef HAL_DACEx_TriangleWaveGenerate(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t Amplitude);
HAL_StatusTypeDef HAL_DACEx_NoiseWaveGenerate(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t Amplitude);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* DAC */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32C882_HAL_DAC_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
