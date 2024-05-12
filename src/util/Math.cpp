#include "util/Math.h"

sf::Vector2f Math::normalize(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    return sf::Vector2f(vector.x / length, vector.y / length);
}