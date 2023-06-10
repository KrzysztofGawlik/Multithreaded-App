#include <SFML/Graphics.hpp>

#include "Button.h"

Button::Button(std::string text, sf::Color color, int posX, int posY)
{
    mShape = new sf::RectangleShape(sf::Vector2f(75, 40));
    mShape->setFillColor(color);
    mShape->setPosition(posX, posY);

    mLabel = new sf::Text();
    mLabel->setString(text);
    mLabel->setPosition(posX + 10, posY + 5);
    mLabel->setCharacterSize(12);
    mLabel->setColor(sf::Color::Black);
}