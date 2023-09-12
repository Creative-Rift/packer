/*
** ShipWreck Engine , 2023
** FileException.cpp
*/

#include "FileException.hpp"

sw::FileException::FileException(std::string&& reason) :
m_reason(reason)
{}

const char *sw::FileException::what() const
{
    return m_reason.c_str();
}