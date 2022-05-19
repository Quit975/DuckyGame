#include "Scene.h"
#include "MusicPlayer.h"
#include <iostream>

float dt = 1;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ducky Game!");
    MusicPlayer music;
    Scene scene(window);
    
    //frame rate management
    sf::Clock clock;
    const float frameDur = 0.0167f;       //approx fame duration in seconds for 60fps setting

    while (window.isOpen())
    {
        if (dt >= frameDur) 
        {
            clock.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            scene.Update(dt);
            scene.CheckCollisions();
            scene.Draw();
            
            dt = 0.f;
        }
        dt += clock.getElapsedTime().asSeconds();
    }
}