#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#define M_PI   3.14159265358979323846264338327950288

class Math 
{
public:
    static sf::Vector2f normalize(const sf::Vector2f& vector);
    static float distance(const sf::Vector2f& point1, const sf::Vector2f& point2);
    static float vectorToDegrees(const sf::Vector2f& direction);
    static float getRandomNumberInRange(float min, float max);
    static sf::Vector2f degreesToVector(const float& degrees);
};
