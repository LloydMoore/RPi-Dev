/*******************************************************************************
* File Name: RDG1.h  
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

#if !defined(CY_PINS_RDG1_H) /* Pins RDG1_H */
#define CY_PINS_RDG1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RDG1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RDG1__PORT == 15 && ((RDG1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RDG1_Write(uint8 value) ;
void    RDG1_SetDriveMode(uint8 mode) ;
uint8   RDG1_ReadDataReg(void) ;
uint8   RDG1_Read(void) ;
uint8   RDG1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RDG1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RDG1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RDG1_DM_RES_UP          PIN_DM_RES_UP
#define RDG1_DM_RES_DWN         PIN_DM_RES_DWN
#define RDG1_DM_OD_LO           PIN_DM_OD_LO
#define RDG1_DM_OD_HI           PIN_DM_OD_HI
#define RDG1_DM_STRONG          PIN_DM_STRONG
#define RDG1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RDG1_MASK               RDG1__MASK
#define RDG1_SHIFT              RDG1__SHIFT
#define RDG1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RDG1_PS                     (* (reg8 *) RDG1__PS)
/* Data Register */
#define RDG1_DR                     (* (reg8 *) RDG1__DR)
/* Port Number */
#define RDG1_PRT_NUM                (* (reg8 *) RDG1__PRT) 
/* Connect to Analog Globals */                                                  
#define RDG1_AG                     (* (reg8 *) RDG1__AG)                       
/* Analog MUX bux enable */
#define RDG1_AMUX                   (* (reg8 *) RDG1__AMUX) 
/* Bidirectional Enable */                                                        
#define RDG1_BIE                    (* (reg8 *) RDG1__BIE)
/* Bit-mask for Aliased Register Access */
#define RDG1_BIT_MASK               (* (reg8 *) RDG1__BIT_MASK)
/* Bypass Enable */
#define RDG1_BYP                    (* (reg8 *) RDG1__BYP)
/* Port wide control signals */                                                   
#define RDG1_CTL                    (* (reg8 *) RDG1__CTL)
/* Drive Modes */
#define RDG1_DM0                    (* (reg8 *) RDG1__DM0) 
#define RDG1_DM1                    (* (reg8 *) RDG1__DM1)
#define RDG1_DM2                    (* (reg8 *) RDG1__DM2) 
/* Input Buffer Disable Override */
#define RDG1_INP_DIS                (* (reg8 *) RDG1__INP_DIS)
/* LCD Common or Segment Drive */
#define RDG1_LCD_COM_SEG            (* (reg8 *) RDG1__LCD_COM_SEG)
/* Enable Segment LCD */
#define RDG1_LCD_EN                 (* (reg8 *) RDG1__LCD_EN)
/* Slew Rate Control */
#define RDG1_SLW                    (* (reg8 *) RDG1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RDG1_PRTDSI__CAPS_SEL       (* (reg8 *) RDG1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RDG1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RDG1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RDG1_PRTDSI__OE_SEL0        (* (reg8 *) RDG1__PRTDSI__OE_SEL0) 
#define RDG1_PRTDSI__OE_SEL1        (* (reg8 *) RDG1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RDG1_PRTDSI__OUT_SEL0       (* (reg8 *) RDG1__PRTDSI__OUT_SEL0) 
#define RDG1_PRTDSI__OUT_SEL1       (* (reg8 *) RDG1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RDG1_PRTDSI__SYNC_OUT       (* (reg8 *) RDG1__PRTDSI__SYNC_OUT) 


#if defined(RDG1__INTSTAT)  /* Interrupt Registers */

    #define RDG1_INTSTAT                (* (reg8 *) RDG1__INTSTAT)
    #define RDG1_SNAP                   (* (reg8 *) RDG1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RDG1_H */


/* [] END OF FILE */
