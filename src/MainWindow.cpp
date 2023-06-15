#include "MainWindow.h"

#include <iostream>
#include <windows.h>
#include <thread>

#include <SFML/Graphics.hpp>

DWORD currProcId = GetCurrentProcessId();

void MainWindow::setup()
{
    // Initiate new window
    std::cout << "Setting up main window..." << std::endl;
    mWindow = new sf::RenderWindow(sf::VideoMode(630, 300), "Multithreaded Application", sf::Style::Titlebar | sf::Style::Close);
    mWindow->setFramerateLimit(60);
    mWindow->clear(sf::Color::White);
    sf::Image icon;
    icon.loadFromFile("resources/icon.png");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load font
    mFont = new sf::Font();
    std::string path = "resources/arial.ttf";
    if (!mFont->loadFromFile(path))
        std::cout << "Failed to load font! (" << path << ")" << std::endl;
    else
        std::cout << "Font loaded successfully." << std::endl;

    // Setting up components
    std::cout << "Adding GUI components..." << std::endl;
    std::cout << "\t- Label" << std::endl;

    addInfoLabel();
    std::cout << "\t- Buttons" << std::endl;
    mButtons.push_back(new Button("Triangle", sf::Color::Red, 350, 20));
    mButtons.push_back(new Button("Rectangle", sf::Color::Green, 440, 20));
    mButtons.push_back(new Button("Circle", sf::Color::Yellow, 530, 20));
    mButtons.push_back(new Button("Process\nInfo", sf::Color(200, 200, 200), 440, 70));
    mButtons.push_back(new Button("Threads\nInfo", sf::Color(200, 200, 200), 530, 70));
    renderButtons();

    addSeparator(325, 130, true, 10);
    addSeparator(140, 610, false, 10);

    std::cout << "\t- Console View" << std::endl;
    // Generate console here
    mConsole = new ConsoleView(610, 130, 10, 155);
    renderConsoleView(mConsole);

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

void MainWindow::renderButtons()
{
    for (auto button : mButtons)
    {
        sf::RectangleShape shape = button->getShape();
        sf::Text label = button->getLabel();
        label.setFont(*mFont);

        mWindow->draw(shape);
        mWindow->draw(label);
    }
}

void MainWindow::renderConsoleView(ConsoleView* console)
{
    mWindow->draw(console->getView());
    mWindow->draw(console->getOutput());
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

            if (event.type == sf::Event::MouseButtonReleased 
                && event.mouseButton.button == sf::Mouse::Left)
            {
                int mousePosX = event.mouseButton.x;
                int mousePosY = event.mouseButton.y;

                for (auto button : mButtons)
                {
                    if (button->clicked(mousePosX, mousePosY))
                    {
                        std::string shapeLabel = button->getLabel().getString();

                        if (shapeLabel == "Process\nInfo")
                        {
                            // Handle process info
                            std::string command = "tasklist /fi \"PID eq " + std::to_string(currProcId) + "\"";
                            mConsole->runCommand(command.c_str());
                            refreshGui();
                        }
                        else if (shapeLabel == "Threads\nInfo")
                        {
                            // Handle thread info
                            std::string command = "wmic process where \"ProcessId = " + std::to_string(currProcId) + "\" get Caption, ProcessId, ThreadCount";
                            mConsole->runCommand(command.c_str());
                            refreshGui();
                        }
                        else
                        {
                            auto createSubwindowOnNewThread = [=](std::string shape) {
                                ShapeWindow* subwindow = new ShapeWindow(shapeLabel);
                                subwindow->init();
                            };
                            std::thread thread(createSubwindowOnNewThread, shapeLabel);
                            thread.detach();
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::refreshGui()
{
    mWindow->clear(sf::Color::White);
    addInfoLabel();
    renderButtons();
    addSeparator(325, 130, true, 10);
    addSeparator(140, 610, false, 10);
    renderConsoleView(mConsole);
    mWindow->display();
}