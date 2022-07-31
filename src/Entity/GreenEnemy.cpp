#include "GreenEnemy.h"
#include "Components/CircleCollisionComponent.h"

GreenEnemy::GreenEnemy(SceneNode* Parent) :
    EnemyEntity(Parent)
{
    LoadData();

    enemyShapeComp = CreateComponent<CircleCollisionComponent>("enemyCollision");
    enemyShapeComp->SetColor(sf::Color::Green);
    enemyShapeComp->SetRadius(size);
    enemyShapeComp->SetCollisionProfile(CollisionMask::ENEMY);
    enemyShapeComp->EnableRendering();

    UpdateData();
}

void GreenEnemy::LoadData()
{
    lua_State* L = ScriptManager::Get().GetState();

    ReadFloat(L, "greenEnemy", "speed", speed);
    ReadFloat(L, "greenEnemy", "size", size);
    ReadFloat(L, "greenEnemy", "rotationSpeed", rotationSpeed);
}

void GreenEnemy::UpdateData()
{
    enemyShapeComp->SetRadius(size);
}

void GreenEnemy::OnUpdate(const float dt)
{
    sf::Vector2u WindowSize = ScenePtr->GetRenderWindow().getSize();

    Rotate(rotationSpeed);
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
