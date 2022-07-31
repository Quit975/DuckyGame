#include "BlueEnemy.h"
#include "Components/CircleCollisionComponent.h"

BlueEnemy::BlueEnemy(SceneNode* Parent) :
    EnemyEntity(Parent)
{
    LoadData();

    enemyShapeComp = CreateComponent<CircleCollisionComponent>("EnemyCollision");
    enemyShapeComp->SetColor(sf::Color::Blue);
    enemyShapeComp->SetRadius(size);
    enemyShapeComp->SetCollisionProfile(CollisionMask::ENEMY);
    enemyShapeComp->EnableRendering();

    UpdateData();
}

void BlueEnemy::LoadData()
{
    lua_State* L = ScriptManager::Get().GetState();

    ReadFloat(L, "blueEnemy", "speed", speed);
    ReadFloat(L, "blueEnemy", "size", size);
}

void BlueEnemy::UpdateData()
{
    enemyShapeComp->SetRadius(size);
}

void BlueEnemy::OnUpdate(const float dt)
{
    sf::Vector2f WorldPosition = GetWorldPosition();
    sf::Vector2u WindowSize = ScenePtr->GetRenderWindow().getSize();

    Move({ 0.f, speed * yMovementDir * dt });
    if (WorldPosition.y <= size)
        yMovementDir = 1;
    else if (WorldPosition.y >= (WindowSize.y - size))
        yMovementDir = -1;
}