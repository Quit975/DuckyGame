#include "BlueEnemy.h"


BlueEnemy::BlueEnemy(float x, float y)
{
    LoadData();

    enemyShapeComp.CircleInit(sf::Color::Blue, size, x, y);

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
    enemyShapeComp.SetProperties(size);
}

void BlueEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemyShapeComp.GetCircleCollision());
}

void BlueEnemy::Update(const float dt)
{
    enemyShapeComp.GetCircleCollision().move(0.f, speed * yMovementDir * dt);
    if (enemyShapeComp.GetPosition().y <= 0.f)
        yMovementDir = 1;
    else if (enemyShapeComp.GetPosition().y >= WindowHeight)
        yMovementDir = -1;
}

sf::FloatRect BlueEnemy::GetBounds()
{
    return enemyShapeComp.GetBounds();
}

sf::Vector2f BlueEnemy::GetLocation()
{
    return enemyShapeComp.GetPosition();
}
