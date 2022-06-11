#include "CollisionCheckManager.h"

void CollisionCheckManager::Check(std::unique_ptr<Player>& player
    , std::unique_ptr<Frog>& frog
    , std::vector<std::unique_ptr<Entity>>& enemies
    , std::unique_ptr<TextCounter>& quackCounter
    , std::unique_ptr<TextCounter>& frogCounter
    , sf::RenderWindow& renderWindow)
{
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(-100, -100);
    renderWindow.draw(shape);
    
    // check collisions with enemies
    bool collided = false;
    sf::Vector2f playerLocation = player->GetLocation();
    for (std::unique_ptr<Entity>& e : enemies)
    {
        sf::Vector2f enemyLocation = e->GetLocation();
        float distanceToEnemy = CalculateDistanceSquared(playerLocation, enemyLocation);
        float intersectEnemyDistance = MaxDistanceNeededToIntersectSquared(player->collisionRadius, e->collisionRadius);
        if (distanceToEnemy <= intersectEnemyDistance)
        {
            if (player->Hit())
            {
                OnPlayerHitEnemy(quackCounter);
            }
            collided = true;
        }
    }
    if (!collided)
    {
        player->ResetHit();
    }

    sf::Vector2f frogLocation = frog->GetLocation();
    float distanceToFrog = CalculateDistanceSquared(playerLocation, frogLocation);
    float intersectFrogDistance = MaxDistanceNeededToIntersectSquared(player->collisionRadius, frog->collisionRadius);
    if (distanceToFrog <= intersectFrogDistance)
    {
        OnPlayerHitFrog(player, frog, frogCounter);
    }
}

float CollisionCheckManager::CalculateDistanceSquared(sf::Vector2f position1, sf::Vector2f position2)
{
    float x = (position1.x - position2.x) * (position1.x - position2.x);
    float y = (position1.y - position2.y) * (position1.y - position2.y);
    return x + y;
}

float CollisionCheckManager::MaxDistanceNeededToIntersectSquared(float radius1, float radius2)
{
    float radiusSum = radius1 + radius2;
    return radiusSum * radiusSum;
}

void CollisionCheckManager::OnPlayerHitEnemy(std::unique_ptr<TextCounter>& quackCounter)
{
    quackCounter->Increase();
}

void CollisionCheckManager::OnPlayerHitFrog(std::unique_ptr<Player>& player, std::unique_ptr<Frog>& frog, std::unique_ptr<TextCounter>& frogCounter)
{
    frogCounter->Increase();
    frog->Catch();
    frog->TeleportAwayFromPlayer(player->GetLocation());
}
