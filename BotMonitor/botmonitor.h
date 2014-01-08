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


#ifndef BOTMONITOR_H
#define BOTMONITOR_H

#include <QMainWindow>
#include "spi_ring.h"

#define TARGET_SPI_PORT "/dev/spidev0.0"      //Port name to use for communication to PSoC

namespace Ui {
class BotMonitor;
}

class BotMonitor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit BotMonitor(QWidget *parent = 0);
    ~BotMonitor();

public slots:
    void processSpiUpdate();            //Process a new update received on the SPI ring
    
private:
    Ui::BotMonitor *ui;
    SpiRing *m_pSpiRing;                //The spi communication path to the PSoC
};

#endif // BOTMONITOR_H
