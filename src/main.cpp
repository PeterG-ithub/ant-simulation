#include "entities/Ant.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Ant Simulation");
    Ant ant;
    Ant ant2;

    ant.load();
    ant2.load();

//----------Colony---------------------------
    sf::CircleShape colony;
    colony.setRadius(50.0f);
    colony.setOrigin(sf::Vector2f(50.0f, 50.0f));
    colony.setPosition(sf::Vector2f(400.0f, 300.0f));
    colony.setFillColor(sf::Color::Red);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMicroseconds() / 1000000.0;
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ant2.animate(deltaTime);
        ant.animate(deltaTime);
        std::cout << "ant1" << std::endl;
        ant.move(500.0f, 30.0f, 100.0f, deltaTime);

        std::cout << "ant2" << std::endl;
        ant2.move(200.0f, 200.0f, 100.0f, deltaTime);
        window.clear(sf::Color::White);
        ant.draw(window);
        ant2.draw(window);
        window.draw(colony);
        window.display();
    }

    return 0;
}