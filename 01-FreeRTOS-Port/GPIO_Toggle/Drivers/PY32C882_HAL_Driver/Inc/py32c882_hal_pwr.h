/**
  ******************************************************************************
  * @file   py32c882_hal_pwr.h
  * @author  MCU Application Team
  * @brief   Header file of PWR HAL module.
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
#ifndef __PY32C882_HAL_PWR_H
#define __PY32C882_HAL_PWR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup PWR
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup PWR_Exported_Types PWR Exported Types
  * @{
  */ 

/**
  * @brief  PWR PVD configuration structure definition
  */
typedef struct
{
  uint32_t PVDLevel;   /*!< PVDLevel: Specifies the PVD detection level.
                            This parameter can be a value of @ref PWR_PVD_detection_level */
    
  uint32_t PVDFilter;  /*!< PVDFilter: Specifies the PVD Filter.
                            This parameter can be a value of @ref PWR_PVD_Filter */

  uint32_t Mode;       /*!< Mode: Specifies the operating mode for the selected pins.
                            This parameter can be a value of @ref PWR_PVD_Mode */

  uint32_t PVDOutputSelect;  /*!< PVDOutSelect: Specifies output selection of the PVD.
                            This parameter can be a value of @ref PWR_PVD_Output_Select */
}PWR_PVDTypeDef;


/**
  * @}
  */


/* Internal constants --------------------------------------------------------*/

/** @addtogroup PWR_Private_Constants
  * @{
  */ 

#define PWR_EXTI_LINE_PVD  ((uint32_t)0x00010000)  /*!< External interrupt line 16 Connected to the PVD EXTI Line */

/**
  * @}
  */

 
/* Exported constants --------------------------------------------------------*/

/** @defgroup PWR_Exported_Constants PWR Exported Constants
  * @{
  */ 

/** @defgroup PWR_PVD_detection_level PWR PVD detection level
  * @{
  */
#define PWR_PVDLEVEL_0                  PWR_CR2_PVDT_1V8
#define PWR_PVDLEVEL_1                  PWR_CR2_PVDT_2V0
#define PWR_PVDLEVEL_2                  PWR_CR2_PVDT_2V2
#define PWR_PVDLEVEL_3                  PWR_CR2_PVDT_2V4
#define PWR_PVDLEVEL_4                  PWR_CR2_PVDT_2V8
#define PWR_PVDLEVEL_5                  PWR_CR2_PVDT_3V1
#define PWR_PVDLEVEL_6                  PWR_CR2_PVDT_3V7
#define PWR_PVDLEVEL_7                  PWR_CR2_PVDT_4V2 
                                                          
/**
  * @}
  */
  
/** @defgroup PWR_PVD_Filter PWR PVD Filter
  * @{
  */
#define PWR_PVD_FILTER_NONE               0x00000000U
#define PWR_PVD_FILTER_1CLOCK             (PWR_CR2_FLTEN)
#define PWR_PVD_FILTER_2CLOCK             (PWR_CR2_FLTEN | PWR_CR2_FLT_TIME_0)
#define PWR_PVD_FILTER_4CLOCK             (PWR_CR2_FLTEN | PWR_CR2_FLT_TIME_1)
#define PWR_PVD_FILTER_16CLOCK            (PWR_CR2_FLTEN | PWR_CR2_FLT_TIME_0 | PWR_CR2_FLT_TIME_1)
#define PWR_PVD_FILTER_64CLOCK            (PWR_CR2_FLTEN | PWR_CR2_FLT_TIME_2)
#define PWR_PVD_FILTER_128CLOCK           (PWR_CR2_FLTEN | PWR_CR2_FLT_TIME_0 | PWR_CR2_FLT_TIME_2)
#define PWR_PVD_FILTER_1024CLOCK          (PWR_CR2_FLTEN | PWR_CR2_FLT_TIME_1 | PWR_CR2_FLT_TIME_2)  
/**
  * @}
  */

/** @defgroup PWR_PVD_Output_Select PWR PVD Output Select
  * @{
  */
#define PWR_PVD_OUT_NOT_SYN_FILTER        0x00000000U
#define PWR_PVD_OUT_SYN_FILTER            (PWR_CR2_PVD_OUT_SEL)
/**
  * @}
  */

/** @defgroup PWR_PVD_Mode PWR PVD Mode
  * @{
  */
#define PWR_PVD_MODE_NORMAL                 0x00000000U   /*!< basic mode is used */
#define PWR_PVD_MODE_IT_RISING              0x00010001U   /*!< External Interrupt Mode with Rising edge trigger detection */
#define PWR_PVD_MODE_IT_FALLING             0x00010002U   /*!< External Interrupt Mode with Falling edge trigger detection */
#define PWR_PVD_MODE_IT_RISING_FALLING      0x00010003U   /*!< External Interrupt Mode with Rising/Falling edge trigger detection */
#define PWR_PVD_MODE_EVENT_RISING           0x00020001U   /*!< Event Mode with Rising edge trigger detection */
#define PWR_PVD_MODE_EVENT_FALLING          0x00020002U   /*!< Event Mode with Falling edge trigger detection */
#define PWR_PVD_MODE_EVENT_RISING_FALLING   0x00020003U   /*!< Event Mode with Rising/Falling edge trigger detection */

/**
  * @}
  */

/** @defgroup PWREx_WUP_Polarity Shift to apply to retrieve polarity information from PWR_WAKEUP_PINy_xxx constants
  * @{
  */
#define PWR_WUP_POLARITY_SHIFT                  0x08U   /*!< Internal constant used to retrieve wakeup pin polariry */
/**
  * @}
  */

/** @defgroup PWREx_WakeUp_Pins  PWR wake-up pins
  * @{
  */
#define PWR_WAKEUP_PIN0                 PWR_CR3_EWUP0  /*!< Wakeup pin 0 (with high level polarity) */
#define PWR_WAKEUP_PIN1                 PWR_CR3_EWUP1  /*!< Wakeup pin 1 (with high level polarity) */
#define PWR_WAKEUP_PIN2                 PWR_CR3_EWUP2  /*!< Wakeup pin 2 (with high level polarity) */
#define PWR_WAKEUP_PIN3                 PWR_CR3_EWUP3  /*!< Wakeup pin 3 (with high level polarity) */
#define PWR_WAKEUP_PIN4                 PWR_CR3_EWUP4  /*!< Wakeup pin 4 (with high level polarity) */
#define PWR_WAKEUP_PIN5                 PWR_CR3_EWUP5  /*!< Wakeup pin 5 (with high level polarity) */
#define PWR_WAKEUP_PIN6                 PWR_CR3_EWUP6  /*!< Wakeup pin 6 (with high level polarity) */
#define PWR_WAKEUP_PIN7                 PWR_CR3_EWUP7  /*!< Wakeup pin 7 (with high level polarity) */
#define PWR_WAKEUP_PIN0_HIGH            PWR_CR3_EWUP0  /*!< Wakeup pin 0 (with high level polarity) */
#define PWR_WAKEUP_PIN1_HIGH            PWR_CR3_EWUP1  /*!< Wakeup pin 1 (with high level polarity) */
#define PWR_WAKEUP_PIN2_HIGH            PWR_CR3_EWUP2  /*!< Wakeup pin 2 (with high level polarity) */
#define PWR_WAKEUP_PIN3_HIGH            PWR_CR3_EWUP3  /*!< Wakeup pin 3 (with high level polarity) */
#define PWR_WAKEUP_PIN4_HIGH            PWR_CR3_EWUP4  /*!< Wakeup pin 4 (with high level polarity) */
#define PWR_WAKEUP_PIN5_HIGH            PWR_CR3_EWUP5  /*!< Wakeup pin 5 (with high level polarity) */
#define PWR_WAKEUP_PIN6_HIGH            PWR_CR3_EWUP6  /*!< Wakeup pin 6 (with high level polarity) */
#define PWR_WAKEUP_PIN7_HIGH            PWR_CR3_EWUP7  /*!< Wakeup pin 7 (with high level polarity) */
#define PWR_WAKEUP_PIN0_LOW             (uint32_t)((PWR_CR4_WP0_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP0) /*!< Wakeup pin 0 (with low level polarity) */
#define PWR_WAKEUP_PIN1_LOW             (uint32_t)((PWR_CR4_WP1_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP1) /*!< Wakeup pin 1 (with low level polarity) */
#define PWR_WAKEUP_PIN2_LOW             (uint32_t)((PWR_CR4_WP2_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP2) /*!< Wakeup pin 2 (with low level polarity) */
#define PWR_WAKEUP_PIN3_LOW             (uint32_t)((PWR_CR4_WP3_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP3) /*!< Wakeup pin 3 (with low level polarity) */
#define PWR_WAKEUP_PIN4_LOW             (uint32_t)((PWR_CR4_WP4_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP4) /*!< Wakeup pin 4 (with low level polarity) */
#define PWR_WAKEUP_PIN5_LOW             (uint32_t)((PWR_CR4_WP5_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP5) /*!< Wakeup pin 5 (with low level polarity) */
#define PWR_WAKEUP_PIN6_LOW             (uint32_t)((PWR_CR4_WP6_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP6) /*!< Wakeup pin 6 (with low level polarity) */
#define PWR_WAKEUP_PIN7_LOW             (uint32_t)((PWR_CR4_WP7_0<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP7) /*!< Wakeup pin 7 (with low level polarity) */
/**
  * @}
  */

/** @defgroup PWR_Regulator_state_in_SLEEP_STOP_mode PWR Regulator state in STOP mode
  * @{
  */
#define PWR_MAINREGULATOR_ON                        0x00000000U            /* MR mode */
#define PWR_LOWPOWERREGULATOR_ON                    PWR_CR1_VR_MODE_0      /* LPR mode */
#define PWR_DEEPLOWPOWERREGULATOR_ON                PWR_CR1_VR_MODE_1      /* DLPR mode */
/**
  * @}
  */

/** @defgroup PWR_SLEEP_mode_entry PWR SLEEP mode entry
  * @{
  */
#define PWR_SLEEPENTRY_WFI              ((uint8_t)0x01)
#define PWR_SLEEPENTRY_WFE              ((uint8_t)0x02)

/**
  * @}
  */

/** @defgroup PWR_STOP_mode_entry PWR STOP mode entry
  * @{
  */
#define PWR_STOPENTRY_WFI               ((uint8_t)0x01)
#define PWR_STOPENTRY_WFE               ((uint8_t)0x02)

/**
  * @}
  */

/** @defgroup PWR_Flag PWR Flag
  * @{
  */
#define PWR_FLAG_WU0                    PWR_SR_WUF0
#define PWR_FLAG_WU1                    PWR_SR_WUF1
#define PWR_FLAG_WU2                    PWR_SR_WUF2
#define PWR_FLAG_WU3                    PWR_SR_WUF3
#define PWR_FLAG_WU4                    PWR_SR_WUF4
#define PWR_FLAG_WU5                    PWR_SR_WUF5
#define PWR_FLAG_WU6                    PWR_SR_WUF6
#define PWR_FLAG_WU7                    PWR_SR_WUF7
#define PWR_FLAG_WU                     PWR_SR_WUF  /*!< Encompass wakeup event on all wakeup pins */
#define PWR_FLAG_SB                     PWR_SR_SBF
#define PWR_FLAG_MR_RDY                 PWR_SR_MR_RDY
#define PWR_FLAG_LPRUN_RUN_SW           PWR_SR_LPRUN_RUN_SWF
#define PWR_FLAG_IWDGRST_WU             PWR_SR_IWDGRST_WUF
#define PWR_FLAG_PINRST_WU              PWR_SR_PINRST_WUF
#define PWR_FLAG_VCC_POR                PWR_SR_VCC_PORF
#define PWR_FLAG_PVDO                   PWR_SR_PVDO
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PWR_Exported_Macros  PWR Exported Macros
  * @{
  */
/** @brief  Check whether or not a specific PWR flag is set.
  * @param  __FLAG__: specifies the flag to check.
  *           This parameter can be one of the following values:
  *            @arg @ref PWR_FLAG_WU0 Wake Up Flag 0. Indicates that a wakeup event
  *                  was received from the WKUP pin 0.
  *            @arg @ref PWR_FLAG_WU1 Wake Up Flag 1. Indicates that a wakeup event
  *                  was received from the WKUP pin 1.
  *            @arg @ref PWR_FLAG_WU2 Wake Up Flag 2. Indicates that a wakeup event
  *                  was received from the WKUP pin 2.
  *            @arg @ref PWR_FLAG_WU3 Wake Up Flag 3. Indicates that a wakeup event
  *                  was received from the WKUP pin 3.
  *            @arg @ref PWR_FLAG_WU4 Wake Up Flag 4. Indicates that a wakeup event
  *                  was received from the WKUP pin 4.
  *            @arg @ref PWR_FLAG_WU5 Wake Up Flag 5. Indicates that a wakeup event
  *                  was received from the WKUP pin 5.
  *            @arg @ref PWR_FLAG_WU6 Wake Up Flag 6. Indicates that a wakeup event
  *                  was received from the WKUP pin 6.
  *            @arg @ref PWR_FLAG_WU7 Wake Up Flag 7. Indicates that a wakeup event
  *                  was received from the WKUP pin 7.
  *            @arg @ref PWR_FLAG_SB STANDBY Flag. Indicates that the system
  *                  entered STANDBY mode.
  *            @arg @ref PWR_FLAG_MR_RDY MR ready flag. Indicates whether or not the
  *                 MR is ready.
  *            @arg @ref PWR_FLAG_LPRUN_RUN_SW The flag for switching between LPRUN and RUN.
  *                 Indicates that the system has switched from LPRUN to RUN mode or is 
  *                 currently switching from RUN to LPRUN mode.
  *            @arg @ref PWR_FLAG_IWDGRST_WU IWDG reset wakes up STANDBY mode flag.
  *                 Indicates that the system was waked up from STANDBY mode by IWDG reset.
  *            @arg @ref PWR_FLAG_PINRST_WU PIN reset wakes up STANDBY mode flag.
  *                 Indicates that the system was waked up from STANDBY mode by PIN reset.
  *            @arg @ref PWR_FLAG_VCC_POR Power-ON reset wakes up STANDBY mode flag.
  *                 Indicates that the system was waked up from STANDBY mode by Power-ON reset.
  *            @arg @ref PWR_FLAG_PVDO Power Voltage Detector Output. Indicates whether VCC voltage is
  *                  below or above the selected PVD threshold.
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_PWR_GET_FLAG(__FLAG__) ((PWR->SR & (__FLAG__)) == (__FLAG__))

/** @brief  Clear the PWR's pending flags.
  * @param  __FLAG__: specifies the flag to clear.
  *          This parameter can be one of the following values:
  *            @arg @ref PWR_FLAG_WU0 Wake Up Flag 0. Indicates that a wakeup event
  *                  was received from the WKUP pin 0.
  *            @arg @ref PWR_FLAG_WU1 Wake Up Flag 1. Indicates that a wakeup event
  *                  was received from the WKUP pin 1.
  *            @arg @ref PWR_FLAG_WU2 Wake Up Flag 2. Indicates that a wakeup event
  *                  was received from the WKUP pin 2.
  *            @arg @ref PWR_FLAG_WU3 Wake Up Flag 3. Indicates that a wakeup event
  *                  was received from the WKUP pin 3.
  *            @arg @ref PWR_FLAG_WU4 Wake Up Flag 4. Indicates that a wakeup event
  *                  was received from the WKUP pin 4.
  *            @arg @ref PWR_FLAG_WU5 Wake Up Flag 5. Indicates that a wakeup event
  *                  was received from the WKUP pin 5.
  *            @arg @ref PWR_FLAG_WU6 Wake Up Flag 6. Indicates that a wakeup event
  *                  was received from the WKUP pin 6.
  *            @arg @ref PWR_FLAG_WU7 Wake Up Flag 7. Indicates that a wakeup event
  *                  was received from the WKUP pin 7.
  *            @arg @ref PWR_FLAG_WU Encompasses all five Wake Up Flags.
  *            @arg @ref PWR_FLAG_SB STANDBY Flag. Indicates that the system
  *                  entered STANDBY mode.
  *            @arg @ref PWR_FLAG_IWDGRST_WU IWDG reset wakes up STANDBY mode flag.
  *                 Indicates that the system was waked up from STANDBY mode by IWDG reset.
  *            @arg @ref PWR_FLAG_PINRST_WU PIN reset wakes up STANDBY mode flag.
  *                 Indicates that the system was waked up from STANDBY mode by PIN reset.
  *            @arg @ref PWR_FLAG_VCC_POR Power-ON reset wakes up STANDBY mode flag.
  *                 Indicates that the system was waked up from STANDBY mode by Power-ON reset.
  */
#define __HAL_PWR_CLEAR_FLAG(__FLAG__) SET_BIT(PWR->SCR, (__FLAG__))

/**
  * @brief Enable interrupt on PVD Exti Line 16.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_IT()      SET_BIT(EXTI->IMR, PWR_EXTI_LINE_PVD)

/**
  * @brief Disable interrupt on PVD Exti Line 16. 
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_IT()     CLEAR_BIT(EXTI->IMR, PWR_EXTI_LINE_PVD)

/**
  * @brief Enable event on PVD Exti Line 16.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR, PWR_EXTI_LINE_PVD)

/**
  * @brief Disable event on PVD Exti Line 16.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR, PWR_EXTI_LINE_PVD)


/**
  * @brief  PVD EXTI line configuration: set falling edge trigger.  
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE()  SET_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)


/**
  * @brief Disable the PVD Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)


/**
  * @brief  PVD EXTI line configuration: set rising edge trigger.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)

/**
  * @brief Disable the PVD Extended Interrupt Rising Trigger.
  * This parameter can be:
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)

/**
  * @brief  PVD EXTI line configuration: set rising & falling edge trigger.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_FALLING_EDGE()   __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();

/**
  * @brief Disable the PVD Extended Interrupt Rising & Falling Trigger.
  * This parameter can be:
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_FALLING_EDGE()  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();



/**
  * @brief Check whether the specified PVD EXTI interrupt flag is set or not.
  * @retval EXTI PVD Line Status.
  */
#define __HAL_PWR_PVD_EXTI_GET_FLAG()       (EXTI->PR & (PWR_EXTI_LINE_PVD))

/**
  * @brief Clear the PVD EXTI flag.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_CLEAR_FLAG()     (EXTI->PR = (PWR_EXTI_LINE_PVD))

/**
  * @brief Generate a Software interrupt on selected EXTI line.
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_GENERATE_SWIT()  SET_BIT(EXTI->SWIER, PWR_EXTI_LINE_PVD)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup PWR_Private_Macros PWR Private Macros
  * @{
  */
#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLEVEL_0) || ((LEVEL) == PWR_PVDLEVEL_1)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_2) || ((LEVEL) == PWR_PVDLEVEL_3)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_4) || ((LEVEL) == PWR_PVDLEVEL_5)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_6) || ((LEVEL) == PWR_PVDLEVEL_7))


#define IS_PWR_PVD_MODE(MODE) (((MODE) == PWR_PVD_MODE_IT_RISING)|| ((MODE) == PWR_PVD_MODE_IT_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_IT_RISING_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING) || \
                              ((MODE) == PWR_PVD_MODE_EVENT_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_NORMAL)) 
                              
#define IS_PWR_PVD_FILTER(FILTER) (((FILTER) == PWR_PVD_FILTER_NONE) || ((FILTER) == PWR_PVD_FILTER_1CLOCK)|| \
                                 ((FILTER) == PWR_PVD_FILTER_2CLOCK) || ((FILTER) == PWR_PVD_FILTER_4CLOCK)|| \
                                 ((FILTER) == PWR_PVD_FILTER_16CLOCK) || ((FILTER) == PWR_PVD_FILTER_64CLOCK)|| \
                                 ((FILTER) == PWR_PVD_FILTER_128CLOCK) || ((FILTER) == PWR_PVD_FILTER_1024CLOCK))

#define IS_PWR_PVD_OUTPUT_SELECT(OUTPUT) (((OUTPUT) == PWR_PVD_OUT_NOT_SYN_FILTER) || \
                                          ((OUTPUT) == PWR_PVD_OUT_SYN_FILTER))

#define IS_PWR_WAKEUP_PIN(PIN) (((PIN) == PWR_WAKEUP_PIN0_HIGH) || ((PIN) == PWR_WAKEUP_PIN0_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN1_HIGH) || ((PIN) == PWR_WAKEUP_PIN1_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN2_HIGH) || ((PIN) == PWR_WAKEUP_PIN2_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN3_HIGH) || ((PIN) == PWR_WAKEUP_PIN3_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN4_HIGH) || ((PIN) == PWR_WAKEUP_PIN4_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN5_HIGH) || ((PIN) == PWR_WAKEUP_PIN5_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN6_HIGH) || ((PIN) == PWR_WAKEUP_PIN6_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN7_HIGH) || ((PIN) == PWR_WAKEUP_PIN7_LOW))

#define IS_PWR_REGULATOR(REGULATOR) (((REGULATOR) == PWR_MAINREGULATOR_ON) || \
                                     ((REGULATOR) == PWR_LOWPOWERREGULATOR_ON))

#define IS_PWR_SLEEP_ENTRY(ENTRY) (((ENTRY) == PWR_SLEEPENTRY_WFI) || ((ENTRY) == PWR_SLEEPENTRY_WFE))

#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPENTRY_WFI) || ((ENTRY) == PWR_STOPENTRY_WFE))

/**
  * @}
  */

/* Include PWR HAL Extension module */
#include "py32c882_hal_pwr_ex.h"


/* Exported functions --------------------------------------------------------*/

/** @addtogroup PWR_Exported_Functions PWR Exported Functions
  * @{
  */
  
/** @addtogroup PWR_Exported_Functions_Group1 Initialization and de-initialization functions 
  * @{
  */

/* Initialization and de-initialization functions *******************************/
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);

/**
  * @}
  */

/** @addtogroup PWR_Exported_Functions_Group2 Peripheral Control functions 
  * @{
  */

/* Peripheral Control functions  ************************************************/
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);

/* WakeUp pins configuration functions ****************************************/
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);

/* Low Power modes configuration functions ************************************/
void HAL_PWR_EnterSLEEPMode(uint8_t SLEEPEntry);
void HAL_PWR_EnterLowPowerSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTANDBYMode(uint32_t Regulator);

void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);

void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);
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


#endif /* __PY32C882_HAL_PWR_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
