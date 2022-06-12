#include "Frog.h"
#include "DuckyMath.h"
#include <stdlib.h>
#include <time.h>

Frog::Frog()
{
    LoadData();

    frogShapeComp.SquareInit(sf::Color::Magenta, size, 400, 300);
    frogSoundComp.Init("Res/froggy.wav", true);
    catchSoundComp.Init("Res/frogCatch.wav");

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
}

void Frog::UpdateData()
{
    frogShapeComp.SetProperties(size);
    frogSoundComp.SetProperties(100.f, croakAttenuation, croakMinDistance);
    catchSoundComp.SetProperties(catchVolume);
}

void Frog::Update(const float dt)
{
    frogShapeComp.GetSquareCollision().move(speed * xMovementDir * dt, speed * yMovementDir * dt);
    if (frogShapeComp.GetPosition().x <= 0.f)
        xMovementDir = 1;
    else if (frogShapeComp.GetPosition().x >= WindowWidth)
        xMovementDir = -1;

    if (frogShapeComp.GetPosition().y <= 0.f)
        yMovementDir = 1;
    else if (frogShapeComp.GetPosition().y >= WindowHeight)
        yMovementDir = -1;

    frogSoundComp.SetPosition(frogShapeComp.GetPosition());
}

void Frog::Draw(sf::RenderWindow& window)
{
#ifndef _RELEASE
    window.draw(frogShapeComp.GetSquareCollision());
#endif
}

sf::FloatRect Frog::GetBounds()
{
    return frogShapeComp.GetBounds();
}

sf::Vector2f Frog::GetLocation()
{
    return frogShapeComp.GetPosition();
}

void Frog::Catch()
{
    catchSoundComp.Play();
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
    frogShapeComp.SetPosition(newFrogLoc);
}

