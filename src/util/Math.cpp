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

// returns 180 to -180
float Math::vectorToDegrees(const sf::Vector2f& direction) {
    return std::atan2(direction.y, direction.x) * 180.0f / 3.1415263f;
}

float Math::getRandomNumberInRange(float min, float max) {
    // Generate a random number between 0 and 1
    float randomFraction = static_cast<float>(rand()) / RAND_MAX;

    // Scale and shift the random fraction to fit within the desired range
    return min + randomFraction * (max - min);
}

sf::Vector2f Math::degreesToVector(const float& degrees) {
    // Convert angle to radians
    float radians = degrees * (3.14159f / 180.f);

    // Calculate the x and y components of the direction vector
    float x = cos(radians);
    float y = sin(radians);

    return sf::Vector2f(x, y);
}