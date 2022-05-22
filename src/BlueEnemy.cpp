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

void BlueEnemy::Update(int WindowWidth, int WindowHeight)
{
    extern int WindowHeight; 
    enemy.move(0.f, 0.1f * yMovementDir);
    if (enemy.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (enemy.getPosition().y >= 600.f)
        yMovementDir = -1;
}

sf::FloatRect BlueEnemy::GetBounds()
{
    return enemy.getGlobalBounds();
}
