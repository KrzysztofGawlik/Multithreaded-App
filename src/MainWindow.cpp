#include <iostream>

#include <SFML/Graphics.hpp>

#include "MainWindow.h"

void MainWindow::setup()
{
    // Initiate new window
    std::cout << "Setting up main window..." << std::endl;
    mWindow = new sf::RenderWindow(sf::VideoMode(800, 300), "Multithreaded Application", sf::Style::Titlebar | sf::Style::Close);
    mWindow->setFramerateLimit(60);
    mWindow->clear(sf::Color::White);

    // Load font
    mFont = new sf::Font();
    if (!mFont->loadFromFile("resources/arial.ttf"))
        std::cout << "Failed to load font!" << std::endl;
    else
        std::cout << "Font loaded successfully." << std::endl;

    // Setting up components
    std::cout << "Adding GUI components..." << std::endl;
    std::cout << "\t- Label" << std::endl;
    addInfoLabel();
    std::cout << "\t- Buttons" << std::endl;
    mButtons["triButton"] = new Button("Triangle", sf::Color::Red, 20, 150);
    mButtons["rectButton"] = new Button("Rectangle", sf::Color::Green, 120, 150);
    mButtons["circButton"] = new Button("Circle", sf::Color::Yellow, 220, 150);
    renderButtons(mButtons);

    std::cout << "GUI ready." << std::endl;
}

void MainWindow::start()
{
    mWindow->display();
    handleEvents();
}

void MainWindow::addInfoLabel()
{
    sf::Text label;
    std::string info = "Author: Krzysztof Gawlik\nAlbum: 147762\n\nProject: Multithreaded application";

    label.setFont(*mFont);
    label.setString(info);
    label.setCharacterSize(16);
    label.setFillColor(sf::Color::Black);
    label.setPosition(20, 20);

    mWindow->draw(label);
}

void MainWindow::renderButtons(std::unordered_map<std::string, Button*> map)
{
    for (auto button : map)
    {
        sf::RectangleShape shape = button.second->getShape();
        sf::Text label = button.second->getLabel();
        label.setFont(*mFont);

        mWindow->draw(shape);
        mWindow->draw(label);
    }
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