/*
** ShipWreck Engine , 2023
** packer.hpp
*/

#ifndef SW_PACKER_PACKER_HPP
#define SW_PACKER_PACKER_HPP

#include <string>

namespace sw {

    class Packer {
        public:
            static void startPackaging(std::string path);
        private:
            static void readDirectory(std::string path);
            static void readFile(std::string path);
    };

} // sw

#endif //SW_PACKER_PACKER_HPP
