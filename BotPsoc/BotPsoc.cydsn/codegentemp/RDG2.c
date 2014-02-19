/*******************************************************************************
* File Name: RDG2.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "RDG2.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 RDG2__PORT == 15 && ((RDG2__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: RDG2_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void RDG2_Write(uint8 value) 
{
    uint8 staticBits = (RDG2_DR & (uint8)(~RDG2_MASK));
    RDG2_DR = staticBits | ((uint8)(value << RDG2_SHIFT) & RDG2_MASK);
}


/*******************************************************************************
* Function Name: RDG2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void RDG2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(RDG2_0, mode);
}


/*******************************************************************************
* Function Name: RDG2_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro RDG2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RDG2_Read(void) 
{
    return (RDG2_PS & RDG2_MASK) >> RDG2_SHIFT;
}


/*******************************************************************************
* Function Name: RDG2_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 RDG2_ReadDataReg(void) 
{
    return (RDG2_DR & RDG2_MASK) >> RDG2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RDG2_INTSTAT) 

    /*******************************************************************************
    * Function Name: RDG2_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 RDG2_ClearInterrupt(void) 
    {
        return (RDG2_INTSTAT & RDG2_MASK) >> RDG2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */