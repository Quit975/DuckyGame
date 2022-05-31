#include "GreenEnemy.h"

GreenEnemy::GreenEnemy(float x, float y)
{
    enemy = sf::RectangleShape({ 50.f, 50.f });
    enemy.setFillColor(sf::Color::Green);
    enemy.setPosition(x, y);
    enemy.setOrigin(25.f, 25.f);
}

void GreenEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemy);
}

void GreenEnemy::Update(const float dt)
{
    enemy.rotate(0.05f);
    enemy.move(speed * xMovementDir * dt, speed * yMovementDir * dt);
    if (enemy.getPosition().x <= 0.f)
        xMovementDir = 1;
    else if (enemy.getPosition().x >= WindowWidth)
        xMovementDir = -1;

    if (enemy.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (enemy.getPosition().y >= WindowHeight)
        yMovementDir = -1;
}

sf::FloatRect GreenEnemy::GetBounds()
{
    return enemy.getGlobalBounds();
}

sf::Vector2f GreenEnemy::GetLocation()
{
    return enemy.getPosition();
}
