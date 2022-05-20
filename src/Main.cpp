#include "Scene.h"
#include "MusicPlayer.h"
#include <iostream>


int main()
{
    float dt;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ducky Game!");
    MusicPlayer music;
    Scene scene(window);
    
    //frame rate management
    sf::Clock clock;
    constexpr float desiredFrameRate = 60.f;
    constexpr float desiredDt = 1 / desiredFrameRate;

    while (window.isOpen())
    {
        dt = clock.getElapsedTime().asSeconds();
        while (dt >= desiredDt)
        {
            clock.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            scene.Update(desiredDt);
            scene.CheckCollisions();
            scene.Draw();

            dt -= desiredDt;
        }
    }
}