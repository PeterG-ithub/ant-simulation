#include "entities/Ant.h"
#include "entities/Colony.h"
#include "entities/Environment.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ant Simulation");
    std::srand(std::time(nullptr));
    Colony colony;
    Environment env;
    //----------------Load-------------------------
    colony.load();
    env.createWorldBorder(window);
    for (size_t i = 0; i < 20; i++)
    {
        colony.generateAnt();
    }

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMicroseconds() / 1000000.0;
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    //----------------Update-------------------------
        colony.update(deltaTime);
    //------------------Draw--------------------------
        window.clear(sf::Color::White);
        colony.draw(window);
        env.draw(window);
        window.display();
    }

    return 0;
}