/*
** ShipWreck Engine , 2023
** main.cpp
*/

#include "File.hpp"
#ifdef SWFP_PACKER
#include "Packer.hpp"
#elif SWFP_UNPACKER
#include "UnPackFile.hpp"
#endif


int main()
{
#ifdef SWFP_PACKER
    sw::File::generateFile("packages", R"(G:\Cretative-Rift\packer\out\0.1\)");
    sw::Packer::startPackaging(R"(G:\Cretative-Rift\packer\out\0.1\textures)");
    sw::File::saveFile();
#elif SWFP_UNPACKER
    sw::UnPackFile file{R"(G:\Cretative-Rift\packer\out\0.1\packages.swfp)"};
#endif
    return 0;
}