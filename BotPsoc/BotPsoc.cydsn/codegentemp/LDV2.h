/*******************************************************************************
* File Name: LDV2.h  
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

#if !defined(CY_PINS_LDV2_H) /* Pins LDV2_H */
#define CY_PINS_LDV2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LDV2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LDV2__PORT == 15 && ((LDV2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LDV2_Write(uint8 value) ;
void    LDV2_SetDriveMode(uint8 mode) ;
uint8   LDV2_ReadDataReg(void) ;
uint8   LDV2_Read(void) ;
uint8   LDV2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LDV2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LDV2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LDV2_DM_RES_UP          PIN_DM_RES_UP
#define LDV2_DM_RES_DWN         PIN_DM_RES_DWN
#define LDV2_DM_OD_LO           PIN_DM_OD_LO
#define LDV2_DM_OD_HI           PIN_DM_OD_HI
#define LDV2_DM_STRONG          PIN_DM_STRONG
#define LDV2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LDV2_MASK               LDV2__MASK
#define LDV2_SHIFT              LDV2__SHIFT
#define LDV2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LDV2_PS                     (* (reg8 *) LDV2__PS)
/* Data Register */
#define LDV2_DR                     (* (reg8 *) LDV2__DR)
/* Port Number */
#define LDV2_PRT_NUM                (* (reg8 *) LDV2__PRT) 
/* Connect to Analog Globals */                                                  
#define LDV2_AG                     (* (reg8 *) LDV2__AG)                       
/* Analog MUX bux enable */
#define LDV2_AMUX                   (* (reg8 *) LDV2__AMUX) 
/* Bidirectional Enable */                                                        
#define LDV2_BIE                    (* (reg8 *) LDV2__BIE)
/* Bit-mask for Aliased Register Access */
#define LDV2_BIT_MASK               (* (reg8 *) LDV2__BIT_MASK)
/* Bypass Enable */
#define LDV2_BYP                    (* (reg8 *) LDV2__BYP)
/* Port wide control signals */                                                   
#define LDV2_CTL                    (* (reg8 *) LDV2__CTL)
/* Drive Modes */
#define LDV2_DM0                    (* (reg8 *) LDV2__DM0) 
#define LDV2_DM1                    (* (reg8 *) LDV2__DM1)
#define LDV2_DM2                    (* (reg8 *) LDV2__DM2) 
/* Input Buffer Disable Override */
#define LDV2_INP_DIS                (* (reg8 *) LDV2__INP_DIS)
/* LCD Common or Segment Drive */
#define LDV2_LCD_COM_SEG            (* (reg8 *) LDV2__LCD_COM_SEG)
/* Enable Segment LCD */
#define LDV2_LCD_EN                 (* (reg8 *) LDV2__LCD_EN)
/* Slew Rate Control */
#define LDV2_SLW                    (* (reg8 *) LDV2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LDV2_PRTDSI__CAPS_SEL       (* (reg8 *) LDV2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LDV2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LDV2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LDV2_PRTDSI__OE_SEL0        (* (reg8 *) LDV2__PRTDSI__OE_SEL0) 
#define LDV2_PRTDSI__OE_SEL1        (* (reg8 *) LDV2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LDV2_PRTDSI__OUT_SEL0       (* (reg8 *) LDV2__PRTDSI__OUT_SEL0) 
#define LDV2_PRTDSI__OUT_SEL1       (* (reg8 *) LDV2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LDV2_PRTDSI__SYNC_OUT       (* (reg8 *) LDV2__PRTDSI__SYNC_OUT) 


#if defined(LDV2__INTSTAT)  /* Interrupt Registers */

    #define LDV2_INTSTAT                (* (reg8 *) LDV2__INTSTAT)
    #define LDV2_SNAP                   (* (reg8 *) LDV2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LDV2_H */


/* [] END OF FILE */
