/*
** ShipWreck Engine , 2023
** main.cpp
*/

#include <iostream>

#include "File.hpp"
#include "Log.hpp"


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
    try {
#ifdef SWFP_PACKER
    sw::Packer::path = argv[1];

    sw::File::countFiles(sw::Packer::path);
    sw::File::generateFile("packages");
    sw::Packer::startPackaging(argv[1]);
    sw::File::saveFile();
#elif SWFP_UNPACKER
        sw::UnPackFile file{argv[1], (argc >= 3 ? argv[2] : "./")};
#endif
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }
    sw::Log::CloseLog();
    return 0;
}