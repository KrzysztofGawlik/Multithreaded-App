#include <SFML/Graphics.hpp>

class ConsoleView
{
public:
    ConsoleView(int width, int height, int offsetX, int offsetY);
    ~ConsoleView() {};

    void setupFont(std::string path);

    sf::RectangleShape getView() { return *mView; }
    sf::Text getOutput() { return *mOutput; }

private:
    sf::RectangleShape* mView;
    sf::Font* mFont;
    sf::Text* mOutput;
};