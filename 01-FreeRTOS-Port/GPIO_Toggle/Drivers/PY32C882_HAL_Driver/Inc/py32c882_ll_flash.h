/**
  ******************************************************************************
  * @file    py32c882_ll_flash.h
  * @author  MCU Application Team
  * @brief   Header file of FLASH LL module.
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
#ifndef PY32C882_LL_FLASH_H
#define PY32C882_LL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32c8xx.h"



/** @addtogroup PY32C882_LL_Driver
  * @{
  */

#if defined (FLASH)

/** @defgroup FLASH_LL FLASH
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup FLASH_LL_Exported_Constants FLASH Exported Constants
  * @{
  */
 /** @defgroup FLASH_LL_EC_USERSTYPE FLASH Users Type
  * @{
  */
#define LL_FLASH_OPTR_ECC_EN         FLASH_OPTR_ECC_EN
#define LL_FLASH_OPTR_BOOT_LOCK      FLASH_OPTR_BOOT_LOCK
#define LL_FLASH_OPTR_BFB            FLASH_OPTR_BFB
#define LL_FLASH_OPTR_SWD_MODE       FLASH_OPTR_SWD_MODE
#define LL_FLASH_OPTR_SRAM_PE        FLASH_OPTR_SRAM_PE
#define LL_FLASH_OPTR_NBOOT1         FLASH_OPTR_NBOOT1
#define LL_FLASH_OPTR_NRST_MODE      FLASH_OPTR_NRST_MODE
#define LL_FLASH_OPTR_WWDG_SW        FLASH_OPTR_WWDG_SW
#define LL_FLASH_OPTR_IWDG_SW        FLASH_OPTR_IWDG_SW
#define LL_FLASH_OPTR_IWDG_STOP      FLASH_OPTR_IWDG_STOP
#define LL_FLASH_OPTR_IWDG_STDBY     FLASH_OPTR_IWDG_STDBY
#define LL_FLASH_OPTR_NRST_STOP      FLASH_OPTR_NRST_STOP
#define LL_FLASH_OPTR_NRST_STDBY     FLASH_OPTR_NRST_STDBY
#define LL_FLASH_OPTR_RDP            FLASH_OPTR_RDP
#define LL_FLASH_OPTR_BOR_LEVEL      FLASH_OPTR_BOR_LEV  
#define LL_FLASH_OPTR_BOR_ENABLE     FLASH_OPTR_BOR_EN  
/**
  * @}
  */
/** @defgroup FLASH_LL_EC_ECCE ECC Enable
  * @{
  */
#define LL_FLASH_ECC_DISABLE          (0x00000000U)                                         /*!< ECC Disable */
#define LL_FLASH_ECC_ENABLE           (FLASH_OPTR_ECC_EN)                                   /*!< ECC Enable  */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_BOOT_LOCK BOOT Lock
  * @{
  */
#define LL_FLASH_BOOT_FROM_OB                     0x00000000U             /*!< BOOT from IO or OB */
#define LL_FLASH_BOOT_FROM_MAINFLASH              (FLASH_OPTR_BOOT_LOCK)  /*!< BOOT from MainFlash */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_BFB BFB Mode
  * @{
  */
#define LL_FLASH_BFB_START_BANK0          (0x00000000U)                                         /*!< Hardware WWDG selected */
#define LL_FLASH_BFB_START_BANK1          (FLASH_OPTR_BFB)                                      /*!< Software WWDG selected */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_SWDMODE SWD Mode
  * @{
  */
#define LL_FLASH_SWDIO_PA4_SWCLK_PA5     (0x00000000U)                                         /*!< SWDIO: PA4 SWCLK: PA5 */
#define LL_FLASH_SWDIO_PB6_SWCLK_PB5     (FLASH_OPTR_SWD_MODE_0)                               /*!< SWDIO: PB6 SWCLK: PB5 */
#define LL_FLASH_SWDIO_PB6_SWCLK_PA5     (FLASH_OPTR_SWD_MODE_1)                               /*!< SWDIO: PB6 SWCLK: PA5 */
#define LL_FLASH_SWDIO_PA4_SWCLK_PB5     (FLASH_OPTR_SWD_MODE_0 | FLASH_OPTR_SWD_MODE_1)       /*!< SWDIO: PA4 SWCLK: PB5 */

/**
  * @}
  */

/** @defgroup FLASH_LL_EC_SRAMPE Sram Parity Enable
  * @{
  */
#define LL_FLASH_SRAM_PARITY_DISABLE          (0x00000000U)            /*!< Disable SRAM1 and CCM SRAM parity check permission bit */
#define LL_FLASH_SRAM_PARITY_ENABLE           (FLASH_OPTR_SRAM_PE)     /*!< Enable SRAM1 and CCM SRAM parity check permission bit */
/**
  * @}
  */


/** @defgroup FLASH_LL_EC_BORLevel Bor Level
  * @{
  */
#define LL_FLASH_BOR_LEV0          (0x00000000U)                                                          /*!< Bor Level 0 */
#define LL_FLASH_BOR_LEV1          (FLASH_OPTR_BOR_LEV_0)                                                 /*!< Bor Level 1 */
#define LL_FLASH_BOR_LEV2          (FLASH_OPTR_BOR_LEV_1)                                                 /*!< Bor Level 2 */
#define LL_FLASH_BOR_LEV3          (FLASH_OPTR_BOR_LEV_1 | FLASH_OPTR_BOR_LEV_0)                          /*!< Bor Level 3 */
#define LL_FLASH_BOR_LEV4          (FLASH_OPTR_BOR_LEV_2)                                                 /*!< Bor Level 4 */
#define LL_FLASH_BOR_LEV5          (FLASH_OPTR_BOR_LEV_2 | FLASH_OPTR_BOR_LEV_0)                          /*!< Bor Level 5 */
#define LL_FLASH_BOR_LEV6          (FLASH_OPTR_BOR_LEV_2 | FLASH_OPTR_BOR_LEV_1)                          /*!< Bor Level 6 */
#define LL_FLASH_BOR_LEV7          (FLASH_OPTR_BOR_LEV_2 | FLASH_OPTR_BOR_LEV_1 | FLASH_OPTR_BOR_LEV_0)   /*!< Bor Level 7 */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_BOREnable Bor Enable
  * @{
  */
#define LL_FLASH_BOR_DISABLE          (0x00000000U)                                        /*!< Bor Disable */
#define LL_FLASH_BOR_ENABLE           (FLASH_OPTR_BOR_EN)                                  /*!< Bor Enable */
/**
  * @}
  */

/** @defgroup FLASH_LL_NBOOT1 FLASH Option Bytes User nBOOT1 Type
  * @{
  */
#define LL_FLASH_NBOOT1_SRAM                   0x00000000U                  /*!< Embedded SRAM1 is selected as boot space (if BOOT0=1) */
#define LL_FLASH_NBOOT1_SYSTEM                 (FLASH_OPTR_NBOOT1)          /*!< System memory is selected as boot space (if BOOT0=1) */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_NRSTMODE NRST Mode
  * @{
  */
#define LL_FLASH_NRST_MODE_RESET          (0x00000000U)                     /*!< NRST Mode Reset */
#define LL_FLASH_NRST_MODE_GPIO           (FLASH_OPTR_NRST_MODE)            /*!< NRST Mode Gpio */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_WWDGMODE WWDG Mode
  * @{
  */
#define LL_FLASH_WWDG_MODE_HW          (0x00000000U)                        /*!< Hardware WWDG selected */
#define LL_FLASH_WWDG_MODE_SW          (FLASH_OPTR_WWDG_SW)                 /*!< Software WWDG selected */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_IWDGMODE IWDG Mode
  * @{
  */
#define LL_FLASH_IWDG_MODE_HW          (0x00000000U)                        /*!< Hardware IWDG selected */
#define LL_FLASH_IWDG_MODE_SW          (FLASH_OPTR_IWDG_SW)                 /*!< Software IWDG selected */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_IWDG_STANDBY FLASH Option Bytes User IWDG Mode On Standby
  * @{
  */
#define LL_FLASH_IWDG_INSTANDBY_FREEZE            0x00000000U               /*!< Independent watchdog counter is frozen in Standby mode */
#define LL_FLASH_IWDG_INSTANDBY_ACTIVE            FLASH_OPTR_IWDG_STDBY     /*!< Independent watchdog counter is running in Standby mode */
/**
  * @}
  */
  
/** @defgroup FLASH_OB_USER_IWDG_STOP FLASH Option Bytes User IWDG Mode On Stop
  * @{
  */
#define LL_FLASH_IWDG_INSTOP_FREEZE             0x00000000U                 /*!< Independent watchdog counter is frozen in Stop mode */
#define LL_FLASH_IWDG_INSTOP_ACTIVE             FLASH_OPTR_IWDG_STOP        /*!< Independent watchdog counter is running in Stop mode */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_STOP_RST_MODE STOP RST Mode
  * @{
  */
#define LL_FLASH_STOP_RST              (0x00000000U)                        /*!< Reset generated when entering Stop mode */
#define LL_FLASH_STOP_NORST            (FLASH_OPTR_NRST_STOP)               /*!< No reset generated when entering Stop mode */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_STANDBY_RST_MODE STANDBY RST Mode
  * @{
  */
#define LL_FLASH_STANDBY_RST           (0x00000000U)                        /*!< Reset generated when entering Standby mode */
#define LL_FLASH_STANDBY_NORST         (FLASH_OPTR_NRST_STDBY)              /*!< No reset generated when entering Standby mode */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_RDP RDP Mode
  * @{
  */
#define LL_FLASH_RDP_LEVEL_0         ((uint8_t)0xAAU)
#define LL_FLASH_RDP_LEVEL_1         ((uint8_t)0x55U)
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_ECC_DETECT FLASH ECC DETECT
  * @{
  */          
#define LL_FLASH_ECC_DETECTIN_SYSTEMFLASH      ((uint32_t)FLASH_ECCR_SYSF_ECC)
#define LL_FLASH_ECC_DETECTIN_BANK0            ((uint32_t)0x00000000U)
#define LL_FLASH_ECC_DETECTIN_BANK1            ((uint32_t)FALSH_ECCR_BK_ECC)
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_WRP Write Protection
  * @{
  */
#define LL_FLASH_WRP_DISABLE                 ((uint32_t)0x00000000)   /* Write protection disable */
#define LL_FLASH_WRP_BANK0_SECTOR_0          ((uint32_t)0x00000001)   /* Write protection of Bank0 Sector0 */
#define LL_FLASH_WRP_BANK0_SECTOR_1          ((uint32_t)0x00000002)   /* Write protection of Bank0 Sector1 */
#define LL_FLASH_WRP_BANK0_SECTOR_2          ((uint32_t)0x00000004)   /* Write protection of Bank0 Sector2 */
#define LL_FLASH_WRP_BANK0_SECTOR_3          ((uint32_t)0x00000008)   /* Write protection of Bank0 Sector3 */
#define LL_FLASH_WRP_BANK0_SECTOR_4          ((uint32_t)0x00000010)   /* Write protection of Bank0 Sector4 */
#define LL_FLASH_WRP_BANK0_SECTOR_5          ((uint32_t)0x00000020)   /* Write protection of Bank0 Sector5 */
#define LL_FLASH_WRP_BANK0_SECTOR_6          ((uint32_t)0x00000040)   /* Write protection of Bank0 Sector6 */
#define LL_FLASH_WRP_BANK0_SECTOR_7          ((uint32_t)0x00000080)   /* Write protection of Bank0 Sector7 */
#define LL_FLASH_WRP_BANK0_SECTOR_8          ((uint32_t)0x00000100)   /* Write protection of Bank0 Sector8 */
#define LL_FLASH_WRP_BANK0_SECTOR_9          ((uint32_t)0x00000200)   /* Write protection of Bank0 Sector9 */
#define LL_FLASH_WRP_BANK0_SECTOR_10         ((uint32_t)0x00000400)   /* Write protection of Bank0 Sector10 */
#define LL_FLASH_WRP_BANK0_SECTOR_11         ((uint32_t)0x00000800)   /* Write protection of Bank0 Sector11 */
#define LL_FLASH_WRP_BANK0_SECTOR_12         ((uint32_t)0x00001000)   /* Write protection of Bank0 Sector12 */
#define LL_FLASH_WRP_BANK0_SECTOR_13         ((uint32_t)0x00002000)   /* Write protection of Bank0 Sector13 */
#define LL_FLASH_WRP_BANK0_SECTOR_14         ((uint32_t)0x00004000)   /* Write protection of Bank0 Sector14 */
#define LL_FLASH_WRP_BANK0_SECTOR_15         ((uint32_t)0x00008000)   /* Write protection of Bank0 Sector15 */

#define LL_FLASH_WRP_BANK1_SECTOR_0          ((uint32_t)0x00010000)   /* Write protection of Bank1 Sector0 */
#define LL_FLASH_WRP_BANK1_SECTOR_1          ((uint32_t)0x00020000)   /* Write protection of Bank1 Sector1 */
#define LL_FLASH_WRP_BANK1_SECTOR_2          ((uint32_t)0x00040000)   /* Write protection of Bank1 Sector2 */
#define LL_FLASH_WRP_BANK1_SECTOR_3          ((uint32_t)0x00080000)   /* Write protection of Bank1 Sector3 */
#define LL_FLASH_WRP_BANK1_SECTOR_4          ((uint32_t)0x00100000)   /* Write protection of Bank1 Sector4 */
#define LL_FLASH_WRP_BANK1_SECTOR_5          ((uint32_t)0x00200000)   /* Write protection of Bank1 Sector5 */
#define LL_FLASH_WRP_BANK1_SECTOR_6          ((uint32_t)0x00400000)   /* Write protection of Bank1 Sector6 */
#define LL_FLASH_WRP_BANK1_SECTOR_7          ((uint32_t)0x00800000)   /* Write protection of Bank1 Sector7 */
#define LL_FLASH_WRP_BANK1_SECTOR_8          ((uint32_t)0x01000000)   /* Write protection of Bank1 Sector8 */
#define LL_FLASH_WRP_BANK1_SECTOR_9          ((uint32_t)0x02000000)   /* Write protection of Bank1 Sector9 */
#define LL_FLASH_WRP_BANK1_SECTOR_10         ((uint32_t)0x04000000)   /* Write protection of Bank1 Sector10 */
#define LL_FLASH_WRP_BANK1_SECTOR_11         ((uint32_t)0x08000000)   /* Write protection of Bank1 Sector11 */
#define LL_FLASH_WRP_BANK1_SECTOR_12         ((uint32_t)0x10000000)   /* Write protection of Bank1 Sector12 */
#define LL_FLASH_WRP_BANK1_SECTOR_13         ((uint32_t)0x20000000)   /* Write protection of Bank1 Sector13 */
#define LL_FLASH_WRP_BANK1_SECTOR_14         ((uint32_t)0x40000000)   /* Write protection of Bank1 Sector14 */
#define LL_FLASH_WRP_BANK1_SECTOR_15         ((uint32_t)0x80000000)   /* Write protection of Bank1 Sector15 */

#define LL_FLASH_WRP_BANK0_Pages0to31        ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_0)   /* Write protection from bank0 page0   to page31 */
#define LL_FLASH_WRP_BANK0_Pages32to63       ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_1)   /* Write protection from bank0 page32  to page63 */
#define LL_FLASH_WRP_BANK0_Pages64to95       ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_2)   /* Write protection from bank0 page64  to page95 */
#define LL_FLASH_WRP_BANK0_Pages96to127      ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_3)   /* Write protection from bank0 page96  to page127 */
#define LL_FLASH_WRP_BANK0_Pages128to159     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_4)   /* Write protection from bank0 page128 to page159 */
#define LL_FLASH_WRP_BANK0_Pages160to191     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_5)   /* Write protection from bank0 page160 to page191 */
#define LL_FLASH_WRP_BANK0_Pages192to223     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_6)   /* Write protection from bank0 page192 to page223 */
#define LL_FLASH_WRP_BANK0_Pages224to255     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_7)   /* Write protection from bank0 page224 to page255 */
#define LL_FLASH_WRP_BANK0_Pages256to287     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_8)   /* Write protection from bank0 page256 to page287 */
#define LL_FLASH_WRP_BANK0_Pages288to319     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_9)   /* Write protection from bank0 page288 to page319 */
#define LL_FLASH_WRP_BANK0_Pages320to351     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_10)  /* Write protection from bank0 page320 to page351 */
#define LL_FLASH_WRP_BANK0_Pages352to383     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_11)  /* Write protection from bank0 page352 to page383 */
#define LL_FLASH_WRP_BANK0_Pages384to415     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_12)  /* Write protection from bank0 page384 to page415 */
#define LL_FLASH_WRP_BANK0_Pages416to447     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_13)  /* Write protection from bank0 page416 to page447 */
#define LL_FLASH_WRP_BANK0_Pages448to479     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_14)  /* Write protection from bank0 page448 to page479 */
#define LL_FLASH_WRP_BANK0_Pages480to511     ((uint32_t)LL_FLASH_WRP_BANK0_SECTOR_15)  /* Write protection from bank0 page480 to page511 */

#define LL_FLASH_WRP_BANK1_Pages0to31        ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_0)   /* Write protection from bank1 page0   to page31 */
#define LL_FLASH_WRP_BANK1_Pages32to63       ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_1)   /* Write protection from bank1 page32  to page63 */
#define LL_FLASH_WRP_BANK1_Pages64to95       ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_2)   /* Write protection from bank1 page64  to page95 */
#define LL_FLASH_WRP_BANK1_Pages96to127      ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_3)   /* Write protection from bank1 page96  to page127 */
#define LL_FLASH_WRP_BANK1_Pages128to159     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_4)   /* Write protection from bank1 page128 to page159 */
#define LL_FLASH_WRP_BANK1_Pages160to191     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_5)   /* Write protection from bank1 page160 to page191 */
#define LL_FLASH_WRP_BANK1_Pages192to223     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_6)   /* Write protection from bank1 page192 to page223 */
#define LL_FLASH_WRP_BANK1_Pages224to255     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_7)   /* Write protection from bank1 page224 to page255 */
#define LL_FLASH_WRP_BANK1_Pages256to287     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_8)   /* Write protection from bank1 page256 to page287 */
#define LL_FLASH_WRP_BANK1_Pages288to319     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_9)   /* Write protection from bank1 page288 to page319 */
#define LL_FLASH_WRP_BANK1_Pages320to351     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_10)  /* Write protection from bank1 page320 to page351 */
#define LL_FLASH_WRP_BANK1_Pages352to383     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_11)  /* Write protection from bank1 page352 to page383 */
#define LL_FLASH_WRP_BANK1_Pages384to415     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_12)  /* Write protection from bank1 page384 to page415 */
#define LL_FLASH_WRP_BANK1_Pages416to447     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_13)  /* Write protection from bank1 page416 to page447 */
#define LL_FLASH_WRP_BANK1_Pages448to479     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_14)  /* Write protection from bank1 page448 to page479 */
#define LL_FLASH_WRP_BANK1_Pages480to511     ((uint32_t)LL_FLASH_WRP_BANK1_SECTOR_15)  /* Write protection from bank1 page480 to page511 */


#define LL_FLASH_WRP_AllPages          ((uint32_t)0xFFFFFFFFU)      /*!< Write protection of all Sectors */
/**
  * @}
  */

/** @defgroup FLASH_EnterLpmodeDelay FLASH Enter LpMode Delay Time 
  * @{
  */
#define LL_FLASH_ENTERLPMODEDELAY_1MSISYSCLOCK         (FLASH_LPCR_LPRUN_ENTERT_0)
#define LL_FLASH_ENTERLPMODEDELAY_2MSISYSCLOCK         (FLASH_LPCR_LPRUN_ENTERT_1)
#define LL_FLASH_ENTERLPMODEDELAY_3MSISYSCLOCK         (FLASH_LPCR_LPRUN_ENTERT_1 | FLASH_LPCR_LPRUN_ENTERT_0)
#define LL_FLASH_ENTERLPMODEDELAY_4MSISYSCLOCK         (FLASH_LPCR_LPRUN_ENTERT_2)
#define LL_FLASH_ENTERLPMODEDELAY_5MSISYSCLOCK         (FLASH_LPCR_LPRUN_ENTERT_2 | FLASH_LPCR_LPRUN_ENTERT_0)
#define LL_FLASH_ENTERLPMODEDELAY_6MSISYSCLOCK         (FLASH_LPCR_LPRUN_ENTERT_2 | FLASH_LPCR_LPRUN_ENTERT_1)
#define LL_FLASH_ENTERLPMODEDELAY_7MSISYSCLOCK         (FLASH_LPCR_LPRUN_ENTERT_2 | FLASH_LPCR_LPRUN_ENTERT_1 | FLASH_LPCR_LPRUN_ENTERT_0) 
/**
  * @}
  */

/** @defgroup FLASH_ExitLpmodeDelay FLASH Exit LpMode Delay Time 
  * @{
  */
#define LL_FLASH_EXITLPMODEDELAY_1MSISYSCLOCK         (FLASH_LPCR_LPRUN_EXITT_0)
#define LL_FLASH_EXITLPMODEDELAY_2MSISYSCLOCK         (FLASH_LPCR_LPRUN_EXITT_1)
#define LL_FLASH_EXITLPMODEDELAY_3MSISYSCLOCK         (FLASH_LPCR_LPRUN_EXITT_1 | FLASH_LPCR_LPRUN_EXITT_0)
#define LL_FLASH_EXITLPMODEDELAY_4MSISYSCLOCK         (FLASH_LPCR_LPRUN_EXITT_2)
#define LL_FLASH_EXITLPMODEDELAY_5MSISYSCLOCK         (FLASH_LPCR_LPRUN_EXITT_2 | FLASH_LPCR_LPRUN_EXITT_0)
#define LL_FLASH_EXITLPMODEDELAY_6MSISYSCLOCK         (FLASH_LPCR_LPRUN_EXITT_2 | FLASH_LPCR_LPRUN_EXITT_1)
#define LL_FLASH_EXITLPMODEDELAY_7MSISYSCLOCK         (FLASH_LPCR_LPRUN_EXITT_2 | FLASH_LPCR_LPRUN_EXITT_1 | FLASH_LPCR_LPRUN_EXITT_0) 
/**
  * @}
  */


/** @defgroup FLASH_LL_EC_KEY Key Value
  * @{
  */
#define LL_FLASH_KEY1                  (FLASH_KEY1)
#define LL_FLASH_KEY2                  (FLASH_KEY2)
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_OPTKEY Optkey Value
  * @{
  */
#define LL_FLASH_OPTKEY1               (FLASH_OPTKEY1)
#define LL_FLASH_OPTKEY2               (FLASH_OPTKEY2)
/**
  * @}
  */
/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/** @defgroup FLASH_LL_Exported_Macros FLASH Exported Macros
  * @{
  */

/** @defgroup FLASH_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_FLASH_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_FLASH_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup FLASH_LL_Exported_Functions FLASH Exported Functions
  * @{
  */


/**
  * @brief  Enable Data Cache
  * @rmtoll ACR          DCEN               LL_FLASH_EnableDataCache
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableDataCache(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->ACR, FLASH_ACR_DCEN);
}

/**
  * @brief  Enable Instruction Cache
  * @rmtoll ACR          ICEN               LL_FLASH_EnableInstructionCache
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableInstructionCache(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->ACR, FLASH_ACR_ICEN);
}

/**
  * @brief  Enable Prefetch Buffer
  * @rmtoll ACR          PRFTEN               LL_FLASH_EnablePrefetchBuffer
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnablePrefetchBuffer(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->ACR, FLASH_ACR_PRFTEN);
}

/**
  * @brief  Disable Data Cache
  * @rmtoll ACR          DCEN               LL_FLASH_DisableDataCache
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableDataCache(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->ACR, FLASH_ACR_DCEN);
}

/**
  * @brief  Disable Instruction Cache
  * @rmtoll ACR          ICEN               LL_FLASH_DisableInstructionCache
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableInstructionCache(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->ACR, FLASH_ACR_ICEN);
}

/**
  * @brief  Disable Prefetch Buffer
  * @rmtoll ACR          PRFTEN               LL_FLASH_DisablePrefetchBuffer
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisablePrefetchBuffer(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->ACR, FLASH_ACR_PRFTEN);
}


/**
  * @brief  Check if Data Cache is enabled
  * @rmtoll ACR          DCEN               LL_FLASH_IsEnabledDataCache
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledDataCache(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->ACR, FLASH_ACR_DCEN) == (FLASH_ACR_DCEN)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Instruction Cache is enabled
  * @rmtoll ACR          ICEN               LL_FLASH_IsEnabledInstructionCache
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledInstructionCache(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->ACR, FLASH_ACR_ICEN) == (FLASH_ACR_ICEN)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Prefetch Buffer is enabled
  * @rmtoll ACR          PRFTEN               LL_FLASH_IsEnabledPrefetchBuffer
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledPrefetchBuffer(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->ACR, FLASH_ACR_PRFTEN) == (FLASH_ACR_PRFTEN)) ? 1UL : 0UL);
}


/** @defgroup FLASH_LL_EF_FLAG_Management Flag Management
  * @{
  */

/**
  * @brief  Indicate the status of End of operation flag.
  * @rmtoll SR          EOP              LL_FLASH_IsActiveFlag_EOP
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_EOP(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_EOP) == (FLASH_SR_EOP));
}

/**
  * @brief  Indicate the status of WRPERR flag.
  * @rmtoll SR          WPRERR           LL_FLASH_IsActiveFlag_WRPERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_WRPERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_WRPERR) == (FLASH_SR_WRPERR));
}

/**
  * @brief  Indicate the status of RDERR0 flag.
  * @rmtoll SR          RDERR0              LL_FLASH_IsActiveFlag_RDERR0
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_RDERR0(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_RDERR0) == (FLASH_SR_RDERR0));
}

/**
  * @brief  Indicate the status of RDERR1 flag.
  * @rmtoll SR          RDERR1              LL_FLASH_IsActiveFlag_RDERR1
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_RDERR1(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_RDERR1) == (FLASH_SR_RDERR1));
}

/**
  * @brief  Indicate the status of USERLOCK flag.
  * @rmtoll SR          USRLOCK              LL_FLASH_IsActiveFlag_USERLOCK
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_USERLOCK(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_USRLOCK) == (FLASH_SR_USRLOCK));
}

/**
  * @brief  Indicate the status of OPTVERR flag.
  * @rmtoll SR          OPTVERR          LL_FLASH_IsActiveFlag_OPTVERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_OPTVERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_OPTVERR) == (FLASH_SR_OPTVERR));
}

/**
  * @brief  Indicate the status of BUSY0 flag.
  * @rmtoll SR          BSY0              LL_FLASH_IsActiveFlag_BUSY0
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_BUSY0(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_BSY0) == (FLASH_SR_BSY0));
}

/**
  * @brief  Indicate the status of BUSY1 flag.
  * @rmtoll SR          BSY1              LL_FLASH_IsActiveFlag_BUSY1
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_BUSY1(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_BSY1) == (FLASH_SR_BSY1));
}

/**
  * @brief  Indicate the status of ECCD flag.
  * @rmtoll ECCR          ECCD              LL_FLASH_IsActiveFlag_ECCD
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_ECCD(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->ECCR, FLASH_ECCR_ECCD) == (FLASH_ECCR_ECCD));
}

/**
  * @brief  Indicate the status of ECCC flag.
  * @rmtoll ECCR          ECCC              LL_FLASH_IsActiveFlag_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_ECCC(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->ECCR, FLASH_ECCR_ECCC) == (FLASH_ECCR_ECCC));
}

/**
  * @brief  Clear End of operation flag.
  * @rmtoll SR          EOP              LL_FLASH_ClearFlag_EOP
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_EOP(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_EOP);
}

/**
  * @brief  Clear WRPERR flag.
  * @rmtoll SR          WRPERR           LL_FLASH_ClearFlag_WRPERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_WRPERR(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_WRPERR);
}

/**
  * @brief  Clear RDERR0 flag.
  * @rmtoll SR          RDERR0           LL_FLASH_ClearFlag_RDERR0
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_RDERR0(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_RDERR0);
}

/**
  * @brief  Clear RDERR1 flag.
  * @rmtoll SR          RDERR1           LL_FLASH_ClearFlag_RDERR1
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_RDERR1(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_RDERR1);
}

/**
  * @brief  Clear OPTVERR flag.
  * @rmtoll SR          OPTVERR          LL_FLASH_ClearFlag_OPTVERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_OPTVERR(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_OPTVERR);
}

/**
  * @brief  Clear ECCD flag.
  * @rmtoll ECCR          ECCD          LL_FLASH_ClearFlag_ECCD
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_ECCD(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->ECCR,FLASH_ECCR_ECCD);
}

/**
  * @brief  Clear ECCC flag.
  * @rmtoll ECCR          ECCC          LL_FLASH_ClearFlag_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_ECCC(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->ECCR,FLASH_ECCR_ECCC);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_ERASE_Management Erase Management
  * @{
  */

/**
  * @brief  Enable Page Program
  * @rmtoll CR          PG               LL_FLASH_EnablePageProgram
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnablePageProgram(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_PG);
}

/**
  * @brief  Enable Page Erase
  * @rmtoll CR          PER              LL_FLASH_EnablePageErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnablePageErase(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_PER);
}

/**
  * @brief  Enable Mass Erase Bank0
  * @rmtoll CR          MER0              LL_FLASH_EnableMassEraseBank0
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableMassEraseBank0(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_MER0);
}

/**
  * @brief  Enable Mass Erase Bank1
  * @rmtoll CR          MER1              LL_FLASH_EnableMassEraseBank1
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableMassEraseBank1(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_MER1);
}

/**
  * @brief  Enable User Data Program
  * @rmtoll CR          UPG              LL_FLASH_EnableUserDataProgram
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableUserDataProgram(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_UPG);
}

/**
  * @brief  Enable User Data Erase
  * @rmtoll CR          UPER              LL_FLASH_EnableUserDataErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableUserDataErase(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_UPER);
}

/**
  * @brief  Enable Sector Erase
  * @rmtoll CR          SER              LL_FLASH_EnableSectorErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableSectorErase(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_SER);
}

/**
  * @brief  Disable Page Program
  * @rmtoll CR          PG               LL_FLASH_DisablePageProgram
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisablePageProgram(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_PG);
}

/**
  * @brief  Disable Page Erase
  * @rmtoll CR          PER              LL_FLASH_DisablePageErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisablePageErase(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_PER);
}

/**
  * @brief  Disable Mass Erase Bank0
  * @rmtoll CR          MER0              LL_FLASH_DisableMassEraseBank0
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableMassEraseBank0(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_MER0);
}

/**
  * @brief  Disable Mass Erase Bank1
  * @rmtoll CR          MER1              LL_FLASH_DisableMassEraseBank1
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableMassEraseBank1(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_MER1);
}

/**
  * @brief  Disable UserData Program
  * @rmtoll CR          UPG              LL_FLASH_DisableUserDataProgram
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableUserDataProgram(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_UPG);
}

/**
  * @brief  Disable UserData Erase
  * @rmtoll CR          UPER              LL_FLASH_DisableUserDataErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableUserDataErase(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_UPER);
}

/**
  * @brief  Disable Sector Erase
  * @rmtoll CR          SER              LL_FLASH_DisableSectorErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableSectorErase(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_SER);
}

/**
  * @brief  Check if Page Program is enabled
  * @rmtoll CR          PG               LL_FLASH_IsEnabledPageProgram
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledPageProgram(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_PG) == (FLASH_CR_PG)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Page erase is enabled
  * @rmtoll CR          PER              LL_FLASH_IsEnabledPageErase
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledPageErase(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_PER) == (FLASH_CR_PER)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Bank0 Mass erase is enabled
  * @rmtoll CR          MER0              LL_FLASH_IsEnabledMassEraseBank0
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledMassEraseBank0(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_MER0) == (FLASH_CR_MER0)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Bank1 Mass erase is enabled
  * @rmtoll CR          MER1              LL_FLASH_IsEnabledMassEraseBank1
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledMassEraseBank1(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_MER1) == (FLASH_CR_MER1)) ? 1UL : 0UL);
}

/**
  * @brief  Check if User Data Program is enabled
  * @rmtoll CR          UPG              LL_FLASH_IsEnabledUserDataProgram
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledUserDataProgram(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_UPG) == (FLASH_CR_UPG)) ? 1UL : 0UL);
}

/**
  * @brief  Check if UserData erase is enabled
  * @rmtoll CR          UPER              LL_FLASH_IsEnabledUserDataErase
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledUserDataErase(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_UPER) == (FLASH_CR_UPER)) ? 1UL : 0UL);
}


/**
  * @brief  Check if Sector Erase is enabled
  * @rmtoll CR          SER              LL_FLASH_IsEnabledSectorErase
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledSectorErase(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_SER) == (FLASH_CR_SER)) ? 1UL : 0UL);
}

/**
  * @brief  Set the Erase Address
  * @rmtoll LL_FLASH_SetEraseAddress
  * @param  FLASHx FLASH Instance
  * @param  address Erase address
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetEraseAddress(FLASH_TypeDef *FLASHx,uint32_t address)
{
  *(__IO uint32_t *)(address) = 0xFFFFFFFF;
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_Lock_Management Lock Management
  * @{
  */

/**
  * @brief Unlock the Flash
  * @rmtoll KEYR        KEYR             LL_FLASH_Unlock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_Unlock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->KEYR, LL_FLASH_KEY1);
  SET_BIT(FLASHx->KEYR, LL_FLASH_KEY2);
}

/**
  * @brief  Unlock the Option
  * @rmtoll OPTKEYR     OPTKEYR          LL_FLASH_OBUnlock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_OBUnlock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->OPTKEYR, LL_FLASH_OPTKEY1);
  SET_BIT(FLASHx->OPTKEYR, LL_FLASH_OPTKEY2);
}


/**
  * @brief  Lock the Flash
  * @rmtoll CR          LOCK             LL_FLASH_Lock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_Lock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_LOCK);
}

/**
  * @brief  Lock the Option
  * @rmtoll CR          OPTLOCK          LL_FLASH_OBLock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_OBLock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_OPTLOCK);
}

/**
  * @brief  Check if Flash is locked
  * @rmtoll CR          LOCK             LL_FLASH_IsLocked
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsLocked(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_LOCK) == (FLASH_CR_LOCK)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Option is locked
  * @rmtoll CR          OPTLOCK          LL_FLASH_IsOBLocked
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsOBLocked(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_OPTLOCK) == (FLASH_CR_OPTLOCK)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_LAUNCH_Management Launch Management
  * @{
  */

/**
  * @brief  Force the Option byte loading
  * @rmtoll CR          OBL_LAUNCH       LL_FLASH_Launch
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_Launch(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_OBL_LAUNCH);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_IT_Management Interrupt Management
  * @{
  */

/**
  * @brief  Enable Error interrupts.
  * @rmtoll CR          ERRIR            LL_FLASH_EnableIT_ERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_ERR(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_ERRIE);
}

/**
  * @brief  Enable End of operation interrupts.
  * @rmtoll CR          EOPIE            LL_FLASH_EnableIT_EOP
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_EOP(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_EOPIE);
}


/**
  * @brief  Enable PCROP0 Read error interrupts.
  * @rmtoll CR          RDERR0IE            LL_FLASH_EnableIT_RDERR0
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_RDERR0(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_RDERR0IE);
}

/**
  * @brief  Enable PCROP1 Read error interrupts.
  * @rmtoll CR          RDERR1IE            LL_FLASH_EnableIT_RDERR1
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_RDERR1(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_RDERR1IE);
}

/**
  * @brief  Enable eccc interrupts.
  * @rmtoll ECCR          ECCCIE            LL_FLASH_EnableIT_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_ECCC(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->ECCR, FLASH_ECCR_ECCCIE);
}

/**
  * @brief  Disable Error interrupts.
  * @rmtoll CR          ERRIE            LL_FLASH_DisableIT_ERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_ERR(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_ERRIE);
}

/**
  * @brief  Disable End of operation interrupts.
  * @rmtoll CR          EOPIE            LL_FLASH_DisableIT_EOP
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_EOP(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_EOPIE);
}

/**
  * @brief  Disable End of operation interrupts.
  * @rmtoll CR          RDERR0IE            LL_FLASH_DisableIT_RDERR0
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_RDERR0(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_RDERR0IE);
}

/**
  * @brief  Disable End of operation interrupts.
  * @rmtoll CR          RDERR1IE            LL_FLASH_DisableIT_RDERR1
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_RDERR1(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_RDERR1IE);
}

/**
  * @brief  Disable ECCC interrupts.
  * @rmtoll ECCR          ECCCIE            LL_FLASH_DisableIT_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_ECCC(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->ECCR, FLASH_ECCR_ECCCIE);
}

/**
  * @brief  Check if Error interrupts are enabled or disabled.
  * @rmtoll CR          ERRIE            LL_FLASH_IsEnabledIT_ERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_ERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_ERRIE) == (FLASH_CR_ERRIE));
}

/**
  * @brief  Check if End of operation interrupts are enabled or disabled.
  * @rmtoll CR          EOPIE            LL_FLASH_IsEnabledIT_EOP
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_EOP(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_EOPIE) == (FLASH_CR_EOPIE));
}

/**
  * @brief  Check if PCROP0 Read error interrupts are enabled or disabled.
  * @rmtoll CR          RDERR0IE            LL_FLASH_IsEnabledIT_RDERR0
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_RDERR0(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_RDERR0IE) == (FLASH_CR_RDERR0IE));
}

/**
  * @brief  Check if PCROP1 Read error interrupts are enabled or disabled.
  * @rmtoll CR          RDERR1IE            LL_FLASH_IsEnabledIT_RDERR1
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_RDERR1(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_RDERR1IE) == (FLASH_CR_RDERR1IE));
}

/**
  * @brief  Check if ECCC interrupts are enabled or disabled.
  * @rmtoll ECCR          ECCCIE            LL_FLASH_IsEnabledIT_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_ECCC(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->ECCR, FLASH_ECCR_ECCCIE) == (FLASH_ECCR_ECCCIE));
}


/**
  * @brief  Return ECC Area.
  * @rmtoll ECCR          BK_ECC            LL_FLASH_GetECCDetectArea
  * @rmtoll ECCR          SYSF_ECC          LL_FLASH_GetECCDetectArea
  * @param  FLASHx FLASH Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_ECC_DETECTIN_SYSTEMFLASH
  *         @arg @ref LL_FLASH_ECC_DETECTIN_BANK0
  *         @arg @ref LL_FLASH_ECC_DETECTIN_BANK1
  */
__STATIC_INLINE uint32_t LL_FLASH_GetECCDetectArea(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->ECCR, FLASH_ECCR_BK_ECC | FLASH_ECCR_SYSF_ECC);
}

/**
  * @brief  Return ECC Address.
  * @rmtoll ECCR          ADDR_ECC            LL_FLASH_GetECCDetectAddress
  * @param  FLASHx FLASH Instance.
  * @retval Returned the ECC Detect Address
  */
__STATIC_INLINE uint32_t LL_FLASH_GetECCDetectAddress(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->ECCR, FLASH_ECCR_ADDR_ECC);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_LPMODE Flash Lp Mode
  * @{
  */

/**
  * @brief  Set Flash Enter Lpmode Delay time
  * @rmtoll LPCR          LPRUN_ENTERT            LL_FLASH_SetEnterLpModeDelay
  * @param  FLASHx FLASH Instance.
  * @param  Flash_Delay The value be one of the follow:
  *           @arg LL_FLASH_ENTERLPMODEDELAY_1MSISYSCLOCK: Wait 1 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_2MSISYSCLOCK: Wait 2 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_3MSISYSCLOCK: Wait 3 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_4MSISYSCLOCK: Wait 4 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_5MSISYSCLOCK: Wait 5 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_6MSISYSCLOCK: Wait 6 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_7MSISYSCLOCK: Wait 7 MSISYS Clock
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetEnterLpModeDelay(FLASH_TypeDef *FLASHx,uint32_t Flash_Delay)
{
  MODIFY_REG(FLASHx->LPCR, FLASH_LPCR_LPRUN_ENTERT, Flash_Delay);
}

/**
  * @brief  Get Flash Enter Lpmode Delay time
  * @rmtoll LPCR          LPRUN_ENTERT            LL_FLASH_GetEnterLpModeDelay
  * @param  FLASHx FLASH Instance.
  * @retval  The value be one of the follow:
  *           @arg LL_FLASH_ENTERLPMODEDELAY_1MSISYSCLOCK: Wait 1 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_2MSISYSCLOCK: Wait 2 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_3MSISYSCLOCK: Wait 3 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_4MSISYSCLOCK: Wait 4 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_5MSISYSCLOCK: Wait 5 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_6MSISYSCLOCK: Wait 6 MSISYS Clock
  *           @arg LL_FLASH_ENTERLPMODEDELAY_7MSISYSCLOCK: Wait 7 MSISYS Clock
  */
__STATIC_INLINE uint32_t LL_FLASH_GetEnterLpModeDelay(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->LPCR, FLASH_LPCR_LPRUN_ENTERT);
}

/**
  * @brief  Set Flash Exit Lpmode Delay time
  * @rmtoll LPCR          LPRUN_EXITT            LL_FLASH_SetExitLpModeDelay
  * @param  FLASHx FLASH Instance.
  * @param  Flash_Delay The value be one of the follow:
  *           @arg LL_FLASH_EXITLPMODEDELAY_1MSISYSCLOCK: Wait 1 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_2MSISYSCLOCK: Wait 2 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_3MSISYSCLOCK: Wait 3 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDLEAY_4MSISYSCLOCK: Wait 4 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_5MSISYSCLOCK: Wait 5 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_6MSISYSCLOCK: Wait 6 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_7MSISYSCLOCK: Wait 7 MSISYS Clock
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetExitLpModeDelay(FLASH_TypeDef *FLASHx,uint32_t Flash_Delay)
{
  MODIFY_REG(FLASHx->LPCR, FLASH_LPCR_LPRUN_EXITT, Flash_Delay);
}

/**
  * @brief  Get Flash Exit Lpmode Delay time
  * @rmtoll LPCR          LPRUN_EXITT            LL_FLASH_GetExitLpModeDelay
  * @param  FLASHx FLASH Instance.
  * @retval  The value be one of the follow:
  *           @arg LL_FLASH_EXITLPMODEDELAY_1MSISYSCLOCK: Wait 1 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_2MSISYSCLOCK: Wait 2 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_3MSISYSCLOCK: Wait 3 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_4MSISYSCLOCK: Wait 4 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_5MSISYSCLOCK: Wait 5 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_6MSISYSCLOCK: Wait 6 MSISYS Clock
  *           @arg LL_FLASH_EXITLPMODEDELAY_7MSISYSCLOCK: Wait 7 MSISYS Clock
  */
__STATIC_INLINE uint32_t LL_FLASH_GetExitLpModeDelay(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->LPCR, FLASH_LPCR_LPRUN_EXITT);
}

/**
  * @brief  Enable Flash Sleep
  * @rmtoll LPCR          SLEEP_EN            LL_FLASH_EnableFlashSleep
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableFlashSleep(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->LPCR, FLASH_LPCR_SLEEP_EN);
}

/**
  * @brief  Disable Flash Sleep
  * @rmtoll LPCR          SLEEP_EN            LL_FLASH_DisableFlashSleep
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableFlashSleep(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->LPCR, FLASH_LPCR_SLEEP_EN);
}

/**
  * @brief  Check if Flash sleep are enabled or disabled.
  * @rmtoll LPCR          SLEEP_EN            LL_FLASH_IsEnabledFlashSleep
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledFlashSleep(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->LPCR, FLASH_LPCR_SLEEP_EN) == (FLASH_LPCR_SLEEP_EN));
}

/**
  * @brief  Set Flash Sleep Time
  * @rmtoll LPCR          SLEEP_TIME            LL_FLASH_SetFlashSleepTime
  * @param  FLASHx FLASH Instance.
  * @param  Sleep_Time The value Sleep Time between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetFlashSleepTime(FLASH_TypeDef *FLASHx,uint32_t Sleep_Time)
{
  MODIFY_REG(FLASHx->LPCR, FLASH_LPCR_SLEEP_TIME, Sleep_Time << FLASH_LPCR_SLEEP_TIME_Pos);
}

/**
  * @brief  Get Flash Sleep Time
  * @rmtoll LPCR          SLEEP_TIME            LL_FLASH_GetFlashSleepTime
  * @param  Sleep_Time The value Sleep Time
  * @retval The value Sleep Time between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_FLASH_GetFlashSleepTime(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->LPCR, FLASH_LPCR_SLEEP_TIME)>>FLASH_LPCR_SLEEP_TIME_Pos);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_PROGRAM_Management Program Management
  * @{
  */

/**
  * @brief  Enable Page Program Start
  * @rmtoll CR          PGSTRT           LL_FLASH_EnablePageProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_EnablePageProgramStart(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_PGSTRT);
}

/**
  * @brief  Enable Option Program Start
  * @rmtoll CR          OPTSTRT          LL_FLASH_EnableOptionProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_EnableOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_OPTSTRT);
}

/**
  * @brief Disable Page Program start
  * @rmtoll CR          PGSTRT           LL_FLASH_DisablePageProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_DisablePageProgramStart(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_PGSTRT);
}

/**
  * @brief  Disable Option Program start
  * @rmtoll CR          OPTSTRT          LL_FLASH_DisableOptionProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_DisableOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_OPTSTRT);
}

/**
  * @brief  Check if Page Program start is enabled
  * @rmtoll CR          PGSTRT              LL_FLASH_IsEnabledPageProgramStart
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledPageProgramStart(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_PGSTRT) == (FLASH_CR_PGSTRT));
}

/**
  * @brief  Check if Option program Start is enabled
  * @rmtoll CR          OPTSTRT         LL_FLASH_IsEnabledOptionProgramStart
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_OPTSTRT) == (FLASH_CR_OPTSTRT));
}

/**
  * @brief  Trigger the Option Program
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_TriggerOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  *((__IO uint32_t *)(0x1FFF1D00))=0xff;
}

/**
  * @brief  Program the page
  * @rmtoll CR          PGSTRT          LL_FLASH_PageProgram
  * @param  FLASHx FLASH Instance
  * @param  Address   Program Address
  * @param  DataAddress Data Address
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_PageProgram(FLASH_TypeDef *FLASHx,uint32_t Address, uint32_t * DataAddress)
{
  uint8_t index=0;
  uint32_t dest = Address;
  uint32_t * src = DataAddress;
  uint32_t primask_bit;
  /* Enter critical section */
  primask_bit = __get_PRIMASK();
  __disable_irq();
  /* 64 words*/
  while(index<64U)
  {
    *(uint32_t *)dest = *src;
    src += 1U;
    dest += 4U;
    index++;
    if(index==63)
    {
      LL_FLASH_EnablePageProgramStart(FLASHx);
    }
  }

  /* Exit critical section: restore previous priority mask */
  __set_PRIMASK(primask_bit);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_WRP_Management WRP Management
  * @{
  */

/**
  * @brief  Set WRP Address
  * @rmtoll WRPR        WRP             LL_FLASH_SetWRPRAddress
  * @param  FLASHx FLASH Instance
  * @param  Address This parameter can be a combination of the following values:
  *         @arg @ref LL_FLASH_WRP_DISABLE
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_0
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_1
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_2
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_3
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_4
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_5
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_6
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_7
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_8
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_9
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_10
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_11
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_12
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_13
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_14
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_15
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_0
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_1
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_2
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_3
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_4
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_5
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_6
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_7
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_8
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_9
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_10
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_11
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_12
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_13
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_14
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_15
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages0to31
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages32to63
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages64to95
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages96to127
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages128to159
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages160to191
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages192to223
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages224to255
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages256to287
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages288to319
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages320to351
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages352to383
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages384to415
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages416to447
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages448to479
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages480to511
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages0to31
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages32to63
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages64to95
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages96to127
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages128to159
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages160to191
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages192to223
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages224to255
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages256to287
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages288to319
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages320to351
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages352to383
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages384to415
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages416to447
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages448to479
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages480to511
  *         @arg @ref LL_FLASH_WRP_AllPages
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetWRPAddress(FLASH_TypeDef *FLASHx,uint32_t Address)
{
  MODIFY_REG(FLASHx->WRPR, FLASH_WRPR_BK0_WRPX | FLASH_WRPR_BK1_WRPX , ((~(Address)) & (FLASH_WRPR_BK0_WRPX | FLASH_WRPR_BK1_WRPX)));
}

/**
  * @brief  Get WRP Address
  * @rmtoll WRPR        WRP             LL_FLASH_GetWRPAddress
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be a combination of the following values:
  *         @arg @ref LL_FLASH_WRP_DISABLE
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_0
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_1
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_2
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_3
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_4
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_5
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_6
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_7
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_8
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_9
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_10
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_11
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_12
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_13
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_14
  *         @arg @ref LL_FLASH_WRP_BANK0_SECTOR_15
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_0
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_1
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_2
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_3
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_4
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_5
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_6
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_7
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_8
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_9
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_10
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_11
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_12
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_13
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_14
  *         @arg @ref LL_FLASH_WRP_BANK1_SECTOR_15
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages0to31
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages32to63
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages64to95
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages96to127
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages128to159
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages160to191
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages192to223
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages224to255
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages256to287
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages288to319
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages320to351
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages352to383
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages384to415
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages416to447
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages448to479
  *         @arg @ref LL_FLASH_WRP_BANK0_Pages480to511
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages0to31
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages32to63
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages64to95
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages96to127
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages128to159
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages160to191
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages192to223
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages224to255
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages256to287
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages288to319
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages320to351
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages352to383
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages384to415
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages416to447
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages448to479
  *         @arg @ref LL_FLASH_WRP_BANK1_Pages480to511
  *         @arg @ref LL_FLASH_WRP_AllPages
  */
__STATIC_INLINE uint32_t LL_FLASH_GetWRPAddress(FLASH_TypeDef *FLASHx)
{
  return ((~(READ_BIT(FLASHx->WRPR, FLASH_WRPR_BK0_WRPX | FLASH_WRPR_BK1_WRPX)))  & (FLASH_WRPR_BK0_WRPX | FLASH_WRPR_BK1_WRPX));
}

/**
  * @brief  Set Bank0 PCROP
  * @rmtoll PCROPR0        PCROP0SR             LL_FLASH_SetBank0PCROP
  * @rmtoll PCROPR0        PCROP0ER             LL_FLASH_SetBank0PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank0 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank0 pcrop
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetBank0PCROP(FLASH_TypeDef *FLASHx,uint32_t PCROPStartAddr,uint32_t PCROPEndAddr)
{
  uint32_t reg_value1;
  uint32_t reg_value2;
  uint32_t bank0_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR, FLASH_OPTR_BFB) == 0U)
  {
    bank0_addr = FLASH_BASE;
  }
  else
  {
    bank0_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }
  
  /* Calculate the location of the PCROPStartAddr in FLASH */
  reg_value1 = ((PCROPStartAddr - bank0_addr) >> 8);
  reg_value2 = (((PCROPEndAddr - bank0_addr) >> 8) << FLASH_PCROPR0_PCROP0ER_Pos) ;

  MODIFY_REG(FLASHx->PCROPR0,(FLASH_PCROPR0_PCROP0SR | FLASH_PCROPR0_PCROP0ER), (reg_value1 | reg_value2));
}

/**
  * @brief  Set Bank1 PCROP
  * @rmtoll PCROPR1        PCROP1SR             LL_FLASH_SetBank1PCROP
  * @rmtoll PCROPR1        PCROP1ER             LL_FLASH_SetBank1PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank1 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank1 pcrop
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetBank1PCROP(FLASH_TypeDef *FLASHx,uint32_t PCROPStartAddr,uint32_t PCROPEndAddr)
{
  uint32_t reg_value1;
  uint32_t reg_value2;
  uint32_t bank1_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR, FLASH_OPTR_BFB) == 0U)
  {
    bank1_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }
  else
  {
    bank1_addr = FLASH_BASE;
  }

  reg_value1 = ((PCROPStartAddr - bank1_addr) >> 8);
  reg_value2 = (((PCROPEndAddr - bank1_addr) >> 8) << FLASH_PCROPR1_PCROP1ER_Pos);
      
  MODIFY_REG(FLASHx->PCROPR1,(FLASH_PCROPR1_PCROP1SR | FLASH_PCROPR1_PCROP1ER), (reg_value1 | reg_value2));
}

/**
  * @brief  Get Bank0 PCROP
  * @rmtoll PCROPR0        PCROP0SR             LL_FLASH_SetBank0PCROP
  * @rmtoll PCROPR0        PCROP0ER             LL_FLASH_SetBank0PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank0 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank0 pcrop
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_GetBank0PCROP(FLASH_TypeDef *FLASHx,uint32_t *PCROPStartAddr,uint32_t *PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank0_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR, FLASH_OPTR_BFB) == 0U)
  {
    bank0_addr = FLASH_BASE;
  }
  else
  {
    bank0_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }
  
  /* Calculate PCROPStartAddr by FLASHx->PCROP0SR */
  reg_value       = ((READ_REG(FLASHx->PCROPR0) & FLASH_PCROPR0_PCROP0SR) << 8);
  *PCROPStartAddr = (reg_value) + bank0_addr;

  /* Calculate PCROPEndAddr by FLASHx->PCROP0ER */
  reg_value     = (((READ_REG(FLASHx->PCROPR0) & FLASH_PCROPR0_PCROP0ER) << 8) >> FLASH_PCROPR0_PCROP0ER_Pos);
  *PCROPEndAddr = (reg_value) + bank0_addr;
}

/**
  * @brief  Get Bank1 PCROP
  * @rmtoll PCROPR1        PCROP1SR             LL_FLASH_GetBank1PCROP
  * @rmtoll PCROPR1        PCROP1ER             LL_FLASH_GetBank1PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank1 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank1 pcrop
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_GetBank1PCROP(FLASH_TypeDef *FLASHx,uint32_t *PCROPStartAddr,uint32_t *PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank1_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR, FLASH_OPTR_BFB) == 0U)
  {
    bank1_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }
  else
  {
    bank1_addr = FLASH_BASE;
  }

  /* Calculate PCROPStartAddr by FLASHx->PCROP1SR */
  reg_value       = ((READ_REG(FLASHx->PCROPR1) & FLASH_PCROPR1_PCROP1SR) << 8);
  *PCROPStartAddr = (reg_value) + bank1_addr;

  /* Calculate PCROPEndAddr by FLASHx->PCROP1ER */
  reg_value     = (((READ_REG(FLASHx->PCROPR1) & FLASH_PCROPR1_PCROP1ER) << 8) >> FLASH_PCROPR1_PCROP1ER_Pos);
  *PCROPEndAddr = (reg_value) + bank1_addr;
}

/**
  * @}
  */

/**
  * @brief  Set Optr
  * @rmtoll OPTR            ECC_EN           LL_FLASH_SetOPTR
  * @rmtoll OPTR            BOOT_LOCK        LL_FLASH_SetOPTR
  * @rmtoll OPTR            BFB              LL_FLASH_SetOPTR
  * @rmtoll OPTR            SWD_MODE         LL_FLASH_SetOPTR
  * @rmtoll OPTR            SRAM_PE          LL_FLASH_SetOPTR
  * @rmtoll OPTR            nBOOT1           LL_FLASH_SetOPTR
  * @rmtoll OPTR            BOR_LEV          LL_FLASH_SetOPTR
  * @rmtoll OPTR            BOR_EN           LL_FLASH_SetOPTR
  * @rmtoll OPTR            NRST_MODE        LL_FLASH_SetOPTR
  * @rmtoll OPTR            WWDG_SW          LL_FLASH_SetOPTR
  * @rmtoll OPTR            IWDG_SW          LL_FLASH_SetOPTR
  * @rmtoll OPTR            IWDG_STOP        LL_FLASH_SetOPTR
  * @rmtoll OPTR            IWDG_STDBY       LL_FLASH_SetOPTR
  * @rmtoll OPTR            NRST_STOP        LL_FLASH_SetOPTR
  * @rmtoll OPTR            NRST_STDBY       LL_FLASH_SetOPTR
  * @rmtoll OPTR            NRST_RDP         LL_FLASH_SetOPTR
  * @param  FLASHx FLASH Instance
  * @param  USERType This parameter can be a combination of following values:
  *         @arg @ref LL_FLASH_OPTR_ECC_EN
  *         @arg @ref LL_FLASH_OPTR_BOOT_LOCK
  *         @arg @ref LL_FLASH_OPTR_BFB
  *         @arg @ref LL_FLASH_OPTR_SWD_MODE
  *         @arg @ref LL_FLASH_OPTR_SRAM_PE
  *         @arg @ref LL_FLASH_OPTR_NBOOT1
  *         @arg @ref LL_FLASH_OPTR_BOR_LEVEL
  *         @arg @ref LL_FLASH_OPTR_BOR_ENABLE
  *         @arg @ref LL_FLASH_OPTR_NRST_MODE
  *         @arg @ref LL_FLASH_OPTR_WWDG_SW
  *         @arg @ref LL_FLASH_OPTR_IWDG_SW
  *         @arg @ref LL_FLASH_OPTR_IWDG_STOP
  *         @arg @ref LL_FLASH_OPTR_IWDG_STDBY
  *         @arg @ref LL_FLASH_OPTR_NRST_STOP
  *         @arg @ref LL_FLASH_OPTR_NRST_STDBY
  *         @arg @ref LL_FLASH_OPTR_RDP
  * @param  USERConfig Optr value need to be config by USERType
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetOPTR(FLASH_TypeDef *FLASHx,uint32_t USERType,uint32_t USERConfig)
{
  MODIFY_REG(FLASHx->OPTR,USERType,USERConfig);
}


/**
  * @brief Get ECC Mode
  * @rmtoll OPTR        ECC_EN          LL_FLASH_GetECCMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_ECC_DISABLE
  *         @arg @ref LL_FLASH_ECC_DISABLE
  */
__STATIC_INLINE uint32_t LL_FLASH_GetECCMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_ECC_EN);
}

/**
  * @brief Get BOOT Lock
  * @rmtoll OPTR        BOOT_LOCK          LL_FLASH_GetBOOTLock
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_BOOT_FROM_OB
  *         @arg @ref LL_FLASH_BOOT_FROM_MAINFLASH
  */
__STATIC_INLINE uint32_t LL_FLASH_GetBOOTLock(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_BOOT_LOCK);
}

/**
  * @brief Get BFB Mode
  * @rmtoll OPTR        BFB          LL_FLASH_GetBFBMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_BFB_START_BANK0
  *         @arg @ref LL_FLASH_BFB_START_BANK1
  */
__STATIC_INLINE uint32_t LL_FLASH_GetBFBMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_BFB);
}

/**
  * @brief Get SWD Mode
  * @rmtoll OPTR        SWD_MODE          LL_FLASH_GetSWDMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_SWDIO_PA4_SWCLK_PA5
  *         @arg @ref LL_FLASH_SWDIO_PB6_SWCLK_PB5
  *         @arg @ref LL_FLASH_SWDIO_PB6_SWCLK_PA5
  *         @arg @ref LL_FLASH_SWDIO_PA4_SWCLK_PB5
  */
__STATIC_INLINE uint32_t LL_FLASH_GetSWDMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_SWD_MODE);
}

/**
  * @brief Get SRAM_PE Mode
  * @rmtoll OPTR        SRAM_PE          LL_FLASH_GetSRAMPE
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_SRAM_PARITY_DISABLE
  *         @arg @ref LL_FLASH_SRAM_PARITY_ENABLE
  */
__STATIC_INLINE uint32_t LL_FLASH_GetSRAMPE(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_SRAM_PE);
}

/**
  * @brief Get BOR Level
  * @rmtoll OPTR        BOR_LEV          LL_FLASH_GetBORLevel
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_BOR_LEV0
  *         @arg @ref LL_FLASH_BOR_LEV1
  *         @arg @ref LL_FLASH_BOR_LEV2
  *         @arg @ref LL_FLASH_BOR_LEV3
  *         @arg @ref LL_FLASH_BOR_LEV4
  *         @arg @ref LL_FLASH_BOR_LEV5
  *         @arg @ref LL_FLASH_BOR_LEV6
  *         @arg @ref LL_FLASH_BOR_LEV7
  */
__STATIC_INLINE uint32_t LL_FLASH_GetBORLevel(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_BOR_LEV);
}

/**
  * @brief Get BOR Enable
  * @rmtoll OPTR        BOR_EN          LL_FLASH_GetBOREnable
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_BOR_DISABLE
  *         @arg @ref LL_FLASH_BOR_ENABLE
  */
__STATIC_INLINE uint32_t LL_FLASH_GetBOREnable(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_BOR_EN);
}


/**
  * @brief Get NBoot1 Mode
  * @rmtoll OPTR        NBOOT1          LL_FLASH_GetnBOOT1Mode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_NBOOT1_SRAM
  *         @arg @ref LL_FLASH_NBOOT1_SYSTEM
  */
__STATIC_INLINE uint32_t LL_FLASH_GetnBOOT1Mode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_NBOOT1);
}

/**
  * @brief Get NRST Mode
  * @rmtoll OPTR        NRST_MODE          LL_FLASH_GetNrstMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_NRST_MODE_RESET
  *         @arg @ref LL_FLASH_NRST_MODE_GPIO
  */
__STATIC_INLINE uint32_t LL_FLASH_GetNrstMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_NRST_MODE);
}

/**
  * @brief Get WWDG Mode
  * @rmtoll OPTR        WWDG_SW          LL_FLASH_GetWWDGMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_WWDG_MODE_HW
  *         @arg @ref LL_FLASH_WWDG_MODE_SW
  */
__STATIC_INLINE uint32_t LL_FLASH_GetWWDGMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_WWDG_SW);
}

/**
  * @brief Get IWDG Mode
  * @rmtoll OPTR        IWDG_SW          LL_FLASH_GetIWDGMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_IWDG_MODE_HW
  *         @arg @ref LL_FLASH_IWDG_MODE_SW
  */
__STATIC_INLINE uint32_t LL_FLASH_GetIWDGMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_IWDG_SW);
}

/**
  * @brief Get IWDG In Stop
  * @rmtoll OPTR        IWDG_STOP          LL_FLASH_GetIWDGInStop
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_IWDG_INSTOP_FREEZE
  *         @arg @ref LL_FLASH_IWDG_INSTOP_ACTIVE
  */
__STATIC_INLINE uint32_t LL_FLASH_GetIWDGInStop(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_IWDG_STOP);
}

/**
  * @brief Get IWDG In Standby
  * @rmtoll OPTR        IWDG_STDBY          LL_FLASH_GetIWDGInStandby
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_IWDG_INSTANDBY_FREEZE
  *         @arg @ref LL_FLASH_IWDG_INSTANDBY_ACTIVE
  */
__STATIC_INLINE uint32_t LL_FLASH_GetIWDGInStandby(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_IWDG_STDBY);
}

/**
  * @brief Get NRST STOP Mode
  * @rmtoll OPTR        NRST_STOP          LL_FLASH_GetStopReset
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_STOP_RST
  *         @arg @ref LL_FLASH_STOP_NORST
  */
__STATIC_INLINE uint32_t LL_FLASH_GetSTOPReset(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_NRST_STOP);
}

/**
  * @brief Get NRST STDBY Mode
  * @rmtoll OPTR        NRST_STDBY          LL_FLASH_GetStandbyReset
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_STANDBY_RST
  *         @arg @ref LL_FLASH_STANDBY_NORST
  */
__STATIC_INLINE uint32_t LL_FLASH_GetSTANDBYReset(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_NRST_STDBY);
}

/**
  * @brief Get RDP Level
  * @rmtoll OPTR        RDP          LL_FLASH_GetRDP
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_RDP_LEVEL_0
  *         @arg @ref LL_FLASH_RDP_LEVEL_1
  */
__STATIC_INLINE uint32_t LL_FLASH_GetRDP(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR, FLASH_OPTR_RDP);
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
#endif /* defined (FLASH) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32C882_LL_FLASH_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
