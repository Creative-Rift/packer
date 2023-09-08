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
            static std::fstream m_file;
            File();

            void generateFile(std::string path = "./");
            void saveFile();
        private:
            filePackHeader m_header;

            void createHeader();
    };

} // sw

#endif //SW_PACKER_FILE_HPP
