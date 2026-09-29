/**
  ******************************************************************************
  * @file    py32c882_hal_lcd.c
  * @author  MCU Application Team
  * @brief   LCD Controller HAL module driver.
  *          This file provides firmware functions to manage the following 
  *          functionalities of the LCD Controller (LCD) peripheral:
  *           + Initialization/de-initialization methods
  *           + I/O operation methods
  *           + Peripheral State methods
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
#include "py32c882_hal_lcd.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

#ifdef HAL_LCD_MODULE_ENABLED

/** @addtogroup LCD
  * @brief LCD HAL module driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup LCD_Private
  * @{
  */
#define LCD_TIMEOUT_VALUE             2000U
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @addtogroup LCD_Exported_Functions
  * @{
  */

/** @addtogroup LCD_Exported_Functions_Group1
  *  @brief    Initialization and Configuration functions 
  *
@verbatim    
===============================================================================
            ##### Initialization and Configuration functions #####
 ===============================================================================  
    [..]

@endverbatim
  * @{
  */

/**
  * @brief  DeInitializes the LCD peripheral. 
  * @param  hlcd LCD handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCD_DeInit(LCD_HandleTypeDef *hlcd)
{
  uint32_t tickstart = 0x00U;

  /* Check the LCD handle allocation */
  if(hlcd == NULL)
  {
    return HAL_ERROR;
  }
  
  /* Check the parameters */
  assert_param(IS_LCD_ALL_INSTANCE(hlcd->Instance));

  /* Check the LCD peripheral state */
  if(hlcd->State == HAL_LCD_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  hlcd->State = HAL_LCD_STATE_BUSY;
  
  /* Disable the peripheral */
  __HAL_LCD_DISABLE(hlcd);

  /* Get timeout */
  tickstart = HAL_GetTick();

  /* Wait Until the LCD is enabled */
  while(__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_ENS) == SET)
  {
    if((HAL_GetTick() - tickstart ) > LCD_TIMEOUT_VALUE)
    { 
      hlcd->ErrorCode = HAL_LCD_ERROR_DISABLE;
      return HAL_TIMEOUT;
    } 
  }
 
  /* Clear SOF */
  __HAL_LCD_CLEAR_FLAG(hlcd,LCD_FLAG_SOF);

  /* DeInit the low level hardware */
  HAL_LCD_MspDeInit(hlcd);
  
  hlcd->ErrorCode = HAL_LCD_ERROR_NONE;
  hlcd->State = HAL_LCD_STATE_RESET;
    
  /* Release Lock */
  __HAL_UNLOCK(hlcd);
  
  return HAL_OK;  
}

/**
  * @brief  Initializes the LCD peripheral according to the specified parameters 
  *         in the LCD_InitStruct.
  * @param  hlcd LCD handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCD_Init(LCD_HandleTypeDef *hlcd)
{
  uint32_t tickstart = 0x00U;
  uint32_t counter = 0x00U;

  /* Check the LCD handle allocation */
  if(hlcd == NULL)
  {
    return HAL_ERROR;
  }
  
  /* Check function parameters */
  assert_param(IS_LCD_ALL_INSTANCE(hlcd->Instance));
  assert_param(IS_LCD_SCAN_FREQ(hlcd->Init.ScanFreq));
  assert_param(IS_LCD_DEAD_TIME(hlcd->Init.DeadTime));
  assert_param(IS_LCD_CONTRAST(hlcd->Init.Contrast));
  assert_param(IS_LCD_VOLTAGE_SOURCE(hlcd->Init.VoltageSource));
  assert_param(IS_LCD_COMSEGDRIVE_TYPE(hlcd->Init.ComSegDriveType));
  assert_param(IS_LCD_FASTCHARGE_CYCLE(hlcd->Init.FastChargeCycle));
#if defined(LCD_CR_VSEL)
  assert_param(IS_LCD_CHARGEPUMP_FREQ(hlcd->Init.ChargePumpFreq));
  assert_param(IS_LCD_CHARGEPUMP_SETTIME(hlcd->Init.ChargePumpSetTime));
#endif
  assert_param(IS_LCD_BIAS_SRC(hlcd->Init.BiasSrc));
  assert_param(IS_LCD_DUTY(hlcd->Init.Duty));
  assert_param(IS_LCD_BIAS(hlcd->Init.Bias));
  assert_param(IS_LCD_MODE(hlcd->Init.Mode));
  assert_param(IS_LCD_BLINK_FREQ(hlcd->Init.BlinkFrequency)); 
  assert_param(IS_LCD_CAPDRIVE_NUMBER(hlcd->Init.CapDriveNumber));

  if(hlcd->State == HAL_LCD_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    __HAL_UNLOCK(hlcd);

    /* Initialize the low level hardware (MSP) */
    HAL_LCD_MspInit(hlcd);
  }
  
  hlcd->State = HAL_LCD_STATE_BUSY;
  
  /* Disable the peripheral */
  __HAL_LCD_DISABLE(hlcd);

  /* Get timeout */
  tickstart = HAL_GetTick();

  /* Wait Until the LCD is enabled */
  while(__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_ENS) == SET)
  {
    if((HAL_GetTick() - tickstart ) > LCD_TIMEOUT_VALUE)
    { 
      hlcd->ErrorCode = HAL_LCD_ERROR_DISABLE;
      return HAL_TIMEOUT;
    } 
  }

  /* Clear the LCD_RAM registers and enable the display request by setting the UDR bit
     in the LCD_SR register */
  for(counter = LCD_RAM_REGISTER0; counter <= LCD_RAM_REGISTER15; counter++)
  {
    hlcd->Instance->RAM[counter] = 0U;
  }
  /* Enable the display request */
  SET_BIT(hlcd->Instance->CSR, LCD_CSR_UDR);

  /* Config LCD Clock/Dead Time/ MODE A/B*/
  MODIFY_REG(hlcd->Instance->CR, (LCD_CR_LCDCLK | LCD_CR_DEAD | LCD_CR_COMSEG_DRV_TYPE), (hlcd->Init.ScanFreq | hlcd->Init.DeadTime | hlcd->Init.ComSegDriveType));

  /* Config Blink Enable/BlinkCnt/Mode0/1 */
  MODIFY_REG(hlcd->Instance->CSR, (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT | LCD_CSR_MODE), hlcd->Init.BlinkFrequency | hlcd->Init.Mode);

  if(hlcd->Init.VoltageSource == LCD_VOLTAGE_SOURCE_VCCA)
  {
#if defined(LCD_CR_VSEL)
    /* Set Voltage VCCA */
    CLEAR_BIT(hlcd->Instance->CR,LCD_CR_VSEL);
#endif
  }
  else
  {
#if defined(LCD_CR_VSEL)
    /* Set Voltage/CP Freq/CP Setup time */ 
    MODIFY_REG(hlcd->Instance->CR, (LCD_CR_VSEL | LCD_CR_VCP_SEL | LCD_CR_CP_FRQ | LCD_CR_CP_ST), hlcd->Init.VoltageSource | hlcd->Init.ChargePumpFreq | hlcd->Init.ChargePumpSetTime);
#endif
  }

  if(hlcd->Init.Duty == LCD_DUTY_STATIC)
  {
    CLEAR_BIT(hlcd->Instance->CR, LCD_CR_DUTY);

    /* If Select VCCA, can select Internal_Resistance/External_Resistance/External_Capacitance */
    /* Else Only can select Internal_Resistance */
    if(hlcd->Init.VoltageSource == LCD_VOLTAGE_SOURCE_VCCA)
    {
      MODIFY_REG(hlcd->Instance->CR,LCD_CR_BSEL, hlcd->Init.BiasSrc);  
    }
    else
    {
      if(hlcd->Init.BiasSrc == LCD_BIAS_SOURCE_INTERNAL_RESISTANCE)
      {
        MODIFY_REG(hlcd->Instance->CR,LCD_CR_BSEL, hlcd->Init.BiasSrc);  
      }
      else
      {
        /* Process Unlocked */
        __HAL_UNLOCK(hlcd);
        return HAL_ERROR;
      }
    }
  }
  else
  {
    /* If Select VCCA, can select Internal_Resistance/External_Resistance/External_Capacitance */
    /* Else Only can select Internal_Resistance */
    if(hlcd->Init.VoltageSource == LCD_VOLTAGE_SOURCE_VCCA)
    {
      MODIFY_REG(hlcd->Instance->CR,LCD_CR_DUTY | LCD_CR_BIAS | LCD_CR_BSEL , hlcd->Init.Duty | hlcd->Init.Bias | hlcd->Init.BiasSrc);
   
      if(hlcd->Init.BiasSrc == LCD_BIAS_SOURCE_EXTERNAL_CAPACITANCE)
      { 
        /* Modify Cap Drv Numbers */
        MODIFY_REG(hlcd->Instance->CSR, LCD_CSR_SWCAP_DRV_NUM, hlcd->Init.CapDriveNumber); 
      }
      else if(hlcd->Init.BiasSrc == LCD_BIAS_SOURCE_INTERNAL_RESISTANCE)
      {
        /* Modify Fast Charge Control / Contrast */
        MODIFY_REG(hlcd->Instance->CR, LCD_CR_FCCTL | LCD_CR_CONTRAST, hlcd->Init.FastChargeCycle | hlcd->Init.Contrast);   
      }
      else
      {
        /* External_Resistance No Config */
      }
    }
    else
    {
      if(hlcd->Init.BiasSrc == LCD_BIAS_SOURCE_INTERNAL_RESISTANCE)
      {
        MODIFY_REG(hlcd->Instance->CR,LCD_CR_DUTY | LCD_CR_BIAS | LCD_CR_BSEL , hlcd->Init.Duty | hlcd->Init.Bias | hlcd->Init.BiasSrc);
        
        /* Modify Fast Charge Control / Contrast */
        MODIFY_REG(hlcd->Instance->CR, LCD_CR_FCCTL | LCD_CR_CONTRAST, hlcd->Init.FastChargeCycle | hlcd->Init.Contrast);   
      }  
      else
      {
        /* Process Unlocked */
        __HAL_UNLOCK(hlcd);
        return HAL_ERROR;
      }
    }  
  }
  
  /* Clear SOF */
  __HAL_LCD_CLEAR_FLAG(hlcd,LCD_FLAG_SOF);

  /* Enable the peripheral */
  __HAL_LCD_ENABLE(hlcd);

  /* Get timeout */
  tickstart = HAL_GetTick();
      
  /* Wait Until the LCD is enabled */
  while(__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_ENS) == RESET)
  {
    if((HAL_GetTick() - tickstart ) > LCD_TIMEOUT_VALUE)
    { 
      hlcd->ErrorCode = HAL_LCD_ERROR_ENS;
      return HAL_TIMEOUT;
    } 
  }

  /* Initialize the LCD state */
  hlcd->ErrorCode = HAL_LCD_ERROR_NONE;
  hlcd->State= HAL_LCD_STATE_READY;
  
  return HAL_OK;
}

/**
  * @brief  LCD MSP DeInit.
  * @param  hlcd LCD handle
  * @retval None
  */
 __weak void HAL_LCD_MspDeInit(LCD_HandleTypeDef *hlcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcd);

  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_LCD_MspDeInit could be implemented in the user file
   */ 
}

/**
  * @brief  LCD MSP Init.
  * @param  hlcd LCD handle
  * @retval None
  */
 __weak void HAL_LCD_MspInit(LCD_HandleTypeDef *hlcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcd);

  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_LCD_MspInit could be implemented in the user file
   */ 
}

/**
  * @}
  */

/** @addtogroup LCD_Exported_Functions_Group2
  *  @brief LCD RAM functions 
  *
@verbatim   
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================      
@endverbatim
  * @{
  */

/**
  * @brief  LCD SEG COM port output enable configuration.
  * @param  hlcd LCD handle
  * @param  SegCom pointer to a LCD_SegComTypeDef structure that contains
  *         the configuration information for LCD SEG COM port output enable.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCD_SetSegCom(LCD_HandleTypeDef *hlcd, LCD_SegComTypeDef *SegCom)
{
  if(hlcd->State == HAL_LCD_STATE_READY)
  {
    __HAL_LOCK(hlcd);
    hlcd->State = HAL_LCD_STATE_BUSY;
    
    WRITE_REG(hlcd->Instance->POEN0, SegCom->Seg0_31);
    WRITE_REG(hlcd->Instance->POEN1, SegCom->Seg32_39_Com0_7_t.Seg32_39_Com0_7);
    
    hlcd->State = HAL_LCD_STATE_READY;
    __HAL_UNLOCK(hlcd);
    
    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}

/**
  * @brief  Writes a word in the specific LCD RAM.
  * @param  hlcd LCD handle
  * @param  RAMRegisterIndex specifies the LCD RAM Register.
  *   This parameter can be one of the following values:
  *     @arg LCD_RAM_REGISTER0: LCD RAM Register 0
  *     @arg LCD_RAM_REGISTER1: LCD RAM Register 1
  *     @arg LCD_RAM_REGISTER2: LCD RAM Register 2
  *     @arg LCD_RAM_REGISTER3: LCD RAM Register 3
  *     @arg LCD_RAM_REGISTER4: LCD RAM Register 4
  *     @arg LCD_RAM_REGISTER5: LCD RAM Register 5
  *     @arg LCD_RAM_REGISTER6: LCD RAM Register 6 
  *     @arg LCD_RAM_REGISTER7: LCD RAM Register 7  
  *     @arg LCD_RAM_REGISTER8: LCD RAM Register 8
  *     @arg LCD_RAM_REGISTER9: LCD RAM Register 9
  *     @arg LCD_RAM_REGISTER10: LCD RAM Register 10
  *     @arg LCD_RAM_REGISTER11: LCD RAM Register 11
  *     @arg LCD_RAM_REGISTER12: LCD RAM Register 12 
  *     @arg LCD_RAM_REGISTER13: LCD RAM Register 13 
  *     @arg LCD_RAM_REGISTER14: LCD RAM Register 14 
  *     @arg LCD_RAM_REGISTER15: LCD RAM Register 15
  * @param  Data specifies LCD Data Value to be written.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCD_Write(LCD_HandleTypeDef *hlcd, uint32_t RAMRegisterIndex, uint32_t Data)
{
  uint32_t tickstart = 0x00U; 
  if(hlcd->State == HAL_LCD_STATE_READY)
  {
    /* Check the parameters */
    assert_param(IS_LCD_RAM_REGISTER(RAMRegisterIndex));
    
    __HAL_LOCK(hlcd);
    hlcd->State = HAL_LCD_STATE_BUSY;

    /* Get timeout */
    tickstart = HAL_GetTick();
      
    /*!< Wait Until the LCD is ready */
    while(__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_UDR) != RESET)
    {
      if((HAL_GetTick() - tickstart) > LCD_TIMEOUT_VALUE)
      { 
        hlcd->ErrorCode = HAL_LCD_ERROR_UDR;      
        /* Process Unlocked */
        __HAL_UNLOCK(hlcd);
        return HAL_TIMEOUT;
      } 
    }
    
    WRITE_REG(hlcd->Instance->RAM[RAMRegisterIndex], Data);
    
    hlcd->State = HAL_LCD_STATE_READY;

    __HAL_UNLOCK(hlcd);
    
    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}

/**
  * @brief Clears the LCD RAM registers.
  * @param hlcd: LCD handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCD_Clear(LCD_HandleTypeDef *hlcd)
{
  uint32_t tickstart = 0x00U; 
  uint32_t counter = 0U;
  HAL_StatusTypeDef status = HAL_ERROR;

  if(hlcd->State == HAL_LCD_STATE_READY)
  {
    __HAL_LOCK(hlcd);
    hlcd->State = HAL_LCD_STATE_BUSY;

    /* Get timeout */
    tickstart = HAL_GetTick();
    
    /*!< Wait Until the LCD is ready */
    while(__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_UDR) != RESET)
    {
      if( (HAL_GetTick() - tickstart) > LCD_TIMEOUT_VALUE)
      { 
        hlcd->ErrorCode = HAL_LCD_ERROR_UDR;

        /* Process Unlocked */
        __HAL_UNLOCK(hlcd);

        return HAL_TIMEOUT;
      } 
    }

    /* Clear the LCD_RAM registers */
    for(counter = LCD_RAM_REGISTER0; counter <= LCD_RAM_REGISTER15; counter++)
    {
      hlcd->Instance->RAM[counter] = 0U;
    }

    /* Update the LCD display */
    status = HAL_LCD_UpdateDisplayRequest(hlcd);  
    
    hlcd->State = HAL_LCD_STATE_READY;

    __HAL_UNLOCK(hlcd);
    
    return status;
  }
  else
  {
    return HAL_ERROR;
  }
}

/**
  * @brief  Waits until the LCD SOF
  * @param  hlcd LCD handle
  * @retval None
  */
HAL_StatusTypeDef HAL_LCD_WaitForSOF(LCD_HandleTypeDef *hlcd)
{
  uint32_t tickstart = 0x00U; 
  
  /* Get timeout */
  tickstart = HAL_GetTick();

  /*!< Wait Until the SOF */
  while(__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_SOF) == RESET)
  {
    if((HAL_GetTick() - tickstart ) > LCD_TIMEOUT_VALUE)
    { 
      hlcd->ErrorCode = HAL_LCD_ERROR_SOF;
      
      /* Process Unlocked */
      __HAL_UNLOCK(hlcd);
  
      return HAL_TIMEOUT;
    }
  }
 
  __HAL_LCD_CLEAR_FLAG(hlcd,LCD_FLAG_SOF);

  return HAL_OK;
}

/**
  * @brief  Enables the Update Display Request.
  * @param  hlcd LCD handle
  * @note   Each time software modifies the LCD_RAM it must set the UDR bit to 
  *         transfer the updated data to the second level buffer. 
  *         The UDR bit stays set until the end of the update and during this 
  *         time the LCD_RAM is write protected.  
  * @retval None
  */
HAL_StatusTypeDef HAL_LCD_UpdateDisplayRequest(LCD_HandleTypeDef *hlcd)
{
  uint32_t tickstart = 0x00U;
  
  /* Clear the Update Display Done flag before starting the update display request */
  __HAL_LCD_CLEAR_FLAG(hlcd, LCD_FLAG_UDD);
  
  /* Enable the display request */
  hlcd->Instance->CSR |= LCD_CSR_UDR;
  
  /* Get timeout */
  tickstart = HAL_GetTick();
  
  /*!< Wait Until the LCD display is done */
  while(__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_UDD) == RESET)
  {
    if((HAL_GetTick() - tickstart ) > LCD_TIMEOUT_VALUE)
    { 
      hlcd->ErrorCode = HAL_LCD_ERROR_UDD;
      
      /* Process Unlocked */
      __HAL_UNLOCK(hlcd);
  
      return HAL_TIMEOUT;
    }
  }

  hlcd->State = HAL_LCD_STATE_READY;
  
  /* Process Unlocked */
  __HAL_UNLOCK(hlcd);
  
  return HAL_OK;
}

/**
  * @brief  Enables the Update Display Request with Interrupt.
  * @param  hlcd LCD handle 
  * @retval None
  */
HAL_StatusTypeDef HAL_LCD_UpdateDisplayRequest_IT(LCD_HandleTypeDef *hlcd)
{
  hlcd->State = HAL_LCD_STATE_BUSY;
  
  /* Clear the Update Display Done flag before starting the update display request */
  __HAL_LCD_CLEAR_FLAG(hlcd, LCD_FLAG_UDD);

  __HAL_LCD_ENABLE_IT(hlcd,LCD_IT_UDD);
  
  /* Enable the display request */
  hlcd->Instance->CSR |= LCD_CSR_UDR;
    
  return HAL_OK;
}

/**
  * @brief  This function handles LCD interrupt request.
  * @param  hlcd LCD handle
  * @retval None
  */
void HAL_LCD_IRQHandler(LCD_HandleTypeDef *hlcd)
{
  if ((__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_UDD) != RESET) && (__HAL_LCD_GET_IT_SOURCE(hlcd, LCD_IT_UDD) != RESET))
  {
    __HAL_LCD_DISABLE_IT(hlcd,LCD_IT_UDD);   

    /* Call LCD interrupt callbacks */
    HAL_LCD_UDDCallback(hlcd);

    /* Clear interrupt flag */
    __HAL_LCD_CLEAR_FLAG(hlcd, LCD_FLAG_UDD);

    hlcd->State = HAL_LCD_STATE_READY;
  }
  if ((__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_SOF) != RESET) && (__HAL_LCD_GET_IT_SOURCE(hlcd, LCD_IT_SOF) != RESET))
  {
    /* Call LCD interrupt callbacks */
    HAL_LCD_SOFCallback(hlcd);

    /* Clear interrupt flag */
    __HAL_LCD_CLEAR_FLAG(hlcd, LCD_FLAG_SOF);

  }
  if ((__HAL_LCD_GET_FLAG(hlcd, LCD_FLAG_BKF) != RESET) && (__HAL_LCD_GET_IT_SOURCE(hlcd, LCD_IT_BKF) != RESET))
  {    
    /* Call LCD interrupt callbacks */
    HAL_LCD_BKFCallback(hlcd);

    /* Clear interrupt flag */
    __HAL_LCD_CLEAR_FLAG(hlcd, LCD_FLAG_BKF);

  }
}

/**
  * @brief  LCD interrupt callbacks.
  * @param  hlcd LCD handle
  * @retval None
  */
__weak void HAL_LCD_UDDCallback(LCD_HandleTypeDef *hlcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcd);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LCD_Callback could be implemented in the user file
   */
}

/**
  * @brief  LCD interrupt callbacks.
  * @param  hlcd LCD handle
  * @retval None
  */
__weak void HAL_LCD_SOFCallback(LCD_HandleTypeDef *hlcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcd);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LCD_Callback could be implemented in the user file
   */
}

/**
  * @brief  LCD interrupt callbacks.
  * @param  hlcd LCD handle
  * @retval None
  */
__weak void HAL_LCD_BKFCallback(LCD_HandleTypeDef *hlcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcd);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LCD_Callback could be implemented in the user file
   */
}

/**
  * @}
  */

/** @addtogroup LCD_Exported_Functions_Group3
  *  @brief   LCD State functions 
  *
@verbatim   
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================  
    [..]
     This subsection provides a set of functions allowing to control the LCD:
      (+) HAL_LCD_GetState() API can be helpful to check in run-time the state of the LCD peripheral State. 
      (+) HAL_LCD_GetError() API to return the LCD error code. 
@endverbatim
  * @{
  */

/**
  * @brief Returns the LCD state.
  * @param hlcd: LCD handle
  * @retval HAL state
  */
HAL_LCD_StateTypeDef HAL_LCD_GetState(LCD_HandleTypeDef *hlcd)
{
  return hlcd->State;
}

/**
  * @brief Return the LCD error code
  * @param hlcd: LCD handle
  * @retval LCD Error Code
  */
uint32_t HAL_LCD_GetError(LCD_HandleTypeDef *hlcd)
{
  return hlcd->ErrorCode;
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
  
/**
  * @}
  */

#endif /* HAL_LCD_MODULE_ENABLED */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
