#include "entities/Colony.h"

void Colony::load()
{
    colony.setRadius(50.0f);
    colony.setOrigin(sf::Vector2f(50.0f, 50.0f));
    colony.setPosition(sf::Vector2f(400.0f, 300.0f));
    colony.setFillColor(sf::Color::Red);
}

void Colony::draw(sf::RenderWindow &window)
{
    window.draw(colony);
}

void Colony::update(float deltaTime)
{

}