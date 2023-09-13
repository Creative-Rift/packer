/*
** ShipWreck Engine , 2023
** MemAlloc.cpp
*/

#include <cstdlib>

#include "utils.hpp"
#include "MemoryException.hpp"

void *sw::MemAlloc(size_t size)
{
    void *memory = std::malloc(size);

    if (!memory)
        throw sw::MemoryException("Cannot allocate memory");
    return memory;
}