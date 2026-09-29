/**
  ******************************************************************************
  * @file   py32c882_hal_rcc.c
  * @author  MCU Application Team
  * @brief   RCC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and Clock Control (RCC) peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *
  @verbatim
  ==============================================================================
                      ##### RCC specific features #####
  ==============================================================================
    [..]
      After reset the device is running from Internal High Speed oscillator
      (HSI 8MHz) with Flash 0 wait state, Flash prefetch buffer is enabled,
      and all peripherals are off except internal SRAM, Flash and JTAG.
      (+) There is no prescaler on High speed (AHB) and Low speed (APB) buses;
          all peripherals mapped on these buses are running at HSI speed.
      (+) The clock for all peripherals is switched off, except the SRAM and FLASH.
      (+) All GPIOs are in input floating state, except the JTAG pins which
          are assigned to be used for debug purpose.
    [..] Once the device started from reset, the user application has to:
      (+) Configure the clock source to be used to drive the System clock
          (if the application needs higher frequency/performance)
      (+) Configure the System clock frequency and Flash settings
      (+) Configure the AHB and APB buses prescalers
      (+) Enable the clock for the peripheral(s) to be used
      (+) Configure the clock source(s) for peripherals whose clocks are not
          derived from the System clock ( RTC, ADC, PVD, USB )

                      ##### RCC Limitations #####
  ==============================================================================
    [..]
      A delay between an RCC peripheral clock enable and the effective peripheral
      enabling should be taken into account in order to manage the peripheral read/write
      from/to registers.
      (+) This delay depends on the peripheral mapping.
        (++) AHB & APB peripherals, 1 dummy read is necessary

    [..]
      Workarounds:
      (#) For AHB & APB peripherals, a dummy read to the peripheral register has been
          inserted in each __HAL_RCC_PPP_CLK_ENABLE() macro.

  @endverbatim
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

/** @defgroup RCC RCC
* @brief RCC HAL module driver
  * @{
  */
#ifdef HAL_RCC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup RCC_Private_Constants RCC Private Constants
 * @{
 */
/**
  * @}
  */
/* Private macro -------------------------------------------------------------*/
/** @defgroup RCC_Private_Macros RCC Private Macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @defgroup RCC_Private_Variables RCC Private Variables
  * @{
  */
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup RCC_Private_Functions RCC Private Functions
  * @{
  */
static uint32_t          RCC_GetSysClockFreqFromPLLSource(void);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup RCC_Exported_Functions RCC Exported Functions
  * @{
  */

/** @defgroup RCC_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  @verbatim
  ===============================================================================
           ##### Initialization and de-initialization functions #####
  ===============================================================================
    [..]
      This section provides functions allowing to configure the internal/external oscillators
      (HSE, HSI, LSE, LSI, MSI, PLL, CSS and MCO) and the System buses clocks (SYSCLK, AHB, APB).

    [..] Internal/external clock and PLL configuration
      (#) HSI (high-speed internal), 8 to 64 MHz factory-trimmed RC used directly or through
          the PLL as System clock source.
      (#) LSI (low-speed internal), ~30 KHz low consumption RC used as IWDG and/or RTC
          clock source.

      (#) HSE (high-speed external), 4 to 32 MHz (PY32C882xx) crystal oscillator used directly or
          through the PLL as System clock source. Can be used also as RTC clock source.

      (#) LSE (low-speed external), 32 KHz oscillator used as RTC clock source.

      (#) MSI 2 MHz RC used directly as System clock source.

      (#) PLL (clocked by HSI or HSE), featuring different output clocks:
        (++) The first output is used to generate the high speed system clock

      (#) CSS (Clock security system), once enable using the function HAL_RCC_EnableCSS()
          and if a HSE clock failure occurs(HSE used directly or through PLL as System
          clock source), the System clocks automatically switched to HSI and an interrupt
          is generated if enabled. The interrupt is linked to the Cortex-M0+ NMI
          (Non-Maskable Interrupt) exception vector.

      (#) MCO (microcontroller clock output), used to output SYSCLK, HSI10M, HSI, HSE, PLL
          LSI, LSE, HCLK, PCLK, MSI, or LCD_HSI10M on PA14 pin

    [..] System, AHB and APB buses clocks configuration
      (#) Several clock sources can be used to drive the System clock (SYSCLK): HSI, LSI, LSE, MSI,
          HSE and PLL.
          The AHB clock (HCLK) is derived from System clock through configurable
          prescaler and used to clock the CPU, memory and peripherals mapped
          on AHB bus (DMA,...) and APB (PCLK) clocks are derived
          from AHB clock through configurable prescalers and used to clock
          the peripherals mapped on these buses. You can use
          "@ref HAL_RCC_GetSysClockFreq()" function to retrieve the frequencies of these clocks.

      -@- All the peripheral clocks are derived from the System clock (SYSCLK) except:
          (+@) RTC: RTC clock can be derived either from the LSI, LSE or HSE clock
              divided by 32.
          (+@) IWDG clock can be derived either from the LSI, LSE.
          (+@) LCD clock can be derived either from the LSI, LSE.
          ...

      (#) For PY32C882xx, the maximum frequency of the SYSCLK and HCLK is 96 MHz.
          Depending on the SYSCLK frequency, the flash latency should be adapted accordingly.
  @endverbatim
  * @{
  */

/*
  Additional consideration on the SYSCLK based on Latency settings:
        +-----------------------------------------------+
        | Latency       | SYSCLK clock frequency (MHz)  |
        |---------------|-------------------------------|
        |0WS(1CPU cycle)|       0 < SYSCLK <= 24        |
        |---------------|-------------------------------|
        |1WS(2CPU cycle)|      24 < SYSCLK <= 48        |
        |---------------|-------------------------------|
        |2WS(3CPU cycle)|      48 < SYSCLK <= 72        |
        |---------------|-------------------------------|
        |4WS(5CPU cycle)|      72 < SYSCLK <= 96        |
        +-----------------------------------------------+

  */

/**
  * @brief  Resets the RCC clock configuration to the default reset state.
  * @note   The default reset state of the clock configuration is given below:
  *            - HSI ON and used as system clock source
  *            - HSE, PLL, MSI, are OFF
  *            - AHB, APB prescaler set to 1.
  *            - CSS and MCO OFF
  *            - All interrupts disabled
  *            - All flags are cleared
  * @note   This function does not modify the configuration of the
  *            - Peripheral clocks
  *            - LSI, LSE and RTC clocks
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_RCC_DeInit(void)
{
  uint32_t tickstart;

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Set HSION bit */
  SET_BIT(RCC->CR, RCC_CR_HSION);

  /* Wait till HSI is ready */
  while (READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RESET)
  {
    if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Set the HSI clock to 8MHz by default */
  __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_HSICALIBRATION_8MHz);
  
  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Reset CFGR register */
  CLEAR_REG(RCC->CFGR);

  /* Wait till HSI is ready */
  while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_HSISYS)
  {
    if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = HSI_VALUE;

  /* Adapt Systick interrupt period */
  if (HAL_InitTick(uwTickPrio) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Clear CR register in 2 steps: first to clear HSEON in case bypass was enabled */
  RCC->CR = RCC_CR_HSION;

  /* Then again to HSEBYP in case bypass was enabled */
  RCC->CR = RCC_CR_HSION;
  
  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Wait till PLL is disabled */
  while (READ_BIT(RCC->CR, RCC_CR_PLLRDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* once PLL is OFF, reset PLLCFGR register to default value */
  CLEAR_REG(RCC->PLLCFGR);

  /* Disable all interrupts */
  CLEAR_REG(RCC->CIER);

  /* Clear all interrupt flags */
  WRITE_REG(RCC->CICR, 0xFFFFFFFFU);

  /* Clear all reset flags */
  SET_BIT(RCC->CSR, RCC_CSR_RMVF);

  return HAL_OK;
}

/**
  * @brief  Initializes the RCC Oscillators according to the specified parameters in the
  *         RCC_OscInitTypeDef.
  * @param  RCC_OscInitStruct pointer to an RCC_OscInitTypeDef structure that
  *         contains the configuration information for the RCC Oscillators.
  * @note   The PLL is not disabled when used as system clock.
  * @note   Transitions LSE Bypass to LSE On and LSE On to LSE Bypass are not
  *         supported by this function. User should request a transition to LSE Off
  *         first and then LSE On or LSE Bypass.
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not
  *         supported by this function. User should request a transition to HSE Off
  *         first and then HSE On or HSE Bypass.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  uint32_t tickstart;
  uint32_t pll_config;
  FlagStatus pwrclkchanged = RESET;

  /* Check Null pointer */
  if (RCC_OscInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_RCC_OSCILLATORTYPE(RCC_OscInitStruct->OscillatorType));
#if defined(RCC_HSE_SUPPORT)
  /*------------------------------- HSE Configuration ------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSE(RCC_OscInitStruct->HSEState));
    assert_param(IS_RCC_HSE_FREQ(RCC_OscInitStruct->HSEFreq));

    /* When the HSE is used as system clock or clock source for PLL in these cases it is not allowed to be disabled */
    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSE) \
        || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) \
            && ((__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE))))
    {
      if ((__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET) && (RCC_OscInitStruct->HSEState == RCC_HSE_OFF))
      {
        return HAL_ERROR;
      }
    }
    else
    {
      if (RCC_OscInitStruct->HSEState == RCC_HSE_ON)
      {
        assert_param(IS_RCC_HSE_FREQ(RCC_OscInitStruct->HSEFreq));

        __HAL_RCC_HSE_CONFIG(RCC_HSE_OFF);
        
        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till HSE is off */
        while (READ_BIT(RCC->CR, RCC_CR_HSERDY) == SET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
        
        /*Set HSE Driver*/
        __HAL_RCC_HSE_FREQ_CONFIG(RCC_OscInitStruct->HSEFreq);
      }
      
      /* Set the new HSE configuration ---------------------------------------*/
      __HAL_RCC_HSE_CONFIG(RCC_OscInitStruct->HSEState);

      /* Check the HSE State */
      if (RCC_OscInitStruct->HSEState != RCC_HSE_OFF)
      {
#ifndef RCC_NO_DETECT_HSE_READY
        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSE is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
#endif
      }
      else
      {
        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSE is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
#endif
  /*----------------------------- HSI Configuration --------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSI(RCC_OscInitStruct->HSIState));
    assert_param(IS_RCC_HSI_CALIBRATION_VALUE(RCC_OscInitStruct->HSICalibrationValue));
    assert_param(IS_RCC_HSIDIV(RCC_OscInitStruct->HSIDiv));

    /* Check if HSI is used as system clock or as PLL source when PLL is selected as system clock */
    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSISYS) \
        || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) \
            && ((__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSI))))
    {
      /* When HSI is used as system clock it will not disabled */
      if ((__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET) && (RCC_OscInitStruct->HSIState != RCC_HSI_ON))
      {
        return HAL_ERROR;
      }
      /* Otherwise, just the calibration is allowed */
      else
      {
        /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
        __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_3);
        
        if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSISYS))
        {
          /* Adjust the HSI division factor */
          __HAL_RCC_HSI_CONFIG(RCC_OscInitStruct->HSIDiv);
        }
        
        /* Adjusts the Internal High Speed oscillator (HSI) calibration value.*/
        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);

        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till HSI is ready */
        while (READ_BIT(RCC->CR, RCC_CR_HSIRDY) == 0U)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        /* Update the SystemCoreClock global variable */
        SystemCoreClock = (HAL_RCC_GetSysClockFreq() >> ((AHBPrescTable[(RCC->CFGR & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos]) & 0x1FU));

        if ((SystemCoreClock > AHB_48MHZ) && (SystemCoreClock <= AHB_72MHZ))
        {
          __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_2);
        }
        else if ((SystemCoreClock > AHB_24MHZ) && (SystemCoreClock <= AHB_48MHZ))
        {
          __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_1);
        }
        else if (SystemCoreClock <= AHB_24MHZ)
        {
          __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_0);
        }
        
        /* Adapt Systick interrupt period */
        if (HAL_InitTick(uwTickPrio) != HAL_OK)
        {
          return HAL_ERROR;
        }
      }
    }
    else
    {
      /* Check the HSI State */
      if (RCC_OscInitStruct->HSIState != RCC_HSI_OFF)
      {
        /* Adjust the HSI division factor */
        __HAL_RCC_HSI_CONFIG(RCC_OscInitStruct->HSIDiv);
        
        /* Enable the Internal High Speed oscillator (HSI). */
        __HAL_RCC_HSI_ENABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSI is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
        
        /* Adjusts the Internal High Speed oscillator (HSI) calibration value.*/
        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
      }
      else
      {
        /* Disable the Internal High Speed oscillator (HSI). */
        __HAL_RCC_HSI_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSI is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  
  /*------------------------------ LSI Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LSI(RCC_OscInitStruct->LSIState));

    /* When the LSI is used as system clock, it is not allowed disable it */
    if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR_SWS_LSI)
    {
      if ((((RCC->BDCR) & RCC_BDCR_LSIRDY) != 0U) && (RCC_OscInitStruct->LSIState == RCC_LSI_OFF))
      {
        return HAL_ERROR;
      }
    }
    else
    {
      /* Update LSI configuration in Backup Domain control register    */
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
      
      /* Check the LSI State */
      if (RCC_OscInitStruct->LSIState != RCC_LSI_OFF)
      {
        /* Enable the Internal Low Speed oscillator (LSI). */
        __HAL_RCC_LSI_ENABLE();

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
      else
      {
        /* Disable the Internal Low Speed oscillator (LSI). */
        __HAL_RCC_LSI_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till LSI is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      
      /* Require to disable power clock if necessary */
      if (pwrclkchanged == SET)
      {
        __HAL_RCC_PWR_CLK_DISABLE();
        pwrclkchanged = RESET;
      }
    }
  }
#if defined(RCC_LSE_SUPPORT)
  /*------------------------------ LSE Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LSE(RCC_OscInitStruct->LSEState));
    assert_param(IS_RCC_LSE_DRIVER(RCC_OscInitStruct->LSEDriver));

    /* When the LSE is used as system clock, it is not allowed disable it */
    if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR_SWS_LSE)
    {
      if ((((RCC->BDCR) & RCC_BDCR_LSERDY) != 0U) && (RCC_OscInitStruct->LSEState == RCC_LSE_OFF))
      {
        return HAL_ERROR;
      }
    }
    else
    {
      /* Update LSE configuration in Backup Domain control register    */
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
      
      if (RCC_OscInitStruct->LSEState == RCC_LSE_ON)
      {
        __HAL_RCC_LSE_CONFIG(RCC_LSE_OFF);
        
        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till LSE is off */
        while (READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == SET)
        {
          if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
        /*Set LSE Driver*/
        __HAL_RCC_LSE_DRIVER_CONFIG(RCC_OscInitStruct->LSEDriver);
      }

      /* Set the new LSE configuration -----------------------------------------*/
      __HAL_RCC_LSE_CONFIG(RCC_OscInitStruct->LSEState);
      /* Check the LSE State */
      if (RCC_OscInitStruct->LSEState != RCC_LSE_OFF)
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
      else
      {
        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till LSE is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }

      /* Require to disable power clock if necessary */
      if (pwrclkchanged == SET)
      {
        __HAL_RCC_PWR_CLK_DISABLE();
      }
    }
  }
#endif
  /*----------------------------- MSI Configuration --------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_MSI) == RCC_OSCILLATORTYPE_MSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_MSI(RCC_OscInitStruct->MSIState));
    assert_param(IS_RCC_MSIDIV(RCC_OscInitStruct->MSIDiv));

    /* Check if MSI is used as system clock */
    if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR_SWS_MSISYS)
    {
      /* When MSI is used as system clock it will not disabled */
      if ((__HAL_RCC_GET_FLAG(RCC_FLAG_MSIRDY) != RESET) && (RCC_OscInitStruct->MSIState != RCC_MSI_ON))
      {
        return HAL_ERROR;
      }
      else
      {
        /* Adjust the MSI division factor */
        __HAL_RCC_MSI_CONFIG(RCC_OscInitStruct->MSIDiv);
      }
      
      /* Update the SystemCoreClock global variable */
      SystemCoreClock = (HAL_RCC_GetSysClockFreq() >> ((AHBPrescTable[(RCC->CFGR & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos]) & 0x1FU));
      
      /* Adapt Systick interrupt period */
      if (HAL_InitTick(uwTickPrio) != HAL_OK)
      {
        return HAL_ERROR;
      }
    }
    else
    {
      /* Check the MSI State */
      if (RCC_OscInitStruct->MSIState != RCC_MSI_OFF)
      {
        /* Adjust the MSI division factor */
        __HAL_RCC_MSI_CONFIG(RCC_OscInitStruct->MSIDiv);
        
        /* Enable the MSI. */
        __HAL_RCC_MSI_ENABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till MSI is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_MSIRDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > MSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        /* Disable the MSI. */
        __HAL_RCC_MSI_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till MSI is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_MSIRDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > MSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  /*-------------------------------- PLL Configuration -----------------------*/
  /* Check the parameters */
  assert_param(IS_RCC_PLL(RCC_OscInitStruct->PLL.PLLState));
  if ((RCC_OscInitStruct->PLL.PLLState) != RCC_PLL_NONE)
  {
    /* Check if the PLL is used as system clock or not */
    if (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_SYSCLKSOURCE_STATUS_PLLCLK)
    {
      if ((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_ON)
      {
        /* Check the parameters */
        assert_param(IS_RCC_PLLSOURCE(RCC_OscInitStruct->PLL.PLLSource));
        assert_param(IS_RCC_PLL_MUL(RCC_OscInitStruct->PLL.PLLMUL));

        /* Disable the main PLL. */
        __HAL_RCC_PLL_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till PLL is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        /* Configure the main PLL clock source and multiplication factors. */
        __HAL_RCC_PLL_CONFIG(RCC_OscInitStruct->PLL.PLLSource,
                             RCC_OscInitStruct->PLL.PLLMUL);
        /* Enable the main PLL. */
        __HAL_RCC_PLL_ENABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till PLL is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  == RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        /* Disable the main PLL. */
        __HAL_RCC_PLL_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till PLL is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
    else
    {
      /* Check if there is a request to disable the PLL used as System clock source */
      if ((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_OFF)
      {
        return HAL_ERROR;
      }
      else
      {
        /* Do not return HAL_ERROR if request repeats the current configuration */
        pll_config = RCC->PLLCFGR;
        if ((READ_BIT(pll_config, RCC_PLLCFGR_PLLSRC) != RCC_OscInitStruct->PLL.PLLSource) ||
            (READ_BIT(pll_config, RCC_PLLCFGR_PLLMUL) != RCC_OscInitStruct->PLL.PLLMUL))
        {
          return HAL_ERROR;
        }
      }
    }
  }

  return HAL_OK;
}

/**
  * @brief  Initializes the CPU, AHB and APB buses clocks according to the specified
  *         parameters in the RCC_ClkInitStruct.
  * @param  RCC_ClkInitStruct pointer to an RCC_OscInitTypeDef structure that
  *         contains the configuration information for the RCC peripheral.
  * @param  FLatency  FLASH Latency
  *          This parameter can be one of the following values:
  *            @arg FLASH_LATENCY_0
  *            @arg FLASH_LATENCY_1
  *            @arg FLASH_LATENCY_2
  *            @arg FLASH_LATENCY_3
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency
  *         and updated by @ref HAL_RCC_GetHCLKFreq() function called within this function
  *
  * @note   The HSI is used (enabled by hardware) as system clock source after
  *         start-up from Reset, wake-up from STOP and STANDBY mode, or in case
  *         of failure of the HSE used directly or indirectly as system clock
  *         (if the Clock Security System CSS is enabled).
  *
  * @note   A switch from one clock source to another occurs only if the target
  *         clock source is ready (clock stable after start-up delay or PLL locked).
  *         If a clock source which is not yet ready is selected, the switch will
  *         occur when the clock source will be ready.
  *         You can use @ref HAL_RCC_GetClockConfig() function to know which clock is
  *         currently used as system clock source.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency)
{
  uint32_t tickstart;
  uint32_t pllfreq;
  uint32_t hpre = RCC_SYSCLK_DIV1;

  /* Check Null pointer */
  if (RCC_ClkInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_RCC_CLOCKTYPE(RCC_ClkInitStruct->ClockType));
  assert_param(IS_FLASH_LATENCY(FLatency));

  /* To correctly read data from FLASH memory, the number of wait states (LATENCY)
  must be correctly programmed according to the frequency of the CPU clock
    (HCLK) and the supply voltage of the device. */

#if defined(FLASH_ACR_LATENCY)
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_3);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by reading the FLASH_ACR register */
    if (__HAL_FLASH_GET_LATENCY() != FLASH_LATENCY_3)
    {
      return HAL_ERROR;
    }

#endif /* FLASH_ACR_LATENCY */

  /*-------------------------- HCLK Configuration --------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_HCLK) == RCC_CLOCKTYPE_HCLK)
  {
    /* Set the highest APB divider in order to ensure that we do not go through
       a non-spec phase whatever we decrease or increase HCLK. */
    if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK) == RCC_CLOCKTYPE_PCLK)
    {
      MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE, RCC_HCLK_DIV16);
    }

    /* Set the new HCLK clock divider */
    assert_param(IS_RCC_HCLK(RCC_ClkInitStruct->AHBCLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_ClkInitStruct->AHBCLKDivider);
  }
  
  /*------------------------- SYSCLK Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK)
  {
    assert_param(IS_RCC_SYSCLKSOURCE(RCC_ClkInitStruct->SYSCLKSource));

    /* PLL is selected as System Clock Source */
    if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_PLLCLK)
    {
      /* Check the PLL ready flag */
      if (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY) == RESET)
      {
        return HAL_ERROR;
      }
      /* Undershoot management when selection PLL as SYSCLK source and frequency above 80Mhz */
      /* Compute target PLL output frequency */
      pllfreq = RCC_GetSysClockFreqFromPLLSource();
    }
    else
    {

      /* LSI is selected as System Clock Source */
      if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_LSI)
      {
        /* Check the LSI ready flag */
        if(__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
#if defined(RCC_HSE_SUPPORT)
      /* HSE is selected as System Clock Source */
      else if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_HSE)
      {
        /* Check the HSE ready flag */
        if(__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
#endif
#if defined(RCC_LSE_SUPPORT)
      /* LSE is selected as System Clock Source */
      else if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_LSE)
      {
        /* Check the LSE ready flag */
        if(__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
#endif
      /* MSISYS is selected as System Clock Source */
      else if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_MSISYS)
      {
        /* Check the MSI ready flag */
        if(__HAL_RCC_GET_FLAG(RCC_FLAG_MSIRDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
      /* HSI is selected as System Clock Source */
      else
      {
        /* Check the HSI ready flag */
        if(__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
      /* Overshoot management when going down from PLL as SYSCLK source and frequency above 80Mhz */
      pllfreq = HAL_RCC_GetSysClockFreq();
    }
    
    /* Before reducing the HCLK frequency below 80MHz or increasing it above 80MHz, 
    it is necessary to use 2 as an intermediate step for the prescaler */
    if(pllfreq > 80000000U)
    {
      if (READ_BIT(RCC->CFGR, RCC_CFGR_HPRE) == RCC_SYSCLK_DIV1)
      {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_SYSCLK_DIV2);
        hpre = RCC_SYSCLK_DIV2;
      }
    }
    
    __HAL_RCC_SYSCLK_CONFIG(RCC_ClkInitStruct->SYSCLKSource);

    /* Get Start Tick */
    tickstart = HAL_GetTick();

    while (__HAL_RCC_GET_SYSCLK_SOURCE() != (RCC_ClkInitStruct->SYSCLKSource << RCC_CFGR_SWS_Pos))
    {
      if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }

  /*-------------------------- HCLK Configuration --------------------------*/
  /* Is intermediate HCLK prescaler 2 applied internally, complete with HCLK prescaler 1 */
  if(hpre == RCC_SYSCLK_DIV2)
  {
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_SYSCLK_DIV1);
  }

#if defined(FLASH_ACR_LATENCY)
  /* Decreasing the number of wait states because of lower CPU frequency */
  if (FLatency < __HAL_FLASH_GET_LATENCY())
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLatency);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by polling the FLASH_ACR register */
    tickstart = HAL_GetTick();

    while (__HAL_FLASH_GET_LATENCY() != FLatency)
    {
      if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }
#endif /* FLASH_ACR_LATENCY */

/*-------------------------- PCLK Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK) == RCC_CLOCKTYPE_PCLK)
  {
    assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APBCLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE, RCC_ClkInitStruct->APBCLKDivider);
  }

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos];

  /* Configure the source of time base considering new system clocks settings*/
  return HAL_InitTick(uwTickPrio);
}

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions_Group2 Peripheral Control functions
  *  @brief   RCC clocks control functions
  *
  @verbatim
  ===============================================================================
                  ##### Peripheral Control functions #####
  ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the RCC Clocks
    frequencies.

  @endverbatim
  * @{
  */

/**
  * @brief  Select the clock source to output on MCO pin.
  * @param  RCC_MCOx  specifies the output direction for the clock source.
  *            @arg @ref RCC_MCO1  Clock source to output on MCO1 pin(PA14).
  *            @arg @ref RCC_MCO2  Clock source to output on MCO2 pin(PB09).
  *            @arg @ref RCC_MCO3  Clock source to output on MCO3 pin(PB13).
  *            @arg @ref RCC_MCO4  Clock source to output on MCO4 pin(PD00).
  * @param  RCC_MCOSource  specifies the clock source to output.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_MCOSOURCE_NOCLOCK  MCO output disabled, no clock on MCO
  *            @arg @ref RCC_MCOSOURCE_SYSCLK  system  clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HSI10M  HSI10M clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HSI  HSI clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HSE  HSE clock selected as MCO sourcee
  *            @arg @ref RCC_MCOSOURCE_PLLCLK  main PLL clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_LSI  LSI clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_LSE  LSE clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HCLK  AHB clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_PCLK  APB clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_MSI  MSI clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_LCD_HSI10M  LCD_HSI10M clock selected as MCO source
  * @note   Depending on devices and packages, some clocks may not be available.
  *         Refer to device datasheet for clocks availability.
  * @param  RCC_MCODiv  specifies the MCO prescaler.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_MCODIV_1  no division applied to MCO clock
  *            @arg @ref RCC_MCODIV_2  division by 2 applied to MCO clock
  *            @arg @ref RCC_MCODIV_4  division by 4 applied to MCO clock
  *            @arg @ref RCC_MCODIV_8  division by 8 applied to MCO clock
  *            @arg @ref RCC_MCODIV_16  division by 16 applied to MCO clock
  *            @arg @ref RCC_MCODIV_32  division by 32 applied to MCO clock
  *            @arg @ref RCC_MCODIV_64  division by 64 applied to MCO clock
  *            @arg @ref RCC_MCODIV_128  division by 128 applied to MCO clock
  *            @arg @ref RCC_MCODIV_256  division by 256 applied to MCO clock
  * @retval None
  */
void HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Check the parameters */
  assert_param(IS_RCC_MCO(RCC_MCOx));
  assert_param(IS_RCC_MCODIV(RCC_MCODiv));
  assert_param(IS_RCC_MCOSOURCE(RCC_MCOSource));

  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  switch(RCC_MCOx)
  {
  case RCC_MCO2 :  /* Configure PB09 as the clock output */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    break;
  case RCC_MCO3 :  /* Configure PB13 as the clock output */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    break;
  case RCC_MCO4 :  /* Configure PD00 as the clock output */
    __HAL_RCC_GPIOD_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    break;
  case RCC_MCO1 :  /* PA14 */
  default :
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_14;
    GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    break;
  }

  /* Mask MCOSEL[] and MCOPRE[] bits then set MCO clock source and prescaler */
  MODIFY_REG(RCC->CFGR, (RCC_CFGR_MCOSEL | RCC_CFGR_MCOPRE), (RCC_MCOSource | RCC_MCODiv));
}
#if defined(RCC_HSE_SUPPORT)
/**
  * @brief  Enables the Clock Security System.
  * @note   If a failure is detected on the HSE oscillator clock, this oscillator
  *         is automatically disabled and an interrupt is generated to inform the
  *         software about the failure (Clock Security System Interrupt, CSSI),
  *         allowing the MCU to perform rescue operations. The CSSI is linked to
  *         the Cortex-M0+ NMI (Non-Maskable Interrupt) exception vector.
  * @retval None
  */
void HAL_RCC_EnableCSS(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSE_CSSON);
}

/**
  * @brief  Disables the Clock Security System.
  * @retval None
  */
void HAL_RCC_DisableCSS(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSE_CSSON);
}
#endif
#if defined(RCC_LSE_SUPPORT)
/**
  * @brief  Enable the LSE Clock Security System.
  * @note   If a failure is detected on the LSE oscillator clock, this oscillator
  *         is automatically disabled and an interrupt is generated to inform the
  *         software about the failure (Clock Security System Interrupt, CSSI),
  *         allowing the MCU to perform rescue operations. The CSSI is linked to
  *         the Cortex-M0+ NMI (Non-Maskable Interrupt) exception vector.
  * @note   The LSE Clock Security System Detection bit (LSECSSD in BDCR) can only be
  *         cleared by a backup domain reset.
  * @retval None
  */
void HAL_RCC_EnableLSECSS(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSECSSON) ;
}

/**
  * @brief  Disable the LSE Clock Security System.
  * @note   After LSE failure detection, the software must disable LSECSSON
  * @note   The Clock Security System can only be cleared by reset otherwise.
  * @retval None
  */
void HAL_RCC_DisableLSECSS(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSECSSON) ;
}
#endif

/**
  * @brief  Returns the SYSCLK frequency
  * @note   The system frequency computed by this function is not the real
  *         frequency in the chip. It is calculated based on the predefined
  *         constant and the selected clock source:
  * @note     If SYSCLK source is HSI, function returns values based on HSI_VALUE(*)
  * @note     If SYSCLK source is HSE, function returns a value based on HSE_VALUE
  *           divided by PREDIV factor(**)
  * @note     If SYSCLK source is PLL, function returns a value based on HSE_VALUE
  *           divided by PREDIV factor(**) or HSI_VALUE(*) multiplied by the PLL factor.
  * @note     (*) HSI_VALUE is a constant defined inpy32c882_hal_conf.h file (default value
  *               8 MHz) but the real value may vary depending on the variations
  *               in voltage and temperature.
  * @note     (**) HSE_VALUE is a constant defined inpy32c882_hal_conf.h file (default value
  *                8 MHz), user has to ensure that HSE_VALUE is same as the real
  *                frequency of the crystal used. Otherwise, this function may
  *                have wrong result.
  *
  * @note   The result of this function could be not correct when using fractional
  *         value for HSE crystal.
  *
  * @note   This function can be used by the user application to compute the
  *         baud-rate for the communication peripherals or configure other parameters.
  *
  * @note   Each time SYSCLK changes, this function must be called to update the
  *         right SYSCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  * @retval SYSCLK frequency
  */
uint32_t HAL_RCC_GetSysClockFreq(void)
{
  const uint8_t aPLLMULFactorTable[17] = {2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18};

  uint32_t tmpreg = 0U,tmppllreg=0, pllclk = 0U, pllmul = 0U, msidiv = 0U, hsidiv = 0U, hsiIndex = 0U;
  uint32_t sysclockfreq = 0U;
  const uint32_t hsiValue[8] = {8000000,8000000,16000000,22120000,24000000,48000000,64000000,8000000};
  
  tmpreg = RCC->CFGR;
  
  tmppllreg = RCC->PLLCFGR;

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (tmpreg & RCC_CFGR_SWS)
  {
#if defined(RCC_HSE_SUPPORT)
    case RCC_SYSCLKSOURCE_STATUS_HSE:  /* HSE used as system clock */
    {
      sysclockfreq = HSE_VALUE;
      break;
    }
#endif
    case RCC_SYSCLKSOURCE_STATUS_LSI:  /* LSI used as system clock */
    {
      sysclockfreq = LSI_VALUE;
      break;
    }
#if defined(RCC_LSE_SUPPORT)
    case RCC_SYSCLKSOURCE_STATUS_LSE:  /* LSE used as system clock */
    {
      sysclockfreq = LSE_VALUE;
      break;
    }
#endif
    case RCC_SYSCLKSOURCE_STATUS_MSISYS:  /* MSISYS used as system clock */
    {
      /* MSISYS can be derived for MSI */
      msidiv = (1UL << ((READ_BIT(RCC->CR, RCC_CR_MSIDIV)) >> RCC_CR_MSIDIV_Pos));

      sysclockfreq = MSI_VALUE / msidiv;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_PLLCLK:  /* PLL used as system clock */
    {
      pllmul = aPLLMULFactorTable[(tmppllreg & RCC_PLLCFGR_PLLMUL)>>RCC_PLLCFGR_PLLMUL_Pos];
      
      if ((tmppllreg & RCC_PLLCFGR_PLLSRC) == RCC_PLLSOURCE_HSI)
      {
        hsiIndex = (RCC->ICSCR & RCC_ICSCR_HSI_FS_OPCR_Msk) >> RCC_ICSCR_HSI_FS_OPCR_Pos;
        
        /* HSI used as PLL clock source : PLLCLK = HSI * PLLMUL */
        pllclk = (uint32_t)(hsiValue[hsiIndex] * pllmul);
      }
#if defined(RCC_HSE_SUPPORT)
      else
      {
        /* HSE used as PLL clock source : PLLCLK = HSE * PLLMUL */
        pllclk = (uint32_t)(HSE_VALUE * pllmul);
      }
#endif
      sysclockfreq = pllclk;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_HSISYS:  /* HSI used as system clock source */
    default: /* HSISYS used as system clock */
    {
      /* HSISYS can be derived for HSI */
      hsidiv = (1UL << ((READ_BIT(RCC->CR, RCC_CR_HSIDIV)) >> RCC_CR_HSIDIV_Pos));

      hsiIndex = (RCC->ICSCR & RCC_ICSCR_HSI_FS_OPCR_Msk) >> RCC_ICSCR_HSI_FS_OPCR_Pos;
      sysclockfreq = (hsiValue[hsiIndex] / hsidiv);
      break;
    }
  }
  return sysclockfreq;
}

/**
  * @brief  Returns the HCLK frequency
  * @note   Each time HCLK changes, this function must be called to update the
  *         right HCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency
  *         and updated within this function
  * @retval HCLK frequency
  */
uint32_t HAL_RCC_GetHCLKFreq(void)
{
  return SystemCoreClock;
}

/**
  * @brief  Returns the PCLK frequency
  * @note   Each time PCLK changes, this function must be called to update the
  *         right PCLK value. Otherwise, any configuration based on this function will be incorrect.
  * @retval PCLK frequency
  */
uint32_t HAL_RCC_GetPCLKFreq(void)
{
  /* Get HCLK source and Compute PCLK1 frequency ---------------------------*/
  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE) >> RCC_CFGR_PPRE_Pos]);
}

/**
  * @brief  Configures the RCC_OscInitStruct according to the internal
  * RCC configuration registers.
  * @param  RCC_OscInitStruct pointer to an RCC_OscInitTypeDef structure that
  * will be configured.
  * @retval None
  */
void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  /* Check the parameters */
  assert_param(RCC_OscInitStruct != NULL);

  /* Set all possible values for the Oscillator type parameter ---------------*/
#if defined(RCC_LSE_SUPPORT) && defined(RCC_HSE_SUPPORT)
  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI  \
                                      | RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI  \
                                      | RCC_OSCILLATORTYPE_MSI;
#elif defined(RCC_HSE_SUPPORT)
  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI  \
                                      | RCC_OSCILLATORTYPE_LSI  \
                                      | RCC_OSCILLATORTYPE_MSI;
#elif defined(RCC_LSE_SUPPORT)
  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSI  \
                                      | RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI  \
                                      | RCC_OSCILLATORTYPE_MSI;
#else
  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSI  \
                                      | RCC_OSCILLATORTYPE_LSI  \
                                      | RCC_OSCILLATORTYPE_MSI;
#endif
#if defined(RCC_HSE_SUPPORT)
  /* Get the HSE configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_HSEBYP) == RCC_CR_HSEBYP)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_BYPASS;
  }
  else if ((RCC->CR & RCC_CR_HSEON) == RCC_CR_HSEON)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_ON;
  }
  else
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_OFF;
  }
  RCC_OscInitStruct->HSEFreq = (uint32_t)(RCC->ECSCR & RCC_ECSCR_HSE_DRV);
#endif
  /* Get the HSI configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_HSION) == RCC_CR_HSION)
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_ON;
  }
  else
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_OFF;
  }
  RCC_OscInitStruct->HSIDiv = (uint32_t)(RCC->CR & RCC_CR_HSIDIV);
  RCC_OscInitStruct->HSICalibrationValue = READ_BIT(RCC->ICSCR, RCC_ICSCR_HSI_FS_OPCR | RCC_ICSCR_HSI_TRIMCR) >> RCC_ICSCR_HSI_TRIMCR_Pos;
  
  /* Get the MSI configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_MSION) == RCC_CR_MSION)
  {
    RCC_OscInitStruct->MSIState = RCC_MSI_ON;
  }
  else
  {
    RCC_OscInitStruct->MSIState = RCC_MSI_OFF;
  }
  RCC_OscInitStruct->MSIDiv = (uint32_t)(RCC->CR & RCC_CR_MSIDIV);
#if defined(RCC_LSE_SUPPORT)
  /* Get the LSE configuration -----------------------------------------------*/
  if ((RCC->BDCR & RCC_BDCR_LSEBYP) == RCC_BDCR_LSEBYP)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_BYPASS;
  }
  else if ((RCC->BDCR & RCC_BDCR_LSEEN) == RCC_LSE_ON)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_ON;
  }
  else
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_OFF;
  }
  RCC_OscInitStruct->LSEDriver = (uint32_t)(RCC->BDCR & RCC_BDCR_LSEDRV);
#endif
  /* Get the LSI configuration -----------------------------------------------*/
  if ((RCC->BDCR & RCC_BDCR_LSION) == RCC_BDCR_LSION)
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_ON;
  }
  else
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_OFF;
  }
  
  /* Get the PLL configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_PLLON) == RCC_CR_PLLON)
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_ON;
  }
  else
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_OFF;
  }
  RCC_OscInitStruct->PLL.PLLSource = (uint32_t)(RCC->PLLCFGR & (RCC_PLLCFGR_PLLSRC));
  RCC_OscInitStruct->PLL.PLLMUL = (uint32_t)(RCC->PLLCFGR & RCC_PLLCFGR_PLLMUL);
}

/**
  * @brief  Get the RCC_ClkInitStruct according to the internal
  *         RCC configuration registers.
  * @param  RCC_ClkInitStruct pointer to an RCC_ClkInitTypeDef structure that
  *         contains the current clock configuration.
  * @param  pFLatency Pointer on the Flash Latency.
  * @retval None
  */
void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency)
{
  /* Check the parameters */
  assert_param(RCC_ClkInitStruct != NULL);
  assert_param(pFLatency != NULL);

  /* Set all possible values for the Clock type parameter --------------------*/
  RCC_ClkInitStruct->ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK;

  /* Get the SYSCLK configuration --------------------------------------------*/
  RCC_ClkInitStruct->SYSCLKSource = (uint32_t)(RCC->CFGR & RCC_CFGR_SW);

  /* Get the HCLK configuration ----------------------------------------------*/
  RCC_ClkInitStruct->AHBCLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_HPRE);

  /* Get the APB1 configuration ----------------------------------------------*/
  RCC_ClkInitStruct->APBCLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_PPRE);

#if   defined(FLASH_ACR_LATENCY)
  /* Get the Flash Wait State (Latency) configuration ------------------------*/
  *pFLatency = (uint32_t)(FLASH->ACR & FLASH_ACR_LATENCY);
#else
  /* For VALUE lines devices, only LATENCY_0 can be set*/
  *pFLatency = (uint32_t)FLASH_LATENCY_0;
#endif
}

/**
  * @brief This function handles the RCC CSS interrupt request.
  * @note This API should be called under the NMI_Handler().
  * @retval None
  */
void HAL_RCC_NMI_IRQHandler(void)
{
#if defined(RCC_HSE_SUPPORT) 
  /* Check RCC CSSF flag  */
  if (__HAL_RCC_GET_IT(RCC_IT_CSS))
  {
    /* RCC Clock Security System interrupt user callback */
    HAL_RCC_CSSCallback();

    /* Clear RCC CSS pending bit */
    __HAL_RCC_CLEAR_IT(RCC_IT_CSS);
  }
#endif
#if defined(RCC_LSE_SUPPORT)
  /* Check RCC LSECSSF flag  */
  if (__HAL_RCC_GET_IT(RCC_IT_LSECSS))
  {
    /* RCC Clock Security System interrupt user callback */
    HAL_RCC_LSECSSCallback();

    /* Clear RCC LSECSS pending bit */
    __HAL_RCC_CLEAR_IT(RCC_IT_LSECSS);
  }
#endif
}

#if defined(RCC_HSE_SUPPORT) 
/**
  * @brief  RCC Clock Security System interrupt callback
  * @retval none
  */
__weak void HAL_RCC_CSSCallback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
    the HAL_RCC_CSSCallback could be implemented in the user file
    */
}
#endif

#if defined(RCC_LSE_SUPPORT)
/**
  * @brief  RCC LSE Clock Security System interrupt callback.
  * @retval none
  */
__weak void HAL_RCC_LSECSSCallback(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_RCC_LSECSSCallback should be implemented in the user file
   */
}
#endif
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup RCC_Private_Functions
  * @{
  */

/**
  * @brief  Compute SYSCLK frequency based on PLL SYSCLK source.
  * @retval SYSCLK frequency
  */
static uint32_t RCC_GetSysClockFreqFromPLLSource(void)
{
  uint32_t sysclockfreq = 0, pllsource = 0, pllmul = 0, hsiIndex = 0;
  const uint32_t hsiValue[8] = {8000000,8000000,16000000,22120000,24000000,48000000,64000000,8000000};

  pllsource = READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC);
  pllmul = (READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLMUL) >> RCC_PLLCFGR_PLLMUL_Pos) + 2U ;

  switch (pllsource)
  {
#if defined(RCC_HSE_SUPPORT)
  case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
    sysclockfreq = (HSE_VALUE * pllmul);
    break;
#endif
  case RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source */
  default:
    hsiIndex = (RCC->ICSCR & RCC_ICSCR_HSI_FS_OPCR_Msk) >> RCC_ICSCR_HSI_FS_OPCR_Pos;
    
    /* HSI used as PLL clock source : PLLCLK = HSI * PLLMUL */
    sysclockfreq = (uint32_t)(hsiValue[hsiIndex] * pllmul);
    break;
  }

  return sysclockfreq;
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

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
