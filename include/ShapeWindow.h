#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum Shape
{
    TRIANGLE,
    RECTANGLE,
    CIRCLE
};

std::string shapeToStdString(Shape s)
{
    switch (s)
    {
    case TRIANGLE :     return "Triangle";
    case RECTANGLE :    return "Rectangle";
    case CIRCLE :       return "Circle";
    default:            return "Unknown";
    }
}

class ShapeWindow
{
public:
    ShapeWindow();
    ~ShapeWindow() {};

private:
    sf::RenderWindow* mWindow;
};