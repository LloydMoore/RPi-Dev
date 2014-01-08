/*******************************************************************************
* File Name: PiUART_TXD.c  
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
#include "PiUART_TXD.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PiUART_TXD__PORT == 15 && ((PiUART_TXD__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PiUART_TXD_Write
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
void PiUART_TXD_Write(uint8 value) 
{
    uint8 staticBits = (PiUART_TXD_DR & (uint8)(~PiUART_TXD_MASK));
    PiUART_TXD_DR = staticBits | ((uint8)(value << PiUART_TXD_SHIFT) & PiUART_TXD_MASK);
}


/*******************************************************************************
* Function Name: PiUART_TXD_SetDriveMode
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
void PiUART_TXD_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PiUART_TXD_0, mode);
}


/*******************************************************************************
* Function Name: PiUART_TXD_Read
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
*  Macro PiUART_TXD_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PiUART_TXD_Read(void) 
{
    return (PiUART_TXD_PS & PiUART_TXD_MASK) >> PiUART_TXD_SHIFT;
}


/*******************************************************************************
* Function Name: PiUART_TXD_ReadDataReg
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
uint8 PiUART_TXD_ReadDataReg(void) 
{
    return (PiUART_TXD_DR & PiUART_TXD_MASK) >> PiUART_TXD_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PiUART_TXD_INTSTAT) 

    /*******************************************************************************
    * Function Name: PiUART_TXD_ClearInterrupt
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
    uint8 PiUART_TXD_ClearInterrupt(void) 
    {
        return (PiUART_TXD_INTSTAT & PiUART_TXD_MASK) >> PiUART_TXD_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
