#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(float x, float y)
{
    LoadData();

    enemy = sf::CircleShape(size);
    enemy.setFillColor(sf::Color::Blue);
    enemy.setPosition(x, y);
    enemy.setOrigin(15.f, 15.f);

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
    enemy.setRadius(size);
}

void BlueEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemy);
}

void BlueEnemy::Update(const float dt)
{
    enemy.move(0.f, speed * yMovementDir * dt);
    if (enemy.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (enemy.getPosition().y >= WindowHeight)
        yMovementDir = -1;
}

sf::FloatRect BlueEnemy::GetBounds()
{
    return enemy.getGlobalBounds();
}

sf::Vector2f BlueEnemy::GetLocation()
{
    return enemy.getPosition();
}
