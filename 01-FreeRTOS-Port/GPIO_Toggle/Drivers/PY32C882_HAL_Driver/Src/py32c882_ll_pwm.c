/**
  ******************************************************************************
  * @file    py32c882_ll_pwm.c
  * @author  MCU Application Team
  * @brief   PWM LL module driver.
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
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "py32c882_ll_pwm.h"
#include "py32c882_ll_bus.h"
#include "py32c882_ll_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "py32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup PY32C882_LL_Driver
  * @{
  */

#if defined (PWM)

/** @addtogroup PWM_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup PWM_LL_Private_Macros
  * @{
  */
#define IS_LL_PWM_COUNTERMODE(__VALUE__) (((__VALUE__) == LL_PWM_COUNTERMODE_UP) \
                                          || ((__VALUE__) == LL_PWM_COUNTERMODE_DOWN) \
                                          || ((__VALUE__) == LL_PWM_COUNTERMODE_CENTER_UP) \
                                          || ((__VALUE__) == LL_PWM_COUNTERMODE_CENTER_DOWN) \
                                          || ((__VALUE__) == LL_PWM_COUNTERMODE_CENTER_UP_DOWN))

#define IS_LL_PWM_CLOCKDIVISION(__VALUE__) (((__VALUE__) == LL_PWM_CLOCKDIVISION_DIV1) \
                                            || ((__VALUE__) == LL_PWM_CLOCKDIVISION_DIV2) \
                                            || ((__VALUE__) == LL_PWM_CLOCKDIVISION_DIV4))

#define IS_LL_PWM_OCMODE(__VALUE__) (((__VALUE__) == LL_PWM_OCMODE_PWM1) \
                                     || ((__VALUE__) == LL_PWM_OCMODE_PWM2))

#define IS_LL_PWM_OCSTATE(__VALUE__) (((__VALUE__) == LL_PWM_OCSTATE_DISABLE) \
                                      || ((__VALUE__) == LL_PWM_OCSTATE_ENABLE))

#define IS_LL_PWM_OCPOLARITY(__VALUE__) (((__VALUE__) == LL_PWM_OCPOLARITY_HIGH) \
                                         || ((__VALUE__) == LL_PWM_OCPOLARITY_LOW))

#define IS_LL_PWM_LOCK_LEVEL(__VALUE__) (((__VALUE__) == LL_PWM_LOCKLEVEL_OFF) \
                                         || ((__VALUE__) == LL_PWM_LOCKLEVEL_1)   \
                                         || ((__VALUE__) == LL_PWM_LOCKLEVEL_2)   \
                                         || ((__VALUE__) == LL_PWM_LOCKLEVEL_3))

#define IS_LL_PWM_BREAK_STATE(__VALUE__) (((__VALUE__) == LL_PWM_BREAK_DISABLE) \
                                          || ((__VALUE__) == LL_PWM_BREAK_ENABLE))

#define IS_LL_PWM_BREAK_POLARITY(__VALUE__) (((__VALUE__) == LL_PWM_BREAK_POLARITY_LOW) \
                                             || ((__VALUE__) == LL_PWM_BREAK_POLARITY_HIGH))

#define IS_LL_PWM_AUTOMATIC_OUTPUT_STATE(__VALUE__) (((__VALUE__) == LL_PWM_AUTOMATICOUTPUT_DISABLE) \
                                                     || ((__VALUE__) == LL_PWM_AUTOMATICOUTPUT_ENABLE))
/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @defgroup PWM_LL_Private_Functions PWM Private Functions
  * @{
  */
static ErrorStatus OC1Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct);
static ErrorStatus OC2Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct);
static ErrorStatus OC3Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct);
static ErrorStatus OC4Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PWM_LL_Exported_Functions
  * @{
  */

/** @addtogroup PWM_LL_EF_Init
  * @{
  */

/**
  * @brief  Set PWMx registers to their reset values.
  * @param  PWMx Pwm instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PWMx registers are de-initialized
  *          - ERROR: invalid PWMx instance
  */
ErrorStatus LL_PWM_DeInit(PWM_TypeDef *PWMx)
{
  ErrorStatus result = SUCCESS;

  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(PWMx));

  if (PWMx == PWM)
  {
    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_PWM);
    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_PWM);
  }
  else
  {
    result = ERROR;
  }

  return result;
}

/**
  * @brief  Set the fields of the time base unit configuration data structure
  *         to their default values.
  * @param  PWM_InitStruct pointer to a @ref LL_PWM_InitTypeDef structure (time base unit configuration data structure)
  * @retval None
  */
void LL_PWM_StructInit(LL_PWM_InitTypeDef *PWM_InitStruct)
{
  /* Set the default configuration */
  PWM_InitStruct->Prescaler         = (uint16_t)0x0000;
  PWM_InitStruct->CounterMode       = LL_PWM_COUNTERMODE_UP;
  PWM_InitStruct->Autoreload        = 0xFFFFFFFFU;
  PWM_InitStruct->ClockDivision     = LL_PWM_CLOCKDIVISION_DIV1;
}

/**
  * @brief  Configure the PWMx time base unit.
  * @param  PWMx Pwm Instance
  * @param  PWM_InitStruct pointer to a @ref LL_PWM_InitTypeDef structure (PWMx time base unit configuration data structure)
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PWMx registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_PWM_Init(PWM_TypeDef *PWMx, LL_PWM_InitTypeDef *PWM_InitStruct)
{
  LL_RCC_ClocksTypeDef rcc_clock;
  uint32_t tmpcr1;

  /* Check the parameters */
  assert_param(IS_PWM_INSTANCE(PWMx));
  assert_param(IS_LL_PWM_COUNTERMODE(PWM_InitStruct->CounterMode));
  assert_param(IS_LL_PWM_CLOCKDIVISION(PWM_InitStruct->ClockDivision));

  tmpcr1 = LL_PWM_ReadReg(PWMx, CR1);
  
  if (IS_PWM_COUNTER_MODE_SELECT_INSTANCE(PWMx))
  {
    /* Select the Counter Mode */
    MODIFY_REG(tmpcr1, (PWM_CR1_DIR | PWM_CR1_CMS), PWM_InitStruct->CounterMode);
  }

  if (IS_PWM_CLOCK_DIVISION_INSTANCE(PWMx))
  {
    /* Set the clock division */
    MODIFY_REG(tmpcr1, PWM_CR1_CKD, PWM_InitStruct->ClockDivision);
  }

  /* Write to PWMx CR1 */
  LL_PWM_WriteReg(PWMx, CR1, tmpcr1);

  /* Set the Autoreload value */
  LL_PWM_ClearFlag_ARROK(PWMx);
  LL_PWM_SetAutoReload(PWMx, PWM_InitStruct->Autoreload);
  if((LL_PWM_IsEnabledExternalClock(PWMx))
    && ((LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_SYS_CLK) || (LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_GPIO_HS)))
  {
    LL_RCC_GetSystemClocksFreq(&rcc_clock);
    /* Polling on ARR write ok status after above restore operation */
    do
    {
      rcc_clock.SYSCLK_Frequency--; /* Used for timeout */
    }
    while (((LL_PWM_IsActiveFlag_ARROK(PWMx) != 1UL)) && ((rcc_clock.SYSCLK_Frequency) > 0UL));
  }
  
  /* Set the Prescaler value */
  LL_PWM_ClearFlag_PSCOK(PWMx);
  LL_PWM_SetPrescaler(PWMx, PWM_InitStruct->Prescaler);
  if((LL_PWM_IsEnabledExternalClock(PWMx))
    && ((LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_SYS_CLK) || (LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_GPIO_HS)))
  {
    LL_RCC_GetSystemClocksFreq(&rcc_clock);
    /* Polling on PSC write ok status after above restore operation */
    do
    {
      rcc_clock.SYSCLK_Frequency--; /* Used for timeout */
    }
    while (((LL_PWM_IsActiveFlag_PSCOK(PWMx) != 1UL)) && ((rcc_clock.SYSCLK_Frequency) > 0UL));
  }
  
  /* Generate an update event to reload the Prescaler
     and the repetition counter value (if applicable) immediately */
  LL_PWM_GenerateEvent_UPDATE(PWMx);

  return SUCCESS;
}

/**
  * @brief  Set the fields of the PWMx output channel configuration data
  *         structure to their default values.
  * @param  PWM_OC_InitStruct pointer to a @ref LL_PWM_OC_InitTypeDef structure (the output channel configuration data structure)
  * @retval None
  */
void LL_PWM_OC_StructInit(LL_PWM_OC_InitTypeDef *PWM_OC_InitStruct)
{
  /* Set the default configuration */
  PWM_OC_InitStruct->OCMode       = LL_PWM_OCMODE_PWM1;
  PWM_OC_InitStruct->OCState      = LL_PWM_OCSTATE_DISABLE;
  PWM_OC_InitStruct->OCNState     = LL_PWM_OCSTATE_DISABLE;
  PWM_OC_InitStruct->CompareValue = 0x00000000U;
  PWM_OC_InitStruct->OCPolarity   = LL_PWM_OCPOLARITY_HIGH;
  PWM_OC_InitStruct->OCNPolarity  = LL_PWM_OCPOLARITY_HIGH;
}

/**
  * @brief  Configure the PWMx output channel.
  * @param  PWMx Pwm Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_PWM_CHANNEL_CH1
  *         @arg @ref LL_PWM_CHANNEL_CH2
  *         @arg @ref LL_PWM_CHANNEL_CH3
  *         @arg @ref LL_PWM_CHANNEL_CH4
  * @param  PWM_OC_InitStruct pointer to a @ref LL_PWM_OC_InitTypeDef structure (PWMx output channel configuration data structure)
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PWMx output channel is initialized
  *          - ERROR: PWMx output channel is not initialized
  */
ErrorStatus LL_PWM_OC_Init(PWM_TypeDef *PWMx, uint32_t Channel, LL_PWM_OC_InitTypeDef *PWM_OC_InitStruct)
{
  ErrorStatus result = ERROR;

  switch (Channel)
  {
    case LL_PWM_CHANNEL_CH1:
      result = OC1Config(PWMx, PWM_OC_InitStruct);
      break;
    case LL_PWM_CHANNEL_CH2:
      result = OC2Config(PWMx, PWM_OC_InitStruct);
      break;
    case LL_PWM_CHANNEL_CH3:
      result = OC3Config(PWMx, PWM_OC_InitStruct);
      break;
    case LL_PWM_CHANNEL_CH4:
      result = OC4Config(PWMx, PWM_OC_InitStruct);
      break;
    default:
      break;
  }

  return result;
}

/**
  * @brief  Set the fields of the Break and Dead Time configuration data structure
  *         to their default values.
  * @param  PWM_BDTRInitStruct pointer to a @ref LL_PWM_BDTR_InitTypeDef structure (Break and Dead Time configuration data structure)
  * @retval None
  */
void LL_PWM_BDTR_StructInit(LL_PWM_BDTR_InitTypeDef *PWM_BDTRInitStruct)
{
  /* Set the default configuration */
  PWM_BDTRInitStruct->LockLevel       = LL_PWM_LOCKLEVEL_OFF;
  PWM_BDTRInitStruct->DeadTime        = (uint8_t)0x00;
  PWM_BDTRInitStruct->BreakState      = LL_PWM_BREAK_DISABLE;
  PWM_BDTRInitStruct->BreakPolarity   = LL_PWM_BREAK_POLARITY_LOW;
  PWM_BDTRInitStruct->AutomaticOutput = LL_PWM_AUTOMATICOUTPUT_DISABLE;
}

/**
  * @brief  Configure the Break and Dead Time feature of the pwm instance.
  * @note As the bits AOE, BKP, BKE, OSSR, OSSI and DTG[7:0] can be write-locked
  *  depending on the LOCK configuration, it can be necessary to configure all of
  *  them during the first write access to the PWMx_BDTR register.
  * @note Macro IS_PWM_BREAK_INSTANCE(PWMx) can be used to check whether or not
  *       a pwm instance provides a break input.
  * @param  PWMx Pwm Instance
  * @param  PWM_BDTRInitStruct pointer to a @ref LL_PWM_BDTR_InitTypeDef structure (Break and Dead Time configuration data structure)
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: Break and Dead Time is initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_PWM_BDTR_Init(PWM_TypeDef *PWMx, LL_PWM_BDTR_InitTypeDef *PWM_BDTRInitStruct)
{
  uint32_t tmpbdtr = 0;

  /* Check the parameters */
  assert_param(IS_PWM_BREAK_INSTANCE(PWMx));
  assert_param(IS_LL_PWM_LOCK_LEVEL(PWM_BDTRInitStruct->LockLevel));
  assert_param(IS_LL_PWM_BREAK_STATE(PWM_BDTRInitStruct->BreakState));
  assert_param(IS_LL_PWM_BREAK_POLARITY(PWM_BDTRInitStruct->BreakPolarity));
  assert_param(IS_LL_PWM_AUTOMATIC_OUTPUT_STATE(PWM_BDTRInitStruct->AutomaticOutput));

  /* Set the Lock level, the Break enable Bit and the Polarity, the OSSR State,
  the OSSI State, the dead time value and the Automatic Output Enable Bit */

  /* Set the BDTR bits */
  MODIFY_REG(tmpbdtr, PWM_BDTR_DTG, PWM_BDTRInitStruct->DeadTime);
  MODIFY_REG(tmpbdtr, PWM_BDTR_LOCK, PWM_BDTRInitStruct->LockLevel);
  MODIFY_REG(tmpbdtr, PWM_BDTR_BKE, PWM_BDTRInitStruct->BreakState);
  MODIFY_REG(tmpbdtr, PWM_BDTR_BKP, PWM_BDTRInitStruct->BreakPolarity);
  MODIFY_REG(tmpbdtr, PWM_BDTR_AOE, PWM_BDTRInitStruct->AutomaticOutput);
  MODIFY_REG(tmpbdtr, PWM_BDTR_MOE, PWM_BDTRInitStruct->AutomaticOutput);

  /* Set PWMx_BDTR */
  LL_PWM_WriteReg(PWMx, BDTR, tmpbdtr);

  return SUCCESS;
}
/**
  * @}
  */

/**
  * @}
  */

/* Private functions --------------------------------------------------------*/
/** @addtogroup PWM_LL_Private_Functions PWM Private Functions
  *  @brief   Private functions
  * @{
  */
/**
  * @brief  Configure the PWMx output channel 1.
  * @param  PWMx Pwm Instance
  * @param  PWM_OCInitStruct pointer to the the PWMx output channel 1 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PWMx registers are de-initialized
  *          - ERROR: not applicable
  */
static ErrorStatus OC1Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct)
{
  LL_RCC_ClocksTypeDef rcc_clock;
  uint32_t tmpccmr1;
  uint32_t tmpccer;

  /* Check the parameters */
  assert_param(IS_PWM_OC1_INSTANCE(PWMx));
  assert_param(IS_LL_PWM_OCMODE(PWM_OCInitStruct->OCMode));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCState));
  assert_param(IS_LL_PWM_OCPOLARITY(PWM_OCInitStruct->OCPolarity));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCNState));
  assert_param(IS_LL_PWM_OCPOLARITY(PWM_OCInitStruct->OCNPolarity));

  /* Disable the Channel 1: Reset the C1E Bit */
  CLEAR_BIT(PWMx->CER, PWM_CER_C1E);

  /* Get the PWMx CER register value */
  tmpccer = LL_PWM_ReadReg(PWMx, CER);

  /* Get the PWMx CMR register value */
  tmpccmr1 = LL_PWM_ReadReg(PWMx, CMR);

  /* Set the Output Compare Mode */
  MODIFY_REG(tmpccmr1, PWM_CMR_OC1M, PWM_OCInitStruct->OCMode);

  /* Set the Output Compare Polarity */
  MODIFY_REG(tmpccer, PWM_CER_C1P, PWM_OCInitStruct->OCPolarity);

  /* Set the Output State */
  MODIFY_REG(tmpccer, PWM_CER_C1E, PWM_OCInitStruct->OCState);

  if (IS_PWM_BREAK_INSTANCE(PWMx))
  {
    /* Set the complementary output Polarity */
    MODIFY_REG(tmpccer, PWM_CER_C1NP, PWM_OCInitStruct->OCNPolarity << 2U);

    /* Set the complementary output State */
    MODIFY_REG(tmpccer, PWM_CER_C1NE, PWM_OCInitStruct->OCNState << 2U);
  }

  /* Write to PWMx CMR */
  LL_PWM_WriteReg(PWMx, CMR, tmpccmr1);
  
  /* Set the Compare Register value */
  LL_PWM_ClearFlag_CCR1OK(PWMx);
  LL_PWM_OC_SetCompareCH1(PWMx, PWM_OCInitStruct->CompareValue);
  if((LL_PWM_IsEnabledExternalClock(PWMx))
    && ((LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_SYS_CLK) || (LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_GPIO_HS)))
  {
    LL_RCC_GetSystemClocksFreq(&rcc_clock);
    /* Polling on CCR1 write ok status after above restore operation */
    do
    {
      rcc_clock.SYSCLK_Frequency--; /* Used for timeout */
    }
    while (((LL_PWM_IsActiveFlag_CCR1OK(PWMx) != 1UL)) && ((rcc_clock.SYSCLK_Frequency) > 0UL));
  }
  
  /* Write to PWMx CER */
  LL_PWM_WriteReg(PWMx, CER, tmpccer);

  return SUCCESS;
}

/**
  * @brief  Configure the PWMx output channel 2.
  * @param  PWMx Pwm Instance
  * @param  PWM_OCInitStruct pointer to the the PWMx output channel 2 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PWMx registers are de-initialized
  *          - ERROR: not applicable
  */
static ErrorStatus OC2Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct)
{
  LL_RCC_ClocksTypeDef rcc_clock;
  uint32_t tmpccmr1;
  uint32_t tmpccer;

  /* Check the parameters */
  assert_param(IS_PWM_OC2_INSTANCE(PWMx));
  assert_param(IS_LL_PWM_OCMODE(PWM_OCInitStruct->OCMode));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCState));
  assert_param(IS_LL_PWM_OCPOLARITY(PWM_OCInitStruct->OCPolarity));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCNState));
  assert_param(IS_LL_PWM_OCPOLARITY(PWM_OCInitStruct->OCNPolarity));

  /* Disable the Channel 2: Reset the C2E Bit */
  CLEAR_BIT(PWMx->CER, PWM_CER_C2E);

  /* Get the PWMx CER register value */
  tmpccer =  LL_PWM_ReadReg(PWMx, CER);

  /* Get the PWMx CMR register value */
  tmpccmr1 = LL_PWM_ReadReg(PWMx, CMR);

  /* Select the Output Compare Mode */
  MODIFY_REG(tmpccmr1, PWM_CMR_OC2M, PWM_OCInitStruct->OCMode << PWM_CMR_OC2M_Pos);

  /* Set the Output Compare Polarity */
  MODIFY_REG(tmpccer, PWM_CER_C2P, PWM_OCInitStruct->OCPolarity << 4U);

  /* Set the Output State */
  MODIFY_REG(tmpccer, PWM_CER_C2E, PWM_OCInitStruct->OCState << 4U);

  if (IS_PWM_BREAK_INSTANCE(PWMx))
  {
    /* Set the complementary output Polarity */
    MODIFY_REG(tmpccer, PWM_CER_C2NP, PWM_OCInitStruct->OCNPolarity << 6U);

    /* Set the complementary output State */
    MODIFY_REG(tmpccer, PWM_CER_C2NE, PWM_OCInitStruct->OCNState << 6U);

  }

  /* Write to PWMx CMR */
  LL_PWM_WriteReg(PWMx, CMR, tmpccmr1);
  
  /* Set the Compare Register value */
  LL_PWM_ClearFlag_CCR2OK(PWMx);
  LL_PWM_OC_SetCompareCH2(PWMx, PWM_OCInitStruct->CompareValue);
  if((LL_PWM_IsEnabledExternalClock(PWMx))
    && ((LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_SYS_CLK) || (LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_GPIO_HS)))
  {
    LL_RCC_GetSystemClocksFreq(&rcc_clock);
    /* Polling on CCR2 write ok status after above restore operation */
    do
    {
      rcc_clock.SYSCLK_Frequency--; /* Used for timeout */
    }
    while (((LL_PWM_IsActiveFlag_CCR2OK(PWMx) != 1UL)) && ((rcc_clock.SYSCLK_Frequency) > 0UL));
  }
  
  /* Write to PWMx CER */
  LL_PWM_WriteReg(PWMx, CER, tmpccer);

  return SUCCESS;
}

/**
  * @brief  Configure the PWMx output channel 3.
  * @param  PWMx Pwm Instance
  * @param  PWM_OCInitStruct pointer to the the PWMx output channel 3 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PWMx registers are de-initialized
  *          - ERROR: not applicable
  */
static ErrorStatus OC3Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct)
{
  LL_RCC_ClocksTypeDef rcc_clock;
  uint32_t tmpccmr2;
  uint32_t tmpccer;

  /* Check the parameters */
  assert_param(IS_PWM_OC3_INSTANCE(PWMx));
  assert_param(IS_LL_PWM_OCMODE(PWM_OCInitStruct->OCMode));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCState));
  assert_param(IS_LL_PWM_OCPOLARITY(PWM_OCInitStruct->OCPolarity));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCNState));

  /* Disable the Channel 3: Reset the C3E Bit */
  CLEAR_BIT(PWMx->CER, PWM_CER_C3E);

  /* Get the PWMx CER register value */
  tmpccer =  LL_PWM_ReadReg(PWMx, CER);

  /* Get the PWMx CMR register value */
  tmpccmr2 = LL_PWM_ReadReg(PWMx, CMR);

  /* Select the Output Compare Mode */
  MODIFY_REG(tmpccmr2, PWM_CMR_OC3M, PWM_OCInitStruct->OCMode << PWM_CMR_OC3M_Pos);

  /* Set the Output Compare Polarity */
  MODIFY_REG(tmpccer, PWM_CER_C3P, PWM_OCInitStruct->OCPolarity << 8U);

  /* Set the Output State */
  MODIFY_REG(tmpccer, PWM_CER_C3E, PWM_OCInitStruct->OCState << 8U);

  /* Write to PWMx CMR */
  LL_PWM_WriteReg(PWMx, CMR, tmpccmr2);

  /* Set the Compare Register value */
  LL_PWM_ClearFlag_CCR3OK(PWMx);
  LL_PWM_OC_SetCompareCH3(PWMx, PWM_OCInitStruct->CompareValue);
  if((LL_PWM_IsEnabledExternalClock(PWMx))
    && ((LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_SYS_CLK) || (LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_GPIO_HS)))
  {
    LL_RCC_GetSystemClocksFreq(&rcc_clock);
    /* Polling on CCR3 write ok status after above restore operation */
    do
    {
      rcc_clock.SYSCLK_Frequency--; /* Used for timeout */
    }
    while (((LL_PWM_IsActiveFlag_CCR3OK(PWMx) != 1UL)) && ((rcc_clock.SYSCLK_Frequency) > 0UL));
  }

  /* Write to PWMx CER */
  LL_PWM_WriteReg(PWMx, CER, tmpccer);

  return SUCCESS;
}

/**
  * @brief  Configure the PWMx output channel 4.
  * @param  PWMx Pwm Instance
  * @param  PWM_OCInitStruct pointer to the the PWMx output channel 4 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PWMx registers are de-initialized
  *          - ERROR: not applicable
  */
static ErrorStatus OC4Config(PWM_TypeDef *PWMx, LL_PWM_OC_InitTypeDef *PWM_OCInitStruct)
{
  LL_RCC_ClocksTypeDef rcc_clock;
  uint32_t tmpccmr2;
  uint32_t tmpccer;

  /* Check the parameters */
  assert_param(IS_PWM_OC4_INSTANCE(PWMx));
  assert_param(IS_LL_PWM_OCMODE(PWM_OCInitStruct->OCMode));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCState));
  assert_param(IS_LL_PWM_OCPOLARITY(PWM_OCInitStruct->OCPolarity));
  assert_param(IS_LL_PWM_OCSTATE(PWM_OCInitStruct->OCNState));

  /* Disable the Channel 4: Reset the C4E Bit */
  CLEAR_BIT(PWMx->CER, PWM_CER_C4E);

  /* Get the PWMx CER register value */
  tmpccer = LL_PWM_ReadReg(PWMx, CER);

  /* Get the PWMx CMR register value */
  tmpccmr2 = LL_PWM_ReadReg(PWMx, CMR);

  /* Select the Output Compare Mode */
  MODIFY_REG(tmpccmr2, PWM_CMR_OC4M, PWM_OCInitStruct->OCMode << PWM_CMR_OC4M_Pos);

  /* Set the Output Compare Polarity */
  MODIFY_REG(tmpccer, PWM_CER_C4P, PWM_OCInitStruct->OCPolarity << 12U);

  /* Set the Output State */
  MODIFY_REG(tmpccer, PWM_CER_C4E, PWM_OCInitStruct->OCState << 12U);

  /* Write to PWMx CMR */
  LL_PWM_WriteReg(PWMx, CMR, tmpccmr2);

  /* Set the Compare Register value */
  LL_PWM_ClearFlag_CCR4OK(PWMx);
  LL_PWM_OC_SetCompareCH4(PWMx, PWM_OCInitStruct->CompareValue);
  if((LL_PWM_IsEnabledExternalClock(PWMx))
    && ((LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_SYS_CLK) || (LL_PWM_GetETRSource(PWMx) == LL_PWM_PWM_ETRSOURCE_GPIO_HS)))
  {
    LL_RCC_GetSystemClocksFreq(&rcc_clock);
    /* Polling on CCR4 write ok status after above restore operation */
    do
    {
      rcc_clock.SYSCLK_Frequency--; /* Used for timeout */
    }
    while (((LL_PWM_IsActiveFlag_CCR4OK(PWMx) != 1UL)) && ((rcc_clock.SYSCLK_Frequency) > 0UL));
  }

  /* Write to PWMx CER */
  LL_PWM_WriteReg(PWMx, CER, tmpccer);

  return SUCCESS;
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* PWM */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
