#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ShapeWindow
{
public:
    ShapeWindow(std::string shape);
    ~ShapeWindow() {};

    void init();

private:
    sf::RenderWindow* mWindow;
    sf::Shape* mShape;
};