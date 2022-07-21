#include "Scene.h"
#include "Components/CircleCollisionComponent.h"
#include "DuckyMath.h"
#include "Entity/Player.h"

Scene::Scene(sf::RenderWindow& window):
    renderWindow{window}
{
    SceneRoot = std::make_unique<SceneNode>(this);

    SceneRoot->SpawnNodeAsChild<Player>();

    bg = std::unique_ptr<Background>(new Background());
}

Scene::~Scene()
{
    
}

void Scene::Update(const float dt)
{
    for (SceneNode* node : updateGroup)
    {
        node->OnUpdate(dt);
    }
}

void Scene::Draw()
{
    renderWindow.clear();
    bg->Draw(renderWindow);
    
    for (SceneNode* node : renderGroup)
    {
        node->OnDraw(renderWindow);
    }

    renderWindow.display();
}

void Scene::RegisterForRendering(SceneNode* Node)
{
    renderGroup.push_back(Node);
}

void Scene::UnregisterFromRendering(SceneNode* Node)
{
    for (auto it = renderGroup.begin(); it < renderGroup.end(); it++)
    {
        if (*it == Node)
        {
            renderGroup.erase(it);
        }
    }
}

void Scene::RegisterForUpdate(SceneNode* Node)
{
    updateGroup.push_back(Node);
}

void Scene::UnregisterFromUpdate(SceneNode* Node)
{
    for (auto it = updateGroup.begin(); it < updateGroup.end(); it++)
    {
        if (*it == Node)
        {
            updateGroup.erase(it);
        }
    }
}
