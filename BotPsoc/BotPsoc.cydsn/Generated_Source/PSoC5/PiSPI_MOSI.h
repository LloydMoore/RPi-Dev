/*******************************************************************************
* File Name: PiSPI_MOSI.h  
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

#if !defined(CY_PINS_PiSPI_MOSI_H) /* Pins PiSPI_MOSI_H */
#define CY_PINS_PiSPI_MOSI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PiSPI_MOSI_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PiSPI_MOSI__PORT == 15 && ((PiSPI_MOSI__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PiSPI_MOSI_Write(uint8 value) ;
void    PiSPI_MOSI_SetDriveMode(uint8 mode) ;
uint8   PiSPI_MOSI_ReadDataReg(void) ;
uint8   PiSPI_MOSI_Read(void) ;
uint8   PiSPI_MOSI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PiSPI_MOSI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PiSPI_MOSI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PiSPI_MOSI_DM_RES_UP          PIN_DM_RES_UP
#define PiSPI_MOSI_DM_RES_DWN         PIN_DM_RES_DWN
#define PiSPI_MOSI_DM_OD_LO           PIN_DM_OD_LO
#define PiSPI_MOSI_DM_OD_HI           PIN_DM_OD_HI
#define PiSPI_MOSI_DM_STRONG          PIN_DM_STRONG
#define PiSPI_MOSI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PiSPI_MOSI_MASK               PiSPI_MOSI__MASK
#define PiSPI_MOSI_SHIFT              PiSPI_MOSI__SHIFT
#define PiSPI_MOSI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PiSPI_MOSI_PS                     (* (reg8 *) PiSPI_MOSI__PS)
/* Data Register */
#define PiSPI_MOSI_DR                     (* (reg8 *) PiSPI_MOSI__DR)
/* Port Number */
#define PiSPI_MOSI_PRT_NUM                (* (reg8 *) PiSPI_MOSI__PRT) 
/* Connect to Analog Globals */                                                  
#define PiSPI_MOSI_AG                     (* (reg8 *) PiSPI_MOSI__AG)                       
/* Analog MUX bux enable */
#define PiSPI_MOSI_AMUX                   (* (reg8 *) PiSPI_MOSI__AMUX) 
/* Bidirectional Enable */                                                        
#define PiSPI_MOSI_BIE                    (* (reg8 *) PiSPI_MOSI__BIE)
/* Bit-mask for Aliased Register Access */
#define PiSPI_MOSI_BIT_MASK               (* (reg8 *) PiSPI_MOSI__BIT_MASK)
/* Bypass Enable */
#define PiSPI_MOSI_BYP                    (* (reg8 *) PiSPI_MOSI__BYP)
/* Port wide control signals */                                                   
#define PiSPI_MOSI_CTL                    (* (reg8 *) PiSPI_MOSI__CTL)
/* Drive Modes */
#define PiSPI_MOSI_DM0                    (* (reg8 *) PiSPI_MOSI__DM0) 
#define PiSPI_MOSI_DM1                    (* (reg8 *) PiSPI_MOSI__DM1)
#define PiSPI_MOSI_DM2                    (* (reg8 *) PiSPI_MOSI__DM2) 
/* Input Buffer Disable Override */
#define PiSPI_MOSI_INP_DIS                (* (reg8 *) PiSPI_MOSI__INP_DIS)
/* LCD Common or Segment Drive */
#define PiSPI_MOSI_LCD_COM_SEG            (* (reg8 *) PiSPI_MOSI__LCD_COM_SEG)
/* Enable Segment LCD */
#define PiSPI_MOSI_LCD_EN                 (* (reg8 *) PiSPI_MOSI__LCD_EN)
/* Slew Rate Control */
#define PiSPI_MOSI_SLW                    (* (reg8 *) PiSPI_MOSI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PiSPI_MOSI_PRTDSI__CAPS_SEL       (* (reg8 *) PiSPI_MOSI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PiSPI_MOSI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PiSPI_MOSI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PiSPI_MOSI_PRTDSI__OE_SEL0        (* (reg8 *) PiSPI_MOSI__PRTDSI__OE_SEL0) 
#define PiSPI_MOSI_PRTDSI__OE_SEL1        (* (reg8 *) PiSPI_MOSI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PiSPI_MOSI_PRTDSI__OUT_SEL0       (* (reg8 *) PiSPI_MOSI__PRTDSI__OUT_SEL0) 
#define PiSPI_MOSI_PRTDSI__OUT_SEL1       (* (reg8 *) PiSPI_MOSI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PiSPI_MOSI_PRTDSI__SYNC_OUT       (* (reg8 *) PiSPI_MOSI__PRTDSI__SYNC_OUT) 


#if defined(PiSPI_MOSI__INTSTAT)  /* Interrupt Registers */

    #define PiSPI_MOSI_INTSTAT                (* (reg8 *) PiSPI_MOSI__INTSTAT)
    #define PiSPI_MOSI_SNAP                   (* (reg8 *) PiSPI_MOSI__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PiSPI_MOSI_H */


/* [] END OF FILE */
