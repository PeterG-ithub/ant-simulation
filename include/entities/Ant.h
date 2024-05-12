#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Ant 
{
public:
    Ant(); // Constructor

    void load(); // Load resources
    void update(float deltaTime); // Update logic
    void draw(sf::RenderWindow& window); // Draw the ant on the window
    void move(float targetX, float targetY, float velocity, float deltaTime);
private:
    sf::Texture texture;
    sf::Sprite sprite;

    float animationSpeed;
    float animationTime;
    float elapsedTime;
    int numColumns;
    int numRows;
    int totalFrames;
};