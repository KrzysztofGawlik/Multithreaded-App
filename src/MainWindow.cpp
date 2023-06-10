#include <iostream>

#include <SFML/Graphics.hpp>

#include "MainWindow.h"

void MainWindow::setup()
{
    // Initiate new window
    std::cout << "Setting up main window..." << std::endl;
    mWindow = new sf::RenderWindow(sf::VideoMode(630, 300), "Multithreaded Application", sf::Style::Titlebar | sf::Style::Close);
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
    addInfoLabel("Krzysztof Gawlik", "147762", "Multithreaded application");
    std::cout << "\t- Buttons" << std::endl;
    mButtons["triButton"] = new Button("Triangle", sf::Color::Red, 350, 20);
    mButtons["rectButton"] = new Button("Rectangle", sf::Color::Green, 440, 20);
    mButtons["circButton"] = new Button("Circle", sf::Color::Yellow, 530, 20);
    mButtons["appThreads"] = new Button("Process\nInfo", sf::Color(200, 200, 200), 440, 70);
    mButtons["allThreads"] = new Button("Threads\nInfo", sf::Color(200, 200, 200), 530, 70);
    renderButtons(mButtons);
    addSeparator(325, 130, true, 10);
    addSeparator(140, 610, false, 10);

    std::cout << "GUI ready." << std::endl;
}

void MainWindow::start()
{
    mWindow->display();
    handleEvents();
}

void MainWindow::addInfoLabel(std::string author, std::string album, std::string project)
{
    sf::Text label;
    std::string info = "Author: " + author + "\nAlbum: " + album + "\n\nProject: " + project;

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

void MainWindow::addSeparator(int position, int size, bool vertical, int offset)
{
    if (vertical)
    {
        sf::RectangleShape shape(sf::Vector2f(1, size));
        shape.setFillColor(sf::Color(200, 200, 200));
        shape.setPosition(position, offset);
        mWindow->draw(shape);
    }
    else
    {
        sf::RectangleShape shape(sf::Vector2f(size, 1));
        shape.setFillColor(sf::Color(200, 200, 200));
        shape.setPosition(offset, position);
        mWindow->draw(shape);
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