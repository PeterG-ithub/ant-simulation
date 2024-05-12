#include "entities/Ant.h"

Ant::Ant() : animationSpeed(0.1f), animationTime(1.0f / animationSpeed), elapsedTime(0.0f), numColumns(4), numRows(8) {
    // Constructor
}

void Ant::load() {
    if (texture.loadFromFile("res/images/ant_walk.png")) {
        std::cout << "Image loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(0, 0));
        sprite.setScale(sf::Vector2f(0.2, 0.2));
        sprite.setTextureRect(sf::IntRect(0, 0, 202, 248));
        totalFrames = numColumns * numRows;
    } else {
        std::cerr << "Image not loaded" << std::endl;
    }
}

void Ant::update(float deltaTime) {
    elapsedTime += deltaTime;
    int currentFrame = static_cast<int>(elapsedTime / animationTime) % totalFrames;
    int row = currentFrame / numColumns;
    int column = currentFrame % numColumns;
    sprite.setTextureRect(sf::IntRect(column * 202, row * 248, 202, 248));
}

void Ant::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}