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

    void start();

protected:
    sf::RenderWindow* mWindow;
    sf::Font* mFont;
    std::unordered_map<std::string, Button*> mButtons;

private:
    void setup();
    void addInfoLabel(std::string author, std::string album, std::string project);
    void renderButtons(std::unordered_map<std::string, Button*> map);
    void addSeparator(int position, int size, bool vertical, int offset);
    void handleEvents();
};