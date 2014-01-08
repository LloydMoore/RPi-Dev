/*******************************************************************************
* File Name: SerDrv_RB.h  
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

#if !defined(CY_PINS_SerDrv_RB_H) /* Pins SerDrv_RB_H */
#define CY_PINS_SerDrv_RB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SerDrv_RB_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SerDrv_RB__PORT == 15 && ((SerDrv_RB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SerDrv_RB_Write(uint8 value) ;
void    SerDrv_RB_SetDriveMode(uint8 mode) ;
uint8   SerDrv_RB_ReadDataReg(void) ;
uint8   SerDrv_RB_Read(void) ;
uint8   SerDrv_RB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SerDrv_RB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SerDrv_RB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SerDrv_RB_DM_RES_UP          PIN_DM_RES_UP
#define SerDrv_RB_DM_RES_DWN         PIN_DM_RES_DWN
#define SerDrv_RB_DM_OD_LO           PIN_DM_OD_LO
#define SerDrv_RB_DM_OD_HI           PIN_DM_OD_HI
#define SerDrv_RB_DM_STRONG          PIN_DM_STRONG
#define SerDrv_RB_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SerDrv_RB_MASK               SerDrv_RB__MASK
#define SerDrv_RB_SHIFT              SerDrv_RB__SHIFT
#define SerDrv_RB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SerDrv_RB_PS                     (* (reg8 *) SerDrv_RB__PS)
/* Data Register */
#define SerDrv_RB_DR                     (* (reg8 *) SerDrv_RB__DR)
/* Port Number */
#define SerDrv_RB_PRT_NUM                (* (reg8 *) SerDrv_RB__PRT) 
/* Connect to Analog Globals */                                                  
#define SerDrv_RB_AG                     (* (reg8 *) SerDrv_RB__AG)                       
/* Analog MUX bux enable */
#define SerDrv_RB_AMUX                   (* (reg8 *) SerDrv_RB__AMUX) 
/* Bidirectional Enable */                                                        
#define SerDrv_RB_BIE                    (* (reg8 *) SerDrv_RB__BIE)
/* Bit-mask for Aliased Register Access */
#define SerDrv_RB_BIT_MASK               (* (reg8 *) SerDrv_RB__BIT_MASK)
/* Bypass Enable */
#define SerDrv_RB_BYP                    (* (reg8 *) SerDrv_RB__BYP)
/* Port wide control signals */                                                   
#define SerDrv_RB_CTL                    (* (reg8 *) SerDrv_RB__CTL)
/* Drive Modes */
#define SerDrv_RB_DM0                    (* (reg8 *) SerDrv_RB__DM0) 
#define SerDrv_RB_DM1                    (* (reg8 *) SerDrv_RB__DM1)
#define SerDrv_RB_DM2                    (* (reg8 *) SerDrv_RB__DM2) 
/* Input Buffer Disable Override */
#define SerDrv_RB_INP_DIS                (* (reg8 *) SerDrv_RB__INP_DIS)
/* LCD Common or Segment Drive */
#define SerDrv_RB_LCD_COM_SEG            (* (reg8 *) SerDrv_RB__LCD_COM_SEG)
/* Enable Segment LCD */
#define SerDrv_RB_LCD_EN                 (* (reg8 *) SerDrv_RB__LCD_EN)
/* Slew Rate Control */
#define SerDrv_RB_SLW                    (* (reg8 *) SerDrv_RB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SerDrv_RB_PRTDSI__CAPS_SEL       (* (reg8 *) SerDrv_RB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SerDrv_RB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SerDrv_RB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SerDrv_RB_PRTDSI__OE_SEL0        (* (reg8 *) SerDrv_RB__PRTDSI__OE_SEL0) 
#define SerDrv_RB_PRTDSI__OE_SEL1        (* (reg8 *) SerDrv_RB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SerDrv_RB_PRTDSI__OUT_SEL0       (* (reg8 *) SerDrv_RB__PRTDSI__OUT_SEL0) 
#define SerDrv_RB_PRTDSI__OUT_SEL1       (* (reg8 *) SerDrv_RB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SerDrv_RB_PRTDSI__SYNC_OUT       (* (reg8 *) SerDrv_RB__PRTDSI__SYNC_OUT) 


#if defined(SerDrv_RB__INTSTAT)  /* Interrupt Registers */

    #define SerDrv_RB_INTSTAT                (* (reg8 *) SerDrv_RB__INTSTAT)
    #define SerDrv_RB_SNAP                   (* (reg8 *) SerDrv_RB__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SerDrv_RB_H */


/* [] END OF FILE */
