#include <vector>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "ConsoleView.h"
#include "ShapeWindow.h"

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
    std::vector<Button*> mButtons;

private:
    void setup();
    void addInfoLabel(std::string author, std::string album, std::string project);
    void renderButtons();
    void renderConsoleView(ConsoleView* console);
    void addSeparator(int position, int size, bool vertical, int offset);
    void handleEvents();
};