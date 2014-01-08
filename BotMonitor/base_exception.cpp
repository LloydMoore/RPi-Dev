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

#include "base_exception.h"

BaseException::BaseException()
{
    m_ErrorMessage = QString();
    m_LineNumber = 0;
    m_FileName = QString();
}

BaseException::BaseException(const QString sMessage, const QString file, const int line)
{
    m_ErrorMessage = sMessage;
    m_LineNumber = line;
    m_FileName = file;
}

BaseException::BaseException(const char *cpMessage, const QString file, const int line)
{
    m_ErrorMessage = QString(cpMessage);
    m_LineNumber = line;
    m_FileName = file;
}

BaseException::~BaseException()
{

}

QString BaseException::GetError()
{
    return m_ErrorMessage;
}

QString BaseException::GetFile()
{
    return m_FileName;
}

int BaseException::GetLine()
{
    return m_LineNumber;
}

QString BaseException::GetFullError()
{
    return m_ErrorMessage + QString(" in file: %1 at line: %2").arg(m_FileName).arg(m_LineNumber);
}

