/*******************************************************************************
* File Name: MotorPwmClock.h
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

#if !defined(CY_CLOCK_MotorPwmClock_H)
#define CY_CLOCK_MotorPwmClock_H

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

void MotorPwmClock_Start(void) ;
void MotorPwmClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void MotorPwmClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void MotorPwmClock_StandbyPower(uint8 state) ;
void MotorPwmClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 MotorPwmClock_GetDividerRegister(void) ;
void MotorPwmClock_SetModeRegister(uint8 modeBitMask) ;
void MotorPwmClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 MotorPwmClock_GetModeRegister(void) ;
void MotorPwmClock_SetSourceRegister(uint8 clkSource) ;
uint8 MotorPwmClock_GetSourceRegister(void) ;
#if defined(MotorPwmClock__CFG3)
void MotorPwmClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 MotorPwmClock_GetPhaseRegister(void) ;
#endif /* defined(MotorPwmClock__CFG3) */

#define MotorPwmClock_Enable()                       MotorPwmClock_Start()
#define MotorPwmClock_Disable()                      MotorPwmClock_Stop()
#define MotorPwmClock_SetDivider(clkDivider)         MotorPwmClock_SetDividerRegister(clkDivider, 1u)
#define MotorPwmClock_SetDividerValue(clkDivider)    MotorPwmClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define MotorPwmClock_SetMode(clkMode)               MotorPwmClock_SetModeRegister(clkMode)
#define MotorPwmClock_SetSource(clkSource)           MotorPwmClock_SetSourceRegister(clkSource)
#if defined(MotorPwmClock__CFG3)
#define MotorPwmClock_SetPhase(clkPhase)             MotorPwmClock_SetPhaseRegister(clkPhase)
#define MotorPwmClock_SetPhaseValue(clkPhase)        MotorPwmClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(MotorPwmClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define MotorPwmClock_CLKEN              (* (reg8 *) MotorPwmClock__PM_ACT_CFG)
#define MotorPwmClock_CLKEN_PTR          ((reg8 *) MotorPwmClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define MotorPwmClock_CLKSTBY            (* (reg8 *) MotorPwmClock__PM_STBY_CFG)
#define MotorPwmClock_CLKSTBY_PTR        ((reg8 *) MotorPwmClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define MotorPwmClock_DIV_LSB            (* (reg8 *) MotorPwmClock__CFG0)
#define MotorPwmClock_DIV_LSB_PTR        ((reg8 *) MotorPwmClock__CFG0)
#define MotorPwmClock_DIV_PTR            ((reg16 *) MotorPwmClock__CFG0)

/* Clock MSB divider configuration register. */
#define MotorPwmClock_DIV_MSB            (* (reg8 *) MotorPwmClock__CFG1)
#define MotorPwmClock_DIV_MSB_PTR        ((reg8 *) MotorPwmClock__CFG1)

/* Mode and source configuration register */
#define MotorPwmClock_MOD_SRC            (* (reg8 *) MotorPwmClock__CFG2)
#define MotorPwmClock_MOD_SRC_PTR        ((reg8 *) MotorPwmClock__CFG2)

#if defined(MotorPwmClock__CFG3)
/* Analog clock phase configuration register */
#define MotorPwmClock_PHASE              (* (reg8 *) MotorPwmClock__CFG3)
#define MotorPwmClock_PHASE_PTR          ((reg8 *) MotorPwmClock__CFG3)
#endif /* defined(MotorPwmClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define MotorPwmClock_CLKEN_MASK         MotorPwmClock__PM_ACT_MSK
#define MotorPwmClock_CLKSTBY_MASK       MotorPwmClock__PM_STBY_MSK

/* CFG2 field masks */
#define MotorPwmClock_SRC_SEL_MSK        MotorPwmClock__CFG2_SRC_SEL_MASK
#define MotorPwmClock_MODE_MASK          (~(MotorPwmClock_SRC_SEL_MSK))

#if defined(MotorPwmClock__CFG3)
/* CFG3 phase mask */
#define MotorPwmClock_PHASE_MASK         MotorPwmClock__CFG3_PHASE_DLY_MASK
#endif /* defined(MotorPwmClock__CFG3) */

#endif /* CY_CLOCK_MotorPwmClock_H */


/* [] END OF FILE */
