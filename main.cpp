#include <iostream>

#include "MainWindow.h"

int main(void)
{
    std::cout << "Application started." << std::endl;

    MainWindow* mainWindow = new MainWindow();
    mainWindow->start();

    std::cout << "Exiting application..." << std::endl;
}