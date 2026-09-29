/**
  ******************************************************************************
  * @file    py32c882_hal_smartcard_ex.h
  * @author  MCU Application Team
  * @brief   Header file of SMARTCARD HAL Extended module.
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
#ifndef __PY32C882_HAL_SMARTCARD_EX_H
#define __PY32C882_HAL_SMARTCARD_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c882_hal_def.h"

/** @addtogroup PY32C882_HAL_Driver
  * @{
  */

/** @addtogroup SMARTCARDEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @addtogroup SMARTCARDEx_Exported_Constants  SMARTCARD Extended Exported Constants
  * @{
  */

/** @defgroup SMARTCARDEx_Transmission_Completion_Indication SMARTCARD Transmission Completion Indication
  * @{
  */
#define SMARTCARD_TC         SMARTCARD_IT_TC    /*!< SMARTCARD transmission complete (flag raised when guard time has elapsed) */
/**
  * @}
  */

/** @defgroup SMARTCARDEx_Advanced_Features_Initialization_Type SMARTCARD advanced feature initialization type
  * @{
  */
#define SMARTCARD_ADVFEATURE_NO_INIT                 0x00000000U    /*!< No advanced feature initialization                  */
#define SMARTCARD_ADVFEATURE_DATAINVERT_INIT         0x00000001U    /*!< Binary data inversion                               */
#define SMARTCARD_ADVFEATURE_SWAP_INIT               0x00000002U    /*!< TX/RX pins swap                                     */
#define SMARTCARD_ADVFEATURE_RXOVERRUNDISABLE_INIT   0x00000004U    /*!< RX overrun disable                                  */
#define SMARTCARD_ADVFEATURE_DMADISABLEONERROR_INIT  0x00000008U    /*!< DMA disable on Reception Error                      */
#define SMARTCARD_ADVFEATURE_MSBFIRST_INIT           0x00000010U    /*!< Most significant bit sent/received first            */
#define SMARTCARD_ADVFEATURE_TXCOMPLETION            0x00000020U    /*!< TX completion indication before of after guard time */
/**
  * @}
  */

/** @defgroup SMARTCARDEx_Flags SMARTCARD Flags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the ISR register
  * @{
  */
#if defined(USART_SR_TXLSEF)
#define SMARTCARD_FLAG_TXLSEF         USART_SR_TXLSEF        /*!< SMARTCARD TX shift register Empty flag     */
#endif
#define SMARTCARD_FLAG_WAITRPT        USART_SR_WAITRPT       /*!< SMARTCARD Waiting retransmit data flag     */
#define SMARTCARD_FLAG_TXBUSY         USART_SR_TXBUSY        /*!< SMARTCARD TX busy flag                     */
#define SMARTCARD_FLAG_RXBUSY         USART_SR_RXBUSY        /*!< SMARTCARD RX busy flag                     */
#define SMARTCARD_FLAG_TXPE           USART_SR_TXPE          /*!< SMARTCARD TX data parity error flag        */
#define SMARTCARD_FLAG_EOBF           USART_SR_EOBF          /*!< SMARTCARD end of block flag                */
#define SMARTCARD_FLAG_RTOF           USART_SR_RTOF          /*!< SMARTCARD receiver timeout flag            */
#define SMARTCARD_FLAG_TXE            USART_SR_TXE           /*!< SMARTCARD transmit data register empty     */
#define SMARTCARD_FLAG_TC             USART_SR_TC            /*!< SMARTCARD transmission complete            */
#define SMARTCARD_FLAG_RXNE           USART_SR_RXNE          /*!< SMARTCARD read data register not empty     */
#define SMARTCARD_FLAG_IDLE           USART_SR_IDLE          /*!< SMARTCARD idle line detection              */
#define SMARTCARD_FLAG_ORE            USART_SR_ORE           /*!< SMARTCARD overrun error                    */
#define SMARTCARD_FLAG_NE             USART_SR_NE            /*!< SMARTCARD noise error                      */
#define SMARTCARD_FLAG_FE             USART_SR_FE            /*!< SMARTCARD frame error                      */
#define SMARTCARD_FLAG_PE             USART_SR_PE            /*!< SMARTCARD parity error                     */
/**
  * @}
  */

/** @defgroup SMARTCARDEx_Interrupt_definition SMARTCARD Interrupts Definition
  *        Elements values convention: 000ZZZZZ0XXYYYYYb
  *           - YYYYY  : Interrupt source position in the XX register (5 bits)
  *           - XX  : Interrupt source register (2 bits)
  *                 - 01: CR1 register
  *                 - 10: CR2 register
  *                 - 11: CR3 register
  *           - ZZZZZ  : Flag position in the ISR register(5 bits)
  * @{
  */
#define SMARTCARD_IT_PE                     0x0028U           /*!< SMARTCARD parity error interruption                 */
#define SMARTCARD_IT_TXE                    0x0727U           /*!< SMARTCARD transmit data register empty interruption */
#define SMARTCARD_IT_TC                     0x0626U           /*!< SMARTCARD transmission complete interruption        */
#define SMARTCARD_IT_RXNE                   0x0525U           /*!< SMARTCARD read data register not empty interruption */
#define SMARTCARD_IT_IDLE                   0x0424U           /*!< SMARTCARD idle line detection interruption          */

#define SMARTCARD_IT_ERR                    0x0060U           /*!< SMARTCARD error interruption         */
#define SMARTCARD_IT_ORE                    0x0300U           /*!< SMARTCARD overrun error interruption */
#define SMARTCARD_IT_NE                     0x0200U           /*!< SMARTCARD noise error interruption   */
#define SMARTCARD_IT_FE                     0x0100U           /*!< SMARTCARD frame error interruption   */

#define SMARTCARD_IT_EOB                    0x127EU           /*!< SMARTCARD end of block interruption     */
#define SMARTCARD_IT_RTO                    0x137DU           /*!< SMARTCARD receiver timeout interruption */
#define SMARTCARD_IT_TXLSE                  0x127FU           /*!< SMARTCARD TXLSE interruption            */

/**
  * @}
  */

/**
  * @}
  */
/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup SMARTCARDEx_Private_Macros SMARTCARD Extended Private Macros
  * @{
  */

/** @brief  Set the Transmission Completion flag
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @note  If TCBGT (Transmission Complete Before Guard Time) flag is not available or if
  *        AdvancedInit.TxCompletionIndication is not already filled, the latter is forced
  *        to SMARTCARD_TC (transmission completion indication when guard time has elapsed).
  * @retval None
  */
#define SMARTCARD_TRANSMISSION_COMPLETION_SETTING(__HANDLE__)                                                \
  do {                                                                                                       \
    if (HAL_IS_BIT_CLR((__HANDLE__)->AdvancedInit.AdvFeatureInit, SMARTCARD_ADVFEATURE_TXCOMPLETION))        \
    {                                                                                                        \
      (__HANDLE__)->AdvancedInit.TxCompletionIndication = SMARTCARD_TC;                                      \
    }                                                                                                        \
    else                                                                                                     \
    {                                                                                                        \
      assert_param(IS_SMARTCARD_TRANSMISSION_COMPLETION((__HANDLE__)->AdvancedInit.TxCompletionIndication)); \
    }                                                                                                        \
  } while(0U)

/** @brief Ensure that SMARTCARD frame transmission completion used flag is valid.
  * @param __TXCOMPLETE__ SMARTCARD frame transmission completion used flag.
  * @retval SET (__TXCOMPLETE__ is valid) or RESET (__TXCOMPLETE__ is invalid)
  */
#define IS_SMARTCARD_TRANSMISSION_COMPLETION(__TXCOMPLETE__) ((__TXCOMPLETE__) == SMARTCARD_TC)

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SMARTCARDEx_Exported_Functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
/* IO operation methods *******************************************************/

/** @addtogroup SMARTCARDEx_Exported_Functions_Group1
  * @{
  */

/* Peripheral Control functions ***********************************************/
void              HAL_SMARTCARDEx_BlockLength_Config(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t BlockLength);
void              HAL_SMARTCARDEx_TimeOut_Config(SMARTCARD_HandleTypeDef *hsmartcard, uint32_t TimeOutValue);
HAL_StatusTypeDef HAL_SMARTCARDEx_EnableReceiverTimeOut(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARDEx_DisableReceiverTimeOut(SMARTCARD_HandleTypeDef *hsmartcard);

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

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

#endif /* PY32C882_HAL_SMARTCARD_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
