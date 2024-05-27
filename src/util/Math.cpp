#include "util/Math.h"

sf::Vector2f Math::normalize(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0) 
    {
        return sf::Vector2f(vector.x / length, vector.y / length);
    }
    return sf::Vector2f(0, 0);
}

float Math::distance(const sf::Vector2f& point1, const sf::Vector2f& point2) {
    float dx = point2.x - point1.x;
    float dy = point2.y - point1.y;
    return std::sqrt(dx * dx + dy * dy);
}
