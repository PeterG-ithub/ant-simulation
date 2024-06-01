#include "entities/Ant.h"

Ant::Ant() : 
    animationSpeed(60.0f),
    animationTime(1.0f / animationSpeed),
    elapsedTime(0.0f),
    numColumns(4),
    numRows(8),
    velocity(320.0f),
    directionChangeCooldown(2.0f),
    directionChangeTimer(2.0f)
{
}
void Ant::load()
{
    if (texture.loadFromFile("res/images/ant_walk.png"))
    {
        std::cout << "Image loaded" << std::endl;
        sprite.setPosition(sf::Vector2f(0, 0));
        sprite.setScale(sf::Vector2f(0.08, 0.08));
        sprite.setTextureRect(sf::IntRect(0, 0, 202, 248));
        sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f));
        totalFrames = numColumns * numRows;
        direction = randomDirection(180.0f);
    }
    else
    {
        std::cerr << "Image not loaded" << std::endl;
    }
}

void Ant::update(float deltaTime)
{
    calculateTargetPosition();
}

void Ant::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    drawTargetPosition(window);
}

void Ant::move(sf::Vector2f movementDirection, float deltaTime) {
    // Normalize the direction
    direction = Math::normalize(movementDirection);
    // Make ant look at where the direction is
    lookTowards(direction);
    // Update ant's position
    sprite.setPosition(sprite.getPosition() + direction * velocity * deltaTime);
    
}

void Ant::lookTowards(sf::Vector2f direction) {
    float angle = 90.0f + std::atan2(direction.y, direction.x) * 180.0f / 3.1415263f;
    sprite.setRotation(angle);
}

void Ant::moveRandomly(float deltaTime) {
    // Update the timer
    directionChangeTimer += deltaTime * 1000.0f;
    // Check if it's time to change direction
    if (directionChangeTimer >= directionChangeCooldown) {
        directionChangeTimer = 0.0f; // Reset the timer
        if (rand() % 100 < 10) { // 10% chance to change direction
            move(randomDirection(10.0f), deltaTime);
        }
    } else {
        // Continue moving in the current direction
        move(direction, deltaTime);
    }
}

//returns a direction in normalized vector
sf::Vector2f Ant::randomDirection(float peripheralRange) {
    sf::Vector2f currentDirection = direction;
    float direction_d = Math::vectorToDegrees(currentDirection);
    float random_d = Math::getRandomNumberInRange(-peripheralRange, peripheralRange);
    float randomDirection_d = direction_d + random_d;
    return Math::degreesToVector(randomDirection_d);
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

void Ant::setDirection(sf::Vector2f dir)
{
    direction = dir;
}

void Ant::drawTargetPosition(sf::RenderWindow& window) {
    float radius = 2.5f;
    sf::CircleShape target(radius);
    target.setFillColor(sf::Color::Green);
    target.setOrigin(sf::Vector2f(radius, radius));
    target.setPosition(targetPosition);
    window.draw(target);
}

void Ant::calculateTargetPosition() 
{
    targetPosition = sprite.getPosition() + 5.0f * direction;
}