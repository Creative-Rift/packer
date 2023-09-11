/*
** ShipWreck Engine , 2023
** Log.hpp
*/

#ifndef SW_PACKER_LOG_HPP
#define SW_PACKER_LOG_HPP

#include <vector>
#include <string>
#include <map>

namespace sw {

    class Log {
    public:
        enum Level {
            NONE,
            DEBUG,
            WARNING,
            ERROR,
        };
        static void AddLog(std::string&& message, Level logLevel = DEBUG);
        static void CloseLog();

    private:
        static std::vector<std::string> m_logs;
        static std::map<Level, std::string> m_levels;
    };

} // sw

#endif //SW_PACKER_LOG_HPP
