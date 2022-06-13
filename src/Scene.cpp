#include "Scene.h"

Scene::Scene(sf::RenderWindow& window):
    renderWindow{window}
{
    bg = std::unique_ptr<Background>(new Background());
    player = std::unique_ptr<Player>(new Player());
    frog = std::unique_ptr<Frog>(new Frog());

    enemies.push_back(std::unique_ptr<Entity>(new GreenEnemy(650.f, 200.f)));
    enemies.push_back(std::unique_ptr<Entity>(new GreenEnemy(150.f, 100.f)));
    enemies.push_back(std::unique_ptr<Entity>(new BlueEnemy(400.f, 500.f)));

    quackCounter = std::unique_ptr<TextCounter>(new TextCounter(50.f, 50.f, "Quack", sf::Color::Red));
    frogCounter = std::unique_ptr<TextCounter>(new TextCounter(500.f, 50.f, "Frog", sf::Color::Green));

    updateGroup.push_back(player.get());
    updateGroup.push_back(frog.get());
   
    drawGroup.push_back(player.get()); // Player* <- Entity*
    drawGroup.push_back(quackCounter.get());
    drawGroup.push_back(frogCounter.get());

#ifndef _RELEASE
    drawGroup.push_back(frog.get());
#endif // _RELEASE

    for (std::unique_ptr<Entity>& e : enemies)
    {
        updateGroup.push_back(e.get());
        drawGroup.push_back(e.get());
    }
}

Scene::~Scene()
{
    
}

void Scene::Update(const float dt)
{
    for (Entity* e : updateGroup)
    {
        e->Update(dt);
    }
}

void Scene::CheckCollisions()
{
    // check collisions with enemies
    bool collided = false;
    sf::Vector2f playerLocation = player->GetLocation();
    for (std::unique_ptr<Entity>& e : enemies)
    {
        sf::Vector2f enemyLocation = e->GetLocation();
        float distanceToEnemy = DistanceBetweenPointsSquared(playerLocation, enemyLocation);
        float distanceToCollideWithEnemy = player->collisionRadius + e->collisionRadius;
        distanceToCollideWithEnemy *= distanceToCollideWithEnemy; // to make it squared since distance is also calculated as squared
        if (distanceToEnemy <= distanceToCollideWithEnemy)
        {
            if (player->Hit()) quackCounter->Increase();          
            collided = true;
        }
    }
    if (!collided)
    {
        player->ResetHit();
    }

    // check collision with a frog
    sf::Vector2f frogLocation = frog->GetLocation();
    float distanceToFrog = DistanceBetweenPointsSquared(playerLocation, frogLocation);
    float distanceToCollideWithFrog = player->collisionRadius + frog->collisionRadius;
    distanceToCollideWithFrog *= distanceToCollideWithFrog; // to make it squared since distance is also calculated as squared
    if (distanceToFrog <= distanceToCollideWithFrog)
    {
        frogCounter->Increase();
        frog->Catch();
        frog->TeleportAwayFromPlayer(player->GetLocation());
    }
}

float Scene::DistanceBetweenPointsSquared(sf::Vector2f position1, sf::Vector2f position2)
{
    return ((position1.x - position2.x) * (position1.x - position2.x)) 
        + ((position1.y - position2.y) * (position1.y - position2.y));
}

void Scene::Draw()
{
    renderWindow.clear();
    bg->Draw(renderWindow);
    
    for (Entity* e : drawGroup)
    {
        e->Draw(renderWindow);
    }

    renderWindow.display();
}
