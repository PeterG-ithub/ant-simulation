#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "util/Math.h"

class Ant 
{
public:
    Ant(); // Constructor

    sf::Sprite sprite;

    void load(); // Load resources
    void update(float deltaTime); // Update logic
    void draw(sf::RenderWindow& window); // Draw the ant on the window
    void move(sf::Vector2f movementDirection, float deltaTime);
    void animate(float deltaTime);
    void setPos(sf::Vector2f pos);
    void lookTowards(sf::Vector2f movementDirection);
    void moveRandomly(float deltaTime);
    void setDirection(sf::Vector2f dir);
    sf::Vector2f randomDirection(float peripheralRange);
private:
    sf::Texture texture;
    sf::Vector2f direction;
    float velocity;
    float directionChangeCooldown = 1.0f; // Cooldown in seconds
    float directionChangeTimer = 0.0f;
    float animationSpeed;
    float animationTime;
    float elapsedTime;
    int numColumns;
    int numRows;
    int totalFrames;
};