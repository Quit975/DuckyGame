#include "GreenEnemy.h"
#include "Components/CircleCollisionComponent.h"

GreenEnemy::GreenEnemy(SceneNode* Parent, float x, float y) :
    EnemyEntity(Parent)
{
    LoadData();

    enemyShapeComp = CreateComponent<CircleCollisionComponent>("enemyCollision");
    enemyShapeComp->SetColor(sf::Color::Green);
    enemyShapeComp->SetRadius(size);
    enemyShapeComp->SetPosition(x, y);

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
    enemyShapeComp->GetShape().rotate(rotationSpeed);
    enemyShapeComp->GetShape().move(speed * xMovementDir * dt, speed * yMovementDir * dt);
    if (enemyShapeComp->GetPosition().x <= size)
        xMovementDir = 1;
    else if (enemyShapeComp->GetPosition().x >= (WindowWidth- size))
        xMovementDir = -1;

    if (enemyShapeComp->GetPosition().y <= size)
        yMovementDir = 1;
    else if (enemyShapeComp->GetPosition().y >= (WindowHeight- size))
        yMovementDir = -1;
}
