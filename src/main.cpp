#include "entities/Ant.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ant Simulation");
    Ant ant;
    ant.load();

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ant.update(deltaTime);

        window.clear(sf::Color::White);
        ant.draw(window);
        window.display();
    }

    return 0;
}