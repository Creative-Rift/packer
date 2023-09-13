/*
** ShipWreck Engine , 2023
** MemoryException.hpp
*/

#ifndef SW_PACKER_MEMORYEXCEPTION_HPP
#define SW_PACKER_MEMORYEXCEPTION_HPP

#include <exception>
#include <string>

namespace sw {

    class MemoryException : public std::exception
    {
    private:
        std::string m_message;
    public:
        explicit MemoryException(std::string message);
        [[nodiscard]]const char * what() const override;
    };

} // sw

#endif //SW_PACKER_MEMORYEXCEPTION_HPP
