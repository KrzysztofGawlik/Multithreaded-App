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
    void addInfoLabel();

    sf::RenderWindow* mWindow;
    sf::Font* font;
};