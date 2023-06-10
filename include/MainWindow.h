#include <SFML/Graphics.hpp>

class MainWindow
{
public:
    MainWindow() {
        setup();
    };
    ~MainWindow() {};

    void show();

protected:
    sf::RenderWindow* mWindow;
    sf::Font* font;

private:
    void setup();
    void addInfoLabel();
    void handleEvents();
};