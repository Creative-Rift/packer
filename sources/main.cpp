/*
** ShipWreck Engine , 2023
** main.cpp
*/

#include <iostream>

#include "File.hpp"
#ifdef SWFP_PACKER
#include "Packer.hpp"
#elif SWFP_UNPACKER
#include "UnPackFile.hpp"
#endif


int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "ERROR: Missing arguments" << std::endl;
        return 1;
    }
#ifdef SWFP_PACKER
    sw::Packer::path = argv[1];

    sw::File::countFiles(sw::Packer::path);
    sw::File::generateFile("packages");
    sw::Packer::startPackaging(argv[1]);
    sw::File::saveFile();
#elif SWFP_UNPACKER
    sw::UnPackFile file{argv[1], (argc >= 3 ? argv[2] : "./")};
#endif
    return 0;
}