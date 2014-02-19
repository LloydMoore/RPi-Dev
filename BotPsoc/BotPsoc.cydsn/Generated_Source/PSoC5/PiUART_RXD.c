/*******************************************************************************
* File Name: PiUART_RXD.c  
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
#include "PiUART_RXD.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PiUART_RXD__PORT == 15 && ((PiUART_RXD__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PiUART_RXD_Write
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
void PiUART_RXD_Write(uint8 value) 
{
    uint8 staticBits = (PiUART_RXD_DR & (uint8)(~PiUART_RXD_MASK));
    PiUART_RXD_DR = staticBits | ((uint8)(value << PiUART_RXD_SHIFT) & PiUART_RXD_MASK);
}


/*******************************************************************************
* Function Name: PiUART_RXD_SetDriveMode
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
void PiUART_RXD_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PiUART_RXD_0, mode);
}


/*******************************************************************************
* Function Name: PiUART_RXD_Read
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
*  Macro PiUART_RXD_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PiUART_RXD_Read(void) 
{
    return (PiUART_RXD_PS & PiUART_RXD_MASK) >> PiUART_RXD_SHIFT;
}


/*******************************************************************************
* Function Name: PiUART_RXD_ReadDataReg
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
uint8 PiUART_RXD_ReadDataReg(void) 
{
    return (PiUART_RXD_DR & PiUART_RXD_MASK) >> PiUART_RXD_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PiUART_RXD_INTSTAT) 

    /*******************************************************************************
    * Function Name: PiUART_RXD_ClearInterrupt
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
    uint8 PiUART_RXD_ClearInterrupt(void) 
    {
        return (PiUART_RXD_INTSTAT & PiUART_RXD_MASK) >> PiUART_RXD_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
