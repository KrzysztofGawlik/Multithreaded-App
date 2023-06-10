#include <iostream>

#include "MainWindow.h"

int main(void)
{
    std::cout << "Application started." << std::endl;

    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();

    std::cout << "Exiting application..." << std::endl;
}