#include <SFML/Graphics.hpp>

/**
 * @brief Class for defining buttons and handling mouse events
*/
class Button
{
public:
    /**
     * @brief Default constructor, prepares button to be drawn
     * @param text Test to be displayed on the button
     * @param color Color of the button
     * @param posX Horizontal position of the button
     * @param posY Vertical position of the button
    */
    Button(std::string text, sf::Color color, int posX, int posY);
    /**
     * @brief Default destructor
    */
    ~Button() {};

    /**
     * @brief Get visual properties of the button
     * @return Instance of button properties
    */
    sf::RectangleShape getShape() { return *mShape; };
    /**
     * @brief Get the text displayed on the button
     * @return Text displayed on the button
    */
    sf::Text getLabel() { return *mLabel; };
    /**
     * @brief Based on button properties verifies if the mouse event has been raised over the button
     * @param x Mouse x position
     * @param y Mouse y position
     * @return True if event was over the button, false otherwise
    */
    bool clicked(int x, int y);

private:
    /// Shape of the button
    sf::RectangleShape* mShape;
    /// Text of the button
    sf::Text* mLabel;
};