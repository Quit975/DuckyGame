#include "Frog.h"
#include "DuckyMath.h"
#include <stdlib.h>
#include <time.h>

Frog::Frog()
{
    LoadData();

    frogBuffer.loadFromFile("Res/froggy.wav");
    frogSound.setBuffer(frogBuffer);
    frogSound.setLoop(true);
    frogSound.play();

    frogCatchBuffer.loadFromFile("Res/frogCatch.wav");
    frogCatchSound.setBuffer(frogCatchBuffer);
    frogCatchSound.setAttenuation(0);

    collisionShape = sf::CircleShape(collisionRadius - outlineThickness);
    collisionShape.setOutlineThickness(outlineThickness);
    collisionShape.setOutlineColor(sf::Color{ 0, 255, 255, 150 });
    collisionShape.setFillColor(sf::Color{ 0, 0, 0, 0 });
    collisionShape.setOrigin(collisionRadius, collisionRadius);
    collisionShape.setPosition(400, 300);

    srand(time(NULL));

    UpdateData();
}

void Frog::LoadData()
{
    lua_State* L = ScriptManager::Get().GetState();

    ReadFloat(L, "frog", "speed", speed);
    ReadFloat(L, "frog", "croakAttenuation", croakAttenuation);
    ReadFloat(L, "frog", "croakMinDistance", croakMinDistance);
    ReadFloat(L, "frog", "catchVolume", catchVolume);
    ReadFloat(L, "frog", "safeDistance", safeDistance);
    ReadFloat(L, "frog", "collisionRadius", collisionRadius);
}

void Frog::UpdateData()
{
    frogSound.setAttenuation(croakAttenuation);
    frogSound.setMinDistance(croakMinDistance);
    frogCatchSound.setVolume(catchVolume);
}

void Frog::Update(const float dt)
{
    collisionShape.move(speed * xMovementDir * dt, speed * yMovementDir * dt);
    if (collisionShape.getPosition().x <= 0.f)
        xMovementDir = 1;
    else if (collisionShape.getPosition().x >= WindowWidth)
        xMovementDir = -1;

    if (collisionShape.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (collisionShape.getPosition().y >= WindowHeight)
        yMovementDir = -1;

    collisionShape.setPosition(collisionShape.getPosition().x, collisionShape.getPosition().y);
    frogSound.setPosition(collisionShape.getPosition().x, collisionShape.getPosition().y, 0.f);
}

void Frog::Draw(sf::RenderWindow& window)
{
#ifndef _RELEASE
    window.draw(collisionShape);
#endif
}

sf::Vector2f Frog::GetLocation()
{
    return collisionShape.getPosition();
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
    collisionShape.setPosition(newFrogLoc);
}

