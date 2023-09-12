/*
** ShipWreck Engine , 2023
** FileException.hpp
*/

#ifndef SW_PACKER_FILEEXCEPTION_HPP
#define SW_PACKER_FILEEXCEPTION_HPP

#include <exception>
#include <string>

namespace sw
{
    class FileException : public std::exception
    {
    private:
        std::string m_reason;
    public:
        explicit FileException(std::string&& reason);
        [[nodiscard]] const char *what() const override;
    };
}

#endif //SW_PACKER_FILEEXCEPTION_HPP
