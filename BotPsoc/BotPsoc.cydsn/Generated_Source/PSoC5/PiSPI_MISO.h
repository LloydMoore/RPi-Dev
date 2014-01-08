/*******************************************************************************
* File Name: PiSPI_MISO.h  
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

#if !defined(CY_PINS_PiSPI_MISO_H) /* Pins PiSPI_MISO_H */
#define CY_PINS_PiSPI_MISO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PiSPI_MISO_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PiSPI_MISO__PORT == 15 && ((PiSPI_MISO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PiSPI_MISO_Write(uint8 value) ;
void    PiSPI_MISO_SetDriveMode(uint8 mode) ;
uint8   PiSPI_MISO_ReadDataReg(void) ;
uint8   PiSPI_MISO_Read(void) ;
uint8   PiSPI_MISO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PiSPI_MISO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PiSPI_MISO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PiSPI_MISO_DM_RES_UP          PIN_DM_RES_UP
#define PiSPI_MISO_DM_RES_DWN         PIN_DM_RES_DWN
#define PiSPI_MISO_DM_OD_LO           PIN_DM_OD_LO
#define PiSPI_MISO_DM_OD_HI           PIN_DM_OD_HI
#define PiSPI_MISO_DM_STRONG          PIN_DM_STRONG
#define PiSPI_MISO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PiSPI_MISO_MASK               PiSPI_MISO__MASK
#define PiSPI_MISO_SHIFT              PiSPI_MISO__SHIFT
#define PiSPI_MISO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PiSPI_MISO_PS                     (* (reg8 *) PiSPI_MISO__PS)
/* Data Register */
#define PiSPI_MISO_DR                     (* (reg8 *) PiSPI_MISO__DR)
/* Port Number */
#define PiSPI_MISO_PRT_NUM                (* (reg8 *) PiSPI_MISO__PRT) 
/* Connect to Analog Globals */                                                  
#define PiSPI_MISO_AG                     (* (reg8 *) PiSPI_MISO__AG)                       
/* Analog MUX bux enable */
#define PiSPI_MISO_AMUX                   (* (reg8 *) PiSPI_MISO__AMUX) 
/* Bidirectional Enable */                                                        
#define PiSPI_MISO_BIE                    (* (reg8 *) PiSPI_MISO__BIE)
/* Bit-mask for Aliased Register Access */
#define PiSPI_MISO_BIT_MASK               (* (reg8 *) PiSPI_MISO__BIT_MASK)
/* Bypass Enable */
#define PiSPI_MISO_BYP                    (* (reg8 *) PiSPI_MISO__BYP)
/* Port wide control signals */                                                   
#define PiSPI_MISO_CTL                    (* (reg8 *) PiSPI_MISO__CTL)
/* Drive Modes */
#define PiSPI_MISO_DM0                    (* (reg8 *) PiSPI_MISO__DM0) 
#define PiSPI_MISO_DM1                    (* (reg8 *) PiSPI_MISO__DM1)
#define PiSPI_MISO_DM2                    (* (reg8 *) PiSPI_MISO__DM2) 
/* Input Buffer Disable Override */
#define PiSPI_MISO_INP_DIS                (* (reg8 *) PiSPI_MISO__INP_DIS)
/* LCD Common or Segment Drive */
#define PiSPI_MISO_LCD_COM_SEG            (* (reg8 *) PiSPI_MISO__LCD_COM_SEG)
/* Enable Segment LCD */
#define PiSPI_MISO_LCD_EN                 (* (reg8 *) PiSPI_MISO__LCD_EN)
/* Slew Rate Control */
#define PiSPI_MISO_SLW                    (* (reg8 *) PiSPI_MISO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PiSPI_MISO_PRTDSI__CAPS_SEL       (* (reg8 *) PiSPI_MISO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PiSPI_MISO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PiSPI_MISO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PiSPI_MISO_PRTDSI__OE_SEL0        (* (reg8 *) PiSPI_MISO__PRTDSI__OE_SEL0) 
#define PiSPI_MISO_PRTDSI__OE_SEL1        (* (reg8 *) PiSPI_MISO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PiSPI_MISO_PRTDSI__OUT_SEL0       (* (reg8 *) PiSPI_MISO__PRTDSI__OUT_SEL0) 
#define PiSPI_MISO_PRTDSI__OUT_SEL1       (* (reg8 *) PiSPI_MISO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PiSPI_MISO_PRTDSI__SYNC_OUT       (* (reg8 *) PiSPI_MISO__PRTDSI__SYNC_OUT) 


#if defined(PiSPI_MISO__INTSTAT)  /* Interrupt Registers */

    #define PiSPI_MISO_INTSTAT                (* (reg8 *) PiSPI_MISO__INTSTAT)
    #define PiSPI_MISO_SNAP                   (* (reg8 *) PiSPI_MISO__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PiSPI_MISO_H */


/* [] END OF FILE */
