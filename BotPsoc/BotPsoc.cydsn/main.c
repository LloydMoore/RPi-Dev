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

#define VAR_MAIN

#include <project.h>
#include "bot_psoc.h"
#include "spi_ring.h"
#include "base_motion.h"

int main()
{
    baseMotion_Start();
    ringComs_Start();

    CyGlobalIntEnable; 
    
    for(;;)
    {
        if(g_spiReady) 
        {
            ringComs_DoTransfer();
            g_spiReady = false;
            
            baseMotion_Update(g_spiRing.effectors.driveMotorCommand, 
                g_spiRing.effectors.rightDriveMotor,
                g_spiRing.effectors.leftDriveMotor);
        }
    }
}

/* [] END OF FILE */
