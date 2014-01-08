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

#include "botmonitor.h"
#include "ui_botmonitor.h"

BotMonitor::BotMonitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BotMonitor),
    m_pSpiRing(NULL)
{
    ui->setupUi(this);
    m_pSpiRing = new SpiRing(QString(TARGET_SPI_PORT), this);

    connect(m_pSpiRing, SIGNAL(newTransferReceived()), this, SLOT(processSpiUpdate()));
}

BotMonitor::~BotMonitor()
{
    if(m_pSpiRing)
    {
        delete m_pSpiRing;
        m_pSpiRing = NULL;
    }

    delete ui;
}


void BotMonitor::processSpiUpdate()
{
    //Read out the sensor values into the UI fields
    ui->sensorIRDistanceEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->irDistance));
    ui->sensorLeftBumperForceEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->leftBumpForce));
    ui->sensorRightBumperForceEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->rightBumpForce));
    ui->sensorLeftBumperFieldEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->leftBumpField));
    ui->sensorRightBumperFieldEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->rightBumpField));
    ui->batteryLevelEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->batteryLevel));
    ui->sensorRCLRValueEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->rcLRValue));
    ui->sensorRCFBValueEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->rcFBValue));
    ui->sensorRCCamPanValueEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->rcCamPanValue));
    ui->sensorRCCamtiltValueEdit->setText((QString("%1").arg(m_pSpiRing->sensors()->rcCamTiltValue)));
    ui->sensorRCOverrideValueEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->rcOverrideValue));
    ui->sensorRCAuxValueEdit->setText(QString("%1").arg(m_pSpiRing->sensors()->rcOverrideValue));

    //Put the UI motor fields into the spi ring motor values
    m_pSpiRing->motor()->leftDriveMotor = ui->leftDriveMotorEdit->text().toUInt();
    m_pSpiRing->motor()->rightDriveMotor = ui->rightDriveMotorEdit->text().toUInt();
    m_pSpiRing->motor()->driveMotorCommand = ui->motorCmdEdit->text().toUInt();
    m_pSpiRing->motor()->camPanDrive = ui->camPanMotorEdit->text().toUInt();
    m_pSpiRing->motor()->camTiltDrive = ui->camTiltMotorEdit->text().toUInt();
}
