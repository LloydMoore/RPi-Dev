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

#ifndef RINGCOMS_H
#define RINGCOMS_H

#include <stdint.h>

#define HEADER_VALUE 0xa5a55a5a             //Constant value to be placed into the header members
#define FOOTER_VALUE 0xffffffff             //Constant value to be placed into the footer members

//Motor motion commands
enum MOTOR_COMMAND {
    MC_BRAKE = 0,                           //Place both motors in the brake/shorted state
    MC_FORWARD,                             //Drive generally forward, motor speeds will determine actual angle
    MC_BACKWARD,                            //Drive generally backward, motor speeds will determine actual angle
    MC_LEFT,                                //Turn hard left, left motor in brake, right motor driving
    MC_RIGHT,                               //Turn hard right, left motor driving, right motor in brake
    MC_PIVOT_LEFT,                          //Pivot in place, left motor in reverse, right motor in forward
    MC_PIVOT_RIGHT,                         //Pivot in place. left motor in forward, right motor in reverse
    MC_END                                  //Marker for the last valid command
};

typedef struct _sensoryMembers
{
    uint32_t    sensoryHeader;              //4 byte header/sentinal value
    uint16_t    irDistance;                 //Distance measurement on IR sensor
    uint16_t    leftBumpForce;              //Force measurement applied to left bump sensor
    uint16_t    rightBumpForce;             //Force measurement applied to right bump sensor
    uint16_t    leftBumpField;              //Capsense field strength on left bump sensor
    uint16_t    rightBumpField;             //Capsense field strength on right bump sensor
    uint16_t    batteryLevel;               //Main battery level
    uint16_t    rcLRValue;                  //RC receiver left / right steering channel value
    uint16_t    rcFBValue;                  //RC receiver forward / back drive channel value
    uint16_t    rcCamPanValue;              //RC receiver camera pan channel value
    uint16_t    rcCamTiltValue;             //RC receiver camera tilt channel value
    uint16_t    rcOverrideValue;            //RC receiver system override value (enables RC control)
    uint16_t    rcAuxValue;                 //RC receiver auxillary value
    uint32_t    sensoryFooter;              //4 byte footer/sentinal value
} SensoryMembers;

typedef struct _motorMembers
{
    uint32_t    motorHeader;                //4 byte header/sentinal value
    uint16_t    leftDriveMotor;             //PWM value for the left drive motor
    uint16_t    rightDriveMotor;            //PWM value for the right drive motor
    uint16_t    camPanDrive;                //PWM value for the camera pan servo
    uint16_t    camTiltDrive;               //PWM value for the camera tilt servo
    uint16_t    driveMotorCommand;          //MOTOR_COMMAND value to drive the main motors with
    uint16_t    unused2;                    //Unused slot to balance structure size with SensoryMembers
    uint16_t    unused3;                    //Unused slot to balance structure size with SensoryMembers
    uint16_t    unused4;                    //Unused slot to balance structure size with SensoryMembers
    uint16_t    unused5;                    //Unused slot to balance structure size with SensoryMembers
    uint16_t    unused6;                    //Unused slot to balance structure size with SensoryMembers
    uint16_t    unused7;                    //Unused slot to balance structure size with SensoryMembers
    uint16_t    unused8;                    //Unused slot to balance structure size with SensoryMembers
    uint32_t    motorFooter;                //4 byte footer/sentinal value
} MotorMembers;

typedef struct _spiRingData
{
    SensoryMembers sensory;                 //Sensory members of the communication data ring
    MotorMembers effectors;                 //Drive members of the communication data ring
} SpiRingData;

#endif // RINGCOMS_H
