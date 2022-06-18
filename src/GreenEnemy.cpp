#include "GreenEnemy.h"
#include "CircleCollisionComponent.h"


GreenEnemy::GreenEnemy(float x, float y)
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

void GreenEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemyShapeComp->GetShape());
}

void GreenEnemy::Update(const float dt)
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

sf::FloatRect GreenEnemy::GetBounds()
{
    return enemyShapeComp->GetBounds();
}

sf::Vector2f GreenEnemy::GetLocation()
{
    return enemyShapeComp->GetPosition();
}
