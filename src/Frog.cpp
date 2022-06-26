#include "Frog.h"
#include "DuckyMath.h"
#include "CircleCollisionComponent.h"
#include <stdlib.h>
#include <time.h>

Frog::Frog()
{
    LoadData();

    frogShapeComp = CreateComponent<CircleCollisionComponent>("frogShape");
    frogSoundComp = CreateComponent<SoundComponent>("frogSound");
    catchSoundComp = CreateComponent<SoundComponent>("catchSound");

    frogShapeComp->SetColor(sf::Color::Magenta);
    frogShapeComp->SetPosition(sf::Vector2f(400, 300));
    frogShapeComp->SetRadius(size);
    frogSoundComp->SetSound("Res/froggy.wav", true);
    catchSoundComp->SetSound("Res/frogCatch.wav");

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
}

void Frog::UpdateData()
{
    frogShapeComp->SetRadius(size);
    frogSoundComp->SetAttenuation(croakAttenuation, croakMinDistance);
    frogSoundComp->SetVolume(100.f);
    catchSoundComp->SetVolume(catchVolume);
}

void Frog::Update(const float dt)
{
    frogShapeComp->GetShape().move(speed * xMovementDir * dt, speed * yMovementDir * dt);
    if (frogShapeComp->GetPosition().x <= size)
        xMovementDir = 1;
    else if (frogShapeComp->GetPosition().x >= (WindowWidth - size))
        xMovementDir = -1;

    if (frogShapeComp->GetPosition().y <= size)
        yMovementDir = 1;
    else if (frogShapeComp->GetPosition().y >= (WindowHeight - size))
        yMovementDir = -1;

    frogSoundComp->SetPosition(frogShapeComp->GetPosition());
}

void Frog::Draw(sf::RenderWindow& window)
{
#ifndef _RELEASE
    window.draw(frogShapeComp->GetShape());
#endif
}

sf::Vector2f Frog::GetLocation()
{
    return frogShapeComp->GetPosition();
}

void Frog::Catch()
{
    catchSoundComp->Play();
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
    frogShapeComp->SetPosition(newFrogLoc);
}

