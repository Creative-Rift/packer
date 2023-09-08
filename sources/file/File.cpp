/*
** ShipWreck Engine , 2023
** file.cpp
*/

#include <iostream>

#include "File.hpp"

std::fstream sw::File::m_file{};

sw::File::File() :
m_header()
{
    createHeader();
}

void sw::File::createHeader()
{
    m_header.id[0] = 's';
    m_header.id[1] = 'w';
    m_header.id[2] = 'f';
    m_header.id[3] = 'p';
    m_header.version = 100;
    m_header.resourcesCount = 0;
    m_header.fileType = DEVPACK;
}

void sw::File::generateFile(std::string path)
{
    m_file.open(path + "/packages.swfp", std::ios::out | std::ios::binary);
    m_file.write(reinterpret_cast<const char *>(&m_header), sizeof(filePackHeader));
}

void sw::File::saveFile()
{
    sw::File::m_file.close();
}
