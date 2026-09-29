/**
  ******************************************************************************
  * @file    py32c882_ll_lcd.h
  * @author  MCU Application Team
  * @brief   Header file of LCD LL module.
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
#ifndef __PY32C882_LL_LCD_H
#define __PY32C882_LL_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c8xx.h"
/** @addtogroup PY32C882_LL_Driver
  * @{
  */

#if defined (LCD)

/** @defgroup LCD_LL LCD
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup LCD_LL_ES_INIT LCD Exported Init structures
  * @{
  */

typedef struct
{
  uint32_t Contrast;        /*!< Configures the LCD Contrast.
                                 This parameter can be one value of @ref LCD_LL_EC_Contrast */
  uint32_t BiasSrc;         /*!< Configures the LCD Bias Source.
                                 This parameter can be one value of @ref LCD_LL_EC_BiasSource */
  uint32_t Duty;            /*!< Configures the LCD Duty.
                                 This parameter can be one value of @ref LCD_LL_EC_Duty */
  uint32_t Bias;            /*!< Configures the LCD Bias.
                                 This parameter can be one value of @ref LCD_LL_EC_Bias */
  uint32_t ScanFreq;         /*!< Configures the LCD Scan Frequency.
                                 This parameter can be one value of @ref LCD_LL_EC_ScanFrequency */

  uint32_t ComSegDriveType;  /*!< Configures the LCD COM/SEG Drive Type.
                                 This parameter can be one value of @ref LCD_LL_EC_ComSegDriveType */

  uint32_t Mode;            /*!< Configures the LCD Mode.
                                 This parameter can be one value of @ref LCD_LL_EC_Mode */
}LL_LCD_InitTypeDef;


typedef struct
{
    uint32_t Seg0_31;
    union{
        uint32_t Seg32_39_Com0_7;
        struct
        {
            uint32_t Seg32_35     :4;
            uint32_t Seg36Com4    :1;
            uint32_t Seg37Com5    :1;
            uint32_t Seg38Com6    :1;
            uint32_t Seg39Com7    :1;
            uint32_t Com0_3       :4;
        }SegComBit;
    }Seg32_39_Com0_7_t;
}LL_LCD_SegComTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup LCD_LL_Exported_Constants LCD Exported Constants
  * @{
  */



/** @defgroup LCD_LL_EC_BiasSource LCD Bias Source
  * @{
  */
#define LL_LCD_BIAS_SOURCE_INTERNAL_RESISTANCE     ((uint32_t)0x00000000U)          /* Internal resistance mode */
#define LL_LCD_BIAS_SOURCE_EXTERNAL_RESISTANCE     (LCD_CR_BSEL_0)                  /* External resistance mode */
#define LL_LCD_BIAS_SOURCE_EXTERNAL_CAPACITANCE    (LCD_CR_BSEL_1)                  /* External capacitance mode */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_DEADTIME LCD Dead Time
  * @{
  */
#define LL_LCD_DEAD_TIME_0                 ((uint32_t)0x00000000U)                          /*!< NO DeadTime */
#define LL_LCD_DEAD_TIME_1                 (LCD_CR_DEAD_0)                                  /*!< DeadTime 1   */
#define LL_LCD_DEAD_TIME_2                 (LCD_CR_DEAD_1)                                  /*!< DeadTime 2   */
#define LL_LCD_DEAD_TIME_3                 (LCD_CR_DEAD_1 | LCD_CR_DEAD_0)                  /*!< DeadTime 3  */
#define LL_LCD_DEAD_TIME_4                 (LCD_CR_DEAD_2)                                  /*!< DeadTime 4   */
#define LL_LCD_DEAD_TIME_5                 (LCD_CR_DEAD_2 | LCD_CR_DEAD_0)                  /*!< DeadTime 5    */
#define LL_LCD_DEAD_TIME_6                 (LCD_CR_DEAD_2 | LCD_CR_DEAD_1)                  /*!< DeadTime 6    */
#define LL_LCD_DEAD_TIME_7                 (LCD_CR_DEAD_2 | LCD_CR_DEAD_1 | LCD_CR_DEAD_0)  /*!< DeadTime 7    */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_FastCharge_Cycle LCD FastCharge Cycle
  * @{
  */
#define LL_LCD_FASTCHARGE_CYCLE_1_2        ((uint32_t)0x00000000U)             /* Fast Charge 1/2 Cycle */
#define LL_LCD_FASTCHARGE_CYCLE_1_4        (LCD_CR_FCCTL_0)                    /* Fast Charge 1/4 Cycle */
#define LL_LCD_FASTCHARGE_CYCLE_1_8        (LCD_CR_FCCTL_1)                    /* Fast Charge 1/8 Cycle */
#define LL_LCD_FASTCHARGE_CYCLE_1_16       (LCD_CR_FCCTL_0 | LCD_CR_FCCTL_1)   /* Fast Charge 1/16 Cycle */
#define LL_LCD_FASTCHARGE_CYCLE_1_32       (LCD_CR_FCCTL_2)                    /* Fast Charge 1/32 Cycle */
#define LL_LCD_FASTCHARGE_CYCLE_1_64       (LCD_CR_FCCTL_2 | LCD_CR_FCCTL_0)   /* Fast Charge 1/64 Cycle */
#define LL_LCD_FASTCHARGE_CYCLE_1_128      (LCD_CR_FCCTL_2 | LCD_CR_FCCTL_1)   /* Fast Charge 1/128 Cycle */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_VOLTAGE_SOURCE LCD Voltage Source
  * @{
  */
/* #define LL_LCD_VOLTAGE_SOURCE_VCCA                    ((uint32_t)0x00000000U)                  */         /* From VCCA */
/* #define LL_LCD_VOLTAGE_SOURCE_INTERNALVOLTAGE         (LCD_CR_VSEL)                            */         /* From Internal Voltage */
/**
  * @}
  */


/** @defgroup LCD_LL_EC_VOLTAGE_LEVEL LCD Voltage Level
  * @{
  */
/* #define LL_LCD_VOLTAGE_LEVEL_2P6          ((uint32_t)0x00000000U)                             */             /* 2.6V VCP SEL */
/* #define LL_LCD_VOLTAGE_LEVEL_2P74         (LCD_CR_VCP_SEL_0)                                  */             /* 2.74V VCP SEL */
/* #define LL_LCD_VOLTAGE_LEVEL_2P88         (LCD_CR_VCP_SEL_1)                                  */             /* 2.88V VCP SEL */
/* #define LL_LCD_VOLTAGE_LEVEL_3P02         (LCD_CR_VCP_SEL_0 | LCD_CR_VCP_SEL_1)               */             /* 3.02V VCP SEL */
/* #define LL_LCD_VOLTAGE_LEVEL_3P16         (LCD_CR_VCP_SEL_2)                                  */             /* 3.16V VCP SEL */
/* #define LL_LCD_VOLTAGE_LEVEL_3P3          (LCD_CR_VCP_SEL_2 | LCD_CR_VCP_SEL_0)               */             /* 3.3V VCP SEL */
/* #define LL_LCD_VOLTAGE_LEVEL_3P44         (LCD_CR_VCP_SEL_2 | LCD_CR_VCP_SEL_1)               */             /* 3.44V VCP SEL */
/* #define LL_LCD_VOLTAGE_LEVEL_3P58         (LCD_CR_VCP_SEL_2 | LCD_CR_VCP_SEL_1 | LCD_CR_VCP_SEL_0)   */      /* 3.58V VCP SEL */

/**
  * @}
  */

/** @defgroup LCD_LL_EC_ChargePump_Settime LCD ChargePump Settime
  * @{
  */
/* #define LL_LCD_CHARGEPUMP_SETTIME_256CLOCK        ((uint32_t)0x00000000U)             */     /* ChargePump Settime 256 LSE/LSI Clocks */
/* #define LL_LCD_CHARGEPUMP_SETTIME_512CLOCK        (LCD_CR_CP_ST_0)                    */     /* ChargePump Settime 512 LSE/LSI Clocks */
/* #define LL_LCD_CHARGEPUMP_SETTIME_1024CLOCK       (LCD_CR_CP_ST_1)                    */     /* ChargePump Settime 1024 LSE/LSI Clocks */
/* #define LL_LCD_CHARGEPUMP_SETTIME_2048CLOCK       (LCD_CR_CP_ST_0 | LCD_CR_CP_ST_1)   */     /* ChargePump Settime 2048 LSE/LSI Clocks */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_ChargePump_Freq LCD ChargePump Freq
  * @{
  */
/* #define LL_LCD_CHARGEPUMP_FREQ_512HZ        ((uint32_t)0x00000000U)                  */     /* ChargePump Freq 512 Hz */
/* #define LL_LCD_CHARGEPUMP_FREQ_1024HZ       (LCD_CR_CP_FRQ_0)                        */     /* ChargePump Freq 1024 Hz */
/* #define LL_LCD_CHARGEPUMP_FREQ_2048HZ       (LCD_CR_CP_FRQ_1)                        */     /* ChargePump Freq 2048 Hz */
/* #define LL_LCD_CHARGEPUMP_FREQ_4096HZ       (LCD_CR_CP_FRQ_0 | LCD_CR_CP_FRQ_1)      */     /* ChargePump Freq 4096 Hz */
/* #define LL_LCD_CHARGEPUMP_FREQ_8192HZ       (LCD_CR_CP_FRQ_2)                        */     /* ChargePump Freq 8192 Hz */
/* #define LL_LCD_CHARGEPUMP_FREQ_16384HZ      (LCD_CR_CP_FRQ_2 | LCD_CR_CP_FRQ_0)      */     /* ChargePump Freq 16384 Hz */
/**
  * @}
  */


/** @defgroup LCD_LL_EC_ComSegDriveType LCD ComSegDrive Type
  * @{
  */
#define LL_LCD_COMSEGDRIVE_TYPE_A                 ((uint32_t)0x00000000U)             /*!< Com/Seg Drive Type A */
#define LL_LCD_COMSEGDRIVE_TYPE_B                 (LCD_CR_COMSEG_DRV_TYPE)            /*!< Com/Seg Drive Type B */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_Contrast LCD Contrast
  * @{
  */
#define LL_LCD_CONTRASTLEVEL_0               ((uint32_t)0x00000000U)
#define LL_LCD_CONTRASTLEVEL_1               (LCD_CR_CONTRAST_0)
#define LL_LCD_CONTRASTLEVEL_2               (LCD_CR_CONTRAST_1)
#define LL_LCD_CONTRASTLEVEL_3               (LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)
#define LL_LCD_CONTRASTLEVEL_4               (LCD_CR_CONTRAST_2)
#define LL_LCD_CONTRASTLEVEL_5               (LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_0)
#define LL_LCD_CONTRASTLEVEL_6               (LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1)
#define LL_LCD_CONTRASTLEVEL_7               (LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)
#define LL_LCD_CONTRASTLEVEL_8               (LCD_CR_CONTRAST_3)
#define LL_LCD_CONTRASTLEVEL_9               (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_0)
#define LL_LCD_CONTRASTLEVEL_10              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_1)
#define LL_LCD_CONTRASTLEVEL_11              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)
#define LL_LCD_CONTRASTLEVEL_12              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2)
#define LL_LCD_CONTRASTLEVEL_13              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_0)
#define LL_LCD_CONTRASTLEVEL_14              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1)
#define LL_LCD_CONTRASTLEVEL_15              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)
/**
  * @}
  */

/** @defgroup LCD_LL_EC_Duty LCD Duty
  * @{
  */
#define LL_LCD_DUTY_STATIC                 ((uint32_t)0x00000000U)                              /*!< Static duty */
#define LL_LCD_DUTY_1_2                    (LCD_CR_DUTY_0)                                      /*!< 1/2 duty    */
#define LL_LCD_DUTY_1_3                    (LCD_CR_DUTY_1)                                      /*!< 1/3 duty    */
#define LL_LCD_DUTY_1_4                    ((LCD_CR_DUTY_1 | LCD_CR_DUTY_0))                    /*!< 1/4 duty    */
#define LL_LCD_DUTY_1_6                    ((LCD_CR_DUTY_2 | LCD_CR_DUTY_0))                    /*!< 1/6 duty    */
#define LL_LCD_DUTY_1_8                    ((LCD_CR_DUTY_2 | LCD_CR_DUTY_1 | LCD_CR_DUTY_0))    /*!< 1/8 duty    */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_Bias LCD Bias
  * @{
  */
#define LL_LCD_BIAS_1_4                    ((uint32_t)0x00000000U)   /*!< 1/4 Bias */
#define LL_LCD_BIAS_1_2                    (LCD_CR_BIAS_0)           /*!< 1/2 Bias */
#define LL_LCD_BIAS_1_3                    (LCD_CR_BIAS_1)           /*!< 1/3 Bias */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_ScanFrequency LCD Scan Frequency
  * @{
  */
#define LL_LCD_SCAN_FREQ_64HZ               ((uint32_t)0x00000000U)                  /*!< Scan Frequency 64Hz */
#define LL_LCD_SCAN_FREQ_128HZ              (LCD_CR_LCDCLK_0)                        /*!< Scan Frequency 128Hz */
#define LL_LCD_SCAN_FREQ_256HZ              (LCD_CR_LCDCLK_1)                        /*!< Scan Frequency 256Hz */
#define LL_LCD_SCAN_FREQ_512HZ              (LCD_CR_LCDCLK_1 | LCD_CR_LCDCLK_0)      /*!< Scan Frequency 512Hz */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_Mode LCD Mode
  * @{
  */
#define LL_LCD_MODE_0                    ((uint32_t)0x00000000U)                     /*!< LCD Mode 0 */
#define LL_LCD_MODE_1                    (LCD_CSR_MODE)                              /*!< LCD Mode 1 */
/**
  * @}
  */

/** @defgroup LCD_LL_EC_SWCapDrive_Number LCD SWCapDrive Number
  * @{
  */
#define LL_LCD_SWCAPDRIVE_NUMBER_4          (0x00000000U)
#define LL_LCD_SWCAPDRIVE_NUMBER_8          (LCD_CSR_SWCAP_DRV_NUM_0)
#define LL_LCD_SWCAPDRIVE_NUMBER_16         (LCD_CSR_SWCAP_DRV_NUM_1)
#define LL_LCD_SWCAPDRIVE_NUMBER_32         (LCD_CSR_SWCAP_DRV_NUM_1 | LCD_CSR_SWCAP_DRV_NUM_0)
#define LL_LCD_SWCAPDRIVE_NUMBER_64         (LCD_CSR_SWCAP_DRV_NUM_2)
/**
  * @}
  */

/** @defgroup LCD_LL_EC_RAMRegister LCD RAMRegister
  * @{
  */
#define LL_LCD_RAM_REGISTER0               ((uint32_t)0x00000000U) /*!< LCD RAM Register 0  */
#define LL_LCD_RAM_REGISTER1               ((uint32_t)0x00000001U) /*!< LCD RAM Register 1  */
#define LL_LCD_RAM_REGISTER2               ((uint32_t)0x00000002U) /*!< LCD RAM Register 2  */
#define LL_LCD_RAM_REGISTER3               ((uint32_t)0x00000003U) /*!< LCD RAM Register 3  */
#define LL_LCD_RAM_REGISTER4               ((uint32_t)0x00000004U) /*!< LCD RAM Register 4  */
#define LL_LCD_RAM_REGISTER5               ((uint32_t)0x00000005U) /*!< LCD RAM Register 5  */
#define LL_LCD_RAM_REGISTER6               ((uint32_t)0x00000006U) /*!< LCD RAM Register 6  */
#define LL_LCD_RAM_REGISTER7               ((uint32_t)0x00000007U) /*!< LCD RAM Register 7  */
#define LL_LCD_RAM_REGISTER8               ((uint32_t)0x00000008U) /*!< LCD RAM Register 8  */
#define LL_LCD_RAM_REGISTER9               ((uint32_t)0x00000009U) /*!< LCD RAM Register 9  */
#define LL_LCD_RAM_REGISTER10              ((uint32_t)0x0000000AU) /*!< LCD RAM Register 10  */
#define LL_LCD_RAM_REGISTER11              ((uint32_t)0x0000000BU) /*!< LCD RAM Register 11  */
#define LL_LCD_RAM_REGISTER12              ((uint32_t)0x0000000CU) /*!< LCD RAM Register 12  */
#define LL_LCD_RAM_REGISTER13              ((uint32_t)0x0000000DU) /*!< LCD RAM Register 13  */
#define LL_LCD_RAM_REGISTER14              ((uint32_t)0x0000000EU) /*!< LCD RAM Register 14  */
#define LL_LCD_RAM_REGISTER15              ((uint32_t)0x0000000FU) /*!< LCD RAM Register 15  */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup LCD_LL_Exported_Macros LCD Exported Macros
  * @{
  */

/** @defgroup LCD_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in LCD register
  * @param  __INSTANCE__ LCD Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_LCD_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in LCD register
  * @param  __INSTANCE__ LCD Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_LCD_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */
  
/* Exported functions --------------------------------------------------------*/
/** @defgroup LCD_LL_Exported_Functions LCD Exported Functions
  * @{
  */

/** @defgroup LCD_LL_EF_CONTRASTLEVEL LCD Constrast Level
  * @{
  */
/**
  * @brief  Set LCD Contrast.
  * @param  LCDx LCD Instance
  * @param  Contrast This parameter can be one of the following values:
  *         @arg @ref LL_LCD_CONTRASTLEVEL_0
  *         @arg @ref LL_LCD_CONTRASTLEVEL_1
  *         @arg @ref LL_LCD_CONTRASTLEVEL_2
  *         @arg @ref LL_LCD_CONTRASTLEVEL_3
  *         @arg @ref LL_LCD_CONTRASTLEVEL_4
  *         @arg @ref LL_LCD_CONTRASTLEVEL_5
  *         @arg @ref LL_LCD_CONTRASTLEVEL_6
  *         @arg @ref LL_LCD_CONTRASTLEVEL_7
  *         @arg @ref LL_LCD_CONTRASTLEVEL_8
  *         @arg @ref LL_LCD_CONTRASTLEVEL_9
  *         @arg @ref LL_LCD_CONTRASTLEVEL_10
  *         @arg @ref LL_LCD_CONTRASTLEVEL_11
  *         @arg @ref LL_LCD_CONTRASTLEVEL_12
  *         @arg @ref LL_LCD_CONTRASTLEVEL_13
  *         @arg @ref LL_LCD_CONTRASTLEVEL_14
  *         @arg @ref LL_LCD_CONTRASTLEVEL_15
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetContrast(LCD_TypeDef *LCDx, uint32_t Contrast)
{
  MODIFY_REG(LCDx->CR, LCD_CR_CONTRAST, Contrast);
}

/**
  * @brief  Get LCD contrast.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_CONTRASTLEVEL_0
  *         @arg @ref LL_LCD_CONTRASTLEVEL_1
  *         @arg @ref LL_LCD_CONTRASTLEVEL_2
  *         @arg @ref LL_LCD_CONTRASTLEVEL_3
  *         @arg @ref LL_LCD_CONTRASTLEVEL_4
  *         @arg @ref LL_LCD_CONTRASTLEVEL_5
  *         @arg @ref LL_LCD_CONTRASTLEVEL_6
  *         @arg @ref LL_LCD_CONTRASTLEVEL_7
  *         @arg @ref LL_LCD_CONTRASTLEVEL_8
  *         @arg @ref LL_LCD_CONTRASTLEVEL_9
  *         @arg @ref LL_LCD_CONTRASTLEVEL_10
  *         @arg @ref LL_LCD_CONTRASTLEVEL_11
  *         @arg @ref LL_LCD_CONTRASTLEVEL_12
  *         @arg @ref LL_LCD_CONTRASTLEVEL_13
  *         @arg @ref LL_LCD_CONTRASTLEVEL_14
  *         @arg @ref LL_LCD_CONTRASTLEVEL_15
  */
__STATIC_INLINE uint32_t LL_LCD_GetContrast(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_CONTRAST));
}

/**
  * @}
  */

/** @defgroup LCD_LL_EF_DEADTIME LCD Dead Time
  * @{
  */
/**
  * @brief  Set LCD Dead Time.
  * @param  LCDx LCD Instance
  * @param  Time This parameter can be one of the following values:
  *         @arg @ref LL_LCD_DEAD_TIME_0
  *         @arg @ref LL_LCD_DEAD_TIME_1
  *         @arg @ref LL_LCD_DEAD_TIME_2
  *         @arg @ref LL_LCD_DEAD_TIME_3
  *         @arg @ref LL_LCD_DEAD_TIME_4
  *         @arg @ref LL_LCD_DEAD_TIME_5
  *         @arg @ref LL_LCD_DEAD_TIME_6
  *         @arg @ref LL_LCD_DEAD_TIME_7
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetDeadTime(LCD_TypeDef *LCDx, uint32_t Time)
{
  MODIFY_REG(LCDx->CR, LCD_CR_DEAD, Time);
}

/**
  * @brief  Get LCD Dead Time.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_DEAD_TIME_0
  *         @arg @ref LL_LCD_DEAD_TIME_1
  *         @arg @ref LL_LCD_DEAD_TIME_2
  *         @arg @ref LL_LCD_DEAD_TIME_3
  *         @arg @ref LL_LCD_DEAD_TIME_4
  *         @arg @ref LL_LCD_DEAD_TIME_5
  *         @arg @ref LL_LCD_DEAD_TIME_6
  *         @arg @ref LL_LCD_DEAD_TIME_7
  */
__STATIC_INLINE uint32_t LL_LCD_GetDeadTime(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_DEAD));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_BIASSOURCE LCD BIAS Source
  * @{
  */
/**
  * @brief  Set LCD bias source.
  * @param  LCDx LCD Instance
  * @param  BiasSource This parameter can be one of the following values:
  *         @arg @ref LL_LCD_BIAS_SOURCE_INTERNAL_RESISTANCE
  *         @arg @ref LL_LCD_BIAS_SOURCE_EXTERNAL_RESISTANCE
  *         @arg @ref LL_LCD_BIAS_SOURCE_EXTERNAL_CAPACITANCE
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetBiasSource(LCD_TypeDef *LCDx, uint32_t BiasSource)
{
  MODIFY_REG(LCDx->CR, LCD_CR_BSEL, BiasSource);
}

/**
  * @brief  Get LCD bias source.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_BIAS_SOURCE_INTERNAL_RESISTANCE
  *         @arg @ref LL_LCD_BIAS_SOURCE_EXTERNAL_RESISTANCE
  *         @arg @ref LL_LCD_BIAS_SOURCE_EXTERNAL_CAPACITANCE
  */
__STATIC_INLINE uint32_t LL_LCD_GetBiasSource(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_BSEL));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_DUTY LCD Duty
  * @{
  */
/**
  * @brief  Set LCD duty.
  * @param  LCDx LCD Instance
  * @param  Duty This parameter can be one of the following values:
  *         @arg @ref LL_LCD_DUTY_STATIC
  *         @arg @ref LL_LCD_DUTY_1_2
  *         @arg @ref LL_LCD_DUTY_1_3
  *         @arg @ref LL_LCD_DUTY_1_4
  *         @arg @ref LL_LCD_DUTY_1_6
  *         @arg @ref LL_LCD_DUTY_1_8
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetDuty(LCD_TypeDef *LCDx, uint32_t Duty)
{
  MODIFY_REG(LCDx->CR, LCD_CR_DUTY, Duty);
}

/**
  * @brief  Get LCD duty.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_DUTY_STATIC
  *         @arg @ref LL_LCD_DUTY_1_2
  *         @arg @ref LL_LCD_DUTY_1_3
  *         @arg @ref LL_LCD_DUTY_1_4
  *         @arg @ref LL_LCD_DUTY_1_6
  *         @arg @ref LL_LCD_DUTY_1_8
  */
__STATIC_INLINE uint32_t LL_LCD_GetDuty(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_DUTY));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_FASTCHARGE_CYCLE FastCharge Cycle
  * @{
  */
/**
  * @brief  Set LCD Fast Charge Cycle.
  * @param  LCDx LCD Instance
  * @param  FastCharge This parameter can be one of the following values:
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_2
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_4
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_8
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_16
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_32
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_64
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_128
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetFastChargeCycle(LCD_TypeDef *LCDx, uint32_t FastCharge)
{
  MODIFY_REG(LCDx->CR, LCD_CR_FCCTL, FastCharge);
}

/**
  * @brief  Get LCD FastChange Cycle.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_2
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_4
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_8
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_16
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_32
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_64
  *         @arg @ref LL_LCD_FASTCHARGE_CYCLE_1_128
  */
__STATIC_INLINE uint32_t LL_LCD_GetFastChargeCycle(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_FCCTL));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_VOLTAGE LCD Voltage
  * @{
  */
/**
  * @brief  Set LCD Voltage Source
  * @param  LCDx LCD Instance
  * @param  Time This parameter can be one of the following values:
  *         @arg @ref LL_LCD_VOLTAGE_SOURCE_VCCA
  *         @arg @ref LL_LCD_VOLTAGE_SOURCE_INTERNALVOLTAGE
  * @retval None
  */
/*
__STATIC_INLINE void LL_LCD_SetVoltageSource(LCD_TypeDef *LCDx, uint32_t Source)
{
  MODIFY_REG(LCDx->CR, LCD_CR_VSEL, Source);
}
*/

/**
  * @brief  Get LCD Voltage Source
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_VOLTAGE_SOURCE_VCCA
  *         @arg @ref LL_LCD_VOLTAGE_SOURCE_INTERNALVOLTAGE
  */
/*
__STATIC_INLINE uint32_t LL_LCD_GetVoltageSource(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_VSEL));
}
*/

/**
  * @brief  Set LCD Voltage Level
  * @param  LCDx LCD Instance
  * @param  Time This parameter can be one of the following values:
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_2P6
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_2P74
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_2P88
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P02
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P16
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P3
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P44
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P58
  * @retval None
  */
/*
__STATIC_INLINE void LL_LCD_SetVoltageLevel(LCD_TypeDef *LCDx, uint32_t Level)
{
  MODIFY_REG(LCDx->CR, LCD_CR_VCP_SEL, Level);
}
*/

/**
  * @brief  Get LCD Voltage Level
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_2P6
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_2P74
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_2P88
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P02
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P16
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P3
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P44
  *         @arg @ref LL_LCD_VOLTAGE_LEVEL_3P58
  */
/*
__STATIC_INLINE uint32_t LL_LCD_GetVoltageLevel(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_VCP_SEL));
}
*/

/**
  * @}
  */

/** @defgroup LCD_LL_EF_CHARGEPUMP LCD Chargepump
  * @{
  */
/**
  * @brief  Set LCD ChargePump Set Time.
  * @param  LCDx LCD Instance
  * @param  Time This parameter can be one of the following values:
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_256CLOCK
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_512CLOCK
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_1024CLOCK
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_2048CLOCK
  * @retval None
  */
/*
__STATIC_INLINE void LL_LCD_SetChargePumpSetTime(LCD_TypeDef *LCDx, uint32_t Time)
{
  MODIFY_REG(LCDx->CR, LCD_CR_CP_ST, Time);
}
*/

/**
  * @brief  Get LCD ChargePump Set Time.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_256CLOCK
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_512CLOCK
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_1024CLOCK
  *         @arg @ref LL_LCD_CHARGEPUMP_SETTIME_2048CLOCK
  */
/*
__STATIC_INLINE uint32_t LL_LCD_GetChargePumpSetTime(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_CP_ST));
}
*/

/**
  * @brief  Set LCD ChargePump Frequency.
  * @param  LCDx LCD Instance
  * @param  Frequency This parameter can be one of the following values:
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_512HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_1024HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_2048HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_4096HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_8192HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_16384HZ
  * @retval None
  */
/*
__STATIC_INLINE void LL_LCD_SetChargePumpFrequency(LCD_TypeDef *LCDx, uint32_t Frequency)
{
  MODIFY_REG(LCDx->CR, LCD_CR_CP_FRQ, Frequency);
}
*/

/**
  * @brief  Get LCD ChargePump Frequency.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_512HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_1024HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_2048HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_4096HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_8192HZ
  *         @arg @ref LL_LCD_CHARGEPUMP_FREQ_16384HZ
  */
/*
__STATIC_INLINE uint32_t LL_LCD_GetChargePumpFrequency(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_CP_FRQ));
}
*/

/**
  * @}
  */

/** @defgroup LCD_LL_EF_BIAS LCD BIAS
  * @{
  */
/**
  * @brief  Set LCD bias.
  * @param  LCDx LCD Instance
  * @param  Bias This parameter can be one of the following values:
  *         @arg @ref LL_LCD_BIAS_1_4
  *         @arg @ref LL_LCD_BIAS_1_3
  *         @arg @ref LL_LCD_BIAS_1_2
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetBias(LCD_TypeDef *LCDx, uint32_t Bias)
{
  MODIFY_REG(LCDx->CR, LCD_CR_BIAS, Bias);
}

/**
  * @brief  Get LCD bias.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_BIAS_1_4
  *         @arg @ref LL_LCD_BIAS_1_3
  *         @arg @ref LL_LCD_BIAS_1_2
  */
__STATIC_INLINE uint32_t LL_LCD_GetBias(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_BIAS));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_SCAN_FREQ LCD Scan Frequency
  * @{
  */
/**
  * @brief  Set LCD scan frequency.
  * @param  LCDx LCD Instance
  * @param  ScanFreq This parameter can be one of the following values:
  *         @arg @ref LL_LCD_SCAN_FREQ_64HZ
  *         @arg @ref LL_LCD_SCAN_FREQ_128HZ
  *         @arg @ref LL_LCD_SCAN_FREQ_256HZ
  *         @arg @ref LL_LCD_SCAN_FREQ_512HZ
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetScanFreq(LCD_TypeDef *LCDx, uint32_t ScanFreq)
{
  MODIFY_REG(LCDx->CR, LCD_CR_LCDCLK, ScanFreq);
}

/**
  * @brief  Get LCD scan frequency.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_SCAN_FREQ_64HZ
  *         @arg @ref LL_LCD_SCAN_FREQ_128HZ
  *         @arg @ref LL_LCD_SCAN_FREQ_256HZ
  *         @arg @ref LL_LCD_SCAN_FREQ_512HZ
  */
__STATIC_INLINE uint32_t LL_LCD_GetScanFreq(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_LCDCLK));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_MODE LCD Mode
  * @{
  */
/**
  * @brief  Set LCD mode.
  * @param  LCDx LCD Instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_LCD_MODE_0
  *         @arg @ref LL_LCD_MODE_1
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetMode(LCD_TypeDef *LCDx, uint32_t Mode)
{
  MODIFY_REG(LCDx->CSR, LCD_CSR_MODE, Mode);
}

/**
  * @brief  Get LCD mode.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_MODE_0
  *         @arg @ref LL_LCD_MODE_1
  */
__STATIC_INLINE uint32_t LL_LCD_GetMode(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CSR, LCD_CSR_MODE));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_COMSEGDRIVETYPE  LCD ComSegDrive Type
  * @{
  */
/**
  * @brief  Set LCD ComSegDrive Type.
  * @param  LCDx LCD Instance
  * @param  Type This parameter can be one of the following values:
  *         @arg @ref LL_LCD_COMSEGDRIVE_TYPE_A
  *         @arg @ref LL_LCD_COMSEGDRIVE_TYPE_B
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetComSegDriveType(LCD_TypeDef *LCDx, uint32_t Type)
{
  MODIFY_REG(LCDx->CR, LCD_CR_COMSEG_DRV_TYPE, Type);
}

/**
  * @brief  Get LCD ComSegDrive Type.
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_COMSEGDRIVE_TYPE_A
  *         @arg @ref LL_LCD_COMSEGDRIVE_TYPE_B
  */
__STATIC_INLINE uint32_t LL_LCD_GetComSegDriveType(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_COMSEG_DRV_TYPE));
}
/**
  * @}
  */

/**
  * @brief  Enable LCD peripheral.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_Enable(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->CR,  LCD_CR_EN);
}

/**
  * @brief  Disable LCD peripheral.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_Disable(LCD_TypeDef *LCDx)
{
  CLEAR_BIT(LCDx->CR, LCD_CR_EN);
}

/**
  * @brief  Check if LCD peripheral is enabled
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabled(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CR, LCD_CR_EN) == (LCD_CR_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Update Request.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_EnableUpdateRequect(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->CSR,  LCD_CSR_UDR);
}

/**
  * @brief  Update Request Status
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabledUpdateRequect(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_UDR) == (LCD_CSR_UDR)) ? 1UL : 0UL);
}

/** @defgroup LCD_LL_EF_BLINK LCD Blink
  * @{
  */
/**
  * @brief  Enable LCD blink mode.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_EnableBlink(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->CSR, LCD_CSR_BLINKEN);
}

/**
  * @brief  Disable LCD blink mode.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_DisableBlink(LCD_TypeDef *LCDx)
{
  CLEAR_BIT(LCDx->CSR, LCD_CSR_BLINKEN);
}

/**
  * @brief  Check if LCD blink mode is enabled.
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabledBlink(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_BLINKEN) == (LCD_CSR_BLINKEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set the number of frames corresponding to LCD blink frequency and interrupt interval.
  * @param  LCDx LCD Instance
  * @param  Count Value between Min_Data=0x00 and Max_Data=0x3F
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetBlinkCount(LCD_TypeDef *LCDx, uint32_t Count)
{
  MODIFY_REG(LCDx->CSR, LCD_CSR_BLINKCNT, Count);
}

/**
  * @brief  Get the number of frames corresponding to LCD blink frequency and interrupt interval.
  * @param  LCDx LCD Instance
  * @retval Returned between Min_Data=0x00 and Max_Data=0x3F
  */
__STATIC_INLINE uint32_t LL_LCD_GetBlinkCount(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CSR, LCD_CSR_BLINKCNT));
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_SWCAPDRIVENUMBER SW CAP Drive Number
  * @{
  */
/**
  * @brief  Set the number of SWCAP Drive Number
  * @param  LCDx LCD Instance
  * @param  Number This parameter can be one of the following values:
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_4
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_8
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_16
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_32
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_64
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetSWCAPDriveNumber(LCD_TypeDef *LCDx, uint32_t Number)
{
  MODIFY_REG(LCDx->CSR, LCD_CSR_SWCAP_DRV_NUM, Number);
}

/**
  * @brief  Get the number of SWCAP Drive Number
  * @param  LCDx LCD Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_4
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_8
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_16
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_32
  *         @arg @ref LL_LCD_SWCAPDRIVE_NUMBER_64
  */
__STATIC_INLINE uint32_t LL_LCD_GetSWCAPDriveNumber(LCD_TypeDef *LCDx)
{
  return (uint32_t)(READ_BIT(LCDx->CSR, LCD_CSR_SWCAP_DRV_NUM));
}
/**
  * @}
  */


/** @defgroup LCD_LL_EF_IT_Management IT Management
  * @{
  */
/**
  * @brief  Enable LCD BKF interrupt.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_EnableIT_BKF(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->CSR, LCD_CSR_BKFIE);
}

/**
  * @brief  Enable LCD SOF interrupt.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_EnableIT_SOF(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->CSR, LCD_CSR_SOFIE);
}

/**
  * @brief  Enable LCD UDD interrupt.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_EnableIT_UDD(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->CSR, LCD_CSR_UDDIE);
}

/**
  * @brief  Disable LCD BKF interrupt.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_DisableIT_BKF(LCD_TypeDef *LCDx)
{
  CLEAR_BIT(LCDx->CSR, LCD_CSR_BKFIE);
}

/**
  * @brief  Disable LCD SOF interrupt.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_DisableIT_SOF(LCD_TypeDef *LCDx)
{
  CLEAR_BIT(LCDx->CSR, LCD_CSR_SOFIE);
}

/**
  * @brief  Disable LCD UDD interrupt.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_DisableIT_UDD(LCD_TypeDef *LCDx)
{
  CLEAR_BIT(LCDx->CSR, LCD_CSR_UDDIE);
}

/**
  * @brief  Check if LCD BKF interrupt is enabled
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabledIT_BKF(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_BKFIE) == (LCD_CSR_BKFIE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if LCD SOF interrupt is enabled
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabledIT_SOF(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_SOFIE) == (LCD_CSR_SOFIE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if LCD UDD interrupt is enabled
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabledIT_UDD(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_UDDIE) == (LCD_CSR_UDDIE)) ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup LCD_LL_EF_FLAG_Management FLAG Management
  * @{
  */
/**
  * @brief  Get LCD ENS flag.
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsActiveFlag_ENS(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_ENS) == (LCD_CSR_ENS)) ? 1UL : 0UL);
}

/**
  * @brief  Get LCD BKF flag.
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsActiveFlag_BKF(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_BKF) == (LCD_CSR_BKF)) ? 1UL : 0UL);
}

/**
  * @brief  Get LCD SOF flag.
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsActiveFlag_SOF(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_SOF) == (LCD_CSR_SOF)) ? 1UL : 0UL);
}

/**
  * @brief  Get LCD UDD flag.
  * @param  LCDx LCD Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsActiveFlag_UDD(LCD_TypeDef *LCDx)
{
  return ((READ_BIT(LCDx->CSR, LCD_CSR_UDD) == (LCD_CSR_UDD)) ? 1UL : 0UL);
}

/**
  * @brief  Clear LCD BKF flag.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_ClearFlag_BKF(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->INTCLR, LCD_INTCLR_BKFC);
}

/**
  * @brief  Clear LCD SOF flag.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_ClearFlag_SOF(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->INTCLR, LCD_INTCLR_SOFC);
}

/**
  * @brief  Clear LCD UDD flag.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_ClearFlag_UDD(LCD_TypeDef *LCDx)
{
  SET_BIT(LCDx->INTCLR, LCD_INTCLR_UDDC);
}

/**
  * @}
  */

/**
  * @brief  Set LCD SEG COM port output enable.
  * @param  LCDx LCD Instance
  * @param  SegCom pointer to a LCD_SegComTypeDef structure that contains
  *         the configuration information for LCD SEG COM port output enable.
  * @retval None
  */
__STATIC_INLINE void LL_LCD_SetSegCom(LCD_TypeDef *LCDx, LL_LCD_SegComTypeDef *SegCom)
{
  WRITE_REG(LCDx->POEN0, SegCom->Seg0_31);
  WRITE_REG(LCDx->POEN1, SegCom->Seg32_39_Com0_7_t.Seg32_39_Com0_7);
}

/**
  * @brief  Writes in the specific LCD RAM.
  * @param  LCDx LCD Instance
  * @param  RAMRegisterIndex specifies the LCD RAM Register.
  *         This parameter can be one of the following values:
  *         @arg @ref LL_LCD_RAM_REGISTER0
  *         @arg @ref LL_LCD_RAM_REGISTER1
  *         @arg @ref LL_LCD_RAM_REGISTER2
  *         @arg @ref LL_LCD_RAM_REGISTER3
  *         @arg @ref LL_LCD_RAM_REGISTER4
  *         @arg @ref LL_LCD_RAM_REGISTER5
  *         @arg @ref LL_LCD_RAM_REGISTER6
  *         @arg @ref LL_LCD_RAM_REGISTER7
  *         @arg @ref LL_LCD_RAM_REGISTER8
  *         @arg @ref LL_LCD_RAM_REGISTER9
  *         @arg @ref LL_LCD_RAM_REGISTER10
  *         @arg @ref LL_LCD_RAM_REGISTER11
  *         @arg @ref LL_LCD_RAM_REGISTER12
  *         @arg @ref LL_LCD_RAM_REGISTER13
  *         @arg @ref LL_LCD_RAM_REGISTER14
  *         @arg @ref LL_LCD_RAM_REGISTER15
  * @param  Data specifies LCD Data Value to be written.
  * @retval None
  */
__STATIC_INLINE void LL_LCD_Write(LCD_TypeDef *LCDx, uint32_t RAMRegisterIndex, uint32_t Data)
{
  WRITE_REG(LCDx->RAM[RAMRegisterIndex], Data);
}

/**
  * @brief  Clears the LCD RAM registers.
  * @param  LCDx LCD Instance
  * @retval None
  */
__STATIC_INLINE void LL_LCD_Clear(LCD_TypeDef *LCDx)
{
  register uint32_t counter = 0U;
  for(counter = LL_LCD_RAM_REGISTER0; counter <= LL_LCD_RAM_REGISTER15; counter++)
  {
    LCDx->RAM[counter] = 0U;
  }
}
  
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup LCD_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_LCD_DeInit(LCD_TypeDef *LCDx);
ErrorStatus LL_LCD_Init(LCD_TypeDef *LCDx, LL_LCD_InitTypeDef *LCD_InitStruct);
void        LL_LCD_StructInit(LL_LCD_InitTypeDef *LCD_InitStruct);
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
  
#endif /* defined (LCD)*/
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32C882_LL_LCD_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
