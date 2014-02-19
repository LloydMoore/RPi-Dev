/*******************************************************************************
* File Name: PiUART_TXD.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PiUART_TXD_H) /* Pins PiUART_TXD_H */
#define CY_PINS_PiUART_TXD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PiUART_TXD_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PiUART_TXD__PORT == 15 && ((PiUART_TXD__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PiUART_TXD_Write(uint8 value) ;
void    PiUART_TXD_SetDriveMode(uint8 mode) ;
uint8   PiUART_TXD_ReadDataReg(void) ;
uint8   PiUART_TXD_Read(void) ;
uint8   PiUART_TXD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PiUART_TXD_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PiUART_TXD_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PiUART_TXD_DM_RES_UP          PIN_DM_RES_UP
#define PiUART_TXD_DM_RES_DWN         PIN_DM_RES_DWN
#define PiUART_TXD_DM_OD_LO           PIN_DM_OD_LO
#define PiUART_TXD_DM_OD_HI           PIN_DM_OD_HI
#define PiUART_TXD_DM_STRONG          PIN_DM_STRONG
#define PiUART_TXD_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PiUART_TXD_MASK               PiUART_TXD__MASK
#define PiUART_TXD_SHIFT              PiUART_TXD__SHIFT
#define PiUART_TXD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PiUART_TXD_PS                     (* (reg8 *) PiUART_TXD__PS)
/* Data Register */
#define PiUART_TXD_DR                     (* (reg8 *) PiUART_TXD__DR)
/* Port Number */
#define PiUART_TXD_PRT_NUM                (* (reg8 *) PiUART_TXD__PRT) 
/* Connect to Analog Globals */                                                  
#define PiUART_TXD_AG                     (* (reg8 *) PiUART_TXD__AG)                       
/* Analog MUX bux enable */
#define PiUART_TXD_AMUX                   (* (reg8 *) PiUART_TXD__AMUX) 
/* Bidirectional Enable */                                                        
#define PiUART_TXD_BIE                    (* (reg8 *) PiUART_TXD__BIE)
/* Bit-mask for Aliased Register Access */
#define PiUART_TXD_BIT_MASK               (* (reg8 *) PiUART_TXD__BIT_MASK)
/* Bypass Enable */
#define PiUART_TXD_BYP                    (* (reg8 *) PiUART_TXD__BYP)
/* Port wide control signals */                                                   
#define PiUART_TXD_CTL                    (* (reg8 *) PiUART_TXD__CTL)
/* Drive Modes */
#define PiUART_TXD_DM0                    (* (reg8 *) PiUART_TXD__DM0) 
#define PiUART_TXD_DM1                    (* (reg8 *) PiUART_TXD__DM1)
#define PiUART_TXD_DM2                    (* (reg8 *) PiUART_TXD__DM2) 
/* Input Buffer Disable Override */
#define PiUART_TXD_INP_DIS                (* (reg8 *) PiUART_TXD__INP_DIS)
/* LCD Common or Segment Drive */
#define PiUART_TXD_LCD_COM_SEG            (* (reg8 *) PiUART_TXD__LCD_COM_SEG)
/* Enable Segment LCD */
#define PiUART_TXD_LCD_EN                 (* (reg8 *) PiUART_TXD__LCD_EN)
/* Slew Rate Control */
#define PiUART_TXD_SLW                    (* (reg8 *) PiUART_TXD__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PiUART_TXD_PRTDSI__CAPS_SEL       (* (reg8 *) PiUART_TXD__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PiUART_TXD_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PiUART_TXD__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PiUART_TXD_PRTDSI__OE_SEL0        (* (reg8 *) PiUART_TXD__PRTDSI__OE_SEL0) 
#define PiUART_TXD_PRTDSI__OE_SEL1        (* (reg8 *) PiUART_TXD__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PiUART_TXD_PRTDSI__OUT_SEL0       (* (reg8 *) PiUART_TXD__PRTDSI__OUT_SEL0) 
#define PiUART_TXD_PRTDSI__OUT_SEL1       (* (reg8 *) PiUART_TXD__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PiUART_TXD_PRTDSI__SYNC_OUT       (* (reg8 *) PiUART_TXD__PRTDSI__SYNC_OUT) 


#if defined(PiUART_TXD__INTSTAT)  /* Interrupt Registers */

    #define PiUART_TXD_INTSTAT                (* (reg8 *) PiUART_TXD__INTSTAT)
    #define PiUART_TXD_SNAP                   (* (reg8 *) PiUART_TXD__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PiUART_TXD_H */


/* [] END OF FILE */
