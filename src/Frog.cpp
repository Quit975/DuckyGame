#include "Frog.h"
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

    frogSound.setPosition(frogShape.getPosition().x, frogShape.getPosition().y, 0.f);
}

void Frog::Draw(sf::RenderWindow& window)
{
#ifndef _RELEASE
    window.draw(frogShape);
#endif
}

sf::FloatRect Frog::GetBounds()
{
    return frogShape.getGlobalBounds();
}

void Frog::Catch()
{
    frogCatchSound.play();
    float x = rand() % 760 + 20;
    float y = rand() % 560 + 20;
    frogShape.setPosition(x, y);
}

