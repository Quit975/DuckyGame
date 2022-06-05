#include "Scene.h"
#include "MusicPlayer.h"

using namespace sf;
const int WindowWidth = 800.f;
const int WindowHeight = 600.f;

int main()
{
    float dt;
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Ducky Game!");

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
                        music.Pause();
                    }

                    #ifndef _RELEASE
                     
                    if (event.key.code == sf::Keyboard::M)
                    {
                        

                        music.Toggle();                       
                    }
                     
                    #endif
               }     
                              
            }             
            if (!paused)
            {
                music.Play();
                scene.Update(dt);
                scene.CheckCollisions();  
                scene.Draw();
                
            }
            
            dt -= desiredDt;   
        }
    }
}