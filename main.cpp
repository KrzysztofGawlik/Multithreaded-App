#include <iostream>
#include <vector>
#include <string>

#include "Logger.h"
#include "MainWindow.h"

int main(void)
{
    Logger* logger = new Logger();
    logger->log("Application started.");

    logger->log("Setting up main window...");
    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();

    logger->log("Closing app...");
}