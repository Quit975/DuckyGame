#include "BlueEnemy.h"
#include "Components/CircleCollisionComponent.h"

BlueEnemy::BlueEnemy(SceneNode* Parent, float x, float y) :
    EnemyEntity(Parent)
{
    LoadData();

    enemyShapeComp = CreateComponent<CircleCollisionComponent>("EnemyCollision");
    enemyShapeComp->SetColor(sf::Color::Blue);
    enemyShapeComp->SetRadius(size);
    enemyShapeComp->SetPosition(x, y);

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

void BlueEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemyShapeComp->GetShape());
}

void BlueEnemy::Update(const float dt)
{
    enemyShapeComp->GetShape().move(0.f, speed * yMovementDir * dt);
    if (enemyShapeComp->GetPosition().y <= size)
        yMovementDir = 1;
    else if (enemyShapeComp->GetPosition().y >= (WindowHeight - size))
        yMovementDir = -1;
}

sf::Vector2f BlueEnemy::GetLocation()
{
    return enemyShapeComp->GetPosition();
}
