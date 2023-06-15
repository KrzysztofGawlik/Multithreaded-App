#include "ShapeWindow.h"

#include <iostream>

ShapeWindow::ShapeWindow(std::string shape)
{
    mWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "Shape", sf::Style::Titlebar | sf::Style::Close);
    mWindow->setFramerateLimit(60);
    sf::Image icon;
    icon.loadFromFile("resources/icon.png");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    mShape = nullptr;
    if (shape == "Triangle")
    {
        sf::ConvexShape* triangle = new sf::ConvexShape(3);
        sf::Vector2f rotationPoint(100, 100);

        triangle->setPoint(0, sf::Vector2f(90, 90));
        triangle->setPoint(1, sf::Vector2f(30, 75));
        triangle->setPoint(2, sf::Vector2f(75, 30));
        triangle->setPosition(rotationPoint.x, rotationPoint.y);
        triangle->setOrigin(rotationPoint);

        mShape = triangle;
    }
    else if (shape == "Rectangle")
    {
        sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(50, 50));
        rect->setPosition(100, 100);

        mShape = rect;
    }
    else if (shape == "Circle")
    {
        sf::CircleShape* circle = new sf::CircleShape(30);
        circle->setPosition(100, 100);
        mShape = circle;
    }
}

void ShapeWindow::init()
{
    while (mWindow->isOpen())
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mWindow->close();
                std::cout << "Closing thread..." << std::endl;
            }
        }

        mWindow->clear();
        mWindow->draw(*mShape);
        mWindow->display();

        mShape->rotate(1);
    }
}