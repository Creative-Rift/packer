/*
** ShipWreck Engine , 2023
** unPackFile.cpp
*/

#include <fstream>
#include <iostream>

#include "UnPackFile.hpp"
#include "File.hpp"

sw::UnPackFile::UnPackFile(std::string path)
{
    std::fstream file;

    file.open(path, std::ios::binary | std::ios::in);
    char *buf = (char *)malloc(sizeof(filePackHeader));

    file.read(buf, sizeof(filePackHeader));

    std::cout << "Id: " << ((filePackHeader*)buf)->id << std::endl;
    std::cout << "Version: " << ((filePackHeader*)buf)->version << std::endl;
    std::cout << "Count: " << ((filePackHeader*)buf)->resourcesCount << std::endl;
}
