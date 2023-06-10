#include <iostream>
#include <vector>
#include <string>

#include "Logger.h"

int main(void)
{
    Logger* logger = new Logger();
    logger->log("Application started.");

    logger->log("Closing app...");
    std::vector<std::string> logData = logger->getLogs();
    for (auto log : logData)
    {
        std::cout << log << std::endl;
    }
}