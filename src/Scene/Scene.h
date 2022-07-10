#pragma once
#include <vector>
#include <memory>

#include "SceneNode.h"

#include "Entity/Player.h"
#include "Entity/GreenEnemy.h"
#include "Entity/BlueEnemy.h"
#include "Entity/Frog.h"
#include "Entity/TextCounter.h"
#include "Background.h"
#include "Entity/EnemyEntity.h"


class Scene
{
public:
	Scene(sf::RenderWindow& window);
	~Scene();
	void Update(const float dt);
	void CheckCollisions();
	void Draw();

private:
	std::unique_ptr<SceneNode> SceneRoot = nullptr;

	std::unique_ptr<Background> bg;
	std::unique_ptr<Player> player;
	std::unique_ptr<Frog> frog;
	std::unique_ptr<TextCounter> frogCounter;
	std::unique_ptr<TextCounter> quackCounter;
	std::vector<std::unique_ptr<EnemyEntity>> enemies;

	std::vector<Entity*> updateGroup;
	std::vector<Entity*> drawGroup;

	sf::RenderWindow& renderWindow;

	bool EntitiesIntersect(CircleCollisionComponent* component1, CircleCollisionComponent* component2);
};

