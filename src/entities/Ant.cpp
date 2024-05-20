#include "entities/Ant.h"
#include "util/Math.h"

Ant::Ant() : animationSpeed(30.0f), animationTime(1.0f / animationSpeed), elapsedTime(0.0f), numColumns(4), numRows(8)
{
    // Constructor
}

void Ant::load()
{
    if (texture.loadFromFile("res/images/ant_walk.png"))
    {
        std::cout << "Image loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(0, 0));
        sprite.setScale(sf::Vector2f(0.2, 0.2));
        sprite.setTextureRect(sf::IntRect(0, 0, 202, 248));
        sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f));
        totalFrames = numColumns * numRows;
    }
    else
    {
        std::cerr << "Image not loaded" << std::endl;
    }
}

void Ant::update(float deltaTime)
{

}

void Ant::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Ant::move(float targetX, float targetY, float velocity, float deltaTime)
{
    sf::Vector2f currentPosition = sprite.getPosition();
    sf::Vector2f direction(targetX - currentPosition.x, targetY - currentPosition.y);
    float distanceToTarget = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    float distance = velocity * deltaTime;
    if (distanceToTarget > distance)
    {
        sf::Vector2f normalizedDirection = Math::normalize(direction);
        // std::cout << normalizedDirection.x << " : " << normalizedDirection.y << std::endl;
        float angle = 90.0f + std::atan2(normalizedDirection.y, normalizedDirection.x) * 180.0f / 3.1415263f;
        // std::cout << angle << std::endl;
        sprite.setRotation(angle);
        sf::Vector2f newPosition(currentPosition.x + normalizedDirection.x * distance, currentPosition.y + normalizedDirection.y * distance);
        sprite.setPosition(newPosition);
    }
}

void Ant::animate(float deltaTime)
{
    elapsedTime += deltaTime;
    int currentFrame = static_cast<int>(elapsedTime / animationTime) % totalFrames;
    int row = currentFrame / numColumns;
    int column = currentFrame % numColumns;
    sprite.setTextureRect(sf::IntRect(column * 202, row * 248, 202, 248));
}

void Ant::setPos(sf::Vector2f pos)
{
    sprite.setPosition(pos);
}