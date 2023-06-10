#include <SFML/Graphics.hpp>

#include "MainWindow.h"

void MainWindow::setup()
{
    // Initiate new window
    mWindow = new sf::RenderWindow(sf::VideoMode(400, 200), "Multithreaded Application");
    mWindow->setFramerateLimit(60);

    // Load font
    font.loadFromFile("resources/arial.ttf");

    // Handle events
    while (mWindow->isOpen())
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow->close();
        }
    }

    addInfoLabel();

    mWindow->clear();
}

void MainWindow::show()
{
    mWindow->display();
}

void MainWindow::addInfoLabel()
{
    sf::Text label;
    std::string info = "Author: Krzysztof Gawlik\nAlbum: 147762\n\nProject: Multithreaded application";

    label.setFont(font);
    label.setString(info);
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::Black);
    label.setPosition(50, 50);

    mWindow->draw(label);
}