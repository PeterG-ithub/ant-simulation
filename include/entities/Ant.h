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
    void move(float targetX, float targetY, float velocity, float deltaTime);
    void animate(float deltaTime);
    void setPos(sf::Vector2f pos);
private:
    sf::Texture texture;


    float animationSpeed;
    float animationTime;
    float elapsedTime;
    int numColumns;
    int numRows;
    int totalFrames;
};