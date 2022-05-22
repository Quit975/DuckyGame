#include "Scene.h"
#include "MusicPlayer.h"

const int WindowWidth = 800.f;
const int WindowHeight = 600.f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Ducky Game!");
    MusicPlayer music;
    Scene scene(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        scene.Update();
        scene.CheckCollisions();
        scene.Draw();
    }
}