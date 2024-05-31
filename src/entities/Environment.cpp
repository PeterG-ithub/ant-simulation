#include "entities/Environment.h"

void Environment::createWorldBorder(sf::RenderWindow& window)
{
    borderN = sf::RectangleShape(sf::Vector2f(window.getSize().x, 5.0f));
    borderN.setFillColor(sf::Color::Black);

    borderE = sf::RectangleShape(sf::Vector2f(window.getSize().y, 5.0f));
    borderE.setFillColor(sf::Color::Black);
    borderE.setRotation(90.0f);
    borderE.setPosition(sf::Vector2f(window.getSize().x ,0));

    borderW = sf::RectangleShape(sf::Vector2f(window.getSize().y, 5.0f));
    borderW.setFillColor(sf::Color::Black);
    borderW.setRotation(90.0f);
    borderW.setPosition(sf::Vector2f(5, 0));

    borderS = sf::RectangleShape(sf::Vector2f(window.getSize().x, 5.0f));
    borderS.setFillColor(sf::Color::Black);
    borderS.setPosition(sf::Vector2f(0, window.getSize().y - 5));
}

void Environment::draw(sf::RenderWindow& window)
{
    window.draw(borderN);
    window.draw(borderE);
    window.draw(borderW);
    window.draw(borderS);
}