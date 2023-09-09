/*
** ShipWreck Engine , 2023
** unPackFile.cpp
*/

#include <fstream>
#include <iostream>
#include <filesystem>

#include "UnPackFile.hpp"
#include "File.hpp"

sw::UnPackFile::UnPackFile(std::string path, std::string outputPath)
{
    m_file.open(path, std::ios::binary | std::ios::in);
    char *buf = (char *)malloc(sizeof(filePackHeader));

    m_file.read(buf, sizeof(filePackHeader));

    std::string id = "SWFP";
    for (int i = 0; i < 4; i++)
        if (((filePackHeader*)buf)->id[i] != id[i]) {
            std::cerr << "Incompatible/Corrupted file" << std::endl;
            return;
        }

    if (((filePackHeader*)buf)->version != 100) {
        std::cerr << "Incompatible version " << ((filePackHeader*)buf)->version << " supported version: 100" << std::endl;
        return;
    }

    for (int i = 0 ; i < ((filePackHeader*)buf)->resourcesCount; i++)
        readChunk(outputPath);
}

void sw::UnPackFile::readChunk(std::string& outputPath)
{
    auto *chunkHeader = (char *)malloc(sizeof(sw::chunkHeader));
    auto *chunkData = (char *)malloc(sizeof(unsigned int) * 2);

    m_file.read(chunkHeader, sizeof(sw::chunkHeader));
    m_file.read(chunkData, sizeof(unsigned int) * 2);
    char *pathM = (char *)malloc(((sw::chunkData *)chunkData)->pathCount + 1);
    memset(pathM, '\0', ((sw::chunkData *)chunkData)->pathCount + 1);
    m_file.read(pathM, ((sw::chunkData *)chunkData)->pathCount);
    createFile(*(sw::chunkHeader*)chunkHeader, pathM, outputPath);
    free(chunkHeader);
    free(chunkData);
    free(pathM);
}

void sw::UnPackFile::createFile(sw::chunkHeader &chunkHeader, std::string path, std::string& outputPath)
{
    std::filesystem::path p(outputPath + path);
    std::filesystem::create_directories(p.parent_path());
    auto *buffer = (unsigned char*)malloc(chunkHeader.sizeBase);
    memset(buffer, '\0', chunkHeader.sizeBase);
    m_file.read((char *)buffer, chunkHeader.sizeBase);
    std::fstream outFile(outputPath + path, std::ios::out | std::ios::binary);
    outFile.write((char *)buffer, chunkHeader.sizeBase);
}
