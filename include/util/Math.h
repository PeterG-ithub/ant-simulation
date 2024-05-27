#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class Math 
{
public:
    static sf::Vector2f normalize(const sf::Vector2f& vector);
    static float distance(const sf::Vector2f& point1, const sf::Vector2f& point2);
};
