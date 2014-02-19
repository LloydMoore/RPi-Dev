/*******************************************************************************
* File Name: LDV1.h  
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

#if !defined(CY_PINS_LDV1_H) /* Pins LDV1_H */
#define CY_PINS_LDV1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LDV1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LDV1__PORT == 15 && ((LDV1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LDV1_Write(uint8 value) ;
void    LDV1_SetDriveMode(uint8 mode) ;
uint8   LDV1_ReadDataReg(void) ;
uint8   LDV1_Read(void) ;
uint8   LDV1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LDV1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LDV1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LDV1_DM_RES_UP          PIN_DM_RES_UP
#define LDV1_DM_RES_DWN         PIN_DM_RES_DWN
#define LDV1_DM_OD_LO           PIN_DM_OD_LO
#define LDV1_DM_OD_HI           PIN_DM_OD_HI
#define LDV1_DM_STRONG          PIN_DM_STRONG
#define LDV1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LDV1_MASK               LDV1__MASK
#define LDV1_SHIFT              LDV1__SHIFT
#define LDV1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LDV1_PS                     (* (reg8 *) LDV1__PS)
/* Data Register */
#define LDV1_DR                     (* (reg8 *) LDV1__DR)
/* Port Number */
#define LDV1_PRT_NUM                (* (reg8 *) LDV1__PRT) 
/* Connect to Analog Globals */                                                  
#define LDV1_AG                     (* (reg8 *) LDV1__AG)                       
/* Analog MUX bux enable */
#define LDV1_AMUX                   (* (reg8 *) LDV1__AMUX) 
/* Bidirectional Enable */                                                        
#define LDV1_BIE                    (* (reg8 *) LDV1__BIE)
/* Bit-mask for Aliased Register Access */
#define LDV1_BIT_MASK               (* (reg8 *) LDV1__BIT_MASK)
/* Bypass Enable */
#define LDV1_BYP                    (* (reg8 *) LDV1__BYP)
/* Port wide control signals */                                                   
#define LDV1_CTL                    (* (reg8 *) LDV1__CTL)
/* Drive Modes */
#define LDV1_DM0                    (* (reg8 *) LDV1__DM0) 
#define LDV1_DM1                    (* (reg8 *) LDV1__DM1)
#define LDV1_DM2                    (* (reg8 *) LDV1__DM2) 
/* Input Buffer Disable Override */
#define LDV1_INP_DIS                (* (reg8 *) LDV1__INP_DIS)
/* LCD Common or Segment Drive */
#define LDV1_LCD_COM_SEG            (* (reg8 *) LDV1__LCD_COM_SEG)
/* Enable Segment LCD */
#define LDV1_LCD_EN                 (* (reg8 *) LDV1__LCD_EN)
/* Slew Rate Control */
#define LDV1_SLW                    (* (reg8 *) LDV1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LDV1_PRTDSI__CAPS_SEL       (* (reg8 *) LDV1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LDV1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LDV1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LDV1_PRTDSI__OE_SEL0        (* (reg8 *) LDV1__PRTDSI__OE_SEL0) 
#define LDV1_PRTDSI__OE_SEL1        (* (reg8 *) LDV1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LDV1_PRTDSI__OUT_SEL0       (* (reg8 *) LDV1__PRTDSI__OUT_SEL0) 
#define LDV1_PRTDSI__OUT_SEL1       (* (reg8 *) LDV1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LDV1_PRTDSI__SYNC_OUT       (* (reg8 *) LDV1__PRTDSI__SYNC_OUT) 


#if defined(LDV1__INTSTAT)  /* Interrupt Registers */

    #define LDV1_INTSTAT                (* (reg8 *) LDV1__INTSTAT)
    #define LDV1_SNAP                   (* (reg8 *) LDV1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LDV1_H */


/* [] END OF FILE */
