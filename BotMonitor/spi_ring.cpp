/*
BotMonitor - UI interface and upper level logic for SRSPiBot Robot
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

#include <QDebug>
#include "spi_ring.h"

SpiRing::SpiRing(QString port, QObject *parent) :
    QThread(parent), m_portName(port)
{
    memset(&m_currentData, 0, sizeof(m_currentData));
    m_FileDescriptor = INVALID_FILE_ID;
    m_SpiMode = SPI_MODE;
    m_SpiBits = SPI_BITS;
    m_SpiSpeed = SPI_SPEED;

    Q_ASSERT(sizeof(SensoryMembers) == sizeof(MotorMembers));       //Ensure that the SPI transfer is "balanced/symetrical"
    m_TransferSize = sizeof(SensoryMembers);                        //Transfer size in 16 bit words
    m_pTransmitBuffer = new uint8_t[m_TransferSize];
    if(m_pTransmitBuffer == NULL) throw new BASE_EXCEPTION("Unable to allocate SPI transmit buffer");
    m_pReceiveBuffer = new uint8_t[m_TransferSize];
    if(m_pReceiveBuffer == NULL) throw new BASE_EXCEPTION("Unable to allocate SPI receive buffer");

    openPort();

    connect(&m_autoTransferTimer, SIGNAL(timeout()), this, SLOT(beginTransfer()));
    m_autoTransferTimer.start(SPI_RING_TRANSFER_INTERVAL);
}

SpiRing::~SpiRing()
{
    m_autoTransferTimer.stop();

    closePort();

    if(m_pTransmitBuffer)
    {
        delete m_pTransmitBuffer;
        m_pTransmitBuffer = NULL;
    }

    if(m_pReceiveBuffer)
    {
        delete m_pReceiveBuffer;
        m_pReceiveBuffer = NULL;
    }
}

SensoryMembers* SpiRing::sensors()
{
    return &(m_currentData.sensory);
}

MotorMembers* SpiRing::motor()
{
    return &(m_currentData.effectors);
}

void SpiRing::openPort()
{
    int retVal = 0;

    m_FileDescriptor = open(m_portName.toLatin1(), O_RDWR);
    if(m_FileDescriptor == INVALID_FILE_ID) throw new BASE_EXCEPTION("Unable to open SPI port");

    retVal = ioctl(m_FileDescriptor, SPI_IOC_WR_MODE, &m_SpiMode);
    if(retVal == -1) throw new BASE_EXCEPTION("Unable to set SPI write mode");

    retVal = ioctl(m_FileDescriptor, SPI_IOC_RD_MODE, &m_SpiMode);
    if(retVal == -1) throw new BASE_EXCEPTION("Unable to set SPI read mode");

    retVal = ioctl(m_FileDescriptor, SPI_IOC_WR_BITS_PER_WORD, &m_SpiBits);
    if(retVal == -1) throw new BASE_EXCEPTION("Unable to set write SPI bits");

    retVal = ioctl(m_FileDescriptor, SPI_IOC_RD_BITS_PER_WORD, &m_SpiBits);
    if(retVal == -1) throw new BASE_EXCEPTION("Unable to set SPI read bits");

    retVal = ioctl(m_FileDescriptor, SPI_IOC_WR_MAX_SPEED_HZ, &m_SpiSpeed);
    if(retVal == -1) throw new BASE_EXCEPTION("Unable to set SPI write speed");

    retVal = ioctl(m_FileDescriptor, SPI_IOC_RD_MAX_SPEED_HZ, &m_SpiSpeed);
    if(retVal == -1) throw new BASE_EXCEPTION("Unable to set SPI read speed");
}

void SpiRing::closePort()
{
    if(m_FileDescriptor != INVALID_FILE_ID)
    {
        close(m_FileDescriptor);
        m_FileDescriptor = INVALID_FILE_ID;
    }
}

void SpiRing::beginTransfer()
{
    QMutexLocker dataLock(&m_currentDataLock);
    m_currentData.effectors.motorHeader = HEADER_VALUE;
    m_currentData.effectors.motorFooter = FOOTER_VALUE;
    memcpy(m_pTransmitBuffer, &m_currentData.effectors, m_TransferSize);
    dataLock.unlock();
    run();
}

void SpiRing::run()
{
    struct spi_ioc_transfer transferDescriptor;                 //Descriptor to describe the SPI operation

    transferDescriptor.tx_buf = (unsigned long) m_pTransmitBuffer;
    transferDescriptor.rx_buf = (unsigned long)m_pReceiveBuffer;
    transferDescriptor.len = m_TransferSize;
    transferDescriptor.delay_usecs = 0;
    transferDescriptor.speed_hz = m_SpiSpeed;
    transferDescriptor.bits_per_word = m_SpiBits;

    ioctl(m_FileDescriptor, SPI_IOC_MESSAGE(1), &transferDescriptor);

    SensoryMembers *pSensoryTest = (SensoryMembers*)(m_pReceiveBuffer);
    QMutexLocker dataLock(&m_currentDataLock);

    if(pSensoryTest->sensoryHeader == HEADER_VALUE && pSensoryTest->sensoryFooter == FOOTER_VALUE)
    {
        memcpy(&m_currentData.sensory, m_pReceiveBuffer, m_TransferSize);
    }
    else
    {
        qDebug() << "Bad packet: Header: %1, Footer: %1" << pSensoryTest->sensoryHeader << pSensoryTest->sensoryFooter;
        memset(&m_currentData.sensory, 0, sizeof(SensoryMembers));
    }

    dataLock.unlock();

    emit newTransferReceived();
}
