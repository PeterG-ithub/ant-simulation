#pragma once
#include "Colony.h"

class Environment {
public:
    void createWorldBorder(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
private:
    sf::RectangleShape borderN;
    sf::RectangleShape borderE;
    sf::RectangleShape borderW;
    sf::RectangleShape borderS;
};