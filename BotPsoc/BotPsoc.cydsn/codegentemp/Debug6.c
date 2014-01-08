/*******************************************************************************
* File Name: Debug6.c  
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
#include "Debug6.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Debug6__PORT == 15 && ((Debug6__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Debug6_Write
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
void Debug6_Write(uint8 value) 
{
    uint8 staticBits = (Debug6_DR & (uint8)(~Debug6_MASK));
    Debug6_DR = staticBits | ((uint8)(value << Debug6_SHIFT) & Debug6_MASK);
}


/*******************************************************************************
* Function Name: Debug6_SetDriveMode
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
void Debug6_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Debug6_0, mode);
}


/*******************************************************************************
* Function Name: Debug6_Read
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
*  Macro Debug6_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Debug6_Read(void) 
{
    return (Debug6_PS & Debug6_MASK) >> Debug6_SHIFT;
}


/*******************************************************************************
* Function Name: Debug6_ReadDataReg
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
uint8 Debug6_ReadDataReg(void) 
{
    return (Debug6_DR & Debug6_MASK) >> Debug6_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Debug6_INTSTAT) 

    /*******************************************************************************
    * Function Name: Debug6_ClearInterrupt
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
    uint8 Debug6_ClearInterrupt(void) 
    {
        return (Debug6_INTSTAT & Debug6_MASK) >> Debug6_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
