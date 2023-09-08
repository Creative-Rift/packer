/*
** SWPacker , 2023
** packer.hpp
*/

#ifndef SW_PACKER_PACKER_HPP
#define SW_PACKER_PACKER_HPP

#include <string>

#include "Chunk.hpp"

namespace sw {

    class Packer {
        public:
            /// \brief Target path for the process
            static std::string path;

            /// \brief Start packaging process
            ///
            /// \param path     -   std::string
            static void startPackaging(std::string&& path);
        private:
            /// \brief Compute all file in a directory
            ///
            /// \param path     -   std::string
            static void readDirectory(std::string path);

            /// \brief Read all data needed from a single file
            ///
            /// \param path     - std::string
            static void readFile(std::string path);

            /// \brief Fill type from a string into chunkHeader
            ///
            /// \param type     -   std::string
            /// \param header   - sw::chunkHeader
            static void fillType(std::string&& type, chunkHeader& header);

            /// \brief Fill props based on the type of the file
            /// \warning The function must be called after fillType()
            ///
            /// \param data     -   sw::chunkData
            static void fillProps(sw::chunkData& data);

            /// \brief Collect and fill all data from a resourceChunk for a single file
            ///
            /// \param path     -   std::string
            /// \param header   - sw::chunkHeader
            /// \param data     -   sw::chunkData
            static void createChunkData(std::string path, sw::chunkHeader& header, sw::chunkData& data);
    };

} // sw

#endif //SW_PACKER_PACKER_HPP
