/*
** ShipWreck Engine , 2023
** packer.cpp
*/

#include <fstream>
#include <filesystem>
#include <iostream>

#include "Packer.hpp"

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

void sw::Packer::readFile(std::string path)
{
    std::cout << path << std::endl;
}
