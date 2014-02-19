/*******************************************************************************
* File Name: Debug2.h  
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

#if !defined(CY_PINS_Debug2_H) /* Pins Debug2_H */
#define CY_PINS_Debug2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Debug2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Debug2__PORT == 15 && ((Debug2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Debug2_Write(uint8 value) ;
void    Debug2_SetDriveMode(uint8 mode) ;
uint8   Debug2_ReadDataReg(void) ;
uint8   Debug2_Read(void) ;
uint8   Debug2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Debug2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Debug2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Debug2_DM_RES_UP          PIN_DM_RES_UP
#define Debug2_DM_RES_DWN         PIN_DM_RES_DWN
#define Debug2_DM_OD_LO           PIN_DM_OD_LO
#define Debug2_DM_OD_HI           PIN_DM_OD_HI
#define Debug2_DM_STRONG          PIN_DM_STRONG
#define Debug2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Debug2_MASK               Debug2__MASK
#define Debug2_SHIFT              Debug2__SHIFT
#define Debug2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Debug2_PS                     (* (reg8 *) Debug2__PS)
/* Data Register */
#define Debug2_DR                     (* (reg8 *) Debug2__DR)
/* Port Number */
#define Debug2_PRT_NUM                (* (reg8 *) Debug2__PRT) 
/* Connect to Analog Globals */                                                  
#define Debug2_AG                     (* (reg8 *) Debug2__AG)                       
/* Analog MUX bux enable */
#define Debug2_AMUX                   (* (reg8 *) Debug2__AMUX) 
/* Bidirectional Enable */                                                        
#define Debug2_BIE                    (* (reg8 *) Debug2__BIE)
/* Bit-mask for Aliased Register Access */
#define Debug2_BIT_MASK               (* (reg8 *) Debug2__BIT_MASK)
/* Bypass Enable */
#define Debug2_BYP                    (* (reg8 *) Debug2__BYP)
/* Port wide control signals */                                                   
#define Debug2_CTL                    (* (reg8 *) Debug2__CTL)
/* Drive Modes */
#define Debug2_DM0                    (* (reg8 *) Debug2__DM0) 
#define Debug2_DM1                    (* (reg8 *) Debug2__DM1)
#define Debug2_DM2                    (* (reg8 *) Debug2__DM2) 
/* Input Buffer Disable Override */
#define Debug2_INP_DIS                (* (reg8 *) Debug2__INP_DIS)
/* LCD Common or Segment Drive */
#define Debug2_LCD_COM_SEG            (* (reg8 *) Debug2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Debug2_LCD_EN                 (* (reg8 *) Debug2__LCD_EN)
/* Slew Rate Control */
#define Debug2_SLW                    (* (reg8 *) Debug2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Debug2_PRTDSI__CAPS_SEL       (* (reg8 *) Debug2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Debug2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Debug2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Debug2_PRTDSI__OE_SEL0        (* (reg8 *) Debug2__PRTDSI__OE_SEL0) 
#define Debug2_PRTDSI__OE_SEL1        (* (reg8 *) Debug2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Debug2_PRTDSI__OUT_SEL0       (* (reg8 *) Debug2__PRTDSI__OUT_SEL0) 
#define Debug2_PRTDSI__OUT_SEL1       (* (reg8 *) Debug2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Debug2_PRTDSI__SYNC_OUT       (* (reg8 *) Debug2__PRTDSI__SYNC_OUT) 


#if defined(Debug2__INTSTAT)  /* Interrupt Registers */

    #define Debug2_INTSTAT                (* (reg8 *) Debug2__INTSTAT)
    #define Debug2_SNAP                   (* (reg8 *) Debug2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Debug2_H */


/* [] END OF FILE */
