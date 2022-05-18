#include "Scene.h"
#include "MusicPlayer.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ducky Game!");
    MusicPlayer music;
    Scene scene(window);
    sf::Clock clock;
    float dt = 0.f;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        scene.Update(dt);
        scene.CheckCollisions();
        scene.Draw();
        sf::Time dTime = clock.restart();
        dt = dTime.asSeconds();
    }
}