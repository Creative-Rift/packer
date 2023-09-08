/*
** ShipWreck Engine , 2023
** unPackFile.cpp
*/

#include <fstream>
#include <iostream>

#include "UnPackFile.hpp"
#include "File.hpp"
#include "Chunk.hpp"

sw::UnPackFile::UnPackFile(std::string path)
{
    std::fstream file;

    file.open(path, std::ios::binary | std::ios::in);
    char *buf = (char *)malloc(sizeof(filePackHeader));

    file.read(buf, sizeof(filePackHeader));

    std::cout << "Id: " << ((filePackHeader*)buf)->id << std::endl;
    std::cout << "Version: " << ((filePackHeader*)buf)->version << std::endl;
    std::cout << "Count: " << ((filePackHeader*)buf)->resourcesCount << std::endl << std::endl;

    auto *chunkHeader = (char *)malloc(sizeof(sw::chunkHeader));
    auto *chunkData = (char *)malloc(sizeof(unsigned int) * 2);

    file.read(chunkHeader, sizeof(sw::chunkHeader));
    file.read(chunkData, sizeof(unsigned int) * 2);
    std::cout << "chunk size: " << ((sw::chunkHeader*)chunkHeader)->sizePack << std::endl;
    char *pathM = (char *)malloc(((sw::chunkData *)chunkData)->pathCount + 1);
    memset(pathM, '\0', ((sw::chunkData *)chunkData)->pathCount + 1);
    file.read(pathM, ((sw::chunkData *)chunkData)->pathCount);
    std::cout << "path: " << pathM << std::endl;

    std::fstream outFile("./out.png", std::ios::out | std::ios::binary);

    auto *buffer = (unsigned char*)malloc(((sw::chunkHeader*)chunkHeader)->sizeBase + 4);
    memset(buffer, '\0', ((sw::chunkHeader*)chunkHeader)->sizeBase + 4);
    file.read((char *)buffer, ((sw::chunkHeader*)chunkHeader)->sizeBase + 4);
    outFile.write((char *)buffer, ((sw::chunkHeader*)chunkHeader)->sizeBase + 4);


}
