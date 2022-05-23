#include "Scene.h"
#include "MusicPlayer.h"

const int WindowWidth = 800.f;
const int WindowHeight = 600.f;

int main()
{
    float dt;
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Ducky Game!");

    MusicPlayer music;
    Scene scene(window);
    bool PlayMusic = true;

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

            scene.Update(dt);
            scene.CheckCollisions();
            scene.Draw();

            dt -= desiredDt;

            //Music can be paused in debug
            #ifndef _RELEASE
            music.ShouldBeMusicPlaying(PlayMusic);
            #endif
        }
    }
}