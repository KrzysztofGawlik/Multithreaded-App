#include <SFML/Graphics.hpp>

#include "MainWindow.h"

void MainWindow::setup()
{
    // Initiate new window
    mWindow = new sf::RenderWindow(sf::VideoMode(400, 200), "Multithreaded Application");
    mWindow->setFramerateLimit(60);

    // Load font
    sf::Font font;
    font.loadFromFile("resources/arial.ttf");

    // Handle window controls
    while (mWindow->isOpen())
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow->close();
        }
    }

    mWindow->clear();
}

void MainWindow::show()
{
    mWindow->display();
}