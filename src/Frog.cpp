#include "Frog.h"
#include "DuckyMath.h"
#include <stdlib.h>
#include <time.h>

Frog::Frog()
{
    frogShape = sf::RectangleShape({ 20.f, 20.f });
    frogShape.setPosition(400, 300);
    frogShape.setOrigin(10.f, 10.f);
    frogBuffer.loadFromFile("Res/froggy.wav");
    frogSound.setBuffer(frogBuffer);
    frogSound.setLoop(true);
    frogSound.setAttenuation(80.f);
    frogSound.setMinDistance(600.f);
    frogSound.play();

    frogCatchBuffer.loadFromFile("Res/frogCatch.wav");
    frogCatchSound.setBuffer(frogCatchBuffer);
    frogCatchSound.setVolume(50.f);
    frogCatchSound.setAttenuation(0.f);

    srand(time(NULL));
}

void Frog::Update(const float dt)
{
    frogShape.move(speed * xMovementDir * dt, speed * yMovementDir * dt);
    if (frogShape.getPosition().x <= 0.f)
        xMovementDir = 1;
    else if (frogShape.getPosition().x >= WindowWidth)
        xMovementDir = -1;

    if (frogShape.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (frogShape.getPosition().y >= WindowHeight)
        yMovementDir = -1;

    frogSound.setPosition(frogShape.getPosition().x, frogShape.getPosition().y, 0.f);
}

void Frog::Draw(sf::RenderWindow& window)
{
#ifndef _RELEASE
    sf::RectangleShape shape({20.f, 20.f});
    shape.setPosition(frogShape.getPosition().x, frogShape.getPosition().y);
    shape.setFillColor(sf::Color::Magenta);
    window.draw(shape);
#endif // _RELEASE
}

sf::FloatRect Frog::GetBounds()
{
    return frogShape.getGlobalBounds();
}

sf::Vector2f Frog::GetLocation()
{
    return frogShape.getPosition();
}

void Frog::Catch()
{
    frogCatchSound.play(); 
}

void Frog::TeleportAwayFromPlayer(sf::Vector2f playerLoc)
{
    sf::Vector2<float> newFrogLoc{};

    while (true) 
    {
        newFrogLoc.x = rand() % (WindowWidth - 20) + 10;            //weird numbers so that frog spawns wholly within bounds
        newFrogLoc.y = rand() % (WindowHeight - 20) + 10;

        float distance = VecLength(newFrogLoc - playerLoc);
        if (distance > safeDistance)
            break;
    }
    frogShape.setPosition(newFrogLoc);
}

