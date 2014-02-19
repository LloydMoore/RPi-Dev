/*******************************************************************************
* File Name: Debug3.h  
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

#if !defined(CY_PINS_Debug3_H) /* Pins Debug3_H */
#define CY_PINS_Debug3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Debug3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Debug3__PORT == 15 && ((Debug3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Debug3_Write(uint8 value) ;
void    Debug3_SetDriveMode(uint8 mode) ;
uint8   Debug3_ReadDataReg(void) ;
uint8   Debug3_Read(void) ;
uint8   Debug3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Debug3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Debug3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Debug3_DM_RES_UP          PIN_DM_RES_UP
#define Debug3_DM_RES_DWN         PIN_DM_RES_DWN
#define Debug3_DM_OD_LO           PIN_DM_OD_LO
#define Debug3_DM_OD_HI           PIN_DM_OD_HI
#define Debug3_DM_STRONG          PIN_DM_STRONG
#define Debug3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Debug3_MASK               Debug3__MASK
#define Debug3_SHIFT              Debug3__SHIFT
#define Debug3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Debug3_PS                     (* (reg8 *) Debug3__PS)
/* Data Register */
#define Debug3_DR                     (* (reg8 *) Debug3__DR)
/* Port Number */
#define Debug3_PRT_NUM                (* (reg8 *) Debug3__PRT) 
/* Connect to Analog Globals */                                                  
#define Debug3_AG                     (* (reg8 *) Debug3__AG)                       
/* Analog MUX bux enable */
#define Debug3_AMUX                   (* (reg8 *) Debug3__AMUX) 
/* Bidirectional Enable */                                                        
#define Debug3_BIE                    (* (reg8 *) Debug3__BIE)
/* Bit-mask for Aliased Register Access */
#define Debug3_BIT_MASK               (* (reg8 *) Debug3__BIT_MASK)
/* Bypass Enable */
#define Debug3_BYP                    (* (reg8 *) Debug3__BYP)
/* Port wide control signals */                                                   
#define Debug3_CTL                    (* (reg8 *) Debug3__CTL)
/* Drive Modes */
#define Debug3_DM0                    (* (reg8 *) Debug3__DM0) 
#define Debug3_DM1                    (* (reg8 *) Debug3__DM1)
#define Debug3_DM2                    (* (reg8 *) Debug3__DM2) 
/* Input Buffer Disable Override */
#define Debug3_INP_DIS                (* (reg8 *) Debug3__INP_DIS)
/* LCD Common or Segment Drive */
#define Debug3_LCD_COM_SEG            (* (reg8 *) Debug3__LCD_COM_SEG)
/* Enable Segment LCD */
#define Debug3_LCD_EN                 (* (reg8 *) Debug3__LCD_EN)
/* Slew Rate Control */
#define Debug3_SLW                    (* (reg8 *) Debug3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Debug3_PRTDSI__CAPS_SEL       (* (reg8 *) Debug3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Debug3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Debug3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Debug3_PRTDSI__OE_SEL0        (* (reg8 *) Debug3__PRTDSI__OE_SEL0) 
#define Debug3_PRTDSI__OE_SEL1        (* (reg8 *) Debug3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Debug3_PRTDSI__OUT_SEL0       (* (reg8 *) Debug3__PRTDSI__OUT_SEL0) 
#define Debug3_PRTDSI__OUT_SEL1       (* (reg8 *) Debug3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Debug3_PRTDSI__SYNC_OUT       (* (reg8 *) Debug3__PRTDSI__SYNC_OUT) 


#if defined(Debug3__INTSTAT)  /* Interrupt Registers */

    #define Debug3_INTSTAT                (* (reg8 *) Debug3__INTSTAT)
    #define Debug3_SNAP                   (* (reg8 *) Debug3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Debug3_H */


/* [] END OF FILE */
