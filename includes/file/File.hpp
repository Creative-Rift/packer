/*
** ShipWreck Engine , 2023
** file.hpp
*/

#ifndef SW_PACKER_FILE_HPP
#define SW_PACKER_FILE_HPP

#include <string>
#include <fstream>
#include <vector>

#include "Chunk.hpp"

namespace sw {

    enum fileType {
        GAMEPACK,
        DEVPACK
    };

    struct filePackHeader {
        unsigned char id[4];
        unsigned short version;
        unsigned char fileType;
        unsigned short resourcesCount;
        unsigned int reserved[2];
    };

    class File {
        public:
            static void generateFile(std::string&& fileName = "packages", std::string&& path = "./", bool discard = false);
            static void saveFile();
            static void writeInFile(const sw::resourceChunk& chunk);
            static void countFiles(std::string path);
        private:
            static filePackHeader m_header;
            static std::fstream m_file;

            static void createHeader();
            static std::string computeFileName(std::string& fileName, std::string& path);
    };

} // sw

#endif //SW_PACKER_FILE_HPP
