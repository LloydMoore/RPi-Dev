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

#ifndef SPI_RING_H
#define SPI_RING_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QTimer>
#include <QString>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include "../../Common/ringcoms.h"
#include "base_exception.h"

#define INVALID_FILE_ID -1                                  //Key code for an invalid file id
#define SPI_MODE 0                                          //Hardware mode to open the SPI port in
#define SPI_BITS 8                                         //Width of SPI transfer in bits
#define SPI_SPEED 4000000                                   //Speed of the SPI transfer in Hz
#define SPI_RING_TRANSFER_INTERVAL 20                       //How frequency to do the data transfer in mS

class SpiRing : public QThread
{
    Q_OBJECT
public:
    explicit SpiRing(QString port, QObject *parent = 0);    //Ctor with initialization
    ~SpiRing();                                             //Default dtor

    SensoryMembers *sensors();                              //Get a pointer to the sensor data
    MotorMembers *motor();                                  //Get a pointer to the motor data
    
signals:
    void newTransferReceived();                             //Signal emitted when a new transfer has been completed
    
public slots:

private slots:
    void beginTransfer();                                   //Begin an SPI transfer

protected:
    virtual void run();                                     //Thread to actually manage the transfer

private:
    void openPort();                                        //Open the SPI port
    void closePort();                                       //Close the SPI port

    int m_FileDescriptor;                                   //File descriptor for the SPI port
    uint8_t m_SpiMode;                                      //Mode for the SPI port
    uint8_t m_SpiBits;                                      //Size of SPI transfers
    uint32_t m_SpiSpeed;                                    //Bit rate of the SPI port in bps
    unsigned long m_TransferSize;                           //Size of the buffers and the SPI transfer in bytes
    uint8_t *m_pTransmitBuffer;                             //Buffer to hold data being transferred for SPI
    uint8_t *m_pReceiveBuffer;                              //Buffer to hold data being received for SPI
    QTimer m_autoTransferTimer;                             //Timer to trigger the ring data transfer at regular intervals
    QString m_portName;                                     //Name of the port to transfer with
    SpiRingData m_currentData;                              //The current ring data to be operating with
    QMutex m_currentDataLock;                               //Lock the spi ring data when being accessed for consistency

};

#endif // SPI_RING_H
