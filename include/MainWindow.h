#include <vector>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "ConsoleView.h"
#include "ShapeWindow.h"

/**
* @brief Class which defines main window of the application
*/
class MainWindow
{
public:
    /**
    * @brief Default constructor
    */
    MainWindow() {
        setup();
    };
    /**
    * @brief Default destructor
    */
    ~MainWindow() {};

    /**
    * @brief Function serves as a starting point of main loop
    */
    void start();

protected:
    /// Main window pointer
    sf::RenderWindow* mWindow;
    /// Main window font setup
    sf::Font* mFont;
    /// Stores all main window buttons
    std::vector<Button*> mButtons;
    /// Build-in console like display to print CMD output
    ConsoleView* mConsole;

private:
    /**
     * @brief Creates main window layout with all required components
    */
    void setup();
    /**
     * @brief Creates label with author, student ID and project name
    */
    void addInfoLabel();
    /**
     * @brief Generates all buttons from the buttons array
    */
    void renderButtons();
    /**
     * @brief Generates the view of console like interface
     * @param console Pointer to created ConsoleView instance
    */
    void renderConsoleView(ConsoleView* console);
    /**
     * @brief Adds a line as a separator to the main window
     * @param position Position of the line starting from top left corner
     * @param size Length of the line
     * @param vertical Set to false to get horizontal line, true for vertical
     * @param offset How far from the window edge the line should start
    */
    void addSeparator(int position, int size, bool vertical, int offset);
    /**
     * @brief Main loop for catching events like mouse click
    */
    void handleEvents();
    /**
     * @brief Reloads all components of the GUI
    */
    void refreshGui();
};