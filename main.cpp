#include <iostream>

#include "MainWindow.h"

/**
* @brief Main function invokes main window of the application GUI
*/
int main(void)
{
    std::cout << "Application started." << std::endl;

    MainWindow* mainWindow = new MainWindow();
    mainWindow->start();

    std::cout << "Exiting application..." << std::endl;
}