#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ShapeWindow
{
public:
    ShapeWindow();
    ~ShapeWindow() {};

private:
    sf::RenderWindow* mWindow;
};