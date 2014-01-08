/*
BotPsoc - Low level logic and drivers for SRSPiBot Robot
Copyright (C) 2013  Lloyd Moore, CyberData Corporation

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

This software has been developed and released by Lloyd Moore, owner of
CyberData Corporation as part of our R&D efforts. For
questions and comments on this code I can be reached at:
e-mail: Lloyd@CyberData-Robotics.com
Web site: http://www.CyberData-Robotics.com
*/

#include "bot_psoc.h"
#include "spi_ring.h"

//Private function prototypes
void ringComs_ConfigureDMA();                               //Configure the DMA for the SPI transfers

//Private variables
uint8 spiDmaTransmitChannel;                                //DMA handle for the SPI transmit operation
uint8 spiDmaReceiveChannel;                                 //DMA handle for the SPI receive operation

uint8 spiDmaTransmitTD[1];                                  //Transfer descriptor array for spi transmit operation
uint8 spiDmaReceiveTD[1];                                   //Transfer descriptor array for the spi receive operation

void ringComs_Start()
{
    //Clear the global variables for the spi ring
    memset(&g_spiRing, 0x00, sizeof(g_spiRing));
    g_spiReady = false;
    
    PiComs_Start();
    SpiXferDone_Start();
   
    //Load the header/footer data into the sensory side
    g_spiRing.sensory.sensoryHeader = HEADER_VALUE;
    g_spiRing.sensory.sensoryFooter = FOOTER_VALUE;
    
    //Just load some temporary data right now for testing
    g_spiRing.sensory.irDistance = 0x0023;
    g_spiRing.sensory.leftBumpForce = 0x0025;
    g_spiRing.sensory.rightBumpForce = 0x00a5;
    g_spiRing.sensory.leftBumpField = 0x00b4;
 
    ringComs_ConfigureDMA();
    ringComs_DoTransfer();   
}

void ringComs_ConfigureDMA()
{
    //Configure the transmit DMA channel
    uint8 *pTransmitStartAddress = (uint8*)(&g_spiRing.sensory.sensoryHeader);     //Start one byte in as the first byte is preloaded directly
    ++pTransmitStartAddress;
    
    spiDmaTransmitChannel = SpiXmitDma_DmaInitialize(SPI_DMA_BYTES_PER_BURST, SPI_DMA_REQUEST_PER_BURST,
        HI16(&g_spiRing.effectors), HI16(PiComs_TXDATA_PTR));
    spiDmaTransmitTD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(spiDmaTransmitTD[0], sizeof(SensoryMembers) - 1, DMA_DISABLE_TD, TD_INC_SRC_ADR);
    CyDmaTdSetAddress(spiDmaTransmitTD[0], LO16((uint32)(pTransmitStartAddress)), LO16((uint32)PiComs_TXDATA_PTR));
    CyDmaChSetInitialTd(spiDmaTransmitChannel, spiDmaTransmitTD[0]);
    
    //Configure the receive DMA channel
    spiDmaReceiveChannel = SpiRcvDma_DmaInitialize(SPI_DMA_BYTES_PER_BURST, SPI_DMA_REQUEST_PER_BURST,
        HI16(PiComs_RXDATA_PTR), HI16(&g_spiRing.sensory));
    spiDmaReceiveTD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(spiDmaReceiveTD[0], sizeof(MotorMembers), DMA_DISABLE_TD, 
        (TD_INC_DST_ADR | SpiRcvDma__TD_TERMOUT_EN));
    CyDmaTdSetAddress(spiDmaReceiveTD[0], LO16((uint32)PiComs_RXDATA_PTR), LO16((uint32)&g_spiRing.effectors));
    CyDmaChSetInitialTd(spiDmaReceiveChannel, spiDmaReceiveTD[0]);

    //Note: The transfer descriptors allocated here will never be returned, they are reused for the full 
    //lifetime of the program.
}

void ringComs_DoTransfer()
{
    uint8 *pFirstByte = (uint8*) &(g_spiRing.sensory.sensoryHeader);
    CyDmaChEnable(spiDmaTransmitChannel, true);
    CyDmaChEnable(spiDmaReceiveChannel, true);
    
    PiComs_WriteTxDataZero(*pFirstByte);
}

/* [] END OF FILE */
