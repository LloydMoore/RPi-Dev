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

#include <project.h>

#define SPI_DMA_BYTES_PER_BURST 1                           //Number of bytes to transfer to the SPI per burst
#define SPI_DMA_REQUEST_PER_BURST 1                         //Each DMA burst must be individually requested


void ringComs_Start();                                      //Configure and start up the ring communications
void ringComs_DoTransfer();                              //Do updates between the tx/rx buffers and the global image



/* [] END OF FILE */
