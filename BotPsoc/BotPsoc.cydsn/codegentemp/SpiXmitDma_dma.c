/***************************************************************************
* File Name: SpiXmitDma_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <SpiXmitDma_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* SpiXmitDma__DRQ_CTL_REG
* 
* 
* SpiXmitDma__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* SpiXmitDma__NUMBEROF_TDS
* 
* Priority of this channel.
* SpiXmitDma__PRIORITY
* 
* True if SpiXmitDma_TERMIN_SEL is used.
* SpiXmitDma__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* SpiXmitDma__TERMIN_SEL
* 
* 
* True if SpiXmitDma_TERMOUT0_SEL is used.
* SpiXmitDma__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* SpiXmitDma__TERMOUT0_SEL
* 
* 
* True if SpiXmitDma_TERMOUT1_SEL is used.
* SpiXmitDma__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* SpiXmitDma__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of SpiXmitDma dma channel */
uint8 SpiXmitDma_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 SpiXmitDma_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 SpiXmitDma_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    SpiXmitDma_DmaHandle = (uint8)SpiXmitDma__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(SpiXmitDma_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)SpiXmitDma__TERMOUT0_SEL,
                                  (uint8)SpiXmitDma__TERMOUT1_SEL,
                                  (uint8)SpiXmitDma__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(SpiXmitDma_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(SpiXmitDma_DmaHandle, (uint8)SpiXmitDma__PRIORITY);
    
    return SpiXmitDma_DmaHandle;
}

/*********************************************************************
* Function Name: void SpiXmitDma_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with SpiXmitDma.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void SpiXmitDma_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(SpiXmitDma_DmaHandle);
}

