/*******************************************************************************
* File Name: LDG2.h  
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

#if !defined(CY_PINS_LDG2_H) /* Pins LDG2_H */
#define CY_PINS_LDG2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LDG2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LDG2__PORT == 15 && ((LDG2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LDG2_Write(uint8 value) ;
void    LDG2_SetDriveMode(uint8 mode) ;
uint8   LDG2_ReadDataReg(void) ;
uint8   LDG2_Read(void) ;
uint8   LDG2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LDG2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LDG2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LDG2_DM_RES_UP          PIN_DM_RES_UP
#define LDG2_DM_RES_DWN         PIN_DM_RES_DWN
#define LDG2_DM_OD_LO           PIN_DM_OD_LO
#define LDG2_DM_OD_HI           PIN_DM_OD_HI
#define LDG2_DM_STRONG          PIN_DM_STRONG
#define LDG2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LDG2_MASK               LDG2__MASK
#define LDG2_SHIFT              LDG2__SHIFT
#define LDG2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LDG2_PS                     (* (reg8 *) LDG2__PS)
/* Data Register */
#define LDG2_DR                     (* (reg8 *) LDG2__DR)
/* Port Number */
#define LDG2_PRT_NUM                (* (reg8 *) LDG2__PRT) 
/* Connect to Analog Globals */                                                  
#define LDG2_AG                     (* (reg8 *) LDG2__AG)                       
/* Analog MUX bux enable */
#define LDG2_AMUX                   (* (reg8 *) LDG2__AMUX) 
/* Bidirectional Enable */                                                        
#define LDG2_BIE                    (* (reg8 *) LDG2__BIE)
/* Bit-mask for Aliased Register Access */
#define LDG2_BIT_MASK               (* (reg8 *) LDG2__BIT_MASK)
/* Bypass Enable */
#define LDG2_BYP                    (* (reg8 *) LDG2__BYP)
/* Port wide control signals */                                                   
#define LDG2_CTL                    (* (reg8 *) LDG2__CTL)
/* Drive Modes */
#define LDG2_DM0                    (* (reg8 *) LDG2__DM0) 
#define LDG2_DM1                    (* (reg8 *) LDG2__DM1)
#define LDG2_DM2                    (* (reg8 *) LDG2__DM2) 
/* Input Buffer Disable Override */
#define LDG2_INP_DIS                (* (reg8 *) LDG2__INP_DIS)
/* LCD Common or Segment Drive */
#define LDG2_LCD_COM_SEG            (* (reg8 *) LDG2__LCD_COM_SEG)
/* Enable Segment LCD */
#define LDG2_LCD_EN                 (* (reg8 *) LDG2__LCD_EN)
/* Slew Rate Control */
#define LDG2_SLW                    (* (reg8 *) LDG2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LDG2_PRTDSI__CAPS_SEL       (* (reg8 *) LDG2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LDG2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LDG2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LDG2_PRTDSI__OE_SEL0        (* (reg8 *) LDG2__PRTDSI__OE_SEL0) 
#define LDG2_PRTDSI__OE_SEL1        (* (reg8 *) LDG2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LDG2_PRTDSI__OUT_SEL0       (* (reg8 *) LDG2__PRTDSI__OUT_SEL0) 
#define LDG2_PRTDSI__OUT_SEL1       (* (reg8 *) LDG2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LDG2_PRTDSI__SYNC_OUT       (* (reg8 *) LDG2__PRTDSI__SYNC_OUT) 


#if defined(LDG2__INTSTAT)  /* Interrupt Registers */

    #define LDG2_INTSTAT                (* (reg8 *) LDG2__INTSTAT)
    #define LDG2_SNAP                   (* (reg8 *) LDG2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LDG2_H */


/* [] END OF FILE */
