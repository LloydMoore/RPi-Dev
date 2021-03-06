/*******************************************************************************
* File Name: SpiXferDone.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_SpiXferDone_H)
#define CY_ISR_SpiXferDone_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SpiXferDone_Start(void);
void SpiXferDone_StartEx(cyisraddress address);
void SpiXferDone_Stop(void);

CY_ISR_PROTO(SpiXferDone_Interrupt);

void SpiXferDone_SetVector(cyisraddress address);
cyisraddress SpiXferDone_GetVector(void);

void SpiXferDone_SetPriority(uint8 priority);
uint8 SpiXferDone_GetPriority(void);

void SpiXferDone_Enable(void);
uint8 SpiXferDone_GetState(void);
void SpiXferDone_Disable(void);

void SpiXferDone_SetPending(void);
void SpiXferDone_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SpiXferDone ISR. */
#define SpiXferDone_INTC_VECTOR            ((reg32 *) SpiXferDone__INTC_VECT)

/* Address of the SpiXferDone ISR priority. */
#define SpiXferDone_INTC_PRIOR             ((reg8 *) SpiXferDone__INTC_PRIOR_REG)

/* Priority of the SpiXferDone interrupt. */
#define SpiXferDone_INTC_PRIOR_NUMBER      SpiXferDone__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SpiXferDone interrupt. */
#define SpiXferDone_INTC_SET_EN            ((reg32 *) SpiXferDone__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SpiXferDone interrupt. */
#define SpiXferDone_INTC_CLR_EN            ((reg32 *) SpiXferDone__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SpiXferDone interrupt state to pending. */
#define SpiXferDone_INTC_SET_PD            ((reg32 *) SpiXferDone__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SpiXferDone interrupt. */
#define SpiXferDone_INTC_CLR_PD            ((reg32 *) SpiXferDone__INTC_CLR_PD_REG)


#endif /* CY_ISR_SpiXferDone_H */


/* [] END OF FILE */
