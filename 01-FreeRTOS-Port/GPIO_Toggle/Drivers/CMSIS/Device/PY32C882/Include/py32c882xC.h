/**
  ******************************************************************************
  * @file    py32c882xC.h
  * @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for PY32C8xx devices.
  * @version v1.0.1
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
 

/** @addtogroup CMSIS_Device
  * @{
  */
/** @addtogroup py32c882xC
  * @{
  */

#ifndef __PY32C882XC_H
#define __PY32C882XC_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M0+ Processor and Core Peripherals
   */
#define __CM0PLUS_REV             0 /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             0 /*!< PY32C8xx do not provide MPU                  */
#define __VTOR_PRESENT            1 /*!< Vector  Table  Register supported             */
#define __NVIC_PRIO_BITS          2 /*!< PY32C8xx uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0 /*!< Set to 1 if different SysTick Config is used  */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief PY32C8xx Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */

/*!< Interrupt Number Definition */
typedef enum
{
  /******  Cortex-M0+ Processor Exceptions Numbers ***************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M Hard Fault Interrupt                                   */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M SV Call Interrupt                                     */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M Pend SV Interrupt                                     */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M System Tick Interrupt                                 */
  /******  PY32C8 specific Interrupt Numbers *********************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window Interrupt                                                  */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt(EXTI line 16)           */
  RTC_TAMP_IRQn               = 2,      /*!< RTC and TAMP global Interrupts                                    */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                              */
  EXTI0_1_IRQn                = 5,      /*!< EXTI 0 and 1 Interrupts                                           */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                                      */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                                      */
  LCD_IRQn                    = 8,      /*!< LCD global Interrupt                                              */
  DMA_Channel1_IRQn           = 9,      /*!< DMA Channel 1 Interrupt                                           */
  DMA_Channel2_3_IRQn         = 10,     /*!< DMA Channel 2 and Channel 3 Interrupts                            */
  DMA_Channel4_7_IRQn         = 11,     /*!< DMA Channel 4 to 7 Interrupt                                      */
  ADC_COMP_IRQn               = 12,     /*!< ADC&COMP Interrupts                                               */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts            */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                             */
  TIM6_DAC_LPTIM1_IRQn        = 17,     /*!< TIM6, DAC,and LPTIM1 global Interrupts                            */
  TIM7_LPTIM2_IRQn            = 18,     /*!< TIM7 and LPTIM2 global Interrupt                                  */
  PWM_IRQn                    = 19,     /*!< PWM global Interrupt                                              */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                            */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                            */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                            */
  I2C1_IRQn                   = 23,     /*!< I2C1 global Interrupt                                             */
  I2C2_IRQn                   = 24,     /*!< I2C2 global Interrupt                                             */
  SPI1_IRQn                   = 25,     /*!< SPI1 Interrupt                                                    */
  SPI2_IRQn                   = 26,     /*!< SPI2 Interrupt                                                    */
  USART1_IRQn                 = 27,     /*!< USART1 Interrupt                                                  */
  USART2_IRQn                 = 28,     /*!< USART2 Interrupt                                                  */
  UART1_LPUART1_IRQn          = 29,     /*!< UART1 and LPUART1 Interrupt                                       */
  UART2_LPUART2_IRQn          = 30,     /*!< UART2 and LPUART2 Interrupt                                       */
  TK_IRQn                     = 31,     /*!< TK global Interrupt                                               */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0plus.h"               /* Cortex-M0+ processor and core peripherals */
#include "system_py32c8xx.h"            /* PY32C8xx System Header */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */
typedef struct
{
   __IO uint32_t ISR;              /*!< ADC ISR Register,                   Address offset: 0x00  */
   __IO uint32_t IER;              /*!< ADC IER Register,                   Address offset: 0x04  */
   __IO uint32_t CR;               /*!< ADC CR  Register,                   Address offset: 0x08  */
   __IO uint32_t CFGR;             /*!< ADC CFGR Register,                  Address offset: 0x0C  */
   __IO uint32_t CFGR2;            /*!< ADC CFGR2 Register,                 Address offset: 0x10  */
   __IO uint32_t SMPR1;            /*!< ADC SMPR1 Register,                 Address offset: 0x14  */
   __IO uint32_t SMPR2;            /*!< ADC SMPR2 Register,                 Address offset: 0x18  */
   __IO uint32_t SMPR3;            /*!< ADC SMPR3 Register,                 Address offset: 0x1C  */
   __IO uint32_t SMPR4;            /*!< ADC SMPR4 Register,                 Address offset: 0x20  */
   __IO uint32_t TR;               /*!< ADC TR Register,                    Address offset: 0x24  */
   __IO uint32_t RESERVED1[2];      
   __IO uint32_t SQR1;             /*!< ADC SQR1 Register,                  Address offset: 0x30  */
   __IO uint32_t SQR2;             /*!< ADC SQR2 Register,                  Address offset: 0x34  */
   __IO uint32_t SQR3;             /*!< ADC SQR3 Register,                  Address offset: 0x38  */
   __IO uint32_t SQR4;             /*!< ADC SQR4 Register,                  Address offset: 0x3C  */
   __IO uint32_t DR;               /*!< ADC DR Register,                    Address offset: 0x40  */
   __IO uint32_t RESERVED2[2];      
   __IO uint32_t JSQR;             /*!< ADC JSQR Register,                  Address offset: 0x4C  */
   __IO uint32_t RESERVED3[4];      
   __IO uint32_t OFR1;             /*!< ADC OFR1 Register,                  Address offset: 0x60  */
   __IO uint32_t OFR2;             /*!< ADC OFR2 Register,                  Address offset: 0x64  */
   __IO uint32_t OFR3;             /*!< ADC OFR3 Register,                  Address offset: 0x68  */
   __IO uint32_t OFR4;             /*!< ADC OFR4 Register,                  Address offset: 0x6C  */
   __IO uint32_t RESERVED4[4];      
   __IO uint32_t JDR1;             /*!< ADC JDR1 Register,                  Address offset: 0x80  */
   __IO uint32_t JDR2;             /*!< ADC JDR2 Register,                  Address offset: 0x84  */
   __IO uint32_t JDR3;             /*!< ADC JDR3 Register,                  Address offset: 0x88  */
   __IO uint32_t JDR4;             /*!< ADC JDR4 Register,                  Address offset: 0x8C  */
   __IO uint32_t RESERVED5[9];      
   __IO uint32_t CALFACT;          /*!< ADC CALFACT Register,               Address offset: 0xB4  */
   __IO uint32_t RESERVED6[2];
   __IO uint32_t GCOMP;            /*!< ADC GCOMP Register,                 Address offset: 0xC0  */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CCR;              /*!< ADC common configuration register,             Address offset: ADC1 base address + 0x308 */
} ADC_Common_TypeDef;

/**
* @brief TK Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< TK CR1 Register,                    Address offset: 0x00  */
   __IO uint32_t CR2;              /*!< TK CR2 Register,                    Address offset: 0x04  */
   __IO uint32_t IDACR;            /*!< TK IDACR Register,                  Address offset: 0x08  */
   __IO uint32_t KR;               /*!< TK KR Register,                     Address offset: 0x0C  */
   __IO uint32_t CSR;              /*!< TK CSR Register,                    Address offset: 0x10  */
   __IO uint32_t UCR;              /*!< TK UCR Register,                    Address offset: 0x14  */
   __IO uint32_t STR;              /*!< TK STR Register,                    Address offset: 0x18  */
   __IO uint32_t RESERVED;         /*!< TK RESERVED Register,               Address offset: 0x1C  */
   __IO uint32_t WR;               /*!< TK WR Register,                     Address offset: 0x20  */
   __IO uint32_t SDR;              /*!< TK SDR Register,                    Address offset: 0x24  */
   __IO uint32_t PRSR;             /*!< TK PRSR Register,                   Address offset: 0x28  */
   __IO uint32_t DR;               /*!< TK DR Register,                     Address offset: 0x2C  */
   __IO uint32_t SR;               /*!< TK SR Register,                     Address offset: 0x30  */
   __IO uint32_t IER;              /*!< TK IER Register,                    Address offset: 0x34  */
   __IO uint32_t ICR;              /*!< TK ICR Register,                    Address offset: 0x38  */
   __IO uint32_t CDR;              /*!< TK CDR Register,                    Address offset: 0x3C  */
   __IO uint32_t LPDR;             /*!< TK LPDR Register,                   Address offset: 0x40  */
   __IO uint32_t LPTR;             /*!< TK LPTR Register,                   Address offset: 0x44  */
   __IO uint32_t OPR;              /*!< TK OPR Register,                    Address offset: 0x48  */
   __IO uint32_t RESERVED1[45];     
   __IO uint32_t TR;               /*!< TK TR Register,                     Address offset: 0x100  */
   __IO uint32_t DDR;              /*!< TK DDR Register,                    Address offset: 0x104  */
} TK_TypeDef;

/**
* @brief CRC Registers
*/
typedef struct
{
   __IO uint32_t DR;               /*!< CRC DR Register,                    Address offset: 0x00  */
   __IO uint32_t IDR;              /*!< CRC IDR Register,                   Address offset: 0x04  */
   __IO uint32_t CR;               /*!< CRC CR Register,                    Address offset: 0x08  */
   __IO uint32_t RESERVED1;         
   __IO uint32_t INIT;             /*!< CRC INIT Register,                  Address offset: 0x10  */
   __IO uint32_t POL;              /*!< CRC POL Register,                   Address offset: 0x14  */
} CRC_TypeDef;

/**
  * @brief Comparator
  */
typedef struct
{
  __IO uint32_t CSR;              /*!< COMP control and status register,           Address offset: 0x00 */
  __IO uint32_t FR;               /*!< COMP filter register,                       Address offset: 0x04 */
} COMP_TypeDef;

typedef struct
{
  __IO uint32_t CSR_ODD;          /*!< COMP control and status register located in register of comparator instance odd, used for bits common to several COMP instances, Address offset: 0x00 */
  __IO uint32_t FR_ODD;
  __IO uint32_t CCSR;
  __IO uint32_t RESERVED1;        /*Reserved*/
  __IO uint32_t CSR_EVEN;         /*!< COMP control and status register located in register of comparator instance even, used for bits common to several COMP instances, Address offset: 0x04 */
  __IO uint32_t FR_EVEN;
} COMP_Common_TypeDef;

/**
* @brief OPA Registers
*/
typedef struct
{
   __IO uint32_t RESERVED1[12];      
   __IO uint32_t OCR;              /*!< OPA OCR Register,                   Address offset: 0x30  */
   __IO uint32_t CR;               /*!< OPA CR Register,                    Address offset: 0x34  */
   __IO uint32_t RESERVED2[2];      
   __IO uint32_t TMR;              /*!< OPA TMR Register,                   Address offset: 0x40  */
} OPA_TypeDef;


/**
  * @brief Debug MCU
  */
typedef struct
{
  __IO uint32_t IDCODE;           /*!< MCU device ID code,              Address offset: 0x00 */
  __IO uint32_t CR;               /*!< Debug configuration register,    Address offset: 0x04 */
  __IO uint32_t APBFZ1;           /*!< Debug APB freeze register 1,     Address offset: 0x08 */
  __IO uint32_t APBFZ2;           /*!< Debug APB freeze register 2,     Address offset: 0x0C */
} DBGMCU_TypeDef;

/**
  * @brief DMA Controller
  */
typedef struct
{
  __IO uint32_t ISR;              /*!< DMA interrupt status register,                 Address offset: 0x00 */
  __IO uint32_t IFCR;             /*!< DMA interrupt flag clear register,             Address offset: 0x04 */
} DMA_TypeDef;

typedef struct
{
  __IO uint32_t CCR;              /*!< DMA channel x configuration register        */
  __IO uint32_t CNDTR;            /*!< DMA channel x number of data register       */
  __IO uint32_t CPAR;             /*!< DMA channel x peripheral address register   */
  __IO uint32_t CMAR;             /*!< DMA channel x memory address register       */
  __IO uint32_t CCCFGR;           /*!< DMA channel x CCCFGR register               */
} DMA_Channel_TypeDef;

/**
* @brief EXTI Registers
*/
typedef struct
{
   __IO uint32_t RTSR;             /*!< EXTI RTSR Register,                 Address offset: 0x00  */
   __IO uint32_t FTSR;             /*!< EXTI FTSR Register,                 Address offset: 0x04  */
   __IO uint32_t SWIER;            /*!< EXTI SWIER Register,                Address offset: 0x08  */
   __IO uint32_t PR;               /*!< EXTI PR Register,                   Address offset: 0x0C  */
   __IO uint32_t IOSEL[2];         /*!< EXTI IOSEL Register,                Address offset: 0x10 ~0x14 */
   __IO uint32_t IMR;              /*!< EXTI IMR Register,                  Address offset: 0x18  */
   __IO uint32_t EMR;              /*!< EXTI EMR Register,                  Address offset: 0x1C  */
} EXTI_TypeDef;

/**
* @brief VREFBUF Registers
*/
typedef struct
{
   __IO uint32_t CR;              /*!< PWR CR Register,                   Address offset: 0x00  */
} VREFBUF_TypeDef;

/**
  * @brief FLASH Registers
  */
typedef struct
{
   __IO uint32_t ACR;              /*!< FLASH ACR Register,                 Address offset: 0x00  */
   __IO uint32_t RESERVED1;         
   __IO uint32_t KEYR;             /*!< FLASH KEYR Register,                Address offset: 0x08  */
   __IO uint32_t OPTKEYR;          /*!< FLASH OPTKEYR Register,             Address offset: 0x0C  */
   __IO uint32_t SR;               /*!< FLASH SR Register,                  Address offset: 0x10  */
   __IO uint32_t CR;               /*!< FLASH CR Register,                  Address offset: 0x14  */
   __IO uint32_t ECCR;             /*!< FLASH ECCR Register,                Address offset: 0x18  */
   __IO uint32_t RESERVED2;         
   __IO uint32_t OPTR;             /*!< FLASH OPTR Register,                Address offset: 0x20  */
   __IO uint32_t RESERVED3;         
   __IO uint32_t WRPR;             /*!< FLASH WRPR Register,                Address offset: 0x28  */
   __IO uint32_t RESERVED4;         
   __IO uint32_t PCROPR0;          /*!< FLASH PCROPR0 Register,             Address offset: 0x30  */
   __IO uint32_t PCROPR1;          /*!< FLASH PCROPR1 Register,             Address offset: 0x34  */
   __IO uint32_t RESERVED5[22];     
   __IO uint32_t LPCR;             /*!< FLASH LPCR Register,                Address offset: 0x90  */
   __IO uint32_t RESERVED6[27];     
   __IO uint32_t TS0;              /*!< FLASH TS0 Register,                 Address offset: 0x100  */
   __IO uint32_t TS1;              /*!< FLASH TS1 Register,                 Address offset: 0x104  */
   __IO uint32_t TS2P;             /*!< FLASH TS2P Register,                Address offset: 0x108  */
   __IO uint32_t TPS3;             /*!< FLASH TPS3 Register,                Address offset: 0x10C  */
   __IO uint32_t TS3;              /*!< FLASH TS3 Register,                 Address offset: 0x110  */
   __IO uint32_t PERTPE;           /*!< FLASH PERTPE Register,              Address offset: 0x114  */
   __IO uint32_t SMERTPE;          /*!< FLASH SMERTPE Register,             Address offset: 0x118  */
   __IO uint32_t PRGTPE;           /*!< FLASH PRGTPE Register,              Address offset: 0x11C  */
   __IO uint32_t PRETPE;           /*!< FLASH PRETPE Register,              Address offset: 0x120  */
   __IO uint32_t TACLK2PW;         /*!< FLASH TACLK2PW Register,            Address offset: 0x124  */
} FLASH_TypeDef;

/**
  * @brief General Purpose I/O
  */
typedef struct
{
  __IO uint32_t MODER;            /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;           /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;          /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;            /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;              /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;              /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;             /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
  __IO uint32_t LCKR;             /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];           /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  __IO uint32_t BRR;              /*!< GPIO Bit Reset register,               Address offset: 0x28      */
} GPIO_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */
typedef struct
{
  __IO uint32_t CR1;              /*!< I2C Control register 1,                Address offset: 0x00 */
  __IO uint32_t CR2;              /*!< I2C Control register 2,                Address offset: 0x04 */
  __IO uint32_t OAR1;             /*!< I2C Own address register 1,            Address offset: 0x08 */
  __IO uint32_t OAR2;             /*!< I2C Own address register 2,            Address offset: 0x0C */
  __IO uint32_t DR;               /*!< I2C Data register,                     Address offset: 0x10 */
  __IO uint32_t SR1;              /*!< I2C Status register 1,                 Address offset: 0x14 */
  __IO uint32_t SR2;              /*!< I2C Status register 2,                 Address offset: 0x18 */
  __IO uint32_t CCR;              /*!< I2C Clock control register,            Address offset: 0x1C */
  __IO uint32_t TRISE;            /*!< I2C TRISE register,                    Address offset: 0x20 */
  __IO uint32_t TIMEOUTR;         /*!< I2C TIMEOUTR register,                 Address offset: 0x24 */
} I2C_TypeDef;

/**
* @brief IWDG Registers
*/
typedef struct
{
   __IO uint32_t KR;               /*!< IWDG KR Register,                   Address offset: 0x0  */
   __IO uint32_t PR;               /*!< IWDG PR Register,                   Address offset: 0x4  */
   __IO uint32_t RLR;              /*!< IWDG RLR Register,                  Address offset: 0x8  */
   __IO uint32_t SR;               /*!< IWDG SR Register,                   Address offset: 0xC  */
   /* __IO uint32_t ICNTR; */           /*!< IWDG ICNTR Register,                Address offset: 0x10  */
   /* __IO uint32_t ICR;   */           /*!< IWDG ICR Register,                  Address offset: 0x14  */
} IWDG_TypeDef;

/**
  * @brief LPTIMER
  */
typedef struct
{
  __IO uint32_t ISR;              /*!< LPTIM Interrupt and Status register,                Address offset: 0x00 */
  __IO uint32_t ICR;              /*!< LPTIM Interrupt Clear register,                     Address offset: 0x04 */
  __IO uint32_t IER;              /*!< LPTIM Interrupt Enable register,                    Address offset: 0x08 */
  __IO uint32_t CFGR;             /*!< LPTIM Configuration register,                       Address offset: 0x0C */
  __IO uint32_t CR;               /*!< LPTIM Control register,                             Address offset: 0x10 */
  __IO uint32_t CMP;              /*!< LPTIM CMP register,                                 Address offset: 0x14 */
  __IO uint32_t ARR;              /*!< LPTIM Autoreload register,                          Address offset: 0x18 */
  __IO uint32_t CNT;              /*!< LPTIM Counter register,                             Address offset: 0x1C */
  __IO uint32_t OR;               /*!< LPTIM OR register,                                  Address offset: 0x20 */
} LPTIM_TypeDef;

/**
* @brief LPUART Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< LPUART CR1 Register,                Address offset: 0x00  */
   __IO uint32_t CR2;              /*!< LPUART CR2 Register,                Address offset: 0x04  */
   __IO uint32_t CR3;              /*!< LPUART CR3 Register,                Address offset: 0x08  */
   __IO uint32_t BRR;              /*!< LPUART BRR Register,                Address offset: 0x0C  */
   __IO uint32_t LPWKUP_BRR;       /*!< LPUART LPWKUP_BRR Register,         Address offset: 0x10  */
   __IO uint32_t RESERVED1;         
   __IO uint32_t RQR;              /*!< LPUART RQR Register,                Address offset: 0x18  */
   __IO uint32_t ISR;              /*!< LPUART ISR Register,                Address offset: 0x1C  */
   __IO uint32_t ICR;              /*!< LPUART ICR Register,                Address offset: 0x20  */
   __IO uint32_t RDR;              /*!< LPUART RDR Register,                Address offset: 0x24  */
   __IO uint32_t TDR;              /*!< LPUART TDR Register,                Address offset: 0x28  */
   __IO uint32_t PRESC;            /*!< LPUART PRESC Register,              Address offset: 0x2C  */
} LPUART_TypeDef;

/**
* @brief BKP Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< TAMP CR1 Register,                  Address offset: 0x0  */
   __IO uint32_t CR2;              /*!< TAMP CR2 Register,                  Address offset: 0x4  */
   __IO uint32_t RESERVED1;         
   __IO uint32_t FLTCR;            /*!< TAMP FLTCR Register,                Address offset: 0xC  */
   __IO uint32_t RESERVED2[7];      
   __IO uint32_t IER;              /*!< TAMP IER Register,                  Address offset: 0x2C  */
   __IO uint32_t SR;               /*!< TAMP SR Register,                   Address offset: 0x30  */
   __IO uint32_t MISR;             /*!< TAMP MISR Register,                 Address offset: 0x34  */
   __IO uint32_t RESERVED3;         
   __IO uint32_t SCR;              /*!< TAMP SCR Register,                  Address offset: 0x3C  */
   __IO uint32_t RESERVED4[48];     
   __IO uint32_t BKP0R;            /*!< TAMP BKP0R Register,                Address offset: 0x100  */
   __IO uint32_t BKP1R;            /*!< TAMP BKP1R Register,                Address offset: 0x104  */
   __IO uint32_t BKP2R;            /*!< TAMP BKP2R Register,                Address offset: 0x108  */
   __IO uint32_t BKP3R;            /*!< TAMP BKP3R Register,                Address offset: 0x10C  */
   __IO uint32_t BKP4R;            /*!< TAMP BKP4R Register,                Address offset: 0x110  */
   __IO uint32_t BKP5R;            /*!< TAMP BKP5R Register,                Address offset: 0x114  */
   __IO uint32_t BKP6R;            /*!< TAMP BKP6R Register,                Address offset: 0x118  */
   __IO uint32_t BKP7R;            /*!< TAMP BKP7R Register,                Address offset: 0x11C  */
} TAMP_TypeDef;

/**
* @brief PWR Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< PWR CR1 Register,                   Address offset: 0x00  */
   __IO uint32_t CR2;              /*!< PWR CR2 Register,                   Address offset: 0x04  */
   __IO uint32_t CR3;              /*!< PWR CR3 Register,                   Address offset: 0x08  */
   __IO uint32_t CR4;              /*!< PWR CR4 Register,                   Address offset: 0x0C  */
   __IO uint32_t SR;               /*!< PWR SR Register,                    Address offset: 0x10  */
   __IO uint32_t SCR;              /*!< PWR SCR Register,                   Address offset: 0x14  */
   __IO uint32_t RESERVED1[2];
   __IO uint32_t PUCRA;            /*!< PWR PUCRA Register,                 Address offset: 0x20  */
   __IO uint32_t PDCRA;            /*!< PWR PDCRA Register,                 Address offset: 0x24  */
   __IO uint32_t PUCRB;            /*!< PWR PUCRB Register,                 Address offset: 0x28  */
   __IO uint32_t PDCRB;            /*!< PWR PDCRB Register,                 Address offset: 0x2C  */
   __IO uint32_t PUCRC;            /*!< PWR PUCRC Register,                 Address offset: 0x30  */
   __IO uint32_t PDCRC;            /*!< PWR PDCRC Register,                 Address offset: 0x34  */
   __IO uint32_t PUCRD;            /*!< PWR PUCRD Register,                 Address offset: 0x38  */
   __IO uint32_t PDCRD;            /*!< PWR PDCRD Register,                 Address offset: 0x3C  */
} PWR_TypeDef;

/**
* @brief DAC Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< DAC CR1 Register,                   Address offset: 0x00  */
   __IO uint32_t CR2;              /*!< DAC CR2 Register,                   Address offset: 0x04  */
   __IO uint32_t DHR12R;           /*!< DAC DHR12R Register,                Address offset: 0x08  */
   __IO uint32_t DHR12L;           /*!< DAC DHR12L Register,                Address offset: 0x0C  */
   __IO uint32_t DHR8R;            /*!< DAC DHR8R Register,                 Address offset: 0x10  */
   __IO uint32_t RESERVED1[6];      
   __IO uint32_t DOR;              /*!< DAC DOR Register,                   Address offset: 0x2C  */
   __IO uint32_t RESERVED2;         
   __IO uint32_t SR;               /*!< DAC SR Register,                    Address offset: 0x34  */
   __IO uint32_t CALR;             /*!< DAC CALR Register,                  Address offset: 0x38  */
} DAC_TypeDef;

/**
* @brief RCC Registers
*/
typedef struct
{
   __IO uint32_t CR;               /*!< RCC CR Register,                    Address offset: 0x00  */
   __IO uint32_t ICSCR;            /*!< RCC ICSCR Register,                 Address offset: 0x04  */
   __IO uint32_t CFGR;             /*!< RCC CFGR Register,                  Address offset: 0x08  */
   __IO uint32_t PLLCFGR;          /*!< RCC PLLCFGR Register,               Address offset: 0x0C  */
   __IO uint32_t ECSCR;            /*!< RCC ECSCR Register,                 Address offset: 0x10  */
   __IO uint32_t RESERVED1;         
   __IO uint32_t CIER;             /*!< RCC CIER Register,                  Address offset: 0x18  */
   __IO uint32_t CIFR;             /*!< RCC CIFR Register,                  Address offset: 0x1C  */
   __IO uint32_t CICR;             /*!< RCC CICR Register,                  Address offset: 0x20  */
   __IO uint32_t IOPRSTR;          /*!< RCC IOPRSTR Register,               Address offset: 0x24  */
   __IO uint32_t AHBRSTR;          /*!< RCC AHBRSTR Register,               Address offset: 0x28  */
   __IO uint32_t APBRSTR1;         /*!< RCC APBRSTR1 Register,              Address offset: 0x2C  */
   __IO uint32_t APBRSTR2;         /*!< RCC APBRSTR2 Register,              Address offset: 0x30  */
   __IO uint32_t IOPENR;           /*!< RCC IOPENR Register,                Address offset: 0x34  */
   __IO uint32_t AHBENR;           /*!< RCC AHBENR Register,                Address offset: 0x38  */
   __IO uint32_t APBENR1;          /*!< RCC APBENR1 Register,               Address offset: 0x3C  */
   __IO uint32_t APBENR2;          /*!< RCC APBENR2 Register,               Address offset: 0x40  */
   __IO uint32_t RESERVED2[4];      
   __IO uint32_t CCIPR;            /*!< RCC CCIPR Register,                 Address offset: 0x54  */
   __IO uint32_t RESERVED3;         
   __IO uint32_t BDCR;             /*!< RCC BDCR Register,                  Address offset: 0x5C  */
   __IO uint32_t CSR;              /*!< RCC CSR Register,                   Address offset: 0x60  */
} RCC_TypeDef;


/**
* @brief RTC Registers
*/
typedef struct
{
   __IO uint32_t TR;               /*!< RTC TR Register,                    Address offset: 0x00  */
   __IO uint32_t DR;               /*!< RTC DR Register,                    Address offset: 0x04  */
   __IO uint32_t SSR;              /*!< RTC SSR Register,                   Address offset: 0x08  */
   __IO uint32_t ICSR;             /*!< RTC ICSR Register,                  Address offset: 0x0C  */
   __IO uint32_t PRER;             /*!< RTC PRER Register,                  Address offset: 0x10  */
   __IO uint32_t WUTR;             /*!< RTC WUTR Register,                  Address offset: 0x14  */
   __IO uint32_t CR;               /*!< RTC CR Register,                    Address offset: 0x18  */
   __IO uint32_t RESERVED1[2];      
   __IO uint32_t WPR;              /*!< RTC WPR Register,                   Address offset: 0x24  */
   __IO uint32_t CALR;             /*!< RTC CALR Register,                  Address offset: 0x28  */
   __IO uint32_t SHIFTR;           /*!< RTC SHIFTR Register,                Address offset: 0x2C  */
   __IO uint32_t TSTR;             /*!< RTC TSTR Register,                  Address offset: 0x30  */
   __IO uint32_t TSDR;             /*!< RTC TSDR Register,                  Address offset: 0x34  */
   __IO uint32_t TSSSR;            /*!< RTC TSSSR Register,                 Address offset: 0x38  */
   __IO uint32_t RESERVED2;         
   __IO uint32_t ALRMAR;           /*!< RTC ALRMAR Register,                Address offset: 0x40  */
   __IO uint32_t ALRMASSR;         /*!< RTC ALRMASSR Register,              Address offset: 0x44  */
   __IO uint32_t ALRMBR;           /*!< RTC ALRMBR Register,                Address offset: 0x48  */
   __IO uint32_t ALRMBSSR;         /*!< RTC ALRMBSSR Register,              Address offset: 0x4C  */
   __IO uint32_t SR;               /*!< RTC SR Register,                    Address offset: 0x50  */
   __IO uint32_t MISR;             /*!< RTC MISR Register,                  Address offset: 0x54  */
   __IO uint32_t RESERVED3;         
   __IO uint32_t SCR;              /*!< RTC SCR Register,                   Address offset: 0x5C  */
} RTC_TypeDef;


/**
* @brief SPI Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< SPI CR1 Register,                   Address offset: 0x00  */
   __IO uint32_t CR2;              /*!< SPI CR2 Register,                   Address offset: 0x04  */
   __IO uint32_t SR;               /*!< SPI SR Register,                    Address offset: 0x08  */
   __IO uint32_t DR;               /*!< SPI DR Register,                    Address offset: 0x0C  */
   __IO uint32_t CRCPR;            /*!< SPI CRCPR Register,                 Address offset: 0x10  */
   __IO uint32_t RXCRC;            /*!< SPI RXCRC Register,                 Address offset: 0x14  */
   __IO uint32_t TXCRC;            /*!< SPI TXCRC Register,                 Address offset: 0x18  */
   __IO uint32_t I2SCFGR;          /*!< SPI I2S_CFGR Register,              Address offset: 0x1C  */
   __IO uint32_t I2SPR;            /*!< SPI I2SPR Register,                 Address offset: 0x20  */
} SPI_TypeDef;


/**
* @brief SYSCFG Registers
*/
typedef struct
{
   __IO uint32_t CFGR1;            /*!< SYSCFG CFGR1 Register,              Address offset: 0x00  */
   __IO uint32_t CFGR2;            /*!< SYSCFG CFGR2 Register,              Address offset: 0x04  */
   __IO uint32_t CFGR3;            /*!< SYSCFG CFGR3 Register,              Address offset: 0x08  */
   __IO uint32_t CFGR4;            /*!< SYSCFG CFGR4 Register,              Address offset: 0x0C  */
   __IO uint32_t RESERVED1[4];      
   __IO uint32_t PA_ENS;           /*!< PA ENS_REG Register,                Address offset: 0x20  */
   __IO uint32_t PB_ENS;           /*!< PB ENS_REG Register,                Address offset: 0x24  */
   __IO uint32_t PC_ENS;           /*!< PC ENS_REG Register,                Address offset: 0x28  */
   __IO uint32_t PD_ENS;           /*!< PD ENS_REG Register,                Address offset: 0x2C  */
   __IO uint32_t RESERVED2[2];      
   __IO uint32_t IOCFG;            /*!< SYSCFG IOCFG Register,              Address offset: 0x38  */
   __IO uint32_t LEDCFG;           /*!< SYSCFG LEDCFG Register,             Address offset: 0x3C  */
   __IO uint32_t PA_ANA2EN;        /*!< PA ANA2EN_REG Register,             Address offset: 0x40  */
   __IO uint32_t PB_ANA2EN;        /*!< PB ANA2EN_REG Register,             Address offset: 0x44  */
   __IO uint32_t PC_ANA2EN;        /*!< PC ANA2EN_REG Register,             Address offset: 0x48  */
   __IO uint32_t PD_ANA2EN;        /*!< PD ANA2EN_REG Register,             Address offset: 0x4C  */
   __IO uint32_t RESERVED3[8];      
   __IO uint32_t SCSR;             /*!< SYSCFG SCSR Register,               Address offset: 0x70  */
   __IO uint32_t SWPR;             /*!< SYSCFG SWPR Register,               Address offset: 0x74  */
   __IO uint32_t RESERVED4[2];      
   __IO uint32_t TEST_DUMMY;       /*!< TEST DUMMY Register,                Address offset: 0x80  */
} SYSCFG_TypeDef;


/**
* @brief TIM Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< TIM CR1 Register,                  Address offset: 0x0000  */
   __IO uint32_t CR2;              /*!< TIM CR2 Register,                  Address offset: 0x0004  */
   __IO uint32_t SMCR;             /*!< TIM SMCR Register,                 Address offset: 0x0008  */
   __IO uint32_t DIER;             /*!< TIM DIER Register,                 Address offset: 0x000C  */
   __IO uint32_t SR;               /*!< TIM SR Register,                   Address offset: 0x0010  */
   __IO uint32_t EGR;              /*!< TIM EGR Register,                  Address offset: 0x0014  */
   __IO uint32_t CCMR1;            /*!< TIM CCMR1 Register,                Address offset: 0x0018  */
   __IO uint32_t CCMR2;            /*!< TIM CCMR2 Register,                Address offset: 0x001C  */
   __IO uint32_t CCER;             /*!< TIM CCER Register,                 Address offset: 0x0020  */
   __IO uint32_t CNT;              /*!< TIM CNT Register,                  Address offset: 0x0024  */
   __IO uint32_t PSC;              /*!< TIM PSC Register,                  Address offset: 0x0028  */
   __IO uint32_t ARR;              /*!< TIM ARR Register,                  Address offset: 0x002C  */
   __IO uint32_t RCR;              /*!< TIM RCR Register,                  Address offset: 0x0030  */
   __IO uint32_t CCR1;             /*!< TIM CCR1 Register,                 Address offset: 0x0034  */
   __IO uint32_t CCR2;             /*!< TIM CCR2 Register,                 Address offset: 0x0038  */
   __IO uint32_t CCR3;             /*!< TIM CCR3 Register,                 Address offset: 0x003C  */
   __IO uint32_t CCR4;             /*!< TIM CCR4 Register,                 Address offset: 0x0040  */
   __IO uint32_t BDTR;             /*!< TIM BDTR Register,                 Address offset: 0x0044  */
   __IO uint32_t RESERVED1[5];      
   __IO uint32_t TISEL;            /*!< TIM TISEL Register,                Address offset: 0x005C  */
   __IO uint32_t AF1;              /*!< TIM AF1 Register,                  Address offset: 0x0060  */
   __IO uint32_t AF2;              /*!< TIM AF2 Register,                  Address offset: 0x0064  */
   __IO uint32_t RESERVED2[221];    
   __IO uint32_t DCR;              /*!< TIM DCR Register,                  Address offset: 0x03DC  */
   __IO uint32_t DMAR;             /*!< TIM DMAR Register,                 Address offset: 0x03E0  */
} TIM_TypeDef;


/**
* @brief PWM Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< PWM CR1 Register,                   Address offset: 0x0000  */
   __IO uint32_t CR2;              /*!< PWM CR2 Register,                   Address offset: 0x0004  */
   __IO uint32_t SMCR;             /*!< PWM SMCR Register,                  Address offset: 0x0008  */
   __IO uint32_t DIER;             /*!< PWM DIER Register,                  Address offset: 0x000C  */
   __IO uint32_t SR;               /*!< PWM SR Register,                    Address offset: 0x0010  */
   __IO uint32_t EGR;              /*!< PWM EGR Register,                   Address offset: 0x0014  */
   __IO uint32_t CMR;              /*!< PWM CMR Register,                   Address offset: 0x0018  */
   __IO uint32_t RESERVED1;         
   __IO uint32_t CER;              /*!< PWM CER Register,                   Address offset: 0x0020  */
   __IO uint32_t CNT;              /*!< PWM CNT Register,                   Address offset: 0x0024  */
   __IO uint32_t PSC;              /*!< PWM PSC Register,                   Address offset: 0x0028  */
   __IO uint32_t ARR;              /*!< PWM ARR Register,                   Address offset: 0x002C  */
   __IO uint32_t RESERVED2;         
   __IO uint32_t CCR1;             /*!< PWM CCR1 Register,                  Address offset: 0x0034  */
   __IO uint32_t CCR2;             /*!< PWM CCR2 Register,                  Address offset: 0x0038  */
   __IO uint32_t CCR3;             /*!< PWM CCR3 Register,                  Address offset: 0x003C  */
   __IO uint32_t CCR4;             /*!< PWM CCR4 Register,                  Address offset: 0x0040  */
   __IO uint32_t BDTR;             /*!< PWM BDTR Register,                  Address offset: 0x0044  */
   __IO uint32_t DCR;              /*!< PWM DCR Register,                   Address offset: 0x48  */
   __IO uint32_t DMAR;             /*!< PWM DMAR Register,                  Address offset: 0x4C  */
} PWM_TypeDef;

/**
* @brief USART Registers
*/
typedef struct
{
   __IO uint32_t SR;               /*!< USART SR Register,                  Address offset: 0x00  */
   __IO uint32_t DR;               /*!< USART DR Register,                  Address offset: 0x04  */
   __IO uint32_t BRR;              /*!< USART BRR Register,                 Address offset: 0x08  */
   __IO uint32_t CR1;              /*!< USART CR1 Register,                 Address offset: 0x0C  */
   __IO uint32_t CR2;              /*!< USART CR2 Register,                 Address offset: 0x10  */
   __IO uint32_t CR3;              /*!< USART CR3 Register,                 Address offset: 0x14  */
   __IO uint32_t GTPR;             /*!< USART GTPR Register,                Address offset: 0x18  */
   __IO uint32_t RTOR;             /*!< USART RTOR Register,                Address offset: 0x1C  */
} USART_TypeDef;

/**
* @brief UART Registers
*/
typedef struct
{
   __IO uint32_t DR;               /*!< UART DR Register,                   Address offset: 0x00  */
   __IO uint32_t BRR;              /*!< UART BRR Register,                  Address offset: 0x04  */
   __IO uint32_t RESERVED1[2];      
   __IO uint32_t SR;               /*!< UART SR Register,                   Address offset: 0x10  */
   __IO uint32_t CR1;              /*!< UART CR1 Register,                  Address offset: 0x14  */
   __IO uint32_t CR2;              /*!< UART CR2 Register,                  Address offset: 0x18  */
   __IO uint32_t CR3;              /*!< UART CR3 Register,                  Address offset: 0x1C  */
   __IO uint32_t RAR;              /*!< UART RAR Register,                  Address offset: 0x20  */
   __IO uint32_t TAR;              /*!< UART TAR Register,                  Address offset: 0x24  */
   __IO uint32_t BRRF;             /*!< UART BRRF Register,                 Address offset: 0x28  */
} UART_TypeDef;

/**
* @brief WWDG Registers
*/
typedef struct
{
   __IO uint32_t CR;               /*!< WWDR CR Register,                   Address offset: 0x0  */
   __IO uint32_t CFR;              /*!< WWDG CFR Register,                  Address offset: 0x4  */
   __IO uint32_t SR;               /*!< WWDG SR Register,                   Address offset: 0x8  */
} WWDG_TypeDef;

/**
* @brief LCD Registers
*/
typedef struct
{
   __IO uint32_t CR;               /*!< LCD CR Register,                    Address offset: 0x00  */
   __IO uint32_t CSR;              /*!< LCD CSR Register,                   Address offset: 0x04  */
   __IO uint32_t INTCLR;           /*!< LCD INTCLR Register,                Address offset: 0x08  */
   __IO uint32_t POEN0;            /*!< LCD POEN0 Register,                 Address offset: 0x0C  */
   __IO uint32_t POEN1;            /*!< LCD POEN1 Register,                 Address offset: 0x10  */
   __IO uint32_t RAM[16];          /*!< LCD RAM Register,                   Address offset: 0x14 ~ 0x50 */
} LCD_TypeDef;


/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE            (0x08000000UL)  /*!< FLASH base address */
#define FLASH_END             (0x0803FFFFUL)  /*!< FLASH end address */
#define FLASH_SIZE            (FLASH_END - FLASH_BASE + 1)
#define FLASH_PAGE_SIZE       0x00000100U     /*!< FLASH Page Size, 256 Bytes */
#define FLASH_PAGE_NB         (FLASH_SIZE / FLASH_PAGE_SIZE)
#define FLASH_SECTOR_SIZE     0x00002000U     /*!< FLASH Sector Size, 8k Bytes */
#define FLASH_SECTOR_NB       (FLASH_SIZE / FLASH_SECTOR_SIZE)
#define SRAM1_BASE            (0x20000000UL)  /*!< SRAM1(8 KB) base address */
#define SRAM2_BASE            (0x20002000UL)  /*!< SRAM2(24 KB) base address */
#define PERIPH_BASE           (0x40000000UL)  /*!< Peripheral base address */
#define IOPORT_BASE           (0x50000000UL)  /*!< IOPORT base address */
#define OB_BASE               (0x1FFF1D00UL)  /*!< Flash Option Bytes base address */
#define UID_BASE              (0x1FFF1C00UL)  /*!< Unique device ID register base address */
#define OTP_BASE              (0x1FFF1A00UL)

/* Legacy defines */
#define SRAM_BASE             SRAM1_BASE

/*!< Peripheral memory map */
#define APBPERIPH_BASE        (PERIPH_BASE)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)

/*!< APB peripherals */
#define TIM2_BASE             (APBPERIPH_BASE + 0x00000000UL)
#define TIM3_BASE             (APBPERIPH_BASE + 0x00000400UL)
#define TIM6_BASE             (APBPERIPH_BASE + 0x00001000UL)
#define TIM7_BASE             (APBPERIPH_BASE + 0x00001400UL)
#define LCD_BASE              (APBPERIPH_BASE + 0x00002400UL)
#define RTC_BASE              (APBPERIPH_BASE + 0x00002800UL)
#define WWDG_BASE             (APBPERIPH_BASE + 0x00002C00UL)
#define IWDG_BASE             (APBPERIPH_BASE + 0x00003000UL)
#define SPI2_BASE             (APBPERIPH_BASE + 0x00003800UL)
#define USART2_BASE           (APBPERIPH_BASE + 0x00004400UL)
#define UART1_BASE            (APBPERIPH_BASE + 0x00004800UL)
#define UART2_BASE            (APBPERIPH_BASE + 0x00004C00UL)
#define I2C1_BASE             (APBPERIPH_BASE + 0x00005400UL)
#define I2C2_BASE             (APBPERIPH_BASE + 0x00005800UL)
#define PWR_BASE              (APBPERIPH_BASE + 0x00007000UL)
#define DAC_BASE              (APBPERIPH_BASE + 0x00007400UL)
#define LPTIM1_BASE           (APBPERIPH_BASE + 0x00007C00UL)
#define LPUART1_BASE          (APBPERIPH_BASE + 0x00008000UL)
#define LPTIM2_BASE           (APBPERIPH_BASE + 0x00009400UL)
#define LPUART2_BASE          (APBPERIPH_BASE + 0x00009800UL)
#define TAMP_BASE             (APBPERIPH_BASE + 0x0000B000UL)
#define SYSCFG_BASE           (APBPERIPH_BASE + 0x00010000UL)
#define COMP1_BASE            (APBPERIPH_BASE + 0x00010200UL)
#define COMP2_BASE            (APBPERIPH_BASE + 0x00010210UL)
#define OPA_BASE              (APBPERIPH_BASE + 0x00010300UL)
#define EXTI_BASE             (APBPERIPH_BASE + 0x00010400UL)
#define VREFBUF_BASE          (APBPERIPH_BASE + 0x00010800UL)
#define ADC_BASE              (APBPERIPH_BASE + 0x00012400UL)
#define ADC_COMMON_BASE       (ADC_BASE + 0x00000308UL)
#define TK_BASE               (APBPERIPH_BASE + 0x00012800UL)
#define TIM1_BASE             (APBPERIPH_BASE + 0x00012C00UL)
#define SPI1_BASE             (APBPERIPH_BASE + 0x00013000UL)
#define USART1_BASE           (APBPERIPH_BASE + 0x00013800UL)
#define TIM15_BASE            (APBPERIPH_BASE + 0x00014000UL)
#define TIM16_BASE            (APBPERIPH_BASE + 0x00014400UL)
#define TIM17_BASE            (APBPERIPH_BASE + 0x00014800UL)
#define PWM_BASE              (APBPERIPH_BASE + 0x00014C00UL)
#define DBGMCU_BASE           (APBPERIPH_BASE + 0x00015800UL)

/*!< AHB peripherals */
#define DMA_BASE              (AHBPERIPH_BASE + 0x00000000UL)
#define DMA_Channel1_BASE     (DMA_BASE + 0x00000008UL)
#define DMA_Channel2_BASE     (DMA_BASE + 0x0000001CUL)
#define DMA_Channel3_BASE     (DMA_BASE + 0x00000030UL)
#define DMA_Channel4_BASE     (DMA_BASE + 0x00000044UL)
#define DMA_Channel5_BASE     (DMA_BASE + 0x00000058UL)
#define DMA_Channel6_BASE     (DMA_BASE + 0x0000006CUL)
#define DMA_Channel7_BASE     (DMA_BASE + 0x00000080UL)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000UL) /*!< FLASH registers base address */
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000UL)

/*!< IOPORT */
#define GPIOA_BASE            (IOPORT_BASE + 0x00000000UL)
#define GPIOB_BASE            (IOPORT_BASE + 0x00000400UL)
#define GPIOC_BASE            (IOPORT_BASE + 0x00000800UL)
#define GPIOD_BASE            (IOPORT_BASE + 0x00000C00UL)

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define LCD                 ((LCD_TypeDef *) LCD_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define UART1               ((UART_TypeDef *) UART1_BASE)
#define UART2               ((UART_TypeDef *) UART2_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE)
#define LPTIM1              ((LPTIM_TypeDef *) LPTIM1_BASE)
#define LPUART1             ((LPUART_TypeDef *) LPUART1_BASE)
#define LPTIM2              ((LPTIM_TypeDef *) LPTIM2_BASE)
#define LPUART2             ((LPUART_TypeDef *) LPUART2_BASE)
#define TAMP                ((TAMP_TypeDef *) TAMP_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define COMP1               ((COMP_TypeDef *) COMP1_BASE)
#define COMP2               ((COMP_TypeDef *) COMP2_BASE)
#define COMP12_COMMON       ((COMP_Common_TypeDef *) COMP1_BASE)
#define OPA                 ((OPA_TypeDef *) OPA_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define VREFBUF             ((VREFBUF_TypeDef *) VREFBUF_BASE)
#define ADC1                ((ADC_TypeDef *) ADC_BASE)
#define ADC_COMMON          ((ADC_Common_TypeDef *) ADC_COMMON_BASE)
#define TK                  ((TK_TypeDef *) TK_BASE)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define TIM15               ((TIM_TypeDef *) TIM15_BASE)
#define TIM16               ((TIM_TypeDef *) TIM16_BASE)
#define TIM17               ((TIM_TypeDef *) TIM17_BASE)
#define PWM                 ((PWM_TypeDef *) PWM_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define DMA                 ((DMA_TypeDef *) DMA_BASE)
#define DMA_Channel1        ((DMA_Channel_TypeDef *) DMA_Channel1_BASE)
#define DMA_Channel2        ((DMA_Channel_TypeDef *) DMA_Channel2_BASE)
#define DMA_Channel3        ((DMA_Channel_TypeDef *) DMA_Channel3_BASE)
#define DMA_Channel4        ((DMA_Channel_TypeDef *) DMA_Channel4_BASE)
#define DMA_Channel5        ((DMA_Channel_TypeDef *) DMA_Channel5_BASE)
#define DMA_Channel6        ((DMA_Channel_TypeDef *) DMA_Channel6_BASE)
#define DMA_Channel7        ((DMA_Channel_TypeDef *) DMA_Channel7_BASE)
#define DMA1                 DMA
#define DMA1_Channel1        DMA_Channel1
#define DMA1_Channel2        DMA_Channel2
#define DMA1_Channel3        DMA_Channel3
#define DMA1_Channel4        DMA_Channel4
#define DMA1_Channel5        DMA_Channel5
#define DMA1_Channel6        DMA_Channel6
#define DMA1_Channel7        DMA_Channel7
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
* @{
*/

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/********************************************************************************************************************/
/********************************* ADC ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for ADC_ISR register **********************************************/
#define ADC_ISR_ADRDY_Pos                         (0U)
#define ADC_ISR_ADRDY_Msk                         (0x1UL<<ADC_ISR_ADRDY_Pos)                        /*!< 0x00000001 */
#define ADC_ISR_ADRDY                             ADC_ISR_ADRDY_Msk                                 
#define ADC_ISR_EOSMP_Pos                         (1U)
#define ADC_ISR_EOSMP_Msk                         (0x1UL<<ADC_ISR_EOSMP_Pos)                        /*!< 0x00000002 */
#define ADC_ISR_EOSMP                             ADC_ISR_EOSMP_Msk                                 
#define ADC_ISR_EOC_Pos                           (2U)
#define ADC_ISR_EOC_Msk                           (0x1UL<<ADC_ISR_EOC_Pos)                          /*!< 0x00000004 */
#define ADC_ISR_EOC                               ADC_ISR_EOC_Msk                                   
#define ADC_ISR_EOS_Pos                           (3U)
#define ADC_ISR_EOS_Msk                           (0x1UL<<ADC_ISR_EOS_Pos)                          /*!< 0x00000008 */
#define ADC_ISR_EOS                               ADC_ISR_EOS_Msk                                   
#define ADC_ISR_OVR_Pos                           (4U)
#define ADC_ISR_OVR_Msk                           (0x1UL<<ADC_ISR_OVR_Pos)                          /*!< 0x00000010 */
#define ADC_ISR_OVR                               ADC_ISR_OVR_Msk                                   
#define ADC_ISR_JEOC_Pos                          (5U)
#define ADC_ISR_JEOC_Msk                          (0x1UL<<ADC_ISR_JEOC_Pos)                         /*!< 0x00000020 */
#define ADC_ISR_JEOC                              ADC_ISR_JEOC_Msk                                  
#define ADC_ISR_JEOS_Pos                          (6U)
#define ADC_ISR_JEOS_Msk                          (0x1UL<<ADC_ISR_JEOS_Pos)                         /*!< 0x00000040 */
#define ADC_ISR_JEOS                              ADC_ISR_JEOS_Msk                                  
#define ADC_ISR_AWD_Pos                           (7U)
#define ADC_ISR_AWD_Msk                           (0x1UL<<ADC_ISR_AWD_Pos)                         /*!< 0x00000080 */
#define ADC_ISR_AWD                               ADC_ISR_AWD_Msk   
#define ADC_ISR_EOCAL_Pos                         (11U)
#define ADC_ISR_EOCAL_Msk                         (0x1UL<<ADC_ISR_EOCAL_Pos)                        /*!< 0x00000800 */
#define ADC_ISR_EOCAL                             ADC_ISR_EOCAL_Msk                                  

/********************************* Bit definition for ADC_IER register **********************************************/
#define ADC_IER_ADRDYIE_Pos                       (0U)
#define ADC_IER_ADRDYIE_Msk                       (0x1UL<<ADC_IER_ADRDYIE_Pos)                      /*!< 0x00000001 */
#define ADC_IER_ADRDYIE                           ADC_IER_ADRDYIE_Msk                               
#define ADC_IER_EOSMPIE_Pos                       (1U)
#define ADC_IER_EOSMPIE_Msk                       (0x1UL<<ADC_IER_EOSMPIE_Pos)                      /*!< 0x00000002 */
#define ADC_IER_EOSMPIE                           ADC_IER_EOSMPIE_Msk                               
#define ADC_IER_EOCIE_Pos                         (2U)
#define ADC_IER_EOCIE_Msk                         (0x1UL<<ADC_IER_EOCIE_Pos)                        /*!< 0x00000004 */
#define ADC_IER_EOCIE                             ADC_IER_EOCIE_Msk                                 
#define ADC_IER_EOSIE_Pos                         (3U)
#define ADC_IER_EOSIE_Msk                         (0x1UL<<ADC_IER_EOSIE_Pos)                        /*!< 0x00000008 */
#define ADC_IER_EOSIE                             ADC_IER_EOSIE_Msk                                 
#define ADC_IER_OVRIE_Pos                         (4U)
#define ADC_IER_OVRIE_Msk                         (0x1UL<<ADC_IER_OVRIE_Pos)                        /*!< 0x00000010 */
#define ADC_IER_OVRIE                             ADC_IER_OVRIE_Msk                                 
#define ADC_IER_JEOCIE_Pos                        (5U)
#define ADC_IER_JEOCIE_Msk                        (0x1UL<<ADC_IER_JEOCIE_Pos)                       /*!< 0x00000020 */
#define ADC_IER_JEOCIE                            ADC_IER_JEOCIE_Msk                                
#define ADC_IER_JEOSIE_Pos                        (6U)
#define ADC_IER_JEOSIE_Msk                        (0x1UL<<ADC_IER_JEOSIE_Pos)                       /*!< 0x00000040 */
#define ADC_IER_JEOSIE                            ADC_IER_JEOSIE_Msk                                
#define ADC_IER_AWDIE_Pos                         (7U)
#define ADC_IER_AWDIE_Msk                         (0x1UL<<ADC_IER_AWDIE_Pos)                       /*!< 0x00000080 */
#define ADC_IER_AWDIE                             ADC_IER_AWDIE_Msk    
#define ADC_IER_EOCALIE_Pos                       (11U)
#define ADC_IER_EOCALIE_Msk                       (0x1UL<<ADC_IER_EOCALIE_Pos)                      /*!< 0x00000800 */
#define ADC_IER_EOCALIE                           ADC_IER_EOCALIE_Msk                                

/********************************* Bit definition for ADC_CR register ***********************************************/
#define ADC_CR_ADEN_Pos                           (0U)
#define ADC_CR_ADEN_Msk                           (0x1UL<<ADC_CR_ADEN_Pos)                          /*!< 0x00000001 */
#define ADC_CR_ADEN                               ADC_CR_ADEN_Msk                                   
#define ADC_CR_ADDIS_Pos                          (1U)
#define ADC_CR_ADDIS_Msk                          (0x1UL<<ADC_CR_ADDIS_Pos)                         /*!< 0x00000002 */
#define ADC_CR_ADDIS                              ADC_CR_ADDIS_Msk                                  
#define ADC_CR_ADSTART_Pos                        (2U)
#define ADC_CR_ADSTART_Msk                        (0x1UL<<ADC_CR_ADSTART_Pos)                       /*!< 0x00000004 */
#define ADC_CR_ADSTART                            ADC_CR_ADSTART_Msk                                
#define ADC_CR_JADSTART_Pos                       (3U)
#define ADC_CR_JADSTART_Msk                       (0x1UL<<ADC_CR_JADSTART_Pos)                      /*!< 0x00000008 */
#define ADC_CR_JADSTART                           ADC_CR_JADSTART_Msk                               
#define ADC_CR_ADSTP_Pos                          (4U)
#define ADC_CR_ADSTP_Msk                          (0x1UL<<ADC_CR_ADSTP_Pos)                         /*!< 0x00000010 */
#define ADC_CR_ADSTP                              ADC_CR_ADSTP_Msk                                  
#define ADC_CR_JADSTP_Pos                         (5U)
#define ADC_CR_JADSTP_Msk                         (0x1UL<<ADC_CR_JADSTP_Pos)                        /*!< 0x00000020 */
#define ADC_CR_JADSTP                             ADC_CR_JADSTP_Msk   
#define ADC_CR_RSTCAL_Pos                         (27U)
#define ADC_CR_RSTCAL_Msk                         (0x1UL<<ADC_CR_RSTCAL_Pos)                        /*!< 0x00000020 */
#define ADC_CR_RSTCAL                             ADC_CR_RSTCAL_Msk                                 
#define ADC_CR_ADCAL_Pos                          (31U)
#define ADC_CR_ADCAL_Msk                          (0x1UL<<ADC_CR_ADCAL_Pos)                         /*!< 0x80000000 */
#define ADC_CR_ADCAL                              ADC_CR_ADCAL_Msk                                  

/********************************* Bit definition for ADC_CFGR register *********************************************/
#define ADC_CFGR_DMAEN_Pos                        (0U)
#define ADC_CFGR_DMAEN_Msk                        (0x1UL<<ADC_CFGR_DMAEN_Pos)                       /*!< 0x00000001 */
#define ADC_CFGR_DMAEN                            ADC_CFGR_DMAEN_Msk                                
#define ADC_CFGR_DMACFG_Pos                       (1U)
#define ADC_CFGR_DMACFG_Msk                       (0x1UL<<ADC_CFGR_DMACFG_Pos)                      /*!< 0x00000002 */
#define ADC_CFGR_DMACFG                           ADC_CFGR_DMACFG_Msk                               
#define ADC_CFGR_RES_Pos                          (3U)
#define ADC_CFGR_RES_Msk                          (0x3UL<<ADC_CFGR_RES_Pos)                         /*!< 0x00000018 */
#define ADC_CFGR_RES                              ADC_CFGR_RES_Msk
#define ADC_CFGR_RES_0                            (0x1UL<<ADC_CFGR_RES_Pos)                         /*!< 0x00000008 */
#define ADC_CFGR_RES_1                            (0x2UL<<ADC_CFGR_RES_Pos)                         /*!< 0x00000010 */
#define ADC_CFGR_EXTSEL_Pos                       (5U)
#define ADC_CFGR_EXTSEL_Msk                       (0xFUL<<ADC_CFGR_EXTSEL_Pos)                      /*!< 0x000001E0 */
#define ADC_CFGR_EXTSEL                           ADC_CFGR_EXTSEL_Msk
#define ADC_CFGR_EXTSEL_0                         (0x1UL<<ADC_CFGR_EXTSEL_Pos)                      /*!< 0x00000020 */
#define ADC_CFGR_EXTSEL_1                         (0x2UL<<ADC_CFGR_EXTSEL_Pos)                      /*!< 0x00000040 */
#define ADC_CFGR_EXTSEL_2                         (0x4UL<<ADC_CFGR_EXTSEL_Pos)                      /*!< 0x00000080 */
#define ADC_CFGR_EXTSEL_3                         (0x8UL<<ADC_CFGR_EXTSEL_Pos)                      /*!< 0x00000100 */
#define ADC_CFGR_EXTEN_Pos                        (10U)
#define ADC_CFGR_EXTEN_Msk                        (0x3UL<<ADC_CFGR_EXTEN_Pos)                       /*!< 0x00000C00 */
#define ADC_CFGR_EXTEN                            ADC_CFGR_EXTEN_Msk
#define ADC_CFGR_EXTEN_0                          (0x1UL<<ADC_CFGR_EXTEN_Pos)                       /*!< 0x00000400 */
#define ADC_CFGR_EXTEN_1                          (0x2UL<<ADC_CFGR_EXTEN_Pos)                       /*!< 0x00000800 */
#define ADC_CFGR_OVRMOD_Pos                       (12U)
#define ADC_CFGR_OVRMOD_Msk                       (0x1UL<<ADC_CFGR_OVRMOD_Pos)                      /*!< 0x00001000 */
#define ADC_CFGR_OVRMOD                           ADC_CFGR_OVRMOD_Msk                               
#define ADC_CFGR_CONT_Pos                         (13U)
#define ADC_CFGR_CONT_Msk                         (0x1UL<<ADC_CFGR_CONT_Pos)                        /*!< 0x00002000 */
#define ADC_CFGR_CONT                             ADC_CFGR_CONT_Msk                                 
#define ADC_CFGR_AUTDLY_Pos                       (14U)
#define ADC_CFGR_AUTDLY_Msk                       (0x1UL<<ADC_CFGR_AUTDLY_Pos)                      /*!< 0x00004000 */
#define ADC_CFGR_AUTDLY                           ADC_CFGR_AUTDLY_Msk                               
#define ADC_CFGR_ALIGN_Pos                        (15U)
#define ADC_CFGR_ALIGN_Msk                        (0x1UL<<ADC_CFGR_ALIGN_Pos)                       /*!< 0x00008000 */
#define ADC_CFGR_ALIGN                            ADC_CFGR_ALIGN_Msk                                
#define ADC_CFGR_DISCEN_Pos                       (16U)
#define ADC_CFGR_DISCEN_Msk                       (0x1UL<<ADC_CFGR_DISCEN_Pos)                      /*!< 0x00010000 */
#define ADC_CFGR_DISCEN                           ADC_CFGR_DISCEN_Msk                               
#define ADC_CFGR_DISCNUM_Pos                      (17U)
#define ADC_CFGR_DISCNUM_Msk                      (0x7UL<<ADC_CFGR_DISCNUM_Pos)                     /*!< 0x000E0000 */
#define ADC_CFGR_DISCNUM                          ADC_CFGR_DISCNUM_Msk
#define ADC_CFGR_DISCNUM_0                        (0x1UL<<ADC_CFGR_DISCNUM_Pos)                     /*!< 0x00020000 */
#define ADC_CFGR_DISCNUM_1                        (0x2UL<<ADC_CFGR_DISCNUM_Pos)                     /*!< 0x00040000 */
#define ADC_CFGR_DISCNUM_2                        (0x4UL<<ADC_CFGR_DISCNUM_Pos)                     /*!< 0x00080000 */
#define ADC_CFGR_JDISCEN_Pos                      (20U)
#define ADC_CFGR_JDISCEN_Msk                      (0x1UL<<ADC_CFGR_JDISCEN_Pos)                     /*!< 0x00100000 */
#define ADC_CFGR_JDISCEN                          ADC_CFGR_JDISCEN_Msk                              
#define ADC_CFGR_AWDSGL_Pos                       (22U)
#define ADC_CFGR_AWDSGL_Msk                       (0x1UL<<ADC_CFGR_AWDSGL_Pos)                     /*!< 0x00400000 */
#define ADC_CFGR_AWDSGL                           ADC_CFGR_AWDSGL_Msk                              
#define ADC_CFGR_AWDEN_Pos                        (23U)
#define ADC_CFGR_AWDEN_Msk                        (0x1UL<<ADC_CFGR_AWDEN_Pos)                      /*!< 0x00800000 */
#define ADC_CFGR_AWDEN                            ADC_CFGR_AWDEN_Msk                               
#define ADC_CFGR_JAWDEN_Pos                       (24U)
#define ADC_CFGR_JAWDEN_Msk                       (0x1UL<<ADC_CFGR_JAWDEN_Pos)                     /*!< 0x01000000 */
#define ADC_CFGR_JAWDEN                           ADC_CFGR_JAWDEN_Msk                              
#define ADC_CFGR_JAUTO_Pos                        (25U)
#define ADC_CFGR_JAUTO_Msk                        (0x1UL<<ADC_CFGR_JAUTO_Pos)                       /*!< 0x02000000 */
#define ADC_CFGR_JAUTO                            ADC_CFGR_JAUTO_Msk                                
#define ADC_CFGR_AWDCH_Pos                        (26U)
#define ADC_CFGR_AWDCH_Msk                        (0x3FUL<<ADC_CFGR_AWDCH_Pos)                     /*!< 0xFC000000 */
#define ADC_CFGR_AWDCH                            ADC_CFGR_AWDCH_Msk
#define ADC_CFGR_AWDCH_0                          (0x1UL<<ADC_CFGR_AWDCH_Pos)                      /*!< 0x04000000 */
#define ADC_CFGR_AWDCH_1                          (0x2UL<<ADC_CFGR_AWDCH_Pos)                      /*!< 0x08000000 */
#define ADC_CFGR_AWDCH_2                          (0x4UL<<ADC_CFGR_AWDCH_Pos)                      /*!< 0x10000000 */
#define ADC_CFGR_AWDCH_3                          (0x8UL<<ADC_CFGR_AWDCH_Pos)                      /*!< 0x20000000 */
#define ADC_CFGR_AWDCH_4                          (0x10UL<<ADC_CFGR_AWDCH_Pos)                     /*!< 0x40000000 */
#define ADC_CFGR_AWDCH_5                          (0x20UL<<ADC_CFGR_AWDCH_Pos)                     /*!< 0x80000000 */

/********************************* Bit definition for ADC_CFGR2 register ********************************************/
#define ADC_CFGR2_ROVSE_Pos                       (0U)
#define ADC_CFGR2_ROVSE_Msk                       (0x1UL<<ADC_CFGR2_ROVSE_Pos)                      /*!< 0x00000001 */
#define ADC_CFGR2_ROVSE                           ADC_CFGR2_ROVSE_Msk                               
#define ADC_CFGR2_JOVSE_Pos                       (1U)
#define ADC_CFGR2_JOVSE_Msk                       (0x1UL<<ADC_CFGR2_JOVSE_Pos)                      /*!< 0x00000002 */
#define ADC_CFGR2_JOVSE                           ADC_CFGR2_JOVSE_Msk                               
#define ADC_CFGR2_OVSR_Pos                        (2U)
#define ADC_CFGR2_OVSR_Msk                        (0x7UL<<ADC_CFGR2_OVSR_Pos)                       /*!< 0x0000001C */
#define ADC_CFGR2_OVSR                            ADC_CFGR2_OVSR_Msk
#define ADC_CFGR2_OVSR_0                          (0x1UL<<ADC_CFGR2_OVSR_Pos)                       /*!< 0x00000004 */
#define ADC_CFGR2_OVSR_1                          (0x2UL<<ADC_CFGR2_OVSR_Pos)                       /*!< 0x00000008 */
#define ADC_CFGR2_OVSR_2                          (0x4UL<<ADC_CFGR2_OVSR_Pos)                       /*!< 0x00000010 */
#define ADC_CFGR2_OVSS_Pos                        (5U)
#define ADC_CFGR2_OVSS_Msk                        (0xFUL<<ADC_CFGR2_OVSS_Pos)                       /*!< 0x000001E0 */
#define ADC_CFGR2_OVSS                            ADC_CFGR2_OVSS_Msk
#define ADC_CFGR2_OVSS_0                          (0x1UL<<ADC_CFGR2_OVSS_Pos)                       /*!< 0x00000020 */
#define ADC_CFGR2_OVSS_1                          (0x2UL<<ADC_CFGR2_OVSS_Pos)                       /*!< 0x00000040 */
#define ADC_CFGR2_OVSS_2                          (0x4UL<<ADC_CFGR2_OVSS_Pos)                       /*!< 0x00000080 */
#define ADC_CFGR2_OVSS_3                          (0x8UL<<ADC_CFGR2_OVSS_Pos)                       /*!< 0x00000100 */
#define ADC_CFGR2_TROVS_Pos                       (9U)
#define ADC_CFGR2_TROVS_Msk                       (0x1UL<<ADC_CFGR2_TROVS_Pos)                      /*!< 0x00000200 */
#define ADC_CFGR2_TROVS                           ADC_CFGR2_TROVS_Msk                               
#define ADC_CFGR2_ROVSM_Pos                       (10U)
#define ADC_CFGR2_ROVSM_Msk                       (0x1UL<<ADC_CFGR2_ROVSM_Pos)                      /*!< 0x00000400 */
#define ADC_CFGR2_ROVSM                           ADC_CFGR2_ROVSM_Msk    
#define ADC_CFGR2_GCOMP_Pos                       (16U)
#define ADC_CFGR2_GCOMP_Msk                       (0x1UL<<ADC_CFGR2_GCOMP_Pos)                      /*!< 0x00000400 */
#define ADC_CFGR2_GCOMP                           ADC_CFGR2_GCOMP_Msk                               
#define ADC_CFGR2_CALNUM_Pos                      (28U)
#define ADC_CFGR2_CALNUM_Msk                      (0x7UL<<ADC_CFGR2_CALNUM_Pos)                     /*!< 0x70000000 */
#define ADC_CFGR2_CALNUM                          ADC_CFGR2_CALNUM_Msk
#define ADC_CFGR2_CALNUM_0                        (0x1UL<<ADC_CFGR2_CALNUM_Pos)                     /*!< 0x10000000 */
#define ADC_CFGR2_CALNUM_1                        (0x2UL<<ADC_CFGR2_CALNUM_Pos)                     /*!< 0x20000000 */
#define ADC_CFGR2_CALNUM_2                        (0x4UL<<ADC_CFGR2_CALNUM_Pos)                     /*!< 0x40000000 */

/********************************* Bit definition for ADC_SMPR1 register ********************************************/
#define ADC_SMPR1_SMP0_Pos                        (0U)
#define ADC_SMPR1_SMP0_Msk                        (0x7UL<<ADC_SMPR1_SMP0_Pos)                       /*!< 0x00000007 */
#define ADC_SMPR1_SMP0                            ADC_SMPR1_SMP0_Msk
#define ADC_SMPR1_SMP0_0                          (0x1UL<<ADC_SMPR1_SMP0_Pos)                       /*!< 0x00000001 */
#define ADC_SMPR1_SMP0_1                          (0x2UL<<ADC_SMPR1_SMP0_Pos)                       /*!< 0x00000002 */
#define ADC_SMPR1_SMP0_2                          (0x4UL<<ADC_SMPR1_SMP0_Pos)                       /*!< 0x00000004 */
#define ADC_SMPR1_SMP1_Pos                        (3U)
#define ADC_SMPR1_SMP1_Msk                        (0x7UL<<ADC_SMPR1_SMP1_Pos)                       /*!< 0x00000038 */
#define ADC_SMPR1_SMP1                            ADC_SMPR1_SMP1_Msk
#define ADC_SMPR1_SMP1_0                          (0x1UL<<ADC_SMPR1_SMP1_Pos)                       /*!< 0x00000008 */
#define ADC_SMPR1_SMP1_1                          (0x2UL<<ADC_SMPR1_SMP1_Pos)                       /*!< 0x00000010 */
#define ADC_SMPR1_SMP1_2                          (0x4UL<<ADC_SMPR1_SMP1_Pos)                       /*!< 0x00000020 */
#define ADC_SMPR1_SMP2_Pos                        (6U)
#define ADC_SMPR1_SMP2_Msk                        (0x7UL<<ADC_SMPR1_SMP2_Pos)                       /*!< 0x000001C0 */
#define ADC_SMPR1_SMP2                            ADC_SMPR1_SMP2_Msk
#define ADC_SMPR1_SMP2_0                          (0x1UL<<ADC_SMPR1_SMP2_Pos)                       /*!< 0x00000040 */
#define ADC_SMPR1_SMP2_1                          (0x2UL<<ADC_SMPR1_SMP2_Pos)                       /*!< 0x00000080 */
#define ADC_SMPR1_SMP2_2                          (0x4UL<<ADC_SMPR1_SMP2_Pos)                       /*!< 0x00000100 */
#define ADC_SMPR1_SMP3_Pos                        (9U)
#define ADC_SMPR1_SMP3_Msk                        (0x7UL<<ADC_SMPR1_SMP3_Pos)                       /*!< 0x00000E00 */
#define ADC_SMPR1_SMP3                            ADC_SMPR1_SMP3_Msk
#define ADC_SMPR1_SMP3_0                          (0x1UL<<ADC_SMPR1_SMP3_Pos)                       /*!< 0x00000200 */
#define ADC_SMPR1_SMP3_1                          (0x2UL<<ADC_SMPR1_SMP3_Pos)                       /*!< 0x00000400 */
#define ADC_SMPR1_SMP3_2                          (0x4UL<<ADC_SMPR1_SMP3_Pos)                       /*!< 0x00000800 */
#define ADC_SMPR1_SMP4_Pos                        (12U)
#define ADC_SMPR1_SMP4_Msk                        (0x7UL<<ADC_SMPR1_SMP4_Pos)                       /*!< 0x00007000 */
#define ADC_SMPR1_SMP4                            ADC_SMPR1_SMP4_Msk
#define ADC_SMPR1_SMP4_0                          (0x1UL<<ADC_SMPR1_SMP4_Pos)                       /*!< 0x00001000 */
#define ADC_SMPR1_SMP4_1                          (0x2UL<<ADC_SMPR1_SMP4_Pos)                       /*!< 0x00002000 */
#define ADC_SMPR1_SMP4_2                          (0x4UL<<ADC_SMPR1_SMP4_Pos)                       /*!< 0x00004000 */
#define ADC_SMPR1_SMP5_Pos                        (15U)
#define ADC_SMPR1_SMP5_Msk                        (0x7UL<<ADC_SMPR1_SMP5_Pos)                       /*!< 0x00038000 */
#define ADC_SMPR1_SMP5                            ADC_SMPR1_SMP5_Msk
#define ADC_SMPR1_SMP5_0                          (0x1UL<<ADC_SMPR1_SMP5_Pos)                       /*!< 0x00008000 */
#define ADC_SMPR1_SMP5_1                          (0x2UL<<ADC_SMPR1_SMP5_Pos)                       /*!< 0x00010000 */
#define ADC_SMPR1_SMP5_2                          (0x4UL<<ADC_SMPR1_SMP5_Pos)                       /*!< 0x00020000 */
#define ADC_SMPR1_SMP6_Pos                        (18U)
#define ADC_SMPR1_SMP6_Msk                        (0x7UL<<ADC_SMPR1_SMP6_Pos)                       /*!< 0x001C0000 */
#define ADC_SMPR1_SMP6                            ADC_SMPR1_SMP6_Msk
#define ADC_SMPR1_SMP6_0                          (0x1UL<<ADC_SMPR1_SMP6_Pos)                       /*!< 0x00040000 */
#define ADC_SMPR1_SMP6_1                          (0x2UL<<ADC_SMPR1_SMP6_Pos)                       /*!< 0x00080000 */
#define ADC_SMPR1_SMP6_2                          (0x4UL<<ADC_SMPR1_SMP6_Pos)                       /*!< 0x00100000 */
#define ADC_SMPR1_SMP7_Pos                        (21U)
#define ADC_SMPR1_SMP7_Msk                        (0x7UL<<ADC_SMPR1_SMP7_Pos)                       /*!< 0x00E00000 */
#define ADC_SMPR1_SMP7                            ADC_SMPR1_SMP7_Msk
#define ADC_SMPR1_SMP7_0                          (0x1UL<<ADC_SMPR1_SMP7_Pos)                       /*!< 0x00200000 */
#define ADC_SMPR1_SMP7_1                          (0x2UL<<ADC_SMPR1_SMP7_Pos)                       /*!< 0x00400000 */
#define ADC_SMPR1_SMP7_2                          (0x4UL<<ADC_SMPR1_SMP7_Pos)                       /*!< 0x00800000 */
#define ADC_SMPR1_SMP8_Pos                        (24U)
#define ADC_SMPR1_SMP8_Msk                        (0x7UL<<ADC_SMPR1_SMP8_Pos)                       /*!< 0x07000000 */
#define ADC_SMPR1_SMP8                            ADC_SMPR1_SMP8_Msk
#define ADC_SMPR1_SMP8_0                          (0x1UL<<ADC_SMPR1_SMP8_Pos)                       /*!< 0x01000000 */
#define ADC_SMPR1_SMP8_1                          (0x2UL<<ADC_SMPR1_SMP8_Pos)                       /*!< 0x02000000 */
#define ADC_SMPR1_SMP8_2                          (0x4UL<<ADC_SMPR1_SMP8_Pos)                       /*!< 0x04000000 */
#define ADC_SMPR1_SMP9_Pos                        (27U)
#define ADC_SMPR1_SMP9_Msk                        (0x7UL<<ADC_SMPR1_SMP9_Pos)                       /*!< 0x38000000 */
#define ADC_SMPR1_SMP9                            ADC_SMPR1_SMP9_Msk
#define ADC_SMPR1_SMP9_0                          (0x1UL<<ADC_SMPR1_SMP9_Pos)                       /*!< 0x08000000 */
#define ADC_SMPR1_SMP9_1                          (0x2UL<<ADC_SMPR1_SMP9_Pos)                       /*!< 0x10000000 */
#define ADC_SMPR1_SMP9_2                          (0x4UL<<ADC_SMPR1_SMP9_Pos)                       /*!< 0x20000000 */

/********************************* Bit definition for ADC_SMPR2 register ********************************************/
#define ADC_SMPR2_SMP10_Pos                       (0U)
#define ADC_SMPR2_SMP10_Msk                       (0x7UL<<ADC_SMPR2_SMP10_Pos)                      /*!< 0x00000007 */
#define ADC_SMPR2_SMP10                           ADC_SMPR2_SMP10_Msk
#define ADC_SMPR2_SMP10_0                         (0x1UL<<ADC_SMPR2_SMP10_Pos)                      /*!< 0x00000001 */
#define ADC_SMPR2_SMP10_1                         (0x2UL<<ADC_SMPR2_SMP10_Pos)                      /*!< 0x00000002 */
#define ADC_SMPR2_SMP10_2                         (0x4UL<<ADC_SMPR2_SMP10_Pos)                      /*!< 0x00000004 */
#define ADC_SMPR2_SMP11_Pos                       (3U)
#define ADC_SMPR2_SMP11_Msk                       (0x7UL<<ADC_SMPR2_SMP11_Pos)                      /*!< 0x00000038 */
#define ADC_SMPR2_SMP11                           ADC_SMPR2_SMP11_Msk
#define ADC_SMPR2_SMP11_0                         (0x1UL<<ADC_SMPR2_SMP11_Pos)                      /*!< 0x00000008 */
#define ADC_SMPR2_SMP11_1                         (0x2UL<<ADC_SMPR2_SMP11_Pos)                      /*!< 0x00000010 */
#define ADC_SMPR2_SMP11_2                         (0x4UL<<ADC_SMPR2_SMP11_Pos)                      /*!< 0x00000020 */
#define ADC_SMPR2_SMP12_Pos                       (6U)
#define ADC_SMPR2_SMP12_Msk                       (0x7UL<<ADC_SMPR2_SMP12_Pos)                      /*!< 0x000001C0 */
#define ADC_SMPR2_SMP12                           ADC_SMPR2_SMP12_Msk
#define ADC_SMPR2_SMP12_0                         (0x1UL<<ADC_SMPR2_SMP12_Pos)                      /*!< 0x00000040 */
#define ADC_SMPR2_SMP12_1                         (0x2UL<<ADC_SMPR2_SMP12_Pos)                      /*!< 0x00000080 */
#define ADC_SMPR2_SMP12_2                         (0x4UL<<ADC_SMPR2_SMP12_Pos)                      /*!< 0x00000100 */
#define ADC_SMPR2_SMP13_Pos                       (9U)
#define ADC_SMPR2_SMP13_Msk                       (0x7UL<<ADC_SMPR2_SMP13_Pos)                      /*!< 0x00000E00 */
#define ADC_SMPR2_SMP13                           ADC_SMPR2_SMP13_Msk
#define ADC_SMPR2_SMP13_0                         (0x1UL<<ADC_SMPR2_SMP13_Pos)                      /*!< 0x00000200 */
#define ADC_SMPR2_SMP13_1                         (0x2UL<<ADC_SMPR2_SMP13_Pos)                      /*!< 0x00000400 */
#define ADC_SMPR2_SMP13_2                         (0x4UL<<ADC_SMPR2_SMP13_Pos)                      /*!< 0x00000800 */
#define ADC_SMPR2_SMP14_Pos                       (12U)
#define ADC_SMPR2_SMP14_Msk                       (0x7UL<<ADC_SMPR2_SMP14_Pos)                      /*!< 0x00007000 */
#define ADC_SMPR2_SMP14                           ADC_SMPR2_SMP14_Msk
#define ADC_SMPR2_SMP14_0                         (0x1UL<<ADC_SMPR2_SMP14_Pos)                      /*!< 0x00001000 */
#define ADC_SMPR2_SMP14_1                         (0x2UL<<ADC_SMPR2_SMP14_Pos)                      /*!< 0x00002000 */
#define ADC_SMPR2_SMP14_2                         (0x4UL<<ADC_SMPR2_SMP14_Pos)                      /*!< 0x00004000 */
#define ADC_SMPR2_SMP15_Pos                       (15U)
#define ADC_SMPR2_SMP15_Msk                       (0x7UL<<ADC_SMPR2_SMP15_Pos)                      /*!< 0x00038000 */
#define ADC_SMPR2_SMP15                           ADC_SMPR2_SMP15_Msk
#define ADC_SMPR2_SMP15_0                         (0x1UL<<ADC_SMPR2_SMP15_Pos)                      /*!< 0x00008000 */
#define ADC_SMPR2_SMP15_1                         (0x2UL<<ADC_SMPR2_SMP15_Pos)                      /*!< 0x00010000 */
#define ADC_SMPR2_SMP15_2                         (0x4UL<<ADC_SMPR2_SMP15_Pos)                      /*!< 0x00020000 */
#define ADC_SMPR2_SMP16_Pos                       (18U)
#define ADC_SMPR2_SMP16_Msk                       (0x7UL<<ADC_SMPR2_SMP16_Pos)                      /*!< 0x001C0000 */
#define ADC_SMPR2_SMP16                           ADC_SMPR2_SMP16_Msk
#define ADC_SMPR2_SMP16_0                         (0x1UL<<ADC_SMPR2_SMP16_Pos)                      /*!< 0x00040000 */
#define ADC_SMPR2_SMP16_1                         (0x2UL<<ADC_SMPR2_SMP16_Pos)                      /*!< 0x00080000 */
#define ADC_SMPR2_SMP16_2                         (0x4UL<<ADC_SMPR2_SMP16_Pos)                      /*!< 0x00100000 */
#define ADC_SMPR2_SMP17_Pos                       (21U)
#define ADC_SMPR2_SMP17_Msk                       (0x7UL<<ADC_SMPR2_SMP17_Pos)                      /*!< 0x00E00000 */
#define ADC_SMPR2_SMP17                           ADC_SMPR2_SMP17_Msk
#define ADC_SMPR2_SMP17_0                         (0x1UL<<ADC_SMPR2_SMP17_Pos)                      /*!< 0x00200000 */
#define ADC_SMPR2_SMP17_1                         (0x2UL<<ADC_SMPR2_SMP17_Pos)                      /*!< 0x00400000 */
#define ADC_SMPR2_SMP17_2                         (0x4UL<<ADC_SMPR2_SMP17_Pos)                      /*!< 0x00800000 */
#define ADC_SMPR2_SMP18_Pos                       (24U)
#define ADC_SMPR2_SMP18_Msk                       (0x7UL<<ADC_SMPR2_SMP18_Pos)                      /*!< 0x07000000 */
#define ADC_SMPR2_SMP18                           ADC_SMPR2_SMP18_Msk
#define ADC_SMPR2_SMP18_0                         (0x1UL<<ADC_SMPR2_SMP18_Pos)                      /*!< 0x01000000 */
#define ADC_SMPR2_SMP18_1                         (0x2UL<<ADC_SMPR2_SMP18_Pos)                      /*!< 0x02000000 */
#define ADC_SMPR2_SMP18_2                         (0x4UL<<ADC_SMPR2_SMP18_Pos)                      /*!< 0x04000000 */
#define ADC_SMPR2_SMP19_Pos                       (27U)
#define ADC_SMPR2_SMP19_Msk                       (0x7UL<<ADC_SMPR2_SMP19_Pos)                      /*!< 0x38000000 */
#define ADC_SMPR2_SMP19                           ADC_SMPR2_SMP19_Msk
#define ADC_SMPR2_SMP19_0                         (0x1UL<<ADC_SMPR2_SMP19_Pos)                      /*!< 0x08000000 */
#define ADC_SMPR2_SMP19_1                         (0x2UL<<ADC_SMPR2_SMP19_Pos)                      /*!< 0x10000000 */
#define ADC_SMPR2_SMP19_2                         (0x4UL<<ADC_SMPR2_SMP19_Pos)                      /*!< 0x20000000 */

/********************************* Bit definition for ADC_SMPR3 register ********************************************/
#define ADC_SMPR3_SMP20_Pos                       (0U)
#define ADC_SMPR3_SMP20_Msk                       (0x7UL<<ADC_SMPR3_SMP20_Pos)                      /*!< 0x00000007 */
#define ADC_SMPR3_SMP20                           ADC_SMPR3_SMP20_Msk
#define ADC_SMPR3_SMP20_0                         (0x1UL<<ADC_SMPR3_SMP20_Pos)                      /*!< 0x00000001 */
#define ADC_SMPR3_SMP20_1                         (0x2UL<<ADC_SMPR3_SMP20_Pos)                      /*!< 0x00000002 */
#define ADC_SMPR3_SMP20_2                         (0x4UL<<ADC_SMPR3_SMP20_Pos)                      /*!< 0x00000004 */
#define ADC_SMPR3_SMP21_Pos                       (3U)
#define ADC_SMPR3_SMP21_Msk                       (0x7UL<<ADC_SMPR3_SMP21_Pos)                      /*!< 0x00000038 */
#define ADC_SMPR3_SMP21                           ADC_SMPR3_SMP21_Msk
#define ADC_SMPR3_SMP21_0                         (0x1UL<<ADC_SMPR3_SMP21_Pos)                      /*!< 0x00000008 */
#define ADC_SMPR3_SMP21_1                         (0x2UL<<ADC_SMPR3_SMP21_Pos)                      /*!< 0x00000010 */
#define ADC_SMPR3_SMP21_2                         (0x4UL<<ADC_SMPR3_SMP21_Pos)                      /*!< 0x00000020 */
#define ADC_SMPR3_SMP22_Pos                       (6U)
#define ADC_SMPR3_SMP22_Msk                       (0x7UL<<ADC_SMPR3_SMP22_Pos)                      /*!< 0x000001C0 */
#define ADC_SMPR3_SMP22                           ADC_SMPR3_SMP22_Msk
#define ADC_SMPR3_SMP22_0                         (0x1UL<<ADC_SMPR3_SMP22_Pos)                      /*!< 0x00000040 */
#define ADC_SMPR3_SMP22_1                         (0x2UL<<ADC_SMPR3_SMP22_Pos)                      /*!< 0x00000080 */
#define ADC_SMPR3_SMP22_2                         (0x4UL<<ADC_SMPR3_SMP22_Pos)                      /*!< 0x00000100 */
#define ADC_SMPR3_SMP23_Pos                       (9U)
#define ADC_SMPR3_SMP23_Msk                       (0x7UL<<ADC_SMPR3_SMP23_Pos)                      /*!< 0x00000E00 */
#define ADC_SMPR3_SMP23                           ADC_SMPR3_SMP23_Msk
#define ADC_SMPR3_SMP23_0                         (0x1UL<<ADC_SMPR3_SMP23_Pos)                      /*!< 0x00000200 */
#define ADC_SMPR3_SMP23_1                         (0x2UL<<ADC_SMPR3_SMP23_Pos)                      /*!< 0x00000400 */
#define ADC_SMPR3_SMP23_2                         (0x4UL<<ADC_SMPR3_SMP23_Pos)                      /*!< 0x00000800 */
#define ADC_SMPR3_SMP24_Pos                       (12U)
#define ADC_SMPR3_SMP24_Msk                       (0x7UL<<ADC_SMPR3_SMP24_Pos)                      /*!< 0x00007000 */
#define ADC_SMPR3_SMP24                           ADC_SMPR3_SMP24_Msk
#define ADC_SMPR3_SMP24_0                         (0x1UL<<ADC_SMPR3_SMP24_Pos)                      /*!< 0x00001000 */
#define ADC_SMPR3_SMP24_1                         (0x2UL<<ADC_SMPR3_SMP24_Pos)                      /*!< 0x00002000 */
#define ADC_SMPR3_SMP24_2                         (0x4UL<<ADC_SMPR3_SMP24_Pos)                      /*!< 0x00004000 */
#define ADC_SMPR3_SMP25_Pos                       (15U)
#define ADC_SMPR3_SMP25_Msk                       (0x7UL<<ADC_SMPR3_SMP25_Pos)                      /*!< 0x00038000 */
#define ADC_SMPR3_SMP25                           ADC_SMPR3_SMP25_Msk
#define ADC_SMPR3_SMP25_0                         (0x1UL<<ADC_SMPR3_SMP25_Pos)                      /*!< 0x00008000 */
#define ADC_SMPR3_SMP25_1                         (0x2UL<<ADC_SMPR3_SMP25_Pos)                      /*!< 0x00010000 */
#define ADC_SMPR3_SMP25_2                         (0x4UL<<ADC_SMPR3_SMP25_Pos)                      /*!< 0x00020000 */
#define ADC_SMPR3_SMP26_Pos                       (18U)
#define ADC_SMPR3_SMP26_Msk                       (0x7UL<<ADC_SMPR3_SMP26_Pos)                      /*!< 0x001C0000 */
#define ADC_SMPR3_SMP26                           ADC_SMPR3_SMP26_Msk
#define ADC_SMPR3_SMP26_0                         (0x1UL<<ADC_SMPR3_SMP26_Pos)                      /*!< 0x00040000 */
#define ADC_SMPR3_SMP26_1                         (0x2UL<<ADC_SMPR3_SMP26_Pos)                      /*!< 0x00080000 */
#define ADC_SMPR3_SMP26_2                         (0x4UL<<ADC_SMPR3_SMP26_Pos)                      /*!< 0x00100000 */
#define ADC_SMPR3_SMP27_Pos                       (21U)
#define ADC_SMPR3_SMP27_Msk                       (0x7UL<<ADC_SMPR3_SMP27_Pos)                      /*!< 0x00E00000 */
#define ADC_SMPR3_SMP27                           ADC_SMPR3_SMP27_Msk
#define ADC_SMPR3_SMP27_0                         (0x1UL<<ADC_SMPR3_SMP27_Pos)                      /*!< 0x00200000 */
#define ADC_SMPR3_SMP27_1                         (0x2UL<<ADC_SMPR3_SMP27_Pos)                      /*!< 0x00400000 */
#define ADC_SMPR3_SMP27_2                         (0x4UL<<ADC_SMPR3_SMP27_Pos)                      /*!< 0x00800000 */
#define ADC_SMPR3_SMP28_Pos                       (24U)
#define ADC_SMPR3_SMP28_Msk                       (0x7UL<<ADC_SMPR3_SMP28_Pos)                      /*!< 0x07000000 */
#define ADC_SMPR3_SMP28                           ADC_SMPR3_SMP28_Msk
#define ADC_SMPR3_SMP28_0                         (0x1UL<<ADC_SMPR3_SMP28_Pos)                      /*!< 0x01000000 */
#define ADC_SMPR3_SMP28_1                         (0x2UL<<ADC_SMPR3_SMP28_Pos)                      /*!< 0x02000000 */
#define ADC_SMPR3_SMP28_2                         (0x4UL<<ADC_SMPR3_SMP28_Pos)                      /*!< 0x04000000 */
#define ADC_SMPR3_SMP29_Pos                       (27U)
#define ADC_SMPR3_SMP29_Msk                       (0x7UL<<ADC_SMPR3_SMP29_Pos)                      /*!< 0x38000000 */
#define ADC_SMPR3_SMP29                           ADC_SMPR3_SMP29_Msk
#define ADC_SMPR3_SMP29_0                         (0x1UL<<ADC_SMPR3_SMP29_Pos)                      /*!< 0x08000000 */
#define ADC_SMPR3_SMP29_1                         (0x2UL<<ADC_SMPR3_SMP29_Pos)                      /*!< 0x10000000 */
#define ADC_SMPR3_SMP29_2                         (0x4UL<<ADC_SMPR3_SMP29_Pos)                      /*!< 0x20000000 */

/********************************* Bit definition for ADC_SMPR4 register ********************************************/
#define ADC_SMPR4_SMP30_Pos                       (0U)
#define ADC_SMPR4_SMP30_Msk                       (0x7UL<<ADC_SMPR4_SMP30_Pos)                      /*!< 0x00000007 */
#define ADC_SMPR4_SMP30                           ADC_SMPR4_SMP30_Msk
#define ADC_SMPR4_SMP30_0                         (0x1UL<<ADC_SMPR4_SMP30_Pos)                      /*!< 0x00000001 */
#define ADC_SMPR4_SMP30_1                         (0x2UL<<ADC_SMPR4_SMP30_Pos)                      /*!< 0x00000002 */
#define ADC_SMPR4_SMP30_2                         (0x4UL<<ADC_SMPR4_SMP30_Pos)                      /*!< 0x00000004 */
#define ADC_SMPR4_SMP31_Pos                       (3U)
#define ADC_SMPR4_SMP31_Msk                       (0x7UL<<ADC_SMPR4_SMP31_Pos)                      /*!< 0x00000038 */
#define ADC_SMPR4_SMP31                           ADC_SMPR4_SMP31_Msk
#define ADC_SMPR4_SMP31_0                         (0x1UL<<ADC_SMPR4_SMP31_Pos)                      /*!< 0x00000008 */
#define ADC_SMPR4_SMP31_1                         (0x2UL<<ADC_SMPR4_SMP31_Pos)                      /*!< 0x00000010 */
#define ADC_SMPR4_SMP31_2                         (0x4UL<<ADC_SMPR4_SMP31_Pos)                      /*!< 0x00000020 */

/********************************* Bit definition for ADC_TR1 register **********************************************/
#define ADC_TR_LT_Pos                             (0U)
#define ADC_TR_LT_Msk                             (0xFFFUL<<ADC_TR_LT_Pos)                        /*!< 0x00000FFF */
#define ADC_TR_LT                                 ADC_TR_LT_Msk
#define ADC_TR_HT_Pos                             (16U)
#define ADC_TR_HT_Msk                             (0xFFFUL<<ADC_TR_HT_Pos)                        /*!< 0x0FFF0000 */
#define ADC_TR_HT                                 ADC_TR_HT_Msk

/********************************* Bit definition for ADC_SQR1 register *********************************************/
#define ADC_SQR1_L_Pos                            (0U)
#define ADC_SQR1_L_Msk                            (0xFUL<<ADC_SQR1_L_Pos)                           /*!< 0x0000000F */
#define ADC_SQR1_L                                ADC_SQR1_L_Msk
#define ADC_SQR1_L_0                              (0x1UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000001 */
#define ADC_SQR1_L_1                              (0x2UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000002 */
#define ADC_SQR1_L_2                              (0x4UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000004 */
#define ADC_SQR1_L_3                              (0x8UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000008 */
#define ADC_SQR1_SQ1_Pos                          (6U)
#define ADC_SQR1_SQ1_Msk                          (0x3FUL<<ADC_SQR1_SQ1_Pos)                        /*!< 0x00000FC0 */
#define ADC_SQR1_SQ1                              ADC_SQR1_SQ1_Msk
#define ADC_SQR1_SQ1_0                            (0x1UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000040 */
#define ADC_SQR1_SQ1_1                            (0x2UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000080 */
#define ADC_SQR1_SQ1_2                            (0x4UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000100 */
#define ADC_SQR1_SQ1_3                            (0x8UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000200 */
#define ADC_SQR1_SQ1_4                            (0x10UL<<ADC_SQR1_SQ1_Pos)                        /*!< 0x00000400 */
#define ADC_SQR1_SQ1_5                            (0x20UL<<ADC_SQR1_SQ1_Pos)                        /*!< 0x00000800 */
#define ADC_SQR1_SQ2_Pos                          (12U)
#define ADC_SQR1_SQ2_Msk                          (0x3FUL<<ADC_SQR1_SQ2_Pos)                        /*!< 0x0003F000 */
#define ADC_SQR1_SQ2                              ADC_SQR1_SQ2_Msk
#define ADC_SQR1_SQ2_0                            (0x1UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00001000 */
#define ADC_SQR1_SQ2_1                            (0x2UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00002000 */
#define ADC_SQR1_SQ2_2                            (0x4UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00004000 */
#define ADC_SQR1_SQ2_3                            (0x8UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00008000 */
#define ADC_SQR1_SQ2_4                            (0x10UL<<ADC_SQR1_SQ2_Pos)                        /*!< 0x00010000 */
#define ADC_SQR1_SQ2_5                            (0x20UL<<ADC_SQR1_SQ2_Pos)                        /*!< 0x00020000 */
#define ADC_SQR1_SQ3_Pos                          (18U)
#define ADC_SQR1_SQ3_Msk                          (0x3FUL<<ADC_SQR1_SQ3_Pos)                        /*!< 0x00FC0000 */
#define ADC_SQR1_SQ3                              ADC_SQR1_SQ3_Msk
#define ADC_SQR1_SQ3_0                            (0x1UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00040000 */
#define ADC_SQR1_SQ3_1                            (0x2UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00080000 */
#define ADC_SQR1_SQ3_2                            (0x4UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00100000 */
#define ADC_SQR1_SQ3_3                            (0x8UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00200000 */
#define ADC_SQR1_SQ3_4                            (0x10UL<<ADC_SQR1_SQ3_Pos)                        /*!< 0x00400000 */
#define ADC_SQR1_SQ3_5                            (0x20UL<<ADC_SQR1_SQ3_Pos)                        /*!< 0x00800000 */
#define ADC_SQR1_SQ4_Pos                          (24U)
#define ADC_SQR1_SQ4_Msk                          (0x3FUL<<ADC_SQR1_SQ4_Pos)                        /*!< 0x3F000000 */
#define ADC_SQR1_SQ4                              ADC_SQR1_SQ4_Msk
#define ADC_SQR1_SQ4_0                            (0x1UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x01000000 */
#define ADC_SQR1_SQ4_1                            (0x2UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x02000000 */
#define ADC_SQR1_SQ4_2                            (0x4UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x04000000 */
#define ADC_SQR1_SQ4_3                            (0x8UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x08000000 */
#define ADC_SQR1_SQ4_4                            (0x10UL<<ADC_SQR1_SQ4_Pos)                        /*!< 0x10000000 */
#define ADC_SQR1_SQ4_5                            (0x20UL<<ADC_SQR1_SQ4_Pos)                        /*!< 0x20000000 */

/********************************* Bit definition for ADC_SQR2 register *********************************************/
#define ADC_SQR2_SQ5_Pos                          (0U)
#define ADC_SQR2_SQ5_Msk                          (0x3FUL<<ADC_SQR2_SQ5_Pos)                        /*!< 0x0000003F */
#define ADC_SQR2_SQ5                              ADC_SQR2_SQ5_Msk
#define ADC_SQR2_SQ5_0                            (0x1UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000001 */
#define ADC_SQR2_SQ5_1                            (0x2UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000002 */
#define ADC_SQR2_SQ5_2                            (0x4UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000004 */
#define ADC_SQR2_SQ5_3                            (0x8UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000008 */
#define ADC_SQR2_SQ5_4                            (0x10UL<<ADC_SQR2_SQ5_Pos)                        /*!< 0x00000010 */
#define ADC_SQR2_SQ5_5                            (0x20UL<<ADC_SQR2_SQ5_Pos)                        /*!< 0x00000020 */
#define ADC_SQR2_SQ6_Pos                          (6U)
#define ADC_SQR2_SQ6_Msk                          (0x3FUL<<ADC_SQR2_SQ6_Pos)                        /*!< 0x00000FC0 */
#define ADC_SQR2_SQ6                              ADC_SQR2_SQ6_Msk
#define ADC_SQR2_SQ6_0                            (0x1UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000040 */
#define ADC_SQR2_SQ6_1                            (0x2UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000080 */
#define ADC_SQR2_SQ6_2                            (0x4UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000100 */
#define ADC_SQR2_SQ6_3                            (0x8UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000200 */
#define ADC_SQR2_SQ6_4                            (0x10UL<<ADC_SQR2_SQ6_Pos)                        /*!< 0x00000400 */
#define ADC_SQR2_SQ6_5                            (0x20UL<<ADC_SQR2_SQ6_Pos)                        /*!< 0x00000800 */
#define ADC_SQR2_SQ7_Pos                          (12U)
#define ADC_SQR2_SQ7_Msk                          (0x3FUL<<ADC_SQR2_SQ7_Pos)                        /*!< 0x0003F000 */
#define ADC_SQR2_SQ7                              ADC_SQR2_SQ7_Msk
#define ADC_SQR2_SQ7_0                            (0x1UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00001000 */
#define ADC_SQR2_SQ7_1                            (0x2UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00002000 */
#define ADC_SQR2_SQ7_2                            (0x4UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00004000 */
#define ADC_SQR2_SQ7_3                            (0x8UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00008000 */
#define ADC_SQR2_SQ7_4                            (0x10UL<<ADC_SQR2_SQ7_Pos)                        /*!< 0x00010000 */
#define ADC_SQR2_SQ7_5                            (0x20UL<<ADC_SQR2_SQ7_Pos)                        /*!< 0x00020000 */
#define ADC_SQR2_SQ8_Pos                          (18U)
#define ADC_SQR2_SQ8_Msk                          (0x3FUL<<ADC_SQR2_SQ8_Pos)                        /*!< 0x00FC0000 */
#define ADC_SQR2_SQ8                              ADC_SQR2_SQ8_Msk
#define ADC_SQR2_SQ8_0                            (0x1UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00040000 */
#define ADC_SQR2_SQ8_1                            (0x2UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00080000 */
#define ADC_SQR2_SQ8_2                            (0x4UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00100000 */
#define ADC_SQR2_SQ8_3                            (0x8UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00200000 */
#define ADC_SQR2_SQ8_4                            (0x10UL<<ADC_SQR2_SQ8_Pos)                        /*!< 0x00400000 */
#define ADC_SQR2_SQ8_5                            (0x20UL<<ADC_SQR2_SQ8_Pos)                        /*!< 0x00800000 */
#define ADC_SQR2_SQ9_Pos                          (24U)
#define ADC_SQR2_SQ9_Msk                          (0x3FUL<<ADC_SQR2_SQ9_Pos)                        /*!< 0x3F000000 */
#define ADC_SQR2_SQ9                              ADC_SQR2_SQ9_Msk
#define ADC_SQR2_SQ9_0                            (0x1UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x01000000 */
#define ADC_SQR2_SQ9_1                            (0x2UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x02000000 */
#define ADC_SQR2_SQ9_2                            (0x4UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x04000000 */
#define ADC_SQR2_SQ9_3                            (0x8UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x08000000 */
#define ADC_SQR2_SQ9_4                            (0x10UL<<ADC_SQR2_SQ9_Pos)                        /*!< 0x10000000 */
#define ADC_SQR2_SQ9_5                            (0x20UL<<ADC_SQR2_SQ9_Pos)                        /*!< 0x20000000 */

/********************************* Bit definition for ADC_SQR3 register *********************************************/
#define ADC_SQR3_SQ10_Pos                         (0U)
#define ADC_SQR3_SQ10_Msk                         (0x3FUL<<ADC_SQR3_SQ10_Pos)                       /*!< 0x0000003F */
#define ADC_SQR3_SQ10                             ADC_SQR3_SQ10_Msk
#define ADC_SQR3_SQ10_0                           (0x1UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000001 */
#define ADC_SQR3_SQ10_1                           (0x2UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000002 */
#define ADC_SQR3_SQ10_2                           (0x4UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000004 */
#define ADC_SQR3_SQ10_3                           (0x8UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000008 */
#define ADC_SQR3_SQ10_4                           (0x10UL<<ADC_SQR3_SQ10_Pos)                       /*!< 0x00000010 */
#define ADC_SQR3_SQ10_5                           (0x20UL<<ADC_SQR3_SQ10_Pos)                       /*!< 0x00000020 */
#define ADC_SQR3_SQ11_Pos                         (6U)
#define ADC_SQR3_SQ11_Msk                         (0x3FUL<<ADC_SQR3_SQ11_Pos)                       /*!< 0x00000FC0 */
#define ADC_SQR3_SQ11                             ADC_SQR3_SQ11_Msk
#define ADC_SQR3_SQ11_0                           (0x1UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000040 */
#define ADC_SQR3_SQ11_1                           (0x2UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000080 */
#define ADC_SQR3_SQ11_2                           (0x4UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000100 */
#define ADC_SQR3_SQ11_3                           (0x8UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000200 */
#define ADC_SQR3_SQ11_4                           (0x10UL<<ADC_SQR3_SQ11_Pos)                       /*!< 0x00000400 */
#define ADC_SQR3_SQ11_5                           (0x20UL<<ADC_SQR3_SQ11_Pos)                       /*!< 0x00000800 */
#define ADC_SQR3_SQ12_Pos                         (12U)
#define ADC_SQR3_SQ12_Msk                         (0x3FUL<<ADC_SQR3_SQ12_Pos)                       /*!< 0x0003F000 */
#define ADC_SQR3_SQ12                             ADC_SQR3_SQ12_Msk
#define ADC_SQR3_SQ12_0                           (0x1UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00001000 */
#define ADC_SQR3_SQ12_1                           (0x2UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00002000 */
#define ADC_SQR3_SQ12_2                           (0x4UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00004000 */
#define ADC_SQR3_SQ12_3                           (0x8UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00008000 */
#define ADC_SQR3_SQ12_4                           (0x10UL<<ADC_SQR3_SQ12_Pos)                       /*!< 0x00010000 */
#define ADC_SQR3_SQ12_5                           (0x20UL<<ADC_SQR3_SQ12_Pos)                       /*!< 0x00020000 */
#define ADC_SQR3_SQ13_Pos                         (18U)
#define ADC_SQR3_SQ13_Msk                         (0x3FUL<<ADC_SQR3_SQ13_Pos)                       /*!< 0x00FC0000 */
#define ADC_SQR3_SQ13                             ADC_SQR3_SQ13_Msk
#define ADC_SQR3_SQ13_0                           (0x1UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00040000 */
#define ADC_SQR3_SQ13_1                           (0x2UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00080000 */
#define ADC_SQR3_SQ13_2                           (0x4UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00100000 */
#define ADC_SQR3_SQ13_3                           (0x8UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00200000 */
#define ADC_SQR3_SQ13_4                           (0x10UL<<ADC_SQR3_SQ13_Pos)                       /*!< 0x00400000 */
#define ADC_SQR3_SQ13_5                           (0x20UL<<ADC_SQR3_SQ13_Pos)                       /*!< 0x00800000 */
#define ADC_SQR3_SQ14_Pos                         (24U)
#define ADC_SQR3_SQ14_Msk                         (0x3FUL<<ADC_SQR3_SQ14_Pos)                       /*!< 0x3F000000 */
#define ADC_SQR3_SQ14                             ADC_SQR3_SQ14_Msk
#define ADC_SQR3_SQ14_0                           (0x1UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x01000000 */
#define ADC_SQR3_SQ14_1                           (0x2UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x02000000 */
#define ADC_SQR3_SQ14_2                           (0x4UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x04000000 */
#define ADC_SQR3_SQ14_3                           (0x8UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x08000000 */
#define ADC_SQR3_SQ14_4                           (0x10UL<<ADC_SQR3_SQ14_Pos)                       /*!< 0x10000000 */
#define ADC_SQR3_SQ14_5                           (0x20UL<<ADC_SQR3_SQ14_Pos)                       /*!< 0x20000000 */

/********************************* Bit definition for ADC_SQR4 register *********************************************/
#define ADC_SQR4_SQ15_Pos                         (0U)
#define ADC_SQR4_SQ15_Msk                         (0x3FUL<<ADC_SQR4_SQ15_Pos)                       /*!< 0x0000003F */
#define ADC_SQR4_SQ15                             ADC_SQR4_SQ15_Msk
#define ADC_SQR4_SQ15_0                           (0x1UL<<ADC_SQR4_SQ15_Pos)                        /*!< 0x00000001 */
#define ADC_SQR4_SQ15_1                           (0x2UL<<ADC_SQR4_SQ15_Pos)                        /*!< 0x00000002 */
#define ADC_SQR4_SQ15_2                           (0x4UL<<ADC_SQR4_SQ15_Pos)                        /*!< 0x00000004 */
#define ADC_SQR4_SQ15_3                           (0x8UL<<ADC_SQR4_SQ15_Pos)                        /*!< 0x00000008 */
#define ADC_SQR4_SQ15_4                           (0x10UL<<ADC_SQR4_SQ15_Pos)                       /*!< 0x00000010 */
#define ADC_SQR4_SQ15_5                           (0x20UL<<ADC_SQR4_SQ15_Pos)                       /*!< 0x00000020 */
#define ADC_SQR4_SQ16_Pos                         (6U)
#define ADC_SQR4_SQ16_Msk                         (0x3FUL<<ADC_SQR4_SQ16_Pos)                       /*!< 0x00000FC0 */
#define ADC_SQR4_SQ16                             ADC_SQR4_SQ16_Msk
#define ADC_SQR4_SQ16_0                           (0x1UL<<ADC_SQR4_SQ16_Pos)                        /*!< 0x00000040 */
#define ADC_SQR4_SQ16_1                           (0x2UL<<ADC_SQR4_SQ16_Pos)                        /*!< 0x00000080 */
#define ADC_SQR4_SQ16_2                           (0x4UL<<ADC_SQR4_SQ16_Pos)                        /*!< 0x00000100 */
#define ADC_SQR4_SQ16_3                           (0x8UL<<ADC_SQR4_SQ16_Pos)                        /*!< 0x00000200 */
#define ADC_SQR4_SQ16_4                           (0x10UL<<ADC_SQR4_SQ16_Pos)                       /*!< 0x00000400 */
#define ADC_SQR4_SQ16_5                           (0x20UL<<ADC_SQR4_SQ16_Pos)                       /*!< 0x00000800 */

/********************************* Bit definition for ADC_DR register ***********************************************/
#define ADC_DR_RDATA_Pos                          (0U)
#define ADC_DR_RDATA_Msk                          (0xFFFFUL<<ADC_DR_RDATA_Pos)                      /*!< 0x0000FFFF */
#define ADC_DR_RDATA                              ADC_DR_RDATA_Msk

/********************************* Bit definition for ADC_JSQR register *********************************************/
#define ADC_JSQR_JL_Pos                           (0U)
#define ADC_JSQR_JL_Msk                           (0x3UL<<ADC_JSQR_JL_Pos)                          /*!< 0x00000003 */
#define ADC_JSQR_JL                               ADC_JSQR_JL_Msk
#define ADC_JSQR_JL_0                             (0x1UL<<ADC_JSQR_JL_Pos)                          /*!< 0x00000001 */
#define ADC_JSQR_JL_1                             (0x2UL<<ADC_JSQR_JL_Pos)                          /*!< 0x00000002 */
#define ADC_JSQR_JEXTSEL_Pos                      (2U)
#define ADC_JSQR_JEXTSEL_Msk                      (0xFUL<<ADC_JSQR_JEXTSEL_Pos)                     /*!< 0x0000003C */
#define ADC_JSQR_JEXTSEL                          ADC_JSQR_JEXTSEL_Msk
#define ADC_JSQR_JEXTSEL_0                        (0x1UL<<ADC_JSQR_JEXTSEL_Pos)                     /*!< 0x00000004 */
#define ADC_JSQR_JEXTSEL_1                        (0x2UL<<ADC_JSQR_JEXTSEL_Pos)                     /*!< 0x00000008 */
#define ADC_JSQR_JEXTSEL_2                        (0x4UL<<ADC_JSQR_JEXTSEL_Pos)                     /*!< 0x00000010 */
#define ADC_JSQR_JEXTSEL_3                        (0x8UL<<ADC_JSQR_JEXTSEL_Pos)                     /*!< 0x00000020 */
#define ADC_JSQR_JEXTEN_Pos                       (6U)
#define ADC_JSQR_JEXTEN_Msk                       (0x3UL<<ADC_JSQR_JEXTEN_Pos)                      /*!< 0x000000C0 */
#define ADC_JSQR_JEXTEN                           ADC_JSQR_JEXTEN_Msk
#define ADC_JSQR_JEXTEN_0                         (0x1UL<<ADC_JSQR_JEXTEN_Pos)                      /*!< 0x00000040 */
#define ADC_JSQR_JEXTEN_1                         (0x2UL<<ADC_JSQR_JEXTEN_Pos)                      /*!< 0x00000080 */
#define ADC_JSQR_JSQ1_Pos                         (8U)
#define ADC_JSQR_JSQ1_Msk                         (0x3FUL<<ADC_JSQR_JSQ1_Pos)                       /*!< 0x00003F00 */
#define ADC_JSQR_JSQ1                             ADC_JSQR_JSQ1_Msk
#define ADC_JSQR_JSQ1_0                           (0x1UL<<ADC_JSQR_JSQ1_Pos)                        /*!< 0x00000100 */
#define ADC_JSQR_JSQ1_1                           (0x2UL<<ADC_JSQR_JSQ1_Pos)                        /*!< 0x00000200 */
#define ADC_JSQR_JSQ1_2                           (0x4UL<<ADC_JSQR_JSQ1_Pos)                        /*!< 0x00000400 */
#define ADC_JSQR_JSQ1_3                           (0x8UL<<ADC_JSQR_JSQ1_Pos)                        /*!< 0x00000800 */
#define ADC_JSQR_JSQ1_4                           (0x10UL<<ADC_JSQR_JSQ1_Pos)                       /*!< 0x00001000 */
#define ADC_JSQR_JSQ1_5                           (0x20UL<<ADC_JSQR_JSQ1_Pos)                       /*!< 0x00002000 */
#define ADC_JSQR_JSQ2_Pos                         (14U)
#define ADC_JSQR_JSQ2_Msk                         (0x3FUL<<ADC_JSQR_JSQ2_Pos)                       /*!< 0x000FC000 */
#define ADC_JSQR_JSQ2                             ADC_JSQR_JSQ2_Msk
#define ADC_JSQR_JSQ2_0                           (0x1UL<<ADC_JSQR_JSQ2_Pos)                        /*!< 0x00004000 */
#define ADC_JSQR_JSQ2_1                           (0x2UL<<ADC_JSQR_JSQ2_Pos)                        /*!< 0x00008000 */
#define ADC_JSQR_JSQ2_2                           (0x4UL<<ADC_JSQR_JSQ2_Pos)                        /*!< 0x00010000 */
#define ADC_JSQR_JSQ2_3                           (0x8UL<<ADC_JSQR_JSQ2_Pos)                        /*!< 0x00020000 */
#define ADC_JSQR_JSQ2_4                           (0x10UL<<ADC_JSQR_JSQ2_Pos)                       /*!< 0x00040000 */
#define ADC_JSQR_JSQ2_5                           (0x20UL<<ADC_JSQR_JSQ2_Pos)                       /*!< 0x00080000 */
#define ADC_JSQR_JSQ3_Pos                         (20U)
#define ADC_JSQR_JSQ3_Msk                         (0x3FUL<<ADC_JSQR_JSQ3_Pos)                       /*!< 0x03F00000 */
#define ADC_JSQR_JSQ3                             ADC_JSQR_JSQ3_Msk
#define ADC_JSQR_JSQ3_0                           (0x1UL<<ADC_JSQR_JSQ3_Pos)                        /*!< 0x00100000 */
#define ADC_JSQR_JSQ3_1                           (0x2UL<<ADC_JSQR_JSQ3_Pos)                        /*!< 0x00200000 */
#define ADC_JSQR_JSQ3_2                           (0x4UL<<ADC_JSQR_JSQ3_Pos)                        /*!< 0x00400000 */
#define ADC_JSQR_JSQ3_3                           (0x8UL<<ADC_JSQR_JSQ3_Pos)                        /*!< 0x00800000 */
#define ADC_JSQR_JSQ3_4                           (0x10UL<<ADC_JSQR_JSQ3_Pos)                       /*!< 0x01000000 */
#define ADC_JSQR_JSQ3_5                           (0x20UL<<ADC_JSQR_JSQ3_Pos)                       /*!< 0x02000000 */
#define ADC_JSQR_JSQ4_Pos                         (26U)
#define ADC_JSQR_JSQ4_Msk                         (0x3FUL<<ADC_JSQR_JSQ4_Pos)                       /*!< 0xFC000000 */
#define ADC_JSQR_JSQ4                             ADC_JSQR_JSQ4_Msk
#define ADC_JSQR_JSQ4_0                           (0x1UL<<ADC_JSQR_JSQ4_Pos)                        /*!< 0x04000000 */
#define ADC_JSQR_JSQ4_1                           (0x2UL<<ADC_JSQR_JSQ4_Pos)                        /*!< 0x08000000 */
#define ADC_JSQR_JSQ4_2                           (0x4UL<<ADC_JSQR_JSQ4_Pos)                        /*!< 0x10000000 */
#define ADC_JSQR_JSQ4_3                           (0x8UL<<ADC_JSQR_JSQ4_Pos)                        /*!< 0x20000000 */
#define ADC_JSQR_JSQ4_4                           (0x10UL<<ADC_JSQR_JSQ4_Pos)                       /*!< 0x40000000 */
#define ADC_JSQR_JSQ4_5                           (0x20UL<<ADC_JSQR_JSQ4_Pos)                       /*!< 0x80000000 */

/********************************* Bit definition for ADC_OFR register *********************************************/
#define ADC_OFR1_OFFSET1_Pos                      (0U)
#define ADC_OFR1_OFFSET1_Msk                      (0xFFFUL<<ADC_OFR1_OFFSET1_Pos)                   /*!< 0x00000FFF */
#define ADC_OFR1_OFFSET1                          ADC_OFR1_OFFSET1_Msk
#define ADC_OFR1_OFFSETPOS_Pos                    (23U)
#define ADC_OFR1_OFFSETPOS_Msk                    (0x1UL<<ADC_OFR1_OFFSETPOS_Pos)                   /*!< 0x00800000 */
#define ADC_OFR1_OFFSETPOS                        ADC_OFR1_OFFSETPOS_Msk                            
#define ADC_OFR1_SATEN_Pos                        (24U)
#define ADC_OFR1_SATEN_Msk                        (0x1UL<<ADC_OFR1_SATEN_Pos)                       /*!< 0x01000000 */
#define ADC_OFR1_SATEN                            ADC_OFR1_SATEN_Msk                                
#define ADC_OFR1_OFFSET1_CH_Pos                   (25U)
#define ADC_OFR1_OFFSET1_CH_Msk                   (0x3FUL<<ADC_OFR1_OFFSET1_CH_Pos)                 /*!< 0x7E000000 */
#define ADC_OFR1_OFFSET1_CH                       ADC_OFR1_OFFSET1_CH_Msk
#define ADC_OFR1_OFFSET1_CH_0                     (0x1UL<<ADC_OFR1_OFFSET1_CH_Pos)                  /*!< 0x02000000 */
#define ADC_OFR1_OFFSET1_CH_1                     (0x2UL<<ADC_OFR1_OFFSET1_CH_Pos)                  /*!< 0x04000000 */
#define ADC_OFR1_OFFSET1_CH_2                     (0x4UL<<ADC_OFR1_OFFSET1_CH_Pos)                  /*!< 0x08000000 */
#define ADC_OFR1_OFFSET1_CH_3                     (0x8UL<<ADC_OFR1_OFFSET1_CH_Pos)                  /*!< 0x10000000 */
#define ADC_OFR1_OFFSET1_CH_4                     (0x10UL<<ADC_OFR1_OFFSET1_CH_Pos)                 /*!< 0x20000000 */
#define ADC_OFR1_OFFSET1_CH_5                     (0x20UL<<ADC_OFR1_OFFSET1_CH_Pos)                 /*!< 0x40000000 */
#define ADC_OFR1_OFFSET1_EN_Pos                   (31U)
#define ADC_OFR1_OFFSET1_EN_Msk                   (0x1UL<<ADC_OFR1_OFFSET1_EN_Pos)                  /*!< 0x80000000 */
#define ADC_OFR1_OFFSET1_EN                       ADC_OFR1_OFFSET1_EN_Msk   

#define ADC_OFR2_OFFSET2_Pos                      (0U)
#define ADC_OFR2_OFFSET2_Msk                      (0xFFFUL<<ADC_OFR2_OFFSET2_Pos)                   /*!< 0x00000FFF */
#define ADC_OFR2_OFFSET2                          ADC_OFR2_OFFSET2_Msk
#define ADC_OFR2_OFFSETPOS_Pos                    (23U)
#define ADC_OFR2_OFFSETPOS_Msk                    (0x1UL<<ADC_OFR2_OFFSETPOS_Pos)                   /*!< 0x00800000 */
#define ADC_OFR2_OFFSETPOS                        ADC_OFR2_OFFSETPOS_Msk                            
#define ADC_OFR2_SATEN_Pos                        (24U)
#define ADC_OFR2_SATEN_Msk                        (0x1UL<<ADC_OFR2_SATEN_Pos)                       /*!< 0x01000000 */
#define ADC_OFR2_SATEN                            ADC_OFR2_SATEN_Msk                                
#define ADC_OFR2_OFFSET2_CH_Pos                   (25U)
#define ADC_OFR2_OFFSET2_CH_Msk                   (0x3FUL<<ADC_OFR2_OFFSET2_CH_Pos)                 /*!< 0x7E000000 */
#define ADC_OFR2_OFFSET2_CH                       ADC_OFR2_OFFSET2_CH_Msk
#define ADC_OFR2_OFFSET2_CH_0                     (0x1UL<<ADC_OFR2_OFFSET2_CH_Pos)                  /*!< 0x02000000 */
#define ADC_OFR2_OFFSET2_CH_1                     (0x2UL<<ADC_OFR2_OFFSET2_CH_Pos)                  /*!< 0x04000000 */
#define ADC_OFR2_OFFSET2_CH_2                     (0x4UL<<ADC_OFR2_OFFSET2_CH_Pos)                  /*!< 0x08000000 */
#define ADC_OFR2_OFFSET2_CH_3                     (0x8UL<<ADC_OFR2_OFFSET2_CH_Pos)                  /*!< 0x10000000 */
#define ADC_OFR2_OFFSET2_CH_4                     (0x10UL<<ADC_OFR2_OFFSET2_CH_Pos)                 /*!< 0x20000000 */
#define ADC_OFR2_OFFSET2_CH_5                     (0x20UL<<ADC_OFR2_OFFSET2_CH_Pos)                 /*!< 0x40000000 */
#define ADC_OFR2_OFFSET2_EN_Pos                   (31U)
#define ADC_OFR2_OFFSET2_EN_Msk                   (0x1UL<<ADC_OFR2_OFFSET2_EN_Pos)                  /*!< 0x80000000 */
#define ADC_OFR2_OFFSET2_EN                       ADC_OFR2_OFFSET2_EN_Msk   

#define ADC_OFR3_OFFSET3_Pos                      (0U)
#define ADC_OFR3_OFFSET3_Msk                      (0xFFFUL<<ADC_OFR3_OFFSET3_Pos)                   /*!< 0x00000FFF */
#define ADC_OFR3_OFFSET3                          ADC_OFR3_OFFSET3_Msk
#define ADC_OFR3_OFFSETPOS_Pos                    (23U)
#define ADC_OFR3_OFFSETPOS_Msk                    (0x1UL<<ADC_OFR3_OFFSETPOS_Pos)                   /*!< 0x00800000 */
#define ADC_OFR3_OFFSETPOS                        ADC_OFR3_OFFSETPOS_Msk                            
#define ADC_OFR3_SATEN_Pos                        (24U)
#define ADC_OFR3_SATEN_Msk                        (0x1UL<<ADC_OFR3_SATEN_Pos)                       /*!< 0x01000000 */
#define ADC_OFR3_SATEN                            ADC_OFR3_SATEN_Msk                                
#define ADC_OFR3_OFFSET3_CH_Pos                   (25U)
#define ADC_OFR3_OFFSET3_CH_Msk                   (0x3FUL<<ADC_OFR3_OFFSET3_CH_Pos)                 /*!< 0x7E000000 */
#define ADC_OFR3_OFFSET3_CH                       ADC_OFR3_OFFSET3_CH_Msk
#define ADC_OFR3_OFFSET3_CH_0                     (0x1UL<<ADC_OFR3_OFFSET3_CH_Pos)                  /*!< 0x02000000 */
#define ADC_OFR3_OFFSET3_CH_1                     (0x2UL<<ADC_OFR3_OFFSET3_CH_Pos)                  /*!< 0x04000000 */
#define ADC_OFR3_OFFSET3_CH_2                     (0x4UL<<ADC_OFR3_OFFSET3_CH_Pos)                  /*!< 0x08000000 */
#define ADC_OFR3_OFFSET3_CH_3                     (0x8UL<<ADC_OFR3_OFFSET3_CH_Pos)                  /*!< 0x10000000 */
#define ADC_OFR3_OFFSET3_CH_4                     (0x10UL<<ADC_OFR3_OFFSET3_CH_Pos)                 /*!< 0x20000000 */
#define ADC_OFR3_OFFSET3_CH_5                     (0x20UL<<ADC_OFR3_OFFSET3_CH_Pos)                 /*!< 0x40000000 */
#define ADC_OFR3_OFFSET3_EN_Pos                   (31U)
#define ADC_OFR3_OFFSET3_EN_Msk                   (0x1UL<<ADC_OFR3_OFFSET3_EN_Pos)                  /*!< 0x80000000 */
#define ADC_OFR3_OFFSET3_EN                       ADC_OFR3_OFFSET3_EN_Msk   

#define ADC_OFR4_OFFSET4_Pos                      (0U)
#define ADC_OFR4_OFFSET4_Msk                      (0xFFFUL<<ADC_OFR4_OFFSET4_Pos)                   /*!< 0x00000FFF */
#define ADC_OFR4_OFFSET4                          ADC_OFR4_OFFSET4_Msk
#define ADC_OFR4_OFFSETPOS_Pos                    (23U)
#define ADC_OFR4_OFFSETPOS_Msk                    (0x1UL<<ADC_OFR4_OFFSETPOS_Pos)                   /*!< 0x00800000 */
#define ADC_OFR4_OFFSETPOS                        ADC_OFR4_OFFSETPOS_Msk                            
#define ADC_OFR4_SATEN_Pos                        (24U)
#define ADC_OFR4_SATEN_Msk                        (0x1UL<<ADC_OFR4_SATEN_Pos)                       /*!< 0x01000000 */
#define ADC_OFR4_SATEN                            ADC_OFR4_SATEN_Msk                                
#define ADC_OFR4_OFFSET4_CH_Pos                   (25U)
#define ADC_OFR4_OFFSET4_CH_Msk                   (0x3FUL<<ADC_OFR4_OFFSET4_CH_Pos)                 /*!< 0x7E000000 */
#define ADC_OFR4_OFFSET4_CH                       ADC_OFR4_OFFSET4_CH_Msk
#define ADC_OFR4_OFFSET4_CH_0                     (0x1UL<<ADC_OFR4_OFFSET4_CH_Pos)                  /*!< 0x02000000 */
#define ADC_OFR4_OFFSET4_CH_1                     (0x2UL<<ADC_OFR4_OFFSET4_CH_Pos)                  /*!< 0x04000000 */
#define ADC_OFR4_OFFSET4_CH_2                     (0x4UL<<ADC_OFR4_OFFSET4_CH_Pos)                  /*!< 0x08000000 */
#define ADC_OFR4_OFFSET4_CH_3                     (0x8UL<<ADC_OFR4_OFFSET4_CH_Pos)                  /*!< 0x10000000 */
#define ADC_OFR4_OFFSET4_CH_4                     (0x10UL<<ADC_OFR4_OFFSET4_CH_Pos)                 /*!< 0x20000000 */
#define ADC_OFR4_OFFSET4_CH_5                     (0x20UL<<ADC_OFR4_OFFSET4_CH_Pos)                 /*!< 0x40000000 */
#define ADC_OFR4_OFFSET4_EN_Pos                   (31U)
#define ADC_OFR4_OFFSET4_EN_Msk                   (0x1UL<<ADC_OFR4_OFFSET4_EN_Pos)                  /*!< 0x80000000 */
#define ADC_OFR4_OFFSET4_EN                       ADC_OFR4_OFFSET4_EN_Msk   
                   

/********************************* Bit definition for ADC_JDR1 register *********************************************/
#define ADC_JDR1_JDATA_Pos                        (0U)
#define ADC_JDR1_JDATA_Msk                        (0xFFFFUL<<ADC_JDR1_JDATA_Pos)                    /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA                            ADC_JDR1_JDATA_Msk

/********************************* Bit definition for ADC_JDR2 register *********************************************/
#define ADC_JDR2_JDATA_Pos                        (0U)
#define ADC_JDR2_JDATA_Msk                        (0xFFFFUL<<ADC_JDR2_JDATA_Pos)                    /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA                            ADC_JDR2_JDATA_Msk

/********************************* Bit definition for ADC_JDR3 register *********************************************/
#define ADC_JDR3_JDATA_Pos                        (0U)
#define ADC_JDR3_JDATA_Msk                        (0xFFFFUL<<ADC_JDR3_JDATA_Pos)                    /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA                            ADC_JDR3_JDATA_Msk

/********************************* Bit definition for ADC_JDR4 register *********************************************/
#define ADC_JDR4_JDATA_Pos                        (0U)
#define ADC_JDR4_JDATA_Msk                        (0xFFFFUL<<ADC_JDR4_JDATA_Pos)                    /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA                            ADC_JDR4_JDATA_Msk

/********************************* Bit definition for ADC_CALFACT register ******************************************/
#define ADC_CALFACT_OFFSUC_Pos                    (20U)
#define ADC_CALFACT_OFFSUC_Msk                    (0x1UL<<ADC_CALFACT_OFFSUC_Pos)                   /*!< 0x00100000 */
#define ADC_CALFACT_OFFSUC                        ADC_CALFACT_OFFSUC_Msk                            
#define ADC_CALFACT_CAPSUC_Pos                    (21U)
#define ADC_CALFACT_CAPSUC_Msk                    (0x1UL<<ADC_CALFACT_CAPSUC_Pos)                   /*!< 0x00200000 */
#define ADC_CALFACT_CAPSUC                        ADC_CALFACT_CAPSUC_Msk                            

/********************************* Bit definition for ADC_GCOMP register ********************************************/
#define ADC_GCOMP_GCOMPCOEFF_Pos                  (0U)
#define ADC_GCOMP_GCOMPCOEFF_Msk                  (0x3FFFUL<<ADC_GCOMP_GCOMPCOEFF_Pos)              /*!< 0x00003FFF */
#define ADC_GCOMP_GCOMPCOEFF                      ADC_GCOMP_GCOMPCOEFF_Msk

/********************************* Bit definition for ADCX_CCR register *********************************************/
#define ADC_CCR_CKMODE_Pos                        (16U)
#define ADC_CCR_CKMODE_Msk                        (0x3UL<<ADC_CCR_CKMODE_Pos)                      /*!< 0x00030000 */
#define ADC_CCR_CKMODE                            ADC_CCR_CKMODE_Msk
#define ADC_CCR_CKMODE_0                          (0x1UL<<ADC_CCR_CKMODE_Pos)                      /*!< 0x00010000 */
#define ADC_CCR_CKMODE_1                          (0x2UL<<ADC_CCR_CKMODE_Pos)                      /*!< 0x00020000 */
#define ADC_CCR_PRESC_Pos                         (18U)
#define ADC_CCR_PRESC_Msk                         (0xFUL<<ADC_CCR_PRESC_Pos)                       /*!< 0x003C0000 */
#define ADC_CCR_PRESC                             ADC_CCR_PRESC_Msk
#define ADC_CCR_PRESC_0                           (0x1UL<<ADC_CCR_PRESC_Pos)                       /*!< 0x00040000 */
#define ADC_CCR_PRESC_1                           (0x2UL<<ADC_CCR_PRESC_Pos)                       /*!< 0x00080000 */
#define ADC_CCR_PRESC_2                           (0x4UL<<ADC_CCR_PRESC_Pos)                       /*!< 0x00100000 */
#define ADC_CCR_PRESC_3                           (0x8UL<<ADC_CCR_PRESC_Pos)                       /*!< 0x00200000 */
#define ADC_CCR_VREFINT_EN_Pos                    (22U)
#define ADC_CCR_VREFINT_EN_Msk                    (0x1UL<<ADC_CCR_VREFINT_EN_Pos)                  /*!< 0x00400000 */
#define ADC_CCR_VREFINT_EN                        ADC_CCR_VREFINT_EN_Msk                               
#define ADC_CCR_TSEN_Pos                          (23U)
#define ADC_CCR_TSEN_Msk                          (0x1UL<<ADC_CCR_TSEN_Pos)                        /*!< 0x00800000 */
#define ADC_CCR_TSEN                              ADC_CCR_TSEN_Msk    
#define ADC_CCR_PWR_MODE_Pos                      (25U)
#define ADC_CCR_PWR_MODE_Msk                      (0x7UL<<ADC_CCR_PWR_MODE_Pos)                        
#define ADC_CCR_PWR_MODE                          ADC_CCR_PWR_MODE_Msk            
#define ADC_CCR_PWR_MODE_0                        (0x1UL<<ADC_CCR_PWR_MODE_Pos)   
#define ADC_CCR_PWR_MODE_1                        (0x2UL<<ADC_CCR_PWR_MODE_Pos)   
#define ADC_CCR_PWR_MODE_2                        (0x4UL<<ADC_CCR_PWR_MODE_Pos)
#define ADC_CCR_VREFSEL_Pos                       (28U)
#define ADC_CCR_VREFSEL_Msk                       (0x1UL<<ADC_CCR_VREFSEL_Pos)                        
#define ADC_CCR_VREFSEL                           ADC_CCR_VREFSEL_Msk  
#define ADC_CCR_DIFF_EN_Pos                       (29U)
#define ADC_CCR_DIFF_EN_Msk                       (0x1UL<<ADC_CCR_DIFF_EN_Pos)                        
#define ADC_CCR_DIFF_EN                           ADC_CCR_DIFF_EN_Msk                  

/********************************************************************************************************************/
/********************************* COMP *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for COMP_CSR register ********************************************/
#define COMP_CSR_EN_Pos                          (0U)
#define COMP_CSR_EN_Msk                          (0x1UL<<COMP_CSR_EN_Pos)                         /*!< 0x00000001 */
#define COMP_CSR_EN                              COMP_CSR_EN_Msk                                  /*!< COMP enable bit */
#define COMP_CSR_COMP1_EN                        COMP_CSR_EN
#define COMP_CSR_COMP2_EN                        COMP_CSR_EN
#define COMP_CSR_INMSEL_Pos                      (2U)
#define COMP_CSR_INMSEL_Msk                      (0x7UL<<COMP_CSR_INMSEL_Pos)                     /*!< 0x0000001C */
#define COMP_CSR_INMSEL                          COMP_CSR_INMSEL_Msk                              /*!< COMP negative input select */
#define COMP_CSR_INMSEL_0                        (0x1UL<<COMP_CSR_INMSEL_Pos)                     /*!< 0x00000004 */
#define COMP_CSR_INMSEL_1                        (0x2UL<<COMP_CSR_INMSEL_Pos)                     /*!< 0x00000008 */
#define COMP_CSR_INMSEL_2                        (0x4UL<<COMP_CSR_INMSEL_Pos)                     /*!< 0x00000010 */
#define COMP_CSR_INPSEL_Pos                      (5U)
#define COMP_CSR_INPSEL_Msk                      (0x7UL<<COMP_CSR_INPSEL_Pos)                     /*!< 0x000000E0 */
#define COMP_CSR_INPSEL                          COMP_CSR_INPSEL_Msk                              /*!< COMP positive input select */
#define COMP_CSR_INPSEL_0                        (0x1UL<<COMP_CSR_INPSEL_Pos)                     /*!< 0x00000020 */
#define COMP_CSR_INPSEL_1                        (0x2UL<<COMP_CSR_INPSEL_Pos)                     /*!< 0x00000040 */
#define COMP_CSR_INPSEL_2                        (0x4UL<<COMP_CSR_INPSEL_Pos)                     /*!< 0x00000080 */
#define COMP_CSR_WINMODE_Pos                     (11U)
#define COMP_CSR_WINMODE_Msk                     (0x1UL<<COMP_CSR_WINMODE_Pos)                    /*!< 0x00000800 */
#define COMP_CSR_WINMODE                         COMP_CSR_WINMODE_Msk                             /*!< COMP window mode enable */
#define COMP_CSR_BLANKSEL_Pos                    (12U)
#define COMP_CSR_BLANKSEL_Msk                    (0x7UL<<COMP_CSR_BLANKSEL_Pos)                   /*!< 0x00007000 */
#define COMP_CSR_BLANKSEL                        COMP_CSR_BLANKSEL_Msk                            /*!< Comparator  blanking signal selection */
#define COMP_CSR_BLANKSEL_0                      (0x1UL<<COMP_CSR_BLANKSEL_Pos)                   /*!< 0x00001000 */
#define COMP_CSR_BLANKSEL_1                      (0x2UL<<COMP_CSR_BLANKSEL_Pos)                   /*!< 0x00002000 */
#define COMP_CSR_BLANKSEL_2                      (0x4UL<<COMP_CSR_BLANKSEL_Pos)                   /*!< 0x00004000 */
#define COMP_CSR_POLARITY_Pos                    (15U)
#define COMP_CSR_POLARITY_Msk                    (0x1UL<<COMP_CSR_POLARITY_Pos)                   /*!< 0x00008000 */
#define COMP_CSR_POLARITY                        COMP_CSR_POLARITY_Msk                            /*!< COMP output polarity selection */
#define COMP_CSR_HYST_Pos                        (16U)
#define COMP_CSR_HYST_Msk                        (0x1UL<<COMP_CSR_HYST_Pos)                       /*!< 0x00010000 */
#define COMP_CSR_HYST                            COMP_CSR_HYST_Msk                                /*!< COMP hysteresis function enable control */
#define COMP_CSR_PWRMODE_Pos                     (18U)
#define COMP_CSR_PWRMODE_Msk                     (0x1UL<<COMP_CSR_PWRMODE_Pos)                    /*!< 0x00040000 */
#define COMP_CSR_PWRMODE                         COMP_CSR_PWRMODE_Msk                             /*!< COMP power mode selection */
#define COMP_CSR_INT_OUT_SEL_Pos                 (29U)
#define COMP_CSR_INT_OUT_SEL_Msk                 (0x1UL<<COMP_CSR_INT_OUT_SEL_Pos)                /*!< 0x20000000 */
#define COMP_CSR_INT_OUT_SEL                     COMP_CSR_INT_OUT_SEL_Msk                         /*!< COMP output to TIM/EXTI selection */
#define COMP_CSR_COMP_OUT_Pos                    (30U)
#define COMP_CSR_COMP_OUT_Msk                    (0x1UL<<COMP_CSR_COMP_OUT_Pos)                   /*!< 0x40000000 */
#define COMP_CSR_COMP_OUT                        COMP_CSR_COMP_OUT_Msk                            /*!< COMP output status */
#define COMP_CSR_LOCK_Pos                        (31U)
#define COMP_CSR_LOCK_Msk                        (0x1UL<<COMP_CSR_LOCK_Pos)                       /*!< 0x80000000 */
#define COMP_CSR_LOCK                            COMP_CSR_LOCK_Msk                                /*!< COMP_CSR registerlock */

/********************************* Bit definition for COMP_FR register *********************************************/
#define COMP_FR_FLTEN_Pos                        (0U)
#define COMP_FR_FLTEN_Msk                        (0x1UL<<COMP_FR_FLTEN_Pos)                       /*!< 0x00000001 */
#define COMP_FR_FLTEN                            COMP_FR_FLTEN_Msk                                /*!< Comparator digital filter configuration */
#define COMP_FR_FLTCNT_Pos                       (16U)
#define COMP_FR_FLTCNT_Msk                       (0xFFFFUL<<COMP_FR_FLTCNT_Pos)                   /*!< 0xFFFF0000 */
#define COMP_FR_FLTCNT                           COMP_FR_FLTCNT_Msk                               /*!< Comparator sampling filter counter */

/********************************* Bit definition for COMP_CCSR register ********************************************/
#define COMP_CCSR_VREFCMP_EN_Pos                  (0U)
#define COMP_CCSR_VREFCMP_EN_Msk                  (0x1UL<<COMP_CCSR_VREFCMP_EN_Pos)                 /*!< 0x00000001 */
#define COMP_CCSR_VREFCMP_EN                      COMP_CCSR_VREFCMP_EN_Msk                          /*!< VREFCMP voltage divider enable signal */
#define COMP_CCSR_VCDIV_Pos                       (1U)
#define COMP_CCSR_VCDIV_Msk                       (0x3FUL<<COMP_CCSR_VCDIV_Pos)                     /*!< 0x0000007E */
#define COMP_CCSR_VCDIV                           COMP_CCSR_VCDIV_Msk
#define COMP_CCSR_VCDIV_0                         (0x1UL<<COMP_CCSR_VCDIV_Pos)                      /*!< 0x00000002 */
#define COMP_CCSR_VCDIV_1                         (0x2UL<<COMP_CCSR_VCDIV_Pos)                      /*!< 0x00000004 */
#define COMP_CCSR_VCDIV_2                         (0x4UL<<COMP_CCSR_VCDIV_Pos)                      /*!< 0x00000008 */
#define COMP_CCSR_VCDIV_3                         (0x8UL<<COMP_CCSR_VCDIV_Pos)                      /*!< 0x00000010 */
#define COMP_CCSR_VCDIV_4                         (0x10UL<<COMP_CCSR_VCDIV_Pos)                     /*!< 0x00000020 */
#define COMP_CCSR_VCDIV_5                         (0x20UL<<COMP_CCSR_VCDIV_Pos)                     /*!< 0x00000040 */
#define COMP_CCSR_SSEL_Pos                        (7U)
#define COMP_CCSR_SSEL_Msk                        (0x1UL<<COMP_CCSR_SSEL_Pos)                       /*!< 0x00000080 */
#define COMP_CCSR_SSEL                            COMP_CCSR_SSEL_Msk                                
#define COMP_CCSR_VSEL_Pos                        (8U)
#define COMP_CCSR_VSEL_Msk                        (0x7UL<<COMP_CCSR_VSEL_Pos)                       /*!< 0x00000700 */
#define COMP_CCSR_VSEL                            COMP_CCSR_VSEL_Msk                                /*!< VREFCMP reference source selection */
#define COMP_CCSR_VSEL_0                          (0x1UL<<COMP_CCSR_VSEL_Pos)                       /*!< 0x00000100 */
#define COMP_CCSR_VSEL_1                          (0x2UL<<COMP_CCSR_VSEL_Pos)                       /*!< 0x00000200 */
#define COMP_CCSR_VSEL_2                          (0x4UL<<COMP_CCSR_VSEL_Pos)                       /*!< 0x00000400 */



/********************************************************************************************************************/
/********************************* CRC ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for CRC_DR register ***********************************************/
#define CRC_DR_DR_Pos                             (0U)
#define CRC_DR_DR_Msk                             (0xFFFFFFFFUL<<CRC_DR_DR_Pos)                     /*!< 0xFFFFFFFF */
#define CRC_DR_DR                                 CRC_DR_DR_Msk                                     /*!< CRC data */

/********************************* Bit definition for CRC_IDR register **********************************************/
#define CRC_IDR_IDR_Pos                           (0U)
#define CRC_IDR_IDR_Msk                           (0xFFFFFFFFUL<<CRC_IDR_IDR_Pos)                   /*!< 0xFFFFFFFF */
#define CRC_IDR_IDR                               CRC_IDR_IDR_Msk                                   /*!< CRC independent data */

/********************************* Bit definition for CRC_CR register ***********************************************/
#define CRC_CR_RESET_Pos                          (0U)
#define CRC_CR_RESET_Msk                          (0x1UL<<CRC_CR_RESET_Pos)                         /*!< 0x00000001 */
#define CRC_CR_RESET                              CRC_CR_RESET_Msk                                  /*!< CRC software reset */
#define CRC_CR_POLYSIZE_Pos                       (3U)
#define CRC_CR_POLYSIZE_Msk                       (0x3UL<<CRC_CR_POLYSIZE_Pos)                      /*!< 0x00000018 */
#define CRC_CR_POLYSIZE                           CRC_CR_POLYSIZE_Msk                               /*!< Polynomial size */
#define CRC_CR_POLYSIZE_0                         (0x1UL<<CRC_CR_POLYSIZE_Pos)                      /*!< 0x00000008 */
#define CRC_CR_POLYSIZE_1                         (0x2UL<<CRC_CR_POLYSIZE_Pos)                      /*!< 0x00000010 */
#define CRC_CR_REV_IN_Pos                         (5U)
#define CRC_CR_REV_IN_Msk                         (0x3UL<<CRC_CR_REV_IN_Pos)                        /*!< 0x00000060 */
#define CRC_CR_REV_IN                             CRC_CR_REV_IN_Msk                                 /*!< Reverse input data */
#define CRC_CR_REV_IN_0                           (0x1UL<<CRC_CR_REV_IN_Pos)                        /*!< 0x00000020 */
#define CRC_CR_REV_IN_1                           (0x2UL<<CRC_CR_REV_IN_Pos)                        /*!< 0x00000040 */
#define CRC_CR_REV_OUT_Pos                        (7U)
#define CRC_CR_REV_OUT_Msk                        (0x1UL<<CRC_CR_REV_OUT_Pos)                       /*!< 0x00000080 */
#define CRC_CR_REV_OUT                            CRC_CR_REV_OUT_Msk                                /*!< Reverse output data */

/********************************* Bit definition for CRC_INIT register *********************************************/
#define CRC_INIT_INIT_Pos                         (0U)
#define CRC_INIT_INIT_Msk                         (0xFFFFFFFFUL<<CRC_INIT_INIT_Pos)                 /*!< 0xFFFFFFFF */
#define CRC_INIT_INIT                             CRC_INIT_INIT_Msk                                 /*!< initial value */

/********************************* Bit definition for CRC_POL register **********************************************/
#define CRC_POL_POL_Pos                           (0U)
#define CRC_POL_POL_Msk                           (0xFFFFFFFFUL<<CRC_POL_POL_Pos)                   /*!< 0xFFFFFFFF */
#define CRC_POL_POL                               CRC_POL_POL_Msk                                   /*!< polynomial  */


/********************************************************************************************************************/
/********************************* DAC ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for DAC_CR1 register **********************************************/
#define DAC_CR1_EN_Pos                            (0U)
#define DAC_CR1_EN_Msk                            (0x1UL<<DAC_CR1_EN_Pos)                           /*!< 0x00000001 */
#define DAC_CR1_EN                                DAC_CR1_EN_Msk                                    
#define DAC_CR1_BOFF_Pos                          (1U)
#define DAC_CR1_BOFF_Msk                          (0x1UL<<DAC_CR1_BOFF_Pos)                         /*!< 0x00000002 */
#define DAC_CR1_BOFF                              DAC_CR1_BOFF_Msk                                  
#define DAC_CR1_TEN_Pos                           (2U)
#define DAC_CR1_TEN_Msk                           (0x1UL<<DAC_CR1_TEN_Pos)                          /*!< 0x00000004 */
#define DAC_CR1_TEN                               DAC_CR1_TEN_Msk                                   
#define DAC_CR1_TSEL_Pos                          (3U)
#define DAC_CR1_TSEL_Msk                          (0x7UL<<DAC_CR1_TSEL_Pos)                         /*!< 0x00000038 */
#define DAC_CR1_TSEL                              DAC_CR1_TSEL_Msk
#define DAC_CR1_TSEL_0                            (0x1UL<<DAC_CR1_TSEL_Pos)                         /*!< 0x00000008 */
#define DAC_CR1_TSEL_1                            (0x2UL<<DAC_CR1_TSEL_Pos)                         /*!< 0x00000010 */
#define DAC_CR1_TSEL_2                            (0x4UL<<DAC_CR1_TSEL_Pos)                         /*!< 0x00000020 */
#define DAC_CR1_WAVE_Pos                          (6U)
#define DAC_CR1_WAVE_Msk                          (0x3UL<<DAC_CR1_WAVE_Pos)                         /*!< 0x000000C0 */
#define DAC_CR1_WAVE                              DAC_CR1_WAVE_Msk
#define DAC_CR1_WAVE_0                            (0x1UL<<DAC_CR1_WAVE_Pos)                         /*!< 0x00000040 */
#define DAC_CR1_WAVE_1                            (0x2UL<<DAC_CR1_WAVE_Pos)                         /*!< 0x00000080 */
#define DAC_CR1_MAMP_Pos                          (8U)
#define DAC_CR1_MAMP_Msk                          (0xFUL<<DAC_CR1_MAMP_Pos)                         /*!< 0x00000F00 */
#define DAC_CR1_MAMP                              DAC_CR1_MAMP_Msk
#define DAC_CR1_MAMP_0                            (0x1UL<<DAC_CR1_MAMP_Pos)                         /*!< 0x00000100 */
#define DAC_CR1_MAMP_1                            (0x2UL<<DAC_CR1_MAMP_Pos)                         /*!< 0x00000200 */
#define DAC_CR1_MAMP_2                            (0x4UL<<DAC_CR1_MAMP_Pos)                         /*!< 0x00000400 */
#define DAC_CR1_MAMP_3                            (0x8UL<<DAC_CR1_MAMP_Pos)                         /*!< 0x00000800 */
#define DAC_CR1_DMAEN_Pos                         (12U)
#define DAC_CR1_DMAEN_Msk                         (0x1UL<<DAC_CR1_DMAEN_Pos)                        /*!< 0x00001000 */
#define DAC_CR1_DMAEN                             DAC_CR1_DMAEN_Msk                                 
#define DAC_CR1_DMAUDRIE_Pos                      (13U)
#define DAC_CR1_DMAUDRIE_Msk                      (0x1UL<<DAC_CR1_DMAUDRIE_Pos)                     /*!< 0x00002000 */
#define DAC_CR1_DMAUDRIE                          DAC_CR1_DMAUDRIE_Msk                              
#define DAC_CR1_DACCEN_Pos                        (14U)
#define DAC_CR1_DACCEN_Msk                        (0x1UL<<DAC_CR1_DACCEN_Pos)                       /*!< 0x00004000 */
#define DAC_CR1_DACCEN                            DAC_CR1_DACCEN_Msk                                
#define DAC_CR1_BUF_CAL_Pos                       (15U)
#define DAC_CR1_BUF_CAL_Msk                       (0x1UL<<DAC_CR1_BUF_CAL_Pos)                      /*!< 0x00008000 */
#define DAC_CR1_BUF_CAL                           DAC_CR1_BUF_CAL_Msk                               

/********************************* Bit definition for DAC_CR2 register **********************************************/
#define DAC_CR2_SWTRIG_Pos                        (0U)
#define DAC_CR2_SWTRIG_Msk                        (0x1UL<<DAC_CR2_SWTRIG_Pos)                       /*!< 0x00000001 */
#define DAC_CR2_SWTRIG                            DAC_CR2_SWTRIG_Msk                                
#define DAC_CR2_VREFSEL_Pos                       (1U)
#define DAC_CR2_VREFSEL_Msk                       (0x1UL<<DAC_CR2_VREFSEL_Pos)                      /*!< 0x00000002 */
#define DAC_CR2_VREFSEL                           DAC_CR2_VREFSEL_Msk                               
#define DAC_CR2_INTEREN_Pos                       (2U)
#define DAC_CR2_INTEREN_Msk                       (0x1UL<<DAC_CR2_INTEREN_Pos)                      /*!< 0x00000004 */
#define DAC_CR2_INTEREN                           DAC_CR2_INTEREN_Msk                               

/********************************* Bit definition for DAC_DHR12R register *******************************************/
#define DAC_DHR12R_DACDHR_Pos                     (0U)
#define DAC_DHR12R_DACDHR_Msk                     (0xFFFUL<<DAC_DHR12R_DACDHR_Pos)                  /*!< 0x00000FFF */
#define DAC_DHR12R_DACDHR                         DAC_DHR12R_DACDHR_Msk

/********************************* Bit definition for DAC_DHR12L register *******************************************/
#define DAC_DHR12L_DACDHR_Pos                     (4U)
#define DAC_DHR12L_DACDHR_Msk                     (0xFFFUL<<DAC_DHR12L_DACDHR_Pos)                  /*!< 0x0000FFF0 */
#define DAC_DHR12L_DACDHR                         DAC_DHR12L_DACDHR_Msk

/********************************* Bit definition for DAC_DHR8R register ********************************************/
#define DAC_DHR8R_DACDHR_Pos                      (0U)
#define DAC_DHR8R_DACDHR_Msk                      (0xFFUL<<DAC_DHR8R_DACDHR_Pos)                    /*!< 0x000000FF */
#define DAC_DHR8R_DACDHR                          DAC_DHR8R_DACDHR_Msk

/********************************* Bit definition for DAC_DOR register **********************************************/
#define DAC_DOR_DACDOR_Pos                        (0U)
#define DAC_DOR_DACDOR_Msk                        (0xFFFUL<<DAC_DOR_DACDOR_Pos)                     /*!< 0x00000FFF */
#define DAC_DOR_DACDOR                            DAC_DOR_DACDOR_Msk

/********************************* Bit definition for DAC_SR register ***********************************************/
#define DAC_SR_DMAUDR_Pos                         (13U)
#define DAC_SR_DMAUDR_Msk                         (0x1UL<<DAC_SR_DMAUDR_Pos)                        /*!< 0x00002000 */
#define DAC_SR_DMAUDR                             DAC_SR_DMAUDR_Msk                                 

/********************************* Bit definition for DAC_CALR register *********************************************/
#define DAC_CALR_DAC_OS_TRIMCR_VCC_Pos            (0U)
#define DAC_CALR_DAC_OS_TRIMCR_VCC_Msk            (0x3FUL<<DAC_CALR_DAC_OS_TRIMCR_VCC_Pos)          /*!< 0x0000003F */
#define DAC_CALR_DAC_OS_TRIMCR_VCC                DAC_CALR_DAC_OS_TRIMCR_VCC_Msk
#define DAC_CALR_DAC_OS_TRIMCR_VCC_0              (0x1UL<<DAC_CALR_DAC_OS_TRIMCR_VCC_Pos)           /*!< 0x00000001 */
#define DAC_CALR_DAC_OS_TRIMCR_VCC_1              (0x2UL<<DAC_CALR_DAC_OS_TRIMCR_VCC_Pos)           /*!< 0x00000002 */
#define DAC_CALR_DAC_OS_TRIMCR_VCC_2              (0x4UL<<DAC_CALR_DAC_OS_TRIMCR_VCC_Pos)           /*!< 0x00000004 */
#define DAC_CALR_DAC_OS_TRIMCR_VCC_3              (0x8UL<<DAC_CALR_DAC_OS_TRIMCR_VCC_Pos)           /*!< 0x00000008 */
#define DAC_CALR_DAC_OS_TRIMCR_VCC_4              (0x10UL<<DAC_CALR_DAC_OS_TRIMCR_VCC_Pos)          /*!< 0x00000010 */
#define DAC_CALR_DAC_OS_TRIMCR_VCC_5              (0x20UL<<DAC_CALR_DAC_OS_TRIMCR_VCC_Pos)          /*!< 0x00000020 */
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos        (6U)
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Msk        (0x3FUL<<DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos)      /*!< 0x00000FC0 */
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF            DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Msk
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_0          (0x1UL<<DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos)       /*!< 0x00000040 */
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_1          (0x2UL<<DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos)       /*!< 0x00000080 */
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_2          (0x4UL<<DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos)       /*!< 0x00000100 */
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_3          (0x8UL<<DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos)       /*!< 0x00000200 */
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_4          (0x10UL<<DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos)      /*!< 0x00000400 */
#define DAC_CALR_DAC_OS_TRIMCR_VREFBUF_5          (0x20UL<<DAC_CALR_DAC_OS_TRIMCR_VREFBUF_Pos)      /*!< 0x00000800 */
#define DAC_CALR_DAC_DOUT_Pos                     (12U)
#define DAC_CALR_DAC_DOUT_Msk                     (0x1UL<<DAC_CALR_DAC_DOUT_Pos)                    /*!< 0x00001000 */
#define DAC_CALR_DAC_DOUT                         DAC_CALR_DAC_DOUT_Msk                             
#define DAC_CALR_DAC_CR_Pos                       (16U)
#define DAC_CALR_DAC_CR_Msk                       (0x1FUL<<DAC_CALR_DAC_CR_Pos)                     /*!< 0x003F0000 */
#define DAC_CALR_DAC_CR                           DAC_CALR_DAC_CR_Msk
#define DAC_CALR_DAC_CR_0                         (0x1UL<<DAC_CALR_DAC_CR_Pos)                      /*!< 0x00010000 */
#define DAC_CALR_DAC_CR_1                         (0x2UL<<DAC_CALR_DAC_CR_Pos)                      /*!< 0x00020000 */
#define DAC_CALR_DAC_CR_2                         (0x4UL<<DAC_CALR_DAC_CR_Pos)                      /*!< 0x00040000 */
#define DAC_CALR_DAC_CR_3                         (0x8UL<<DAC_CALR_DAC_CR_Pos)                      /*!< 0x00080000 */
#define DAC_CALR_DAC_CR_4                         (0x10UL<<DAC_CALR_DAC_CR_Pos)                     /*!< 0x00100000 */



/******************************************************************************/
/*                                                                            */
/*                                Debug MCU (DBGMCU)                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBG_IDCODE register  *************/
#define DBGMCU_IDCODE_DEV_ID_Pos                          (0U)
#define DBGMCU_IDCODE_DEV_ID_Msk                          (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos)  /*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID                              DBGMCU_IDCODE_DEV_ID_Msk
#define DBGMCU_IDCODE_REV_ID_Pos                          (16U)
#define DBGMCU_IDCODE_REV_ID_Msk                          (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID                              DBGMCU_IDCODE_REV_ID_Msk

/********************  Bit definition for DBGMCU_CR register  *****************/
#define DBGMCU_CR_DBG_SLEEP_Pos                           (0U)
#define DBGMCU_CR_DBG_SLEEP_Msk                           (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos)     /*!< 0x00000001 */
#define DBGMCU_CR_DBG_SLEEP                               DBGMCU_CR_DBG_SLEEP_Msk

#define DBGMCU_CR_DBG_STOP_Pos                            (1U)
#define DBGMCU_CR_DBG_STOP_Msk                            (0x1UL << DBGMCU_CR_DBG_STOP_Pos)      /*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP                                DBGMCU_CR_DBG_STOP_Msk

/* #define DBGMCU_CR_DBG_STDBY_Pos                           (2U) */
/* #define DBGMCU_CR_DBG_STDBY_Msk                           (0x1UL << DBGMCU_CR_DBG_STDBY_Pos) */     /*!< 0x00000004 */
/* #define DBGMCU_CR_DBG_STDBY                               DBGMCU_CR_DBG_STDBY_Msk */

/********************  Bit definition for DBGMCU_APB_FZ1 register  ***********/
#define DBGMCU_APB_FZ1_DBG_TIM2_STOP_Pos                  (0U)
#define DBGMCU_APB_FZ1_DBG_TIM2_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_TIM2_STOP_Pos) /*!< 0x00000001 */
#define DBGMCU_APB_FZ1_DBG_TIM2_STOP                      DBGMCU_APB_FZ1_DBG_TIM2_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_TIM3_STOP_Pos                  (1U)
#define DBGMCU_APB_FZ1_DBG_TIM3_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_TIM3_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_APB_FZ1_DBG_TIM3_STOP                      DBGMCU_APB_FZ1_DBG_TIM3_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_TIM6_STOP_Pos                  (4U)
#define DBGMCU_APB_FZ1_DBG_TIM6_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_TIM6_STOP_Pos) /*!< 0x00000010 */
#define DBGMCU_APB_FZ1_DBG_TIM6_STOP                      DBGMCU_APB_FZ1_DBG_TIM6_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_TIM7_STOP_Pos                  (5U)
#define DBGMCU_APB_FZ1_DBG_TIM7_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_TIM7_STOP_Pos) /*!< 0x00000020 */
#define DBGMCU_APB_FZ1_DBG_TIM7_STOP                      DBGMCU_APB_FZ1_DBG_TIM7_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_RTC_STOP_Pos                   (10U)
#define DBGMCU_APB_FZ1_DBG_RTC_STOP_Msk                   (0x1UL << DBGMCU_APB_FZ1_DBG_RTC_STOP_Pos)  /*!< 0x00000400 */
#define DBGMCU_APB_FZ1_DBG_RTC_STOP                       DBGMCU_APB_FZ1_DBG_RTC_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_WWDG_STOP_Pos                  (11U)
#define DBGMCU_APB_FZ1_DBG_WWDG_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_WWDG_STOP_Pos) /*!< 0x00000800 */
#define DBGMCU_APB_FZ1_DBG_WWDG_STOP                      DBGMCU_APB_FZ1_DBG_WWDG_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_IWDG_STOP_Pos                  (12U)
#define DBGMCU_APB_FZ1_DBG_IWDG_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_IWDG_STOP_Pos) /*!< 0x00001000 */
#define DBGMCU_APB_FZ1_DBG_IWDG_STOP                      DBGMCU_APB_FZ1_DBG_IWDG_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_I2C1_STOP_Pos                  (21U)
#define DBGMCU_APB_FZ1_DBG_I2C1_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_I2C1_STOP_Pos) /*!< 0x00200000 */
#define DBGMCU_APB_FZ1_DBG_I2C1_STOP                      DBGMCU_APB_FZ1_DBG_I2C1_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_I2C2_STOP_Pos                  (22U)
#define DBGMCU_APB_FZ1_DBG_I2C2_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_I2C2_STOP_Pos) /*!< 0x00400000 */
#define DBGMCU_APB_FZ1_DBG_I2C2_STOP                      DBGMCU_APB_FZ1_DBG_I2C2_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_LPTIM2_STOP_Pos                (30U)
#define DBGMCU_APB_FZ1_DBG_LPTIM2_STOP_Msk                (0x1UL << DBGMCU_APB_FZ1_DBG_LPTIM2_STOP_Pos) /*!< 0x40000000 */
#define DBGMCU_APB_FZ1_DBG_LPTIM2_STOP                    DBGMCU_APB_FZ1_DBG_LPTIM2_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_LPTIM1_STOP_Pos                (31U)
#define DBGMCU_APB_FZ1_DBG_LPTIM1_STOP_Msk                (0x1UL << DBGMCU_APB_FZ1_DBG_LPTIM1_STOP_Pos) /*!< 0x80000000 */
#define DBGMCU_APB_FZ1_DBG_LPTIM1_STOP                    DBGMCU_APB_FZ1_DBG_LPTIM1_STOP_Msk

/********************  Bit definition for DBGMCU_APB_FZ2 register  ************/
#define DBGMCU_APB_FZ2_DBG_TIM1_STOP_Pos                  (11U)
#define DBGMCU_APB_FZ2_DBG_TIM1_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ2_DBG_TIM1_STOP_Pos)  /*!< 0x00000800 */
#define DBGMCU_APB_FZ2_DBG_TIM1_STOP                      DBGMCU_APB_FZ2_DBG_TIM1_STOP_Msk
#define DBGMCU_APB_FZ2_DBG_TIM15_STOP_Pos                 (16U)
#define DBGMCU_APB_FZ2_DBG_TIM15_STOP_Msk                 (0x1UL << DBGMCU_APB_FZ2_DBG_TIM15_STOP_Pos) /*!< 0x00010000 */
#define DBGMCU_APB_FZ2_DBG_TIM15_STOP                     DBGMCU_APB_FZ2_DBG_TIM15_STOP_Msk
#define DBGMCU_APB_FZ2_DBG_TIM16_STOP_Pos                 (17U)
#define DBGMCU_APB_FZ2_DBG_TIM16_STOP_Msk                 (0x1UL << DBGMCU_APB_FZ2_DBG_TIM16_STOP_Pos) /*!< 0x00020000 */
#define DBGMCU_APB_FZ2_DBG_TIM16_STOP                     DBGMCU_APB_FZ2_DBG_TIM16_STOP_Msk
#define DBGMCU_APB_FZ2_DBG_TIM17_STOP_Pos                 (18U)
#define DBGMCU_APB_FZ2_DBG_TIM17_STOP_Msk                 (0x1UL << DBGMCU_APB_FZ2_DBG_TIM17_STOP_Pos) /*!< 0x00040000 */
#define DBGMCU_APB_FZ2_DBG_TIM17_STOP                     DBGMCU_APB_FZ2_DBG_TIM17_STOP_Msk
#define DBGMCU_APB_FZ2_DBG_PWM_STOP_Pos                   (19U)
#define DBGMCU_APB_FZ2_DBG_PWM_STOP_Msk                   (0x1UL << DBGMCU_APB_FZ2_DBG_PWM_STOP_Pos)   /*!< 0x00080000 */
#define DBGMCU_APB_FZ2_DBG_PWM_STOP                       DBGMCU_APB_FZ2_DBG_PWM_STOP_Msk

/********************************************************************************************************************/
/********************************* DMA ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for DMA_ISR register **********************************************/
#define DMA_ISR_TCIF1_Pos                         (0U)
#define DMA_ISR_TCIF1_Msk                         (0x1UL<<DMA_ISR_TCIF1_Pos)                        /*!< 0x00000001 */
#define DMA_ISR_TCIF1                             DMA_ISR_TCIF1_Msk                                 /*!< Transfer Complete Flag for Channel 1 */
#define DMA_ISR_BTCIF1_Pos                        (1U)
#define DMA_ISR_BTCIF1_Msk                        (0x1UL<<DMA_ISR_BTCIF1_Pos)                       /*!< 0x00000002 */
#define DMA_ISR_BTCIF1                            DMA_ISR_BTCIF1_Msk                                /*!< Block Transfer Complete Flag for Channel 1 */
#define DMA_ISR_HBTIF1_Pos                        (2U)
#define DMA_ISR_HBTIF1_Msk                        (0x1UL<<DMA_ISR_HBTIF1_Pos)                       /*!< 0x00000004 */
#define DMA_ISR_HBTIF1                            DMA_ISR_HBTIF1_Msk                                /*!< Half Block Transfer Complete Flag for Channel 1 */
#define DMA_ISR_TEIF1_Pos                         (3U)
#define DMA_ISR_TEIF1_Msk                         (0x1UL<<DMA_ISR_TEIF1_Pos)                        /*!< 0x00000008 */
#define DMA_ISR_TEIF1                             DMA_ISR_TEIF1_Msk                                 /*!< Transfer Error Flag for Channel 1 */
#define DMA_ISR_TCIF2_Pos                         (4U)
#define DMA_ISR_TCIF2_Msk                         (0x1UL<<DMA_ISR_TCIF2_Pos)                        /*!< 0x00000010 */
#define DMA_ISR_TCIF2                             DMA_ISR_TCIF2_Msk                                 /*!< Transfer Complete Flag for Channel 2 */
#define DMA_ISR_BTCIF2_Pos                        (5U)
#define DMA_ISR_BTCIF2_Msk                        (0x1UL<<DMA_ISR_BTCIF2_Pos)                       /*!< 0x00000020 */
#define DMA_ISR_BTCIF2                            DMA_ISR_BTCIF2_Msk                                /*!< Block Transfer Complete Flag for Channel 2 */
#define DMA_ISR_HBTIF2_Pos                        (6U)
#define DMA_ISR_HBTIF2_Msk                        (0x1UL<<DMA_ISR_HBTIF2_Pos)                       /*!< 0x00000040 */
#define DMA_ISR_HBTIF2                            DMA_ISR_HBTIF2_Msk                                /*!< Half Block Transfer Complete Flag for Channel 2 */
#define DMA_ISR_TEIF2_Pos                         (7U)
#define DMA_ISR_TEIF2_Msk                         (0x1UL<<DMA_ISR_TEIF2_Pos)                        /*!< 0x00000080 */
#define DMA_ISR_TEIF2                             DMA_ISR_TEIF2_Msk                                 /*!< Transfer Error Flag for Channel 2 */
#define DMA_ISR_TCIF3_Pos                         (8U)
#define DMA_ISR_TCIF3_Msk                         (0x1UL<<DMA_ISR_TCIF3_Pos)                        /*!< 0x00000100 */
#define DMA_ISR_TCIF3                             DMA_ISR_TCIF3_Msk                                 /*!< Transfer Complete Flag for Channel 3 */
#define DMA_ISR_BTCIF3_Pos                        (9U)
#define DMA_ISR_BTCIF3_Msk                        (0x1UL<<DMA_ISR_BTCIF3_Pos)                       /*!< 0x00000200 */
#define DMA_ISR_BTCIF3                            DMA_ISR_BTCIF3_Msk                                /*!< Block Transfer Complete Flag for Channel 3 */
#define DMA_ISR_HBTIF3_Pos                        (10U)
#define DMA_ISR_HBTIF3_Msk                        (0x1UL<<DMA_ISR_HBTIF3_Pos)                       /*!< 0x00000400 */
#define DMA_ISR_HBTIF3                            DMA_ISR_HBTIF3_Msk                                /*!< Half Block Transfer Complete Flag for Channel 3 */
#define DMA_ISR_TEIF3_Pos                         (11U)
#define DMA_ISR_TEIF3_Msk                         (0x1UL<<DMA_ISR_TEIF3_Pos)                        /*!< 0x00000800 */
#define DMA_ISR_TEIF3                             DMA_ISR_TEIF3_Msk                                 /*!< Transfer Error Flag for Channel 3 */
#define DMA_ISR_TCIF4_Pos                         (12U)
#define DMA_ISR_TCIF4_Msk                         (0x1UL<<DMA_ISR_TCIF4_Pos)                        /*!< 0x00001000 */
#define DMA_ISR_TCIF4                             DMA_ISR_TCIF4_Msk                                 /*!< Transfer Complete Flag for Channel 4 */
#define DMA_ISR_BTCIF4_Pos                        (13U)
#define DMA_ISR_BTCIF4_Msk                        (0x1UL<<DMA_ISR_BTCIF4_Pos)                       /*!< 0x00002000 */
#define DMA_ISR_BTCIF4                            DMA_ISR_BTCIF4_Msk                                /*!< Block Transfer Complete Flag for Channel 4 */
#define DMA_ISR_HBTIF4_Pos                        (14U)
#define DMA_ISR_HBTIF4_Msk                        (0x1UL<<DMA_ISR_HBTIF4_Pos)                       /*!< 0x00004000 */
#define DMA_ISR_HBTIF4                            DMA_ISR_HBTIF4_Msk                                /*!< Half Block Transfer Complete Flag for Channel 4 */
#define DMA_ISR_TEIF4_Pos                         (15U)
#define DMA_ISR_TEIF4_Msk                         (0x1UL<<DMA_ISR_TEIF4_Pos)                        /*!< 0x00008000 */
#define DMA_ISR_TEIF4                             DMA_ISR_TEIF4_Msk                                 /*!< Transfer Error Flag for Channel 4 */
#define DMA_ISR_TCIF5_Pos                         (16U)
#define DMA_ISR_TCIF5_Msk                         (0x1UL<<DMA_ISR_TCIF5_Pos)                        /*!< 0x00010000 */
#define DMA_ISR_TCIF5                             DMA_ISR_TCIF5_Msk                                 /*!< Transfer Complete Flag for Channel 5 */
#define DMA_ISR_BTCIF5_Pos                        (17U)
#define DMA_ISR_BTCIF5_Msk                        (0x1UL<<DMA_ISR_BTCIF5_Pos)                       /*!< 0x00020000 */
#define DMA_ISR_BTCIF5                            DMA_ISR_BTCIF5_Msk                                /*!< Block Transfer Complete Flag for Channel 5 */
#define DMA_ISR_HBTIF5_Pos                        (18U)
#define DMA_ISR_HBTIF5_Msk                        (0x1UL<<DMA_ISR_HBTIF5_Pos)                       /*!< 0x00040000 */
#define DMA_ISR_HBTIF5                            DMA_ISR_HBTIF5_Msk                                /*!< Half Block Transfer Complete Flag for Channel 5 */
#define DMA_ISR_TEIF5_Pos                         (19U)
#define DMA_ISR_TEIF5_Msk                         (0x1UL<<DMA_ISR_TEIF5_Pos)                        /*!< 0x00080000 */
#define DMA_ISR_TEIF5                             DMA_ISR_TEIF5_Msk                                 /*!< Transfer Error Flag for Channel 5 */
#define DMA_ISR_TCIF6_Pos                         (20U)
#define DMA_ISR_TCIF6_Msk                         (0x1UL<<DMA_ISR_TCIF6_Pos)                        /*!< 0x00100000 */
#define DMA_ISR_TCIF6                             DMA_ISR_TCIF6_Msk                                 /*!< Transfer Complete Flag for Channel 6 */
#define DMA_ISR_BTCIF6_Pos                        (21U)
#define DMA_ISR_BTCIF6_Msk                        (0x1UL<<DMA_ISR_BTCIF6_Pos)                       /*!< 0x00200000 */
#define DMA_ISR_BTCIF6                            DMA_ISR_BTCIF6_Msk                                /*!< Block Transfer Complete Flag for Channel 6 */
#define DMA_ISR_HBTIF6_Pos                        (22U)
#define DMA_ISR_HBTIF6_Msk                        (0x1UL<<DMA_ISR_HBTIF6_Pos)                       /*!< 0x00400000 */
#define DMA_ISR_HBTIF6                            DMA_ISR_HBTIF6_Msk                                /*!< Half Block Transfer Complete Flag for Channel 6 */
#define DMA_ISR_TEIF6_Pos                         (23U)
#define DMA_ISR_TEIF6_Msk                         (0x1UL<<DMA_ISR_TEIF6_Pos)                        /*!< 0x00800000 */
#define DMA_ISR_TEIF6                             DMA_ISR_TEIF6_Msk                                 /*!< Transfer Error Flag for Channel 6 */
#define DMA_ISR_TCIF7_Pos                         (24U)
#define DMA_ISR_TCIF7_Msk                         (0x1UL<<DMA_ISR_TCIF7_Pos)                        /*!< 0x01000000 */
#define DMA_ISR_TCIF7                             DMA_ISR_TCIF7_Msk                                 /*!< Transfer Complete Flag for Channel 7 */
#define DMA_ISR_BTCIF7_Pos                        (25U)
#define DMA_ISR_BTCIF7_Msk                        (0x1UL<<DMA_ISR_BTCIF7_Pos)                       /*!< 0x02000000 */
#define DMA_ISR_BTCIF7                            DMA_ISR_BTCIF7_Msk                                /*!< Block Transfer Complete Flag for Channel 7 */
#define DMA_ISR_HBTIF7_Pos                        (26U)
#define DMA_ISR_HBTIF7_Msk                        (0x1UL<<DMA_ISR_HBTIF7_Pos)                       /*!< 0x04000000 */
#define DMA_ISR_HBTIF7                            DMA_ISR_HBTIF7_Msk                                /*!< Half Block Transfer Complete Flag for Channel 7 */
#define DMA_ISR_TEIF7_Pos                         (27U)
#define DMA_ISR_TEIF7_Msk                         (0x1UL<<DMA_ISR_TEIF7_Pos)                        /*!< 0x08000000 */
#define DMA_ISR_TEIF7                             DMA_ISR_TEIF7_Msk                                 /*!< Transfer Error Flag for Channel 7 */

/********************************* Bit definition for DMA_IFCR register *********************************************/
#define DMA_IFCR_CTCIF1_Pos                       (0U)
#define DMA_IFCR_CTCIF1_Msk                       (0x1UL<<DMA_IFCR_CTCIF1_Pos)                      /*!< 0x00000001 */
#define DMA_IFCR_CTCIF1                           DMA_IFCR_CTCIF1_Msk                               /*!< Transfer Complete Flag Clear for Channel 1 */
#define DMA_IFCR_CBTCIF1_Pos                      (1U)
#define DMA_IFCR_CBTCIF1_Msk                      (0x1UL<<DMA_IFCR_CBTCIF1_Pos)                     /*!< 0x00000002 */
#define DMA_IFCR_CBTCIF1                          DMA_IFCR_CBTCIF1_Msk                              /*!< Block Transfer Complete Flag Clear for Channel 1 */
#define DMA_IFCR_CHBTIF1_Pos                      (2U)
#define DMA_IFCR_CHBTIF1_Msk                      (0x1UL<<DMA_IFCR_CHBTIF1_Pos)                     /*!< 0x00000004 */
#define DMA_IFCR_CHBTIF1                          DMA_IFCR_CHBTIF1_Msk                              /*!< Half Block Transfer Complete Flag Clear for Channel 1 */
#define DMA_IFCR_CTEIF1_Pos                       (3U)
#define DMA_IFCR_CTEIF1_Msk                       (0x1UL<<DMA_IFCR_CTEIF1_Pos)                      /*!< 0x00000008 */
#define DMA_IFCR_CTEIF1                           DMA_IFCR_CTEIF1_Msk                               /*!< Transfer Error Flag Clear for Channel 1 */
#define DMA_IFCR_CTCIF2_Pos                       (4U)
#define DMA_IFCR_CTCIF2_Msk                       (0x1UL<<DMA_IFCR_CTCIF2_Pos)                      /*!< 0x00000010 */
#define DMA_IFCR_CTCIF2                           DMA_IFCR_CTCIF2_Msk                               /*!< Transfer Complete Flag Clear for Channel 2 */
#define DMA_IFCR_CBTCIF2_Pos                      (5U)
#define DMA_IFCR_CBTCIF2_Msk                      (0x1UL<<DMA_IFCR_CBTCIF2_Pos)                     /*!< 0x00000020 */
#define DMA_IFCR_CBTCIF2                          DMA_IFCR_CBTCIF2_Msk                              /*!< Block Transfer Complete Flag Clear for Channel 2 */
#define DMA_IFCR_CHBTIF2_Pos                      (6U)
#define DMA_IFCR_CHBTIF2_Msk                      (0x1UL<<DMA_IFCR_CHBTIF2_Pos)                     /*!< 0x00000040 */
#define DMA_IFCR_CHBTIF2                          DMA_IFCR_CHBTIF2_Msk                              /*!< Half Block Transfer Complete Flag Clear for Channel 2 */
#define DMA_IFCR_CTEIF2_Pos                       (7U)
#define DMA_IFCR_CTEIF2_Msk                       (0x1UL<<DMA_IFCR_CTEIF2_Pos)                      /*!< 0x00000080 */
#define DMA_IFCR_CTEIF2                           DMA_IFCR_CTEIF2_Msk                               /*!< Transfer Error Flag Clear for Channel 2 */
#define DMA_IFCR_CTCIF3_Pos                       (8U)
#define DMA_IFCR_CTCIF3_Msk                       (0x1UL<<DMA_IFCR_CTCIF3_Pos)                      /*!< 0x00000100 */
#define DMA_IFCR_CTCIF3                           DMA_IFCR_CTCIF3_Msk                               /*!< Transfer Complete Flag Clear for Channel 3 */
#define DMA_IFCR_CBTCIF3_Pos                      (9U)
#define DMA_IFCR_CBTCIF3_Msk                      (0x1UL<<DMA_IFCR_CBTCIF3_Pos)                     /*!< 0x00000200 */
#define DMA_IFCR_CBTCIF3                          DMA_IFCR_CBTCIF3_Msk                              /*!< Block Transfer Complete Flag Clear for Channel 3 */
#define DMA_IFCR_CHBTIF3_Pos                      (10U)
#define DMA_IFCR_CHBTIF3_Msk                      (0x1UL<<DMA_IFCR_CHBTIF3_Pos)                     /*!< 0x00000400 */
#define DMA_IFCR_CHBTIF3                          DMA_IFCR_CHBTIF3_Msk                              /*!< Half Block Transfer Complete Flag Clear for Channel 3 */
#define DMA_IFCR_CTEIF3_Pos                       (11U)
#define DMA_IFCR_CTEIF3_Msk                       (0x1UL<<DMA_IFCR_CTEIF3_Pos)                      /*!< 0x00000800 */
#define DMA_IFCR_CTEIF3                           DMA_IFCR_CTEIF3_Msk                               /*!< Transfer Error Flag Clear for Channel 3 */
#define DMA_IFCR_CTCIF4_Pos                       (12U)
#define DMA_IFCR_CTCIF4_Msk                       (0x1UL<<DMA_IFCR_CTCIF4_Pos)                      /*!< 0x00001000 */
#define DMA_IFCR_CTCIF4                           DMA_IFCR_CTCIF4_Msk                               /*!< Transfer Complete Flag Clear for Channel 4 */
#define DMA_IFCR_CBTCIF4_Pos                      (13U)
#define DMA_IFCR_CBTCIF4_Msk                      (0x1UL<<DMA_IFCR_CBTCIF4_Pos)                     /*!< 0x00002000 */
#define DMA_IFCR_CBTCIF4                          DMA_IFCR_CBTCIF4_Msk                              /*!< Block Transfer Complete Flag Clear for Channel 4 */
#define DMA_IFCR_CHBTIF4_Pos                      (14U)
#define DMA_IFCR_CHBTIF4_Msk                      (0x1UL<<DMA_IFCR_CHBTIF4_Pos)                     /*!< 0x00004000 */
#define DMA_IFCR_CHBTIF4                          DMA_IFCR_CHBTIF4_Msk                              /*!< Half Block Transfer Complete Flag Clear for Channel 4 */
#define DMA_IFCR_CTEIF4_Pos                       (15U)
#define DMA_IFCR_CTEIF4_Msk                       (0x1UL<<DMA_IFCR_CTEIF4_Pos)                      /*!< 0x00008000 */
#define DMA_IFCR_CTEIF4                           DMA_IFCR_CTEIF4_Msk                               /*!< Transfer Error Flag Clear for Channel 4 */
#define DMA_IFCR_CTCIF5_Pos                       (16U)
#define DMA_IFCR_CTCIF5_Msk                       (0x1UL<<DMA_IFCR_CTCIF5_Pos)                      /*!< 0x00010000 */
#define DMA_IFCR_CTCIF5                           DMA_IFCR_CTCIF5_Msk                               /*!< Transfer Complete Flag Clear for Channel 5 */
#define DMA_IFCR_CBTCIF5_Pos                      (17U)
#define DMA_IFCR_CBTCIF5_Msk                      (0x1UL<<DMA_IFCR_CBTCIF5_Pos)                     /*!< 0x00020000 */
#define DMA_IFCR_CBTCIF5                          DMA_IFCR_CBTCIF5_Msk                              /*!< Block Transfer Complete Flag Clear for Channel 5 */
#define DMA_IFCR_CHBTIF5_Pos                      (18U)
#define DMA_IFCR_CHBTIF5_Msk                      (0x1UL<<DMA_IFCR_CHBTIF5_Pos)                     /*!< 0x00040000 */
#define DMA_IFCR_CHBTIF5                          DMA_IFCR_CHBTIF5_Msk                              /*!< Half Block Transfer Complete Flag Clear for Channel 5 */
#define DMA_IFCR_CTEIF5_Pos                       (19U)
#define DMA_IFCR_CTEIF5_Msk                       (0x1UL<<DMA_IFCR_CTEIF5_Pos)                      /*!< 0x00080000 */
#define DMA_IFCR_CTEIF5                           DMA_IFCR_CTEIF5_Msk                               /*!< Transfer Error Flag Clear for Channel 5 */
#define DMA_IFCR_CTCIF6_Pos                       (20U)
#define DMA_IFCR_CTCIF6_Msk                       (0x1UL<<DMA_IFCR_CTCIF6_Pos)                      /*!< 0x00100000 */
#define DMA_IFCR_CTCIF6                           DMA_IFCR_CTCIF6_Msk                               /*!< Transfer Complete Flag Clear for Channel 6 */
#define DMA_IFCR_CBTCIF6_Pos                      (21U)
#define DMA_IFCR_CBTCIF6_Msk                      (0x1UL<<DMA_IFCR_CBTCIF6_Pos)                     /*!< 0x00200000 */
#define DMA_IFCR_CBTCIF6                          DMA_IFCR_CBTCIF6_Msk                              /*!< Block Transfer Complete Flag Clear for Channel 6 */
#define DMA_IFCR_CHBTIF6_Pos                      (22U)
#define DMA_IFCR_CHBTIF6_Msk                      (0x1UL<<DMA_IFCR_CHBTIF6_Pos)                     /*!< 0x00400000 */
#define DMA_IFCR_CHBTIF6                          DMA_IFCR_CHBTIF6_Msk                              /*!< Half Block Transfer Complete Flag Clear for Channel 6 */
#define DMA_IFCR_CTEIF6_Pos                       (23U)
#define DMA_IFCR_CTEIF6_Msk                       (0x1UL<<DMA_IFCR_CTEIF6_Pos)                      /*!< 0x00800000 */
#define DMA_IFCR_CTEIF6                           DMA_IFCR_CTEIF6_Msk                               /*!< Transfer Error Flag Clear for Channel 6 */
#define DMA_IFCR_CTCIF7_Pos                       (24U)
#define DMA_IFCR_CTCIF7_Msk                       (0x1UL<<DMA_IFCR_CTCIF7_Pos)                      /*!< 0x01000000 */
#define DMA_IFCR_CTCIF7                           DMA_IFCR_CTCIF7_Msk                               /*!< Transfer Complete Flag Clear for Channel 7 */
#define DMA_IFCR_CBTCIF7_Pos                      (25U)
#define DMA_IFCR_CBTCIF7_Msk                      (0x1UL<<DMA_IFCR_CBTCIF7_Pos)                     /*!< 0x02000000 */
#define DMA_IFCR_CBTCIF7                          DMA_IFCR_CBTCIF7_Msk                              /*!< Block Transfer Complete Flag Clear for Channel 7 */
#define DMA_IFCR_CHBTIF7_Pos                      (26U)
#define DMA_IFCR_CHBTIF7_Msk                      (0x1UL<<DMA_IFCR_CHBTIF7_Pos)                     /*!< 0x04000000 */
#define DMA_IFCR_CHBTIF7                          DMA_IFCR_CHBTIF7_Msk                              /*!< Half Block Transfer Complete Flag Clear for Channel 7 */
#define DMA_IFCR_CTEIF7_Pos                       (27U)
#define DMA_IFCR_CTEIF7_Msk                       (0x1UL<<DMA_IFCR_CTEIF7_Pos)                      /*!< 0x08000000 */
#define DMA_IFCR_CTEIF7                           DMA_IFCR_CTEIF7_Msk                               /*!< Transfer Error Flag Clear for Channel 7 */

/********************************* Bit definition for DMA_CCR register *********************************************/
#define DMA_CCR_EN_Pos                           (0U)
#define DMA_CCR_EN_Msk                           (0x1UL<<DMA_CCR_EN_Pos)                          /*!< 0x00000001 */
#define DMA_CCR_EN                               DMA_CCR_EN_Msk                                   /*!< Channel Enable */
#define DMA_CCR_TCIE_Pos                         (1U)
#define DMA_CCR_TCIE_Msk                         (0x1UL<<DMA_CCR_TCIE_Pos)                        /*!< 0x00000002 */
#define DMA_CCR_TCIE                             DMA_CCR_TCIE_Msk                                 /*!< Transfer Complete Interrupt Enable */
#define DMA_CCR_BTCIE_Pos                        (2U)
#define DMA_CCR_BTCIE_Msk                        (0x1UL<<DMA_CCR_BTCIE_Pos)                       /*!< 0x00000004 */
#define DMA_CCR_BTCIE                            DMA_CCR_BTCIE_Msk                                /*!< Block Transfer Complete Interrupt Enable */
#define DMA_CCR_HBTIE_Pos                        (3U)
#define DMA_CCR_HBTIE_Msk                        (0x1UL<<DMA_CCR_HBTIE_Pos)                       /*!< 0x00000008 */
#define DMA_CCR_HBTIE                            DMA_CCR_HBTIE_Msk                                /*!< Half Block Transfer Complete Interrupt Enable */
#define DMA_CCR_TEIE_Pos                         (4U)
#define DMA_CCR_TEIE_Msk                         (0x1UL<<DMA_CCR_TEIE_Pos)                        /*!< 0x00000010 */
#define DMA_CCR_TEIE                             DMA_CCR_TEIE_Msk                                 /*!< Transfer Error Interrupt Enable */
#define DMA_CCR_DIR_Pos                          (5U)
#define DMA_CCR_DIR_Msk                          (0x1UL<<DMA_CCR_DIR_Pos)                         /*!< 0x00000020 */
#define DMA_CCR_DIR                              DMA_CCR_DIR_Msk                                  /*!< Data Transfer Direction */
#define DMA_CCR_CIRC_Pos                         (6U)
#define DMA_CCR_CIRC_Msk                         (0x1UL<<DMA_CCR_CIRC_Pos)                        /*!< 0x00000040 */
#define DMA_CCR_CIRC                             DMA_CCR_CIRC_Msk                                 /*!< Circular Mode */
#define DMA_CCR_TRANST_Pos                       (7U)
#define DMA_CCR_TRANST_Msk                       (0x1UL<<DMA_CCR_TRANST_Pos)                      /*!< 0x00000080 */
#define DMA_CCR_TRANST                           DMA_CCR_TRANST_Msk                               /*!< Transfer Type */
#define DMA_CCR_PINC_Pos                         (8U)
#define DMA_CCR_PINC_Msk                         (0x3UL<<DMA_CCR_PINC_Pos)                        /*!< 0x00000300 */
#define DMA_CCR_PINC                             DMA_CCR_PINC_Msk                                 /*!< Peripheral Increment Mode */
#define DMA_CCR_PINC_0                           (0x1UL<<DMA_CCR_PINC_Pos)                        /*!< 0x00000100 */
#define DMA_CCR_PINC_1                           (0x2UL<<DMA_CCR_PINC_Pos)                        /*!< 0x00000200 */
#define DMA_CCR_MINC_Pos                         (10U)
#define DMA_CCR_MINC_Msk                         (0x3UL<<DMA_CCR_MINC_Pos)                        /*!< 0x00000C00 */
#define DMA_CCR_MINC                             DMA_CCR_MINC_Msk                                 /*!< Memory Increment Mode */
#define DMA_CCR_MINC_0                           (0x1UL<<DMA_CCR_MINC_Pos)                        /*!< 0x00000400 */
#define DMA_CCR_MINC_1                           (0x2UL<<DMA_CCR_MINC_Pos)                        /*!< 0x00000800 */
#define DMA_CCR_PSIZE_Pos                        (12U)
#define DMA_CCR_PSIZE_Msk                        (0x3UL<<DMA_CCR_PSIZE_Pos)                       /*!< 0x00003000 */
#define DMA_CCR_PSIZE                            DMA_CCR_PSIZE_Msk                                /*!< Peripheral Size */
#define DMA_CCR_PSIZE_0                          (0x1UL<<DMA_CCR_PSIZE_Pos)                       /*!< 0x00001000 */
#define DMA_CCR_PSIZE_1                          (0x2UL<<DMA_CCR_PSIZE_Pos)                       /*!< 0x00002000 */
#define DMA_CCR_MSIZE_Pos                        (14U)
#define DMA_CCR_MSIZE_Msk                        (0x3UL<<DMA_CCR_MSIZE_Pos)                       /*!< 0x0000C000 */
#define DMA_CCR_MSIZE                            DMA_CCR_MSIZE_Msk                                /*!< Memory Size */
#define DMA_CCR_MSIZE_0                          (0x1UL<<DMA_CCR_MSIZE_Pos)                       /*!< 0x00004000 */
#define DMA_CCR_MSIZE_1                          (0x2UL<<DMA_CCR_MSIZE_Pos)                       /*!< 0x00008000 */
#define DMA_CCR_PL_Pos                           (16U)
#define DMA_CCR_PL_Msk                           (0x7UL<<DMA_CCR_PL_Pos)                          /*!< 0x00070000 */
#define DMA_CCR_PL                               DMA_CCR_PL_Msk                                   /*!< Priority Level */
#define DMA_CCR_PL_0                             (0x1UL<<DMA_CCR_PL_Pos)                          /*!< 0x00010000 */
#define DMA_CCR_PL_1                             (0x2UL<<DMA_CCR_PL_Pos)                          /*!< 0x00020000 */
#define DMA_CCR_PL_2                             (0x4UL<<DMA_CCR_PL_Pos)                          /*!< 0x00040000 */
#define DMA_CCR_MEM2MEM_Pos                      (19U)
#define DMA_CCR_MEM2MEM_Msk                      (0x1UL<<DMA_CCR_MEM2MEM_Pos)                     /*!< 0x00080000 */
#define DMA_CCR_MEM2MEM                          DMA_CCR_MEM2MEM_Msk                              /*!< Memory-to-memory Mode */
#define DMA_CCR_PNORLD_Pos                       (20U)
#define DMA_CCR_PNORLD_Msk                       (0x1UL<<DMA_CCR_PNORLD_Pos)                      /*!< 0x00100000 */
#define DMA_CCR_PNORLD                           DMA_CCR_PNORLD_Msk                               /*!< Peripheral No Reload */
#define DMA_CCR_MNORLD_Pos                       (21U)
#define DMA_CCR_MNORLD_Msk                       (0x1UL<<DMA_CCR_MNORLD_Pos)                      /*!< 0x00200000 */
#define DMA_CCR_MNORLD                           DMA_CCR_MNORLD_Msk                               /*!< Memory No Reload */
#define DMA_CCR_BTCSUSP_Pos                      (22U)
#define DMA_CCR_BTCSUSP_Msk                      (0x1UL<<DMA_CCR_BTCSUSP_Pos)                     /*!< 0x00400000 */
#define DMA_CCR_BTCSUSP                          DMA_CCR_BTCSUSP_Msk                              /*!< Suspend in Block Transfer Complete Interrupt */
#define DMA_CCR_M2MARB_Pos                       (23U)
#define DMA_CCR_M2MARB_Msk                       (0x1UL<<DMA_CCR_M2MARB_Pos)                      /*!< 0x00800000 */
#define DMA_CCR_M2MARB                           DMA_CCR_M2MARB_Msk                               /*!< Memory-to-memory Mode Arbitration */

/********************************* Bit definition for DMA_CNDTR register *******************************************/
#define DMA_CNDTR_NDT_Pos                        (0U)
#define DMA_CNDTR_NDT_Msk                        (0xFFFFUL<<DMA_CNDTR_NDT_Pos)                    /*!< 0x0000FFFF */
#define DMA_CNDTR_NDT                            DMA_CNDTR_NDT_Msk                                /*!< Number of Data to Transfer */

/********************************* Bit definition for DMA_CPAR register ********************************************/
#define DMA_CPAR_PA_Pos                          (0U)
#define DMA_CPAR_PA_Msk                          (0xFFFFFFFFUL<<DMA_CPAR_PA_Pos)                  /*!< 0xFFFFFFFF */
#define DMA_CPAR_PA                              DMA_CPAR_PA_Msk                                  /*!< Peripheral Address */

/********************************* Bit definition for DMA_CMAR register ********************************************/
#define DMA_CMAR_MA_Pos                          (0U)
#define DMA_CMAR_MA_Msk                          (0xFFFFFFFFUL<<DMA_CMAR_MA_Pos)                  /*!< 0xFFFFFFFF */
#define DMA_CMAR_MA                              DMA_CMAR_MA_Msk                                  /*!< Memory Address */

/********************************* Bit definition for DMA_CCCFGR register ******************************************/
#define DMA_CCCFGR_NBT_Pos                       (0U)
#define DMA_CCCFGR_NBT_Msk                       (0xFFUL<<DMA_CCCFGR_NBT_Pos)                     /*!< 0x000000FF */
#define DMA_CCCFGR_NBT                           DMA_CCCFGR_NBT_Msk                               /*!< Number of Block to Loop Transfer */
#define DMA_CCCFGR_NDTL_Pos                      (16U)
#define DMA_CCCFGR_NDTL_Msk                      (0xFFFFUL<<DMA_CCCFGR_NDTL_Pos)                  /*!< 0xFFFF0000 */
#define DMA_CCCFGR_NDTL                          DMA_CCCFGR_NDTL_Msk                              /*!< Number of Data to Transfer Last Loop */

/********************************************************************************************************************/
/********************************* EXTI *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for EXTI_RTSR register ********************************************/
#define EXTI_RTSR_RT0_Pos                         (0U)
#define EXTI_RTSR_RT0_Msk                         (0x1UL<<EXTI_RTSR_RT0_Pos)                        /*!< 0x00000001 */
#define EXTI_RTSR_RT0                             EXTI_RTSR_RT0_Msk                                 
#define EXTI_RTSR_RT1_Pos                         (1U)
#define EXTI_RTSR_RT1_Msk                         (0x1UL<<EXTI_RTSR_RT1_Pos)                        /*!< 0x00000002 */
#define EXTI_RTSR_RT1                             EXTI_RTSR_RT1_Msk                                 
#define EXTI_RTSR_RT2_Pos                         (2U)
#define EXTI_RTSR_RT2_Msk                         (0x1UL<<EXTI_RTSR_RT2_Pos)                        /*!< 0x00000004 */
#define EXTI_RTSR_RT2                             EXTI_RTSR_RT2_Msk                                 
#define EXTI_RTSR_RT3_Pos                         (3U)
#define EXTI_RTSR_RT3_Msk                         (0x1UL<<EXTI_RTSR_RT3_Pos)                        /*!< 0x00000008 */
#define EXTI_RTSR_RT3                             EXTI_RTSR_RT3_Msk                                 
#define EXTI_RTSR_RT4_Pos                         (4U)
#define EXTI_RTSR_RT4_Msk                         (0x1UL<<EXTI_RTSR_RT4_Pos)                        /*!< 0x00000010 */
#define EXTI_RTSR_RT4                             EXTI_RTSR_RT4_Msk                                 
#define EXTI_RTSR_RT5_Pos                         (5U)
#define EXTI_RTSR_RT5_Msk                         (0x1UL<<EXTI_RTSR_RT5_Pos)                        /*!< 0x00000020 */
#define EXTI_RTSR_RT5                             EXTI_RTSR_RT5_Msk                                 
#define EXTI_RTSR_RT6_Pos                         (6U)
#define EXTI_RTSR_RT6_Msk                         (0x1UL<<EXTI_RTSR_RT6_Pos)                        /*!< 0x00000040 */
#define EXTI_RTSR_RT6                             EXTI_RTSR_RT6_Msk                                 
#define EXTI_RTSR_RT7_Pos                         (7U)
#define EXTI_RTSR_RT7_Msk                         (0x1UL<<EXTI_RTSR_RT7_Pos)                        /*!< 0x00000080 */
#define EXTI_RTSR_RT7                             EXTI_RTSR_RT7_Msk                                 
#define EXTI_RTSR_RT8_Pos                         (8U)
#define EXTI_RTSR_RT8_Msk                         (0x1UL<<EXTI_RTSR_RT8_Pos)                        /*!< 0x00000100 */
#define EXTI_RTSR_RT8                             EXTI_RTSR_RT8_Msk                                 
#define EXTI_RTSR_RT9_Pos                         (9U)
#define EXTI_RTSR_RT9_Msk                         (0x1UL<<EXTI_RTSR_RT9_Pos)                        /*!< 0x00000200 */
#define EXTI_RTSR_RT9                             EXTI_RTSR_RT9_Msk                                 
#define EXTI_RTSR_RT10_Pos                        (10U)
#define EXTI_RTSR_RT10_Msk                        (0x1UL<<EXTI_RTSR_RT10_Pos)                       /*!< 0x00000400 */
#define EXTI_RTSR_RT10                            EXTI_RTSR_RT10_Msk                                
#define EXTI_RTSR_RT11_Pos                        (11U)
#define EXTI_RTSR_RT11_Msk                        (0x1UL<<EXTI_RTSR_RT11_Pos)                       /*!< 0x00000800 */
#define EXTI_RTSR_RT11                            EXTI_RTSR_RT11_Msk                                
#define EXTI_RTSR_RT12_Pos                        (12U)
#define EXTI_RTSR_RT12_Msk                        (0x1UL<<EXTI_RTSR_RT12_Pos)                       /*!< 0x00001000 */
#define EXTI_RTSR_RT12                            EXTI_RTSR_RT12_Msk                                
#define EXTI_RTSR_RT13_Pos                        (13U)
#define EXTI_RTSR_RT13_Msk                        (0x1UL<<EXTI_RTSR_RT13_Pos)                       /*!< 0x00002000 */
#define EXTI_RTSR_RT13                            EXTI_RTSR_RT13_Msk                                
#define EXTI_RTSR_RT14_Pos                        (14U)
#define EXTI_RTSR_RT14_Msk                        (0x1UL<<EXTI_RTSR_RT14_Pos)                       /*!< 0x00004000 */
#define EXTI_RTSR_RT14                            EXTI_RTSR_RT14_Msk                                
#define EXTI_RTSR_RT15_Pos                        (15U)
#define EXTI_RTSR_RT15_Msk                        (0x1UL<<EXTI_RTSR_RT15_Pos)                       /*!< 0x00008000 */
#define EXTI_RTSR_RT15                            EXTI_RTSR_RT15_Msk                                
#define EXTI_RTSR_RT16_Pos                        (16U)
#define EXTI_RTSR_RT16_Msk                        (0x1UL<<EXTI_RTSR_RT16_Pos)                       /*!< 0x00010000 */
#define EXTI_RTSR_RT16                            EXTI_RTSR_RT16_Msk                                
#define EXTI_RTSR_RT17_Pos                        (17U)
#define EXTI_RTSR_RT17_Msk                        (0x1UL<<EXTI_RTSR_RT17_Pos)                       /*!< 0x00020000 */
#define EXTI_RTSR_RT17                            EXTI_RTSR_RT17_Msk                                
#define EXTI_RTSR_RT18_Pos                        (18U)
#define EXTI_RTSR_RT18_Msk                        (0x1UL<<EXTI_RTSR_RT18_Pos)                       /*!< 0x00040000 */
#define EXTI_RTSR_RT18                            EXTI_RTSR_RT18_Msk                                
#define EXTI_RTSR_RT19_Pos                        (19U)
#define EXTI_RTSR_RT19_Msk                        (0x1UL<<EXTI_RTSR_RT19_Pos)                       /*!< 0x00080000 */
#define EXTI_RTSR_RT19                            EXTI_RTSR_RT19_Msk                                

/********************************* Bit definition for EXTI_FTSR register ********************************************/
#define EXTI_FTSR_FT0_Pos                         (0U)
#define EXTI_FTSR_FT0_Msk                         (0x1UL<<EXTI_FTSR_FT0_Pos)                        /*!< 0x00000001 */
#define EXTI_FTSR_FT0                             EXTI_FTSR_FT0_Msk                                 
#define EXTI_FTSR_FT1_Pos                         (1U)
#define EXTI_FTSR_FT1_Msk                         (0x1UL<<EXTI_FTSR_FT1_Pos)                        /*!< 0x00000002 */
#define EXTI_FTSR_FT1                             EXTI_FTSR_FT1_Msk                                 
#define EXTI_FTSR_FT2_Pos                         (2U)
#define EXTI_FTSR_FT2_Msk                         (0x1UL<<EXTI_FTSR_FT2_Pos)                        /*!< 0x00000004 */
#define EXTI_FTSR_FT2                             EXTI_FTSR_FT2_Msk                                 
#define EXTI_FTSR_FT3_Pos                         (3U)
#define EXTI_FTSR_FT3_Msk                         (0x1UL<<EXTI_FTSR_FT3_Pos)                        /*!< 0x00000008 */
#define EXTI_FTSR_FT3                             EXTI_FTSR_FT3_Msk                                 
#define EXTI_FTSR_FT4_Pos                         (4U)
#define EXTI_FTSR_FT4_Msk                         (0x1UL<<EXTI_FTSR_FT4_Pos)                        /*!< 0x00000010 */
#define EXTI_FTSR_FT4                             EXTI_FTSR_FT4_Msk                                 
#define EXTI_FTSR_FT5_Pos                         (5U)
#define EXTI_FTSR_FT5_Msk                         (0x1UL<<EXTI_FTSR_FT5_Pos)                        /*!< 0x00000020 */
#define EXTI_FTSR_FT5                             EXTI_FTSR_FT5_Msk                                 
#define EXTI_FTSR_FT6_Pos                         (6U)
#define EXTI_FTSR_FT6_Msk                         (0x1UL<<EXTI_FTSR_FT6_Pos)                        /*!< 0x00000040 */
#define EXTI_FTSR_FT6                             EXTI_FTSR_FT6_Msk                                 
#define EXTI_FTSR_FT7_Pos                         (7U)
#define EXTI_FTSR_FT7_Msk                         (0x1UL<<EXTI_FTSR_FT7_Pos)                        /*!< 0x00000080 */
#define EXTI_FTSR_FT7                             EXTI_FTSR_FT7_Msk                                 
#define EXTI_FTSR_FT8_Pos                         (8U)
#define EXTI_FTSR_FT8_Msk                         (0x1UL<<EXTI_FTSR_FT8_Pos)                        /*!< 0x00000100 */
#define EXTI_FTSR_FT8                             EXTI_FTSR_FT8_Msk                                 
#define EXTI_FTSR_FT9_Pos                         (9U)
#define EXTI_FTSR_FT9_Msk                         (0x1UL<<EXTI_FTSR_FT9_Pos)                        /*!< 0x00000200 */
#define EXTI_FTSR_FT9                             EXTI_FTSR_FT9_Msk                                 
#define EXTI_FTSR_FT10_Pos                        (10U)
#define EXTI_FTSR_FT10_Msk                        (0x1UL<<EXTI_FTSR_FT10_Pos)                       /*!< 0x00000400 */
#define EXTI_FTSR_FT10                            EXTI_FTSR_FT10_Msk                                
#define EXTI_FTSR_FT11_Pos                        (11U)
#define EXTI_FTSR_FT11_Msk                        (0x1UL<<EXTI_FTSR_FT11_Pos)                       /*!< 0x00000800 */
#define EXTI_FTSR_FT11                            EXTI_FTSR_FT11_Msk                                
#define EXTI_FTSR_FT12_Pos                        (12U)
#define EXTI_FTSR_FT12_Msk                        (0x1UL<<EXTI_FTSR_FT12_Pos)                       /*!< 0x00001000 */
#define EXTI_FTSR_FT12                            EXTI_FTSR_FT12_Msk                                
#define EXTI_FTSR_FT13_Pos                        (13U)
#define EXTI_FTSR_FT13_Msk                        (0x1UL<<EXTI_FTSR_FT13_Pos)                       /*!< 0x00002000 */
#define EXTI_FTSR_FT13                            EXTI_FTSR_FT13_Msk                                
#define EXTI_FTSR_FT14_Pos                        (14U)
#define EXTI_FTSR_FT14_Msk                        (0x1UL<<EXTI_FTSR_FT14_Pos)                       /*!< 0x00004000 */
#define EXTI_FTSR_FT14                            EXTI_FTSR_FT14_Msk                                
#define EXTI_FTSR_FT15_Pos                        (15U)
#define EXTI_FTSR_FT15_Msk                        (0x1UL<<EXTI_FTSR_FT15_Pos)                       /*!< 0x00008000 */
#define EXTI_FTSR_FT15                            EXTI_FTSR_FT15_Msk                                
#define EXTI_FTSR_FT16_Pos                        (16U)
#define EXTI_FTSR_FT16_Msk                        (0x1UL<<EXTI_FTSR_FT16_Pos)                       /*!< 0x00010000 */
#define EXTI_FTSR_FT16                            EXTI_FTSR_FT16_Msk                                
#define EXTI_FTSR_FT17_Pos                        (17U)
#define EXTI_FTSR_FT17_Msk                        (0x1UL<<EXTI_FTSR_FT17_Pos)                       /*!< 0x00020000 */
#define EXTI_FTSR_FT17                            EXTI_FTSR_FT17_Msk                                
#define EXTI_FTSR_FT18_Pos                        (18U)
#define EXTI_FTSR_FT18_Msk                        (0x1UL<<EXTI_FTSR_FT18_Pos)                       /*!< 0x00040000 */
#define EXTI_FTSR_FT18                            EXTI_FTSR_FT18_Msk                                
#define EXTI_FTSR_FT19_Pos                        (19U)
#define EXTI_FTSR_FT19_Msk                        (0x1UL<<EXTI_FTSR_FT19_Pos)                       /*!< 0x00080000 */
#define EXTI_FTSR_FT19                            EXTI_FTSR_FT19_Msk                                

/********************************* Bit definition for EXTI_SWIER register *******************************************/
#define EXTI_SWIER_SWIE0_Pos                      (0U)
#define EXTI_SWIER_SWIE0_Msk                      (0x1UL<<EXTI_SWIER_SWIE0_Pos)                     /*!< 0x00000001 */
#define EXTI_SWIER_SWIE0                          EXTI_SWIER_SWIE0_Msk                              
#define EXTI_SWIER_SWIE1_Pos                      (1U)
#define EXTI_SWIER_SWIE1_Msk                      (0x1UL<<EXTI_SWIER_SWIE1_Pos)                     /*!< 0x00000002 */
#define EXTI_SWIER_SWIE1                          EXTI_SWIER_SWIE1_Msk                              
#define EXTI_SWIER_SWIE2_Pos                      (2U)
#define EXTI_SWIER_SWIE2_Msk                      (0x1UL<<EXTI_SWIER_SWIE2_Pos)                     /*!< 0x00000004 */
#define EXTI_SWIER_SWIE2                          EXTI_SWIER_SWIE2_Msk                              
#define EXTI_SWIER_SWIE3_Pos                      (3U)
#define EXTI_SWIER_SWIE3_Msk                      (0x1UL<<EXTI_SWIER_SWIE3_Pos)                     /*!< 0x00000008 */
#define EXTI_SWIER_SWIE3                          EXTI_SWIER_SWIE3_Msk                              
#define EXTI_SWIER_SWIE4_Pos                      (4U)
#define EXTI_SWIER_SWIE4_Msk                      (0x1UL<<EXTI_SWIER_SWIE4_Pos)                     /*!< 0x00000010 */
#define EXTI_SWIER_SWIE4                          EXTI_SWIER_SWIE4_Msk                              
#define EXTI_SWIER_SWIE5_Pos                      (5U)
#define EXTI_SWIER_SWIE5_Msk                      (0x1UL<<EXTI_SWIER_SWIE5_Pos)                     /*!< 0x00000020 */
#define EXTI_SWIER_SWIE5                          EXTI_SWIER_SWIE5_Msk                              
#define EXTI_SWIER_SWIE6_Pos                      (6U)
#define EXTI_SWIER_SWIE6_Msk                      (0x1UL<<EXTI_SWIER_SWIE6_Pos)                     /*!< 0x00000040 */
#define EXTI_SWIER_SWIE6                          EXTI_SWIER_SWIE6_Msk                              
#define EXTI_SWIER_SWIE7_Pos                      (7U)
#define EXTI_SWIER_SWIE7_Msk                      (0x1UL<<EXTI_SWIER_SWIE7_Pos)                     /*!< 0x00000080 */
#define EXTI_SWIER_SWIE7                          EXTI_SWIER_SWIE7_Msk                              
#define EXTI_SWIER_SWIE8_Pos                      (8U)
#define EXTI_SWIER_SWIE8_Msk                      (0x1UL<<EXTI_SWIER_SWIE8_Pos)                     /*!< 0x00000100 */
#define EXTI_SWIER_SWIE8                          EXTI_SWIER_SWIE8_Msk                              
#define EXTI_SWIER_SWIE9_Pos                      (9U)
#define EXTI_SWIER_SWIE9_Msk                      (0x1UL<<EXTI_SWIER_SWIE9_Pos)                     /*!< 0x00000200 */
#define EXTI_SWIER_SWIE9                          EXTI_SWIER_SWIE9_Msk                              
#define EXTI_SWIER_SWIE10_Pos                     (10U)
#define EXTI_SWIER_SWIE10_Msk                     (0x1UL<<EXTI_SWIER_SWIE10_Pos)                    /*!< 0x00000400 */
#define EXTI_SWIER_SWIE10                         EXTI_SWIER_SWIE10_Msk                             
#define EXTI_SWIER_SWIE11_Pos                     (11U)
#define EXTI_SWIER_SWIE11_Msk                     (0x1UL<<EXTI_SWIER_SWIE11_Pos)                    /*!< 0x00000800 */
#define EXTI_SWIER_SWIE11                         EXTI_SWIER_SWIE11_Msk                             
#define EXTI_SWIER_SWIE12_Pos                     (12U)
#define EXTI_SWIER_SWIE12_Msk                     (0x1UL<<EXTI_SWIER_SWIE12_Pos)                    /*!< 0x00001000 */
#define EXTI_SWIER_SWIE12                         EXTI_SWIER_SWIE12_Msk                             
#define EXTI_SWIER_SWIE13_Pos                     (13U)
#define EXTI_SWIER_SWIE13_Msk                     (0x1UL<<EXTI_SWIER_SWIE13_Pos)                    /*!< 0x00002000 */
#define EXTI_SWIER_SWIE13                         EXTI_SWIER_SWIE13_Msk                             
#define EXTI_SWIER_SWIE14_Pos                     (14U)
#define EXTI_SWIER_SWIE14_Msk                     (0x1UL<<EXTI_SWIER_SWIE14_Pos)                    /*!< 0x00004000 */
#define EXTI_SWIER_SWIE14                         EXTI_SWIER_SWIE14_Msk                             
#define EXTI_SWIER_SWIE15_Pos                     (15U)
#define EXTI_SWIER_SWIE15_Msk                     (0x1UL<<EXTI_SWIER_SWIE15_Pos)                    /*!< 0x00008000 */
#define EXTI_SWIER_SWIE15                         EXTI_SWIER_SWIE15_Msk                             
#define EXTI_SWIER_SWIE16_Pos                     (16U)
#define EXTI_SWIER_SWIE16_Msk                     (0x1UL<<EXTI_SWIER_SWIE16_Pos)                    /*!< 0x00010000 */
#define EXTI_SWIER_SWIE16                         EXTI_SWIER_SWIE16_Msk                             
#define EXTI_SWIER_SWIE17_Pos                     (17U)
#define EXTI_SWIER_SWIE17_Msk                     (0x1UL<<EXTI_SWIER_SWIE17_Pos)                    /*!< 0x00020000 */
#define EXTI_SWIER_SWIE17                         EXTI_SWIER_SWIE17_Msk                             
#define EXTI_SWIER_SWIE18_Pos                     (18U)
#define EXTI_SWIER_SWIE18_Msk                     (0x1UL<<EXTI_SWIER_SWIE18_Pos)                    /*!< 0x00040000 */
#define EXTI_SWIER_SWIE18                         EXTI_SWIER_SWIE18_Msk                             
#define EXTI_SWIER_SWIE19_Pos                     (19U)
#define EXTI_SWIER_SWIE19_Msk                     (0x1UL<<EXTI_SWIER_SWIE19_Pos)                    /*!< 0x00080000 */
#define EXTI_SWIER_SWIE19                         EXTI_SWIER_SWIE19_Msk                             

/********************************* Bit definition for EXTI_PR register **********************************************/
#define EXTI_PR_PR0_Pos                           (0U)
#define EXTI_PR_PR0_Msk                           (0x1UL<<EXTI_PR_PR0_Pos)                          /*!< 0x00000001 */
#define EXTI_PR_PR0                               EXTI_PR_PR0_Msk                                   
#define EXTI_PR_PR1_Pos                           (1U)
#define EXTI_PR_PR1_Msk                           (0x1UL<<EXTI_PR_PR1_Pos)                          /*!< 0x00000002 */
#define EXTI_PR_PR1                               EXTI_PR_PR1_Msk                                   
#define EXTI_PR_PR2_Pos                           (2U)
#define EXTI_PR_PR2_Msk                           (0x1UL<<EXTI_PR_PR2_Pos)                          /*!< 0x00000004 */
#define EXTI_PR_PR2                               EXTI_PR_PR2_Msk                                   
#define EXTI_PR_PR3_Pos                           (3U)
#define EXTI_PR_PR3_Msk                           (0x1UL<<EXTI_PR_PR3_Pos)                          /*!< 0x00000008 */
#define EXTI_PR_PR3                               EXTI_PR_PR3_Msk                                   
#define EXTI_PR_PR4_Pos                           (4U)
#define EXTI_PR_PR4_Msk                           (0x1UL<<EXTI_PR_PR4_Pos)                          /*!< 0x00000010 */
#define EXTI_PR_PR4                               EXTI_PR_PR4_Msk                                   
#define EXTI_PR_PR5_Pos                           (5U)
#define EXTI_PR_PR5_Msk                           (0x1UL<<EXTI_PR_PR5_Pos)                          /*!< 0x00000020 */
#define EXTI_PR_PR5                               EXTI_PR_PR5_Msk                                   
#define EXTI_PR_PR6_Pos                           (6U)
#define EXTI_PR_PR6_Msk                           (0x1UL<<EXTI_PR_PR6_Pos)                          /*!< 0x00000040 */
#define EXTI_PR_PR6                               EXTI_PR_PR6_Msk                                   
#define EXTI_PR_PR7_Pos                           (7U)
#define EXTI_PR_PR7_Msk                           (0x1UL<<EXTI_PR_PR7_Pos)                          /*!< 0x00000080 */
#define EXTI_PR_PR7                               EXTI_PR_PR7_Msk                                   
#define EXTI_PR_PR8_Pos                           (8U)
#define EXTI_PR_PR8_Msk                           (0x1UL<<EXTI_PR_PR8_Pos)                          /*!< 0x00000100 */
#define EXTI_PR_PR8                               EXTI_PR_PR8_Msk                                   
#define EXTI_PR_PR9_Pos                           (9U)
#define EXTI_PR_PR9_Msk                           (0x1UL<<EXTI_PR_PR9_Pos)                          /*!< 0x00000200 */
#define EXTI_PR_PR9                               EXTI_PR_PR9_Msk                                   
#define EXTI_PR_PR10_Pos                          (10U)
#define EXTI_PR_PR10_Msk                          (0x1UL<<EXTI_PR_PR10_Pos)                         /*!< 0x00000400 */
#define EXTI_PR_PR10                              EXTI_PR_PR10_Msk                                  
#define EXTI_PR_PR11_Pos                          (11U)
#define EXTI_PR_PR11_Msk                          (0x1UL<<EXTI_PR_PR11_Pos)                         /*!< 0x00000800 */
#define EXTI_PR_PR11                              EXTI_PR_PR11_Msk                                  
#define EXTI_PR_PR12_Pos                          (12U)
#define EXTI_PR_PR12_Msk                          (0x1UL<<EXTI_PR_PR12_Pos)                         /*!< 0x00001000 */
#define EXTI_PR_PR12                              EXTI_PR_PR12_Msk                                  
#define EXTI_PR_PR13_Pos                          (13U)
#define EXTI_PR_PR13_Msk                          (0x1UL<<EXTI_PR_PR13_Pos)                         /*!< 0x00002000 */
#define EXTI_PR_PR13                              EXTI_PR_PR13_Msk                                  
#define EXTI_PR_PR14_Pos                          (14U)
#define EXTI_PR_PR14_Msk                          (0x1UL<<EXTI_PR_PR14_Pos)                         /*!< 0x00004000 */
#define EXTI_PR_PR14                              EXTI_PR_PR14_Msk                                  
#define EXTI_PR_PR15_Pos                          (15U)
#define EXTI_PR_PR15_Msk                          (0x1UL<<EXTI_PR_PR15_Pos)                         /*!< 0x00008000 */
#define EXTI_PR_PR15                              EXTI_PR_PR15_Msk                                  
#define EXTI_PR_PR16_Pos                          (16U)
#define EXTI_PR_PR16_Msk                          (0x1UL<<EXTI_PR_PR16_Pos)                         /*!< 0x00010000 */
#define EXTI_PR_PR16                              EXTI_PR_PR16_Msk                                  
#define EXTI_PR_PR17_Pos                          (17U)
#define EXTI_PR_PR17_Msk                          (0x1UL<<EXTI_PR_PR17_Pos)                         /*!< 0x00020000 */
#define EXTI_PR_PR17                              EXTI_PR_PR17_Msk                                  
#define EXTI_PR_PR18_Pos                          (18U)
#define EXTI_PR_PR18_Msk                          (0x1UL<<EXTI_PR_PR18_Pos)                         /*!< 0x00040000 */
#define EXTI_PR_PR18                              EXTI_PR_PR18_Msk                                  
#define EXTI_PR_PR19_Pos                          (19U)
#define EXTI_PR_PR19_Msk                          (0x1UL<<EXTI_PR_PR19_Pos)                         /*!< 0x00080000 */
#define EXTI_PR_PR19                              EXTI_PR_PR19_Msk                                  

/********************************* Bit definition for EXTI_IOSEL1 register ******************************************/
#define EXTI_IOSEL1_EXTI0SEL_Pos                  (0U)
#define EXTI_IOSEL1_EXTI0SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI0SEL_Pos)                 /*!< 0x00000003 */
#define EXTI_IOSEL1_EXTI0SEL                      EXTI_IOSEL1_EXTI0SEL_Msk
#define EXTI_IOSEL1_EXTI0SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI0SEL_Pos)                 /*!< 0x00000001 */
#define EXTI_IOSEL1_EXTI0SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI0SEL_Pos)                 /*!< 0x00000002 */
#define EXTI_IOSEL1_EXTI1SEL_Pos                  (4U)
#define EXTI_IOSEL1_EXTI1SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI1SEL_Pos)                 /*!< 0x00000030 */
#define EXTI_IOSEL1_EXTI1SEL                      EXTI_IOSEL1_EXTI1SEL_Msk
#define EXTI_IOSEL1_EXTI1SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI1SEL_Pos)                 /*!< 0x00000010 */
#define EXTI_IOSEL1_EXTI1SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI1SEL_Pos)                 /*!< 0x00000020 */
#define EXTI_IOSEL1_EXTI2SEL_Pos                  (8U)
#define EXTI_IOSEL1_EXTI2SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI2SEL_Pos)                 /*!< 0x00000300 */
#define EXTI_IOSEL1_EXTI2SEL                      EXTI_IOSEL1_EXTI2SEL_Msk
#define EXTI_IOSEL1_EXTI2SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI2SEL_Pos)                 /*!< 0x00000100 */
#define EXTI_IOSEL1_EXTI2SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI2SEL_Pos)                 /*!< 0x00000200 */
#define EXTI_IOSEL1_EXTI3SEL_Pos                  (12U)
#define EXTI_IOSEL1_EXTI3SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI3SEL_Pos)                 /*!< 0x00003000 */
#define EXTI_IOSEL1_EXTI3SEL                      EXTI_IOSEL1_EXTI3SEL_Msk
#define EXTI_IOSEL1_EXTI3SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI3SEL_Pos)                 /*!< 0x00001000 */
#define EXTI_IOSEL1_EXTI3SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI3SEL_Pos)                 /*!< 0x00002000 */
#define EXTI_IOSEL1_EXTI4SEL_Pos                  (16U)
#define EXTI_IOSEL1_EXTI4SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI4SEL_Pos)                 /*!< 0x00030000 */
#define EXTI_IOSEL1_EXTI4SEL                      EXTI_IOSEL1_EXTI4SEL_Msk
#define EXTI_IOSEL1_EXTI4SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI4SEL_Pos)                 /*!< 0x00010000 */
#define EXTI_IOSEL1_EXTI4SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI4SEL_Pos)                 /*!< 0x00020000 */
#define EXTI_IOSEL1_EXTI5SEL_Pos                  (20U)
#define EXTI_IOSEL1_EXTI5SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI5SEL_Pos)                 /*!< 0x00300000 */
#define EXTI_IOSEL1_EXTI5SEL                      EXTI_IOSEL1_EXTI5SEL_Msk
#define EXTI_IOSEL1_EXTI5SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI5SEL_Pos)                 /*!< 0x00100000 */
#define EXTI_IOSEL1_EXTI5SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI5SEL_Pos)                 /*!< 0x00200000 */
#define EXTI_IOSEL1_EXTI6SEL_Pos                  (24U)
#define EXTI_IOSEL1_EXTI6SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI6SEL_Pos)                 /*!< 0x03000000 */
#define EXTI_IOSEL1_EXTI6SEL                      EXTI_IOSEL1_EXTI6SEL_Msk
#define EXTI_IOSEL1_EXTI6SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI6SEL_Pos)                 /*!< 0x01000000 */
#define EXTI_IOSEL1_EXTI6SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI6SEL_Pos)                 /*!< 0x02000000 */
#define EXTI_IOSEL1_EXTI7SEL_Pos                  (28U)
#define EXTI_IOSEL1_EXTI7SEL_Msk                  (0x3UL<<EXTI_IOSEL1_EXTI7SEL_Pos)                 /*!< 0x30000000 */
#define EXTI_IOSEL1_EXTI7SEL                      EXTI_IOSEL1_EXTI7SEL_Msk
#define EXTI_IOSEL1_EXTI7SEL_0                    (0x1UL<<EXTI_IOSEL1_EXTI7SEL_Pos)                 /*!< 0x10000000 */
#define EXTI_IOSEL1_EXTI7SEL_1                    (0x2UL<<EXTI_IOSEL1_EXTI7SEL_Pos)                 /*!< 0x20000000 */

/********************************* Bit definition for EXTI_IOSEL2 register ******************************************/
#define EXTI_IOSEL2_EXTI8SEL_Pos                  (0U)
#define EXTI_IOSEL2_EXTI8SEL_Msk                  (0x3UL<<EXTI_IOSEL2_EXTI8SEL_Pos)                 /*!< 0x00000003 */
#define EXTI_IOSEL2_EXTI8SEL                      EXTI_IOSEL2_EXTI8SEL_Msk
#define EXTI_IOSEL2_EXTI8SEL_0                    (0x1UL<<EXTI_IOSEL2_EXTI8SEL_Pos)                 /*!< 0x00000001 */
#define EXTI_IOSEL2_EXTI8SEL_1                    (0x2UL<<EXTI_IOSEL2_EXTI8SEL_Pos)                 /*!< 0x00000002 */
#define EXTI_IOSEL2_EXTI9SEL_Pos                  (4U)
#define EXTI_IOSEL2_EXTI9SEL_Msk                  (0x3UL<<EXTI_IOSEL2_EXTI9SEL_Pos)                 /*!< 0x00000030 */
#define EXTI_IOSEL2_EXTI9SEL                      EXTI_IOSEL2_EXTI9SEL_Msk
#define EXTI_IOSEL2_EXTI9SEL_0                    (0x1UL<<EXTI_IOSEL2_EXTI9SEL_Pos)                 /*!< 0x00000010 */
#define EXTI_IOSEL2_EXTI9SEL_1                    (0x2UL<<EXTI_IOSEL2_EXTI9SEL_Pos)                 /*!< 0x00000020 */
#define EXTI_IOSEL2_EXTI10SEL_Pos                 (8U)
#define EXTI_IOSEL2_EXTI10SEL_Msk                 (0x3UL<<EXTI_IOSEL2_EXTI10SEL_Pos)                /*!< 0x00000300 */
#define EXTI_IOSEL2_EXTI10SEL                     EXTI_IOSEL2_EXTI10SEL_Msk
#define EXTI_IOSEL2_EXTI10SEL_0                   (0x1UL<<EXTI_IOSEL2_EXTI10SEL_Pos)                /*!< 0x00000100 */
#define EXTI_IOSEL2_EXTI10SEL_1                   (0x2UL<<EXTI_IOSEL2_EXTI10SEL_Pos)                /*!< 0x00000200 */
#define EXTI_IOSEL2_EXTI11SEL_Pos                 (12U)
#define EXTI_IOSEL2_EXTI11SEL_Msk                 (0x3UL<<EXTI_IOSEL2_EXTI11SEL_Pos)                /*!< 0x00003000 */
#define EXTI_IOSEL2_EXTI11SEL                     EXTI_IOSEL2_EXTI11SEL_Msk
#define EXTI_IOSEL2_EXTI11SEL_0                   (0x1UL<<EXTI_IOSEL2_EXTI11SEL_Pos)                /*!< 0x00001000 */
#define EXTI_IOSEL2_EXTI11SEL_1                   (0x2UL<<EXTI_IOSEL2_EXTI11SEL_Pos)                /*!< 0x00002000 */
#define EXTI_IOSEL2_EXTI12SEL_Pos                 (16U)
#define EXTI_IOSEL2_EXTI12SEL_Msk                 (0x3UL<<EXTI_IOSEL2_EXTI12SEL_Pos)                /*!< 0x00030000 */
#define EXTI_IOSEL2_EXTI12SEL                     EXTI_IOSEL2_EXTI12SEL_Msk
#define EXTI_IOSEL2_EXTI12SEL_0                   (0x1UL<<EXTI_IOSEL2_EXTI12SEL_Pos)                /*!< 0x00010000 */
#define EXTI_IOSEL2_EXTI12SEL_1                   (0x2UL<<EXTI_IOSEL2_EXTI12SEL_Pos)                /*!< 0x00020000 */
#define EXTI_IOSEL2_EXTI13SEL_Pos                 (20U)
#define EXTI_IOSEL2_EXTI13SEL_Msk                 (0x3UL<<EXTI_IOSEL2_EXTI13SEL_Pos)                /*!< 0x00300000 */
#define EXTI_IOSEL2_EXTI13SEL                     EXTI_IOSEL2_EXTI13SEL_Msk
#define EXTI_IOSEL2_EXTI13SEL_0                   (0x1UL<<EXTI_IOSEL2_EXTI13SEL_Pos)                /*!< 0x00100000 */
#define EXTI_IOSEL2_EXTI13SEL_1                   (0x2UL<<EXTI_IOSEL2_EXTI13SEL_Pos)                /*!< 0x00200000 */
#define EXTI_IOSEL2_EXTI14SEL_Pos                 (24U)
#define EXTI_IOSEL2_EXTI14SEL_Msk                 (0x3UL<<EXTI_IOSEL2_EXTI14SEL_Pos)                /*!< 0x03000000 */
#define EXTI_IOSEL2_EXTI14SEL                     EXTI_IOSEL2_EXTI14SEL_Msk
#define EXTI_IOSEL2_EXTI14SEL_0                   (0x1UL<<EXTI_IOSEL2_EXTI14SEL_Pos)                /*!< 0x01000000 */
#define EXTI_IOSEL2_EXTI14SEL_1                   (0x2UL<<EXTI_IOSEL2_EXTI14SEL_Pos)                /*!< 0x02000000 */
#define EXTI_IOSEL2_EXTI15SEL_Pos                 (28U)
#define EXTI_IOSEL2_EXTI15SEL_Msk                 (0x3UL<<EXTI_IOSEL2_EXTI15SEL_Pos)                /*!< 0x30000000 */
#define EXTI_IOSEL2_EXTI15SEL                     EXTI_IOSEL2_EXTI15SEL_Msk
#define EXTI_IOSEL2_EXTI15SEL_0                   (0x1UL<<EXTI_IOSEL2_EXTI15SEL_Pos)                /*!< 0x10000000 */
#define EXTI_IOSEL2_EXTI15SEL_1                   (0x2UL<<EXTI_IOSEL2_EXTI15SEL_Pos)                /*!< 0x20000000 */

/********************************* Bit definition for EXTI_IMR register *********************************************/
#define EXTI_IMR_IM0_Pos                          (0U)
#define EXTI_IMR_IM0_Msk                          (0x1UL<<EXTI_IMR_IM0_Pos)                         /*!< 0x00000001 */
#define EXTI_IMR_IM0                              EXTI_IMR_IM0_Msk                                  
#define EXTI_IMR_IM1_Pos                          (1U)
#define EXTI_IMR_IM1_Msk                          (0x1UL<<EXTI_IMR_IM1_Pos)                         /*!< 0x00000002 */
#define EXTI_IMR_IM1                              EXTI_IMR_IM1_Msk                                  
#define EXTI_IMR_IM2_Pos                          (2U)
#define EXTI_IMR_IM2_Msk                          (0x1UL<<EXTI_IMR_IM2_Pos)                         /*!< 0x00000004 */
#define EXTI_IMR_IM2                              EXTI_IMR_IM2_Msk                                  
#define EXTI_IMR_IM3_Pos                          (3U)
#define EXTI_IMR_IM3_Msk                          (0x1UL<<EXTI_IMR_IM3_Pos)                         /*!< 0x00000008 */
#define EXTI_IMR_IM3                              EXTI_IMR_IM3_Msk                                  
#define EXTI_IMR_IM4_Pos                          (4U)
#define EXTI_IMR_IM4_Msk                          (0x1UL<<EXTI_IMR_IM4_Pos)                         /*!< 0x00000010 */
#define EXTI_IMR_IM4                              EXTI_IMR_IM4_Msk                                  
#define EXTI_IMR_IM5_Pos                          (5U)
#define EXTI_IMR_IM5_Msk                          (0x1UL<<EXTI_IMR_IM5_Pos)                         /*!< 0x00000020 */
#define EXTI_IMR_IM5                              EXTI_IMR_IM5_Msk                                  
#define EXTI_IMR_IM6_Pos                          (6U)
#define EXTI_IMR_IM6_Msk                          (0x1UL<<EXTI_IMR_IM6_Pos)                         /*!< 0x00000040 */
#define EXTI_IMR_IM6                              EXTI_IMR_IM6_Msk                                  
#define EXTI_IMR_IM7_Pos                          (7U)
#define EXTI_IMR_IM7_Msk                          (0x1UL<<EXTI_IMR_IM7_Pos)                         /*!< 0x00000080 */
#define EXTI_IMR_IM7                              EXTI_IMR_IM7_Msk                                  
#define EXTI_IMR_IM8_Pos                          (8U)
#define EXTI_IMR_IM8_Msk                          (0x1UL<<EXTI_IMR_IM8_Pos)                         /*!< 0x00000100 */
#define EXTI_IMR_IM8                              EXTI_IMR_IM8_Msk                                  
#define EXTI_IMR_IM9_Pos                          (9U)
#define EXTI_IMR_IM9_Msk                          (0x1UL<<EXTI_IMR_IM9_Pos)                         /*!< 0x00000200 */
#define EXTI_IMR_IM9                              EXTI_IMR_IM9_Msk                                  
#define EXTI_IMR_IM10_Pos                         (10U)
#define EXTI_IMR_IM10_Msk                         (0x1UL<<EXTI_IMR_IM10_Pos)                        /*!< 0x00000400 */
#define EXTI_IMR_IM10                             EXTI_IMR_IM10_Msk                                 
#define EXTI_IMR_IM11_Pos                         (11U)
#define EXTI_IMR_IM11_Msk                         (0x1UL<<EXTI_IMR_IM11_Pos)                        /*!< 0x00000800 */
#define EXTI_IMR_IM11                             EXTI_IMR_IM11_Msk                                 
#define EXTI_IMR_IM12_Pos                         (12U)
#define EXTI_IMR_IM12_Msk                         (0x1UL<<EXTI_IMR_IM12_Pos)                        /*!< 0x00001000 */
#define EXTI_IMR_IM12                             EXTI_IMR_IM12_Msk                                 
#define EXTI_IMR_IM13_Pos                         (13U)
#define EXTI_IMR_IM13_Msk                         (0x1UL<<EXTI_IMR_IM13_Pos)                        /*!< 0x00002000 */
#define EXTI_IMR_IM13                             EXTI_IMR_IM13_Msk                                 
#define EXTI_IMR_IM14_Pos                         (14U)
#define EXTI_IMR_IM14_Msk                         (0x1UL<<EXTI_IMR_IM14_Pos)                        /*!< 0x00004000 */
#define EXTI_IMR_IM14                             EXTI_IMR_IM14_Msk                                 
#define EXTI_IMR_IM15_Pos                         (15U)
#define EXTI_IMR_IM15_Msk                         (0x1UL<<EXTI_IMR_IM15_Pos)                        /*!< 0x00008000 */
#define EXTI_IMR_IM15                             EXTI_IMR_IM15_Msk                                 
#define EXTI_IMR_IM16_Pos                         (16U)
#define EXTI_IMR_IM16_Msk                         (0x1UL<<EXTI_IMR_IM16_Pos)                        /*!< 0x00010000 */
#define EXTI_IMR_IM16                             EXTI_IMR_IM16_Msk                                 
#define EXTI_IMR_IM17_Pos                         (17U)
#define EXTI_IMR_IM17_Msk                         (0x1UL<<EXTI_IMR_IM17_Pos)                        /*!< 0x00020000 */
#define EXTI_IMR_IM17                             EXTI_IMR_IM17_Msk                                 
#define EXTI_IMR_IM18_Pos                         (18U)
#define EXTI_IMR_IM18_Msk                         (0x1UL<<EXTI_IMR_IM18_Pos)                        /*!< 0x00040000 */
#define EXTI_IMR_IM18                             EXTI_IMR_IM18_Msk                                 
#define EXTI_IMR_IM19_Pos                         (19U)
#define EXTI_IMR_IM19_Msk                         (0x1UL<<EXTI_IMR_IM19_Pos)                        /*!< 0x00080000 */
#define EXTI_IMR_IM19                             EXTI_IMR_IM19_Msk                                 
#define EXTI_IMR_IM20_Pos                         (20U)
#define EXTI_IMR_IM20_Msk                         (0x1UL<<EXTI_IMR_IM20_Pos)                        /*!< 0x00100000 */
#define EXTI_IMR_IM20                             EXTI_IMR_IM20_Msk                                 
#define EXTI_IMR_IM21_Pos                         (21U)
#define EXTI_IMR_IM21_Msk                         (0x1UL<<EXTI_IMR_IM21_Pos)                        /*!< 0x00200000 */
#define EXTI_IMR_IM21                             EXTI_IMR_IM21_Msk                                 
#define EXTI_IMR_IM22_Pos                         (22U)
#define EXTI_IMR_IM22_Msk                         (0x1UL<<EXTI_IMR_IM22_Pos)                        /*!< 0x00400000 */
#define EXTI_IMR_IM22                             EXTI_IMR_IM22_Msk                                 
#define EXTI_IMR_IM23_Pos                         (23U)
#define EXTI_IMR_IM23_Msk                         (0x1UL<<EXTI_IMR_IM23_Pos)                        /*!< 0x00800000 */
#define EXTI_IMR_IM23                             EXTI_IMR_IM23_Msk                                 
#define EXTI_IMR_IM24_Pos                         (24U)
#define EXTI_IMR_IM24_Msk                         (0x1UL<<EXTI_IMR_IM24_Pos)                        /*!< 0x01000000 */
#define EXTI_IMR_IM24                             EXTI_IMR_IM24_Msk                                 
#define EXTI_IMR_IM25_Pos                         (25U)
#define EXTI_IMR_IM25_Msk                         (0x1UL<<EXTI_IMR_IM25_Pos)                        /*!< 0x02000000 */
#define EXTI_IMR_IM25                             EXTI_IMR_IM25_Msk                                 
#define EXTI_IMR_IM26_Pos                         (26U)
#define EXTI_IMR_IM26_Msk                         (0x1UL<<EXTI_IMR_IM26_Pos)                        /*!< 0x04000000 */
#define EXTI_IMR_IM26                             EXTI_IMR_IM26_Msk                                 
#define EXTI_IMR_IM27_Pos                         (27U)
#define EXTI_IMR_IM27_Msk                         (0x1UL<<EXTI_IMR_IM27_Pos)                        /*!< 0x08000000 */
#define EXTI_IMR_IM27                             EXTI_IMR_IM27_Msk                                 
#define EXTI_IMR_IM28_Pos                         (28U)
#define EXTI_IMR_IM28_Msk                         (0x1UL<<EXTI_IMR_IM28_Pos)                        /*!< 0x10000000 */
#define EXTI_IMR_IM28                             EXTI_IMR_IM28_Msk                                 
#define EXTI_IMR_IM29_Pos                         (29U)
#define EXTI_IMR_IM29_Msk                         (0x1UL<<EXTI_IMR_IM29_Pos)                        /*!< 0x20000000 */
#define EXTI_IMR_IM29                             EXTI_IMR_IM29_Msk                                 

/********************************* Bit definition for EXTI_EMR register *********************************************/
#define EXTI_EMR_EM0_Pos                          (0U)
#define EXTI_EMR_EM0_Msk                          (0x1UL<<EXTI_EMR_EM0_Pos)                         /*!< 0x00000001 */
#define EXTI_EMR_EM0                              EXTI_EMR_EM0_Msk                                  
#define EXTI_EMR_EM1_Pos                          (1U)
#define EXTI_EMR_EM1_Msk                          (0x1UL<<EXTI_EMR_EM1_Pos)                         /*!< 0x00000002 */
#define EXTI_EMR_EM1                              EXTI_EMR_EM1_Msk                                  
#define EXTI_EMR_EM2_Pos                          (2U)
#define EXTI_EMR_EM2_Msk                          (0x1UL<<EXTI_EMR_EM2_Pos)                         /*!< 0x00000004 */
#define EXTI_EMR_EM2                              EXTI_EMR_EM2_Msk                                  
#define EXTI_EMR_EM3_Pos                          (3U)
#define EXTI_EMR_EM3_Msk                          (0x1UL<<EXTI_EMR_EM3_Pos)                         /*!< 0x00000008 */
#define EXTI_EMR_EM3                              EXTI_EMR_EM3_Msk                                  
#define EXTI_EMR_EM4_Pos                          (4U)
#define EXTI_EMR_EM4_Msk                          (0x1UL<<EXTI_EMR_EM4_Pos)                         /*!< 0x00000010 */
#define EXTI_EMR_EM4                              EXTI_EMR_EM4_Msk                                  
#define EXTI_EMR_EM5_Pos                          (5U)
#define EXTI_EMR_EM5_Msk                          (0x1UL<<EXTI_EMR_EM5_Pos)                         /*!< 0x00000020 */
#define EXTI_EMR_EM5                              EXTI_EMR_EM5_Msk                                  
#define EXTI_EMR_EM6_Pos                          (6U)
#define EXTI_EMR_EM6_Msk                          (0x1UL<<EXTI_EMR_EM6_Pos)                         /*!< 0x00000040 */
#define EXTI_EMR_EM6                              EXTI_EMR_EM6_Msk                                  
#define EXTI_EMR_EM7_Pos                          (7U)
#define EXTI_EMR_EM7_Msk                          (0x1UL<<EXTI_EMR_EM7_Pos)                         /*!< 0x00000080 */
#define EXTI_EMR_EM7                              EXTI_EMR_EM7_Msk                                  
#define EXTI_EMR_EM8_Pos                          (8U)
#define EXTI_EMR_EM8_Msk                          (0x1UL<<EXTI_EMR_EM8_Pos)                         /*!< 0x00000100 */
#define EXTI_EMR_EM8                              EXTI_EMR_EM8_Msk                                  
#define EXTI_EMR_EM9_Pos                          (9U)
#define EXTI_EMR_EM9_Msk                          (0x1UL<<EXTI_EMR_EM9_Pos)                         /*!< 0x00000200 */
#define EXTI_EMR_EM9                              EXTI_EMR_EM9_Msk                                  
#define EXTI_EMR_EM10_Pos                         (10U)
#define EXTI_EMR_EM10_Msk                         (0x1UL<<EXTI_EMR_EM10_Pos)                        /*!< 0x00000400 */
#define EXTI_EMR_EM10                             EXTI_EMR_EM10_Msk                                 
#define EXTI_EMR_EM11_Pos                         (11U)
#define EXTI_EMR_EM11_Msk                         (0x1UL<<EXTI_EMR_EM11_Pos)                        /*!< 0x00000800 */
#define EXTI_EMR_EM11                             EXTI_EMR_EM11_Msk                                 
#define EXTI_EMR_EM12_Pos                         (12U)
#define EXTI_EMR_EM12_Msk                         (0x1UL<<EXTI_EMR_EM12_Pos)                        /*!< 0x00001000 */
#define EXTI_EMR_EM12                             EXTI_EMR_EM12_Msk                                 
#define EXTI_EMR_EM13_Pos                         (13U)
#define EXTI_EMR_EM13_Msk                         (0x1UL<<EXTI_EMR_EM13_Pos)                        /*!< 0x00002000 */
#define EXTI_EMR_EM13                             EXTI_EMR_EM13_Msk                                 
#define EXTI_EMR_EM14_Pos                         (14U)
#define EXTI_EMR_EM14_Msk                         (0x1UL<<EXTI_EMR_EM14_Pos)                        /*!< 0x00004000 */
#define EXTI_EMR_EM14                             EXTI_EMR_EM14_Msk                                 
#define EXTI_EMR_EM15_Pos                         (15U)
#define EXTI_EMR_EM15_Msk                         (0x1UL<<EXTI_EMR_EM15_Pos)                        /*!< 0x00008000 */
#define EXTI_EMR_EM15                             EXTI_EMR_EM15_Msk                                 
#define EXTI_EMR_EM16_Pos                         (16U)
#define EXTI_EMR_EM16_Msk                         (0x1UL<<EXTI_EMR_EM16_Pos)                        /*!< 0x00010000 */
#define EXTI_EMR_EM16                             EXTI_EMR_EM16_Msk                                 
#define EXTI_EMR_EM17_Pos                         (17U)
#define EXTI_EMR_EM17_Msk                         (0x1UL<<EXTI_EMR_EM17_Pos)                        /*!< 0x00020000 */
#define EXTI_EMR_EM17                             EXTI_EMR_EM17_Msk                                 
#define EXTI_EMR_EM18_Pos                         (18U)
#define EXTI_EMR_EM18_Msk                         (0x1UL<<EXTI_EMR_EM18_Pos)                        /*!< 0x00040000 */
#define EXTI_EMR_EM18                             EXTI_EMR_EM18_Msk                                 
#define EXTI_EMR_EM19_Pos                         (19U)
#define EXTI_EMR_EM19_Msk                         (0x1UL<<EXTI_EMR_EM19_Pos)                        /*!< 0x00080000 */
#define EXTI_EMR_EM19                             EXTI_EMR_EM19_Msk                                 
#define EXTI_EMR_EM20_Pos                         (20U)
#define EXTI_EMR_EM20_Msk                         (0x1UL<<EXTI_EMR_EM20_Pos)                        /*!< 0x00100000 */
#define EXTI_EMR_EM20                             EXTI_EMR_EM20_Msk                                 
#define EXTI_EMR_EM21_Pos                         (21U)
#define EXTI_EMR_EM21_Msk                         (0x1UL<<EXTI_EMR_EM21_Pos)                        /*!< 0x00200000 */
#define EXTI_EMR_EM21                             EXTI_EMR_EM21_Msk                                 
#define EXTI_EMR_EM22_Pos                         (22U)
#define EXTI_EMR_EM22_Msk                         (0x1UL<<EXTI_EMR_EM22_Pos)                        /*!< 0x00400000 */
#define EXTI_EMR_EM22                             EXTI_EMR_EM22_Msk                                 
#define EXTI_EMR_EM23_Pos                         (23U)
#define EXTI_EMR_EM23_Msk                         (0x1UL<<EXTI_EMR_EM23_Pos)                        /*!< 0x00800000 */
#define EXTI_EMR_EM23                             EXTI_EMR_EM23_Msk                                 
#define EXTI_EMR_EM24_Pos                         (24U)
#define EXTI_EMR_EM24_Msk                         (0x1UL<<EXTI_EMR_EM24_Pos)                        /*!< 0x01000000 */
#define EXTI_EMR_EM24                             EXTI_EMR_EM24_Msk                                 
#define EXTI_EMR_EM25_Pos                         (25U)
#define EXTI_EMR_EM25_Msk                         (0x1UL<<EXTI_EMR_EM25_Pos)                        /*!< 0x02000000 */
#define EXTI_EMR_EM25                             EXTI_EMR_EM25_Msk                                 
#define EXTI_EMR_EM26_Pos                         (26U)
#define EXTI_EMR_EM26_Msk                         (0x1UL<<EXTI_EMR_EM26_Pos)                        /*!< 0x04000000 */
#define EXTI_EMR_EM26                             EXTI_EMR_EM26_Msk                                 
#define EXTI_EMR_EM27_Pos                         (27U)
#define EXTI_EMR_EM27_Msk                         (0x1UL<<EXTI_EMR_EM27_Pos)                        /*!< 0x08000000 */
#define EXTI_EMR_EM27                             EXTI_EMR_EM27_Msk                                 
#define EXTI_EMR_EM28_Pos                         (28U)
#define EXTI_EMR_EM28_Msk                         (0x1UL<<EXTI_EMR_EM28_Pos)                        /*!< 0x10000000 */
#define EXTI_EMR_EM28                             EXTI_EMR_EM28_Msk                                 
#define EXTI_EMR_EM29_Pos                         (29U)
#define EXTI_EMR_EM29_Msk                         (0x1UL<<EXTI_EMR_EM29_Pos)                        /*!< 0x20000000 */
#define EXTI_EMR_EM29                             EXTI_EMR_EM29_Msk

/********************************************************************************************************************/
/********************************* FMC ******************************************************************************/
/********************************************************************************************************************/
/******************  FLASH Keys  **********************************************/
#define FLASH_KEY1_Pos                            (0U)
#define FLASH_KEY1_Msk                            (0x45670123UL << FLASH_KEY1_Pos)                  /*!< 0x45670123 */
#define FLASH_KEY1                                FLASH_KEY1_Msk                                    /*!< Flash program erase key1 */
#define FLASH_KEY2_Pos                            (0U)
#define FLASH_KEY2_Msk                            (0xCDEF89ABUL << FLASH_KEY2_Pos)                  /*!< 0xCDEF89AB */
#define FLASH_KEY2                                FLASH_KEY2_Msk                                    /*!< Flash program erase key2: used with FLASH_PEKEY1
                                                                                                         to unlock the write access to the FPEC. */

#define FLASH_OPTKEY1_Pos                         (0U)
#define FLASH_OPTKEY1_Msk                         (0x08192A3BUL << FLASH_OPTKEY1_Pos)               /*!< 0x08192A3B */
#define FLASH_OPTKEY1                             FLASH_OPTKEY1_Msk                                 /*!< Flash option key1 */
#define FLASH_OPTKEY2_Pos                         (0U)
#define FLASH_OPTKEY2_Msk                         (0x4C5D6E7FUL << FLASH_OPTKEY2_Pos)               /*!< 0x4C5D6E7F */
#define FLASH_OPTKEY2                             FLASH_OPTKEY2_Msk                                 /*!< Flash option key2: used with FLASH_OPTKEY1 to
                                                                                                         unlock the write access to the option byte block */

/********************************* Bit definition for FLASH_ACR register ********************************************/
#define FLASH_ACR_LATENCY_Pos                     (0U)
#define FLASH_ACR_LATENCY_Msk                     (0x3UL<<FLASH_ACR_LATENCY_Pos)                    /*!< 0x00000003 */
#define FLASH_ACR_LATENCY                         FLASH_ACR_LATENCY_Msk                             /*!< Latency */
#define FLASH_ACR_LATENCY_0                       (0x1UL<<FLASH_ACR_LATENCY_Pos)                    /*!< 0x00000001 */
#define FLASH_ACR_LATENCY_1                       (0x2UL<<FLASH_ACR_LATENCY_Pos)                    /*!< 0x00000002 */
#define FLASH_ACR_PRFTEN_Pos                      (8U)
#define FLASH_ACR_PRFTEN_Msk                      (0x1UL<<FLASH_ACR_PRFTEN_Pos)                     /*!< 0x00000100 */
#define FLASH_ACR_PRFTEN                          FLASH_ACR_PRFTEN_Msk                              /*!< Prefect enable */
#define FLASH_ACR_ICEN_Pos                        (9U)
#define FLASH_ACR_ICEN_Msk                        (0x1UL<<FLASH_ACR_ICEN_Pos)                       /*!< 0x00000200 */
#define FLASH_ACR_ICEN                            FLASH_ACR_ICEN_Msk                                /*!< Instruction cache enable */
#define FLASH_ACR_DCEN_Pos                        (10U)
#define FLASH_ACR_DCEN_Msk                        (0x1UL<<FLASH_ACR_DCEN_Pos)                       /*!< 0x00000400 */
#define FLASH_ACR_DCEN                            FLASH_ACR_DCEN_Msk                                /*!< Data cache enable */

/********************************* Bit definition for FLASH_KEYR register *******************************************/
#define FLASH_KEYR_KEY_Pos                        (0U)
#define FLASH_KEYR_KEY_Msk                        (0xFFFFFFFFUL<<FLASH_KEYR_KEY_Pos)                /*!< 0xFFFFFFFF */
#define FLASH_KEYR_KEY                            FLASH_KEYR_KEY_Msk                                /*!< Flash CR key */

/********************************* Bit definition for FLASH_OPTKEYR register ****************************************/
#define FLASH_OPTKEYR_OPTKEY_Pos                  (0U)
#define FLASH_OPTKEYR_OPTKEY_Msk                  (0xFFFFFFFFUL<<FLASH_OPTKEYR_OPTKEY_Pos)          /*!< 0xFFFFFFFF */
#define FLASH_OPTKEYR_OPTKEY                      FLASH_OPTKEYR_OPTKEY_Msk                          /*!< Flash Option key */

/********************************* Bit definition for FLASH_SR register *********************************************/
#define FLASH_SR_EOP_Pos                          (0U)
#define FLASH_SR_EOP_Msk                          (0x1UL<<FLASH_SR_EOP_Pos)                         /*!< 0x00000001 */
#define FLASH_SR_EOP                              FLASH_SR_EOP_Msk                                  /*!< End of operation */
#define FLASH_SR_WRPERR_Pos                       (4U)
#define FLASH_SR_WRPERR_Msk                       (0x1UL<<FLASH_SR_WRPERR_Pos)                      /*!< 0x00000010 */
#define FLASH_SR_WRPERR                           FLASH_SR_WRPERR_Msk                               /*!< Write protection error */
#define FLASH_SR_RDERR0_Pos                       (11U)
#define FLASH_SR_RDERR0_Msk                       (0x1UL<<FLASH_SR_RDERR0_Pos)                      /*!< 0x00000800 */
#define FLASH_SR_RDERR0                           FLASH_SR_RDERR0_Msk                               /*!< Bank0 pcrop read error */
#define FLASH_SR_RDERR1_Pos                       (12U)
#define FLASH_SR_RDERR1_Msk                       (0x1UL<<FLASH_SR_RDERR1_Pos)                      /*!< 0x00001000 */
#define FLASH_SR_RDERR1                           FLASH_SR_RDERR1_Msk                               /*!< Bank1 pcrop read error */
#define FLASH_SR_USRLOCK_Pos                      (13U)
#define FLASH_SR_USRLOCK_Msk                      (0x1UL<<FLASH_SR_USRLOCK_Pos)                     /*!< 0x00002000 */
#define FLASH_SR_USRLOCK                          FLASH_SR_USRLOCK_Msk                              /*!< Userdata Lock  */
#define FLASH_SR_OPTVERR_Pos                      (15U)
#define FLASH_SR_OPTVERR_Msk                      (0x1UL<<FLASH_SR_OPTVERR_Pos)                     /*!< 0x00008000 */
#define FLASH_SR_OPTVERR                          FLASH_SR_OPTVERR_Msk                              /*!< Option and trimming bits loading validity error */
#define FLASH_SR_BSY0_Pos                         (16U)
#define FLASH_SR_BSY0_Msk                         (0x1UL<<FLASH_SR_BSY0_Pos)                        /*!< 0x00010000 */
#define FLASH_SR_BSY0                             FLASH_SR_BSY0_Msk                                 /*!< Bank0 Busy */
#define FLASH_SR_BSY1_Pos                         (17U)
#define FLASH_SR_BSY1_Msk                         (0x1UL<<FLASH_SR_BSY1_Pos)                        /*!< 0x00020000 */
#define FLASH_SR_BSY1                             FLASH_SR_BSY1_Msk                                 /*!< Bank1 Busy */

/********************************* Bit definition for FLASH_CR register *********************************************/
#define FLASH_CR_PG_Pos                           (0U)
#define FLASH_CR_PG_Msk                           (0x1UL<<FLASH_CR_PG_Pos)                          /*!< 0x00000001 */
#define FLASH_CR_PG                               FLASH_CR_PG_Msk                                   /*!< Page Program */
#define FLASH_CR_PER_Pos                          (1U)
#define FLASH_CR_PER_Msk                          (0x1UL<<FLASH_CR_PER_Pos)                         /*!< 0x00000002 */
#define FLASH_CR_PER                              FLASH_CR_PER_Msk                                  /*!< Page Erase */
#define FLASH_CR_MER0_Pos                         (2U)
#define FLASH_CR_MER0_Msk                         (0x1UL<<FLASH_CR_MER0_Pos)                        /*!< 0x00000004 */
#define FLASH_CR_MER0                             FLASH_CR_MER0_Msk                                 /*!< Bank 0 Mass Erase */
#define FLASH_CR_MER1_Pos                         (3U)
#define FLASH_CR_MER1_Msk                         (0x1UL<<FLASH_CR_MER1_Pos)                        /*!< 0x00000008 */
#define FLASH_CR_MER1                             FLASH_CR_MER1_Msk                                 /*!< Bank 1 Mass Erase */
#define FLASH_CR_UPG_Pos                          (4U)
#define FLASH_CR_UPG_Msk                          (0x1UL<<FLASH_CR_UPG_Pos)                         /*!< 0x00000010 */
#define FLASH_CR_UPG                              FLASH_CR_UPG_Msk                                  /*!< Userdata Program */
#define FLASH_CR_UPER_Pos                         (5U)
#define FLASH_CR_UPER_Msk                         (0x1UL<<FLASH_CR_UPER_Pos)                        /*!< 0x00000020 */
#define FLASH_CR_UPER                             FLASH_CR_UPER_Msk                                 /*!< Userdata Page Erase */
#define FLASH_CR_SER_Pos                          (11U)
#define FLASH_CR_SER_Msk                          (0x1UL<<FLASH_CR_SER_Pos)                         /*!< 0x00000800 */
#define FLASH_CR_SER                              FLASH_CR_SER_Msk                                  /*!< Sector Erase */
#define FLASH_CR_OPTSTRT_Pos                      (17U)
#define FLASH_CR_OPTSTRT_Msk                      (0x1UL<<FLASH_CR_OPTSTRT_Pos)                     /*!< 0x00020000 */
#define FLASH_CR_OPTSTRT                          FLASH_CR_OPTSTRT_Msk                              /*!< Option bytes Programming Start */
#define FLASH_CR_UPGSTRT_Pos                      (18U)
#define FLASH_CR_UPGSTRT_Msk                      (0x1UL<<FLASH_CR_UPGSTRT_Pos)                     /*!< 0x00040000 */
#define FLASH_CR_UPGSTRT                          FLASH_CR_UPGSTRT_Msk                              /*!< Userdata Programming Start */
#define FLASH_CR_PGSTRT_Pos                       (19U)
#define FLASH_CR_PGSTRT_Msk                       (0x1UL<<FLASH_CR_PGSTRT_Pos)                      /*!< 0x00080000 */
#define FLASH_CR_PGSTRT                           FLASH_CR_PGSTRT_Msk                               /*!< Programming Start */
#define FLASH_CR_RDERR0IE_Pos                     (22U)
#define FLASH_CR_RDERR0IE_Msk                     (0x1UL<<FLASH_CR_RDERR0IE_Pos)                    /*!< 0x00400000 */
#define FLASH_CR_RDERR0IE                         FLASH_CR_RDERR0IE_Msk                             /*!< Bank0 pcrop read error interrupt enable */
#define FLASH_CR_RDERR1IE_Pos                     (23U)
#define FLASH_CR_RDERR1IE_Msk                     (0x1UL<<FLASH_CR_RDERR1IE_Pos)                    /*!< 0x00800000 */
#define FLASH_CR_RDERR1IE                         FLASH_CR_RDERR1IE_Msk                             /*!< Bank1 pcrop read error interrupt enable */
#define FLASH_CR_EOPIE_Pos                        (24U)
#define FLASH_CR_EOPIE_Msk                        (0x1UL<<FLASH_CR_EOPIE_Pos)                       /*!< 0x01000000 */
#define FLASH_CR_EOPIE                            FLASH_CR_EOPIE_Msk                                /*!< End of operation interrupt enable */
#define FLASH_CR_ERRIE_Pos                        (25U)
#define FLASH_CR_ERRIE_Msk                        (0x1UL<<FLASH_CR_ERRIE_Pos)                       /*!< 0x02000000 */
#define FLASH_CR_ERRIE                            FLASH_CR_ERRIE_Msk                                /*!< Error interrupt enable */
#define FLASH_CR_OBL_LAUNCH_Pos                   (27U)
#define FLASH_CR_OBL_LAUNCH_Msk                   (0x1UL<<FLASH_CR_OBL_LAUNCH_Pos)                  /*!< 0x08000000 */
#define FLASH_CR_OBL_LAUNCH                       FLASH_CR_OBL_LAUNCH_Msk                           /*!< Force the option bytes loading */
#define FLASH_CR_OPTLOCK_Pos                      (30U)
#define FLASH_CR_OPTLOCK_Msk                      (0x1UL<<FLASH_CR_OPTLOCK_Pos)                     /*!< 0x40000000 */
#define FLASH_CR_OPTLOCK                          FLASH_CR_OPTLOCK_Msk                              /*!< Option Lock */
#define FLASH_CR_LOCK_Pos                         (31U)
#define FLASH_CR_LOCK_Msk                         (0x1UL<<FLASH_CR_LOCK_Pos)                        /*!< 0x80000000 */
#define FLASH_CR_LOCK                             FLASH_CR_LOCK_Msk                                 /*!< Lock */

/********************************* Bit definition for FLASH_ECCR register *******************************************/
#define FLASH_ECCR_ADDR_ECC_Pos                   (0U)
#define FLASH_ECCR_ADDR_ECC_Msk                   (0x1FFFFUL<<FLASH_ECCR_ADDR_ECC_Pos)              /*!< 0x0001FFFF */
#define FLASH_ECCR_ADDR_ECC                       FLASH_ECCR_ADDR_ECC_Msk                           /*!< ECC fail address */
#define FLASH_ECCR_BK_ECC_Pos                     (21U)
#define FLASH_ECCR_BK_ECC_Msk                     (0x1UL<<FLASH_ECCR_BK_ECC_Pos)                    /*!< 0x00200000 */
#define FLASH_ECCR_BK_ECC                         FLASH_ECCR_BK_ECC_Msk                             /*!< ECC fail bank */
#define FLASH_ECCR_SYSF_ECC_Pos                   (22U)
#define FLASH_ECCR_SYSF_ECC_Msk                   (0x1UL<<FLASH_ECCR_SYSF_ECC_Pos)                  /*!< 0x00400000 */
#define FLASH_ECCR_SYSF_ECC                       FLASH_ECCR_SYSF_ECC_Msk                           /*!< System Flash ECC fail */
#define FLASH_ECCR_ECCCIE_Pos                     (24U)
#define FLASH_ECCR_ECCCIE_Msk                     (0x1UL<<FLASH_ECCR_ECCCIE_Pos)                    /*!< 0x01000000 */
#define FLASH_ECCR_ECCCIE                         FLASH_ECCR_ECCCIE_Msk                             /*!< ECC correction interrupt enable */
#define FLASH_ECCR_ECCC_Pos                       (30U)
#define FLASH_ECCR_ECCC_Msk                       (0x1UL<<FLASH_ECCR_ECCC_Pos)                      /*!< 0x40000000 */
#define FLASH_ECCR_ECCC                           FLASH_ECCR_ECCC_Msk                               /*!< ECC correction */
#define FLASH_ECCR_ECCD_Pos                       (31U)
#define FLASH_ECCR_ECCD_Msk                       (0x1UL<<FLASH_ECCR_ECCD_Pos)                      /*!< 0x80000000 */
#define FLASH_ECCR_ECCD                           FLASH_ECCR_ECCD_Msk                               /*!< ECC detection */

/********************************* Bit definition for FLASH_OPTR register *******************************************/
#define FLASH_OPTR_RDP_Pos                        (0U)
#define FLASH_OPTR_RDP_Msk                        (0xFFUL<<FLASH_OPTR_RDP_Pos)                      /*!< 0x000000FF */
#define FLASH_OPTR_RDP                            FLASH_OPTR_RDP_Msk                                /*!< Read Protection */
#define FLASH_OPTR_NRST_STDBY_Pos                 (8U)
#define FLASH_OPTR_NRST_STDBY_Msk                 (0x1UL<<FLASH_OPTR_NRST_STDBY_Pos)                /*!< 0x00000100 */
#define FLASH_OPTR_NRST_STDBY                     FLASH_OPTR_NRST_STDBY_Msk                         /*!< nrst standby */
#define FLASH_OPTR_NRST_STOP_Pos                  (9U)
#define FLASH_OPTR_NRST_STOP_Msk                  (0x1UL<<FLASH_OPTR_NRST_STOP_Pos)                 /*!< 0x00000200 */
#define FLASH_OPTR_NRST_STOP                      FLASH_OPTR_NRST_STOP_Msk                          /*!< nrst stop */
#define FLASH_OPTR_IWDG_STDBY_Pos                 (10U)
#define FLASH_OPTR_IWDG_STDBY_Msk                 (0x1UL<<FLASH_OPTR_IWDG_STDBY_Pos)                /*!< 0x00000400 */
#define FLASH_OPTR_IWDG_STDBY                     FLASH_OPTR_IWDG_STDBY_Msk                         /*!< IWDG Standy Count Control */
#define FLASH_OPTR_IWDG_STOP_Pos                  (11U)
#define FLASH_OPTR_IWDG_STOP_Msk                  (0x1UL<<FLASH_OPTR_IWDG_STOP_Pos)                 /*!< 0x00000800 */
#define FLASH_OPTR_IWDG_STOP                      FLASH_OPTR_IWDG_STOP_Msk                          /*!< IWDG Stop Count Control */
#define FLASH_OPTR_IWDG_SW_Pos                    (12U)
#define FLASH_OPTR_IWDG_SW_Msk                    (0x1UL<<FLASH_OPTR_IWDG_SW_Pos)                   /*!< 0x00001000 */
#define FLASH_OPTR_IWDG_SW                        FLASH_OPTR_IWDG_SW_Msk                            /*!< IWDG Software Enable */
#define FLASH_OPTR_WWDG_SW_Pos                    (13U)
#define FLASH_OPTR_WWDG_SW_Msk                    (0x1UL<<FLASH_OPTR_WWDG_SW_Pos)                   /*!< 0x00002000 */
#define FLASH_OPTR_WWDG_SW                        FLASH_OPTR_WWDG_SW_Msk                            /*!< WWDG Software Enable */
#define FLASH_OPTR_NRST_MODE_Pos                  (14U)
#define FLASH_OPTR_NRST_MODE_Msk                  (0x1UL<<FLASH_OPTR_NRST_MODE_Pos)                 /*!< 0x00004000 */
#define FLASH_OPTR_NRST_MODE                      FLASH_OPTR_NRST_MODE_Msk                          /*!< nrst mode */
#define FLASH_OPTR_NBOOT1_Pos                     (15U)
#define FLASH_OPTR_NBOOT1_Msk                     (0x1UL<<FLASH_OPTR_NBOOT1_Pos)                    /*!< 0x00008000 */
#define FLASH_OPTR_NBOOT1                         FLASH_OPTR_NBOOT1_Msk                             /*!< nboot1 */
#define FLASH_OPTR_BOR_EN_Pos                     (16U)
#define FLASH_OPTR_BOR_EN_Msk                     (0x1UL<<FLASH_OPTR_BOR_EN_Pos)                    /*!< 0x00010000 */
#define FLASH_OPTR_BOR_EN                         FLASH_OPTR_BOR_EN_Msk                             /*!< BOR enable */
#define FLASH_OPTR_BOR_LEV_Pos                    (17U)
#define FLASH_OPTR_BOR_LEV_Msk                    (0x7UL<<FLASH_OPTR_BOR_LEV_Pos)                   /*!< 0x000E0000 */
#define FLASH_OPTR_BOR_LEV                        FLASH_OPTR_BOR_LEV_Msk                            /*!< BOR Level */
#define FLASH_OPTR_BOR_LEV_0                      (0x1UL<<FLASH_OPTR_BOR_LEV_Pos)                   /*!< 0x00020000 */
#define FLASH_OPTR_BOR_LEV_1                      (0x2UL<<FLASH_OPTR_BOR_LEV_Pos)                   /*!< 0x00040000 */
#define FLASH_OPTR_BOR_LEV_2                      (0x4UL<<FLASH_OPTR_BOR_LEV_Pos)                   /*!< 0x00080000 */
#define FLASH_OPTR_SRAM_PE_Pos                    (20U)
#define FLASH_OPTR_SRAM_PE_Msk                    (0x1UL<<FLASH_OPTR_SRAM_PE_Pos)                   /*!< 0x00100000 */
#define FLASH_OPTR_SRAM_PE                        FLASH_OPTR_SRAM_PE_Msk                            /*!< sram parity enable */
#define FLASH_OPTR_SWD_MODE_Pos                   (21U)
#define FLASH_OPTR_SWD_MODE_Msk                   (0x3UL<<FLASH_OPTR_SWD_MODE_Pos)                  /*!< 0x00600000 */
#define FLASH_OPTR_SWD_MODE                       FLASH_OPTR_SWD_MODE_Msk                           /*!< SWD mode */
#define FLASH_OPTR_SWD_MODE_0                     (0x1UL<<FLASH_OPTR_SWD_MODE_Pos)                  /*!< 0x00200000 */
#define FLASH_OPTR_SWD_MODE_1                     (0x2UL<<FLASH_OPTR_SWD_MODE_Pos)                  /*!< 0x00400000 */
#define FLASH_OPTR_BFB_Pos                        (23U)
#define FLASH_OPTR_BFB_Msk                        (0x1UL<<FLASH_OPTR_BFB_Pos)                       /*!< 0x00800000 */
#define FLASH_OPTR_BFB                            FLASH_OPTR_BFB_Msk                                /*!< Boot Flash Bank */
#define FLASH_OPTR_BOOT_LOCK_Pos                  (24U)
#define FLASH_OPTR_BOOT_LOCK_Msk                  (0x1UL<<FLASH_OPTR_BOOT_LOCK_Pos)                 /*!< 0x01000000 */
#define FLASH_OPTR_BOOT_LOCK                      FLASH_OPTR_BOOT_LOCK_Msk                          /*!< Boot Lock */
#define FLASH_OPTR_ECC_EN_Pos                     (25U)
#define FLASH_OPTR_ECC_EN_Msk                     (0x1UL<<FLASH_OPTR_ECC_EN_Pos)                    /*!< 0x02000000 */
#define FLASH_OPTR_ECC_EN                         FLASH_OPTR_ECC_EN_Msk                             /*!< ECC enable */

/********************************* Bit definition for FLASH_WRPR register *******************************************/
#define FLASH_WRPR_BK0_WRPX_Pos                   (0U)
#define FLASH_WRPR_BK0_WRPX_Msk                   (0xFFFFUL<<FLASH_WRPR_BK0_WRPX_Pos)               /*!< 0x0000FFFF */
#define FLASH_WRPR_BK0_WRPX                       FLASH_WRPR_BK0_WRPX_Msk                           /*!< Bank0 Sector Write Protection */
#define FLASH_WRPR_BK1_WRPX_Pos                   (16U)
#define FLASH_WRPR_BK1_WRPX_Msk                   (0xFFFFUL<<FLASH_WRPR_BK1_WRPX_Pos)               /*!< 0xFFFF0000 */
#define FLASH_WRPR_BK1_WRPX                       FLASH_WRPR_BK1_WRPX_Msk                           /*!< Bank1 Sector Write Protection */

/********************************* Bit definition for FLASH_PCROPR0 register ****************************************/
#define FLASH_PCROPR0_PCROP0SR_Pos                (0U)
#define FLASH_PCROPR0_PCROP0SR_Msk                (0x1FFUL<<FLASH_PCROPR0_PCROP0SR_Pos)             /*!< 0x000001FF */
#define FLASH_PCROPR0_PCROP0SR                    FLASH_PCROPR0_PCROP0SR_Msk                        /*!< Bank0 pcrop start address */
#define FLASH_PCROPR0_PCROP0ER_Pos                (16U)
#define FLASH_PCROPR0_PCROP0ER_Msk                (0x1FFUL<<FLASH_PCROPR0_PCROP0ER_Pos)             /*!< 0x01FF0000 */
#define FLASH_PCROPR0_PCROP0ER                    FLASH_PCROPR0_PCROP0ER_Msk                        /*!< Bank0 pcrop end address */

/********************************* Bit definition for FLASH_PCROPR1 register ****************************************/
#define FLASH_PCROPR1_PCROP1SR_Pos                (0U)
#define FLASH_PCROPR1_PCROP1SR_Msk                (0x1FFUL<<FLASH_PCROPR1_PCROP1SR_Pos)             /*!< 0x000001FF */
#define FLASH_PCROPR1_PCROP1SR                    FLASH_PCROPR1_PCROP1SR_Msk                        /*!< Bank1 pcrop start address */
#define FLASH_PCROPR1_PCROP1ER_Pos                (16U)
#define FLASH_PCROPR1_PCROP1ER_Msk                (0x1FFUL<<FLASH_PCROPR1_PCROP1ER_Pos)             /*!< 0x01FF0000 */
#define FLASH_PCROPR1_PCROP1ER                    FLASH_PCROPR1_PCROP1ER_Msk                        /*!< Bank1 pcrop end address */

/********************************* Bit definition for FLASH_LPCR register *******************************************/
#define FLASH_LPCR_SLEEP_EN_Pos                   (0U)
#define FLASH_LPCR_SLEEP_EN_Msk                   (0x1UL<<FLASH_LPCR_SLEEP_EN_Pos)                  /*!< 0x00000001 */
#define FLASH_LPCR_SLEEP_EN                       FLASH_LPCR_SLEEP_EN_Msk                           /*!< Sleep enable */
#define FLASH_LPCR_SLEEP_TIME_Pos                 (8U)
#define FLASH_LPCR_SLEEP_TIME_Msk                 (0xFFUL<<FLASH_LPCR_SLEEP_TIME_Pos)               /*!< 0x0000FF00 */
#define FLASH_LPCR_SLEEP_TIME                     FLASH_LPCR_SLEEP_TIME_Msk                         /*!< Sleep time */
#define FLASH_LPCR_LPRUN_ENTERT_Pos               (16U)
#define FLASH_LPCR_LPRUN_ENTERT_Msk               (0x7UL<<FLASH_LPCR_LPRUN_ENTERT_Pos)              /*!< 0x00070000 */
#define FLASH_LPCR_LPRUN_ENTERT                   FLASH_LPCR_LPRUN_ENTERT_Msk                       /*!< Low power run mode enter time */
#define FLASH_LPCR_LPRUN_ENTERT_0                 (0x1UL<<FLASH_LPCR_LPRUN_ENTERT_Pos)              /*!< 0x00010000 */
#define FLASH_LPCR_LPRUN_ENTERT_1                 (0x2UL<<FLASH_LPCR_LPRUN_ENTERT_Pos)              /*!< 0x00020000 */
#define FLASH_LPCR_LPRUN_ENTERT_2                 (0x4UL<<FLASH_LPCR_LPRUN_ENTERT_Pos)              /*!< 0x00040000 */
#define FLASH_LPCR_LPRUN_EXITT_Pos                (20U)
#define FLASH_LPCR_LPRUN_EXITT_Msk                (0x7UL<<FLASH_LPCR_LPRUN_EXITT_Pos)               /*!< 0x00700000 */
#define FLASH_LPCR_LPRUN_EXITT                    FLASH_LPCR_LPRUN_EXITT_Msk                        /*!< Low power run mode exit time */
#define FLASH_LPCR_LPRUN_EXITT_0                  (0x1UL<<FLASH_LPCR_LPRUN_EXITT_Pos)               /*!< 0x00100000 */
#define FLASH_LPCR_LPRUN_EXITT_1                  (0x2UL<<FLASH_LPCR_LPRUN_EXITT_Pos)               /*!< 0x00200000 */
#define FLASH_LPCR_LPRUN_EXITT_2                  (0x4UL<<FLASH_LPCR_LPRUN_EXITT_Pos)               /*!< 0x00400000 */

/********************************* Bit definition for FLASH_TS0 register ********************************************/
#define FLASH_TS0_TS0_Pos                         (0U)
#define FLASH_TS0_TS0_Msk                         (0x1FFUL<<FLASH_TS0_TS0_Pos)                      /*!< 0x000001FF */
#define FLASH_TS0_TS0                             FLASH_TS0_TS0_Msk                                 /*!< TS0 */

/********************************* Bit definition for FLASH_TS1 register ********************************************/
#define FLASH_TS1_TS1_Pos                         (0U)
#define FLASH_TS1_TS1_Msk                         (0x7FFUL<<FLASH_TS1_TS1_Pos)                      /*!< 0x000007FF */
#define FLASH_TS1_TS1                             FLASH_TS1_TS1_Msk                                 /*!< TS1 */

/********************************* Bit definition for FLASH_TS2P register *******************************************/
#define FLASH_TS2P_TS2P_Pos                       (0U)
#define FLASH_TS2P_TS2P_Msk                       (0x1FFUL<<FLASH_TS2P_TS2P_Pos)                    /*!< 0x000001FF */
#define FLASH_TS2P_TS2P                           FLASH_TS2P_TS2P_Msk                               /*!< TS2P */

/********************************* Bit definition for FLASH_TPS3 register *******************************************/
#define FLASH_TPS3_TPS3_Pos                       (0U)
#define FLASH_TPS3_TPS3_Msk                       (0x1FFFUL<<FLASH_TPS3_TPS3_Pos)                   /*!< 0x00001FFF */
#define FLASH_TPS3_TPS3                           FLASH_TPS3_TPS3_Msk                               /*!< TPS3 */

/********************************* Bit definition for FLASH_TS3 register ********************************************/
#define FLASH_TS3_TS3_Pos                         (0U)
#define FLASH_TS3_TS3_Msk                         (0x1FFUL<<FLASH_TS3_TS3_Pos)                      /*!< 0x000001FF */
#define FLASH_TS3_TS3                             FLASH_TS3_TS3_Msk                                 /*!< TS3 */

/********************************* Bit definition for FLASH_PERTPE register *****************************************/
#define FLASH_PERTPE_PERTPE_Pos                   (0U)
#define FLASH_PERTPE_PERTPE_Msk                   (0x3FFFFUL<<FLASH_PERTPE_PERTPE_Pos)              /*!< 0x0003FFFF */
#define FLASH_PERTPE_PERTPE                       FLASH_PERTPE_PERTPE_Msk                           /*!< PERTPE */

/********************************* Bit definition for FLASH_SMERTPE register ****************************************/
#define FLASH_SMERTPE_SMERTPE_Pos                 (0U)
#define FLASH_SMERTPE_SMERTPE_Msk                 (0x3FFFFUL<<FLASH_SMERTPE_SMERTPE_Pos)            /*!< 0x0003FFFF */
#define FLASH_SMERTPE_SMERTPE                     FLASH_SMERTPE_SMERTPE_Msk                         /*!< SMERTPE */

/********************************* Bit definition for FLASH_PRGTPE register *****************************************/
#define FLASH_PRGTPE_PRGTPE_Pos                   (0U)
#define FLASH_PRGTPE_PRGTPE_Msk                   (0xFFFFUL<<FLASH_PRGTPE_PRGTPE_Pos)               /*!< 0x0000FFFF */
#define FLASH_PRGTPE_PRGTPE                       FLASH_PRGTPE_PRGTPE_Msk                           /*!< PRGTPE */

/********************************* Bit definition for FLASH_PRETPE register *****************************************/
#define FLASH_PRETPE_PRETPE_Pos                   (0U)
#define FLASH_PRETPE_PRETPE_Msk                   (0x3FFFUL<<FLASH_PRETPE_PRETPE_Pos)               /*!< 0x00003FFF */
#define FLASH_PRETPE_PRETPE                       FLASH_PRETPE_PRETPE_Msk                           /*!< PRETPE */

/********************************* Bit definition for FLASH_ACLK2PW register ****************************************/
#define FLASH_ACLK2PW_TACLK2PW_Pos                (0U)
#define FLASH_ACLK2PW_TACLK2PW_Msk                (0xFFUL<<FLASH_ACLK2PW_TACLK2PW_Pos)              /*!< 0x000000FF */
#define FLASH_ACLK2PW_TACLK2PW                    FLASH_ACLK2PW_TACLK2PW_Msk                        /*!< TACLK2PW */


/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O (GPIO)                      */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODE0_Pos           (0U)
#define GPIO_MODER_MODE0_Msk           (0x3UL << GPIO_MODER_MODE0_Pos)          /*!< 0x00000003 */
#define GPIO_MODER_MODE0               GPIO_MODER_MODE0_Msk
#define GPIO_MODER_MODE0_0             (0x1UL << GPIO_MODER_MODE0_Pos)          /*!< 0x00000001 */
#define GPIO_MODER_MODE0_1             (0x2UL << GPIO_MODER_MODE0_Pos)          /*!< 0x00000002 */
#define GPIO_MODER_MODE1_Pos           (2U)
#define GPIO_MODER_MODE1_Msk           (0x3UL << GPIO_MODER_MODE1_Pos)          /*!< 0x0000000C */
#define GPIO_MODER_MODE1               GPIO_MODER_MODE1_Msk
#define GPIO_MODER_MODE1_0             (0x1UL << GPIO_MODER_MODE1_Pos)          /*!< 0x00000004 */
#define GPIO_MODER_MODE1_1             (0x2UL << GPIO_MODER_MODE1_Pos)          /*!< 0x00000008 */
#define GPIO_MODER_MODE2_Pos           (4U)
#define GPIO_MODER_MODE2_Msk           (0x3UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000030 */
#define GPIO_MODER_MODE2               GPIO_MODER_MODE2_Msk
#define GPIO_MODER_MODE2_0             (0x1UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000010 */
#define GPIO_MODER_MODE2_1             (0x2UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000020 */
#define GPIO_MODER_MODE3_Pos           (6U)
#define GPIO_MODER_MODE3_Msk           (0x3UL << GPIO_MODER_MODE3_Pos)          /*!< 0x000000C0 */
#define GPIO_MODER_MODE3               GPIO_MODER_MODE3_Msk
#define GPIO_MODER_MODE3_0             (0x1UL << GPIO_MODER_MODE3_Pos)          /*!< 0x00000040 */
#define GPIO_MODER_MODE3_1             (0x2UL << GPIO_MODER_MODE3_Pos)          /*!< 0x00000080 */
#define GPIO_MODER_MODE4_Pos           (8U)
#define GPIO_MODER_MODE4_Msk           (0x3UL << GPIO_MODER_MODE4_Pos)          /*!< 0x00000300 */
#define GPIO_MODER_MODE4               GPIO_MODER_MODE4_Msk
#define GPIO_MODER_MODE4_0             (0x1UL << GPIO_MODER_MODE4_Pos)          /*!< 0x00000100 */
#define GPIO_MODER_MODE4_1             (0x2UL << GPIO_MODER_MODE4_Pos)          /*!< 0x00000200 */
#define GPIO_MODER_MODE5_Pos           (10U)
#define GPIO_MODER_MODE5_Msk           (0x3UL << GPIO_MODER_MODE5_Pos)          /*!< 0x00000C00 */
#define GPIO_MODER_MODE5               GPIO_MODER_MODE5_Msk
#define GPIO_MODER_MODE5_0             (0x1UL << GPIO_MODER_MODE5_Pos)          /*!< 0x00000400 */
#define GPIO_MODER_MODE5_1             (0x2UL << GPIO_MODER_MODE5_Pos)          /*!< 0x00000800 */
#define GPIO_MODER_MODE6_Pos           (12U)
#define GPIO_MODER_MODE6_Msk           (0x3UL << GPIO_MODER_MODE6_Pos)          /*!< 0x00003000 */
#define GPIO_MODER_MODE6               GPIO_MODER_MODE6_Msk
#define GPIO_MODER_MODE6_0             (0x1UL << GPIO_MODER_MODE6_Pos)          /*!< 0x00001000 */
#define GPIO_MODER_MODE6_1             (0x2UL << GPIO_MODER_MODE6_Pos)          /*!< 0x00002000 */
#define GPIO_MODER_MODE7_Pos           (14U)
#define GPIO_MODER_MODE7_Msk           (0x3UL << GPIO_MODER_MODE7_Pos)          /*!< 0x0000C000 */
#define GPIO_MODER_MODE7               GPIO_MODER_MODE7_Msk
#define GPIO_MODER_MODE7_0             (0x1UL << GPIO_MODER_MODE7_Pos)          /*!< 0x00004000 */
#define GPIO_MODER_MODE7_1             (0x2UL << GPIO_MODER_MODE7_Pos)          /*!< 0x00008000 */
#define GPIO_MODER_MODE8_Pos           (16U)
#define GPIO_MODER_MODE8_Msk           (0x3UL << GPIO_MODER_MODE8_Pos)          /*!< 0x00030000 */
#define GPIO_MODER_MODE8               GPIO_MODER_MODE8_Msk
#define GPIO_MODER_MODE8_0             (0x1UL << GPIO_MODER_MODE8_Pos)          /*!< 0x00010000 */
#define GPIO_MODER_MODE8_1             (0x2UL << GPIO_MODER_MODE8_Pos)          /*!< 0x00020000 */
#define GPIO_MODER_MODE9_Pos           (18U)
#define GPIO_MODER_MODE9_Msk           (0x3UL << GPIO_MODER_MODE9_Pos)          /*!< 0x000C0000 */
#define GPIO_MODER_MODE9               GPIO_MODER_MODE9_Msk
#define GPIO_MODER_MODE9_0             (0x1UL << GPIO_MODER_MODE9_Pos)          /*!< 0x00040000 */
#define GPIO_MODER_MODE9_1             (0x2UL << GPIO_MODER_MODE9_Pos)          /*!< 0x00080000 */
#define GPIO_MODER_MODE10_Pos          (20U)
#define GPIO_MODER_MODE10_Msk          (0x3UL << GPIO_MODER_MODE10_Pos)         /*!< 0x00300000 */
#define GPIO_MODER_MODE10              GPIO_MODER_MODE10_Msk
#define GPIO_MODER_MODE10_0            (0x1UL << GPIO_MODER_MODE10_Pos)         /*!< 0x00100000 */
#define GPIO_MODER_MODE10_1            (0x2UL << GPIO_MODER_MODE10_Pos)         /*!< 0x00200000 */
#define GPIO_MODER_MODE11_Pos          (22U)
#define GPIO_MODER_MODE11_Msk          (0x3UL << GPIO_MODER_MODE11_Pos)         /*!< 0x00C00000 */
#define GPIO_MODER_MODE11              GPIO_MODER_MODE11_Msk
#define GPIO_MODER_MODE11_0            (0x1UL << GPIO_MODER_MODE11_Pos)         /*!< 0x00400000 */
#define GPIO_MODER_MODE11_1            (0x2UL << GPIO_MODER_MODE11_Pos)         /*!< 0x00800000 */
#define GPIO_MODER_MODE12_Pos          (24U)
#define GPIO_MODER_MODE12_Msk          (0x3UL << GPIO_MODER_MODE12_Pos)         /*!< 0x03000000 */
#define GPIO_MODER_MODE12              GPIO_MODER_MODE12_Msk
#define GPIO_MODER_MODE12_0            (0x1UL << GPIO_MODER_MODE12_Pos)         /*!< 0x01000000 */
#define GPIO_MODER_MODE12_1            (0x2UL << GPIO_MODER_MODE12_Pos)         /*!< 0x02000000 */
#define GPIO_MODER_MODE13_Pos          (26U)
#define GPIO_MODER_MODE13_Msk          (0x3UL << GPIO_MODER_MODE13_Pos)         /*!< 0x0C000000 */
#define GPIO_MODER_MODE13              GPIO_MODER_MODE13_Msk
#define GPIO_MODER_MODE13_0            (0x1UL << GPIO_MODER_MODE13_Pos)         /*!< 0x04000000 */
#define GPIO_MODER_MODE13_1            (0x2UL << GPIO_MODER_MODE13_Pos)         /*!< 0x08000000 */
#define GPIO_MODER_MODE14_Pos          (28U)
#define GPIO_MODER_MODE14_Msk          (0x3UL << GPIO_MODER_MODE14_Pos)         /*!< 0x30000000 */
#define GPIO_MODER_MODE14              GPIO_MODER_MODE14_Msk
#define GPIO_MODER_MODE14_0            (0x1UL << GPIO_MODER_MODE14_Pos)         /*!< 0x10000000 */
#define GPIO_MODER_MODE14_1            (0x2UL << GPIO_MODER_MODE14_Pos)         /*!< 0x20000000 */
#define GPIO_MODER_MODE15_Pos          (30U)
#define GPIO_MODER_MODE15_Msk          (0x3UL << GPIO_MODER_MODE15_Pos)         /*!< 0xC0000000 */
#define GPIO_MODER_MODE15              GPIO_MODER_MODE15_Msk
#define GPIO_MODER_MODE15_0            (0x1UL << GPIO_MODER_MODE15_Pos)         /*!< 0x40000000 */
#define GPIO_MODER_MODE15_1            (0x2UL << GPIO_MODER_MODE15_Pos)         /*!< 0x80000000 */

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT0_Pos            (0U)
#define GPIO_OTYPER_OT0_Msk            (0x1UL << GPIO_OTYPER_OT0_Pos)           /*!< 0x00000001 */
#define GPIO_OTYPER_OT0                GPIO_OTYPER_OT0_Msk
#define GPIO_OTYPER_OT1_Pos            (1U)
#define GPIO_OTYPER_OT1_Msk            (0x1UL << GPIO_OTYPER_OT1_Pos)           /*!< 0x00000002 */
#define GPIO_OTYPER_OT1                GPIO_OTYPER_OT1_Msk
#define GPIO_OTYPER_OT2_Pos            (2U)
#define GPIO_OTYPER_OT2_Msk            (0x1UL << GPIO_OTYPER_OT2_Pos)           /*!< 0x00000004 */
#define GPIO_OTYPER_OT2                GPIO_OTYPER_OT2_Msk
#define GPIO_OTYPER_OT3_Pos            (3U)
#define GPIO_OTYPER_OT3_Msk            (0x1UL << GPIO_OTYPER_OT3_Pos)           /*!< 0x00000008 */
#define GPIO_OTYPER_OT3                GPIO_OTYPER_OT3_Msk
#define GPIO_OTYPER_OT4_Pos            (4U)
#define GPIO_OTYPER_OT4_Msk            (0x1UL << GPIO_OTYPER_OT4_Pos)           /*!< 0x00000010 */
#define GPIO_OTYPER_OT4                GPIO_OTYPER_OT4_Msk
#define GPIO_OTYPER_OT5_Pos            (5U)
#define GPIO_OTYPER_OT5_Msk            (0x1UL << GPIO_OTYPER_OT5_Pos)           /*!< 0x00000020 */
#define GPIO_OTYPER_OT5                GPIO_OTYPER_OT5_Msk
#define GPIO_OTYPER_OT6_Pos            (6U)
#define GPIO_OTYPER_OT6_Msk            (0x1UL << GPIO_OTYPER_OT6_Pos)           /*!< 0x00000040 */
#define GPIO_OTYPER_OT6                GPIO_OTYPER_OT6_Msk
#define GPIO_OTYPER_OT7_Pos            (7U)
#define GPIO_OTYPER_OT7_Msk            (0x1UL << GPIO_OTYPER_OT7_Pos)           /*!< 0x00000080 */
#define GPIO_OTYPER_OT7                GPIO_OTYPER_OT7_Msk
#define GPIO_OTYPER_OT8_Pos            (8U)
#define GPIO_OTYPER_OT8_Msk            (0x1UL << GPIO_OTYPER_OT8_Pos)           /*!< 0x00000100 */
#define GPIO_OTYPER_OT8                GPIO_OTYPER_OT8_Msk
#define GPIO_OTYPER_OT9_Pos            (9U)
#define GPIO_OTYPER_OT9_Msk            (0x1UL << GPIO_OTYPER_OT9_Pos)           /*!< 0x00000200 */
#define GPIO_OTYPER_OT9                GPIO_OTYPER_OT9_Msk
#define GPIO_OTYPER_OT10_Pos           (10U)
#define GPIO_OTYPER_OT10_Msk           (0x1UL << GPIO_OTYPER_OT10_Pos)          /*!< 0x00000400 */
#define GPIO_OTYPER_OT10               GPIO_OTYPER_OT10_Msk
#define GPIO_OTYPER_OT11_Pos           (11U)
#define GPIO_OTYPER_OT11_Msk           (0x1UL << GPIO_OTYPER_OT11_Pos)          /*!< 0x00000800 */
#define GPIO_OTYPER_OT11               GPIO_OTYPER_OT11_Msk
#define GPIO_OTYPER_OT12_Pos           (12U)
#define GPIO_OTYPER_OT12_Msk           (0x1UL << GPIO_OTYPER_OT12_Pos)          /*!< 0x00001000 */
#define GPIO_OTYPER_OT12               GPIO_OTYPER_OT12_Msk
#define GPIO_OTYPER_OT13_Pos           (13U)
#define GPIO_OTYPER_OT13_Msk           (0x1UL << GPIO_OTYPER_OT13_Pos)          /*!< 0x00002000 */
#define GPIO_OTYPER_OT13               GPIO_OTYPER_OT13_Msk
#define GPIO_OTYPER_OT14_Pos           (14U)
#define GPIO_OTYPER_OT14_Msk           (0x1UL << GPIO_OTYPER_OT14_Pos)          /*!< 0x00004000 */
#define GPIO_OTYPER_OT14               GPIO_OTYPER_OT14_Msk
#define GPIO_OTYPER_OT15_Pos           (15U)
#define GPIO_OTYPER_OT15_Msk           (0x1UL << GPIO_OTYPER_OT15_Pos)          /*!< 0x00008000 */
#define GPIO_OTYPER_OT15               GPIO_OTYPER_OT15_Msk

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDR_OSPEED0_Pos       (0U)
#define GPIO_OSPEEDR_OSPEED0_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000003 */
#define GPIO_OSPEEDR_OSPEED0           GPIO_OSPEEDR_OSPEED0_Msk
#define GPIO_OSPEEDR_OSPEED0_0         (0x1UL << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000001 */
#define GPIO_OSPEEDR_OSPEED0_1         (0x2UL << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000002 */
#define GPIO_OSPEEDR_OSPEED1_Pos       (2U)
#define GPIO_OSPEEDR_OSPEED1_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x0000000C */
#define GPIO_OSPEEDR_OSPEED1           GPIO_OSPEEDR_OSPEED1_Msk
#define GPIO_OSPEEDR_OSPEED1_0         (0x1UL << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x00000004 */
#define GPIO_OSPEEDR_OSPEED1_1         (0x2UL << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x00000008 */
#define GPIO_OSPEEDR_OSPEED2_Pos       (4U)
#define GPIO_OSPEEDR_OSPEED2_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000030 */
#define GPIO_OSPEEDR_OSPEED2           GPIO_OSPEEDR_OSPEED2_Msk
#define GPIO_OSPEEDR_OSPEED2_0         (0x1UL << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000010 */
#define GPIO_OSPEEDR_OSPEED2_1         (0x2UL << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000020 */
#define GPIO_OSPEEDR_OSPEED3_Pos       (6U)
#define GPIO_OSPEEDR_OSPEED3_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x000000C0 */
#define GPIO_OSPEEDR_OSPEED3           GPIO_OSPEEDR_OSPEED3_Msk
#define GPIO_OSPEEDR_OSPEED3_0         (0x1UL << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x00000040 */
#define GPIO_OSPEEDR_OSPEED3_1         (0x2UL << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x00000080 */
#define GPIO_OSPEEDR_OSPEED4_Pos       (8U)
#define GPIO_OSPEEDR_OSPEED4_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000300 */
#define GPIO_OSPEEDR_OSPEED4           GPIO_OSPEEDR_OSPEED4_Msk
#define GPIO_OSPEEDR_OSPEED4_0         (0x1UL << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000100 */
#define GPIO_OSPEEDR_OSPEED4_1         (0x2UL << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000200 */
#define GPIO_OSPEEDR_OSPEED5_Pos       (10U)
#define GPIO_OSPEEDR_OSPEED5_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000C00 */
#define GPIO_OSPEEDR_OSPEED5           GPIO_OSPEEDR_OSPEED5_Msk
#define GPIO_OSPEEDR_OSPEED5_0         (0x1UL << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000400 */
#define GPIO_OSPEEDR_OSPEED5_1         (0x2UL << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000800 */
#define GPIO_OSPEEDR_OSPEED6_Pos       (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00003000 */
#define GPIO_OSPEEDR_OSPEED6           GPIO_OSPEEDR_OSPEED6_Msk
#define GPIO_OSPEEDR_OSPEED6_0         (0x1UL << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00001000 */
#define GPIO_OSPEEDR_OSPEED6_1         (0x2UL << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00002000 */
#define GPIO_OSPEEDR_OSPEED7_Pos       (14U)
#define GPIO_OSPEEDR_OSPEED7_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x0000C000 */
#define GPIO_OSPEEDR_OSPEED7           GPIO_OSPEEDR_OSPEED7_Msk
#define GPIO_OSPEEDR_OSPEED7_0         (0x1UL << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x00004000 */
#define GPIO_OSPEEDR_OSPEED7_1         (0x2UL << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x00008000 */
#define GPIO_OSPEEDR_OSPEED8_Pos       (16U)
#define GPIO_OSPEEDR_OSPEED8_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED8_Pos)      /*!< 0x00030000 */
#define GPIO_OSPEEDR_OSPEED8           GPIO_OSPEEDR_OSPEED8_Msk
#define GPIO_OSPEEDR_OSPEED8_0         (0x1UL << GPIO_OSPEEDR_OSPEED8_Pos)      /*!< 0x00010000 */
#define GPIO_OSPEEDR_OSPEED8_1         (0x2UL << GPIO_OSPEEDR_OSPEED8_Pos)      /*!< 0x00020000 */
#define GPIO_OSPEEDR_OSPEED9_Pos       (18U)
#define GPIO_OSPEEDR_OSPEED9_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED9_Pos)      /*!< 0x000C0000 */
#define GPIO_OSPEEDR_OSPEED9           GPIO_OSPEEDR_OSPEED9_Msk
#define GPIO_OSPEEDR_OSPEED9_0         (0x1UL << GPIO_OSPEEDR_OSPEED9_Pos)      /*!< 0x00040000 */
#define GPIO_OSPEEDR_OSPEED9_1         (0x2UL << GPIO_OSPEEDR_OSPEED9_Pos)      /*!< 0x00080000 */
#define GPIO_OSPEEDR_OSPEED10_Pos      (20U)
#define GPIO_OSPEEDR_OSPEED10_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED10_Pos)     /*!< 0x00300000 */
#define GPIO_OSPEEDR_OSPEED10          GPIO_OSPEEDR_OSPEED10_Msk
#define GPIO_OSPEEDR_OSPEED10_0        (0x1UL << GPIO_OSPEEDR_OSPEED10_Pos)     /*!< 0x00100000 */
#define GPIO_OSPEEDR_OSPEED10_1        (0x2UL << GPIO_OSPEEDR_OSPEED10_Pos)     /*!< 0x00200000 */
#define GPIO_OSPEEDR_OSPEED11_Pos      (22U)
#define GPIO_OSPEEDR_OSPEED11_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED11_Pos)     /*!< 0x00C00000 */
#define GPIO_OSPEEDR_OSPEED11          GPIO_OSPEEDR_OSPEED11_Msk
#define GPIO_OSPEEDR_OSPEED11_0        (0x1UL << GPIO_OSPEEDR_OSPEED11_Pos)     /*!< 0x00400000 */
#define GPIO_OSPEEDR_OSPEED11_1        (0x2UL << GPIO_OSPEEDR_OSPEED11_Pos)     /*!< 0x00800000 */
#define GPIO_OSPEEDR_OSPEED12_Pos      (24U)
#define GPIO_OSPEEDR_OSPEED12_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED12_Pos)     /*!< 0x03000000 */
#define GPIO_OSPEEDR_OSPEED12          GPIO_OSPEEDR_OSPEED12_Msk
#define GPIO_OSPEEDR_OSPEED12_0        (0x1UL << GPIO_OSPEEDR_OSPEED12_Pos)     /*!< 0x01000000 */
#define GPIO_OSPEEDR_OSPEED12_1        (0x2UL << GPIO_OSPEEDR_OSPEED12_Pos)     /*!< 0x02000000 */
#define GPIO_OSPEEDR_OSPEED13_Pos      (26U)
#define GPIO_OSPEEDR_OSPEED13_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED13_Pos)     /*!< 0x0C000000 */
#define GPIO_OSPEEDR_OSPEED13          GPIO_OSPEEDR_OSPEED13_Msk
#define GPIO_OSPEEDR_OSPEED13_0        (0x1UL << GPIO_OSPEEDR_OSPEED13_Pos)     /*!< 0x04000000 */
#define GPIO_OSPEEDR_OSPEED13_1        (0x2UL << GPIO_OSPEEDR_OSPEED13_Pos)     /*!< 0x08000000 */
#define GPIO_OSPEEDR_OSPEED14_Pos      (28U)
#define GPIO_OSPEEDR_OSPEED14_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED14_Pos)     /*!< 0x30000000 */
#define GPIO_OSPEEDR_OSPEED14          GPIO_OSPEEDR_OSPEED14_Msk
#define GPIO_OSPEEDR_OSPEED14_0        (0x1UL << GPIO_OSPEEDR_OSPEED14_Pos)     /*!< 0x10000000 */
#define GPIO_OSPEEDR_OSPEED14_1        (0x2UL << GPIO_OSPEEDR_OSPEED14_Pos)     /*!< 0x20000000 */
#define GPIO_OSPEEDR_OSPEED15_Pos      (30U)
#define GPIO_OSPEEDR_OSPEED15_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED15_Pos)     /*!< 0xC0000000 */
#define GPIO_OSPEEDR_OSPEED15          GPIO_OSPEEDR_OSPEED15_Msk
#define GPIO_OSPEEDR_OSPEED15_0        (0x1UL << GPIO_OSPEEDR_OSPEED15_Pos)     /*!< 0x40000000 */
#define GPIO_OSPEEDR_OSPEED15_1        (0x2UL << GPIO_OSPEEDR_OSPEED15_Pos)     /*!< 0x80000000 */

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPD0_Pos           (0U)
#define GPIO_PUPDR_PUPD0_Msk           (0x3UL << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000003 */
#define GPIO_PUPDR_PUPD0               GPIO_PUPDR_PUPD0_Msk
#define GPIO_PUPDR_PUPD0_0             (0x1UL << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000001 */
#define GPIO_PUPDR_PUPD0_1             (0x2UL << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000002 */
#define GPIO_PUPDR_PUPD1_Pos           (2U)
#define GPIO_PUPDR_PUPD1_Msk           (0x3UL << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x0000000C */
#define GPIO_PUPDR_PUPD1               GPIO_PUPDR_PUPD1_Msk
#define GPIO_PUPDR_PUPD1_0             (0x1UL << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x00000004 */
#define GPIO_PUPDR_PUPD1_1             (0x2UL << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x00000008 */
#define GPIO_PUPDR_PUPD2_Pos           (4U)
#define GPIO_PUPDR_PUPD2_Msk           (0x3UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000030 */
#define GPIO_PUPDR_PUPD2               GPIO_PUPDR_PUPD2_Msk
#define GPIO_PUPDR_PUPD2_0             (0x1UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000010 */
#define GPIO_PUPDR_PUPD2_1             (0x2UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000020 */
#define GPIO_PUPDR_PUPD3_Pos           (6U)
#define GPIO_PUPDR_PUPD3_Msk           (0x3UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPD3               GPIO_PUPDR_PUPD3_Msk
#define GPIO_PUPDR_PUPD3_0             (0x1UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000040 */
#define GPIO_PUPDR_PUPD3_1             (0x2UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000080 */
#define GPIO_PUPDR_PUPD4_Pos           (8U)
#define GPIO_PUPDR_PUPD4_Msk           (0x3UL << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000300 */
#define GPIO_PUPDR_PUPD4               GPIO_PUPDR_PUPD4_Msk
#define GPIO_PUPDR_PUPD4_0             (0x1UL << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000100 */
#define GPIO_PUPDR_PUPD4_1             (0x2UL << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000200 */
#define GPIO_PUPDR_PUPD5_Pos           (10U)
#define GPIO_PUPDR_PUPD5_Msk           (0x3UL << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPD5               GPIO_PUPDR_PUPD5_Msk
#define GPIO_PUPDR_PUPD5_0             (0x1UL << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000400 */
#define GPIO_PUPDR_PUPD5_1             (0x2UL << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000800 */
#define GPIO_PUPDR_PUPD6_Pos           (12U)
#define GPIO_PUPDR_PUPD6_Msk           (0x3UL << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00003000 */
#define GPIO_PUPDR_PUPD6               GPIO_PUPDR_PUPD6_Msk
#define GPIO_PUPDR_PUPD6_0             (0x1UL << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00001000 */
#define GPIO_PUPDR_PUPD6_1             (0x2UL << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00002000 */
#define GPIO_PUPDR_PUPD7_Pos           (14U)
#define GPIO_PUPDR_PUPD7_Msk           (0x3UL << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPD7               GPIO_PUPDR_PUPD7_Msk
#define GPIO_PUPDR_PUPD7_0             (0x1UL << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x00004000 */
#define GPIO_PUPDR_PUPD7_1             (0x2UL << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x00008000 */
#define GPIO_PUPDR_PUPD8_Pos           (16U)
#define GPIO_PUPDR_PUPD8_Msk           (0x3UL << GPIO_PUPDR_PUPD8_Pos)          /*!< 0x00030000 */
#define GPIO_PUPDR_PUPD8               GPIO_PUPDR_PUPD8_Msk
#define GPIO_PUPDR_PUPD8_0             (0x1UL << GPIO_PUPDR_PUPD8_Pos)          /*!< 0x00010000 */
#define GPIO_PUPDR_PUPD8_1             (0x2UL << GPIO_PUPDR_PUPD8_Pos)          /*!< 0x00020000 */
#define GPIO_PUPDR_PUPD9_Pos           (18U)
#define GPIO_PUPDR_PUPD9_Msk           (0x3UL << GPIO_PUPDR_PUPD9_Pos)          /*!< 0x000C0000 */
#define GPIO_PUPDR_PUPD9               GPIO_PUPDR_PUPD9_Msk
#define GPIO_PUPDR_PUPD9_0             (0x1UL << GPIO_PUPDR_PUPD9_Pos)          /*!< 0x00040000 */
#define GPIO_PUPDR_PUPD9_1             (0x2UL << GPIO_PUPDR_PUPD9_Pos)          /*!< 0x00080000 */
#define GPIO_PUPDR_PUPD10_Pos          (20U)
#define GPIO_PUPDR_PUPD10_Msk          (0x3UL << GPIO_PUPDR_PUPD10_Pos)         /*!< 0x00300000 */
#define GPIO_PUPDR_PUPD10              GPIO_PUPDR_PUPD10_Msk
#define GPIO_PUPDR_PUPD10_0            (0x1UL << GPIO_PUPDR_PUPD10_Pos)         /*!< 0x00100000 */
#define GPIO_PUPDR_PUPD10_1            (0x2UL << GPIO_PUPDR_PUPD10_Pos)         /*!< 0x00200000 */
#define GPIO_PUPDR_PUPD11_Pos          (22U)
#define GPIO_PUPDR_PUPD11_Msk          (0x3UL << GPIO_PUPDR_PUPD11_Pos)         /*!< 0x00C00000 */
#define GPIO_PUPDR_PUPD11              GPIO_PUPDR_PUPD11_Msk
#define GPIO_PUPDR_PUPD11_0            (0x1UL << GPIO_PUPDR_PUPD11_Pos)         /*!< 0x00400000 */
#define GPIO_PUPDR_PUPD11_1            (0x2UL << GPIO_PUPDR_PUPD11_Pos)         /*!< 0x00800000 */
#define GPIO_PUPDR_PUPD12_Pos          (24U)
#define GPIO_PUPDR_PUPD12_Msk          (0x3UL << GPIO_PUPDR_PUPD12_Pos)         /*!< 0x03000000 */
#define GPIO_PUPDR_PUPD12              GPIO_PUPDR_PUPD12_Msk
#define GPIO_PUPDR_PUPD12_0            (0x1UL << GPIO_PUPDR_PUPD12_Pos)         /*!< 0x01000000 */
#define GPIO_PUPDR_PUPD12_1            (0x2UL << GPIO_PUPDR_PUPD12_Pos)         /*!< 0x02000000 */
#define GPIO_PUPDR_PUPD13_Pos          (26U)
#define GPIO_PUPDR_PUPD13_Msk          (0x3UL << GPIO_PUPDR_PUPD13_Pos)         /*!< 0x0C000000 */
#define GPIO_PUPDR_PUPD13              GPIO_PUPDR_PUPD13_Msk
#define GPIO_PUPDR_PUPD13_0            (0x1UL << GPIO_PUPDR_PUPD13_Pos)         /*!< 0x04000000 */
#define GPIO_PUPDR_PUPD13_1            (0x2UL << GPIO_PUPDR_PUPD13_Pos)         /*!< 0x08000000 */
#define GPIO_PUPDR_PUPD14_Pos          (28U)
#define GPIO_PUPDR_PUPD14_Msk          (0x3UL << GPIO_PUPDR_PUPD14_Pos)         /*!< 0x30000000 */
#define GPIO_PUPDR_PUPD14              GPIO_PUPDR_PUPD14_Msk
#define GPIO_PUPDR_PUPD14_0            (0x1UL << GPIO_PUPDR_PUPD14_Pos)         /*!< 0x10000000 */
#define GPIO_PUPDR_PUPD14_1            (0x2UL << GPIO_PUPDR_PUPD14_Pos)         /*!< 0x20000000 */
#define GPIO_PUPDR_PUPD15_Pos          (30U)
#define GPIO_PUPDR_PUPD15_Msk          (0x3UL << GPIO_PUPDR_PUPD15_Pos)         /*!< 0xC0000000 */
#define GPIO_PUPDR_PUPD15              GPIO_PUPDR_PUPD15_Msk
#define GPIO_PUPDR_PUPD15_0            (0x1UL << GPIO_PUPDR_PUPD15_Pos)         /*!< 0x40000000 */
#define GPIO_PUPDR_PUPD15_1            (0x2UL << GPIO_PUPDR_PUPD15_Pos)         /*!< 0x80000000 */

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_ID0_Pos               (0U)
#define GPIO_IDR_ID0_Msk               (0x1UL << GPIO_IDR_ID0_Pos)              /*!< 0x00000001 */
#define GPIO_IDR_ID0                   GPIO_IDR_ID0_Msk
#define GPIO_IDR_ID1_Pos               (1U)
#define GPIO_IDR_ID1_Msk               (0x1UL << GPIO_IDR_ID1_Pos)              /*!< 0x00000002 */
#define GPIO_IDR_ID1                   GPIO_IDR_ID1_Msk
#define GPIO_IDR_ID2_Pos               (2U)
#define GPIO_IDR_ID2_Msk               (0x1UL << GPIO_IDR_ID2_Pos)              /*!< 0x00000004 */
#define GPIO_IDR_ID2                   GPIO_IDR_ID2_Msk
#define GPIO_IDR_ID3_Pos               (3U)
#define GPIO_IDR_ID3_Msk               (0x1UL << GPIO_IDR_ID3_Pos)              /*!< 0x00000008 */
#define GPIO_IDR_ID3                   GPIO_IDR_ID3_Msk
#define GPIO_IDR_ID4_Pos               (4U)
#define GPIO_IDR_ID4_Msk               (0x1UL << GPIO_IDR_ID4_Pos)              /*!< 0x00000010 */
#define GPIO_IDR_ID4                   GPIO_IDR_ID4_Msk
#define GPIO_IDR_ID5_Pos               (5U)
#define GPIO_IDR_ID5_Msk               (0x1UL << GPIO_IDR_ID5_Pos)              /*!< 0x00000020 */
#define GPIO_IDR_ID5                   GPIO_IDR_ID5_Msk
#define GPIO_IDR_ID6_Pos               (6U)
#define GPIO_IDR_ID6_Msk               (0x1UL << GPIO_IDR_ID6_Pos)              /*!< 0x00000040 */
#define GPIO_IDR_ID6                   GPIO_IDR_ID6_Msk
#define GPIO_IDR_ID7_Pos               (7U)
#define GPIO_IDR_ID7_Msk               (0x1UL << GPIO_IDR_ID7_Pos)              /*!< 0x00000080 */
#define GPIO_IDR_ID7                   GPIO_IDR_ID7_Msk
#define GPIO_IDR_ID8_Pos               (8U)
#define GPIO_IDR_ID8_Msk               (0x1UL << GPIO_IDR_ID8_Pos)              /*!< 0x00000100 */
#define GPIO_IDR_ID8                   GPIO_IDR_ID8_Msk
#define GPIO_IDR_ID9_Pos               (9U)
#define GPIO_IDR_ID9_Msk               (0x1UL << GPIO_IDR_ID9_Pos)              /*!< 0x00000200 */
#define GPIO_IDR_ID9                   GPIO_IDR_ID9_Msk
#define GPIO_IDR_ID10_Pos              (10U)
#define GPIO_IDR_ID10_Msk              (0x1UL << GPIO_IDR_ID10_Pos)             /*!< 0x00000400 */
#define GPIO_IDR_ID10                  GPIO_IDR_ID10_Msk
#define GPIO_IDR_ID11_Pos              (11U)
#define GPIO_IDR_ID11_Msk              (0x1UL << GPIO_IDR_ID11_Pos)             /*!< 0x00000800 */
#define GPIO_IDR_ID11                  GPIO_IDR_ID11_Msk
#define GPIO_IDR_ID12_Pos              (12U)
#define GPIO_IDR_ID12_Msk              (0x1UL << GPIO_IDR_ID12_Pos)             /*!< 0x00001000 */
#define GPIO_IDR_ID12                  GPIO_IDR_ID12_Msk
#define GPIO_IDR_ID13_Pos              (13U)
#define GPIO_IDR_ID13_Msk              (0x1UL << GPIO_IDR_ID13_Pos)             /*!< 0x00002000 */
#define GPIO_IDR_ID13                  GPIO_IDR_ID13_Msk
#define GPIO_IDR_ID14_Pos              (14U)
#define GPIO_IDR_ID14_Msk              (0x1UL << GPIO_IDR_ID14_Pos)             /*!< 0x00004000 */
#define GPIO_IDR_ID14                  GPIO_IDR_ID14_Msk
#define GPIO_IDR_ID15_Pos              (15U)
#define GPIO_IDR_ID15_Msk              (0x1UL << GPIO_IDR_ID15_Pos)             /*!< 0x00008000 */
#define GPIO_IDR_ID15                  GPIO_IDR_ID15_Msk

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_OD0_Pos               (0U)
#define GPIO_ODR_OD0_Msk               (0x1UL << GPIO_ODR_OD0_Pos)              /*!< 0x00000001 */
#define GPIO_ODR_OD0                   GPIO_ODR_OD0_Msk
#define GPIO_ODR_OD1_Pos               (1U)
#define GPIO_ODR_OD1_Msk               (0x1UL << GPIO_ODR_OD1_Pos)              /*!< 0x00000002 */
#define GPIO_ODR_OD1                   GPIO_ODR_OD1_Msk
#define GPIO_ODR_OD2_Pos               (2U)
#define GPIO_ODR_OD2_Msk               (0x1UL << GPIO_ODR_OD2_Pos)              /*!< 0x00000004 */
#define GPIO_ODR_OD2                   GPIO_ODR_OD2_Msk
#define GPIO_ODR_OD3_Pos               (3U)
#define GPIO_ODR_OD3_Msk               (0x1UL << GPIO_ODR_OD3_Pos)              /*!< 0x00000008 */
#define GPIO_ODR_OD3                   GPIO_ODR_OD3_Msk
#define GPIO_ODR_OD4_Pos               (4U)
#define GPIO_ODR_OD4_Msk               (0x1UL << GPIO_ODR_OD4_Pos)              /*!< 0x00000010 */
#define GPIO_ODR_OD4                   GPIO_ODR_OD4_Msk
#define GPIO_ODR_OD5_Pos               (5U)
#define GPIO_ODR_OD5_Msk               (0x1UL << GPIO_ODR_OD5_Pos)              /*!< 0x00000020 */
#define GPIO_ODR_OD5                   GPIO_ODR_OD5_Msk
#define GPIO_ODR_OD6_Pos               (6U)
#define GPIO_ODR_OD6_Msk               (0x1UL << GPIO_ODR_OD6_Pos)              /*!< 0x00000040 */
#define GPIO_ODR_OD6                   GPIO_ODR_OD6_Msk
#define GPIO_ODR_OD7_Pos               (7U)
#define GPIO_ODR_OD7_Msk               (0x1UL << GPIO_ODR_OD7_Pos)              /*!< 0x00000080 */
#define GPIO_ODR_OD7                   GPIO_ODR_OD7_Msk
#define GPIO_ODR_OD8_Pos               (8U)
#define GPIO_ODR_OD8_Msk               (0x1UL << GPIO_ODR_OD8_Pos)              /*!< 0x00000100 */
#define GPIO_ODR_OD8                   GPIO_ODR_OD8_Msk
#define GPIO_ODR_OD9_Pos               (9U)
#define GPIO_ODR_OD9_Msk               (0x1UL << GPIO_ODR_OD9_Pos)              /*!< 0x00000200 */
#define GPIO_ODR_OD9                   GPIO_ODR_OD9_Msk
#define GPIO_ODR_OD10_Pos              (10U)
#define GPIO_ODR_OD10_Msk              (0x1UL << GPIO_ODR_OD10_Pos)             /*!< 0x00000400 */
#define GPIO_ODR_OD10                  GPIO_ODR_OD10_Msk
#define GPIO_ODR_OD11_Pos              (11U)
#define GPIO_ODR_OD11_Msk              (0x1UL << GPIO_ODR_OD11_Pos)             /*!< 0x00000800 */
#define GPIO_ODR_OD11                  GPIO_ODR_OD11_Msk
#define GPIO_ODR_OD12_Pos              (12U)
#define GPIO_ODR_OD12_Msk              (0x1UL << GPIO_ODR_OD12_Pos)             /*!< 0x00001000 */
#define GPIO_ODR_OD12                  GPIO_ODR_OD12_Msk
#define GPIO_ODR_OD13_Pos              (13U)
#define GPIO_ODR_OD13_Msk              (0x1UL << GPIO_ODR_OD13_Pos)             /*!< 0x00002000 */
#define GPIO_ODR_OD13                  GPIO_ODR_OD13_Msk
#define GPIO_ODR_OD14_Pos              (14U)
#define GPIO_ODR_OD14_Msk              (0x1UL << GPIO_ODR_OD14_Pos)             /*!< 0x00004000 */
#define GPIO_ODR_OD14                  GPIO_ODR_OD14_Msk
#define GPIO_ODR_OD15_Pos              (15U)
#define GPIO_ODR_OD15_Msk              (0x1UL << GPIO_ODR_OD15_Pos)             /*!< 0x00008000 */
#define GPIO_ODR_OD15                  GPIO_ODR_OD15_Msk

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS0_Pos              (0U)
#define GPIO_BSRR_BS0_Msk              (0x1UL << GPIO_BSRR_BS0_Pos)             /*!< 0x00000001 */
#define GPIO_BSRR_BS0                  GPIO_BSRR_BS0_Msk
#define GPIO_BSRR_BS1_Pos              (1U)
#define GPIO_BSRR_BS1_Msk              (0x1UL << GPIO_BSRR_BS1_Pos)             /*!< 0x00000002 */
#define GPIO_BSRR_BS1                  GPIO_BSRR_BS1_Msk
#define GPIO_BSRR_BS2_Pos              (2U)
#define GPIO_BSRR_BS2_Msk              (0x1UL << GPIO_BSRR_BS2_Pos)             /*!< 0x00000004 */
#define GPIO_BSRR_BS2                  GPIO_BSRR_BS2_Msk
#define GPIO_BSRR_BS3_Pos              (3U)
#define GPIO_BSRR_BS3_Msk              (0x1UL << GPIO_BSRR_BS3_Pos)             /*!< 0x00000008 */
#define GPIO_BSRR_BS3                  GPIO_BSRR_BS3_Msk
#define GPIO_BSRR_BS4_Pos              (4U)
#define GPIO_BSRR_BS4_Msk              (0x1UL << GPIO_BSRR_BS4_Pos)             /*!< 0x00000010 */
#define GPIO_BSRR_BS4                  GPIO_BSRR_BS4_Msk
#define GPIO_BSRR_BS5_Pos              (5U)
#define GPIO_BSRR_BS5_Msk              (0x1UL << GPIO_BSRR_BS5_Pos)             /*!< 0x00000020 */
#define GPIO_BSRR_BS5                  GPIO_BSRR_BS5_Msk
#define GPIO_BSRR_BS6_Pos              (6U)
#define GPIO_BSRR_BS6_Msk              (0x1UL << GPIO_BSRR_BS6_Pos)             /*!< 0x00000040 */
#define GPIO_BSRR_BS6                  GPIO_BSRR_BS6_Msk
#define GPIO_BSRR_BS7_Pos              (7U)
#define GPIO_BSRR_BS7_Msk              (0x1UL << GPIO_BSRR_BS7_Pos)             /*!< 0x00000080 */
#define GPIO_BSRR_BS7                  GPIO_BSRR_BS7_Msk
#define GPIO_BSRR_BS8_Pos              (8U)
#define GPIO_BSRR_BS8_Msk              (0x1UL << GPIO_BSRR_BS8_Pos)             /*!< 0x00000100 */
#define GPIO_BSRR_BS8                  GPIO_BSRR_BS8_Msk
#define GPIO_BSRR_BS9_Pos              (9U)
#define GPIO_BSRR_BS9_Msk              (0x1UL << GPIO_BSRR_BS9_Pos)             /*!< 0x00000200 */
#define GPIO_BSRR_BS9                  GPIO_BSRR_BS9_Msk
#define GPIO_BSRR_BS10_Pos             (10U)
#define GPIO_BSRR_BS10_Msk             (0x1UL << GPIO_BSRR_BS10_Pos)            /*!< 0x00000400 */
#define GPIO_BSRR_BS10                 GPIO_BSRR_BS10_Msk
#define GPIO_BSRR_BS11_Pos             (11U)
#define GPIO_BSRR_BS11_Msk             (0x1UL << GPIO_BSRR_BS11_Pos)            /*!< 0x00000800 */
#define GPIO_BSRR_BS11                 GPIO_BSRR_BS11_Msk
#define GPIO_BSRR_BS12_Pos             (12U)
#define GPIO_BSRR_BS12_Msk             (0x1UL << GPIO_BSRR_BS12_Pos)            /*!< 0x00001000 */
#define GPIO_BSRR_BS12                 GPIO_BSRR_BS12_Msk
#define GPIO_BSRR_BS13_Pos             (13U)
#define GPIO_BSRR_BS13_Msk             (0x1UL << GPIO_BSRR_BS13_Pos)            /*!< 0x00002000 */
#define GPIO_BSRR_BS13                 GPIO_BSRR_BS13_Msk
#define GPIO_BSRR_BS14_Pos             (14U)
#define GPIO_BSRR_BS14_Msk             (0x1UL << GPIO_BSRR_BS14_Pos)            /*!< 0x00004000 */
#define GPIO_BSRR_BS14                 GPIO_BSRR_BS14_Msk
#define GPIO_BSRR_BS15_Pos             (15U)
#define GPIO_BSRR_BS15_Msk             (0x1UL << GPIO_BSRR_BS15_Pos)            /*!< 0x00008000 */
#define GPIO_BSRR_BS15                 GPIO_BSRR_BS15_Msk
#define GPIO_BSRR_BR0_Pos              (16U)
#define GPIO_BSRR_BR0_Msk              (0x1UL << GPIO_BSRR_BR0_Pos)             /*!< 0x00010000 */
#define GPIO_BSRR_BR0                  GPIO_BSRR_BR0_Msk
#define GPIO_BSRR_BR1_Pos              (17U)
#define GPIO_BSRR_BR1_Msk              (0x1UL << GPIO_BSRR_BR1_Pos)             /*!< 0x00020000 */
#define GPIO_BSRR_BR1                  GPIO_BSRR_BR1_Msk
#define GPIO_BSRR_BR2_Pos              (18U)
#define GPIO_BSRR_BR2_Msk              (0x1UL << GPIO_BSRR_BR2_Pos)             /*!< 0x00040000 */
#define GPIO_BSRR_BR2                  GPIO_BSRR_BR2_Msk
#define GPIO_BSRR_BR3_Pos              (19U)
#define GPIO_BSRR_BR3_Msk              (0x1UL << GPIO_BSRR_BR3_Pos)             /*!< 0x00080000 */
#define GPIO_BSRR_BR3                  GPIO_BSRR_BR3_Msk
#define GPIO_BSRR_BR4_Pos              (20U)
#define GPIO_BSRR_BR4_Msk              (0x1UL << GPIO_BSRR_BR4_Pos)             /*!< 0x00100000 */
#define GPIO_BSRR_BR4                  GPIO_BSRR_BR4_Msk
#define GPIO_BSRR_BR5_Pos              (21U)
#define GPIO_BSRR_BR5_Msk              (0x1UL << GPIO_BSRR_BR5_Pos)             /*!< 0x00200000 */
#define GPIO_BSRR_BR5                  GPIO_BSRR_BR5_Msk
#define GPIO_BSRR_BR6_Pos              (22U)
#define GPIO_BSRR_BR6_Msk              (0x1UL << GPIO_BSRR_BR6_Pos)             /*!< 0x00400000 */
#define GPIO_BSRR_BR6                  GPIO_BSRR_BR6_Msk
#define GPIO_BSRR_BR7_Pos              (23U)
#define GPIO_BSRR_BR7_Msk              (0x1UL << GPIO_BSRR_BR7_Pos)             /*!< 0x00800000 */
#define GPIO_BSRR_BR7                  GPIO_BSRR_BR7_Msk
#define GPIO_BSRR_BR8_Pos              (24U)
#define GPIO_BSRR_BR8_Msk              (0x1UL << GPIO_BSRR_BR8_Pos)             /*!< 0x01000000 */
#define GPIO_BSRR_BR8                  GPIO_BSRR_BR8_Msk
#define GPIO_BSRR_BR9_Pos              (25U)
#define GPIO_BSRR_BR9_Msk              (0x1UL << GPIO_BSRR_BR9_Pos)             /*!< 0x02000000 */
#define GPIO_BSRR_BR9                  GPIO_BSRR_BR9_Msk
#define GPIO_BSRR_BR10_Pos             (26U)
#define GPIO_BSRR_BR10_Msk             (0x1UL << GPIO_BSRR_BR10_Pos)            /*!< 0x04000000 */
#define GPIO_BSRR_BR10                 GPIO_BSRR_BR10_Msk
#define GPIO_BSRR_BR11_Pos             (27U)
#define GPIO_BSRR_BR11_Msk             (0x1UL << GPIO_BSRR_BR11_Pos)            /*!< 0x08000000 */
#define GPIO_BSRR_BR11                 GPIO_BSRR_BR11_Msk
#define GPIO_BSRR_BR12_Pos             (28U)
#define GPIO_BSRR_BR12_Msk             (0x1UL << GPIO_BSRR_BR12_Pos)            /*!< 0x10000000 */
#define GPIO_BSRR_BR12                 GPIO_BSRR_BR12_Msk
#define GPIO_BSRR_BR13_Pos             (29U)
#define GPIO_BSRR_BR13_Msk             (0x1UL << GPIO_BSRR_BR13_Pos)            /*!< 0x20000000 */
#define GPIO_BSRR_BR13                 GPIO_BSRR_BR13_Msk
#define GPIO_BSRR_BR14_Pos             (30U)
#define GPIO_BSRR_BR14_Msk             (0x1UL << GPIO_BSRR_BR14_Pos)            /*!< 0x40000000 */
#define GPIO_BSRR_BR14                 GPIO_BSRR_BR14_Msk
#define GPIO_BSRR_BR15_Pos             (31U)
#define GPIO_BSRR_BR15_Msk             (0x1UL << GPIO_BSRR_BR15_Pos)            /*!< 0x80000000 */
#define GPIO_BSRR_BR15                 GPIO_BSRR_BR15_Msk

/****************** Bit definition for GPIO_LCKR register *********************/
#define GPIO_LCKR_LCK0_Pos             (0U)
#define GPIO_LCKR_LCK0_Msk             (0x1UL << GPIO_LCKR_LCK0_Pos)            /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                 GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos             (1U)
#define GPIO_LCKR_LCK1_Msk             (0x1UL << GPIO_LCKR_LCK1_Pos)            /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                 GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos             (2U)
#define GPIO_LCKR_LCK2_Msk             (0x1UL << GPIO_LCKR_LCK2_Pos)            /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                 GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos             (3U)
#define GPIO_LCKR_LCK3_Msk             (0x1UL << GPIO_LCKR_LCK3_Pos)            /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                 GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos             (4U)
#define GPIO_LCKR_LCK4_Msk             (0x1UL << GPIO_LCKR_LCK4_Pos)            /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                 GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos             (5U)
#define GPIO_LCKR_LCK5_Msk             (0x1UL << GPIO_LCKR_LCK5_Pos)            /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                 GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos             (6U)
#define GPIO_LCKR_LCK6_Msk             (0x1UL << GPIO_LCKR_LCK6_Pos)            /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                 GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos             (7U)
#define GPIO_LCKR_LCK7_Msk             (0x1UL << GPIO_LCKR_LCK7_Pos)            /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                 GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos             (8U)
#define GPIO_LCKR_LCK8_Msk             (0x1UL << GPIO_LCKR_LCK8_Pos)            /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                 GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos             (9U)
#define GPIO_LCKR_LCK9_Msk             (0x1UL << GPIO_LCKR_LCK9_Pos)            /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                 GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos            (10U)
#define GPIO_LCKR_LCK10_Msk            (0x1UL << GPIO_LCKR_LCK10_Pos)           /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos            (11U)
#define GPIO_LCKR_LCK11_Msk            (0x1UL << GPIO_LCKR_LCK11_Pos)           /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos            (12U)
#define GPIO_LCKR_LCK12_Msk            (0x1UL << GPIO_LCKR_LCK12_Pos)           /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos            (13U)
#define GPIO_LCKR_LCK13_Msk            (0x1UL << GPIO_LCKR_LCK13_Pos)           /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos            (14U)
#define GPIO_LCKR_LCK14_Msk            (0x1UL << GPIO_LCKR_LCK14_Pos)           /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos            (15U)
#define GPIO_LCKR_LCK15_Msk            (0x1UL << GPIO_LCKR_LCK15_Pos)           /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos             (16U)
#define GPIO_LCKR_LCKK_Msk             (0x1UL << GPIO_LCKR_LCKK_Pos)            /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                 GPIO_LCKR_LCKK_Msk

/****************** Bit definition for GPIO_AFRL register *********************/
#define GPIO_AFRL_AFSEL0_Pos           (0U)
#define GPIO_AFRL_AFSEL0_Msk           (0xFUL << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x0000000F */
#define GPIO_AFRL_AFSEL0               GPIO_AFRL_AFSEL0_Msk
#define GPIO_AFRL_AFSEL0_0             (0x1UL << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000001 */
#define GPIO_AFRL_AFSEL0_1             (0x2UL << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000002 */
#define GPIO_AFRL_AFSEL0_2             (0x4UL << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000004 */
#define GPIO_AFRL_AFSEL0_3             (0x8UL << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000008 */
#define GPIO_AFRL_AFSEL1_Pos           (4U)
#define GPIO_AFRL_AFSEL1_Msk           (0xFUL << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x000000F0 */
#define GPIO_AFRL_AFSEL1               GPIO_AFRL_AFSEL1_Msk
#define GPIO_AFRL_AFSEL1_0             (0x1UL << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000010 */
#define GPIO_AFRL_AFSEL1_1             (0x2UL << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000020 */
#define GPIO_AFRL_AFSEL1_2             (0x4UL << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000040 */
#define GPIO_AFRL_AFSEL1_3             (0x8UL << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000080 */
#define GPIO_AFRL_AFSEL2_Pos           (8U)
#define GPIO_AFRL_AFSEL2_Msk           (0xFUL << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000F00 */
#define GPIO_AFRL_AFSEL2               GPIO_AFRL_AFSEL2_Msk
#define GPIO_AFRL_AFSEL2_0             (0x1UL << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000100 */
#define GPIO_AFRL_AFSEL2_1             (0x2UL << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000200 */
#define GPIO_AFRL_AFSEL2_2             (0x4UL << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000400 */
#define GPIO_AFRL_AFSEL2_3             (0x8UL << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000800 */
#define GPIO_AFRL_AFSEL3_Pos           (12U)
#define GPIO_AFRL_AFSEL3_Msk           (0xFUL << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x0000F000 */
#define GPIO_AFRL_AFSEL3               GPIO_AFRL_AFSEL3_Msk
#define GPIO_AFRL_AFSEL3_0             (0x1UL << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00001000 */
#define GPIO_AFRL_AFSEL3_1             (0x2UL << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00002000 */
#define GPIO_AFRL_AFSEL3_2             (0x4UL << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00004000 */
#define GPIO_AFRL_AFSEL3_3             (0x8UL << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00008000 */
#define GPIO_AFRL_AFSEL4_Pos           (16U)
#define GPIO_AFRL_AFSEL4_Msk           (0xFUL << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x000F0000 */
#define GPIO_AFRL_AFSEL4               GPIO_AFRL_AFSEL4_Msk
#define GPIO_AFRL_AFSEL4_0             (0x1UL << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00010000 */
#define GPIO_AFRL_AFSEL4_1             (0x2UL << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00020000 */
#define GPIO_AFRL_AFSEL4_2             (0x4UL << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00040000 */
#define GPIO_AFRL_AFSEL4_3             (0x8UL << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00080000 */
#define GPIO_AFRL_AFSEL5_Pos           (20U)
#define GPIO_AFRL_AFSEL5_Msk           (0xFUL << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00F00000 */
#define GPIO_AFRL_AFSEL5               GPIO_AFRL_AFSEL5_Msk
#define GPIO_AFRL_AFSEL5_0             (0x1UL << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00100000 */
#define GPIO_AFRL_AFSEL5_1             (0x2UL << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00200000 */
#define GPIO_AFRL_AFSEL5_2             (0x4UL << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00400000 */
#define GPIO_AFRL_AFSEL5_3             (0x8UL << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00800000 */
#define GPIO_AFRL_AFSEL6_Pos           (24U)
#define GPIO_AFRL_AFSEL6_Msk           (0xFUL << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x0F000000 */
#define GPIO_AFRL_AFSEL6               GPIO_AFRL_AFSEL6_Msk
#define GPIO_AFRL_AFSEL6_0             (0x1UL << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x01000000 */
#define GPIO_AFRL_AFSEL6_1             (0x2UL << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x02000000 */
#define GPIO_AFRL_AFSEL6_2             (0x4UL << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x04000000 */
#define GPIO_AFRL_AFSEL6_3             (0x8UL << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x08000000 */
#define GPIO_AFRL_AFSEL7_Pos           (28U)
#define GPIO_AFRL_AFSEL7_Msk           (0xFUL << GPIO_AFRL_AFSEL7_Pos)          /*!< 0xF0000000 */
#define GPIO_AFRL_AFSEL7               GPIO_AFRL_AFSEL7_Msk
#define GPIO_AFRL_AFSEL7_0             (0x1UL << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x10000000 */
#define GPIO_AFRL_AFSEL7_1             (0x2UL << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x20000000 */
#define GPIO_AFRL_AFSEL7_2             (0x4UL << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x40000000 */
#define GPIO_AFRL_AFSEL7_3             (0x8UL << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x80000000 */

/****************** Bit definition for GPIO_AFRH register *********************/
#define GPIO_AFRH_AFSEL8_Pos           (0U)
#define GPIO_AFRH_AFSEL8_Msk           (0xFUL << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x0000000F */
#define GPIO_AFRH_AFSEL8               GPIO_AFRH_AFSEL8_Msk
#define GPIO_AFRH_AFSEL8_0             (0x1UL << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000001 */
#define GPIO_AFRH_AFSEL8_1             (0x2UL << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000002 */
#define GPIO_AFRH_AFSEL8_2             (0x4UL << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000004 */
#define GPIO_AFRH_AFSEL8_3             (0x8UL << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000008 */
#define GPIO_AFRH_AFSEL9_Pos           (4U)
#define GPIO_AFRH_AFSEL9_Msk           (0xFUL << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x000000F0 */
#define GPIO_AFRH_AFSEL9               GPIO_AFRH_AFSEL9_Msk
#define GPIO_AFRH_AFSEL9_0             (0x1UL << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000010 */
#define GPIO_AFRH_AFSEL9_1             (0x2UL << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000020 */
#define GPIO_AFRH_AFSEL9_2             (0x4UL << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000040 */
#define GPIO_AFRH_AFSEL9_3             (0x8UL << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000080 */
#define GPIO_AFRH_AFSEL10_Pos          (8U)
#define GPIO_AFRH_AFSEL10_Msk          (0xFUL << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000F00 */
#define GPIO_AFRH_AFSEL10              GPIO_AFRH_AFSEL10_Msk
#define GPIO_AFRH_AFSEL10_0            (0x1UL << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000100 */
#define GPIO_AFRH_AFSEL10_1            (0x2UL << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000200 */
#define GPIO_AFRH_AFSEL10_2            (0x4UL << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000400 */
#define GPIO_AFRH_AFSEL10_3            (0x8UL << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000800 */
#define GPIO_AFRH_AFSEL11_Pos          (12U)
#define GPIO_AFRH_AFSEL11_Msk          (0xFUL << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x0000F000 */
#define GPIO_AFRH_AFSEL11              GPIO_AFRH_AFSEL11_Msk
#define GPIO_AFRH_AFSEL11_0            (0x1UL << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00001000 */
#define GPIO_AFRH_AFSEL11_1            (0x2UL << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00002000 */
#define GPIO_AFRH_AFSEL11_2            (0x4UL << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00004000 */
#define GPIO_AFRH_AFSEL11_3            (0x8UL << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00008000 */
#define GPIO_AFRH_AFSEL12_Pos          (16U)
#define GPIO_AFRH_AFSEL12_Msk          (0xFUL << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x000F0000 */
#define GPIO_AFRH_AFSEL12              GPIO_AFRH_AFSEL12_Msk
#define GPIO_AFRH_AFSEL12_0            (0x1UL << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00010000 */
#define GPIO_AFRH_AFSEL12_1            (0x2UL << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00020000 */
#define GPIO_AFRH_AFSEL12_2            (0x4UL << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00040000 */
#define GPIO_AFRH_AFSEL12_3            (0x8UL << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00080000 */
#define GPIO_AFRH_AFSEL13_Pos          (20U)
#define GPIO_AFRH_AFSEL13_Msk          (0xFUL << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00F00000 */
#define GPIO_AFRH_AFSEL13              GPIO_AFRH_AFSEL13_Msk
#define GPIO_AFRH_AFSEL13_0            (0x1UL << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00100000 */
#define GPIO_AFRH_AFSEL13_1            (0x2UL << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00200000 */
#define GPIO_AFRH_AFSEL13_2            (0x4UL << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00400000 */
#define GPIO_AFRH_AFSEL13_3            (0x8UL << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00800000 */
#define GPIO_AFRH_AFSEL14_Pos          (24U)
#define GPIO_AFRH_AFSEL14_Msk          (0xFUL << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x0F000000 */
#define GPIO_AFRH_AFSEL14              GPIO_AFRH_AFSEL14_Msk
#define GPIO_AFRH_AFSEL14_0            (0x1UL << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x01000000 */
#define GPIO_AFRH_AFSEL14_1            (0x2UL << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x02000000 */
#define GPIO_AFRH_AFSEL14_2            (0x4UL << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x04000000 */
#define GPIO_AFRH_AFSEL14_3            (0x8UL << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x08000000 */
#define GPIO_AFRH_AFSEL15_Pos          (28U)
#define GPIO_AFRH_AFSEL15_Msk          (0xFUL << GPIO_AFRH_AFSEL15_Pos)         /*!< 0xF0000000 */
#define GPIO_AFRH_AFSEL15              GPIO_AFRH_AFSEL15_Msk
#define GPIO_AFRH_AFSEL15_0            (0x1UL << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x10000000 */
#define GPIO_AFRH_AFSEL15_1            (0x2UL << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x20000000 */
#define GPIO_AFRH_AFSEL15_2            (0x4UL << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x40000000 */
#define GPIO_AFRH_AFSEL15_3            (0x8UL << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x80000000 */

/******************  Bits definition for GPIO_BRR register  ******************/
#define GPIO_BRR_BR0_Pos               (0U)
#define GPIO_BRR_BR0_Msk               (0x1UL << GPIO_BRR_BR0_Pos)              /*!< 0x00000001 */
#define GPIO_BRR_BR0                   GPIO_BRR_BR0_Msk
#define GPIO_BRR_BR1_Pos               (1U)
#define GPIO_BRR_BR1_Msk               (0x1UL << GPIO_BRR_BR1_Pos)              /*!< 0x00000002 */
#define GPIO_BRR_BR1                   GPIO_BRR_BR1_Msk
#define GPIO_BRR_BR2_Pos               (2U)
#define GPIO_BRR_BR2_Msk               (0x1UL << GPIO_BRR_BR2_Pos)              /*!< 0x00000004 */
#define GPIO_BRR_BR2                   GPIO_BRR_BR2_Msk
#define GPIO_BRR_BR3_Pos               (3U)
#define GPIO_BRR_BR3_Msk               (0x1UL << GPIO_BRR_BR3_Pos)              /*!< 0x00000008 */
#define GPIO_BRR_BR3                   GPIO_BRR_BR3_Msk
#define GPIO_BRR_BR4_Pos               (4U)
#define GPIO_BRR_BR4_Msk               (0x1UL << GPIO_BRR_BR4_Pos)              /*!< 0x00000010 */
#define GPIO_BRR_BR4                   GPIO_BRR_BR4_Msk
#define GPIO_BRR_BR5_Pos               (5U)
#define GPIO_BRR_BR5_Msk               (0x1UL << GPIO_BRR_BR5_Pos)              /*!< 0x00000020 */
#define GPIO_BRR_BR5                   GPIO_BRR_BR5_Msk
#define GPIO_BRR_BR6_Pos               (6U)
#define GPIO_BRR_BR6_Msk               (0x1UL << GPIO_BRR_BR6_Pos)              /*!< 0x00000040 */
#define GPIO_BRR_BR6                   GPIO_BRR_BR6_Msk
#define GPIO_BRR_BR7_Pos               (7U)
#define GPIO_BRR_BR7_Msk               (0x1UL << GPIO_BRR_BR7_Pos)              /*!< 0x00000080 */
#define GPIO_BRR_BR7                   GPIO_BRR_BR7_Msk
#define GPIO_BRR_BR8_Pos               (8U)
#define GPIO_BRR_BR8_Msk               (0x1UL << GPIO_BRR_BR8_Pos)              /*!< 0x00000100 */
#define GPIO_BRR_BR8                   GPIO_BRR_BR8_Msk
#define GPIO_BRR_BR9_Pos               (9U)
#define GPIO_BRR_BR9_Msk               (0x1UL << GPIO_BRR_BR9_Pos)              /*!< 0x00000200 */
#define GPIO_BRR_BR9                   GPIO_BRR_BR9_Msk
#define GPIO_BRR_BR10_Pos              (10U)
#define GPIO_BRR_BR10_Msk              (0x1UL << GPIO_BRR_BR10_Pos)             /*!< 0x00000400 */
#define GPIO_BRR_BR10                  GPIO_BRR_BR10_Msk
#define GPIO_BRR_BR11_Pos              (11U)
#define GPIO_BRR_BR11_Msk              (0x1UL << GPIO_BRR_BR11_Pos)             /*!< 0x00000800 */
#define GPIO_BRR_BR11                  GPIO_BRR_BR11_Msk
#define GPIO_BRR_BR12_Pos              (12U)
#define GPIO_BRR_BR12_Msk              (0x1UL << GPIO_BRR_BR12_Pos)             /*!< 0x00001000 */
#define GPIO_BRR_BR12                  GPIO_BRR_BR12_Msk
#define GPIO_BRR_BR13_Pos              (13U)
#define GPIO_BRR_BR13_Msk              (0x1UL << GPIO_BRR_BR13_Pos)             /*!< 0x00002000 */
#define GPIO_BRR_BR13                  GPIO_BRR_BR13_Msk
#define GPIO_BRR_BR14_Pos              (14U)
#define GPIO_BRR_BR14_Msk              (0x1UL << GPIO_BRR_BR14_Pos)             /*!< 0x00004000 */
#define GPIO_BRR_BR14                  GPIO_BRR_BR14_Msk
#define GPIO_BRR_BR15_Pos              (15U)
#define GPIO_BRR_BR15_Msk              (0x1UL << GPIO_BRR_BR15_Pos)             /*!< 0x00008000 */
#define GPIO_BRR_BR15                  GPIO_BRR_BR15_Msk


/********************************************************************************************************************/
/********************************* I2C ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for I2C_CR1 register **********************************************/
#define I2C_CR1_PE_Pos                            (0U)
#define I2C_CR1_PE_Msk                            (0x1UL<<I2C_CR1_PE_Pos)                           /*!< 0x00000001 */
#define I2C_CR1_PE                                I2C_CR1_PE_Msk                                    /*!< Peripheral enable */
#define I2C_CR1_SMBUS_Pos                         (1U)
#define I2C_CR1_SMBUS_Msk                         (0x1UL<<I2C_CR1_SMBUS_Pos)                        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                             I2C_CR1_SMBUS_Msk                                 /*!< SMBus mode */
#define I2C_CR1_WUPEN_Pos                         (2U)
#define I2C_CR1_WUPEN_Msk                         (0x1UL<<I2C_CR1_WUPEN_Pos)                        /*!< 0x00000004 */
#define I2C_CR1_WUPEN                             I2C_CR1_WUPEN_Msk                                 /*!< Wakeup from Stop mode enable */
#define I2C_CR1_SMBTYPE_Pos                       (3U)
#define I2C_CR1_SMBTYPE_Msk                       (0x1UL<<I2C_CR1_SMBTYPE_Pos)                      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                           I2C_CR1_SMBTYPE_Msk                               /*!< SMBus type */
#define I2C_CR1_ENARP_Pos                         (4U)
#define I2C_CR1_ENARP_Msk                         (0x1UL<<I2C_CR1_ENARP_Pos)                        /*!< 0x00000010 */
#define I2C_CR1_ENARP                             I2C_CR1_ENARP_Msk                                 /*!< ARP enable */
#define I2C_CR1_ENPEC_Pos                         (5U)
#define I2C_CR1_ENPEC_Msk                         (0x1UL<<I2C_CR1_ENPEC_Pos)                        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                             I2C_CR1_ENPEC_Msk                                 /*!< PEC enable */
#define I2C_CR1_ENGC_Pos                          (6U)
#define I2C_CR1_ENGC_Msk                          (0x1UL<<I2C_CR1_ENGC_Pos)                         /*!< 0x00000040 */
#define I2C_CR1_ENGC                              I2C_CR1_ENGC_Msk                                  /*!< General call enable */
#define I2C_CR1_NOSTRETCH_Pos                     (7U)
#define I2C_CR1_NOSTRETCH_Msk                     (0x1UL<<I2C_CR1_NOSTRETCH_Pos)                    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                         I2C_CR1_NOSTRETCH_Msk                             /*!< Clock stretching disable (Slave mode) */
#define I2C_CR1_START_Pos                         (8U)
#define I2C_CR1_START_Msk                         (0x1UL<<I2C_CR1_START_Pos)                        /*!< 0x00000100 */
#define I2C_CR1_START                             I2C_CR1_START_Msk                                 /*!< Start generation */
#define I2C_CR1_STOP_Pos                          (9U)
#define I2C_CR1_STOP_Msk                          (0x1UL<<I2C_CR1_STOP_Pos)                         /*!< 0x00000200 */
#define I2C_CR1_STOP                              I2C_CR1_STOP_Msk                                  /*!< Stop generation */
#define I2C_CR1_ACK_Pos                           (10U)
#define I2C_CR1_ACK_Msk                           (0x1UL<<I2C_CR1_ACK_Pos)                          /*!< 0x00000400 */
#define I2C_CR1_ACK                               I2C_CR1_ACK_Msk                                   /*!< Acknowledge enable */
#define I2C_CR1_POS_Pos                           (11U)
#define I2C_CR1_POS_Msk                           (0x1UL<<I2C_CR1_POS_Pos)                          /*!< 0x00000800 */
#define I2C_CR1_POS                               I2C_CR1_POS_Msk                                   /*!< Acknowledge(for data reception) */
#define I2C_CR1_PEC_Pos                           (12U)
#define I2C_CR1_PEC_Msk                           (0x1UL<<I2C_CR1_PEC_Pos)                          /*!< 0x00001000 */
#define I2C_CR1_PEC                               I2C_CR1_PEC_Msk                                   /*!< Packet error checking */
#define I2C_CR1_ALERT_Pos                         (13U)
#define I2C_CR1_ALERT_Msk                         (0x1UL<<I2C_CR1_ALERT_Pos)                        /*!< 0x00002000 */
#define I2C_CR1_ALERT                             I2C_CR1_ALERT_Msk                                 /*!< SMBus alert */
#define I2C_CR1_SWRST_Pos                         (15U)
#define I2C_CR1_SWRST_Msk                         (0x1UL<<I2C_CR1_SWRST_Pos)                        /*!< 0x00008000 */
#define I2C_CR1_SWRST                             I2C_CR1_SWRST_Msk                                 /*!< Software reset */
#define I2C_CR1_WKUP_DIV_Pos                      (16U)
#define I2C_CR1_WKUP_DIV_Msk                      (0x3UL<<I2C_CR1_WKUP_DIV_Pos)                     /*!< 0x00030000 */
#define I2C_CR1_WKUP_DIV                          I2C_CR1_WKUP_DIV_Msk                              /*!< PCLK division */
#define I2C_CR1_WKUP_DIV_0                        (0x1UL<<I2C_CR1_WKUP_DIV_Pos)                     /*!< 0x00010000 */
#define I2C_CR1_WKUP_DIV_1                        (0x2UL<<I2C_CR1_WKUP_DIV_Pos)                     /*!< 0x00020000 */
#define I2C_CR1_WKUP_CNT_Pos                      (18U)
#define I2C_CR1_WKUP_CNT_Msk                      (0x3UL<<I2C_CR1_WKUP_CNT_Pos)                     /*!< 0x000C0000 */
#define I2C_CR1_WKUP_CNT                          I2C_CR1_WKUP_CNT_Msk                              /*!< Timeout count number */
#define I2C_CR1_WKUP_CNT_0                        (0x1UL<<I2C_CR1_WKUP_CNT_Pos)                     /*!< 0x00040000 */
#define I2C_CR1_WKUP_CNT_1                        (0x2UL<<I2C_CR1_WKUP_CNT_Pos)                     /*!< 0x00080000 */

/********************************* Bit definition for I2C_CR2 register **********************************************/
#define I2C_CR2_FREQ_Pos                          (0U)
#define I2C_CR2_FREQ_Msk                          (0x7FUL<<I2C_CR2_FREQ_Pos)                        /*!< 0x0000007F */
#define I2C_CR2_FREQ                              I2C_CR2_FREQ_Msk                                  /*!< Peripheral clock frequency */
#define I2C_CR2_ITERREN_Pos                       (8U)
#define I2C_CR2_ITERREN_Msk                       (0x1UL<<I2C_CR2_ITERREN_Pos)                      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                           I2C_CR2_ITERREN_Msk                               /*!< Error interrupt enable */
#define I2C_CR2_ITEVTEN_Pos                       (9U)
#define I2C_CR2_ITEVTEN_Msk                       (0x1UL<<I2C_CR2_ITEVTEN_Pos)                      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                           I2C_CR2_ITEVTEN_Msk                               /*!< Event interrupt enable */
#define I2C_CR2_ITBUFEN_Pos                       (10U)
#define I2C_CR2_ITBUFEN_Msk                       (0x1UL<<I2C_CR2_ITBUFEN_Pos)                      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                           I2C_CR2_ITBUFEN_Msk                               /*!< Buffer interrupt enable */
#define I2C_CR2_DMAEN_Pos                         (11U)
#define I2C_CR2_DMAEN_Msk                         (0x1UL<<I2C_CR2_DMAEN_Pos)                        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                             I2C_CR2_DMAEN_Msk                                 /*!< DMA requests enable */
#define I2C_CR2_LAST_Pos                          (12U)
#define I2C_CR2_LAST_Msk                          (0x1UL<<I2C_CR2_LAST_Pos)                         /*!< 0x00001000 */
#define I2C_CR2_LAST                              I2C_CR2_LAST_Msk                                  /*!< DMA last transfer */

/********************************* Bit definition for I2C_OAR1 register *********************************************/
#define I2C_OAR1_ADD0_Pos                         (0U)
#define I2C_OAR1_ADD0_Msk                         (0x1UL << I2C_OAR1_ADD0_Pos)                      /*!< 0x00000001 */
#define I2C_OAR1_ADD0                             I2C_OAR1_ADD0_Msk                                 /*!< desc ADD0 */
#define I2C_OAR1_ADD1_Pos                         (1U)
#define I2C_OAR1_ADD1_Msk                         (0x1UL << I2C_OAR1_ADD1_Pos)                      /*!< 0x00000002 */
#define I2C_OAR1_ADD1                             I2C_OAR1_ADD1_Msk                                 /*!< Bit 1 */
#define I2C_OAR1_ADD2_Pos                         (2U)
#define I2C_OAR1_ADD2_Msk                         (0x1UL << I2C_OAR1_ADD2_Pos)                      /*!< 0x00000004 */
#define I2C_OAR1_ADD2                             I2C_OAR1_ADD2_Msk                                 /*!< Bit 2 */
#define I2C_OAR1_ADD3_Pos                         (3U)
#define I2C_OAR1_ADD3_Msk                         (0x1UL << I2C_OAR1_ADD3_Pos)                      /*!< 0x00000008 */
#define I2C_OAR1_ADD3                             I2C_OAR1_ADD3_Msk                                 /*!< Bit 3 */
#define I2C_OAR1_ADD4_Pos                         (4U)
#define I2C_OAR1_ADD4_Msk                         (0x1UL << I2C_OAR1_ADD4_Pos)                      /*!< 0x00000010 */
#define I2C_OAR1_ADD4                             I2C_OAR1_ADD4_Msk                                 /*!< Bit 4 */
#define I2C_OAR1_ADD5_Pos                         (5U)
#define I2C_OAR1_ADD5_Msk                         (0x1UL << I2C_OAR1_ADD5_Pos)                      /*!< 0x00000020 */
#define I2C_OAR1_ADD5                             I2C_OAR1_ADD5_Msk                                 /*!< Bit 5 */
#define I2C_OAR1_ADD6_Pos                         (6U)
#define I2C_OAR1_ADD6_Msk                         (0x1UL << I2C_OAR1_ADD6_Pos)                      /*!< 0x00000040 */
#define I2C_OAR1_ADD6                             I2C_OAR1_ADD6_Msk                                 /*!< Bit 6 */
#define I2C_OAR1_ADD7_Pos                         (7U)
#define I2C_OAR1_ADD7_Msk                         (0x1UL << I2C_OAR1_ADD7_Pos)                      /*!< 0x00000080 */
#define I2C_OAR1_ADD7                             I2C_OAR1_ADD7_Msk                                 /*!< Bit 7 */
#define I2C_OAR1_ADD8_Pos                         (8U)
#define I2C_OAR1_ADD8_Msk                         (0x1UL << I2C_OAR1_ADD8_Pos)                      /*!< 0x00000100 */
#define I2C_OAR1_ADD8                             I2C_OAR1_ADD8_Msk                                 /*!< Bit 8 */
#define I2C_OAR1_ADD9_Pos                         (9U)
#define I2C_OAR1_ADD9_Msk                         (0x1UL << I2C_OAR1_ADD9_Pos)                      /*!< 0x00000200 */
#define I2C_OAR1_ADD9                             I2C_OAR1_ADD9_Msk                                 /*!< Bit 9 */

#define I2C_OAR1_ADD1_7                           0x000000FEU                                       /*!< Interface Address */
#define I2C_OAR1_ADD8_9                           0x00000300U                                       /*!< Interface Address */
#define I2C_OAR1_ADD_Pos                          (0U)
#define I2C_OAR1_ADD_Msk                          (0x3FFUL<<I2C_OAR1_ADD_Pos)                       /*!< 0x000003FF */
#define I2C_OAR1_ADD                              I2C_OAR1_ADD_Msk                                  /*!< Interface address */
#define I2C_OAR1_ADDMODE_Pos                      (15U)
#define I2C_OAR1_ADDMODE_Msk                      (0x1UL<<I2C_OAR1_ADDMODE_Pos)                     /*!< 0x00008000 */
#define I2C_OAR1_ADDMODE                          I2C_OAR1_ADDMODE_Msk                              /*!< Addressing mode (slave mode) */

/********************************* Bit definition for I2C_OAR2 register *********************************************/
#define I2C_OAR2_ENDUAL_Pos                       (0U)
#define I2C_OAR2_ENDUAL_Msk                       (0x1UL<<I2C_OAR2_ENDUAL_Pos)                      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                           I2C_OAR2_ENDUAL_Msk                               /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                         (1U)
#define I2C_OAR2_ADD2_Msk                         (0x7FUL<<I2C_OAR2_ADD2_Pos)                       /*!< 0x000000FE */
#define I2C_OAR2_ADD2                             I2C_OAR2_ADD2_Msk                                 /*!< Interface address */
#define I2C_OAR2_OA2MSK_Pos                       (8U)
#define I2C_OAR2_OA2MSK_Msk                       (0x7UL<<I2C_OAR2_OA2MSK_Pos)                      /*!< 0x00000700 */
#define I2C_OAR2_OA2MSK                           I2C_OAR2_OA2MSK_Msk                               /*!< Own Address 2 masks */
#define I2C_OAR2_OA2MSK_0                         (0x1UL<<I2C_OAR2_OA2MSK_Pos)                      /*!< 0x00000100 */
#define I2C_OAR2_OA2MSK_1                         (0x2UL<<I2C_OAR2_OA2MSK_Pos)                      /*!< 0x00000200 */
#define I2C_OAR2_OA2MSK_2                         (0x4UL<<I2C_OAR2_OA2MSK_Pos)                      /*!< 0x00000400 */

/********************************* Bit definition for I2C_DR register ***********************************************/
#define I2C_DR_DR_Pos                             (0U)
#define I2C_DR_DR_Msk                             (0xFFUL<<I2C_DR_DR_Pos)                           /*!< 0x000000FF */
#define I2C_DR_DR                                 I2C_DR_DR_Msk                                     /*!< 8-bit data register */

/********************************* Bit definition for I2C_SR1 register **********************************************/
#define I2C_SR1_SB_Pos                            (0U)
#define I2C_SR1_SB_Msk                            (0x1UL<<I2C_SR1_SB_Pos)                           /*!< 0x00000001 */
#define I2C_SR1_SB                                I2C_SR1_SB_Msk                                    /*!< Start bit (Master mode) */
#define I2C_SR1_ADDR_Pos                          (1U)
#define I2C_SR1_ADDR_Msk                          (0x1UL<<I2C_SR1_ADDR_Pos)                         /*!< 0x00000002 */
#define I2C_SR1_ADDR                              I2C_SR1_ADDR_Msk                                  /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                           (2U)
#define I2C_SR1_BTF_Msk                           (0x1UL<<I2C_SR1_BTF_Pos)                          /*!< 0x00000004 */
#define I2C_SR1_BTF                               I2C_SR1_BTF_Msk                                   /*!< Byte transfer finished */
#define I2C_SR1_ADD10_Pos                         (3U)
#define I2C_SR1_ADD10_Msk                         (0x1UL<<I2C_SR1_ADD10_Pos)                        /*!< 0x00000008 */
#define I2C_SR1_ADD10                             I2C_SR1_ADD10_Msk                                 /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                         (4U)
#define I2C_SR1_STOPF_Msk                         (0x1UL<<I2C_SR1_STOPF_Pos)                        /*!< 0x00000010 */
#define I2C_SR1_STOPF                             I2C_SR1_STOPF_Msk                                 /*!< Stop detection (slave mode) */
#define I2C_SR1_RXNE_Pos                          (6U)
#define I2C_SR1_RXNE_Msk                          (0x1UL<<I2C_SR1_RXNE_Pos)                         /*!< 0x00000040 */
#define I2C_SR1_RXNE                              I2C_SR1_RXNE_Msk                                  /*!< Data register not empty (receivers) */
#define I2C_SR1_TXE_Pos                           (7U)
#define I2C_SR1_TXE_Msk                           (0x1UL<<I2C_SR1_TXE_Pos)                          /*!< 0x00000080 */
#define I2C_SR1_TXE                               I2C_SR1_TXE_Msk                                   /*!< Data register empty (transmitters) */
#define I2C_SR1_BERR_Pos                          (8U)
#define I2C_SR1_BERR_Msk                          (0x1UL<<I2C_SR1_BERR_Pos)                         /*!< 0x00000100 */
#define I2C_SR1_BERR                              I2C_SR1_BERR_Msk                                  /*!< Bus error */
#define I2C_SR1_ARLO_Pos                          (9U)
#define I2C_SR1_ARLO_Msk                          (0x1UL<<I2C_SR1_ARLO_Pos)                         /*!< 0x00000200 */
#define I2C_SR1_ARLO                              I2C_SR1_ARLO_Msk                                  /*!< Arbitration lost (master mode) */
#define I2C_SR1_AF_Pos                            (10U)
#define I2C_SR1_AF_Msk                            (0x1UL<<I2C_SR1_AF_Pos)                           /*!< 0x00000400 */
#define I2C_SR1_AF                                I2C_SR1_AF_Msk                                    /*!< Acknowledge failure */
#define I2C_SR1_OVR_Pos                           (11U)
#define I2C_SR1_OVR_Msk                           (0x1UL<<I2C_SR1_OVR_Pos)                          /*!< 0x00000800 */
#define I2C_SR1_OVR                               I2C_SR1_OVR_Msk                                   /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                        (12U)
#define I2C_SR1_PECERR_Msk                        (0x1UL<<I2C_SR1_PECERR_Pos)                       /*!< 0x00001000 */
#define I2C_SR1_PECERR                            I2C_SR1_PECERR_Msk                                /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                       (14U)
#define I2C_SR1_TIMEOUT_Msk                       (0x1UL<<I2C_SR1_TIMEOUT_Pos)                      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                           I2C_SR1_TIMEOUT_Msk                               /*!< Timeout or Tlow error */
#define I2C_SR1_SMBALERT_Pos                      (15U)
#define I2C_SR1_SMBALERT_Msk                      (0x1UL<<I2C_SR1_SMBALERT_Pos)                     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                          I2C_SR1_SMBALERT_Msk                              /*!< SMBus alert */

/********************************* Bit definition for I2C_SR2 register **********************************************/
#define I2C_SR2_MSL_Pos                           (0U)
#define I2C_SR2_MSL_Msk                           (0x1UL<<I2C_SR2_MSL_Pos)                          /*!< 0x00000001 */
#define I2C_SR2_MSL                               I2C_SR2_MSL_Msk                                   /*!< Master/slave */
#define I2C_SR2_BUSY_Pos                          (1U)
#define I2C_SR2_BUSY_Msk                          (0x1UL<<I2C_SR2_BUSY_Pos)                         /*!< 0x00000002 */
#define I2C_SR2_BUSY                              I2C_SR2_BUSY_Msk                                  /*!< Bus busy */
#define I2C_SR2_TRA_Pos                           (2U)
#define I2C_SR2_TRA_Msk                           (0x1UL<<I2C_SR2_TRA_Pos)                          /*!< 0x00000004 */
#define I2C_SR2_TRA                               I2C_SR2_TRA_Msk                                   /*!< Transmitter/receiver */
#define I2C_SR2_GENCALL_Pos                       (4U)
#define I2C_SR2_GENCALL_Msk                       (0x1UL<<I2C_SR2_GENCALL_Pos)                      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                           I2C_SR2_GENCALL_Msk                               /*!< General call address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos                    (5U)
#define I2C_SR2_SMBDEFAULT_Msk                    (0x1UL<<I2C_SR2_SMBDEFAULT_Pos)                   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                        I2C_SR2_SMBDEFAULT_Msk                            /*!< SMBus device default address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                       (6U)
#define I2C_SR2_SMBHOST_Msk                       (0x1UL<<I2C_SR2_SMBHOST_Pos)                      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                           I2C_SR2_SMBHOST_Msk                               /*!< SMBus host header (Slave mode) */
#define I2C_SR2_DUALF_Pos                         (7U)
#define I2C_SR2_DUALF_Msk                         (0x1UL<<I2C_SR2_DUALF_Pos)                        /*!< 0x00000080 */
#define I2C_SR2_DUALF                             I2C_SR2_DUALF_Msk                                 /*!< Dual flag (Slave mode) */
#define I2C_SR2_PEC_Pos                           (8U)
#define I2C_SR2_PEC_Msk                           (0xFFUL<<I2C_SR2_PEC_Pos)                         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                               I2C_SR2_PEC_Msk                                   /*!< Packet error checking register */

/********************************* Bit definition for I2C_CCR register **********************************************/
#define I2C_CCR_CCR_Pos                           (0U)
#define I2C_CCR_CCR_Msk                           (0xFFFUL<<I2C_CCR_CCR_Pos)                        /*!< 0x00000FFF */
#define I2C_CCR_CCR                               I2C_CCR_CCR_Msk                                   /*!< Clock control register in Fm/Sm mode (Master mode) */
#define I2C_CCR_FP_Pos                            (13U)
#define I2C_CCR_FP_Msk                            (0x1UL<<I2C_CCR_FP_Pos)                           /*!< 0x00002000 */
#define I2C_CCR_FP                                I2C_CCR_FP_Msk                                    /*!< I2C master mode selection */
#define I2C_CCR_DUTY_Pos                          (14U)
#define I2C_CCR_DUTY_Msk                          (0x1UL<<I2C_CCR_DUTY_Pos)                         /*!< 0x00004000 */
#define I2C_CCR_DUTY                              I2C_CCR_DUTY_Msk                                  /*!< Fm mode duty cycle */
#define I2C_CCR_FS_Pos                            (15U)
#define I2C_CCR_FS_Msk                            (0x1UL<<I2C_CCR_FS_Pos)                           /*!< 0x00008000 */
#define I2C_CCR_FS                                I2C_CCR_FS_Msk                                    /*!< I2C master mode selection */

/********************************* Bit definition for I2C_TRISE register ********************************************/
#define I2C_TRISE_TRISE_Pos                       (0U)
#define I2C_TRISE_TRISE_Msk                       (0x7FUL<<I2C_TRISE_TRISE_Pos)                     /*!< 0x0000007F */
#define I2C_TRISE_TRISE                           I2C_TRISE_TRISE_Msk                               /*!< Maximum rise time in Fm+/Fm/Sm mode (Master mode) */
#define I2C_TRISE_THOLDDATA_Pos                   (7U)
#define I2C_TRISE_THOLDDATA_Msk                   (0x1FUL<<I2C_TRISE_THOLDDATA_Pos)                 /*!< 0x00000F80 */
#define I2C_TRISE_THOLDDATA                       I2C_TRISE_THOLDDATA_Msk                           /*!< Data hold time */
#define I2C_TRISE_THOLDDATA_0                     (0x1UL<<I2C_TRISE_THOLDDATA_Pos)                  /*!< 0x00000080 */
#define I2C_TRISE_THOLDDATA_1                     (0x2UL<<I2C_TRISE_THOLDDATA_Pos)                  /*!< 0x00000100 */
#define I2C_TRISE_THOLDDATA_2                     (0x4UL<<I2C_TRISE_THOLDDATA_Pos)                  /*!< 0x00000200 */
#define I2C_TRISE_THOLDDATA_3                     (0x8UL<<I2C_TRISE_THOLDDATA_Pos)                  /*!< 0x00000400 */
#define I2C_TRISE_THOLDDATA_4                     (0x10UL<<I2C_TRISE_THOLDDATA_Pos)                 /*!< 0x00000800 */
#define I2C_TRISE_THOLDDATA_SEL_Pos               (12U)
#define I2C_TRISE_THOLDDATA_SEL_Msk               (0x1UL<<I2C_TRISE_THOLDDATA_SEL_Pos)              /*!< 0x00001000 */
#define I2C_TRISE_THOLDDATA_SEL                   I2C_TRISE_THOLDDATA_SEL_Msk                       /*!< Data hold time select */

/********************************* Bit definition for I2C_TIMEOUTR register *****************************************/
#define I2C_TIMEOUTR_TIMEOUTA_Pos                 (0U)
#define I2C_TIMEOUTR_TIMEOUTA_Msk                 (0xFFFUL<<I2C_TIMEOUTR_TIMEOUTA_Pos)              /*!< 0x00000FFF */
#define I2C_TIMEOUTR_TIMEOUTA                     I2C_TIMEOUTR_TIMEOUTA_Msk                         /*!< Bus Timeout A */
#define I2C_TIMEOUTR_TIDLE_Pos                    (12U)
#define I2C_TIMEOUTR_TIDLE_Msk                    (0x1UL<<I2C_TIMEOUTR_TIDLE_Pos)                   /*!< 0x00001000 */
#define I2C_TIMEOUTR_TIDLE                        I2C_TIMEOUTR_TIDLE_Msk                            /*!< Idle clock timeout detection */
#define I2C_TIMEOUTR_TIMEOUTEN_Pos                (15U)
#define I2C_TIMEOUTR_TIMEOUTEN_Msk                (0x1UL<<I2C_TIMEOUTR_TIMEOUTEN_Pos)               /*!< 0x00008000 */
#define I2C_TIMEOUTR_TIMEOUTEN                    I2C_TIMEOUTR_TIMEOUTEN_Msk                        /*!< Clock timeout enable */
#define I2C_TIMEOUTR_TIMEOUTB_Pos                 (16U)
#define I2C_TIMEOUTR_TIMEOUTB_Msk                 (0xFFFUL<<I2C_TIMEOUTR_TIMEOUTB_Pos)              /*!< 0x0FFF0000 */
#define I2C_TIMEOUTR_TIMEOUTB                     I2C_TIMEOUTR_TIMEOUTB_Msk                         /*!< Bus timeout B */
#define I2C_TIMEOUTR_TEXTEN_Pos                   (31U)
#define I2C_TIMEOUTR_TEXTEN_Msk                   (0x1UL<<I2C_TIMEOUTR_TEXTEN_Pos)                  /*!< 0x80000000 */
#define I2C_TIMEOUTR_TEXTEN                       I2C_TIMEOUTR_TEXTEN_Msk                           /*!< Extended clock timeout enable */


/********************************************************************************************************************/
/********************************* IWDG *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for IWDG_KR register **********************************************/
#define IWDG_KR_KEY_Pos                           (0U)
#define IWDG_KR_KEY_Msk                           (0xFFFFUL<<IWDG_KR_KEY_Pos)                       /*!< 0x0000FFFF */
#define IWDG_KR_KEY                               IWDG_KR_KEY_Msk                                   /*!< IWDG KEY */

/********************************* Bit definition for IWDG_PR register **********************************************/
#define IWDG_PR_PR_Pos                            (0U)
#define IWDG_PR_PR_Msk                            (0x7UL<<IWDG_PR_PR_Pos)                           /*!< 0x00000007 */
#define IWDG_PR_PR                                IWDG_PR_PR_Msk                                    /*!< IWDG preload */
#define IWDG_PR_PR_0                              (0x1UL<<IWDG_PR_PR_Pos)                           /*!< 0x00000001 */
#define IWDG_PR_PR_1                              (0x2UL<<IWDG_PR_PR_Pos)                           /*!< 0x00000002 */
#define IWDG_PR_PR_2                              (0x4UL<<IWDG_PR_PR_Pos)                           /*!< 0x00000004 */

/********************************* Bit definition for IWDG_RLR register *********************************************/
#define IWDG_RLR_RL_Pos                           (0U)
#define IWDG_RLR_RL_Msk                           (0xFFFUL<<IWDG_RLR_RL_Pos)                        /*!< 0x00000FFF */
#define IWDG_RLR_RL                               IWDG_RLR_RL_Msk                                   /*!< IWDG reload */

/********************************* Bit definition for IWDG_SR register **********************************************/
#define IWDG_SR_PVU_Pos                           (0U)
#define IWDG_SR_PVU_Msk                           (0x1UL<<IWDG_SR_PVU_Pos)                          /*!< 0x00000001 */
#define IWDG_SR_PVU                               IWDG_SR_PVU_Msk                                   /*!< Watchdog prescaler value update */
#define IWDG_SR_RVU_Pos                           (1U)
#define IWDG_SR_RVU_Msk                           (0x1UL<<IWDG_SR_RVU_Pos)                          /*!< 0x00000002 */
#define IWDG_SR_RVU                               IWDG_SR_RVU_Msk                                   /*!< Watchdog counter reload value update */
/* #define IWDG_SR_IVU_Pos                           (3U)                     */
/* #define IWDG_SR_IVU_Msk                           (0x1UL<<IWDG_SR_IVU_Pos) */                         /*!< 0x00000008 */
/* #define IWDG_SR_IVU                               IWDG_SR_IVU_Msk          */                         /*!< Watchdog Interrupt value update */
/* #define IWDG_SR_IF_Pos                            (4U)                     */  
/* #define IWDG_SR_IF_Msk                            (0x1UL<<IWDG_SR_IF_Pos)  */                         /*!< 0x00000010 */
/* #define IWDG_SR_IF                                IWDG_SR_IF_Msk           */                         /*!< Watchdog interrupt status */

/********************************* Bit definition for IWDG_ICNTR register *******************************************/
/* #define IWDG_ICNTR_ICNTR_Pos                      (0U)                             */
/* #define IWDG_ICNTR_ICNTR_Msk                      (0xFFFUL<<IWDG_ICNTR_ICNTR_Pos)  */                 /*!< 0x00000FFF */
/* #define IWDG_ICNTR_ICNTR                          IWDG_ICNTR_ICNTR_Msk             */                 /*!< Watchdog prescaler value update */

/********************************* Bit definition for IWDG_ICR register *********************************************/
/* #define IWDG_ICR_IER_Pos                          (0U)                      */
/* #define IWDG_ICR_IER_Msk                          (0x1UL<<IWDG_ICR_IER_Pos) */                       /*!< 0x00000001 */
/* #define IWDG_ICR_IER                              IWDG_ICR_IER_Msk          */                       /*!< Watchdog Interrupt enable */
/* #define IWDG_ICR_ICR_Pos                          (1U)                      */
/* #define IWDG_ICR_ICR_Msk                          (0x1UL<<IWDG_ICR_ICR_Pos) */                       /*!< 0x00000002 */
/* #define IWDG_ICR_ICR                              IWDG_ICR_ICR_Msk          */                       /*!< Watchdog interrupt status clear */


/********************************************************************************************************************/
/********************************* LCD ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for LCD_CR register ***********************************************/
#define LCD_CR_EN_Pos                             (0U)
#define LCD_CR_EN_Msk                             (0x1UL<<LCD_CR_EN_Pos)                            /*!< 0x00000001 */
#define LCD_CR_EN                                 LCD_CR_EN_Msk                                     
#define LCD_CR_LCDCLK_Pos                         (1U)
#define LCD_CR_LCDCLK_Msk                         (0x3UL<<LCD_CR_LCDCLK_Pos)                        /*!< 0x00000006 */
#define LCD_CR_LCDCLK                             LCD_CR_LCDCLK_Msk
#define LCD_CR_LCDCLK_0                           (0x1UL<<LCD_CR_LCDCLK_Pos)                        /*!< 0x00000002 */
#define LCD_CR_LCDCLK_1                           (0x2UL<<LCD_CR_LCDCLK_Pos)                        /*!< 0x00000004 */
#define LCD_CR_BIAS_Pos                           (4U)
#define LCD_CR_BIAS_Msk                           (0x3UL<<LCD_CR_BIAS_Pos)                          /*!< 0x00000030 */
#define LCD_CR_BIAS                               LCD_CR_BIAS_Msk
#define LCD_CR_BIAS_0                             (0x1UL<<LCD_CR_BIAS_Pos)                          /*!< 0x00000010 */
#define LCD_CR_BIAS_1                             (0x2UL<<LCD_CR_BIAS_Pos)                          /*!< 0x00000020 */
#define LCD_CR_DUTY_Pos                           (6U)
#define LCD_CR_DUTY_Msk                           (0x7UL<<LCD_CR_DUTY_Pos)                          /*!< 0x000001C0 */
#define LCD_CR_DUTY                               LCD_CR_DUTY_Msk
#define LCD_CR_DUTY_0                             (0x1UL<<LCD_CR_DUTY_Pos)                          /*!< 0x00000040 */
#define LCD_CR_DUTY_1                             (0x2UL<<LCD_CR_DUTY_Pos)                          /*!< 0x00000080 */
#define LCD_CR_DUTY_2                             (0x4UL<<LCD_CR_DUTY_Pos)                          /*!< 0x00000100 */
#define LCD_CR_BSEL_Pos                           (9U)
#define LCD_CR_BSEL_Msk                           (0x3UL<<LCD_CR_BSEL_Pos)                          /*!< 0x00000600 */
#define LCD_CR_BSEL                               LCD_CR_BSEL_Msk
#define LCD_CR_BSEL_0                             (0x1UL<<LCD_CR_BSEL_Pos)                          /*!< 0x00000200 */
#define LCD_CR_BSEL_1                             (0x2UL<<LCD_CR_BSEL_Pos)                          /*!< 0x00000400 */
#define LCD_CR_CONTRAST_Pos                       (12U)
#define LCD_CR_CONTRAST_Msk                       (0xFUL<<LCD_CR_CONTRAST_Pos)                      /*!< 0x0000F000 */
#define LCD_CR_CONTRAST                           LCD_CR_CONTRAST_Msk
#define LCD_CR_CONTRAST_0                         (0x1UL<<LCD_CR_CONTRAST_Pos)                      /*!< 0x00001000 */
#define LCD_CR_CONTRAST_1                         (0x2UL<<LCD_CR_CONTRAST_Pos)                      /*!< 0x00002000 */
#define LCD_CR_CONTRAST_2                         (0x4UL<<LCD_CR_CONTRAST_Pos)                      /*!< 0x00004000 */
#define LCD_CR_CONTRAST_3                         (0x8UL<<LCD_CR_CONTRAST_Pos)                      /*!< 0x00008000 */
//#define LCD_CR_VSEL_Pos                           (16U)
//#define LCD_CR_VSEL_Msk                           (0x1UL<<LCD_CR_VSEL_Pos)                          /*!< 0x00010000 */
//#define LCD_CR_VSEL                               LCD_CR_VSEL_Msk                                   
//#define LCD_CR_VCP_SEL_Pos                        (17U)
//#define LCD_CR_VCP_SEL_Msk                        (0x7UL<<LCD_CR_VCP_SEL_Pos)                       /*!< 0x000E0000 */
//#define LCD_CR_VCP_SEL                            LCD_CR_VCP_SEL_Msk
//#define LCD_CR_VCP_SEL_0                          (0x1UL<<LCD_CR_VCP_SEL_Pos)                       /*!< 0x00020000 */
//#define LCD_CR_VCP_SEL_1                          (0x2UL<<LCD_CR_VCP_SEL_Pos)                       /*!< 0x00040000 */
//#define LCD_CR_VCP_SEL_2                          (0x4UL<<LCD_CR_VCP_SEL_Pos)                       /*!< 0x00080000 */
#define LCD_CR_COMSEG_DRV_TYPE_Pos                (20U)
#define LCD_CR_COMSEG_DRV_TYPE_Msk                (0x1UL<<LCD_CR_COMSEG_DRV_TYPE_Pos)               /*!< 0x00100000 */
#define LCD_CR_COMSEG_DRV_TYPE                    LCD_CR_COMSEG_DRV_TYPE_Msk
#define LCD_CR_FCCTL_Pos                          (21U)
#define LCD_CR_FCCTL_Msk                          (0x7UL<<LCD_CR_FCCTL_Pos)                         /*!< 0x00E00000 */
#define LCD_CR_FCCTL                              LCD_CR_FCCTL_Msk
#define LCD_CR_FCCTL_0                            (0x1UL<<LCD_CR_FCCTL_Pos)                         /*!< 0x00200000 */
#define LCD_CR_FCCTL_1                            (0x2UL<<LCD_CR_FCCTL_Pos)                         /*!< 0x00400000 */
#define LCD_CR_FCCTL_2                            (0x4UL<<LCD_CR_FCCTL_Pos)                         /*!< 0x00800000 */
#define LCD_CR_DEAD_Pos                           (24U)
#define LCD_CR_DEAD_Msk                           (0x7UL<<LCD_CR_DEAD_Pos)                          /*!< 0x07000000 */
#define LCD_CR_DEAD                               LCD_CR_DEAD_Msk
#define LCD_CR_DEAD_0                             (0x1UL<<LCD_CR_DEAD_Pos)                          /*!< 0x01000000 */
#define LCD_CR_DEAD_1                             (0x2UL<<LCD_CR_DEAD_Pos)                          /*!< 0x02000000 */
#define LCD_CR_DEAD_2                             (0x4UL<<LCD_CR_DEAD_Pos)                          /*!< 0x04000000 */
//#define LCD_CR_CP_FRQ_Pos                         (27U)
//#define LCD_CR_CP_FRQ_Msk                         (0x7UL<<LCD_CR_CP_FRQ_Pos)                        /*!< 0x38000000 */
//#define LCD_CR_CP_FRQ                             LCD_CR_CP_FRQ_Msk
//#define LCD_CR_CP_FRQ_0                           (0x1UL<<LCD_CR_CP_FRQ_Pos)                        /*!< 0x08000000 */
//#define LCD_CR_CP_FRQ_1                           (0x2UL<<LCD_CR_CP_FRQ_Pos)                        /*!< 0x10000000 */
//#define LCD_CR_CP_FRQ_2                           (0x4UL<<LCD_CR_CP_FRQ_Pos)                        /*!< 0x20000000 */
//#define LCD_CR_CP_ST_Pos                          (30U)
//#define LCD_CR_CP_ST_Msk                          (0x3UL<<LCD_CR_CP_ST_Pos)                         /*!< 0xC0000000 */
//#define LCD_CR_CP_ST                              LCD_CR_CP_ST_Msk
//#define LCD_CR_CP_ST_0                            (0x1UL<<LCD_CR_CP_ST_Pos)                         /*!< 0x40000000 */
//#define LCD_CR_CP_ST_1                            (0x2UL<<LCD_CR_CP_ST_Pos)                         /*!< 0x80000000 */

/********************************* Bit definition for LCD_CSR register **********************************************/
#define LCD_CSR_BLINKCNT_Pos                      (0U)
#define LCD_CSR_BLINKCNT_Msk                      (0x3FUL<<LCD_CSR_BLINKCNT_Pos)                    /*!< 0x0000003F */
#define LCD_CSR_BLINKCNT                          LCD_CSR_BLINKCNT_Msk
#define LCD_CSR_BLINKCNT_0                        (0x1UL<<LCD_CSR_BLINKCNT_Pos)                     /*!< 0x00000001 */
#define LCD_CSR_BLINKCNT_1                        (0x2UL<<LCD_CSR_BLINKCNT_Pos)                     /*!< 0x00000002 */
#define LCD_CSR_BLINKCNT_2                        (0x4UL<<LCD_CSR_BLINKCNT_Pos)                     /*!< 0x00000004 */
#define LCD_CSR_BLINKCNT_3                        (0x8UL<<LCD_CSR_BLINKCNT_Pos)                     /*!< 0x00000008 */
#define LCD_CSR_BLINKCNT_4                        (0x10UL<<LCD_CSR_BLINKCNT_Pos)                    /*!< 0x00000010 */
#define LCD_CSR_BLINKCNT_5                        (0x20UL<<LCD_CSR_BLINKCNT_Pos)                    /*!< 0x00000020 */
#define LCD_CSR_BLINKEN_Pos                       (6U)
#define LCD_CSR_BLINKEN_Msk                       (0x1UL<<LCD_CSR_BLINKEN_Pos)                      /*!< 0x00000040 */
#define LCD_CSR_BLINKEN                           LCD_CSR_BLINKEN_Msk                               
#define LCD_CSR_SWCAP_DRV_NUM_Pos                 (7U)
#define LCD_CSR_SWCAP_DRV_NUM_Msk                 (0x7UL<<LCD_CSR_SWCAP_DRV_NUM_Pos)                /*!< 0x00000380 */
#define LCD_CSR_SWCAP_DRV_NUM                     LCD_CSR_SWCAP_DRV_NUM_Msk
#define LCD_CSR_SWCAP_DRV_NUM_0                   (0x1UL<<LCD_CSR_SWCAP_DRV_NUM_Pos)                /*!< 0x00000080 */
#define LCD_CSR_SWCAP_DRV_NUM_1                   (0x2UL<<LCD_CSR_SWCAP_DRV_NUM_Pos)                /*!< 0x00000100 */
#define LCD_CSR_SWCAP_DRV_NUM_2                   (0x4UL<<LCD_CSR_SWCAP_DRV_NUM_Pos)                /*!< 0x00000200 */
#define LCD_CSR_MODE_Pos                          (10U)
#define LCD_CSR_MODE_Msk                          (0x1UL<<LCD_CSR_MODE_Pos)                         /*!< 0x00000400 */
#define LCD_CSR_MODE                              LCD_CSR_MODE_Msk                                                                
#define LCD_CSR_BKFIE_Pos                         (12U)
#define LCD_CSR_BKFIE_Msk                         (0x1UL<<LCD_CSR_BKFIE_Pos)                        /*!< 0x00001000 */
#define LCD_CSR_BKFIE                             LCD_CSR_BKFIE_Msk                                 
#define LCD_CSR_SOFIE_Pos                         (13U)
#define LCD_CSR_SOFIE_Msk                         (0x1UL<<LCD_CSR_SOFIE_Pos)                        /*!< 0x00002000 */
#define LCD_CSR_SOFIE                             LCD_CSR_SOFIE_Msk                                 
#define LCD_CSR_UDDIE_Pos                         (14U)
#define LCD_CSR_UDDIE_Msk                         (0x1UL<<LCD_CSR_UDDIE_Pos)                        /*!< 0x00004000 */
#define LCD_CSR_UDDIE                             LCD_CSR_UDDIE_Msk                                 
#define LCD_CSR_UDR_Pos                           (15U)
#define LCD_CSR_UDR_Msk                           (0x1UL<<LCD_CSR_UDR_Pos)                          /*!< 0x00008000 */
#define LCD_CSR_UDR                               LCD_CSR_UDR_Msk                                   
#define LCD_CSR_BKF_Pos                           (16U)
#define LCD_CSR_BKF_Msk                           (0x1UL<<LCD_CSR_BKF_Pos)                          /*!< 0x00010000 */
#define LCD_CSR_BKF                               LCD_CSR_BKF_Msk                                   
#define LCD_CSR_SOF_Pos                           (17U)
#define LCD_CSR_SOF_Msk                           (0x1UL<<LCD_CSR_SOF_Pos)                          /*!< 0x00020000 */
#define LCD_CSR_SOF                               LCD_CSR_SOF_Msk                                   
#define LCD_CSR_UDD_Pos                           (18U)
#define LCD_CSR_UDD_Msk                           (0x1UL<<LCD_CSR_UDD_Pos)                          /*!< 0x00040000 */
#define LCD_CSR_UDD                               LCD_CSR_UDD_Msk                                   
#define LCD_CSR_ENS_Pos                           (19U)
#define LCD_CSR_ENS_Msk                           (0x1UL<<LCD_CSR_ENS_Pos)                          /*!< 0x00080000 */
#define LCD_CSR_ENS                               LCD_CSR_ENS_Msk                                   

/********************************* Bit definition for LCD_INTCLR register *******************************************/
#define LCD_INTCLR_BKFC_Pos                       (16U)
#define LCD_INTCLR_BKFC_Msk                       (0x1UL<<LCD_INTCLR_BKFC_Pos)                      /*!< 0x00010000 */
#define LCD_INTCLR_BKFC                           LCD_INTCLR_BKFC_Msk                               
#define LCD_INTCLR_SOFC_Pos                       (17U)
#define LCD_INTCLR_SOFC_Msk                       (0x1UL<<LCD_INTCLR_SOFC_Pos)                      /*!< 0x00020000 */
#define LCD_INTCLR_SOFC                           LCD_INTCLR_SOFC_Msk                               
#define LCD_INTCLR_UDDC_Pos                       (18U)
#define LCD_INTCLR_UDDC_Msk                       (0x1UL<<LCD_INTCLR_UDDC_Pos)                      /*!< 0x00040000 */
#define LCD_INTCLR_UDDC                           LCD_INTCLR_UDDC_Msk                               

/********************************* Bit definition for LCD_POEN0 register ********************************************/
#define LCD_POEN0_SX_Pos                          (0U)
#define LCD_POEN0_SX_Msk                          (0xFFFFFFFFUL<<LCD_POEN0_SX_Pos)                  /*!< 0xFFFFFFFF */
#define LCD_POEN0_SX                              LCD_POEN0_SX_Msk

/********************************* Bit definition for LCD_POEN1 register ********************************************/
#define LCD_POEN1_SX_Pos                          (0U)
#define LCD_POEN1_SX_Msk                          (0xFUL<<LCD_POEN1_SX_Pos)                         /*!< 0x0000000F */
#define LCD_POEN1_SX                              LCD_POEN1_SX_Msk
#define LCD_POEN1_SX_0                            (0x1UL<<LCD_POEN1_SX_Pos)                         /*!< 0x00000001 */
#define LCD_POEN1_SX_1                            (0x2UL<<LCD_POEN1_SX_Pos)                         /*!< 0x00000002 */
#define LCD_POEN1_SX_2                            (0x4UL<<LCD_POEN1_SX_Pos)                         /*!< 0x00000004 */
#define LCD_POEN1_SX_3                            (0x8UL<<LCD_POEN1_SX_Pos)                         /*!< 0x00000008 */
#define LCD_POEN1_SXCY_Pos                        (4U)
#define LCD_POEN1_SXCY_Msk                        (0xFUL<<LCD_POEN1_SXCY_Pos)                       /*!< 0x000000F0 */
#define LCD_POEN1_SXCY                            LCD_POEN1_SXCY_Msk
#define LCD_POEN1_SXCY_0                          (0x1UL<<LCD_POEN1_SXCY_Pos)                       /*!< 0x00000010 */
#define LCD_POEN1_SXCY_1                          (0x2UL<<LCD_POEN1_SXCY_Pos)                       /*!< 0x00000020 */
#define LCD_POEN1_SXCY_2                          (0x4UL<<LCD_POEN1_SXCY_Pos)                       /*!< 0x00000040 */
#define LCD_POEN1_SXCY_3                          (0x8UL<<LCD_POEN1_SXCY_Pos)                       /*!< 0x00000080 */
#define LCD_POEN1_CX_Pos                          (8U)
#define LCD_POEN1_CX_Msk                          (0xFUL<<LCD_POEN1_CX_Pos)                         /*!< 0x00000F00 */
#define LCD_POEN1_CX                              LCD_POEN1_CX_Msk
#define LCD_POEN1_CX_0                            (0x1UL<<LCD_POEN1_CX_Pos)                         /*!< 0x00000100 */
#define LCD_POEN1_CX_1                            (0x2UL<<LCD_POEN1_CX_Pos)                         /*!< 0x00000200 */
#define LCD_POEN1_CX_2                            (0x4UL<<LCD_POEN1_CX_Pos)                         /*!< 0x00000400 */
#define LCD_POEN1_CX_3                            (0x8UL<<LCD_POEN1_CX_Pos)                         /*!< 0x00000800 */

/********************************* Bit definition for LCD_RAM0 register *********************************************/
#define LCD_RAM0_DX_Pos                           (0U)
#define LCD_RAM0_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM0_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM0_DX                               LCD_RAM0_DX_Msk

/********************************* Bit definition for LCD_RAM1 register *********************************************/
#define LCD_RAM1_DX_Pos                           (0U)
#define LCD_RAM1_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM1_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM1_DX                               LCD_RAM1_DX_Msk

/********************************* Bit definition for LCD_RAM2 register *********************************************/
#define LCD_RAM2_DX_Pos                           (0U)
#define LCD_RAM2_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM2_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM2_DX                               LCD_RAM2_DX_Msk

/********************************* Bit definition for LCD_RAM3 register *********************************************/
#define LCD_RAM3_DX_Pos                           (0U)
#define LCD_RAM3_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM3_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM3_DX                               LCD_RAM3_DX_Msk

/********************************* Bit definition for LCD_RAM4 register *********************************************/
#define LCD_RAM4_DX_Pos                           (0U)
#define LCD_RAM4_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM4_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM4_DX                               LCD_RAM4_DX_Msk

/********************************* Bit definition for LCD_RAM5 register *********************************************/
#define LCD_RAM5_DX_Pos                           (0U)
#define LCD_RAM5_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM5_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM5_DX                               LCD_RAM5_DX_Msk

/********************************* Bit definition for LCD_RAM6 register *********************************************/
#define LCD_RAM6_DX_Pos                           (0U)
#define LCD_RAM6_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM6_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM6_DX                               LCD_RAM6_DX_Msk

/********************************* Bit definition for LCD_RAM7 register *********************************************/
#define LCD_RAM7_DX_Pos                           (0U)
#define LCD_RAM7_DX_Msk                           (0xFFFFFFFFUL<<LCD_RAM7_DX_Pos)                   /*!< 0xFFFFFFFF */
#define LCD_RAM7_DX                               LCD_RAM7_DX_Msk

/********************************* Bit definition for LCD_RAM8 register *********************************************/
#define LCD_RAM8_DX_Pos                           (0U)
#define LCD_RAM8_DX_Msk                           (0xFFUL<<LCD_RAM8_DX_Pos)                         /*!< 0x000000FF */
#define LCD_RAM8_DX                               LCD_RAM8_DX_Msk

/********************************* Bit definition for LCD_RAM9 register *********************************************/
#define LCD_RAM9_DX_Pos                           (0U)
#define LCD_RAM9_DX_Msk                           (0xFFUL<<LCD_RAM9_DX_Pos)                         /*!< 0x000000FF */
#define LCD_RAM9_DX                               LCD_RAM9_DX_Msk

/********************************* Bit definition for LCD_RAM10 register ********************************************/
#define LCD_RAM10_DX_Pos                          (0U)
#define LCD_RAM10_DX_Msk                          (0xFFUL<<LCD_RAM10_DX_Pos)                        /*!< 0x000000FF */
#define LCD_RAM10_DX                              LCD_RAM10_DX_Msk

/********************************* Bit definition for LCD_RAM11 register ********************************************/
#define LCD_RAM11_DX_Pos                          (0U)
#define LCD_RAM11_DX_Msk                          (0xFFUL<<LCD_RAM11_DX_Pos)                        /*!< 0x000000FF */
#define LCD_RAM11_DX                              LCD_RAM11_DX_Msk

/********************************* Bit definition for LCD_RAM12 register ********************************************/
#define LCD_RAM12_DX_Pos                          (0U)
#define LCD_RAM12_DX_Msk                          (0xFFUL<<LCD_RAM12_DX_Pos)                         /*!< 0x000000FF */
#define LCD_RAM12_DX                              LCD_RAM12_DX_Msk

/********************************* Bit definition for LCD_RAM13 register ********************************************/
#define LCD_RAM13_DX_Pos                          (0U)
#define LCD_RAM13_DX_Msk                          (0xFFUL<<LCD_RAM13_DX_Pos)                         /*!< 0x000000FF */
#define LCD_RAM13_DX                              LCD_RAM13_DX_Msk

/********************************* Bit definition for LCD_RAM14 register ********************************************/
#define LCD_RAM14_DX_Pos                          (0U)
#define LCD_RAM14_DX_Msk                          (0xFFUL<<LCD_RAM14_DX_Pos)                         /*!< 0x000000FF */
#define LCD_RAM14_DX                              LCD_RAM14_DX_Msk

/********************************* Bit definition for LCD_RAM15 register ********************************************/
#define LCD_RAM15_DX_Pos                          (0U)
#define LCD_RAM15_DX_Msk                          (0xFFUL<<LCD_RAM15_DX_Pos)                         /*!< 0x000000FF */
#define LCD_RAM15_DX                              LCD_RAM15_DX_Msk


/********************************************************************************************************************/
/********************************* LPUART ***************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for LPUART_CR1 register *******************************************/
#define LPUART_CR1_UE_Pos                         (0U)
#define LPUART_CR1_UE_Msk                         (0x1UL<<LPUART_CR1_UE_Pos)                        /*!< 0x00000001 */
#define LPUART_CR1_UE                             LPUART_CR1_UE_Msk                                 /*!< LPUART enabled */
#define LPUART_CR1_UESM_Pos                       (1U)
#define LPUART_CR1_UESM_Msk                       (0x1UL<<LPUART_CR1_UESM_Pos)                      /*!< 0x00000002 */
#define LPUART_CR1_UESM                           LPUART_CR1_UESM_Msk                               /*!< LPUART enabled in Stop mode */
#define LPUART_CR1_RE_Pos                         (2U)
#define LPUART_CR1_RE_Msk                         (0x1UL<<LPUART_CR1_RE_Pos)                        /*!< 0x00000004 */
#define LPUART_CR1_RE                             LPUART_CR1_RE_Msk                                 /*!< Receive enable */
#define LPUART_CR1_TE_Pos                         (3U)
#define LPUART_CR1_TE_Msk                         (0x1UL<<LPUART_CR1_TE_Pos)                        /*!< 0x00000008 */
#define LPUART_CR1_TE                             LPUART_CR1_TE_Msk                                 /*!< Transfer enable */
#define LPUART_CR1_IDLEIE_Pos                     (4U)
#define LPUART_CR1_IDLEIE_Msk                     (0x1UL<<LPUART_CR1_IDLEIE_Pos)                    /*!< 0x00000010 */
#define LPUART_CR1_IDLEIE                         LPUART_CR1_IDLEIE_Msk                             /*!< IDLE interrupt enable */
#define LPUART_CR1_RXNEIE_Pos                     (5U)
#define LPUART_CR1_RXNEIE_Msk                     (0x1UL<<LPUART_CR1_RXNEIE_Pos)                    /*!< 0x00000020 */
#define LPUART_CR1_RXNEIE                         LPUART_CR1_RXNEIE_Msk                             /*!< RXNE interrupt enable */
#define LPUART_CR1_TCIE_Pos                       (6U)
#define LPUART_CR1_TCIE_Msk                       (0x1UL<<LPUART_CR1_TCIE_Pos)                      /*!< 0x00000040 */
#define LPUART_CR1_TCIE                           LPUART_CR1_TCIE_Msk                               /*!< End of Transfer interrupt enabled */
#define LPUART_CR1_TXEIE_Pos                      (7U)
#define LPUART_CR1_TXEIE_Msk                      (0x1UL<<LPUART_CR1_TXEIE_Pos)                     /*!< 0x00000080 */
#define LPUART_CR1_TXEIE                          LPUART_CR1_TXEIE_Msk                              /*!< TXE interrupt enable */
#define LPUART_CR1_PEIE_Pos                       (8U)
#define LPUART_CR1_PEIE_Msk                       (0x1UL<<LPUART_CR1_PEIE_Pos)                      /*!< 0x00000100 */
#define LPUART_CR1_PEIE                           LPUART_CR1_PEIE_Msk                               /*!< PE interrupt enable */
#define LPUART_CR1_PS_Pos                         (9U)
#define LPUART_CR1_PS_Msk                         (0x1UL<<LPUART_CR1_PS_Pos)                        /*!< 0x00000200 */
#define LPUART_CR1_PS                             LPUART_CR1_PS_Msk                                 /*!< Parity selection */
#define LPUART_CR1_PCE_Pos                        (10U)
#define LPUART_CR1_PCE_Msk                        (0x1UL<<LPUART_CR1_PCE_Pos)                       /*!< 0x00000400 */
#define LPUART_CR1_PCE                            LPUART_CR1_PCE_Msk                                /*!< Parity control */
#define LPUART_CR1_WAKE_Pos                       (11U)
#define LPUART_CR1_WAKE_Msk                       (0x1UL<<LPUART_CR1_WAKE_Pos)                      /*!< 0x00000800 */
#define LPUART_CR1_WAKE                           LPUART_CR1_WAKE_Msk                               /*!< Receive wake-up mode */
#define LPUART_CR1_M0_Pos                         (12U)
#define LPUART_CR1_M0_Msk                         (0x1UL<<LPUART_CR1_M0_Pos)                        /*!< 0x00001000 */
#define LPUART_CR1_M0                             LPUART_CR1_M0_Msk                                 /*!< Configure the word length in combination with M1 */
#define LPUART_CR1_MME_Pos                        (13U)
#define LPUART_CR1_MME_Msk                        (0x1UL<<LPUART_CR1_MME_Pos)                       /*!< 0x00002000 */
#define LPUART_CR1_MME                            LPUART_CR1_MME_Msk                                /*!< Silent mode enabled */
#define LPUART_CR1_CMIE_Pos                       (14U)
#define LPUART_CR1_CMIE_Msk                       (0x1UL<<LPUART_CR1_CMIE_Pos)                      /*!< 0x00004000 */
#define LPUART_CR1_CMIE                           LPUART_CR1_CMIE_Msk                               /*!< Character match interrupt enabled */
#define LPUART_CR1_DEDT_Pos                       (16U)
#define LPUART_CR1_DEDT_Msk                       (0x1FUL<<LPUART_CR1_DEDT_Pos)                     /*!< 0x001F0000 */
#define LPUART_CR1_DEDT                           LPUART_CR1_DEDT_Msk                               /*!< The time between the transmit frame stop bit and the invalid DE (driver enable) signal */
#define LPUART_CR1_DEDT_0                         (0x1UL<<LPUART_CR1_DEDT_Pos)                      /*!< 0x00010000 */
#define LPUART_CR1_DEDT_1                         (0x2UL<<LPUART_CR1_DEDT_Pos)                      /*!< 0x00020000 */
#define LPUART_CR1_DEDT_2                         (0x4UL<<LPUART_CR1_DEDT_Pos)                      /*!< 0x00040000 */
#define LPUART_CR1_DEDT_3                         (0x8UL<<LPUART_CR1_DEDT_Pos)                      /*!< 0x00080000 */
#define LPUART_CR1_DEDT_4                         (0x10UL<<LPUART_CR1_DEDT_Pos)                     /*!< 0x00100000 */
#define LPUART_CR1_DEAT_Pos                       (21U)
#define LPUART_CR1_DEAT_Msk                       (0x1FUL<<LPUART_CR1_DEAT_Pos)                     /*!< 0x03E00000 */
#define LPUART_CR1_DEAT                           LPUART_CR1_DEAT_Msk                               /*!< The time between the DE (driver enable) signal validity and the start bit */
#define LPUART_CR1_DEAT_0                         (0x1UL<<LPUART_CR1_DEAT_Pos)                      /*!< 0x00200000 */
#define LPUART_CR1_DEAT_1                         (0x2UL<<LPUART_CR1_DEAT_Pos)                      /*!< 0x00400000 */
#define LPUART_CR1_DEAT_2                         (0x4UL<<LPUART_CR1_DEAT_Pos)                      /*!< 0x00800000 */
#define LPUART_CR1_DEAT_3                         (0x8UL<<LPUART_CR1_DEAT_Pos)                      /*!< 0x01000000 */
#define LPUART_CR1_DEAT_4                         (0x10UL<<LPUART_CR1_DEAT_Pos)                     /*!< 0x02000000 */
#define LPUART_CR1_M1_Pos                         (28U)
#define LPUART_CR1_M1_Msk                         (0x1UL<<LPUART_CR1_M1_Pos)                        /*!< 0x10000000 */
#define LPUART_CR1_M1                             LPUART_CR1_M1_Msk                                 /*!< The value of {M1,M0} the configurate length */

/********************************* Bit definition for LPUART_CR2 register *******************************************/
#define LPUART_CR2_ADDM7_Pos                      (4U)
#define LPUART_CR2_ADDM7_Msk                      (0x1UL<<LPUART_CR2_ADDM7_Pos)                     /*!< 0x00000010 */
#define LPUART_CR2_ADDM7                          LPUART_CR2_ADDM7_Msk                              /*!< 7bit/4bit address detection configuration */
#define LPUART_CR2_STOP_Pos                       (12U)
#define LPUART_CR2_STOP_Msk                       (0x3UL<<LPUART_CR2_STOP_Pos)                      /*!< 0x00003000 */
#define LPUART_CR2_STOP                           LPUART_CR2_STOP_Msk                               /*!< Stop bit configuration */
#define LPUART_CR2_STOP_0                         (0x1UL<<LPUART_CR2_STOP_Pos)                      /*!< 0x00001000 */
#define LPUART_CR2_STOP_1                         (0x2UL<<LPUART_CR2_STOP_Pos)                      /*!< 0x00002000 */
#define LPUART_CR2_SWAP_Pos                       (15U)
#define LPUART_CR2_SWAP_Msk                       (0x1UL<<LPUART_CR2_SWAP_Pos)                      /*!< 0x00008000 */
#define LPUART_CR2_SWAP                           LPUART_CR2_SWAP_Msk                               /*!< TX/RX pin interchangeable */
#define LPUART_CR2_RXINV_Pos                      (16U)
#define LPUART_CR2_RXINV_Msk                      (0x1UL<<LPUART_CR2_RXINV_Pos)                     /*!< 0x00010000 */
#define LPUART_CR2_RXINV                          LPUART_CR2_RXINV_Msk                              /*!< The RX pin is active level inverting */
#define LPUART_CR2_TXINV_Pos                      (17U)
#define LPUART_CR2_TXINV_Msk                      (0x1UL<<LPUART_CR2_TXINV_Pos)                     /*!< 0x00020000 */
#define LPUART_CR2_TXINV                          LPUART_CR2_TXINV_Msk                              /*!< TX pin active level inverted */
#define LPUART_CR2_DATAINV_Pos                    (18U)
#define LPUART_CR2_DATAINV_Msk                    (0x1UL<<LPUART_CR2_DATAINV_Pos)                   /*!< 0x00040000 */
#define LPUART_CR2_DATAINV                        LPUART_CR2_DATAINV_Msk                            /*!< Inverse binary data processing */
#define LPUART_CR2_MSBFIRST_Pos                   (19U)
#define LPUART_CR2_MSBFIRST_Msk                   (0x1UL<<LPUART_CR2_MSBFIRST_Pos)                  /*!< 0x00080000 */
#define LPUART_CR2_MSBFIRST                       LPUART_CR2_MSBFIRST_Msk                           /*!< MSB first */
#define LPUART_CR2_TXOE_ALWAYS_ON_Pos             (20U)
#define LPUART_CR2_TXOE_ALWAYS_ON_Msk             (0x1UL<<LPUART_CR2_TXOE_ALWAYS_ON_Pos)            /*!< 0x00100000 */
#define LPUART_CR2_TXOE_ALWAYS_ON                 LPUART_CR2_TXOE_ALWAYS_ON_Msk                     
#define LPUART_CR2_ADD_Pos                        (24U)
#define LPUART_CR2_ADD_Msk                        (0xFFUL<<LPUART_CR2_ADD_Pos)                      /*!< 0xFF000000 */
#define LPUART_CR2_ADD                            LPUART_CR2_ADD_Msk                                /*!< LPUART address */

/********************************* Bit definition for LPUART_CR3 register *******************************************/
#define LPUART_CR3_EIE_Pos                        (0U)
#define LPUART_CR3_EIE_Msk                        (0x1UL<<LPUART_CR3_EIE_Pos)                       /*!< 0x00000001 */
#define LPUART_CR3_EIE                            LPUART_CR3_EIE_Msk                                /*!< Error interrupts are enabled */
#define LPUART_CR3_HDSEL_Pos                      (3U)
#define LPUART_CR3_HDSEL_Msk                      (0x1UL<<LPUART_CR3_HDSEL_Pos)                     /*!< 0x00000008 */
#define LPUART_CR3_HDSEL                          LPUART_CR3_HDSEL_Msk                              /*!< Half-duplex selection */
#define LPUART_CR3_DMAR_Pos                       (6U)
#define LPUART_CR3_DMAR_Msk                       (0x1UL<<LPUART_CR3_DMAR_Pos)                      /*!< 0x00000040 */
#define LPUART_CR3_DMAR                           LPUART_CR3_DMAR_Msk                               /*!< Enable DMA on reception */
#define LPUART_CR3_DMAT_Pos                       (7U)
#define LPUART_CR3_DMAT_Msk                       (0x1UL<<LPUART_CR3_DMAT_Pos)                      /*!< 0x00000080 */
#define LPUART_CR3_DMAT                           LPUART_CR3_DMAT_Msk                               /*!< Enable DMA while transmitting */
#define LPUART_CR3_RTSE_Pos                       (8U)
#define LPUART_CR3_RTSE_Msk                       (0x1UL<<LPUART_CR3_RTSE_Pos)                      /*!< 0x00000100 */
#define LPUART_CR3_RTSE                           LPUART_CR3_RTSE_Msk                               /*!< RTS enabled */
#define LPUART_CR3_CTSE_Pos                       (9U)
#define LPUART_CR3_CTSE_Msk                       (0x1UL<<LPUART_CR3_CTSE_Pos)                      /*!< 0x00000200 */
#define LPUART_CR3_CTSE                           LPUART_CR3_CTSE_Msk                               /*!< CTS enabled */
#define LPUART_CR3_CTSIE_Pos                      (10U)
#define LPUART_CR3_CTSIE_Msk                      (0x1UL<<LPUART_CR3_CTSIE_Pos)                     /*!< 0x00000400 */
#define LPUART_CR3_CTSIE                          LPUART_CR3_CTSIE_Msk                              /*!< CTS interrupt enable */
#define LPUART_CR3_OVRDIS_Pos                     (12U)
#define LPUART_CR3_OVRDIS_Msk                     (0x1UL<<LPUART_CR3_OVRDIS_Pos)                    /*!< 0x00001000 */
#define LPUART_CR3_OVRDIS                         LPUART_CR3_OVRDIS_Msk                             /*!< Overrun is prohibited */
#define LPUART_CR3_DDRE_Pos                       (13U)
#define LPUART_CR3_DDRE_Msk                       (0x1UL<<LPUART_CR3_DDRE_Pos)                      /*!< 0x00002000 */
#define LPUART_CR3_DDRE                           LPUART_CR3_DDRE_Msk                               /*!< Whether DMA is disabled when receiving an error */
#define LPUART_CR3_DEM_Pos                        (14U)
#define LPUART_CR3_DEM_Msk                        (0x1UL<<LPUART_CR3_DEM_Pos)                       /*!< 0x00004000 */
#define LPUART_CR3_DEM                            LPUART_CR3_DEM_Msk                                /*!< DE mode enabled */
#define LPUART_CR3_DEP_Pos                        (15U)
#define LPUART_CR3_DEP_Msk                        (0x1UL<<LPUART_CR3_DEP_Pos)                       /*!< 0x00008000 */
#define LPUART_CR3_DEP                            LPUART_CR3_DEP_Msk                                /*!< DE polarity selection */
#define LPUART_CR3_WUS_Pos                        (20U)
#define LPUART_CR3_WUS_Msk                        (0x3UL<<LPUART_CR3_WUS_Pos)                       /*!< 0x00300000 */
#define LPUART_CR3_WUS                            LPUART_CR3_WUS_Msk                                /*!< Low-power wake-up options */
#define LPUART_CR3_WUS_0                          (0x1UL<<LPUART_CR3_WUS_Pos)                       /*!< 0x00100000 */
#define LPUART_CR3_WUS_1                          (0x2UL<<LPUART_CR3_WUS_Pos)                       /*!< 0x00200000 */
#define LPUART_CR3_WUFIE_Pos                      (22U)
#define LPUART_CR3_WUFIE_Msk                      (0x1UL<<LPUART_CR3_WUFIE_Pos)                     /*!< 0x00400000 */
#define LPUART_CR3_WUFIE                          LPUART_CR3_WUFIE_Msk                              /*!< Low-power wake-up interrupt enable */

/********************************* Bit definition for LPUART_BRR register *******************************************/
#define LPUART_BRR_BBR_Pos                        (0U)
#define LPUART_BRR_BBR_Msk                        (0xFFFFFUL<<LPUART_BRR_BBR_Pos)                   /*!< 0x000FFFFF */
#define LPUART_BRR_BBR                            LPUART_BRR_BBR_Msk                                /*!< LPUART baud rate */

/********************************* Bit definition for LPUART_LPWKUP_BRR register ************************************/
#define LPUART_LPWKUP_BRR_LPWKUP_BBR_Pos          (0U)
#define LPUART_LPWKUP_BRR_LPWKUP_BBR_Msk          (0xFFFFFUL<<LPUART_LPWKUP_BRR_LPWKUP_BBR_Pos)     /*!< 0x000FFFFF */
#define LPUART_LPWKUP_BRR_LPWKUP_BBR              LPUART_LPWKUP_BRR_LPWKUP_BBR_Msk                  /*!< LPUART lpwkup baud rate */
#define LPUART_LPWKUP_BRR_HW_BRR_UPEN_Pos         (20U)
#define LPUART_LPWKUP_BRR_HW_BRR_UPEN_Msk         (0x1UL<<LPUART_LPWKUP_BRR_HW_BRR_UPEN_Pos)        /*!< 0x00100000 */
#define LPUART_LPWKUP_BRR_HW_BRR_UPEN             LPUART_LPWKUP_BRR_HW_BRR_UPEN_Msk                 /*!< LPUART wkup brr update enable */

/********************************* Bit definition for LPUART_RQR register *******************************************/
#define LPUART_RQR_SBKRQ_Pos                      (1U)
#define LPUART_RQR_SBKRQ_Msk                      (0x1UL<<LPUART_RQR_SBKRQ_Pos)                     /*!< 0x00000002 */
#define LPUART_RQR_SBKRQ                          LPUART_RQR_SBKRQ_Msk                              /*!< Send an abort request */
#define LPUART_RQR_MMRQ_Pos                       (2U)
#define LPUART_RQR_MMRQ_Msk                       (0x1UL<<LPUART_RQR_MMRQ_Pos)                      /*!< 0x00000004 */
#define LPUART_RQR_MMRQ                           LPUART_RQR_MMRQ_Msk                               /*!< Silent mode request */

/********************************* Bit definition for LPUART_ISR register *******************************************/
#define LPUART_ISR_PE_Pos                         (0U)
#define LPUART_ISR_PE_Msk                         (0x1UL<<LPUART_ISR_PE_Pos)                        /*!< 0x00000001 */
#define LPUART_ISR_PE                             LPUART_ISR_PE_Msk                                 /*!< Parity error */
#define LPUART_ISR_FE_Pos                         (1U)
#define LPUART_ISR_FE_Msk                         (0x1UL<<LPUART_ISR_FE_Pos)                        /*!< 0x00000002 */
#define LPUART_ISR_FE                             LPUART_ISR_FE_Msk                                 /*!< Frame error flag */
#define LPUART_ISR_NE_Pos                         (2U)
#define LPUART_ISR_NE_Msk                         (0x1UL<<LPUART_ISR_NE_Pos)                        /*!< 0x00000004 */
#define LPUART_ISR_NE                             LPUART_ISR_NE_Msk                                 /*!< START bit noise flag */
#define LPUART_ISR_ORE_Pos                        (3U)
#define LPUART_ISR_ORE_Msk                        (0x1UL<<LPUART_ISR_ORE_Pos)                       /*!< 0x00000008 */
#define LPUART_ISR_ORE                            LPUART_ISR_ORE_Msk                                /*!< Overrun error flag */
#define LPUART_ISR_IDLE_Pos                       (4U)
#define LPUART_ISR_IDLE_Msk                       (0x1UL<<LPUART_ISR_IDLE_Pos)                      /*!< 0x00000010 */
#define LPUART_ISR_IDLE                           LPUART_ISR_IDLE_Msk                               /*!< idle flag */
#define LPUART_ISR_RXNE_Pos                       (5U)
#define LPUART_ISR_RXNE_Msk                       (0x1UL<<LPUART_ISR_RXNE_Pos)                      /*!< 0x00000020 */
#define LPUART_ISR_RXNE                           LPUART_ISR_RXNE_Msk                               /*!< RX register not empty */
#define LPUART_ISR_TC_Pos                         (6U)
#define LPUART_ISR_TC_Msk                         (0x1UL<<LPUART_ISR_TC_Pos)                        /*!< 0x00000040 */
#define LPUART_ISR_TC                             LPUART_ISR_TC_Msk                                 /*!< Transmission completion flag */
#define LPUART_ISR_TXE_Pos                        (7U)
#define LPUART_ISR_TXE_Msk                        (0x1UL<<LPUART_ISR_TXE_Pos)                       /*!< 0x00000080 */
#define LPUART_ISR_TXE                            LPUART_ISR_TXE_Msk                                /*!< TX register empty */
#define LPUART_ISR_CTSIF_Pos                      (9U)
#define LPUART_ISR_CTSIF_Msk                      (0x1UL<<LPUART_ISR_CTSIF_Pos)                     /*!< 0x00000200 */
#define LPUART_ISR_CTSIF                          LPUART_ISR_CTSIF_Msk                              /*!< CTS interrupt flag */
#define LPUART_ISR_CTS_Pos                        (10U)
#define LPUART_ISR_CTS_Msk                        (0x1UL<<LPUART_ISR_CTS_Pos)                       /*!< 0x00000400 */
#define LPUART_ISR_CTS                            LPUART_ISR_CTS_Msk                                /*!< CTS flag */
#define LPUART_ISR_BUSY_Pos                       (16U)
#define LPUART_ISR_BUSY_Msk                       (0x1UL<<LPUART_ISR_BUSY_Pos)                      /*!< 0x00010000 */
#define LPUART_ISR_BUSY                           LPUART_ISR_BUSY_Msk                               /*!< Busy flag */
#define LPUART_ISR_CMF_Pos                        (17U)
#define LPUART_ISR_CMF_Msk                        (0x1UL<<LPUART_ISR_CMF_Pos)                       /*!< 0x00020000 */
#define LPUART_ISR_CMF                            LPUART_ISR_CMF_Msk                                /*!< Address match flag */
#define LPUART_ISR_SBKF_Pos                       (18U)
#define LPUART_ISR_SBKF_Msk                       (0x1UL<<LPUART_ISR_SBKF_Pos)                      /*!< 0x00040000 */
#define LPUART_ISR_SBKF                           LPUART_ISR_SBKF_Msk                               /*!< Send abort flag */
#define LPUART_ISR_RWU_Pos                        (19U)
#define LPUART_ISR_RWU_Msk                        (0x1UL<<LPUART_ISR_RWU_Pos)                       /*!< 0x00080000 */
#define LPUART_ISR_RWU                            LPUART_ISR_RWU_Msk                                /*!< Receive Mute mode wake-up flag */
#define LPUART_ISR_WUF_Pos                        (20U)
#define LPUART_ISR_WUF_Msk                        (0x1UL<<LPUART_ISR_WUF_Pos)                       /*!< 0x00100000 */
#define LPUART_ISR_WUF                            LPUART_ISR_WUF_Msk                                /*!< Wake flag from low-power mode */
#define LPUART_ISR_TEACK_Pos                      (21U)
#define LPUART_ISR_TEACK_Msk                      (0x1UL<<LPUART_ISR_TEACK_Pos)                     /*!< 0x00200000 */
#define LPUART_ISR_TEACK                          LPUART_ISR_TEACK_Msk                              /*!< Transport enable acknowledgement flag */
#define LPUART_ISR_REACK_Pos                      (22U)
#define LPUART_ISR_REACK_Msk                      (0x1UL<<LPUART_ISR_REACK_Pos)                     /*!< 0x00400000 */
#define LPUART_ISR_REACK                          LPUART_ISR_REACK_Msk                              /*!< Receive the enable acknowledgment flag */

/********************************* Bit definition for LPUART_ICR register *******************************************/
#define LPUART_ICR_PECF_Pos                       (0U)
#define LPUART_ICR_PECF_Msk                       (0x1UL<<LPUART_ICR_PECF_Pos)                      /*!< 0x00000001 */
#define LPUART_ICR_PECF                           LPUART_ICR_PECF_Msk                               /*!< Check value error flag reset */
#define LPUART_ICR_FECF_Pos                       (1U)
#define LPUART_ICR_FECF_Msk                       (0x1UL<<LPUART_ICR_FECF_Pos)                      /*!< 0x00000002 */
#define LPUART_ICR_FECF                           LPUART_ICR_FECF_Msk                               /*!< Frame error flag reset */
#define LPUART_ICR_NECF_Pos                       (2U)
#define LPUART_ICR_NECF_Msk                       (0x1UL<<LPUART_ICR_NECF_Pos)                      /*!< 0x00000004 */
#define LPUART_ICR_NECF                           LPUART_ICR_NECF_Msk                               /*!< Clear the START bit noise flag */
#define LPUART_ICR_ORECF_Pos                      (3U)
#define LPUART_ICR_ORECF_Msk                      (0x1UL<<LPUART_ICR_ORECF_Pos)                     /*!< 0x00000008 */
#define LPUART_ICR_ORECF                          LPUART_ICR_ORECF_Msk                              /*!< Overrun error flag reset */
#define LPUART_ICR_IDLECF_Pos                     (4U)
#define LPUART_ICR_IDLECF_Msk                     (0x1UL<<LPUART_ICR_IDLECF_Pos)                    /*!< 0x00000010 */
#define LPUART_ICR_IDLECF                         LPUART_ICR_IDLECF_Msk                             /*!< Clear idle flag  */
#define LPUART_ICR_TCCF_Pos                       (6U)
#define LPUART_ICR_TCCF_Msk                       (0x1UL<<LPUART_ICR_TCCF_Pos)                      /*!< 0x00000040 */
#define LPUART_ICR_TCCF                           LPUART_ICR_TCCF_Msk                               /*!< Transfer completion flag reset */
#define LPUART_ICR_CTSCF_Pos                      (9U)
#define LPUART_ICR_CTSCF_Msk                      (0x1UL<<LPUART_ICR_CTSCF_Pos)                     /*!< 0x00000200 */
#define LPUART_ICR_CTSCF                          LPUART_ICR_CTSCF_Msk                              /*!< CTS flag reset */
#define LPUART_ICR_CMCF_Pos                       (17U)
#define LPUART_ICR_CMCF_Msk                       (0x1UL<<LPUART_ICR_CMCF_Pos)                      /*!< 0x00020000 */
#define LPUART_ICR_CMCF                           LPUART_ICR_CMCF_Msk                               /*!< Address matching flag reset */
#define LPUART_ICR_WUCF_Pos                       (20U)
#define LPUART_ICR_WUCF_Msk                       (0x1UL<<LPUART_ICR_WUCF_Pos)                      /*!< 0x00100000 */
#define LPUART_ICR_WUCF                           LPUART_ICR_WUCF_Msk                               /*!< Low power wake-up flag reset */

/********************************* Bit definition for LPUART_RDR register *******************************************/
#define LPUART_RDR_RDR_Pos                        (0U)
#define LPUART_RDR_RDR_Msk                        (0x1FFUL<<LPUART_RDR_RDR_Pos)                     /*!< 0x000001FF */
#define LPUART_RDR_RDR                            LPUART_RDR_RDR_Msk                                /*!< Receive Data Register */

/********************************* Bit definition for LPUART_TDR register *******************************************/
#define LPUART_TDR_TDR_Pos                        (0U)
#define LPUART_TDR_TDR_Msk                        (0x1FFUL<<LPUART_TDR_TDR_Pos)                     /*!< 0x000001FF */
#define LPUART_TDR_TDR                            LPUART_TDR_TDR_Msk                                /*!< Transmit Data Register */

/********************************* Bit definition for LPUART_PRESC register *****************************************/
#define LPUART_PRESC_PRESCALER_Pos                (0U)
#define LPUART_PRESC_PRESCALER_Msk                (0xFUL<<LPUART_PRESC_PRESCALER_Pos)               /*!< 0x0000000F */
#define LPUART_PRESC_PRESCALER                    LPUART_PRESC_PRESCALER_Msk                        /*!< Input clock prescaler register */
#define LPUART_PRESC_PRESCALER_0                  (0x1UL<<LPUART_PRESC_PRESCALER_Pos)               /*!< 0x00000001 */
#define LPUART_PRESC_PRESCALER_1                  (0x2UL<<LPUART_PRESC_PRESCALER_Pos)               /*!< 0x00000002 */
#define LPUART_PRESC_PRESCALER_2                  (0x4UL<<LPUART_PRESC_PRESCALER_Pos)               /*!< 0x00000004 */
#define LPUART_PRESC_PRESCALER_3                  (0x8UL<<LPUART_PRESC_PRESCALER_Pos)               /*!< 0x00000008 */

/********************************* Bit definition for LPUART_DBG register *******************************************/
#define LPUART_DBG_DBGSEL_Pos                     (0U)
#define LPUART_DBG_DBGSEL_Msk                     (0x3UL<<LPUART_DBG_DBGSEL_Pos)                    /*!< 0x00000003 */
#define LPUART_DBG_DBGSEL                         LPUART_DBG_DBGSEL_Msk                             /*!< debug select */
#define LPUART_DBG_DBGSEL_0                       (0x1UL<<LPUART_DBG_DBGSEL_Pos)                    /*!< 0x00000001 */
#define LPUART_DBG_DBGSEL_1                       (0x2UL<<LPUART_DBG_DBGSEL_Pos)                    /*!< 0x00000002 */
#define LPUART_DBG_OFFSET_ADD_Pos                 (24U)
#define LPUART_DBG_OFFSET_ADD_Msk                 (0xFFUL<<LPUART_DBG_OFFSET_ADD_Pos)               /*!< 0xFF000000 */
#define LPUART_DBG_OFFSET_ADD                     LPUART_DBG_OFFSET_ADD_Msk                         /*!< offset add */


/********************************************************************************************************************/
/********************************* OPA ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for OPA_OCR register **********************************************/
#define OPA_OCR_OPA_EXTOEN_Pos                    (0U)
#define OPA_OCR_OPA_EXTOEN_Msk                    (0x1UL<<OPA_OCR_OPA_EXTOEN_Pos)                   /*!< 0x00000001 */
#define OPA_OCR_OPA_EXTOEN                        OPA_OCR_OPA_EXTOEN_Msk                            
#define OPA_OCR_OPA_EXTOSEL_Pos                   (1U)
#define OPA_OCR_OPA_EXTOSEL_Msk                   (0x3UL<<OPA_OCR_OPA_EXTOSEL_Pos)                  /*!< 0x00000006 */
#define OPA_OCR_OPA_EXTOSEL                       OPA_OCR_OPA_EXTOSEL_Msk 
#define OPA_OCR_OPA_EXTOSEL_0                     (0x1UL<<OPA_OCR_OPA_EXTOSEL_Pos)                  /*!< 0x00000002 */  
#define OPA_OCR_OPA_EXTOSEL_1                     (0x2UL<<OPA_OCR_OPA_EXTOSEL_Pos)                  /*!< 0x00000004 */                          

/********************************* Bit definition for OPA_CR register ***********************************************/
#define OPA_CR_OPA_VINPSEL_Pos                    (0U)
#define OPA_CR_OPA_VINPSEL_Msk                    (0x1UL<<OPA_CR_OPA_VINPSEL_Pos)                   /*!< 0x00000001 */
#define OPA_CR_OPA_VINPSEL                        OPA_CR_OPA_VINPSEL_Msk                            
#define OPA_CR_OPA_VINMSEL_Pos                    (2U)
#define OPA_CR_OPA_VINMSEL_Msk                    (0x1UL<<OPA_CR_OPA_VINMSEL_Pos)                   /*!< 0x00000004 */
#define OPA_CR_OPA_VINMSEL                        OPA_CR_OPA_VINMSEL_Msk                            
#define OPA_CR_OPAEN_Pos                          (5U)
#define OPA_CR_OPAEN_Msk                          (0x1UL<<OPA_CR_OPAEN_Pos)                         /*!< 0x00000020 */
#define OPA_CR_OPAEN                              OPA_CR_OPAEN_Msk                                  

/********************************* Bit definition for OPA_TMR register **********************************************/
#define OPA_TMR_OPA_TM_Pos                        (0U)
#define OPA_TMR_OPA_TM_Msk                        (0x1UL<<OPA_TMR_OPA_TM_Pos)                       /*!< 0x00000001 */
#define OPA_TMR_OPA_TM                            OPA_TMR_OPA_TM_Msk                                
                            


/********************************************************************************************************************/
/********************************* PWR ******************************************************************************/
/********************************************************************************************************************/
#define PWR_PVD_SUPPORT                       /*!< PWR feature available only on specific devices: Power Voltage Detection feature */

/********************************* Bit definition for PWR_CR1 register **********************************************/
#define PWR_CR1_LPMS_Pos                          (0U)
#define PWR_CR1_LPMS_Msk                          (0x7UL<<PWR_CR1_LPMS_Pos)                         /*!< 0x00000007 */
#define PWR_CR1_LPMS                              PWR_CR1_LPMS_Msk
#define PWR_CR1_LPMS_0                            (0x1UL<<PWR_CR1_LPMS_Pos)                         /*!< 0x00000001 */
#define PWR_CR1_LPMS_1                            (0x2UL<<PWR_CR1_LPMS_Pos)                         /*!< 0x00000002 */
#define PWR_CR1_LPMS_2                            (0x4UL<<PWR_CR1_LPMS_Pos)                         /*!< 0x00000004 */
#define PWR_CR1_DBP_Pos                           (8U)
#define PWR_CR1_DBP_Msk                           (0x1UL<<PWR_CR1_DBP_Pos)                          /*!< 0x00000100 */
#define PWR_CR1_DBP                               PWR_CR1_DBP_Msk                                   
#define PWR_CR1_VR_MODE_Pos                       (9U)
#define PWR_CR1_VR_MODE_Msk                       (0x3UL<<PWR_CR1_VR_MODE_Pos)                      /*!< 0x00000600 */
#define PWR_CR1_VR_MODE                           PWR_CR1_VR_MODE_Msk
#define PWR_CR1_VR_MODE_0                         (0x1UL<<PWR_CR1_VR_MODE_Pos)                      /*!< 0x00000200 */
#define PWR_CR1_VR_MODE_1                         (0x2UL<<PWR_CR1_VR_MODE_Pos)                      /*!< 0x00000400 */
#define PWR_CR1_FLS_SLPTIME_Pos                   (12U)
#define PWR_CR1_FLS_SLPTIME_Msk                   (0x3UL<<PWR_CR1_FLS_SLPTIME_Pos)                  /*!< 0x00003000 */
#define PWR_CR1_FLS_SLPTIME                       PWR_CR1_FLS_SLPTIME_Msk
#define PWR_CR1_FLS_SLPTIME_0                     (0x1UL<<PWR_CR1_FLS_SLPTIME_Pos)                  /*!< 0x00001000 */
#define PWR_CR1_FLS_SLPTIME_1                     (0x2UL<<PWR_CR1_FLS_SLPTIME_Pos)                  /*!< 0x00002000 */
#define PWR_CR1_MR_VSEL_Pos                       (16U)
#define PWR_CR1_MR_VSEL_Msk                       (0x3UL<<PWR_CR1_MR_VSEL_Pos)                      /*!< 0x00003000 */
#define PWR_CR1_MR_VSEL                           PWR_CR1_MR_VSEL_Msk
#define PWR_CR1_MR_VSEL_0                         (0x1UL<<PWR_CR1_MR_VSEL_Pos)                      /*!< 0x00001000 */
#define PWR_CR1_MR_VSEL_1                         (0x2UL<<PWR_CR1_MR_VSEL_Pos)                      /*!< 0x00002000 */
#define PWR_CR1_LPR_VSEL_Pos                      (18U)
#define PWR_CR1_LPR_VSEL_Msk                      (0x3UL<<PWR_CR1_LPR_VSEL_Pos)                     /*!< 0x00003000 */
#define PWR_CR1_LPR_VSEL                          PWR_CR1_LPR_VSEL_Msk
#define PWR_CR1_LPR_VSEL_0                        (0x1UL<<PWR_CR1_LPR_VSEL_Pos)                     /*!< 0x00001000 */
#define PWR_CR1_LPR_VSEL_1                        (0x2UL<<PWR_CR1_LPR_VSEL_Pos)                     /*!< 0x00002000 */
#define PWR_CR1_DLPR_VSEL_Pos                     (20U)
#define PWR_CR1_DLPR_VSEL_Msk                     (0x3UL<<PWR_CR1_DLPR_VSEL_Pos)                    /*!< 0x00003000 */
#define PWR_CR1_DLPR_VSEL                         PWR_CR1_DLPR_VSEL_Msk
#define PWR_CR1_DLPR_VSEL_0                       (0x1UL<<PWR_CR1_DLPR_VSEL_Pos)                    /*!< 0x00001000 */
#define PWR_CR1_DLPR_VSEL_1                       (0x2UL<<PWR_CR1_DLPR_VSEL_Pos)                    /*!< 0x00002000 */
#define PWR_CR1_FLSSLP_CTRL_Pos                   (24U)
#define PWR_CR1_FLSSLP_CTRL_Msk                   (0x1UL<<PWR_CR1_FLSSLP_CTRL_Pos)                  /*!< 0x01000000 */
#define PWR_CR1_FLSSLP_CTRL                       PWR_CR1_FLSSLP_CTRL_Msk                           
#define PWR_CR1_HSION_CTRL_Pos                    (25U)
#define PWR_CR1_HSION_CTRL_Msk                    (0x1UL<<PWR_CR1_HSION_CTRL_Pos)                   /*!< 0x02000000 */
#define PWR_CR1_HSION_CTRL                        PWR_CR1_HSION_CTRL_Msk                            
#define PWR_CR1_STDBY_MRRDY_WAIT_Pos              (26U)
#define PWR_CR1_STDBY_MRRDY_WAIT_Msk              (0x3UL<<PWR_CR1_STDBY_MRRDY_WAIT_Pos)             /*!< 0x0C000000 */
#define PWR_CR1_STDBY_MRRDY_WAIT                  PWR_CR1_STDBY_MRRDY_WAIT_Msk
#define PWR_CR1_STDBY_MRRDY_WAIT_0                (0x1UL<<PWR_CR1_STDBY_MRRDY_WAIT_Pos)             /*!< 0x04000000 */
#define PWR_CR1_STDBY_MRRDY_WAIT_1                (0x2UL<<PWR_CR1_STDBY_MRRDY_WAIT_Pos)             /*!< 0x08000000 */

/********************************* Bit definition for PWR_CR2 register **********************************************/
#define PWR_CR2_PVDE_Pos                          (0U)
#define PWR_CR2_PVDE_Msk                          (0x1UL<<PWR_CR2_PVDE_Pos)                         /*!< 0x00000001 */
#define PWR_CR2_PVDE                              PWR_CR2_PVDE_Msk                                  
#define PWR_CR2_PVDT_Pos                          (4U)
#define PWR_CR2_PVDT_Msk                          (0x7UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000070 */
#define PWR_CR2_PVDT                              PWR_CR2_PVDT_Msk
#define PWR_CR2_PVDT_0                            (0x1UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000010 */
#define PWR_CR2_PVDT_1                            (0x2UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000020 */
#define PWR_CR2_PVDT_2                            (0x4UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000040 */
#define PWR_CR2_PVD_OUT_SEL_Pos                   (7U)
#define PWR_CR2_PVD_OUT_SEL_Msk                   (0x1UL<<PWR_CR2_PVD_OUT_SEL_Pos)                  /*!< 0x00000080 */
#define PWR_CR2_PVD_OUT_SEL                       PWR_CR2_PVD_OUT_SEL_Msk                           
#define PWR_CR2_FLTEN_Pos                         (8U)
#define PWR_CR2_FLTEN_Msk                         (0x1UL<<PWR_CR2_FLTEN_Pos)                        /*!< 0x00000100 */
#define PWR_CR2_FLTEN                             PWR_CR2_FLTEN_Msk                                 
#define PWR_CR2_FLT_TIME_Pos                      (9U)
#define PWR_CR2_FLT_TIME_Msk                      (0x7UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000E00 */
#define PWR_CR2_FLT_TIME                          PWR_CR2_FLT_TIME_Msk
#define PWR_CR2_FLT_TIME_0                        (0x1UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000200 */
#define PWR_CR2_FLT_TIME_1                        (0x2UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000400 */
#define PWR_CR2_FLT_TIME_2                        (0x4UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000800 */
#define PWR_CR2_PVDT_1V8                          (0x00000000U)
#define PWR_CR2_PVDT_2V0                          (0x00000010U)
#define PWR_CR2_PVDT_2V2                          (0x00000020U)
#define PWR_CR2_PVDT_2V4                          (0x00000030U)
#define PWR_CR2_PVDT_2V8                          (0x00000040U)
#define PWR_CR2_PVDT_3V1                          (0x00000050U)
#define PWR_CR2_PVDT_3V7                          (0x00000060U)
#define PWR_CR2_PVDT_4V2                          (0x00000070U)

/********************************* Bit definition for PWR_CR3 register **********************************************/
#define PWR_CR3_EWUP0_Pos                         (0U)
#define PWR_CR3_EWUP0_Msk                         (0x1UL<<PWR_CR3_EWUP0_Pos)                        /*!< 0x00000001 */
#define PWR_CR3_EWUP0                             PWR_CR3_EWUP0_Msk                                 
#define PWR_CR3_EWUP1_Pos                         (1U)
#define PWR_CR3_EWUP1_Msk                         (0x1UL<<PWR_CR3_EWUP1_Pos)                        /*!< 0x00000002 */
#define PWR_CR3_EWUP1                             PWR_CR3_EWUP1_Msk                                 
#define PWR_CR3_EWUP2_Pos                         (2U)
#define PWR_CR3_EWUP2_Msk                         (0x1UL<<PWR_CR3_EWUP2_Pos)                        /*!< 0x00000004 */
#define PWR_CR3_EWUP2                             PWR_CR3_EWUP2_Msk                                 
#define PWR_CR3_EWUP3_Pos                         (3U)
#define PWR_CR3_EWUP3_Msk                         (0x1UL<<PWR_CR3_EWUP3_Pos)                        /*!< 0x00000008 */
#define PWR_CR3_EWUP3                             PWR_CR3_EWUP3_Msk                                 
#define PWR_CR3_EWUP4_Pos                         (4U)
#define PWR_CR3_EWUP4_Msk                         (0x1UL<<PWR_CR3_EWUP4_Pos)                        /*!< 0x00000010 */
#define PWR_CR3_EWUP4                             PWR_CR3_EWUP4_Msk                                 
#define PWR_CR3_EWUP5_Pos                         (5U)
#define PWR_CR3_EWUP5_Msk                         (0x1UL<<PWR_CR3_EWUP5_Pos)                        /*!< 0x00000020 */
#define PWR_CR3_EWUP5                             PWR_CR3_EWUP5_Msk                                 
#define PWR_CR3_EWUP6_Pos                         (6U)
#define PWR_CR3_EWUP6_Msk                         (0x1UL<<PWR_CR3_EWUP6_Pos)                        /*!< 0x00000040 */
#define PWR_CR3_EWUP6                             PWR_CR3_EWUP6_Msk                                 
#define PWR_CR3_EWUP7_Pos                         (7U)
#define PWR_CR3_EWUP7_Msk                         (0x1UL<<PWR_CR3_EWUP7_Pos)                        /*!< 0x00000080 */
#define PWR_CR3_EWUP7                             PWR_CR3_EWUP7_Msk                                 
#define PWR_CR3_EWUP_Pos                          (0U)
#define PWR_CR3_EWUP_Msk                          (0xFFUL<<PWR_CR3_EWUP_Pos)                        /*!< 0x000000FF */
#define PWR_CR3_EWUP                              PWR_CR3_EWUP_Msk                                 
#define PWR_CR3_LD_EN_Pos                         (8U)
#define PWR_CR3_LD_EN_Msk                         (0x1UL<<PWR_CR3_LD_EN_Pos)                        /*!< 0x00000100 */
#define PWR_CR3_LD_EN                             PWR_CR3_LD_EN_Msk                                 
#define PWR_CR3_APC_Pos                           (9U)
#define PWR_CR3_APC_Msk                           (0x1UL<<PWR_CR3_APC_Pos)                          /*!< 0x00000200 */
#define PWR_CR3_APC                               PWR_CR3_APC_Msk                                   
#define PWR_CR3_SRAM1PDSTD_Pos                    (10U)
#define PWR_CR3_SRAM1PDSTD_Msk                    (0x1UL<<PWR_CR3_SRAM1PDSTD_Pos)                   /*!< 0x00000400 */
#define PWR_CR3_SRAM1PDSTD                        PWR_CR3_SRAM1PDSTD_Msk                                   

/********************************* Bit definition for PWR_CR4 register **********************************************/
#define PWR_CR4_WP0_Pos                           (0U)
#define PWR_CR4_WP0_Msk                           (0x3UL<<PWR_CR4_WP0_Pos)                          /*!< 0x00000003 */
#define PWR_CR4_WP0                               PWR_CR4_WP0_Msk
#define PWR_CR4_WP0_0                             (0x1UL<<PWR_CR4_WP0_Pos)                          /*!< 0x00000001 */
#define PWR_CR4_WP0_1                             (0x2UL<<PWR_CR4_WP0_Pos)                          /*!< 0x00000002 */
#define PWR_CR4_WP1_Pos                           (2U)
#define PWR_CR4_WP1_Msk                           (0x3UL<<PWR_CR4_WP1_Pos)                          /*!< 0x0000000C */
#define PWR_CR4_WP1                               PWR_CR4_WP1_Msk
#define PWR_CR4_WP1_0                             (0x1UL<<PWR_CR4_WP1_Pos)                          /*!< 0x00000004 */
#define PWR_CR4_WP1_1                             (0x2UL<<PWR_CR4_WP1_Pos)                          /*!< 0x00000008 */
#define PWR_CR4_WP2_Pos                           (4U)
#define PWR_CR4_WP2_Msk                           (0x3UL<<PWR_CR4_WP2_Pos)                          /*!< 0x00000030 */
#define PWR_CR4_WP2                               PWR_CR4_WP2_Msk
#define PWR_CR4_WP2_0                             (0x1UL<<PWR_CR4_WP2_Pos)                          /*!< 0x00000010 */
#define PWR_CR4_WP2_1                             (0x2UL<<PWR_CR4_WP2_Pos)                          /*!< 0x00000020 */
#define PWR_CR4_WP3_Pos                           (6U)
#define PWR_CR4_WP3_Msk                           (0x3UL<<PWR_CR4_WP3_Pos)                          /*!< 0x000000C0 */
#define PWR_CR4_WP3                               PWR_CR4_WP3_Msk
#define PWR_CR4_WP3_0                             (0x1UL<<PWR_CR4_WP3_Pos)                          /*!< 0x00000040 */
#define PWR_CR4_WP3_1                             (0x2UL<<PWR_CR4_WP3_Pos)                          /*!< 0x00000080 */
#define PWR_CR4_WP4_Pos                           (8U)
#define PWR_CR4_WP4_Msk                           (0x3UL<<PWR_CR4_WP4_Pos)                          /*!< 0x00000300 */
#define PWR_CR4_WP4                               PWR_CR4_WP4_Msk
#define PWR_CR4_WP4_0                             (0x1UL<<PWR_CR4_WP4_Pos)                          /*!< 0x00000100 */
#define PWR_CR4_WP4_1                             (0x2UL<<PWR_CR4_WP4_Pos)                          /*!< 0x00000200 */
#define PWR_CR4_WP5_Pos                           (10U)
#define PWR_CR4_WP5_Msk                           (0x3UL<<PWR_CR4_WP5_Pos)                          /*!< 0x00000C00 */
#define PWR_CR4_WP5                               PWR_CR4_WP5_Msk
#define PWR_CR4_WP5_0                             (0x1UL<<PWR_CR4_WP5_Pos)                          /*!< 0x00000400 */
#define PWR_CR4_WP5_1                             (0x2UL<<PWR_CR4_WP5_Pos)                          /*!< 0x00000800 */
#define PWR_CR4_WP6_Pos                           (12U)
#define PWR_CR4_WP6_Msk                           (0x3UL<<PWR_CR4_WP6_Pos)                          /*!< 0x00003000 */
#define PWR_CR4_WP6                               PWR_CR4_WP6_Msk
#define PWR_CR4_WP6_0                             (0x1UL<<PWR_CR4_WP6_Pos)                          /*!< 0x00001000 */
#define PWR_CR4_WP6_1                             (0x2UL<<PWR_CR4_WP6_Pos)                          /*!< 0x00002000 */
#define PWR_CR4_WP7_Pos                           (14U)
#define PWR_CR4_WP7_Msk                           (0x3UL<<PWR_CR4_WP7_Pos)                          /*!< 0x0000C000 */
#define PWR_CR4_WP7                               PWR_CR4_WP7_Msk
#define PWR_CR4_WP7_0                             (0x1UL<<PWR_CR4_WP7_Pos)                          /*!< 0x00004000 */
#define PWR_CR4_WP7_1                             (0x2UL<<PWR_CR4_WP7_Pos)                          /*!< 0x00008000 */

/********************************* Bit definition for PWR_SR register ***********************************************/
#define PWR_SR_WUF0_Pos                           (0U)
#define PWR_SR_WUF0_Msk                           (0x1UL<<PWR_SR_WUF0_Pos)                          /*!< 0x00000001 */
#define PWR_SR_WUF0                               PWR_SR_WUF0_Msk                                   
#define PWR_SR_WUF1_Pos                           (1U)
#define PWR_SR_WUF1_Msk                           (0x1UL<<PWR_SR_WUF1_Pos)                          /*!< 0x00000002 */
#define PWR_SR_WUF1                               PWR_SR_WUF1_Msk                                   
#define PWR_SR_WUF2_Pos                           (2U)
#define PWR_SR_WUF2_Msk                           (0x1UL<<PWR_SR_WUF2_Pos)                          /*!< 0x00000004 */
#define PWR_SR_WUF2                               PWR_SR_WUF2_Msk                                   
#define PWR_SR_WUF3_Pos                           (3U)
#define PWR_SR_WUF3_Msk                           (0x1UL<<PWR_SR_WUF3_Pos)                          /*!< 0x00000008 */
#define PWR_SR_WUF3                               PWR_SR_WUF3_Msk                                   
#define PWR_SR_WUF4_Pos                           (4U)
#define PWR_SR_WUF4_Msk                           (0x1UL<<PWR_SR_WUF4_Pos)                          /*!< 0x00000010 */
#define PWR_SR_WUF4                               PWR_SR_WUF4_Msk                                   
#define PWR_SR_WUF5_Pos                           (5U)
#define PWR_SR_WUF5_Msk                           (0x1UL<<PWR_SR_WUF5_Pos)                          /*!< 0x00000020 */
#define PWR_SR_WUF5                               PWR_SR_WUF5_Msk                                   
#define PWR_SR_WUF6_Pos                           (6U)
#define PWR_SR_WUF6_Msk                           (0x1UL<<PWR_SR_WUF6_Pos)                          /*!< 0x00000040 */
#define PWR_SR_WUF6                               PWR_SR_WUF6_Msk                                   
#define PWR_SR_WUF7_Pos                           (7U)
#define PWR_SR_WUF7_Msk                           (0x1UL<<PWR_SR_WUF7_Pos)                          /*!< 0x00000080 */
#define PWR_SR_WUF7                               PWR_SR_WUF7_Msk                                   
#define PWR_SR_WUF_Pos                            (0U)
#define PWR_SR_WUF_Msk                            (0xFFUL<<PWR_SR_WUF_Pos)                          /*!< 0x000000FF */
#define PWR_SR_WUF                                PWR_SR_WUF_Msk                                   
#define PWR_SR_SBF_Pos                            (8U)
#define PWR_SR_SBF_Msk                            (0x1UL<<PWR_SR_SBF_Pos)                           /*!< 0x00000100 */
#define PWR_SR_SBF                                PWR_SR_SBF_Msk                                    
#define PWR_SR_MR_RDY_Pos                         (9U)
#define PWR_SR_MR_RDY_Msk                         (0x1UL<<PWR_SR_MR_RDY_Pos)                        /*!< 0x00000200 */
#define PWR_SR_MR_RDY                             PWR_SR_MR_RDY_Msk                                 
//#define PWR_SR_MR_VOS_RDY_Pos                     (10U)
//#define PWR_SR_MR_VOS_RDY_Msk                     (0x1UL<<PWR_SR_MR_VOS_RDY_Pos)                  /*!< 0x00000400 */
//#define PWR_SR_MR_VOS_RDY                         PWR_SR_MR_VOS_RDY_Msk                           
#define PWR_SR_LPRUN_RUN_SWF_Pos                  (11U)
#define PWR_SR_LPRUN_RUN_SWF_Msk                  (0x1UL<<PWR_SR_LPRUN_RUN_SWF_Pos)                 /*!< 0x00000800 */
#define PWR_SR_LPRUN_RUN_SWF                       PWR_SR_LPRUN_RUN_SWF_Msk                         
#define PWR_SR_IWDGRST_WUF_Pos                    (12U)
#define PWR_SR_IWDGRST_WUF_Msk                    (0x1UL<<PWR_SR_IWDGRST_WUF_Pos)                   /*!< 0x00001000 */
#define PWR_SR_IWDGRST_WUF                        PWR_SR_IWDGRST_WUF_Msk                            
#define PWR_SR_PINRST_WUF_Pos                     (13U)
#define PWR_SR_PINRST_WUF_Msk                     (0x1UL<<PWR_SR_PINRST_WUF_Pos)                    /*!< 0x00002000 */
#define PWR_SR_PINRST_WUF                         PWR_SR_PINRST_WUF_Msk                             
#define PWR_SR_VCC_PORF_Pos                       (14U)
#define PWR_SR_VCC_PORF_Msk                       (0x1UL<<PWR_SR_VCC_PORF_Pos)                      /*!< 0x00004000 */
#define PWR_SR_VCC_PORF                           PWR_SR_VCC_PORF_Msk                             
#define PWR_SR_PVDO_Pos                           (16U)
#define PWR_SR_PVDO_Msk                           (0x1UL<<PWR_SR_PVDO_Pos)                          /*!< 0x00010000 */
#define PWR_SR_PVDO                               PWR_SR_PVDO_Msk                                   

/********************************* Bit definition for PWR_SCR register **********************************************/
#define PWR_SCR_CWUF0_Pos                         (0U)
#define PWR_SCR_CWUF0_Msk                         (0x1UL<<PWR_SCR_CWUF0_Pos)                        /*!< 0x00000001 */
#define PWR_SCR_CWUF0                             PWR_SCR_CWUF0_Msk                                 
#define PWR_SCR_CWUF1_Pos                         (1U)
#define PWR_SCR_CWUF1_Msk                         (0x1UL<<PWR_SCR_CWUF1_Pos)                        /*!< 0x00000002 */
#define PWR_SCR_CWUF1                             PWR_SCR_CWUF1_Msk                                 
#define PWR_SCR_CWUF2_Pos                         (2U)
#define PWR_SCR_CWUF2_Msk                         (0x1UL<<PWR_SCR_CWUF2_Pos)                        /*!< 0x00000004 */
#define PWR_SCR_CWUF2                             PWR_SCR_CWUF2_Msk                                 
#define PWR_SCR_CWUF3_Pos                         (3U)
#define PWR_SCR_CWUF3_Msk                         (0x1UL<<PWR_SCR_CWUF3_Pos)                        /*!< 0x00000008 */
#define PWR_SCR_CWUF3                             PWR_SCR_CWUF3_Msk                                 
#define PWR_SCR_CWUF4_Pos                         (4U)
#define PWR_SCR_CWUF4_Msk                         (0x1UL<<PWR_SCR_CWUF4_Pos)                        /*!< 0x00000010 */
#define PWR_SCR_CWUF4                             PWR_SCR_CWUF4_Msk                                 
#define PWR_SCR_CWUF5_Pos                         (5U)
#define PWR_SCR_CWUF5_Msk                         (0x1UL<<PWR_SCR_CWUF5_Pos)                        /*!< 0x00000020 */
#define PWR_SCR_CWUF5                             PWR_SCR_CWUF5_Msk                                 
#define PWR_SCR_CWUF6_Pos                         (6U)
#define PWR_SCR_CWUF6_Msk                         (0x1UL<<PWR_SCR_CWUF6_Pos)                        /*!< 0x00000040 */
#define PWR_SCR_CWUF6                             PWR_SCR_CWUF6_Msk                                 
#define PWR_SCR_CWUF7_Pos                         (7U)
#define PWR_SCR_CWUF7_Msk                         (0x1UL<<PWR_SCR_CWUF7_Pos)                        /*!< 0x00000080 */
#define PWR_SCR_CWUF7                             PWR_SCR_CWUF7_Msk                                 
#define PWR_SCR_CWUF_Pos                          (0U)
#define PWR_SCR_CWUF_Msk                          (0xFFUL<<PWR_SCR_CWUF_Pos)                          /*!< 0x000000FF */
#define PWR_SCR_CWUF                              PWR_SCR_CWUF_Msk                                   
#define PWR_SCR_CSBF_Pos                          (8U)
#define PWR_SCR_CSBF_Msk                          (0x1UL<<PWR_SCR_CSBF_Pos)                         /*!< 0x00000100 */
#define PWR_SCR_CSBF                              PWR_SCR_CSBF_Msk                                  
#define PWR_SCR_CIWDGRSTWUF_Pos                   (12U)
#define PWR_SCR_CIWDGRSTWUF_Msk                   (0x1UL<<PWR_SCR_CIWDGRSTWUF_Pos)                  /*!< 0x00001000 */
#define PWR_SCR_CIWDGRSTWUF                       PWR_SCR_CIWDGRSTWUF_Msk                          
#define PWR_SCR_CPINRSTWUF_Pos                    (13U)
#define PWR_SCR_CPINRSTWUF_Msk                    (0x1UL<<PWR_SCR_CPINRSTWUF_Pos)                   /*!< 0x00002000 */
#define PWR_SCR_CPINRSTWUF                        PWR_SCR_CPINRSTWUF_Msk                           
#define PWR_SCR_CVCCPORF_Pos                      (14U)
#define PWR_SCR_CVCCPORF_Msk                      (0x1UL<<PWR_SCR_CVCCPORF_Pos)                     /*!< 0x00004000 */
#define PWR_SCR_CVCCPORF                          PWR_SCR_CVCCPORF_Msk                           

/********************************* Bit definition for PWR_PUCRA register ********************************************/
#define PWR_PUCRA_PA_PU0_Pos                      (0U)
#define PWR_PUCRA_PA_PU0_Msk                      (0x1UL<<PWR_PUCRA_PA_PU0_Pos)                     /*!< 0x00000001 */
#define PWR_PUCRA_PA_PU0                          PWR_PUCRA_PA_PU0_Msk                              
#define PWR_PUCRA_PA_PU1_Pos                      (1U)
#define PWR_PUCRA_PA_PU1_Msk                      (0x1UL<<PWR_PUCRA_PA_PU1_Pos)                     /*!< 0x00000002 */
#define PWR_PUCRA_PA_PU1                          PWR_PUCRA_PA_PU1_Msk                              
#define PWR_PUCRA_PA_PU2_Pos                      (2U)
#define PWR_PUCRA_PA_PU2_Msk                      (0x1UL<<PWR_PUCRA_PA_PU2_Pos)                     /*!< 0x00000004 */
#define PWR_PUCRA_PA_PU2                          PWR_PUCRA_PA_PU2_Msk                              
#define PWR_PUCRA_PA_PU3_Pos                      (3U)
#define PWR_PUCRA_PA_PU3_Msk                      (0x1UL<<PWR_PUCRA_PA_PU3_Pos)                     /*!< 0x00000008 */
#define PWR_PUCRA_PA_PU3                          PWR_PUCRA_PA_PU3_Msk                              
#define PWR_PUCRA_PA_PU4_Pos                      (4U)
#define PWR_PUCRA_PA_PU4_Msk                      (0x1UL<<PWR_PUCRA_PA_PU4_Pos)                     /*!< 0x00000010 */
#define PWR_PUCRA_PA_PU4                          PWR_PUCRA_PA_PU4_Msk                              
#define PWR_PUCRA_PA_PU5_Pos                      (5U)
#define PWR_PUCRA_PA_PU5_Msk                      (0x1UL<<PWR_PUCRA_PA_PU5_Pos)                     /*!< 0x00000020 */
#define PWR_PUCRA_PA_PU5                          PWR_PUCRA_PA_PU5_Msk                              
#define PWR_PUCRA_PA_PU6_Pos                      (6U)
#define PWR_PUCRA_PA_PU6_Msk                      (0x1UL<<PWR_PUCRA_PA_PU6_Pos)                     /*!< 0x00000040 */
#define PWR_PUCRA_PA_PU6                          PWR_PUCRA_PA_PU6_Msk                              
#define PWR_PUCRA_PA_PU7_Pos                      (7U)
#define PWR_PUCRA_PA_PU7_Msk                      (0x1UL<<PWR_PUCRA_PA_PU7_Pos)                     /*!< 0x00000080 */
#define PWR_PUCRA_PA_PU7                          PWR_PUCRA_PA_PU7_Msk                              
#define PWR_PUCRA_PA_PU8_Pos                      (8U)
#define PWR_PUCRA_PA_PU8_Msk                      (0x1UL<<PWR_PUCRA_PA_PU8_Pos)                     /*!< 0x00000100 */
#define PWR_PUCRA_PA_PU8                          PWR_PUCRA_PA_PU8_Msk                              
#define PWR_PUCRA_PA_PU9_Pos                      (9U)
#define PWR_PUCRA_PA_PU9_Msk                      (0x1UL<<PWR_PUCRA_PA_PU9_Pos)                     /*!< 0x00000200 */
#define PWR_PUCRA_PA_PU9                          PWR_PUCRA_PA_PU9_Msk                              
#define PWR_PUCRA_PA_PU10_Pos                     (10U)
#define PWR_PUCRA_PA_PU10_Msk                     (0x1UL<<PWR_PUCRA_PA_PU10_Pos)                    /*!< 0x00000400 */
#define PWR_PUCRA_PA_PU10                         PWR_PUCRA_PA_PU10_Msk                             
#define PWR_PUCRA_PA_PU11_Pos                     (11U)
#define PWR_PUCRA_PA_PU11_Msk                     (0x1UL<<PWR_PUCRA_PA_PU11_Pos)                    /*!< 0x00000800 */
#define PWR_PUCRA_PA_PU11                         PWR_PUCRA_PA_PU11_Msk                             
#define PWR_PUCRA_PA_PU12_Pos                     (12U)
#define PWR_PUCRA_PA_PU12_Msk                     (0x1UL<<PWR_PUCRA_PA_PU12_Pos)                    /*!< 0x00001000 */
#define PWR_PUCRA_PA_PU12                         PWR_PUCRA_PA_PU12_Msk                             
#define PWR_PUCRA_PA_PU13_Pos                     (13U)
#define PWR_PUCRA_PA_PU13_Msk                     (0x1UL<<PWR_PUCRA_PA_PU13_Pos)                    /*!< 0x00002000 */
#define PWR_PUCRA_PA_PU13                         PWR_PUCRA_PA_PU13_Msk                             
#define PWR_PUCRA_PA_PU14_Pos                     (14U)
#define PWR_PUCRA_PA_PU14_Msk                     (0x1UL<<PWR_PUCRA_PA_PU14_Pos)                    /*!< 0x00004000 */
#define PWR_PUCRA_PA_PU14                         PWR_PUCRA_PA_PU14_Msk                             
#define PWR_PUCRA_PA_PU15_Pos                     (15U)
#define PWR_PUCRA_PA_PU15_Msk                     (0x1UL<<PWR_PUCRA_PA_PU15_Pos)                    /*!< 0x00008000 */
#define PWR_PUCRA_PA_PU15                         PWR_PUCRA_PA_PU15_Msk                             

/********************************* Bit definition for PWR_PDCRA register ********************************************/
#define PWR_PDCRA_PA_PD0_Pos                      (0U)
#define PWR_PDCRA_PA_PD0_Msk                      (0x1UL<<PWR_PDCRA_PA_PD0_Pos)                     /*!< 0x00000001 */
#define PWR_PDCRA_PA_PD0                          PWR_PDCRA_PA_PD0_Msk                              
#define PWR_PDCRA_PA_PD1_Pos                      (1U)
#define PWR_PDCRA_PA_PD1_Msk                      (0x1UL<<PWR_PDCRA_PA_PD1_Pos)                     /*!< 0x00000002 */
#define PWR_PDCRA_PA_PD1                          PWR_PDCRA_PA_PD1_Msk                              
#define PWR_PDCRA_PA_PD2_Pos                      (2U)
#define PWR_PDCRA_PA_PD2_Msk                      (0x1UL<<PWR_PDCRA_PA_PD2_Pos)                     /*!< 0x00000004 */
#define PWR_PDCRA_PA_PD2                          PWR_PDCRA_PA_PD2_Msk                              
#define PWR_PDCRA_PA_PD3_Pos                      (3U)
#define PWR_PDCRA_PA_PD3_Msk                      (0x1UL<<PWR_PDCRA_PA_PD3_Pos)                     /*!< 0x00000008 */
#define PWR_PDCRA_PA_PD3                          PWR_PDCRA_PA_PD3_Msk                              
#define PWR_PDCRA_PA_PD4_Pos                      (4U)
#define PWR_PDCRA_PA_PD4_Msk                      (0x1UL<<PWR_PDCRA_PA_PD4_Pos)                     /*!< 0x00000010 */
#define PWR_PDCRA_PA_PD4                          PWR_PDCRA_PA_PD4_Msk                              
#define PWR_PDCRA_PA_PD5_Pos                      (5U)
#define PWR_PDCRA_PA_PD5_Msk                      (0x1UL<<PWR_PDCRA_PA_PD5_Pos)                     /*!< 0x00000020 */
#define PWR_PDCRA_PA_PD5                          PWR_PDCRA_PA_PD5_Msk                              
#define PWR_PDCRA_PA_PD6_Pos                      (6U)
#define PWR_PDCRA_PA_PD6_Msk                      (0x1UL<<PWR_PDCRA_PA_PD6_Pos)                     /*!< 0x00000040 */
#define PWR_PDCRA_PA_PD6                          PWR_PDCRA_PA_PD6_Msk                              
#define PWR_PDCRA_PA_PD7_Pos                      (7U)
#define PWR_PDCRA_PA_PD7_Msk                      (0x1UL<<PWR_PDCRA_PA_PD7_Pos)                     /*!< 0x00000080 */
#define PWR_PDCRA_PA_PD7                          PWR_PDCRA_PA_PD7_Msk                              
#define PWR_PDCRA_PA_PD8_Pos                      (8U)
#define PWR_PDCRA_PA_PD8_Msk                      (0x1UL<<PWR_PDCRA_PA_PD8_Pos)                     /*!< 0x00000100 */
#define PWR_PDCRA_PA_PD8                          PWR_PDCRA_PA_PD8_Msk                              
#define PWR_PDCRA_PA_PD9_Pos                      (9U)
#define PWR_PDCRA_PA_PD9_Msk                      (0x1UL<<PWR_PDCRA_PA_PD9_Pos)                     /*!< 0x00000200 */
#define PWR_PDCRA_PA_PD9                          PWR_PDCRA_PA_PD9_Msk                              
#define PWR_PDCRA_PA_PD10_Pos                     (10U)
#define PWR_PDCRA_PA_PD10_Msk                     (0x1UL<<PWR_PDCRA_PA_PD10_Pos)                    /*!< 0x00000400 */
#define PWR_PDCRA_PA_PD10                         PWR_PDCRA_PA_PD10_Msk                             
#define PWR_PDCRA_PA_PD11_Pos                     (11U)
#define PWR_PDCRA_PA_PD11_Msk                     (0x1UL<<PWR_PDCRA_PA_PD11_Pos)                    /*!< 0x00000800 */
#define PWR_PDCRA_PA_PD11                         PWR_PDCRA_PA_PD11_Msk                             
#define PWR_PDCRA_PA_PD12_Pos                     (12U)
#define PWR_PDCRA_PA_PD12_Msk                     (0x1UL<<PWR_PDCRA_PA_PD12_Pos)                    /*!< 0x00001000 */
#define PWR_PDCRA_PA_PD12                         PWR_PDCRA_PA_PD12_Msk                             
#define PWR_PDCRA_PA_PD13_Pos                     (13U)
#define PWR_PDCRA_PA_PD13_Msk                     (0x1UL<<PWR_PDCRA_PA_PD13_Pos)                    /*!< 0x00002000 */
#define PWR_PDCRA_PA_PD13                         PWR_PDCRA_PA_PD13_Msk                             
#define PWR_PDCRA_PA_PD14_Pos                     (14U)
#define PWR_PDCRA_PA_PD14_Msk                     (0x1UL<<PWR_PDCRA_PA_PD14_Pos)                    /*!< 0x00004000 */
#define PWR_PDCRA_PA_PD14                         PWR_PDCRA_PA_PD14_Msk                             
#define PWR_PDCRA_PA_PD15_Pos                     (15U)
#define PWR_PDCRA_PA_PD15_Msk                     (0x1UL<<PWR_PDCRA_PA_PD15_Pos)                    /*!< 0x00008000 */
#define PWR_PDCRA_PA_PD15                         PWR_PDCRA_PA_PD15_Msk                             

/********************************* Bit definition for PWR_PUCRB register ********************************************/
#define PWR_PUCRB_PB_PU0_Pos                      (0U)
#define PWR_PUCRB_PB_PU0_Msk                      (0x1UL<<PWR_PUCRB_PB_PU0_Pos)                     /*!< 0x00000001 */
#define PWR_PUCRB_PB_PU0                          PWR_PUCRB_PB_PU0_Msk                              
#define PWR_PUCRB_PB_PU1_Pos                      (1U)
#define PWR_PUCRB_PB_PU1_Msk                      (0x1UL<<PWR_PUCRB_PB_PU1_Pos)                     /*!< 0x00000002 */
#define PWR_PUCRB_PB_PU1                          PWR_PUCRB_PB_PU1_Msk                              
#define PWR_PUCRB_PB_PU2_Pos                      (2U)
#define PWR_PUCRB_PB_PU2_Msk                      (0x1UL<<PWR_PUCRB_PB_PU2_Pos)                     /*!< 0x00000004 */
#define PWR_PUCRB_PB_PU2                          PWR_PUCRB_PB_PU2_Msk                              
#define PWR_PUCRB_PB_PU3_Pos                      (3U)
#define PWR_PUCRB_PB_PU3_Msk                      (0x1UL<<PWR_PUCRB_PB_PU3_Pos)                     /*!< 0x00000008 */
#define PWR_PUCRB_PB_PU3                          PWR_PUCRB_PB_PU3_Msk                              
#define PWR_PUCRB_PB_PU4_Pos                      (4U)
#define PWR_PUCRB_PB_PU4_Msk                      (0x1UL<<PWR_PUCRB_PB_PU4_Pos)                     /*!< 0x00000010 */
#define PWR_PUCRB_PB_PU4                          PWR_PUCRB_PB_PU4_Msk                              
#define PWR_PUCRB_PB_PU5_Pos                      (5U)
#define PWR_PUCRB_PB_PU5_Msk                      (0x1UL<<PWR_PUCRB_PB_PU5_Pos)                     /*!< 0x00000020 */
#define PWR_PUCRB_PB_PU5                          PWR_PUCRB_PB_PU5_Msk                              
#define PWR_PUCRB_PB_PU6_Pos                      (6U)
#define PWR_PUCRB_PB_PU6_Msk                      (0x1UL<<PWR_PUCRB_PB_PU6_Pos)                     /*!< 0x00000040 */
#define PWR_PUCRB_PB_PU6                          PWR_PUCRB_PB_PU6_Msk                              
#define PWR_PUCRB_PB_PU7_Pos                      (7U)
#define PWR_PUCRB_PB_PU7_Msk                      (0x1UL<<PWR_PUCRB_PB_PU7_Pos)                     /*!< 0x00000080 */
#define PWR_PUCRB_PB_PU7                          PWR_PUCRB_PB_PU7_Msk                              
#define PWR_PUCRB_PB_PU8_Pos                      (8U)
#define PWR_PUCRB_PB_PU8_Msk                      (0x1UL<<PWR_PUCRB_PB_PU8_Pos)                     /*!< 0x00000100 */
#define PWR_PUCRB_PB_PU8                          PWR_PUCRB_PB_PU8_Msk                              
#define PWR_PUCRB_PB_PU9_Pos                      (9U)
#define PWR_PUCRB_PB_PU9_Msk                      (0x1UL<<PWR_PUCRB_PB_PU9_Pos)                     /*!< 0x00000200 */
#define PWR_PUCRB_PB_PU9                          PWR_PUCRB_PB_PU9_Msk                              
#define PWR_PUCRB_PB_PU10_Pos                     (10U)
#define PWR_PUCRB_PB_PU10_Msk                     (0x1UL<<PWR_PUCRB_PB_PU10_Pos)                    /*!< 0x00000400 */
#define PWR_PUCRB_PB_PU10                         PWR_PUCRB_PB_PU10_Msk                             
#define PWR_PUCRB_PB_PU11_Pos                     (11U)
#define PWR_PUCRB_PB_PU11_Msk                     (0x1UL<<PWR_PUCRB_PB_PU11_Pos)                    /*!< 0x00000800 */
#define PWR_PUCRB_PB_PU11                         PWR_PUCRB_PB_PU11_Msk                             
#define PWR_PUCRB_PB_PU12_Pos                     (12U)
#define PWR_PUCRB_PB_PU12_Msk                     (0x1UL<<PWR_PUCRB_PB_PU12_Pos)                    /*!< 0x00001000 */
#define PWR_PUCRB_PB_PU12                         PWR_PUCRB_PB_PU12_Msk                             
#define PWR_PUCRB_PB_PU13_Pos                     (13U)
#define PWR_PUCRB_PB_PU13_Msk                     (0x1UL<<PWR_PUCRB_PB_PU13_Pos)                    /*!< 0x00002000 */
#define PWR_PUCRB_PB_PU13                         PWR_PUCRB_PB_PU13_Msk                             
#define PWR_PUCRB_PB_PU14_Pos                     (14U)
#define PWR_PUCRB_PB_PU14_Msk                     (0x1UL<<PWR_PUCRB_PB_PU14_Pos)                    /*!< 0x00004000 */
#define PWR_PUCRB_PB_PU14                         PWR_PUCRB_PB_PU14_Msk                             
#define PWR_PUCRB_PB_PU15_Pos                     (15U)
#define PWR_PUCRB_PB_PU15_Msk                     (0x1UL<<PWR_PUCRB_PB_PU15_Pos)                    /*!< 0x00008000 */
#define PWR_PUCRB_PB_PU15                         PWR_PUCRB_PB_PU15_Msk                             

/********************************* Bit definition for PWR_PDCRB register ********************************************/
#define PWR_PDCRB_PB_PD0_Pos                      (0U)
#define PWR_PDCRB_PB_PD0_Msk                      (0x1UL<<PWR_PDCRB_PB_PD0_Pos)                     /*!< 0x00000001 */
#define PWR_PDCRB_PB_PD0                          PWR_PDCRB_PB_PD0_Msk                              
#define PWR_PDCRB_PB_PD1_Pos                      (1U)
#define PWR_PDCRB_PB_PD1_Msk                      (0x1UL<<PWR_PDCRB_PB_PD1_Pos)                     /*!< 0x00000002 */
#define PWR_PDCRB_PB_PD1                          PWR_PDCRB_PB_PD1_Msk                              
#define PWR_PDCRB_PB_PD2_Pos                      (2U)
#define PWR_PDCRB_PB_PD2_Msk                      (0x1UL<<PWR_PDCRB_PB_PD2_Pos)                     /*!< 0x00000004 */
#define PWR_PDCRB_PB_PD2                          PWR_PDCRB_PB_PD2_Msk                              
#define PWR_PDCRB_PB_PD3_Pos                      (3U)
#define PWR_PDCRB_PB_PD3_Msk                      (0x1UL<<PWR_PDCRB_PB_PD3_Pos)                     /*!< 0x00000008 */
#define PWR_PDCRB_PB_PD3                          PWR_PDCRB_PB_PD3_Msk                              
#define PWR_PDCRB_PB_PD4_Pos                      (4U)
#define PWR_PDCRB_PB_PD4_Msk                      (0x1UL<<PWR_PDCRB_PB_PD4_Pos)                     /*!< 0x00000010 */
#define PWR_PDCRB_PB_PD4                          PWR_PDCRB_PB_PD4_Msk                              
#define PWR_PDCRB_PB_PD5_Pos                      (5U)
#define PWR_PDCRB_PB_PD5_Msk                      (0x1UL<<PWR_PDCRB_PB_PD5_Pos)                     /*!< 0x00000020 */
#define PWR_PDCRB_PB_PD5                          PWR_PDCRB_PB_PD5_Msk                              
#define PWR_PDCRB_PB_PD6_Pos                      (6U)
#define PWR_PDCRB_PB_PD6_Msk                      (0x1UL<<PWR_PDCRB_PB_PD6_Pos)                     /*!< 0x00000040 */
#define PWR_PDCRB_PB_PD6                          PWR_PDCRB_PB_PD6_Msk                              
#define PWR_PDCRB_PB_PD7_Pos                      (7U)
#define PWR_PDCRB_PB_PD7_Msk                      (0x1UL<<PWR_PDCRB_PB_PD7_Pos)                     /*!< 0x00000080 */
#define PWR_PDCRB_PB_PD7                          PWR_PDCRB_PB_PD7_Msk                              
#define PWR_PDCRB_PB_PD8_Pos                      (8U)
#define PWR_PDCRB_PB_PD8_Msk                      (0x1UL<<PWR_PDCRB_PB_PD8_Pos)                     /*!< 0x00000100 */
#define PWR_PDCRB_PB_PD8                          PWR_PDCRB_PB_PD8_Msk                              
#define PWR_PDCRB_PB_PD9_Pos                      (9U)
#define PWR_PDCRB_PB_PD9_Msk                      (0x1UL<<PWR_PDCRB_PB_PD9_Pos)                     /*!< 0x00000200 */
#define PWR_PDCRB_PB_PD9                          PWR_PDCRB_PB_PD9_Msk                              
#define PWR_PDCRB_PB_PD10_Pos                     (10U)
#define PWR_PDCRB_PB_PD10_Msk                     (0x1UL<<PWR_PDCRB_PB_PD10_Pos)                    /*!< 0x00000400 */
#define PWR_PDCRB_PB_PD10                         PWR_PDCRB_PB_PD10_Msk                             
#define PWR_PDCRB_PB_PD11_Pos                     (11U)
#define PWR_PDCRB_PB_PD11_Msk                     (0x1UL<<PWR_PDCRB_PB_PD11_Pos)                    /*!< 0x00000800 */
#define PWR_PDCRB_PB_PD11                         PWR_PDCRB_PB_PD11_Msk                             
#define PWR_PDCRB_PB_PD12_Pos                     (12U)
#define PWR_PDCRB_PB_PD12_Msk                     (0x1UL<<PWR_PDCRB_PB_PD12_Pos)                    /*!< 0x00001000 */
#define PWR_PDCRB_PB_PD12                         PWR_PDCRB_PB_PD12_Msk                             
#define PWR_PDCRB_PB_PD13_Pos                     (13U)
#define PWR_PDCRB_PB_PD13_Msk                     (0x1UL<<PWR_PDCRB_PB_PD13_Pos)                    /*!< 0x00002000 */
#define PWR_PDCRB_PB_PD13                         PWR_PDCRB_PB_PD13_Msk                             
#define PWR_PDCRB_PB_PD14_Pos                     (14U)
#define PWR_PDCRB_PB_PD14_Msk                     (0x1UL<<PWR_PDCRB_PB_PD14_Pos)                    /*!< 0x00004000 */
#define PWR_PDCRB_PB_PD14                         PWR_PDCRB_PB_PD14_Msk                             
#define PWR_PDCRB_PB_PD15_Pos                     (15U)
#define PWR_PDCRB_PB_PD15_Msk                     (0x1UL<<PWR_PDCRB_PB_PD15_Pos)                    /*!< 0x00008000 */
#define PWR_PDCRB_PB_PD15                         PWR_PDCRB_PB_PD15_Msk                             

/********************************* Bit definition for PWR_PUCRC register ********************************************/
#define PWR_PUCRC_PC_PU0_Pos                      (0U)
#define PWR_PUCRC_PC_PU0_Msk                      (0x1UL<<PWR_PUCRC_PC_PU0_Pos)                     /*!< 0x00000001 */
#define PWR_PUCRC_PC_PU0                          PWR_PUCRC_PC_PU0_Msk                              
#define PWR_PUCRC_PC_PU1_Pos                      (1U)
#define PWR_PUCRC_PC_PU1_Msk                      (0x1UL<<PWR_PUCRC_PC_PU1_Pos)                     /*!< 0x00000002 */
#define PWR_PUCRC_PC_PU1                          PWR_PUCRC_PC_PU1_Msk                              
#define PWR_PUCRC_PC_PU2_Pos                      (2U)
#define PWR_PUCRC_PC_PU2_Msk                      (0x1UL<<PWR_PUCRC_PC_PU2_Pos)                     /*!< 0x00000004 */
#define PWR_PUCRC_PC_PU2                          PWR_PUCRC_PC_PU2_Msk                              
#define PWR_PUCRC_PC_PU3_Pos                      (3U)
#define PWR_PUCRC_PC_PU3_Msk                      (0x1UL<<PWR_PUCRC_PC_PU3_Pos)                     /*!< 0x00000008 */
#define PWR_PUCRC_PC_PU3                          PWR_PUCRC_PC_PU3_Msk                              
#define PWR_PUCRC_PC_PU4_Pos                      (4U)
#define PWR_PUCRC_PC_PU4_Msk                      (0x1UL<<PWR_PUCRC_PC_PU4_Pos)                     /*!< 0x00000010 */
#define PWR_PUCRC_PC_PU4                          PWR_PUCRC_PC_PU4_Msk                              
#define PWR_PUCRC_PC_PU5_Pos                      (5U)
#define PWR_PUCRC_PC_PU5_Msk                      (0x1UL<<PWR_PUCRC_PC_PU5_Pos)                     /*!< 0x00000020 */
#define PWR_PUCRC_PC_PU5                          PWR_PUCRC_PC_PU5_Msk                              
#define PWR_PUCRC_PC_PU6_Pos                      (6U)
#define PWR_PUCRC_PC_PU6_Msk                      (0x1UL<<PWR_PUCRC_PC_PU6_Pos)                     /*!< 0x00000040 */
#define PWR_PUCRC_PC_PU6                          PWR_PUCRC_PC_PU6_Msk                              
#define PWR_PUCRC_PC_PU7_Pos                      (7U)
#define PWR_PUCRC_PC_PU7_Msk                      (0x1UL<<PWR_PUCRC_PC_PU7_Pos)                     /*!< 0x00000080 */
#define PWR_PUCRC_PC_PU7                          PWR_PUCRC_PC_PU7_Msk                              
#define PWR_PUCRC_PC_PU8_Pos                      (8U)
#define PWR_PUCRC_PC_PU8_Msk                      (0x1UL<<PWR_PUCRC_PC_PU8_Pos)                     /*!< 0x00000100 */
#define PWR_PUCRC_PC_PU8                          PWR_PUCRC_PC_PU8_Msk                              
#define PWR_PUCRC_PC_PU9_Pos                      (9U)
#define PWR_PUCRC_PC_PU9_Msk                      (0x1UL<<PWR_PUCRC_PC_PU9_Pos)                     /*!< 0x00000200 */
#define PWR_PUCRC_PC_PU9                          PWR_PUCRC_PC_PU9_Msk                              
#define PWR_PUCRC_PC_PU10_Pos                     (10U)
#define PWR_PUCRC_PC_PU10_Msk                     (0x1UL<<PWR_PUCRC_PC_PU10_Pos)                    /*!< 0x00000400 */
#define PWR_PUCRC_PC_PU10                         PWR_PUCRC_PC_PU10_Msk                             
#define PWR_PUCRC_PC_PU11_Pos                     (11U)
#define PWR_PUCRC_PC_PU11_Msk                     (0x1UL<<PWR_PUCRC_PC_PU11_Pos)                    /*!< 0x00000800 */
#define PWR_PUCRC_PC_PU11                         PWR_PUCRC_PC_PU11_Msk                             
#define PWR_PUCRC_PC_PU12_Pos                     (12U)
#define PWR_PUCRC_PC_PU12_Msk                     (0x1UL<<PWR_PUCRC_PC_PU12_Pos)                    /*!< 0x00001000 */
#define PWR_PUCRC_PC_PU12                         PWR_PUCRC_PC_PU12_Msk                             
#define PWR_PUCRC_PC_PU13_Pos                     (13U)
#define PWR_PUCRC_PC_PU13_Msk                     (0x1UL<<PWR_PUCRC_PC_PU13_Pos)                    /*!< 0x00002000 */
#define PWR_PUCRC_PC_PU13                         PWR_PUCRC_PC_PU13_Msk                             
#define PWR_PUCRC_PC_PU14_Pos                     (14U)
#define PWR_PUCRC_PC_PU14_Msk                     (0x1UL<<PWR_PUCRC_PC_PU14_Pos)                    /*!< 0x00004000 */
#define PWR_PUCRC_PC_PU14                         PWR_PUCRC_PC_PU14_Msk                             
#define PWR_PUCRC_PC_PU15_Pos                     (15U)
#define PWR_PUCRC_PC_PU15_Msk                     (0x1UL<<PWR_PUCRC_PC_PU15_Pos)                    /*!< 0x00008000 */
#define PWR_PUCRC_PC_PU15                         PWR_PUCRC_PC_PU15_Msk                             

/********************************* Bit definition for PWR_PDCRC register ********************************************/
#define PWR_PDCRC_PC_PD0_Pos                      (0U)
#define PWR_PDCRC_PC_PD0_Msk                      (0x1UL<<PWR_PDCRC_PC_PD0_Pos)                     /*!< 0x00000001 */
#define PWR_PDCRC_PC_PD0                          PWR_PDCRC_PC_PD0_Msk                              
#define PWR_PDCRC_PC_PD1_Pos                      (1U)
#define PWR_PDCRC_PC_PD1_Msk                      (0x1UL<<PWR_PDCRC_PC_PD1_Pos)                     /*!< 0x00000002 */
#define PWR_PDCRC_PC_PD1                          PWR_PDCRC_PC_PD1_Msk                              
#define PWR_PDCRC_PC_PD2_Pos                      (2U)
#define PWR_PDCRC_PC_PD2_Msk                      (0x1UL<<PWR_PDCRC_PC_PD2_Pos)                     /*!< 0x00000004 */
#define PWR_PDCRC_PC_PD2                          PWR_PDCRC_PC_PD2_Msk                              
#define PWR_PDCRC_PC_PD3_Pos                      (3U)
#define PWR_PDCRC_PC_PD3_Msk                      (0x1UL<<PWR_PDCRC_PC_PD3_Pos)                     /*!< 0x00000008 */
#define PWR_PDCRC_PC_PD3                          PWR_PDCRC_PC_PD3_Msk                              
#define PWR_PDCRC_PC_PD4_Pos                      (4U)
#define PWR_PDCRC_PC_PD4_Msk                      (0x1UL<<PWR_PDCRC_PC_PD4_Pos)                     /*!< 0x00000010 */
#define PWR_PDCRC_PC_PD4                          PWR_PDCRC_PC_PD4_Msk                              
#define PWR_PDCRC_PC_PD5_Pos                      (5U)
#define PWR_PDCRC_PC_PD5_Msk                      (0x1UL<<PWR_PDCRC_PC_PD5_Pos)                     /*!< 0x00000020 */
#define PWR_PDCRC_PC_PD5                          PWR_PDCRC_PC_PD5_Msk                              
#define PWR_PDCRC_PC_PD6_Pos                      (6U)
#define PWR_PDCRC_PC_PD6_Msk                      (0x1UL<<PWR_PDCRC_PC_PD6_Pos)                     /*!< 0x00000040 */
#define PWR_PDCRC_PC_PD6                          PWR_PDCRC_PC_PD6_Msk                              
#define PWR_PDCRC_PC_PD7_Pos                      (7U)
#define PWR_PDCRC_PC_PD7_Msk                      (0x1UL<<PWR_PDCRC_PC_PD7_Pos)                     /*!< 0x00000080 */
#define PWR_PDCRC_PC_PD7                          PWR_PDCRC_PC_PD7_Msk                              
#define PWR_PDCRC_PC_PD8_Pos                      (8U)
#define PWR_PDCRC_PC_PD8_Msk                      (0x1UL<<PWR_PDCRC_PC_PD8_Pos)                     /*!< 0x00000100 */
#define PWR_PDCRC_PC_PD8                          PWR_PDCRC_PC_PD8_Msk                              
#define PWR_PDCRC_PC_PD9_Pos                      (9U)
#define PWR_PDCRC_PC_PD9_Msk                      (0x1UL<<PWR_PDCRC_PC_PD9_Pos)                     /*!< 0x00000200 */
#define PWR_PDCRC_PC_PD9                          PWR_PDCRC_PC_PD9_Msk                              
#define PWR_PDCRC_PC_PD10_Pos                     (10U)
#define PWR_PDCRC_PC_PD10_Msk                     (0x1UL<<PWR_PDCRC_PC_PD10_Pos)                    /*!< 0x00000400 */
#define PWR_PDCRC_PC_PD10                         PWR_PDCRC_PC_PD10_Msk                             
#define PWR_PDCRC_PC_PD11_Pos                     (11U)
#define PWR_PDCRC_PC_PD11_Msk                     (0x1UL<<PWR_PDCRC_PC_PD11_Pos)                    /*!< 0x00000800 */
#define PWR_PDCRC_PC_PD11                         PWR_PDCRC_PC_PD11_Msk                             
#define PWR_PDCRC_PC_PD12_Pos                     (12U)
#define PWR_PDCRC_PC_PD12_Msk                     (0x1UL<<PWR_PDCRC_PC_PD12_Pos)                    /*!< 0x00001000 */
#define PWR_PDCRC_PC_PD12                         PWR_PDCRC_PC_PD12_Msk                             
#define PWR_PDCRC_PC_PD13_Pos                     (13U)
#define PWR_PDCRC_PC_PD13_Msk                     (0x1UL<<PWR_PDCRC_PC_PD13_Pos)                    /*!< 0x00002000 */
#define PWR_PDCRC_PC_PD13                         PWR_PDCRC_PC_PD13_Msk                             
#define PWR_PDCRC_PC_PD14_Pos                     (14U)
#define PWR_PDCRC_PC_PD14_Msk                     (0x1UL<<PWR_PDCRC_PC_PD14_Pos)                    /*!< 0x00004000 */
#define PWR_PDCRC_PC_PD14                         PWR_PDCRC_PC_PD14_Msk                             
#define PWR_PDCRC_PC_PD15_Pos                     (15U)
#define PWR_PDCRC_PC_PD15_Msk                     (0x1UL<<PWR_PDCRC_PC_PD15_Pos)                    /*!< 0x00008000 */
#define PWR_PDCRC_PC_PD15                         PWR_PDCRC_PC_PD15_Msk                             

/********************************* Bit definition for PWR_PUCRD register ********************************************/
#define PWR_PUCRD_PD_PU0_Pos                      (0U)
#define PWR_PUCRD_PD_PU0_Msk                      (0x1UL<<PWR_PUCRD_PD_PU0_Pos)                     /*!< 0x00000001 */
#define PWR_PUCRD_PD_PU0                          PWR_PUCRD_PD_PU0_Msk                              
#define PWR_PUCRD_PD_PU1_Pos                      (1U)
#define PWR_PUCRD_PD_PU1_Msk                      (0x1UL<<PWR_PUCRD_PD_PU1_Pos)                     /*!< 0x00000002 */
#define PWR_PUCRD_PD_PU1                          PWR_PUCRD_PD_PU1_Msk                              
#define PWR_PUCRD_PD_PU2_Pos                      (2U)
#define PWR_PUCRD_PD_PU2_Msk                      (0x1UL<<PWR_PUCRD_PD_PU2_Pos)                     /*!< 0x00000004 */
#define PWR_PUCRD_PD_PU2                          PWR_PUCRD_PD_PU2_Msk                              
#define PWR_PUCRD_PD_PU3_Pos                      (3U)
#define PWR_PUCRD_PD_PU3_Msk                      (0x1UL<<PWR_PUCRD_PD_PU3_Pos)                     /*!< 0x00000008 */
#define PWR_PUCRD_PD_PU3                          PWR_PUCRD_PD_PU3_Msk                              
#define PWR_PUCRD_PD_PU4_Pos                      (4U)
#define PWR_PUCRD_PD_PU4_Msk                      (0x1UL<<PWR_PUCRD_PD_PU4_Pos)                     /*!< 0x00000010 */
#define PWR_PUCRD_PD_PU4                          PWR_PUCRD_PD_PU4_Msk                              
#define PWR_PUCRD_PD_PU5_Pos                      (5U)
#define PWR_PUCRD_PD_PU5_Msk                      (0x1UL<<PWR_PUCRD_PD_PU5_Pos)                     /*!< 0x00000020 */
#define PWR_PUCRD_PD_PU5                          PWR_PUCRD_PD_PU5_Msk                              
#define PWR_PUCRD_PD_PU6_Pos                      (6U)
#define PWR_PUCRD_PD_PU6_Msk                      (0x1UL<<PWR_PUCRD_PD_PU6_Pos)                     /*!< 0x00000040 */
#define PWR_PUCRD_PD_PU6                          PWR_PUCRD_PD_PU6_Msk                              
#define PWR_PUCRD_PD_PU7_Pos                      (7U)
#define PWR_PUCRD_PD_PU7_Msk                      (0x1UL<<PWR_PUCRD_PD_PU7_Pos)                     /*!< 0x00000080 */
#define PWR_PUCRD_PD_PU7                          PWR_PUCRD_PD_PU7_Msk                              
#define PWR_PUCRD_PD_PU8_Pos                      (8U)
#define PWR_PUCRD_PD_PU8_Msk                      (0x1UL<<PWR_PUCRD_PD_PU8_Pos)                     /*!< 0x00000100 */
#define PWR_PUCRD_PD_PU8                          PWR_PUCRD_PD_PU8_Msk                              
#define PWR_PUCRD_PD_PU9_Pos                      (9U)
#define PWR_PUCRD_PD_PU9_Msk                      (0x1UL<<PWR_PUCRD_PD_PU9_Pos)                     /*!< 0x00000200 */
#define PWR_PUCRD_PD_PU9                          PWR_PUCRD_PD_PU9_Msk                              
#define PWR_PUCRD_PD_PU10_Pos                     (10U)
#define PWR_PUCRD_PD_PU10_Msk                     (0x1UL<<PWR_PUCRD_PD_PU10_Pos)                    /*!< 0x00000400 */
#define PWR_PUCRD_PD_PU10                         PWR_PUCRD_PD_PU10_Msk                             
#define PWR_PUCRD_PD_PU11_Pos                     (11U)
#define PWR_PUCRD_PD_PU11_Msk                     (0x1UL<<PWR_PUCRD_PD_PU11_Pos)                    /*!< 0x00000800 */
#define PWR_PUCRD_PD_PU11                         PWR_PUCRD_PD_PU11_Msk                             
#define PWR_PUCRD_PD_PU12_Pos                     (12U)
#define PWR_PUCRD_PD_PU12_Msk                     (0x1UL<<PWR_PUCRD_PD_PU12_Pos)                    /*!< 0x00001000 */
#define PWR_PUCRD_PD_PU12                         PWR_PUCRD_PD_PU12_Msk                             
#define PWR_PUCRD_PD_PU13_Pos                     (13U)
#define PWR_PUCRD_PD_PU13_Msk                     (0x1UL<<PWR_PUCRD_PD_PU13_Pos)                    /*!< 0x00002000 */
#define PWR_PUCRD_PD_PU13                         PWR_PUCRD_PD_PU13_Msk                             
#define PWR_PUCRD_PD_PU14_Pos                     (14U)
#define PWR_PUCRD_PD_PU14_Msk                     (0x1UL<<PWR_PUCRD_PD_PU14_Pos)                    /*!< 0x00004000 */
#define PWR_PUCRD_PD_PU14                         PWR_PUCRD_PD_PU14_Msk                             
#define PWR_PUCRD_PD_PU15_Pos                     (15U)
#define PWR_PUCRD_PD_PU15_Msk                     (0x1UL<<PWR_PUCRD_PD_PU15_Pos)                    /*!< 0x00008000 */
#define PWR_PUCRD_PD_PU15                         PWR_PUCRD_PD_PU15_Msk                             

/********************************* Bit definition for PWR_PDCRD register ********************************************/
#define PWR_PDCRD_PD_PD0_Pos                      (0U)
#define PWR_PDCRD_PD_PD0_Msk                      (0x1UL<<PWR_PDCRD_PD_PD0_Pos)                     /*!< 0x00000001 */
#define PWR_PDCRD_PD_PD0                          PWR_PDCRD_PD_PD0_Msk                              
#define PWR_PDCRD_PD_PD1_Pos                      (1U)
#define PWR_PDCRD_PD_PD1_Msk                      (0x1UL<<PWR_PDCRD_PD_PD1_Pos)                     /*!< 0x00000002 */
#define PWR_PDCRD_PD_PD1                          PWR_PDCRD_PD_PD1_Msk                              
#define PWR_PDCRD_PD_PD2_Pos                      (2U)
#define PWR_PDCRD_PD_PD2_Msk                      (0x1UL<<PWR_PDCRD_PD_PD2_Pos)                     /*!< 0x00000004 */
#define PWR_PDCRD_PD_PD2                          PWR_PDCRD_PD_PD2_Msk                              
#define PWR_PDCRD_PD_PD3_Pos                      (3U)
#define PWR_PDCRD_PD_PD3_Msk                      (0x1UL<<PWR_PDCRD_PD_PD3_Pos)                     /*!< 0x00000008 */
#define PWR_PDCRD_PD_PD3                          PWR_PDCRD_PD_PD3_Msk                              
#define PWR_PDCRD_PD_PD4_Pos                      (4U)
#define PWR_PDCRD_PD_PD4_Msk                      (0x1UL<<PWR_PDCRD_PD_PD4_Pos)                     /*!< 0x00000010 */
#define PWR_PDCRD_PD_PD4                          PWR_PDCRD_PD_PD4_Msk                              
#define PWR_PDCRD_PD_PD5_Pos                      (5U)
#define PWR_PDCRD_PD_PD5_Msk                      (0x1UL<<PWR_PDCRD_PD_PD5_Pos)                     /*!< 0x00000020 */
#define PWR_PDCRD_PD_PD5                          PWR_PDCRD_PD_PD5_Msk                              
#define PWR_PDCRD_PD_PD6_Pos                      (6U)
#define PWR_PDCRD_PD_PD6_Msk                      (0x1UL<<PWR_PDCRD_PD_PD6_Pos)                     /*!< 0x00000040 */
#define PWR_PDCRD_PD_PD6                          PWR_PDCRD_PD_PD6_Msk                              
#define PWR_PDCRD_PD_PD7_Pos                      (7U)
#define PWR_PDCRD_PD_PD7_Msk                      (0x1UL<<PWR_PDCRD_PD_PD7_Pos)                     /*!< 0x00000080 */
#define PWR_PDCRD_PD_PD7                          PWR_PDCRD_PD_PD7_Msk                              
#define PWR_PDCRD_PD_PD8_Pos                      (8U)
#define PWR_PDCRD_PD_PD8_Msk                      (0x1UL<<PWR_PDCRD_PD_PD8_Pos)                     /*!< 0x00000100 */
#define PWR_PDCRD_PD_PD8                          PWR_PDCRD_PD_PD8_Msk                              
#define PWR_PDCRD_PD_PD9_Pos                      (9U)
#define PWR_PDCRD_PD_PD9_Msk                      (0x1UL<<PWR_PDCRD_PD_PD9_Pos)                     /*!< 0x00000200 */
#define PWR_PDCRD_PD_PD9                          PWR_PDCRD_PD_PD9_Msk                              
#define PWR_PDCRD_PD_PD10_Pos                     (10U)
#define PWR_PDCRD_PD_PD10_Msk                     (0x1UL<<PWR_PDCRD_PD_PD10_Pos)                    /*!< 0x00000400 */
#define PWR_PDCRD_PD_PD10                         PWR_PDCRD_PD_PD10_Msk                             
#define PWR_PDCRD_PD_PD11_Pos                     (11U)
#define PWR_PDCRD_PD_PD11_Msk                     (0x1UL<<PWR_PDCRD_PD_PD11_Pos)                    /*!< 0x00000800 */
#define PWR_PDCRD_PD_PD11                         PWR_PDCRD_PD_PD11_Msk                             
#define PWR_PDCRD_PD_PD12_Pos                     (12U)
#define PWR_PDCRD_PD_PD12_Msk                     (0x1UL<<PWR_PDCRD_PD_PD12_Pos)                    /*!< 0x00001000 */
#define PWR_PDCRD_PD_PD12                         PWR_PDCRD_PD_PD12_Msk                             
#define PWR_PDCRD_PD_PD13_Pos                     (13U)
#define PWR_PDCRD_PD_PD13_Msk                     (0x1UL<<PWR_PDCRD_PD_PD13_Pos)                    /*!< 0x00002000 */
#define PWR_PDCRD_PD_PD13                         PWR_PDCRD_PD_PD13_Msk                             
#define PWR_PDCRD_PD_PD14_Pos                     (14U)
#define PWR_PDCRD_PD_PD14_Msk                     (0x1UL<<PWR_PDCRD_PD_PD14_Pos)                    /*!< 0x00004000 */
#define PWR_PDCRD_PD_PD14                         PWR_PDCRD_PD_PD14_Msk                             
#define PWR_PDCRD_PD_PD15_Pos                     (15U)
#define PWR_PDCRD_PD_PD15_Msk                     (0x1UL<<PWR_PDCRD_PD_PD15_Pos)                    /*!< 0x00008000 */
#define PWR_PDCRD_PD_PD15                         PWR_PDCRD_PD_PD15_Msk                             
                         

/********************************************************************************************************************/
/********************************* RCC ******************************************************************************/
/********************************************************************************************************************/
#define RCC_HSE_SUPPORT
#define RCC_LSE_SUPPORT
#define RCC_PLL_SUPPORT

/********************************* Bit definition for RCC_CR register ***********************************************/
#define RCC_CR_MSIDIV_Pos                         (0U)
#define RCC_CR_MSIDIV_Msk                         (0x7UL<<RCC_CR_MSIDIV_Pos)                        /*!< 0x00000007 */
#define RCC_CR_MSIDIV                             RCC_CR_MSIDIV_Msk
#define RCC_CR_MSIDIV_0                           (0x1UL<<RCC_CR_MSIDIV_Pos)                        /*!< 0x00000001 */
#define RCC_CR_MSIDIV_1                           (0x2UL<<RCC_CR_MSIDIV_Pos)                        /*!< 0x00000002 */
#define RCC_CR_MSIDIV_2                           (0x4UL<<RCC_CR_MSIDIV_Pos)                        /*!< 0x00000004 */
#define RCC_CR_HSIKERON_Pos                       (6U)
#define RCC_CR_HSIKERON_Msk                       (0x1UL<<RCC_CR_HSIKERON_Pos)                      /*!< 0x00000040 */
#define RCC_CR_HSIKERON                           RCC_CR_HSIKERON_Msk                               
#define RCC_CR_MSION_Pos                          (7U)
#define RCC_CR_MSION_Msk                          (0x1UL<<RCC_CR_MSION_Pos)                         /*!< 0x00000080 */
#define RCC_CR_MSION                              RCC_CR_MSION_Msk                                  
#define RCC_CR_HSION_Pos                          (8U)
#define RCC_CR_HSION_Msk                          (0x1UL<<RCC_CR_HSION_Pos)                         /*!< 0x00000100 */
#define RCC_CR_HSION                              RCC_CR_HSION_Msk                                  
#define RCC_CR_MSIRDY_Pos                         (9U)
#define RCC_CR_MSIRDY_Msk                         (0x1UL<<RCC_CR_MSIRDY_Pos)                        /*!< 0x00000200 */
#define RCC_CR_MSIRDY                             RCC_CR_MSIRDY_Msk                                 
#define RCC_CR_HSIRDY_Pos                         (10U)
#define RCC_CR_HSIRDY_Msk                         (0x1UL<<RCC_CR_HSIRDY_Pos)                        /*!< 0x00000400 */
#define RCC_CR_HSIRDY                             RCC_CR_HSIRDY_Msk                                 
#define RCC_CR_HSIDIV_Pos                         (11U)
#define RCC_CR_HSIDIV_Msk                         (0x7UL<<RCC_CR_HSIDIV_Pos)                        /*!< 0x00003800 */
#define RCC_CR_HSIDIV                             RCC_CR_HSIDIV_Msk
#define RCC_CR_HSIDIV_0                           (0x1UL<<RCC_CR_HSIDIV_Pos)                        /*!< 0x00000800 */
#define RCC_CR_HSIDIV_1                           (0x2UL<<RCC_CR_HSIDIV_Pos)                        /*!< 0x00001000 */
#define RCC_CR_HSIDIV_2                           (0x4UL<<RCC_CR_HSIDIV_Pos)                        /*!< 0x00002000 */
#define RCC_CR_HSEON_Pos                          (16U)
#define RCC_CR_HSEON_Msk                          (0x1UL<<RCC_CR_HSEON_Pos)                         /*!< 0x00010000 */
#define RCC_CR_HSEON                              RCC_CR_HSEON_Msk                                  
#define RCC_CR_HSERDY_Pos                         (17U)
#define RCC_CR_HSERDY_Msk                         (0x1UL<<RCC_CR_HSERDY_Pos)                        /*!< 0x00020000 */
#define RCC_CR_HSERDY                             RCC_CR_HSERDY_Msk                                 
#define RCC_CR_HSEBYP_Pos                         (18U)
#define RCC_CR_HSEBYP_Msk                         (0x1UL<<RCC_CR_HSEBYP_Pos)                        /*!< 0x00040000 */
#define RCC_CR_HSEBYP                             RCC_CR_HSEBYP_Msk                                 
#define RCC_CR_HSE_CSSON_Pos                      (19U)
#define RCC_CR_HSE_CSSON_Msk                      (0x1UL<<RCC_CR_HSE_CSSON_Pos)                     /*!< 0x00080000 */
#define RCC_CR_HSE_CSSON                          RCC_CR_HSE_CSSON_Msk                              
#define RCC_CR_PLLON_Pos                          (24U)
#define RCC_CR_PLLON_Msk                          (0x1UL<<RCC_CR_PLLON_Pos)                         /*!< 0x01000000 */
#define RCC_CR_PLLON                              RCC_CR_PLLON_Msk                                  
#define RCC_CR_PLLRDY_Pos                         (25U)
#define RCC_CR_PLLRDY_Msk                         (0x1UL<<RCC_CR_PLLRDY_Pos)                        /*!< 0x02000000 */
#define RCC_CR_PLLRDY                             RCC_CR_PLLRDY_Msk                                 

/********************************* Bit definition for RCC_ICSCR register ********************************************/
#define RCC_ICSCR_HSI_TRIMCR_Pos                  (0U)
#define RCC_ICSCR_HSI_TRIMCR_Msk                  (0x1FFFUL<<RCC_ICSCR_HSI_TRIMCR_Pos)              /*!< 0x00001FFF */
#define RCC_ICSCR_HSI_TRIMCR                      RCC_ICSCR_HSI_TRIMCR_Msk
#define RCC_ICSCR_HSI_FS_OPCR_Pos                 (13U)
#define RCC_ICSCR_HSI_FS_OPCR_Msk                 (0x7UL<<RCC_ICSCR_HSI_FS_OPCR_Pos)                  /*!< 0x0000E000 */
#define RCC_ICSCR_HSI_FS_OPCR                     RCC_ICSCR_HSI_FS_OPCR_Msk
#define RCC_ICSCR_HSI_FS_OPCR_0                   (0x1UL<<RCC_ICSCR_HSI_FS_OPCR_Pos)                  /*!< 0x00002000 */
#define RCC_ICSCR_HSI_FS_OPCR_1                   (0x2UL<<RCC_ICSCR_HSI_FS_OPCR_Pos)                  /*!< 0x00004000 */
#define RCC_ICSCR_HSI_FS_OPCR_2                   (0x4UL<<RCC_ICSCR_HSI_FS_OPCR_Pos)                  /*!< 0x00008000 */

/********************************* Bit definition for RCC_CFGR register *********************************************/
#define RCC_CFGR_SW_Pos                           (0U)
#define RCC_CFGR_SW_Msk                           (0x7UL<<RCC_CFGR_SW_Pos)                          /*!< 0x00000007 */
#define RCC_CFGR_SW                               RCC_CFGR_SW_Msk
#define RCC_CFGR_SW_0                             (0x1UL<<RCC_CFGR_SW_Pos)                          /*!< 0x00000001 */
#define RCC_CFGR_SW_1                             (0x2UL<<RCC_CFGR_SW_Pos)                          /*!< 0x00000002 */
#define RCC_CFGR_SW_2                             (0x4UL<<RCC_CFGR_SW_Pos)                          /*!< 0x00000004 */
#define RCC_CFGR_SWS_Pos                          (3U)
#define RCC_CFGR_SWS_Msk                          (0x7UL<<RCC_CFGR_SWS_Pos)                         /*!< 0x00000038 */
#define RCC_CFGR_SWS                              RCC_CFGR_SWS_Msk
#define RCC_CFGR_SWS_0                            (0x1UL<<RCC_CFGR_SWS_Pos)                         /*!< 0x00000008 */
#define RCC_CFGR_SWS_1                            (0x2UL<<RCC_CFGR_SWS_Pos)                         /*!< 0x00000010 */
#define RCC_CFGR_SWS_2                            (0x4UL<<RCC_CFGR_SWS_Pos)                         /*!< 0x00000020 */
#define RCC_CFGR_SW_HSISYS                        (0x00000000U)                                     /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                           (0x00000001U)                                     /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                           (0x00000002U)
#define RCC_CFGR_SW_LSI                           (0x00000003U)
#define RCC_CFGR_SW_LSE                           (0x00000004U)
#define RCC_CFGR_SW_MSISYS                        (0x00000005U)

#define RCC_CFGR_SWS_HSISYS                       (0x00000000U)                                     /*!< HSISYS used as system clock */
#define RCC_CFGR_SWS_HSE                          (0x00000008U)                                     /*!< HSE used as system clock */
#define RCC_CFGR_SWS_PLL                          (0x00000010U)                                     /*!< PLL used as system clock */
#define RCC_CFGR_SWS_LSI                          (0x00000018U)                                     /*!< LSI used as system clock */
#define RCC_CFGR_SWS_LSE                          (0x00000020U)                                     /*!< LSE used as system clock */
#define RCC_CFGR_SWS_MSISYS                       (0x00000028U)                                     /*!< MSISYS used as system clock */

#define RCC_CFGR_HPRE_Pos                         (8U)
#define RCC_CFGR_HPRE_Msk                         (0xFUL<<RCC_CFGR_HPRE_Pos)                        /*!< 0x00000F00 */
#define RCC_CFGR_HPRE                             RCC_CFGR_HPRE_Msk
#define RCC_CFGR_HPRE_0                           (0x1UL<<RCC_CFGR_HPRE_Pos)                        /*!< 0x00000100 */
#define RCC_CFGR_HPRE_1                           (0x2UL<<RCC_CFGR_HPRE_Pos)                        /*!< 0x00000200 */
#define RCC_CFGR_HPRE_2                           (0x4UL<<RCC_CFGR_HPRE_Pos)                        /*!< 0x00000400 */
#define RCC_CFGR_HPRE_3                           (0x8UL<<RCC_CFGR_HPRE_Pos)                        /*!< 0x00000800 */
#define RCC_CFGR_PPRE_Pos                         (12U)
#define RCC_CFGR_PPRE_Msk                         (0x7UL<<RCC_CFGR_PPRE_Pos)                        /*!< 0x00007000 */
#define RCC_CFGR_PPRE                             RCC_CFGR_PPRE_Msk
#define RCC_CFGR_PPRE_0                           (0x1UL<<RCC_CFGR_PPRE_Pos)                        /*!< 0x00001000 */
#define RCC_CFGR_PPRE_1                           (0x2UL<<RCC_CFGR_PPRE_Pos)                        /*!< 0x00002000 */
#define RCC_CFGR_PPRE_2                           (0x4UL<<RCC_CFGR_PPRE_Pos)                        /*!< 0x00004000 */
#define RCC_CFGR_MCOSEL_Pos                       (24U)
#define RCC_CFGR_MCOSEL_Msk                       (0xFUL<<RCC_CFGR_MCOSEL_Pos)                      /*!< 0x0F000000 */
#define RCC_CFGR_MCOSEL                           RCC_CFGR_MCOSEL_Msk
#define RCC_CFGR_MCOSEL_0                         (0x1UL<<RCC_CFGR_MCOSEL_Pos)                      /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_1                         (0x2UL<<RCC_CFGR_MCOSEL_Pos)                      /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_2                         (0x4UL<<RCC_CFGR_MCOSEL_Pos)                      /*!< 0x04000000 */
#define RCC_CFGR_MCOSEL_3                         (0x8UL<<RCC_CFGR_MCOSEL_Pos)                      /*!< 0x08000000 */
#define RCC_CFGR_MCOPRE_Pos                       (28U)
#define RCC_CFGR_MCOPRE_Msk                       (0xFUL<<RCC_CFGR_MCOPRE_Pos)                      /*!< 0xF0000000 */
#define RCC_CFGR_MCOPRE                           RCC_CFGR_MCOPRE_Msk
#define RCC_CFGR_MCOPRE_0                         (0x1UL<<RCC_CFGR_MCOPRE_Pos)                      /*!< 0x10000000 */
#define RCC_CFGR_MCOPRE_1                         (0x2UL<<RCC_CFGR_MCOPRE_Pos)                      /*!< 0x20000000 */
#define RCC_CFGR_MCOPRE_2                         (0x4UL<<RCC_CFGR_MCOPRE_Pos)                      /*!< 0x40000000 */
#define RCC_CFGR_MCOPRE_3                         (0x8UL<<RCC_CFGR_MCOPRE_Pos)                      /*!< 0x80000000 */

/********************************* Bit definition for RCC_PLLCFGR register ******************************************/
#define RCC_PLLCFGR_PLLSRC_Pos                    (0U)
#define RCC_PLLCFGR_PLLSRC_Msk                    (0x1UL<<RCC_PLLCFGR_PLLSRC_Pos)                   /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLSRC                        RCC_PLLCFGR_PLLSRC_Msk                            
#define RCC_PLLCFGR_PLLMUL_Pos                    (2U)
#define RCC_PLLCFGR_PLLMUL_Msk                    (0x1FUL<<RCC_PLLCFGR_PLLMUL_Pos)                  /*!< 0x0000007C */
#define RCC_PLLCFGR_PLLMUL                        RCC_PLLCFGR_PLLMUL_Msk
#define RCC_PLLCFGR_PLLMUL_0                      (0x1UL<<RCC_PLLCFGR_PLLMUL_Pos)                   /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLMUL_1                      (0x2UL<<RCC_PLLCFGR_PLLMUL_Pos)                   /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLMUL_2                      (0x4UL<<RCC_PLLCFGR_PLLMUL_Pos)                   /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLMUL_3                      (0x8UL<<RCC_PLLCFGR_PLLMUL_Pos)                   /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLMUL_4                      (0x10UL<<RCC_PLLCFGR_PLLMUL_Pos)                  /*!< 0x00000040 */

/********************************* Bit definition for RCC_ECSCR register ********************************************/
#define RCC_ECSCR_HSE_DRV_Pos                     (0U)
#define RCC_ECSCR_HSE_DRV_Msk                     (0x3UL<<RCC_ECSCR_HSE_DRV_Pos)                    /*!< 0x00000003 */
#define RCC_ECSCR_HSE_DRV                         RCC_ECSCR_HSE_DRV_Msk
#define RCC_ECSCR_HSE_DRV_0                       (0x1UL<<RCC_ECSCR_HSE_DRV_Pos)                    /*!< 0x00000001 */
#define RCC_ECSCR_HSE_DRV_1                       (0x2UL<<RCC_ECSCR_HSE_DRV_Pos)                    /*!< 0x00000002 */
#define RCC_ECSCR_HSE_RDYSEL_Pos                  (2U)
#define RCC_ECSCR_HSE_RDYSEL_Msk                  (0x3UL<<RCC_ECSCR_HSE_RDYSEL_Pos)                 /*!< 0x0000000C */
#define RCC_ECSCR_HSE_RDYSEL                      RCC_ECSCR_HSE_RDYSEL_Msk
#define RCC_ECSCR_HSE_RDYSEL_0                    (0x1UL<<RCC_ECSCR_HSE_RDYSEL_Pos)                 /*!< 0x00000004 */
#define RCC_ECSCR_HSE_RDYSEL_1                    (0x2UL<<RCC_ECSCR_HSE_RDYSEL_Pos)                 /*!< 0x00000008 */
#define RCC_ECSCR_HSE_FILT_ENB_Pos                (4U)
#define RCC_ECSCR_HSE_FILT_ENB_Msk                (0x1UL<<RCC_ECSCR_HSE_FILT_ENB_Pos)               /*!< 0x00000010 */
#define RCC_ECSCR_HSE_FILT_ENB                    RCC_ECSCR_HSE_FILT_ENB_Msk                         

/********************************* Bit definition for RCC_CIER register *********************************************/
#define RCC_CIER_LSIRDYIE_Pos                     (0U)
#define RCC_CIER_LSIRDYIE_Msk                     (0x1UL<<RCC_CIER_LSIRDYIE_Pos)                    /*!< 0x00000001 */
#define RCC_CIER_LSIRDYIE                         RCC_CIER_LSIRDYIE_Msk                             
#define RCC_CIER_LSERDYIE_Pos                     (1U)
#define RCC_CIER_LSERDYIE_Msk                     (0x1UL<<RCC_CIER_LSERDYIE_Pos)                    /*!< 0x00000002 */
#define RCC_CIER_LSERDYIE                         RCC_CIER_LSERDYIE_Msk                             
#define RCC_CIER_MSIRDYIE_Pos                     (2U)
#define RCC_CIER_MSIRDYIE_Msk                     (0x1UL<<RCC_CIER_MSIRDYIE_Pos)                    /*!< 0x00000004 */
#define RCC_CIER_MSIRDYIE                         RCC_CIER_MSIRDYIE_Msk                             
#define RCC_CIER_HSIRDYIE_Pos                     (3U)
#define RCC_CIER_HSIRDYIE_Msk                     (0x1UL<<RCC_CIER_HSIRDYIE_Pos)                    /*!< 0x00000008 */
#define RCC_CIER_HSIRDYIE                         RCC_CIER_HSIRDYIE_Msk                             
#define RCC_CIER_HSERDYIE_Pos                     (4U)
#define RCC_CIER_HSERDYIE_Msk                     (0x1UL<<RCC_CIER_HSERDYIE_Pos)                    /*!< 0x00000010 */
#define RCC_CIER_HSERDYIE                         RCC_CIER_HSERDYIE_Msk                             
#define RCC_CIER_PLLRDYIE_Pos                     (5U)
#define RCC_CIER_PLLRDYIE_Msk                     (0x1UL<<RCC_CIER_PLLRDYIE_Pos)                    /*!< 0x00000020 */
#define RCC_CIER_PLLRDYIE                         RCC_CIER_PLLRDYIE_Msk                             

/********************************* Bit definition for RCC_CIFR register *********************************************/
#define RCC_CIFR_LSIRDYF_Pos                      (0U)
#define RCC_CIFR_LSIRDYF_Msk                      (0x1UL<<RCC_CIFR_LSIRDYF_Pos)                     /*!< 0x00000001 */
#define RCC_CIFR_LSIRDYF                          RCC_CIFR_LSIRDYF_Msk                              
#define RCC_CIFR_LSERDYF_Pos                      (1U)
#define RCC_CIFR_LSERDYF_Msk                      (0x1UL<<RCC_CIFR_LSERDYF_Pos)                     /*!< 0x00000002 */
#define RCC_CIFR_LSERDYF                          RCC_CIFR_LSERDYF_Msk                              
#define RCC_CIFR_MSIRDYF_Pos                      (2U)
#define RCC_CIFR_MSIRDYF_Msk                      (0x1UL<<RCC_CIFR_MSIRDYF_Pos)                     /*!< 0x00000004 */
#define RCC_CIFR_MSIRDYF                          RCC_CIFR_MSIRDYF_Msk                              
#define RCC_CIFR_HSIRDYF_Pos                      (3U)
#define RCC_CIFR_HSIRDYF_Msk                      (0x1UL<<RCC_CIFR_HSIRDYF_Pos)                     /*!< 0x00000008 */
#define RCC_CIFR_HSIRDYF                          RCC_CIFR_HSIRDYF_Msk                              
#define RCC_CIFR_HSERDYF_Pos                      (4U)
#define RCC_CIFR_HSERDYF_Msk                      (0x1UL<<RCC_CIFR_HSERDYF_Pos)                     /*!< 0x00000010 */
#define RCC_CIFR_HSERDYF                          RCC_CIFR_HSERDYF_Msk                              
#define RCC_CIFR_PLLRDYF_Pos                      (5U)
#define RCC_CIFR_PLLRDYF_Msk                      (0x1UL<<RCC_CIFR_PLLRDYF_Pos)                     /*!< 0x00000020 */
#define RCC_CIFR_PLLRDYF                          RCC_CIFR_PLLRDYF_Msk                              
#define RCC_CIFR_CSSF_Pos                         (8U)
#define RCC_CIFR_CSSF_Msk                         (0x1UL<<RCC_CIFR_CSSF_Pos)                        /*!< 0x00000100 */
#define RCC_CIFR_CSSF                             RCC_CIFR_CSSF_Msk                                 
#define RCC_CIFR_LSECSSF_Pos                      (9U)
#define RCC_CIFR_LSECSSF_Msk                      (0x1UL<<RCC_CIFR_LSECSSF_Pos)                     /*!< 0x00000200 */
#define RCC_CIFR_LSECSSF                          RCC_CIFR_LSECSSF_Msk                              

/********************************* Bit definition for RCC_CICR register *********************************************/
#define RCC_CICR_LSIRDYC_Pos                      (0U)
#define RCC_CICR_LSIRDYC_Msk                      (0x1UL<<RCC_CICR_LSIRDYC_Pos)                     /*!< 0x00000001 */
#define RCC_CICR_LSIRDYC                          RCC_CICR_LSIRDYC_Msk                              
#define RCC_CICR_LSERDYC_Pos                      (1U)
#define RCC_CICR_LSERDYC_Msk                      (0x1UL<<RCC_CICR_LSERDYC_Pos)                     /*!< 0x00000002 */
#define RCC_CICR_LSERDYC                          RCC_CICR_LSERDYC_Msk                              
#define RCC_CICR_MSIRDYC_Pos                      (2U)
#define RCC_CICR_MSIRDYC_Msk                      (0x1UL<<RCC_CICR_MSIRDYC_Pos)                     /*!< 0x00000002 */
#define RCC_CICR_MSIRDYC                          RCC_CICR_MSIRDYC_Msk
#define RCC_CICR_HSIRDYC_Pos                      (3U)
#define RCC_CICR_HSIRDYC_Msk                      (0x1UL<<RCC_CICR_HSIRDYC_Pos)                     /*!< 0x00000008 */
#define RCC_CICR_HSIRDYC                          RCC_CICR_HSIRDYC_Msk                              
#define RCC_CICR_HSERDYC_Pos                      (4U)
#define RCC_CICR_HSERDYC_Msk                      (0x1UL<<RCC_CICR_HSERDYC_Pos)                     /*!< 0x00000010 */
#define RCC_CICR_HSERDYC                          RCC_CICR_HSERDYC_Msk                              
#define RCC_CICR_PLLRDYC_Pos                      (5U)
#define RCC_CICR_PLLRDYC_Msk                      (0x1UL<<RCC_CICR_PLLRDYC_Pos)                     /*!< 0x00000020 */
#define RCC_CICR_PLLRDYC                          RCC_CICR_PLLRDYC_Msk                              
#define RCC_CICR_CSSC_Pos                         (8U)
#define RCC_CICR_CSSC_Msk                         (0x1UL<<RCC_CICR_CSSC_Pos)                        /*!< 0x00000100 */
#define RCC_CICR_CSSC                             RCC_CICR_CSSC_Msk                                 
#define RCC_CICR_LSECSSC_Pos                      (9U)
#define RCC_CICR_LSECSSC_Msk                      (0x1UL<<RCC_CICR_LSECSSC_Pos)                     /*!< 0x00000200 */
#define RCC_CICR_LSECSSC                          RCC_CICR_LSECSSC_Msk                              

/********************************* Bit definition for RCC_IOPRSTR register ******************************************/
#define RCC_IOPRSTR_GPIOARST_Pos                  (0U)
#define RCC_IOPRSTR_GPIOARST_Msk                  (0x1UL<<RCC_IOPRSTR_GPIOARST_Pos)                 /*!< 0x00000001 */
#define RCC_IOPRSTR_GPIOARST                      RCC_IOPRSTR_GPIOARST_Msk                          
#define RCC_IOPRSTR_GPIOBRST_Pos                  (1U)
#define RCC_IOPRSTR_GPIOBRST_Msk                  (0x1UL<<RCC_IOPRSTR_GPIOBRST_Pos)                 /*!< 0x00000002 */
#define RCC_IOPRSTR_GPIOBRST                      RCC_IOPRSTR_GPIOBRST_Msk                          
#define RCC_IOPRSTR_GPIOCRST_Pos                  (2U)
#define RCC_IOPRSTR_GPIOCRST_Msk                  (0x1UL<<RCC_IOPRSTR_GPIOCRST_Pos)                 /*!< 0x00000004 */
#define RCC_IOPRSTR_GPIOCRST                      RCC_IOPRSTR_GPIOCRST_Msk                          
#define RCC_IOPRSTR_GPIODRST_Pos                  (3U)
#define RCC_IOPRSTR_GPIODRST_Msk                  (0x1UL<<RCC_IOPRSTR_GPIODRST_Pos)                 /*!< 0x00000008 */
#define RCC_IOPRSTR_GPIODRST                      RCC_IOPRSTR_GPIODRST_Msk                          

/********************************* Bit definition for RCC_AHBRSTR register ******************************************/
#define RCC_AHBRSTR_DMARST_Pos                    (0U)
#define RCC_AHBRSTR_DMARST_Msk                    (0x1UL<<RCC_AHBRSTR_DMARST_Pos)                   /*!< 0x00000001 */
#define RCC_AHBRSTR_DMARST                        RCC_AHBRSTR_DMARST_Msk                            
#define RCC_AHBRSTR_CRCRST_Pos                    (12U)
#define RCC_AHBRSTR_CRCRST_Msk                    (0x1UL<<RCC_AHBRSTR_CRCRST_Pos)                   /*!< 0x00001000 */
#define RCC_AHBRSTR_CRCRST                        RCC_AHBRSTR_CRCRST_Msk                            

/********************************* Bit definition for RCC_APBRSTR1 register *****************************************/
#define RCC_APBRSTR1_TIM2RST_Pos                  (0U)
#define RCC_APBRSTR1_TIM2RST_Msk                  (0x1UL<<RCC_APBRSTR1_TIM2RST_Pos)                 /*!< 0x00000001 */
#define RCC_APBRSTR1_TIM2RST                      RCC_APBRSTR1_TIM2RST_Msk                          
#define RCC_APBRSTR1_TIM3RST_Pos                  (1U)
#define RCC_APBRSTR1_TIM3RST_Msk                  (0x1UL<<RCC_APBRSTR1_TIM3RST_Pos)                 /*!< 0x00000002 */
#define RCC_APBRSTR1_TIM3RST                      RCC_APBRSTR1_TIM3RST_Msk                          
#define RCC_APBRSTR1_TIM6RST_Pos                  (4U)
#define RCC_APBRSTR1_TIM6RST_Msk                  (0x1UL<<RCC_APBRSTR1_TIM6RST_Pos)                 /*!< 0x00000010 */
#define RCC_APBRSTR1_TIM6RST                      RCC_APBRSTR1_TIM6RST_Msk                          
#define RCC_APBRSTR1_TIM7RST_Pos                  (5U)
#define RCC_APBRSTR1_TIM7RST_Msk                  (0x1UL<<RCC_APBRSTR1_TIM7RST_Pos)                 /*!< 0x00000020 */
#define RCC_APBRSTR1_TIM7RST                      RCC_APBRSTR1_TIM7RST_Msk                          
#define RCC_APBRSTR1_PWMRST_Pos                   (6U)
#define RCC_APBRSTR1_PWMRST_Msk                   (0x1UL<<RCC_APBRSTR1_PWMRST_Pos)                  /*!< 0x00000040 */
#define RCC_APBRSTR1_PWMRST                       RCC_APBRSTR1_PWMRST_Msk                           
#define RCC_APBRSTR1_WWDGRST_Pos                  (11U)
#define RCC_APBRSTR1_WWDGRST_Msk                  (0x1UL<<RCC_APBRSTR1_WWDGRST_Pos)                 /*!< 0x00000800 */
#define RCC_APBRSTR1_WWDGRST                      RCC_APBRSTR1_WWDGRST_Msk                          
#define RCC_APBRSTR1_SPI2RST_Pos                  (14U)
#define RCC_APBRSTR1_SPI2RST_Msk                  (0x1UL<<RCC_APBRSTR1_SPI2RST_Pos)                 /*!< 0x00004000 */
#define RCC_APBRSTR1_SPI2RST                      RCC_APBRSTR1_SPI2RST_Msk                          
#define RCC_APBRSTR1_LPUART2RST_Pos               (16U)
#define RCC_APBRSTR1_LPUART2RST_Msk               (0x1UL<<RCC_APBRSTR1_LPUART2RST_Pos)              /*!< 0x00010000 */
#define RCC_APBRSTR1_LPUART2RST                   RCC_APBRSTR1_LPUART2RST_Msk                       
#define RCC_APBRSTR1_USART2RST_Pos                (17U)
#define RCC_APBRSTR1_USART2RST_Msk                (0x1UL<<RCC_APBRSTR1_USART2RST_Pos)               /*!< 0x00020000 */
#define RCC_APBRSTR1_USART2RST                    RCC_APBRSTR1_USART2RST_Msk                        
#define RCC_APBRSTR1_UART1RST_Pos                 (18U)
#define RCC_APBRSTR1_UART1RST_Msk                 (0x1UL<<RCC_APBRSTR1_UART1RST_Pos)                /*!< 0x00040000 */
#define RCC_APBRSTR1_UART1RST                     RCC_APBRSTR1_UART1RST_Msk                         
#define RCC_APBRSTR1_UART2RST_Pos                 (19U)
#define RCC_APBRSTR1_UART2RST_Msk                 (0x1UL<<RCC_APBRSTR1_UART2RST_Pos)                /*!< 0x00080000 */
#define RCC_APBRSTR1_UART2RST                     RCC_APBRSTR1_UART2RST_Msk                         
#define RCC_APBRSTR1_LPUART1RST_Pos               (20U)
#define RCC_APBRSTR1_LPUART1RST_Msk               (0x1UL<<RCC_APBRSTR1_LPUART1RST_Pos)              /*!< 0x00100000 */
#define RCC_APBRSTR1_LPUART1RST                   RCC_APBRSTR1_LPUART1RST_Msk                       
#define RCC_APBRSTR1_I2C1RST_Pos                  (21U)
#define RCC_APBRSTR1_I2C1RST_Msk                  (0x1UL<<RCC_APBRSTR1_I2C1RST_Pos)                 /*!< 0x00200000 */
#define RCC_APBRSTR1_I2C1RST                      RCC_APBRSTR1_I2C1RST_Msk                          
#define RCC_APBRSTR1_I2C2RST_Pos                  (22U)
#define RCC_APBRSTR1_I2C2RST_Msk                  (0x1UL<<RCC_APBRSTR1_I2C2RST_Pos)                 /*!< 0x00400000 */
#define RCC_APBRSTR1_I2C2RST                      RCC_APBRSTR1_I2C2RST_Msk                          
#define RCC_APBRSTR1_OPARST_Pos                   (23U)
#define RCC_APBRSTR1_OPARST_Msk                   (0x1UL<<RCC_APBRSTR1_OPARST_Pos)                  /*!< 0x00800000 */
#define RCC_APBRSTR1_OPARST                       RCC_APBRSTR1_OPARST_Msk                           
#define RCC_APBRSTR1_DBGRST_Pos                   (27U)
#define RCC_APBRSTR1_DBGRST_Msk                   (0x1UL<<RCC_APBRSTR1_DBGRST_Pos)                  /*!< 0x08000000 */
#define RCC_APBRSTR1_DBGRST                       RCC_APBRSTR1_DBGRST_Msk                           
#define RCC_APBRSTR1_PWRRST_Pos                   (28U)
#define RCC_APBRSTR1_PWRRST_Msk                   (0x1UL<<RCC_APBRSTR1_PWRRST_Pos)                  /*!< 0x10000000 */
#define RCC_APBRSTR1_PWRRST                       RCC_APBRSTR1_PWRRST_Msk                           
#define RCC_APBRSTR1_DACRST_Pos                   (29U)
#define RCC_APBRSTR1_DACRST_Msk                   (0x1UL<<RCC_APBRSTR1_DACRST_Pos)                  /*!< 0x20000000 */
#define RCC_APBRSTR1_DACRST                       RCC_APBRSTR1_DACRST_Msk                           
#define RCC_APBRSTR1_LPTIM2RST_Pos                (30U)
#define RCC_APBRSTR1_LPTIM2RST_Msk                (0x1UL<<RCC_APBRSTR1_LPTIM2RST_Pos)               /*!< 0x40000000 */
#define RCC_APBRSTR1_LPTIM2RST                    RCC_APBRSTR1_LPTIM2RST_Msk                        
#define RCC_APBRSTR1_LPTIM1RST_Pos                (31U)
#define RCC_APBRSTR1_LPTIM1RST_Msk                (0x1UL<<RCC_APBRSTR1_LPTIM1RST_Pos)               /*!< 0x80000000 */
#define RCC_APBRSTR1_LPTIM1RST                    RCC_APBRSTR1_LPTIM1RST_Msk                        

/********************************* Bit definition for RCC_APBRSTR2 register *****************************************/
#define RCC_APBRSTR2_SYSCFGRST_Pos                (0U)
#define RCC_APBRSTR2_SYSCFGRST_Msk                (0x1UL<<RCC_APBRSTR2_SYSCFGRST_Pos)               /*!< 0x00000001 */
#define RCC_APBRSTR2_SYSCFGRST                    RCC_APBRSTR2_SYSCFGRST_Msk                        
#define RCC_APBRSTR2_TIM1RST_Pos                  (11U)
#define RCC_APBRSTR2_TIM1RST_Msk                  (0x1UL<<RCC_APBRSTR2_TIM1RST_Pos)                 /*!< 0x00000800 */
#define RCC_APBRSTR2_TIM1RST                      RCC_APBRSTR2_TIM1RST_Msk                          
#define RCC_APBRSTR2_SPI1RST_Pos                  (12U)
#define RCC_APBRSTR2_SPI1RST_Msk                  (0x1UL<<RCC_APBRSTR2_SPI1RST_Pos)                 /*!< 0x00001000 */
#define RCC_APBRSTR2_SPI1RST                      RCC_APBRSTR2_SPI1RST_Msk                          
#define RCC_APBRSTR2_USART1RST_Pos                (14U)
#define RCC_APBRSTR2_USART1RST_Msk                (0x1UL<<RCC_APBRSTR2_USART1RST_Pos)               /*!< 0x00004000 */
#define RCC_APBRSTR2_USART1RST                    RCC_APBRSTR2_USART1RST_Msk                        
#define RCC_APBRSTR2_TIM15RST_Pos                 (16U)
#define RCC_APBRSTR2_TIM15RST_Msk                 (0x1UL<<RCC_APBRSTR2_TIM15RST_Pos)                /*!< 0x00010000 */
#define RCC_APBRSTR2_TIM15RST                     RCC_APBRSTR2_TIM15RST_Msk                         
#define RCC_APBRSTR2_TIM16RST_Pos                 (17U)
#define RCC_APBRSTR2_TIM16RST_Msk                 (0x1UL<<RCC_APBRSTR2_TIM16RST_Pos)                /*!< 0x00020000 */
#define RCC_APBRSTR2_TIM16RST                     RCC_APBRSTR2_TIM16RST_Msk                         
#define RCC_APBRSTR2_TIM17RST_Pos                 (18U)
#define RCC_APBRSTR2_TIM17RST_Msk                 (0x1UL<<RCC_APBRSTR2_TIM17RST_Pos)                /*!< 0x00040000 */
#define RCC_APBRSTR2_TIM17RST                     RCC_APBRSTR2_TIM17RST_Msk                         
#define RCC_APBRSTR2_ADCRST_Pos                   (20U)
#define RCC_APBRSTR2_ADCRST_Msk                   (0x1UL<<RCC_APBRSTR2_ADCRST_Pos)                  /*!< 0x00100000 */
#define RCC_APBRSTR2_ADCRST                       RCC_APBRSTR2_ADCRST_Msk                           
#define RCC_APBRSTR2_COMP1RST_Pos                 (21U)
#define RCC_APBRSTR2_COMP1RST_Msk                 (0x1UL<<RCC_APBRSTR2_COMP1RST_Pos)                /*!< 0x00200000 */
#define RCC_APBRSTR2_COMP1RST                     RCC_APBRSTR2_COMP1RST_Msk                         
#define RCC_APBRSTR2_COMP2RST_Pos                 (22U)
#define RCC_APBRSTR2_COMP2RST_Msk                 (0x1UL<<RCC_APBRSTR2_COMP2RST_Pos)                /*!< 0x00400000 */
#define RCC_APBRSTR2_COMP2RST                     RCC_APBRSTR2_COMP2RST_Msk                         
#define RCC_APBRSTR2_LCDRST_Pos                   (24U)
#define RCC_APBRSTR2_LCDRST_Msk                   (0x1UL<<RCC_APBRSTR2_LCDRST_Pos)                  /*!< 0x01000000 */
#define RCC_APBRSTR2_LCDRST                       RCC_APBRSTR2_LCDRST_Msk                           
#define RCC_APBRSTR2_TKRST_Pos                    (25U)
#define RCC_APBRSTR2_TKRST_Msk                    (0x1UL<<RCC_APBRSTR2_TKRST_Pos)                   /*!< 0x02000000 */
#define RCC_APBRSTR2_TKRST                        RCC_APBRSTR2_TKRST_Msk                            
#define RCC_APBRSTR2_VREFBUFRST_Pos               (26U)
#define RCC_APBRSTR2_VREFBUFRST_Msk               (0x1UL<<RCC_APBRSTR2_VREFBUFRST_Pos)              /*!< 0x04000000 */
#define RCC_APBRSTR2_VREFBUFRST                   RCC_APBRSTR2_VREFBUFRST_Msk                       

/********************************* Bit definition for RCC_IOPENR register *******************************************/
#define RCC_IOPENR_GPIOAEN_Pos                    (0U)
#define RCC_IOPENR_GPIOAEN_Msk                    (0x1UL<<RCC_IOPENR_GPIOAEN_Pos)                   /*!< 0x00000001 */
#define RCC_IOPENR_GPIOAEN                        RCC_IOPENR_GPIOAEN_Msk                            
#define RCC_IOPENR_GPIOBEN_Pos                    (1U)
#define RCC_IOPENR_GPIOBEN_Msk                    (0x1UL<<RCC_IOPENR_GPIOBEN_Pos)                   /*!< 0x00000002 */
#define RCC_IOPENR_GPIOBEN                        RCC_IOPENR_GPIOBEN_Msk                            
#define RCC_IOPENR_GPIOCEN_Pos                    (2U)
#define RCC_IOPENR_GPIOCEN_Msk                    (0x1UL<<RCC_IOPENR_GPIOCEN_Pos)                   /*!< 0x00000004 */
#define RCC_IOPENR_GPIOCEN                        RCC_IOPENR_GPIOCEN_Msk                            
#define RCC_IOPENR_GPIODEN_Pos                    (3U)
#define RCC_IOPENR_GPIODEN_Msk                    (0x1UL<<RCC_IOPENR_GPIODEN_Pos)                   /*!< 0x00000008 */
#define RCC_IOPENR_GPIODEN                        RCC_IOPENR_GPIODEN_Msk                            

/********************************* Bit definition for RCC_AHBENR register *******************************************/
#define RCC_AHBENR_DMAEN_Pos                      (0U)
#define RCC_AHBENR_DMAEN_Msk                      (0x1UL<<RCC_AHBENR_DMAEN_Pos)                     /*!< 0x00000001 */
#define RCC_AHBENR_DMAEN                          RCC_AHBENR_DMAEN_Msk                              
#define RCC_AHBENR_FLASHEN_Pos                    (8U)
#define RCC_AHBENR_FLASHEN_Msk                    (0x1UL<<RCC_AHBENR_FLASHEN_Pos)                   /*!< 0x00000100 */
#define RCC_AHBENR_FLASHEN                        RCC_AHBENR_FLASHEN_Msk                            
#define RCC_AHBENR_SRAMEN_Pos                     (9U)
#define RCC_AHBENR_SRAMEN_Msk                     (0x1UL<<RCC_AHBENR_SRAMEN_Pos)                    /*!< 0x00000200 */
#define RCC_AHBENR_SRAMEN                         RCC_AHBENR_SRAMEN_Msk                             
#define RCC_AHBENR_CRCEN_Pos                      (12U)
#define RCC_AHBENR_CRCEN_Msk                      (0x1UL<<RCC_AHBENR_CRCEN_Pos)                     /*!< 0x00001000 */
#define RCC_AHBENR_CRCEN                          RCC_AHBENR_CRCEN_Msk                              

/********************************* Bit definition for RCC_APBENR1 register ******************************************/
#define RCC_APBENR1_TIM2EN_Pos                    (0U)
#define RCC_APBENR1_TIM2EN_Msk                    (0x1UL<<RCC_APBENR1_TIM2EN_Pos)                   /*!< 0x00000001 */
#define RCC_APBENR1_TIM2EN                        RCC_APBENR1_TIM2EN_Msk                            
#define RCC_APBENR1_TIM3EN_Pos                    (1U)
#define RCC_APBENR1_TIM3EN_Msk                    (0x1UL<<RCC_APBENR1_TIM3EN_Pos)                   /*!< 0x00000002 */
#define RCC_APBENR1_TIM3EN                        RCC_APBENR1_TIM3EN_Msk                            
#define RCC_APBENR1_TIM6EN_Pos                    (4U)
#define RCC_APBENR1_TIM6EN_Msk                    (0x1UL<<RCC_APBENR1_TIM6EN_Pos)                   /*!< 0x00000010 */
#define RCC_APBENR1_TIM6EN                        RCC_APBENR1_TIM6EN_Msk                            
#define RCC_APBENR1_TIM7EN_Pos                    (5U)
#define RCC_APBENR1_TIM7EN_Msk                    (0x1UL<<RCC_APBENR1_TIM7EN_Pos)                   /*!< 0x00000020 */
#define RCC_APBENR1_TIM7EN                        RCC_APBENR1_TIM7EN_Msk                            
#define RCC_APBENR1_PWMEN_Pos                     (6U)
#define RCC_APBENR1_PWMEN_Msk                     (0x1UL<<RCC_APBENR1_PWMEN_Pos)                    /*!< 0x00000040 */
#define RCC_APBENR1_PWMEN                         RCC_APBENR1_PWMEN_Msk                             
#define RCC_APBENR1_WWDGEN_Pos                    (11U)
#define RCC_APBENR1_WWDGEN_Msk                    (0x1UL<<RCC_APBENR1_WWDGEN_Pos)                   /*!< 0x00000800 */
#define RCC_APBENR1_WWDGEN                        RCC_APBENR1_WWDGEN_Msk                            
#define RCC_APBENR1_SPI2EN_Pos                    (14U)
#define RCC_APBENR1_SPI2EN_Msk                    (0x1UL<<RCC_APBENR1_SPI2EN_Pos)                   /*!< 0x00004000 */
#define RCC_APBENR1_SPI2EN                        RCC_APBENR1_SPI2EN_Msk                            
#define RCC_APBENR1_LPUART2EN_Pos                 (16U)
#define RCC_APBENR1_LPUART2EN_Msk                 (0x1UL<<RCC_APBENR1_LPUART2EN_Pos)                /*!< 0x00010000 */
#define RCC_APBENR1_LPUART2EN                     RCC_APBENR1_LPUART2EN_Msk                         
#define RCC_APBENR1_USART2EN_Pos                  (17U)
#define RCC_APBENR1_USART2EN_Msk                  (0x1UL<<RCC_APBENR1_USART2EN_Pos)                 /*!< 0x00020000 */
#define RCC_APBENR1_USART2EN                      RCC_APBENR1_USART2EN_Msk                          
#define RCC_APBENR1_UART1EN_Pos                   (18U)
#define RCC_APBENR1_UART1EN_Msk                   (0x1UL<<RCC_APBENR1_UART1EN_Pos)                  /*!< 0x00040000 */
#define RCC_APBENR1_UART1EN                       RCC_APBENR1_UART1EN_Msk                           
#define RCC_APBENR1_UART2EN_Pos                   (19U)
#define RCC_APBENR1_UART2EN_Msk                   (0x1UL<<RCC_APBENR1_UART2EN_Pos)                  /*!< 0x00080000 */
#define RCC_APBENR1_UART2EN                       RCC_APBENR1_UART2EN_Msk                           
#define RCC_APBENR1_LPUART1EN_Pos                 (20U)
#define RCC_APBENR1_LPUART1EN_Msk                 (0x1UL<<RCC_APBENR1_LPUART1EN_Pos)                /*!< 0x00100000 */
#define RCC_APBENR1_LPUART1EN                     RCC_APBENR1_LPUART1EN_Msk                         
#define RCC_APBENR1_I2C1EN_Pos                    (21U)
#define RCC_APBENR1_I2C1EN_Msk                    (0x1UL<<RCC_APBENR1_I2C1EN_Pos)                   /*!< 0x00200000 */
#define RCC_APBENR1_I2C1EN                        RCC_APBENR1_I2C1EN_Msk                            
#define RCC_APBENR1_I2C2EN_Pos                    (22U)
#define RCC_APBENR1_I2C2EN_Msk                    (0x1UL<<RCC_APBENR1_I2C2EN_Pos)                   /*!< 0x00400000 */
#define RCC_APBENR1_I2C2EN                        RCC_APBENR1_I2C2EN_Msk                            
#define RCC_APBENR1_OPAEN_Pos                     (23U)
#define RCC_APBENR1_OPAEN_Msk                     (0x1UL<<RCC_APBENR1_OPAEN_Pos)                    /*!< 0x00800000 */
#define RCC_APBENR1_OPAEN                         RCC_APBENR1_OPAEN_Msk                             
#define RCC_APBENR1_DBGEN_Pos                     (27U)
#define RCC_APBENR1_DBGEN_Msk                     (0x1UL<<RCC_APBENR1_DBGEN_Pos)                    /*!< 0x08000000 */
#define RCC_APBENR1_DBGEN                         RCC_APBENR1_DBGEN_Msk                             
#define RCC_APBENR1_PWREN_Pos                     (28U)
#define RCC_APBENR1_PWREN_Msk                     (0x1UL<<RCC_APBENR1_PWREN_Pos)                    /*!< 0x10000000 */
#define RCC_APBENR1_PWREN                         RCC_APBENR1_PWREN_Msk                             
#define RCC_APBENR1_DACEN_Pos                     (29U)
#define RCC_APBENR1_DACEN_Msk                     (0x1UL<<RCC_APBENR1_DACEN_Pos)                    /*!< 0x20000000 */
#define RCC_APBENR1_DACEN                         RCC_APBENR1_DACEN_Msk                             
#define RCC_APBENR1_LPTIM2EN_Pos                  (30U)
#define RCC_APBENR1_LPTIM2EN_Msk                  (0x1UL<<RCC_APBENR1_LPTIM2EN_Pos)                 /*!< 0x40000000 */
#define RCC_APBENR1_LPTIM2EN                      RCC_APBENR1_LPTIM2EN_Msk                          
#define RCC_APBENR1_LPTIM1EN_Pos                  (31U)
#define RCC_APBENR1_LPTIM1EN_Msk                  (0x1UL<<RCC_APBENR1_LPTIM1EN_Pos)                 /*!< 0x80000000 */
#define RCC_APBENR1_LPTIM1EN                      RCC_APBENR1_LPTIM1EN_Msk                          

/********************************* Bit definition for RCC_APBENR2 register ******************************************/
#define RCC_APBENR2_SYSCFGEN_Pos                  (0U)
#define RCC_APBENR2_SYSCFGEN_Msk                  (0x1UL<<RCC_APBENR2_SYSCFGEN_Pos)                 /*!< 0x00000001 */
#define RCC_APBENR2_SYSCFGEN                      RCC_APBENR2_SYSCFGEN_Msk                          
#define RCC_APBENR2_TIM1EN_Pos                    (11U)
#define RCC_APBENR2_TIM1EN_Msk                    (0x1UL<<RCC_APBENR2_TIM1EN_Pos)                   /*!< 0x00000800 */
#define RCC_APBENR2_TIM1EN                        RCC_APBENR2_TIM1EN_Msk                            
#define RCC_APBENR2_SPI1EN_Pos                    (12U)
#define RCC_APBENR2_SPI1EN_Msk                    (0x1UL<<RCC_APBENR2_SPI1EN_Pos)                   /*!< 0x00001000 */
#define RCC_APBENR2_SPI1EN                        RCC_APBENR2_SPI1EN_Msk                            
#define RCC_APBENR2_USART1EN_Pos                  (14U)
#define RCC_APBENR2_USART1EN_Msk                  (0x1UL<<RCC_APBENR2_USART1EN_Pos)                 /*!< 0x00004000 */
#define RCC_APBENR2_USART1EN                      RCC_APBENR2_USART1EN_Msk                          
#define RCC_APBENR2_TIM15EN_Pos                   (16U)
#define RCC_APBENR2_TIM15EN_Msk                   (0x1UL<<RCC_APBENR2_TIM15EN_Pos)                  /*!< 0x00010000 */
#define RCC_APBENR2_TIM15EN                       RCC_APBENR2_TIM15EN_Msk                           
#define RCC_APBENR2_TIM16EN_Pos                   (17U)
#define RCC_APBENR2_TIM16EN_Msk                   (0x1UL<<RCC_APBENR2_TIM16EN_Pos)                  /*!< 0x00020000 */
#define RCC_APBENR2_TIM16EN                       RCC_APBENR2_TIM16EN_Msk                           
#define RCC_APBENR2_TIM17EN_Pos                   (18U)
#define RCC_APBENR2_TIM17EN_Msk                   (0x1UL<<RCC_APBENR2_TIM17EN_Pos)                  /*!< 0x00040000 */
#define RCC_APBENR2_TIM17EN                       RCC_APBENR2_TIM17EN_Msk                           
#define RCC_APBENR2_ADCEN_Pos                     (20U)
#define RCC_APBENR2_ADCEN_Msk                     (0x1UL<<RCC_APBENR2_ADCEN_Pos)                    /*!< 0x00100000 */
#define RCC_APBENR2_ADCEN                         RCC_APBENR2_ADCEN_Msk                             
#define RCC_APBENR2_COMP1EN_Pos                   (21U)
#define RCC_APBENR2_COMP1EN_Msk                   (0x1UL<<RCC_APBENR2_COMP1EN_Pos)                  /*!< 0x00200000 */
#define RCC_APBENR2_COMP1EN                       RCC_APBENR2_COMP1EN_Msk                           
#define RCC_APBENR2_COMP2EN_Pos                   (22U)
#define RCC_APBENR2_COMP2EN_Msk                   (0x1UL<<RCC_APBENR2_COMP2EN_Pos)                  /*!< 0x00400000 */
#define RCC_APBENR2_COMP2EN                       RCC_APBENR2_COMP2EN_Msk                           
#define RCC_APBENR2_COMP3EN_Pos                   (23U)
#define RCC_APBENR2_COMP3EN_Msk                   (0x1UL<<RCC_APBENR2_COMP3EN_Pos)                  /*!< 0x00800000 */
#define RCC_APBENR2_COMP3EN                       RCC_APBENR2_COMP3EN_Msk                           
#define RCC_APBENR2_LCDEN_Pos                     (24U)
#define RCC_APBENR2_LCDEN_Msk                     (0x1UL<<RCC_APBENR2_LCDEN_Pos)                    /*!< 0x01000000 */
#define RCC_APBENR2_LCDEN                         RCC_APBENR2_LCDEN_Msk                             
#define RCC_APBENR2_TKEN_Pos                      (25U)
#define RCC_APBENR2_TKEN_Msk                      (0x1UL<<RCC_APBENR2_TKEN_Pos)                     /*!< 0x02000000 */
#define RCC_APBENR2_TKEN                          RCC_APBENR2_TKEN_Msk                              
#define RCC_APBENR2_VREFBUFEN_Pos                 (26U)
#define RCC_APBENR2_VREFBUFEN_Msk                 (0x1UL<<RCC_APBENR2_VREFBUFEN_Pos)                /*!< 0x04000000 */
#define RCC_APBENR2_VREFBUFEN                     RCC_APBENR2_VREFBUFEN_Msk                         

/********************************* Bit definition for RCC_CCIPR register ********************************************/
#define RCC_CCIPR_TIMCLKCTRL_Pos                  (0U)
#define RCC_CCIPR_TIMCLKCTRL_Msk                  (0x1UL<<RCC_CCIPR_TIMCLKCTRL_Pos)                 /*!< 0x00000001 */
#define RCC_CCIPR_TIMCLKCTRL                      RCC_CCIPR_TIMCLKCTRL_Msk                          
#define RCC_CCIPR_PVDSEL_Pos                      (7U)
#define RCC_CCIPR_PVDSEL_Msk                      (0x1UL<<RCC_CCIPR_PVDSEL_Pos)                     /*!< 0x00000080 */
#define RCC_CCIPR_PVDSEL                          RCC_CCIPR_PVDSEL_Msk                              
#define RCC_CCIPR_COMP1SEL_Pos                    (8U)
#define RCC_CCIPR_COMP1SEL_Msk                    (0x1UL<<RCC_CCIPR_COMP1SEL_Pos)                   /*!< 0x00000100 */
#define RCC_CCIPR_COMP1SEL                        RCC_CCIPR_COMP1SEL_Msk                            
#define RCC_CCIPR_COMP2SEL_Pos                    (9U)
#define RCC_CCIPR_COMP2SEL_Msk                    (0x1UL<<RCC_CCIPR_COMP2SEL_Pos)                   /*!< 0x00000200 */
#define RCC_CCIPR_COMP2SEL                        RCC_CCIPR_COMP2SEL_Msk                            
#define RCC_CCIPR_COMP3SEL_Pos                    (10U)
#define RCC_CCIPR_COMP3SEL_Msk                    (0x1UL<<RCC_CCIPR_COMP3SEL_Pos)                   /*!< 0x00000400 */
#define RCC_CCIPR_COMP3SEL                        RCC_CCIPR_COMP3SEL_Msk                            
#define RCC_CCIPR_LPUART1SEL_Pos                  (11U)
#define RCC_CCIPR_LPUART1SEL_Msk                  (0x3UL<<RCC_CCIPR_LPUART1SEL_Pos)                 /*!< 0x00001800 */
#define RCC_CCIPR_LPUART1SEL                      RCC_CCIPR_LPUART1SEL_Msk
#define RCC_CCIPR_LPUART1SEL_0                    (0x1UL<<RCC_CCIPR_LPUART1SEL_Pos)                 /*!< 0x00000800 */
#define RCC_CCIPR_LPUART1SEL_1                    (0x2UL<<RCC_CCIPR_LPUART1SEL_Pos)                 /*!< 0x00001000 */
#define RCC_CCIPR_LPUART2SEL_Pos                  (13U)
#define RCC_CCIPR_LPUART2SEL_Msk                  (0x3UL<<RCC_CCIPR_LPUART2SEL_Pos)                 /*!< 0x00006000 */
#define RCC_CCIPR_LPUART2SEL                      RCC_CCIPR_LPUART2SEL_Msk
#define RCC_CCIPR_LPUART2SEL_0                    (0x1UL<<RCC_CCIPR_LPUART2SEL_Pos)                 /*!< 0x00002000 */
#define RCC_CCIPR_LPUART2SEL_1                    (0x2UL<<RCC_CCIPR_LPUART2SEL_Pos)                 /*!< 0x00004000 */
#define RCC_CCIPR_LPTIM1SEL_Pos                   (16U)
#define RCC_CCIPR_LPTIM1SEL_Msk                   (0x3UL<<RCC_CCIPR_LPTIM1SEL_Pos)                  /*!< 0x00030000 */
#define RCC_CCIPR_LPTIM1SEL                       RCC_CCIPR_LPTIM1SEL_Msk
#define RCC_CCIPR_LPTIM1SEL_0                     (0x1UL<<RCC_CCIPR_LPTIM1SEL_Pos)                  /*!< 0x00010000 */
#define RCC_CCIPR_LPTIM1SEL_1                     (0x2UL<<RCC_CCIPR_LPTIM1SEL_Pos)                  /*!< 0x00020000 */
#define RCC_CCIPR_LPTIM2SEL_Pos                   (18U)
#define RCC_CCIPR_LPTIM2SEL_Msk                   (0x3UL<<RCC_CCIPR_LPTIM2SEL_Pos)                  /*!< 0x000C0000 */
#define RCC_CCIPR_LPTIM2SEL                       RCC_CCIPR_LPTIM2SEL_Msk
#define RCC_CCIPR_LPTIM2SEL_0                     (0x1UL<<RCC_CCIPR_LPTIM2SEL_Pos)                  /*!< 0x00040000 */
#define RCC_CCIPR_LPTIM2SEL_1                     (0x2UL<<RCC_CCIPR_LPTIM2SEL_Pos)                  /*!< 0x00080000 */
#define RCC_CCIPR_PWMSEL_Pos                      (21U)
#define RCC_CCIPR_PWMSEL_Msk                      (0x1UL<<RCC_CCIPR_PWMSEL_Pos)                     /*!< 0x00200000 */
#define RCC_CCIPR_PWMSEL                          RCC_CCIPR_PWMSEL_Msk                              
#define RCC_CCIPR_ADCSEL_Pos                      (30U)
#define RCC_CCIPR_ADCSEL_Msk                      (0x3UL<<RCC_CCIPR_ADCSEL_Pos)                     /*!< 0xC0000000 */
#define RCC_CCIPR_ADCSEL                          RCC_CCIPR_ADCSEL_Msk
#define RCC_CCIPR_ADCSEL_0                        (0x1UL<<RCC_CCIPR_ADCSEL_Pos)                     /*!< 0x40000000 */
#define RCC_CCIPR_ADCSEL_1                        (0x2UL<<RCC_CCIPR_ADCSEL_Pos)                     /*!< 0x80000000 */

/********************************* Bit definition for RCC_BDCR register *********************************************/
#define RCC_BDCR_LSERDY_Pos                       (1U)
#define RCC_BDCR_LSERDY_Msk                       (0x1UL<<RCC_BDCR_LSERDY_Pos)                      /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                           RCC_BDCR_LSERDY_Msk                               
#define RCC_BDCR_LSEBYP_Pos                       (2U)
#define RCC_BDCR_LSEBYP_Msk                       (0x1UL<<RCC_BDCR_LSEBYP_Pos)                      /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                           RCC_BDCR_LSEBYP_Msk                               
#define RCC_BDCR_LSEDRV_Pos                       (3U)
#define RCC_BDCR_LSEDRV_Msk                       (0x3UL<<RCC_BDCR_LSEDRV_Pos)                      /*!< 0x00000018 */
#define RCC_BDCR_LSEDRV                           RCC_BDCR_LSEDRV_Msk
#define RCC_BDCR_LSEDRV_0                         (0x1UL<<RCC_BDCR_LSEDRV_Pos)                      /*!< 0x00000008 */
#define RCC_BDCR_LSEDRV_1                         (0x2UL<<RCC_BDCR_LSEDRV_Pos)                      /*!< 0x00000010 */
#define RCC_BDCR_LSECSSON_Pos                     (5U)
#define RCC_BDCR_LSECSSON_Msk                     (0x1UL<<RCC_BDCR_LSECSSON_Pos)                    /*!< 0x00000020 */
#define RCC_BDCR_LSECSSON                         RCC_BDCR_LSECSSON_Msk                             
#define RCC_BDCR_LSECSSD_Pos                      (6U)
#define RCC_BDCR_LSECSSD_Msk                      (0x1UL<<RCC_BDCR_LSECSSD_Pos)                     /*!< 0x00000040 */
#define RCC_BDCR_LSECSSD                          RCC_BDCR_LSECSSD_Msk                              
#define RCC_BDCR_RTCSEL_Pos                       (8U)
#define RCC_BDCR_RTCSEL_Msk                       (0x3UL<<RCC_BDCR_RTCSEL_Pos)                      /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                           RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                         (0x1UL<<RCC_BDCR_RTCSEL_Pos)                      /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                         (0x2UL<<RCC_BDCR_RTCSEL_Pos)                      /*!< 0x00000200 */
#define RCC_BDCR_LSEEN_Pos                        (10U)
#define RCC_BDCR_LSEEN_Msk                        (0xFUL<<RCC_BDCR_LSEEN_Pos)                       /*!< 0x00003C00 */
#define RCC_BDCR_LSEEN                            RCC_BDCR_LSEEN_Msk
#define RCC_BDCR_LSEEN_0                          (0x1UL<<RCC_BDCR_LSEEN_Pos)                       /*!< 0x00000400 */
#define RCC_BDCR_LSEEN_1                          (0x2UL<<RCC_BDCR_LSEEN_Pos)                       /*!< 0x00000800 */
#define RCC_BDCR_LSEEN_2                          (0x4UL<<RCC_BDCR_LSEEN_Pos)                       /*!< 0x00001000 */
#define RCC_BDCR_LSEEN_3                          (0x8UL<<RCC_BDCR_LSEEN_Pos)                       /*!< 0x00002000 */
#define RCC_BDCR_LSCSEL_Pos                       (14U)
#define RCC_BDCR_LSCSEL_Msk                       (0x1UL<<RCC_BDCR_LSCSEL_Pos)                      /*!< 0x00004000 */
#define RCC_BDCR_LSCSEL                           RCC_BDCR_LSCSEL_Msk                               
#define RCC_BDCR_RTCEN_Pos                        (15U)
#define RCC_BDCR_RTCEN_Msk                        (0x1UL<<RCC_BDCR_RTCEN_Pos)                       /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                            RCC_BDCR_RTCEN_Msk                                
#define RCC_BDCR_BDRST_Pos                        (16U)
#define RCC_BDCR_BDRST_Msk                        (0x1UL<<RCC_BDCR_BDRST_Pos)                       /*!< 0x00010000 */
#define RCC_BDCR_BDRST                            RCC_BDCR_BDRST_Msk                                
#define RCC_BDCR_LSI_TRIMCR_Pos                   (17U)
#define RCC_BDCR_LSI_TRIMCR_Msk                   (0x1FFUL<<RCC_BDCR_LSI_TRIMCR_Pos)                /*!< 0x03FE0000 */
#define RCC_BDCR_LSI_TRIMCR                       RCC_BDCR_LSI_TRIMCR_Msk
#define RCC_BDCR_LSION_Pos                        (26U)
#define RCC_BDCR_LSION_Msk                        (0x1UL<<RCC_BDCR_LSION_Pos)                       /*!< 0x04000000 */
#define RCC_BDCR_LSION                            RCC_BDCR_LSION_Msk                                
#define RCC_BDCR_LSIRDY_Pos                       (27U)
#define RCC_BDCR_LSIRDY_Msk                       (0x1UL<<RCC_BDCR_LSIRDY_Pos)                      /*!< 0x08000000 */
#define RCC_BDCR_LSIRDY                           RCC_BDCR_LSIRDY_Msk                               
#define RCC_BDCR_LSE_RDYSEL_Pos                   (28U)
#define RCC_BDCR_LSE_RDYSEL_Msk                   (0x3UL<<RCC_BDCR_LSE_RDYSEL_Pos)                  /*!< 0x30000000 */
#define RCC_BDCR_LSE_RDYSEL                       RCC_BDCR_LSE_RDYSEL_Msk
#define RCC_BDCR_LSE_RDYSEL_0                     (0x1UL<<RCC_BDCR_LSE_RDYSEL_Pos)                  /*!< 0x10000000 */
#define RCC_BDCR_LSE_RDYSEL_1                     (0x2UL<<RCC_BDCR_LSE_RDYSEL_Pos)                  /*!< 0x20000000 */
#define RCC_BDCR_IWDGSEL_Pos                      (30U)
#define RCC_BDCR_IWDGSEL_Msk                      (0x1UL<<RCC_BDCR_IWDGSEL_Pos)                     /*!< 0x40000000 */
#define RCC_BDCR_IWDGSEL                          RCC_BDCR_IWDGSEL_Msk                              

/********************************* Bit definition for RCC_CSR register **********************************************/
#define RCC_CSR_NRST_FLTDIS_Pos                   (8U)
#define RCC_CSR_NRST_FLTDIS_Msk                   (0x1UL<<RCC_CSR_NRST_FLTDIS_Pos)                  /*!< 0x00000100 */
#define RCC_CSR_NRST_FLTDIS                       RCC_CSR_NRST_FLTDIS_Msk                           
#define RCC_CSR_SPERSTF_Pos                       (22U)
#define RCC_CSR_SPERSTF_Msk                       (0x1UL<<RCC_CSR_SPERSTF_Pos)                      /*!< 0x00400000 */
#define RCC_CSR_SPERSTF                           RCC_CSR_SPERSTF_Msk                              
#define RCC_CSR_RMVF_Pos                          (23U)
#define RCC_CSR_RMVF_Msk                          (0x1UL<<RCC_CSR_RMVF_Pos)                         /*!< 0x00800000 */
#define RCC_CSR_RMVF                              RCC_CSR_RMVF_Msk                                  
#define RCC_CSR_OBLRSTF_Pos                       (25U)
#define RCC_CSR_OBLRSTF_Msk                       (0x1UL<<RCC_CSR_OBLRSTF_Pos)                      /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                           RCC_CSR_OBLRSTF_Msk                               
#define RCC_CSR_PINRSTF_Pos                       (26U)
#define RCC_CSR_PINRSTF_Msk                       (0x1UL<<RCC_CSR_PINRSTF_Pos)                      /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                           RCC_CSR_PINRSTF_Msk                               
#define RCC_CSR_PWRRSTF_Pos                       (27U)
#define RCC_CSR_PWRRSTF_Msk                       (0x1UL<<RCC_CSR_PWRRSTF_Pos)                      /*!< 0x08000000 */
#define RCC_CSR_PWRRSTF                           RCC_CSR_PWRRSTF_Msk                               
#define RCC_CSR_SFTRSTF_Pos                       (28U)
#define RCC_CSR_SFTRSTF_Msk                       (0x1UL<<RCC_CSR_SFTRSTF_Pos)                      /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                           RCC_CSR_SFTRSTF_Msk                               
#define RCC_CSR_IWDGRSTF_Pos                      (29U)
#define RCC_CSR_IWDGRSTF_Msk                      (0x1UL<<RCC_CSR_IWDGRSTF_Pos)                     /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                          RCC_CSR_IWDGRSTF_Msk                              
#define RCC_CSR_WWDGRSTF_Pos                      (30U)
#define RCC_CSR_WWDGRSTF_Msk                      (0x1UL<<RCC_CSR_WWDGRSTF_Pos)                     /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                          RCC_CSR_WWDGRSTF_Msk                              
#define RCC_CSR_LPWRRSTF_Pos                      (31U)
#define RCC_CSR_LPWRRSTF_Msk                      (0x1UL<<RCC_CSR_LPWRRSTF_Pos)                     /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                          RCC_CSR_LPWRRSTF_Msk                              
                            

/********************************************************************************************************************/
/********************************* RTC ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for RTC_TR register ***********************************************/
#define RTC_TR_SU_Pos                             (0U)
#define RTC_TR_SU_Msk                             (0xFUL<<RTC_TR_SU_Pos)                            /*!< 0x0000000F */
#define RTC_TR_SU                                 RTC_TR_SU_Msk
#define RTC_TR_SU_0                               (0x1UL<<RTC_TR_SU_Pos)                            /*!< 0x00000001 */
#define RTC_TR_SU_1                               (0x2UL<<RTC_TR_SU_Pos)                            /*!< 0x00000002 */
#define RTC_TR_SU_2                               (0x4UL<<RTC_TR_SU_Pos)                            /*!< 0x00000004 */
#define RTC_TR_SU_3                               (0x8UL<<RTC_TR_SU_Pos)                            /*!< 0x00000008 */
#define RTC_TR_ST_Pos                             (4U)
#define RTC_TR_ST_Msk                             (0x7UL<<RTC_TR_ST_Pos)                            /*!< 0x00000070 */
#define RTC_TR_ST                                 RTC_TR_ST_Msk
#define RTC_TR_ST_0                               (0x1UL<<RTC_TR_ST_Pos)                            /*!< 0x00000010 */
#define RTC_TR_ST_1                               (0x2UL<<RTC_TR_ST_Pos)                            /*!< 0x00000020 */
#define RTC_TR_ST_2                               (0x4UL<<RTC_TR_ST_Pos)                            /*!< 0x00000040 */
#define RTC_TR_MNU_Pos                            (8U)
#define RTC_TR_MNU_Msk                            (0xFUL<<RTC_TR_MNU_Pos)                           /*!< 0x00000F00 */
#define RTC_TR_MNU                                RTC_TR_MNU_Msk
#define RTC_TR_MNU_0                              (0x1UL<<RTC_TR_MNU_Pos)                           /*!< 0x00000100 */
#define RTC_TR_MNU_1                              (0x2UL<<RTC_TR_MNU_Pos)                           /*!< 0x00000200 */
#define RTC_TR_MNU_2                              (0x4UL<<RTC_TR_MNU_Pos)                           /*!< 0x00000400 */
#define RTC_TR_MNU_3                              (0x8UL<<RTC_TR_MNU_Pos)                           /*!< 0x00000800 */
#define RTC_TR_MNT_Pos                            (12U)
#define RTC_TR_MNT_Msk                            (0x7UL<<RTC_TR_MNT_Pos)                           /*!< 0x00007000 */
#define RTC_TR_MNT                                RTC_TR_MNT_Msk
#define RTC_TR_MNT_0                              (0x1UL<<RTC_TR_MNT_Pos)                           /*!< 0x00001000 */
#define RTC_TR_MNT_1                              (0x2UL<<RTC_TR_MNT_Pos)                           /*!< 0x00002000 */
#define RTC_TR_MNT_2                              (0x4UL<<RTC_TR_MNT_Pos)                           /*!< 0x00004000 */
#define RTC_TR_HU_Pos                             (16U)
#define RTC_TR_HU_Msk                             (0xFUL<<RTC_TR_HU_Pos)                            /*!< 0x000F0000 */
#define RTC_TR_HU                                 RTC_TR_HU_Msk
#define RTC_TR_HU_0                               (0x1UL<<RTC_TR_HU_Pos)                            /*!< 0x00010000 */
#define RTC_TR_HU_1                               (0x2UL<<RTC_TR_HU_Pos)                            /*!< 0x00020000 */
#define RTC_TR_HU_2                               (0x4UL<<RTC_TR_HU_Pos)                            /*!< 0x00040000 */
#define RTC_TR_HU_3                               (0x8UL<<RTC_TR_HU_Pos)                            /*!< 0x00080000 */
#define RTC_TR_HT_Pos                             (20U)
#define RTC_TR_HT_Msk                             (0x3UL<<RTC_TR_HT_Pos)                            /*!< 0x00300000 */
#define RTC_TR_HT                                 RTC_TR_HT_Msk
#define RTC_TR_HT_0                               (0x1UL<<RTC_TR_HT_Pos)                            /*!< 0x00100000 */
#define RTC_TR_HT_1                               (0x2UL<<RTC_TR_HT_Pos)                            /*!< 0x00200000 */
#define RTC_TR_PM_Pos                             (22U)
#define RTC_TR_PM_Msk                             (0x1UL<<RTC_TR_PM_Pos)                            /*!< 0x00400000 */
#define RTC_TR_PM                                 RTC_TR_PM_Msk                                     

/********************************* Bit definition for RTC_DR register ***********************************************/
#define RTC_DR_DU_Pos                             (0U)
#define RTC_DR_DU_Msk                             (0xFUL<<RTC_DR_DU_Pos)                            /*!< 0x0000000F */
#define RTC_DR_DU                                 RTC_DR_DU_Msk
#define RTC_DR_DU_0                               (0x1UL<<RTC_DR_DU_Pos)                            /*!< 0x00000001 */
#define RTC_DR_DU_1                               (0x2UL<<RTC_DR_DU_Pos)                            /*!< 0x00000002 */
#define RTC_DR_DU_2                               (0x4UL<<RTC_DR_DU_Pos)                            /*!< 0x00000004 */
#define RTC_DR_DU_3                               (0x8UL<<RTC_DR_DU_Pos)                            /*!< 0x00000008 */
#define RTC_DR_DT_Pos                             (4U)
#define RTC_DR_DT_Msk                             (0x3UL<<RTC_DR_DT_Pos)                            /*!< 0x00000030 */
#define RTC_DR_DT                                 RTC_DR_DT_Msk
#define RTC_DR_DT_0                               (0x1UL<<RTC_DR_DT_Pos)                            /*!< 0x00000010 */
#define RTC_DR_DT_1                               (0x2UL<<RTC_DR_DT_Pos)                            /*!< 0x00000020 */
#define RTC_DR_MU_Pos                             (8U)
#define RTC_DR_MU_Msk                             (0xFUL<<RTC_DR_MU_Pos)                            /*!< 0x00000F00 */
#define RTC_DR_MU                                 RTC_DR_MU_Msk
#define RTC_DR_MU_0                               (0x1UL<<RTC_DR_MU_Pos)                            /*!< 0x00000100 */
#define RTC_DR_MU_1                               (0x2UL<<RTC_DR_MU_Pos)                            /*!< 0x00000200 */
#define RTC_DR_MU_2                               (0x4UL<<RTC_DR_MU_Pos)                            /*!< 0x00000400 */
#define RTC_DR_MU_3                               (0x8UL<<RTC_DR_MU_Pos)                            /*!< 0x00000800 */
#define RTC_DR_MT_Pos                             (12U)
#define RTC_DR_MT_Msk                             (0x1UL<<RTC_DR_MT_Pos)                            /*!< 0x00001000 */
#define RTC_DR_MT                                 RTC_DR_MT_Msk                                     
#define RTC_DR_WDU_Pos                            (13U)
#define RTC_DR_WDU_Msk                            (0x7UL<<RTC_DR_WDU_Pos)                           /*!< 0x0000E000 */
#define RTC_DR_WDU                                RTC_DR_WDU_Msk
#define RTC_DR_WDU_0                              (0x1UL<<RTC_DR_WDU_Pos)                           /*!< 0x00002000 */
#define RTC_DR_WDU_1                              (0x2UL<<RTC_DR_WDU_Pos)                           /*!< 0x00004000 */
#define RTC_DR_WDU_2                              (0x4UL<<RTC_DR_WDU_Pos)                           /*!< 0x00008000 */
#define RTC_DR_YU_Pos                             (16U)
#define RTC_DR_YU_Msk                             (0xFUL<<RTC_DR_YU_Pos)                            /*!< 0x000F0000 */
#define RTC_DR_YU                                 RTC_DR_YU_Msk
#define RTC_DR_YU_0                               (0x1UL<<RTC_DR_YU_Pos)                            /*!< 0x00010000 */
#define RTC_DR_YU_1                               (0x2UL<<RTC_DR_YU_Pos)                            /*!< 0x00020000 */
#define RTC_DR_YU_2                               (0x4UL<<RTC_DR_YU_Pos)                            /*!< 0x00040000 */
#define RTC_DR_YU_3                               (0x8UL<<RTC_DR_YU_Pos)                            /*!< 0x00080000 */
#define RTC_DR_YT_Pos                             (20U)
#define RTC_DR_YT_Msk                             (0xFUL<<RTC_DR_YT_Pos)                            /*!< 0x00F00000 */
#define RTC_DR_YT                                 RTC_DR_YT_Msk
#define RTC_DR_YT_0                               (0x1UL<<RTC_DR_YT_Pos)                            /*!< 0x00100000 */
#define RTC_DR_YT_1                               (0x2UL<<RTC_DR_YT_Pos)                            /*!< 0x00200000 */
#define RTC_DR_YT_2                               (0x4UL<<RTC_DR_YT_Pos)                            /*!< 0x00400000 */
#define RTC_DR_YT_3                               (0x8UL<<RTC_DR_YT_Pos)                            /*!< 0x00800000 */

/********************************* Bit definition for RTC_SSR register **********************************************/
#define RTC_SSR_SS_Pos                            (0U)
#define RTC_SSR_SS_Msk                            (0xFFFFUL<<RTC_SSR_SS_Pos)                        /*!< 0x0000FFFF */
#define RTC_SSR_SS                                RTC_SSR_SS_Msk

/********************************* Bit definition for RTC_ICSR register *********************************************/
#define RTC_ICSR_ALRAWF_Pos                       (0U)
#define RTC_ICSR_ALRAWF_Msk                       (0x1UL<<RTC_ICSR_ALRAWF_Pos)                      /*!< 0x00000001 */
#define RTC_ICSR_ALRAWF                           RTC_ICSR_ALRAWF_Msk                               
#define RTC_ICSR_ALRBWF_Pos                       (1U)
#define RTC_ICSR_ALRBWF_Msk                       (0x1UL<<RTC_ICSR_ALRBWF_Pos)                      /*!< 0x00000002 */
#define RTC_ICSR_ALRBWF                           RTC_ICSR_ALRBWF_Msk                               
#define RTC_ICSR_WUTWF_Pos                        (2U)
#define RTC_ICSR_WUTWF_Msk                        (0x1UL<<RTC_ICSR_WUTWF_Pos)                       /*!< 0x00000004 */
#define RTC_ICSR_WUTWF                            RTC_ICSR_WUTWF_Msk                                
#define RTC_ICSR_SHPF_Pos                         (3U)
#define RTC_ICSR_SHPF_Msk                         (0x1UL<<RTC_ICSR_SHPF_Pos)                        /*!< 0x00000008 */
#define RTC_ICSR_SHPF                             RTC_ICSR_SHPF_Msk                                 
#define RTC_ICSR_INITS_Pos                        (4U)
#define RTC_ICSR_INITS_Msk                        (0x1UL<<RTC_ICSR_INITS_Pos)                       /*!< 0x00000010 */
#define RTC_ICSR_INITS                            RTC_ICSR_INITS_Msk                                
#define RTC_ICSR_RSF_Pos                          (5U)
#define RTC_ICSR_RSF_Msk                          (0x1UL<<RTC_ICSR_RSF_Pos)                         /*!< 0x00000020 */
#define RTC_ICSR_RSF                              RTC_ICSR_RSF_Msk                                  
#define RTC_ICSR_INITF_Pos                        (6U)
#define RTC_ICSR_INITF_Msk                        (0x1UL<<RTC_ICSR_INITF_Pos)                       /*!< 0x00000040 */
#define RTC_ICSR_INITF                            RTC_ICSR_INITF_Msk                                
#define RTC_ICSR_INIT_Pos                         (7U)
#define RTC_ICSR_INIT_Msk                         (0x1UL<<RTC_ICSR_INIT_Pos)                        /*!< 0x00000080 */
#define RTC_ICSR_INIT                             RTC_ICSR_INIT_Msk                                 
#define RTC_ICSR_RECALPF_Pos                      (16U)
#define RTC_ICSR_RECALPF_Msk                      (0x1UL<<RTC_ICSR_RECALPF_Pos)                     /*!< 0x00010000 */
#define RTC_ICSR_RECALPF                          RTC_ICSR_RECALPF_Msk                              

/********************************* Bit definition for RTC_PRER register *********************************************/
#define RTC_PRER_PREDIV_S_Pos                     (0U)
#define RTC_PRER_PREDIV_S_Msk                     (0x7FFFUL<<RTC_PRER_PREDIV_S_Pos)                 /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S                         RTC_PRER_PREDIV_S_Msk
#define RTC_PRER_PREDIV_A_Pos                     (16U)
#define RTC_PRER_PREDIV_A_Msk                     (0x7FUL<<RTC_PRER_PREDIV_A_Pos)                   /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A                         RTC_PRER_PREDIV_A_Msk

/********************************* Bit definition for RTC_WUTR register *********************************************/
#define RTC_WUTR_WUT_Pos                          (0U)
#define RTC_WUTR_WUT_Msk                          (0xFFFFUL<<RTC_WUTR_WUT_Pos)                      /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                              RTC_WUTR_WUT_Msk

/********************************* Bit definition for RTC_CR register ***********************************************/
#define RTC_CR_WUCKSEL_Pos                        (0U)
#define RTC_CR_WUCKSEL_Msk                        (0x7UL<<RTC_CR_WUCKSEL_Pos)                       /*!< 0x00000007 */
#define RTC_CR_WUCKSEL                            RTC_CR_WUCKSEL_Msk
#define RTC_CR_WUCKSEL_0                          (0x1UL<<RTC_CR_WUCKSEL_Pos)                       /*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1                          (0x2UL<<RTC_CR_WUCKSEL_Pos)                       /*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2                          (0x4UL<<RTC_CR_WUCKSEL_Pos)                       /*!< 0x00000004 */
#define RTC_CR_TSEDGE_Pos                         (3U)
#define RTC_CR_TSEDGE_Msk                         (0x1UL<<RTC_CR_TSEDGE_Pos)                        /*!< 0x00000008 */
#define RTC_CR_TSEDGE                             RTC_CR_TSEDGE_Msk                                 
#define RTC_CR_REFCKON_Pos                        (4U)
#define RTC_CR_REFCKON_Msk                        (0x1UL<<RTC_CR_REFCKON_Pos)                       /*!< 0x00000010 */
#define RTC_CR_REFCKON                            RTC_CR_REFCKON_Msk                                
#define RTC_CR_BYPSHAD_Pos                        (5U)
#define RTC_CR_BYPSHAD_Msk                        (0x1UL<<RTC_CR_BYPSHAD_Pos)                       /*!< 0x00000020 */
#define RTC_CR_BYPSHAD                            RTC_CR_BYPSHAD_Msk                                
#define RTC_CR_FMT_Pos                            (6U)
#define RTC_CR_FMT_Msk                            (0x1UL<<RTC_CR_FMT_Pos)                           /*!< 0x00000040 */
#define RTC_CR_FMT                                RTC_CR_FMT_Msk                                    
#define RTC_CR_ALRAE_Pos                          (8U)
#define RTC_CR_ALRAE_Msk                          (0x1UL<<RTC_CR_ALRAE_Pos)                         /*!< 0x00000100 */
#define RTC_CR_ALRAE                              RTC_CR_ALRAE_Msk                                  
#define RTC_CR_ALRBE_Pos                          (9U)
#define RTC_CR_ALRBE_Msk                          (0x1UL<<RTC_CR_ALRBE_Pos)                         /*!< 0x00000200 */
#define RTC_CR_ALRBE                              RTC_CR_ALRBE_Msk                                  
#define RTC_CR_WUTE_Pos                           (10U)
#define RTC_CR_WUTE_Msk                           (0x1UL<<RTC_CR_WUTE_Pos)                          /*!< 0x00000400 */
#define RTC_CR_WUTE                               RTC_CR_WUTE_Msk                                   
#define RTC_CR_TSE_Pos                            (11U)
#define RTC_CR_TSE_Msk                            (0x1UL<<RTC_CR_TSE_Pos)                           /*!< 0x00000800 */
#define RTC_CR_TSE                                RTC_CR_TSE_Msk                                    
#define RTC_CR_ALRAIE_Pos                         (12U)
#define RTC_CR_ALRAIE_Msk                         (0x1UL<<RTC_CR_ALRAIE_Pos)                        /*!< 0x00001000 */
#define RTC_CR_ALRAIE                             RTC_CR_ALRAIE_Msk                                 
#define RTC_CR_ALRBIE_Pos                         (13U)
#define RTC_CR_ALRBIE_Msk                         (0x1UL<<RTC_CR_ALRBIE_Pos)                        /*!< 0x00002000 */
#define RTC_CR_ALRBIE                             RTC_CR_ALRBIE_Msk                                 
#define RTC_CR_WUTIE_Pos                          (14U)
#define RTC_CR_WUTIE_Msk                          (0x1UL<<RTC_CR_WUTIE_Pos)                         /*!< 0x00004000 */
#define RTC_CR_WUTIE                              RTC_CR_WUTIE_Msk                                  
#define RTC_CR_TSIE_Pos                           (15U)
#define RTC_CR_TSIE_Msk                           (0x1UL<<RTC_CR_TSIE_Pos)                          /*!< 0x00008000 */
#define RTC_CR_TSIE                               RTC_CR_TSIE_Msk                                   
#define RTC_CR_ADD1H_Pos                          (16U)
#define RTC_CR_ADD1H_Msk                          (0x1UL<<RTC_CR_ADD1H_Pos)                         /*!< 0x00010000 */
#define RTC_CR_ADD1H                              RTC_CR_ADD1H_Msk                                  
#define RTC_CR_SUB1H_Pos                          (17U)
#define RTC_CR_SUB1H_Msk                          (0x1UL<<RTC_CR_SUB1H_Pos)                         /*!< 0x00020000 */
#define RTC_CR_SUB1H                              RTC_CR_SUB1H_Msk                                  
#define RTC_CR_BKP_Pos                            (18U)
#define RTC_CR_BKP_Msk                            (0x1UL<<RTC_CR_BKP_Pos)                           /*!< 0x00040000 */
#define RTC_CR_BKP                                RTC_CR_BKP_Msk                                    
#define RTC_CR_COSEL_Pos                          (19U)
#define RTC_CR_COSEL_Msk                          (0x1UL<<RTC_CR_COSEL_Pos)                         /*!< 0x00080000 */
#define RTC_CR_COSEL                              RTC_CR_COSEL_Msk                                  
#define RTC_CR_POL_Pos                            (20U)
#define RTC_CR_POL_Msk                            (0x1UL<<RTC_CR_POL_Pos)                           /*!< 0x00100000 */
#define RTC_CR_POL                                RTC_CR_POL_Msk                                    
#define RTC_CR_OSEL_Pos                           (21U)
#define RTC_CR_OSEL_Msk                           (0x3UL<<RTC_CR_OSEL_Pos)                          /*!< 0x00600000 */
#define RTC_CR_OSEL                               RTC_CR_OSEL_Msk
#define RTC_CR_OSEL_0                             (0x1UL<<RTC_CR_OSEL_Pos)                          /*!< 0x00200000 */
#define RTC_CR_OSEL_1                             (0x2UL<<RTC_CR_OSEL_Pos)                          /*!< 0x00400000 */
#define RTC_CR_COE_Pos                            (23U)
#define RTC_CR_COE_Msk                            (0x1UL<<RTC_CR_COE_Pos)                           /*!< 0x00800000 */
#define RTC_CR_COE                                RTC_CR_COE_Msk                                    
#define RTC_CR_ITSE_Pos                           (24U)
#define RTC_CR_ITSE_Msk                           (0x1UL<<RTC_CR_ITSE_Pos)                          /*!< 0x01000000 */
#define RTC_CR_ITSE                               RTC_CR_ITSE_Msk                                   
#define RTC_CR_TAMPTS_Pos                         (25U)
#define RTC_CR_TAMPTS_Msk                         (0x1UL<<RTC_CR_TAMPTS_Pos)                        /*!< 0x02000000 */
#define RTC_CR_TAMPTS                             RTC_CR_TAMPTS_Msk                                 
#define RTC_CR_TAMPOE_Pos                         (26U)
#define RTC_CR_TAMPOE_Msk                         (0x1UL<<RTC_CR_TAMPOE_Pos)                        /*!< 0x04000000 */
#define RTC_CR_TAMPOE                             RTC_CR_TAMPOE_Msk                                 
#define RTC_CR_TAMPALRM_PU_Pos                    (29U)
#define RTC_CR_TAMPALRM_PU_Msk                    (0x1UL<<RTC_CR_TAMPALRM_PU_Pos)                   /*!< 0x20000000 */
#define RTC_CR_TAMPALRM_PU                        RTC_CR_TAMPALRM_PU_Msk                            
#define RTC_CR_TAMPALRM_TYPE_Pos                  (30U)
#define RTC_CR_TAMPALRM_TYPE_Msk                  (0x1UL<<RTC_CR_TAMPALRM_TYPE_Pos)                 /*!< 0x40000000 */
#define RTC_CR_TAMPALRM_TYPE                      RTC_CR_TAMPALRM_TYPE_Msk                          

/********************************* Bit definition for RTC_WPR register **********************************************/
#define RTC_WPR_KEY_Pos                           (0U)
#define RTC_WPR_KEY_Msk                           (0xFFUL<<RTC_WPR_KEY_Pos)                         /*!< 0x000000FF */
#define RTC_WPR_KEY                               RTC_WPR_KEY_Msk

/********************************* Bit definition for RTC_CALR register *********************************************/
#define RTC_CALR_CALM_Pos                         (0U)
#define RTC_CALR_CALM_Msk                         (0x1FFUL<<RTC_CALR_CALM_Pos)                      /*!< 0x000001FF */
#define RTC_CALR_CALM                             RTC_CALR_CALM_Msk
#define RTC_CALR_CALW16_Pos                       (13U)
#define RTC_CALR_CALW16_Msk                       (0x1UL<<RTC_CALR_CALW16_Pos)                      /*!< 0x00002000 */
#define RTC_CALR_CALW16                           RTC_CALR_CALW16_Msk                               
#define RTC_CALR_CALW8_Pos                        (14U)
#define RTC_CALR_CALW8_Msk                        (0x1UL<<RTC_CALR_CALW8_Pos)                       /*!< 0x00004000 */
#define RTC_CALR_CALW8                            RTC_CALR_CALW8_Msk                                
#define RTC_CALR_CALP_Pos                         (15U)
#define RTC_CALR_CALP_Msk                         (0x1UL<<RTC_CALR_CALP_Pos)                        /*!< 0x00008000 */
#define RTC_CALR_CALP                             RTC_CALR_CALP_Msk                                 

/********************************* Bit definition for RTC_SHIFTR register *******************************************/
#define RTC_SHIFTR_SUBFS_Pos                      (0U)
#define RTC_SHIFTR_SUBFS_Msk                      (0x7FFFUL<<RTC_SHIFTR_SUBFS_Pos)                  /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS                          RTC_SHIFTR_SUBFS_Msk
#define RTC_SHIFTR_ADD1S_Pos                      (31U)
#define RTC_SHIFTR_ADD1S_Msk                      (0x1UL<<RTC_SHIFTR_ADD1S_Pos)                     /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S                          RTC_SHIFTR_ADD1S_Msk                              

/********************************* Bit definition for RTC_TSTR register *********************************************/
#define RTC_TSTR_SU_Pos                           (0U)
#define RTC_TSTR_SU_Msk                           (0xFUL<<RTC_TSTR_SU_Pos)                          /*!< 0x0000000F */
#define RTC_TSTR_SU                               RTC_TSTR_SU_Msk
#define RTC_TSTR_SU_0                             (0x1UL<<RTC_TSTR_SU_Pos)                          /*!< 0x00000001 */
#define RTC_TSTR_SU_1                             (0x2UL<<RTC_TSTR_SU_Pos)                          /*!< 0x00000002 */
#define RTC_TSTR_SU_2                             (0x4UL<<RTC_TSTR_SU_Pos)                          /*!< 0x00000004 */
#define RTC_TSTR_SU_3                             (0x8UL<<RTC_TSTR_SU_Pos)                          /*!< 0x00000008 */
#define RTC_TSTR_ST_Pos                           (4U)
#define RTC_TSTR_ST_Msk                           (0x7UL<<RTC_TSTR_ST_Pos)                          /*!< 0x00000070 */
#define RTC_TSTR_ST                               RTC_TSTR_ST_Msk
#define RTC_TSTR_ST_0                             (0x1UL<<RTC_TSTR_ST_Pos)                          /*!< 0x00000010 */
#define RTC_TSTR_ST_1                             (0x2UL<<RTC_TSTR_ST_Pos)                          /*!< 0x00000020 */
#define RTC_TSTR_ST_2                             (0x4UL<<RTC_TSTR_ST_Pos)                          /*!< 0x00000040 */
#define RTC_TSTR_MNU_Pos                          (8U)
#define RTC_TSTR_MNU_Msk                          (0xFUL<<RTC_TSTR_MNU_Pos)                         /*!< 0x00000F00 */
#define RTC_TSTR_MNU                              RTC_TSTR_MNU_Msk
#define RTC_TSTR_MNU_0                            (0x1UL<<RTC_TSTR_MNU_Pos)                         /*!< 0x00000100 */
#define RTC_TSTR_MNU_1                            (0x2UL<<RTC_TSTR_MNU_Pos)                         /*!< 0x00000200 */
#define RTC_TSTR_MNU_2                            (0x4UL<<RTC_TSTR_MNU_Pos)                         /*!< 0x00000400 */
#define RTC_TSTR_MNU_3                            (0x8UL<<RTC_TSTR_MNU_Pos)                         /*!< 0x00000800 */
#define RTC_TSTR_MNT_Pos                          (12U)
#define RTC_TSTR_MNT_Msk                          (0x7UL<<RTC_TSTR_MNT_Pos)                         /*!< 0x00007000 */
#define RTC_TSTR_MNT                              RTC_TSTR_MNT_Msk
#define RTC_TSTR_MNT_0                            (0x1UL<<RTC_TSTR_MNT_Pos)                         /*!< 0x00001000 */
#define RTC_TSTR_MNT_1                            (0x2UL<<RTC_TSTR_MNT_Pos)                         /*!< 0x00002000 */
#define RTC_TSTR_MNT_2                            (0x4UL<<RTC_TSTR_MNT_Pos)                         /*!< 0x00004000 */
#define RTC_TSTR_HU_Pos                           (16U)
#define RTC_TSTR_HU_Msk                           (0xFUL<<RTC_TSTR_HU_Pos)                          /*!< 0x000F0000 */
#define RTC_TSTR_HU                               RTC_TSTR_HU_Msk
#define RTC_TSTR_HU_0                             (0x1UL<<RTC_TSTR_HU_Pos)                          /*!< 0x00010000 */
#define RTC_TSTR_HU_1                             (0x2UL<<RTC_TSTR_HU_Pos)                          /*!< 0x00020000 */
#define RTC_TSTR_HU_2                             (0x4UL<<RTC_TSTR_HU_Pos)                          /*!< 0x00040000 */
#define RTC_TSTR_HU_3                             (0x8UL<<RTC_TSTR_HU_Pos)                          /*!< 0x00080000 */
#define RTC_TSTR_HT_Pos                           (20U)
#define RTC_TSTR_HT_Msk                           (0x3UL<<RTC_TSTR_HT_Pos)                          /*!< 0x00300000 */
#define RTC_TSTR_HT                               RTC_TSTR_HT_Msk
#define RTC_TSTR_HT_0                             (0x1UL<<RTC_TSTR_HT_Pos)                          /*!< 0x00100000 */
#define RTC_TSTR_HT_1                             (0x2UL<<RTC_TSTR_HT_Pos)                          /*!< 0x00200000 */
#define RTC_TSTR_PM_Pos                           (22U)
#define RTC_TSTR_PM_Msk                           (0x1UL<<RTC_TSTR_PM_Pos)                          /*!< 0x00400000 */
#define RTC_TSTR_PM                               RTC_TSTR_PM_Msk                                   

/********************************* Bit definition for RTC_TSDR register *********************************************/
#define RTC_TSDR_DU_Pos                           (0U)
#define RTC_TSDR_DU_Msk                           (0xFUL<<RTC_TSDR_DU_Pos)                          /*!< 0x0000000F */
#define RTC_TSDR_DU                               RTC_TSDR_DU_Msk
#define RTC_TSDR_DU_0                             (0x1UL<<RTC_TSDR_DU_Pos)                          /*!< 0x00000001 */
#define RTC_TSDR_DU_1                             (0x2UL<<RTC_TSDR_DU_Pos)                          /*!< 0x00000002 */
#define RTC_TSDR_DU_2                             (0x4UL<<RTC_TSDR_DU_Pos)                          /*!< 0x00000004 */
#define RTC_TSDR_DU_3                             (0x8UL<<RTC_TSDR_DU_Pos)                          /*!< 0x00000008 */
#define RTC_TSDR_DT_Pos                           (4U)
#define RTC_TSDR_DT_Msk                           (0x3UL<<RTC_TSDR_DT_Pos)                          /*!< 0x00000030 */
#define RTC_TSDR_DT                               RTC_TSDR_DT_Msk
#define RTC_TSDR_DT_0                             (0x1UL<<RTC_TSDR_DT_Pos)                          /*!< 0x00000010 */
#define RTC_TSDR_DT_1                             (0x2UL<<RTC_TSDR_DT_Pos)                          /*!< 0x00000020 */
#define RTC_TSDR_MU_Pos                           (8U)
#define RTC_TSDR_MU_Msk                           (0xFUL<<RTC_TSDR_MU_Pos)                          /*!< 0x00000F00 */
#define RTC_TSDR_MU                               RTC_TSDR_MU_Msk
#define RTC_TSDR_MU_0                             (0x1UL<<RTC_TSDR_MU_Pos)                          /*!< 0x00000100 */
#define RTC_TSDR_MU_1                             (0x2UL<<RTC_TSDR_MU_Pos)                          /*!< 0x00000200 */
#define RTC_TSDR_MU_2                             (0x4UL<<RTC_TSDR_MU_Pos)                          /*!< 0x00000400 */
#define RTC_TSDR_MU_3                             (0x8UL<<RTC_TSDR_MU_Pos)                          /*!< 0x00000800 */
#define RTC_TSDR_MT_Pos                           (12U)
#define RTC_TSDR_MT_Msk                           (0x1UL<<RTC_TSDR_MT_Pos)                          /*!< 0x00001000 */
#define RTC_TSDR_MT                               RTC_TSDR_MT_Msk                                   
#define RTC_TSDR_WDU_Pos                          (13U)
#define RTC_TSDR_WDU_Msk                          (0x7UL<<RTC_TSDR_WDU_Pos)                         /*!< 0x0000E000 */
#define RTC_TSDR_WDU                              RTC_TSDR_WDU_Msk
#define RTC_TSDR_WDU_0                            (0x1UL<<RTC_TSDR_WDU_Pos)                         /*!< 0x00002000 */
#define RTC_TSDR_WDU_1                            (0x2UL<<RTC_TSDR_WDU_Pos)                         /*!< 0x00004000 */
#define RTC_TSDR_WDU_2                            (0x4UL<<RTC_TSDR_WDU_Pos)                         /*!< 0x00008000 */

/********************************* Bit definition for RTC_TSSSR register ********************************************/
#define RTC_TSSSR_SS_Pos                          (0U)
#define RTC_TSSSR_SS_Msk                          (0xFFFFUL<<RTC_TSSSR_SS_Pos)                      /*!< 0x0000FFFF */
#define RTC_TSSSR_SS                              RTC_TSSSR_SS_Msk

/********************************* Bit definition for RTC_ALRMAR register *******************************************/
#define RTC_ALRMAR_SU_Pos                         (0U)
#define RTC_ALRMAR_SU_Msk                         (0xFUL<<RTC_ALRMAR_SU_Pos)                        /*!< 0x0000000F */
#define RTC_ALRMAR_SU                             RTC_ALRMAR_SU_Msk
#define RTC_ALRMAR_SU_0                           (0x1UL<<RTC_ALRMAR_SU_Pos)                        /*!< 0x00000001 */
#define RTC_ALRMAR_SU_1                           (0x2UL<<RTC_ALRMAR_SU_Pos)                        /*!< 0x00000002 */
#define RTC_ALRMAR_SU_2                           (0x4UL<<RTC_ALRMAR_SU_Pos)                        /*!< 0x00000004 */
#define RTC_ALRMAR_SU_3                           (0x8UL<<RTC_ALRMAR_SU_Pos)                        /*!< 0x00000008 */
#define RTC_ALRMAR_ST_Pos                         (4U)
#define RTC_ALRMAR_ST_Msk                         (0x7UL<<RTC_ALRMAR_ST_Pos)                        /*!< 0x00000070 */
#define RTC_ALRMAR_ST                             RTC_ALRMAR_ST_Msk
#define RTC_ALRMAR_ST_0                           (0x1UL<<RTC_ALRMAR_ST_Pos)                        /*!< 0x00000010 */
#define RTC_ALRMAR_ST_1                           (0x2UL<<RTC_ALRMAR_ST_Pos)                        /*!< 0x00000020 */
#define RTC_ALRMAR_ST_2                           (0x4UL<<RTC_ALRMAR_ST_Pos)                        /*!< 0x00000040 */
#define RTC_ALRMAR_MSK1_Pos                       (7U)
#define RTC_ALRMAR_MSK1_Msk                       (0x1UL<<RTC_ALRMAR_MSK1_Pos)                      /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1                           RTC_ALRMAR_MSK1_Msk                               
#define RTC_ALRMAR_MNU_Pos                        (8U)
#define RTC_ALRMAR_MNU_Msk                        (0xFUL<<RTC_ALRMAR_MNU_Pos)                       /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU                            RTC_ALRMAR_MNU_Msk
#define RTC_ALRMAR_MNU_0                          (0x1UL<<RTC_ALRMAR_MNU_Pos)                       /*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1                          (0x2UL<<RTC_ALRMAR_MNU_Pos)                       /*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2                          (0x4UL<<RTC_ALRMAR_MNU_Pos)                       /*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3                          (0x8UL<<RTC_ALRMAR_MNU_Pos)                       /*!< 0x00000800 */
#define RTC_ALRMAR_MNT_Pos                        (12U)
#define RTC_ALRMAR_MNT_Msk                        (0x7UL<<RTC_ALRMAR_MNT_Pos)                       /*!< 0x00007000 */
#define RTC_ALRMAR_MNT                            RTC_ALRMAR_MNT_Msk
#define RTC_ALRMAR_MNT_0                          (0x1UL<<RTC_ALRMAR_MNT_Pos)                       /*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1                          (0x2UL<<RTC_ALRMAR_MNT_Pos)                       /*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2                          (0x4UL<<RTC_ALRMAR_MNT_Pos)                       /*!< 0x00004000 */
#define RTC_ALRMAR_MSK2_Pos                       (15U)
#define RTC_ALRMAR_MSK2_Msk                       (0x1UL<<RTC_ALRMAR_MSK2_Pos)                      /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2                           RTC_ALRMAR_MSK2_Msk                               
#define RTC_ALRMAR_HU_Pos                         (16U)
#define RTC_ALRMAR_HU_Msk                         (0xFUL<<RTC_ALRMAR_HU_Pos)                        /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                             RTC_ALRMAR_HU_Msk
#define RTC_ALRMAR_HU_0                           (0x1UL<<RTC_ALRMAR_HU_Pos)                        /*!< 0x00010000 */
#define RTC_ALRMAR_HU_1                           (0x2UL<<RTC_ALRMAR_HU_Pos)                        /*!< 0x00020000 */
#define RTC_ALRMAR_HU_2                           (0x4UL<<RTC_ALRMAR_HU_Pos)                        /*!< 0x00040000 */
#define RTC_ALRMAR_HU_3                           (0x8UL<<RTC_ALRMAR_HU_Pos)                        /*!< 0x00080000 */
#define RTC_ALRMAR_HT_Pos                         (20U)
#define RTC_ALRMAR_HT_Msk                         (0x3UL<<RTC_ALRMAR_HT_Pos)                        /*!< 0x00300000 */
#define RTC_ALRMAR_HT                             RTC_ALRMAR_HT_Msk
#define RTC_ALRMAR_HT_0                           (0x1UL<<RTC_ALRMAR_HT_Pos)                        /*!< 0x00100000 */
#define RTC_ALRMAR_HT_1                           (0x2UL<<RTC_ALRMAR_HT_Pos)                        /*!< 0x00200000 */
#define RTC_ALRMAR_PM_Pos                         (22U)
#define RTC_ALRMAR_PM_Msk                         (0x1UL<<RTC_ALRMAR_PM_Pos)                        /*!< 0x00400000 */
#define RTC_ALRMAR_PM                             RTC_ALRMAR_PM_Msk                                 
#define RTC_ALRMAR_MSK3_Pos                       (23U)
#define RTC_ALRMAR_MSK3_Msk                       (0x1UL<<RTC_ALRMAR_MSK3_Pos)                      /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3                           RTC_ALRMAR_MSK3_Msk                               
#define RTC_ALRMAR_DU_Pos                         (24U)
#define RTC_ALRMAR_DU_Msk                         (0xFUL<<RTC_ALRMAR_DU_Pos)                        /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                             RTC_ALRMAR_DU_Msk
#define RTC_ALRMAR_DU_0                           (0x1UL<<RTC_ALRMAR_DU_Pos)                        /*!< 0x01000000 */
#define RTC_ALRMAR_DU_1                           (0x2UL<<RTC_ALRMAR_DU_Pos)                        /*!< 0x02000000 */
#define RTC_ALRMAR_DU_2                           (0x4UL<<RTC_ALRMAR_DU_Pos)                        /*!< 0x04000000 */
#define RTC_ALRMAR_DU_3                           (0x8UL<<RTC_ALRMAR_DU_Pos)                        /*!< 0x08000000 */
#define RTC_ALRMAR_DT_Pos                         (28U)
#define RTC_ALRMAR_DT_Msk                         (0x3UL<<RTC_ALRMAR_DT_Pos)                        /*!< 0x30000000 */
#define RTC_ALRMAR_DT                             RTC_ALRMAR_DT_Msk
#define RTC_ALRMAR_DT_0                           (0x1UL<<RTC_ALRMAR_DT_Pos)                        /*!< 0x10000000 */
#define RTC_ALRMAR_DT_1                           (0x2UL<<RTC_ALRMAR_DT_Pos)                        /*!< 0x20000000 */
#define RTC_ALRMAR_WDSEL_Pos                      (30U)
#define RTC_ALRMAR_WDSEL_Msk                      (0x1UL<<RTC_ALRMAR_WDSEL_Pos)                     /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL                          RTC_ALRMAR_WDSEL_Msk                              
#define RTC_ALRMAR_MSK4_Pos                       (31U)
#define RTC_ALRMAR_MSK4_Msk                       (0x1UL<<RTC_ALRMAR_MSK4_Pos)                      /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4                           RTC_ALRMAR_MSK4_Msk                               

/********************************* Bit definition for RTC_ALRMASSR register *****************************************/
#define RTC_ALRMASSR_SS_Pos                       (0U)
#define RTC_ALRMASSR_SS_Msk                       (0x7FFFUL<<RTC_ALRMASSR_SS_Pos)                   /*!< 0x00007FFF */
#define RTC_ALRMASSR_SS                           RTC_ALRMASSR_SS_Msk
#define RTC_ALRMASSR_MASKSS_Pos                   (24U)
#define RTC_ALRMASSR_MASKSS_Msk                   (0xFUL<<RTC_ALRMASSR_MASKSS_Pos)                  /*!< 0x0F000000 */
#define RTC_ALRMASSR_MASKSS                       RTC_ALRMASSR_MASKSS_Msk
#define RTC_ALRMASSR_MASKSS_0                     (0x1UL<<RTC_ALRMASSR_MASKSS_Pos)                  /*!< 0x01000000 */
#define RTC_ALRMASSR_MASKSS_1                     (0x2UL<<RTC_ALRMASSR_MASKSS_Pos)                  /*!< 0x02000000 */
#define RTC_ALRMASSR_MASKSS_2                     (0x4UL<<RTC_ALRMASSR_MASKSS_Pos)                  /*!< 0x04000000 */
#define RTC_ALRMASSR_MASKSS_3                     (0x8UL<<RTC_ALRMASSR_MASKSS_Pos)                  /*!< 0x08000000 */

/********************************* Bit definition for RTC_ALRMBR register *******************************************/
#define RTC_ALRMBR_SU_Pos                         (0U)
#define RTC_ALRMBR_SU_Msk                         (0xFUL<<RTC_ALRMBR_SU_Pos)                        /*!< 0x0000000F */
#define RTC_ALRMBR_SU                             RTC_ALRMBR_SU_Msk
#define RTC_ALRMBR_SU_0                           (0x1UL<<RTC_ALRMBR_SU_Pos)                        /*!< 0x00000001 */
#define RTC_ALRMBR_SU_1                           (0x2UL<<RTC_ALRMBR_SU_Pos)                        /*!< 0x00000002 */
#define RTC_ALRMBR_SU_2                           (0x4UL<<RTC_ALRMBR_SU_Pos)                        /*!< 0x00000004 */
#define RTC_ALRMBR_SU_3                           (0x8UL<<RTC_ALRMBR_SU_Pos)                        /*!< 0x00000008 */
#define RTC_ALRMBR_ST_Pos                         (4U)
#define RTC_ALRMBR_ST_Msk                         (0x7UL<<RTC_ALRMBR_ST_Pos)                        /*!< 0x00000070 */
#define RTC_ALRMBR_ST                             RTC_ALRMBR_ST_Msk
#define RTC_ALRMBR_ST_0                           (0x1UL<<RTC_ALRMBR_ST_Pos)                        /*!< 0x00000010 */
#define RTC_ALRMBR_ST_1                           (0x2UL<<RTC_ALRMBR_ST_Pos)                        /*!< 0x00000020 */
#define RTC_ALRMBR_ST_2                           (0x4UL<<RTC_ALRMBR_ST_Pos)                        /*!< 0x00000040 */
#define RTC_ALRMBR_MSK1_Pos                       (7U)
#define RTC_ALRMBR_MSK1_Msk                       (0x1UL<<RTC_ALRMBR_MSK1_Pos)                      /*!< 0x00000080 */
#define RTC_ALRMBR_MSK1                           RTC_ALRMBR_MSK1_Msk                               
#define RTC_ALRMBR_MNU_Pos                        (8U)
#define RTC_ALRMBR_MNU_Msk                        (0xFUL<<RTC_ALRMBR_MNU_Pos)                       /*!< 0x00000F00 */
#define RTC_ALRMBR_MNU                            RTC_ALRMBR_MNU_Msk
#define RTC_ALRMBR_MNU_0                          (0x1UL<<RTC_ALRMBR_MNU_Pos)                       /*!< 0x00000100 */
#define RTC_ALRMBR_MNU_1                          (0x2UL<<RTC_ALRMBR_MNU_Pos)                       /*!< 0x00000200 */
#define RTC_ALRMBR_MNU_2                          (0x4UL<<RTC_ALRMBR_MNU_Pos)                       /*!< 0x00000400 */
#define RTC_ALRMBR_MNU_3                          (0x8UL<<RTC_ALRMBR_MNU_Pos)                       /*!< 0x00000800 */
#define RTC_ALRMBR_MNT_Pos                        (12U)
#define RTC_ALRMBR_MNT_Msk                        (0x7UL<<RTC_ALRMBR_MNT_Pos)                       /*!< 0x00007000 */
#define RTC_ALRMBR_MNT                            RTC_ALRMBR_MNT_Msk
#define RTC_ALRMBR_MNT_0                          (0x1UL<<RTC_ALRMBR_MNT_Pos)                       /*!< 0x00001000 */
#define RTC_ALRMBR_MNT_1                          (0x2UL<<RTC_ALRMBR_MNT_Pos)                       /*!< 0x00002000 */
#define RTC_ALRMBR_MNT_2                          (0x4UL<<RTC_ALRMBR_MNT_Pos)                       /*!< 0x00004000 */
#define RTC_ALRMBR_MSK2_Pos                       (15U)
#define RTC_ALRMBR_MSK2_Msk                       (0x1UL<<RTC_ALRMBR_MSK2_Pos)                      /*!< 0x00008000 */
#define RTC_ALRMBR_MSK2                           RTC_ALRMBR_MSK2_Msk                               
#define RTC_ALRMBR_HU_Pos                         (16U)
#define RTC_ALRMBR_HU_Msk                         (0xFUL<<RTC_ALRMBR_HU_Pos)                        /*!< 0x000F0000 */
#define RTC_ALRMBR_HU                             RTC_ALRMBR_HU_Msk
#define RTC_ALRMBR_HU_0                           (0x1UL<<RTC_ALRMBR_HU_Pos)                        /*!< 0x00010000 */
#define RTC_ALRMBR_HU_1                           (0x2UL<<RTC_ALRMBR_HU_Pos)                        /*!< 0x00020000 */
#define RTC_ALRMBR_HU_2                           (0x4UL<<RTC_ALRMBR_HU_Pos)                        /*!< 0x00040000 */
#define RTC_ALRMBR_HU_3                           (0x8UL<<RTC_ALRMBR_HU_Pos)                        /*!< 0x00080000 */
#define RTC_ALRMBR_HT_Pos                         (20U)
#define RTC_ALRMBR_HT_Msk                         (0x3UL<<RTC_ALRMBR_HT_Pos)                        /*!< 0x00300000 */
#define RTC_ALRMBR_HT                             RTC_ALRMBR_HT_Msk
#define RTC_ALRMBR_HT_0                           (0x1UL<<RTC_ALRMBR_HT_Pos)                        /*!< 0x00100000 */
#define RTC_ALRMBR_HT_1                           (0x2UL<<RTC_ALRMBR_HT_Pos)                        /*!< 0x00200000 */
#define RTC_ALRMBR_PM_Pos                         (22U)
#define RTC_ALRMBR_PM_Msk                         (0x1UL<<RTC_ALRMBR_PM_Pos)                        /*!< 0x00400000 */
#define RTC_ALRMBR_PM                             RTC_ALRMBR_PM_Msk                                 
#define RTC_ALRMBR_MSK3_Pos                       (23U)
#define RTC_ALRMBR_MSK3_Msk                       (0x1UL<<RTC_ALRMBR_MSK3_Pos)                      /*!< 0x00800000 */
#define RTC_ALRMBR_MSK3                           RTC_ALRMBR_MSK3_Msk                               
#define RTC_ALRMBR_DU_Pos                         (24U)
#define RTC_ALRMBR_DU_Msk                         (0xFUL<<RTC_ALRMBR_DU_Pos)                        /*!< 0x0F000000 */
#define RTC_ALRMBR_DU                             RTC_ALRMBR_DU_Msk
#define RTC_ALRMBR_DU_0                           (0x1UL<<RTC_ALRMBR_DU_Pos)                        /*!< 0x01000000 */
#define RTC_ALRMBR_DU_1                           (0x2UL<<RTC_ALRMBR_DU_Pos)                        /*!< 0x02000000 */
#define RTC_ALRMBR_DU_2                           (0x4UL<<RTC_ALRMBR_DU_Pos)                        /*!< 0x04000000 */
#define RTC_ALRMBR_DU_3                           (0x8UL<<RTC_ALRMBR_DU_Pos)                        /*!< 0x08000000 */
#define RTC_ALRMBR_DT_Pos                         (28U)
#define RTC_ALRMBR_DT_Msk                         (0x3UL<<RTC_ALRMBR_DT_Pos)                        /*!< 0x30000000 */
#define RTC_ALRMBR_DT                             RTC_ALRMBR_DT_Msk
#define RTC_ALRMBR_DT_0                           (0x1UL<<RTC_ALRMBR_DT_Pos)                        /*!< 0x10000000 */
#define RTC_ALRMBR_DT_1                           (0x2UL<<RTC_ALRMBR_DT_Pos)                        /*!< 0x20000000 */
#define RTC_ALRMBR_WDSEL_Pos                      (30U)
#define RTC_ALRMBR_WDSEL_Msk                      (0x1UL<<RTC_ALRMBR_WDSEL_Pos)                     /*!< 0x40000000 */
#define RTC_ALRMBR_WDSEL                          RTC_ALRMBR_WDSEL_Msk                              
#define RTC_ALRMBR_MSK4_Pos                       (31U)
#define RTC_ALRMBR_MSK4_Msk                       (0x1UL<<RTC_ALRMBR_MSK4_Pos)                      /*!< 0x80000000 */
#define RTC_ALRMBR_MSK4                           RTC_ALRMBR_MSK4_Msk                               

/********************************* Bit definition for RTC_ALRMBSSR register *****************************************/
#define RTC_ALRMBSSR_SS_Pos                       (0U)
#define RTC_ALRMBSSR_SS_Msk                       (0x7FFFUL<<RTC_ALRMBSSR_SS_Pos)                   /*!< 0x00007FFF */
#define RTC_ALRMBSSR_SS                           RTC_ALRMBSSR_SS_Msk
#define RTC_ALRMBSSR_MASKSS_Pos                   (24U)
#define RTC_ALRMBSSR_MASKSS_Msk                   (0xFUL<<RTC_ALRMBSSR_MASKSS_Pos)                  /*!< 0x0F000000 */
#define RTC_ALRMBSSR_MASKSS                       RTC_ALRMBSSR_MASKSS_Msk
#define RTC_ALRMBSSR_MASKSS_0                     (0x1UL<<RTC_ALRMBSSR_MASKSS_Pos)                  /*!< 0x01000000 */
#define RTC_ALRMBSSR_MASKSS_1                     (0x2UL<<RTC_ALRMBSSR_MASKSS_Pos)                  /*!< 0x02000000 */
#define RTC_ALRMBSSR_MASKSS_2                     (0x4UL<<RTC_ALRMBSSR_MASKSS_Pos)                  /*!< 0x04000000 */
#define RTC_ALRMBSSR_MASKSS_3                     (0x8UL<<RTC_ALRMBSSR_MASKSS_Pos)                  /*!< 0x08000000 */

/********************************* Bit definition for RTC_SR register ***********************************************/
#define RTC_SR_ALRAF_Pos                          (0U)
#define RTC_SR_ALRAF_Msk                          (0x1UL<<RTC_SR_ALRAF_Pos)                         /*!< 0x00000001 */
#define RTC_SR_ALRAF                              RTC_SR_ALRAF_Msk                                  
#define RTC_SR_ALRBF_Pos                          (1U)
#define RTC_SR_ALRBF_Msk                          (0x1UL<<RTC_SR_ALRBF_Pos)                         /*!< 0x00000002 */
#define RTC_SR_ALRBF                              RTC_SR_ALRBF_Msk                                  
#define RTC_SR_WUTF_Pos                           (2U)
#define RTC_SR_WUTF_Msk                           (0x1UL<<RTC_SR_WUTF_Pos)                          /*!< 0x00000004 */
#define RTC_SR_WUTF                               RTC_SR_WUTF_Msk                                   
#define RTC_SR_TSF_Pos                            (3U)
#define RTC_SR_TSF_Msk                            (0x1UL<<RTC_SR_TSF_Pos)                           /*!< 0x00000008 */
#define RTC_SR_TSF                                RTC_SR_TSF_Msk                                    
#define RTC_SR_TSOVF_Pos                          (4U)
#define RTC_SR_TSOVF_Msk                          (0x1UL<<RTC_SR_TSOVF_Pos)                         /*!< 0x00000010 */
#define RTC_SR_TSOVF                              RTC_SR_TSOVF_Msk                                  
#define RTC_SR_ITSF_Pos                           (5U)
#define RTC_SR_ITSF_Msk                           (0x1UL<<RTC_SR_ITSF_Pos)                          /*!< 0x00000020 */
#define RTC_SR_ITSF                               RTC_SR_ITSF_Msk                                   

/********************************* Bit definition for RTC_MISR register *********************************************/
#define RTC_MISR_ALRAMF_Pos                       (0U)
#define RTC_MISR_ALRAMF_Msk                       (0x1UL<<RTC_MISR_ALRAMF_Pos)                      /*!< 0x00000001 */
#define RTC_MISR_ALRAMF                           RTC_MISR_ALRAMF_Msk                               
#define RTC_MISR_ALRBMF_Pos                       (1U)
#define RTC_MISR_ALRBMF_Msk                       (0x1UL<<RTC_MISR_ALRBMF_Pos)                      /*!< 0x00000002 */
#define RTC_MISR_ALRBMF                           RTC_MISR_ALRBMF_Msk                               
#define RTC_MISR_WUTMF_Pos                        (2U)
#define RTC_MISR_WUTMF_Msk                        (0x1UL<<RTC_MISR_WUTMF_Pos)                       /*!< 0x00000004 */
#define RTC_MISR_WUTMF                            RTC_MISR_WUTMF_Msk                                
#define RTC_MISR_TSMF_Pos                         (3U)
#define RTC_MISR_TSMF_Msk                         (0x1UL<<RTC_MISR_TSMF_Pos)                        /*!< 0x00000008 */
#define RTC_MISR_TSMF                             RTC_MISR_TSMF_Msk                                 
#define RTC_MISR_TSOVMF_Pos                       (4U)
#define RTC_MISR_TSOVMF_Msk                       (0x1UL<<RTC_MISR_TSOVMF_Pos)                      /*!< 0x00000010 */
#define RTC_MISR_TSOVMF                           RTC_MISR_TSOVMF_Msk                               
#define RTC_MISR_ITSMF_Pos                        (5U)
#define RTC_MISR_ITSMF_Msk                        (0x1UL<<RTC_MISR_ITSMF_Pos)                       /*!< 0x00000020 */
#define RTC_MISR_ITSMF                            RTC_MISR_ITSMF_Msk                                

/********************************* Bit definition for RTC_SCR register **********************************************/
#define RTC_SCR_CALRAF_Pos                        (0U)
#define RTC_SCR_CALRAF_Msk                        (0x1UL<<RTC_SCR_CALRAF_Pos)                       /*!< 0x00000001 */
#define RTC_SCR_CALRAF                            RTC_SCR_CALRAF_Msk                                
#define RTC_SCR_CALRBF_Pos                        (1U)
#define RTC_SCR_CALRBF_Msk                        (0x1UL<<RTC_SCR_CALRBF_Pos)                       /*!< 0x00000002 */
#define RTC_SCR_CALRBF                            RTC_SCR_CALRBF_Msk                                
#define RTC_SCR_CWUTF_Pos                         (2U)
#define RTC_SCR_CWUTF_Msk                         (0x1UL<<RTC_SCR_CWUTF_Pos)                        /*!< 0x00000004 */
#define RTC_SCR_CWUTF                             RTC_SCR_CWUTF_Msk                                 
#define RTC_SCR_CTSF_Pos                          (3U)
#define RTC_SCR_CTSF_Msk                          (0x1UL<<RTC_SCR_CTSF_Pos)                         /*!< 0x00000008 */
#define RTC_SCR_CTSF                              RTC_SCR_CTSF_Msk                                  
#define RTC_SCR_CTSOVF_Pos                        (4U)
#define RTC_SCR_CTSOVF_Msk                        (0x1UL<<RTC_SCR_CTSOVF_Pos)                       /*!< 0x00000010 */
#define RTC_SCR_CTSOVF                            RTC_SCR_CTSOVF_Msk                                
#define RTC_SCR_CITSF_Pos                         (5U)
#define RTC_SCR_CITSF_Msk                         (0x1UL<<RTC_SCR_CITSF_Pos)                        /*!< 0x00000020 */
#define RTC_SCR_CITSF                             RTC_SCR_CITSF_Msk                                 
                                

/********************************************************************************************************************/
/********************************* TAMP *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for TAMP_CR1 register *********************************************/
#define TAMP_CR1_TAMP1EN_Pos                      (0U)
#define TAMP_CR1_TAMP1EN_Msk                      (0x1UL<<TAMP_CR1_TAMP1EN_Pos)                     /*!< 0x00000001 */
#define TAMP_CR1_TAMP1EN                          TAMP_CR1_TAMP1EN_Msk                              /*!< TAMP enable */
#define TAMP_CR1_ITAMP1EN_Pos                     (16U)
#define TAMP_CR1_ITAMP1EN_Msk                     (0x1UL<<TAMP_CR1_ITAMP1EN_Pos)                    /*!< 0x00010000 */
#define TAMP_CR1_ITAMP1EN                         TAMP_CR1_ITAMP1EN_Msk                             /*!< TAMPER pin interrupt enable */

/********************************* Bit definition for TAMP_CR2 register *********************************************/
#define TAMP_CR2_TAMP1NOER_Pos                    (0U)
#define TAMP_CR2_TAMP1NOER_Msk                    (0x1UL<<TAMP_CR2_TAMP1NOER_Pos)                   /*!< 0x00000001 */
#define TAMP_CR2_TAMP1NOER                        TAMP_CR2_TAMP1NOER_Msk                            /*!< TAMP not erase enable */
#define TAMP_CR2_TAMP1MSK_Pos                     (16U)
#define TAMP_CR2_TAMP1MSK_Msk                     (0x1UL<<TAMP_CR2_TAMP1MSK_Pos)                    /*!< 0x00010000 */
#define TAMP_CR2_TAMP1MSK                         TAMP_CR2_TAMP1MSK_Msk                             /*!< TAMP enable */
#define TAMP_CR2_TAMP1TRG_Pos                     (24U)
#define TAMP_CR2_TAMP1TRG_Msk                     (0x1UL<<TAMP_CR2_TAMP1TRG_Pos)                    /*!< 0x01000000 */
#define TAMP_CR2_TAMP1TRG                         TAMP_CR2_TAMP1TRG_Msk                             /*!< TAMPER pin interrupt enable */

/********************************* Bit definition for TAMP_FLTCR register *******************************************/
#define TAMP_FLTCR_TAMPFREQ_Pos                   (0U)
#define TAMP_FLTCR_TAMPFREQ_Msk                   (0x7UL<<TAMP_FLTCR_TAMPFREQ_Pos)                  /*!< 0x00000007 */
#define TAMP_FLTCR_TAMPFREQ                       TAMP_FLTCR_TAMPFREQ_Msk                           /*!< TAMP_IN Filter FREQUENCY */
#define TAMP_FLTCR_TAMPFREQ_0                     (0x1UL<<TAMP_FLTCR_TAMPFREQ_Pos)                  /*!< 0x00000001 */
#define TAMP_FLTCR_TAMPFREQ_1                     (0x2UL<<TAMP_FLTCR_TAMPFREQ_Pos)                  /*!< 0x00000002 */
#define TAMP_FLTCR_TAMPFREQ_2                     (0x4UL<<TAMP_FLTCR_TAMPFREQ_Pos)                  /*!< 0x00000004 */
#define TAMP_FLTCR_TAMPFLT_Pos                    (3U)
#define TAMP_FLTCR_TAMPFLT_Msk                    (0x3UL<<TAMP_FLTCR_TAMPFLT_Pos)                   /*!< 0x00000018 */
#define TAMP_FLTCR_TAMPFLT                        TAMP_FLTCR_TAMPFLT_Msk                            /*!< TAMP_IN Filter */
#define TAMP_FLTCR_TAMPFLT_0                      (0x1UL<<TAMP_FLTCR_TAMPFLT_Pos)                   /*!< 0x00000008 */
#define TAMP_FLTCR_TAMPFLT_1                      (0x2UL<<TAMP_FLTCR_TAMPFLT_Pos)                   /*!< 0x00000010 */

/********************************* Bit definition for TAMP_IER register *********************************************/
#define TAMP_IER_TAMP1IE_Pos                      (0U)
#define TAMP_IER_TAMP1IE_Msk                      (0x1UL<<TAMP_IER_TAMP1IE_Pos)                     /*!< 0x00000001 */
#define TAMP_IER_TAMP1IE                          TAMP_IER_TAMP1IE_Msk                              
#define TAMP_IER_ITAMP1IE_Pos                     (16U)
#define TAMP_IER_ITAMP1IE_Msk                     (0x1UL<<TAMP_IER_ITAMP1IE_Pos)                    /*!< 0x00010000 */
#define TAMP_IER_ITAMP1IE                         TAMP_IER_ITAMP1IE_Msk                             

/********************************* Bit definition for TAMP_SR register **********************************************/
#define TAMP_SR_TAMP1F_Pos                        (0U)
#define TAMP_SR_TAMP1F_Msk                        (0x1UL<<TAMP_SR_TAMP1F_Pos)                      /*!< 0x00000001 */
#define TAMP_SR_TAMP1F                            TAMP_SR_TAMP1F_Msk                               
#define TAMP_SR_ITAMP1F_Pos                       (16U)
#define TAMP_SR_ITAMP1F_Msk                       (0x1UL<<TAMP_SR_ITAMP1F_Pos)                      /*!< 0x00010000 */
#define TAMP_SR_ITAMP1F                           TAMP_SR_ITAMP1F_Msk                               

/********************************* Bit definition for TAMP_MISR register ********************************************/
#define TAMP_MISR_TAMP1MF_Pos                     (0U)
#define TAMP_MISR_TAMP1MF_Msk                     (0x1UL<<TAMP_MISR_TAMP1MF_Pos)                    /*!< 0x00000001 */
#define TAMP_MISR_TAMP1MF                         TAMP_MISR_TAMP1MF_Msk                             
#define TAMP_MISR_ITAMP1MF_Pos                    (16U)
#define TAMP_MISR_ITAMP1MF_Msk                    (0x1UL<<TAMP_MISR_ITAMP1MF_Pos)                   /*!< 0x00010000 */
#define TAMP_MISR_ITAMP1MF                        TAMP_MISR_ITAMP1MF_Msk                            

/********************************* Bit definition for TAMP_SCR register *********************************************/
#define TAMP_SCR_CTAMP1F_Pos                      (0U)
#define TAMP_SCR_CTAMP1F_Msk                      (0x1UL<<TAMP_SCR_CTAMP1F_Pos)                     /*!< 0x00000001 */
#define TAMP_SCR_CTAMP1F                          TAMP_SCR_CTAMP1F_Msk                              
#define TAMP_SCR_CITAMP1F_Pos                     (16U)
#define TAMP_SCR_CITAMP1F_Msk                     (0x1UL<<TAMP_SCR_CITAMP1F_Pos)                    /*!< 0x00010000 */
#define TAMP_SCR_CITAMP1F                         TAMP_SCR_CITAMP1F_Msk                             

/********************************* Bit definition for TAMP_BKP0R register *******************************************/
#define TAMP_BKP0R_D_Pos                          (0U)
#define TAMP_BKP0R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP0R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP0R_D                              TAMP_BKP0R_D_Msk                                  /*!< bakeup data word0 */

/********************************* Bit definition for TAMP_BKP1R register *******************************************/
#define TAMP_BKP1R_D_Pos                          (0U)
#define TAMP_BKP1R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP1R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP1R_D                              TAMP_BKP1R_D_Msk                                  /*!< bakeup data word1 */

/********************************* Bit definition for TAMP_BKP2R register *******************************************/
#define TAMP_BKP2R_D_Pos                          (0U)
#define TAMP_BKP2R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP2R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP2R_D                              TAMP_BKP2R_D_Msk                                  /*!< bakeup data word2 */

/********************************* Bit definition for TAMP_BKP3R register *******************************************/
#define TAMP_BKP3R_D_Pos                          (0U)
#define TAMP_BKP3R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP3R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP3R_D                              TAMP_BKP3R_D_Msk                                  /*!< bakeup data word3 */

/********************************* Bit definition for TAMP_BKP4R register *******************************************/
#define TAMP_BKP4R_D_Pos                          (0U)
#define TAMP_BKP4R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP4R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP4R_D                              TAMP_BKP4R_D_Msk                                  /*!< bakeup data word4 */

/********************************* Bit definition for TAMP_BKP5R register *******************************************/
#define TAMP_BKP5R_D_Pos                          (0U)
#define TAMP_BKP5R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP5R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP5R_D                              TAMP_BKP5R_D_Msk                                  /*!< bakeup data word5 */

/********************************* Bit definition for TAMP_BKP6R register *******************************************/
#define TAMP_BKP6R_D_Pos                          (0U)
#define TAMP_BKP6R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP6R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP6R_D                              TAMP_BKP6R_D_Msk                                  /*!< bakeup data word6 */

/********************************* Bit definition for TAMP_BKP7R register *******************************************/
#define TAMP_BKP7R_D_Pos                          (0U)
#define TAMP_BKP7R_D_Msk                          (0xFFFFFFFFUL<<TAMP_BKP7R_D_Pos)                  /*!< 0xFFFFFFFF */
#define TAMP_BKP7R_D                              TAMP_BKP7R_D_Msk                                  /*!< bakeup data word7 */

/********************************************************************************************************************/
/********************************* SPI ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for SPI_CR1 register **********************************************/
#define SPI_CR1_CPHA_Pos                          (0U)
#define SPI_CR1_CPHA_Msk                          (0x1UL<<SPI_CR1_CPHA_Pos)                         /*!< 0x00000001 */
#define SPI_CR1_CPHA                              SPI_CR1_CPHA_Msk                                  /*!< Clock Phase */
#define SPI_CR1_CPOL_Pos                          (1U)
#define SPI_CR1_CPOL_Msk                          (0x1UL<<SPI_CR1_CPOL_Pos)                         /*!< 0x00000002 */
#define SPI_CR1_CPOL                              SPI_CR1_CPOL_Msk                                  /*!< Clock Polarity  */
#define SPI_CR1_MSTR_Pos                          (2U)
#define SPI_CR1_MSTR_Msk                          (0x1UL<<SPI_CR1_MSTR_Pos)                         /*!< 0x00000004 */
#define SPI_CR1_MSTR                              SPI_CR1_MSTR_Msk                                  /*!< Master Selection */
#define SPI_CR1_BR_Pos                            (3U)
#define SPI_CR1_BR_Msk                            (0x7UL<<SPI_CR1_BR_Pos)                           /*!< 0x00000038 */
#define SPI_CR1_BR                                SPI_CR1_BR_Msk                                    /*!< Baud Rate Control */
#define SPI_CR1_BR_0                              (0x1UL<<SPI_CR1_BR_Pos)                           /*!< 0x00000008 */
#define SPI_CR1_BR_1                              (0x2UL<<SPI_CR1_BR_Pos)                           /*!< 0x00000010 */
#define SPI_CR1_BR_2                              (0x4UL<<SPI_CR1_BR_Pos)                           /*!< 0x00000020 */
#define SPI_CR1_SPE_Pos                           (6U)
#define SPI_CR1_SPE_Msk                           (0x1UL<<SPI_CR1_SPE_Pos)                          /*!< 0x00000040 */
#define SPI_CR1_SPE                               SPI_CR1_SPE_Msk                                   /*!< SPI Enable */
#define SPI_CR1_LSBFIRST_Pos                      (7U)
#define SPI_CR1_LSBFIRST_Msk                      (0x1UL<<SPI_CR1_LSBFIRST_Pos)                     /*!< 0x00000080 */
#define SPI_CR1_LSBFIRST                          SPI_CR1_LSBFIRST_Msk                              /*!<  Frame Format */
#define SPI_CR1_SSI_Pos                           (8U)
#define SPI_CR1_SSI_Msk                           (0x1UL<<SPI_CR1_SSI_Pos)                          /*!< 0x00000100 */
#define SPI_CR1_SSI                               SPI_CR1_SSI_Msk                                   /*!< Internal slave select */
#define SPI_CR1_SSM_Pos                           (9U)
#define SPI_CR1_SSM_Msk                           (0x1UL<<SPI_CR1_SSM_Pos)                          /*!< 0x00000200 */
#define SPI_CR1_SSM                               SPI_CR1_SSM_Msk                                   /*!< Software slave management  */
#define SPI_CR1_RXONLY_Pos                        (10U)
#define SPI_CR1_RXONLY_Msk                        (0x1UL<<SPI_CR1_RXONLY_Pos)                       /*!< 0x00000400 */
#define SPI_CR1_RXONLY                            SPI_CR1_RXONLY_Msk                                /*!< Receive only */
#define SPI_CR1_DFF_Pos                           (11U)
#define SPI_CR1_DFF_Msk                           (0x1UL<<SPI_CR1_DFF_Pos)                          /*!< 0x00000800 */
#define SPI_CR1_DFF                               SPI_CR1_DFF_Msk                                   /*!< Data frame format */
#define SPI_CR1_CRCNEXT_Pos                       (12U)
#define SPI_CR1_CRCNEXT_Msk                       (0x1UL<<SPI_CR1_CRCNEXT_Pos)                      /*!< 0x00001000 */
#define SPI_CR1_CRCNEXT                           SPI_CR1_CRCNEXT_Msk                               /*!< Transmit CRC next */
#define SPI_CR1_CRCEN_Pos                         (13U)
#define SPI_CR1_CRCEN_Msk                         (0x1UL<<SPI_CR1_CRCEN_Pos)                        /*!< 0x00002000 */
#define SPI_CR1_CRCEN                             SPI_CR1_CRCEN_Msk                                 /*!< Hardware CRC calculation enable */
#define SPI_CR1_BIDIOE_Pos                        (14U)
#define SPI_CR1_BIDIOE_Msk                        (0x1UL<<SPI_CR1_BIDIOE_Pos)                       /*!< 0x00004000 */
#define SPI_CR1_BIDIOE                            SPI_CR1_BIDIOE_Msk                                /*!< Output enable in bidirectional mode */
#define SPI_CR1_BIDIMODE_Pos                      (15U)
#define SPI_CR1_BIDIMODE_Msk                      (0x1UL<<SPI_CR1_BIDIMODE_Pos)                     /*!< 0x00008000 */
#define SPI_CR1_BIDIMODE                          SPI_CR1_BIDIMODE_Msk                              /*!< Bidirectional data mode enable */

/********************************* Bit definition for SPI_CR2 register **********************************************/
#define SPI_CR2_RXDMAEN_Pos                       (0U)
#define SPI_CR2_RXDMAEN_Msk                       (0x1UL<<SPI_CR2_RXDMAEN_Pos)                      /*!< 0x00000001 */
#define SPI_CR2_RXDMAEN                           SPI_CR2_RXDMAEN_Msk                               /*!< Rx buffer DMA enable */
#define SPI_CR2_TXDMAEN_Pos                       (1U)
#define SPI_CR2_TXDMAEN_Msk                       (0x1UL<<SPI_CR2_TXDMAEN_Pos)                      /*!< 0x00000002 */
#define SPI_CR2_TXDMAEN                           SPI_CR2_TXDMAEN_Msk                               /*!< Tx buffer DMA enable */
#define SPI_CR2_SSOE_Pos                          (2U)
#define SPI_CR2_SSOE_Msk                          (0x1UL<<SPI_CR2_SSOE_Pos)                         /*!< 0x00000004 */
#define SPI_CR2_SSOE                              SPI_CR2_SSOE_Msk                                  /*!< SS Output Enable  */
#define SPI_CR2_CLRTXFIFO_Pos                     (4U)
#define SPI_CR2_CLRTXFIFO_Msk                     (0x1UL<<SPI_CR2_CLRTXFIFO_Pos)                    /*!< 0x00000010 */
#define SPI_CR2_CLRTXFIFO                         SPI_CR2_CLRTXFIFO_Msk                             /*!< Clear FIFO */
#define SPI_CR2_ERRIE_Pos                         (5U)
#define SPI_CR2_ERRIE_Msk                         (0x1UL<<SPI_CR2_ERRIE_Pos)                        /*!< 0x00000020 */
#define SPI_CR2_ERRIE                             SPI_CR2_ERRIE_Msk                                 /*!< Error Interrupt Enable */
#define SPI_CR2_RXNEIE_Pos                        (6U)
#define SPI_CR2_RXNEIE_Msk                        (0x1UL<<SPI_CR2_RXNEIE_Pos)                       /*!< 0x00000040 */
#define SPI_CR2_RXNEIE                            SPI_CR2_RXNEIE_Msk                                /*!< RX buffer Not Empty Interrupt Enable */
#define SPI_CR2_TXEIE_Pos                         (7U)
#define SPI_CR2_TXEIE_Msk                         (0x1UL<<SPI_CR2_TXEIE_Pos)                        /*!< 0x00000080 */
#define SPI_CR2_TXEIE                             SPI_CR2_TXEIE_Msk                                 /*!< Tx buffer Empty Interrupt Enable */
#define SPI_CR2_FRF_Pos                           (15U)
#define SPI_CR2_FRF_Msk                           (0x1UL<<SPI_CR2_FRF_Pos)                          /*!< 0x00008000 */
#define SPI_CR2_FRF                               SPI_CR2_FRF_Msk                                   

/********************************* Bit definition for SPI_SR register ***********************************************/
#define SPI_SR_RXNE_Pos                           (0U)
#define SPI_SR_RXNE_Msk                           (0x1UL<<SPI_SR_RXNE_Pos)                          /*!< 0x00000001 */
#define SPI_SR_RXNE                               SPI_SR_RXNE_Msk                                   /*!< Receive buffer Not Empty  */
#define SPI_SR_TXE_Pos                            (1U)
#define SPI_SR_TXE_Msk                            (0x1UL<<SPI_SR_TXE_Pos)                           /*!< 0x00000002 */
#define SPI_SR_TXE                                SPI_SR_TXE_Msk                                    /*!< Transmit buffer Empty  */
#define SPI_SR_CHSIDE_Pos                         (2U)
#define SPI_SR_CHSIDE_Msk                         (0x1UL<<SPI_SR_CHSIDE_Pos)                        /*!< 0x00000004 */
#define SPI_SR_CHSIDE                             SPI_SR_CHSIDE_Msk                                 /*!< Channel side */
#define SPI_SR_UDR_Pos                            (3U)
#define SPI_SR_UDR_Msk                            (0x1UL<<SPI_SR_UDR_Pos)                           /*!< 0x00000008 */
#define SPI_SR_UDR                                SPI_SR_UDR_Msk                                    /*!< Underrun flag */
#define SPI_SR_CRCERR_Pos                         (4U)
#define SPI_SR_CRCERR_Msk                         (0x1UL<<SPI_SR_CRCERR_Pos)                        /*!< 0x00000010 */
#define SPI_SR_CRCERR                             SPI_SR_CRCERR_Msk                                 /*!< CRC error flag */
#define SPI_SR_MODF_Pos                           (5U)
#define SPI_SR_MODF_Msk                           (0x1UL<<SPI_SR_MODF_Pos)                          /*!< 0x00000020 */
#define SPI_SR_MODF                               SPI_SR_MODF_Msk                                   /*!< Mode fault */
#define SPI_SR_OVR_Pos                            (6U)
#define SPI_SR_OVR_Msk                            (0x1UL<<SPI_SR_OVR_Pos)                           /*!< 0x00000040 */
#define SPI_SR_OVR                                SPI_SR_OVR_Msk                                    /*!<  Overrun flag */
#define SPI_SR_BSY_Pos                            (7U)
#define SPI_SR_BSY_Msk                            (0x1UL<<SPI_SR_BSY_Pos)                           /*!< 0x00000080 */
#define SPI_SR_BSY                                SPI_SR_BSY_Msk                                    /*!< Busy flag  */
#define SPI_SR_FRE_Pos                            (8U)
#define SPI_SR_FRE_Msk                            (0x1UL<<SPI_SR_FRE_Pos)                           /*!< 0x00000100 */
#define SPI_SR_FRE                                SPI_SR_FRE_Msk                                    
#define SPI_SR_FRLVL_Pos                          (9U)
#define SPI_SR_FRLVL_Msk                          (0x3UL<<SPI_SR_FRLVL_Pos)                         /*!< 0x00000600 */
#define SPI_SR_FRLVL                              SPI_SR_FRLVL_Msk                                  /*!< FIFO Reception Level */
#define SPI_SR_FRLVL_0                            (0x1UL<<SPI_SR_FRLVL_Pos)                         /*!< 0x00000200 */
#define SPI_SR_FRLVL_1                            (0x2UL<<SPI_SR_FRLVL_Pos)                         /*!< 0x00000400 */
#define SPI_SR_FTLVL_Pos                          (11U)
#define SPI_SR_FTLVL_Msk                          (0x3UL<<SPI_SR_FTLVL_Pos)                         /*!< 0x00001800 */
#define SPI_SR_FTLVL                              SPI_SR_FTLVL_Msk                                  /*!< FIFO Transmission Level */
#define SPI_SR_FTLVL_0                            (0x1UL<<SPI_SR_FTLVL_Pos)                         /*!< 0x00000800 */
#define SPI_SR_FTLVL_1                            (0x2UL<<SPI_SR_FTLVL_Pos)                         /*!< 0x00001000 */

/********************************* Bit definition for SPI_DR register ***********************************************/
#define SPI_DR_DR_Pos                             (0U)
#define SPI_DR_DR_Msk                             (0xFFFFUL<<SPI_DR_DR_Pos)                         /*!< 0x0000FFFF */
#define SPI_DR_DR                                 SPI_DR_DR_Msk                                     /*!< Data Register */

/********************************* Bit definition for SPI_CRCPR register ********************************************/
#define SPI_CRCPR_CRCPOLY_Pos                     (0U)
#define SPI_CRCPR_CRCPOLY_Msk                     (0xFFFFUL<<SPI_CRCPR_CRCPOLY_Pos)                 /*!< 0x0000FFFF */
#define SPI_CRCPR_CRCPOLY                         SPI_CRCPR_CRCPOLY_Msk                             /*!< CRC polynomial register */

/********************************* Bit definition for SPI_RXCRCR register *******************************************/
#define SPI_RXCRCR_RXCRC_Pos                      (0U)
#define SPI_RXCRCR_RXCRC_Msk                      (0xFFFFUL<<SPI_RXCRCR_RXCRC_Pos)                  /*!< 0x0000FFFF */
#define SPI_RXCRCR_RXCRC                          SPI_RXCRCR_RXCRC_Msk                              /*!< rcv crc reg */

/********************************* Bit definition for SPI_TXCRCR register *******************************************/
#define SPI_TXCRCR_TXCRC_Pos                      (0U)
#define SPI_TXCRCR_TXCRC_Msk                      (0xFFFFUL<<SPI_TXCRCR_TXCRC_Pos)                  /*!< 0x0000FFFF */
#define SPI_TXCRCR_TXCRC                          SPI_TXCRCR_TXCRC_Msk                              /*!< tx crc reg  */

/********************************* Bit definition for SPI_I2S_CFGR register *****************************************/
#define SPI_I2S_CFGR_CHLEN_Pos                    (0U)
#define SPI_I2S_CFGR_CHLEN_Msk                    (0x1UL<<SPI_I2S_CFGR_CHLEN_Pos)                   /*!< 0x00000001 */
#define SPI_I2S_CFGR_CHLEN                        SPI_I2S_CFGR_CHLEN_Msk                            /*!< Channel length (number of bits per audio channel */
#define SPI_I2S_CFGR_DATLEN_Pos                   (1U)
#define SPI_I2S_CFGR_DATLEN_Msk                   (0x3UL<<SPI_I2S_CFGR_DATLEN_Pos)                  /*!< 0x00000006 */
#define SPI_I2S_CFGR_DATLEN                       SPI_I2S_CFGR_DATLEN_Msk                           /*!< Data length to be transferred */
#define SPI_I2S_CFGR_DATLEN_0                     (0x1UL<<SPI_I2S_CFGR_DATLEN_Pos)                  /*!< 0x00000002 */
#define SPI_I2S_CFGR_DATLEN_1                     (0x2UL<<SPI_I2S_CFGR_DATLEN_Pos)                  /*!< 0x00000004 */
#define SPI_I2S_CFGR_CKPOL_Pos                    (3U)
#define SPI_I2S_CFGR_CKPOL_Msk                    (0x1UL<<SPI_I2S_CFGR_CKPOL_Pos)                   /*!< 0x00000008 */
#define SPI_I2S_CFGR_CKPOL                        SPI_I2S_CFGR_CKPOL_Msk                            /*!< Steady state clock polarity */
#define SPI_I2S_CFGR_I2SSTD_Pos                   (4U)
#define SPI_I2S_CFGR_I2SSTD_Msk                   (0x3UL<<SPI_I2S_CFGR_I2SSTD_Pos)                  /*!< 0x00000030 */
#define SPI_I2S_CFGR_I2SSTD                       SPI_I2S_CFGR_I2SSTD_Msk                           /*!< I2S standard selection */
#define SPI_I2S_CFGR_I2SSTD_0                     (0x1UL<<SPI_I2S_CFGR_I2SSTD_Pos)                  /*!< 0x00000010 */
#define SPI_I2S_CFGR_I2SSTD_1                     (0x2UL<<SPI_I2S_CFGR_I2SSTD_Pos)                  /*!< 0x00000020 */
#define SPI_I2S_CFGR_PCMSYNC_Pos                  (7U)
#define SPI_I2S_CFGR_PCMSYNC_Msk                  (0x1UL<<SPI_I2S_CFGR_PCMSYNC_Pos)                 /*!< 0x00000080 */
#define SPI_I2S_CFGR_PCMSYNC                      SPI_I2S_CFGR_PCMSYNC_Msk                          /*!< PCM frame synchronization */
#define SPI_I2S_CFGR_I2SCFG_Pos                   (8U)
#define SPI_I2S_CFGR_I2SCFG_Msk                   (0x3UL<<SPI_I2S_CFGR_I2SCFG_Pos)                  /*!< 0x00000300 */
#define SPI_I2S_CFGR_I2SCFG                       SPI_I2S_CFGR_I2SCFG_Msk                           /*!< I2S configuration mode */
#define SPI_I2S_CFGR_I2SCFG_0                     (0x1UL<<SPI_I2S_CFGR_I2SCFG_Pos)                  /*!< 0x00000100 */
#define SPI_I2S_CFGR_I2SCFG_1                     (0x2UL<<SPI_I2S_CFGR_I2SCFG_Pos)                  /*!< 0x00000200 */
#define SPI_I2S_CFGR_I2SE_Pos                     (10U)
#define SPI_I2S_CFGR_I2SE_Msk                     (0x1UL<<SPI_I2S_CFGR_I2SE_Pos)                    /*!< 0x00000400 */
#define SPI_I2S_CFGR_I2SE                         SPI_I2S_CFGR_I2SE_Msk                             /*!<  I2S enable */
#define SPI_I2S_CFGR_I2SMOD_Pos                   (11U)
#define SPI_I2S_CFGR_I2SMOD_Msk                   (0x1UL<<SPI_I2S_CFGR_I2SMOD_Pos)                  /*!< 0x00000800 */
#define SPI_I2S_CFGR_I2SMOD                       SPI_I2S_CFGR_I2SMOD_Msk                           /*!< I2S mode selection */

#define SPI_I2S_SUPPORT       /*!< I2S support */

/********************************* Bit definition for SPI_I2SPR register ********************************************/
#define SPI_I2SPR_I2SDIV_Pos                      (0U)
#define SPI_I2SPR_I2SDIV_Msk                      (0xFFUL<<SPI_I2SPR_I2SDIV_Pos)                    /*!< 0x000000FF */
#define SPI_I2SPR_I2SDIV                          SPI_I2SPR_I2SDIV_Msk                              /*!< I2S linear prescaler */
#define SPI_I2SPR_ODD_Pos                         (8U)
#define SPI_I2SPR_ODD_Msk                         (0x1UL<<SPI_I2SPR_ODD_Pos)                        /*!< 0x00000100 */
#define SPI_I2SPR_ODD                             SPI_I2SPR_ODD_Msk                                 /*!< Odd factor for the prescaler */
#define SPI_I2SPR_MCKOE_Pos                       (9U)
#define SPI_I2SPR_MCKOE_Msk                       (0x1UL<<SPI_I2SPR_MCKOE_Pos)                      /*!< 0x00000200 */
#define SPI_I2SPR_MCKOE                           SPI_I2SPR_MCKOE_Msk                               /*!<  Master clock output enable */


/********************************************************************************************************************/
/********************************* SYSCFG ***************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for SYSCFG_CFGR1 register *****************************************/
#define SYSCFG_CFGR1_MEM_MODE_Pos                 (0U)
#define SYSCFG_CFGR1_MEM_MODE_Msk                 (0x3UL<<SYSCFG_CFGR1_MEM_MODE_Pos)                /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                     SYSCFG_CFGR1_MEM_MODE_Msk
#define SYSCFG_CFGR1_MEM_MODE_0                   (0x1UL<<SYSCFG_CFGR1_MEM_MODE_Pos)                /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1                   (0x2UL<<SYSCFG_CFGR1_MEM_MODE_Pos)                /*!< 0x00000002 */
#define SYSCFG_CFGR1_TK_LP_TRIG_Pos               (8U)
#define SYSCFG_CFGR1_TK_LP_TRIG_Msk               (0x3UL<<SYSCFG_CFGR1_TK_LP_TRIG_Pos)              /*!< 0x00000300 */
#define SYSCFG_CFGR1_TK_LP_TRIG                   SYSCFG_CFGR1_TK_LP_TRIG_Msk
#define SYSCFG_CFGR1_TK_LP_TRIG_0                 (0x1UL<<SYSCFG_CFGR1_TK_LP_TRIG_Pos)              /*!< 0x00000100 */
#define SYSCFG_CFGR1_TK_LP_TRIG_1                 (0x2UL<<SYSCFG_CFGR1_TK_LP_TRIG_Pos)              /*!< 0x00000200 */
#define SYSCFG_CFGR1_RTC_TRIG_TKSEL_Pos           (10U)
#define SYSCFG_CFGR1_RTC_TRIG_TKSEL_Msk           (0x3UL<<SYSCFG_CFGR1_RTC_TRIG_TKSEL_Pos)          /*!< 0x00000C00 */
#define SYSCFG_CFGR1_RTC_TRIG_TKSEL               SYSCFG_CFGR1_RTC_TRIG_TKSEL_Msk
#define SYSCFG_CFGR1_RTC_TRIG_TKSEL_0             (0x1UL<<SYSCFG_CFGR1_RTC_TRIG_TKSEL_Pos)          /*!< 0x00000400 */
#define SYSCFG_CFGR1_RTC_TRIG_TKSEL_1             (0x2UL<<SYSCFG_CFGR1_RTC_TRIG_TKSEL_Pos)          /*!< 0x00000800 */
#define SYSCFG_CFGR1_LPTIM1_TRIG_TKEN_Pos         (12U)
#define SYSCFG_CFGR1_LPTIM1_TRIG_TKEN_Msk         (0x1UL<<SYSCFG_CFGR1_LPTIM1_TRIG_TKEN_Pos)        /*!< 0x00001000 */
#define SYSCFG_CFGR1_LPTIM1_TRIG_TKEN             SYSCFG_CFGR1_LPTIM1_TRIG_TKEN_Msk                 
#define SYSCFG_CFGR1_LPTIM2_TRIG_TKEN_Pos         (13U)
#define SYSCFG_CFGR1_LPTIM2_TRIG_TKEN_Msk         (0x1UL<<SYSCFG_CFGR1_LPTIM2_TRIG_TKEN_Pos)        /*!< 0x00002000 */
#define SYSCFG_CFGR1_LPTIM2_TRIG_TKEN             SYSCFG_CFGR1_LPTIM2_TRIG_TKEN_Msk                 
#define SYSCFG_CFGR1_GPIO_AHB_SEL_Pos             (24U)
#define SYSCFG_CFGR1_GPIO_AHB_SEL_Msk             (0x1UL<<SYSCFG_CFGR1_GPIO_AHB_SEL_Pos)            /*!< 0x01000000 */
#define SYSCFG_CFGR1_GPIO_AHB_SEL                 SYSCFG_CFGR1_GPIO_AHB_SEL_Msk                     

/********************************* Bit definition for SYSCFG_CFGR2 register *****************************************/
#define SYSCFG_CFGR2_CLL_Pos                      (0U)
#define SYSCFG_CFGR2_CLL_Msk                      (0x1UL<<SYSCFG_CFGR2_CLL_Pos)                     /*!< 0x00000001 */
#define SYSCFG_CFGR2_CLL                          SYSCFG_CFGR2_CLL_Msk                              
#define SYSCFG_CFGR2_SPL_Pos                      (1U)
#define SYSCFG_CFGR2_SPL_Msk                      (0x1UL<<SYSCFG_CFGR2_SPL_Pos)                     /*!< 0x00000002 */
#define SYSCFG_CFGR2_SPL                          SYSCFG_CFGR2_SPL_Msk                              
#define SYSCFG_CFGR2_PVDL_Pos                     (2U)
#define SYSCFG_CFGR2_PVDL_Msk                     (0x1UL<<SYSCFG_CFGR2_PVDL_Pos)                    /*!< 0x00000004 */
#define SYSCFG_CFGR2_PVDL                         SYSCFG_CFGR2_PVDL_Msk                             
#define SYSCFG_CFGR2_ECCL_Pos                     (3U)
#define SYSCFG_CFGR2_ECCL_Msk                     (0x1UL<<SYSCFG_CFGR2_ECCL_Pos)                    /*!< 0x00000008 */
#define SYSCFG_CFGR2_ECCL                         SYSCFG_CFGR2_ECCL_Msk                             

/********************************* Bit definition for SYSCFG_CFGR3 register *****************************************/
#define SYSCFG_CFGR3_DMA1_MAP_Pos                 (0U)
#define SYSCFG_CFGR3_DMA1_MAP_Msk                 (0x3FUL<<SYSCFG_CFGR3_DMA1_MAP_Pos)               /*!< 0x0000003F */
#define SYSCFG_CFGR3_DMA1_MAP                     SYSCFG_CFGR3_DMA1_MAP_Msk
#define SYSCFG_CFGR3_DMA1_MAP_0                   (0x1UL<<SYSCFG_CFGR3_DMA1_MAP_Pos)                /*!< 0x00000001 */
#define SYSCFG_CFGR3_DMA1_MAP_1                   (0x2UL<<SYSCFG_CFGR3_DMA1_MAP_Pos)                /*!< 0x00000002 */
#define SYSCFG_CFGR3_DMA1_MAP_2                   (0x4UL<<SYSCFG_CFGR3_DMA1_MAP_Pos)                /*!< 0x00000004 */
#define SYSCFG_CFGR3_DMA1_MAP_3                   (0x8UL<<SYSCFG_CFGR3_DMA1_MAP_Pos)                /*!< 0x00000008 */
#define SYSCFG_CFGR3_DMA1_MAP_4                   (0x10UL<<SYSCFG_CFGR3_DMA1_MAP_Pos)               /*!< 0x00000010 */
#define SYSCFG_CFGR3_DMA1_MAP_5                   (0x20UL<<SYSCFG_CFGR3_DMA1_MAP_Pos)               /*!< 0x00000020 */
#define SYSCFG_CFGR3_DMA2_MAP_Pos                 (8U)
#define SYSCFG_CFGR3_DMA2_MAP_Msk                 (0x3FUL<<SYSCFG_CFGR3_DMA2_MAP_Pos)               /*!< 0x00003F00 */
#define SYSCFG_CFGR3_DMA2_MAP                     SYSCFG_CFGR3_DMA2_MAP_Msk
#define SYSCFG_CFGR3_DMA2_MAP_0                   (0x1UL<<SYSCFG_CFGR3_DMA2_MAP_Pos)                /*!< 0x00000100 */
#define SYSCFG_CFGR3_DMA2_MAP_1                   (0x2UL<<SYSCFG_CFGR3_DMA2_MAP_Pos)                /*!< 0x00000200 */
#define SYSCFG_CFGR3_DMA2_MAP_2                   (0x4UL<<SYSCFG_CFGR3_DMA2_MAP_Pos)                /*!< 0x00000400 */
#define SYSCFG_CFGR3_DMA2_MAP_3                   (0x8UL<<SYSCFG_CFGR3_DMA2_MAP_Pos)                /*!< 0x00000800 */
#define SYSCFG_CFGR3_DMA2_MAP_4                   (0x10UL<<SYSCFG_CFGR3_DMA2_MAP_Pos)               /*!< 0x00001000 */
#define SYSCFG_CFGR3_DMA2_MAP_5                   (0x20UL<<SYSCFG_CFGR3_DMA2_MAP_Pos)               /*!< 0x00002000 */
#define SYSCFG_CFGR3_DMA3_MAP_Pos                 (16U)
#define SYSCFG_CFGR3_DMA3_MAP_Msk                 (0x3FUL<<SYSCFG_CFGR3_DMA3_MAP_Pos)               /*!< 0x003F0000 */
#define SYSCFG_CFGR3_DMA3_MAP                     SYSCFG_CFGR3_DMA3_MAP_Msk
#define SYSCFG_CFGR3_DMA3_MAP_0                   (0x1UL<<SYSCFG_CFGR3_DMA3_MAP_Pos)                /*!< 0x00010000 */
#define SYSCFG_CFGR3_DMA3_MAP_1                   (0x2UL<<SYSCFG_CFGR3_DMA3_MAP_Pos)                /*!< 0x00020000 */
#define SYSCFG_CFGR3_DMA3_MAP_2                   (0x4UL<<SYSCFG_CFGR3_DMA3_MAP_Pos)                /*!< 0x00040000 */
#define SYSCFG_CFGR3_DMA3_MAP_3                   (0x8UL<<SYSCFG_CFGR3_DMA3_MAP_Pos)                /*!< 0x00080000 */
#define SYSCFG_CFGR3_DMA3_MAP_4                   (0x10UL<<SYSCFG_CFGR3_DMA3_MAP_Pos)               /*!< 0x00100000 */
#define SYSCFG_CFGR3_DMA3_MAP_5                   (0x20UL<<SYSCFG_CFGR3_DMA3_MAP_Pos)               /*!< 0x00200000 */
#define SYSCFG_CFGR3_DMA4_MAP_Pos                 (24U)
#define SYSCFG_CFGR3_DMA4_MAP_Msk                 (0x3FUL<<SYSCFG_CFGR3_DMA4_MAP_Pos)               /*!< 0x3F000000 */
#define SYSCFG_CFGR3_DMA4_MAP                     SYSCFG_CFGR3_DMA4_MAP_Msk
#define SYSCFG_CFGR3_DMA4_MAP_0                   (0x1UL<<SYSCFG_CFGR3_DMA4_MAP_Pos)                /*!< 0x01000000 */
#define SYSCFG_CFGR3_DMA4_MAP_1                   (0x2UL<<SYSCFG_CFGR3_DMA4_MAP_Pos)                /*!< 0x02000000 */
#define SYSCFG_CFGR3_DMA4_MAP_2                   (0x4UL<<SYSCFG_CFGR3_DMA4_MAP_Pos)                /*!< 0x04000000 */
#define SYSCFG_CFGR3_DMA4_MAP_3                   (0x8UL<<SYSCFG_CFGR3_DMA4_MAP_Pos)                /*!< 0x08000000 */
#define SYSCFG_CFGR3_DMA4_MAP_4                   (0x10UL<<SYSCFG_CFGR3_DMA4_MAP_Pos)               /*!< 0x10000000 */
#define SYSCFG_CFGR3_DMA4_MAP_5                   (0x20UL<<SYSCFG_CFGR3_DMA4_MAP_Pos)               /*!< 0x20000000 */

/********************************* Bit definition for SYSCFG_CFGR4 register *****************************************/
#define SYSCFG_CFGR4_DMA5_MAP_Pos                 (0U)
#define SYSCFG_CFGR4_DMA5_MAP_Msk                 (0x3FUL<<SYSCFG_CFGR4_DMA5_MAP_Pos)               /*!< 0x0000003F */
#define SYSCFG_CFGR4_DMA5_MAP                     SYSCFG_CFGR4_DMA5_MAP_Msk
#define SYSCFG_CFGR4_DMA5_MAP_0                   (0x1UL<<SYSCFG_CFGR4_DMA5_MAP_Pos)                /*!< 0x00000001 */
#define SYSCFG_CFGR4_DMA5_MAP_1                   (0x2UL<<SYSCFG_CFGR4_DMA5_MAP_Pos)                /*!< 0x00000002 */
#define SYSCFG_CFGR4_DMA5_MAP_2                   (0x4UL<<SYSCFG_CFGR4_DMA5_MAP_Pos)                /*!< 0x00000004 */
#define SYSCFG_CFGR4_DMA5_MAP_3                   (0x8UL<<SYSCFG_CFGR4_DMA5_MAP_Pos)                /*!< 0x00000008 */
#define SYSCFG_CFGR4_DMA5_MAP_4                   (0x10UL<<SYSCFG_CFGR4_DMA5_MAP_Pos)               /*!< 0x00000010 */
#define SYSCFG_CFGR4_DMA5_MAP_5                   (0x20UL<<SYSCFG_CFGR4_DMA5_MAP_Pos)               /*!< 0x00000020 */
#define SYSCFG_CFGR4_DMA6_MAP_Pos                 (8U)
#define SYSCFG_CFGR4_DMA6_MAP_Msk                 (0x3FUL<<SYSCFG_CFGR4_DMA6_MAP_Pos)               /*!< 0x00003F00 */
#define SYSCFG_CFGR4_DMA6_MAP                     SYSCFG_CFGR4_DMA6_MAP_Msk
#define SYSCFG_CFGR4_DMA6_MAP_0                   (0x1UL<<SYSCFG_CFGR4_DMA6_MAP_Pos)                /*!< 0x00000100 */
#define SYSCFG_CFGR4_DMA6_MAP_1                   (0x2UL<<SYSCFG_CFGR4_DMA6_MAP_Pos)                /*!< 0x00000200 */
#define SYSCFG_CFGR4_DMA6_MAP_2                   (0x4UL<<SYSCFG_CFGR4_DMA6_MAP_Pos)                /*!< 0x00000400 */
#define SYSCFG_CFGR4_DMA6_MAP_3                   (0x8UL<<SYSCFG_CFGR4_DMA6_MAP_Pos)                /*!< 0x00000800 */
#define SYSCFG_CFGR4_DMA6_MAP_4                   (0x10UL<<SYSCFG_CFGR4_DMA6_MAP_Pos)               /*!< 0x00001000 */
#define SYSCFG_CFGR4_DMA6_MAP_5                   (0x20UL<<SYSCFG_CFGR4_DMA6_MAP_Pos)               /*!< 0x00002000 */
#define SYSCFG_CFGR4_DMA7_MAP_Pos                 (16U)
#define SYSCFG_CFGR4_DMA7_MAP_Msk                 (0x3FUL<<SYSCFG_CFGR4_DMA7_MAP_Pos)               /*!< 0x003F0000 */
#define SYSCFG_CFGR4_DMA7_MAP                     SYSCFG_CFGR4_DMA7_MAP_Msk
#define SYSCFG_CFGR4_DMA7_MAP_0                   (0x1UL<<SYSCFG_CFGR4_DMA7_MAP_Pos)                /*!< 0x00010000 */
#define SYSCFG_CFGR4_DMA7_MAP_1                   (0x2UL<<SYSCFG_CFGR4_DMA7_MAP_Pos)                /*!< 0x00020000 */
#define SYSCFG_CFGR4_DMA7_MAP_2                   (0x4UL<<SYSCFG_CFGR4_DMA7_MAP_Pos)                /*!< 0x00040000 */
#define SYSCFG_CFGR4_DMA7_MAP_3                   (0x8UL<<SYSCFG_CFGR4_DMA7_MAP_Pos)                /*!< 0x00080000 */
#define SYSCFG_CFGR4_DMA7_MAP_4                   (0x10UL<<SYSCFG_CFGR4_DMA7_MAP_Pos)               /*!< 0x00100000 */
#define SYSCFG_CFGR4_DMA7_MAP_5                   (0x20UL<<SYSCFG_CFGR4_DMA7_MAP_Pos)               /*!< 0x00200000 */

/********************************* Bit definition for PA_ENS register ***********************************************/
#define SYSCFG_PA_ENS_PA_ENS_Pos                  (0U)
#define SYSCFG_PA_ENS_PA_ENS_Msk                  (0xFFFFUL<<SYSCFG_PA_ENS_PA_ENS_Pos)                     /*!< 0x0000FFFF */
#define SYSCFG_PA_ENS_PA_ENS                      SYSCFG_PA_ENS_PA_ENS_Msk

/********************************* Bit definition for PB_ENS register ***********************************************/
#define SYSCFG_PB_ENS_PB_ENS_Pos                  (0U)
#define SYSCFG_PB_ENS_PB_ENS_Msk                  (0xFFFFUL<<SYSCFG_PB_ENS_PB_ENS_Pos)                     /*!< 0x0000FFFF */
#define SYSCFG_PB_ENS_PB_ENS                      SYSCFG_PB_ENS_PB_ENS_Msk

/********************************* Bit definition for PC_ENS register ***********************************************/
#define SYSCFG_PC_ENS_PC_ENS_Pos                  (0U)
#define SYSCFG_PC_ENS_PC_ENS_Msk                  (0xFFFFUL<<SYSCFG_PC_ENS_PC_ENS_Pos)                     /*!< 0x0000FFFF */
#define SYSCFG_PC_ENS_PC_ENS                      SYSCFG_PC_ENS_PC_ENS_Msk

/********************************* Bit definition for PD_ENS register ***********************************************/
#define SYSCFG_PD_ENS_PD_ENS_Pos                  (0U)
#define SYSCFG_PD_ENS_PD_ENS_Msk                  (0xFFFFUL<<SYSCFG_PD_ENS_PD_ENS_Pos)                     /*!< 0x0000FFFF */
#define SYSCFG_PD_ENS_PD_ENS                      SYSCFG_PD_ENS_PD_ENS_Msk

/********************************* Bit definition for SYSCFG_IOCFG register *****************************************/
#define SYSCFG_IOCFG_PA_EIIC_Pos                  (0U)
#define SYSCFG_IOCFG_PA_EIIC_Msk                  (0xFUL<<SYSCFG_IOCFG_PA_EIIC_Pos)                 /*!< 0x0000000F */
#define SYSCFG_IOCFG_PA_EIIC                      SYSCFG_IOCFG_PA_EIIC_Msk
#define SYSCFG_IOCFG_PA_EIIC_0                    (0x1UL<<SYSCFG_IOCFG_PA_EIIC_Pos)                 /*!< 0x00000001 */
#define SYSCFG_IOCFG_PA_EIIC_1                    (0x2UL<<SYSCFG_IOCFG_PA_EIIC_Pos)                 /*!< 0x00000002 */
#define SYSCFG_IOCFG_PA_EIIC_2                    (0x4UL<<SYSCFG_IOCFG_PA_EIIC_Pos)                 /*!< 0x00000004 */
#define SYSCFG_IOCFG_PA_EIIC_3                    (0x8UL<<SYSCFG_IOCFG_PA_EIIC_Pos)                 /*!< 0x00000008 */
#define SYSCFG_IOCFG_PB_EIIC_Pos                  (8U)
#define SYSCFG_IOCFG_PB_EIIC_Msk                  (0x3FUL<<SYSCFG_IOCFG_PB_EIIC_Pos)                /*!< 0x00003F00 */
#define SYSCFG_IOCFG_PB_EIIC                      SYSCFG_IOCFG_PB_EIIC_Msk
#define SYSCFG_IOCFG_PB_EIIC_0                    (0x1UL<<SYSCFG_IOCFG_PB_EIIC_Pos)                 /*!< 0x00000100 */
#define SYSCFG_IOCFG_PB_EIIC_1                    (0x2UL<<SYSCFG_IOCFG_PB_EIIC_Pos)                 /*!< 0x00000200 */
#define SYSCFG_IOCFG_PB_EIIC_2                    (0x4UL<<SYSCFG_IOCFG_PB_EIIC_Pos)                 /*!< 0x00000400 */
#define SYSCFG_IOCFG_PB_EIIC_3                    (0x8UL<<SYSCFG_IOCFG_PB_EIIC_Pos)                 /*!< 0x00000800 */
#define SYSCFG_IOCFG_PB_EIIC_4                    (0x10UL<<SYSCFG_IOCFG_PB_EIIC_Pos)                /*!< 0x00001000 */
#define SYSCFG_IOCFG_PB_EIIC_5                    (0x20UL<<SYSCFG_IOCFG_PB_EIIC_Pos)                /*!< 0x00002000 */
#define SYSCFG_IOCFG_PD_EIIC_10_Pos               (14U)
#define SYSCFG_IOCFG_PD_EIIC_10_Msk               (0x1UL<<SYSCFG_IOCFG_PD_EIIC_10_Pos)              /*!< 0x00004000 */
#define SYSCFG_IOCFG_PD_EIIC_10                   SYSCFG_IOCFG_PD_EIIC_10_Msk   
#define SYSCFG_IOCFG_PD_EIIC_11_Pos               (15U)
#define SYSCFG_IOCFG_PD_EIIC_11_Msk               (0x1UL<<SYSCFG_IOCFG_PD_EIIC_11_Pos)              /*!< 0x00008000 */
#define SYSCFG_IOCFG_PD_EIIC_11                   SYSCFG_IOCFG_PD_EIIC_11_Msk                     
#define SYSCFG_IOCFG_PC_EIIC_Pos                  (16U)
#define SYSCFG_IOCFG_PC_EIIC_Msk                  (0x1FFUL<<SYSCFG_IOCFG_PC_EIIC_Pos)               /*!< 0x01FF0000 */
#define SYSCFG_IOCFG_PC_EIIC                      SYSCFG_IOCFG_PC_EIIC_Msk
#define SYSCFG_IOCFG_PC_EIIC_0                    (0x1UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_1                    (0x2UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_2                    (0x4UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_3                    (0x8UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_4                    (0x10UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_5                    (0x20UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_6                    (0x40UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_7                    (0x80UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PC_EIIC_8                    (0x100UL<<SYSCFG_IOCFG_PC_EIIC_Pos)
#define SYSCFG_IOCFG_PD_EIIC_Pos                  (26U)
#define SYSCFG_IOCFG_PD_EIIC_Msk                  (0xFUL<<SYSCFG_IOCFG_PD_EIIC_Pos)                 /*!< 0x3C000000 */
#define SYSCFG_IOCFG_PD_EIIC                      SYSCFG_IOCFG_PD_EIIC_Msk
#define SYSCFG_IOCFG_PD_EIIC_0                    (0x1UL<<SYSCFG_IOCFG_PD_EIIC_Pos)                 /*!< 0x04000000 */
#define SYSCFG_IOCFG_PD_EIIC_1                    (0x2UL<<SYSCFG_IOCFG_PD_EIIC_Pos)                 /*!< 0x08000000 */
#define SYSCFG_IOCFG_PD_EIIC_2                    (0x4UL<<SYSCFG_IOCFG_PD_EIIC_Pos)                 /*!< 0x10000000 */
#define SYSCFG_IOCFG_PD_EIIC_3                    (0x8UL<<SYSCFG_IOCFG_PD_EIIC_Pos)                 /*!< 0x20000000 */
#define SYSCFG_IOCFG_PD_PU_IIC_Pos                (30U)
#define SYSCFG_IOCFG_PD_PU_IIC_Msk                (0x3UL<<SYSCFG_IOCFG_PD_PU_IIC_Pos)               /*!< 0xC0000000 */
#define SYSCFG_IOCFG_PD_PU_IIC                    SYSCFG_IOCFG_PD_PU_IIC_Msk
#define SYSCFG_IOCFG_PD_PU_IIC_0                  (0x1UL<<SYSCFG_IOCFG_PD_PU_IIC_Pos)               /*!< 0x40000000 */
#define SYSCFG_IOCFG_PD_PU_IIC_1                  (0x2UL<<SYSCFG_IOCFG_PD_PU_IIC_Pos)               /*!< 0x80000000 */

/********************************* Bit definition for SYSCFG_LEDCFG register ****************************************/
#define SYSCFG_LEDCFG_SEGIS_EN_Pos                (0U)
#define SYSCFG_LEDCFG_SEGIS_EN_Msk                (0xFUL<<SYSCFG_LEDCFG_SEGIS_EN_Pos)               /*!< 0x0000000F */
#define SYSCFG_LEDCFG_SEGIS_EN                    SYSCFG_LEDCFG_SEGIS_EN_Msk
#define SYSCFG_LEDCFG_SEGIS_EN_0                  (0x1UL<<SYSCFG_LEDCFG_SEGIS_EN_Pos)               /*!< 0x00000001 */
#define SYSCFG_LEDCFG_SEGIS_EN_1                  (0x2UL<<SYSCFG_LEDCFG_SEGIS_EN_Pos)               /*!< 0x00000002 */
#define SYSCFG_LEDCFG_SEGIS_EN_2                  (0x4UL<<SYSCFG_LEDCFG_SEGIS_EN_Pos)               /*!< 0x00000004 */
#define SYSCFG_LEDCFG_SEGIS_EN_3                  (0x8UL<<SYSCFG_LEDCFG_SEGIS_EN_Pos)               /*!< 0x00000008 */
#define SYSCFG_LEDCFG_PB_EHS_Pos                  (8U)
#define SYSCFG_LEDCFG_PB_EHS_Msk                  (0xFFUL<<SYSCFG_LEDCFG_PB_EHS_Pos)                /*!< 0x0000FF00 */
#define SYSCFG_LEDCFG_PB_EHS                      SYSCFG_LEDCFG_PB_EHS_Msk
#define SYSCFG_LEDCFG_PB_EHS_0                    (0x1UL<<SYSCFG_LEDCFG_PB_EHS_Pos)  
#define SYSCFG_LEDCFG_PB_EHS_1                    (0x2UL<<SYSCFG_LEDCFG_PB_EHS_Pos)  
#define SYSCFG_LEDCFG_PB_EHS_2                    (0x4UL<<SYSCFG_LEDCFG_PB_EHS_Pos)  
#define SYSCFG_LEDCFG_PB_EHS_3                    (0x8UL<<SYSCFG_LEDCFG_PB_EHS_Pos) 
#define SYSCFG_LEDCFG_PB_EHS_4                    (0x10UL<<SYSCFG_LEDCFG_PB_EHS_Pos)  
#define SYSCFG_LEDCFG_PB_EHS_5                    (0x20UL<<SYSCFG_LEDCFG_PB_EHS_Pos)  
#define SYSCFG_LEDCFG_PB_EHS_6                    (0x40UL<<SYSCFG_LEDCFG_PB_EHS_Pos)  
#define SYSCFG_LEDCFG_PB_EHS_7                    (0x80UL<<SYSCFG_LEDCFG_PB_EHS_Pos)   
#define SYSCFG_LEDCFG_PB_ENSEG_Pos                (16U)
#define SYSCFG_LEDCFG_PB_ENSEG_Msk                (0x3FFFUL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)              /*!< 0x3FFF0000 */
#define SYSCFG_LEDCFG_PB_ENSEG                    SYSCFG_LEDCFG_PB_ENSEG_Msk
#define SYSCFG_LEDCFG_PB_ENSEG_0                  (0x1UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_1                  (0x2UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_2                  (0x4UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_3                  (0x8UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_4                  (0x10UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_5                  (0x20UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_6                  (0x40UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_7                  (0x80UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_8                  (0x100UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_9                  (0x200UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_10                 (0x400UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_11                 (0x800UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_12                 (0x1000UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  
#define SYSCFG_LEDCFG_PB_ENSEG_13                 (0x2000UL<<SYSCFG_LEDCFG_PB_ENSEG_Pos)  

#define SYSCFG_LEDCFG_PC_ENSEG_Pos                (30U)
#define SYSCFG_LEDCFG_PC_ENSEG_Msk                (0x3UL<<SYSCFG_LEDCFG_PC_ENSEG_Pos)               /*!< 0xC0000000 */
#define SYSCFG_LEDCFG_PC_ENSEG                    SYSCFG_LEDCFG_PC_ENSEG_Msk
#define SYSCFG_LEDCFG_PC_ENSEG_0                  (0x1UL<<SYSCFG_LEDCFG_PC_ENSEG_Pos)               /*!< 0x40000000 */
#define SYSCFG_LEDCFG_PC_ENSEG_1                  (0x2UL<<SYSCFG_LEDCFG_PC_ENSEG_Pos)               /*!< 0x80000000 */

/********************************* Bit definition for PA_ANA2EN_REG register ****************************************/
#define SFSCFG_PA_ANA2EN_REG_PA_ANA2EN_Pos        (0U)
#define SFSCFG_PA_ANA2EN_REG_PA_ANA2EN_Msk        (0xFFFFUL<<SFSCFG_PA_ANA2EN_REG_PA_ANA2EN_Pos)           /*!< 0x0000FFFF */
#define SFSCFG_PA_ANA2EN_REG_PA_ANA2EN            SFSCFG_PA_ANA2EN_REG_PA_ANA2EN_Msk

/********************************* Bit definition for PB_ANA2EN_REG register ****************************************/
#define SYSCFG_PB_ANA2EN_REG_PB_ANA2EN_Pos        (0U)
#define SYSCFG_PB_ANA2EN_REG_PB_ANA2EN_Msk        (0xFFFFUL<<SYSCFG_PB_ANA2EN_REG_PB_ANA2EN_Pos)           /*!< 0x0000FFFF */
#define SYSCFG_PB_ANA2EN_REG_PB_ANA2EN            SYSCFG_PB_ANA2EN_REG_PB_ANA2EN_Msk

/********************************* Bit definition for PC_ANA2EN_REG register ****************************************/
#define SYSCFG_PC_ANA2EN_REG_PC_ANA2EN_Pos        (0U)
#define SYSCFG_PC_ANA2EN_REG_PC_ANA2EN_Msk        (0xFFFFUL<<SYSCFG_PC_ANA2EN_REG_PC_ANA2EN_Pos)           /*!< 0x0000FFFF */
#define SYSCFG_PC_ANA2EN_REG_PC_ANA2EN            SYSCFG_PC_ANA2EN_REG_PC_ANA2EN_Msk

/********************************* Bit definition for PD_ANA2EN_REG register ****************************************/
#define SYSCFG_PD_ANA2EN_REG_PD_ANA2EN_Pos        (0U)
#define SYSCFG_PD_ANA2EN_REG_PD_ANA2EN_Msk        (0xFFFFUL<<SYSCFG_PD_ANA2EN_REG_PD_ANA2EN_Pos)           /*!< 0x0000FFFF */
#define SYSCFG_PD_ANA2EN_REG_PD_ANA2EN            SYSCFG_PD_ANA2EN_REG_PD_ANA2EN_Msk

/********************************* Bit definition for SYSCFG_SCSR register ******************************************/
#define SYSCFG_SCSR_PERR_RSTEN_Pos                (0U)
#define SYSCFG_SCSR_PERR_RSTEN_Msk                (0x1UL<<SYSCFG_SCSR_PERR_RSTEN_Pos)               /*!< 0x00000001 */
#define SYSCFG_SCSR_PERR_RSTEN                    SYSCFG_SCSR_PERR_RSTEN_Msk                        
#define SYSCFG_SCSR_SPF_Pos                       (8U)
#define SYSCFG_SCSR_SPF_Msk                       (0x1UL<<SYSCFG_SCSR_SPF_Pos)                      /*!< 0x00000100 */
#define SYSCFG_SCSR_SPF                           SYSCFG_SCSR_SPF_Msk                               

/********************************* Bit definition for SYSCFG_SWPR register ******************************************/
#define SYSCFG_SWPR_SRAM_P0WP_Pos                 (0U)
#define SYSCFG_SWPR_SRAM_P0WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P0WP_Pos)       
#define SYSCFG_SWPR_SRAM_P0WP                     SYSCFG_SWPR_SRAM_P0WP_Msk
#define SYSCFG_SWPR_SRAM_P1WP_Pos                 (1U)
#define SYSCFG_SWPR_SRAM_P1WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P1WP_Pos)       
#define SYSCFG_SWPR_SRAM_P1WP                     SYSCFG_SWPR_SRAM_P1WP_Msk
#define SYSCFG_SWPR_SRAM_P2WP_Pos                 (2U)
#define SYSCFG_SWPR_SRAM_P2WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P2WP_Pos)       
#define SYSCFG_SWPR_SRAM_P2WP                     SYSCFG_SWPR_SRAM_P2WP_Msk
#define SYSCFG_SWPR_SRAM_P3WP_Pos                 (3U)
#define SYSCFG_SWPR_SRAM_P3WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P3WP_Pos)       
#define SYSCFG_SWPR_SRAM_P3WP                     SYSCFG_SWPR_SRAM_P3WP_Msk
#define SYSCFG_SWPR_SRAM_P4WP_Pos                 (4U)
#define SYSCFG_SWPR_SRAM_P4WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P4WP_Pos)       
#define SYSCFG_SWPR_SRAM_P4WP                     SYSCFG_SWPR_SRAM_P4WP_Msk
#define SYSCFG_SWPR_SRAM_P5WP_Pos                 (5U)
#define SYSCFG_SWPR_SRAM_P5WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P5WP_Pos)       
#define SYSCFG_SWPR_SRAM_P5WP                     SYSCFG_SWPR_SRAM_P5WP_Msk
#define SYSCFG_SWPR_SRAM_P6WP_Pos                 (6U)
#define SYSCFG_SWPR_SRAM_P6WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P6WP_Pos)       
#define SYSCFG_SWPR_SRAM_P6WP                     SYSCFG_SWPR_SRAM_P6WP_Msk
#define SYSCFG_SWPR_SRAM_P7WP_Pos                 (7U)
#define SYSCFG_SWPR_SRAM_P7WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P7WP_Pos)       
#define SYSCFG_SWPR_SRAM_P7WP                     SYSCFG_SWPR_SRAM_P7WP_Msk
#define SYSCFG_SWPR_SRAM_P8WP_Pos                 (8U)
#define SYSCFG_SWPR_SRAM_P8WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P8WP_Pos)       
#define SYSCFG_SWPR_SRAM_P8WP                     SYSCFG_SWPR_SRAM_P8WP_Msk
#define SYSCFG_SWPR_SRAM_P9WP_Pos                 (9U)
#define SYSCFG_SWPR_SRAM_P9WP_Msk                 (0x1UL<<SYSCFG_SWPR_SRAM_P9WP_Pos)       
#define SYSCFG_SWPR_SRAM_P9WP                     SYSCFG_SWPR_SRAM_P9WP_Msk
#define SYSCFG_SWPR_SRAM_P10WP_Pos                (10U)
#define SYSCFG_SWPR_SRAM_P10WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P10WP_Pos)       
#define SYSCFG_SWPR_SRAM_P10WP                    SYSCFG_SWPR_SRAM_P10WP_Msk
#define SYSCFG_SWPR_SRAM_P11WP_Pos                (11U)
#define SYSCFG_SWPR_SRAM_P11WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P11WP_Pos)       
#define SYSCFG_SWPR_SRAM_P11WP                    SYSCFG_SWPR_SRAM_P11WP_Msk
#define SYSCFG_SWPR_SRAM_P12WP_Pos                (12U)
#define SYSCFG_SWPR_SRAM_P12WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P12WP_Pos)       
#define SYSCFG_SWPR_SRAM_P12WP                    SYSCFG_SWPR_SRAM_P12WP_Msk
#define SYSCFG_SWPR_SRAM_P13WP_Pos                (13U)
#define SYSCFG_SWPR_SRAM_P13WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P13WP_Pos)       
#define SYSCFG_SWPR_SRAM_P13WP                    SYSCFG_SWPR_SRAM_P13WP_Msk
#define SYSCFG_SWPR_SRAM_P14WP_Pos                (14U)
#define SYSCFG_SWPR_SRAM_P14WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P14WP_Pos)       
#define SYSCFG_SWPR_SRAM_P14WP                    SYSCFG_SWPR_SRAM_P14WP_Msk
#define SYSCFG_SWPR_SRAM_P15WP_Pos                (15U)
#define SYSCFG_SWPR_SRAM_P15WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P15WP_Pos)       
#define SYSCFG_SWPR_SRAM_P15WP                    SYSCFG_SWPR_SRAM_P15WP_Msk
#define SYSCFG_SWPR_SRAM_P16WP_Pos                (16U)
#define SYSCFG_SWPR_SRAM_P16WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P16WP_Pos)       
#define SYSCFG_SWPR_SRAM_P16WP                    SYSCFG_SWPR_SRAM_P16WP_Msk
#define SYSCFG_SWPR_SRAM_P17WP_Pos                (17U)
#define SYSCFG_SWPR_SRAM_P17WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P17WP_Pos)       
#define SYSCFG_SWPR_SRAM_P17WP                    SYSCFG_SWPR_SRAM_P17WP_Msk
#define SYSCFG_SWPR_SRAM_P18WP_Pos                (18U)
#define SYSCFG_SWPR_SRAM_P18WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P18WP_Pos)       
#define SYSCFG_SWPR_SRAM_P18WP                    SYSCFG_SWPR_SRAM_P18WP_Msk
#define SYSCFG_SWPR_SRAM_P19WP_Pos                (19U)
#define SYSCFG_SWPR_SRAM_P19WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P19WP_Pos)       
#define SYSCFG_SWPR_SRAM_P19WP                    SYSCFG_SWPR_SRAM_P19WP_Msk
#define SYSCFG_SWPR_SRAM_P20WP_Pos                (20U)
#define SYSCFG_SWPR_SRAM_P20WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P20WP_Pos)       
#define SYSCFG_SWPR_SRAM_P20WP                    SYSCFG_SWPR_SRAM_P20WP_Msk
#define SYSCFG_SWPR_SRAM_P21WP_Pos                (21U)
#define SYSCFG_SWPR_SRAM_P21WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P21WP_Pos)       
#define SYSCFG_SWPR_SRAM_P21WP                    SYSCFG_SWPR_SRAM_P21WP_Msk
#define SYSCFG_SWPR_SRAM_P22WP_Pos                (22U)
#define SYSCFG_SWPR_SRAM_P22WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P22WP_Pos)       
#define SYSCFG_SWPR_SRAM_P22WP                    SYSCFG_SWPR_SRAM_P22WP_Msk
#define SYSCFG_SWPR_SRAM_P23WP_Pos                (23U)
#define SYSCFG_SWPR_SRAM_P23WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P23WP_Pos)       
#define SYSCFG_SWPR_SRAM_P23WP                    SYSCFG_SWPR_SRAM_P23WP_Msk
#define SYSCFG_SWPR_SRAM_P24WP_Pos                (24U)
#define SYSCFG_SWPR_SRAM_P24WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P24WP_Pos)       
#define SYSCFG_SWPR_SRAM_P24WP                    SYSCFG_SWPR_SRAM_P24WP_Msk
#define SYSCFG_SWPR_SRAM_P25WP_Pos                (25U)
#define SYSCFG_SWPR_SRAM_P25WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P25WP_Pos)       
#define SYSCFG_SWPR_SRAM_P25WP                    SYSCFG_SWPR_SRAM_P25WP_Msk
#define SYSCFG_SWPR_SRAM_P26WP_Pos                (26U)
#define SYSCFG_SWPR_SRAM_P26WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P26WP_Pos)       
#define SYSCFG_SWPR_SRAM_P26WP                    SYSCFG_SWPR_SRAM_P26WP_Msk
#define SYSCFG_SWPR_SRAM_P27WP_Pos                (27U)
#define SYSCFG_SWPR_SRAM_P27WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P27WP_Pos)       
#define SYSCFG_SWPR_SRAM_P27WP                    SYSCFG_SWPR_SRAM_P27WP_Msk
#define SYSCFG_SWPR_SRAM_P28WP_Pos                (28U)
#define SYSCFG_SWPR_SRAM_P28WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P28WP_Pos)       
#define SYSCFG_SWPR_SRAM_P28WP                    SYSCFG_SWPR_SRAM_P28WP_Msk
#define SYSCFG_SWPR_SRAM_P29WP_Pos                (29U)
#define SYSCFG_SWPR_SRAM_P29WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P29WP_Pos)       
#define SYSCFG_SWPR_SRAM_P29WP                    SYSCFG_SWPR_SRAM_P29WP_Msk
#define SYSCFG_SWPR_SRAM_P30WP_Pos                (30U)
#define SYSCFG_SWPR_SRAM_P30WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P30WP_Pos)       
#define SYSCFG_SWPR_SRAM_P30WP                    SYSCFG_SWPR_SRAM_P30WP_Msk
#define SYSCFG_SWPR_SRAM_P31WP_Pos                (31U)
#define SYSCFG_SWPR_SRAM_P31WP_Msk                (0x1UL<<SYSCFG_SWPR_SRAM_P31WP_Pos)       
#define SYSCFG_SWPR_SRAM_P31WP                    SYSCFG_SWPR_SRAM_P31WP_Msk


/********************************************************************************************************************/
/********************************* TIM1 *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for TIM_CR1 register *********************************************/
#define TIM_CR1_CEN_Pos                          (0U)
#define TIM_CR1_CEN_Msk                          (0x1UL << TIM_CR1_CEN_Pos)                    /*!< 0x00000001 */
#define TIM_CR1_CEN                              TIM_CR1_CEN_Msk                               /*!<Counter enable */
#define TIM_CR1_UDIS_Pos                         (1U)
#define TIM_CR1_UDIS_Msk                         (0x1UL << TIM_CR1_UDIS_Pos)                   /*!< 0x00000002 */
#define TIM_CR1_UDIS                             TIM_CR1_UDIS_Msk                              /*!<Update disable */
#define TIM_CR1_URS_Pos                          (2U)
#define TIM_CR1_URS_Msk                          (0x1UL << TIM_CR1_URS_Pos)                    /*!< 0x00000004 */
#define TIM_CR1_URS                              TIM_CR1_URS_Msk                               /*!<Update request source */
#define TIM_CR1_OPM_Pos                          (3U)
#define TIM_CR1_OPM_Msk                          (0x1UL << TIM_CR1_OPM_Pos)                    /*!< 0x00000008 */
#define TIM_CR1_OPM                              TIM_CR1_OPM_Msk                               /*!<One pulse mode */
#define TIM_CR1_DIR_Pos                          (4U)
#define TIM_CR1_DIR_Msk                          (0x1UL << TIM_CR1_DIR_Pos)                    /*!< 0x00000010 */
#define TIM_CR1_DIR                              TIM_CR1_DIR_Msk                               /*!<Direction */
#define TIM_CR1_CMS_Pos                          (5U)
#define TIM_CR1_CMS_Msk                          (0x3UL << TIM_CR1_CMS_Pos)                    /*!< 0x00000060 */
#define TIM_CR1_CMS                              TIM_CR1_CMS_Msk                               /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0                            (0x1UL << TIM_CR1_CMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR1_CMS_1                            (0x2UL << TIM_CR1_CMS_Pos)                    /*!< 0x00000040 */
#define TIM_CR1_ARPE_Pos                         (7U)
#define TIM_CR1_ARPE_Msk                         (0x1UL << TIM_CR1_ARPE_Pos)                   /*!< 0x00000080 */
#define TIM_CR1_ARPE                             TIM_CR1_ARPE_Msk                              /*!<Auto-reload preload enable */
#define TIM_CR1_CKD_Pos                          (8U)
#define TIM_CR1_CKD_Msk                          (0x3UL << TIM_CR1_CKD_Pos)                    /*!< 0x00000300 */
#define TIM_CR1_CKD                              TIM_CR1_CKD_Msk                               /*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0                            (0x1UL << TIM_CR1_CKD_Pos)                    /*!< 0x00000100 */
#define TIM_CR1_CKD_1                            (0x2UL << TIM_CR1_CKD_Pos)                    /*!< 0x00000200 */

/********************************* Bit definition for TIM_CR2 register *********************************************/
#define TIM_CR2_CCPC_Pos                         (0U)
#define TIM_CR2_CCPC_Msk                         (0x1UL << TIM_CR2_CCPC_Pos)                   /*!< 0x00000001 */
#define TIM_CR2_CCPC                             TIM_CR2_CCPC_Msk                              /*!<Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos                         (2U)
#define TIM_CR2_CCUS_Msk                         (0x1UL << TIM_CR2_CCUS_Pos)                   /*!< 0x00000004 */
#define TIM_CR2_CCUS                             TIM_CR2_CCUS_Msk                              /*!<Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos                         (3U)
#define TIM_CR2_CCDS_Msk                         (0x1UL << TIM_CR2_CCDS_Pos)                   /*!< 0x00000008 */
#define TIM_CR2_CCDS                             TIM_CR2_CCDS_Msk                              /*!<Capture/Compare DMA Selection */
#define TIM_CR2_MMS_Pos                          (4U)
#define TIM_CR2_MMS_Msk                          (0x200007UL << TIM_CR2_MMS_Pos)               /*!< 0x02000070 */
#define TIM_CR2_MMS                              TIM_CR2_MMS_Msk
#define TIM_CR2_MMS_0                            (0x000001UL << TIM_CR2_MMS_Pos)               /*!< 0x00000010 */
#define TIM_CR2_MMS_1                            (0x000002UL << TIM_CR2_MMS_Pos)               /*!< 0x00000020 */
#define TIM_CR2_MMS_2                            (0x000004UL << TIM_CR2_MMS_Pos)               /*!< 0x00000040 */
#define TIM_CR2_MMS_3                            (0x200000UL << TIM_CR2_MMS_Pos)               /*!< 0x02000000 */
#define TIM_CR2_TI1S_Pos                         (7U)
#define TIM_CR2_TI1S_Msk                         (0x1UL << TIM_CR2_TI1S_Pos)                   /*!< 0x00000080 */
#define TIM_CR2_TI1S                             TIM_CR2_TI1S_Msk                              /*!<TI1 Selection */
#define TIM_CR2_OIS1_Pos                         (8U)
#define TIM_CR2_OIS1_Msk                         (0x1UL << TIM_CR2_OIS1_Pos)                   /*!< 0x00000100 */
#define TIM_CR2_OIS1                             TIM_CR2_OIS1_Msk                              /*!<Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos                        (9U)
#define TIM_CR2_OIS1N_Msk                        (0x1UL << TIM_CR2_OIS1N_Pos)                  /*!< 0x00000200 */
#define TIM_CR2_OIS1N                            TIM_CR2_OIS1N_Msk                             /*!<Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos                         (10U)
#define TIM_CR2_OIS2_Msk                         (0x1UL << TIM_CR2_OIS2_Pos)                   /*!< 0x00000400 */
#define TIM_CR2_OIS2                             TIM_CR2_OIS2_Msk                              /*!<Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos                        (11U)
#define TIM_CR2_OIS2N_Msk                        (0x1UL << TIM_CR2_OIS2N_Pos)                  /*!< 0x00000800 */
#define TIM_CR2_OIS2N                            TIM_CR2_OIS2N_Msk                             /*!<Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos                         (12U)
#define TIM_CR2_OIS3_Msk                         (0x1UL << TIM_CR2_OIS3_Pos)                   /*!< 0x00001000 */
#define TIM_CR2_OIS3                             TIM_CR2_OIS3_Msk                              /*!<Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos                        (13U)
#define TIM_CR2_OIS3N_Msk                        (0x1UL << TIM_CR2_OIS3N_Pos)                  /*!< 0x00002000 */
#define TIM_CR2_OIS3N                            TIM_CR2_OIS3N_Msk                             /*!<Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos                         (14U)
#define TIM_CR2_OIS4_Msk                         (0x1UL << TIM_CR2_OIS4_Pos)                   /*!< 0x00004000 */
#define TIM_CR2_OIS4                             TIM_CR2_OIS4_Msk                              /*!<Output Idle state 4 (OC4 output) */

/********************************* Bit definition for TIM_SMCR register ********************************************/
#define TIM_SMCR_SMS_Pos                         (0U)
#define TIM_SMCR_SMS_Msk                         (0x00010007UL<<TIM_SMCR_SMS_Pos)                 /*!< 0x00010007 */
#define TIM_SMCR_SMS                             TIM_SMCR_SMS_Msk
#define TIM_SMCR_SMS_0                           (0x1UL<<TIM_SMCR_SMS_Pos)                        /*!< 0x00000001 */
#define TIM_SMCR_SMS_1                           (0x2UL<<TIM_SMCR_SMS_Pos)                        /*!< 0x00000002 */
#define TIM_SMCR_SMS_2                           (0x4UL<<TIM_SMCR_SMS_Pos)                        /*!< 0x00000004 */
#define TIM_SMCR_SMS_3                           (0x10000UL<<TIM_SMCR_SMS_Pos)                    /*!< 0x00010000 */
#define TIM_SMCR_OCCS_Pos                        (3U)
#define TIM_SMCR_OCCS_Msk                        (0x1UL<<TIM_SMCR_OCCS_Pos)                       /*!< 0x00000008 */
#define TIM_SMCR_OCCS                            TIM_SMCR_OCCS_Msk                                
#define TIM_SMCR_TS_Pos                          (4U)
#define TIM_SMCR_TS_Msk                          (0x30007UL<<TIM_SMCR_TS_Pos)                     /*!< 0x00300070 */
#define TIM_SMCR_TS                              TIM_SMCR_TS_Msk
#define TIM_SMCR_TS_0                            (0x1UL<<TIM_SMCR_TS_Pos)                         /*!< 0x00000010 */
#define TIM_SMCR_TS_1                            (0x2UL<<TIM_SMCR_TS_Pos)                         /*!< 0x00000020 */
#define TIM_SMCR_TS_2                            (0x4UL<<TIM_SMCR_TS_Pos)                         /*!< 0x00000040 */
#define TIM_SMCR_TS_3                            (0x10000UL<<TIM_SMCR_TS_Pos)                     /*!< 0x00100000 */
#define TIM_SMCR_TS_4                            (0x20000UL<<TIM_SMCR_TS_Pos)                     /*!< 0x00200000 */
#define TIM_SMCR_MSM_Pos                         (7U)
#define TIM_SMCR_MSM_Msk                         (0x1UL<<TIM_SMCR_MSM_Pos)                        /*!< 0x00000080 */
#define TIM_SMCR_MSM                             TIM_SMCR_MSM_Msk                                 
#define TIM_SMCR_ETF_Pos                         (8U)
#define TIM_SMCR_ETF_Msk                         (0xFUL<<TIM_SMCR_ETF_Pos)                        /*!< 0x00000F00 */
#define TIM_SMCR_ETF                             TIM_SMCR_ETF_Msk
#define TIM_SMCR_ETF_0                           (0x1UL<<TIM_SMCR_ETF_Pos)                        /*!< 0x00000100 */
#define TIM_SMCR_ETF_1                           (0x2UL<<TIM_SMCR_ETF_Pos)                        /*!< 0x00000200 */
#define TIM_SMCR_ETF_2                           (0x4UL<<TIM_SMCR_ETF_Pos)                        /*!< 0x00000400 */
#define TIM_SMCR_ETF_3                           (0x8UL<<TIM_SMCR_ETF_Pos)                        /*!< 0x00000800 */
#define TIM_SMCR_ETPS_Pos                        (12U)
#define TIM_SMCR_ETPS_Msk                        (0x3UL<<TIM_SMCR_ETPS_Pos)                       /*!< 0x00003000 */
#define TIM_SMCR_ETPS                            TIM_SMCR_ETPS_Msk
#define TIM_SMCR_ETPS_0                          (0x1UL<<TIM_SMCR_ETPS_Pos)                       /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1                          (0x2UL<<TIM_SMCR_ETPS_Pos)                       /*!< 0x00002000 */
#define TIM_SMCR_ECE_Pos                         (14U)
#define TIM_SMCR_ECE_Msk                         (0x1UL<<TIM_SMCR_ECE_Pos)                        /*!< 0x00004000 */
#define TIM_SMCR_ECE                             TIM_SMCR_ECE_Msk                                 
#define TIM_SMCR_ETP_Pos                         (15U)
#define TIM_SMCR_ETP_Msk                         (0x1UL<<TIM_SMCR_ETP_Pos)                        /*!< 0x00008000 */
#define TIM_SMCR_ETP                             TIM_SMCR_ETP_Msk                                

/********************************* Bit definition for TIM_DIER register ********************************************/
#define TIM_DIER_UIE_Pos                         (0U)
#define TIM_DIER_UIE_Msk                         (0x1UL << TIM_DIER_UIE_Pos)                   /*!< 0x00000001 */
#define TIM_DIER_UIE                             TIM_DIER_UIE_Msk                              /*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos                       (1U)
#define TIM_DIER_CC1IE_Msk                       (0x1UL << TIM_DIER_CC1IE_Pos)                 /*!< 0x00000002 */
#define TIM_DIER_CC1IE                           TIM_DIER_CC1IE_Msk                            /*!<Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos                       (2U)
#define TIM_DIER_CC2IE_Msk                       (0x1UL << TIM_DIER_CC2IE_Pos)                 /*!< 0x00000004 */
#define TIM_DIER_CC2IE                           TIM_DIER_CC2IE_Msk                            /*!<Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos                       (3U)
#define TIM_DIER_CC3IE_Msk                       (0x1UL << TIM_DIER_CC3IE_Pos)                 /*!< 0x00000008 */
#define TIM_DIER_CC3IE                           TIM_DIER_CC3IE_Msk                            /*!<Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos                       (4U)
#define TIM_DIER_CC4IE_Msk                       (0x1UL << TIM_DIER_CC4IE_Pos)                 /*!< 0x00000010 */
#define TIM_DIER_CC4IE                           TIM_DIER_CC4IE_Msk                            /*!<Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos                       (5U)
#define TIM_DIER_COMIE_Msk                       (0x1UL << TIM_DIER_COMIE_Pos)                 /*!< 0x00000020 */
#define TIM_DIER_COMIE                           TIM_DIER_COMIE_Msk                            /*!<COM interrupt enable */
#define TIM_DIER_TIE_Pos                         (6U)
#define TIM_DIER_TIE_Msk                         (0x1UL << TIM_DIER_TIE_Pos)                   /*!< 0x00000040 */
#define TIM_DIER_TIE                             TIM_DIER_TIE_Msk                              /*!<Trigger interrupt enable */
#define TIM_DIER_BIE_Pos                         (7U)
#define TIM_DIER_BIE_Msk                         (0x1UL << TIM_DIER_BIE_Pos)                   /*!< 0x00000080 */
#define TIM_DIER_BIE                             TIM_DIER_BIE_Msk                              /*!<Break interrupt enable */
#define TIM_DIER_UDE_Pos                         (8U)
#define TIM_DIER_UDE_Msk                         (0x1UL << TIM_DIER_UDE_Pos)                   /*!< 0x00000100 */
#define TIM_DIER_UDE                             TIM_DIER_UDE_Msk                              /*!<Update DMA request enable */
#define TIM_DIER_CC1DE_Pos                       (9U)
#define TIM_DIER_CC1DE_Msk                       (0x1UL << TIM_DIER_CC1DE_Pos)                 /*!< 0x00000200 */
#define TIM_DIER_CC1DE                           TIM_DIER_CC1DE_Msk                            /*!<Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos                       (10U)
#define TIM_DIER_CC2DE_Msk                       (0x1UL << TIM_DIER_CC2DE_Pos)                 /*!< 0x00000400 */
#define TIM_DIER_CC2DE                           TIM_DIER_CC2DE_Msk                            /*!<Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos                       (11U)
#define TIM_DIER_CC3DE_Msk                       (0x1UL << TIM_DIER_CC3DE_Pos)                 /*!< 0x00000800 */
#define TIM_DIER_CC3DE                           TIM_DIER_CC3DE_Msk                            /*!<Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos                       (12U)
#define TIM_DIER_CC4DE_Msk                       (0x1UL << TIM_DIER_CC4DE_Pos)                 /*!< 0x00001000 */
#define TIM_DIER_CC4DE                           TIM_DIER_CC4DE_Msk                            /*!<Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos                       (13U)
#define TIM_DIER_COMDE_Msk                       (0x1UL << TIM_DIER_COMDE_Pos)                 /*!< 0x00002000 */
#define TIM_DIER_COMDE                           TIM_DIER_COMDE_Msk                            /*!<COM DMA request enable */
#define TIM_DIER_TDE_Pos                         (14U)
#define TIM_DIER_TDE_Msk                         (0x1UL << TIM_DIER_TDE_Pos)                   /*!< 0x00004000 */
#define TIM_DIER_TDE                             TIM_DIER_TDE_Msk                              /*!<Trigger DMA request enable */       

/********************************* Bit definition for TIM_SR register **********************************************/
#define TIM_SR_UIF_Pos                           (0U)
#define TIM_SR_UIF_Msk                           (0x1UL<<TIM_SR_UIF_Pos)                          /*!< 0x00000001 */
#define TIM_SR_UIF                               TIM_SR_UIF_Msk                                   
#define TIM_SR_CC1IF_Pos                         (1U)
#define TIM_SR_CC1IF_Msk                         (0x1UL<<TIM_SR_CC1IF_Pos)                        /*!< 0x00000002 */
#define TIM_SR_CC1IF                             TIM_SR_CC1IF_Msk                                 
#define TIM_SR_CC2IF_Pos                         (2U)
#define TIM_SR_CC2IF_Msk                         (0x1UL<<TIM_SR_CC2IF_Pos)                        /*!< 0x00000004 */
#define TIM_SR_CC2IF                             TIM_SR_CC2IF_Msk                                 
#define TIM_SR_CC3IF_Pos                         (3U)
#define TIM_SR_CC3IF_Msk                         (0x1UL<<TIM_SR_CC3IF_Pos)                        /*!< 0x00000008 */
#define TIM_SR_CC3IF                             TIM_SR_CC3IF_Msk                                 
#define TIM_SR_CC4IF_Pos                         (4U)
#define TIM_SR_CC4IF_Msk                         (0x1UL<<TIM_SR_CC4IF_Pos)                        /*!< 0x00000010 */
#define TIM_SR_CC4IF                             TIM_SR_CC4IF_Msk                                 
#define TIM_SR_COMIF_Pos                         (5U)
#define TIM_SR_COMIF_Msk                         (0x1UL<<TIM_SR_COMIF_Pos)                        /*!< 0x00000020 */
#define TIM_SR_COMIF                             TIM_SR_COMIF_Msk                                 
#define TIM_SR_TIF_Pos                           (6U)
#define TIM_SR_TIF_Msk                           (0x1UL<<TIM_SR_TIF_Pos)                          /*!< 0x00000040 */
#define TIM_SR_TIF                               TIM_SR_TIF_Msk                                   
#define TIM_SR_BIF_Pos                           (7U)
#define TIM_SR_BIF_Msk                           (0x1UL<<TIM_SR_BIF_Pos)                          /*!< 0x00000080 */
#define TIM_SR_BIF                               TIM_SR_BIF_Msk                                                                   
#define TIM_SR_CC1OF_Pos                         (9U)
#define TIM_SR_CC1OF_Msk                         (0x1UL<<TIM_SR_CC1OF_Pos)                        /*!< 0x00000200 */
#define TIM_SR_CC1OF                             TIM_SR_CC1OF_Msk                                 
#define TIM_SR_CC2OF_Pos                         (10U)
#define TIM_SR_CC2OF_Msk                         (0x1UL<<TIM_SR_CC2OF_Pos)                        /*!< 0x00000400 */
#define TIM_SR_CC2OF                             TIM_SR_CC2OF_Msk                                 
#define TIM_SR_CC3OF_Pos                         (11U)
#define TIM_SR_CC3OF_Msk                         (0x1UL<<TIM_SR_CC3OF_Pos)                        /*!< 0x00000800 */
#define TIM_SR_CC3OF                             TIM_SR_CC3OF_Msk                                 
#define TIM_SR_CC4OF_Pos                         (12U)
#define TIM_SR_CC4OF_Msk                         (0x1UL<<TIM_SR_CC4OF_Pos)                        /*!< 0x00001000 */
#define TIM_SR_CC4OF                             TIM_SR_CC4OF_Msk                                 
#define TIM_SR_SBIF_Pos                          (13U)
#define TIM_SR_SBIF_Msk                          (0x1UL<<TIM_SR_SBIF_Pos)                         /*!< 0x00002000 */
#define TIM_SR_SBIF                              TIM_SR_SBIF_Msk                                                                
#define TIM_SR_IC1IR_Pos                         (18U)
#define TIM_SR_IC1IR_Msk                         (0x1UL<<TIM_SR_IC1IR_Pos)                        /*!< 0x00040000 */
#define TIM_SR_IC1IR                             TIM_SR_IC1IR_Msk                                 
#define TIM_SR_IC2IR_Pos                         (19U)
#define TIM_SR_IC2IR_Msk                         (0x1UL<<TIM_SR_IC2IR_Pos)                        /*!< 0x00080000 */
#define TIM_SR_IC2IR                             TIM_SR_IC2IR_Msk                                                              
#define TIM_SR_IC3IR_Pos                         (24U)
#define TIM_SR_IC3IR_Msk                         (0x1UL<<TIM_SR_IC3IR_Pos)                        /*!< 0x01000000 */
#define TIM_SR_IC3IR                             TIM_SR_IC3IR_Msk                                 
#define TIM_SR_IC4IR_Pos                         (25U)
#define TIM_SR_IC4IR_Msk                         (0x1UL<<TIM_SR_IC4IR_Pos)                        /*!< 0x02000000 */
#define TIM_SR_IC4IR                             TIM_SR_IC4IR_Msk                                 
#define TIM_SR_IC1IF_Pos                         (26U)
#define TIM_SR_IC1IF_Msk                         (0x1UL<<TIM_SR_IC1IF_Pos)                        /*!< 0x04000000 */
#define TIM_SR_IC1IF                             TIM_SR_IC1IF_Msk                                 
#define TIM_SR_IC2IF_Pos                         (27U)
#define TIM_SR_IC2IF_Msk                         (0x1UL<<TIM_SR_IC2IF_Pos)                        /*!< 0x08000000 */
#define TIM_SR_IC2IF                             TIM_SR_IC2IF_Msk                                 
#define TIM_SR_IC3IF_Pos                         (28U)
#define TIM_SR_IC3IF_Msk                         (0x1UL<<TIM_SR_IC3IF_Pos)                        /*!< 0x10000000 */
#define TIM_SR_IC3IF                             TIM_SR_IC3IF_Msk                                 
#define TIM_SR_IC4IF_Pos                         (29U)
#define TIM_SR_IC4IF_Msk                         (0x1UL<<TIM_SR_IC4IF_Pos)                        /*!< 0x20000000 */
#define TIM_SR_IC4IF                             TIM_SR_IC4IF_Msk                          

/********************************* Bit definition for TIM_EGR register *********************************************/
#define TIM_EGR_UG_Pos                           (0U)
#define TIM_EGR_UG_Msk                           (0x1UL << TIM_EGR_UG_Pos)                     /*!< 0x00000001 */
#define TIM_EGR_UG                               TIM_EGR_UG_Msk                                /*!<Update Generation */
#define TIM_EGR_CC1G_Pos                         (1U)
#define TIM_EGR_CC1G_Msk                         (0x1UL << TIM_EGR_CC1G_Pos)                   /*!< 0x00000002 */
#define TIM_EGR_CC1G                             TIM_EGR_CC1G_Msk                              /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos                         (2U)
#define TIM_EGR_CC2G_Msk                         (0x1UL << TIM_EGR_CC2G_Pos)                   /*!< 0x00000004 */
#define TIM_EGR_CC2G                             TIM_EGR_CC2G_Msk                              /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos                         (3U)
#define TIM_EGR_CC3G_Msk                         (0x1UL << TIM_EGR_CC3G_Pos)                   /*!< 0x00000008 */
#define TIM_EGR_CC3G                             TIM_EGR_CC3G_Msk                              /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos                         (4U)
#define TIM_EGR_CC4G_Msk                         (0x1UL << TIM_EGR_CC4G_Pos)                   /*!< 0x00000010 */
#define TIM_EGR_CC4G                             TIM_EGR_CC4G_Msk                              /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos                         (5U)
#define TIM_EGR_COMG_Msk                         (0x1UL << TIM_EGR_COMG_Pos)                   /*!< 0x00000020 */
#define TIM_EGR_COMG                             TIM_EGR_COMG_Msk                              /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos                           (6U)
#define TIM_EGR_TG_Msk                           (0x1UL << TIM_EGR_TG_Pos)                     /*!< 0x00000040 */
#define TIM_EGR_TG                               TIM_EGR_TG_Msk                                /*!<Trigger Generation */
#define TIM_EGR_BG_Pos                           (7U)
#define TIM_EGR_BG_Msk                           (0x1UL << TIM_EGR_BG_Pos)                     /*!< 0x00000080 */
#define TIM_EGR_BG                               TIM_EGR_BG_Msk                                /*!<Break Generation */                                  

/********************************* Bit definition for TIM_CCMR1 register *******************************************/
#define TIM_CCMR1_CC1S_Pos                       (0U)
#define TIM_CCMR1_CC1S_Msk                       (0x3UL << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000003 */
#define TIM_CCMR1_CC1S                           TIM_CCMR1_CC1S_Msk                            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0                         (0x1UL << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1                         (0x2UL << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR1_OC1FE_Pos                      (2U)
#define TIM_CCMR1_OC1FE_Msk                      (0x1UL << TIM_CCMR1_OC1FE_Pos)                /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE                          TIM_CCMR1_OC1FE_Msk                           /*!<Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos                      (3U)
#define TIM_CCMR1_OC1PE_Msk                      (0x1UL << TIM_CCMR1_OC1PE_Pos)                /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE                          TIM_CCMR1_OC1PE_Msk                           /*!<Output Compare 1 Preload enable */

#define TIM_CCMR1_OC1M_Pos                       (4U)
#define TIM_CCMR1_OC1M_Msk                       (0x1007UL << TIM_CCMR1_OC1M_Pos)              /*!< 0x00010070 */
#define TIM_CCMR1_OC1M                           TIM_CCMR1_OC1M_Msk                            /*!<OC1M[3:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_0                         (0x1UL << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1                         (0x2UL << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2                         (0x4UL << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR1_OC1M_3                         (0x1000UL << TIM_CCMR1_OC1M_Pos)              /*!< 0x00010000 */

#define TIM_CCMR1_OC1CE_Pos                      (7U)
#define TIM_CCMR1_OC1CE_Msk                      (0x1UL << TIM_CCMR1_OC1CE_Pos)                /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE                          TIM_CCMR1_OC1CE_Msk                           /*!<Output Compare 1Clear Enable */

#define TIM_CCMR1_CC2S_Pos                       (8U)
#define TIM_CCMR1_CC2S_Msk                       (0x3UL << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000300 */
#define TIM_CCMR1_CC2S                           TIM_CCMR1_CC2S_Msk                            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0                         (0x1UL << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1                         (0x2UL << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR1_OC2FE_Pos                      (10U)
#define TIM_CCMR1_OC2FE_Msk                      (0x1UL << TIM_CCMR1_OC2FE_Pos)                /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE                          TIM_CCMR1_OC2FE_Msk                           /*!<Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos                      (11U)
#define TIM_CCMR1_OC2PE_Msk                      (0x1UL << TIM_CCMR1_OC2PE_Pos)                /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE                          TIM_CCMR1_OC2PE_Msk                           /*!<Output Compare 2 Preload enable */

#define TIM_CCMR1_OC2M_Pos                       (12U)
#define TIM_CCMR1_OC2M_Msk                       (0x1007UL << TIM_CCMR1_OC2M_Pos)              /*!< 0x01007000 */
#define TIM_CCMR1_OC2M                           TIM_CCMR1_OC2M_Msk                            /*!<OC2M[3:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_0                         (0x1UL << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1                         (0x2UL << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2                         (0x4UL << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR1_OC2M_3                         (0x1000UL << TIM_CCMR1_OC2M_Pos)              /*!< 0x01000000 */

#define TIM_CCMR1_OC2CE_Pos                      (15U)
#define TIM_CCMR1_OC2CE_Msk                      (0x1UL << TIM_CCMR1_OC2CE_Pos)                /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE                          TIM_CCMR1_OC2CE_Msk                           /*!<Output Compare 2 Clear Enable */

/*---------------------------------------------------------------------------*/
#define TIM_CCMR1_IC1PSC_Pos                     (2U)
#define TIM_CCMR1_IC1PSC_Msk                     (0x3UL << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC                         TIM_CCMR1_IC1PSC_Msk                          /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_0                       (0x1UL << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1                       (0x2UL << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000008 */

#define TIM_CCMR1_IC1F_Pos                       (4U)
#define TIM_CCMR1_IC1F_Msk                       (0xFUL << TIM_CCMR1_IC1F_Pos)                 /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F                           TIM_CCMR1_IC1F_Msk                            /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0                         (0x1UL << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1                         (0x2UL << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2                         (0x4UL << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3                         (0x8UL << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000080 */

#define TIM_CCMR1_IC2PSC_Pos                     (10U)
#define TIM_CCMR1_IC2PSC_Msk                     (0x3UL << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC                         TIM_CCMR1_IC2PSC_Msk                          /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_0                       (0x1UL << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1                       (0x2UL << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000800 */

#define TIM_CCMR1_IC2F_Pos                       (12U)
#define TIM_CCMR1_IC2F_Msk                       (0xFUL << TIM_CCMR1_IC2F_Pos)                 /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F                           TIM_CCMR1_IC2F_Msk                            /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0                         (0x1UL << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1                         (0x2UL << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2                         (0x4UL << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3                         (0x8UL << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00008000 */

/********************************* Bit definition for TIM_CCMR2 register ********************************************/
#define TIM_CCMR2_CC3S_Pos                       (0U)
#define TIM_CCMR2_CC3S_Msk                       (0x3UL << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000003 */
#define TIM_CCMR2_CC3S                           TIM_CCMR2_CC3S_Msk                            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_0                         (0x1UL << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1                         (0x2UL << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000002 */
               
#define TIM_CCMR2_OC3FE_Pos                      (2U)
#define TIM_CCMR2_OC3FE_Msk                      (0x1UL << TIM_CCMR2_OC3FE_Pos)                /*!< 0x00000004 */
#define TIM_CCMR2_OC3FE                          TIM_CCMR2_OC3FE_Msk                           /*!<Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos                      (3U)
#define TIM_CCMR2_OC3PE_Msk                      (0x1UL << TIM_CCMR2_OC3PE_Pos)                /*!< 0x00000008 */
#define TIM_CCMR2_OC3PE                          TIM_CCMR2_OC3PE_Msk                           /*!<Output Compare 3 Preload enable */
               
#define TIM_CCMR2_OC3M_Pos                       (4U)
#define TIM_CCMR2_OC3M_Msk                       (0x1007UL << TIM_CCMR2_OC3M_Pos)              /*!< 0x00010070 */
#define TIM_CCMR2_OC3M                           TIM_CCMR2_OC3M_Msk                            /*!<OC3M[3:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_0                         (0x1UL << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1                         (0x2UL << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2                         (0x4UL << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR2_OC3M_3                         (0x1000UL << TIM_CCMR2_OC3M_Pos)              /*!< 0x00010000 */
               
#define TIM_CCMR2_OC3CE_Pos                      (7U)
#define TIM_CCMR2_OC3CE_Msk                      (0x1UL << TIM_CCMR2_OC3CE_Pos)                /*!< 0x00000080 */
#define TIM_CCMR2_OC3CE                          TIM_CCMR2_OC3CE_Msk                           /*!<Output Compare 3 Clear Enable */
               
#define TIM_CCMR2_CC4S_Pos                       (8U)
#define TIM_CCMR2_CC4S_Msk                       (0x3UL << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000300 */
#define TIM_CCMR2_CC4S                           TIM_CCMR2_CC4S_Msk                            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_0                         (0x1UL << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1                         (0x2UL << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000200 */
               
#define TIM_CCMR2_OC4FE_Pos                      (10U)
#define TIM_CCMR2_OC4FE_Msk                      (0x1UL << TIM_CCMR2_OC4FE_Pos)                /*!< 0x00000400 */
#define TIM_CCMR2_OC4FE                          TIM_CCMR2_OC4FE_Msk                           /*!<Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos                      (11U)
#define TIM_CCMR2_OC4PE_Msk                      (0x1UL << TIM_CCMR2_OC4PE_Pos)                /*!< 0x00000800 */
#define TIM_CCMR2_OC4PE                          TIM_CCMR2_OC4PE_Msk                           /*!<Output Compare 4 Preload enable */
               
#define TIM_CCMR2_OC4M_Pos                       (12U)
#define TIM_CCMR2_OC4M_Msk                       (0x1007UL << TIM_CCMR2_OC4M_Pos)              /*!< 0x01007000 */
#define TIM_CCMR2_OC4M                           TIM_CCMR2_OC4M_Msk                            /*!<OC4M[3:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_0                         (0x1UL << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1                         (0x2UL << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2                         (0x4UL << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR2_OC4M_3                         (0x1000UL << TIM_CCMR2_OC4M_Pos)              /*!< 0x01000000 */
               
#define TIM_CCMR2_OC4CE_Pos                      (15U)
#define TIM_CCMR2_OC4CE_Msk                      (0x1UL << TIM_CCMR2_OC4CE_Pos)                /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE                          TIM_CCMR2_OC4CE_Msk                           /*!<Output Compare 4 Clear Enable */

/*---------------------------------------------------------------------------*/
#define TIM_CCMR2_IC3PSC_Pos                     (2U)
#define TIM_CCMR2_IC3PSC_Msk                     (0x3UL << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC                         TIM_CCMR2_IC3PSC_Msk                          /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0                       (0x1UL << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1                       (0x2UL << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000008 */
              
#define TIM_CCMR2_IC3F_Pos                       (4U)
#define TIM_CCMR2_IC3F_Msk                       (0xFUL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F                           TIM_CCMR2_IC3F_Msk                            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0                         (0x1UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1                         (0x2UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2                         (0x4UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3                         (0x8UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000080 */
              
#define TIM_CCMR2_IC4PSC_Pos                     (10U)
#define TIM_CCMR2_IC4PSC_Msk                     (0x3UL << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC                         TIM_CCMR2_IC4PSC_Msk                          /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0                       (0x1UL << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1                       (0x2UL << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000800 */
              
#define TIM_CCMR2_IC4F_Pos                       (12U)
#define TIM_CCMR2_IC4F_Msk                       (0xFUL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F                           TIM_CCMR2_IC4F_Msk                            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0                         (0x1UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1                         (0x2UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2                         (0x4UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3                         (0x8UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00008000 */

/********************************* Bit definition for TIM_CCER register *********************************************/
#define TIM_CCER_CC1E_Pos                        (0U)
#define TIM_CCER_CC1E_Msk                        (0x1UL << TIM_CCER_CC1E_Pos)                  /*!< 0x00000001 */
#define TIM_CCER_CC1E                            TIM_CCER_CC1E_Msk                             /*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos                        (1U)
#define TIM_CCER_CC1P_Msk                        (0x1UL << TIM_CCER_CC1P_Pos)                  /*!< 0x00000002 */
#define TIM_CCER_CC1P                            TIM_CCER_CC1P_Msk                             /*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos                       (2U)
#define TIM_CCER_CC1NE_Msk                       (0x1UL << TIM_CCER_CC1NE_Pos)                 /*!< 0x00000004 */
#define TIM_CCER_CC1NE                           TIM_CCER_CC1NE_Msk                            /*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos                       (3U)
#define TIM_CCER_CC1NP_Msk                       (0x1UL << TIM_CCER_CC1NP_Pos)                 /*!< 0x00000008 */
#define TIM_CCER_CC1NP                           TIM_CCER_CC1NP_Msk                            /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos                        (4U)
#define TIM_CCER_CC2E_Msk                        (0x1UL << TIM_CCER_CC2E_Pos)                  /*!< 0x00000010 */
#define TIM_CCER_CC2E                            TIM_CCER_CC2E_Msk                             /*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos                        (5U)
#define TIM_CCER_CC2P_Msk                        (0x1UL << TIM_CCER_CC2P_Pos)                  /*!< 0x00000020 */
#define TIM_CCER_CC2P                            TIM_CCER_CC2P_Msk                             /*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos                       (6U)
#define TIM_CCER_CC2NE_Msk                       (0x1UL << TIM_CCER_CC2NE_Pos)                 /*!< 0x00000040 */
#define TIM_CCER_CC2NE                           TIM_CCER_CC2NE_Msk                            /*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos                       (7U)
#define TIM_CCER_CC2NP_Msk                       (0x1UL << TIM_CCER_CC2NP_Pos)                 /*!< 0x00000080 */
#define TIM_CCER_CC2NP                           TIM_CCER_CC2NP_Msk                            /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos                        (8U)
#define TIM_CCER_CC3E_Msk                        (0x1UL << TIM_CCER_CC3E_Pos)                  /*!< 0x00000100 */
#define TIM_CCER_CC3E                            TIM_CCER_CC3E_Msk                             /*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos                        (9U)
#define TIM_CCER_CC3P_Msk                        (0x1UL << TIM_CCER_CC3P_Pos)                  /*!< 0x00000200 */
#define TIM_CCER_CC3P                            TIM_CCER_CC3P_Msk                             /*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos                       (10U)
#define TIM_CCER_CC3NE_Msk                       (0x1UL << TIM_CCER_CC3NE_Pos)                 /*!< 0x00000400 */
#define TIM_CCER_CC3NE                           TIM_CCER_CC3NE_Msk                            /*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos                       (11U)
#define TIM_CCER_CC3NP_Msk                       (0x1UL << TIM_CCER_CC3NP_Pos)                 /*!< 0x00000800 */
#define TIM_CCER_CC3NP                           TIM_CCER_CC3NP_Msk                            /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos                        (12U)
#define TIM_CCER_CC4E_Msk                        (0x1UL << TIM_CCER_CC4E_Pos)                  /*!< 0x00001000 */
#define TIM_CCER_CC4E                            TIM_CCER_CC4E_Msk                             /*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos                        (13U)
#define TIM_CCER_CC4P_Msk                        (0x1UL << TIM_CCER_CC4P_Pos)                  /*!< 0x00002000 */
#define TIM_CCER_CC4P                            TIM_CCER_CC4P_Msk                             /*!<Capture/Compare 4 output Polarity */                      

/********************************* Bit definition for TIM_CNT register *********************************************/
#define TIM_CNT_CNT_Pos                          (0U)
#define TIM_CNT_CNT_Msk                          (0xFFFFUL<<TIM_CNT_CNT_Pos)                      /*!< 0x0000FFFF */
#define TIM_CNT_CNT                              TIM_CNT_CNT_Msk

/********************************* Bit definition for TIM_PSC register *********************************************/
#define TIM_PSC_PSC_Pos                          (0U)
#define TIM_PSC_PSC_Msk                          (0xFFFFUL<<TIM_PSC_PSC_Pos)                      /*!< 0x0000FFFF */
#define TIM_PSC_PSC                              TIM_PSC_PSC_Msk

/********************************* Bit definition for TIM_ARR register *********************************************/
#define TIM_ARR_ARR_Pos                          (0U)
#define TIM_ARR_ARR_Msk                          (0xFFFFUL<<TIM_ARR_ARR_Pos)                      /*!< 0x0000FFFF */
#define TIM_ARR_ARR                              TIM_ARR_ARR_Msk

/********************************* Bit definition for TIM_RCR register *********************************************/
#define TIM_RCR_REP_Pos                          (0U)
#define TIM_RCR_REP_Msk                          (0xFFUL<<TIM_RCR_REP_Pos)                        /*!< 0x000000FF */
#define TIM_RCR_REP                              TIM_RCR_REP_Msk

/********************************* Bit definition for TIM_CCR1 register ********************************************/
#define TIM_CCR1_CCR1_Pos                        (0U)
#define TIM_CCR1_CCR1_Msk                        (0xFFFFUL<<TIM_CCR1_CCR1_Pos)                    /*!< 0x0000FFFF */
#define TIM_CCR1_CCR1                            TIM_CCR1_CCR1_Msk

/********************************* Bit definition for TIM_CCR2 register ********************************************/
#define TIM_CCR2_CCR2_Pos                        (0U)
#define TIM_CCR2_CCR2_Msk                        (0xFFFFUL<<TIM_CCR2_CCR2_Pos)                    /*!< 0x0000FFFF */
#define TIM_CCR2_CCR2                            TIM_CCR2_CCR2_Msk

/********************************* Bit definition for TIM_CCR3 register ********************************************/
#define TIM_CCR3_CCR3_Pos                        (0U)
#define TIM_CCR3_CCR3_Msk                        (0xFFFFUL<<TIM_CCR3_CCR3_Pos)                    /*!< 0x0000FFFF */
#define TIM_CCR3_CCR3                            TIM_CCR3_CCR3_Msk

/********************************* Bit definition for TIM_CCR4 register ********************************************/
#define TIM_CCR4_CCR4_Pos                        (0U)
#define TIM_CCR4_CCR4_Msk                        (0xFFFFUL<<TIM_CCR4_CCR4_Pos)                    /*!< 0x0000FFFF */
#define TIM_CCR4_CCR4                            TIM_CCR4_CCR4_Msk

/********************************* Bit definition for TIM_BDTR register ********************************************/
#define TIM_BDTR_DTG_Pos                         (0U)
#define TIM_BDTR_DTG_Msk                         (0xFFUL<<TIM_BDTR_DTG_Pos)                       /*!< 0x000000FF */
#define TIM_BDTR_DTG                             TIM_BDTR_DTG_Msk
#define TIM_BDTR_LOCK_Pos                        (8U)
#define TIM_BDTR_LOCK_Msk                        (0x3UL<<TIM_BDTR_LOCK_Pos)                       /*!< 0x00000300 */
#define TIM_BDTR_LOCK                            TIM_BDTR_LOCK_Msk
#define TIM_BDTR_LOCK_0                          (0x1UL<<TIM_BDTR_LOCK_Pos)                       /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1                          (0x2UL<<TIM_BDTR_LOCK_Pos)                       /*!< 0x00000200 */
#define TIM_BDTR_OSSI_Pos                        (10U)
#define TIM_BDTR_OSSI_Msk                        (0x1UL<<TIM_BDTR_OSSI_Pos)                       /*!< 0x00000400 */
#define TIM_BDTR_OSSI                            TIM_BDTR_OSSI_Msk                                
#define TIM_BDTR_OSSR_Pos                        (11U)
#define TIM_BDTR_OSSR_Msk                        (0x1UL<<TIM_BDTR_OSSR_Pos)                       /*!< 0x00000800 */
#define TIM_BDTR_OSSR                            TIM_BDTR_OSSR_Msk                                
#define TIM_BDTR_BKE_Pos                         (12U)
#define TIM_BDTR_BKE_Msk                         (0x1UL<<TIM_BDTR_BKE_Pos)                        /*!< 0x00001000 */
#define TIM_BDTR_BKE                             TIM_BDTR_BKE_Msk                                 
#define TIM_BDTR_BKP_Pos                         (13U)
#define TIM_BDTR_BKP_Msk                         (0x1UL<<TIM_BDTR_BKP_Pos)                        /*!< 0x00002000 */
#define TIM_BDTR_BKP                             TIM_BDTR_BKP_Msk                                 
#define TIM_BDTR_AOE_Pos                         (14U)
#define TIM_BDTR_AOE_Msk                         (0x1UL<<TIM_BDTR_AOE_Pos)                        /*!< 0x00004000 */
#define TIM_BDTR_AOE                             TIM_BDTR_AOE_Msk                                 
#define TIM_BDTR_MOE_Pos                         (15U)
#define TIM_BDTR_MOE_Msk                         (0x1UL<<TIM_BDTR_MOE_Pos)                        /*!< 0x00008000 */
#define TIM_BDTR_MOE                             TIM_BDTR_MOE_Msk                                 

/********************************* Bit definition for TIM_TISEL register *******************************************/
#define TIM_TISEL_TI1SEL_Pos                     (0U)
#define TIM_TISEL_TI1SEL_Msk                     (0xFUL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x0000000F */
#define TIM_TISEL_TI1SEL                         TIM_TISEL_TI1SEL_Msk
#define TIM_TISEL_TI1SEL_0                       (0x1UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000001 */
#define TIM_TISEL_TI1SEL_1                       (0x2UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000002 */
#define TIM_TISEL_TI1SEL_2                       (0x4UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000004 */
#define TIM_TISEL_TI1SEL_3                       (0x8UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000008 */
#define TIM_TISEL_TI2SEL_Pos                     (8U)
#define TIM_TISEL_TI2SEL_Msk                     (0xFUL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000F00 */
#define TIM_TISEL_TI2SEL                         TIM_TISEL_TI2SEL_Msk
#define TIM_TISEL_TI2SEL_0                       (0x1UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000100 */
#define TIM_TISEL_TI2SEL_1                       (0x2UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000200 */
#define TIM_TISEL_TI2SEL_2                       (0x4UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000400 */
#define TIM_TISEL_TI2SEL_3                       (0x8UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000800 */
#define TIM_TISEL_TI3SEL_Pos                     (16U)
#define TIM_TISEL_TI3SEL_Msk                     (0xFUL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x000F0000 */
#define TIM_TISEL_TI3SEL                         TIM_TISEL_TI3SEL_Msk
#define TIM_TISEL_TI3SEL_0                       (0x1UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00010000 */
#define TIM_TISEL_TI3SEL_1                       (0x2UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00020000 */
#define TIM_TISEL_TI3SEL_2                       (0x4UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00040000 */
#define TIM_TISEL_TI3SEL_3                       (0x8UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00080000 */
#define TIM_TISEL_TI4SEL_Pos                     (24U)
#define TIM_TISEL_TI4SEL_Msk                     (0xFUL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x0F000000 */
#define TIM_TISEL_TI4SEL                         TIM_TISEL_TI4SEL_Msk
#define TIM_TISEL_TI4SEL_0                       (0x1UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x01000000 */
#define TIM_TISEL_TI4SEL_1                       (0x2UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x02000000 */
#define TIM_TISEL_TI4SEL_2                       (0x4UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x04000000 */
#define TIM_TISEL_TI4SEL_3                       (0x8UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x08000000 */

/********************************* Bit definition for TIM_AF1 register *********************************************/
#define TIM_AF1_BKINE_Pos                        (0U)
#define TIM_AF1_BKINE_Msk                        (0x1UL<<TIM_AF1_BKINE_Pos)                       /*!< 0x00000001 */
#define TIM_AF1_BKINE                            TIM_AF1_BKINE_Msk                                
#define TIM_AF1_BKCMP1E_Pos                      (1U)
#define TIM_AF1_BKCMP1E_Msk                      (0x1UL<<TIM_AF1_BKCMP1E_Pos)                     /*!< 0x00000002 */
#define TIM_AF1_BKCMP1E                          TIM_AF1_BKCMP1E_Msk                              
#define TIM_AF1_BKCMP2E_Pos                      (2U)
#define TIM_AF1_BKCMP2E_Msk                      (0x1UL<<TIM_AF1_BKCMP2E_Pos)                     /*!< 0x00000004 */
#define TIM_AF1_BKCMP2E                          TIM_AF1_BKCMP2E_Msk                              
#define TIM_AF1_BKINP_Pos                        (9U)
#define TIM_AF1_BKINP_Msk                        (0x1UL<<TIM_AF1_BKINP_Pos)                       /*!< 0x00000200 */
#define TIM_AF1_BKINP                            TIM_AF1_BKINP_Msk                                
#define TIM_AF1_BKCMP1P_Pos                      (10U)
#define TIM_AF1_BKCMP1P_Msk                      (0x1UL<<TIM_AF1_BKCMP1P_Pos)                     /*!< 0x00000400 */
#define TIM_AF1_BKCMP1P                          TIM_AF1_BKCMP1P_Msk                              
#define TIM_AF1_BKCMP2P_Pos                      (11U)
#define TIM_AF1_BKCMP2P_Msk                      (0x1UL<<TIM_AF1_BKCMP2P_Pos)                     /*!< 0x00000800 */
#define TIM_AF1_BKCMP2P                          TIM_AF1_BKCMP2P_Msk                              
#define TIM_AF1_ETRSEL_Pos                       (14U)
#define TIM_AF1_ETRSEL_Msk                       (0xFUL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x0003C000 */
#define TIM_AF1_ETRSEL                           TIM_AF1_ETRSEL_Msk
#define TIM_AF1_ETRSEL_0                         (0x1UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00004000 */
#define TIM_AF1_ETRSEL_1                         (0x2UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00008000 */
#define TIM_AF1_ETRSEL_2                         (0x4UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00010000 */
#define TIM_AF1_ETRSEL_3                         (0x8UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00020000 */

/********************************* Bit definition for TIM_AF2 register *********************************************/
#define TIM_AF2_OCRSEL_Pos                       (16U)
#define TIM_AF2_OCRSEL_Msk                       (0x7UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00070000 */
#define TIM_AF2_OCRSEL                           TIM_AF2_OCRSEL_Msk
#define TIM_AF2_OCRSEL_0                         (0x1UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00010000 */
#define TIM_AF2_OCRSEL_1                         (0x2UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00020000 */
#define TIM_AF2_OCRSEL_2                         (0x4UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00040000 */

/********************************* Bit definition for TIM_DCR register *********************************************/
#define TIM_DCR_DBA_Pos                          (0U)
#define TIM_DCR_DBA_Msk                          (0x1FUL<<TIM_DCR_DBA_Pos)                        /*!< 0x0000001F */
#define TIM_DCR_DBA                              TIM_DCR_DBA_Msk
#define TIM_DCR_DBA_0                            (0x1UL<<TIM_DCR_DBA_Pos)                         /*!< 0x00000001 */
#define TIM_DCR_DBA_1                            (0x2UL<<TIM_DCR_DBA_Pos)                         /*!< 0x00000002 */
#define TIM_DCR_DBA_2                            (0x4UL<<TIM_DCR_DBA_Pos)                         /*!< 0x00000004 */
#define TIM_DCR_DBA_3                            (0x8UL<<TIM_DCR_DBA_Pos)                         /*!< 0x00000008 */
#define TIM_DCR_DBA_4                            (0x10UL<<TIM_DCR_DBA_Pos)                        /*!< 0x00000010 */
#define TIM_DCR_DBL_Pos                          (8U)
#define TIM_DCR_DBL_Msk                          (0x1FUL<<TIM_DCR_DBL_Pos)                        /*!< 0x00001F00 */
#define TIM_DCR_DBL                              TIM_DCR_DBL_Msk
#define TIM_DCR_DBL_0                            (0x1UL<<TIM_DCR_DBL_Pos)                         /*!< 0x00000100 */
#define TIM_DCR_DBL_1                            (0x2UL<<TIM_DCR_DBL_Pos)                         /*!< 0x00000200 */
#define TIM_DCR_DBL_2                            (0x4UL<<TIM_DCR_DBL_Pos)                         /*!< 0x00000400 */
#define TIM_DCR_DBL_3                            (0x8UL<<TIM_DCR_DBL_Pos)                         /*!< 0x00000800 */
#define TIM_DCR_DBL_4                            (0x10UL<<TIM_DCR_DBL_Pos)                        /*!< 0x00001000 */

/********************************* Bit definition for TIM_DMAR register ********************************************/
#define TIM_DMAR_DMAB_Pos                        (0U)
#define TIM_DMAR_DMAB_Msk                        (0xFFFFFFFFUL<<TIM_DMAR_DMAB_Pos)                /*!< 0xFFFFFFFF */
#define TIM_DMAR_DMAB                            TIM_DMAR_DMAB_Msk


/********************************************************************************************************************/
/********************************* PWM ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for PWM_CR1 register **********************************************/
#define PWM_CR1_CEN_Pos                           (0U)
#define PWM_CR1_CEN_Msk                           (0x1UL<<PWM_CR1_CEN_Pos)                          /*!< 0x00000001 */
#define PWM_CR1_CEN                               PWM_CR1_CEN_Msk                                   
#define PWM_CR1_UDIS_Pos                          (1U)
#define PWM_CR1_UDIS_Msk                          (0x1UL<<PWM_CR1_UDIS_Pos)                         /*!< 0x00000002 */
#define PWM_CR1_UDIS                              PWM_CR1_UDIS_Msk                                  
#define PWM_CR1_URS_Pos                           (2U)
#define PWM_CR1_URS_Msk                           (0x1UL<<PWM_CR1_URS_Pos)                          /*!< 0x00000004 */
#define PWM_CR1_URS                               PWM_CR1_URS_Msk                                   
#define PWM_CR1_DIR_Pos                           (4U)
#define PWM_CR1_DIR_Msk                           (0x1UL<<PWM_CR1_DIR_Pos)                          /*!< 0x00000010 */
#define PWM_CR1_DIR                               PWM_CR1_DIR_Msk                                   
#define PWM_CR1_CMS_Pos                           (5U)
#define PWM_CR1_CMS_Msk                           (0x3UL<<PWM_CR1_CMS_Pos)                          /*!< 0x00000060 */
#define PWM_CR1_CMS                               PWM_CR1_CMS_Msk
#define PWM_CR1_CMS_0                             (0x1UL<<PWM_CR1_CMS_Pos)                          /*!< 0x00000020 */
#define PWM_CR1_CMS_1                             (0x2UL<<PWM_CR1_CMS_Pos)                          /*!< 0x00000040 */
#define PWM_CR1_ARPE_Pos                          (7U)
#define PWM_CR1_ARPE_Msk                          (0x1UL<<PWM_CR1_ARPE_Pos)                         /*!< 0x00000080 */
#define PWM_CR1_ARPE                              PWM_CR1_ARPE_Msk                                  
#define PWM_CR1_CKD_Pos                           (8U)
#define PWM_CR1_CKD_Msk                           (0x3UL<<PWM_CR1_CKD_Pos)                          /*!< 0x00000300 */
#define PWM_CR1_CKD                               PWM_CR1_CKD_Msk
#define PWM_CR1_CKD_0                             (0x1UL<<PWM_CR1_CKD_Pos)                          /*!< 0x00000100 */
#define PWM_CR1_CKD_1                             (0x2UL<<PWM_CR1_CKD_Pos)                          /*!< 0x00000200 */

/********************************* Bit definition for PWM_CR2 register **********************************************/
#define PWM_CR2_BKINE_Pos                         (0U)
#define PWM_CR2_BKINE_Msk                         (0x1UL<<PWM_CR2_BKINE_Pos)                        /*!< 0x00000001 */
#define PWM_CR2_BKINE                             PWM_CR2_BKINE_Msk                                 
#define PWM_CR2_BKCMP1E_Pos                       (1U)
#define PWM_CR2_BKCMP1E_Msk                       (0x1UL<<PWM_CR2_BKCMP1E_Pos)                      /*!< 0x00000002 */
#define PWM_CR2_BKCMP1E                           PWM_CR2_BKCMP1E_Msk                               
#define PWM_CR2_BKCMP2E_Pos                       (2U)
#define PWM_CR2_BKCMP2E_Msk                       (0x1UL<<PWM_CR2_BKCMP2E_Pos)                      /*!< 0x00000004 */
#define PWM_CR2_BKCMP2E                           PWM_CR2_BKCMP2E_Msk                               
#define PWM_CR2_BKINP_Pos                         (9U)
#define PWM_CR2_BKINP_Msk                         (0x1UL<<PWM_CR2_BKINP_Pos)                        /*!< 0x00000200 */
#define PWM_CR2_BKINP                             PWM_CR2_BKINP_Msk                                 
#define PWM_CR2_BKCMP1P_Pos                       (10U)
#define PWM_CR2_BKCMP1P_Msk                       (0x1UL<<PWM_CR2_BKCMP1P_Pos)                      /*!< 0x00000400 */
#define PWM_CR2_BKCMP1P                           PWM_CR2_BKCMP1P_Msk                               
#define PWM_CR2_BKCMP2P_Pos                       (11U)
#define PWM_CR2_BKCMP2P_Msk                       (0x1UL<<PWM_CR2_BKCMP2P_Pos)                      /*!< 0x00000800 */
#define PWM_CR2_BKCMP2P                           PWM_CR2_BKCMP2P_Msk                               
#define PWM_CR2_ETRSEL_Pos                        (13U)
#define PWM_CR2_ETRSEL_Msk                        (0x7UL<<PWM_CR2_ETRSEL_Pos)                       /*!< 0x0000E000 */
#define PWM_CR2_ETRSEL                            PWM_CR2_ETRSEL_Msk
#define PWM_CR2_ETRSEL_0                          (0x1UL<<PWM_CR2_ETRSEL_Pos)                       /*!< 0x00002000 */
#define PWM_CR2_ETRSEL_1                          (0x2UL<<PWM_CR2_ETRSEL_Pos)                       /*!< 0x00004000 */
#define PWM_CR2_ETRSEL_2                          (0x4UL<<PWM_CR2_ETRSEL_Pos)                       /*!< 0x00008000 */

/********************************* Bit definition for PWM_SMCR register *********************************************/
#define PWM_SMCR_ETF_Pos                          (8U)
#define PWM_SMCR_ETF_Msk                          (0xFUL<<PWM_SMCR_ETF_Pos)                         /*!< 0x00000F00 */
#define PWM_SMCR_ETF                              PWM_SMCR_ETF_Msk
#define PWM_SMCR_ETF_0                            (0x1UL<<PWM_SMCR_ETF_Pos)                         /*!< 0x00000100 */
#define PWM_SMCR_ETF_1                            (0x2UL<<PWM_SMCR_ETF_Pos)                         /*!< 0x00000200 */
#define PWM_SMCR_ETF_2                            (0x4UL<<PWM_SMCR_ETF_Pos)                         /*!< 0x00000400 */
#define PWM_SMCR_ETF_3                            (0x8UL<<PWM_SMCR_ETF_Pos)                         /*!< 0x00000800 */
#define PWM_SMCR_ETPS_Pos                         (12U)
#define PWM_SMCR_ETPS_Msk                         (0x3UL<<PWM_SMCR_ETPS_Pos)                        /*!< 0x00003000 */
#define PWM_SMCR_ETPS                             PWM_SMCR_ETPS_Msk
#define PWM_SMCR_ETPS_0                           (0x1UL<<PWM_SMCR_ETPS_Pos)                        /*!< 0x00001000 */
#define PWM_SMCR_ETPS_1                           (0x2UL<<PWM_SMCR_ETPS_Pos)                        /*!< 0x00002000 */
#define PWM_SMCR_ECE_Pos                          (14U)
#define PWM_SMCR_ECE_Msk                          (0x1UL<<PWM_SMCR_ECE_Pos)                         /*!< 0x00004000 */
#define PWM_SMCR_ECE                              PWM_SMCR_ECE_Msk                                  
#define PWM_SMCR_ETP_Pos                          (15U)
#define PWM_SMCR_ETP_Msk                          (0x1UL<<PWM_SMCR_ETP_Pos)                         /*!< 0x00008000 */
#define PWM_SMCR_ETP                              PWM_SMCR_ETP_Msk                                  

/********************************* Bit definition for PWM_DIER register *********************************************/
#define PWM_DIER_UIE_Pos                          (0U)
#define PWM_DIER_UIE_Msk                          (0x1UL<<PWM_DIER_UIE_Pos)                         /*!< 0x00000001 */
#define PWM_DIER_UIE                              PWM_DIER_UIE_Msk                                  
#define PWM_DIER_OC1IE_Pos                        (1U)
#define PWM_DIER_OC1IE_Msk                        (0x1UL<<PWM_DIER_OC1IE_Pos)                       /*!< 0x00000002 */
#define PWM_DIER_OC1IE                            PWM_DIER_OC1IE_Msk                                
#define PWM_DIER_OC2IE_Pos                        (2U)
#define PWM_DIER_OC2IE_Msk                        (0x1UL<<PWM_DIER_OC2IE_Pos)                       /*!< 0x00000004 */
#define PWM_DIER_OC2IE                            PWM_DIER_OC2IE_Msk                                
#define PWM_DIER_OC3IE_Pos                        (3U)
#define PWM_DIER_OC3IE_Msk                        (0x1UL<<PWM_DIER_OC3IE_Pos)                       /*!< 0x00000008 */
#define PWM_DIER_OC3IE                            PWM_DIER_OC3IE_Msk                                
#define PWM_DIER_OC4IE_Pos                        (4U)
#define PWM_DIER_OC4IE_Msk                        (0x1UL<<PWM_DIER_OC4IE_Pos)                       /*!< 0x00000010 */
#define PWM_DIER_OC4IE                            PWM_DIER_OC4IE_Msk                                
#define PWM_DIER_BIE_Pos                          (7U)
#define PWM_DIER_BIE_Msk                          (0x1UL<<PWM_DIER_BIE_Pos)                         /*!< 0x00000080 */
#define PWM_DIER_BIE                              PWM_DIER_BIE_Msk                                  
#define PWM_DIER_UDE_Pos                          (8U)
#define PWM_DIER_UDE_Msk                          (0x1UL<<PWM_DIER_UDE_Pos)                         /*!< 0x00000100 */
#define PWM_DIER_UDE                              PWM_DIER_UDE_Msk                                  
#define PWM_DIER_OC1DE_Pos                        (9U)
#define PWM_DIER_OC1DE_Msk                        (0x1UL<<PWM_DIER_OC1DE_Pos)                       /*!< 0x00000200 */
#define PWM_DIER_OC1DE                            PWM_DIER_OC1DE_Msk                                
#define PWM_DIER_OC2DE_Pos                        (10U)
#define PWM_DIER_OC2DE_Msk                        (0x1UL<<PWM_DIER_OC2DE_Pos)                       /*!< 0x00000400 */
#define PWM_DIER_OC2DE                            PWM_DIER_OC2DE_Msk                                
#define PWM_DIER_OC3DE_Pos                        (11U)
#define PWM_DIER_OC3DE_Msk                        (0x1UL<<PWM_DIER_OC3DE_Pos)                       /*!< 0x00000800 */
#define PWM_DIER_OC3DE                            PWM_DIER_OC3DE_Msk                                
#define PWM_DIER_OC4DE_Pos                        (12U)
#define PWM_DIER_OC4DE_Msk                        (0x1UL<<PWM_DIER_OC4DE_Pos)                       /*!< 0x00001000 */
#define PWM_DIER_OC4DE                            PWM_DIER_OC4DE_Msk                                

/********************************* Bit definition for PWM_SR register ***********************************************/
#define PWM_SR_UIF_Pos                            (0U)
#define PWM_SR_UIF_Msk                            (0x1UL<<PWM_SR_UIF_Pos)                           /*!< 0x00000001 */
#define PWM_SR_UIF                                PWM_SR_UIF_Msk                                    
#define PWM_SR_OC1IF_Pos                          (1U)
#define PWM_SR_OC1IF_Msk                          (0x1UL<<PWM_SR_OC1IF_Pos)                         /*!< 0x00000002 */
#define PWM_SR_OC1IF                              PWM_SR_OC1IF_Msk                                  
#define PWM_SR_OC2IF_Pos                          (2U)
#define PWM_SR_OC2IF_Msk                          (0x1UL<<PWM_SR_OC2IF_Pos)                         /*!< 0x00000004 */
#define PWM_SR_OC2IF                              PWM_SR_OC2IF_Msk                                  
#define PWM_SR_OC3IF_Pos                          (3U)
#define PWM_SR_OC3IF_Msk                          (0x1UL<<PWM_SR_OC3IF_Pos)                         /*!< 0x00000008 */
#define PWM_SR_OC3IF                              PWM_SR_OC3IF_Msk                                  
#define PWM_SR_OC4IF_Pos                          (4U)
#define PWM_SR_OC4IF_Msk                          (0x1UL<<PWM_SR_OC4IF_Pos)                         /*!< 0x00000010 */
#define PWM_SR_OC4IF                              PWM_SR_OC4IF_Msk                                  
#define PWM_SR_BIF_Pos                            (7U)
#define PWM_SR_BIF_Msk                            (0x1UL<<PWM_SR_BIF_Pos)                           /*!< 0x00000080 */
#define PWM_SR_BIF                                PWM_SR_BIF_Msk                                    
#define PWM_SR_CCR1OK_Pos                         (9U)
#define PWM_SR_CCR1OK_Msk                         (0x1UL<<PWM_SR_CCR1OK_Pos)                        /*!< 0x00000200 */
#define PWM_SR_CCR1OK                             PWM_SR_CCR1OK_Msk                                 
#define PWM_SR_CCR2OK_Pos                         (10U)
#define PWM_SR_CCR2OK_Msk                         (0x1UL<<PWM_SR_CCR2OK_Pos)                        /*!< 0x00000400 */
#define PWM_SR_CCR2OK                             PWM_SR_CCR2OK_Msk                                 
#define PWM_SR_CCR3OK_Pos                         (11U)
#define PWM_SR_CCR3OK_Msk                         (0x1UL<<PWM_SR_CCR3OK_Pos)                        /*!< 0x00000800 */
#define PWM_SR_CCR3OK                             PWM_SR_CCR3OK_Msk                                 
#define PWM_SR_CCR4OK_Pos                         (12U)
#define PWM_SR_CCR4OK_Msk                         (0x1UL<<PWM_SR_CCR4OK_Pos)                        /*!< 0x00001000 */
#define PWM_SR_CCR4OK                             PWM_SR_CCR4OK_Msk                                 
#define PWM_SR_CNTOK_Pos                          (13U)
#define PWM_SR_CNTOK_Msk                          (0x1UL<<PWM_SR_CNTOK_Pos)                         /*!< 0x00002000 */
#define PWM_SR_CNTOK                              PWM_SR_CNTOK_Msk                                  
#define PWM_SR_PSCOK_Pos                          (14U)
#define PWM_SR_PSCOK_Msk                          (0x1UL<<PWM_SR_PSCOK_Pos)                         /*!< 0x00004000 */
#define PWM_SR_PSCOK                              PWM_SR_PSCOK_Msk                                  
#define PWM_SR_ARROK_Pos                          (15U)
#define PWM_SR_ARROK_Msk                          (0x1UL<<PWM_SR_ARROK_Pos)                         /*!< 0x00008000 */
#define PWM_SR_ARROK                              PWM_SR_ARROK_Msk                                  

/********************************* Bit definition for PWM_EGR register **********************************************/
#define PWM_EGR_UG_Pos                            (0U)
#define PWM_EGR_UG_Msk                            (0x1UL<<PWM_EGR_UG_Pos)                           /*!< 0x00000001 */
#define PWM_EGR_UG                                PWM_EGR_UG_Msk                                    

/********************************* Bit definition for PWM_CMR register **********************************************/
#define PWM_CMR_OC1M_Pos                          (0U)
#define PWM_CMR_OC1M_Msk                          (0x3UL<<PWM_CMR_OC1M_Pos)                         /*!< 0x00000003 */
#define PWM_CMR_OC1M                              PWM_CMR_OC1M_Msk
#define PWM_CMR_OC1M_0                            (0x1UL<<PWM_CMR_OC1M_Pos)                         /*!< 0x00000001 */
#define PWM_CMR_OC1M_1                            (0x2UL<<PWM_CMR_OC1M_Pos)                         /*!< 0x00000002 */
#define PWM_CMR_OC2M_Pos                          (2U)
#define PWM_CMR_OC2M_Msk                          (0x3UL<<PWM_CMR_OC2M_Pos)                         /*!< 0x0000000C */
#define PWM_CMR_OC2M                              PWM_CMR_OC2M_Msk
#define PWM_CMR_OC2M_0                            (0x1UL<<PWM_CMR_OC2M_Pos)                         /*!< 0x00000004 */
#define PWM_CMR_OC2M_1                            (0x2UL<<PWM_CMR_OC2M_Pos)                         /*!< 0x00000008 */
#define PWM_CMR_OC3M_Pos                          (4U)
#define PWM_CMR_OC3M_Msk                          (0x3UL<<PWM_CMR_OC3M_Pos)                         /*!< 0x00000030 */
#define PWM_CMR_OC3M                              PWM_CMR_OC3M_Msk
#define PWM_CMR_OC3M_0                            (0x1UL<<PWM_CMR_OC3M_Pos)                         /*!< 0x00000010 */
#define PWM_CMR_OC3M_1                            (0x2UL<<PWM_CMR_OC3M_Pos)                         /*!< 0x00000020 */
#define PWM_CMR_OC4M_Pos                          (6U)
#define PWM_CMR_OC4M_Msk                          (0x3UL<<PWM_CMR_OC4M_Pos)                         /*!< 0x000000C0 */
#define PWM_CMR_OC4M                              PWM_CMR_OC4M_Msk
#define PWM_CMR_OC4M_0                            (0x1UL<<PWM_CMR_OC4M_Pos)                         /*!< 0x00000040 */
#define PWM_CMR_OC4M_1                            (0x2UL<<PWM_CMR_OC4M_Pos)                         /*!< 0x00000080 */
#define PWM_CMR_OC1PE_Pos                         (8U)
#define PWM_CMR_OC1PE_Msk                         (0x1UL<<PWM_CMR_OC1PE_Pos)                        /*!< 0x00000100 */
#define PWM_CMR_OC1PE                             PWM_CMR_OC1PE_Msk                                 
#define PWM_CMR_OC2PE_Pos                         (9U)
#define PWM_CMR_OC2PE_Msk                         (0x1UL<<PWM_CMR_OC2PE_Pos)                        /*!< 0x00000200 */
#define PWM_CMR_OC2PE                             PWM_CMR_OC2PE_Msk                                 
#define PWM_CMR_OC3PE_Pos                         (10U)
#define PWM_CMR_OC3PE_Msk                         (0x1UL<<PWM_CMR_OC3PE_Pos)                        /*!< 0x00000400 */
#define PWM_CMR_OC3PE                             PWM_CMR_OC3PE_Msk                                 
#define PWM_CMR_OC4PE_Pos                         (11U)
#define PWM_CMR_OC4PE_Msk                         (0x1UL<<PWM_CMR_OC4PE_Pos)                        /*!< 0x00000800 */
#define PWM_CMR_OC4PE                             PWM_CMR_OC4PE_Msk                                 

/********************************* Bit definition for PWM_CER register **********************************************/
#define PWM_CER_C1E_Pos                           (0U)
#define PWM_CER_C1E_Msk                           (0x1UL<<PWM_CER_C1E_Pos)                          /*!< 0x00000001 */
#define PWM_CER_C1E                               PWM_CER_C1E_Msk                                   
#define PWM_CER_C1P_Pos                           (1U)
#define PWM_CER_C1P_Msk                           (0x1UL<<PWM_CER_C1P_Pos)                          /*!< 0x00000002 */
#define PWM_CER_C1P                               PWM_CER_C1P_Msk                                   
#define PWM_CER_C1NE_Pos                          (2U)
#define PWM_CER_C1NE_Msk                          (0x1UL<<PWM_CER_C1NE_Pos)                         /*!< 0x00000004 */
#define PWM_CER_C1NE                              PWM_CER_C1NE_Msk                                  
#define PWM_CER_C1NP_Pos                          (3U)
#define PWM_CER_C1NP_Msk                          (0x1UL<<PWM_CER_C1NP_Pos)                         /*!< 0x00000008 */
#define PWM_CER_C1NP                              PWM_CER_C1NP_Msk                                  
#define PWM_CER_C2E_Pos                           (4U)
#define PWM_CER_C2E_Msk                           (0x1UL<<PWM_CER_C2E_Pos)                          /*!< 0x00000010 */
#define PWM_CER_C2E                               PWM_CER_C2E_Msk                                   
#define PWM_CER_C2P_Pos                           (5U)
#define PWM_CER_C2P_Msk                           (0x1UL<<PWM_CER_C2P_Pos)                          /*!< 0x00000020 */
#define PWM_CER_C2P                               PWM_CER_C2P_Msk                                   
#define PWM_CER_C2NE_Pos                          (6U)
#define PWM_CER_C2NE_Msk                          (0x1UL<<PWM_CER_C2NE_Pos)                         /*!< 0x00000040 */
#define PWM_CER_C2NE                              PWM_CER_C2NE_Msk                                  
#define PWM_CER_C2NP_Pos                          (7U)
#define PWM_CER_C2NP_Msk                          (0x1UL<<PWM_CER_C2NP_Pos)                         /*!< 0x00000080 */
#define PWM_CER_C2NP                              PWM_CER_C2NP_Msk                                  
#define PWM_CER_C3E_Pos                           (8U)
#define PWM_CER_C3E_Msk                           (0x1UL<<PWM_CER_C3E_Pos)                          /*!< 0x00000100 */
#define PWM_CER_C3E                               PWM_CER_C3E_Msk                                   
#define PWM_CER_C3P_Pos                           (9U)
#define PWM_CER_C3P_Msk                           (0x1UL<<PWM_CER_C3P_Pos)                          /*!< 0x00000200 */
#define PWM_CER_C3P                               PWM_CER_C3P_Msk                                   
#define PWM_CER_C4E_Pos                           (12U)
#define PWM_CER_C4E_Msk                           (0x1UL<<PWM_CER_C4E_Pos)                          /*!< 0x00001000 */
#define PWM_CER_C4E                               PWM_CER_C4E_Msk                                   
#define PWM_CER_C4P_Pos                           (13U)
#define PWM_CER_C4P_Msk                           (0x1UL<<PWM_CER_C4P_Pos)                          /*!< 0x00002000 */
#define PWM_CER_C4P                               PWM_CER_C4P_Msk                                   

/********************************* Bit definition for PWM_CNT register **********************************************/
#define PWM_CNT_CNT_Pos                           (0U)
#define PWM_CNT_CNT_Msk                           (0xFFFFUL<<PWM_CNT_CNT_Pos)                       /*!< 0x0000FFFF */
#define PWM_CNT_CNT                               PWM_CNT_CNT_Msk

/********************************* Bit definition for PWM_PSC register **********************************************/
#define PWM_PSC_PSC_Pos                           (0U)
#define PWM_PSC_PSC_Msk                           (0xFFFFUL<<PWM_PSC_PSC_Pos)                       /*!< 0x0000FFFF */
#define PWM_PSC_PSC                               PWM_PSC_PSC_Msk

/********************************* Bit definition for PWM_ARR register **********************************************/
#define PWM_ARR_ARR_Pos                           (0U)
#define PWM_ARR_ARR_Msk                           (0xFFFFUL<<PWM_ARR_ARR_Pos)                       /*!< 0x0000FFFF */
#define PWM_ARR_ARR                               PWM_ARR_ARR_Msk

/********************************* Bit definition for PWM_CCR1 register *********************************************/
#define PWM_CCR1_CCR1_Pos                         (0U)
#define PWM_CCR1_CCR1_Msk                         (0xFFFFUL<<PWM_CCR1_CCR1_Pos)                     /*!< 0x0000FFFF */
#define PWM_CCR1_CCR1                             PWM_CCR1_CCR1_Msk

/********************************* Bit definition for PWM_CCR2 register *********************************************/
#define PWM_CCR2_CCR2_Pos                         (0U)
#define PWM_CCR2_CCR2_Msk                         (0xFFFFUL<<PWM_CCR2_CCR2_Pos)                     /*!< 0x0000FFFF */
#define PWM_CCR2_CCR2                             PWM_CCR2_CCR2_Msk

/********************************* Bit definition for PWM_CCR3 register *********************************************/
#define PWM_CCR3_CCR3_Pos                         (0U)
#define PWM_CCR3_CCR3_Msk                         (0xFFFFUL<<PWM_CCR3_CCR3_Pos)                     /*!< 0x0000FFFF */
#define PWM_CCR3_CCR3                             PWM_CCR3_CCR3_Msk

/********************************* Bit definition for PWM_CCR4 register *********************************************/
#define PWM_CCR4_CCR4_Pos                         (0U)
#define PWM_CCR4_CCR4_Msk                         (0xFFFFUL<<PWM_CCR4_CCR4_Pos)                     /*!< 0x0000FFFF */
#define PWM_CCR4_CCR4                             PWM_CCR4_CCR4_Msk

/********************************* Bit definition for PWM_BDTR register *********************************************/
#define PWM_BDTR_DTG_Pos                          (0U)
#define PWM_BDTR_DTG_Msk                          (0xFFUL<<PWM_BDTR_DTG_Pos)                        /*!< 0x000000FF */
#define PWM_BDTR_DTG                              PWM_BDTR_DTG_Msk
#define PWM_BDTR_LOCK_Pos                         (8U)
#define PWM_BDTR_LOCK_Msk                         (0x3UL<<PWM_BDTR_LOCK_Pos)                        /*!< 0x00000300 */
#define PWM_BDTR_LOCK                             PWM_BDTR_LOCK_Msk
#define PWM_BDTR_LOCK_0                           (0x1UL<<PWM_BDTR_LOCK_Pos)                        /*!< 0x00000100 */
#define PWM_BDTR_LOCK_1                           (0x2UL<<PWM_BDTR_LOCK_Pos)                        /*!< 0x00000200 */
#define PWM_BDTR_BKE_Pos                          (12U)
#define PWM_BDTR_BKE_Msk                          (0x1UL<<PWM_BDTR_BKE_Pos)                         /*!< 0x00001000 */
#define PWM_BDTR_BKE                              PWM_BDTR_BKE_Msk                                  
#define PWM_BDTR_BKP_Pos                          (13U)
#define PWM_BDTR_BKP_Msk                          (0x1UL<<PWM_BDTR_BKP_Pos)                         /*!< 0x00002000 */
#define PWM_BDTR_BKP                              PWM_BDTR_BKP_Msk                                  
#define PWM_BDTR_AOE_Pos                          (14U)
#define PWM_BDTR_AOE_Msk                          (0x1UL<<PWM_BDTR_AOE_Pos)                         /*!< 0x00004000 */
#define PWM_BDTR_AOE                              PWM_BDTR_AOE_Msk                                  
#define PWM_BDTR_MOE_Pos                          (15U)
#define PWM_BDTR_MOE_Msk                          (0x1UL<<PWM_BDTR_MOE_Pos)                         /*!< 0x00008000 */
#define PWM_BDTR_MOE                              PWM_BDTR_MOE_Msk                                  

/********************************* Bit definition for PWM_DCR register **********************************************/
#define PWM_DCR_DBA_Pos                           (0U)
#define PWM_DCR_DBA_Msk                           (0x1FUL<<PWM_DCR_DBA_Pos)                         /*!< 0x0000001F */
#define PWM_DCR_DBA                               PWM_DCR_DBA_Msk
#define PWM_DCR_DBA_0                             (0x1UL<<PWM_DCR_DBA_Pos)                          /*!< 0x00000001 */
#define PWM_DCR_DBA_1                             (0x2UL<<PWM_DCR_DBA_Pos)                          /*!< 0x00000002 */
#define PWM_DCR_DBA_2                             (0x4UL<<PWM_DCR_DBA_Pos)                          /*!< 0x00000004 */
#define PWM_DCR_DBA_3                             (0x8UL<<PWM_DCR_DBA_Pos)                          /*!< 0x00000008 */
#define PWM_DCR_DBA_4                             (0x10UL<<PWM_DCR_DBA_Pos)                         /*!< 0x00000010 */
#define PWM_DCR_DBL_Pos                           (8U)
#define PWM_DCR_DBL_Msk                           (0x1FUL<<PWM_DCR_DBL_Pos)                         /*!< 0x00001F00 */
#define PWM_DCR_DBL                               PWM_DCR_DBL_Msk
#define PWM_DCR_DBL_0                             (0x1UL<<PWM_DCR_DBL_Pos)                          /*!< 0x00000100 */
#define PWM_DCR_DBL_1                             (0x2UL<<PWM_DCR_DBL_Pos)                          /*!< 0x00000200 */
#define PWM_DCR_DBL_2                             (0x4UL<<PWM_DCR_DBL_Pos)                          /*!< 0x00000400 */
#define PWM_DCR_DBL_3                             (0x8UL<<PWM_DCR_DBL_Pos)                          /*!< 0x00000800 */
#define PWM_DCR_DBL_4                             (0x10UL<<PWM_DCR_DBL_Pos)                         /*!< 0x00001000 */

/********************************* Bit definition for PWM_DMAR register *********************************************/
#define PWM_DMAR_DMAB_Pos                         (0U)
#define PWM_DMAR_DMAB_Msk                         (0xFFFFFFFFUL<<PWM_DMAR_DMAB_Pos)                 /*!< 0xFFFFFFFF */
#define PWM_DMAR_DMAB                             PWM_DMAR_DMAB_Msk


/********************************************************************************************************************/
/********************************* TK *******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for TK_CR1 register ***********************************************/
#define TK_CR1_EN_Pos                             (0U)
#define TK_CR1_EN_Msk                             (0x1UL<<TK_CR1_EN_Pos)                            /*!< 0x00000001 */
#define TK_CR1_EN                                 TK_CR1_EN_Msk                                     
#define TK_CR1_EXTCMODEN_Pos                      (3U)
#define TK_CR1_EXTCMODEN_Msk                      (0x1UL<<TK_CR1_EXTCMODEN_Pos)                     /*!< 0x00000008 */
#define TK_CR1_EXTCMODEN                          TK_CR1_EXTCMODEN_Msk                              
#define TK_CR1_ICOPA_Pos                          (4U)
#define TK_CR1_ICOPA_Msk                          (0x1UL<<TK_CR1_ICOPA_Pos)                         /*!< 0x00000010 */
#define TK_CR1_ICOPA                              TK_CR1_ICOPA_Msk                                  
#define TK_CR1_COPAMODE_Pos                       (5U)
#define TK_CR1_COPAMODE_Msk                       (0x1UL<<TK_CR1_COPAMODE_Pos)                      /*!< 0x00000020 */
#define TK_CR1_COPAMODE                           TK_CR1_COPAMODE_Msk                               
#define TK_CR1_COPADATA_Pos                       (6U)
#define TK_CR1_COPADATA_Msk                       (0x3UL<<TK_CR1_COPADATA_Pos)                      /*!< 0x000000C0 */
#define TK_CR1_COPADATA                           TK_CR1_COPADATA_Msk
#define TK_CR1_COPADATA_0                         (0x1UL<<TK_CR1_COPADATA_Pos)                      /*!< 0x00000040 */
#define TK_CR1_COPADATA_1                         (0x2UL<<TK_CR1_COPADATA_Pos)                      /*!< 0x00000080 */
#define TK_CR1_VCC1SEL_Pos                        (11U)
#define TK_CR1_VCC1SEL_Msk                        (0x7UL<<TK_CR1_VCC1SEL_Pos)                       /*!< 0x00003800 */
#define TK_CR1_VCC1SEL                            TK_CR1_VCC1SEL_Msk
#define TK_CR1_VCC1SEL_0                          (0x1UL<<TK_CR1_VCC1SEL_Pos)                       /*!< 0x00000800 */
#define TK_CR1_VCC1SEL_1                          (0x2UL<<TK_CR1_VCC1SEL_Pos)                       /*!< 0x00001000 */
#define TK_CR1_VCC1SEL_2                          (0x4UL<<TK_CR1_VCC1SEL_Pos)                       /*!< 0x00002000 */
#define TK_CR1_MIDACSTEP_Pos                      (14U)
#define TK_CR1_MIDACSTEP_Msk                      (0x1UL<<TK_CR1_MIDACSTEP_Pos)                     /*!< 0x00004000 */
#define TK_CR1_MIDACSTEP                          TK_CR1_MIDACSTEP_Msk                              
#define TK_CR1_SIDACSTEP_Pos                      (15U)
#define TK_CR1_SIDACSTEP_Msk                      (0x1UL<<TK_CR1_SIDACSTEP_Pos)                     /*!< 0x00008000 */
#define TK_CR1_SIDACSTEP                          TK_CR1_SIDACSTEP_Msk                              
#define TK_CR1_CFT_Pos                            (16U)
#define TK_CR1_CFT_Msk                            (0x7UL<<TK_CR1_CFT_Pos)                           /*!< 0x00070000 */
#define TK_CR1_CFT                                TK_CR1_CFT_Msk
#define TK_CR1_CFT_0                              (0x1UL<<TK_CR1_CFT_Pos)                           /*!< 0x00010000 */
#define TK_CR1_CFT_1                              (0x2UL<<TK_CR1_CFT_Pos)                           /*!< 0x00020000 */
#define TK_CR1_CFT_2                              (0x4UL<<TK_CR1_CFT_Pos)                           /*!< 0x00040000 */
#define TK_CR1_INTCMODEN_Pos                      (20U)
#define TK_CR1_INTCMODEN_Msk                      (0x1UL<<TK_CR1_INTCMODEN_Pos)                     /*!< 0x00100000 */
#define TK_CR1_INTCMODEN                          TK_CR1_INTCMODEN_Msk                              
#define TK_CR1_CMPHYSEN_Pos                       (21U)
#define TK_CR1_CMPHYSEN_Msk                       (0x1UL<<TK_CR1_CMPHYSEN_Pos)                      /*!< 0x00200000 */
#define TK_CR1_CMPHYSEN                           TK_CR1_CMPHYSEN_Msk                               /*!< Comparetor Hysteresis Enable */
#define TK_CR1_BUFFEREN_Pos                       (22U)
#define TK_CR1_BUFFEREN_Msk                       (0x1UL<<TK_CR1_BUFFEREN_Pos)                      /*!< 0x00400000 */
#define TK_CR1_BUFFEREN                           TK_CR1_BUFFEREN_Msk                               /*!< Buffer Enable */
#define TK_CR1_DIV_Pos                            (24U)
#define TK_CR1_DIV_Msk                            (0x7UL<<TK_CR1_DIV_Pos)                           /*!< 0x07000000 */
#define TK_CR1_DIV                                TK_CR1_DIV_Msk                                    /*!< TK_CLK Division */
#define TK_CR1_DIV_0                              (0x1UL<<TK_CR1_DIV_Pos)                           /*!< 0x01000000 */
#define TK_CR1_DIV_1                              (0x2UL<<TK_CR1_DIV_Pos)                           /*!< 0x02000000 */
#define TK_CR1_DIV_2                              (0x4UL<<TK_CR1_DIV_Pos)                           /*!< 0x04000000 */
#define TK_CR1_STDIV_Pos                          (27U)
#define TK_CR1_STDIV_Msk                          (0xFUL<<TK_CR1_STDIV_Pos)                         /*!< 0x78000000 */
#define TK_CR1_STDIV                              TK_CR1_STDIV_Msk                                  /*!< ST_CLK Division */
#define TK_CR1_STDIV_0                            (0x1UL<<TK_CR1_STDIV_Pos)                         /*!< 0x08000000 */
#define TK_CR1_STDIV_1                            (0x2UL<<TK_CR1_STDIV_Pos)                         /*!< 0x10000000 */
#define TK_CR1_STDIV_2                            (0x4UL<<TK_CR1_STDIV_Pos)                         /*!< 0x20000000 */
#define TK_CR1_STDIV_3                            (0x8UL<<TK_CR1_STDIV_Pos)                         /*!< 0x40000000 */
#define TK_CR1_INTEREN_Pos                        (31U)
#define TK_CR1_INTEREN_Msk                        (0x1UL<<TK_CR1_INTEREN_Pos)                       /*!< 0x80000000 */
#define TK_CR1_INTEREN                            TK_CR1_INTEREN_Msk                                /*!< Internal Enable */

/********************************* Bit definition for TK_CR2 register ***********************************************/
#define TK_CR2_START_Pos                          (0U)
#define TK_CR2_START_Msk                          (0x1UL<<TK_CR2_START_Pos)                         /*!< 0x00000001 */
#define TK_CR2_START                              TK_CR2_START_Msk                                  
#define TK_CR2_RSTB_Pos                           (1U)
#define TK_CR2_RSTB_Msk                           (0x1UL<<TK_CR2_RSTB_Pos)                          /*!< 0x00000002 */
#define TK_CR2_RSTB                               TK_CR2_RSTB_Msk                                   
#define TK_CR2_SWCTRL_Pos                         (2U)
#define TK_CR2_SWCTRL_Msk                         (0x1UL<<TK_CR2_SWCTRL_Pos)                        /*!< 0x00000004 */
#define TK_CR2_SWCTRL                             TK_CR2_SWCTRL_Msk                                 
#define TK_CR2_CMODCHRG_Pos                       (3U)
#define TK_CR2_CMODCHRG_Msk                       (0x1UL<<TK_CR2_CMODCHRG_Pos)                      /*!< 0x00000008 */
#define TK_CR2_CMODCHRG                           TK_CR2_CMODCHRG_Msk                               
#define TK_CR2_CMODDISCH_Pos                      (4U)
#define TK_CR2_CMODDISCH_Msk                      (0x1UL<<TK_CR2_CMODDISCH_Pos)                     /*!< 0x00000010 */
#define TK_CR2_CMODDISCH                          TK_CR2_CMODDISCH_Msk                              
#define TK_CR2_MIDACEN_Pos                        (5U)
#define TK_CR2_MIDACEN_Msk                        (0x1UL<<TK_CR2_MIDACEN_Pos)                       /*!< 0x00000020 */
#define TK_CR2_MIDACEN                            TK_CR2_MIDACEN_Msk                                
#define TK_CR2_SIDACEN_Pos                        (6U)
#define TK_CR2_SIDACEN_Msk                        (0x1UL<<TK_CR2_SIDACEN_Pos)                       /*!< 0x00000040 */
#define TK_CR2_SIDACEN                            TK_CR2_SIDACEN_Msk                                
#define TK_CR2_PWMM_Pos                           (8U)
#define TK_CR2_PWMM_Msk                           (0x1UL<<TK_CR2_PWMM_Pos)                          /*!< 0x00000100 */
#define TK_CR2_PWMM                               TK_CR2_PWMM_Msk                                   
#define TK_CR2_CTRLSOURCE_Pos                     (9U)
#define TK_CR2_CTRLSOURCE_Msk                     (0x1UL<<TK_CR2_CTRLSOURCE_Pos)                    /*!< 0x00000200 */
#define TK_CR2_CTRLSOURCE                         TK_CR2_CTRLSOURCE_Msk                             
#define TK_CR2_LPABNORMAL_Pos                     (10U)
#define TK_CR2_LPABNORMAL_Msk                     (0x1UL<<TK_CR2_LPABNORMAL_Pos)                    /*!< 0x00000400 */
#define TK_CR2_LPABNORMAL                         TK_CR2_LPABNORMAL_Msk                             
#define TK_CR2_SHORTSW_NUM_Pos                    (12U)
#define TK_CR2_SHORTSW_NUM_Msk                    (0x3UL<<TK_CR2_SHORTSW_NUM_Pos)                   /*!< 0x00003000 */
#define TK_CR2_SHORTSW_NUM                        TK_CR2_SHORTSW_NUM_Msk
#define TK_CR2_SHORTSW_NUM_0                      (0x1UL<<TK_CR2_SHORTSW_NUM_Pos)                   /*!< 0x00001000 */
#define TK_CR2_SHORTSW_NUM_1                      (0x2UL<<TK_CR2_SHORTSW_NUM_Pos)                   /*!< 0x00002000 */
#define TK_CR2_LPEN_Pos                           (14U)
#define TK_CR2_LPEN_Msk                           (0x1UL<<TK_CR2_LPEN_Pos)                          /*!< 0x00004000 */
#define TK_CR2_LPEN                               TK_CR2_LPEN_Msk                                   
#define TK_CR2_KVREF_Pos                          (16U)
#define TK_CR2_KVREF_Msk                          (0x3UL<<TK_CR2_KVREF_Pos)                         /*!< 0x00030000 */
#define TK_CR2_KVREF                              TK_CR2_KVREF_Msk
#define TK_CR2_KVREF_0                            (0x1UL<<TK_CR2_KVREF_Pos)                         /*!< 0x00010000 */
#define TK_CR2_KVREF_1                            (0x2UL<<TK_CR2_KVREF_Pos)                         /*!< 0x00020000 */
#define TK_CR2_LFSRW_Pos                          (20U)
#define TK_CR2_LFSRW_Msk                          (0xFUL<<TK_CR2_LFSRW_Pos)                         /*!< 0x00F00000 */
#define TK_CR2_LFSRW                              TK_CR2_LFSRW_Msk
#define TK_CR2_LFSRW_0                            (0x1UL<<TK_CR2_LFSRW_Pos)                         /*!< 0x00100000 */
#define TK_CR2_LFSRW_1                            (0x2UL<<TK_CR2_LFSRW_Pos)                         /*!< 0x00200000 */
#define TK_CR2_LFSRW_2                            (0x4UL<<TK_CR2_LFSRW_Pos)                         /*!< 0x00400000 */
#define TK_CR2_LFSRW_3                            (0x8UL<<TK_CR2_LFSRW_Pos)                         /*!< 0x00800000 */
#define TK_CR2_CMODTKCOPA_Pos                     (29U)
#define TK_CR2_CMODTKCOPA_Msk                     (0x1UL<<TK_CR2_CMODTKCOPA_Pos)                    /*!< 0x20000000 */
#define TK_CR2_CMODTKCOPA                         TK_CR2_CMODTKCOPA_Msk                             
#define TK_CR2_CMODTKCS_Pos                       (30U)
#define TK_CR2_CMODTKCS_Msk                       (0x1UL<<TK_CR2_CMODTKCS_Pos)                      /*!< 0x40000000 */
#define TK_CR2_CMODTKCS                           TK_CR2_CMODTKCS_Msk                               
#define TK_CR2_CMODTKEN_Pos                       (31U)
#define TK_CR2_CMODTKEN_Msk                       (0x1UL<<TK_CR2_CMODTKEN_Pos)                      /*!< 0x80000000 */
#define TK_CR2_CMODTKEN                           TK_CR2_CMODTKEN_Msk                               

/********************************* Bit definition for TK_IDACR register *********************************************/
#define TK_IDACR_MIDAC_Pos                        (0U)
#define TK_IDACR_MIDAC_Msk                        (0xFFUL<<TK_IDACR_MIDAC_Pos)                      /*!< 0x000000FF */
#define TK_IDACR_MIDAC                            TK_IDACR_MIDAC_Msk
#define TK_IDACR_SIDAC_Pos                        (16U)
#define TK_IDACR_SIDAC_Msk                        (0xFFUL<<TK_IDACR_SIDAC_Pos)                      /*!< 0x00FF0000 */
#define TK_IDACR_SIDAC                            TK_IDACR_SIDAC_Msk

/********************************* Bit definition for TK_KR register ************************************************/
#define TK_KR_KEN_Pos                             (0U)
#define TK_KR_KEN_Msk                             (0xFFFFFFFFUL<<TK_KR_KEN_Pos)                     /*!< 0xFFFFFFFF */
#define TK_KR_KEN                                 TK_KR_KEN_Msk

/********************************* Bit definition for TK_CSR register ***********************************************/
#define TK_CSR_CHS_Pos                            (0U)
#define TK_CSR_CHS_Msk                            (0xFFFFFFFFUL<<TK_CSR_CHS_Pos)                    /*!< 0xFFFFFFFF */
#define TK_CSR_CHS                                TK_CSR_CHS_Msk

/********************************* Bit definition for TK_UCR register ***********************************************/
#define TK_UCR_COPAMODEIO_Pos                     (0U)
#define TK_UCR_COPAMODEIO_Msk                     (0xFFFFFFFFUL<<TK_UCR_COPAMODEIO_Pos)             /*!< 0xFFFFFFFF */
#define TK_UCR_COPAMODEIO                         TK_UCR_COPAMODEIO_Msk

/********************************* Bit definition for TK_STR register ***********************************************/
#define TK_STR_SETTIME_Pos                        (0U)
#define TK_STR_SETTIME_Msk                        (0x3FFUL<<TK_STR_SETTIME_Pos)                     /*!< 0x000003FF */
#define TK_STR_SETTIME                            TK_STR_SETTIME_Msk

/********************************* Bit definition for TK_RESERVED register ******************************************/

/********************************* Bit definition for TK_WR register ************************************************/
#define TK_WR_WIN_Pos                             (0U)
#define TK_WR_WIN_Msk                             (0xFFFFUL<<TK_WR_WIN_Pos)                         /*!< 0x0000FFFF */
#define TK_WR_WIN                                 TK_WR_WIN_Msk

/********************************* Bit definition for TK_SDR register ***********************************************/
#define TK_SDR_SWDIV_Pos                          (0U)
#define TK_SDR_SWDIV_Msk                          (0x1FFUL<<TK_SDR_SWDIV_Pos)                       /*!< 0x000001FF */
#define TK_SDR_SWDIV                              TK_SDR_SWDIV_Msk

/********************************* Bit definition for TK_PRSR register **********************************************/
#define TK_PRSR_LFSRP_Pos                         (0U)
#define TK_PRSR_LFSRP_Msk                         (0xFFFFUL<<TK_PRSR_LFSRP_Pos)                     /*!< 0x0000FFFF */
#define TK_PRSR_LFSRP                             TK_PRSR_LFSRP_Msk
#define TK_PRSR_SEED_Pos                          (16U)
#define TK_PRSR_SEED_Msk                          (0xFFFFUL<<TK_PRSR_SEED_Pos)                      /*!< 0xFFFF0000 */
#define TK_PRSR_SEED                              TK_PRSR_SEED_Msk

/********************************* Bit definition for TK_DR register ************************************************/
#define TK_DR_DATA_Pos                            (0U)
#define TK_DR_DATA_Msk                            (0xFFFFUL<<TK_DR_DATA_Pos)                        /*!< 0x0000FFFF */
#define TK_DR_DATA                                TK_DR_DATA_Msk

/********************************* Bit definition for TK_SR register ************************************************/
#define TK_SR_SENSEDONE_Pos                       (0U)
#define TK_SR_SENSEDONE_Msk                       (0x1UL<<TK_SR_SENSEDONE_Pos)                      /*!< 0x00000001 */
#define TK_SR_SENSEDONE                           TK_SR_SENSEDONE_Msk                               
#define TK_SR_CMPOUT_Pos                          (1U)
#define TK_SR_CMPOUT_Msk                          (0x1UL<<TK_SR_CMPOUT_Pos)                         /*!< 0x00000002 */
#define TK_SR_CMPOUT                              TK_SR_CMPOUT_Msk                                  
#define TK_SR_SHORTSWERR_Pos                      (2U)
#define TK_SR_SHORTSWERR_Msk                      (0x1UL<<TK_SR_SHORTSWERR_Pos)                     /*!< 0x00000004 */
#define TK_SR_SHORTSWERR                          TK_SR_SHORTSWERR_Msk                              

/********************************* Bit definition for TK_IER register ***********************************************/
#define TK_IER_EVTINTEN_Pos                       (0U)
#define TK_IER_EVTINTEN_Msk                       (0x1UL<<TK_IER_EVTINTEN_Pos)                      /*!< 0x00000001 */
#define TK_IER_EVTINTEN                           TK_IER_EVTINTEN_Msk                               
#define TK_IER_ERRINTEN_Pos                       (1U)
#define TK_IER_ERRINTEN_Msk                       (0x1UL<<TK_IER_ERRINTEN_Pos)                      /*!< 0x00000002 */
#define TK_IER_ERRINTEN                           TK_IER_ERRINTEN_Msk                               

/********************************* Bit definition for TK_ICR register ***********************************************/
#define TK_ICR_EVTINTCLR_Pos                      (0U)
#define TK_ICR_EVTINTCLR_Msk                      (0x1UL<<TK_ICR_EVTINTCLR_Pos)                     /*!< 0x00000001 */
#define TK_ICR_EVTINTCLR                          TK_ICR_EVTINTCLR_Msk                              
#define TK_ICR_ERRINTCLR_Pos                      (1U)
#define TK_ICR_ERRINTCLR_Msk                      (0x1UL<<TK_ICR_ERRINTCLR_Pos)                     /*!< 0x00000002 */
#define TK_ICR_ERRINTCLR                          TK_ICR_ERRINTCLR_Msk                              

/********************************* Bit definition for TK_CDR register ***********************************************/
#define TK_CDR_CDATA_Pos                          (0U)
#define TK_CDR_CDATA_Msk                          (0xFFFFUL<<TK_CDR_CDATA_Pos)                      /*!< 0x0000FFFF */
#define TK_CDR_CDATA                              TK_CDR_CDATA_Msk

/********************************* Bit definition for TK_LPDR register **********************************************/
#define TK_LPDR_NORMALDELTA_Pos                   (0U)
#define TK_LPDR_NORMALDELTA_Msk                   (0x3FFUL<<TK_LPDR_NORMALDELTA_Pos)                /*!< 0x000003FF */
#define TK_LPDR_NORMALDELTA                       TK_LPDR_NORMALDELTA_Msk
#define TK_LPDR_ABNORMALDELTA_Pos                 (16U)
#define TK_LPDR_ABNORMALDELTA_Msk                 (0x3FFUL<<TK_LPDR_ABNORMALDELTA_Pos)              /*!< 0x03FF0000 */
#define TK_LPDR_ABNORMALDELTA                     TK_LPDR_ABNORMALDELTA_Msk

/********************************* Bit definition for TK_LPTR register **********************************************/
#define TK_LPTR_LPWAIT_Pos                        (0U)
#define TK_LPTR_LPWAIT_Msk                        (0x7FUL<<TK_LPTR_LPWAIT_Pos)                      /*!< 0x0000007F */
#define TK_LPTR_LPWAIT                            TK_LPTR_LPWAIT_Msk

/********************************* Bit definition for TK_OPR register ***********************************************/
#define TK_OPR_OP_Pos                             (0U)
#define TK_OPR_OP_Msk                             (0x3FUL<<TK_OPR_OP_Pos)                           /*!< 0x0000003F */
#define TK_OPR_OP                                 TK_OPR_OP_Msk
#define TK_OPR_OP_0                               (0x1UL<<TK_OPR_OP_Pos)                            /*!< 0x00000001 */
#define TK_OPR_OP_1                               (0x2UL<<TK_OPR_OP_Pos)                            /*!< 0x00000002 */
#define TK_OPR_OP_2                               (0x4UL<<TK_OPR_OP_Pos)                            /*!< 0x00000004 */
#define TK_OPR_OP_3                               (0x8UL<<TK_OPR_OP_Pos)                            /*!< 0x00000008 */
#define TK_OPR_OP_4                               (0x10UL<<TK_OPR_OP_Pos)                           /*!< 0x00000010 */
#define TK_OPR_OP_5                               (0x20UL<<TK_OPR_OP_Pos)                           /*!< 0x00000020 */

/********************************* Bit definition for TK_TR register ************************************************/
#define TK_TR_TMODE_Pos                           (0U)
#define TK_TR_TMODE_Msk                           (0x7UL<<TK_TR_TMODE_Pos)                          /*!< 0x00000007 */
#define TK_TR_TMODE                               TK_TR_TMODE_Msk
#define TK_TR_TMODE_0                             (0x1UL<<TK_TR_TMODE_Pos)                          /*!< 0x00000001 */
#define TK_TR_TMODE_1                             (0x2UL<<TK_TR_TMODE_Pos)                          /*!< 0x00000002 */
#define TK_TR_TMODE_2                             (0x4UL<<TK_TR_TMODE_Pos)                          /*!< 0x00000004 */
#define TK_TR_DBGSEL_Pos                          (16U)
#define TK_TR_DBGSEL_Msk                          (0xFUL<<TK_TR_DBGSEL_Pos)                         /*!< 0x000F0000 */
#define TK_TR_DBGSEL                              TK_TR_DBGSEL_Msk
#define TK_TR_DBGSEL_0                            (0x1UL<<TK_TR_DBGSEL_Pos)                         /*!< 0x00010000 */
#define TK_TR_DBGSEL_1                            (0x2UL<<TK_TR_DBGSEL_Pos)                         /*!< 0x00020000 */
#define TK_TR_DBGSEL_2                            (0x4UL<<TK_TR_DBGSEL_Pos)                         /*!< 0x00040000 */
#define TK_TR_DBGSEL_3                            (0x8UL<<TK_TR_DBGSEL_Pos)                         /*!< 0x00080000 */

/********************************* Bit definition for TK_DDR register ***********************************************/
#define TK_DDR_SHORTSW_DATA_Pos                   (0U)
#define TK_DDR_SHORTSW_DATA_Msk                   (0x3FFUL<<TK_DDR_SHORTSW_DATA_Pos)                /*!< 0x000003FF */
#define TK_DDR_SHORTSW_DATA                       TK_DDR_SHORTSW_DATA_Msk


/********************************************************************************************************************/
/********************************* 32BIT ****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for LPTIM_ISR register ********************************************/
#define LPTIM_ISR_CMPM_Pos                        (0U)
#define LPTIM_ISR_CMPM_Msk                        (0x1UL<<LPTIM_ISR_CMPM_Pos)                       /*!< 0x00000001 */
#define LPTIM_ISR_CMPM                            LPTIM_ISR_CMPM_Msk                                /*!< Compare match */
#define LPTIM_ISR_ARRM_Pos                        (1U)
#define LPTIM_ISR_ARRM_Msk                        (0x1UL<<LPTIM_ISR_ARRM_Pos)                       /*!< 0x00000002 */
#define LPTIM_ISR_ARRM                            LPTIM_ISR_ARRM_Msk                                /*!< Autoreload match */
//#define LPTIM_ISR_EXTTRIG_Pos                     (2U)
//#define LPTIM_ISR_EXTTRIG_Msk                     (0x1UL<<LPTIM_ISR_EXTTRIG_Pos)                    /*!< 0x00000004 */
//#define LPTIM_ISR_EXTTRIG                         LPTIM_ISR_EXTTRIG_Msk                             /*!< External trigger edge event */
#define LPTIM_ISR_CMPOK_Pos                       (3U)
#define LPTIM_ISR_CMPOK_Msk                       (0x1UL<<LPTIM_ISR_CMPOK_Pos)                      /*!< 0x00000008 */
#define LPTIM_ISR_CMPOK                           LPTIM_ISR_CMPOK_Msk                               /*!< Compare register update OK */
#define LPTIM_ISR_ARROK_Pos                       (4U)
#define LPTIM_ISR_ARROK_Msk                       (0x1UL<<LPTIM_ISR_ARROK_Pos)                      /*!< 0x00000010 */
#define LPTIM_ISR_ARROK                           LPTIM_ISR_ARROK_Msk                               /*!< Autoreload register update OK */
#define LPTIM_ISR_UP_Pos                          (5U)
#define LPTIM_ISR_UP_Msk                          (0x1UL<<LPTIM_ISR_UP_Pos)                         /*!< 0x00000020 */
#define LPTIM_ISR_UP                              LPTIM_ISR_UP_Msk                                  /*!< Counter direction change down to up */
#define LPTIM_ISR_DOWN_Pos                        (6U)
#define LPTIM_ISR_DOWN_Msk                        (0x1UL<<LPTIM_ISR_DOWN_Pos)                       /*!< 0x00000040 */
#define LPTIM_ISR_DOWN                            LPTIM_ISR_DOWN_Msk                                /*!< Counter direction change up to down */

/********************************* Bit definition for LPTIM_ICR register ********************************************/
#define LPTIM_ICR_CMPMCF_Pos                      (0U)
#define LPTIM_ICR_CMPMCF_Msk                      (0x1UL<<LPTIM_ICR_CMPMCF_Pos)                     /*!< 0x00000001 */
#define LPTIM_ICR_CMPMCF                          LPTIM_ICR_CMPMCF_Msk                              /*!< Compare match clear flag */
#define LPTIM_ICR_ARRMCF_Pos                      (1U)
#define LPTIM_ICR_ARRMCF_Msk                      (0x1UL<<LPTIM_ICR_ARRMCF_Pos)                     /*!< 0x00000002 */
#define LPTIM_ICR_ARRMCF                          LPTIM_ICR_ARRMCF_Msk                              /*!< Autoreload match clear flag */
//#define LPTIM_ICR_EXTTRIGCF_Pos                   (2U)
//#define LPTIM_ICR_EXTTRIGCF_Msk                   (0x1UL<<LPTIM_ICR_EXTTRIGCF_Pos)                  /*!< 0x00000004 */
//#define LPTIM_ICR_EXTTRIGCF                       LPTIM_ICR_EXTTRIGCF_Msk                           /*!< External trigger valid edge clear flag */
#define LPTIM_ICR_CMPOKCF_Pos                     (3U)
#define LPTIM_ICR_CMPOKCF_Msk                     (0x1UL<<LPTIM_ICR_CMPOKCF_Pos)                    /*!< 0x00000008 */
#define LPTIM_ICR_CMPOKCF                         LPTIM_ICR_CMPOKCF_Msk                             /*!< Compare register update OK clear flag */
#define LPTIM_ICR_ARROKCF_Pos                     (4U)
#define LPTIM_ICR_ARROKCF_Msk                     (0x1UL<<LPTIM_ICR_ARROKCF_Pos)                    /*!< 0x00000010 */
#define LPTIM_ICR_ARROKCF                         LPTIM_ICR_ARROKCF_Msk                             /*!< Autoreload register update OK clear flag */
#define LPTIM_ICR_UPCF_Pos                        (5U)
#define LPTIM_ICR_UPCF_Msk                        (0x1UL<<LPTIM_ICR_UPCF_Pos)                       /*!< 0x00000020 */
#define LPTIM_ICR_UPCF                            LPTIM_ICR_UPCF_Msk                                /*!< Direction change to UP clear flag */
#define LPTIM_ICR_DOWNCF_Pos                      (6U)
#define LPTIM_ICR_DOWNCF_Msk                      (0x1UL<<LPTIM_ICR_DOWNCF_Pos)                     /*!< 0x00000040 */
#define LPTIM_ICR_DOWNCF                          LPTIM_ICR_DOWNCF_Msk                              /*!< Direction change to down clear flag */

/********************************* Bit definition for LPTIM_IER register ********************************************/
#define LPTIM_IER_CMPMIE_Pos                      (0U)
#define LPTIM_IER_CMPMIE_Msk                      (0x1UL<<LPTIM_IER_CMPMIE_Pos)                     /*!< 0x00000001 */
#define LPTIM_IER_CMPMIE                          LPTIM_IER_CMPMIE_Msk                              /*!< Compare match Interrupt Enable */
#define LPTIM_IER_ARRMIE_Pos                      (1U)
#define LPTIM_IER_ARRMIE_Msk                      (0x1UL<<LPTIM_IER_ARRMIE_Pos)                     /*!< 0x00000002 */
#define LPTIM_IER_ARRMIE                          LPTIM_IER_ARRMIE_Msk                              /*!< Autoreload match Interrupt Enable */
//#define LPTIM_IER_EXTTRIGIE_Pos                   (2U)
//#define LPTIM_IER_EXTTRIGIE_Msk                   (0x1UL<<LPTIM_IER_EXTTRIGIE_Pos)                  /*!< 0x00000004 */
//#define LPTIM_IER_EXTTRIGIE                       LPTIM_IER_EXTTRIGIE_Msk                           /*!< External trigger valid edge Interrupt Enable */
#define LPTIM_IER_CMPOKIE_Pos                     (3U)
#define LPTIM_IER_CMPOKIE_Msk                     (0x1UL<<LPTIM_IER_CMPOKIE_Pos)                    /*!< 0x00000008 */
#define LPTIM_IER_CMPOKIE                         LPTIM_IER_CMPOKIE_Msk                             /*!< Compare register update OK Interrupt Enable */
#define LPTIM_IER_ARROKIE_Pos                     (4U)
#define LPTIM_IER_ARROKIE_Msk                     (0x1UL<<LPTIM_IER_ARROKIE_Pos)                    /*!< 0x00000010 */
#define LPTIM_IER_ARROKIE                         LPTIM_IER_ARROKIE_Msk                             /*!< Autoreload register update OK Interrupt Enable */
#define LPTIM_IER_UPIE_Pos                        (5U)
#define LPTIM_IER_UPIE_Msk                        (0x1UL<<LPTIM_IER_UPIE_Pos)                       /*!< 0x00000020 */
#define LPTIM_IER_UPIE                            LPTIM_IER_UPIE_Msk                                /*!< Direction change to UP Interrupt Enable */
#define LPTIM_IER_DOWNIE_Pos                      (6U)
#define LPTIM_IER_DOWNIE_Msk                      (0x1UL<<LPTIM_IER_DOWNIE_Pos)                     /*!< 0x00000040 */
#define LPTIM_IER_DOWNIE                          LPTIM_IER_DOWNIE_Msk                              /*!< Direction change to down Interrupt Enable */

/********************************* Bit definition for LPTIM_CFGR register *******************************************/
#define LPTIM_CFGR_CKSEL_Pos                      (0U)
#define LPTIM_CFGR_CKSEL_Msk                      (0x1UL<<LPTIM_CFGR_CKSEL_Pos)                     /*!< 0x00000001 */
#define LPTIM_CFGR_CKSEL                          LPTIM_CFGR_CKSEL_Msk                              /*!< Clock selector */
#define LPTIM_CFGR_CKPOL_Pos                      (1U)
#define LPTIM_CFGR_CKPOL_Msk                      (0x3UL<<LPTIM_CFGR_CKPOL_Pos)                     /*!< 0x00000006 */
#define LPTIM_CFGR_CKPOL                          LPTIM_CFGR_CKPOL_Msk                              /*!< Clock Polarity */
#define LPTIM_CFGR_CKPOL_0                        (0x1UL<<LPTIM_CFGR_CKPOL_Pos)                     /*!< 0x00000002 */
#define LPTIM_CFGR_CKPOL_1                        (0x2UL<<LPTIM_CFGR_CKPOL_Pos)                     /*!< 0x00000004 */
//#define LPTIM_CFGR_CKFLT_Pos                      (3U)
//#define LPTIM_CFGR_CKFLT_Msk                      (0x3UL<<LPTIM_CFGR_CKFLT_Pos)                     /*!< 0x00000018 */
//#define LPTIM_CFGR_CKFLT                          LPTIM_CFGR_CKFLT_Msk                              /*!< Configurable digital filter for external clock */
//#define LPTIM_CFGR_CKFLT_0                        (0x1UL<<LPTIM_CFGR_CKFLT_Pos)                     /*!< 0x00000008 */
//#define LPTIM_CFGR_CKFLT_1                        (0x2UL<<LPTIM_CFGR_CKFLT_Pos)                     /*!< 0x00000010 */
#define LPTIM_CFGR_TRGFLT_Pos                     (6U)
#define LPTIM_CFGR_TRGFLT_Msk                     (0x3UL<<LPTIM_CFGR_TRGFLT_Pos)                    /*!< 0x000000C0 */
#define LPTIM_CFGR_TRGFLT                         LPTIM_CFGR_TRGFLT_Msk                             /*!< Configurable digital filter for trigger */
#define LPTIM_CFGR_TRGFLT_0                       (0x1UL<<LPTIM_CFGR_TRGFLT_Pos)                    /*!< 0x00000040 */
#define LPTIM_CFGR_TRGFLT_1                       (0x2UL<<LPTIM_CFGR_TRGFLT_Pos)                    /*!< 0x00000080 */
#define LPTIM_CFGR_PRESC_Pos                      (9U)
#define LPTIM_CFGR_PRESC_Msk                      (0x7UL<<LPTIM_CFGR_PRESC_Pos)                     /*!< 0x00000E00 */
#define LPTIM_CFGR_PRESC                          LPTIM_CFGR_PRESC_Msk                              /*!< Clock prescaler */
#define LPTIM_CFGR_PRESC_0                        (0x1UL<<LPTIM_CFGR_PRESC_Pos)                     /*!< 0x00000200 */
#define LPTIM_CFGR_PRESC_1                        (0x2UL<<LPTIM_CFGR_PRESC_Pos)                     /*!< 0x00000400 */
#define LPTIM_CFGR_PRESC_2                        (0x4UL<<LPTIM_CFGR_PRESC_Pos)                     /*!< 0x00000800 */
#define LPTIM_CFGR_TRIGSEL_Pos                    (13U)
#define LPTIM_CFGR_TRIGSEL_Msk                    (0x7UL<<LPTIM_CFGR_TRIGSEL_Pos)                   /*!< 0x0000E000 */
#define LPTIM_CFGR_TRIGSEL                        LPTIM_CFGR_TRIGSEL_Msk                            /*!< Trigger selector */
#define LPTIM_CFGR_TRIGSEL_0                      (0x1UL<<LPTIM_CFGR_TRIGSEL_Pos)                   /*!< 0x00002000 */
#define LPTIM_CFGR_TRIGSEL_1                      (0x2UL<<LPTIM_CFGR_TRIGSEL_Pos)                   /*!< 0x00004000 */
#define LPTIM_CFGR_TRIGSEL_2                      (0x4UL<<LPTIM_CFGR_TRIGSEL_Pos)                   /*!< 0x00008000 */
#define LPTIM_CFGR_TRIGEN_Pos                     (17U)
#define LPTIM_CFGR_TRIGEN_Msk                     (0x3UL<<LPTIM_CFGR_TRIGEN_Pos)                    /*!< 0x00060000 */
#define LPTIM_CFGR_TRIGEN                         LPTIM_CFGR_TRIGEN_Msk                             /*!< Trigger enable and polarity */
#define LPTIM_CFGR_TRIGEN_0                       (0x1UL<<LPTIM_CFGR_TRIGEN_Pos)                    /*!< 0x00020000 */
#define LPTIM_CFGR_TRIGEN_1                       (0x2UL<<LPTIM_CFGR_TRIGEN_Pos)                    /*!< 0x00040000 */
//#define LPTIM_CFGR_TIMOUT_Pos                     (19U)
//#define LPTIM_CFGR_TIMOUT_Msk                     (0x1UL<<LPTIM_CFGR_TIMOUT_Pos)                    /*!< 0x00080000 */
//#define LPTIM_CFGR_TIMOUT                         LPTIM_CFGR_TIMOUT_Msk                             /*!<  Timeout enable */
#define LPTIM_CFGR_WAVE_Pos                       (20U)
#define LPTIM_CFGR_WAVE_Msk                       (0x1UL<<LPTIM_CFGR_WAVE_Pos)                      /*!< 0x00100000 */
#define LPTIM_CFGR_WAVE                           LPTIM_CFGR_WAVE_Msk                               /*!< Waveform shape */
#define LPTIM_CFGR_WAVPOL_Pos                     (21U)
#define LPTIM_CFGR_WAVPOL_Msk                     (0x1UL<<LPTIM_CFGR_WAVPOL_Pos)                    /*!< 0x00200000 */
#define LPTIM_CFGR_WAVPOL                         LPTIM_CFGR_WAVPOL_Msk                             /*!< Waveform shape polarity */
#define LPTIM_CFGR_PRELOAD_Pos                    (22U)
#define LPTIM_CFGR_PRELOAD_Msk                    (0x1UL<<LPTIM_CFGR_PRELOAD_Pos)                   /*!< 0x00400000 */
#define LPTIM_CFGR_PRELOAD                        LPTIM_CFGR_PRELOAD_Msk                            /*!< Registers update mode */
#define LPTIM_CFGR_ENC_Pos                        (24U)
#define LPTIM_CFGR_ENC_Msk                        (0x1UL<<LPTIM_CFGR_ENC_Pos)                       /*!< 0x01000000 */
#define LPTIM_CFGR_ENC                            LPTIM_CFGR_ENC_Msk                                /*!< Encoder mode enable */

/********************************* Bit definition for LPTIM_CR register *********************************************/
#define LPTIM_CR_ENABLE_Pos                       (0U)
#define LPTIM_CR_ENABLE_Msk                       (0x1UL<<LPTIM_CR_ENABLE_Pos)                      /*!< 0x00000001 */
#define LPTIM_CR_ENABLE                           LPTIM_CR_ENABLE_Msk                               /*!< LPTIM enable */
#define LPTIM_CR_SNGSTRT_Pos                      (1U)
#define LPTIM_CR_SNGSTRT_Msk                      (0x1UL<<LPTIM_CR_SNGSTRT_Pos)                     /*!< 0x00000002 */
#define LPTIM_CR_SNGSTRT                          LPTIM_CR_SNGSTRT_Msk                              /*!< LPTIM start in Single mode */
#define LPTIM_CR_CNTSTRT_Pos                      (2U)
#define LPTIM_CR_CNTSTRT_Msk                      (0x1UL<<LPTIM_CR_CNTSTRT_Pos)                     /*!< 0x00000004 */
#define LPTIM_CR_CNTSTRT                          LPTIM_CR_CNTSTRT_Msk                              /*!< Timer start in Continuous mode */
#define LPTIM_CR_COUNTRST_Pos                     (3U)
#define LPTIM_CR_COUNTRST_Msk                     (0x1UL<<LPTIM_CR_COUNTRST_Pos)                    /*!< 0x00000008 */
#define LPTIM_CR_COUNTRST                         LPTIM_CR_COUNTRST_Msk                             /*!< Counter reset */
#define LPTIM_CR_RSTARE_Pos                       (4U)
#define LPTIM_CR_RSTARE_Msk                       (0x1UL<<LPTIM_CR_RSTARE_Pos)                      /*!< 0x00000010 */
#define LPTIM_CR_RSTARE                           LPTIM_CR_RSTARE_Msk                               /*!< Reset after read enable */

/********************************* Bit definition for LPTIM_CMP register ********************************************/
#define LPTIM_CMP_CMP_Pos                         (0U)
#define LPTIM_CMP_CMP_Msk                         (0xFFFFFFFFUL<<LPTIM_CMP_CMP_Pos)                 /*!< 0xFFFFFFFF */
#define LPTIM_CMP_CMP                             LPTIM_CMP_CMP_Msk                                 /*!< Compare value */

/********************************* Bit definition for LPTIM_ARR register ********************************************/
#define LPTIM_ARR_ARR_Pos                         (0U)
#define LPTIM_ARR_ARR_Msk                         (0xFFFFFFFFUL<<LPTIM_ARR_ARR_Pos)                 /*!< 0xFFFFFFFF */
#define LPTIM_ARR_ARR                             LPTIM_ARR_ARR_Msk                                 /*!< Auto reload value */

/********************************* Bit definition for LPTIM_CNT register ********************************************/
#define LPTIM_CNT_CNT_Pos                         (0U)
#define LPTIM_CNT_CNT_Msk                         (0xFFFFFFFFUL<<LPTIM_CNT_CNT_Pos)                 /*!< 0xFFFFFFFF */
#define LPTIM_CNT_CNT                             LPTIM_CNT_CNT_Msk                                 /*!< Counter value */

/********************************* Bit definition for LPTIM_OR register *********************************************/
#define LPTIM_OR_IN1_Pos                          (0U)
#define LPTIM_OR_IN1_Msk                          (0xDUL<<LPTIM_OR_IN1_Pos)                         /*!< 0x0000000D */
#define LPTIM_OR_IN1                              LPTIM_OR_IN1_Msk                                  /*!< LPTimer input 1 remap extension */
#define LPTIM_OR_IN1_0                            (0x1UL<<LPTIM_OR_IN1_Pos)                         /*!< 0x00000001 */
#define LPTIM_OR_IN1_1                            (0x4UL<<LPTIM_OR_IN1_Pos)                         /*!< 0x00000004 */
#define LPTIM_OR_IN1_2                            (0x8UL<<LPTIM_OR_IN1_Pos)                         /*!< 0x00000008 */
#define LPTIM_OR_IN2_Pos                          (1U)
#define LPTIM_OR_IN2_Msk                          (0x19UL<<LPTIM_OR_IN2_Pos)                        /*!< 0x00000032 */
#define LPTIM_OR_IN2                              LPTIM_OR_IN2_Msk                                  /*!< LPTimer input 2 remap extension */
#define LPTIM_OR_IN2_0                            (0x1UL<<LPTIM_OR_IN2_Pos)                         /*!< 0x00000002 */
#define LPTIM_OR_IN2_1                            (0x8UL<<LPTIM_OR_IN2_Pos)                         /*!< 0x00000010 */
#define LPTIM_OR_IN2_2                            (0x10UL<<LPTIM_OR_IN2_Pos)                        /*!< 0x00000020 */

/********************************************************************************************************************/
/********************************* UART *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for UART_DR register **********************************************/
#define UART_DR_DR_Pos                            (0U)
#define UART_DR_DR_Msk                            (0x1FFUL<<UART_DR_DR_Pos)                         /*!< 0x000001FF */
#define UART_DR_DR                                UART_DR_DR_Msk                                    /*!< Receive/send data register */

/********************************* Bit definition for UART_BRR register *********************************************/
#define UART_BRR_BRR_Pos                          (0U)
#define UART_BRR_BRR_Msk                          (0xFFFFUL<<UART_BRR_BRR_Pos)                      /*!< 0x0000FFFF */
#define UART_BRR_BRR                              UART_BRR_BRR_Msk                                  /*!< Baud rate register */

/********************************* Bit definition for UART_SR register **********************************************/
#define UART_SR_RXNE_Pos                          (0U)
#define UART_SR_RXNE_Msk                          (0x1UL<<UART_SR_RXNE_Pos)                         /*!< 0x00000001 */
#define UART_SR_RXNE                              UART_SR_RXNE_Msk                                  /*!< Receive register not empty */
#define UART_SR_ORE_Pos                           (1U)
#define UART_SR_ORE_Msk                           (0x1UL<<UART_SR_ORE_Pos)                          /*!< 0x00000002 */
#define UART_SR_ORE                               UART_SR_ORE_Msk                                   /*!< Overrun error bit */
#define UART_SR_PE_Pos                            (2U)
#define UART_SR_PE_Msk                            (0x1UL<<UART_SR_PE_Pos)                           /*!< 0x00000004 */
#define UART_SR_PE                                UART_SR_PE_Msk                                    /*!< Parity Error bit */
#define UART_SR_FE_Pos                            (3U)
#define UART_SR_FE_Msk                            (0x1UL<<UART_SR_FE_Pos)                           /*!< 0x00000008 */
#define UART_SR_FE                                UART_SR_FE_Msk                                    /*!< Framing Error bit */
#define UART_SR_BRI_Pos                           (4U)
#define UART_SR_BRI_Msk                           (0x1UL<<UART_SR_BRI_Pos)                          /*!< 0x00000010 */
#define UART_SR_BRI                               UART_SR_BRI_Msk                                   /*!< Break Interrupt bit */
#define UART_SR_TDRE_Pos                          (5U)
#define UART_SR_TDRE_Msk                          (0x1UL<<UART_SR_TDRE_Pos)                         /*!< 0x00000020 */
#define UART_SR_TDRE                              UART_SR_TDRE_Msk                                  /*!< Transmit Holding Register Empty bit */
#define UART_SR_TXE_Pos                           (6U)
#define UART_SR_TXE_Msk                           (0x1UL<<UART_SR_TXE_Pos)                          /*!< 0x00000040 */
#define UART_SR_TXE                               UART_SR_TXE_Msk                                   /*!< Transmitter Empty bit */
#define UART_SR_ADDR_RCVD_Pos                     (8U)
#define UART_SR_ADDR_RCVD_Msk                     (0x1UL<<UART_SR_ADDR_RCVD_Pos)                    /*!< 0x00000100 */
#define UART_SR_ADDR_RCVD                         UART_SR_ADDR_RCVD_Msk                             /*!< Address Received Bit */
#define UART_SR_BUSY_Pos                          (9U)
#define UART_SR_BUSY_Msk                          (0x1UL<<UART_SR_BUSY_Pos)                         /*!< 0x00000200 */
#define UART_SR_BUSY                              UART_SR_BUSY_Msk                                  /*!< UART Busy */
#define UART_SR_BUSY_ERR_Pos                      (10U)
#define UART_SR_BUSY_ERR_Msk                      (0x1UL<<UART_SR_BUSY_ERR_Pos)                     /*!< 0x00000400 */
#define UART_SR_BUSY_ERR                          UART_SR_BUSY_ERR_Msk                              /*!< Busy Detect Error */

/********************************* Bit definition for UART_CR1 register *********************************************/
#define UART_CR1_M_Pos                            (0U)
#define UART_CR1_M_Msk                            (0x3UL<<UART_CR1_M_Pos)                           /*!< 0x00000003 */
#define UART_CR1_M                                UART_CR1_M_Msk                                    /*!< Data Length Select */
#define UART_CR1_M_0                              (0x1UL<<UART_CR1_M_Pos)                           /*!< 0x00000001 */
#define UART_CR1_M_1                              (0x2UL<<UART_CR1_M_Pos)                           /*!< 0x00000002 */
#define UART_CR1_STOP_Pos                         (2U)
#define UART_CR1_STOP_Msk                         (0x1UL<<UART_CR1_STOP_Pos)                        /*!< 0x00000004 */
#define UART_CR1_STOP                             UART_CR1_STOP_Msk                                 /*!< Number of stop bits */
#define UART_CR1_PCE_Pos                          (3U)
#define UART_CR1_PCE_Msk                          (0x1UL<<UART_CR1_PCE_Pos)                         /*!< 0x00000008 */
#define UART_CR1_PCE                              UART_CR1_PCE_Msk                                  /*!< Parity Enable */
#define UART_CR1_PS_Pos                           (4U)
#define UART_CR1_PS_Msk                           (0x1UL<<UART_CR1_PS_Pos)                          /*!< 0x00000010 */
#define UART_CR1_PS                               UART_CR1_PS_Msk                                   /*!< Even Parity Select */
#define UART_CR1_SP_Pos                           (5U)
#define UART_CR1_SP_Msk                           (0x1UL<<UART_CR1_SP_Pos)                          /*!< 0x00000020 */
#define UART_CR1_SP                               UART_CR1_SP_Msk                                   /*!< Stick Parity */
#define UART_CR1_SBK_Pos                          (6U)
#define UART_CR1_SBK_Msk                          (0x1UL<<UART_CR1_SBK_Pos)                         /*!< 0x00000040 */
#define UART_CR1_SBK                              UART_CR1_SBK_Msk                                  /*!< Send Break */
#define UART_CR1_SWAP_Pos                         (8U)
#define UART_CR1_SWAP_Msk                         (0x1UL<<UART_CR1_SWAP_Pos)                        /*!< 0x00000100 */
#define UART_CR1_SWAP                             UART_CR1_SWAP_Msk                                 /*!< TX/RX pin swap */
#define UART_CR1_MSBFIRST_Pos                     (9U)
#define UART_CR1_MSBFIRST_Msk                     (0x1UL<<UART_CR1_MSBFIRST_Pos)                    /*!< 0x00000200 */
#define UART_CR1_MSBFIRST                         UART_CR1_MSBFIRST_Msk                             /*!< MSB first mode */

/********************************* Bit definition for UART_CR2 register *********************************************/
#define UART_CR2_RXNEIE_Pos                       (0U)
#define UART_CR2_RXNEIE_Msk                       (0x1UL<<UART_CR2_RXNEIE_Pos)                      /*!< 0x00000001 */
#define UART_CR2_RXNEIE                           UART_CR2_RXNEIE_Msk                               /*!< Enable Received Data Available Interrupt */
#define UART_CR2_TDREIE_Pos                       (1U)
#define UART_CR2_TDREIE_Msk                       (0x1UL<<UART_CR2_TDREIE_Pos)                      /*!< 0x00000002 */
#define UART_CR2_TDREIE                           UART_CR2_TDREIE_Msk                               /*!< Enable Transmit Holding Register Empty Interrupt */
#define UART_CR2_LSIE_Pos                         (2U)
#define UART_CR2_LSIE_Msk                         (0x1UL<<UART_CR2_LSIE_Pos)                        /*!< 0x00000004 */
#define UART_CR2_LSIE                             UART_CR2_LSIE_Msk                                 /*!< Enable Receiver Line Status Interrupt */
#define UART_CR2_BUSYERRIE_Pos                    (3U)
#define UART_CR2_BUSYERRIE_Msk                    (0x1UL<<UART_CR2_BUSYERRIE_Pos)                   /*!< 0x00000008 */
#define UART_CR2_BUSYERRIE                        UART_CR2_BUSYERRIE_Msk                            /*!< Enable Busyerr state interruption */
#define UART_CR2_TXEIE_Pos                        (4U)
#define UART_CR2_TXEIE_Msk                        (0x1UL<<UART_CR2_TXEIE_Pos)                       /*!< 0x00000010 */
#define UART_CR2_TXEIE                            UART_CR2_TXEIE_Msk                                /*!< Enable tx empty interruption */

/********************************* Bit definition for UART_CR3 register *********************************************/
#define UART_CR3_M_E_Pos                          (0U)
#define UART_CR3_M_E_Msk                          (0x1UL<<UART_CR3_M_E_Pos)                         /*!< 0x00000001 */
#define UART_CR3_M_E                              UART_CR3_M_E_Msk                                  /*!< Extension for DLS */
#define UART_CR3_ADDR_MATCH_Pos                   (1U)
#define UART_CR3_ADDR_MATCH_Msk                   (0x1UL<<UART_CR3_ADDR_MATCH_Pos)                  /*!< 0x00000002 */
#define UART_CR3_ADDR_MATCH                       UART_CR3_ADDR_MATCH_Msk                           /*!<  Address Match Mode */
#define UART_CR3_SEND_ADDR_Pos                    (2U)
#define UART_CR3_SEND_ADDR_Msk                    (0x1UL<<UART_CR3_SEND_ADDR_Pos)                   /*!< 0x00000004 */
#define UART_CR3_SEND_ADDR                        UART_CR3_SEND_ADDR_Msk                            /*!< Send address control bit */
#define UART_CR3_TX_MODE_Pos                      (3U)
#define UART_CR3_TX_MODE_Msk                      (0x1UL<<UART_CR3_TX_MODE_Pos)                     /*!< 0x00000008 */
#define UART_CR3_TX_MODE                          UART_CR3_TX_MODE_Msk                              /*!< Transmit mode control bit */
#define UART_CR3_DMAR_Pos                         (4U)
#define UART_CR3_DMAR_Msk                         (0x1UL<<UART_CR3_DMAR_Pos)                        /*!< 0x00000010 */
#define UART_CR3_DMAR                             UART_CR3_DMAR_Msk                                 /*!< DMA receive enable */
#define UART_CR3_DMAT_Pos                         (5U)
#define UART_CR3_DMAT_Msk                         (0x1UL<<UART_CR3_DMAT_Pos)                        /*!< 0x00000020 */
#define UART_CR3_DMAT                             UART_CR3_DMAT_Msk                                 /*!< DMA transmit enable */
#define UART_CR3_DMA_SOFT_ACK_Pos                 (6U)
#define UART_CR3_DMA_SOFT_ACK_Msk                 (0x1UL<<UART_CR3_DMA_SOFT_ACK_Pos)                /*!< 0x00000040 */
#define UART_CR3_DMA_SOFT_ACK                     UART_CR3_DMA_SOFT_ACK_Msk                         /*!< DMA software ack */

/********************************* Bit definition for UART_RAR register *********************************************/
#define UART_RAR_RAR_Pos                          (0U)
#define UART_RAR_RAR_Msk                          (0xFFUL<<UART_RAR_RAR_Pos)                        /*!< 0x000000FF */
#define UART_RAR_RAR                              UART_RAR_RAR_Msk                                  /*!< Receive address matching register */

/********************************* Bit definition for UART_TAR register *********************************************/
#define UART_TAR_TAR_Pos                          (0U)
#define UART_TAR_TAR_Msk                          (0xFFUL<<UART_TAR_TAR_Pos)                        /*!< 0x000000FF */
#define UART_TAR_TAR                              UART_TAR_TAR_Msk                                  /*!< Transmit address matching register */

/********************************* Bit definition for UART_BRRF register ********************************************/
#define UART_BRRF_BRRF_Pos                        (0U)
#define UART_BRRF_BRRF_Msk                        (0xFUL<<UART_BRRF_BRRF_Pos)                       /*!< 0x0000000F */
#define UART_BRRF_BRRF                            UART_BRRF_BRRF_Msk                                /*!< Baud rate fractional register */
#define UART_BRRF_BRRF_0                          (0x1UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000001 */
#define UART_BRRF_BRRF_1                          (0x2UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000002 */
#define UART_BRRF_BRRF_2                          (0x4UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000004 */
#define UART_BRRF_BRRF_3                          (0x8UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000008 */



/********************************************************************************************************************/
/********************************* USART ****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for USART_SR register *********************************************/
#define USART_SR_PE_Pos                           (0U)
#define USART_SR_PE_Msk                           (0x1UL<<USART_SR_PE_Pos)                          /*!< 0x00000001 */
#define USART_SR_PE                               USART_SR_PE_Msk                                   /*!< Parity error */
#define USART_SR_FE_Pos                           (1U)
#define USART_SR_FE_Msk                           (0x1UL<<USART_SR_FE_Pos)                          /*!< 0x00000002 */
#define USART_SR_FE                               USART_SR_FE_Msk                                   /*!< Framing error */
#define USART_SR_NE_Pos                           (2U)
#define USART_SR_NE_Msk                           (0x1UL<<USART_SR_NE_Pos)                          /*!< 0x00000004 */
#define USART_SR_NE                               USART_SR_NE_Msk                                   /*!< Noise error flag */
#define USART_SR_ORE_Pos                          (3U)
#define USART_SR_ORE_Msk                          (0x1UL<<USART_SR_ORE_Pos)                         /*!< 0x00000008 */
#define USART_SR_ORE                              USART_SR_ORE_Msk                                  /*!< overrun error */
#define USART_SR_IDLE_Pos                         (4U)
#define USART_SR_IDLE_Msk                         (0x1UL<<USART_SR_IDLE_Pos)                        /*!< 0x00000010 */
#define USART_SR_IDLE                             USART_SR_IDLE_Msk                                 /*!< idle */
#define USART_SR_RXNE_Pos                         (5U)
#define USART_SR_RXNE_Msk                         (0x1UL<<USART_SR_RXNE_Pos)                        /*!< 0x00000020 */
#define USART_SR_RXNE                             USART_SR_RXNE_Msk                                 /*!< Read data register not empty */
#define USART_SR_TC_Pos                           (6U)
#define USART_SR_TC_Msk                           (0x1UL<<USART_SR_TC_Pos)                          /*!< 0x00000040 */
#define USART_SR_TC                               USART_SR_TC_Msk                                   /*!< Transmission complete */
#define USART_SR_TXE_Pos                          (7U)
#define USART_SR_TXE_Msk                          (0x1UL<<USART_SR_TXE_Pos)                         /*!< 0x00000080 */
#define USART_SR_TXE                              USART_SR_TXE_Msk                                  /*!< Transmit data register empty */
#define USART_SR_LBD_Pos                          (8U)
#define USART_SR_LBD_Msk                          (0x1UL<<USART_SR_LBD_Pos)                         /*!< 0x00000100 */
#define USART_SR_LBD                              USART_SR_LBD_Msk                                  /*!< LIN break detection flag */
#define USART_SR_CTS_Pos                          (9U)
#define USART_SR_CTS_Msk                          (0x1UL<<USART_SR_CTS_Pos)                         /*!< 0x00000200 */
#define USART_SR_CTS                              USART_SR_CTS_Msk                                  /*!< cts flag */
#define USART_SR_ABRF_Pos                         (10U)
#define USART_SR_ABRF_Msk                         (0x1UL<<USART_SR_ABRF_Pos)                        /*!< 0x00000400 */
#define USART_SR_ABRF                             USART_SR_ABRF_Msk                                 /*!< auto baud rate flag */
#define USART_SR_ABRE_Pos                         (11U)
#define USART_SR_ABRE_Msk                         (0x1UL<<USART_SR_ABRE_Pos)                        /*!< 0x00000800 */
#define USART_SR_ABRE                             USART_SR_ABRE_Msk                                 /*!< auto baud rateerror */
#define USART_SR_ABRRQ_Pos                        (12U)
#define USART_SR_ABRRQ_Msk                        (0x1UL<<USART_SR_ABRRQ_Pos)                       /*!< 0x00001000 */
#define USART_SR_ABRRQ                            USART_SR_ABRRQ_Msk                                /*!< auto baud rate req */
#define USART_SR_EOBF_Pos                         (18U)
#define USART_SR_EOBF_Msk                         (0x1UL<<USART_SR_EOBF_Pos)                        /*!< 0x00040000 */
#define USART_SR_EOBF                             USART_SR_EOBF_Msk                                 /*!< end of block flag */
#define USART_SR_RTOF_Pos                         (19U)
#define USART_SR_RTOF_Msk                         (0x1UL<<USART_SR_RTOF_Pos)                        /*!< 0x00080000 */
#define USART_SR_RTOF                             USART_SR_RTOF_Msk                                 /*!< rto flag */
#define USART_SR_TXPE_Pos                         (20U)
#define USART_SR_TXPE_Msk                         (0x1UL<<USART_SR_TXPE_Pos)                        /*!< 0x00100000 */
#define USART_SR_TXPE                             USART_SR_TXPE_Msk                                 
#define USART_SR_RXBUSY_Pos                       (21U)
#define USART_SR_RXBUSY_Msk                       (0x1UL<<USART_SR_RXBUSY_Pos)                      /*!< 0x00200000 */
#define USART_SR_RXBUSY                           USART_SR_RXBUSY_Msk                               
#define USART_SR_TXBUSY_Pos                       (22U)
#define USART_SR_TXBUSY_Msk                       (0x1UL<<USART_SR_TXBUSY_Pos)                      /*!< 0x00400000 */
#define USART_SR_TXBUSY                           USART_SR_TXBUSY_Msk                               
#define USART_SR_WAIT_RPT_Pos                     (23U)
#define USART_SR_WAIT_RPT_Msk                     (0x1UL<<USART_SR_WAIT_RPT_Pos)                    /*!< 0x00800000 */
#define USART_SR_WAIT_RPT                         USART_SR_WAIT_RPT_Msk                             
/* #define USART_SR_TXLSEF_Pos                       (31U) */
/* #define USART_SR_TXLSEF_Msk                       (0x1UL<<USART_SR_TXLSEF_Pos) */                     /*!< 0x80000000 */
/* #define USART_SR_TXLSEF                           USART_SR_TXLSEF_Msk          */                     

/********************************* Bit definition for USART_DR register *********************************************/
#define USART_DR_DR_Pos                           (0U)
#define USART_DR_DR_Msk                           (0x1FFUL<<USART_DR_DR_Pos)                        /*!< 0x000001FF */
#define USART_DR_DR                               USART_DR_DR_Msk                                   /*!< dr */

/********************************* Bit definition for USART_BRR register ********************************************/
#define USART_BRR_DIV_FRACTION_Pos                (0U)
#define USART_BRR_DIV_FRACTION_Msk                (0xFUL<<USART_BRR_DIV_FRACTION_Pos)               /*!< 0x0000000F */
#define USART_BRR_DIV_FRACTION                    USART_BRR_DIV_FRACTION_Msk                        /*!< DIV_Fraction */
#define USART_BRR_DIV_FRACTION_0                  (0x1UL<<USART_BRR_DIV_FRACTION_Pos)               /*!< 0x00000001 */
#define USART_BRR_DIV_FRACTION_1                  (0x2UL<<USART_BRR_DIV_FRACTION_Pos)               /*!< 0x00000002 */
#define USART_BRR_DIV_FRACTION_2                  (0x4UL<<USART_BRR_DIV_FRACTION_Pos)               /*!< 0x00000004 */
#define USART_BRR_DIV_FRACTION_3                  (0x8UL<<USART_BRR_DIV_FRACTION_Pos)               /*!< 0x00000008 */
#define USART_BRR_DIV_MANTISSA_Pos                (4U)
#define USART_BRR_DIV_MANTISSA_Msk                (0xFFFUL<<USART_BRR_DIV_MANTISSA_Pos)             /*!< 0x0000FFF0 */
#define USART_BRR_DIV_MANTISSA                    USART_BRR_DIV_MANTISSA_Msk                        /*!< DIV_Mantissa */

/********************************* Bit definition for USART_CR1 register ********************************************/
#define USART_CR1_SBK_Pos                         (0U)
#define USART_CR1_SBK_Msk                         (0x1UL<<USART_CR1_SBK_Pos)                        /*!< 0x00000001 */
#define USART_CR1_SBK                             USART_CR1_SBK_Msk                                 /*!< Send break */
#define USART_CR1_RWU_Pos                         (1U)
#define USART_CR1_RWU_Msk                         (0x1UL<<USART_CR1_RWU_Pos)                        /*!< 0x00000002 */
#define USART_CR1_RWU                             USART_CR1_RWU_Msk                                 /*!< Receiver wakeup */
#define USART_CR1_RE_Pos                          (2U)
#define USART_CR1_RE_Msk                          (0x1UL<<USART_CR1_RE_Pos)                         /*!< 0x00000004 */
#define USART_CR1_RE                              USART_CR1_RE_Msk                                  /*!< Receiver enable */
#define USART_CR1_TE_Pos                          (3U)
#define USART_CR1_TE_Msk                          (0x1UL<<USART_CR1_TE_Pos)                         /*!< 0x00000008 */
#define USART_CR1_TE                              USART_CR1_TE_Msk                                  /*!< Transmitter enable */
#define USART_CR1_IDLEIE_Pos                      (4U)
#define USART_CR1_IDLEIE_Msk                      (0x1UL<<USART_CR1_IDLEIE_Pos)                     /*!< 0x00000010 */
#define USART_CR1_IDLEIE                          USART_CR1_IDLEIE_Msk                              /*!< IDLE interrupt enable */
#define USART_CR1_RXNEIE_Pos                      (5U)
#define USART_CR1_RXNEIE_Msk                      (0x1UL<<USART_CR1_RXNEIE_Pos)                     /*!< 0x00000020 */
#define USART_CR1_RXNEIE                          USART_CR1_RXNEIE_Msk                              /*!< RXNE interrupt enable */
#define USART_CR1_TCIE_Pos                        (6U)
#define USART_CR1_TCIE_Msk                        (0x1UL<<USART_CR1_TCIE_Pos)                       /*!< 0x00000040 */
#define USART_CR1_TCIE                            USART_CR1_TCIE_Msk                                /*!< send complete int enable */
#define USART_CR1_TXEIE_Pos                       (7U)
#define USART_CR1_TXEIE_Msk                       (0x1UL<<USART_CR1_TXEIE_Pos)                      /*!< 0x00000080 */
#define USART_CR1_TXEIE                           USART_CR1_TXEIE_Msk                               /*!< txe  */
#define USART_CR1_PEIE_Pos                        (8U)
#define USART_CR1_PEIE_Msk                        (0x1UL<<USART_CR1_PEIE_Pos)                       /*!< 0x00000100 */
#define USART_CR1_PEIE                            USART_CR1_PEIE_Msk                                /*!< PE interrupt enable */
#define USART_CR1_PS_Pos                          (9U)
#define USART_CR1_PS_Msk                          (0x1UL<<USART_CR1_PS_Pos)                         /*!< 0x00000200 */
#define USART_CR1_PS                              USART_CR1_PS_Msk                                  /*!< Parity selection */
#define USART_CR1_PCE_Pos                         (10U)
#define USART_CR1_PCE_Msk                         (0x1UL<<USART_CR1_PCE_Pos)                        /*!< 0x00000400 */
#define USART_CR1_PCE                             USART_CR1_PCE_Msk                                 /*!< Parity control enable */
#define USART_CR1_WAKE_Pos                        (11U)
#define USART_CR1_WAKE_Msk                        (0x1UL<<USART_CR1_WAKE_Pos)                       /*!< 0x00000800 */
#define USART_CR1_WAKE                            USART_CR1_WAKE_Msk                                /*!< Wakeup method */
#define USART_CR1_M_Pos                           (12U)
#define USART_CR1_M_Msk                           (0x1UL<<USART_CR1_M_Pos)                          /*!< 0x00001000 */
#define USART_CR1_M                               USART_CR1_M_Msk                                   /*!< word length */
#define USART_CR1_UE_Pos                          (13U)
#define USART_CR1_UE_Msk                          (0x1UL<<USART_CR1_UE_Pos)                         /*!< 0x00002000 */
#define USART_CR1_UE                              USART_CR1_UE_Msk                                  /*!< uesart enable  */
#define USART_CR1_MSBFIRST_Pos                    (15U)
#define USART_CR1_MSBFIRST_Msk                    (0x1UL<<USART_CR1_MSBFIRST_Pos)                   /*!< 0x00008000 */
#define USART_CR1_MSBFIRST                        USART_CR1_MSBFIRST_Msk                            /*!< msbfirst */
#define USART_CR1_SWAP_Pos                        (18U)
#define USART_CR1_SWAP_Msk                        (0x1UL<<USART_CR1_SWAP_Pos)                       /*!< 0x00040000 */
#define USART_CR1_SWAP                            USART_CR1_SWAP_Msk                                /*!< swap */
#define USART_CR1_DATAINV_Pos                     (27U)
#define USART_CR1_DATAINV_Msk                     (0x1UL<<USART_CR1_DATAINV_Pos)                    /*!< 0x08000000 */
#define USART_CR1_DATAINV                         USART_CR1_DATAINV_Msk                             /*!< data inverse */

/********************************* Bit definition for USART_CR2 register ********************************************/
#define USART_CR2_ADD_Pos                         (0U)
#define USART_CR2_ADD_Msk                         (0xFUL<<USART_CR2_ADD_Pos)                        /*!< 0x0000000F */
#define USART_CR2_ADD                             USART_CR2_ADD_Msk                                 /*!< mute addr */
#define USART_CR2_ADD_0                           (0x1UL<<USART_CR2_ADD_Pos)                        /*!< 0x00000001 */
#define USART_CR2_ADD_1                           (0x2UL<<USART_CR2_ADD_Pos)                        /*!< 0x00000002 */
#define USART_CR2_ADD_2                           (0x4UL<<USART_CR2_ADD_Pos)                        /*!< 0x00000004 */
#define USART_CR2_ADD_3                           (0x8UL<<USART_CR2_ADD_Pos)                        /*!< 0x00000008 */
#define USART_CR2_LBDL_Pos                        (5U)
#define USART_CR2_LBDL_Msk                        (0x1UL<<USART_CR2_LBDL_Pos)                       /*!< 0x00000020 */
#define USART_CR2_LBDL                            USART_CR2_LBDL_Msk                                /*!< LIN break detection length */
#define USART_CR2_LBDIE_Pos                       (6U)
#define USART_CR2_LBDIE_Msk                       (0x1UL<<USART_CR2_LBDIE_Pos)                      /*!< 0x00000040 */
#define USART_CR2_LBDIE                           USART_CR2_LBDIE_Msk                               /*!< lin break enable */
#define USART_CR2_LBCL_Pos                        (8U)
#define USART_CR2_LBCL_Msk                        (0x1UL<<USART_CR2_LBCL_Pos)                       /*!< 0x00000100 */
#define USART_CR2_LBCL                            USART_CR2_LBCL_Msk                                /*!< lbcl  */
#define USART_CR2_CPHA_Pos                        (9U)
#define USART_CR2_CPHA_Msk                        (0x1UL<<USART_CR2_CPHA_Pos)                       /*!< 0x00000200 */
#define USART_CR2_CPHA                            USART_CR2_CPHA_Msk                                /*!< cpha */
#define USART_CR2_CPOL_Pos                        (10U)
#define USART_CR2_CPOL_Msk                        (0x1UL<<USART_CR2_CPOL_Pos)                       /*!< 0x00000400 */
#define USART_CR2_CPOL                            USART_CR2_CPOL_Msk                                /*!< cpol */
#define USART_CR2_CLKEN_Pos                       (11U)
#define USART_CR2_CLKEN_Msk                       (0x1UL<<USART_CR2_CLKEN_Pos)                      /*!< 0x00000800 */
#define USART_CR2_CLKEN                           USART_CR2_CLKEN_Msk                               /*!< clk en */
#define USART_CR2_STOP_Pos                        (12U)
#define USART_CR2_STOP_Msk                        (0x3UL<<USART_CR2_STOP_Pos)                       /*!< 0x00003000 */
#define USART_CR2_STOP                            USART_CR2_STOP_Msk                                /*!< stop bit */
#define USART_CR2_STOP_0                          (0x1UL<<USART_CR2_STOP_Pos)                       /*!< 0x00001000 */
#define USART_CR2_STOP_1                          (0x2UL<<USART_CR2_STOP_Pos)                       /*!< 0x00002000 */
#define USART_CR2_LINEN_Pos                       (14U)
#define USART_CR2_LINEN_Msk                       (0x1UL<<USART_CR2_LINEN_Pos)                      /*!< 0x00004000 */
#define USART_CR2_LINEN                           USART_CR2_LINEN_Msk                               /*!< lin enable */
#define USART_CR2_RTOEN_Pos                       (25U)
#define USART_CR2_RTOEN_Msk                       (0x1UL<<USART_CR2_RTOEN_Pos)                      /*!< 0x02000000 */
#define USART_CR2_RTOEN                           USART_CR2_RTOEN_Msk                               /*!< Receiver timeout enable */
#define USART_CR2_ERSW_Pos                        (26U)
#define USART_CR2_ERSW_Msk                        (0x3UL<<USART_CR2_ERSW_Pos)                       /*!< 0x0C000000 */
#define USART_CR2_ERSW                            USART_CR2_ERSW_Msk                                /*!< error select width */
#define USART_CR2_ERSW_0                          (0x1UL<<USART_CR2_ERSW_Pos)                       /*!< 0x04000000 */
#define USART_CR2_ERSW_1                          (0x2UL<<USART_CR2_ERSW_Pos)                       /*!< 0x08000000 */
#define USART_CR2_REP_T_Pos                       (28U)
#define USART_CR2_REP_T_Msk                       (0x1UL<<USART_CR2_REP_T_Pos)                      /*!< 0x10000000 */
#define USART_CR2_REP_T                           USART_CR2_REP_T_Msk                               /*!< repeat times */
#define USART_CR2_TREPEN_Pos                      (29U)
#define USART_CR2_TREPEN_Msk                      (0x1UL<<USART_CR2_TREPEN_Pos)                     /*!< 0x20000000 */
#define USART_CR2_TREPEN                          USART_CR2_TREPEN_Msk                              /*!< tx repeat enable */
#define USART_CR2_RREPEN_Pos                      (30U)
#define USART_CR2_RREPEN_Msk                      (0x1UL<<USART_CR2_RREPEN_Pos)                     /*!< 0x40000000 */
#define USART_CR2_RREPEN                          USART_CR2_RREPEN_Msk                              

/********************************* Bit definition for USART_CR3 register ********************************************/
#define USART_CR3_EIE_Pos                         (0U)
#define USART_CR3_EIE_Msk                         (0x1UL<<USART_CR3_EIE_Pos)                        /*!< 0x00000001 */
#define USART_CR3_EIE                             USART_CR3_EIE_Msk                                 /*!< error int enable */
#define USART_CR3_IREN_Pos                        (1U)
#define USART_CR3_IREN_Msk                        (0x1UL<<USART_CR3_IREN_Pos)                       /*!< 0x00000002 */
#define USART_CR3_IREN                            USART_CR3_IREN_Msk                                /*!< iren enable */
#define USART_CR3_IRLP_Pos                        (2U)
#define USART_CR3_IRLP_Msk                        (0x1UL<<USART_CR3_IRLP_Pos)                       /*!< 0x00000004 */
#define USART_CR3_IRLP                            USART_CR3_IRLP_Msk                                /*!< idra lowpower */
#define USART_CR3_HDSEL_Pos                       (3U)
#define USART_CR3_HDSEL_Msk                       (0x1UL<<USART_CR3_HDSEL_Pos)                      /*!< 0x00000008 */
#define USART_CR3_HDSEL                           USART_CR3_HDSEL_Msk                               /*!< hdsel  */
#define USART_CR3_NACK_Pos                        (4U)
#define USART_CR3_NACK_Msk                        (0x1UL<<USART_CR3_NACK_Pos)                       /*!< 0x00000010 */
#define USART_CR3_NACK                            USART_CR3_NACK_Msk                                /*!< scen nack enable */
#define USART_CR3_SCEN_Pos                        (5U)
#define USART_CR3_SCEN_Msk                        (0x1UL<<USART_CR3_SCEN_Pos)                       /*!< 0x00000020 */
#define USART_CR3_SCEN                            USART_CR3_SCEN_Msk                                /*!< scen enable */
#define USART_CR3_DMAR_Pos                        (6U)
#define USART_CR3_DMAR_Msk                        (0x1UL<<USART_CR3_DMAR_Pos)                       /*!< 0x00000040 */
#define USART_CR3_DMAR                            USART_CR3_DMAR_Msk                                /*!< dma rx enable */
#define USART_CR3_DMAT_Pos                        (7U)
#define USART_CR3_DMAT_Msk                        (0x1UL<<USART_CR3_DMAT_Pos)                       /*!< 0x00000080 */
#define USART_CR3_DMAT                            USART_CR3_DMAT_Msk                                /*!< dma tx enable */
#define USART_CR3_RTSE_Pos                        (8U)
#define USART_CR3_RTSE_Msk                        (0x1UL<<USART_CR3_RTSE_Pos)                       /*!< 0x00000100 */
#define USART_CR3_RTSE                            USART_CR3_RTSE_Msk                                /*!< rts enable */
#define USART_CR3_CTSE_Pos                        (9U)
#define USART_CR3_CTSE_Msk                        (0x1UL<<USART_CR3_CTSE_Pos)                       /*!< 0x00000200 */
#define USART_CR3_CTSE                            USART_CR3_CTSE_Msk                                /*!< cts enable */
#define USART_CR3_CTSIE_Pos                       (10U)
#define USART_CR3_CTSIE_Msk                       (0x1UL<<USART_CR3_CTSIE_Pos)                      /*!< 0x00000400 */
#define USART_CR3_CTSIE                           USART_CR3_CTSIE_Msk                               /*!< cts int enable */
#define USART_CR3_OVER8_Pos                       (11U)
#define USART_CR3_OVER8_Msk                       (0x1UL<<USART_CR3_OVER8_Pos)                      /*!< 0x00000800 */
#define USART_CR3_OVER8                           USART_CR3_OVER8_Msk                               /*!< oversampling  */
#define USART_CR3_ABREN_Pos                       (12U)
#define USART_CR3_ABREN_Msk                       (0x1UL<<USART_CR3_ABREN_Pos)                      /*!< 0x00001000 */
#define USART_CR3_ABREN                           USART_CR3_ABREN_Msk                               /*!< autobaud enable */
#define USART_CR3_ABRMOD_Pos                      (13U)
#define USART_CR3_ABRMOD_Msk                      (0x3UL<<USART_CR3_ABRMOD_Pos)                     /*!< 0x00006000 */
#define USART_CR3_ABRMOD                          USART_CR3_ABRMOD_Msk                              /*!< auto baud mod */
#define USART_CR3_ABRMOD_0                        (0x1UL<<USART_CR3_ABRMOD_Pos)                     /*!< 0x00002000 */
#define USART_CR3_ABRMOD_1                        (0x2UL<<USART_CR3_ABRMOD_Pos)                     /*!< 0x00004000 */
#define USART_CR3_RTOIE_Pos                       (29U)
#define USART_CR3_RTOIE_Msk                       (0x1UL<<USART_CR3_RTOIE_Pos)                      /*!< 0x20000000 */
#define USART_CR3_RTOIE                           USART_CR3_RTOIE_Msk                               /*!< rto int enable */
#define USART_CR3_EOBIE_Pos                       (30U)
#define USART_CR3_EOBIE_Msk                       (0x1UL<<USART_CR3_EOBIE_Pos)                      /*!< 0x40000000 */
#define USART_CR3_EOBIE                           USART_CR3_EOBIE_Msk                               /*!< eob int enable */
/* #define USART_CR3_TXLSEIE_Pos                     (31U) */
/* #define USART_CR3_TXLSEIE_Msk                     (0x1UL<<USART_CR3_TXLSEIE_Pos) */                   /*!< 0x80000000 */
/* #define USART_CR3_TXLSEIE                         USART_CR3_TXLSEIE_Msk          */                   /*!< tx register empty int enable */

/********************************* Bit definition for USART_GTPR register *******************************************/
#define USART_GTPR_PSC_Pos                        (0U)
#define USART_GTPR_PSC_Msk                        (0xFFUL<<USART_GTPR_PSC_Pos)                      /*!< 0x000000FF */
#define USART_GTPR_PSC                            USART_GTPR_PSC_Msk                                /*!< Prescaler value */
#define USART_GTPR_GT_Pos                         (8U)
#define USART_GTPR_GT_Msk                         (0xFFUL<<USART_GTPR_GT_Pos)                       /*!< 0x0000FF00 */
#define USART_GTPR_GT                             USART_GTPR_GT_Msk                                 /*!< Guard time value */

/********************************* Bit definition for USART_RTOR register *******************************************/
#define USART_RTOR_RTO_Pos                        (0U)
#define USART_RTOR_RTO_Msk                        (0xFFFFFFUL<<USART_RTOR_RTO_Pos)                  /*!< 0x00FFFFFF */
#define USART_RTOR_RTO                            USART_RTOR_RTO_Msk                                /*!< receive timeout */
#define USART_RTOR_BLEN_Pos                       (24U)
#define USART_RTOR_BLEN_Msk                       (0xFFUL<<USART_RTOR_BLEN_Pos)                     /*!< 0xFF000000 */
#define USART_RTOR_BLEN                           USART_RTOR_BLEN_Msk                               /*!< blocken length */


/********************************************************************************************************************/
/********************************* WWDG *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for WWDG_CR register **********************************************/
#define WWDG_CR_T_Pos                             (0U)
#define WWDG_CR_T_Msk                             (0x7FUL<<WWDG_CR_T_Pos)                           /*!< 0x0000007F */
#define WWDG_CR_T                                 WWDG_CR_T_Msk                                     /*!< wwdg counter bit6 */
#define WWDG_CR_T_0                               (0x1UL << WWDG_CR_T_Pos)                          /*!< 0x00000001 */
#define WWDG_CR_T_1                               (0x2UL << WWDG_CR_T_Pos)                          /*!< 0x00000002 */
#define WWDG_CR_T_2                               (0x4UL << WWDG_CR_T_Pos)                          /*!< 0x00000004 */
#define WWDG_CR_T_3                               (0x8UL << WWDG_CR_T_Pos)                          /*!< 0x00000008 */
#define WWDG_CR_T_4                               (0x10UL << WWDG_CR_T_Pos)                         /*!< 0x00000010 */
#define WWDG_CR_T_5                               (0x20UL << WWDG_CR_T_Pos)                         /*!< 0x00000020 */
#define WWDG_CR_T_6                               (0x40UL << WWDG_CR_T_Pos)                         /*!< 0x00000040 */
#define WWDG_CR_WDGA_Pos                          (7U)
#define WWDG_CR_WDGA_Msk                          (0x1UL<<WWDG_CR_WDGA_Pos)                         /*!< 0x00000080 */
#define WWDG_CR_WDGA                              WWDG_CR_WDGA_Msk                                  /*!< WWDG Activation */

/********************************* Bit definition for WWDG_CFR register *********************************************/
#define WWDG_CFR_W_Pos                            (0U)
#define WWDG_CFR_W_Msk                            (0x7FUL<<WWDG_CFR_W_Pos)                          /*!< 0x0000007F */
#define WWDG_CFR_W                                WWDG_CFR_W_Msk                                    /*!< window value bit 6 */
#define WWDG_CFR_W_0                              (0x1UL << WWDG_CFR_W_Pos)                         /*!< 0x00000001 */
#define WWDG_CFR_W_1                              (0x2UL << WWDG_CFR_W_Pos)                         /*!< 0x00000002 */
#define WWDG_CFR_W_2                              (0x4UL << WWDG_CFR_W_Pos)                         /*!< 0x00000004 */
#define WWDG_CFR_W_3                              (0x8UL << WWDG_CFR_W_Pos)                         /*!< 0x00000008 */
#define WWDG_CFR_W_4                              (0x10UL << WWDG_CFR_W_Pos)                        /*!< 0x00000010 */
#define WWDG_CFR_W_5                              (0x20UL << WWDG_CFR_W_Pos)                        /*!< 0x00000020 */
#define WWDG_CFR_W_6                              (0x40UL << WWDG_CFR_W_Pos)                        /*!< 0x00000040 */
#define WWDG_CFR_WDGTB_Pos                        (7U)
#define WWDG_CFR_WDGTB_Msk                        (0x3UL<<WWDG_CFR_WDGTB_Pos)                       /*!< 0x00000180 */
#define WWDG_CFR_WDGTB                            WWDG_CFR_WDGTB_Msk                                /*!< time base bit 1 */
#define WWDG_CFR_WDGTB_0                          (0x1UL<<WWDG_CFR_WDGTB_Pos)                       /*!< 0x00000080 */
#define WWDG_CFR_WDGTB_1                          (0x2UL<<WWDG_CFR_WDGTB_Pos)                       /*!< 0x00000100 */
#define WWDG_CFR_EWI_Pos                          (9U)
#define WWDG_CFR_EWI_Msk                          (0x1UL<<WWDG_CFR_EWI_Pos)                         /*!< 0x00000200 */
#define WWDG_CFR_EWI                              WWDG_CFR_EWI_Msk                                  /*!< Early wakeup interrupt */

/********************************* Bit definition for WWDG_SR register **********************************************/
#define WWDG_SR_EWIF_Pos                          (0U)
#define WWDG_SR_EWIF_Msk                          (0x1UL<<WWDG_SR_EWIF_Pos)                         /*!< 0x00000001 */
#define WWDG_SR_EWIF                              WWDG_SR_EWIF_Msk                                  /*!< Early wakeup interrupt flag */

/********************************************************************************************************************/
/********************************* VREFBUF **************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for VREFBUF_CR register *******************************************/
#define VREFBUF_CR_VREFBUF_OUT_SEL_Pos            (0U)
#define VREFBUF_CR_VREFBUF_OUT_SEL_Msk            (0x7UL<<VREFBUF_CR_VREFBUF_OUT_SEL_Pos)           /*!< 0x00000007 */
#define VREFBUF_CR_VREFBUF_OUT_SEL                VREFBUF_CR_VREFBUF_OUT_SEL_Msk
#define VREFBUF_CR_VREFBUF_OUT_SEL_0              (0x1UL<<VREFBUF_CR_VREFBUF_OUT_SEL_Pos)           /*!< 0x00000001 */
#define VREFBUF_CR_VREFBUF_OUT_SEL_1              (0x2UL<<VREFBUF_CR_VREFBUF_OUT_SEL_Pos)           /*!< 0x00000002 */
#define VREFBUF_CR_VREFBUF_OUT_SEL_2              (0x4UL<<VREFBUF_CR_VREFBUF_OUT_SEL_Pos)           /*!< 0x00000004 */
#define VREFBUF_CR_VREFBUF_EN_Pos                 (3U)
#define VREFBUF_CR_VREFBUF_EN_Msk                 (0x1UL<<VREFBUF_CR_VREFBUF_EN_Pos)                /*!< 0x00000008 */
#define VREFBUF_CR_VREFBUF_EN                     VREFBUF_CR_VREFBUF_EN_Msk                         


/** @addtogroup Exported_macros
  * @{
  */

/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC_COMMON)

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)


/******************************** DMA Instances *******************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA_Channel1) || \
                                       ((INSTANCE) == DMA_Channel2) || \
                                       ((INSTANCE) == DMA_Channel3) || \
                                       ((INSTANCE) == DMA_Channel4) || \
                                       ((INSTANCE) == DMA_Channel5) || \
                                       ((INSTANCE) == DMA_Channel6) || \
                                       ((INSTANCE) == DMA_Channel7))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD))

/********************** GPIO Alternate Function Instances *********************/
#define IS_GPIO_AF_INSTANCE(INSTANCE)   IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/****************************** I2C Instances ********************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == I2C1) || \
                                        ((INSTANCE) == I2C2))
 
/********************* I2C WAKEUP FROMSTOP Instances **************************/
#define IS_I2C_WAKEUP_FROMSTOP_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                                   ((INSTANCE) == I2C2)) 

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

#define IS_TAMP_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == TAMP)
/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2))

#define IS_I2S_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2))                                       

/****************** LPTIM Instances : All supported instances *****************/
#define IS_LPTIM_INSTANCE(INSTANCE)   (((INSTANCE) == LPTIM1) || \
                                       ((INSTANCE) == LPTIM2))

/****************** LPTIM Instances : supporting 32 bits counter ****************/
#define IS_LPTIM_32B_COUNTER_INSTANCE(INSTANCE) ((INSTANCE) == LPTIM1)

/****************************** START TIM Instances ***************************/
/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(INSTANCE)       (((INSTANCE) == TIM1)    || \
                                         ((INSTANCE) == TIM2)    || \
                                         ((INSTANCE) == TIM3)    || \
                                         ((INSTANCE) == TIM6)    || \
                                         ((INSTANCE) == TIM7)    || \
                                         ((INSTANCE) == TIM15)   || \
                                         ((INSTANCE) == TIM16)   || \
                                         ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting 32 bits counter ****************/
#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE) ((INSTANCE) == TIM2    || \
                                               (INSTANCE) == TIM6 )

/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)    || \
                                            ((INSTANCE) == TIM15)   || \
                                            ((INSTANCE) == TIM16)   || \
                                            ((INSTANCE) == TIM17))

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)   || \
                                          ((INSTANCE) == TIM2)   || \
                                          ((INSTANCE) == TIM3)   || \
                                          ((INSTANCE) == TIM15)  || \
                                          ((INSTANCE) == TIM16)  || \
                                          ((INSTANCE) == TIM17))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)   || \
                                          ((INSTANCE) == TIM2)   || \
                                          ((INSTANCE) == TIM3)   || \
                                          ((INSTANCE) == TIM15))

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)   || \
                                          ((INSTANCE) == TIM2)   || \
                                          ((INSTANCE) == TIM3))

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)   || \
                                          ((INSTANCE) == TIM2)   || \
                                          ((INSTANCE) == TIM3))

/************ TIM Instances : DMA requests generation (TIMx_DIER.UDE) *********/
#define IS_TIM_DMA_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2)   || \
                                            ((INSTANCE) == TIM3)   || \
                                            ((INSTANCE) == TIM6)   || \
                                            ((INSTANCE) == TIM7)   || \
                                            ((INSTANCE) == TIM15)  || \
                                            ((INSTANCE) == TIM16)  || \
                                            ((INSTANCE) == TIM17))

/************ TIM Instances : DMA requests generation (TIMx_DIER.CCxDE) *******/
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2)   || \
                                            ((INSTANCE) == TIM3)   || \
                                            ((INSTANCE) == TIM15)  || \
                                            ((INSTANCE) == TIM16)  || \
                                            ((INSTANCE) == TIM17))

/******************** TIM Instances : DMA burst feature ***********************/
#define IS_TIM_DMABURST_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2)   || \
                                            ((INSTANCE) == TIM3)   || \
                                            ((INSTANCE) == TIM15)  || \
                                            ((INSTANCE) == TIM16)  || \
                                            ((INSTANCE) == TIM17))

/******************* TIM Instances : output(s) available **********************/
#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
     ||                                        \
    (((INSTANCE) == TIM2) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
     ||                                        \
    (((INSTANCE) == TIM3) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
     ||                                        \
     (((INSTANCE) == TIM15) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2)))           \
     ||                                         \
     (((INSTANCE) == TIM16) &&                 \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
     ||                                        \
     (((INSTANCE) == TIM17) &&                 \
      (((CHANNEL) == TIM_CHANNEL_1))))

/****************** TIM Instances : supporting complementary output(s) ********/
#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    ||                                          \
    (((INSTANCE) == TIM15) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1))              \
    ||                                          \
    (((INSTANCE) == TIM16) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1))              \
    ||                                          \
    (((INSTANCE) == TIM17) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1)))

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)    || \
                                                    ((INSTANCE) == TIM2)    || \
                                                    ((INSTANCE) == TIM3)    || \
                                                    ((INSTANCE) == TIM15)   || \
                                                    ((INSTANCE) == TIM16)   || \
                                                    ((INSTANCE) == TIM17))

/****** TIM Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM15))

/****** TIM Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM15))

/********** TIM Instances : supporting external clock mode 1 for TIX inputs****/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM15))

/********** TIM Instances : supporting internal trigger inputs(ITRX) **********/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)     (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1)   || \
                                                      ((INSTANCE) == TIM15)  || \
                                                      ((INSTANCE) == TIM16)  || \
                                                      ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3))

/****************** TIM Instances : supporting Hall sensor interface **********/
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1))

/****** TIM Instances : Master mode available (TIMx_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2)  || \
                                            ((INSTANCE) == TIM3)  || \
                                            ((INSTANCE) == TIM6)  || \
                                            ((INSTANCE) == TIM7)  || \
                                            ((INSTANCE) == TIM15))

/*********** TIM Instances : Slave mode available (TIMx_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2)  || \
                                            ((INSTANCE) == TIM3)  || \
                                            ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)         (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3))

/****************** TIM Instances : supporting bitfield OCCS in SMCR register *******************/
#define IS_TIM_OCCS_INSTANCE(INSTANCE)                (((INSTANCE) == TIM1)  || \
                                                       ((INSTANCE) == TIM2)  || \
                                                       ((INSTANCE) == TIM3))

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)   || \
                                              ((INSTANCE) == TIM2)   || \
                                              ((INSTANCE) == TIM3)   || \
                                              ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)  || \
                                                        ((INSTANCE) == TIM15)  || \
                                                        ((INSTANCE) == TIM16)  || \
                                                        ((INSTANCE) == TIM17))

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2)   || \
                                            ((INSTANCE) == TIM3))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE) (((INSTANCE) == UART1) || \
                                    ((INSTANCE) == UART2))

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2))

/******************** USART Instances : Asynchronous mode *********************/
#define IS_SCI_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                   ((INSTANCE) == USART2))

/******************** USART Instances : HWFLOW mode ***************************/
#define IS_SCI_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                          ((INSTANCE) == USART2))

/****************** USART Instances : Driver Enable detection *****************/
#define IS_SCI_DRIVER_ENABLE_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                 ((INSTANCE) == USART2))

/****************** USART Instances : Auto Baud Rate detection ****************/
#define IS_SCI_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                          ((INSTANCE) == USART2))

/******************** USART Instances : Asynchronous mode *********************/
#define IS_SCI_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                              ((INSTANCE) == USART2))
                                              
/******************** USART Instances : Asynchronous mode *********************/
#define IS_SCI_LIN_INSTANCE(INSTANCE)        (((INSTANCE) == USART1) || \
                                              ((INSTANCE) == USART2))

/******************** USART Instances : Half-Duplex mode **********************/
#define IS_USART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                ((INSTANCE) == USART2))

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                               ((INSTANCE) == USART2))

/******************** USART Instances : LIN mode **********************/
#define IS_USART_LIN_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2))

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) )

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2))

/********************* UART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2))

/****************** UART Instances : Auto Baud Rate detection *****************/
#define IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                            ((INSTANCE) == USART2))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2))

/***************** UART Instances : Multi-Processor mode **********************/
#define IS_UART_MULTIPROCESSOR_INSTANCE(INSTANCE)  (((INSTANCE) == USART1) || \
                                                    ((INSTANCE) == USART2))

/***************** UART Instances : DMA mode available ************************/
#define IS_UART_DMA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2))

/****************** LPUART Instances : Hardware Flow control ******************/
#define IS_LPUART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == LPUART1) || \
                                             ((INSTANCE) == LPUART2))

/****************** LPUART Instances : Hardware Flow control ******************/
#define IS_LPUART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == LPUART1) || \
                                                 ((INSTANCE) == LPUART2))

/******************** LPUART Instance *****************************************/
#define IS_LPUART_INSTANCE(INSTANCE)    (((INSTANCE) == LPUART1) || \
                                         ((INSTANCE) == LPUART2))                                          

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)

/****************************** LCD Instances ********************************/
#define IS_LCD_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == LCD)

/****************************** COMP Instances ********************************/
#define IS_COMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == COMP1) || \
                                        ((INSTANCE) == COMP2))

/****************************** OPA Instances ********************************/
#define IS_OPA_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == OPA)

/****************************** DAC Instances *******************************/
#define IS_DAC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DAC)

/****************************** LPUART Instances ********************************/
#define IS_LPUART_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == LPUART1) || \
                                           ((INSTANCE) == LPUART2))

/****************************** LPUART Instances : Driver Enable ******** **/
#define IS_LPUART_DRIVER_ENABLE_INSTANCE(INSTANCE)  (((INSTANCE) == LPUART1) || \
                                                     ((INSTANCE) == LPUART2))

/****************************** LPUART Instances : Wake-up from Stop mode *****/
#define IS_LPUART_WAKEUP_FROMSTOP_INSTANCE(INSTANCE)  (((INSTANCE) == LPUART1) || \
                                                       ((INSTANCE) == LPUART2))

/****************************** TK Instances *******************************/
#define IS_TK_ALL_INSTANCE(INSTANCE) ((INSTANCE) == TK) 

/****************************** PWM Instances *******************************/
#define IS_PWM_INSTANCE(INSTANCE) ((INSTANCE) == PWM) 

/****************** PWM Instances : supporting the break function *************/
#define IS_PWM_BREAK_INSTANCE(INSTANCE)    ((INSTANCE) == PWM)

/************* PWM Instances : at least 1 compare channel *************/
#define IS_PWM_OC1_INSTANCE(INSTANCE)    ((INSTANCE) == PWM)

/************ PWM Instances : at least 2 compare channels *************/
#define IS_PWM_OC2_INSTANCE(INSTANCE)    ((INSTANCE) == PWM)

/************ PWM Instances : at least 3 compare channels *************/
#define IS_PWM_OC3_INSTANCE(INSTANCE)    ((INSTANCE) == PWM)

/************ PWM Instances : at least 4 compare channels *************/
#define IS_PWM_OC4_INSTANCE(INSTANCE)    ((INSTANCE) == PWM)

/************ PWM Instances : DMA requests generation (PWMx_DIER.UDE) *********/
#define IS_PWM_DMA_INSTANCE(INSTANCE)      ((INSTANCE) == PWM)

/************ PWM Instances : DMA requests generation (PWMx_DIER.OCxDE) *******/
#define IS_PWM_DMA_OC_INSTANCE(INSTANCE)   ((INSTANCE) == PWM)

/******************** PWM Instances : DMA burst feature ***********************/
#define IS_PWM_DMABURST_INSTANCE(INSTANCE)  ((INSTANCE) == PWM)

/******************* PWM Instances : output(s) available **********************/
#define IS_PWM_OCX_INSTANCE(INSTANCE, CHANNEL) \
    (((INSTANCE) == PWM) &&                  \
     (((CHANNEL) == PWM_CHANNEL_1) ||          \
      ((CHANNEL) == PWM_CHANNEL_2) ||          \
      ((CHANNEL) == PWM_CHANNEL_3) ||          \
      ((CHANNEL) == PWM_CHANNEL_4)))

/****************** PWM Instances : supporting complementary output(s) ********/
#define IS_PWM_OCXN_INSTANCE(INSTANCE, CHANNEL) \
    (((INSTANCE) == PWM) &&                   \
     (((CHANNEL) == PWM_CHANNEL_1) ||           \
      ((CHANNEL) == PWM_CHANNEL_2)))

/****************** PWM Instances : supporting clock division *****************/
#define IS_PWM_CLOCK_DIVISION_INSTANCE(INSTANCE)   ((INSTANCE) == PWM)

/****** PWM Instances : supporting external clock mode *******/
#define IS_PWM_CLOCKSOURCE_ETRMODE_INSTANCE(INSTANCE) ((INSTANCE) == PWM)

/****************** PWM Instances : supporting counting mode selection ********/
#define IS_PWM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  ((INSTANCE) == PWM)

/****************** PWM Instances : remapping capability **********************/
#define IS_PWM_REMAP_INSTANCE(INSTANCE)      ((INSTANCE) == PWM)

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
#endif /* __cplusplus */

#endif /* __PY32C882XC_H */

/**
  * @}
  */

/**
* @}
*/

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

