#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(std::string text, sf::Color color, int posX, int posY);
    ~Button() {};

    sf::RectangleShape getShape() { return *mShape; };
    sf::Text getLabel() { return *mLabel; };
    bool clicked(int x, int y);

private:
    sf::RectangleShape* mShape;
    sf::Text* mLabel;
};