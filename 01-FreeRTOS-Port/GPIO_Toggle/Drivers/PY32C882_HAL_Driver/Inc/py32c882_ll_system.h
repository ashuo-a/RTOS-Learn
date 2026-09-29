/**
  ******************************************************************************
  * @file    py32c882_ll_system.h
  * @author  MCU Application Team
  * @brief   Header file of SYSTEM LL module.
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
#ifndef PY32C882_LL_SYSTEM_H
#define PY32C882_LL_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c8xx.h"

/** @addtogroup PY32C882_LL_Driver
  * @{
  */

#if defined (FLASH) || defined (SYSCFG) || defined (DBGMCU) || defined (VREFBUF)

/** @defgroup SYSTEM_LL SYSTEM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Private_Constants SYSTEM Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Constants SYSTEM Exported Constants
  * @{
  */

/** @defgroup SYSTEM_LL_EC_REMAP SYSCFG REMAP
  * @{
  */
#define LL_SYSCFG_REMAP_FLASH               0x00000000U                                           /*!< Main Flash memory mapped at 0x00000000 */
#define LL_SYSCFG_REMAP_SYSTEMFLASH         SYSCFG_CFGR1_MEM_MODE_0                               /*!< System Flash memory mapped at 0x00000000 */
#define LL_SYSCFG_REMAP_SRAM                (SYSCFG_CFGR1_MEM_MODE_1 | SYSCFG_CFGR1_MEM_MODE_0)   /*!< Embedded SRAM mapped at 0x00000000 */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_I2C_ANF I2C ANALOG FILTER ENABLE CONTORL
  * @{
  */
#define LL_SYSCFG_I2C_ANF_PA11           SYSCFG_IOCFG_PA_EIIC_0
#define LL_SYSCFG_I2C_ANF_PA12           SYSCFG_IOCFG_PA_EIIC_1
#define LL_SYSCFG_I2C_ANF_PA13           SYSCFG_IOCFG_PA_EIIC_2
#define LL_SYSCFG_I2C_ANF_PA14           SYSCFG_IOCFG_PA_EIIC_3
#define LL_SYSCFG_I2C_ANF_PB4            SYSCFG_IOCFG_PB_EIIC_0
#define LL_SYSCFG_I2C_ANF_PB5            SYSCFG_IOCFG_PB_EIIC_1
#define LL_SYSCFG_I2C_ANF_PB8            SYSCFG_IOCFG_PB_EIIC_2
#define LL_SYSCFG_I2C_ANF_PB9            SYSCFG_IOCFG_PB_EIIC_3
#define LL_SYSCFG_I2C_ANF_PB12           SYSCFG_IOCFG_PB_EIIC_4
#define LL_SYSCFG_I2C_ANF_PB13           SYSCFG_IOCFG_PB_EIIC_5
#define LL_SYSCFG_I2C_ANF_PC5            SYSCFG_IOCFG_PC_EIIC_0
#define LL_SYSCFG_I2C_ANF_PC6            SYSCFG_IOCFG_PC_EIIC_1
#define LL_SYSCFG_I2C_ANF_PC7            SYSCFG_IOCFG_PC_EIIC_2
#define LL_SYSCFG_I2C_ANF_PC9            SYSCFG_IOCFG_PC_EIIC_3
#define LL_SYSCFG_I2C_ANF_PC10           SYSCFG_IOCFG_PC_EIIC_4
#define LL_SYSCFG_I2C_ANF_PC12           SYSCFG_IOCFG_PC_EIIC_5
#define LL_SYSCFG_I2C_ANF_PC13           SYSCFG_IOCFG_PC_EIIC_6
#define LL_SYSCFG_I2C_ANF_PC14           SYSCFG_IOCFG_PC_EIIC_7
#define LL_SYSCFG_I2C_ANF_PC15           SYSCFG_IOCFG_PC_EIIC_8
#define LL_SYSCFG_I2C_ANF_PD6            SYSCFG_IOCFG_PD_EIIC_0
#define LL_SYSCFG_I2C_ANF_PD7            SYSCFG_IOCFG_PD_EIIC_1
#define LL_SYSCFG_I2C_ANF_PD10           SYSCFG_IOCFG_PD_EIIC_10
#define LL_SYSCFG_I2C_ANF_PD11           SYSCFG_IOCFG_PD_EIIC_11
#define LL_SYSCFG_I2C_ANF_PD14           SYSCFG_IOCFG_PD_EIIC_2
#define LL_SYSCFG_I2C_ANF_PD15           SYSCFG_IOCFG_PD_EIIC_3

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_TIMBREAK SYSCFG TIMER BREAK
  * @{
  */
#if defined(SYSCFG_CFGR2_ECCL)
#define LL_SYSCFG_TIMBREAK_ECC             SYSCFG_CFGR2_ECCL  /*!< Enables and locks the ECC error signal 
                                                                   with Break Input of TIM1/15/16/17/PWM                           */
#endif
#if defined(SYSCFG_CFGR2_PVDL)
#define LL_SYSCFG_TIMBREAK_PVD             SYSCFG_CFGR2_PVDL  /*!< Enables and locks the PVD connection 
                                                                   with TIM1/15/16/17/PWM Break Input 
                                                                   and also the PVDE and PLS bits of the Power Control Interface */
#endif
#if defined(SYSCFG_CFGR2_SPL)
#define LL_SYSCFG_TIMBREAK_SRAM_PARITY     SYSCFG_CFGR2_SPL   /*!< Enables and locks the SRAM_PARITY error signal 
                                                                   with Break Input of TIM1/15/16/17/PWM                           */
#endif
#if defined(SYSCFG_CFGR2_CLL)
#define LL_SYSCFG_TIMBREAK_LOCKUP          SYSCFG_CFGR2_CLL   /*!< Enables and locks the LOCKUP output of CortexM0 
                                                                   with Break Input of TIM1/15/16/17/PWM                             */
#endif
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_DMA_MAP DMA MAP
  * @{
  */
#define LL_SYSCFG_DMA_MAP_ADC               0x00000000U
#if defined(DAC)
#define LL_SYSCFG_DMA_MAP_DAC               0x00000001U
#endif /* DAC */
#define LL_SYSCFG_DMA_MAP_SPI1_RX           0x00000003U
#define LL_SYSCFG_DMA_MAP_SPI1_TX           0x00000004U
#define LL_SYSCFG_DMA_MAP_SPI2_RX           0x00000005U
#define LL_SYSCFG_DMA_MAP_SPI2_TX           0x00000006U
#define LL_SYSCFG_DMA_MAP_USART1_RX         0x00000007U
#define LL_SYSCFG_DMA_MAP_USART1_TX         0x00000008U
#define LL_SYSCFG_DMA_MAP_USART2_RX         0x00000009U
#define LL_SYSCFG_DMA_MAP_USART2_TX         0x0000000AU
#define LL_SYSCFG_DMA_MAP_UART1_RX          0x0000000BU
#define LL_SYSCFG_DMA_MAP_UART1_TX          0x0000000CU
#define LL_SYSCFG_DMA_MAP_LPUART1_RX        0x0000000DU
#define LL_SYSCFG_DMA_MAP_LPUART1_TX        0x0000000EU
#define LL_SYSCFG_DMA_MAP_I2C1_RX           0x0000000FU
#define LL_SYSCFG_DMA_MAP_I2C1_TX           0x00000010U
#define LL_SYSCFG_DMA_MAP_I2C2_RX           0x00000011U
#define LL_SYSCFG_DMA_MAP_I2C2_TX           0x00000012U
#define LL_SYSCFG_DMA_MAP_TIM1_CH1          0x00000013U
#define LL_SYSCFG_DMA_MAP_TIM1_CH2          0x00000014U
#define LL_SYSCFG_DMA_MAP_TIM1_CH3          0x00000015U
#define LL_SYSCFG_DMA_MAP_TIM1_CH4          0x00000016U
#define LL_SYSCFG_DMA_MAP_TIM1_COM          0x00000017U
#define LL_SYSCFG_DMA_MAP_TIM1_TRG         0x00000018U
#define LL_SYSCFG_DMA_MAP_TIM1_UP           0x00000019U
#define LL_SYSCFG_DMA_MAP_TIM2_CH1          0x0000001AU
#define LL_SYSCFG_DMA_MAP_TIM2_CH2          0x0000001BU
#define LL_SYSCFG_DMA_MAP_TIM2_CH3          0x0000001CU
#define LL_SYSCFG_DMA_MAP_TIM2_CH4          0x0000001DU
#define LL_SYSCFG_DMA_MAP_TIM2_UP           0x0000001EU
#define LL_SYSCFG_DMA_MAP_TIM2_TRG         0x0000001FU
#define LL_SYSCFG_DMA_MAP_TIM3_CH1          0x00000020U
#define LL_SYSCFG_DMA_MAP_TIM3_CH2          0x00000021U
#define LL_SYSCFG_DMA_MAP_TIM3_CH3          0x00000022U
#define LL_SYSCFG_DMA_MAP_TIM3_CH4          0x00000023U
#define LL_SYSCFG_DMA_MAP_TIM3_UP           0x00000024U
#define LL_SYSCFG_DMA_MAP_TIM3_TRG         0x00000025U
#define LL_SYSCFG_DMA_MAP_TIM6_UP           0x00000026U
#define LL_SYSCFG_DMA_MAP_TIM7_UP           0x00000027U
#define LL_SYSCFG_DMA_MAP_TIM15_CH1         0x00000028U
#define LL_SYSCFG_DMA_MAP_TIM15_CH2         0x00000029U
#define LL_SYSCFG_DMA_MAP_TIM15_UP          0x0000002AU
#define LL_SYSCFG_DMA_MAP_TIM15_TRG        0x0000002BU
#define LL_SYSCFG_DMA_MAP_TIM15_COM         0x0000002CU
#define LL_SYSCFG_DMA_MAP_TIM16_CH1         0x0000002DU
#define LL_SYSCFG_DMA_MAP_TIM16_UP          0x0000002EU
#define LL_SYSCFG_DMA_MAP_TIM17_CH1         0x0000002FU
#define LL_SYSCFG_DMA_MAP_TIM17_UP          0x00000030U
#define LL_SYSCFG_DMA_MAP_LPUART2_RX        0x00000032U
#define LL_SYSCFG_DMA_MAP_LPUART2_TX        0x00000033U
#define LL_SYSCFG_DMA_MAP_PWM_CH1           0x00000034U
#define LL_SYSCFG_DMA_MAP_PWM_CH2           0x00000035U
#define LL_SYSCFG_DMA_MAP_PWM_CH3           0x00000036U
#define LL_SYSCFG_DMA_MAP_PWM_CH4           0x00000037U
#define LL_SYSCFG_DMA_MAP_PWM_UP            0x00000038U
#define LL_SYSCFG_DMA_MAP_UART2_RX          0x00000039U
#define LL_SYSCFG_DMA_MAP_UART2_TX          0x0000003AU
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_GPIO_PORT GPIO PORT
  * @{
  */
#define LL_SYSCFG_GPIO_PORTA              0x00000000U
#define LL_SYSCFG_GPIO_PORTB              0x00000001U
#define LL_SYSCFG_GPIO_PORTC              0x00000002U
#define LL_SYSCFG_GPIO_PORTD              0x00000003U
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_EC_GPIO_PIN GPIO PIN
  * @{
  */
#define LL_SYSCFG_GPIO_PIN_0              0x00000001U
#define LL_SYSCFG_GPIO_PIN_1              0x00000002U
#define LL_SYSCFG_GPIO_PIN_2              0x00000004U
#define LL_SYSCFG_GPIO_PIN_3              0x00000008U
#define LL_SYSCFG_GPIO_PIN_4              0x00000010U
#define LL_SYSCFG_GPIO_PIN_5              0x00000020U
#define LL_SYSCFG_GPIO_PIN_6              0x00000040U
#define LL_SYSCFG_GPIO_PIN_7              0x00000080U
#define LL_SYSCFG_GPIO_PIN_8              0x00000100U
#define LL_SYSCFG_GPIO_PIN_9              0x00000200U
#define LL_SYSCFG_GPIO_PIN_10             0x00000400U
#define LL_SYSCFG_GPIO_PIN_11             0x00000800U
#define LL_SYSCFG_GPIO_PIN_12             0x00001000U
#define LL_SYSCFG_GPIO_PIN_13             0x00002000U
#define LL_SYSCFG_GPIO_PIN_14             0x00004000U
#define LL_SYSCFG_GPIO_PIN_15             0x00008000U
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_SRAM_PARITY_ERROR_RESPONSE_MODE SRAM PARITY ERROR RESPONSE MODE
  * @{
  */
#define LL_SYSCFPG_RESPONSE_MODE_NMI    0x00000000U
#define LL_SYSCFPG_RESPONSE_MODE_RESET  SYSCFG_SCSR_PERR_RSTEN
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_EC_CCMSRAMWRP SYSCFG CCMSRAM WRP
  * @{
  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE0         SYSCFG_SWPR_SRAM_P0WP  /*!< CCMSRAM Write protection page 0  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE1         SYSCFG_SWPR_SRAM_P1WP  /*!< CCMSRAM Write protection page 1  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE2         SYSCFG_SWPR_SRAM_P2WP  /*!< CCMSRAM Write protection page 2  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE3         SYSCFG_SWPR_SRAM_P3WP  /*!< CCMSRAM Write protection page 3  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE4         SYSCFG_SWPR_SRAM_P4WP  /*!< CCMSRAM Write protection page 4  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE5         SYSCFG_SWPR_SRAM_P5WP  /*!< CCMSRAM Write protection page 5  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE6         SYSCFG_SWPR_SRAM_P6WP  /*!< CCMSRAM Write protection page 6  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE7         SYSCFG_SWPR_SRAM_P7WP  /*!< CCMSRAM Write protection page 7  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE8         SYSCFG_SWPR_SRAM_P8WP  /*!< CCMSRAM Write protection page 8  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE9         SYSCFG_SWPR_SRAM_P9WP  /*!< CCMSRAM Write protection page 9  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE10        SYSCFG_SWPR_SRAM_P10WP /*!< CCMSRAM Write protection page 10 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE11        SYSCFG_SWPR_SRAM_P11WP /*!< CCMSRAM Write protection page 11 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE12        SYSCFG_SWPR_SRAM_P12WP /*!< CCMSRAM Write protection page 12 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE13        SYSCFG_SWPR_SRAM_P13WP /*!< CCMSRAM Write protection page 13 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE14        SYSCFG_SWPR_SRAM_P14WP /*!< CCMSRAM Write protection page 14 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE15        SYSCFG_SWPR_SRAM_P15WP /*!< CCMSRAM Write protection page 15 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE16        SYSCFG_SWPR_SRAM_P16WP /*!< CCMSRAM Write protection page 16 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE17        SYSCFG_SWPR_SRAM_P17WP /*!< CCMSRAM Write protection page 17 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE18        SYSCFG_SWPR_SRAM_P18WP /*!< CCMSRAM Write protection page 18 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE19        SYSCFG_SWPR_SRAM_P19WP /*!< CCMSRAM Write protection page 19 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE20        SYSCFG_SWPR_SRAM_P20WP /*!< CCMSRAM Write protection page 20 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE21        SYSCFG_SWPR_SRAM_P21WP /*!< CCMSRAM Write protection page 21 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE22        SYSCFG_SWPR_SRAM_P22WP /*!< CCMSRAM Write protection page 22 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE23        SYSCFG_SWPR_SRAM_P23WP /*!< CCMSRAM Write protection page 23 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE24        SYSCFG_SWPR_SRAM_P24WP /*!< CCMSRAM Write protection page 24 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE25        SYSCFG_SWPR_SRAM_P25WP /*!< CCMSRAM Write protection page 25 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE26        SYSCFG_SWPR_SRAM_P26WP /*!< CCMSRAM Write protection page 26 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE27        SYSCFG_SWPR_SRAM_P27WP /*!< CCMSRAM Write protection page 27 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE28        SYSCFG_SWPR_SRAM_P28WP /*!< CCMSRAM Write protection page 28 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE29        SYSCFG_SWPR_SRAM_P29WP /*!< CCMSRAM Write protection page 29 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE30        SYSCFG_SWPR_SRAM_P30WP /*!< CCMSRAM Write protection page 30 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE31        SYSCFG_SWPR_SRAM_P31WP /*!< CCMSRAM Write protection page 31 */
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_GPIO_SEL GPIO SEL
  * @{
  */
#define LL_SYSCFG_GPIO_SEL_FASTIO          0x00000000U 
#define LL_SYSCFG_GPIO_SEL_AHB             SYSCFG_CFGR1_GPIO_AHB_SEL
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_TK_LP_TRIG  TK Lowpower Wakeup Trigger Source
  * @{
  */
#define LL_SYSCFG_TK_LP_TRIG_DISABLE        0x00000000U
#define LL_SYSCFG_TK_LP_TRIG_RTC            SYSCFG_CFGR1_TK_LP_TRIG_0
#define LL_SYSCFG_TK_LP_TRIG_LPTIM1         SYSCFG_CFGR1_TK_LP_TRIG_1
#define LL_SYSCFG_TK_LP_TRIG_LPTIM2         (SYSCFG_CFGR1_TK_LP_TRIG_1 | SYSCFG_CFGR1_TK_LP_TRIG_0)
/**
  * @}
  */

/** @defgroup SYSTEM_LL_RTC_TRIG_TK_SEL RTC Trigger TK Select
  * @{
  */
#define LL_SYSCFG_RTC_TRIG_TK_SEL_WAKEUP_TIMER   0x00000000U
#define LL_SYSCFG_RTC_TRIG_TK_SEL_ALARMA         SYSCFG_CFGR1_RTC_TRIG_TKSEL_0
#define LL_SYSCFG_RTC_TRIG_TK_SEL_ALARMB         SYSCFG_CFGR1_RTC_TRIG_TKSEL_1
/**
  * @}
  */
  
/** @defgroup SYSCFG_LL_PU_IIC I2C PIN PULL-UP
  * @{
  */
#define LL_SYSCFG_PU_IIC_PD14    SYSCFG_IOCFG_PD_PU_IIC_0
#define LL_SYSCFG_PU_IIC_PD15    SYSCFG_IOCFG_PD_PU_IIC_1
/**
  * @}
  */
  
/** @defgroup SYSCFG_LL_EHS LED PIN HIGH DRIVER SIGNAL
  * @{
  */
#define LL_SYSCFG_SEGIS_EN_0    SYSCFG_LEDCFG_SEGIS_EN_0
#define LL_SYSCFG_SEGIS_EN_1    SYSCFG_LEDCFG_SEGIS_EN_1
#define LL_SYSCFG_SEGIS_EN_2    SYSCFG_LEDCFG_SEGIS_EN_2
#define LL_SYSCFG_SEGIS_EN_3    SYSCFG_LEDCFG_SEGIS_EN_3

#define LL_SYSCFG_EHS_PB2       SYSCFG_LEDCFG_PB_EHS_0
#define LL_SYSCFG_EHS_PB3       SYSCFG_LEDCFG_PB_EHS_1
#define LL_SYSCFG_EHS_PB4       SYSCFG_LEDCFG_PB_EHS_2
#define LL_SYSCFG_EHS_PB5       SYSCFG_LEDCFG_PB_EHS_3
#define LL_SYSCFG_EHS_PB6       SYSCFG_LEDCFG_PB_EHS_4
#define LL_SYSCFG_EHS_PB7       SYSCFG_LEDCFG_PB_EHS_5
#define LL_SYSCFG_EHS_PB8       SYSCFG_LEDCFG_PB_EHS_6
#define LL_SYSCFG_EHS_PB9       SYSCFG_LEDCFG_PB_EHS_7

#define LL_SYSCFG_ENSEG_PB2     SYSCFG_LEDCFG_PB_ENSEG_0
#define LL_SYSCFG_ENSEG_PB3     SYSCFG_LEDCFG_PB_ENSEG_1
#define LL_SYSCFG_ENSEG_PB4     SYSCFG_LEDCFG_PB_ENSEG_2
#define LL_SYSCFG_ENSEG_PB5     SYSCFG_LEDCFG_PB_ENSEG_3
#define LL_SYSCFG_ENSEG_PB6     SYSCFG_LEDCFG_PB_ENSEG_4
#define LL_SYSCFG_ENSEG_PB7     SYSCFG_LEDCFG_PB_ENSEG_5
#define LL_SYSCFG_ENSEG_PB8     SYSCFG_LEDCFG_PB_ENSEG_6
#define LL_SYSCFG_ENSEG_PB9     SYSCFG_LEDCFG_PB_ENSEG_7
#define LL_SYSCFG_ENSEG_PB10    SYSCFG_LEDCFG_PB_ENSEG_8
#define LL_SYSCFG_ENSEG_PB11    SYSCFG_LEDCFG_PB_ENSEG_9
#define LL_SYSCFG_ENSEG_PB12    SYSCFG_LEDCFG_PB_ENSEG_10
#define LL_SYSCFG_ENSEG_PB13    SYSCFG_LEDCFG_PB_ENSEG_11
#define LL_SYSCFG_ENSEG_PB14    SYSCFG_LEDCFG_PB_ENSEG_12
#define LL_SYSCFG_ENSEG_PB15    SYSCFG_LEDCFG_PB_ENSEG_13
#define LL_SYSCFG_ENSEG_PC0     SYSCFG_LEDCFG_PC_ENSEG_0
#define LL_SYSCFG_ENSEG_PC1     SYSCFG_LEDCFG_PC_ENSEG_1
/**
  * @}
  */
  
#if defined(VREFBUF)
/** @defgroup SYSCFG_LL_VREFBUF_VoltageScale VREFBUF Voltage Scale
  * @{
  */
#define LL_VREFBUF_Voltage_1P024V         0x00000000UL                                                    /* Vrefbuf 1.024V */  
#define LL_VREFBUF_Voltage_1P5V           VREFBUF_CR_VREFBUF_OUT_SEL_0                                    /* Vrefbuf 1.5V */  
#define LL_VREFBUF_Voltage_2P048V         VREFBUF_CR_VREFBUF_OUT_SEL_1                                    /* Vrefbuf 2.048V */  
#define LL_VREFBUF_Voltage_2P5V           (VREFBUF_CR_VREFBUF_OUT_SEL_1 | VREFBUF_CR_VREFBUF_OUT_SEL_0)   /* Vrefbuf 2.5V */  
#define LL_VREFBUF_Voltage_0P6V           VREFBUF_CR_VREFBUF_OUT_SEL_2                                    /* Vrefbuf 0.6V */  

/**
  * @}
  */
#endif
  
/** @defgroup SYSTEM_LL_EC_LATENCY FLASH LATENCY
  * @{
  */
#define LL_FLASH_LATENCY_0                 0x00000000UL                                  /*!< FLASH Zero wait state */
#define LL_FLASH_LATENCY_1                 FLASH_ACR_LATENCY_0                           /*!< FLASH One wait state */
#define LL_FLASH_LATENCY_2                 FLASH_ACR_LATENCY_1                           /*!< FLASH Two wait state */
#define LL_FLASH_LATENCY_3                 (FLASH_ACR_LATENCY_0 | FLASH_ACR_LATENCY_1)   /*!< FLASH Four wait state */
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_EC_STOP_IP  DBGMCU STOP IP
  * @{
  */
#if defined(DBGMCU_APB_FZ1_DBG_TIM2_STOP)
#define LL_DBGMCU_APB1_GRP1_TIM2_STOP                  DBGMCU_APB_FZ1_DBG_TIM2_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_TIM3_STOP)
#define LL_DBGMCU_APB1_GRP1_TIM3_STOP                  DBGMCU_APB_FZ1_DBG_TIM3_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_TIM6_STOP)
#define LL_DBGMCU_APB1_GRP1_TIM6_STOP                  DBGMCU_APB_FZ1_DBG_TIM6_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_TIM7_STOP)
#define LL_DBGMCU_APB1_GRP1_TIM7_STOP                  DBGMCU_APB_FZ1_DBG_TIM7_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_RTC_STOP)
#define LL_DBGMCU_APB1_GRP1_RTC_STOP                   DBGMCU_APB_FZ1_DBG_RTC_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_WWDG_STOP)
#define LL_DBGMCU_APB1_GRP1_WWDG_STOP                  DBGMCU_APB_FZ1_DBG_WWDG_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_IWDG_STOP)
#define LL_DBGMCU_APB1_GRP1_IWDG_STOP                  DBGMCU_APB_FZ1_DBG_IWDG_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_I2C1_STOP)
#define LL_DBGMCU_APB1_GRP1_I2C1_STOP                  DBGMCU_APB_FZ1_DBG_I2C1_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_I2C2_STOP)
#define LL_DBGMCU_APB1_GRP1_I2C2_STOP                  DBGMCU_APB_FZ1_DBG_I2C2_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_LPTIM2_STOP)
#define LL_DBGMCU_APB1_GRP1_LPTIM2_STOP                DBGMCU_APB_FZ1_DBG_LPTIM2_STOP
#endif
  
#if defined(DBGMCU_APB_FZ1_DBG_LPTIM1_STOP)
#define LL_DBGMCU_APB1_GRP1_LPTIM1_STOP                DBGMCU_APB_FZ1_DBG_LPTIM1_STOP
#endif
  
#if defined(DBGMCU_APB_FZ2_DBG_TIM1_STOP)
#define LL_DBGMCU_APB1_GRP2_TIM1_STOP                  DBGMCU_APB_FZ2_DBG_TIM1_STOP
#endif
  
#if defined(DBGMCU_APB_FZ2_DBG_TIM15_STOP)
#define LL_DBGMCU_APB1_GRP2_TIM15_STOP                 DBGMCU_APB_FZ2_DBG_TIM15_STOP
#endif

#if defined(DBGMCU_APB_FZ2_DBG_TIM16_STOP)
#define LL_DBGMCU_APB1_GRP2_TIM16_STOP                 DBGMCU_APB_FZ2_DBG_TIM16_STOP
#endif
#if defined(DBGMCU_APB_FZ2_DBG_TIM17_STOP)
#define LL_DBGMCU_APB1_GRP2_TIM17_STOP                 DBGMCU_APB_FZ2_DBG_TIM17_STOP
#endif
#if defined(DBGMCU_APB_FZ2_DBG_PWM_STOP)
#define LL_DBGMCU_APB1_GRP2_PWM_STOP                   DBGMCU_APB_FZ2_DBG_PWM_STOP
#endif

/**
  * @}
  */

/**
  * @}
  */
/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Functions SYSTEM Exported Functions
  * @{
  */

/** @defgroup SYSTEM_LL_EF_SYSCFG SYSCFG
  * @{
  */

/**
  * @brief  Set FASTIO or AHB to access the GPIO register control
  * @rmtoll SYSCFG_CFGR1 GPIO_AHB_SEL      LL_SYSCFG_SetGPIOAccess
  * @param  GPIOSel This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_SEL_FASTIO
  *         @arg @ref LL_SYSCFG_GPIO_SEL_AHB
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetGPIOAccess(uint32_t GPIOSel)
{
  MODIFY_REG(SYSCFG->CFGR1, SYSCFG_CFGR1_GPIO_AHB_SEL, GPIOSel);
}

/**
  * @brief  Get FASTIO or AHB to access the GPIO register control
  * @rmtoll SYSCFG_CFGR1 GPIO_AHB_SEL      LL_SYSCFG_GetGPIOAccess
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_SEL_FASTIO
  *         @arg @ref LL_SYSCFG_GPIO_SEL_AHB
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetGPIOAccess(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_GPIO_AHB_SEL));
}  

/**
  * @brief  Set memory mapping at address 0x00000000
  * @rmtoll SYSCFG_CFGR1 MEM_MODE      LL_SYSCFG_SetRemapMemory
  * @param  Memory This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_REMAP_FLASH
  *         @arg @ref LL_SYSCFG_REMAP_SYSTEMFLASH
  *         @arg @ref LL_SYSCFG_REMAP_SRAM
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetRemapMemory(uint32_t Memory)
{
  MODIFY_REG(SYSCFG->CFGR1, SYSCFG_CFGR1_MEM_MODE, Memory);
}

/**
  * @brief  Get memory mapping at address 0x00000000
  * @rmtoll SYSCFG_CFGR1 MEM_MODE      LL_SYSCFG_GetRemapMemory
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_REMAP_FLASH
  *         @arg @ref LL_SYSCFG_REMAP_SYSTEMFLASH
  *         @arg @ref LL_SYSCFG_REMAP_SRAM
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetRemapMemory(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_MEM_MODE));
}

/**
  * @brief  Set the source for counting the TK wakeup interval time.
  * @param  Source Source of TK Wake-up Interval Count.
  *          This parameter can be one of the following values:
  *            @arg LL_SYSCFG_TK_LP_TRIG_DISABLE
  *            @arg LL_SYSCFG_TK_LP_TRIG_RTC    
  *            @arg LL_SYSCFG_TK_LP_TRIG_LPTIM1 
  *            @arg LL_SYSCFG_TK_LP_TRIG_LPTIM2 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetTKLPTRIG(uint32_t Source)
{
  MODIFY_REG(SYSCFG->CFGR1, SYSCFG_CFGR1_TK_LP_TRIG, Source);  
}

/**
  * @brief  Get the source for counting the TK wakeup interval time.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_TK_LP_TRIG_DISABLE
  *         @arg @ref LL_SYSCFG_TK_LP_TRIG_RTC    
  *         @arg @ref LL_SYSCFG_TK_LP_TRIG_LPTIM1 
  *         @arg @ref LL_SYSCFG_TK_LP_TRIG_LPTIM2 
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetTKLPTRIG(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_TK_LP_TRIG));
}

/**
  * @brief  Set the source selection for the RTC-controlled TK wake-up interval.
  * @param  Source RTC-controlled TK wake-up interval Source.
  *          This parameter can be one of the following values:
  *            @arg LL_SYSCFG_RTC_TRIG_TK_SEL_WAKEUP_TIMER
  *            @arg LL_SYSCFG_RTC_TRIG_TK_SEL_ALARMA      
  *            @arg LL_SYSCFG_RTC_TRIG_TK_SEL_ALARMB      
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetRTCTRIGTKSEL(uint32_t Source)
{
  MODIFY_REG(SYSCFG->CFGR1, SYSCFG_CFGR1_RTC_TRIG_TKSEL, Source);  
}

/**
  * @brief  Get the source selection for the RTC-controlled TK wake-up interval.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_RTC_TRIG_TK_SEL_WAKEUP_TIMER
  *         @arg @ref LL_SYSCFG_RTC_TRIG_TK_SEL_ALARMA      
  *         @arg @ref LL_SYSCFG_RTC_TRIG_TK_SEL_ALARMB      
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetRTCTRIGTKSEL(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_RTC_TRIG_TKSEL));
}

#if defined(SYSCFG_CFGR1_LPTIM1_TRIG_TKEN)
/**
  * @brief  Enable LPTIM1 count overflow triggers TK low-power wake-up
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableLPTIM1TrigTK(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_LPTIM1_TRIG_TKEN);  
}

/**
  * @brief  Disable LPTIM1 count overflow triggers TK low-power wake-up
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableLPTIM1TrigTK(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_LPTIM1_TRIG_TKEN);  
}

/**
  * @brief  Check if LPTIM1 count overflow triggers TK low-power wake-up is enabld
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledLPTIM1TrigTK(void)
{
  return ((READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_LPTIM1_TRIG_TKEN) == (SYSCFG_CFGR1_LPTIM1_TRIG_TKEN)) ? 1UL : 0UL);  
}
#endif

#if defined(SYSCFG_CFGR1_LPTIM2_TRIG_TKEN)
/**
  * @brief  Enable LPTIM2 count overflow triggers TK low-power wake-up
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableLPTIM2TrigTK(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_LPTIM2_TRIG_TKEN);  
}

/**
  * @brief  Disable LPTIM2 count overflow triggers TK low-power wake-up
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableLPTIM2TrigTK(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_LPTIM2_TRIG_TKEN);  
}

/**
  * @brief  Check if LPTIM2 count overflow triggers TK low-power wake-up is enabled
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledLPTIM2TrigTK(void)
{
  return ((READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_LPTIM2_TRIG_TKEN) == (SYSCFG_CFGR1_LPTIM2_TRIG_TKEN)) ? 1UL : 0UL);  
}
#endif

/**
  * @brief  Set connections to TIM1/15/16/17/PWM Break inputs
  * @rmtoll SYSCFG_CFGR2 CLL           LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 SPL           LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 PVDL          LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 ECCL          LL_SYSCFG_SetTIMBreakInputs
  * @param  Break This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_TIMBREAK_ECC
  *         @arg @ref LL_SYSCFG_TIMBREAK_PVD
  *         @arg @ref LL_SYSCFG_TIMBREAK_SRAM_PARITY
  *         @arg @ref LL_SYSCFG_TIMBREAK_LOCKUP
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetTIMBreakInputs(uint32_t Break)
{
  MODIFY_REG(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL, Break);
}

/**
  * @brief  Get connections to TIM1/15/16/17/PWM Break inputs
  * @rmtoll SYSCFG_CFGR2 CLL           LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 SPL           LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 PVDL          LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 ECCL          LL_SYSCFG_GetTIMBreakInputs
  * @retval Returned value can be can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_TIMBREAK_ECC
  *         @arg @ref LL_SYSCFG_TIMBREAK_PVD
  *         @arg @ref LL_SYSCFG_TIMBREAK_SRAM_PARITY
  *         @arg @ref LL_SYSCFG_TIMBREAK_LOCKUP
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetTIMBreakInputs(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL));
}

/**
  * @brief  Enable GPIO Filter
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOFilter(uint32_t GPIOPort, uint32_t GPIOPin)
{
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    SET_BIT(SYSCFG->PA_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    SET_BIT(SYSCFG->PB_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {    
    SET_BIT(SYSCFG->PC_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {    
    SET_BIT(SYSCFG->PD_ENS, GPIOPin);
  }
  else
  {
    
  }
}

/**
  * @brief  Disable GPIO Filter
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOFilter(uint32_t GPIOPort, uint32_t GPIOPin)
{
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    CLEAR_BIT(SYSCFG->PA_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    CLEAR_BIT(SYSCFG->PB_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {    
    CLEAR_BIT(SYSCFG->PC_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {    
    CLEAR_BIT(SYSCFG->PD_ENS, GPIOPin);
  }
  else
  {
    
  }
}

/**
  * @brief  Check if GPIO Filter is enabled
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIOFilter(uint32_t GPIOPort, uint32_t GPIOPin)
{
  uint32_t temp = 0;
  
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    temp = READ_BIT(SYSCFG->PA_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    temp = READ_BIT(SYSCFG->PB_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {    
    temp = READ_BIT(SYSCFG->PC_ENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {    
    temp = READ_BIT(SYSCFG->PD_ENS, GPIOPin);
  }
  else
  {
    
  }
  
  return ((temp == (GPIOPin)) ? 1U:0U);
}

/**
  * @brief  Enable analog filtering of I2C related IO
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  I2CAnalogFilter This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA11 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB4  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB5  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB8  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB9  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC5  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC6  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC7  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC9  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC10 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC15 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD6  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD7  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD10 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD11 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD15 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableI2CAnalogFilter(uint32_t I2CAnalogFilter)
{
  SET_BIT(SYSCFG->IOCFG, I2CAnalogFilter);
}

/**
  * @brief  Disable analog filtering of I2C related IO
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  I2CAnalogFilter This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA11 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB4  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB5  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB8  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB9  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC5  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC6  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC7  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC9  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC10 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC15 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD6  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD7  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD10 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD11 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD15 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableI2CAnalogFilter(uint32_t I2CAnalogFilter)
{
  CLEAR_BIT(SYSCFG->IOCFG, I2CAnalogFilter);
}

/**
  * @brief  Indicate if analog filtering of I2C related IO is enabled
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  I2CAnalogFilter This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA11 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB4  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB5  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB8  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB9  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC5  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC6  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC7  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC9  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC10 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC12 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC13 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC15 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD6  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD7  
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD10 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD11 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD14 
  *         @arg @ref LL_SYSCFG_I2C_ANF_PD15 
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledI2CAnalogFilter(uint32_t I2CAnalogFilter)
{
  return ((READ_BIT(SYSCFG->IOCFG, I2CAnalogFilter) == (I2CAnalogFilter)) ? 1UL : 0UL);
}

/**
  * @brief  Enable I2C pin pull-up.
  * @param  PORT_Pin specifies the pin
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_PU_IIC_PD14
  *            @arg LL_SYSCFG_PU_IIC_PD15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableI2CPinPullUp(uint32_t PORT_Pin)
{
  SET_BIT(SYSCFG->IOCFG, PORT_Pin);
}

/**
  * @brief  Disable I2C pin pull-up.
  * @param  PORT_Pin specifies the pin
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_PU_IIC_PD14
  *            @arg LL_SYSCFG_PU_IIC_PD15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableI2CPinPullUp(uint32_t PORT_Pin)
{
  CLEAR_BIT(SYSCFG->IOCFG, PORT_Pin);
}

/**
  * @brief  Check if I2C pin pull-up is enabled
  * @param  PORT_Pin specifies the pin
  *         This parameter can be one of the following values:
  *            @arg LL_SYSCFG_PU_IIC_PD14
  *            @arg LL_SYSCFG_PU_IIC_PD15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledI2CPinPullUp(uint32_t PORT_Pin)
{
  return ((READ_BIT(SYSCFG->IOCFG, PORT_Pin) == (PORT_Pin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable high driving capability of LED pins.
  * @param  PORT_Pin specifies the pin
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_EHS_PB2 
  *            @arg LL_SYSCFG_EHS_PB3 
  *            @arg LL_SYSCFG_EHS_PB4 
  *            @arg LL_SYSCFG_EHS_PB5 
  *            @arg LL_SYSCFG_EHS_PB6 
  *            @arg LL_SYSCFG_EHS_PB7 
  *            @arg LL_SYSCFG_EHS_PB8 
  *            @arg LL_SYSCFG_EHS_PB9 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableLEDPinHighDrvSignal(uint32_t PORT_Pin)
{
  SET_BIT(SYSCFG->LEDCFG, PORT_Pin);
}

/**
  * @brief  Disable high driving capability of LED pins.
  * @param  PORT_Pin specifies the pin
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_EHS_PB2 
  *            @arg LL_SYSCFG_EHS_PB3 
  *            @arg LL_SYSCFG_EHS_PB4 
  *            @arg LL_SYSCFG_EHS_PB5 
  *            @arg LL_SYSCFG_EHS_PB6 
  *            @arg LL_SYSCFG_EHS_PB7 
  *            @arg LL_SYSCFG_EHS_PB8 
  *            @arg LL_SYSCFG_EHS_PB9 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableLEDPinHighDrvSignal(uint32_t PORT_Pin)
{
  CLEAR_BIT(SYSCFG->LEDCFG, PORT_Pin);
}

/**
  * @brief  Check if high driving capability of LED pins is enabled
  * @param  PORT_Pin specifies the pin
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_EHS_PB2 
  *            @arg LL_SYSCFG_EHS_PB3 
  *            @arg LL_SYSCFG_EHS_PB4 
  *            @arg LL_SYSCFG_EHS_PB5 
  *            @arg LL_SYSCFG_EHS_PB6 
  *            @arg LL_SYSCFG_EHS_PB7 
  *            @arg LL_SYSCFG_EHS_PB8 
  *            @arg LL_SYSCFG_EHS_PB9 
  * @retval None
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledLEDPinHighDrvSignal(uint32_t PORT_Pin)
{
  return ((READ_BIT(SYSCFG->LEDCFG, PORT_Pin) == (PORT_Pin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable SEG Constant Current Source.
  * @param  SEGx specifies the seg
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_SEGIS_EN_0
  *            @arg LL_SYSCFG_SEGIS_EN_1
  *            @arg LL_SYSCFG_SEGIS_EN_2
  *            @arg LL_SYSCFG_SEGIS_EN_3
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableSEGConstantCurrentSource(uint32_t SEGx)
{
  SET_BIT(SYSCFG->LEDCFG, SEGx);
}

/**
  * @brief  Disable SEG Constant Current Source.
  * @param  SEGx specifies the seg
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_SEGIS_EN_0 
  *            @arg LL_SYSCFG_SEGIS_EN_1 
  *            @arg LL_SYSCFG_SEGIS_EN_2 
  *            @arg LL_SYSCFG_SEGIS_EN_3 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableSEGConstantCurrentSource(uint32_t SEGx)
{
  CLEAR_BIT(SYSCFG->LEDCFG, SEGx);
}

/**
  * @brief  Check if SEG Constant Current Source is enabled
  * @param  SEGx specifies the seg
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_SEGIS_EN_0
  *            @arg LL_SYSCFG_SEGIS_EN_1
  *            @arg LL_SYSCFG_SEGIS_EN_2
  *            @arg LL_SYSCFG_SEGIS_EN_3
  * @retval None
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledSEGConstantCurrentSource(uint32_t SEGx)
{
  return ((READ_BIT(SYSCFG->LEDCFG, SEGx) == (SEGx)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIO Constant Current Source.
  * @param  GPIOx specifies the GPIO
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_ENSEG_PB2 
  *            @arg LL_SYSCFG_ENSEG_PB3 
  *            @arg LL_SYSCFG_ENSEG_PB4 
  *            @arg LL_SYSCFG_ENSEG_PB5 
  *            @arg LL_SYSCFG_ENSEG_PB6 
  *            @arg LL_SYSCFG_ENSEG_PB7 
  *            @arg LL_SYSCFG_ENSEG_PB8 
  *            @arg LL_SYSCFG_ENSEG_PB9 
  *            @arg LL_SYSCFG_ENSEG_PB10
  *            @arg LL_SYSCFG_ENSEG_PB11
  *            @arg LL_SYSCFG_ENSEG_PB12
  *            @arg LL_SYSCFG_ENSEG_PB13
  *            @arg LL_SYSCFG_ENSEG_PB14
  *            @arg LL_SYSCFG_ENSEG_PB15
  *            @arg LL_SYSCFG_ENSEG_PC0 
  *            @arg LL_SYSCFG_ENSEG_PC1 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOConstantCurrentSource(uint32_t GPIOx)
{
  SET_BIT(SYSCFG->LEDCFG, GPIOx);
}

/**
  * @brief  Disable GPIO Constant Current Source..
  * @param  GPIOx specifies the seg
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_ENSEG_PB2 
  *            @arg LL_SYSCFG_ENSEG_PB3 
  *            @arg LL_SYSCFG_ENSEG_PB4 
  *            @arg LL_SYSCFG_ENSEG_PB5 
  *            @arg LL_SYSCFG_ENSEG_PB6 
  *            @arg LL_SYSCFG_ENSEG_PB7 
  *            @arg LL_SYSCFG_ENSEG_PB8 
  *            @arg LL_SYSCFG_ENSEG_PB9 
  *            @arg LL_SYSCFG_ENSEG_PB10
  *            @arg LL_SYSCFG_ENSEG_PB11
  *            @arg LL_SYSCFG_ENSEG_PB12
  *            @arg LL_SYSCFG_ENSEG_PB13
  *            @arg LL_SYSCFG_ENSEG_PB14
  *            @arg LL_SYSCFG_ENSEG_PB15
  *            @arg LL_SYSCFG_ENSEG_PC0 
  *            @arg LL_SYSCFG_ENSEG_PC1 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOConstantCurrentSource(uint32_t GPIOx)
{
  CLEAR_BIT(SYSCFG->LEDCFG, GPIOx);
}

/**
  * @brief  Check if GPIO Constant Current Source is enabled
  * @param  GPIOx specifies the GPIO
  *         This parameter can be any combination of the following values:
  *            @arg LL_SYSCFG_ENSEG_PB2 
  *            @arg LL_SYSCFG_ENSEG_PB3 
  *            @arg LL_SYSCFG_ENSEG_PB4 
  *            @arg LL_SYSCFG_ENSEG_PB5 
  *            @arg LL_SYSCFG_ENSEG_PB6 
  *            @arg LL_SYSCFG_ENSEG_PB7 
  *            @arg LL_SYSCFG_ENSEG_PB8 
  *            @arg LL_SYSCFG_ENSEG_PB9 
  *            @arg LL_SYSCFG_ENSEG_PB10
  *            @arg LL_SYSCFG_ENSEG_PB11
  *            @arg LL_SYSCFG_ENSEG_PB12
  *            @arg LL_SYSCFG_ENSEG_PB13
  *            @arg LL_SYSCFG_ENSEG_PB14
  *            @arg LL_SYSCFG_ENSEG_PB15
  *            @arg LL_SYSCFG_ENSEG_PC0 
  *            @arg LL_SYSCFG_ENSEG_PC1 
  * @retval None
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIOConstantCurrentSource(uint32_t GPIOx)
{
  return ((READ_BIT(SYSCFG->LEDCFG, GPIOx) == (GPIOx)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIO Analog2
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOAnalog2(uint32_t GPIOPort, uint32_t GPIOPin) 
{
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    SET_BIT(SYSCFG->PA_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    SET_BIT(SYSCFG->PB_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {
    SET_BIT(SYSCFG->PC_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {
    SET_BIT(SYSCFG->PD_ANA2EN, GPIOPin);
  }
  else
  {
    
  }
}

/**
  * @brief  Disable GPIO Filter
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOAnalog2(uint32_t GPIOPort, uint32_t GPIOPin) 
{
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    CLEAR_BIT(SYSCFG->PA_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    CLEAR_BIT(SYSCFG->PB_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {
    CLEAR_BIT(SYSCFG->PC_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {
    CLEAR_BIT(SYSCFG->PD_ANA2EN, GPIOPin);
  }
  else
  {
    
  }
}

/**
  * @brief  Check if GPIO Analog2 is enabled
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIOAnalog2(uint32_t GPIOPort, uint32_t GPIOPin) 
{
  uint32_t temp = 0;
  
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    temp = READ_BIT(SYSCFG->PA_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    temp = READ_BIT(SYSCFG->PB_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {
    temp = READ_BIT(SYSCFG->PC_ANA2EN, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {
    temp = READ_BIT(SYSCFG->PD_ANA2EN, GPIOPin);
  }
  else
  {
    
  }
  
  return ((temp == (GPIOPin)) ? 1U:0U);
}

/**
  * @brief  Check if SRAM parity error detected
  * @rmtoll SYSCFG_SCSR SPF           LL_SYSCFG_IsActiveFlag_SP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsActiveFlag_SP(void)
{
  return ((READ_BIT(SYSCFG->SCSR, SYSCFG_SCSR_SPF) == (SYSCFG_SCSR_SPF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear SRAM parity error flag
  * @rmtoll SYSCFG_SCSR SPF           LL_SYSCFG_ClearFlag_SP
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_ClearFlag_SP(void)
{
  SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_SPF);
}

/**
  * @brief  Set SRAM parity error response
  * @rmtoll FLASH_SCSR    PERR_RSTEN       LL_SYSCFPG_SetSRAMParityErrorResponseMode
  * @param  ResponseMode This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFPG_RESPONSE_MODE_NMI
  *         @arg @ref LL_SYSCFPG_RESPONSE_MODE_RESET
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFPG_SetSRAMParityErrorResponseMode(uint32_t ResponseMode)
{
  MODIFY_REG(SYSCFG->SCSR, SYSCFG_SCSR_PERR_RSTEN, ResponseMode);
}

/**
  * @brief  Get SRAM parity error response
  * @rmtoll FLASH_SCSR    PERR_RSTEN       LL_SYSCFPG_GetSRAMParityErrorResponseMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFPG_RESPONSE_MODE_NMI
  *         @arg @ref LL_SYSCFPG_RESPONSE_MODE_RESET
  */
__STATIC_INLINE uint32_t LL_SYSCFPG_GetSRAMParityErrorResponseMode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->SCSR, SYSCFG_SCSR_PERR_RSTEN));
}

/**
  * @brief  Enable CCMSRAM page write protection
  * @note Write protection is cleared only by a system reset
  * @rmtoll SYSCFG_SWPR  PAGEx         LL_SYSCFG_EnableCCMSRAMPageWRP
  * @param  CCMSRAMWRP This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE0
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE1
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE2
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE3
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE4
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE5
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE6
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE7
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE8
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE9
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE10
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE11
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE12
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE13
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE14
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE15
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE16
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE17
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE18
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE19
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE20
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE21
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE22
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE23
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE24
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE25
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE26
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE27
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE28
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE29
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE30
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE31
  *
  *         (*) value not defined in all devices
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableCCMSRAMPageWRP(uint32_t CCMSRAMWRP)
{
  SET_BIT(SYSCFG->SWPR, CCMSRAMWRP);
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_FLASH FLASH
  * @{
  */

/**
  * @brief  Set FLASH Latency
  * @rmtoll FLASH_ACR    LATENCY       LL_FLASH_SetLatency
  * @param  Latency This parameter can be one of the following values:
  *         @arg @ref LL_FLASH_LATENCY_0
  *         @arg @ref LL_FLASH_LATENCY_1
  *         @arg @ref LL_FLASH_LATENCY_2
  *         @arg @ref LL_FLASH_LATENCY_3
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetLatency(uint32_t Latency)
{
  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, Latency);
}

/**
  * @brief  Get FLASH Latency
  * @rmtoll FLASH_ACR    LATENCY       LL_FLASH_GetLatency
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_LATENCY_0
  *         @arg @ref LL_FLASH_LATENCY_1
  *         @arg @ref LL_FLASH_LATENCY_2
  *         @arg @ref LL_FLASH_LATENCY_3
  */
__STATIC_INLINE uint32_t LL_FLASH_GetLatency(void)
{
  return (uint32_t)(READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY));
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_DBGMCU DBGMCU
  * @{
  */

/**
  * @brief  Return the device revision identifier
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t LL_DBGMCU_GetRevisionID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_REV_ID) >> DBGMCU_IDCODE_REV_ID_Pos);
}

/**
  * @brief  Return the device identifier
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t LL_DBGMCU_GetDeviceID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_DEV_ID) >> DBGMCU_IDCODE_DEV_ID_Pos);
}

/**
  * @brief  Enable the Debug Module during SLEEP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}

/**
  * @brief  Disable the Debug Module during SLEEP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}

/**
  * @brief  Indicate if enable the Debug Module during SLEEP mode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_IsEnabledDBGSleepMode(void)
{
  return ((READ_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP) == (DBGMCU_CR_DBG_SLEEP)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the Debug Module during STOP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

/**
  * @brief  Disable the Debug Module during STOP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

/**
  * @brief  Indicate if enable the Debug Module during STOP mode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_IsEnabledDBGStopMode(void)
{
  return ((READ_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP) == (DBGMCU_CR_DBG_STOP)) ? 1UL : 0UL);
}
#if defined(DBGMCU_CR_DBG_STDBY)
/**
  * @brief  Enable the Debug Module during Standby mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STDBY);
}

/**
  * @brief  Disable the Debug Module during Standby mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STDBY);
}

/**
  * @brief  Indicate if enable the Debug Module during Standby mode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_IsEnabledDBGStandbyMode(void)
{
  return ((READ_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STDBY) == (DBGMCU_CR_DBG_STDBY)) ? 1UL : 0UL);
}
#endif
/**
  * @brief  Freeze APB1 peripherals (group1 peripherals)
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM3_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM6_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM7_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_RTC_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_WWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_IWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_LPTIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_LPTIM1_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APBFZ1, Periphs);
}

/**
  * @brief  Unfreeze APB1 peripherals (group1 peripherals)
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM3_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM6_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM7_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_RTC_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_WWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_IWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_LPTIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_LPTIM1_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APBFZ1, Periphs);
}

/**
  * @brief  Indicate if Freeze APB1 peripherals (group1 peripherals)
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be one of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM3_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM6_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM7_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_RTC_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_WWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_IWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_LPTIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_LPTIM1_STOP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_APB1_GRP1_IsFreezePeriph(uint32_t Periphs)
{
  return ((READ_BIT(DBGMCU->APBFZ1, Periphs) == (Periphs)) ? 1UL : 0UL);
}

/**
  * @brief  Freeze APB1 peripherals(group2 peripherals)
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM15_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM16_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM17_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_PWM_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP2_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APBFZ2, Periphs);
}

/**
  * @brief  Unfreeze APB1 peripherals(group2 peripherals)
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM15_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM16_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM17_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_PWM_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP2_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APBFZ2, Periphs);
}

/**
  * @brief  Indicate if Freeze APB1 peripherals (group2 peripherals)
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be one of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM15_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM16_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_TIM17_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP2_PWM_STOP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_APB1_GRP2_IsFreezePeriph(uint32_t Periphs)
{
  return ((READ_BIT(DBGMCU->APBFZ2, Periphs) == (Periphs)) ? 1UL : 0UL);
}

/**
  * @}
  */
/** @defgroup SYSTEM_LL_EF_VREFBUF VREFBUF
  * @{
  */
#if defined(VREFBUF)

/**
  * @brief  Enable the Internal Voltage Reference buffer (VREFBUF).
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_Enable(void)
{
  SET_BIT(VREFBUF->CR, VREFBUF_CR_VREFBUF_EN);
}

/**
  * @brief  Disable the Internal Voltage Reference buffer (VREFBUF).
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_Disable(void)
{
  CLEAR_BIT(VREFBUF->CR, VREFBUF_CR_VREFBUF_EN);
}

/**
  * @brief  Check if enable the Internal Voltage Reference buffer (VREFBUF).
  * @retval None
  */
__STATIC_INLINE uint32_t LL_VREFBUF_IsEnabled(void)
{
  return ((READ_BIT(VREFBUF->CR, VREFBUF_CR_VREFBUF_EN) == (VREFBUF_CR_VREFBUF_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the Internal Voltage Reference buffer (VREFBUF).
  * @param  Voltage specifies the vrebuf voltage level
  *         This parameter can be any combination of the following values:
  *            @arg LL_VREFBUF_Voltage_1P024V
  *            @arg LL_VREFBUF_Voltage_1P5V  
  *            @arg LL_VREFBUF_Voltage_2P048V
  *            @arg LL_VREFBUF_Voltage_2P5V  
  *            @arg LL_VREFBUF_Voltage_0P6V  
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_SetVrefbufVoltage(uint32_t Voltage)
{
  MODIFY_REG(VREFBUF->CR, (VREFBUF_CR_VREFBUF_OUT_SEL), Voltage);
}

/**
  * @brief  Get the Internal Voltage Reference buffer (VREFBUF).
  * @retval Returned value can be one of the following values:
  *            @arg LL_VREFBUF_Voltage_1P024V
  *            @arg LL_VREFBUF_Voltage_1P5V  
  *            @arg LL_VREFBUF_Voltage_2P048V
  *            @arg LL_VREFBUF_Voltage_2P5V  
  *            @arg LL_VREFBUF_Voltage_0P6V  
  */
__STATIC_INLINE uint32_t LL_VREFBUF_GetVrefbufVoltage(void)
{
  return (uint32_t)(READ_BIT(VREFBUF->CR, (VREFBUF_CR_VREFBUF_OUT_SEL)));
}

#endif /* VREFBUF */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif /* defined (FLASH) || defined (SYSCFG) || defined (DBGMCU) || defined (VREFBUF) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32C882_LL_SYSTEM_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
