#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Colony 
{
public:
    void load(); // Load resources
    void update(float deltaTime); // Update logic
    void draw(sf::RenderWindow& window); // Draw the ant on the window
private:
    sf::CircleShape colony;
};