#include "Scene.h"
#include "Components/CircleCollisionComponent.h"
#include "DuckyMath.h"

Scene::Scene(sf::RenderWindow& window):
    renderWindow{window}
{
    bg = std::unique_ptr<Background>(new Background());
    player = std::unique_ptr<Player>(new Player());
    frog = std::unique_ptr<Frog>(new Frog());

    enemies.push_back(std::unique_ptr<EnemyEntity>(new GreenEnemy(650.f, 200.f)));
    enemies.push_back(std::unique_ptr<EnemyEntity>(new GreenEnemy(150.f, 100.f)));
    enemies.push_back(std::unique_ptr<EnemyEntity>(new BlueEnemy(400.f, 500.f)));

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

    for (std::unique_ptr<EnemyEntity>& e : enemies)
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
    for (std::unique_ptr<EnemyEntity>& e : enemies)
    {
        if (EntitiesIntersect(player->collisionComp, e->enemyShapeComp))
        {
            if (player->Hit())
            {
                quackCounter->Increase();
            }
            collided = true;
        }
    }
    if (!collided)
    {
        player->ResetHit();
    }

    // check collision with a frog
    if (EntitiesIntersect(player->collisionComp, frog->frogShapeComp))
    {
        frogCounter->Increase();
        frog->Catch();
        frog->TeleportAwayFromPlayer(player->GetLocation());
    }
}

bool Scene::EntitiesIntersect(CircleCollisionComponent* component1, CircleCollisionComponent* component2)
{
    float distanceToCollide = component1->collisionRadius + component2->collisionRadius;
    float distanceBetweenEntities = VecLength(component1->GetPosition() - component2->GetPosition());
    return distanceBetweenEntities <= distanceToCollide;
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
