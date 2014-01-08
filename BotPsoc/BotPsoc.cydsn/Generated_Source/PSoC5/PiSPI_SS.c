/*******************************************************************************
* File Name: PiSPI_SS.c  
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
#include "PiSPI_SS.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PiSPI_SS__PORT == 15 && ((PiSPI_SS__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PiSPI_SS_Write
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
void PiSPI_SS_Write(uint8 value) 
{
    uint8 staticBits = (PiSPI_SS_DR & (uint8)(~PiSPI_SS_MASK));
    PiSPI_SS_DR = staticBits | ((uint8)(value << PiSPI_SS_SHIFT) & PiSPI_SS_MASK);
}


/*******************************************************************************
* Function Name: PiSPI_SS_SetDriveMode
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
void PiSPI_SS_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PiSPI_SS_0, mode);
}


/*******************************************************************************
* Function Name: PiSPI_SS_Read
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
*  Macro PiSPI_SS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PiSPI_SS_Read(void) 
{
    return (PiSPI_SS_PS & PiSPI_SS_MASK) >> PiSPI_SS_SHIFT;
}


/*******************************************************************************
* Function Name: PiSPI_SS_ReadDataReg
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
uint8 PiSPI_SS_ReadDataReg(void) 
{
    return (PiSPI_SS_DR & PiSPI_SS_MASK) >> PiSPI_SS_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PiSPI_SS_INTSTAT) 

    /*******************************************************************************
    * Function Name: PiSPI_SS_ClearInterrupt
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
    uint8 PiSPI_SS_ClearInterrupt(void) 
    {
        return (PiSPI_SS_INTSTAT & PiSPI_SS_MASK) >> PiSPI_SS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
