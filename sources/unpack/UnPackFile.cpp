/*
** ShipWreck Engine , 2023
** unPackFile.cpp
*/

#include <fstream>
#include <filesystem>

#include "UnPackFile.hpp"
#include "File.hpp"
#include "FileException.hpp"
#include "utils.hpp"
#include "Log.hpp"

sw::UnPackFile::UnPackFile(std::string path, std::string outputPath)
{
    m_file.open(path, std::ios::binary | std::ios::in);
    char *buf = (char *)sw::MemAlloc(sizeof(filePackHeader));

    m_file.read(buf, sizeof(filePackHeader));

    for (int i = 0; i < 4; i++)
        if (((filePackHeader*)buf)->id[i] != FILE_TYPE[i])
            throw sw::FileException("Incompatible/Corrupted file");

    if (((filePackHeader*)buf)->version != FILE_VERSION)
        throw sw::FileException("Incompatible version " + std::to_string(((filePackHeader*)buf)->version) + " supported version: " + std::to_string(FILE_VERSION));

    for (int i = 0 ; i < ((filePackHeader*)buf)->resourcesCount; i++)
        readChunk(outputPath);
    m_file.close();
    free(buf);
}

void sw::UnPackFile::readChunk(std::string& outputPath)
{
    auto *chunkHeader = (char *)sw::MemAlloc(sizeof(sw::chunkHeader));
    auto *chunkData = (char *)sw::MemAlloc(sizeof(unsigned int) * 2);

    m_file.read(chunkHeader, sizeof(sw::chunkHeader));
    m_file.read(chunkData, sizeof(unsigned int) * 2);
    char *pathM = (char *)sw::MemAlloc(((sw::chunkData *)chunkData)->pathCount + 1);
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
    auto *buffer = (unsigned char*)sw::MemAlloc(chunkHeader.sizeBase);

    memset(buffer, '\0', chunkHeader.sizeBase);
    m_file.read((char *)buffer, chunkHeader.sizeBase);
    try {
        std::fstream outFile(outputPath + path, std::ios::out | std::ios::binary);
        if (outFile.is_open())
            throw sw::FileException("File cannot be created");
        outFile.write((char *)buffer, chunkHeader.sizeBase);
        free(buffer);
    } catch (const sw::FileException& e) {
        sw::Log::AddLog("Cannot create file: " + path, sw::Log::WARNING);
    }
}
