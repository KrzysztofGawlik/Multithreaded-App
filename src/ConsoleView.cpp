#include "ConsoleView.h"

#include <iostream>
#include <cstdio>

#include <SFML/Graphics.hpp>

ConsoleView::ConsoleView(int width, int height, int offsetX, int offsetY)
{
    mView = new sf::RectangleShape(sf::Vector2f(width, height));
    mView->setPosition(offsetX, offsetY);
    mView->setFillColor(sf::Color::Black);
    
    mOutput = new sf::Text();
    mOutput->setString("Console #\n\nPress any Info button to display results . . .");
    mOutput->setPosition(offsetX + 5, offsetY + 5);
    setupFont("resources/consolas.ttf");
    mOutput->setFont(*mFont);
    mOutput->setCharacterSize(12);
}

void ConsoleView::setupFont(std::string path)
{
    mFont = new sf::Font();
    if (!mFont->loadFromFile(path))
        std::cout << "Failed to load font! (" << path << ")" << std::endl;
}

void ConsoleView::runCommand(const char* command)
{
    std::string result;
    char buffer[128];

    FILE* pipe = _popen(command, "r");
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr) {
            result += buffer;
        }
    }
    _pclose(pipe);

    mOutput->setString(result);
}