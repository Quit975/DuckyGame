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
    bool paused = true;
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
               
     
            switch (event.type)
            paused = !paused;
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Escape);
            }
                //std::cout << "Esc was pressed" << std::endl;
            {
                if (event.type == sf::Event::KeyPressed)
                paused = false;
                else if (Keyboard::isKeyPressed(Keyboard::Escape))
                paused = true;
                if (event.type == sf::Event::KeyPressed)

                   
                break;
               
             }
             
            
            }
           
            if (!paused) 
            scene.Update(dt);
            scene.CheckCollisions();
            scene.Draw();
            dt -= desiredDt;
        }
    }
}