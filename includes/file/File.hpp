/*
** SWPacker , 2023
** file.hpp
*/

#ifndef SW_PACKER_FILE_HPP
#define SW_PACKER_FILE_HPP

#include <string>
#include <fstream>
#include <vector>

#include "Chunk.hpp"

#define FILE_TYPE "SWFP"
#define FILE_VERSION 100

namespace sw {

    /// \brief Define the type of the file
    /// \def GAMEPACK - File build for an Engine/Game not made to be unpack
    /// \def DEVPACK - File build to pack files and made to be unpacked
    enum fileType {
        GAMEPACK,
        DEVPACK
    };

    /// \brief Define the file header
    struct filePackHeader {
        unsigned char id[4];            // Id of the file: swfp
        unsigned short version;         // Version of the packer
        unsigned char fileType;         // File type
        unsigned short resourcesCount;  // Number of resources in the file
        unsigned int reserved[2];       // reserved for more data
    };

    class File {
        public:
            /// \brief Generate the output file and his header
            ///
            /// \param fileName - std::string
            /// \param path     - std::string
            /// \param discard  - boolean
            static void generateFile(std::string&& fileName = "packages", std::string&& path = "./", bool discard = false);

            /// \brief Save and close the file
            static void saveFile();

            /// \brief Write in the current file the given chunk
            ///
            /// \param chunk    - sw::resourceChunk
            static void writeInFile(const sw::resourceChunk& chunk);

            /// \brief Count the number of files in the path (dir and subdir)
            ///
            /// \param path - std::string
            static void countFiles(std::string path);
        private:
            static filePackHeader m_header;
            static std::fstream m_file;

            /// \brief Fill the header
            static void createHeader();

            /// \brief Check the file name exist, if yes find the one who doesn't exist
            ///
            /// \param fileName - std::string
            /// \param path     - std::string
            /// \return         std::string
            static std::string computeFileName(std::string& fileName, std::string& path);
    };

} // sw

#endif //SW_PACKER_FILE_HPP
