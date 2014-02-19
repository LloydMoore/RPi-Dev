/*******************************************************************************
* File Name: SerDrv_RA.c  
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
#include "SerDrv_RA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SerDrv_RA__PORT == 15 && ((SerDrv_RA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SerDrv_RA_Write
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
void SerDrv_RA_Write(uint8 value) 
{
    uint8 staticBits = (SerDrv_RA_DR & (uint8)(~SerDrv_RA_MASK));
    SerDrv_RA_DR = staticBits | ((uint8)(value << SerDrv_RA_SHIFT) & SerDrv_RA_MASK);
}


/*******************************************************************************
* Function Name: SerDrv_RA_SetDriveMode
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
void SerDrv_RA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SerDrv_RA_0, mode);
}


/*******************************************************************************
* Function Name: SerDrv_RA_Read
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
*  Macro SerDrv_RA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SerDrv_RA_Read(void) 
{
    return (SerDrv_RA_PS & SerDrv_RA_MASK) >> SerDrv_RA_SHIFT;
}


/*******************************************************************************
* Function Name: SerDrv_RA_ReadDataReg
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
uint8 SerDrv_RA_ReadDataReg(void) 
{
    return (SerDrv_RA_DR & SerDrv_RA_MASK) >> SerDrv_RA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SerDrv_RA_INTSTAT) 

    /*******************************************************************************
    * Function Name: SerDrv_RA_ClearInterrupt
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
    uint8 SerDrv_RA_ClearInterrupt(void) 
    {
        return (SerDrv_RA_INTSTAT & SerDrv_RA_MASK) >> SerDrv_RA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
