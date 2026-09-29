/**
  ******************************************************************************
  * @file    py32c882_hal_pwm.c
  * @author  MCU Application Team
  * @brief   PWM HAL module driver.
  *
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

/* Includes ------------------------------------------------------------------*/
#include "py32c8xx_hal.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @defgroup PWM PWM
  * @brief PWM HAL module driver
  * @{
  */

#ifdef HAL_PWM_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup PWM_Private_Constants
  * @{
  */
#define TIMEOUT                                     1000UL /* Timeout is 1s */
/**
  * @}
  */
  
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static HAL_StatusTypeDef PWM_WaitForFlag(const PWM_TypeDef *PWMx, uint32_t flag);
/** @addtogroup PWM_Private_Functions
  * @{
  */
static HAL_StatusTypeDef PWM_OC1_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config);
static HAL_StatusTypeDef PWM_OC2_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config);
static HAL_StatusTypeDef PWM_OC3_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config);
static HAL_StatusTypeDef PWM_OC4_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config);
#if (defined(DMA) || defined(DMA1))
static void PWM_DMAPeriodElapsedCplt(DMA_HandleTypeDef *hdma);
static void PWM_DMAPeriodElapsedHalfCplt(DMA_HandleTypeDef *hdma);
#endif
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/

/** @defgroup PWM_Exported_Functions PWM Exported Functions
  * @{
  */

/** @defgroup PWM_Exported_Functions_Group1 PWM Time Base functions
  *  @brief    Time Base functions
  *
@verbatim
  ==============================================================================
              ##### Time Base functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the PWM base.
    (+) De-initialize the PWM base.
    (+) Start the Time Base.
    (+) Stop the Time Base.
    (+) Start the Time Base and enable interrupt.
    (+) Stop the Time Base and disable interrupt.
    (+) Start the Time Base and enable DMA transfer.
    (+) Stop the Time Base and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the PWM Time base Unit according to the specified
  *         parameters in the PWM_HandleTypeDef and initialize the associated handle.
  * @note   Switching from Center Aligned counter mode to Edge counter mode (or reverse)
  *         requires a timer reset to avoid unexpected direction
  *         due to DIR bit readonly in center aligned mode.
  *         Ex: call @ref HAL_PWM_Base_DeInit() before HAL_PWM_Base_Init()
  * @param  hpwm PWM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_Init(PWM_HandleTypeDef *hpwm)
{
  /* Check the PWM handle allocation */
  if (hpwm == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_COUNTER_MODE(hpwm->Init.CounterMode));
  assert_param(IS_PWM_CLOCKDIVISION_DIV(hpwm->Init.ClockDivision));
  assert_param(IS_PWM_PERIOD(hpwm->Init.Period));
  assert_param(IS_PWM_AUTORELOAD_PRELOAD(hpwm->Init.AutoReloadPreload));

  if (hpwm->State == HAL_PWM_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hpwm->Lock = HAL_UNLOCKED;

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
    /* Reset interrupt callbacks to legacy weak callbacks */
    PWM_ResetCallback(hpwm);

    if (hpwm->Base_MspInitCallback == NULL)
    {
      hpwm->Base_MspInitCallback = HAL_PWM_Base_MspInit;
    }
    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    hpwm->Base_MspInitCallback(hpwm);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    HAL_PWM_Base_MspInit(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
  }

  /* Set the PWM state */
  hpwm->State = HAL_PWM_STATE_BUSY;

  /* Set the Time Base configuration */
  if(PWM_Base_SetConfig(hpwm->Instance, &hpwm->Init) == HAL_TIMEOUT)
  {
    return HAL_TIMEOUT;
  }

  /* Initialize the PWM state*/
  hpwm->State = HAL_PWM_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  DeInitializes the PWM Base peripheral
  * @param  hpwm PWM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_DeInit(PWM_HandleTypeDef *hpwm)
{
  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));

  hpwm->State = HAL_PWM_STATE_BUSY;

  /* Disable the PWM Peripheral Clock */
  __HAL_PWM_DISABLE(hpwm);

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  if (hpwm->Base_MspDeInitCallback == NULL)
  {
    hpwm->Base_MspDeInitCallback = HAL_PWM_Base_MspDeInit;
  }
  /* DeInit the low level hardware */
  hpwm->Base_MspDeInitCallback(hpwm);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC */
  HAL_PWM_Base_MspDeInit(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

  /* Change PWM state */
  hpwm->State = HAL_PWM_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hpwm);

  return HAL_OK;
}

/**
  * @brief  Initializes the PWM Base MSP.
  * @param  hpwm PWM Base handle
  * @retval None
  */
__weak void HAL_PWM_Base_MspInit(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_Base_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes PWM Base MSP.
  * @param  hpwm PWM Base handle
  * @retval None
  */
__weak void HAL_PWM_Base_MspDeInit(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_Base_MspDeInit could be implemented in the user file
   */
}


/**
  * @brief  Starts the PWM Base generation.
  * @param  hpwm PWM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_Start(PWM_HandleTypeDef *hpwm)
{
  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));

  /* Set the PWM state */
  hpwm->State = HAL_PWM_STATE_BUSY;

  __HAL_PWM_ENABLE(hpwm);

  /* Change the PWM state*/
  hpwm->State = HAL_PWM_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM Base generation.
  * @param  hpwm PWM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_Stop(PWM_HandleTypeDef *hpwm)
{
  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));

  /* Set the PWM state */
  hpwm->State = HAL_PWM_STATE_BUSY;

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Change the PWM state*/
  hpwm->State = HAL_PWM_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Starts the PWM Base generation in interrupt mode.
  * @param  hpwm PWM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_Start_IT(PWM_HandleTypeDef *hpwm)
{
  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));

  /* Enable the PWM Update interrupt */
  __HAL_PWM_ENABLE_IT(hpwm, PWM_IT_UPDATE);

  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM Base generation in interrupt mode.
  * @param  hpwm PWM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_Stop_IT(PWM_HandleTypeDef *hpwm)
{
  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));
  /* Disable the PWM Update interrupt */
  __HAL_PWM_DISABLE_IT(hpwm, PWM_IT_UPDATE);

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

#if (defined(DMA) || defined(DMA1))
/**
  * @brief  Starts the PWM Base generation in DMA mode.
  * @param  hpwm PWM Base handle
  * @param  pData The source Buffer address.
  * @param  Length The length of data to be transferred from memory to peripheral.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_Start_DMA(PWM_HandleTypeDef *hpwm, uint32_t *pData, uint16_t Length)
{
  /* Check the parameters */
  assert_param(IS_PWM_DMA_INSTANCE(hpwm->Instance));

  if (hpwm->State == HAL_PWM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  else if (hpwm->State == HAL_PWM_STATE_READY)
  {
    if ((pData == NULL) && (Length > 0U))
    {
      return HAL_ERROR;
    }
    else
    {
      hpwm->State = HAL_PWM_STATE_BUSY;
    }
  }
  else
  {
    /* nothing to do */
  }

  /* Set the DMA Period elapsed callbacks */
  hpwm->hdma[PWM_DMA_ID_UPDATE]->XferCpltCallback = PWM_DMAPeriodElapsedCplt;
  hpwm->hdma[PWM_DMA_ID_UPDATE]->XferHalfBlockCpltCallback = PWM_DMAPeriodElapsedHalfCplt;

  /* Set the DMA error callback */
  hpwm->hdma[PWM_DMA_ID_UPDATE]->XferErrorCallback = PWM_DMAError ;

  /* Enable the DMA channel */
  if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_UPDATE], (uint32_t)pData, (uint32_t)&hpwm->Instance->ARR, Length) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Enable the PWM Update DMA request */
  __HAL_PWM_ENABLE_DMA(hpwm, PWM_DMA_UPDATE);

  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM Base generation in DMA mode.
  * @param  hpwm PWM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_Base_Stop_DMA(PWM_HandleTypeDef *hpwm)
{
  /* Check the parameters */
  assert_param(IS_PWM_DMA_INSTANCE(hpwm->Instance));

  /* Disable the PWM Update DMA request */
  __HAL_PWM_DISABLE_DMA(hpwm, PWM_DMA_UPDATE);

  (void)HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_UPDATE]);

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Change the hpwm state */
  hpwm->State = HAL_PWM_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @}
  */
#endif


/** @defgroup PWM_Exported_Functions_Group2 PWM PWM functions
  *  @brief    PWM PWM functions
  *
@verbatim
  ==============================================================================
                          ##### PWM PWM functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the PWM PWM.
    (+) De-initialize the PWM PWM.
    (+) Start the PWM PWM.
    (+) Stop the PWM PWM.
    (+) Start the PWM PWM and enable interrupt.
    (+) Stop the PWM PWM and disable interrupt.
    (+) Start the PWM PWM and enable DMA transfer.
    (+) Stop the PWM PWM and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the PWM PWM Time Base according to the specified
  *         parameters in the PWM_HandleTypeDef and initializes the associated handle.
  * @note   Switching from Center Aligned counter mode to Edge counter mode (or reverse)
  *         requires a timer reset to avoid unexpected direction
  *         due to DIR bit readonly in center aligned mode.
  *         Ex: call @ref HAL_PWM_PWM_DeInit() before HAL_PWM_PWM_Init()
  * @param  hpwm PWM PWM handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_Init(PWM_HandleTypeDef *hpwm)
{
  /* Check the PWM handle allocation */
  if (hpwm == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_COUNTER_MODE(hpwm->Init.CounterMode));
  assert_param(IS_PWM_CLOCKDIVISION_DIV(hpwm->Init.ClockDivision));
  assert_param(IS_PWM_PERIOD(hpwm->Init.Period));
  assert_param(IS_PWM_AUTORELOAD_PRELOAD(hpwm->Init.AutoReloadPreload));

  if (hpwm->State == HAL_PWM_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hpwm->Lock = HAL_UNLOCKED;

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
    /* Reset interrupt callbacks to legacy weak callbacks */
    PWM_ResetCallback(hpwm);

    if (hpwm->PWM_MspInitCallback == NULL)
    {
      hpwm->PWM_MspInitCallback = HAL_PWM_PWM_MspInit;
    }
    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    hpwm->PWM_MspInitCallback(hpwm);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
    HAL_PWM_PWM_MspInit(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
  }

  /* Set the PWM state */
  hpwm->State = HAL_PWM_STATE_BUSY;

  /* Init the base time for the PWM */
  if(PWM_Base_SetConfig(hpwm->Instance, &hpwm->Init) == HAL_TIMEOUT)
  {
    return HAL_TIMEOUT;
  }

  /* Initialize the PWM state*/
  hpwm->State = HAL_PWM_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  DeInitializes the PWM peripheral
  * @param  hpwm PWM PWM handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_DeInit(PWM_HandleTypeDef *hpwm)
{
  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));

  hpwm->State = HAL_PWM_STATE_BUSY;

  /* Disable the PWM Peripheral Clock */
  __HAL_PWM_DISABLE(hpwm);

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  if (hpwm->PWM_MspDeInitCallback == NULL)
  {
    hpwm->PWM_MspDeInitCallback = HAL_PWM_PWM_MspDeInit;
  }
  /* DeInit the low level hardware */
  hpwm->PWM_MspDeInitCallback(hpwm);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC and DMA */
  HAL_PWM_PWM_MspDeInit(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

  /* Change PWM state */
  hpwm->State = HAL_PWM_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hpwm);

  return HAL_OK;
}

/**
  * @brief  Initializes the PWM PWM MSP.
  * @param  hpwm PWM PWM handle
  * @retval None
  */
__weak void HAL_PWM_PWM_MspInit(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_PWM_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes PWM PWM MSP.
  * @param  hpwm PWM PWM handle
  * @retval None
  */
__weak void HAL_PWM_PWM_MspDeInit(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_PWM_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief  Starts the PWM signal generation.
  * @param  hpwm PWM handle
  * @param  Channel PWM Channels to be enabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_Start(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCX_INSTANCE(hpwm->Instance, Channel));

  /* Enable the compare channel */
  PWM_OCxChannelCmd(hpwm->Instance, Channel, PWM_OCx_ENABLE);

  if (IS_PWM_BREAK_INSTANCE(hpwm->Instance) != RESET)
  {
    /* Enable the main output */
    __HAL_PWM_MOE_ENABLE(hpwm);
  }


  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM signal generation.
  * @param  hpwm PWM PWM handle
  * @param  Channel PWM Channels to be disabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_Stop(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCX_INSTANCE(hpwm->Instance, Channel));

  /* Disable the compare channel */
  PWM_OCxChannelCmd(hpwm->Instance, Channel, PWM_OCx_DISABLE);

  if (IS_PWM_BREAK_INSTANCE(hpwm->Instance) != RESET)
  {
    /* Disable the Main Output */
    __HAL_PWM_MOE_DISABLE(hpwm);
  }

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Change the hpwm state */
  hpwm->State = HAL_PWM_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Starts the PWM signal generation in interrupt mode.
  * @param  hpwm PWM PWM handle
  * @param  Channel PWM Channel to be enabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_Start_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCX_INSTANCE(hpwm->Instance, Channel));

  switch (Channel)
  {
  case PWM_CHANNEL_1:
  {
    /* Enable the PWM Compare 1 interrupt */
    __HAL_PWM_ENABLE_IT(hpwm, PWM_IT_OC1);
    break;
  }

  case PWM_CHANNEL_2:
  {
    /* Enable the PWM Compare 2 interrupt */
    __HAL_PWM_ENABLE_IT(hpwm, PWM_IT_OC2);
    break;
  }

  case PWM_CHANNEL_3:
  {
    /* Enable the PWM Compare 3 interrupt */
    __HAL_PWM_ENABLE_IT(hpwm, PWM_IT_OC3);
    break;
  }

  case PWM_CHANNEL_4:
  {
    /* Enable the PWM Compare 4 interrupt */
    __HAL_PWM_ENABLE_IT(hpwm, PWM_IT_OC4);
    break;
  }

  default:
    break;
  }

  /* Enable the  compare channel */
  PWM_OCxChannelCmd(hpwm->Instance, Channel, PWM_OCx_ENABLE);

  if (IS_PWM_BREAK_INSTANCE(hpwm->Instance) != RESET)
  {
    /* Enable the main output */
    __HAL_PWM_MOE_ENABLE(hpwm);
  }

  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM signal generation in interrupt mode.
  * @param  hpwm PWM PWM handle
  * @param  Channel PWM Channels to be disabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_Stop_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCX_INSTANCE(hpwm->Instance, Channel));

  switch (Channel)
  {
  case PWM_CHANNEL_1:
  {
    /* Disable the PWM Compare 1 interrupt */
    __HAL_PWM_DISABLE_IT(hpwm, PWM_IT_OC1);
    break;
  }

  case PWM_CHANNEL_2:
  {
    /* Disable the PWM Compare 2 interrupt */
    __HAL_PWM_DISABLE_IT(hpwm, PWM_IT_OC2);
    break;
  }

  case PWM_CHANNEL_3:
  {
    /* Disable the PWM Compare 3 interrupt */
    __HAL_PWM_DISABLE_IT(hpwm, PWM_IT_OC3);
    break;
  }

  case PWM_CHANNEL_4:
  {
    /* Disable the PWM Compare 4 interrupt */
    __HAL_PWM_DISABLE_IT(hpwm, PWM_IT_OC4);
    break;
  }

  default:
    break;
  }

  /* Disable the compare channel */
  PWM_OCxChannelCmd(hpwm->Instance, Channel, PWM_OCx_DISABLE);

  if (IS_PWM_BREAK_INSTANCE(hpwm->Instance) != RESET)
  {
    /* Disable the Main Output */
    __HAL_PWM_MOE_DISABLE(hpwm);
  }

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

#if (defined(DMA) || defined(DMA1))
/**
  * @brief  Starts the PWM PWM signal generation in DMA mode.
  * @param  hpwm PWM PWM handle
  * @param  Channel PWM Channels to be enabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @param  pData The source Buffer address.
  * @param  Length The length of data to be transferred from memory to PWM peripheral
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_Start_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel, uint32_t *pData, uint16_t Length)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCX_INSTANCE(hpwm->Instance, Channel));

  if (hpwm->State == HAL_PWM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  else if (hpwm->State == HAL_PWM_STATE_READY)
  {
    if ((pData == NULL) && (Length > 0U))
    {
      return HAL_ERROR;
    }
    else
    {
      hpwm->State = HAL_PWM_STATE_BUSY;
    }
  }
  else
  {
    /* nothing to do */
  }

  switch (Channel)
  {
  case PWM_CHANNEL_1:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC1]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC1]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC1]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC1], (uint32_t)pData, (uint32_t)&hpwm->Instance->CCR1, Length) != HAL_OK)
    {
      return HAL_ERROR;
    }

    /* Enable the PWM Compare 1 DMA request */
    __HAL_PWM_ENABLE_DMA(hpwm, PWM_DMA_OC1);

    break;
  }

  case PWM_CHANNEL_2:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC2]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC2]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC2]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC2], (uint32_t)pData, (uint32_t)&hpwm->Instance->CCR2, Length) != HAL_OK)
    {
      return HAL_ERROR;
    }
    /* Enable the PWM Compare 2 DMA request */
    __HAL_PWM_ENABLE_DMA(hpwm, PWM_DMA_OC2);
    break;
  }

  case PWM_CHANNEL_3:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC3]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC3]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC3]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC3], (uint32_t)pData, (uint32_t)&hpwm->Instance->CCR3, Length) != HAL_OK)
    {
      return HAL_ERROR;
    }
    /* Enable the PWM Output Compare 3 request */
    __HAL_PWM_ENABLE_DMA(hpwm, PWM_DMA_OC3);
    break;
  }

  case PWM_CHANNEL_4:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC4]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC4]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC4]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC4], (uint32_t)pData, (uint32_t)&hpwm->Instance->CCR4, Length) != HAL_OK)
    {
      return HAL_ERROR;
    }
    /* Enable the PWM Compare 4 DMA request */
    __HAL_PWM_ENABLE_DMA(hpwm, PWM_DMA_OC4);
    break;
  }

  default:
    break;
  }

  /* Enable the  compare channel */
  PWM_OCxChannelCmd(hpwm->Instance, Channel, PWM_OCx_ENABLE);

  if (IS_PWM_BREAK_INSTANCE(hpwm->Instance) != RESET)
  {
    /* Enable the main output */
    __HAL_PWM_MOE_ENABLE(hpwm);
  }

  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM PWM signal generation in DMA mode.
  * @param  hpwm PWM PWM handle
  * @param  Channel PWM Channels to be disabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_Stop_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCX_INSTANCE(hpwm->Instance, Channel));

  switch (Channel)
  {
  case PWM_CHANNEL_1:
  {
    /* Disable the PWM Compare 1 DMA request */
    __HAL_PWM_DISABLE_DMA(hpwm, PWM_DMA_OC1);
    (void)HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC1]);
    break;
  }

  case PWM_CHANNEL_2:
  {
    /* Disable the PWM Compare 2 DMA request */
    __HAL_PWM_DISABLE_DMA(hpwm, PWM_DMA_OC2);
    (void)HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC2]);
    break;
  }

  case PWM_CHANNEL_3:
  {
    /* Disable the PWM Compare 3 DMA request */
    __HAL_PWM_DISABLE_DMA(hpwm, PWM_DMA_OC3);
    (void)HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC3]);
    break;
  }

  case PWM_CHANNEL_4:
  {
    /* Disable the PWM Compare 4 interrupt */
    __HAL_PWM_DISABLE_DMA(hpwm, PWM_DMA_OC4);
    (void)HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC4]);
    break;
  }

  default:
    break;
  }

  /* Disable the compare channel */
  PWM_OCxChannelCmd(hpwm->Instance, Channel, PWM_OCx_DISABLE);

  if (IS_PWM_BREAK_INSTANCE(hpwm->Instance) != RESET)
  {
    /* Disable the Main Output */
    __HAL_PWM_MOE_DISABLE(hpwm);
  }

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Change the hpwm state */
  hpwm->State = HAL_PWM_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

#endif
/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Group3 PWM IRQ handler management
  *  @brief    PWM IRQ handler management
  *
@verbatim
  ==============================================================================
                        ##### IRQ handler management #####
  ==============================================================================
  [..]
    This section provides Timer IRQ handler function.

@endverbatim
  * @{
  */
/**
  * @brief  This function handles PWM interrupts requests.
  * @param  hpwm PWM  handle
  * @retval None
  */
void HAL_PWM_IRQHandler(PWM_HandleTypeDef *hpwm)
{
  /*  compare 1 event */
  if (__HAL_PWM_GET_FLAG(hpwm, PWM_FLAG_OC1) != RESET)
  {
    if (__HAL_PWM_GET_IT_SOURCE(hpwm, PWM_IT_OC1) != RESET)
    {
      {
        __HAL_PWM_CLEAR_IT(hpwm, PWM_IT_OC1);
        hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_1;

        /* Output compare event */
#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
          hpwm->PWM_PulseFinishedCallback(hpwm);
#else
          HAL_PWM_PWM_PulseFinishedCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

        hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_CLEARED;
      }
    }
  }
  /*  compare 2 event */
  if (__HAL_PWM_GET_FLAG(hpwm, PWM_FLAG_OC2) != RESET)
  {
    if (__HAL_PWM_GET_IT_SOURCE(hpwm, PWM_IT_OC2) != RESET)
    {
      __HAL_PWM_CLEAR_IT(hpwm, PWM_IT_OC2);
      hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_2;
      
      /* Output compare event */
#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
        hpwm->PWM_PulseFinishedCallback(hpwm);
#else
        HAL_PWM_PWM_PulseFinishedCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

      hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_CLEARED;
    }
  }
  /*  compare 3 event */
  if (__HAL_PWM_GET_FLAG(hpwm, PWM_FLAG_OC3) != RESET)
  {
    if (__HAL_PWM_GET_IT_SOURCE(hpwm, PWM_IT_OC3) != RESET)
    {
      __HAL_PWM_CLEAR_IT(hpwm, PWM_IT_OC3);
      hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_3;

      /* Output compare event */

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
        hpwm->PWM_PulseFinishedCallback(hpwm);
#else
        HAL_PWM_PWM_PulseFinishedCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

      hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_CLEARED;
    }
  }
  /*  compare 4 event */
  if (__HAL_PWM_GET_FLAG(hpwm, PWM_FLAG_OC4) != RESET)
  {
    if (__HAL_PWM_GET_IT_SOURCE(hpwm, PWM_IT_OC4) != RESET)
    {
      __HAL_PWM_CLEAR_IT(hpwm, PWM_IT_OC4);
      hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_4;

      /* Output compare event */

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
        hpwm->PWM_PulseFinishedCallback(hpwm);
#else
        HAL_PWM_PWM_PulseFinishedCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

      hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_CLEARED;
    }
  }
  /* PWM Update event */
  if (__HAL_PWM_GET_FLAG(hpwm, PWM_FLAG_UPDATE) != RESET)
  {
    if (__HAL_PWM_GET_IT_SOURCE(hpwm, PWM_IT_UPDATE) != RESET)
    {
      __HAL_PWM_CLEAR_IT(hpwm, PWM_IT_UPDATE);
#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
      hpwm->PeriodElapsedCallback(hpwm);
#else
      HAL_PWM_PeriodElapsedCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
    }
  }
  /* PWM Break input event */
  if (__HAL_PWM_GET_FLAG(hpwm, PWM_FLAG_BREAK) != RESET)
  {
    if (__HAL_PWM_GET_IT_SOURCE(hpwm, PWM_IT_BREAK) != RESET)
    {
      __HAL_PWM_CLEAR_FLAG(hpwm, PWM_FLAG_BREAK);
#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
      hpwm->BreakCallback(hpwm);
#else
      HAL_PWMEx_BreakCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
    }
  }
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Group4 PWM Peripheral Control functions
  *  @brief    PWM Peripheral Control functions
  *
@verbatim
  ==============================================================================
                   ##### Peripheral Control functions #####
  ==============================================================================
 [..]
   This section provides functions allowing to:
      (+) Configure The Output channels for PWM mode.
      (+) Configure External Clock source.
      (+) Configure Complementary channels, break features and dead time.
      (+) Configure the DMA Burst Mode.

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the PWM PWM  channels according to the specified
  *         parameters in the PWM_OC_InitTypeDef.
  * @param  hpwm PWM PWM handle
  * @param  sConfig PWM PWM configuration structure
  * @param  Channel PWM Channels to be configured
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  *            @arg PWM_CHANNEL_3: PWM Channel 3 selected
  *            @arg PWM_CHANNEL_4: PWM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_PWM_ConfigChannel(PWM_HandleTypeDef *hpwm,
    PWM_OC_InitTypeDef *sConfig,
    uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_CHANNELS(Channel));
  assert_param(IS_PWM_PWM_MODE(sConfig->OCMode));
  assert_param(IS_PWM_OC_POLARITY(sConfig->OCPolarity));

  /* Process Locked */
  __HAL_LOCK(hpwm);

  hpwm->State = HAL_PWM_STATE_BUSY;

  switch (Channel)
  {
  case PWM_CHANNEL_1:
  {
    /* Check the parameters */
    assert_param(IS_PWM_OC1_INSTANCE(hpwm->Instance));

    /* Configure the Channel 1 in PWM mode */
    if(PWM_OC1_SetConfig(hpwm->Instance, sConfig) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
    /* Set the Preload enable bit for channel1 */
    hpwm->Instance->CMR |= PWM_CMR_OC1PE;

    break;
  }

  case PWM_CHANNEL_2:
  {
    /* Check the parameters */
    assert_param(IS_PWM_OC2_INSTANCE(hpwm->Instance));

    /* Configure the Channel 2 in PWM mode */
    if(PWM_OC2_SetConfig(hpwm->Instance, sConfig) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
    
    /* Set the Preload enable bit for channel2 */
    hpwm->Instance->CMR |= PWM_CMR_OC2PE;
    
    break;
  }

  case PWM_CHANNEL_3:
  {
    /* Check the parameters */
    assert_param(IS_PWM_OC3_INSTANCE(hpwm->Instance));

    /* Configure the Channel 3 in PWM mode */
    if(PWM_OC3_SetConfig(hpwm->Instance, sConfig) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
    
    /* Set the Preload enable bit for channel3 */
    hpwm->Instance->CMR |= PWM_CMR_OC3PE;

    break;
  }

  case PWM_CHANNEL_4:
  {
    /* Check the parameters */
    assert_param(IS_PWM_OC4_INSTANCE(hpwm->Instance));

    /* Configure the Channel 4 in PWM mode */
    if(PWM_OC4_SetConfig(hpwm->Instance, sConfig) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
    
    /* Set the Preload enable bit for channel4 */
    hpwm->Instance->CMR |= PWM_CMR_OC4PE;

    break;
  }

  default:
    break;
  }

  hpwm->State = HAL_PWM_STATE_READY;

  __HAL_UNLOCK(hpwm);

  return HAL_OK;
}

#if (defined(DMA) || defined(DMA1))
/**
  * @brief  Configure the DMA Burst to transfer Data from the memory to the PWM peripheral
  * @param  hpwm PWM handle
  * @param  BurstBaseAddress PWM Base address from where the DMA  will start the Data write
  *         This parameter can be one of the following values:
  *            @arg PWM_DMABASE_CR1
  *            @arg PWM_DMABASE_CR2
  *            @arg PWM_DMABASE_SMCR
  *            @arg PWM_DMABASE_DIER
  *            @arg PWM_DMABASE_SR
  *            @arg PWM_DMABASE_EGR
  *            @arg PWM_DMABASE_CMR
  *            @arg PWM_DMABASE_CER
  *            @arg PWM_DMABASE_CNT
  *            @arg PWM_DMABASE_PSC
  *            @arg PWM_DMABASE_ARR
  *            @arg PWM_DMABASE_CCR1
  *            @arg PWM_DMABASE_CCR2
  *            @arg PWM_DMABASE_CCR3
  *            @arg PWM_DMABASE_CCR4
  *            @arg PWM_DMABASE_BDTR
  *            @arg PWM_DMABASE_DCR
  *            @arg PWM_DMABASE_DMAR
  * @param  BurstRequestSrc PWM DMA Request sources
  *         This parameter can be one of the following values:
  *            @arg PWM_DMA_UPDATE: PWM update Interrupt source
  *            @arg PWM_DMA_OC1: PWM Capture Compare 1 DMA source
  *            @arg PWM_DMA_OC2: PWM Capture Compare 2 DMA source
  *            @arg PWM_DMA_OC3: PWM Capture Compare 3 DMA source
  *            @arg PWM_DMA_OC4: PWM Capture Compare 4 DMA source
  * @param  BurstBuffer The Buffer address.
  * @param  BurstLength DMA Burst length. This parameter can be one value
  *         between: PWM_DMABURSTLENGTH_1TRANSFER and PWM_DMABURSTLENGTH_18TRANSFERS.
  * @note   This function should be used only when BurstLength is equal to DMA data transfer length.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_DMABurst_WriteStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t *BurstBuffer, uint32_t  BurstLength)
{
  return HAL_PWM_DMABurst_MultiWriteStart(hpwm, BurstBaseAddress, BurstRequestSrc, BurstBuffer, BurstLength,
                                          ((BurstLength) >> 8U) + 1U);
}

/**
  * @brief  Configure the DMA Burst to transfer multiple Data from the memory to the PWM peripheral
  * @param  hpwm PWM handle
  * @param  BurstBaseAddress PWM Base address from where the DMA will start the Data write
  *         This parameter can be one of the following values:
  *            @arg PWM_DMABASE_CR1
  *            @arg PWM_DMABASE_CR2
  *            @arg PWM_DMABASE_SMCR
  *            @arg PWM_DMABASE_DIER
  *            @arg PWM_DMABASE_SR
  *            @arg PWM_DMABASE_EGR
  *            @arg PWM_DMABASE_CMR
  *            @arg PWM_DMABASE_CER
  *            @arg PWM_DMABASE_CNT
  *            @arg PWM_DMABASE_PSC
  *            @arg PWM_DMABASE_ARR
  *            @arg PWM_DMABASE_CCR1
  *            @arg PWM_DMABASE_CCR2
  *            @arg PWM_DMABASE_CCR3
  *            @arg PWM_DMABASE_CCR4
  *            @arg PWM_DMABASE_BDTR
  *            @arg PWM_DMABASE_DCR
  *            @arg PWM_DMABASE_DMAR
  * @param  BurstRequestSrc PWM DMA Request sources
  *         This parameter can be one of the following values:
  *            @arg PWM_DMA_UPDATE: PWM update Interrupt source
  *            @arg PWM_DMA_OC1: PWM Capture Compare 1 DMA source
  *            @arg PWM_DMA_OC2: PWM Capture Compare 2 DMA source
  *            @arg PWM_DMA_OC3: PWM Capture Compare 3 DMA source
  *            @arg PWM_DMA_OC4: PWM Capture Compare 4 DMA source
  * @param  BurstBuffer The Buffer address.
  * @param  BurstLength DMA Burst length. This parameter can be one value
  *         between: PWM_DMABURSTLENGTH_1TRANSFER and PWM_DMABURSTLENGTH_18TRANSFERS.
  * @param  DataLength Data length. This parameter can be one value
  *         between 1 and 0xFFFF.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_DMABurst_MultiWriteStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t *BurstBuffer,
    uint32_t  BurstLength,  uint32_t  DataLength)
{
  /* Check the parameters */
  assert_param(IS_PWM_DMABURST_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_DMA_BASE(BurstBaseAddress));
  assert_param(IS_PWM_DMA_SOURCE(BurstRequestSrc));
  assert_param(IS_PWM_DMA_LENGTH(BurstLength));
  assert_param(IS_PWM_DMA_DATA_LENGTH(DataLength));

  if (hpwm->State == HAL_PWM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  else if (hpwm->State == HAL_PWM_STATE_READY)
  {
    if ((BurstBuffer == NULL) && (BurstLength > 0U))
    {
      return HAL_ERROR;
    }
    else
    {
      hpwm->State = HAL_PWM_STATE_BUSY;
    }
  }
  else
  {
    /* nothing to do */
  }
  switch (BurstRequestSrc)
  {
  case PWM_DMA_UPDATE:
  {
    /* Set the DMA Period elapsed callbacks */
    hpwm->hdma[PWM_DMA_ID_UPDATE]->XferCpltCallback = PWM_DMAPeriodElapsedCplt;
    hpwm->hdma[PWM_DMA_ID_UPDATE]->XferHalfBlockCpltCallback = PWM_DMAPeriodElapsedHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_UPDATE]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_UPDATE], (uint32_t)BurstBuffer,
                         (uint32_t)&hpwm->Instance->DMAR, DataLength) != HAL_OK)
    {
      return HAL_ERROR;
    }
    break;
  }
  case PWM_DMA_OC1:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC1]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC1]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC1]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC1], (uint32_t)BurstBuffer,
                         (uint32_t)&hpwm->Instance->DMAR, DataLength) != HAL_OK)
    {
      return HAL_ERROR;
    }
    break;
  }
  case PWM_DMA_OC2:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC2]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC2]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC2]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC2], (uint32_t)BurstBuffer,
                         (uint32_t)&hpwm->Instance->DMAR, DataLength) != HAL_OK)
    {
      return HAL_ERROR;
    }
    break;
  }
  case PWM_DMA_OC3:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC3]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC3]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC3]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC3], (uint32_t)BurstBuffer,
                         (uint32_t)&hpwm->Instance->DMAR, DataLength) != HAL_OK)
    {
      return HAL_ERROR;
    }
    break;
  }
  case PWM_DMA_OC4:
  {
    /* Set the DMA compare callbacks */
    hpwm->hdma[PWM_DMA_ID_OC4]->XferCpltCallback = PWM_DMADelayPulseCplt;
    hpwm->hdma[PWM_DMA_ID_OC4]->XferHalfBlockCpltCallback = PWM_DMADelayPulseHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_OC4]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_OC4], (uint32_t)BurstBuffer,
                         (uint32_t)&hpwm->Instance->DMAR, DataLength) != HAL_OK)
    {
      return HAL_ERROR;
    }
    break;
  }
  default:
    break;
  }

  /* Configure the DMA Burst Mode */
  hpwm->Instance->DCR = (BurstBaseAddress | BurstLength);
  /* Enable the PWM DMA Request */
  __HAL_PWM_ENABLE_DMA(hpwm, BurstRequestSrc);

  hpwm->State = HAL_PWM_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM DMA Burst mode
  * @param  hpwm PWM handle
  * @param  BurstRequestSrc PWM DMA Request sources to disable
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_DMABurst_WriteStop(PWM_HandleTypeDef *hpwm, uint32_t BurstRequestSrc)
{
  HAL_StatusTypeDef status = HAL_OK;
  /* Check the parameters */
  assert_param(IS_PWM_DMA_SOURCE(BurstRequestSrc));

  /* Abort the DMA transfer (at least disable the DMA channel) */
  switch (BurstRequestSrc)
  {
  case PWM_DMA_UPDATE:
  {
    status = HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_UPDATE]);
    break;
  }
  case PWM_DMA_OC1:
  {
    status = HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC1]);
    break;
  }
  case PWM_DMA_OC2:
  {
    status = HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC2]);
    break;
  }
  case PWM_DMA_OC3:
  {
    status = HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC3]);
    break;
  }
  case PWM_DMA_OC4:
  {
    status = HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_OC4]);
    break;
  }
  default:
    break;
  }

  if (HAL_OK == status)
  {
    /* Disable the PWM Update DMA request */
    __HAL_PWM_DISABLE_DMA(hpwm, BurstRequestSrc);
  }

  /* Return function status */
  return status;
}

/**
  * @brief  Configure the DMA Burst to transfer Data from the PWM peripheral to the memory
  * @param  hpwm PWM handle
  * @param  BurstBaseAddress PWM Base address from where the DMA  will start the Data read
  *         This parameter can be one of the following values:
  *            @arg PWM_DMABASE_CR1
  *            @arg PWM_DMABASE_CR2
  *            @arg PWM_DMABASE_SMCR
  *            @arg PWM_DMABASE_DIER
  *            @arg PWM_DMABASE_SR
  *            @arg PWM_DMABASE_EGR
  *            @arg PWM_DMABASE_CMR
  *            @arg PWM_DMABASE_CER
  *            @arg PWM_DMABASE_CNT
  *            @arg PWM_DMABASE_PSC
  *            @arg PWM_DMABASE_ARR
  *            @arg PWM_DMABASE_CCR1
  *            @arg PWM_DMABASE_CCR2
  *            @arg PWM_DMABASE_CCR3
  *            @arg PWM_DMABASE_CCR4
  *            @arg PWM_DMABASE_BDTR
  *            @arg PWM_DMABASE_DCR
  *            @arg PWM_DMABASE_DMAR
  * @param  BurstRequestSrc PWM DMA Request sources
  *         This parameter can be one of the following values:
  *            @arg PWM_DMA_UPDATE: PWM update Interrupt source
  * @param  BurstBuffer The Buffer address.
  * @param  BurstLength DMA Burst length. This parameter can be one value
  *         between: PWM_DMABURSTLENGTH_1TRANSFER and PWM_DMABURSTLENGTH_18TRANSFERS.
  * @note   This function should be used only when BurstLength is equal to DMA data transfer length.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_DMABurst_ReadStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength)
{
  return HAL_PWM_DMABurst_MultiReadStart(hpwm, BurstBaseAddress, BurstRequestSrc, BurstBuffer, BurstLength,
                                         ((BurstLength) >> 8U) + 1U);
}

/**
  * @brief  Configure the DMA Burst to transfer Data from the PWM peripheral to the memory
  * @param  hpwm PWM handle
  * @param  BurstBaseAddress PWM Base address from where the DMA  will start the Data read
  *         This parameter can be one of the following values:
  *            @arg PWM_DMABASE_CR1
  *            @arg PWM_DMABASE_CR2
  *            @arg PWM_DMABASE_SMCR
  *            @arg PWM_DMABASE_DIER
  *            @arg PWM_DMABASE_SR
  *            @arg PWM_DMABASE_EGR
  *            @arg PWM_DMABASE_CMR
  *            @arg PWM_DMABASE_CER
  *            @arg PWM_DMABASE_CNT
  *            @arg PWM_DMABASE_PSC
  *            @arg PWM_DMABASE_ARR
  *            @arg PWM_DMABASE_CCR1
  *            @arg PWM_DMABASE_CCR2
  *            @arg PWM_DMABASE_CCR3
  *            @arg PWM_DMABASE_CCR4
  *            @arg PWM_DMABASE_BDTR
  *            @arg PWM_DMABASE_DCR
  *            @arg PWM_DMABASE_DMAR
  * @param  BurstRequestSrc PWM DMA Request sources
  *         This parameter can be one of the following values:
  *            @arg PWM_DMA_UPDATE: PWM update Interrupt source
  * @param  BurstBuffer The Buffer address.
  * @param  BurstLength DMA Burst length. This parameter can be one value
  *         between: PWM_DMABURSTLENGTH_1TRANSFER and PWM_DMABURSTLENGTH_18TRANSFERS.
  * @param  DataLength Data length. This parameter can be one value
  *         between 1 and 0xFFFF.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_DMABurst_MultiReadStart(PWM_HandleTypeDef *hpwm, uint32_t BurstBaseAddress,
    uint32_t BurstRequestSrc, uint32_t  *BurstBuffer,
    uint32_t  BurstLength, uint32_t  DataLength)
{
  /* Check the parameters */
  assert_param(IS_PWM_DMABURST_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_DMA_BASE(BurstBaseAddress));
  assert_param(IS_PWM_DMA_SOURCE(BurstRequestSrc));
  assert_param(IS_PWM_DMA_LENGTH(BurstLength));
  assert_param(IS_PWM_DMA_DATA_LENGTH(DataLength));

  if (hpwm->State == HAL_PWM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  else if (hpwm->State == HAL_PWM_STATE_READY)
  {
    if ((BurstBuffer == NULL) && (BurstLength > 0U))
    {
      return HAL_ERROR;
    }
    else
    {
      hpwm->State = HAL_PWM_STATE_BUSY;
    }
  }
  else
  {
    /* nothing to do */
  }
  switch (BurstRequestSrc)
  {
  case PWM_DMA_UPDATE:
  {
    /* Set the DMA Period elapsed callbacks */
    hpwm->hdma[PWM_DMA_ID_UPDATE]->XferCpltCallback = PWM_DMAPeriodElapsedCplt;
    hpwm->hdma[PWM_DMA_ID_UPDATE]->XferHalfBlockCpltCallback = PWM_DMAPeriodElapsedHalfCplt;

    /* Set the DMA error callback */
    hpwm->hdma[PWM_DMA_ID_UPDATE]->XferErrorCallback = PWM_DMAError ;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hpwm->hdma[PWM_DMA_ID_UPDATE], (uint32_t)&hpwm->Instance->DMAR, (uint32_t)BurstBuffer,
                         DataLength) != HAL_OK)
    {
      return HAL_ERROR;
    }
    break;
  }
  default:
    break;
  }

  /* Configure the DMA Burst Mode */
  hpwm->Instance->DCR = (BurstBaseAddress | BurstLength);

  /* Enable the PWM DMA Request */
  __HAL_PWM_ENABLE_DMA(hpwm, BurstRequestSrc);

  hpwm->State = HAL_PWM_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stop the DMA burst reading
  * @param  hpwm PWM handle
  * @param  BurstRequestSrc PWM DMA Request sources to disable.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_DMABurst_ReadStop(PWM_HandleTypeDef *hpwm, uint32_t BurstRequestSrc)
{
  HAL_StatusTypeDef status = HAL_OK;
  /* Check the parameters */
  assert_param(IS_PWM_DMA_SOURCE(BurstRequestSrc));

  /* Abort the DMA transfer (at least disable the DMA channel) */
  switch (BurstRequestSrc)
  {
  case PWM_DMA_UPDATE:
  {
    status = HAL_DMA_Abort_IT(hpwm->hdma[PWM_DMA_ID_UPDATE]);
    break;
  }
  default:
    break;
  }

  if (HAL_OK == status)
  {
    /* Disable the PWM Update DMA request */
    __HAL_PWM_DISABLE_DMA(hpwm, BurstRequestSrc);
  }

  /* Return function status */
  return status;
}

#endif
/**
  * @brief  Generate a software event
  * @param  hpwm PWM handle
  * @param  EventSource specifies the event source.
  *          This parameter can be one of the following values:
  *            @arg PWM_EVENTSOURCE_UPDATE: Timer update Event source
  * @retval HAL status
  */

HAL_StatusTypeDef HAL_PWM_GenerateEvent(PWM_HandleTypeDef *hpwm, uint32_t EventSource)
{
  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_EVENT_SOURCE(EventSource));

  /* Process Locked */
  __HAL_LOCK(hpwm);

  /* Change the PWM state */
  hpwm->State = HAL_PWM_STATE_BUSY;

  /* Set the event sources */
  hpwm->Instance->EGR = EventSource;

  /* Change the PWM state */
  hpwm->State = HAL_PWM_STATE_READY;

  __HAL_UNLOCK(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Configures the clock source to be used
  * @param  hpwm PWM handle
  * @param  sClockSourceConfig pointer to a PWM_ClockConfigTypeDef structure that
  *         contains the clock source information for the PWM peripheral.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWM_ConfigClockSource(PWM_HandleTypeDef *hpwm, PWM_ClockConfigTypeDef *sClockSourceConfig)
{
  uint32_t tmpsmcr;

  /* Process Locked */
  __HAL_LOCK(hpwm);

  hpwm->State = HAL_PWM_STATE_BUSY;

  /* Check the parameters */
  assert_param(IS_PWM_CLOCKSOURCE(sClockSourceConfig->ClockSource));

  /* Reset the ECE, ETPS and ETRF bits */
  tmpsmcr = hpwm->Instance->SMCR;
  tmpsmcr &= ~(PWM_SMCR_ETF | PWM_SMCR_ETPS | PWM_SMCR_ECE | PWM_SMCR_ETP);
  hpwm->Instance->SMCR = tmpsmcr;

  switch (sClockSourceConfig->ClockSource)
  {
  case PWM_CLOCKSOURCE_INTERNAL:
  {
    assert_param(IS_PWM_INSTANCE(hpwm->Instance));
    break;
  }

  case PWM_CLOCKSOURCE_ETRMODE:
  {
    /* Check whether or not the timer instance supports external trigger input mode (ETRF)*/
    assert_param(IS_PWM_CLOCKSOURCE_ETRMODE_INSTANCE(hpwm->Instance));

    /* Check ETR input conditioning related parameters */
    assert_param(IS_PWM_CLOCKPRESCALER(sClockSourceConfig->ClockPrescaler));
    assert_param(IS_PWM_CLOCKPOLARITY(sClockSourceConfig->ClockPolarity));
    assert_param(IS_PWM_CLOCKFILTER(sClockSourceConfig->ClockFilter));

    /* Configure the ETR Clock source */
    PWM_ETR_SetConfig(hpwm->Instance,
                      sClockSourceConfig->ClockPrescaler,
                      sClockSourceConfig->ClockPolarity,
                      sClockSourceConfig->ClockFilter);

    /* Select the External clock mode and the ETRF trigger */
    tmpsmcr = hpwm->Instance->SMCR;
    tmpsmcr |= PWM_CLOCKSOURCE_ETRMODE;
    /* Write to PWMx SMCR */
    hpwm->Instance->SMCR = tmpsmcr;
    break;
  }

  default:
    break;
  }
  hpwm->State = HAL_PWM_STATE_READY;

  __HAL_UNLOCK(hpwm);

  return HAL_OK;
}



/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Group5 PWM Callbacks functions
  *  @brief    PWM Callbacks functions
  *
@verbatim
  ==============================================================================
                        ##### PWM Callbacks functions #####
  ==============================================================================
 [..]
   This section provides PWM callback functions:
   (+) PWM Period elapsed callback
   (+) PWM Output Compare callback
   (+) PWM Error callback

@endverbatim
  * @{
  */

/**
  * @brief  Period elapsed callback in non-blocking mode
  * @param  hpwm PWM handle
  * @retval None
  */
__weak void HAL_PWM_PeriodElapsedCallback(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_PeriodElapsedCallback could be implemented in the user file
   */
}

/**
  * @brief  Period elapsed half complete callback in non-blocking mode
  * @param  hpwm PWM handle
  * @retval None
  */
__weak void HAL_PWM_PeriodElapsedHalfCpltCallback(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_PeriodElapsedHalfCpltCallback could be implemented in the user file
   */
}


/**
  * @brief  PWM Pulse finished callback in non-blocking mode
  * @param  hpwm PWM handle
  * @retval None
  */
__weak void HAL_PWM_PWM_PulseFinishedCallback(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_PWM_PulseFinishedCallback could be implemented in the user file
   */
}

/**
  * @brief  PWM Pulse finished half complete callback in non-blocking mode
  * @param  hpwm PWM handle
  * @retval None
  */
__weak void HAL_PWM_PWM_PulseFinishedHalfCpltCallback(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_PWM_PulseFinishedHalfCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Timer error callback in non-blocking mode
  * @param  hpwm PWM handle
  * @retval None
  */
__weak void HAL_PWM_ErrorCallback(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWM_ErrorCallback could be implemented in the user file
   */
}

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User PWM callback to be used instead of the weak predefined callback
  * @param hpwm tim handle
  * @param CallbackID ID of the callback to be registered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_PWM_BASE_MSPINIT_CB_ID Base MspInit Callback ID
  *          @arg @ref HAL_PWM_BASE_MSPDEINIT_CB_ID Base MspDeInit Callback ID
  *          @arg @ref HAL_PWM_PWM_MSPINIT_CB_ID PWM MspInit Callback ID
  *          @arg @ref HAL_PWM_PWM_MSPDEINIT_CB_ID PWM MspDeInit Callback ID
  *          @arg @ref HAL_PWM_PERIOD_ELAPSED_CB_ID Period Elapsed Callback ID
  *          @arg @ref HAL_PWM_PERIOD_ELAPSED_HALF_CB_ID Period Elapsed half complete Callback ID
  *          @arg @ref HAL_PWM_PWM_PULSE_FINISHED_CB_ID PWM Pulse Finished Callback ID
  *          @arg @ref HAL_PWM_PWM_PULSE_FINISHED_HALF_CB_ID PWM Pulse Finished half complete Callback ID
  *          @arg @ref HAL_PWM_ERROR_CB_ID Error Callback ID
  *          @arg @ref HAL_PWM_BREAK_CB_ID Break Callback ID
  *          @param pCallback pointer to the callback function
  *          @retval status
  */
HAL_StatusTypeDef HAL_PWM_RegisterCallback(PWM_HandleTypeDef *hpwm, HAL_PWM_CallbackIDTypeDef CallbackID,
    pPWM_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hpwm);

  if (hpwm->State == HAL_PWM_STATE_READY)
  {
    switch (CallbackID)
    {
    case HAL_PWM_BASE_MSPINIT_CB_ID :
      hpwm->Base_MspInitCallback                 = pCallback;
      break;

    case HAL_PWM_BASE_MSPDEINIT_CB_ID :
      hpwm->Base_MspDeInitCallback               = pCallback;
      break;

    case HAL_PWM_PWM_MSPINIT_CB_ID :
      hpwm->PWM_MspInitCallback                  = pCallback;
      break;

    case HAL_PWM_PWM_MSPDEINIT_CB_ID :
      hpwm->PWM_MspDeInitCallback                = pCallback;
      break;

    case HAL_PWM_PERIOD_ELAPSED_CB_ID :
      hpwm->PeriodElapsedCallback                = pCallback;
      break;

    case HAL_PWM_PERIOD_ELAPSED_HALF_CB_ID :
      hpwm->PeriodElapsedHalfCpltCallback        = pCallback;
      break;

    case HAL_PWM_PWM_PULSE_FINISHED_CB_ID :
      hpwm->PWM_PulseFinishedCallback            = pCallback;
      break;

    case HAL_PWM_PWM_PULSE_FINISHED_HALF_CB_ID :
      hpwm->PWM_PulseFinishedHalfCpltCallback    = pCallback;
      break;

    case HAL_PWM_ERROR_CB_ID :
      hpwm->ErrorCallback                        = pCallback;
      break;

    case HAL_PWM_BREAK_CB_ID :
      hpwm->BreakCallback                        = pCallback;
      break;

    default :
      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (hpwm->State == HAL_PWM_STATE_RESET)
  {
    switch (CallbackID)
    {
    case HAL_PWM_BASE_MSPINIT_CB_ID :
      hpwm->Base_MspInitCallback         = pCallback;
      break;

    case HAL_PWM_BASE_MSPDEINIT_CB_ID :
      hpwm->Base_MspDeInitCallback       = pCallback;
      break;

    case HAL_PWM_PWM_MSPINIT_CB_ID :
      hpwm->PWM_MspInitCallback          = pCallback;
      break;

    case HAL_PWM_PWM_MSPDEINIT_CB_ID :
      hpwm->PWM_MspDeInitCallback        = pCallback;
      break;

    default :
      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hpwm);

  return status;
}

/**
  * @brief  Unregister a PWM callback
  *         PWM callback is redirected to the weak predefined callback
  * @param hpwm tim handle
  * @param CallbackID ID of the callback to be unregistered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_PWM_BASE_MSPINIT_CB_ID Base MspInit Callback ID
  *          @arg @ref HAL_PWM_BASE_MSPDEINIT_CB_ID Base MspDeInit Callback ID
  *          @arg @ref HAL_PWM_PWM_MSPINIT_CB_ID PWM MspInit Callback ID
  *          @arg @ref HAL_PWM_PWM_MSPDEINIT_CB_ID PWM MspDeInit Callback ID
  *          @arg @ref HAL_PWM_PERIOD_ELAPSED_CB_ID Period Elapsed Callback ID
  *          @arg @ref HAL_PWM_PERIOD_ELAPSED_HALF_CB_ID Period Elapsed half complete Callback ID
  *          @arg @ref HAL_PWM_PWM_PULSE_FINISHED_CB_ID PWM Pulse Finished Callback ID
  *          @arg @ref HAL_PWM_PWM_PULSE_FINISHED_HALF_CB_ID PWM Pulse Finished half complete Callback ID
  *          @arg @ref HAL_PWM_ERROR_CB_ID Error Callback ID
  *          @arg @ref HAL_PWM_BREAK_CB_ID Break Callback ID
  *          @retval status
  */
HAL_StatusTypeDef HAL_PWM_UnRegisterCallback(PWM_HandleTypeDef *hpwm, HAL_PWM_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hpwm);

  if (hpwm->State == HAL_PWM_STATE_READY)
  {
    switch (CallbackID)
    {
    case HAL_PWM_BASE_MSPINIT_CB_ID :
      hpwm->Base_MspInitCallback              = HAL_PWM_Base_MspInit;                      /* Legacy weak Base MspInit Callback */
      break;

    case HAL_PWM_BASE_MSPDEINIT_CB_ID :
      hpwm->Base_MspDeInitCallback            = HAL_PWM_Base_MspDeInit;                    /* Legacy weak Base Msp DeInit Callback */
      break;

    case HAL_PWM_PWM_MSPINIT_CB_ID :
      hpwm->PWM_MspInitCallback               = HAL_PWM_PWM_MspInit;                       /* Legacy weak PWM Msp Init Callback */
      break;

    case HAL_PWM_PWM_MSPDEINIT_CB_ID :
      hpwm->PWM_MspDeInitCallback             = HAL_PWM_PWM_MspDeInit;                     /* Legacy weak PWM Msp DeInit Callback */
      break;

    case HAL_PWM_PERIOD_ELAPSED_CB_ID :
      hpwm->PeriodElapsedCallback             = HAL_PWM_PeriodElapsedCallback;             /* Legacy weak Period Elapsed Callback */
      break;

    case HAL_PWM_PERIOD_ELAPSED_HALF_CB_ID :
      hpwm->PeriodElapsedHalfCpltCallback     = HAL_PWM_PeriodElapsedHalfCpltCallback;     /* Legacy weak Period Elapsed half complete Callback */
      break;

    case HAL_PWM_PWM_PULSE_FINISHED_CB_ID :
      hpwm->PWM_PulseFinishedCallback         = HAL_PWM_PWM_PulseFinishedCallback;         /* Legacy weak PWM Pulse Finished Callback */
      break;

    case HAL_PWM_PWM_PULSE_FINISHED_HALF_CB_ID :
      hpwm->PWM_PulseFinishedHalfCpltCallback = HAL_PWM_PWM_PulseFinishedHalfCpltCallback; /* Legacy weak PWM Pulse Finished half complete Callback */
      break;

    case HAL_PWM_ERROR_CB_ID :
      hpwm->ErrorCallback                     = HAL_PWM_ErrorCallback;                     /* Legacy weak Error Callback */
      break;

    case HAL_PWM_BREAK_CB_ID :
      hpwm->BreakCallback                     = HAL_PWMEx_BreakCallback;                   /* Legacy weak Break Callback */
      break;

    default :
      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (hpwm->State == HAL_PWM_STATE_RESET)
  {
    switch (CallbackID)
    {
    case HAL_PWM_BASE_MSPINIT_CB_ID :
      hpwm->Base_MspInitCallback         = HAL_PWM_Base_MspInit;              /* Legacy weak Base MspInit Callback */
      break;

    case HAL_PWM_BASE_MSPDEINIT_CB_ID :
      hpwm->Base_MspDeInitCallback       = HAL_PWM_Base_MspDeInit;            /* Legacy weak Base Msp DeInit Callback */
      break;

    case HAL_PWM_PWM_MSPINIT_CB_ID :
      hpwm->PWM_MspInitCallback          = HAL_PWM_PWM_MspInit;               /* Legacy weak PWM Msp Init Callback */
      break;

    case HAL_PWM_PWM_MSPDEINIT_CB_ID :
      hpwm->PWM_MspDeInitCallback        = HAL_PWM_PWM_MspDeInit;             /* Legacy weak PWM Msp DeInit Callback */
      break;

    default :
      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hpwm);

  return status;
}
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Group6 PWM Peripheral State functions
  *  @brief   PWM Peripheral State functions
  *
@verbatim
  ==============================================================================
                        ##### Peripheral State functions #####
  ==============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Return the PWM Base handle state.
  * @param  hpwm PWM Base handle
  * @retval HAL state
  */
HAL_PWM_StateTypeDef HAL_PWM_Base_GetState(PWM_HandleTypeDef *hpwm)
{
  return hpwm->State;
}

/**
  * @brief  Return the PWM PWM handle state.
  * @param  hpwm PWM handle
  * @retval HAL state
  */
HAL_PWM_StateTypeDef HAL_PWM_PWM_GetState(PWM_HandleTypeDef *hpwm)
{
  return hpwm->State;
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup PWM_Private_Functions PWM Private Functions
  * @{
  */

#if (defined(DMA) || defined(DMA1))
/**
  * @brief  PWM DMA error callback
  * @param  hdma pointer to DMA handle.
  * @retval None
  */
void PWM_DMAError(DMA_HandleTypeDef *hdma)
{
  PWM_HandleTypeDef *hpwm = (PWM_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  hpwm->State = HAL_PWM_STATE_READY;

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  hpwm->ErrorCallback(hpwm);
#else
  HAL_PWM_ErrorCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
}

/**
  * @brief  PWM DMA Delay Pulse complete callback.
  * @param  hdma pointer to DMA handle.
  * @retval None
  */
void PWM_DMADelayPulseCplt(DMA_HandleTypeDef *hdma)
{
  PWM_HandleTypeDef *hpwm = (PWM_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  hpwm->State = HAL_PWM_STATE_READY;

  if (hdma == hpwm->hdma[PWM_DMA_ID_OC1])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_1;
  }
  else if (hdma == hpwm->hdma[PWM_DMA_ID_OC2])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_2;
  }
  else if (hdma == hpwm->hdma[PWM_DMA_ID_OC3])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_3;
  }
  else if (hdma == hpwm->hdma[PWM_DMA_ID_OC4])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_4;
  }
  else
  {
    /* nothing to do */
  }

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  hpwm->PWM_PulseFinishedCallback(hpwm);
#else
  HAL_PWM_PWM_PulseFinishedCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

  hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_CLEARED;
}

/**
  * @brief  PWM DMA Delay Pulse half complete callback.
  * @param  hdma pointer to DMA handle.
  * @retval None
  */
void PWM_DMADelayPulseHalfCplt(DMA_HandleTypeDef *hdma)
{
  PWM_HandleTypeDef *hpwm = (PWM_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  hpwm->State = HAL_PWM_STATE_READY;

  if (hdma == hpwm->hdma[PWM_DMA_ID_OC1])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_1;
  }
  else if (hdma == hpwm->hdma[PWM_DMA_ID_OC2])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_2;
  }
  else if (hdma == hpwm->hdma[PWM_DMA_ID_OC3])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_3;
  }
  else if (hdma == hpwm->hdma[PWM_DMA_ID_OC4])
  {
    hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_4;
  }
  else
  {
    /* nothing to do */
  }

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  hpwm->PWM_PulseFinishedHalfCpltCallback(hpwm);
#else
  HAL_PWM_PWM_PulseFinishedHalfCpltCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

  hpwm->Channel = HAL_PWM_ACTIVE_CHANNEL_CLEARED;
}

/**
  * @brief  PWM DMA Period Elapse complete callback.
  * @param  hdma pointer to DMA handle.
  * @retval None
  */
static void PWM_DMAPeriodElapsedCplt(DMA_HandleTypeDef *hdma)
{
  PWM_HandleTypeDef *hpwm = (PWM_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  hpwm->State = HAL_PWM_STATE_READY;

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  hpwm->PeriodElapsedCallback(hpwm);
#else
  HAL_PWM_PeriodElapsedCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
}

/**
  * @brief  PWM DMA Period Elapse half complete callback.
  * @param  hdma pointer to DMA handle.
  * @retval None
  */
static void PWM_DMAPeriodElapsedHalfCplt(DMA_HandleTypeDef *hdma)
{
  PWM_HandleTypeDef *hpwm = (PWM_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  hpwm->State = HAL_PWM_STATE_READY;

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
  hpwm->PeriodElapsedHalfCpltCallback(hpwm);
#else
  HAL_PWM_PeriodElapsedHalfCpltCallback(hpwm);
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */
}

#endif
/**
  * @brief  Time Base configuration
  * @param  PWMx PWM peripheral
  * @param  Structure PWM Base configuration structure
  * @retval HAL status
  */
HAL_StatusTypeDef PWM_Base_SetConfig(PWM_TypeDef *PWMx, PWM_Base_InitTypeDef *Structure)
{
  uint32_t tmpcr1;
  tmpcr1 = PWMx->CR1;

  /* Set PWM Time Base Unit parameters ---------------------------------------*/
  if (IS_PWM_COUNTER_MODE_SELECT_INSTANCE(PWMx))
  {
    /* Select the Counter Mode */
    tmpcr1 &= ~(PWM_CR1_DIR | PWM_CR1_CMS);
    tmpcr1 |= Structure->CounterMode;
  }

  if (IS_PWM_CLOCK_DIVISION_INSTANCE(PWMx))
  {
    /* Set the clock division */
    tmpcr1 &= ~PWM_CR1_CKD;
    tmpcr1 |= (uint32_t)Structure->ClockDivision;
  }

  /* Set the auto-reload preload */
  MODIFY_REG(tmpcr1, PWM_CR1_ARPE, Structure->AutoReloadPreload);

  PWMx->CR1 = tmpcr1;

  /* Set the Autoreload value */
  PWMx->SR = ~(PWM_FLAG_ARROK);
  PWMx->ARR = (uint32_t)Structure->Period ;
  if(((PWMx->SMCR & PWM_SMCR_ECE) == PWM_SMCR_ECE)
    && (((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_SYS_CLK) || ((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_GPIO_HS)))
  {
    if(PWM_WaitForFlag(PWMx,PWM_FLAG_ARROK) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
  }
  
  /* Set the Prescaler value */
  PWMx->SR = ~(PWM_FLAG_PSCOK);
  PWMx->PSC = Structure->Prescaler;
  if(((PWMx->SMCR & PWM_SMCR_ECE) == PWM_SMCR_ECE)
    && (((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_SYS_CLK) || ((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_GPIO_HS)))
  {
    if(PWM_WaitForFlag(PWMx,PWM_FLAG_PSCOK) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
  }
  
  /* Generate an update event to reload the Prescaler
     and the repetition counter (only for advanced timer) value immediately */
  PWMx->EGR = PWM_EGR_UG;
  
  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Timer Output Compare 1 configuration
  * @param  PWMx to select the PWM peripheral
  * @param  OC_Config The ouput configuration structure
  * @retval None
  */
static HAL_StatusTypeDef PWM_OC1_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config)
{
  uint32_t tmpccmrx;
  uint32_t tmpccer;
  uint32_t tmpcr2;

  /* Disable the Channel 1: Reset the C1E Bit */
  PWMx->CER &= ~PWM_CER_C1E;

  /* Get the PWMx CER register value */
  tmpccer = PWMx->CER;
  /* Get the PWMx CR2 register value */
  tmpcr2 =  PWMx->CR2;

  /* Get the PWMx CMR register value */
  tmpccmrx = PWMx->CMR;

  /* Reset the Output Compare Mode Bits */
  tmpccmrx &= ~PWM_CMR_OC1M;
  /* Select the Output Compare Mode */
  tmpccmrx |= OC_Config->OCMode;

  /* Reset the Output Polarity level */
  tmpccer &= ~PWM_CER_C1P;
  /* Set the Output Compare Polarity */
  tmpccer |= OC_Config->OCPolarity;

  if (IS_PWM_OCXN_INSTANCE(PWMx, PWM_CHANNEL_1))
  {
    /* Check parameters */
    assert_param(IS_PWM_OCN_POLARITY(OC_Config->OCNPolarity));

    /* Reset the Output N Polarity level */
    tmpccer &= ~PWM_CER_C1NP;
    /* Set the Output N Polarity */
    tmpccer |= OC_Config->OCNPolarity;
    /* Reset the Output N State */
    tmpccer &= ~PWM_CER_C1NE;
  }

  /* Write to PWMx CR2 */
  PWMx->CR2 = tmpcr2;

  /* Write to PWMx CMR */
  PWMx->CMR = tmpccmrx;

  /* Set the Capture Compare Register value */
  PWMx->SR = ~(PWM_FLAG_CCR1OK);
  PWMx->CCR1 = OC_Config->Pulse;
  if(((PWMx->SMCR & PWM_SMCR_ECE) == PWM_SMCR_ECE)
    && (((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_SYS_CLK) || ((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_GPIO_HS)))
  {
    if(PWM_WaitForFlag(PWMx,PWM_FLAG_CCR1OK) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
  }
  
  /* Write to PWMx CER */
  PWMx->CER = tmpccer;
  
  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Timer Output Compare 2 configuration
  * @param  PWMx to select the PWM peripheral
  * @param  OC_Config The ouput configuration structure
  * @retval None
  */
static HAL_StatusTypeDef PWM_OC2_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config)
{
  uint32_t tmpccmrx;
  uint32_t tmpccer;
  uint32_t tmpcr2;

  /* Disable the Channel 2: Reset the CC2E Bit */
  PWMx->CER &= ~PWM_CER_C2E;

  /* Get the PWMx CER register value */
  tmpccer = PWMx->CER;
  /* Get the PWMx CR2 register value */
  tmpcr2 =  PWMx->CR2;

  /* Get the PWMx CMR register value */
  tmpccmrx = PWMx->CMR;

  /* Reset the Output Compare mode and Compare selection Bits */
  tmpccmrx &= ~PWM_CMR_OC2M;

  /* Select the Output Compare Mode */
  tmpccmrx |= ((OC_Config->OCMode >> PWM_CMR_OC1M_Pos) << PWM_CMR_OC2M_Pos);

  /* Reset the Output Polarity level */
  tmpccer &= ~PWM_CER_C2P;
  /* Set the Output Compare Polarity */
  tmpccer |= ((OC_Config->OCPolarity >> PWM_CER_C1P_Pos) << PWM_CER_C2P_Pos);

  if (IS_PWM_OCXN_INSTANCE(PWMx, PWM_CHANNEL_2))
  {
    assert_param(IS_PWM_OCN_POLARITY(OC_Config->OCNPolarity));

    /* Reset the Output N Polarity level */
    tmpccer &= ~PWM_CER_C2NP;
    /* Set the Output N Polarity */
    tmpccer |= ((OC_Config->OCNPolarity >> PWM_CER_C1NP_Pos) << PWM_CER_C2NP_Pos);
    /* Reset the Output N State */
    tmpccer &= ~PWM_CER_C2NE;

  }

  /* Write to PWMx CR2 */
  PWMx->CR2 = tmpcr2;

  /* Write to PWMx CMR */
  PWMx->CMR = tmpccmrx;

  /* Set the Capture Compare Register value */
  PWMx->SR = ~(PWM_FLAG_CCR2OK);
  PWMx->CCR2 = OC_Config->Pulse;
  if(((PWMx->SMCR & PWM_SMCR_ECE) == PWM_SMCR_ECE)
    && (((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_SYS_CLK) || ((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_GPIO_HS)))
  {
    if(PWM_WaitForFlag(PWMx,PWM_FLAG_CCR2OK) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
  }
  
  /* Write to PWMx CER */
  PWMx->CER = tmpccer;
  
  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Timer Output Compare 3 configuration
  * @param  PWMx to select the PWM peripheral
  * @param  OC_Config The ouput configuration structure
  * @retval None
  */
static HAL_StatusTypeDef PWM_OC3_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config)
{
  uint32_t tmpccmrx;
  uint32_t tmpccer;
  uint32_t tmpcr2;

  /* Disable the Channel 3: Reset the C3E Bit */
  PWMx->CER &= ~PWM_CER_C3E;

  /* Get the PWMx CER register value */
  tmpccer = PWMx->CER;
  /* Get the PWMx CR2 register value */
  tmpcr2 =  PWMx->CR2;

  /* Get the PWMx CMR register value */
  tmpccmrx = PWMx->CMR;

  /* Reset the Output Compare mode and Compare selection Bits */
  tmpccmrx &= ~PWM_CMR_OC3M;
  /* Select the Output Compare Mode */
  tmpccmrx |= ((OC_Config->OCMode >> PWM_CMR_OC1M_Pos) << PWM_CMR_OC3M_Pos);

  /* Reset the Output Polarity level */
  tmpccer &= ~PWM_CER_C3P;
  /* Set the Output Compare Polarity */
  tmpccer |= ((OC_Config->OCPolarity >> PWM_CER_C1P_Pos) << PWM_CER_C3P_Pos);

  /* Write to PWMx CR2 */
  PWMx->CR2 = tmpcr2;

  /* Write to PWMx CMR */
  PWMx->CMR = tmpccmrx;

  /* Set the Capture Compare Register value */
  PWMx->SR = ~(PWM_FLAG_CCR3OK);
  PWMx->CCR3 = OC_Config->Pulse;
  if(((PWMx->SMCR & PWM_SMCR_ECE) == PWM_SMCR_ECE)
    && (((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_SYS_CLK) || ((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_GPIO_HS)))
  {
    if(PWM_WaitForFlag(PWMx,PWM_FLAG_CCR3OK) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
  }
  
  /* Write to PWMx CER */
  PWMx->CER = tmpccer;
  
  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Timer Output Compare 4 configuration
  * @param  PWMx to select the PWM peripheral
  * @param  OC_Config The ouput configuration structure
  * @retval None
  */
static HAL_StatusTypeDef PWM_OC4_SetConfig(PWM_TypeDef *PWMx, PWM_OC_InitTypeDef *OC_Config)
{
  uint32_t tmpccmrx;
  uint32_t tmpccer;
  uint32_t tmpcr2;

  /* Disable the Channel 4: Reset the CC4E Bit */
  PWMx->CER &= ~PWM_CER_C4E;

  /* Get the PWMx CER register value */
  tmpccer = PWMx->CER;
  /* Get the PWMx CR2 register value */
  tmpcr2 =  PWMx->CR2;

  /* Get the PWMx CMR register value */
  tmpccmrx = PWMx->CMR;

  /* Reset the Output Compare mode and Compare selection Bits */
  tmpccmrx &= ~PWM_CMR_OC4M;

  /* Select the Output Compare Mode */
  tmpccmrx |= ((OC_Config->OCMode >> PWM_CMR_OC1M_Pos) << PWM_CMR_OC4M_Pos);

  /* Reset the Output Polarity level */
  tmpccer &= ~PWM_CER_C4P;
  /* Set the Output Compare Polarity */
  tmpccer |= ((OC_Config->OCPolarity >> PWM_CER_C1P_Pos) << PWM_CER_C4P_Pos);

  /* Write to PWMx CR2 */
  PWMx->CR2 = tmpcr2;

  /* Write to PWMx CMR */
  PWMx->CMR = tmpccmrx;

  /* Set the Capture Compare Register value */
  PWMx->SR = ~(PWM_FLAG_CCR4OK);
  PWMx->CCR4 = OC_Config->Pulse;
  if(((PWMx->SMCR & PWM_SMCR_ECE) == PWM_SMCR_ECE)
    && (((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_SYS_CLK) || ((PWMx->CR2 & PWM_CR2_ETRSEL) == PWM_PWM_ETR_GPIO_HS)))
  {
    if(PWM_WaitForFlag(PWMx,PWM_FLAG_CCR4OK) == HAL_TIMEOUT)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Write to PWMx CER */
  PWMx->CER = tmpccer;
  
  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Configures the PWMx External Trigger (ETR).
  * @param  PWMx to select the PWM peripheral
  * @param  PWM_ExtTRGPrescaler The external Trigger Prescaler.
  *          This parameter can be one of the following values:
  *            @arg PWM_ETRPRESCALER_DIV1: ETRP Prescaler OFF.
  *            @arg PWM_ETRPRESCALER_DIV2: ETRP frequency divided by 2.
  *            @arg PWM_ETRPRESCALER_DIV4: ETRP frequency divided by 4.
  *            @arg PWM_ETRPRESCALER_DIV8: ETRP frequency divided by 8.
  * @param  PWM_ExtTRGPolarity The external Trigger Polarity.
  *          This parameter can be one of the following values:
  *            @arg PWM_ETRPOLARITY_INVERTED: active low or falling edge active.
  *            @arg PWM_ETRPOLARITY_NONINVERTED: active high or rising edge active.
  * @param  ExtTRGFilter External Trigger Filter.
  *          This parameter must be a value between 0x00 and 0x0F
  * @retval None
  */
void PWM_ETR_SetConfig(PWM_TypeDef *PWMx, uint32_t PWM_ExtTRGPrescaler,
                       uint32_t PWM_ExtTRGPolarity, uint32_t ExtTRGFilter)
{
  uint32_t tmpsmcr;
  
  tmpsmcr = PWMx->SMCR;

  /* Reset the ETR Bits */
  tmpsmcr &= ~(PWM_SMCR_ETF | PWM_SMCR_ETPS | PWM_SMCR_ECE | PWM_SMCR_ETP);

  /* Set the Prescaler, the Filter value and the Polarity */
  tmpsmcr |= (uint32_t)(PWM_ExtTRGPrescaler | (PWM_ExtTRGPolarity | (ExtTRGFilter << PWM_SMCR_ETF_Pos)));

  /* Write to PWMx SMCR */
  PWMx->SMCR = tmpsmcr;
}

/**
  * @brief  Enables or disables the PWM Compare Channel x.
  * @param  PWMx to select the PWM peripheral
  * @param  Channel specifies the PWM Channel
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1
  *            @arg PWM_CHANNEL_2: PWM Channel 2
  *            @arg PWM_CHANNEL_3: PWM Channel 3
  *            @arg PWM_CHANNEL_4: PWM Channel 4
  * @param  ChannelState specifies the PWM Channel CxE bit new state.
  *          This parameter can be: PWM_OCx_ENABLE or PWM_OCx_DISABLE.
  * @retval None
  */
void PWM_OCxChannelCmd(PWM_TypeDef *PWMx, uint32_t Channel, uint32_t ChannelState)
{
  uint32_t tmp;

  /* Check the parameters */
  assert_param(IS_PWM_OC1_INSTANCE(PWMx));
  assert_param(IS_PWM_CHANNELS(Channel));

  tmp = PWM_CER_C1E << (Channel & 0x1FU); /* 0x1FU = 31 bits max shift */

  /* Reset the CxE Bit */
  PWMx->CER &= ~tmp;

  /* Set or reset the CxE Bit */
  PWMx->CER |= (uint32_t)(ChannelState << (Channel & 0x1FU)); /* 0x1FU = 31 bits max shift */
}

#if (USE_HAL_PWM_REGISTER_CALLBACKS == 1)
/**
  * @brief  Reset interrupt callbacks to the legacy weak callbacks.
  * @param  hpwm pointer to a PWM_HandleTypeDef structure that contains
  *                the configuration information for PWM module.
  * @retval None
  */
void PWM_ResetCallback(PWM_HandleTypeDef *hpwm)
{
  /* Reset the PWM callback to the legacy weak callbacks */
  hpwm->PeriodElapsedCallback             = HAL_PWM_PeriodElapsedCallback;             /* Legacy weak PeriodElapsedCallback             */
  hpwm->PeriodElapsedHalfCpltCallback     = HAL_PWM_PeriodElapsedHalfCpltCallback;     /* Legacy weak PeriodElapsedHalfCpltCallback     */
  hpwm->PWM_PulseFinishedCallback         = HAL_PWM_PWM_PulseFinishedCallback;         /* Legacy weak PWM_PulseFinishedCallback         */
  hpwm->PWM_PulseFinishedHalfCpltCallback = HAL_PWM_PWM_PulseFinishedHalfCpltCallback; /* Legacy weak PWM_PulseFinishedHalfCpltCallback */
  hpwm->ErrorCallback                     = HAL_PWM_ErrorCallback;                     /* Legacy weak ErrorCallback                     */
  hpwm->BreakCallback                     = HAL_PWMEx_BreakCallback;                   /* Legacy weak BreakCallback                     */
}
#endif /* USE_HAL_PWM_REGISTER_CALLBACKS */

/**
  * @brief  PWM Wait for flag set
  * @param  PWMx to select the PWM peripheral
  * @param  flag   The pwm flag
  * @retval HAL status
  */
static HAL_StatusTypeDef PWM_WaitForFlag(const PWM_TypeDef *PWMx, uint32_t flag)
{
  HAL_StatusTypeDef result = HAL_OK;
  uint32_t count = TIMEOUT * (SystemCoreClock / 20UL / 1000UL);
  do
  {
    count--;
    if (count == 0UL)
    {
      result = HAL_TIMEOUT;
    }
  } while (((PWMx->SR & flag) != (flag)) && (count != 0UL));
           
  return result;
}

/**
  * @}
  */

#endif /* HAL_PWM_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT Puya *****END OF FILE****/
