/*******************************************************************************
* File Name: Debug5.c  
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
#include "Debug5.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Debug5__PORT == 15 && ((Debug5__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Debug5_Write
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
void Debug5_Write(uint8 value) 
{
    uint8 staticBits = (Debug5_DR & (uint8)(~Debug5_MASK));
    Debug5_DR = staticBits | ((uint8)(value << Debug5_SHIFT) & Debug5_MASK);
}


/*******************************************************************************
* Function Name: Debug5_SetDriveMode
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
void Debug5_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Debug5_0, mode);
}


/*******************************************************************************
* Function Name: Debug5_Read
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
*  Macro Debug5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Debug5_Read(void) 
{
    return (Debug5_PS & Debug5_MASK) >> Debug5_SHIFT;
}


/*******************************************************************************
* Function Name: Debug5_ReadDataReg
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
uint8 Debug5_ReadDataReg(void) 
{
    return (Debug5_DR & Debug5_MASK) >> Debug5_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Debug5_INTSTAT) 

    /*******************************************************************************
    * Function Name: Debug5_ClearInterrupt
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
    uint8 Debug5_ClearInterrupt(void) 
    {
        return (Debug5_INTSTAT & Debug5_MASK) >> Debug5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
