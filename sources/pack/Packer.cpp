/*
** ShipWreck Engine , 2023
** packer.cpp
*/

#include <fstream>
#include <filesystem>
#include <iostream>

#include "Packer.hpp"
#include "Chunk.hpp"
#include "csc32.hpp"
#include "File.hpp"

void sw::Packer::startPackaging(std::string path)
{
    if (!std::filesystem::exists(path)) {
        std::cout << "Path: [" << path << "] doesn't exist!";
        return;
    }
    if (!std::filesystem::is_directory(path)) {
        std::cout << "[" << path << "] id not a path!";
        return;
    }
    readDirectory(path);
}

void sw::Packer::readDirectory(std::string path)
{
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory())
            readDirectory(entry.path().string());
        else
            readFile(entry.path().string());
    }
}

void createChunkData(std::string path, sw::chunkHeader& header, sw::chunkData& data)
{
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open())
        throw std::exception();
    std::streamsize size = file.tellg();
    std::vector<char> buffer(size);

    file.seekg(0, std::ios::beg);
    file.read(buffer.data(), size);

    data.path = (char *)std::malloc(path.size());
    std::memset(data.path, '\0', path.size());
    std::memcpy(data.path, path.data(), path.size());
    data.pathCount = path.size();
    data.propsCount = 0;
    data.props = nullptr;
    data.data = std::malloc(size);
    std::memcpy(data.data, buffer.data(), size);

    header.sizeBase = size;
    header.sizePack = size;
}

void sw::Packer::readFile(std::string path)
{
    sw::resourceChunk chunk{};
    std::filesystem::path path1(path);

    chunk.header.type[0] = 'R';
    chunk.header.type[1] = 'A';
    chunk.header.type[2] = 'W';
    chunk.header.type[3] = 'D';
    chunk.header.id = sw::computeCsc32((unsigned char *)path1.filename().string().data(), path1.filename().string().size());
    createChunkData(path, chunk.header, chunk.data);
    chunk.header.crc32 = sw::computeCsc32((unsigned char *)&chunk.data, sizeof(chunk.data));
    sw::File::m_file.write(reinterpret_cast<const char *>(&chunk.header), sizeof(sw::chunkHeader));
    sw::File::m_file.write(reinterpret_cast<const char *>(&chunk.data), sizeof(unsigned int) * 2);
    sw::File::m_file.write(reinterpret_cast<const char *>(chunk.data.path), chunk.data.pathCount);
    sw::File::m_file.write(reinterpret_cast<const char *>(chunk.data.data), chunk.header.sizePack);
}
