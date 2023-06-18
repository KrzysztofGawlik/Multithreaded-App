#include "ConsoleView.h"

#include <iostream>
#include <cstdio>
#include <memory>
#include <SFML/Graphics.hpp>

const int BUFFER_SIZE = 128;
const int CHARACTER_SIZE = 12;

ConsoleView::ConsoleView(int width, int height, int offsetX, int offsetY)
{
    mView = std::make_unique<sf::RectangleShape>(sf::Vector2f(width, height));
    mView->setPosition(offsetX, offsetY);
    mView->setFillColor(sf::Color::Black);

    mOutput = std::make_unique<sf::Text>();
    mOutput->setString("Console #\n\nPress any Info button to display results . . .");
    mOutput->setPosition(offsetX + 5, offsetY + 5);
    setupFont("resources/consolas.ttf");
    mOutput->setFont(*mFont);
    mOutput->setCharacterSize(CHARACTER_SIZE);
}

void ConsoleView::setupFont(const std::string& path)
{
    mFont = std::make_unique<sf::Font>();
    if (!mFont->loadFromFile(path)) {
        throw std::runtime_error("Failed to load font: " + path);
    }
}

void ConsoleView::runCommand(const char* command)
{
    std::string result;
    char buffer[BUFFER_SIZE];

    FILE* pipe = _popen(command, "r");
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (!feof(pipe)) {
        if (fgets(buffer, BUFFER_SIZE, pipe) != nullptr) {
            result += buffer;
        }
    }
    _pclose(pipe);

    mOutput->setString(result);
}
