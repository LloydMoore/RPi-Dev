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

#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <QString>


#define BASE_EXCEPTION(msg) BaseException((msg), (__FILE__), (__LINE__))

class BaseException
{
public:
    BaseException();                                                        //Standard constructor
    BaseException(const QString sMessage, const QString file = QString(),
                  const int line = 0);                                      //Constructor with string initializer
    BaseException(const char *cpMessage, const QString file = QString(),
                  const int line = 0);                                      //Constructor with char pointer initializer
    ~BaseException();                                                       //Standard destructor
    QString GetError();                                                     //Get the current error message
    QString GetFile();                                                      //Get the file name the exception occured in
    int GetLine();                                                          //Get the line number the exception occured in
    QString GetFullError();                                                 //Return a composite error message error+file+line

private:
    QString m_ErrorMessage;                                                 //Storage for the attached error message
    int m_LineNumber;                                                       //Line number the exception occured on
    QString m_FileName;                                                     //Filename the exception occured in

};

#endif // BaseException


