/*******************************************************************************
* File Name: PiSPI_CLK.h
* Version 2.10
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_PiSPI_CLK_H)
#define CY_CLOCK_PiSPI_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void PiSPI_CLK_Start(void) ;
void PiSPI_CLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void PiSPI_CLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void PiSPI_CLK_StandbyPower(uint8 state) ;
void PiSPI_CLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 PiSPI_CLK_GetDividerRegister(void) ;
void PiSPI_CLK_SetModeRegister(uint8 modeBitMask) ;
void PiSPI_CLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 PiSPI_CLK_GetModeRegister(void) ;
void PiSPI_CLK_SetSourceRegister(uint8 clkSource) ;
uint8 PiSPI_CLK_GetSourceRegister(void) ;
#if defined(PiSPI_CLK__CFG3)
void PiSPI_CLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 PiSPI_CLK_GetPhaseRegister(void) ;
#endif /* defined(PiSPI_CLK__CFG3) */

#define PiSPI_CLK_Enable()                       PiSPI_CLK_Start()
#define PiSPI_CLK_Disable()                      PiSPI_CLK_Stop()
#define PiSPI_CLK_SetDivider(clkDivider)         PiSPI_CLK_SetDividerRegister(clkDivider, 1u)
#define PiSPI_CLK_SetDividerValue(clkDivider)    PiSPI_CLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define PiSPI_CLK_SetMode(clkMode)               PiSPI_CLK_SetModeRegister(clkMode)
#define PiSPI_CLK_SetSource(clkSource)           PiSPI_CLK_SetSourceRegister(clkSource)
#if defined(PiSPI_CLK__CFG3)
#define PiSPI_CLK_SetPhase(clkPhase)             PiSPI_CLK_SetPhaseRegister(clkPhase)
#define PiSPI_CLK_SetPhaseValue(clkPhase)        PiSPI_CLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(PiSPI_CLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define PiSPI_CLK_CLKEN              (* (reg8 *) PiSPI_CLK__PM_ACT_CFG)
#define PiSPI_CLK_CLKEN_PTR          ((reg8 *) PiSPI_CLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define PiSPI_CLK_CLKSTBY            (* (reg8 *) PiSPI_CLK__PM_STBY_CFG)
#define PiSPI_CLK_CLKSTBY_PTR        ((reg8 *) PiSPI_CLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define PiSPI_CLK_DIV_LSB            (* (reg8 *) PiSPI_CLK__CFG0)
#define PiSPI_CLK_DIV_LSB_PTR        ((reg8 *) PiSPI_CLK__CFG0)
#define PiSPI_CLK_DIV_PTR            ((reg16 *) PiSPI_CLK__CFG0)

/* Clock MSB divider configuration register. */
#define PiSPI_CLK_DIV_MSB            (* (reg8 *) PiSPI_CLK__CFG1)
#define PiSPI_CLK_DIV_MSB_PTR        ((reg8 *) PiSPI_CLK__CFG1)

/* Mode and source configuration register */
#define PiSPI_CLK_MOD_SRC            (* (reg8 *) PiSPI_CLK__CFG2)
#define PiSPI_CLK_MOD_SRC_PTR        ((reg8 *) PiSPI_CLK__CFG2)

#if defined(PiSPI_CLK__CFG3)
/* Analog clock phase configuration register */
#define PiSPI_CLK_PHASE              (* (reg8 *) PiSPI_CLK__CFG3)
#define PiSPI_CLK_PHASE_PTR          ((reg8 *) PiSPI_CLK__CFG3)
#endif /* defined(PiSPI_CLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define PiSPI_CLK_CLKEN_MASK         PiSPI_CLK__PM_ACT_MSK
#define PiSPI_CLK_CLKSTBY_MASK       PiSPI_CLK__PM_STBY_MSK

/* CFG2 field masks */
#define PiSPI_CLK_SRC_SEL_MSK        PiSPI_CLK__CFG2_SRC_SEL_MASK
#define PiSPI_CLK_MODE_MASK          (~(PiSPI_CLK_SRC_SEL_MSK))

#if defined(PiSPI_CLK__CFG3)
/* CFG3 phase mask */
#define PiSPI_CLK_PHASE_MASK         PiSPI_CLK__CFG3_PHASE_DLY_MASK
#endif /* defined(PiSPI_CLK__CFG3) */

#endif /* CY_CLOCK_PiSPI_CLK_H */


/* [] END OF FILE */
