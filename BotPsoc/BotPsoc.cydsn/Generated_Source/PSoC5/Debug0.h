/*******************************************************************************
* File Name: Debug0.h  
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

#if !defined(CY_PINS_Debug0_H) /* Pins Debug0_H */
#define CY_PINS_Debug0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Debug0_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Debug0__PORT == 15 && ((Debug0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Debug0_Write(uint8 value) ;
void    Debug0_SetDriveMode(uint8 mode) ;
uint8   Debug0_ReadDataReg(void) ;
uint8   Debug0_Read(void) ;
uint8   Debug0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Debug0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Debug0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Debug0_DM_RES_UP          PIN_DM_RES_UP
#define Debug0_DM_RES_DWN         PIN_DM_RES_DWN
#define Debug0_DM_OD_LO           PIN_DM_OD_LO
#define Debug0_DM_OD_HI           PIN_DM_OD_HI
#define Debug0_DM_STRONG          PIN_DM_STRONG
#define Debug0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Debug0_MASK               Debug0__MASK
#define Debug0_SHIFT              Debug0__SHIFT
#define Debug0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Debug0_PS                     (* (reg8 *) Debug0__PS)
/* Data Register */
#define Debug0_DR                     (* (reg8 *) Debug0__DR)
/* Port Number */
#define Debug0_PRT_NUM                (* (reg8 *) Debug0__PRT) 
/* Connect to Analog Globals */                                                  
#define Debug0_AG                     (* (reg8 *) Debug0__AG)                       
/* Analog MUX bux enable */
#define Debug0_AMUX                   (* (reg8 *) Debug0__AMUX) 
/* Bidirectional Enable */                                                        
#define Debug0_BIE                    (* (reg8 *) Debug0__BIE)
/* Bit-mask for Aliased Register Access */
#define Debug0_BIT_MASK               (* (reg8 *) Debug0__BIT_MASK)
/* Bypass Enable */
#define Debug0_BYP                    (* (reg8 *) Debug0__BYP)
/* Port wide control signals */                                                   
#define Debug0_CTL                    (* (reg8 *) Debug0__CTL)
/* Drive Modes */
#define Debug0_DM0                    (* (reg8 *) Debug0__DM0) 
#define Debug0_DM1                    (* (reg8 *) Debug0__DM1)
#define Debug0_DM2                    (* (reg8 *) Debug0__DM2) 
/* Input Buffer Disable Override */
#define Debug0_INP_DIS                (* (reg8 *) Debug0__INP_DIS)
/* LCD Common or Segment Drive */
#define Debug0_LCD_COM_SEG            (* (reg8 *) Debug0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Debug0_LCD_EN                 (* (reg8 *) Debug0__LCD_EN)
/* Slew Rate Control */
#define Debug0_SLW                    (* (reg8 *) Debug0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Debug0_PRTDSI__CAPS_SEL       (* (reg8 *) Debug0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Debug0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Debug0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Debug0_PRTDSI__OE_SEL0        (* (reg8 *) Debug0__PRTDSI__OE_SEL0) 
#define Debug0_PRTDSI__OE_SEL1        (* (reg8 *) Debug0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Debug0_PRTDSI__OUT_SEL0       (* (reg8 *) Debug0__PRTDSI__OUT_SEL0) 
#define Debug0_PRTDSI__OUT_SEL1       (* (reg8 *) Debug0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Debug0_PRTDSI__SYNC_OUT       (* (reg8 *) Debug0__PRTDSI__SYNC_OUT) 


#if defined(Debug0__INTSTAT)  /* Interrupt Registers */

    #define Debug0_INTSTAT                (* (reg8 *) Debug0__INTSTAT)
    #define Debug0_SNAP                   (* (reg8 *) Debug0__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Debug0_H */


/* [] END OF FILE */
