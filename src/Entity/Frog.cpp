#include "Frog.h"
#include "DuckyMath.h"
#include "Components/CircleCollisionComponent.h"
#include "Components/SoundComponent.h"
#include <stdlib.h>
#include <time.h>

Frog::Frog(SceneNode* Parent) :
    ScriptEntity(Parent),
    IUpdateable(Parent->GetScene())
{
    LoadData();

    frogShapeComp = CreateComponent<CircleCollisionComponent>("frogShape");
    frogSoundComp = CreateComponent<SoundComponent>("frogSound");
    catchSoundComp = CreateComponent<SoundComponent>("catchSound");

    frogShapeComp->SetColor(sf::Color::Magenta);
    frogShapeComp->SetRadius(size);
    frogShapeComp->SetCollisionProfile(CollisionMask::FROG);
#ifndef _RELEASE
    frogShapeComp->EnableRendering();
#endif // !_RELEASE

    frogSoundComp->SetSound("Frog", true);
    frogSoundComp->Play();
    catchSoundComp->SetSound("Catch");

    srand(static_cast<unsigned int>(time(NULL)));

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

void Frog::OnUpdate(const float dt)
{
    sf::Vector2u WindowSize = ScenePtr->GetRenderWindow().getSize();

    Move({ speed * xMovementDir * dt, speed * yMovementDir * dt });

    sf::Vector2f WorldPosition = GetWorldPosition();
    if (WorldPosition.x <= size)
        xMovementDir = 1;
    else if (WorldPosition.x >= (WindowSize.x - size))
        xMovementDir = -1;

    if (WorldPosition.y <= size)
        yMovementDir = 1;
    else if (WorldPosition.y >= (WindowSize.y - size))
        yMovementDir = -1;
}

void Frog::Catch()
{
    catchSoundComp->Play();
}

void Frog::TeleportAwayFromPlayer(sf::Vector2f playerLoc)
{
    sf::Vector2<float> newFrogLoc{};
    sf::Vector2u WindowSize = ScenePtr->GetRenderWindow().getSize();

    while (true) 
    {
        newFrogLoc.x = static_cast<float>(rand() % (WindowSize.x - 20) + 10);            //weird numbers so that frog spawns wholly within bounds
        newFrogLoc.y = static_cast<float>(rand() % (WindowSize.y - 20) + 10);

        float distance = VecLength(newFrogLoc - playerLoc);
        if (distance > safeDistance)
            break;
    }
    SetWorldPosition(newFrogLoc);
}

