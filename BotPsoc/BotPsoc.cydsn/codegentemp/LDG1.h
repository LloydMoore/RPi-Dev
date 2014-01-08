/*******************************************************************************
* File Name: LDG1.h  
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

#if !defined(CY_PINS_LDG1_H) /* Pins LDG1_H */
#define CY_PINS_LDG1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LDG1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LDG1__PORT == 15 && ((LDG1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LDG1_Write(uint8 value) ;
void    LDG1_SetDriveMode(uint8 mode) ;
uint8   LDG1_ReadDataReg(void) ;
uint8   LDG1_Read(void) ;
uint8   LDG1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LDG1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LDG1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LDG1_DM_RES_UP          PIN_DM_RES_UP
#define LDG1_DM_RES_DWN         PIN_DM_RES_DWN
#define LDG1_DM_OD_LO           PIN_DM_OD_LO
#define LDG1_DM_OD_HI           PIN_DM_OD_HI
#define LDG1_DM_STRONG          PIN_DM_STRONG
#define LDG1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LDG1_MASK               LDG1__MASK
#define LDG1_SHIFT              LDG1__SHIFT
#define LDG1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LDG1_PS                     (* (reg8 *) LDG1__PS)
/* Data Register */
#define LDG1_DR                     (* (reg8 *) LDG1__DR)
/* Port Number */
#define LDG1_PRT_NUM                (* (reg8 *) LDG1__PRT) 
/* Connect to Analog Globals */                                                  
#define LDG1_AG                     (* (reg8 *) LDG1__AG)                       
/* Analog MUX bux enable */
#define LDG1_AMUX                   (* (reg8 *) LDG1__AMUX) 
/* Bidirectional Enable */                                                        
#define LDG1_BIE                    (* (reg8 *) LDG1__BIE)
/* Bit-mask for Aliased Register Access */
#define LDG1_BIT_MASK               (* (reg8 *) LDG1__BIT_MASK)
/* Bypass Enable */
#define LDG1_BYP                    (* (reg8 *) LDG1__BYP)
/* Port wide control signals */                                                   
#define LDG1_CTL                    (* (reg8 *) LDG1__CTL)
/* Drive Modes */
#define LDG1_DM0                    (* (reg8 *) LDG1__DM0) 
#define LDG1_DM1                    (* (reg8 *) LDG1__DM1)
#define LDG1_DM2                    (* (reg8 *) LDG1__DM2) 
/* Input Buffer Disable Override */
#define LDG1_INP_DIS                (* (reg8 *) LDG1__INP_DIS)
/* LCD Common or Segment Drive */
#define LDG1_LCD_COM_SEG            (* (reg8 *) LDG1__LCD_COM_SEG)
/* Enable Segment LCD */
#define LDG1_LCD_EN                 (* (reg8 *) LDG1__LCD_EN)
/* Slew Rate Control */
#define LDG1_SLW                    (* (reg8 *) LDG1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LDG1_PRTDSI__CAPS_SEL       (* (reg8 *) LDG1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LDG1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LDG1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LDG1_PRTDSI__OE_SEL0        (* (reg8 *) LDG1__PRTDSI__OE_SEL0) 
#define LDG1_PRTDSI__OE_SEL1        (* (reg8 *) LDG1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LDG1_PRTDSI__OUT_SEL0       (* (reg8 *) LDG1__PRTDSI__OUT_SEL0) 
#define LDG1_PRTDSI__OUT_SEL1       (* (reg8 *) LDG1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LDG1_PRTDSI__SYNC_OUT       (* (reg8 *) LDG1__PRTDSI__SYNC_OUT) 


#if defined(LDG1__INTSTAT)  /* Interrupt Registers */

    #define LDG1_INTSTAT                (* (reg8 *) LDG1__INTSTAT)
    #define LDG1_SNAP                   (* (reg8 *) LDG1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LDG1_H */


/* [] END OF FILE */
