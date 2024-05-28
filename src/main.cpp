#include "entities/Ant.h"
#include "entities/Colony.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ant Simulation");
    Colony colony;
    //----------------Load-------------------------
    colony.load();

    colony.generateAnt();
    
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
        
        window.display();
    }

    return 0;
}