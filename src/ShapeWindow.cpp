#include "ShapeWindow.h"

ShapeWindow::ShapeWindow()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "Shape");
    mWindow->setFrameLimit(60);
}