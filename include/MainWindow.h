#include <SFML/Graphics.hpp>

class MainWindow
{
public:
    MainWindow() {
        setup();
    };
    ~MainWindow() {};

    void show();

private:
    void setup();

    sf::RenderWindow* mWindow;
};