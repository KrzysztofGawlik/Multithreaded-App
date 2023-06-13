#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ShapeWindow
{
public:
    ShapeWindow(std::string shape);
    ~ShapeWindow() {};

private:
    sf::RenderWindow* mWindow;
    sf::Shape* mShape;
    void handleEvents();
};