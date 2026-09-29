/**
  ******************************************************************************
  * @file    py32c882_ll_opa.h
  * @author  MCU Application Team
  * @brief   Header file of OPA LL module.
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
#ifndef __PY32C882_LL_OPA_H
#define __PY32C882_LL_OPA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c8xx.h"

/** @addtogroup PY32C882_LL_Driver
  * @{
  */

#if defined (OPA) 

/** @defgroup OPA_LL OPA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup OPA_LL_Private_Constants OPA Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup OPA_LL_Private_Macros OPA Private Macros
  * @{
  */
  
/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)


#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup OPA_LL_Exported_Constants OPA Exported Constants
  * @{
  */
/** @defgroup OPA_LL_EC_INPUT_NONINVERTING OPA input non-inverting
  * @{
  */
#define LL_OPA_INPUT_NONINVERT_IO0   (0x00000000UL)        /*!< OPA non inverting input connected to PD3 */
#define LL_OPA_INPUT_NONINVERT_IO1   OPA_CR_OPA_VINPSEL    /*!< OPA non inverting input connected to PC2 */
/**
  * @}
  */

/** @defgroup OPA_LL_EC_INPUT_INVERTING OPA input inverting
  * @{
  */
#define LL_OPA_INPUT_INVERT_IO0      (0x00000000UL)           /*!< OPA inverting input connected to PD2 */
#define LL_OPA_INPUT_INVERT_IO1      OPA_CR_OPA_VINMSEL       /*!< OPA inverting input connected to PC1 */
/**
  * @}
  */
  
/** @defgroup OPA_LL_EC_EXTERNAL_OUPUT_MODE OPA external output mode
  * @{
  */
#define LL_OPA_EXTERNAL_OUPUT_IO0      0x00000000UL            /*!< OPA external output to PD4 */
#define LL_OPA_EXTERNAL_OUPUT_IO1      OPA_OCR_OPA_EXTOSEL_0   /*!< OPA external output to PD1 */
#define LL_OPA_EXTERNAL_OUPUT_IO2      OPA_OCR_OPA_EXTOSEL_1   /*!< OPA external output to PC8 */
#define LL_OPA_EXTERNAL_OUPUT_IO3      OPA_OCR_OPA_EXTOSEL     /*!< OPA external output to PC9 */
/**
  * @}
  */
  
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/
/** @defgroup OPA_LL_Exported_Functions OPA Exported Functions
  * @{
  */

/** @defgroup OPA_LL_EF_CONFIGURATION_OPA_INSTANCE Configuration of OPA hierarchical scope: OPA instance
  * @{
  */

/**
  * @brief  Enable the OPA.
  * @rmtoll CR      OPAEN            LL_OPA_Enable
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_Enable(OPA_TypeDef *OPAx)
{
  SET_BIT(OPAx->CR, OPA_CR_OPAEN);
}

/**
  * @brief  Disable the OPA.
  * @rmtoll CR      OPAEN            LL_OPA_Disable
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_Disable(OPA_TypeDef *OPAx)
{
  CLEAR_BIT(OPAx->CR, OPA_CR_OPAEN);
}

/**
  * @brief  Get the OPA Enable state.
  * @rmtoll CR      OPAEN            LL_OPA_IsEnabled
  * @param  OPAx OPA instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_OPA_IsEnabled(OPA_TypeDef *OPAx)
{
  return ((READ_BIT(OPAx->CR, OPA_CR_OPAEN) == (OPA_CR_OPAEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set OPA non-inverting input connection.
  * @rmtoll CR      VINPSEL          LL_OPA_SetInputNonInverting
  * @param  OPAx OPA instance
  * @param  InputNonInverting This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO0
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO1
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInputNonInverting(OPA_TypeDef *OPAx, uint32_t InputNonInverting)
{
  MODIFY_REG(OPAx->CR, OPA_CR_OPA_VINPSEL, InputNonInverting);
}

/**
  * @brief  Get OPA non-inverting input connection.
  * @rmtoll CR      VINPSEL          LL_OPA_GetInputNonInverting
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO0
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO1
  */
__STATIC_INLINE uint32_t LL_OPA_GetInputNonInverting(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->CR, OPA_CR_OPA_VINPSEL));
}

/**
  * @brief  Set OPA inverting input connection.
  * @rmtoll CR      VINMSEL          LL_OPA_SetInputInverting
  * @param  OPAx OPA instance
  * @param  InputInverting This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_INVERT_IO0
  *         @arg @ref LL_OPA_INPUT_INVERT_IO1
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInputInverting(OPA_TypeDef *OPAx, uint32_t InputInverting)
{
  MODIFY_REG(OPAx->CR, OPA_CR_OPA_VINMSEL, InputInverting);
}

/**
  * @brief  Get OPA inverting input connection.
  * @rmtoll CR      VINMSEL          LL_OPA_GetInputInverting
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_INVERT_IO0
  *         @arg @ref LL_OPA_INPUT_INVERT_IO1
  */
__STATIC_INLINE uint32_t LL_OPA_GetInputInverting(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->CR, OPA_CR_OPA_VINMSEL));
}

/**
  * @brief  Enable OPA output connected to GPIO and internal analog module.
  * @rmtoll OCR      EXTOEN     LL_OPA_EnableOutput
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_EnableOutput(OPA_TypeDef *OPAx)
{
  SET_BIT(OPAx->OCR, OPA_OCR_OPA_EXTOEN);
}

/**
  * @brief  Disable OPA output.
  * @rmtoll OCR      EXTOEN     LL_OPA_DisableOutput
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_DisableOutput(OPA_TypeDef *OPAx)
{
  CLEAR_BIT(OPAx->OCR, OPA_OCR_OPA_EXTOEN);
}

/**
  * @brief  Check if OPA output is enabled
  * @rmtoll OCR      EXTOEN     LL_OPA_IsEnabledOutput
  * @param  OPAx OPA instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t LL_OPA_IsEnabledOutput(OPA_TypeDef *OPAx)
{
  return ((READ_BIT(OPAx->OCR, OPA_OCR_OPA_EXTOEN) == (OPA_OCR_OPA_EXTOEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set OPA external output.
  * @rmtoll OCR      EXTOSEL    LL_OPA_SetExternalOutput
  * @param  OPAx OPA instance
  * @param  ExternalOutput This parameter can be one of the following values:
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO0
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO1
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO2
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO3
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetExternalOutput(OPA_TypeDef *OPAx, uint32_t ExternalOutput)
{
  MODIFY_REG(OPAx->OCR, OPA_OCR_OPA_EXTOSEL, ExternalOutput);
}

/**
  * @brief  Get OPA external output state.
  * @rmtoll OCR      EXTOSEL    LL_OPA_GetExternalOutput
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO0
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO1
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO2
  *         @arg @ref LL_OPA_EXTERNAL_OUPUT_IO3
  */
__STATIC_INLINE uint32_t LL_OPA_GetExternalOutput(OPA_TypeDef *OPAx)
{
  return READ_BIT(OPAx->OCR, OPA_OCR_OPA_EXTOSEL);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup OPA_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

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

#endif /* OPA */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32C882_LL_OPA_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
