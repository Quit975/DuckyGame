#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(float x, float y)
{
    enemy = sf::CircleShape(30.f);
    enemy.setFillColor(sf::Color::Blue);
    enemy.setPosition(x, y);
    enemy.setOrigin(15.f, 15.f);
}

void BlueEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemy);
}

void BlueEnemy::Update(const float dt)
{
    enemy.move(0.f, vel * yMovementDir * dt);
    if (enemy.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (enemy.getPosition().y >= 600.f)
        yMovementDir = -1;
}

sf::FloatRect BlueEnemy::GetBounds()
{
    return enemy.getGlobalBounds();
}
