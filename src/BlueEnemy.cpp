#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(float x, float y)
{
    LoadData();

    enemy = sf::CircleShape(size);
    enemy.setFillColor(sf::Color::Blue);
    enemy.setPosition(x, y);
    enemy.setOrigin(32.f, 32.f); // why 32? I have no idea but it somehow fixes the origin to the centre o-o

    collisionShape = sf::CircleShape(collisionRadius - outlineThickness);
    collisionShape.setOutlineThickness(outlineThickness);
    collisionShape.setOutlineColor(sf::Color{ 0, 255, 255, 200 });
    collisionShape.setFillColor(sf::Color{ 0, 0, 0, 0 });
    collisionShape.setOrigin(collisionRadius, collisionRadius);

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

sf::Vector2f BlueEnemy::GetLocation()
{
    return enemy.getPosition();
}
