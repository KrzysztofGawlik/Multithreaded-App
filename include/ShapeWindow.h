#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ShapeWindow
{
public:
    /**
     * @brief Default constructor, creates new window for rotating shapes
     * @param shape String identifying the name of shape (Triangle/Rectangle/Circle)
    */
    ShapeWindow(std::string shape);
    /**
     * @brief Default destructor
    */
    ~ShapeWindow() {};

    /**
     * @brief Main loop that handles events for the window
    */
    void init();

private:
    /// Instance of the window
    sf::RenderWindow* mWindow;
    /// Properties of the shape displayed inside the window
    sf::Shape* mShape;
};