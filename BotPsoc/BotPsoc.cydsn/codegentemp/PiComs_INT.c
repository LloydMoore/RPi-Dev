/*******************************************************************************
* File Name: PiComs_INT.c
* Version 2.60
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Slave
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PiComs_PVT.h"


/* User code required at start of ISR */
/* `#START PiComs_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: PiComs_TX_ISR
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Slave.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  PiComs_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  PiComs_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  PiComs_txBuffer[PiComs_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(PiComs_TX_ISR)
{

    #if(PiComs_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (PiComs_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START PiComs_ISR_TX_START` */

    /* `#END` */

    #if(PiComs_TX_SOFTWARE_BUF_ENABLED)
        /* Component interrupt service code */

        /* See if TX data buffer is not empty and there is space in TX FIFO */
        while(PiComs_txBufferRead != PiComs_txBufferWrite)
        {
            tmpStatus = PiComs_GET_STATUS_TX(PiComs_swStatusTx);
            PiComs_swStatusTx = tmpStatus;

            if ((PiComs_swStatusTx & PiComs_STS_TX_FIFO_NOT_FULL) != 0u)
            {
                if(PiComs_txBufferFull == 0u)
                {
                   PiComs_txBufferRead++;

                    if(PiComs_txBufferRead >= PiComs_TX_BUFFER_SIZE)
                    {
                        PiComs_txBufferRead = 0u;
                    }
                }
                else
                {
                    PiComs_txBufferFull = 0u;
                }

                /* Move data from the Buffer to the FIFO */
                CY_SET_REG8(PiComs_TXDATA_PTR,
                PiComs_txBuffer[PiComs_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        /* If Buffer is empty then disable TX FIFO status interrupt until there is data in the buffer */
        if(PiComs_txBufferRead == PiComs_txBufferWrite)
        {
            PiComs_TX_STATUS_MASK_REG &= ((uint8)~PiComs_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */

    /* User code required at end of ISR (Optional) */
    /* `#START PiComs_ISR_TX_END` */
   
    /* `#END` */

   }


/*******************************************************************************
* Function Name: PiComs_RX_ISR
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Slave.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  PiComs_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  PiComs_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  PiComs_rxBuffer[PiComs_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(PiComs_RX_ISR)
{
    #if(PiComs_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (PiComs_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START PiComs_RX_ISR_START` */

    /* `#END` */

    #if(PiComs_RX_SOFTWARE_BUF_ENABLED)
        tmpStatus = PiComs_GET_STATUS_RX(PiComs_swStatusRx);
        PiComs_swStatusRx = tmpStatus;
        /* See if RX data FIFO has some data and if it can be moved to the RX Buffer */
        while((PiComs_swStatusRx & PiComs_STS_RX_FIFO_NOT_EMPTY) != 0u)
        {
            rxData = CY_GET_REG8(PiComs_RXDATA_PTR);

            /* Set next pointer. */
            PiComs_rxBufferWrite++;
            if(PiComs_rxBufferWrite >= PiComs_RX_BUFFER_SIZE)
            {
                PiComs_rxBufferWrite = 0u;
            }

            if(PiComs_rxBufferWrite == PiComs_rxBufferRead)
            {
                PiComs_rxBufferRead++;
                if(PiComs_rxBufferRead >= PiComs_RX_BUFFER_SIZE)
                {
                    PiComs_rxBufferRead = 0u;
                }
                PiComs_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            PiComs_rxBuffer[PiComs_rxBufferWrite] = rxData;

            tmpStatus = PiComs_GET_STATUS_RX(PiComs_swStatusRx);
            PiComs_swStatusRx = tmpStatus;
        }
    #endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

    /* User code required at end of ISR (Optional) */
    /* `#START PiComs_RX_ISR_END` */

    /* `#END` */

}

/* [] END OF FILE */
