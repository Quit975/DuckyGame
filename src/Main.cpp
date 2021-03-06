#include "Scene/Scene.h"
#include "MusicPlayer.h"
#include "Scripting/ScriptManager.h"
#include "ResourceManager.h"

const int WindowWidth = 800;
const int WindowHeight = 600;

int main()
{
	ScriptManager::Get().Initialize();
    ResourceManager::Get().LoadResources(); 

    float dt;
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Ducky Game!", sf::Style::Titlebar | sf::Style::Close);
    MusicPlayer music;
    Scene scene(window);

    //frame rate management
    sf::Clock clock;
    constexpr float desiredFrameRate = 60.f;
    constexpr float desiredDt = 1 / desiredFrameRate;

    bool paused = false;
    
    while (window.isOpen())
    {
        dt = clock.getElapsedTime().asSeconds();
        
        // tempshit guard against monster dt when debugging
        if (dt > desiredDt * 3)
            dt = desiredDt * 3;

        while (dt >= desiredDt)
        {
            clock.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                
                if (event.type == sf::Event::KeyReleased)
                {

                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        paused = !paused;
                        if (paused) {
                           music.Pause();
                        }
                        else {
                           music.Play();
                        }
                            
                    }
                  
                    #ifndef _RELEASE
                    if (event.key.code == sf::Keyboard::M && paused == false)
                    {
                        music.Toggle();
                    }
                    #endif
               
                    if (event.key.code == sf::Keyboard::F5)
                    {
                        ScriptManager::Get().ReloadScripts();
                    }
                }  
            }   
       
            if (!paused)
            {
                scene.Update(dt);
                scene.CheckCollisions();
                scene.Draw();
            }
                dt -= desiredDt;    
        }
    }   

    ResourceManager::Get().UnloadResources();
}