#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "Button.h"

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
    sf::Font* mFont;
    std::unordered_map<std::string, Button*> mButtons;

private:
    void setup();
    void addInfoLabel();
    void renderButtons(std::unordered_map<std::string, Button*> map);
    void handleEvents();
};