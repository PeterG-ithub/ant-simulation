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
    void calculateTargetPosition();
    void drawTargetPosition(sf::RenderWindow& window);
    sf::Vector2f randomDirection(float peripheralRange);
    sf::Vector2f direction;
    sf::Vector2f targetPosition;
private:
    sf::Texture texture;
    float velocity;
    float directionChangeCooldown; // Cooldown in seconds
    float directionChangeTimer;
    float animationSpeed;
    float animationTime;
    float elapsedTime;
    int numColumns;
    int numRows;
    int totalFrames;
};