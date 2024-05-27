#include "entities/Colony.h"

void Colony::load()
{
    colony.setRadius(50.0f);
    colony.setOrigin(sf::Vector2f(50.0f, 50.0f));
    colony.setPosition(sf::Vector2f(400.0f, 300.0f));
    colony.setFillColor(sf::Color::Red);
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
        ant.move(200.0f, 200.0f, 100.0f, deltaTime);
        ant.animate(deltaTime);
    }
}

void Colony::generateAnt()
{
    Ant ant;
    ant.load();
    ant_texture.loadFromFile("res/images/ant_walk.png");
    ant.sprite.setTexture(ant_texture);
    ant.setPos(colony.getPosition());
    ants.push_back(ant);
}