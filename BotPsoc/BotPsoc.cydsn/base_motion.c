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

#include "base_motion.h"

//Private function prototypes
void baseMotion_SetMotorControl(uint8_t motorCommand);

void baseMotion_Start()
{
    baseMotion_SetMotorControl(MC_BRAKE);
    LMotorPwm_Start();
    RMotorPwm_Start();
}


void baseMotion_Update(uint8_t motorCommand, uint16_t rightSpeed, uint16_t leftSpeed)
{
    baseMotion_SetMotorControl(motorCommand);
    LMotorPwm_WriteCompare(leftSpeed);
    RMotorPwm_WriteCompare(rightSpeed);
}


void baseMotion_SetMotorControl(uint8_t motorCommand)
{
    static uint8 motorControlBits[MC_END] = 
    {
        0x0a,                               //MC_BRAKE - Place both motors in the brake/shorted state
        0x05,                               //MC_FORWARD - Drive generally forward, motor speeds will determine actual angle
        0x00,                               //MC_BACKWARD - Drive generally backward, motor speeds will determine actual angle
        0x09,                               //MC_LEFT - Turn hard left, left motor in brake, right motor driving
        0x06,                               //MC_RIGHT - Turn hard right, left motor driving, right motor in brake
        0x01,                               //MC_PIVOT_LEFT - Pivot in place, left motor in reverse, right motor in forward
        0x04,                               //MC_PIVOT_RIGHT - Pivot in place. left motor in forward, right motor in reverse
    };
    
    if(motorCommand >= MC_END) motorCommand = MC_BRAKE;     //If something is wrong then stop!
    MotorControlReg_Write(motorControlBits[motorCommand]);
}

/* [] END OF FILE */
