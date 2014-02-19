/*******************************************************************************
* File Name: Debug5.h  
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

#if !defined(CY_PINS_Debug5_H) /* Pins Debug5_H */
#define CY_PINS_Debug5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Debug5_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Debug5__PORT == 15 && ((Debug5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Debug5_Write(uint8 value) ;
void    Debug5_SetDriveMode(uint8 mode) ;
uint8   Debug5_ReadDataReg(void) ;
uint8   Debug5_Read(void) ;
uint8   Debug5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Debug5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Debug5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Debug5_DM_RES_UP          PIN_DM_RES_UP
#define Debug5_DM_RES_DWN         PIN_DM_RES_DWN
#define Debug5_DM_OD_LO           PIN_DM_OD_LO
#define Debug5_DM_OD_HI           PIN_DM_OD_HI
#define Debug5_DM_STRONG          PIN_DM_STRONG
#define Debug5_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Debug5_MASK               Debug5__MASK
#define Debug5_SHIFT              Debug5__SHIFT
#define Debug5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Debug5_PS                     (* (reg8 *) Debug5__PS)
/* Data Register */
#define Debug5_DR                     (* (reg8 *) Debug5__DR)
/* Port Number */
#define Debug5_PRT_NUM                (* (reg8 *) Debug5__PRT) 
/* Connect to Analog Globals */                                                  
#define Debug5_AG                     (* (reg8 *) Debug5__AG)                       
/* Analog MUX bux enable */
#define Debug5_AMUX                   (* (reg8 *) Debug5__AMUX) 
/* Bidirectional Enable */                                                        
#define Debug5_BIE                    (* (reg8 *) Debug5__BIE)
/* Bit-mask for Aliased Register Access */
#define Debug5_BIT_MASK               (* (reg8 *) Debug5__BIT_MASK)
/* Bypass Enable */
#define Debug5_BYP                    (* (reg8 *) Debug5__BYP)
/* Port wide control signals */                                                   
#define Debug5_CTL                    (* (reg8 *) Debug5__CTL)
/* Drive Modes */
#define Debug5_DM0                    (* (reg8 *) Debug5__DM0) 
#define Debug5_DM1                    (* (reg8 *) Debug5__DM1)
#define Debug5_DM2                    (* (reg8 *) Debug5__DM2) 
/* Input Buffer Disable Override */
#define Debug5_INP_DIS                (* (reg8 *) Debug5__INP_DIS)
/* LCD Common or Segment Drive */
#define Debug5_LCD_COM_SEG            (* (reg8 *) Debug5__LCD_COM_SEG)
/* Enable Segment LCD */
#define Debug5_LCD_EN                 (* (reg8 *) Debug5__LCD_EN)
/* Slew Rate Control */
#define Debug5_SLW                    (* (reg8 *) Debug5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Debug5_PRTDSI__CAPS_SEL       (* (reg8 *) Debug5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Debug5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Debug5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Debug5_PRTDSI__OE_SEL0        (* (reg8 *) Debug5__PRTDSI__OE_SEL0) 
#define Debug5_PRTDSI__OE_SEL1        (* (reg8 *) Debug5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Debug5_PRTDSI__OUT_SEL0       (* (reg8 *) Debug5__PRTDSI__OUT_SEL0) 
#define Debug5_PRTDSI__OUT_SEL1       (* (reg8 *) Debug5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Debug5_PRTDSI__SYNC_OUT       (* (reg8 *) Debug5__PRTDSI__SYNC_OUT) 


#if defined(Debug5__INTSTAT)  /* Interrupt Registers */

    #define Debug5_INTSTAT                (* (reg8 *) Debug5__INTSTAT)
    #define Debug5_SNAP                   (* (reg8 *) Debug5__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Debug5_H */


/* [] END OF FILE */
