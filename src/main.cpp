#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
//---------------Initialize-----------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ant Simulation");
    sf::RectangleShape rectangle;
    sf::Texture texture;
    sf::Sprite sprite;
//---------------Initialize-----------------------------------

//---------------Load-----------------------------------------
    if(texture.loadFromFile("../../res/images/ant_walk.png")) 
    {
        std::cout << "Image loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(0, 0));
        sprite.setScale(sf::Vector2f(0.2, 0.2));


        sprite.setTextureRect(sf::IntRect(0, 0, 202, 248));
    }
    else
    {
        std::cerr << "Image not loaded" << std::endl;
    }

    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(10, 20);

    sf::Clock clock;
    float animationSpeed = 0.1f;
    float animationTime = 1.0f / animationSpeed;
    static float elapsedTime = 0.0f;
    int numColumns = 4;
    int numRows = 8;
    int totalFrames = numColumns * numRows;
//---------------Load-----------------------------------------

//--------------Update---------------------------------------- 
    while (window.isOpen()) 
    {
        sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        sf::Vector2f position = rectangle.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		    rectangle.setPosition(position + sf::Vector2f(0, -1) * (float)deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		    rectangle.setPosition(position + sf::Vector2f(-1, 0) * (float)deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            rectangle.setPosition(position + sf::Vector2f(0, 1) * (float)deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            rectangle.setPosition(position + sf::Vector2f(1, 0) * (float)deltaTime);

        elapsedTime += deltaTime;

        // Calculate current frame index
        int currentFrame = static_cast<int>(elapsedTime / animationTime) % totalFrames;

        // Calculate row and column indices
        int row = currentFrame / numColumns;
        int column = currentFrame % numColumns;

        // Set texture rectangle
        sprite.setTextureRect(sf::IntRect(column * 202, row * 248, 202, 248));
//--------------Update----------------------------------------

//--------------Draw------------------------------------------
        window.clear(sf::Color::White);
        
        window.draw(rectangle);
        window.draw(sprite);

        window.display();
//-------------Draw-------------------------------------------
    }
    return 0;
}