/**
  ******************************************************************************
  * @file    py32c882_hal_opa.h
  * @author  MCU Application Team
  * @brief   Header file of OPA HAL module.
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
#ifndef __PY32C882_HAL_OPA_H
#define __PY32C882_HAL_OPA_H

#ifdef __cplusplus
 extern "C" {
#endif
                  
/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup OPA
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/ 

/** @defgroup OPA_Exported_Types OPA Exported Types
  * @{
  */
/** 
  * @brief  OPA Init structure definition  
  */
typedef struct
{
  uint32_t InputPlus;          /*!< Set OPA input plus (non-inverting input).
                                    This parameter can be a value of @ref OPA_InputPlus */

  uint32_t InputMinus;         /*!< Set OPA input minus (inverting input).
                                    This parameter can be a value of @ref OPA_InputMinus */

  uint32_t OutputSel;          /*!< Set the output selection of the OPA.
                                    This parameter can be a value of @ref OPA_Output_Selection */                                  
}OPA_InitTypeDef;


/** 
  * @brief  HAL State structures definition  
  */ 
typedef enum
{
  HAL_OPA_STATE_RESET               = 0x00000000U, /*!< OPA is not yet Initialized          */
  
  HAL_OPA_STATE_READY               = 0x00000001U, /*!< OPA is initialized and ready for use */

  HAL_OPA_STATE_BUSY                = 0x00000002U, /*!< OPA is enabled and running in normal mode */    
    
  HAL_OPA_STATE_BUSYLOCKED          = 0x00000004U  /*!< OPA is locked
                                                        only system reset allows reconfiguring the OPA. */                                                                        
}HAL_OPA_StateTypeDef;

/** 
  * @brief OPA Handle Structure definition
  */ 
#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
typedef struct __OPA_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */
{
  OPA_TypeDef                 *Instance;                    /*!< OPA instance's registers base address   */
  OPA_InitTypeDef              Init;                        /*!< OPA required parameters */
  HAL_LockTypeDef              Lock;                        /*!< Locking object          */
  __IO HAL_OPA_StateTypeDef    State;                       /*!< OPA communication state */
  
#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
void (* MspInitCallback)                (struct __OPA_HandleTypeDef *hopa);
void (* MspDeInitCallback)              (struct __OPA_HandleTypeDef *hopa); 
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */ 
} OPA_HandleTypeDef;

/**
  * @}
  */

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL OPA Callback ID enumeration definition
  */
typedef enum
{
  HAL_OPA_MSP_INIT_CB_ID                     = 0x01U,  /*!< OPA MspInit Callback ID           */
  HAL_OPA_MSP_DEINIT_CB_ID                   = 0x02U,  /*!< OPA MspDeInit Callback ID         */
  HAL_OPA_ALL_CB_ID                          = 0x03U   /*!< OPA All ID                        */
}HAL_OPA_CallbackIDTypeDef;                            

/**
  * @brief  HAL OPA Callback pointer definition
  */
typedef void (*pOPA_CallbackTypeDef)(OPA_HandleTypeDef *hopa);
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */

    
    
/* Exported constants --------------------------------------------------------*/
/** @defgroup OPA_Exported_Constants OPA Exported Constants
  * @{
  */  

/** @defgroup OPA_InputPlus OPA Input Plus
  * @{
  */ 
#define OPA_INPUT_PLUS_IO0     (0x00000000UL)                          /*!< OPA input plus connected to IO0(pin PD3) */
#define OPA_INPUT_PLUS_IO1     (OPA_CR_OPA_VINPSEL)                    /*!< OPA input plus connected to IO1(pin PC2) */

/**
  * @}
  */

/** @defgroup OPA_InputMinus OPA Input Minus
  * @{
  */ 
#define OPA_INPUT_MINUS_IO0    (0x00000000UL)                          /*!< OPA input minus connected to IO0(pin PD2) */
#define OPA_INPUT_MINUS_IO1    (OPA_CR_OPA_VINMSEL)                    /*!< OPA input minus connected to IO1(pin PC1) */

/**
  * @}
  */

/** @defgroup OPA_Output_Selection OPA Output Selection
  * @{
  */ 
#define OPA_OUTPUT_SEL_IO0     (OPA_OCR_OPA_EXTOEN)                                                     /*!< OPA output connected to IO1(pin PD4) and internal analog module */
#define OPA_OUTPUT_SEL_IO1     (OPA_OCR_OPA_EXTOEN | OPA_OCR_OPA_EXTOSEL_0)                             /*!< OPA output connected to IO1(pin PD1) and internal analog module */
#define OPA_OUTPUT_SEL_IO2     (OPA_OCR_OPA_EXTOEN | OPA_OCR_OPA_EXTOSEL_1)                             /*!< OPA output connected to IO1(pin PC8) and internal analog module */
#define OPA_OUTPUT_SEL_IO3     (OPA_OCR_OPA_EXTOEN | OPA_OCR_OPA_EXTOSEL_0 | OPA_OCR_OPA_EXTOSEL_1)     /*!< OPA output connected to IO1(pin PC9) and internal analog module */

/**
  * @}
  */

/**
  * @}
  */ 

/* Private constants ---------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/** @defgroup OPA_Exported_Macros OPA Exported Macros
  * @{
  */

/** @brief Reset OPA handle state.
  * @param  __HANDLE__: OPA handle.
  * @retval None
  */
#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
#define __HAL_OPA_RESET_HANDLE_STATE(__HANDLE__) do{                                                  \
                                                      (__HANDLE__)->State = HAL_OPA_STATE_RESET;      \
                                                      (__HANDLE__)->MspInitCallback = NULL;           \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;         \
                                                    } while(0)
#else
#define __HAL_OPA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_OPA_STATE_RESET)
#endif
/**
  * @}
  */ 

/* Private macros ------------------------------------------------------------*/
/** @defgroup OPA_Private_Macros OPA Private Macros
  * @{
  */

/** @defgroup OPA_IS_OPA_INPUT OPA private macros to check input parameters
  * @{
  */

#define IS_OPA_INPUT_PLUS(__INPUT_PLUS__)                     (((__INPUT_PLUS__) == OPA_INPUT_PLUS_IO0)  || \
                                                               ((__INPUT_PLUS__) == OPA_INPUT_PLUS_IO1))


#define IS_OPA_INPUT_MINUS(__INPUT_MINUS__)                   (((__INPUT_MINUS__) == OPA_INPUT_MINUS_IO0)  || \
                                                               ((__INPUT_MINUS__) == OPA_INPUT_MINUS_IO1))

/**
  * @}
  */

/** @defgroup OPA_IS_OPA_OUPUT OPA private macros to check output parameters
  * @{
  */
#define IS_OPA_OUTPUT(__OUTPUT__)                             (((__OUTPUT__) == OPA_OUTPUT_SEL_ANALOG)  || \
                                                               ((__OUTPUT__) == OPA_OUTPUT_SEL_IO0)  || \
                                                               ((__OUTPUT__) == OPA_OUTPUT_SEL_IO1)  || \
                                                               ((__OUTPUT__) == OPA_OUTPUT_SEL_IO2)  || \
                                                               ((__OUTPUT__) == OPA_OUTPUT_SEL_IO3))
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup OPA_Exported_Functions
  * @{
  */

/** @addtogroup OPA_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  **********************************/
HAL_StatusTypeDef HAL_OPA_Init(OPA_HandleTypeDef *hopa);
HAL_StatusTypeDef HAL_OPA_DeInit (OPA_HandleTypeDef *hopa);
void              HAL_OPA_MspInit(OPA_HandleTypeDef *hopa);
void              HAL_OPA_MspDeInit(OPA_HandleTypeDef *hopa);

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_OPA_RegisterCallback (OPA_HandleTypeDef *hopa, HAL_OPA_CallbackIDTypeDef CallbackId, pOPA_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_OPA_UnRegisterCallback (OPA_HandleTypeDef *hopa, HAL_OPA_CallbackIDTypeDef CallbackId);
#endif
/**
  * @}
  */

/* I/O operation functions  *****************************************************/
/** @addtogroup OPA_Exported_Functions_Group2
  * @{
  */

HAL_StatusTypeDef HAL_OPA_Start(OPA_HandleTypeDef *hopa);
HAL_StatusTypeDef HAL_OPA_Stop(OPA_HandleTypeDef *hopa);
HAL_StatusTypeDef HAL_OPA_Lock(OPA_HandleTypeDef *hopa);

/**
  * @}
  */

/* Peripheral State functions  **************************************************/
/** @addtogroup OPA_Exported_Functions_Group3
  * @{
  */

HAL_OPA_StateTypeDef HAL_OPA_GetState(OPA_HandleTypeDef *hopa);

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

#endif /* PY32C882_HAL_OPA_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
