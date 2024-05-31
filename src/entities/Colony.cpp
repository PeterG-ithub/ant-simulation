#include "entities/Colony.h"

void Colony::load()
{
    colony.setRadius(50.0f);
    colony.setOrigin(sf::Vector2f(50.0f, 50.0f));
    colony.setPosition(sf::Vector2f(900.0f, 500.0f));
    colony.setFillColor(sf::Color::Red);
    ant_texture.loadFromFile("res/images/ant_walk.png");
}

void Colony::draw(sf::RenderWindow &window)
{
    window.draw(colony);
    for (Ant& ant : ants) {
        ant.draw(window);
    }
}

void Colony::update(float deltaTime)
{
    for (Ant& ant : ants) {
        ant.moveRandomly(deltaTime);
        ant.animate(deltaTime);
    }
}

void Colony::generateAnt()
{
    Ant ant;
    ant.load();
    ant.sprite.setTexture(ant_texture);
    ant.setPos(colony.getPosition());
    ants.push_back(ant);
}