/**
  ******************************************************************************
  * @file   py32c882_hal_rcc_ex.c
  * @author  MCU Application Team
  * @brief   Extended RCC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities RCC extended peripheral:
  *           + Extended Peripheral Control functions
  *           + Extended Clock management functions
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

#ifdef HAL_RCC_MODULE_ENABLED

/** @defgroup RCCEx RCCEx
  * @brief RCC Extension HAL module driver.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup RCCEx_Private_Constants RCCEx Private Constants
  * @{
  */
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup RCCEx_Private_Macros RCCEx Private Macros
  * @{
  */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static uint32_t RCCEx_GetPLLClockFreq(void);
/* Private functions ---------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Functions RCCEx Exported Functions
  * @{
  */

/** @defgroup RCCEx_Exported_Functions_Group1 Peripheral Control functions
  *  @brief  Extended Peripheral Control functions
  *
@verbatim
 ===============================================================================
                ##### Extended Peripheral Control functions  #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the RCC Clocks
    frequencies.
    [..]
    (@) Important note: Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to
        select the RTC clock source; in this case the Backup domain will be reset in
        order to modify the RTC Clock source, as consequence RTC registers (including
        the backup registers) are set to their reset values.

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the RCC extended peripherals clocks according to the specified parameters in the
  *         RCC_PeriphCLKInitTypeDef.
  * @param  PeriphClkInit pointer to an RCC_PeriphCLKInitTypeDef structure that
  *         contains the configuration information for the Extended Peripherals clocks(RTC clock).
  *
  * @note   Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select
  *         the RTC clock source; in this case the Backup domain will be reset in
  *         order to modify the RTC Clock source, as consequence RTC registers (including
  *         the backup registers) are set to their reset values.
  *
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  uint32_t tickstart = 0U, temp_reg = 0U;

  /* Check the parameters */
  assert_param(IS_RCC_PERIPHCLOCK(PeriphClkInit->PeriphClockSelection));

  /*------------------------------- RTC Configuration ------------------------*/
  if ((((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_RTC) == RCC_PERIPHCLK_RTC))
  {
    /* check for RTC Parameters used to output RTCCLK */
    assert_param(IS_RCC_RTCCLKSOURCE(PeriphClkInit->RTCClockSelection));

    FlagStatus       pwrclkchanged = RESET;

    /* As soon as function is called to change RTC clock source, activation of the
       power domain is done. */
    /* Requires to enable write access to Backup Domain of necessary */
    if (__HAL_RCC_PWR_IS_CLK_DISABLED())
    {
      __HAL_RCC_PWR_CLK_ENABLE();
      pwrclkchanged = SET;
    }

    if (HAL_IS_BIT_CLR(PWR->CR1, PWR_CR1_DBP))
    {
      /* Enable write access to Backup domain */
      SET_BIT(PWR->CR1, PWR_CR1_DBP);

      /* Wait for Backup domain Write protection disable */
      tickstart = HAL_GetTick();

      while (HAL_IS_BIT_CLR(PWR->CR1, PWR_CR1_DBP))
      {
        if ((HAL_GetTick() - tickstart) > RCC_DBP_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }

    /* Reset the Backup domain only if the RTC Clock source selection is modified from reset value */
    temp_reg = (RCC->BDCR & RCC_BDCR_RTCSEL);
    if ((temp_reg != 0x00000000U) && (temp_reg != (PeriphClkInit->RTCClockSelection & RCC_BDCR_RTCSEL)))
    {
      /* Store the content of BDCR register before the reset of Backup Domain */
      temp_reg = (RCC->BDCR & ~(RCC_BDCR_RTCSEL));
      /* RTC Clock selection can be changed only if the Backup Domain is reset */
      __HAL_RCC_BACKUPRESET_FORCE();
      __HAL_RCC_BACKUPRESET_RELEASE();
      /* Restore the Content of BDCR register */
      RCC->BDCR = temp_reg;

      /* Wait for LSIRDY if LSI was enabled */
      if (READ_BIT(temp_reg, RCC_BDCR_LSION) == RCC_LSI_ON)
      {
        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till LSI is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
#if defined(RCC_LSE_SUPPORT)
      /* Wait for LSERDY if LSE was enabled */
      if (READ_BIT(temp_reg, RCC_BDCR_LSEEN) == RCC_LSE_ON)
      {
        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till LSE is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
#endif
    }
    __HAL_RCC_RTC_CONFIG(PeriphClkInit->RTCClockSelection);

    /* Require to disable power clock if necessary */
    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }

  /*------------------------------- IWDG Configuration ------------------------*/
  if ((((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_IWDG) == RCC_PERIPHCLK_IWDG))
  {
    /* check for IWDG Parameters used to output IWDGCLK */
    assert_param(IS_RCC_IWDGCLKSOURCE(PeriphClkInit->IwdgClockSelection));

    FlagStatus       pwrclkchanged = RESET;

    /* As soon as function is called to change RTC clock source, activation of the
       power domain is done. */
    /* Requires to enable write access to Backup Domain of necessary */
    if (__HAL_RCC_PWR_IS_CLK_DISABLED())
    {
      __HAL_RCC_PWR_CLK_ENABLE();
      pwrclkchanged = SET;
    }

    if (HAL_IS_BIT_CLR(PWR->CR1, PWR_CR1_DBP))
    {
      /* Enable write access to Backup domain */
      SET_BIT(PWR->CR1, PWR_CR1_DBP);

      /* Wait for Backup domain Write protection disable */
      tickstart = HAL_GetTick();

      while (HAL_IS_BIT_CLR(PWR->CR1, PWR_CR1_DBP))
      {
        if ((HAL_GetTick() - tickstart) > RCC_DBP_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }

    __HAL_RCC_IWDG_CONFIG(PeriphClkInit->IwdgClockSelection);

    /* Require to disable power clock if necessary */
    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }

#if defined(RCC_CCIPR_CANSEL)
  /*------------------------------ CAN clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_CAN) == RCC_PERIPHCLK_CAN)
  {
    /* Check the parameters */
    assert_param(IS_RCC_CANCLKSOURCE(PeriphClkInit->CanClockSelection));

    /* Configure the CAN clock source */
    __HAL_RCC_CAN_CONFIG(PeriphClkInit->CanClockSelection);
  }
#endif /* RCC_CCIPR_CANSEL */
  
  /*------------------------------ PVD clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_PVD) == RCC_PERIPHCLK_PVD)
  {
    /* Check the parameters */
    assert_param(IS_RCC_PVDDETECTCLKSOURCE(PeriphClkInit->PvdDetectClockSelection));

    /* Configure the PVD detect clock source */
    __HAL_RCC_PVD_CONFIG(PeriphClkInit->PvdDetectClockSelection);
  }
  
  /*------------------------------ COMP1 clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_COMP1) == RCC_PERIPHCLK_COMP1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_COMP1CLKSOURCE(PeriphClkInit->Comp1ClockSelection));

    /* Configure the COMP1 clock source */
    __HAL_RCC_COMP1_CONFIG(PeriphClkInit->Comp1ClockSelection);
  }
  
  /*------------------------------ COMP2 clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_COMP2) == RCC_PERIPHCLK_COMP2)
  {
    /* Check the parameters */
    assert_param(IS_RCC_COMP2CLKSOURCE(PeriphClkInit->Comp2ClockSelection));

    /* Configure the COMP2 clock source */
    __HAL_RCC_COMP2_CONFIG(PeriphClkInit->Comp2ClockSelection);
  }
  
  /*------------------------------ LPUART1 clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_LPUART1) == RCC_PERIPHCLK_LPUART1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LPUART1CLKSOURCE(PeriphClkInit->Lpuart1ClockSelection));

    /* Configure the LPUART1 clock source */
    __HAL_RCC_LPUART1_CONFIG(PeriphClkInit->Lpuart1ClockSelection);
  }
  
  /*------------------------------ LPUART2 clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_LPUART2) == RCC_PERIPHCLK_LPUART2)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LPUART2CLKSOURCE(PeriphClkInit->Lpuart2ClockSelection));

    /* Configure the LPUART1 clock source */
    __HAL_RCC_LPUART2_CONFIG(PeriphClkInit->Lpuart2ClockSelection);
  }
  
  /*------------------------------ LPTIM1 clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_LPTIM1) == RCC_PERIPHCLK_LPTIM1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LPTIM1CLKSOURCE(PeriphClkInit->Lptim1ClockSelection));

    /* Configure the LPTIM1 clock source */
    __HAL_RCC_LPTIM1_CONFIG(PeriphClkInit->Lptim1ClockSelection);
  }
  
  /*------------------------------ LPTIM2 clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_LPTIM2) == RCC_PERIPHCLK_LPTIM2)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LPTIM2CLKSOURCE(PeriphClkInit->Lptim2ClockSelection));

    /* Configure the LPTIM2 clock source */
    __HAL_RCC_LPTIM2_CONFIG(PeriphClkInit->Lptim2ClockSelection);
  }
  
  /*------------------------------ ADC clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC) == RCC_PERIPHCLK_ADC)
  {
    /* Check the parameters */
    assert_param(IS_RCC_ADCCLKSOURCE(PeriphClkInit->AdcClockSelection));

    /* Configure the ADC clock source */
    __HAL_RCC_ADC_CONFIG(PeriphClkInit->AdcClockSelection);
  }
  
  return HAL_OK;
}

/**
  * @brief  Get the PeriphClkInit according to the internal
  *         RCC configuration registers.
  * @param  PeriphClkInit pointer to an RCC_PeriphCLKInitTypeDef structure that
  *         returns the configuration information for the Extended Peripherals clocks(RTC, CAN, PVD ... clocks).
  * @retval None
  */
void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  /* Set all possible values for the extended clock type parameter------------*/
  PeriphClkInit->PeriphClockSelection = RCC_PERIPHCLK_RTC;
  /* Source clock is LSE, LSI, or HSE_DIV32*/
  PeriphClkInit->RTCClockSelection = __HAL_RCC_GET_RTC_SOURCE();

  /* Get the IWDG clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_IWDG;
  PeriphClkInit->IwdgClockSelection = __HAL_RCC_GET_IWDG_SOURCE();

#if defined(RCC_CCIPR_CANSEL)
  /* Get the CAN clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_CAN;
  PeriphClkInit->CanClockSelection = __HAL_RCC_GET_CAN_SOURCE();
#endif /* RCC_CCIPR_CANSEL */
  
  /* Get the PVD detect clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_PVD;
  PeriphClkInit->PvdDetectClockSelection = __HAL_RCC_GET_PVD_DETECT_SOURCE();
  
  /* Get the COMP1 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_COMP1;
  PeriphClkInit->Comp1ClockSelection = __HAL_RCC_GET_COMP1_SOURCE();
  
  /* Get the COMP2 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_COMP2;
  PeriphClkInit->Comp2ClockSelection = __HAL_RCC_GET_COMP2_SOURCE();
  
  /* Get the LPUART1 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_LPUART1;
  PeriphClkInit->Lpuart1ClockSelection = __HAL_RCC_GET_LPUART1_SOURCE();
  
  /* Get the LPUART2 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_LPUART2;
  PeriphClkInit->Lpuart2ClockSelection = __HAL_RCC_GET_LPUART2_SOURCE();
  
  /* Get the LPTIM1 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_LPTIM1;
  PeriphClkInit->Lptim1ClockSelection = __HAL_RCC_GET_LPTIM1_SOURCE();
  
  /* Get the LPTIM2 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_LPTIM2;
  PeriphClkInit->Lptim2ClockSelection = __HAL_RCC_GET_LPTIM2_SOURCE();
  
  /* Get the ADC clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_ADC;
  PeriphClkInit->AdcClockSelection = __HAL_RCC_GET_ADC_SOURCE();
}

/**
  * @brief  Returns the peripheral clock frequency
  * @note   Returns 0 if peripheral clock is unknown
  * @param  PeriphClk Peripheral clock identifier
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_PERIPHCLK_RTC      RTC peripheral clock
  *            @arg @ref RCC_PERIPHCLK_IWDG     IWDG peripheral clock
  *            @arg @ref RCC_PERIPHCLK_CAN      CAN peripheral clock
  *            @arg @ref RCC_PERIPHCLK_PVD      PVD peripheral clock
  *            @arg @ref RCC_PERIPHCLK_COMP1    COMP1 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_COMP2    COMP2 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_LPUART1  LPUART1 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_LPUART2  LPUART2 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_LPTIM1   LPUART1 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_LPTIM2   LPTIM2 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_ADC      ADC peripheral clock
  * @retval Frequency in Hz (0: means that no available frequency for the peripheral)
  */
uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk)
{
  uint32_t srcclk = 0U, temp_reg = 0U, frequency = 0U, hsiIndex = 0U;
  
  const uint32_t hsiValue[8] = {8000000,8000000,16000000,22120000,24000000,48000000,64000000,8000000};

  /* Check the parameters */
  assert_param(IS_RCC_PERIPHCLOCK(PeriphClk));

  switch (PeriphClk)
  {
    case RCC_PERIPHCLK_RTC:
    {
      /* Get RCC BDCR configuration ------------------------------------------------------*/
      temp_reg = RCC->BDCR;


      /* Check if LSI is ready if RTC clock selection is LSI */
      if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_LSI) && (HAL_IS_BIT_SET(temp_reg, RCC_BDCR_LSIRDY)))
      {
        frequency = LSI_VALUE;
      }
#if defined(RCC_LSE_SUPPORT)
      /* Check if LSE is ready if RTC clock selection is LSE */
      else if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_LSE) && (HAL_IS_BIT_SET(temp_reg, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
#endif
#if defined(RCC_HSE_SUPPORT)
      else if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_HSE_DIV32) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSERDY)))
      {
        frequency = HSE_VALUE / 32U;
      }
#endif
      /* Clock not enabled for RTC*/
      else
      {
        /* nothing to do: frequency already initialized to 0U */
      }
      break;
    }
    case RCC_PERIPHCLK_IWDG:
    {
      /* Get the current IWDG source */
      srcclk = __HAL_RCC_GET_IWDG_SOURCE();
      
      if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (srcclk == RCC_IWDGCLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
#if defined(RCC_LSE_SUPPORT)
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_IWDGCLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
#endif
      /* Clock not enabled for LPUART1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
#if defined(RCC_CCIPR_CANSEL)
    case RCC_PERIPHCLK_CAN:
    {
      /* Get the current CAN source */
      srcclk = __HAL_RCC_GET_CAN_SOURCE();
      
      if (srcclk == RCC_CANCLKSOURCE_PLL)
      {
        frequency = RCCEx_GetPLLClockFreq();
      }
      else if (srcclk == RCC_CANCLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
#if defined(RCC_HSE_SUPPORT)
      else if ((HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSERDY)) && (srcclk == RCC_CANCLKSOURCE_HSE))
      {
        frequency = HSE_VALUE;
      }
#endif
      /* Clock not enabled for CAN */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
#endif /* RCC_CCIPR_CANSEL */

    case RCC_PERIPHCLK_PVD:
    {
      /* Get the current PVD source */
      srcclk = __HAL_RCC_GET_PVD_DETECT_SOURCE();
      
      if (srcclk == RCC_PVDDETECTCLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
      else if (srcclk == RCC_PVDDETECTCLKSOURCE_LSC)
      {
        if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (HAL_IS_BIT_CLR(RCC->BDCR, RCC_BDCR_LSCSEL)))
        {
          frequency = LSI_VALUE;
        }
#if defined(RCC_LSE_SUPPORT)
        else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSCSEL)))
        {
          frequency = LSE_VALUE;
        }
#endif
        else
        {
          /* nothing to do: frequency already initialized to 0 */
        }
      }
      /* Clock not enabled for PVD */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_COMP1:
    {
      /* Get the current COMP1 source */
      srcclk = __HAL_RCC_GET_COMP1_SOURCE();
      
      if (srcclk == RCC_COMP1CLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
      else if (srcclk == RCC_COMP1CLKSOURCE_LSC)
      {
        if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (HAL_IS_BIT_CLR(RCC->BDCR, RCC_BDCR_LSCSEL)))
        {
          frequency = LSI_VALUE;
        }
#if defined(RCC_LSE_SUPPORT)
        else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSCSEL)))
        {
          frequency = LSE_VALUE;
        }
#endif
        else
        {
          /* nothing to do: frequency already initialized to 0 */
        }
      }
      /* Clock not enabled for COMP1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_COMP2:
    {
      /* Get the current COMP2 source */
      srcclk = __HAL_RCC_GET_COMP2_SOURCE();
      
      if (srcclk == RCC_COMP2CLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
      else if (srcclk == RCC_COMP2CLKSOURCE_LSC)
      {
        if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (HAL_IS_BIT_CLR(RCC->BDCR, RCC_BDCR_LSCSEL)))
        {
          frequency = LSI_VALUE;
        }
#if defined(RCC_LSE_SUPPORT)
        else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSCSEL)))
        {
          frequency = LSE_VALUE;
        }
#endif
        else
        {
          /* nothing to do: frequency already initialized to 0 */
        }
      }
      /* Clock not enabled for COMP2 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_LPUART1:
    {
      /* Get the current LPUART1 source */
      srcclk = __HAL_RCC_GET_LPUART1_SOURCE();
      
      if (srcclk == RCC_LPUART1CLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
      else if (srcclk == RCC_LPUART1CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (srcclk == RCC_LPUART1CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
#if defined(RCC_LSE_SUPPORT)
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_LPUART1CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
#endif
      /* Clock not enabled for LPUART1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_LPUART2:
    {
      /* Get the current LPUART2 source */
      srcclk = __HAL_RCC_GET_LPUART2_SOURCE();
      
      if (srcclk == RCC_LPUART2CLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
      else if (srcclk == RCC_LPUART2CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (srcclk == RCC_LPUART2CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
#if defined(RCC_LSE_SUPPORT)
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_LPUART2CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
#endif
      /* Clock not enabled for LPUART2 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_LPTIM1:
    {
      /* Get the current LPTIM1 source */
      srcclk = __HAL_RCC_GET_LPTIM1_SOURCE();
      
      if (srcclk == RCC_LPTIM1CLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (srcclk == RCC_LPTIM1CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
#if defined(RCC_LSE_SUPPORT)
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_LPTIM1CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
#endif
      /* Clock not enabled for LPTIM1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_LPTIM2:
    {
      /* Get the current LPTIM2 source */
      srcclk = __HAL_RCC_GET_LPTIM2_SOURCE();
      
      if (srcclk == RCC_LPTIM2CLKSOURCE_PCLK)
      {
        frequency = HAL_RCC_GetPCLKFreq();
      }
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSIRDY)) && (srcclk == RCC_LPTIM2CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
#if defined(RCC_LSE_SUPPORT)
      else if ((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_LPTIM2CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
#endif
      /* Clock not enabled for LPTIM1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_ADC:
    {
      /* Get the current ADC source */
      srcclk = __HAL_RCC_GET_ADC_SOURCE();
      
      if (srcclk == RCC_ADCCLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      else if ((HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)) && (srcclk == RCC_ADCCLKSOURCE_PLL))
      {
        frequency = RCCEx_GetPLLClockFreq();
      }
      else if ((HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)) && (srcclk == RCC_ADCCLKSOURCE_HSI))
      {
        hsiIndex = (RCC->ICSCR & RCC_ICSCR_HSI_FS_OPCR_Msk) >> RCC_ICSCR_HSI_FS_OPCR_Pos;
        frequency = hsiValue[hsiIndex];
      }
      /* Clock not enabled for ADC */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
  }
  
  return (frequency);
}

/**
  * @brief  Set the Low Speed clock source.
  * @param  LSCSource  specifies the Low Speed clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LSCSOURCE_LSI  LSI clock selected as LSC source
  *            @arg @ref RCC_LSCSOURCE_LSE  LSE clock selected as LSC source
  * @retval None
  */
void HAL_RCCEx_SetLSCSource(uint32_t LSCSource)
{
  FlagStatus       pwrclkchanged = RESET;
  FlagStatus       backupchanged = RESET;
  
  /* Check the parameters */
  assert_param(IS_RCC_LSCSOURCE(LSCSource));

  /* Update LSCOSEL clock source in Backup Domain control register */
  if (__HAL_RCC_PWR_IS_CLK_DISABLED())
  {
    __HAL_RCC_PWR_CLK_ENABLE();
    pwrclkchanged = SET;
  }
  if (HAL_IS_BIT_CLR(PWR->CR1, PWR_CR1_DBP))
  {

    HAL_PWR_EnableBkUpAccess();
    backupchanged = SET;
  }

  MODIFY_REG(RCC->BDCR, RCC_BDCR_LSCSEL, LSCSource);

  if (backupchanged == SET)
  {
    HAL_PWR_DisableBkUpAccess();
  }
  if (pwrclkchanged == SET)
  {
    __HAL_RCC_PWR_CLK_DISABLE();
  }
}

/**
  * @brief  Get the Low Speed clock source.
  * @retval Returned value can be one of the following values:
  *         @arg @ref RCC_LSCSOURCE_LSI
  *         @arg @ref RCC_LSCSOURCE_LSE
  */
uint32_t HAL_RCCEx_GetLSCSource(void)
{
  uint32_t         LSCSource;

  LSCSource = READ_BIT(RCC->BDCR, RCC_BDCR_LSCSEL);

  return LSCSource;
}

/**
  * @brief  Returns the PLL clock frequencies.
  * @note   The function returns values based on HSE_VALUE or HSI_VALUE multiplied by the PLL
  *         factors.
  * @note   This function can be used by the user application to compute the
  *         baud-rate for the communication peripherals or configure other parameters.
  * @retval Frequency in Hz
  */
static uint32_t RCCEx_GetPLLClockFreq(void)
{
  uint32_t pllsource = 0, pllmul = 0, pllvco = 0, hsiIndex = 0;
  const uint32_t hsiValue[8] = {8000000,8000000,16000000,22120000,24000000,48000000,64000000,8000000};

  pllsource = READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC);
  pllmul = (READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLMUL) >> RCC_PLLCFGR_PLLMUL_Pos) + 2U ;

  switch (pllsource)
  {
#if defined(RCC_HSE_SUPPORT)
  case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
    pllvco = (HSE_VALUE * pllmul);
    break;
#endif
  case RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source */
  default:
    hsiIndex = (RCC->ICSCR & RCC_ICSCR_HSI_FS_OPCR_Msk) >> RCC_ICSCR_HSI_FS_OPCR_Pos;
    
    /* HSI used as PLL clock source : PLLCLK = HSI * PLLMUL */
    pllvco = (uint32_t)(hsiValue[hsiIndex] * pllmul);
    break;
  }

  return pllvco;
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_RCC_MODULE_ENABLED */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

