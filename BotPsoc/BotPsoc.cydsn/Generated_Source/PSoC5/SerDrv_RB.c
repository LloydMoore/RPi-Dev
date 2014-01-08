/*******************************************************************************
* File Name: SerDrv_RB.c  
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
#include "SerDrv_RB.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SerDrv_RB__PORT == 15 && ((SerDrv_RB__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SerDrv_RB_Write
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
void SerDrv_RB_Write(uint8 value) 
{
    uint8 staticBits = (SerDrv_RB_DR & (uint8)(~SerDrv_RB_MASK));
    SerDrv_RB_DR = staticBits | ((uint8)(value << SerDrv_RB_SHIFT) & SerDrv_RB_MASK);
}


/*******************************************************************************
* Function Name: SerDrv_RB_SetDriveMode
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
void SerDrv_RB_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SerDrv_RB_0, mode);
}


/*******************************************************************************
* Function Name: SerDrv_RB_Read
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
*  Macro SerDrv_RB_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SerDrv_RB_Read(void) 
{
    return (SerDrv_RB_PS & SerDrv_RB_MASK) >> SerDrv_RB_SHIFT;
}


/*******************************************************************************
* Function Name: SerDrv_RB_ReadDataReg
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
uint8 SerDrv_RB_ReadDataReg(void) 
{
    return (SerDrv_RB_DR & SerDrv_RB_MASK) >> SerDrv_RB_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SerDrv_RB_INTSTAT) 

    /*******************************************************************************
    * Function Name: SerDrv_RB_ClearInterrupt
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
    uint8 SerDrv_RB_ClearInterrupt(void) 
    {
        return (SerDrv_RB_INTSTAT & SerDrv_RB_MASK) >> SerDrv_RB_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
