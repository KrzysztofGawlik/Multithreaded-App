#include <SFML/Graphics.hpp>

/**
 * @brief Build-in console like display to print CMD output
*/
class ConsoleView
{
public:
    /**
     * @brief Default constructor
     * @param width Width of console view
     * @param height Height of console view
     * @param offsetX Horizontal shift from the left edge of window
     * @param offsetY Vertical shift from the top edge of window
    */
    ConsoleView(int width, int height, int offsetX, int offsetY);
    /**
     * @brief Default destructor
    */
    ~ConsoleView() {};

    /**
     * @brief Loads font from .ttf file
     * @param path Path to .ttf file
    */
    void setupFont(std::string path);
    /**
     * @brief Executes Windows commands and displays output in Console View
     * @param command Command to be executed
    */
    void runCommand(const char* command);

    /**
     * @brief Get properties of ConsoleView shape
     * @return Instance of properties from ConsoleView shape
    */
    sf::RectangleShape getView() { return *mView; }
    /**
     * @brief Get text currently stored in ConsoleView
     * @return SFML Text currently stored in ConsoleView
    */
    sf::Text getOutput() { return *mOutput; }

private:
    /// Background properties
    sf::RectangleShape* mView;
    /// Font loaded
    sf::Font* mFont;
    /// Stored text content
    sf::Text* mOutput;
};