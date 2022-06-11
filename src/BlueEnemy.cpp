#include "BlueEnemy.h"
#include <iostream>

BlueEnemy::BlueEnemy(float x, float y)
{
    LoadData();

    enemy = sf::CircleShape(size);
    enemy.setFillColor(sf::Color::Blue);
    enemy.setPosition(x, y);
    enemy.setOrigin(15.f, 15.f);

    collisionShape = sf::CircleShape(collisionRadius);
    collisionShape.setFillColor(sf::Color{ 0, 255, 255, 100 });
    collisionShape.setOrigin(collisionRadius/2, collisionRadius/2);

    UpdateData();
}

void BlueEnemy::LoadData()
{
    lua_State* L = ScriptManager::Get().GetState();

    ReadFloat(L, "blueEnemy", "speed", speed);
    ReadFloat(L, "blueEnemy", "size", size);
    ReadFloat(L, "blueEnemy", "collisionRadius", collisionRadius);
}

void BlueEnemy::UpdateData()
{
    enemy.setRadius(size);
}

void BlueEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemy);

#ifndef _RELEASE
    window.draw(collisionShape);
#endif
}

void BlueEnemy::Update(const float dt)
{
    enemy.move(0.f, speed * yMovementDir * dt);
    if (enemy.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (enemy.getPosition().y >= WindowHeight)
        yMovementDir = -1;

    collisionShape.setPosition(enemy.getPosition().x, enemy.getPosition().y);
}

sf::FloatRect BlueEnemy::GetBounds()
{
    return enemy.getGlobalBounds();
}

sf::Vector2f BlueEnemy::GetLocation()
{
    return enemy.getPosition();
}
