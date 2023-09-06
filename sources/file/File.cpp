/*
** ShipWreck Engine , 2023
** file.cpp
*/

#include <fstream>
#include <iostream>

#include "File.hpp"

sw::File::File()
{
    createHeader();
}

void sw::File::createHeader()
{
    m_header.id[0] = 's';
    m_header.id[1] = 'w';
    m_header.id[2] = 'f';
    m_header.id[3] = 'p';
    m_header.version = 10;
    m_header.resourcesCount = 0;
    m_header.fileType = DEVPACK;

    std::cout << "version: " << m_header.version << std::endl;
}

void sw::File::generateFile(std::string path)
{
    std::fstream newFile;

    newFile.open(path + "packages.swfp", std::ios::out | std::ios::binary);
    newFile.write(reinterpret_cast<const char *>(&m_header), sizeof(filePackHeader));
    newFile.close();
}
