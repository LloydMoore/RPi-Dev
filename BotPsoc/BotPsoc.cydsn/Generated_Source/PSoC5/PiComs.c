/*******************************************************************************
* File Name: PiComs.c
* Version 2.60
*
* Description:
*  This file provides all API functionality of the SPI Slave component.
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

#if (PiComs_TX_SOFTWARE_BUF_ENABLED)

    volatile uint8 PiComs_txBuffer[PiComs_TX_BUFFER_SIZE] = {0u};
    volatile uint8 PiComs_txBufferRead;
    volatile uint8 PiComs_txBufferWrite;
    volatile uint8 PiComs_txBufferFull;

#endif /* PiComs_TX_SOFTWARE_BUF_ENABLED*/

#if (PiComs_RX_SOFTWARE_BUF_ENABLED)

    volatile uint8 PiComs_rxBuffer[PiComs_RX_BUFFER_SIZE] = {0u};
    volatile uint8 PiComs_rxBufferRead;
    volatile uint8 PiComs_rxBufferWrite;
    volatile uint8 PiComs_rxBufferFull;

#endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

uint8 PiComs_initVar = 0u;

volatile uint8 PiComs_swStatusTx;
volatile uint8 PiComs_swStatusRx;


/*******************************************************************************
* Function Name: PiComs_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIS configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the
*  interrupt service routine, configuring the bit-counter parameters and
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_Init(void) 
{
    /*Initialize the Bit counter */
    PiComs_COUNTER_PERIOD_REG = PiComs_BITCTR_INIT;

    /* ISR initialization */
    #if(PiComs_INTERNAL_TX_INT_ENABLED)

        CyIntDisable(PiComs_TX_ISR_NUMBER);

        /* Set the ISR to point to the PiComs_isr Interrupt. */
        (void)CyIntSetVector(PiComs_TX_ISR_NUMBER, &PiComs_TX_ISR);

        /* Set the priority. */
        CyIntSetPriority(PiComs_TX_ISR_NUMBER, PiComs_TX_ISR_PRIORITY);

    #endif /* PiComs_INTERNAL_TX_INT_ENABLED */

    #if(PiComs_INTERNAL_RX_INT_ENABLED)

        CyIntDisable(PiComs_RX_ISR_NUMBER);

        /* Set the ISR to point to the PiComs_isr Interrupt. */
        (void)CyIntSetVector(PiComs_RX_ISR_NUMBER, &PiComs_RX_ISR);

        /* Set the priority. */
        CyIntSetPriority(PiComs_RX_ISR_NUMBER, PiComs_RX_ISR_PRIORITY);

    #endif /* PiComs_INTERNAL_RX_INT_ENABLED */

    /* Clear any stray data from the RX and TX FIFO */
    PiComs_ClearFIFO();

    #if(PiComs_RX_SOFTWARE_BUF_ENABLED)
        PiComs_txBufferFull = 0u;
        PiComs_rxBufferRead = 0u;
        PiComs_rxBufferWrite = 0u;
    #endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

    #if(PiComs_TX_SOFTWARE_BUF_ENABLED)
        PiComs_txBufferFull = 0u;
        PiComs_txBufferRead = 0u;
        PiComs_txBufferWrite = 0u;
    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */

    (void) PiComs_ReadTxStatus(); /* Clear any pending status bits */
    (void) PiComs_ReadRxStatus(); /* Clear any pending status bits */


    /* Configure the Initial interrupt mask */
    #if (PiComs_TX_SOFTWARE_BUF_ENABLED)
        PiComs_TX_STATUS_MASK_REG  = (PiComs_TX_INIT_INTERRUPTS_MASK &
                                                (uint8)~PiComs_STS_TX_FIFO_NOT_FULL);
    #else /* PiComs_TX_SOFTWARE_BUF_ENABLED */
        PiComs_TX_STATUS_MASK_REG  = PiComs_TX_INIT_INTERRUPTS_MASK;
    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */

    PiComs_RX_STATUS_MASK_REG  = PiComs_RX_INIT_INTERRUPTS_MASK;

}


/*******************************************************************************
* Function Name: PiComs_Enable
********************************************************************************
*
* Summary:
*  Enable SPIS component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void PiComs_Enable(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    PiComs_COUNTER_CONTROL_REG |= PiComs_CNTR_ENABLE;
    PiComs_TX_STATUS_ACTL_REG |= PiComs_INT_ENABLE;
    PiComs_RX_STATUS_ACTL_REG |= PiComs_INT_ENABLE;

    CyExitCriticalSection(enableInterrupts);

    #if(PiComs_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(PiComs_TX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_TX_INT_ENABLED */

    #if(PiComs_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(PiComs_RX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_RX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Slave component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  PiComs_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_Start(void) 
{
    if(PiComs_initVar == 0u)
    {
        PiComs_Init();
        PiComs_initVar = 1u;
    }

    PiComs_Enable();
}


/*******************************************************************************
* Function Name: PiComs_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Slave component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt if one is used.
*
*******************************************************************************/
void PiComs_Stop(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    PiComs_TX_STATUS_ACTL_REG &= (uint8)~PiComs_INT_ENABLE;
    PiComs_RX_STATUS_ACTL_REG &= (uint8)~PiComs_INT_ENABLE;

    CyExitCriticalSection(enableInterrupts);

    #if(PiComs_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(PiComs_TX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_TX_INT_ENABLED */

    #if(PiComs_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(PiComs_RX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_RX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void PiComs_EnableTxInt(void) 
{
    #if(PiComs_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(PiComs_TX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_TX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void PiComs_EnableRxInt(void) 
{
    #if(PiComs_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(PiComs_RX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_RX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void PiComs_DisableTxInt(void) 
{
    #if(PiComs_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(PiComs_TX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_TX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void PiComs_DisableRxInt(void) 
{
    #if(PiComs_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(PiComs_RX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_RX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void PiComs_SetTxInterruptMode(uint8 intSrc) 
{
    PiComs_TX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: PiComs_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void PiComs_SetRxInterruptMode(uint8 intSrc) 
{
    PiComs_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: PiComs_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  PiComs_swStatusTx - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 PiComs_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if (PiComs_TX_SOFTWARE_BUF_ENABLED)

        PiComs_DisableTxInt();

        tmpStatus = PiComs_GET_STATUS_TX(PiComs_swStatusTx);

        PiComs_swStatusTx = 0u;

        /* Enable Interrupts */
        PiComs_EnableTxInt();

    #else /* !PiComs_TX_SOFTWARE_BUF_ENABLED */

        tmpStatus = PiComs_TX_STATUS_REG;

    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: PiComs_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  PiComs_swStatusRx - used to store in software Rx status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 PiComs_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if (PiComs_RX_SOFTWARE_BUF_ENABLED)

        PiComs_DisableRxInt();

        tmpStatus = PiComs_GET_STATUS_RX(PiComs_swStatusRx);

        PiComs_swStatusRx = 0u;

        /* Enable Interrupts */
        PiComs_EnableRxInt();

    #else /* !PiComs_RX_SOFTWARE_BUF_ENABLED */

        tmpStatus = PiComs_RX_STATUS_REG;

    #endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: PiComs_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  PiComs_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  PiComs_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  PiComs_txBuffer[PiComs_TX_BUFFER_SIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_WriteTxData(uint8 txData) 
{
    #if(PiComs_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if buffer is full, so we don't overwrite. */
        do
        {
            tmpTxBufferRead = PiComs_txBufferRead;
            if (0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = PiComs_TX_BUFFER_SIZE - 1u;
            }
            else
            {
                tmpTxBufferRead--;
            }

        } while(tmpTxBufferRead == PiComs_txBufferWrite);

        /* Disable Interrupt to protect variables that could change on interrupt. */
        PiComs_DisableTxInt();

        tempStatus = PiComs_GET_STATUS_TX(PiComs_swStatusTx);
        PiComs_swStatusTx = tempStatus;

        if((PiComs_txBufferRead == PiComs_txBufferWrite) &&
            (0u != (PiComs_swStatusTx & PiComs_STS_TX_FIFO_NOT_FULL)))
        {
            /* Add directly to the FIFO. */
            CY_SET_REG8(PiComs_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the software buffer. */
            PiComs_txBufferWrite++;
            if(PiComs_txBufferWrite >= PiComs_TX_BUFFER_SIZE)
            {
                PiComs_txBufferWrite = 0u;
            }

            if(PiComs_txBufferWrite == PiComs_txBufferRead)
            {
                PiComs_txBufferRead++;
                if(PiComs_txBufferRead >= PiComs_RX_BUFFER_SIZE)
                {
                    PiComs_txBufferRead = 0u;
                }
                PiComs_txBufferFull = 1u;
            }

            PiComs_txBuffer[PiComs_txBufferWrite] = txData;

            PiComs_TX_STATUS_MASK_REG |= PiComs_STS_TX_FIFO_NOT_FULL;
        }

        /* Enable Interrupt. */
        PiComs_EnableTxInt();

    #else /* !PiComs_TX_SOFTWARE_BUF_ENABLED*/

        
        while(0u == (PiComs_TX_STATUS_REG & PiComs_STS_TX_FIFO_NOT_FULL))
		{
			; /* Block while FIFO is full */
		}

        /* Then write the byte */
        CY_SET_REG8(PiComs_TXDATA_PTR, txData);

    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */
}

#if(PiComs_MODE_USE_ZERO != 0u)

    /*******************************************************************************
    * Function Name: PiComs_WriteTxDataZero
    ********************************************************************************
    *
    * Summary:
    *  Write a byte zero of data to be sent across the SPI. This must be used in
    *  Mode 00 and 01 if the FIFO is empty and data is not being sent.
    *
    * Parameters:
    *  txDataByte: The data value to send across the SPI.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Allows the user to transmit any byte of data in a single transfer. Clear
    *  status register of the component.
    *
    *******************************************************************************/
    void PiComs_WriteTxDataZero(uint8 txDataByte)
                                        
    {
        CY_SET_REG8(PiComs_TXDATA_ZERO_PTR, txDataByte);
    }

#endif /* (PiComs_MODE_USE_ZERO != 0u) */


/*******************************************************************************
* Function Name: PiComs_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  PiComs_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  PiComs_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  PiComs_rxBuffer[PiComs_RX_BUFFER_SIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty.  User should poll for FIFO
*  empty status before calling Read function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 PiComs_ReadRxData(void) 
{
    uint8 rxData;

    #if(PiComs_RX_SOFTWARE_BUF_ENABLED)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        PiComs_DisableRxInt();

        if(PiComs_rxBufferRead != PiComs_rxBufferWrite)
        {
            if(PiComs_rxBufferFull == 0u)
            {
                PiComs_rxBufferRead++;
                if(PiComs_rxBufferRead >= PiComs_RX_BUFFER_SIZE)
                {
                    PiComs_rxBufferRead = 0u;
                }
            }
            else
            {
                PiComs_rxBufferFull = 0u;
            }
        }

        rxData = PiComs_rxBuffer[PiComs_rxBufferRead];

        /* Enable Interrupt. */
        PiComs_EnableRxInt();

    #else /* !PiComs_RX_SOFTWARE_BUF_ENABLED */

        rxData = CY_GET_REG8(PiComs_RXDATA_PTR);

    #endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

    return (rxData);

}


/*******************************************************************************
* Function Name: PiComs_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  PiComs_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  PiComs_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Theory:
*  Allows the user to find out how full the RX Buffer is.
*
*******************************************************************************/
uint8 PiComs_GetRxBufferSize(void) 
{
    uint8 size;

    #if(PiComs_RX_SOFTWARE_BUF_ENABLED)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        PiComs_DisableRxInt();

        if(PiComs_rxBufferRead == PiComs_rxBufferWrite)
        {
            size = 0u; /* No data in RX buffer */
        }
        else if(PiComs_rxBufferRead < PiComs_rxBufferWrite)
        {
            size = (PiComs_rxBufferWrite - PiComs_rxBufferRead);
        }
        else
        {
            size = (PiComs_RX_BUFFER_SIZE - PiComs_rxBufferRead) + PiComs_rxBufferWrite;
        }

        /* Enable interrupt. */
        PiComs_EnableRxInt();

    #else /* !PiComs_RX_SOFTWARE_BUF_ENABLED*/

        /* We can only know if there is data in the fifo. */
        size = ((PiComs_RX_STATUS_REG & PiComs_STS_RX_FIFO_NOT_EMPTY) != 0u) ? 1u : 0u;

    #endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

    return (size);
}


/*******************************************************************************
* Function Name: PiComs_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  PiComs_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  PiComs_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Theory:
*  Allows the user to find out how full the TX Buffer is.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  PiComs_GetTxBufferSize(void) 
{
    uint8 size;

    #if(PiComs_TX_SOFTWARE_BUF_ENABLED)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        PiComs_DisableTxInt();

        if(PiComs_txBufferRead == PiComs_txBufferWrite)
        {
            size = 0u;
        }
        else if(PiComs_txBufferRead < PiComs_txBufferWrite)
        {
            size = (PiComs_txBufferWrite - PiComs_txBufferRead);
        }
        else
        {
            size = (PiComs_TX_BUFFER_SIZE - PiComs_txBufferRead) + PiComs_txBufferWrite;
        }

        /* Enable Interrupt. */
        PiComs_EnableTxInt();

    #else /* !PiComs_TX_SOFTWARE_BUF_ENABLED */

        size = PiComs_TX_STATUS_REG;

        /* Is the fifo is full. */
        if((size & PiComs_STS_TX_FIFO_EMPTY) != 0u)
        {
            size = 0u;
        }
        else if((size & PiComs_STS_TX_FIFO_NOT_FULL) != 0u)
        {
            size = 1u;
        }
        else
        {
            size = 4u;
        }

    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */

    return (size);
}


/*******************************************************************************
* Function Name: PiComs_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  PiComs_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  PiComs_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while((PiComs_RX_STATUS_REG & PiComs_STS_RX_FIFO_NOT_EMPTY) != 0u)
    {
        CY_GET_REG8(PiComs_RXDATA_PTR);
    }

    #if(PiComs_RX_SOFTWARE_BUF_ENABLED)

        /* Disable interrupt to protect variables that could change on interrupt. */
        PiComs_DisableRxInt();

        PiComs_rxBufferRead  = 0u;
        PiComs_rxBufferWrite = 0u;
		PiComs_rxBufferFull  = 0u;
        /* Enable interrupt. */
        PiComs_EnableRxInt();

    #endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  PiComs_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  PiComs_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware TX FIFO */
    enableInterrupts = CyEnterCriticalSection();

    #if(PiComs_DATA_WIDTH <= 8u)

        /* Clear TX FIFO */
        PiComs_TX_AUX_CONTROL_DP0_REG |= (uint8)PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP0_REG &= (uint8)~PiComs_FIFO_CLR;

    #else

        /* Clear TX FIFO */
        PiComs_TX_AUX_CONTROL_DP0_REG |= (uint8)PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP0_REG &= (uint8)~PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP1_REG |= (uint8)PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP1_REG &= (uint8)~PiComs_FIFO_CLR;

    #endif /* PiComs_DATA_WIDTH > 8u */

    CyExitCriticalSection(enableInterrupts);

    #if(PiComs_TX_SOFTWARE_BUF_ENABLED)

        /* Disable Interrupt to protect variables that could change on interrupt. */
        PiComs_DisableTxInt();

        PiComs_txBufferRead  = 0u;
        PiComs_txBufferWrite = 0u;
		PiComs_txBufferFull  = 0u;
		
        /* If Buffer is empty then disable TX FIFO status interrupt */
        PiComs_TX_STATUS_MASK_REG &= (uint8)~PiComs_STS_TX_FIFO_NOT_FULL;

        /* Enable Interrupt. */
        PiComs_EnableTxInt();

    #endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */
}


#if (PiComs_BIDIRECTIONAL_MODE != 0u)

    /*******************************************************************************
    * Function Name: PiComs_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI Slave is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void PiComs_TxEnable(void) 
    {
            PiComs_CONTROL_REG |= PiComs_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: PiComs_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI Slave is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void PiComs_TxDisable(void) 
    {
            PiComs_CONTROL_REG &= (uint8)~PiComs_CTRL_TX_SIGNAL_EN;
    }

#endif /* PiComs_BIDIRECTIONAL_MODE != 0u */


/*******************************************************************************
* Function Name: PiComs_PutArray
********************************************************************************
*
* Summary:
*  Write available data from RAM/ROM to the TX buffer while space is available
*  in the TX buffer. Keep trying until all data is passed to the TX buffer. If
*  used Mode 00 or 01 before PutArray() function should be called
*  WriteTxDataZero() function.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PiComs_PutArray(const uint8 buffer[], uint8 byteCount)
                                                                    
{
    uint8 bufIndex;
    bufIndex = 0u;

    while(byteCount > 0u)
    {
        PiComs_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: PiComs_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void PiComs_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    while((PiComs_RX_STATUS_REG & PiComs_STS_RX_FIFO_NOT_EMPTY) != 0u)
    {
        CY_GET_REG8(PiComs_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();

    #if(PiComs_DATA_WIDTH <= 8u)

        /* Clear TX FIFO */
        PiComs_TX_AUX_CONTROL_DP0_REG |= (uint8)PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP0_REG &= (uint8)~PiComs_FIFO_CLR;

    #else

        /* Clear TX FIFO */
        PiComs_TX_AUX_CONTROL_DP0_REG |= (uint8)PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP0_REG &= (uint8)~PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP1_REG |= (uint8)PiComs_FIFO_CLR;
        PiComs_TX_AUX_CONTROL_DP1_REG &= (uint8)~PiComs_FIFO_CLR;

    #endif /* PiComs_DATA_WIDTH <= 8u */

    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: PiComs_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void PiComs_EnableInt(void) 
{
    #if(PiComs_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(PiComs_TX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_TX_INT_ENABLED */

    #if(PiComs_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(PiComs_RX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_RX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void PiComs_DisableInt(void) 
{
    #if(PiComs_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(PiComs_TX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_TX_INT_ENABLED */

    #if(PiComs_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(PiComs_RX_ISR_NUMBER);
    #endif /* PiComs_INTERNAL_RX_INT_ENABLED */
}


/*******************************************************************************
* Function Name: PiComs_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void PiComs_SetInterruptMode(uint8 intSrc) 
{
    PiComs_TX_STATUS_MASK_REG  = intSrc;
    PiComs_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: PiComs_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  PiComs_swStatus - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 PiComs_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if ((PiComs_TX_SOFTWARE_BUF_ENABLED) || (PiComs_RX_SOFTWARE_BUF_ENABLED))

        PiComs_DisableInt();

        tmpStatus = PiComs_GET_STATUS_TX(PiComs_swStatusTx) |
              (PiComs_GET_STATUS_RX(PiComs_swStatusRx) & (uint8)~PiComs_STS_RX_FIFO_FULL);

        PiComs_swStatusTx = 0u;
        PiComs_swStatusRx = 0u;

        /* Enable Interrupts */
        PiComs_EnableInt();

    #else /* !((PiComs_TX_SOFTWARE_BUF_ENABLED) || (PiComs_RX_SOFTWARE_BUF_ENABLED)) */

        tmpStatus = PiComs_TX_STATUS_REG | (PiComs_RX_STATUS_REG &
                                                      (uint8)~PiComs_STS_RX_FIFO_FULL);

    #endif /* (PiComs_TX_SOFTWARE_BUF_ENABLED) || (PiComs_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
