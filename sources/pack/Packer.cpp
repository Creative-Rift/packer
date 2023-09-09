/*
** ShipWreck Engine , 2023
** packer.cpp
*/

#include <fstream>
#include <filesystem>
#include <iostream>

#include "Packer.hpp"
#include "csc32.hpp"
#include "File.hpp"

std::string sw::Packer::path{};

void sw::Packer::startPackaging(std::string&& path)
{
    if (!std::filesystem::exists(path)) {
        std::cout << "Path: [" << path << "] doesn't exist!";
        return;
    }
    if (!std::filesystem::is_directory(path)) {
        std::cout << "[" << path << "] id not a directory!";
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

void sw::Packer::createChunkData(std::string path, sw::chunkHeader& header, sw::chunkData& data)
{
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open())
        throw std::exception();
    std::streamsize size = file.tellg();
    std::vector<char> buffer(size);

    file.seekg(0, std::ios::beg);
    file.read(buffer.data(), size);

    data.path = (char *)std::malloc(path.size() - sw::Packer::path.size() + 1);
    std::memset(data.path, '\0', path.size() - sw::Packer::path.size() + 1);
    std::memcpy(data.path, path.data() + sw::Packer::path.size(), path.size() - sw::Packer::path.size());
    data.pathCount = path.size() - sw::Packer::path.size();
    fillProps(data);
    data.data = std::malloc(size);
    std::memcpy(data.data, buffer.data(), size);

    header.sizeBase = size;
    header.sizePack = size;
}

void sw::Packer::readFile(std::string path)
{
    sw::resourceChunk chunk{};
    std::filesystem::path path1(path);

    fillType("RAWD", chunk.header);
    chunk.header.id = sw::computeCsc32((unsigned char *)path1.filename().string().data(), path1.filename().string().size());
    createChunkData(path, chunk.header, chunk.data);
    chunk.header.crc32 = sw::computeCsc32((unsigned char *)&chunk.data, sizeof(chunk.data));
    sw::File::writeInFile(chunk);
}

void sw::Packer::fillType(std::string &&type, sw::chunkHeader& header)
{
    for (int i = 0; i < 4; i++)
        header.type[i] = type[i];
}

void sw::Packer::fillProps(sw::chunkData& data)
{
    data.propsCount = 0;
    data.props = nullptr;
}
