#include "Logger.h"

void Logger::log(std::string logMessage)
{
    buffer.push_back(logMessage);
}

std::vector<std::string> Logger::getLogs()
{
    return buffer;
}