#pragma once
#include <vector>
#include <memory>
#include "Player.h"
#include "GreenEnemy.h"
#include "BlueEnemy.h"
#include "Frog.h"
#include "TextCounter.h"
#include "Background.h"
#include "EnemyEntity.h"
#include "DuckyMath.h"

class Scene
{
public:
	Scene(sf::RenderWindow& window);
	~Scene();
	void Update(const float dt);
	void CheckCollisions();
	void Draw();

private:
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

