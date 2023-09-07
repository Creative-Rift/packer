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
    std::fstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open())
        throw std::exception();
    std::streamsize size = file.tellg();
    std::vector<char> buffer(size);

    file.seekg(0, std::ios::beg);
    file.read(buffer.data(), size);

    data.path = path.data();
    data.propsCount = 0;
    data.props = nullptr;
    data.data = std::malloc(size);
    std::memcpy(data.data, buffer.data(), size);

    header.sizeBase = size;
    header.sizePack = size;
}

void sw::Packer::readFile(std::string path)
{
    sw::chunkHeader header{};
    sw::chunkData data{};
    std::filesystem::path path1(path);

    header.type[0] = 'R';
    header.type[1] = 'A';
    header.type[2] = 'W';
    header.type[3] = 'D';
    createChunkData(path, header, data);
    header.id = sw::computeCsc32(path1.filename().string().data(), path1.filename().string().size());
    header.crc32 = sw::computeCsc32((char *)&data, sizeof(data));
}
