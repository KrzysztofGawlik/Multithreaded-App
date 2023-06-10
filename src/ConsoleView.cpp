#include <iostream>
#include <SFML/Graphics.hpp>

#include "ConsoleView.h"

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
    mOutput->setCharacterSize(14);
}

void ConsoleView::setupFont(std::string path)
{
    mFont = new sf::Font();
    if (!mFont->loadFromFile(path))
        std::cout << "Failed to load font! (" << path << ")" << std::endl;
}