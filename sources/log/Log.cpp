/*
** ShipWreck Engine , 2023
** Log.cpp
*/

#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>

#include "Log.hpp"

std::vector<std::string> sw::Log::m_logs;
std::map<sw::Log::Level, std::string> sw::Log::m_levels =  {
        {NONE, ""},
        {DEBUG, "Debug"},
        {WARNING, "Warning"},
        {ERROR, "Error"},
};

void sw::Log::AddLog(std::string&& message, Level logLevel)
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream ossLog;

    ossLog << "[" << std::put_time(&tm, "%H:%M:%S") << "] " << m_levels[logLevel] << ": " << message;
    m_logs.emplace_back(ossLog.str());
}

void sw::Log::CloseLog()
{
    if (m_logs.empty())
        return;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y_%H-%M-%S");
    std::fstream outFile("./SWPacker_" + oss.str() + ".txt", std::ios::out);

    if (!outFile.is_open()) {
        std::cerr << "ERROR: Unable to create log file! [" << "SWPacker_" + oss.str() << "]" << std::endl;
        return;
    }
    for (const auto & m_log : m_logs) {
        outFile.write(m_log.c_str(), m_log.size());
        outFile.write("\n", 1);
    }
    outFile.close();
}
