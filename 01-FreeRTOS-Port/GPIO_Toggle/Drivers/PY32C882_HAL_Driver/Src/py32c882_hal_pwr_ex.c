/**
  ******************************************************************************
  * @file   py32c882_hal_pwr_ex.c
  * @author  MCU Application Team
  * @brief   Extended PWR HAL module driver.
  *          This file provides firmware functions to manage the following 
  *          functionalities of PWR extension peripheral:           
  *           + Peripheral Extended features functions
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

/** @defgroup PWREx PWREx
  * @brief PWR HAL module driver
  * @{
  */

#ifdef HAL_PWR_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup PWREx_TimeOut_Value PWR Extended Flag Setting Time Out Value
  * @{
  */
#define PWR_FLAG_SETTING_DELAY_US                      50UL   /*!< Time out value for MR_RDY and LPRUN_RUN_SWF flags setting */
/**
  * @}
  */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup PWREx_Exported_Functions PWREx Exported Functions
  *  @{
  */

/** @defgroup PWREx_Exported_Functions_Group1 Peripheral Extended features functions 
  *  @brief Peripheral Extended features functions 
  *

  * @{
  */

/**
  * @brief Config wakeup from stop mode, enable flash delay time.
  * @param  DelayTime: Specifies the delay time before FLASH control
  *          This parameter can be one of the following values:
  *            - @arg PWR_WAKEUP_FLASH_DELAY_3US: Wake up from the STOP mode, Delay 3us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_5US: Wake up from the STOP mode, Delay 5us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_1US: Wake up from the STOP mode, Delay 1us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_0US: Wake up from the STOP mode, Enable flash immediately
  * @retval None
  */
void HAL_PWREx_SetWakeupFlashDelay(uint32_t DelayTime)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_FLS_SLPTIME, DelayTime);
}

/**
  * @brief Get wakeup from stop mode, enable flash delay time.
  * @retval Config Flash wakeup delay time.
  *            - @arg PWR_WAKEUP_FLASH_DELAY_3US: Wake up from the STOP mode, Delay 3us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_5US: Wake up from the STOP mode, Delay 5us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_1US: Wake up from the STOP mode, Delay 1us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_0US: Wake up from the STOP mode, Enable flash immediately
  */
uint32_t HAL_PWREx_GetWakeupFlashDelay(void)
{
  return (PWR->CR1 & PWR_CR1_FLS_SLPTIME);
}

/**
  * @brief Config wakeup from STANDBY mode MR Ready delay time.
  * @param  DelayTime: Specifies the delay time afte MR Ready.
  *          This parameter can be one of the following values:
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_0US:   Wake up from the STANDY mode, MR Ready Delay 0us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_5US:   Wake up from the STANDY mode, MR Ready Delay 5us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_10US:  Wake up from the STANDY mode, MR Ready Delay 10us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_20US:  Wake up from the STANDY mode, MR Ready Delay 20us
  * @retval None
  */
void HAL_PWREx_SetWakeupMrReadyDelay(uint32_t DelayTime)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_STDBY_MRRDY_WAIT, DelayTime);
}

/**
  * @brief Get wakeup from STANDBY mode MR Ready delay time.
  * @retval Get STANDBY wakeup MR Ready delay time.
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_0US:   Wake up from the STANDY mode, MR Ready Delay 0us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_5US:   Wake up from the STANDY mode, MR Ready Delay 5us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_10US:  Wake up from the STANDY mode, MR Ready Delay 10us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_20US:  Wake up from the STANDY mode, MR Ready Delay 20us
  */
uint32_t HAL_PWREx_GetWakeupMrReadyDelay(void)
{
  return (PWR->CR1 & PWR_CR1_STDBY_MRRDY_WAIT);
}

/**
  * @brief When wakeup from stop mode,HSI and Main Regulator start at the same time.
  * @retval None
  */
void HAL_PWREx_DisableHSIWakeupWait(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_HSION_CTRL);
}

/**
  * @brief When wakeup from stop mode,HSI enable After Main Regulator stable.
  * @retval None
  */
void HAL_PWREx_EnableHSIWakeupWait(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_HSION_CTRL);
}

/**
  * @brief When wakeup from stop mode to low power run mode, MSI and Flash start at the same time.
  * @retval None
  */
void HAL_PWREx_DisableFlashWakeupWait(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_FLSSLP_CTRL);
}

/**
  * @brief When wakeup from stop mode to low power run mode, Flash starts counting only after MSI stabilizes.
  * @retval None
  */
void HAL_PWREx_EnableFlashWakeupWait(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_FLSSLP_CTRL);
}

/**
  * @brief Enable power on load.
  * @note  When LD_EN bit is set, perform power-on load after waking up from standby mode
  * @retval None
  */
void HAL_PWREx_EnablePowerOnLoad(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_LD_EN);
}


/**
  * @brief Disable power on load.
  * @note  When LD_EN bit is set, do not perform power-on load after waking up from standby mode
  * @retval None
  */
void HAL_PWREx_DisablePowerOnLoad(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_LD_EN);
}

/**
  * @brief Enable GPIO pull-up state in Standby modes.
  * @note  Set the relevant PUy bits of PWR_PUCRx register to configure the I/O in
  *        pull-up state in Standby modes.
  * @note  This state is effective in Standby modes only if APC bit
  *        is set through HAL_PWREx_EnablePullUpPullDownConfig() API.
  * @note  The configuration is lost when exiting the Shutdown mode due to the
  *        power-on reset, maintained when exiting the Standby mode.
  * @note  To avoid any conflict at Standby modes exits, the corresponding
  *        PDy bit of PWR_PDCRx register is cleared unless it is reserved.
  * @note  Even if a PUy bit to set is reserved, the other PUy bits entered as input
  *        parameter at the same time are set.
  * @param  GPIO: Specify the IO port. This parameter can be PWR_GPIO_A, ..., PWR_GPIO_D
  *         to select the GPIO peripheral.
  * @param  GPIONumber: Specify the I/O pins numbers.
  *         This parameter can be one of the following values:
  *         PWR_GPIO_BIT_0, ..., PWR_GPIO_BIT_15 (except for the port where less
  *         I/O pins are available) or the logical OR of several of them to set
  *         several bits for a given port in a single API call.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       SET_BIT(PWR->PUCRA, (GPIONumber & (~(PWR_GPIO_BIT_4|PWR_GPIO_BIT_6|PWR_GPIO_BIT_7|PWR_GPIO_BIT_8))));
       CLEAR_BIT(PWR->PDCRA, (GPIONumber & (~(PWR_GPIO_BIT_5|PWR_GPIO_BIT_6|PWR_GPIO_BIT_7|PWR_GPIO_BIT_8))));
       break;
    case PWR_GPIO_B:
       SET_BIT(PWR->PUCRB, GPIONumber);
       CLEAR_BIT(PWR->PDCRB, GPIONumber);
       break;
    case PWR_GPIO_C:
       SET_BIT(PWR->PUCRC, GPIONumber);
       CLEAR_BIT(PWR->PDCRC, GPIONumber);
       break;
    case PWR_GPIO_D:
       SET_BIT(PWR->PUCRD, GPIONumber);
       CLEAR_BIT(PWR->PDCRD, GPIONumber);
       break;
    default:
      status = HAL_ERROR;
      break;
  }

  return status;
}


/**
  * @brief Disable GPIO pull-up state in Standby mode and Shutdown modes.
  * @note  Reset the relevant PUy bits of PWR_PUCRx register used to configure the I/O
  *        in pull-up state in Standby modes.
  * @note  Even if a PUy bit to reset is reserved, the other PUy bits entered as input
  *        parameter at the same time are reset.
  * @param  GPIO: Specifies the IO port. This parameter can be PWR_GPIO_A, ..., PWR_GPIO_D
  *          to select the GPIO peripheral.
  * @param  GPIONumber: Specify the I/O pins numbers.
  *         This parameter can be one of the following values:
  *         PWR_GPIO_BIT_0, ..., PWR_GPIO_BIT_15 (except for the port where less
  *         I/O pins are available) or the logical OR of several of them to reset
  *         several bits for a given port in a single API call.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       CLEAR_BIT(PWR->PUCRA, (GPIONumber & (~(PWR_GPIO_BIT_4|PWR_GPIO_BIT_6|PWR_GPIO_BIT_7|PWR_GPIO_BIT_8))));
       break;
    case PWR_GPIO_B:
       CLEAR_BIT(PWR->PUCRB, GPIONumber);
       break;
    case PWR_GPIO_C:
       CLEAR_BIT(PWR->PUCRC, GPIONumber);
       break;
    case PWR_GPIO_D:
       CLEAR_BIT(PWR->PUCRD, GPIONumber);
       break;
    default:
       status = HAL_ERROR;
       break;
  }

  return status;
}

/**
  * @brief Enable GPIO pull-down state in Standby modes.
  * @note  Set the relevant PDy bits of PWR_PDCRx register to configure the I/O in
  *        pull-down state in Standby modes.
  * @note  This state is effective in Standby modes only if APC bit
  *        is set through HAL_PWREx_EnablePullUpPullDownConfig() API.
  * @note  The configuration is lost when exiting the Shutdown mode due to the
  *        power-on reset, maintained when exiting the Standby mode.
  * @note  To avoid any conflict at Standby modes exits, the corresponding
  *        PUy bit of PWR_PUCRx register is cleared unless it is reserved.
  * @note  Even if a PDy bit to set is reserved, the other PDy bits entered as input
  *        parameter at the same time are set.
  * @param  GPIO: Specify the IO port. This parameter can be PWR_GPIO_A..PWR_GPIO_D
  *         to select the GPIO peripheral.
  * @param  GPIONumber: Specify the I/O pins numbers.
  *         This parameter can be one of the following values:
  *         PWR_GPIO_BIT_0, ..., PWR_GPIO_BIT_15 (except for the port where less
  *         I/O pins are available) or the logical OR of several of them to set
  *         several bits for a given port in a single API call.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       SET_BIT(PWR->PDCRA, (GPIONumber & (~(PWR_GPIO_BIT_5|PWR_GPIO_BIT_6|PWR_GPIO_BIT_7|PWR_GPIO_BIT_8))));
       CLEAR_BIT(PWR->PUCRA, (GPIONumber & (~(PWR_GPIO_BIT_4|PWR_GPIO_BIT_6|PWR_GPIO_BIT_7|PWR_GPIO_BIT_8))));
       break;
    case PWR_GPIO_B:
       SET_BIT(PWR->PDCRB, GPIONumber);
       CLEAR_BIT(PWR->PUCRB, GPIONumber);
       break;
    case PWR_GPIO_C:
       SET_BIT(PWR->PDCRC, GPIONumber);
       CLEAR_BIT(PWR->PUCRC, GPIONumber);
       break;
    case PWR_GPIO_D:
       SET_BIT(PWR->PDCRD, GPIONumber);
       CLEAR_BIT(PWR->PUCRD, GPIONumber);
       break;
    default:
      status = HAL_ERROR;
      break;
  }

  return status;
}

/**
  * @brief Disable GPIO pull-down state in Standby modes.
  * @note  Reset the relevant PDy bits of PWR_PDCRx register used to configure the I/O
  *        in pull-down state in Standby modes.
  * @note  Even if a PDy bit to reset is reserved, the other PDy bits entered as input
  *        parameter at the same time are reset.
  * @param  GPIO: Specifies the IO port. This parameter can be PWR_GPIO_A..PWR_GPIO_D
  *         to select the GPIO peripheral.
  * @param  GPIONumber: Specify the I/O pins numbers.
  *         This parameter can be one of the following values:
  *         PWR_GPIO_BIT_0, ..., PWR_GPIO_BIT_15 (except for the port where less
  *         I/O pins are available) or the logical OR of several of them to reset
  *         several bits for a given port in a single API call.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       CLEAR_BIT(PWR->PDCRA, (GPIONumber & (~(PWR_GPIO_BIT_5|PWR_GPIO_BIT_6|PWR_GPIO_BIT_7|PWR_GPIO_BIT_8))));
       break;
    case PWR_GPIO_B:
       CLEAR_BIT(PWR->PDCRB, GPIONumber);
       break;
    case PWR_GPIO_C:
       CLEAR_BIT(PWR->PDCRC, GPIONumber);
       break;
    case PWR_GPIO_D:
       CLEAR_BIT(PWR->PDCRD, GPIONumber);
       break;
    default:
      status = HAL_ERROR;
      break;
  }

  return status;
}

/**
  * @brief Enable pull-up and pull-down configuration.
  * @note  When APC bit is set, the I/O pull-up and pull-down configurations defined in
  *        PWR_PUCRx and PWR_PDCRx registers are applied in Standby modes.
  * @note  Pull-up set by PUy bit of PWR_PUCRx register is not activated if the corresponding
  *        PDy bit of PWR_PDCRx register is also set (pull-down configuration priority is higher).
  *        HAL_PWREx_EnableGPIOPullUp() and HAL_PWREx_EnableGPIOPullDown() API's ensure there
  *        is no conflict when setting PUy or PDy bit.
  * @retval None
  */
void HAL_PWREx_EnablePullUpPullDownConfig(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_APC);
}

/**
  * @brief Disable pull-up and pull-down configuration.
  * @note  When APC bit is cleared, the I/O pull-up and pull-down configurations defined in
  *        PWR_PUCRx and PWR_PDCRx registers are not applied in Standby modes.
  * @retval None
  */
void HAL_PWREx_DisablePullUpPullDownConfig(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_APC);
}

/**
  * @brief Enable SRAM1 content retention in Standby mode.
  * @note  When SRAM1PDSTD bit is set, SRAM1 is powered by the low-power regulator in
  *         Standby mode and its content is kept.
  * @retval None
  */
void HAL_PWREx_EnableSRAM1ContentRetention(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_SRAM1PDSTD);
}

/**
  * @brief Disable SRAM1 content retention in Standby mode.
  * @note  When SRAM1PDSTD bit is reset, SRAM1 is powered off in Standby mode
  *        and its content is lost.
  * @retval None
  */
void HAL_PWREx_DisableSRAM1ContentRetention(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_SRAM1PDSTD);
}

/**
  * @brief Config Voltage of MR.
  * @param  Voltage: Specifies the Voltage of MR
  *          This parameter can be one of the following values:
  *            - @arg PWR_MR_VOLTAGE_LOW:        Low voltage
  *            - @arg PWR_MR_VOLTAGE_OVERCLOCK:  Overclock voltage
  *            - @arg PWR_MR_VOLTAGE_STANDARD:   Standard voltage
  * @retval None
  */
void HAL_PWREx_SetMrVoltageMode(uint32_t Voltage)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_MR_VSEL, Voltage);
}

/**
  * @brief Return Voltage of MR.
  * @retval  The configured voltage for the MR.
  *          The returned value can be one of the following:
  *            - @arg PWR_MR_VOLTAGE_LOW:        Low voltage
  *            - @arg PWR_MR_VOLTAGE_OVERCLOCK:  Overclock voltage
  *            - @arg PWR_MR_VOLTAGE_STANDARD:   Standard voltage
  */
uint32_t HAL_PWREx_GetMrVoltageMode(void)
{
  return(PWR->CR1 & PWR_CR1_MR_VSEL);
}

/**
  * @brief Config Voltage of LPR.
  * @param  Voltage: Specifies the Voltage of LPR
  *          This parameter can be one of the following values:
  *            - @arg PWR_LPR_VOLTAGE_HIGH:       High voltage
  *            - @arg PWR_LPR_VOLTAGE_MEDIUM:     Medium voltage
  *            - @arg PWR_LPR_VOLTAGE_LOW:        Low voltage
  * @retval None
  */
void HAL_PWREx_SetLprVoltageMode(uint32_t Voltage)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_LPR_VSEL, Voltage);
}

/**
  * @brief Return Voltage of LPR.
  * @retval  The configured voltage for the LPR.
  *          The returned value can be one of the following:
  *            - @arg PWR_LPR_VOLTAGE_HIGH:       High voltage
  *            - @arg PWR_LPR_VOLTAGE_MEDIUM:     Medium voltage
  *            - @arg PWR_LPR_VOLTAGE_LOW:        Low voltage
  */
uint32_t HAL_PWREx_GetLprVoltageMode(void)
{
  return(PWR->CR1 & PWR_CR1_LPR_VSEL);
}

/**
  * @brief Config Voltage of DLPR.
  * @param  Voltage: Specifies the Voltage of DLPR
  *          This parameter can be one of the following values:
  *            - @arg PWR_DLPR_VOLTAGE_HIGH:       High voltage
  *            - @arg PWR_DLPR_VOLTAGE_MEDIUM:     Medium voltage
  *            - @arg PWR_DLPR_VOLTAGE_MEDIUM_LOW: Medium low voltage
  *            - @arg PWR_DLPR_VOLTAGE_LOW:        Low voltage
  * @retval None
  */
void HAL_PWREx_SetDlprVoltageMode(uint32_t Voltage)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_DLPR_VSEL, Voltage);
}

/**
  * @brief Return Voltage of DLPR.
  * @retval  The configured voltage for the DLPR.
  *          The returned value can be one of the following:
  *            - @arg PWR_DLPR_VOLTAGE_HIGH:       High voltage
  *            - @arg PWR_DLPR_VOLTAGE_MEDIUM:     Medium voltage
  *            - @arg PWR_DLPR_VOLTAGE_MEDIUM_LOW: Medium low voltage
  *            - @arg PWR_DLPR_VOLTAGE_LOW:        Low voltage
  */
uint32_t HAL_PWREx_GetDlprVoltageMode(void)
{
  return(PWR->CR1 & PWR_CR1_DLPR_VSEL);
}

/**
  * @brief Config Voltage Regulator mode.
  * @param  VRMode: Specifies the mode of Voltage Regulator
  *          This parameter can be one of the following values:
  *            - @arg PWR_MAINREGULATOR_ON         : Voltage Regulator selects MR mode
  *            - @arg PWR_LOWPOWERREGULATOR_ON     : Voltage Regulator selects LPR mode
  *            - @arg PWR_DEEPLOWPOWERREGULATOR_ON : Voltage Regulator selects DLPR mode
  * @retval None
  */
void HAL_PWREx_SetVoltageRegulatorMode(uint32_t VRMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, VRMode);
}

/**
  * @brief Return Voltage Regulator mode.
  * @retval  The configured mode for the Voltage Regulator.
  *          The returned value can be one of the following:
  *            - @arg PWR_MAINREGULATOR_ON         : Voltage Regulator selects MR mode
  *            - @arg PWR_LOWPOWERREGULATOR_ON     : Voltage Regulator selects LPR mode
  *            - @arg PWR_DEEPLOWPOWERREGULATOR_ON : Voltage Regulator selects DLPR mode
  */
uint32_t HAL_PWREx_GetVoltageRegulatorMode(void)
{
  return(PWR->CR1 & PWR_CR1_VR_MODE);
}

/**
  * @brief Enter Low-power Run mode
  * @note  In Low-power Run mode, all I/O pins keep the same state as in Run mode.
  * @note  The system clock source must be set to MSISYS.
  * @param  VRMode: Specifies the mode of Voltage Regulator
  *          This parameter can be one of the following values:
  *            - @arg PWR_MAINREGULATOR_ON         : Voltage Regulator selects MR mode
  *            - @arg PWR_LOWPOWERREGULATOR_ON     : Voltage Regulator selects LPR mode
  * @retval None
  */
void HAL_PWREx_EnterLowPowerRunMode(uint32_t Regulator)
{
  /* LPRUN mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_2 | PWR_CR1_LPMS_1);
  
  /* Configure the Voltage Regulator mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, Regulator);
}

/**
  * @brief Exit Low-power Run mode.
  * @note  Before HAL_PWREx_ExitLowPowerRunMode() completion, the function checks that
  *        MR_RDY and LPRUN_RUN_SWF have been properly set (otherwise, 
  *        HAL_PWREx_ExitLowPowerRunMode() returns HAL_TIMEOUT status). 
  *        The system clock source must not be set to MSISYS.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_PWREx_ExitLowPowerRunMode(void)
{
  uint32_t wait_loop_index;

  /* Voltage Regulator selects MR mode */
  HAL_PWREx_SetVoltageRegulatorMode(PWR_MAINREGULATOR_ON);
  
  /* RUN mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, 0U);

  /* Wait until MR_RDY is set */
  wait_loop_index = (PWR_FLAG_SETTING_DELAY_US * (SystemCoreClock / 1000000U));
  while ((__HAL_PWR_GET_FLAG(PWR_FLAG_MR_RDY) == 0U) && (wait_loop_index != 0U))
  {
    wait_loop_index--;
  }
  
  /* Wait until LPRUN_RUN_SWF is set */
  wait_loop_index = (PWR_FLAG_SETTING_DELAY_US * (SystemCoreClock / 1000000U));
  while ((__HAL_PWR_GET_FLAG(PWR_FLAG_LPRUN_RUN_SW) == 0U) && (wait_loop_index != 0U))
  {
    wait_loop_index--;
  }
  
  if ((__HAL_PWR_GET_FLAG(PWR_FLAG_MR_RDY) == 0U) || (__HAL_PWR_GET_FLAG(PWR_FLAG_LPRUN_RUN_SW) == 0U))
  {
    return HAL_TIMEOUT;
  }

  return HAL_OK;
}

/**
  * @brief  Enter the whole system to Stop 0 mode.
  * @note   The system clock when exiting from Stop mode can be either MSISYS 
            or HSISYS, depending on software configuration.
  * @param  Regulator : Specifies the regulator state in Stop mode.
  *                     This parameter can be one of the following values :
  *                     @arg @ref PWR_MAINREGULATOR_ON        
  *                     @arg @ref PWR_LOWPOWERREGULATOR_ON    
  *                     @arg @ref PWR_DEEPLOWPOWERREGULATOR_ON
  * @param  STOPEntry : Specifies if Stop mode is entered with WFI or WFE
  *                     instruction.
  *                     This parameter can be one of the following values :
  *                     @arg @ref PWR_STOPENTRY_WFI enter Stop mode with Wait
  *                               For Interrupt request.
  *                     @arg @ref PWR_STOPENTRY_WFE enter Stop mode with Wait
  *                               For Event request.
  * @retval None.
  */
void HAL_PWREx_EnterSTOP0Mode(uint32_t Regulator, uint8_t STOPEntry)
{
  /* Check the parameters */
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

  /* Select Stop 0 mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_0);
  
  /* Configure the Voltage Regulator mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, Regulator);

  /* Set SLEEPDEEP bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select Stop mode entry */
  if (STOPEntry == PWR_STOPENTRY_WFI)
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
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
  }

  /* Reset SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}

/**
  * @brief  Enter the whole system to Stop 1 mode.
  * @note   The system clock when exiting from Stop mode can be either MSISYS or 
  *         HSISYS, depending on software configuration.
  * @param  STOPEntry : Specifies if Stop mode is entered with WFI or WFE
  *                     instruction.
  *                     This parameter can be one of the following values :
  *                     @arg @ref PWR_STOPENTRY_WFI enter Stop mode with Wait
  *                               For Interrupt request.
  *                     @arg @ref PWR_STOPENTRY_WFE enter Stop mode with Wait
  *                               For Event request.
  * @retval None.
  */
void HAL_PWREx_EnterSTOP1Mode(uint32_t Regulator, uint8_t STOPEntry)
{
  /* Check the parameters */
  assert_param(IS_PWR_REGULATOR(Regulator));
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

  /* Stop 1 mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_1);
  
  /* Configure the Voltage Regulator mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, Regulator);

  /* Set SLEEPDEEP bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select Stop mode entry */
  if (STOPEntry == PWR_STOPENTRY_WFI)
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
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
  }

  /* Reset SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}

/**
  * @brief  Enter the whole system to Stop 2 mode.
  * @note   The system clock when exiting from Stop mode can be either MSISYS or 
  *         HSISYS, depending on software configuration.
  * @param  STOPEntry : Specifies if Stop mode is entered with WFI or WFE
  *                     instruction.
  *                     This parameter can be one of the following values :
  *                     @arg @ref PWR_STOPENTRY_WFI enter Stop mode with Wait
  *                               For Interrupt request.
  *                     @arg @ref PWR_STOPENTRY_WFE enter Stop mode with Wait
  *                               For Event request.
  * @retval None.
  */
void HAL_PWREx_EnterSTOP2Mode(uint32_t Regulator, uint8_t STOPEntry)
{
  /* Check the parameters */
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

  /* Stop 2 mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_1 | PWR_CR1_LPMS_0);

  /* Configure the Voltage Regulator mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, Regulator);
  
  /* Set SLEEPDEEP bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select Stop mode entry */
  if (STOPEntry == PWR_STOPENTRY_WFI)
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
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
  }

  /* Reset SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}

/**
  * @brief  Enter the whole system to Stop 3 mode.
  * @note   In Stop 3 mode, the PLL, MSI,HSI and HSE oscillators are disabled.
  * @note   Stop mode achieves the lowest power consumption while retaining
  *         the content of SRAM and registers. The PLL, the MSI RC, the HSI RC 
  *         and the HSE crystal oscillators are disabled. The LSE or LSI is still
  *         running.
  * @note   The system clock when exiting from Stop mode can be either MSISYS or 
  *         HSISYS, depending on software configuration.
  * @param  STOPEntry : Specifies if Stop mode is entered with WFI or WFE
  *                     instruction.
  *                     This parameter can be one of the following values :
  *                     @arg @ref PWR_STOPENTRY_WFI enter Stop mode with Wait
  *                               For Interrupt request.
  *                     @arg @ref PWR_STOPENTRY_WFE enter Stop mode with Wait
  *                               For Event request.
  * @retval None.
  */
void HAL_PWREx_EnterSTOP3Mode(uint32_t Regulator, uint8_t STOPEntry)
{
  /* Check the parameter */
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

  /* Set Stop mode 3 */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, (PWR_CR1_LPMS_2));

  /* Configure the Voltage Regulator mode */
  MODIFY_REG(PWR->CR1, PWR_CR1_VR_MODE, Regulator);
  
  /* Set SLEEPDEEP bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select Stop mode entry */
  if (STOPEntry == PWR_STOPENTRY_WFI)
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
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
  }

  /* Reset SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
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
