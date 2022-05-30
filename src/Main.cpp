#include "Scene.h"
#include "MusicPlayer.h"
#include "ScriptManager.h"

const int WindowWidth = 800.f;
const int WindowHeight = 600.f;

int main()
{
	ScriptManager::Get().Initialize();

    float dt;
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Ducky Game!");

    MusicPlayer music;
    Scene scene(window);
    music.Toggle();

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

                #ifndef _RELEASE
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::M)
                    {
                        music.Toggle();
                    }

                    if (event.key.code == sf::Keyboard::F5)
                    {
                        ScriptManager::Get().ReloadScripts();
                    }
                } 
                #endif
            }

            scene.Update(dt);
            scene.CheckCollisions();
            scene.Draw();

            dt -= desiredDt;    
        }
    }
}