/*******************************************************************************
* File Name: .h
* Version 2.60
*
* Description:
*  This private header file contains internal definitions for the SPIS
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIS_PVT_PiComs_H)
#define CY_SPIS_PVT_PiComs_H

#include "PiComs.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/
extern volatile uint8 PiComs_swStatusTx;
extern volatile uint8 PiComs_swStatusRx;

#if (PiComs_RX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 PiComs_rxBuffer[PiComs_RX_BUFFER_SIZE];
    extern volatile uint8 PiComs_rxBufferRead;
    extern volatile uint8 PiComs_rxBufferWrite;
    extern volatile uint8 PiComs_rxBufferFull;

#endif /* PiComs_RX_SOFTWARE_BUF_ENABLED */

#if (PiComs_TX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 PiComs_txBuffer[PiComs_TX_BUFFER_SIZE];
    extern volatile uint8 PiComs_txBufferRead;
    extern volatile uint8 PiComs_txBufferWrite;
    extern volatile uint8 PiComs_txBufferFull;

#endif /* PiComs_TX_SOFTWARE_BUF_ENABLED */

#endif /* CY_SPIS_PVT_PiComs_H */


/* [] END OF FILE */
