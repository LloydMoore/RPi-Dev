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
#include <QApplication>
#include <QDebug>
#include "base_exception.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int retVal = 0;

    try
    {
        BotMonitor w;
        w.show();
        retVal = a.exec();
    }
    catch(BaseException *e)
    {
        qDebug() << "Caught exception in main():" << e->GetFullError();
        delete e;
        retVal = 1;
    }
    
    return retVal;
}
