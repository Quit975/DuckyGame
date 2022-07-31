#include "Scene.h"
#include "IRenderable.h"
#include "IUpdateable.h"
#include "ICollideable.h"
#include "DuckyMath.h"
#include "Entity/Player.h"
#include "Entity/GreenEnemy.h"
#include "Entity/BlueEnemy.h"
#include "Entity/Frog.h"
#include "Entity/TextCounter.h"
#include "Entity/StaticImage.h"

Scene::Scene(sf::RenderWindow& window):
    renderWindow{window}
{
    SceneRoot = std::make_unique<SceneNode>(this);

    SpawnNodeOnScene<StaticImage>()->SetImageTexture("Meadow")->SetWorldPosition({ 400.f, 300.f });

    SpawnNodeOnScene<Player>()->SetNodeID("Player");
    SpawnNodeOnScene<GreenEnemy>(300.f, 400.f);
    SpawnNodeOnScene<GreenEnemy>(600.f, 200.f);
    SpawnNodeOnScene<BlueEnemy>(400.f, 200.f);
    SpawnNodeOnScene<Frog>(550.f, 250.f)->SetNodeID("Frog");

    SpawnNodeOnScene<TextCounter>(100.f, 0.f)->SetText("Times hit")->SetColor(sf::Color::Red)->SetNodeID("HitCounter");
    SpawnNodeOnScene<TextCounter>(450.f, 0.f)->SetText("Frogs caught")->SetColor(sf::Color::Blue)->SetNodeID("CatchCounter");

    SceneRoot->PropagateOnSceneReady();
}

Scene::~Scene()
{
    
}

SceneNode* Scene::FindNodeByID(const char* ID)
{
    return SceneRoot->FindNodeByID(ID);
}

void Scene::Update(const float dt)
{
    for (IUpdateable* updateable : updateGroup)
    {
        updateable->OnUpdate(dt);
    }
}

void Scene::CheckCollisions()
{
    if (collisionGroup.size() > 1)
    {
        for (unsigned int i = 0; i < collisionGroup.size() - 1; i++)
        {
            ICollideable* A = collisionGroup[i];
            CollisionInfo AInfo = A->GetCollisionInfo();

            for (unsigned int j = i + 1; j < collisionGroup.size(); j++)
            {
                ICollideable* B = collisionGroup[j];
                CollisionInfo BInfo = B->GetCollisionInfo();

                sf::Vector2f vecA{ AInfo.X, AInfo.Y };
                sf::Vector2f vecB{ BInfo.X, BInfo.Y };
                sf::Vector2f diff = vecA - vecB;

                float len = VecLength(diff);

                if (len <= AInfo.radius + BInfo.radius)
                {
                    A->Collide(B);
                    B->Collide(A);
                }
            }

            A->ResolveCollisions();
            A->CacheCollisions();
        }
        collisionGroup.back()->ResolveCollisions();
        collisionGroup.back()->CacheCollisions();
    }
}

void Scene::Draw()
{
    renderWindow.clear();
    
    for (IRenderable* renderable : renderGroup)
    {
        renderable->OnDraw(renderWindow);
    }

    renderWindow.display();
}

void Scene::RegisterForRendering(IRenderable* renderable)
{
    renderGroup.push_back(renderable);
}

void Scene::UnregisterFromRendering(IRenderable* renderable)
{
    for (auto it = renderGroup.begin(); it < renderGroup.end(); it++)
    {
        if (*it == renderable)
        {
            renderGroup.erase(it);
        }
    }
}

void Scene::RegisterForUpdate(IUpdateable* Updateable)
{
    updateGroup.push_back(Updateable);
}

void Scene::UnregisterFromUpdate(IUpdateable* Updateable)
{
    for (auto it = updateGroup.begin(); it < updateGroup.end(); it++)
    {
        if (*it == Updateable)
        {
            updateGroup.erase(it);
        }
    }
}

void Scene::RegisterForCollisions(ICollideable* Collideable)
{
    collisionGroup.push_back(Collideable);
}

void Scene::UnregisterFromCollisions(ICollideable* Collideable)
{
    for (auto it = collisionGroup.begin(); it < collisionGroup.end(); it++)
    {
        if (*it == Collideable)
        {
            collisionGroup.erase(it);
        }
    }
}
