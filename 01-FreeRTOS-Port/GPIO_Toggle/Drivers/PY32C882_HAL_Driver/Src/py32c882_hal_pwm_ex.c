/**
  ******************************************************************************
  * @file    py32c882_hal_pwm_ex.c
  * @author  MCU Application Team
  * @brief   PWM_EX HAL module driver.
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

/** @defgroup PWMEx PWMEx
  * @brief PWM Extended HAL module driver
  * @{
  */

#ifdef HAL_PWM_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void PWM_OCxNChannelCmd(PWM_TypeDef *PWMx, uint32_t Channel, uint32_t ChannelNState);

/* Exported functions --------------------------------------------------------*/
/** @defgroup PWMEx_Exported_Functions PWM Extended Exported Functions
  * @{
  */

/** @defgroup PWMEx_Exported_Functions_Group1 Extended PWM Complementary PWM functions
  * @brief    pwm Complementary PWM functions
  *
@verbatim
  ==============================================================================
                 ##### pwm Complementary PWM functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Start the Complementary PWM.
    (+) Stop the Complementary PWM.
    (+) Start the Complementary PWM and enable interrupts.
    (+) Stop the Complementary PWM and disable interrupts.
    (+) Start the Complementary PWM and enable DMA transfers.
    (+) Stop the Complementary PWM and disable DMA transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Starts the PWM signal generation on the complementary output.
  * @param  hpwm PWM handle
  * @param  Channel PWM Channel to be enabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Start(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCXN_INSTANCE(hpwm->Instance, Channel));

  /* Enable the complementary PWM output  */
  PWM_OCxNChannelCmd(hpwm->Instance, Channel, PWM_OCxN_ENABLE);

  /* Enable the Main Output */
  __HAL_PWM_MOE_ENABLE(hpwm);

  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM signal generation on the complementary output.
  * @param  hpwm PWM handle
  * @param  Channel PWM Channel to be disabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Stop(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCXN_INSTANCE(hpwm->Instance, Channel));

  /* Disable the complementary PWM output  */
  PWM_OCxNChannelCmd(hpwm->Instance, Channel, PWM_OCxN_DISABLE);

  /* Disable the Main Output */
  __HAL_PWM_MOE_DISABLE(hpwm);

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Starts the PWM signal generation in interrupt mode on the
  *         complementary output.
  * @param  hpwm PWM handle
  * @param  Channel PWM Channel to be disabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Start_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCXN_INSTANCE(hpwm->Instance, Channel));

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

  default:
    break;
  }

  /* Enable the PWM Break interrupt */
  __HAL_PWM_ENABLE_IT(hpwm, PWM_IT_BREAK);

  /* Enable the complementary PWM output  */
  PWM_OCxNChannelCmd(hpwm->Instance, Channel, PWM_OCxN_ENABLE);

  /* Enable the Main Output */
  __HAL_PWM_MOE_ENABLE(hpwm);

  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM signal generation in interrupt mode on the
  *         complementary output.
  * @param  hpwm PWM handle
  * @param  Channel PWM Channel to be disabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Stop_IT(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  uint32_t tmpccer;

  /* Check the parameters */
  assert_param(IS_PWM_OCXN_INSTANCE(hpwm->Instance, Channel));

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

  default:
    break;
  }

  /* Disable the complementary PWM output  */
  PWM_OCxNChannelCmd(hpwm->Instance, Channel, PWM_OCxN_DISABLE);

  /* Disable the PWM Break interrupt (only if no more channel is active) */
  tmpccer = hpwm->Instance->CER;
  if ((tmpccer & (PWM_CER_C1NE | PWM_CER_C2NE )) == (uint32_t)RESET)
  {
    __HAL_PWM_DISABLE_IT(hpwm, PWM_IT_BREAK);
  }

  /* Disable the Main Output */
  __HAL_PWM_MOE_DISABLE(hpwm);

  /* Disable the Peripheral */
  __HAL_PWM_DISABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

#if (defined(DMA) || defined(DMA1))
/**
  * @brief  Starts the PWM PWM signal generation in DMA mode on the
  *         complementary output
  * @param  hpwm PWM handle
  * @param  Channel PWM Channel to be enabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  * @param  pData The source Buffer address.
  * @param  Length The length of data to be transferred from memory to PWM peripheral
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Start_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel, uint32_t *pData, uint16_t Length)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCXN_INSTANCE(hpwm->Instance, Channel));

  if (hpwm->State == HAL_PWM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  else if (hpwm->State == HAL_PWM_STATE_READY)
  {
    if (((uint32_t)pData == 0U) && (Length > 0U))
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

  default:
    break;
  }

  /* Enable the complementary PWM output  */
  PWM_OCxNChannelCmd(hpwm->Instance, Channel, PWM_OCxN_ENABLE);

  /* Enable the Main Output */
  __HAL_PWM_MOE_ENABLE(hpwm);

  __HAL_PWM_ENABLE(hpwm);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the PWM PWM signal generation in DMA mode on the complementary
  *         output
  * @param  hpwm PWM handle
  * @param  Channel PWM Channel to be disabled
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1 selected
  *            @arg PWM_CHANNEL_2: PWM Channel 2 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_PWMN_Stop_DMA(PWM_HandleTypeDef *hpwm, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_PWM_OCXN_INSTANCE(hpwm->Instance, Channel));

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

  default:
    break;
  }

  /* Disable the complementary PWM output */
  PWM_OCxNChannelCmd(hpwm->Instance, Channel, PWM_OCxN_DISABLE);

  /* Disable the Main Output */
  __HAL_PWM_MOE_DISABLE(hpwm);

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

/** @defgroup PWMEx_Exported_Functions_Group2 Extended Peripheral Control functions
  * @brief    Peripheral Control functions
  *
@verbatim
  ==============================================================================
                    ##### Peripheral Control functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
      (+) Configure Output channels for PWM mode.
      (+) Configure Complementary channels, break features and dead time.
      (+) Configure pwm remapping capabilities.

@endverbatim
  * @{
  */

/**
  * @brief  Configures the Break feature, dead time, Lock level
  *         and the AOE(automatic output enable).
  * @param  hpwm PWM handle
  * @param  sBreakDeadTimeConfig pointer to a PWM_ConfigBreakDeadConfigTypeDef structure that
  *         contains the BDTR Register configuration  information for the PWM peripheral.
  * @note   Interrupts can be generated when an active level is detected on the
  *         break input. Break
  *         interrupt can be enabled by calling the @ref __HAL_PWM_ENABLE_IT macro.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_ConfigBreakDeadTime(PWM_HandleTypeDef *hpwm,
    PWM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig)
{
  /* Keep this variable initialized to 0 as it is used to configure BDTR register */
  uint32_t tmpbdtr = 0U;

  /* Check the parameters */
  assert_param(IS_PWM_BREAK_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_LOCK_LEVEL(sBreakDeadTimeConfig->LockLevel));
  assert_param(IS_PWM_DEADPWME(sBreakDeadTimeConfig->DeadTime));
  assert_param(IS_PWM_BREAK_STATE(sBreakDeadTimeConfig->BreakState));
  assert_param(IS_PWM_BREAK_POLARITY(sBreakDeadTimeConfig->BreakPolarity));
  assert_param(IS_PWM_AUTOMATIC_OUTPUT_STATE(sBreakDeadTimeConfig->AutomaticOutput));

  /* Check input state */
  __HAL_LOCK(hpwm);

  /* Set the Lock level, the Break enable Bit and the Polarity,
  the dead time value and the Automatic Output Enable Bit */

  /* Set the BDTR bits */
  MODIFY_REG(tmpbdtr, PWM_BDTR_DTG, sBreakDeadTimeConfig->DeadTime);
  MODIFY_REG(tmpbdtr, PWM_BDTR_LOCK, sBreakDeadTimeConfig->LockLevel);
  MODIFY_REG(tmpbdtr, PWM_BDTR_BKE, sBreakDeadTimeConfig->BreakState);
  MODIFY_REG(tmpbdtr, PWM_BDTR_BKP, sBreakDeadTimeConfig->BreakPolarity);
  MODIFY_REG(tmpbdtr, PWM_BDTR_AOE, sBreakDeadTimeConfig->AutomaticOutput);

  /* Set PWMx_BDTR */
  hpwm->Instance->BDTR = tmpbdtr;

  __HAL_UNLOCK(hpwm);

  return HAL_OK;
}

/**
  * @brief  Configures the break input source.
  * @param  hpwm PWM handle.
  * @param  BreakInput Break input to configure
  *          This parameter can be one of the following values:
  *            @arg PWM_BREAKINPUT_BRK: pwm break input
  * @param  sBreakInputConfig Break input source configuration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_ConfigBreakInput(PWM_HandleTypeDef *hpwm,
                                             uint32_t BreakInput,
                                             const PWMEx_BreakInputConfigTypeDef *sBreakInputConfig)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tmporx;
  uint32_t bkin_enable_mask;
  uint32_t bkin_polarity_mask;
  uint32_t bkin_enable_bitpos;
  uint32_t bkin_polarity_bitpos;

  /* Check the parameters */
  assert_param(IS_PWM_BREAK_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_BREAKINPUT(BreakInput));
  assert_param(IS_PWM_BREAKINPUTSOURCE(sBreakInputConfig->Source));
  assert_param(IS_PWM_BREAKINPUTSOURCE_STATE(sBreakInputConfig->Enable));
  assert_param(IS_PWM_BREAKINPUTSOURCE_POLARITY(sBreakInputConfig->Polarity));

  /* Check input state */
  __HAL_LOCK(hpwm);

  switch (sBreakInputConfig->Source)
  {
    case PWM_BREAKINPUTSOURCE_BKIN:
    {
      bkin_enable_mask = PWM_CR2_BKINE;
      bkin_enable_bitpos = PWM_CR2_BKINE_Pos;
      bkin_polarity_mask = PWM_CR2_BKINP;
      bkin_polarity_bitpos = PWM_CR2_BKINP_Pos;
      break;
    }
    case PWM_BREAKINPUTSOURCE_COMP1:
    {
      bkin_enable_mask = PWM_CR2_BKCMP1E;
      bkin_enable_bitpos = PWM_CR2_BKCMP1E_Pos;
      bkin_polarity_mask = PWM_CR2_BKCMP1P;
      bkin_polarity_bitpos = PWM_CR2_BKCMP1P_Pos;
      break;
    }
    case PWM_BREAKINPUTSOURCE_COMP2:
    {
      bkin_enable_mask = PWM_CR2_BKCMP2E;
      bkin_enable_bitpos = PWM_CR2_BKCMP2E_Pos;
      bkin_polarity_mask = PWM_CR2_BKCMP2P;
      bkin_polarity_bitpos = PWM_CR2_BKCMP2P_Pos;
      break;
    }
    default:
    {
      bkin_enable_mask = 0U;
      bkin_polarity_mask = 0U;
      bkin_enable_bitpos = 0U;
      bkin_polarity_bitpos = 0U;
      break;
    }
  }

  switch (BreakInput)
  {
    case PWM_BREAKINPUT_BRK:
    {
      /* Get the PWMx_CR2 register value */
      tmporx = hpwm->Instance->CR2;

      /* Enable the break input */
      tmporx &= ~bkin_enable_mask;
      tmporx |= (sBreakInputConfig->Enable << bkin_enable_bitpos) & bkin_enable_mask;

      /* Set the break input polarity */
      tmporx &= ~bkin_polarity_mask;
      tmporx |= (sBreakInputConfig->Polarity << bkin_polarity_bitpos) & bkin_polarity_mask;

      /* Set PWMx_CR2 */
      hpwm->Instance->CR2 = tmporx;
      break;
    }

    default:
      status = HAL_ERROR;
      break;
  }

  __HAL_UNLOCK(hpwm);

  return status;
}

/**
  * @brief  Configures the PWMx Remapping input capabilities.
  * @param  hpwm PWM handle.
  * @param  Remap specifies the PWM remapping source.
  *         For PWM, the parameter can take one of the following values:
  *            @arg PWM_PWM_ETR_GPIO_LS        PWM ETR is connected to GPIO_LS
  *            @arg PWM_PWM_ETR_COMP1          PWM ETR is connected to COMP1 output
  *            @arg PWM_PWM_ETR_COMP2          PWM ETR is connected to COMP2 output
  *            @arg PWM_PWM_ETR_SYS_CLK        PWM ETR is connected to System clock
  *            @arg PWM_PWM_ETR_GPIO_HS        PWM ETR is connected to GPIO_HS
  *
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_RemapConfig(PWM_HandleTypeDef *hpwm, uint32_t Remap)
{
  /* Check parameters */
  assert_param(IS_PWM_REMAP_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_REMAP(Remap));

  __HAL_LOCK(hpwm);

  MODIFY_REG(hpwm->Instance->CR2, PWM_CR2_ETRSEL_Msk, Remap);

  __HAL_UNLOCK(hpwm);

  return HAL_OK;
}


/**
  * @brief  Configure deadtime
  * @param  hpwm PWM handle
  * @param  Deadtime Deadtime value
  * @note   This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWMEx_ConfigDeadTime(PWM_HandleTypeDef *hpwm, uint32_t Deadtime)
{
  /* Check the parameters */
  assert_param(IS_PWM_BREAK_INSTANCE(hpwm->Instance));
  assert_param(IS_PWM_DEADPWME(Deadtime));

  MODIFY_REG(hpwm->Instance->BDTR, PWM_BDTR_DTG, Deadtime);
  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup PWMEx_Exported_Functions_Group3 Extended Callbacks functions
  * @brief    Extended Callbacks functions
  *
@verbatim
  ==============================================================================
                    ##### Extended Callbacks functions #####
  ==============================================================================
  [..]
    This section provides Extended PWM callback functions:
    (+) pwm Break callback

@endverbatim
  * @{
  */

/**
  * @brief  Hall Break detection callback in non-blocking mode
  * @param  hpwm PWM handle
  * @retval None
  */
__weak void HAL_PWMEx_BreakCallback(PWM_HandleTypeDef *hpwm)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpwm);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PWMEx_BreakCallback could be implemented in the user file
   */
}
/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup PWMEx_Private_Functions PWM Extended Private Functions
  * @{
  */

/**
  * @brief  Enables or disables the PWM Compare Channel xN.
  * @param  PWMx to select the PWM peripheral
  * @param  Channel specifies the PWM Channel
  *          This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_1: PWM Channel 1
  *            @arg PWM_CHANNEL_2: PWM Channel 2
  * @param  ChannelNState specifies the PWM Channel CxNE bit new state.
  *          This parameter can be: PWM_OCxN_ENABLE or PWM_OCxN_Disable.
  * @retval None
  */
static void PWM_OCxNChannelCmd(PWM_TypeDef *PWMx, uint32_t Channel, uint32_t ChannelNState)
{
  uint32_t tmp;

  tmp = PWM_CER_C1NE << (Channel & 0x1FU); /* 0x1FU = 31 bits max shift */

  /* Reset the CxNE Bit */
  PWMx->CER &=  ~tmp;

  /* Set or reset the CxNE Bit */
  PWMx->CER |= (uint32_t)(ChannelNState << (Channel & 0x1FU)); /* 0x1FU = 31 bits max shift */
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
