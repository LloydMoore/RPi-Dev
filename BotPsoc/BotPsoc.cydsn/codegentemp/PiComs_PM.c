/*******************************************************************************
* File Name: PiComs_PM.c
* Version 2.60
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PiComs_PVT.h"

static PiComs_BACKUP_STRUCT PiComs_backup = 
{
    PiComs_DISABLED,
    PiComs_BITCTR_INIT,
    #if(CY_UDB_V0)
        PiComs_TX_INIT_INTERRUPTS_MASK,
        PiComs_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


/*******************************************************************************
* Function Name: PiComs_SaveConfig
********************************************************************************
*
* Summary:
*  Saves SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  PiComs_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if (CY_UDB_V0)

       PiComs_backup.saveSrTxIntMask = PiComs_TX_STATUS_MASK_REG;
       PiComs_backup.saveSrRxIntMask = PiComs_RX_STATUS_MASK_REG;
       PiComs_backup.cntrPeriod      = PiComs_COUNTER_PERIOD_REG;

    #endif /* CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: PiComs_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores SPIS configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  PiComs_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  PiComs_STATUS_MASK_REG and PiComs_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void PiComs_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if (CY_UDB_V0)

        PiComs_TX_STATUS_MASK_REG = PiComs_backup.saveSrTxIntMask;
        PiComs_RX_STATUS_MASK_REG = PiComs_backup.saveSrRxIntMask;
        PiComs_COUNTER_PERIOD_REG = PiComs_backup.cntrPeriod;

    #endif /* CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: PiComs_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  PiComs_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_Sleep(void) 
{
    /* Save components enable state */
    if ((PiComs_TX_STATUS_ACTL_REG & PiComs_INT_ENABLE) != 0u)
    {
        PiComs_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        PiComs_backup.enableState = 0u;
    }

    PiComs_Stop();

    PiComs_SaveConfig();
}


/*******************************************************************************
* Function Name: PiComs_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  PiComs_backup - used when non-retention registers are restored.
*  PiComs_txBufferWrite - modified every function call - resets to
*  zero.
*  PiComs_txBufferRead - modified every function call - resets to
*  zero.
*  PiComs_rxBufferWrite - modified every function call - resets to
*  zero.
*  PiComs_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_Wakeup(void) 
{
    PiComs_RestoreConfig();

    #if (PiComs_TX_SOFTWARE_BUF_ENABLED)
        PiComs_txBufferFull = 0u;
        PiComs_txBufferRead = 0u;
        PiComs_txBufferWrite = 0u;
    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */

    #if (PiComs_RX_SOFTWARE_BUF_ENABLED)
        PiComs_rxBufferFull = 0u;
        PiComs_rxBufferRead = 0u;
        PiComs_rxBufferWrite = 0u;
    #endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

    PiComs_ClearFIFO();

    /* Restore components block enable state */
    if (PiComs_backup.enableState != 0u)
    {
         /* Components block was enabled */
         PiComs_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
