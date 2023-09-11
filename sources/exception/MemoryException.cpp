/*
** ShipWreck Engine , 2023
** MemoryException.cpp
*/

#include "MemoryException.hpp"

sw::MemoryException::MemoryException(std::string message) :
m_message(message)
{}

const char *sw::MemoryException::what() const
{
    return m_message.c_str();
}