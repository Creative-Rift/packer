/*
** ShipWreck Engine , 2023
** packer.hpp
*/

#ifndef SW_PACKER_PACKER_HPP
#define SW_PACKER_PACKER_HPP

#include <string>

#include "Chunk.hpp"

namespace sw {

    class Packer {
        public:
            static std::string path;
            static void startPackaging(std::string&& path);
        private:
            static void readDirectory(std::string path);
            static void readFile(std::string path);
            static void fillType(std::string&& type, chunkHeader& header);
            static void fillProps(sw::chunkData& data);
            static void createChunkData(std::string path, sw::chunkHeader& header, sw::chunkData& data);
    };

} // sw

#endif //SW_PACKER_PACKER_HPP
