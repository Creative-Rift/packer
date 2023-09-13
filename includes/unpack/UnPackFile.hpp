/*
** ShipWreck Engine , 2023
** unPackFile.hpp
*/

#ifndef SW_PACKER_UNPACKFILE_HPP
#define SW_PACKER_UNPACKFILE_HPP

#include <string>

#include "Chunk.hpp"

namespace sw {

    class UnPackFile {
        public:
            explicit UnPackFile(std::string path, std::string outputPath = "./");
        private:
            std::fstream m_file;

            void readChunk(std::string& outputPath);
            void createFile(sw::chunkHeader &chunkHeader, std::string path, std::string& outputPath);
    };

} // sw

#endif //SW_PACKER_UNPACKFILE_HPP
