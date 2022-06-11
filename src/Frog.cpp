#include "Frog.h"
#include "DuckyMath.h"
#include <stdlib.h>
#include <time.h>

Frog::Frog()
{
    LoadData();

    frogShape = sf::RectangleShape({ size, size });
    frogShape.setPosition(400, 300);
    frogShape.setOrigin(10.f, 10.f);
    frogShape.setFillColor(sf::Color::Magenta); // for debug draw
    frogBuffer.loadFromFile("Res/froggy.wav");
    frogSound.setBuffer(frogBuffer);
    frogSound.setLoop(true);
    frogSound.play();

    frogCatchBuffer.loadFromFile("Res/frogCatch.wav");
    frogCatchSound.setBuffer(frogCatchBuffer);
    frogCatchSound.setAttenuation(0);

    collisionShape = sf::CircleShape(collisionRadius);
    collisionShape.setFillColor(sf::Color{ 0, 255, 255, 100 });
    collisionShape.setOrigin(collisionRadius, collisionRadius);

    srand(time(NULL));

    UpdateData();
}

void Frog::LoadData()
{
    lua_State* L = ScriptManager::Get().GetState();

    ReadFloat(L, "frog", "speed", speed);
    ReadFloat(L, "frog", "size", size);
    ReadFloat(L, "frog", "croakAttenuation", croakAttenuation);
    ReadFloat(L, "frog", "croakMinDistance", croakMinDistance);
    ReadFloat(L, "frog", "catchVolume", catchVolume);
    ReadFloat(L, "frog", "safeDistance", safeDistance);
    ReadFloat(L, "frog", "collisionRadius", collisionRadius);
}

void Frog::UpdateData()
{
    frogShape.setSize({ size, size });
    frogSound.setAttenuation(croakAttenuation);
    frogSound.setMinDistance(croakMinDistance);
    frogCatchSound.setVolume(catchVolume);
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

    collisionShape.setPosition(frogShape.getPosition().x, frogShape.getPosition().y);
    frogSound.setPosition(frogShape.getPosition().x, frogShape.getPosition().y, 0.f);
}

void Frog::Draw(sf::RenderWindow& window)
{
#ifndef _RELEASE
    window.draw(frogShape);
    window.draw(collisionShape);
#endif
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

