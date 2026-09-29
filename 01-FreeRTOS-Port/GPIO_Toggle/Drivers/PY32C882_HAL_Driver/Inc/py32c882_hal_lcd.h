/**
  ******************************************************************************
  * @file    py32c882_hal_lcd.h
  * @author  MCU Application Team
  * @brief   Header file of LCD Controller HAL module.
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
#ifndef __PY32C882_HAL_LCD_H
#define __PY32C882_HAL_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @defgroup LCD LCD
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/** @defgroup LCD_Exported_Types LCD Exported Types
  * @{
  */

/** 
  * @brief LCD Init structure definition
  */
typedef struct
{
  uint32_t ScanFreq;          /*!< Configures the LCD Scan Frequency.
                                 This parameter can be one value of @ref LCD_ScanFrequency */
  uint32_t Mode;              /*!< Configures the LCD Mode.
                                 This parameter can be one value of @ref LCD_Mode */
  uint32_t DeadTime;          /*!< Configures the LCD Dead Time.
                                 This parameter can be one value of @ref LCD_DeadTime */
  uint32_t ComSegDriveType;   /*!< Selects the LCD Voltage source.
                                 This parameter can be one value of @ref LCD_ComSegDrive_Type */
  uint32_t BlinkFrequency;    /*!< Configures the LCD Blink frequency.
                                 This parameter can be one value of @ref LCD_BlinkFrequency */
  uint32_t VoltageSource;     /*!< Selects the LCD Voltage source.
                                 This parameter can be one value of @ref LCD_Voltage_Source */ 
  uint32_t ChargePumpFreq;    /*!< Configures the LCD ChargePum Frequency.
                                 This parameter can be one value of @ref LCD_ChargePump_Freq */
  uint32_t ChargePumpSetTime;     /*!< Configures the LCD ChargePump Set Time.
                                 This parameter can be one value of @ref LCD_ChargePump_SetTime */
  uint32_t Duty;              /*!< Configures the LCD Duty.
                                 This parameter can be one value of @ref LCD_Duty */
  uint32_t BiasSrc;           /*!< Configures the LCD Bias Source.
                                 This parameter can be one value of @ref LCD_BiasSource */
  uint32_t Bias;              /*!< Configures the LCD Bias.
                                 This parameter can be one value of @ref LCD_Bias */
  uint32_t Contrast;          /*!< Configures the LCD Contrast.
                                 This parameter can be one value of @ref LCD_Contrast */
  uint32_t FastChargeCycle;   /*!< Configures the LCD FastCharge Cycle.
                                 This parameter can be one value of @ref LCD_FastCharge_Cycle */
  uint32_t CapDriveNumber;    /*!< Configures the LCD Cap Drive Time.
                                 This parameter can be one value of @ref LCD_CapDrive_Number */
}LCD_InitTypeDef;

/** 
  * @brief HAL LCD State structures definition
  */ 
typedef enum
{
  HAL_LCD_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized */
  HAL_LCD_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use */
  HAL_LCD_STATE_BUSY              = 0x02U,    /*!< an internal process is ongoing */
  HAL_LCD_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state */
  HAL_LCD_STATE_ERROR             = 0x04U     /*!< Error */
}HAL_LCD_StateTypeDef;

/** 
  * @brief  LCD handle Structure definition
  */  
typedef struct
{
  LCD_TypeDef                   *Instance;  /* LCD registers base address */
  
  LCD_InitTypeDef               Init;       /* LCD communication parameters */

  HAL_LockTypeDef               Lock;       /* Locking object */

  __IO HAL_LCD_StateTypeDef     State;      /* LCD communication state */
  
  __IO uint32_t                 ErrorCode;  /* LCD Error code */
  
}LCD_HandleTypeDef;

/** 
  * @brief  LCD SEG COM port output enable configuration
  */
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
}LCD_SegComTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup LCD_Exported_Constants LCD Exported Constants
  * @{
  */

/** @defgroup  LCD_ErrorCode LCD Error Code
  * @{
  */ 
#define HAL_LCD_ERROR_NONE       (0x00U)    /*!< No error */
#define HAL_LCD_ERROR_UDR        (0x02U)    /*!< Update display request flag timeout error */
#define HAL_LCD_ERROR_UDD        (0x04U)    /*!< Update display done flag timeout error */
#define HAL_LCD_ERROR_ENS        (0x08U)    /*!< LCD enabled status flag timeout error */
#define HAL_LCD_ERROR_SOF        (0x10U)    /*!< LCD sof status flag timeout error */
#define HAL_LCD_ERROR_DISABLE    (0x20U)    /*!< LCD disable status flag timeout error */
/**
  * @}
  */
  
/** @defgroup LCD_ScanFrequency LCD Scan Frequency
  * @{
  */
  
#define LCD_SCAN_FREQ_64HZ               ((uint32_t)0x00000000U)                /* LCD Scan Frequency 64Hz */
#define LCD_SCAN_FREQ_128HZ              (LCD_CR_LCDCLK_0)                      /* LCD Scan Frequency 128Hz */
#define LCD_SCAN_FREQ_256HZ              (LCD_CR_LCDCLK_1)                      /* LCD Scan Frequency 256Hz */
#define LCD_SCAN_FREQ_512HZ              (LCD_CR_LCDCLK_1 | LCD_CR_LCDCLK_0)    /* LCD Scan Frequency 512Hz */

/**
  * @}
  */

/** @defgroup LCD_Bias LCD Bias
  * @{
  */
  
#define LCD_BIAS_1_4                    ((uint32_t)0x00000000U) /*!< 1/4 Bias */
#define LCD_BIAS_1_2                    (LCD_CR_BIAS_0)         /*!< 1/2 Bias */
#define LCD_BIAS_1_3                    (LCD_CR_BIAS_1)         /*!< 1/3 Bias */

/**
  * @}
  */

/** @defgroup LCD_Duty LCD Duty
  * @{
  */
  
#define LCD_DUTY_STATIC                 ((uint32_t)0x00000000U)                           /*!< Static duty */
#define LCD_DUTY_1_2                    (LCD_CR_DUTY_0)                                   /*!< 1/2 duty    */
#define LCD_DUTY_1_3                    (LCD_CR_DUTY_1)                                   /*!< 1/3 duty    */
#define LCD_DUTY_1_4                    (LCD_CR_DUTY_1 | LCD_CR_DUTY_0)                   /*!< 1/4 duty    */
#define LCD_DUTY_1_6                    (LCD_CR_DUTY_2 | LCD_CR_DUTY_0)                   /*!< 1/6 duty    */
#define LCD_DUTY_1_8                    (LCD_CR_DUTY_2 | LCD_CR_DUTY_1 | LCD_CR_DUTY_0)   /*!< 1/8 duty    */

/**
  * @}
  */ 

/** @defgroup LCD_BiasSource LCD Bias Source
  * @{
  */

#define LCD_BIAS_SOURCE_INTERNAL_RESISTANCE                 ((uint32_t)0x00000000U)          /* Internal resistance mode */
#define LCD_BIAS_SOURCE_EXTERNAL_RESISTANCE                 (LCD_CR_BSEL_0)                  /* External resistance mode */
#define LCD_BIAS_SOURCE_EXTERNAL_CAPACITANCE                (LCD_CR_BSEL_1)                  /* External capacitance mode */

/**
  * @}
  */

/** @defgroup LCD_Contrast LCD Contrast
  * @{
  */

#define LCD_CONTRASTLEVEL_0               ((uint32_t)0x00000000U)
#define LCD_CONTRASTLEVEL_1               (LCD_CR_CONTRAST_0)
#define LCD_CONTRASTLEVEL_2               (LCD_CR_CONTRAST_1)
#define LCD_CONTRASTLEVEL_3               (LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)
#define LCD_CONTRASTLEVEL_4               (LCD_CR_CONTRAST_2)
#define LCD_CONTRASTLEVEL_5               (LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_0)
#define LCD_CONTRASTLEVEL_6               (LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1)
#define LCD_CONTRASTLEVEL_7               (LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)
#define LCD_CONTRASTLEVEL_8               (LCD_CR_CONTRAST_3)
#define LCD_CONTRASTLEVEL_9               (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_0)
#define LCD_CONTRASTLEVEL_10              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_1)
#define LCD_CONTRASTLEVEL_11              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)
#define LCD_CONTRASTLEVEL_12              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2)
#define LCD_CONTRASTLEVEL_13              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_0)
#define LCD_CONTRASTLEVEL_14              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1)
#define LCD_CONTRASTLEVEL_15              (LCD_CR_CONTRAST_3 | LCD_CR_CONTRAST_2 | LCD_CR_CONTRAST_1 | LCD_CR_CONTRAST_0)

/**
  * @}
  */

/** @defgroup LCD_Voltage_Source LCD Voltage Source
  * @{
  */

#define LCD_VOLTAGE_SOURCE_VCCA         ((uint32_t)0x00000000U)                                                          /*VCCA */
#if defined(LCD_CR_VSEL)
#define LCD_VOLTAGE_SOURCE_2P6          (LCD_CR_VSEL)                                                               /* 2.6V VCP SEL */
#define LCD_VOLTAGE_SOURCE_2P74         (LCD_CR_VSEL | LCD_CR_VCP_SEL_0)                                            /* 2.74V VCP SEL */
#define LCD_VOLTAGE_SOURCE_2P88         (LCD_CR_VSEL | LCD_CR_VCP_SEL_1)                                            /* 2.88V VCP SEL */
#define LCD_VOLTAGE_SOURCE_3P02         (LCD_CR_VSEL | LCD_CR_VCP_SEL_0 | LCD_CR_VCP_SEL_1)                         /* 3.02V VCP SEL */
#define LCD_VOLTAGE_SOURCE_3P16         (LCD_CR_VSEL | LCD_CR_VCP_SEL_2)                                            /* 3.16V VCP SEL */
#define LCD_VOLTAGE_SOURCE_3P3          (LCD_CR_VSEL | LCD_CR_VCP_SEL_2 | LCD_CR_VCP_SEL_0)                         /* 3.3V VCP SEL */
#define LCD_VOLTAGE_SOURCE_3P44         (LCD_CR_VSEL | LCD_CR_VCP_SEL_2 | LCD_CR_VCP_SEL_1)                         /* 3.44V VCP SEL */
#define LCD_VOLTAGE_SOURCE_3P58         (LCD_CR_VSEL | LCD_CR_VCP_SEL_2 | LCD_CR_VCP_SEL_1 | LCD_CR_VCP_SEL_0)      /* 3.58V VCP SEL */
#endif

/**
  * @}
  */

/** @defgroup LCD_ComSegDrive_Type LCD ComSegDrive Type
  * @{
  */

#define LCD_COMSEGDRIVE_TYPE_A             ((uint32_t)0x00000000)        /*!< LCD COM SEG Drive Type A */
#define LCD_COMSEGDRIVE_TYPE_B             (LCD_CR_COMSEG_DRV_TYPE)      /*!< LCD COM SEG Drive Type B */
/**
  * @}
  */

/** @defgroup LCD_FastCharge_Cycle LCD Fast Charge Cycle
  * @{
  */

#define LCD_FASTCHARGE_CYCLE_1_2        ((uint32_t)0x00000000U)             /* Fast Charge 1/2 LCD COM Cycle */
#define LCD_FASTCHARGE_CYCLE_1_4        (LCD_CR_FCCTL_0)                    /* Fast Charge 1/4 LCD COM Cycle */
#define LCD_FASTCHARGE_CYCLE_1_8        (LCD_CR_FCCTL_1)                    /* Fast Charge 1/8 LCD COM Cycle */
#define LCD_FASTCHARGE_CYCLE_1_16       (LCD_CR_FCCTL_0 | LCD_CR_FCCTL_1)   /* Fast Charge 1/16 LCD COM Cycle */
#define LCD_FASTCHARGE_CYCLE_1_32       (LCD_CR_FCCTL_2)                    /* Fast Charge 1/32 LCD COM Cycle */
#define LCD_FASTCHARGE_CYCLE_1_64       (LCD_CR_FCCTL_2 | LCD_CR_FCCTL_0)   /* Fast Charge 1/64 LCD COM Cycle */
#define LCD_FASTCHARGE_CYCLE_1_128      (LCD_CR_FCCTL_2 | LCD_CR_FCCTL_1)   /* Fast Charge 1/128 LCD COM Cycle */
/**
  * @}
  */

#if defined(LCD_CR_VSEL)
/** @defgroup LCD_ChargePump_Freq LCD ChargePump Freq
  * @{
  */
#define LCD_CHARGEPUMP_FREQ_512HZ          (0x00000000U)                                          /* ChargePump 512 Hz */
#define LCD_CHARGEPUMP_FREQ_1024HZ         (LCD_CR_CP_FRQ_0)                                       /* ChargePump 1024 Hz */
#define LCD_CHARGEPUMP_FREQ_2048HZ         (LCD_CR_CP_FRQ_1)                                       /* ChargePump 2048 Hz */
#define LCD_CHARGEPUMP_FREQ_4096HZ         (LCD_CR_CP_FRQ_0 | LCD_CR_CP_FRQ_1)                     /* ChargePump 4096 Hz */
#define LCD_CHARGEPUMP_FREQ_8192HZ         (LCD_CR_CP_FRQ_2)                                       /* ChargePump 8192 Hz */
#define LCD_CHARGEPUMP_FREQ_16384HZ        (LCD_CR_CP_FRQ_2 | LCD_CR_CP_FRQ_0)                     /* ChargePump 16384 Hz */
/**
  * @}
  */

/** @defgroup LCD_ChargePump_SetTime LCD ChargePump SetTime
  * @{
  */

#define LCD_CHARGEPUMP_SETTIME_256CLOCK          (0x00000000U)                                   /* ChargePump Settime 256 LSE/LSI Clocks  */                                
#define LCD_CHARGEPUMP_SETTIME_512CLOCK          (LCD_CR_CP_ST_0)                                /* ChargePump Settime 512 LSE/LSI Clocks  */
#define LCD_CHARGEPUMP_SETTIME_1024CLOCK         (LCD_CR_CP_ST_1)                                /* ChargePump Settime 1024 LSE/LSI Clocks  */
#define LCD_CHARGEPUMP_SETTIME_2048CLOCK         (LCD_CR_CP_ST_0 | LCD_CR_CP_ST_1)               /* ChargePump Settime 2048 LSE/LSI Clocks  */
/**
  * @}
  */
#endif

/** @defgroup LCD_DeadTime LCD Dead Time
  * @{
  */
#define LCD_DEAD_TIME_0                  (0x00000000U)                     /*!< No dead Time                                  */
#define LCD_DEAD_TIME_1                  (LCD_CR_DEAD_0)                   /*!< One Phase between different couple of Frame   */
#define LCD_DEAD_TIME_2                  (LCD_CR_DEAD_1)                   /*!< Two Phase between different couple of Frame   */
#define LCD_DEAD_TIME_3                  (LCD_CR_DEAD_1 | LCD_CR_DEAD_0)   /*!< Three Phase between different couple of Frame */
#define LCD_DEAD_TIME_4                  (LCD_CR_DEAD_2)                   /*!< Four Phase between different couple of Frame  */
#define LCD_DEAD_TIME_5                  (LCD_CR_DEAD_2 | LCD_CR_DEAD_0)   /*!< Five Phase between different couple of Frame  */
#define LCD_DEAD_TIME_6                  (LCD_CR_DEAD_2 | LCD_CR_DEAD_1)   /*!< Six Phase between different couple of Frame   */
#define LCD_DEAD_TIME_7                  (LCD_CR_DEAD)                     /*!< Seven Phase between different couple of Frame */
/**
  * @}
  */

/** @defgroup LCD_BlinkFrequency LCD Blink Frequency
  * @{
  */
#define LCD_BLINK_FREQ_OFF              (0x00000000U)                                                                                                                                         /*!< Blink disabled         */
#define LCD_BLINK_FREQ_DIV1             (LCD_CSR_BLINKEN                                                                                                                              )       /*!< Blink enabled 1/64     */
#define LCD_BLINK_FREQ_DIV2             (LCD_CSR_BLINKEN                                                                                                          | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 2/64     */
#define LCD_BLINK_FREQ_DIV3             (LCD_CSR_BLINKEN                                                                                     | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 3/64     */
#define LCD_BLINK_FREQ_DIV4             (LCD_CSR_BLINKEN                                                                                     | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 4/64     */
#define LCD_BLINK_FREQ_DIV5             (LCD_CSR_BLINKEN                                                                | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 5/64     */
#define LCD_BLINK_FREQ_DIV6             (LCD_CSR_BLINKEN                                                                | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 6/64     */
#define LCD_BLINK_FREQ_DIV7             (LCD_CSR_BLINKEN                                                                | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 7/64     */
#define LCD_BLINK_FREQ_DIV8             (LCD_CSR_BLINKEN                                                                | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 8/64     */
#define LCD_BLINK_FREQ_DIV9             (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3                                                               )       /*!< Blink enabled 9/64     */
#define LCD_BLINK_FREQ_DIV10            (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3                                           | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 10/64     */
#define LCD_BLINK_FREQ_DIV11            (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 11/64     */
#define LCD_BLINK_FREQ_DIV12            (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 12/64     */
#define LCD_BLINK_FREQ_DIV13            (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 13/64     */
#define LCD_BLINK_FREQ_DIV14            (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 14/64     */
#define LCD_BLINK_FREQ_DIV15            (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 15/64     */
#define LCD_BLINK_FREQ_DIV16            (LCD_CSR_BLINKEN                                           | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 16/64     */
#define LCD_BLINK_FREQ_DIV17            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                                                                                    )       /*!< Blink enabled 17/64     */
#define LCD_BLINK_FREQ_DIV18            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                                                                | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 18/64     */
#define LCD_BLINK_FREQ_DIV19            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                                           | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 19/64     */
#define LCD_BLINK_FREQ_DIV20            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                                           | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 20/64     */
#define LCD_BLINK_FREQ_DIV21            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 21/64     */
#define LCD_BLINK_FREQ_DIV22            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 22/64     */
#define LCD_BLINK_FREQ_DIV23            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 23/64     */
#define LCD_BLINK_FREQ_DIV24            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 24/64     */
#define LCD_BLINK_FREQ_DIV25            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                                                               )       /*!< Blink enabled 25/64     */
#define LCD_BLINK_FREQ_DIV26            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                                           | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 26/64     */
#define LCD_BLINK_FREQ_DIV27            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 27/64     */
#define LCD_BLINK_FREQ_DIV28            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 28/64     */
#define LCD_BLINK_FREQ_DIV29            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 29/64     */
#define LCD_BLINK_FREQ_DIV30            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 30/64     */
#define LCD_BLINK_FREQ_DIV31            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 31/64     */
#define LCD_BLINK_FREQ_DIV32            (LCD_CSR_BLINKEN                      | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 32/64     */
#define LCD_BLINK_FREQ_DIV33            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                                                                                         )       /*!< Blink enabled 33/64     */
#define LCD_BLINK_FREQ_DIV34            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                                                                     | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 34/64     */
#define LCD_BLINK_FREQ_DIV35            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                                                | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 35/64     */
#define LCD_BLINK_FREQ_DIV36            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                                                | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 36/64     */
#define LCD_BLINK_FREQ_DIV37            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                           | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 37/64     */
#define LCD_BLINK_FREQ_DIV38            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                           | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 38/64     */
#define LCD_BLINK_FREQ_DIV39            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                           | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 39/64     */
#define LCD_BLINK_FREQ_DIV40            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                                           | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 40/64     */
#define LCD_BLINK_FREQ_DIV41            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3                                                               )       /*!< Blink enabled 41/64     */
#define LCD_BLINK_FREQ_DIV42            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3                                           | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 42/64     */
#define LCD_BLINK_FREQ_DIV43            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 43/64     */
#define LCD_BLINK_FREQ_DIV44            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 44/64     */
#define LCD_BLINK_FREQ_DIV45            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 45/64     */
#define LCD_BLINK_FREQ_DIV46            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 46/64     */
#define LCD_BLINK_FREQ_DIV47            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 47/64     */
#define LCD_BLINK_FREQ_DIV48            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5                      | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 48/64     */
#define LCD_BLINK_FREQ_DIV49            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                                                                                    )       /*!< Blink enabled 49/64     */
#define LCD_BLINK_FREQ_DIV50            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                                                                | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 50/64     */
#define LCD_BLINK_FREQ_DIV51            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                                           | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 51/64     */
#define LCD_BLINK_FREQ_DIV52            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                                           | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 52/64     */
#define LCD_BLINK_FREQ_DIV53            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 53/64     */
#define LCD_BLINK_FREQ_DIV54            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 54/64     */
#define LCD_BLINK_FREQ_DIV55            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 55/64     */
#define LCD_BLINK_FREQ_DIV56            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4                      | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 56/64     */
#define LCD_BLINK_FREQ_DIV57            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                                                               )       /*!< Blink enabled 57/64     */
#define LCD_BLINK_FREQ_DIV58            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                                           | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 58/64     */
#define LCD_BLINK_FREQ_DIV59            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 59/64     */
#define LCD_BLINK_FREQ_DIV60            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3                      | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 60/64     */
#define LCD_BLINK_FREQ_DIV61            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                                          )       /*!< Blink enabled 61/64     */
#define LCD_BLINK_FREQ_DIV62            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2                      | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 62/64     */
#define LCD_BLINK_FREQ_DIV63            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1                     )       /*!< Blink enabled 63/64     */
#define LCD_BLINK_FREQ_DIV64            (LCD_CSR_BLINKEN | LCD_CSR_BLINKCNT_5 | LCD_CSR_BLINKCNT_4 | LCD_CSR_BLINKCNT_3 | LCD_CSR_BLINKCNT_2 | LCD_CSR_BLINKCNT_1 | LCD_CSR_BLINKCNT_0)       /*!< Blink enabled 64/64     */

/**
  * @}
  */

/** @defgroup LCD_CapDrive_Number LCD CapDrive Number  
  * @{
  */

#define LCD_CAPDRIVE_NUMBER_4          (0x00000000U)
#define LCD_CAPDRIVE_NUMBER_8          (LCD_CSR_SWCAP_DRV_NUM_0)
#define LCD_CAPDRIVE_NUMBER_16         (LCD_CSR_SWCAP_DRV_NUM_1)
#define LCD_CAPDRIVE_NUMBER_32         (LCD_CSR_SWCAP_DRV_NUM_1 | LCD_CSR_SWCAP_DRV_NUM_0)
#define LCD_CAPDRIVE_NUMBER_64         (LCD_CSR_SWCAP_DRV_NUM_2)

/**
  * @}
  */

/** @defgroup LCD_Mode LCD Mode
  * @{
  */
  
#define LCD_MODE_0                    ((uint32_t)0x00000000U)
#define LCD_MODE_1                    (LCD_CSR_MODE)

/**
  * @}
  */

/** @defgroup LCD_RAMRegister LCD RAMRegister
  * @{
  */

#define LCD_RAM_REGISTER0               ((uint32_t)0x00000000U) /*!< LCD RAM Register 0  */
#define LCD_RAM_REGISTER1               ((uint32_t)0x00000001U) /*!< LCD RAM Register 1  */
#define LCD_RAM_REGISTER2               ((uint32_t)0x00000002U) /*!< LCD RAM Register 2  */
#define LCD_RAM_REGISTER3               ((uint32_t)0x00000003U) /*!< LCD RAM Register 3  */
#define LCD_RAM_REGISTER4               ((uint32_t)0x00000004U) /*!< LCD RAM Register 4  */
#define LCD_RAM_REGISTER5               ((uint32_t)0x00000005U) /*!< LCD RAM Register 5  */
#define LCD_RAM_REGISTER6               ((uint32_t)0x00000006U) /*!< LCD RAM Register 6  */
#define LCD_RAM_REGISTER7               ((uint32_t)0x00000007U) /*!< LCD RAM Register 7  */
#define LCD_RAM_REGISTER8               ((uint32_t)0x00000008U) /*!< LCD RAM Register 8  */
#define LCD_RAM_REGISTER9               ((uint32_t)0x00000009U) /*!< LCD RAM Register 9  */
#define LCD_RAM_REGISTER10              ((uint32_t)0x0000000AU) /*!< LCD RAM Register 10 */
#define LCD_RAM_REGISTER11              ((uint32_t)0x0000000BU) /*!< LCD RAM Register 11 */
#define LCD_RAM_REGISTER12              ((uint32_t)0x0000000CU) /*!< LCD RAM Register 12 */
#define LCD_RAM_REGISTER13              ((uint32_t)0x0000000DU) /*!< LCD RAM Register 13 */
#define LCD_RAM_REGISTER14              ((uint32_t)0x0000000EU) /*!< LCD RAM Register 14 */
#define LCD_RAM_REGISTER15              ((uint32_t)0x0000000FU) /*!< LCD RAM Register 15 */

/**
  * @}
  */

/** @defgroup LCD_Interrupt LCD Interrupt
  * @{
  */
#define LCD_IT_BKF                        LCD_CSR_BKFIE
#define LCD_IT_SOF                        LCD_CSR_SOFIE
#define LCD_IT_UDD                        LCD_CSR_UDDIE
#define LCD_IT                            (LCD_IT_BKFIE | LCD_IT_SOFIE | LCD_IT_UDDIE)

/**
  * @}
  */

/** @defgroup LCD_Flag LCD Flag
  * @{
  */
#define LCD_FLAG_ENS                   LCD_CSR_ENS
#define LCD_FLAG_UDR                   LCD_CSR_UDR
#define LCD_FLAG_UDD                   LCD_CSR_UDD
#define LCD_FLAG_SOF                   LCD_CSR_SOF
#define LCD_FLAG_BKF                   LCD_CSR_BKF
#define LCD_FLAG_INTF                 (LCD_CSR_ENS | LCD_FLAG_UDD | LCD_FLAG_SOF | LCD_FLAG_BKF)

/**
  * @}
  */

 
/**
  * @}
  */
 
/* Exported macro ------------------------------------------------------------*/

/** @defgroup LCD_Exported_Macros LCD Exported Macros
  * @{
  */

/** @brief Reset LCD handle state
  * @param  __HANDLE__ specifies the LCD Handle.
  * @retval None
  */
#define __HAL_LCD_RESET_HANDLE_STATE(__HANDLE__)  ((__HANDLE__)->State = HAL_LCD_STATE_RESET)

/** @brief  macros to enables or disables the LCD
  * @param  __HANDLE__ specifies the LCD Handle.  
  * @retval None
  */     
#define __HAL_LCD_ENABLE(__HANDLE__)              (SET_BIT((__HANDLE__)->Instance->CR, LCD_CR_EN))
#define __HAL_LCD_DISABLE(__HANDLE__)             (CLEAR_BIT((__HANDLE__)->Instance->CR, LCD_CR_EN))

/**
  * @brief  Macro to configure the LCD Contrast.
  * @param  __HANDLE__ specifies the LCD Handle.
  * @param  __CONTRAST__ specifies the LCD Contrast.
  *   This parameter can be one of the following values:
  *     @arg LCD_CONTRASTLEVEL_0
  *     @arg LCD_CONTRASTLEVEL_1
  *     @arg LCD_CONTRASTLEVEL_2
  *     @arg LCD_CONTRASTLEVEL_3
  *     @arg LCD_CONTRASTLEVEL_4
  *     @arg LCD_CONTRASTLEVEL_5
  *     @arg LCD_CONTRASTLEVEL_6
  *     @arg LCD_CONTRASTLEVEL_7
  *     @arg LCD_CONTRASTLEVEL_8
  *     @arg LCD_CONTRASTLEVEL_9
  *     @arg LCD_CONTRASTLEVEL_10
  *     @arg LCD_CONTRASTLEVEL_11
  *     @arg LCD_CONTRASTLEVEL_12
  *     @arg LCD_CONTRASTLEVEL_13
  *     @arg LCD_CONTRASTLEVEL_14
  *     @arg LCD_CONTRASTLEVEL_15
  * @retval None
  */
#define __HAL_LCD_CONTRAST_CONFIG(__HANDLE__, __CONTRAST__)    (MODIFY_REG((__HANDLE__)->Instance->CR, LCD_CR_CONTRAST, (__CONTRAST__)))

/** @brief  Enables or disables the specified LCD interrupt.
  * @param  __HANDLE__ specifies the LCD Handle.
  * @param  __INTERRUPT__ specifies the LCD interrupt source to be enabled or disabled.
  *          This parameter can be one of the following values:
  *     @arg LCD_IT_SOF: Start of Frame Interrupt
  *     @arg LCD_IT_UDD: Update Display Done Interrupt
  *     @arg LCD_IT_BKF: Blink Done Interrupt
  * @retval None
  */
#define __HAL_LCD_ENABLE_IT(__HANDLE__, __INTERRUPT__)      (SET_BIT((__HANDLE__)->Instance->CSR, (__INTERRUPT__)))
#define __HAL_LCD_DISABLE_IT(__HANDLE__, __INTERRUPT__)     (CLEAR_BIT((__HANDLE__)->Instance->CSR, (__INTERRUPT__)))

/** @brief  Checks whether the specified LCD interrupt is enabled or not.
  * @param  __HANDLE__ specifies the LCD Handle.
  * @param  __IT__ specifies the LCD interrupt source to check.
  *        This parameter can be one of the following values:
  *     @arg LCD_IT_SOF: Start of Frame Interrupt
  *     @arg LCD_IT_UDD: Update Display Done Interrupt
  *     @arg LCD_IT_BKF: Blink Done Interrupt
  * @retval The state of __IT__ (TRUE or FALSE).
  */
#define __HAL_LCD_GET_IT_SOURCE(__HANDLE__, __IT__) ((((__HANDLE__)->Instance->CSR) & (__IT__)) == (__IT__))

/** @brief  Checks whether the specified LCD flag is set or not.
  * @param  __HANDLE__ specifies the LCD Handle.
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *        @arg LCD_FLAG_ENS: LCD Enabled flag. It indicates the LCD controller status.
  *        @arg LCD_FLAG_SOF: Start of Frame flag. This flag is set by hardware at 
  *             the beginning of a new frame, at the same time as the display data is 
  *             updated.
  *        @arg LCD_FLAG_UDR: Update Display Request flag.
  *        @arg LCD_FLAG_UDD: Update Display Done flag. 
  *        @arg LCD_FLAG_BKF: Blink Done flag. 
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_LCD_GET_FLAG(__HANDLE__, __FLAG__)    (((__HANDLE__)->Instance->CSR & (__FLAG__)) == (__FLAG__))

/** @brief  Clears the specified LCD pending flag.
  * @param  __HANDLE__ specifies the LCD Handle.
  * @param  __FLAG__ specifies the flag to clear.
  *        This parameter can be any combination of the following values:
  *        @arg LCD_FLAG_SOF: Start of Frame Flag
  *        @arg LCD_FLAG_UDD: Update Display Done FLag
  *        @arg LCD_FLAG_BKF: Blink Done Flag
  * @retval None
  */
#define __HAL_LCD_CLEAR_FLAG(__HANDLE__, __FLAG__)  (SET_BIT((__HANDLE__)->Instance->INTCLR, (__FLAG__)))

/** @brief  Enables or disables the LCD blink mode.
  * @param  __HANDLE__ specifies the LCD Handle.
  * @retval None
  */
#define __HAL_LCD_ENABLE_BLINK(__HANDLE__)      (SET_BIT((__HANDLE__)->Instance->CSR, LCD_CSR_BLINKEN))
#define __HAL_LCD_DISABLE_BLINK(__HANDLE__)     (CLEAR_BIT((__HANDLE__)->Instance->CSR, LCD_CSR_BLINKEN))

/** @brief  Configure the number of frames corresponding to LCD blink frequency and interrupt interval
  * @param  __HANDLE__ specifies the LCD Handle.
  * @param  __VALUE__ specifies the number of frames corresponding to LCD blink frequency and interrupt interval.
  * @retval None
  */
#define __HAL_LCD_BLINK_CONFIG(__HANDLE__, __VALUE__)   (MODIFY_REG((__HANDLE__)->Instance->CSR, LCD_CSR_BLINKCNT, (__VALUE__)))

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup LCD_Private_Macros LCD Private Macros
  * @{
  */

#define IS_LCD_SCAN_FREQ(__FREQ__)     (((__FREQ__) == LCD_SCAN_FREQ_64HZ) || \
                                        ((__FREQ__) == LCD_SCAN_FREQ_128HZ) || \
                                        ((__FREQ__) == LCD_SCAN_FREQ_256HZ) || \
                                        ((__FREQ__) == LCD_SCAN_FREQ_512HZ))

#define IS_LCD_BIAS(__BIAS__)         (((__BIAS__) == LCD_BIAS_1_4) || \
                                       ((__BIAS__) == LCD_BIAS_1_3) || \
                                       ((__BIAS__) == LCD_BIAS_1_2))

#define IS_LCD_DUTY(__DUTY__)         (((__DUTY__) == LCD_DUTY_STATIC)  || \
                                       ((__DUTY__) == LCD_DUTY_1_2)     || \
                                       ((__DUTY__) == LCD_DUTY_1_3)     || \
                                       ((__DUTY__) == LCD_DUTY_1_4)     || \
                                       ((__DUTY__) == LCD_DUTY_1_6)     || \
                                       ((__DUTY__) == LCD_DUTY_1_8))

#define IS_LCD_BIAS_SRC(__SOURCE__)   (((__SOURCE__) == LCD_BIAS_SOURCE_INTERNAL_RESISTANCE) || \
                                       ((__SOURCE__) == LCD_BIAS_SOURCE_EXTERNAL_RESISTANCE) || \
                                       ((__SOURCE__) == LCD_BIAS_SOURCE_EXTERNAL_CAPACITANCE))

#define IS_LCD_CONTRAST(__CONTRAST__) (((__CONTRAST__) == LCD_CONTRASTLEVEL_0) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_1) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_2) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_3) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_4) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_5) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_6) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_7) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_8) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_9) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_10) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_11) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_12) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_13) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_14) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_15))


#if defined(LCD_CR_VSEL)
#define IS_LCD_VOLTAGE_SOURCE(__SOURCE__) (((__SOURCE__) == LCD_VOLTAGE_SOURCE_VCCA) || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_2P6) || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_2P74) || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_2P88) || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_3P02) || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_3P16) || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_3P3)  || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_3P44) || \
                                           ((__SOURCE__) == LCD_VOLTAGE_SOURCE_3P58))
#else
#define IS_LCD_VOLTAGE_SOURCE(__SOURCE__) (((__SOURCE__) == LCD_VOLTAGE_SOURCE_VCCA))
#endif

#define IS_LCD_COMSEGDRIVE_TYPE(__TYPE__) (((__TYPE__) == LCD_COMSEGDRIVE_TYPE_A) || \
                                           ((__TYPE__) == LCD_COMSEGDRIVE_TYPE_B))


#define IS_LCD_FASTCHARGE_CYCLE(__CYCLE__) (((__CYCLE__) == LCD_FASTCHARGE_CYCLE_1_2) || \
                                            ((__CYCLE__) == LCD_FASTCHARGE_CYCLE_1_4) || \
                                            ((__CYCLE__) == LCD_FASTCHARGE_CYCLE_1_8) || \
                                            ((__CYCLE__) == LCD_FASTCHARGE_CYCLE_1_16) || \
                                            ((__CYCLE__) == LCD_FASTCHARGE_CYCLE_1_32) || \
                                            ((__CYCLE__) == LCD_FASTCHARGE_CYCLE_1_64)  || \
                                            ((__CYCLE__) == LCD_FASTCHARGE_CYCLE_1_128))

#define IS_LCD_CHARGEPUMP_FREQ(__FREQ__) (((__FREQ__) == LCD_CHARGEPUMP_FREQ_512HZ) || \
                                          ((__FREQ__) == LCD_CHARGEPUMP_FREQ_1024HZ) || \
                                          ((__FREQ__) == LCD_CHARGEPUMP_FREQ_2048HZ) || \
                                          ((__FREQ__) == LCD_CHARGEPUMP_FREQ_4096HZ) || \
                                          ((__FREQ__) == LCD_CHARGEPUMP_FREQ_8192HZ) || \
                                          ((__FREQ__) == LCD_CHARGEPUMP_FREQ_16384HZ))

#define IS_LCD_CHARGEPUMP_SETTIME(__SETTIME__) (((__SETTIME__) == LCD_CHARGEPUMP_SETTIME_256CLOCK) || \
                                                ((__SETTIME__) == LCD_CHARGEPUMP_SETTIME_512CLOCK) || \
                                                ((__SETTIME__) == LCD_CHARGEPUMP_SETTIME_1024CLOCK) || \
                                                ((__SETTIME__) == LCD_CHARGEPUMP_SETTIME_2048CLOCK))

#define IS_LCD_DEAD_TIME(__TIME__) (((__TIME__) == LCD_DEAD_TIME_0) || \
                                    ((__TIME__) == LCD_DEAD_TIME_1) || \
                                    ((__TIME__) == LCD_DEAD_TIME_2) || \
                                    ((__TIME__) == LCD_DEAD_TIME_3) || \
                                    ((__TIME__) == LCD_DEAD_TIME_4) || \
                                    ((__TIME__) == LCD_DEAD_TIME_5)  || \
                                    ((__TIME__) == LCD_DEAD_TIME_6)  || \
                                    ((__TIME__) == LCD_DEAD_TIME_7))

#define IS_LCD_BLINK_FREQ(__FREQ__) (((__FREQ__) == LCD_BLINK_FREQ_OFF)   || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV1)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV2)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV3)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV4)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV5)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV6)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV7)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV8)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV9)  || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV10) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV11) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV12) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV13) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV14) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV15) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV16) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV17) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV18) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV19) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV20) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV21) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV22) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV23) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV24) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV25) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV26) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV27) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV28) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV29) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV30) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV31) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV32) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV33) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV34) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV35) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV36) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV37) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV38) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV39) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV40) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV41) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV42) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV43) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV44) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV45) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV46) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV47) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV48) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV49) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV50) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV51) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV52) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV53) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV54) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV55) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV56) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV57) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV58) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV59) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV60) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV61) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV62) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV63) || \
                                     ((__FREQ__) == LCD_BLINK_FREQ_DIV64))


#define IS_LCD_CAPDRIVE_NUMBER(__NUMBER__) (((__NUMBER__) == LCD_CAPDRIVE_NUMBER_4)  || \
                                            ((__NUMBER__) == LCD_CAPDRIVE_NUMBER_8)  || \
                                            ((__NUMBER__) == LCD_CAPDRIVE_NUMBER_16)  || \
                                            ((__NUMBER__) == LCD_CAPDRIVE_NUMBER_32)  || \
                                            ((__NUMBER__) == LCD_CAPDRIVE_NUMBER_64))



#define IS_LCD_MODE(__MODE__)         (((__MODE__) == LCD_MODE_0) || \
                                       ((__MODE__) == LCD_MODE_1))

#define IS_LCD_RAM_REGISTER(__REGISTER__) (((__REGISTER__) == LCD_RAM_REGISTER0)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER1)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER2)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER3)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER4)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER5)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER6)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER7)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER8)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER9)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER10) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER11) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER12) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER13) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER14) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER15))


/**
  * @}
  */
  
/* Exported functions ------------------------------------------------------- */

/** @defgroup LCD_Exported_Functions LCD Exported Functions
  * @{
  */

/** @defgroup LCD_Exported_Functions_Group1 Initialization and de-initialization methods
  * @{
  */

/* Initialization/de-initialization methods  **********************************/
HAL_StatusTypeDef     HAL_LCD_DeInit(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef     HAL_LCD_Init(LCD_HandleTypeDef *hlcd);
void                  HAL_LCD_MspInit(LCD_HandleTypeDef *hlcd);
void                  HAL_LCD_MspDeInit(LCD_HandleTypeDef *hlcd);

/**
  * @}
  */

/** @defgroup LCD_Exported_Functions_Group2 IO operation methods
  * @{
  */

/* IO operation methods *******************************************************/
HAL_StatusTypeDef     HAL_LCD_SetSegCom(LCD_HandleTypeDef *hlcd, LCD_SegComTypeDef *SegCom);
HAL_StatusTypeDef     HAL_LCD_Write(LCD_HandleTypeDef *hlcd, uint32_t RAMRegisterIndex, uint32_t Data);
HAL_StatusTypeDef     HAL_LCD_Clear(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef     HAL_LCD_UpdateDisplayRequest(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef     HAL_LCD_UpdateDisplayRequest_IT(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef     HAL_LCD_WaitForSOF(LCD_HandleTypeDef *hlcd);

void HAL_LCD_IRQHandler(LCD_HandleTypeDef *hlcd);
void HAL_LCD_UDDCallback(LCD_HandleTypeDef *hlcd);
void HAL_LCD_SOFCallback(LCD_HandleTypeDef *hlcd);
void HAL_LCD_BKFCallback(LCD_HandleTypeDef *hlcd);
/**
  * @}
  */

/** @defgroup LCD_Exported_Functions_Group3 Peripheral State methods
  * @{
  */

/* Peripheral State methods  **************************************************/
HAL_LCD_StateTypeDef  HAL_LCD_GetState(LCD_HandleTypeDef *hlcd);
uint32_t              HAL_LCD_GetError(LCD_HandleTypeDef *hlcd);

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

#endif /* __PY32C882_HAL_LCD_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
