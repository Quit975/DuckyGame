#include "Scene.h"

Scene::Scene(sf::RenderWindow& window):
    renderWindow{window}
{
    player = new Player();
    frog = new Frog();

    enemies.push_back(new GreenEnemy(650.f, 200.f));
    enemies.push_back(new GreenEnemy(150.f, 100.f));
    enemies.push_back(new BlueEnemy(400.f, 500.f));

    quackCounter = new TextCounter(50.f, 50.f, "Quack", sf::Color::Red);
    frogCounter = new TextCounter(500.f, 50.f, "Frog", sf::Color::Green);

    updateGroup.push_back(player);
    updateGroup.push_back(frog);

    drawGroup.push_back(player);
    drawGroup.push_back(quackCounter);
    drawGroup.push_back(frogCounter);

#ifdef _DEBUG
    drawGroup.push_back(frog);
#endif // _DEBUG

    for (Entity* e : enemies)
    {
        updateGroup.push_back(e);
        drawGroup.push_back(e);
    }
}

Scene::~Scene()
{
    
}

void Scene::Update()
{
    for (Entity* e : updateGroup)
    {
        e->Update();
    }
}

void Scene::CheckCollisions()
{
    sf::FloatRect duckyShape = player->GetBounds();
    sf::FloatRect frogShape = frog->GetBounds();

    // check collisions with enemies
    bool collided = false;
    for (Entity* e : enemies)
    {
        if (duckyShape.intersects(e->GetBounds()))
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

    // check if frog caught
    if (duckyShape.intersects(frogShape))
    {
        frogCounter->Increase();
        frog->Catch();
    }
}

void Scene::Draw()
{
    renderWindow.clear();

    for (Entity* e : drawGroup)
    {
        e->Draw(renderWindow);
    }

    renderWindow.display();
}

void Scene::ClearStuff()
{
    delete player;
    delete frog;
    delete quackCounter;
    delete frogCounter;

    for (Entity* e : enemies)
    {
        delete e;
    }
}
