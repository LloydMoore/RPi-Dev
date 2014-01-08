/*******************************************************************************
* File Name: RDG2.h  
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

#if !defined(CY_PINS_RDG2_H) /* Pins RDG2_H */
#define CY_PINS_RDG2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RDG2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RDG2__PORT == 15 && ((RDG2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RDG2_Write(uint8 value) ;
void    RDG2_SetDriveMode(uint8 mode) ;
uint8   RDG2_ReadDataReg(void) ;
uint8   RDG2_Read(void) ;
uint8   RDG2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RDG2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RDG2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RDG2_DM_RES_UP          PIN_DM_RES_UP
#define RDG2_DM_RES_DWN         PIN_DM_RES_DWN
#define RDG2_DM_OD_LO           PIN_DM_OD_LO
#define RDG2_DM_OD_HI           PIN_DM_OD_HI
#define RDG2_DM_STRONG          PIN_DM_STRONG
#define RDG2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RDG2_MASK               RDG2__MASK
#define RDG2_SHIFT              RDG2__SHIFT
#define RDG2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RDG2_PS                     (* (reg8 *) RDG2__PS)
/* Data Register */
#define RDG2_DR                     (* (reg8 *) RDG2__DR)
/* Port Number */
#define RDG2_PRT_NUM                (* (reg8 *) RDG2__PRT) 
/* Connect to Analog Globals */                                                  
#define RDG2_AG                     (* (reg8 *) RDG2__AG)                       
/* Analog MUX bux enable */
#define RDG2_AMUX                   (* (reg8 *) RDG2__AMUX) 
/* Bidirectional Enable */                                                        
#define RDG2_BIE                    (* (reg8 *) RDG2__BIE)
/* Bit-mask for Aliased Register Access */
#define RDG2_BIT_MASK               (* (reg8 *) RDG2__BIT_MASK)
/* Bypass Enable */
#define RDG2_BYP                    (* (reg8 *) RDG2__BYP)
/* Port wide control signals */                                                   
#define RDG2_CTL                    (* (reg8 *) RDG2__CTL)
/* Drive Modes */
#define RDG2_DM0                    (* (reg8 *) RDG2__DM0) 
#define RDG2_DM1                    (* (reg8 *) RDG2__DM1)
#define RDG2_DM2                    (* (reg8 *) RDG2__DM2) 
/* Input Buffer Disable Override */
#define RDG2_INP_DIS                (* (reg8 *) RDG2__INP_DIS)
/* LCD Common or Segment Drive */
#define RDG2_LCD_COM_SEG            (* (reg8 *) RDG2__LCD_COM_SEG)
/* Enable Segment LCD */
#define RDG2_LCD_EN                 (* (reg8 *) RDG2__LCD_EN)
/* Slew Rate Control */
#define RDG2_SLW                    (* (reg8 *) RDG2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RDG2_PRTDSI__CAPS_SEL       (* (reg8 *) RDG2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RDG2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RDG2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RDG2_PRTDSI__OE_SEL0        (* (reg8 *) RDG2__PRTDSI__OE_SEL0) 
#define RDG2_PRTDSI__OE_SEL1        (* (reg8 *) RDG2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RDG2_PRTDSI__OUT_SEL0       (* (reg8 *) RDG2__PRTDSI__OUT_SEL0) 
#define RDG2_PRTDSI__OUT_SEL1       (* (reg8 *) RDG2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RDG2_PRTDSI__SYNC_OUT       (* (reg8 *) RDG2__PRTDSI__SYNC_OUT) 


#if defined(RDG2__INTSTAT)  /* Interrupt Registers */

    #define RDG2_INTSTAT                (* (reg8 *) RDG2__INTSTAT)
    #define RDG2_SNAP                   (* (reg8 *) RDG2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RDG2_H */


/* [] END OF FILE */
