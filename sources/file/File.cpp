/*
** ShipWreck Engine , 2023
** file.cpp
*/

#include <iostream>
#include <filesystem>

#include "File.hpp"

std::fstream sw::File::m_file{};
sw::filePackHeader sw::File::m_header{};

void sw::File::createHeader()
{
    m_header.id[0] = 's';
    m_header.id[1] = 'w';
    m_header.id[2] = 'f';
    m_header.id[3] = 'p';
    m_header.version = 100;
    m_header.fileType = DEVPACK;
}

void sw::File::generateFile(std::string&& fileName, std::string&& path, bool discard)
{
    createHeader();
    if (discard)
        m_file.open(path + fileName + ".swfp", std::ios::out | std::ios::binary | std::ios::trunc);
    else {
        fileName = computeFileName(fileName, path);
        m_file.open(path + fileName + ".swfp", std::ios::out | std::ios::binary);
    }
    m_file.write(reinterpret_cast<const char *>(&m_header), sizeof(filePackHeader));
}

void sw::File::saveFile()
{
    sw::File::m_file.close();
}

void sw::File::writeInFile(const sw::resourceChunk& chunk)
{
    m_file.write(reinterpret_cast<const char *>(&chunk.header), sizeof(sw::chunkHeader));
    m_file.write(reinterpret_cast<const char *>(&chunk.data), sizeof(unsigned int) * 2);
    m_file.write(reinterpret_cast<const char *>(chunk.data.path), chunk.data.pathCount);
    m_file.write(reinterpret_cast<const char *>(chunk.data.data), chunk.header.sizePack);
}

std::string sw::File::computeFileName(std::string &fileName, std::string &path)
{
    unsigned int index = 1;
    std::string newFileName = fileName;

    while(std::filesystem::exists(path + newFileName + ".swfp"))
        newFileName = fileName + std::to_string(index++);
    return newFileName;
}

void sw::File::countFiles(std::string path)
{
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory())
            countFiles(entry.path().string());
        else
            m_header.resourcesCount += 1;
    }
}
