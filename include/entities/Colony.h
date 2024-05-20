#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "entities/Ant.h"

class Colony 
{
public:
    std::vector<Ant> ants;
    sf::Texture ant_texture;

    void load(); // Load resources
    void update(float deltaTime); // Update logic
    void draw(sf::RenderWindow& window); // Draw the ant on the window
    void generateAnt();
private:
    sf::CircleShape colony;
};