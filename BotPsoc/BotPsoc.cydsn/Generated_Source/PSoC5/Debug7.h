/*******************************************************************************
* File Name: Debug7.h  
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

#if !defined(CY_PINS_Debug7_H) /* Pins Debug7_H */
#define CY_PINS_Debug7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Debug7_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Debug7__PORT == 15 && ((Debug7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Debug7_Write(uint8 value) ;
void    Debug7_SetDriveMode(uint8 mode) ;
uint8   Debug7_ReadDataReg(void) ;
uint8   Debug7_Read(void) ;
uint8   Debug7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Debug7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Debug7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Debug7_DM_RES_UP          PIN_DM_RES_UP
#define Debug7_DM_RES_DWN         PIN_DM_RES_DWN
#define Debug7_DM_OD_LO           PIN_DM_OD_LO
#define Debug7_DM_OD_HI           PIN_DM_OD_HI
#define Debug7_DM_STRONG          PIN_DM_STRONG
#define Debug7_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Debug7_MASK               Debug7__MASK
#define Debug7_SHIFT              Debug7__SHIFT
#define Debug7_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Debug7_PS                     (* (reg8 *) Debug7__PS)
/* Data Register */
#define Debug7_DR                     (* (reg8 *) Debug7__DR)
/* Port Number */
#define Debug7_PRT_NUM                (* (reg8 *) Debug7__PRT) 
/* Connect to Analog Globals */                                                  
#define Debug7_AG                     (* (reg8 *) Debug7__AG)                       
/* Analog MUX bux enable */
#define Debug7_AMUX                   (* (reg8 *) Debug7__AMUX) 
/* Bidirectional Enable */                                                        
#define Debug7_BIE                    (* (reg8 *) Debug7__BIE)
/* Bit-mask for Aliased Register Access */
#define Debug7_BIT_MASK               (* (reg8 *) Debug7__BIT_MASK)
/* Bypass Enable */
#define Debug7_BYP                    (* (reg8 *) Debug7__BYP)
/* Port wide control signals */                                                   
#define Debug7_CTL                    (* (reg8 *) Debug7__CTL)
/* Drive Modes */
#define Debug7_DM0                    (* (reg8 *) Debug7__DM0) 
#define Debug7_DM1                    (* (reg8 *) Debug7__DM1)
#define Debug7_DM2                    (* (reg8 *) Debug7__DM2) 
/* Input Buffer Disable Override */
#define Debug7_INP_DIS                (* (reg8 *) Debug7__INP_DIS)
/* LCD Common or Segment Drive */
#define Debug7_LCD_COM_SEG            (* (reg8 *) Debug7__LCD_COM_SEG)
/* Enable Segment LCD */
#define Debug7_LCD_EN                 (* (reg8 *) Debug7__LCD_EN)
/* Slew Rate Control */
#define Debug7_SLW                    (* (reg8 *) Debug7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Debug7_PRTDSI__CAPS_SEL       (* (reg8 *) Debug7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Debug7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Debug7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Debug7_PRTDSI__OE_SEL0        (* (reg8 *) Debug7__PRTDSI__OE_SEL0) 
#define Debug7_PRTDSI__OE_SEL1        (* (reg8 *) Debug7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Debug7_PRTDSI__OUT_SEL0       (* (reg8 *) Debug7__PRTDSI__OUT_SEL0) 
#define Debug7_PRTDSI__OUT_SEL1       (* (reg8 *) Debug7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Debug7_PRTDSI__SYNC_OUT       (* (reg8 *) Debug7__PRTDSI__SYNC_OUT) 


#if defined(Debug7__INTSTAT)  /* Interrupt Registers */

    #define Debug7_INTSTAT                (* (reg8 *) Debug7__INTSTAT)
    #define Debug7_SNAP                   (* (reg8 *) Debug7__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Debug7_H */


/* [] END OF FILE */
