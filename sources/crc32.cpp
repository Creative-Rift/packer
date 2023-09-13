/*
** ShipWreck Engine , 2023
** crc32.cpp
*/

#include "csc32.hpp"

unsigned int sw::computeCsc32(unsigned char *buffer, unsigned int len)
{
    unsigned int crc = ~0u;

    for (int i = 0; i < len; i++)
        crc = (crc >> 8)^sw::crcTable[buffer[i]^(crc&0xff)];
    return ~crc;
}