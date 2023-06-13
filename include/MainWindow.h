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
    ConsoleView* mConsole;

private:
    void setup();
    void addInfoLabel();
    void renderButtons();
    void renderConsoleView(ConsoleView* console);
    void addSeparator(int position, int size, bool vertical, int offset);
    void handleEvents();
    void refreshGui();
};