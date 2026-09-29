/**
  ******************************************************************************
  * @file    py32c882_hal_pwr.c
  * @author  MCU Application Team
  * @brief   PWR HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Power Controller (PWR) peripheral:
  *           + Initialization/de-initialization functions
  *           + Peripheral Control functions 
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

/** @defgroup PWR PWR
  * @brief    PWR HAL module driver
  * @{
  */

#ifdef HAL_PWR_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/** @defgroup PWR_Private_Constants PWR Private Constants
  * @{
  */
  
/** @defgroup PWR_PVD_Mode_Mask PWR PVD Mode Mask
  * @{
  */ 
#define PVD_MODE_IT               0x00010000U
#define PVD_MODE_EVT              0x00020000U
#define PVD_RISING_EDGE           0x00000001U
#define PVD_FALLING_EDGE          0x00000002U
/**
  * @}
  */
  
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/** @defgroup PWR_Exported_Functions PWR Exported Functions
  * @{
  */

/** @defgroup PWR_Exported_Functions_Group1 Initialization and de-initialization functions 
  *  @brief   Initialization and de-initialization functions
  *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]
      After reset, the backup domain (RTC registers, RTC backup data
      registers) is protected against possible unwanted
      write accesses.
      To enable access to the RTC Domain and RTC registers, proceed as follows:
        (+) Enable the Power Controller (PWR) APB1 interface clock using the
            __HAL_RCC_PWR_CLK_ENABLE() macro.
        (+) Enable access to RTC domain using the HAL_PWR_EnableBkUpAccess() function.

@endverbatim
  * @{
  */

/**
  * @brief  Deinitializes the PWR peripheral registers to their default reset values.  
  * @retval None
  */
void HAL_PWR_DeInit(void)
{
 __HAL_RCC_PWR_FORCE_RESET();
 __HAL_RCC_PWR_RELEASE_RESET();
}

/**
  * @brief  Enables access to the backup domain (RTC registers, RTC
  *         backup data registers ).
  * @note   If the HSE divided by 128 is used as the RTC clock, the
  *         Backup Domain Access should be kept enabled.
  * @retval None
  */
void HAL_PWR_EnableBkUpAccess(void)
{
  /* Enable access to RTC and backup registers */
    SET_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @brief  Disables access to the backup domain (RTC registers, RTC
  *         backup data registers).
  * @note   If the HSE divided by 128 is used as the RTC clock, the
  *         Backup Domain Access should be kept enabled.
  * @retval None
  */
void HAL_PWR_DisableBkUpAccess(void)
{
  /* Disable access to RTC and backup registers */
    CLEAR_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @}
  */

/** @defgroup PWR_Exported_Functions_Group2 Peripheral Control functions 
  * @brief    Low Power modes configuration functions
  *
@verbatim
 ===============================================================================
                 ##### Peripheral Control functions #####
 ===============================================================================
     
    *** PVD configuration ***
    =========================
    [..]
      (+) The PVD is used to monitor the VDD power supply by comparing it to a
          threshold selected by the PVD Level (PVDT[2:0] bits in the PWR_CR2).

      (+) A PVDO flag is available to indicate if VDD/VDDA is higher or lower
          than the PVD threshold. This event is internally connected to the EXTI
          line16 and can generate an interrupt if enabled. This is done through
          __HAL_PWR_PVD_EXTI_ENABLE_IT() macro.
      (+) The PVD is stopped in Standby mode.

    *** WakeUp pin configuration ***
    ================================
    [..]
      (+) WakeUp pin is used to wake up the system from Standby mode. This pin is
          forced in input pull-down configuration and is active on rising edges.

    [..]

    *** Low Power modes configuration ***
    =====================================
     [..]
      The device features 3 low-power modes:
      (+) Sleep mode: CPU clock off, all peripherals including Cortex-M4 core peripherals like 
                      NVIC, SysTick, etc. are kept running
      (+) Stop mode: All clocks are stopped
      (+) Standby mode: 1.8V domain powered off
  
  
   *** Sleep mode ***
   ==================
    [..]
      (+) Entry:
          The Sleep mode is entered by using the HAL_PWR_EnterSLEEPMode(PWR_SLEEPENTRY_WFx)
              functions with
          (++) PWR_SLEEPENTRY_WFI: enter SLEEP mode with WFI instruction
          (++) PWR_SLEEPENTRY_WFE: enter SLEEP mode with WFE instruction
     
      (+) Exit:
        (++) WFI entry mode, Any peripheral interrupt acknowledged by the nested vectored interrupt
             controller (NVIC) can wake up the device from Sleep mode.
        (++) WFE entry mode, Any wakeup event can wake up the device from Sleep mode.
           (+++) Any peripheral interrupt w/o NVIC configuration & SEVONPEND bit set in the Cortex (HAL_PWR_EnableSEVOnPend)
           (+++) Any EXTI Line (Internal or External) configured in Event mode

   *** Stop mode ***
   =================
    [..]
      The Stop mode is based on the Cortex-M4 deepsleep mode combined with peripheral
      clock gating. The voltage regulator can be configured either in normal or low-power mode.
      In Stop mode, all clocks in the 1.8V domain are stopped, the PLL, the HSI and the HSE RC 
      oscillators are disabled. SRAM and register contents are preserved.
      In Stop mode, all I/O pins keep the same state as in Run mode.

      (+) Entry:
           The Stop mode is entered using the HAL_PWR_EnterSTOPMode(PWR_REGULATOR_VALUE, PWR_SLEEPENTRY_WFx )
             function with:
          (++) PWR_REGULATOR_VALUE= PWR_MAINREGULATOR_ON: Main regulator ON.
          (++) PWR_REGULATOR_VALUE= PWR_LOWPOWERREGULATOR_ON: Low Power regulator ON.
          (++) PWR_SLEEPENTRY_WFx= PWR_SLEEPENTRY_WFI: enter STOP mode with WFI instruction
          (++) PWR_SLEEPENTRY_WFx= PWR_SLEEPENTRY_WFE: enter STOP mode with WFE instruction
      (+) Exit:
          (++) WFI entry mode, Any EXTI Line (Internal or External) configured in Interrupt mode with NVIC configured
          (++) WFE entry mode, Any EXTI Line (Internal or External) configured in Event mode.

   *** Standby mode ***
   ====================
     [..]
      The Standby mode allows to achieve the lowest power consumption. It is based on the
      Cortex-M4 deepsleep mode, with the voltage regulator disabled. The 1.8 V domain is 
      consequently powered off. The PLL, the HSI oscillator and the HSE oscillator are also 
      switched off. SRAM and register contents are lost except for registers in the Backup domain 
      and Standby circuitry
      
      (+) Entry:
        (++) The Standby mode is entered using the HAL_PWR_EnterSTANDBYMode() function.
      (+) Exit:
        (++) WKUP pin rising edge, RTC alarm event rising edge, external Reset in 
             NRSTpin, IWDG Reset

   *** Auto-wakeup (AWU) from low-power mode ***
       =============================================
       [..]
        
       (+) The MCU can be woken up from low-power mode by an RTC Alarm event, 
           without depending on an external interrupt (Auto-wakeup mode).
   
       (+) RTC auto-wakeup (AWU) from the Stop and Standby modes

           (++) To wake up from the Stop mode with an RTC alarm event, it is necessary to 
                configure the RTC to generate the RTC alarm using the HAL_RTC_SetAlarm_IT() function.

   *** PWR Workarounds linked to Silicon Limitation ***
       ====================================================
       [..]
       Below the list of all silicon limitations known on PY32F4xx prouct.

       (#)Workarounds Implemented inside PWR HAL Driver
          (##)Debugging Stop mode with WFE entry - overloaded the WFE by an internal function    
        
@endverbatim
  * @{
  */

/**
  * @brief  Configures the voltage threshold detected by the Power Voltage Detector(PVD).
  * @param  sConfigPVD: pointer to an PWR_PVDTypeDef structure that contains the configuration
  *         information for the PVD.
  * @note   Refer to the electrical characteristics of your device datasheet for
  *         more details about the voltage threshold corresponding to each
  *         detection level.
  * @retval None
  */
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD)
{
  /* Check the parameters */
  assert_param(IS_PWR_PVD_LEVEL(sConfigPVD->PVDLevel));
  assert_param(IS_PWR_PVD_MODE(sConfigPVD->Mode));
  assert_param(IS_PWR_PVD_FILTER(sConfigPVD->PVDFilter));
  assert_param(IS_PWR_PVD_OUTPUT_SELECT(sConfigPVD->PVDOutputSelect)); 

  /* Set PVDT[2:0] and PVD_OUT_SEL bits according to PVDLevel value */
  MODIFY_REG(PWR->CR2, PWR_CR2_PVDT | PWR_CR2_PVD_OUT_SEL, sConfigPVD->PVDLevel | sConfigPVD->PVDOutputSelect);
  
  if(sConfigPVD->PVDOutputSelect == PWR_PVD_OUT_SYN_FILTER)
  {
    MODIFY_REG(PWR->CR2, (PWR_CR2_FLTEN | PWR_CR2_FLT_TIME), sConfigPVD->PVDFilter);
  }
  else
  {
    CLEAR_BIT(PWR->CR2, PWR_CR2_FLTEN);
  }
  
  /* Clear any previous config. Keep it clear if no event or IT mode is selected */
  __HAL_PWR_PVD_EXTI_DISABLE_EVENT();
  __HAL_PWR_PVD_EXTI_DISABLE_IT();
  __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE(); 
  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();

  /* Configure interrupt mode */
  if((sConfigPVD->Mode & PVD_MODE_IT) == PVD_MODE_IT)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_IT();
  }
  
  /* Configure event mode */
  if((sConfigPVD->Mode & PVD_MODE_EVT) == PVD_MODE_EVT)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_EVENT();
  }
  
  /* Configure the edge */
  if((sConfigPVD->Mode & PVD_RISING_EDGE) == PVD_RISING_EDGE)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();
  }
  
  if((sConfigPVD->Mode & PVD_FALLING_EDGE) == PVD_FALLING_EDGE)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();
  }
}

/**
  * @brief  Enables the Power Voltage Detector(PVD).
  * @retval None
  */
void HAL_PWR_EnablePVD(void)
{
  /* Enable the power voltage detector */
    SET_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief  Disables the Power Voltage Detector(PVD).
  * @retval None
  */
void HAL_PWR_DisablePVD(void)
{
  /* Disable the power voltage detector */
    CLEAR_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief Enable the WakeUp PINx functionality.
  * @param WakeUpPinPolarity: Specifies which Wake-Up pin to enable.
  *         This parameter can be one of the following legacy values which set the default polarity
  *         i.e. detection on high level (rising edge):
  *           @arg @ref PWR_WAKEUP_PIN0, PWR_WAKEUP_PIN1, PWR_WAKEUP_PIN2, PWR_WAKEUP_PIN3, PWR_WAKEUP_PIN4, PWR_WAKEUP_PIN5, PWR_WAKEUP_PIN6, PWR_WAKEUP_PIN7
  *
  *         or one of the following value where the user can explicitly specify the enabled pin and
  *         the chosen polarity:
  *           @arg @ref PWR_WAKEUP_PIN0_HIGH or PWR_WAKEUP_PIN0_LOW
  *           @arg @ref PWR_WAKEUP_PIN1_HIGH or PWR_WAKEUP_PIN1_LOW
  *           @arg @ref PWR_WAKEUP_PIN2_HIGH or PWR_WAKEUP_PIN2_LOW
  *           @arg @ref PWR_WAKEUP_PIN3_HIGH or PWR_WAKEUP_PIN3_LOW
  *           @arg @ref PWR_WAKEUP_PIN4_HIGH or PWR_WAKEUP_PIN4_LOW
  *           @arg @ref PWR_WAKEUP_PIN5_HIGH or PWR_WAKEUP_PIN5_LOW
  *           @arg @ref PWR_WAKEUP_PIN6_HIGH or PWR_WAKEUP_PIN6_LOW
  *           @arg @ref PWR_WAKEUP_PIN7_HIGH or PWR_WAKEUP_PIN7_LOW
  * @note  PWR_WAKEUP_PINx and PWR_WAKEUP_PINx_HIGH are equivalent.
  * @retval None
  */
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinPolarity)
{
  assert_param(IS_PWR_WAKEUP_PIN(WakeUpPinPolarity));
  
  uint32_t position = 0x00u;
  uint32_t pin = PWR_CR3_EWUP & WakeUpPinPolarity;
  /* Specifies the Wake-Up pin polarity for the event detection
    (rising or falling edge) */
  while(((pin & (1uL << position)) == 0x00u) && (position < 8u))
  {
    position++;
  }
  MODIFY_REG(PWR->CR4, 0x3U << (2 * position), (WakeUpPinPolarity >> PWR_WUP_POLARITY_SHIFT));

  /* Enable wake-up pin */
  SET_BIT(PWR->CR3, pin);
}

/**
  * @brief Disable the WakeUp PINx functionality.
  * @param WakeUpPinx: Specifies the Power Wake-Up pin to disable.
  *         This parameter can be one of the following values:
  *           @arg @ref PWR_WAKEUP_PIN0, PWR_WAKEUP_PIN1, PWR_WAKEUP_PIN2, PWR_WAKEUP_PIN3, PWR_WAKEUP_PIN4, PWR_WAKEUP_PIN5, PWR_WAKEUP_PIN6, PWR_WAKEUP_PIN7
  * @retval None
  */
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx)
{
  assert_param(IS_PWR_WAKEUP_PIN(WakeUpPinx));

  CLEAR_BIT(PWR->CR3, (PWR_CR3_EWUP & WakeUpPinx));
}

/**
  * @brief Enter Sleep or Low-power Sleep mode.
  * @note  In Sleep/Low-power Sleep mode, all I/O pins keep the same state as in Run mode.
  * @param SLEEPEntry: Specifies if Sleep mode is entered with WFI or WFE instruction.
  *           This parameter can be one of the following values:
  *            @arg @ref PWR_SLEEPENTRY_WFI enter Sleep mode with WFI instruction
  *            @arg @ref PWR_SLEEPENTRY_WFE enter Sleep mode with WFE instruction
  * @note  When WFI entry is used, tick interrupt have to be disabled if not desired as
  *        the interrupt wake up source.
  * @retval None
  */
void HAL_PWR_EnterSLEEPMode(uint8_t SLEEPEntry)
{
  /* Check the parameters */
  assert_param(IS_PWR_SLEEP_ENTRY(SLEEPEntry));

  /* Voltage Regulator selects MR mode */
  HAL_PWREx_SetVoltageRegulatorMode(PWR_MAINREGULATOR_ON);
  
  /* Clear SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select SLEEP mode entry -------------------------------------------------*/
  if(SLEEPEntry == PWR_SLEEPENTRY_WFI)
  {
    /* Request Wait For Interrupt */
    __WFI();
  }
  else
  {
    /* Request Wait For Event */
    __SEV();
    __WFE();
    __WFE();
  }
}

/**
  * @brief Enter Sleep or Low-power Sleep mode.
  * @note  In Sleep/Low-power Sleep mode, all I/O pins keep the same state as in Run mode.
  * @note  Low-power Sleep mode is entered from Low-power Run mode.
  *        Additionally, the system clock source must be set to MSISYS.
  * @note  When exiting Low-power Sleep mode, the MCU is in Low-power Run mode. To move in
  *        Run mode, the user must resort to HAL_PWREx_ExitLowPowerRunMode() API.
  * @param  Regulator : Specifies the regulator state in Low power sleep mode.
  *                     This parameter can be one of the following values :
  *                     @arg @ref PWR_MAINREGULATOR_ON        
  *                     @arg @ref PWR_LOWPOWERREGULATOR_ON    
  * @param SLEEPEntry: Specifies if Sleep mode is entered with WFI or WFE instruction.
  *           This parameter can be one of the following values:
  *            @arg @ref PWR_SLEEPENTRY_WFI enter Sleep or Low-power Sleep mode with WFI instruction
  *            @arg @ref PWR_SLEEPENTRY_WFE enter Sleep or Low-power Sleep mode with WFE instruction
  * @note  When WFI entry is used, tick interrupt have to be disabled if not desired as
  *        the interrupt wake up source.
  * @retval None
  */
void HAL_PWR_EnterLowPowerSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry)
{
  /* Check the parameters */
  assert_param(IS_PWR_REGULATOR(Regulator));
  assert_param(IS_PWR_SLEEP_ENTRY(SLEEPEntry));

  /* The system clock source must be MSISYS at this point. */
  HAL_PWREx_EnterLowPowerRunMode(Regulator);
  
  /* Clear SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select SLEEP mode entry -------------------------------------------------*/
  if(SLEEPEntry == PWR_SLEEPENTRY_WFI)
  {
    /* Request Wait For Interrupt */
    __WFI();
  }
  else
  {
    /* Request Wait For Event */
    __SEV();
    __WFE();
    __WFE();
  }
}

/**
  * @brief Enter Standby mode.
  * @note  In Standby mode, the PLL, the HSI and the HSE oscillators are switched
  *        off. The voltage regulator is disabled, except when SRAM2 content is preserved
  *        in which case the regulator is in low-power mode.
  *        SRAM1 and register contents are lost except for registers in the Backup domain and
  *        Standby circuitry. SRAM2 content can be preserved if the bit RRS is set in PWR_CR3 register.
  *        To enable this feature, the user can resort to HAL_PWREx_EnableSRAM2ContentRetention() API
  *        to set RRS bit.
  *        The BOR is available.
  * @note  The I/Os can be configured either with a pull-up or pull-down or can be kept in analog state.
  *        HAL_PWREx_EnableGPIOPullUp() and HAL_PWREx_EnableGPIOPullDown() respectively enable Pull Up and
  *        Pull Down state, HAL_PWREx_DisableGPIOPullUp() and HAL_PWREx_DisableGPIOPullDown() disable the
  *        same.
  *        These states are effective in Standby mode only if APC bit is set through
  *        HAL_PWREx_EnablePullUpPullDownConfig() API.
  * @param Regulator : Specifies the regulator state in Standby mode.
  *                     This parameter can be one of the following values :
  *                     @arg @ref PWR_MAINREGULATOR_ON        
  *                     @arg @ref PWR_LOWPOWERREGULATOR_ON    
  *                     @arg @ref PWR_DEEPLOWPOWERREGULATOR_ON
  * @retval None
  */
void HAL_PWR_EnterSTANDBYMode(uint32_t Regulator)
{
  /* Clear the wake-up flag */
  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);

  /* Set Stand-by mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_2 | PWR_CR1_LPMS_0);
  
  /* Configure the Voltage Regulator mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, Regulator);

  /* Set SLEEPDEEP bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

/* This option is used to ensure that store operations are completed */
#if defined ( __CC_ARM)
  __force_stores();
#endif
  /* Request Wait For Interrupt */
  __WFI();
}

/**
  * @brief Indicates Sleep-On-Exit when returning from Handler mode to Thread mode. 
  * @note Set SLEEPONEXIT bit of SCR register. When this bit is set, the processor 
  *       re-enters SLEEP mode when an interruption handling is over.
  *       Setting this bit is useful when the processor is expected to run only on
  *       interruptions handling.         
  * @retval None
  */
void HAL_PWR_EnableSleepOnExit(void)
{
  /* Set SLEEPONEXIT bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}

/**
  * @brief Disables Sleep-On-Exit feature when returning from Handler mode to Thread mode. 
  * @note Clears SLEEPONEXIT bit of SCR register. When this bit is set, the processor 
  *       re-enters SLEEP mode when an interruption handling is over.          
  * @retval None
  */
void HAL_PWR_DisableSleepOnExit(void)
{
  /* Clear SLEEPONEXIT bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}

/**
  * @brief Enables CORTEX M4 SEVONPEND bit. 
  * @note Sets SEVONPEND bit of SCR register. When this bit is set, this causes 
  *       WFE to wake up when an interrupt moves from inactive to pended.
  * @retval None
  */
void HAL_PWR_EnableSEVOnPend(void)
{
  /* Set SEVONPEND bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}

/**
  * @brief Disables CORTEX M4 SEVONPEND bit. 
  * @note Clears SEVONPEND bit of SCR register. When this bit is set, this causes 
  *       WFE to wake up when an interrupt moves from inactive to pended.         
  * @retval None
  */
void HAL_PWR_DisableSEVOnPend(void)
{
  /* Clear SEVONPEND bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}

/**
  * @brief  This function handles the PWR PVD interrupt request.
  * @note   This API should be called under the PVD_IRQHandler().
  * @retval None
  */
void HAL_PWR_PVD_IRQHandler(void)
{
  /* Check PWR exti flag */
  if(__HAL_PWR_PVD_EXTI_GET_FLAG() != RESET)
  {
    /* PWR PVD interrupt user callback */
    HAL_PWR_PVDCallback();

    /* Clear PWR Exti pending bit */
    __HAL_PWR_PVD_EXTI_CLEAR_FLAG();
  }
}

/**
  * @brief  PWR PVD interrupt callback
  * @retval None
  */
__weak void HAL_PWR_PVDCallback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_PWR_PVDCallback could be implemented in the user file
   */ 
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_PWR_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
