#include <iostream>

#include <SFML/Graphics.hpp>

#include "MainWindow.h"

void MainWindow::setup()
{
    // Initiate new window
    std::cout << "Setting up main window..." << std::endl;
    mWindow = new sf::RenderWindow(sf::VideoMode(400, 200), "Multithreaded Application", sf::Style::Titlebar | sf::Style::Close);
    mWindow->setFramerateLimit(60);
    mWindow->clear(sf::Color::White);

    // Load font
    font = new sf::Font();
    if (!font->loadFromFile("resources/arial.ttf"))
        std::cout << "Failed to load font!" << std::endl;
    else
        std::cout << "Font loaded successfully." << std::endl;

    // Setting up components
    std::cout << "Adding components..." << std::endl;
    addInfoLabel();
}

void MainWindow::show()
{
    mWindow->display();
    handleEvents();
}

void MainWindow::addInfoLabel()
{
    std::cout << "\t- Label" << std::endl;
    sf::Text label;
    std::string info = "Author: Krzysztof Gawlik\nAlbum: 147762\n\nProject: Multithreaded application";

    label.setFont(*font);
    label.setString(info);
    label.setCharacterSize(16);
    label.setFillColor(sf::Color::Black);
    label.setPosition(50, 50);

    mWindow->draw(label);
}

void MainWindow::handleEvents()
{
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
}