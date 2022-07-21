#pragma once
#include <vector>
#include <memory>

#include "SceneNode.h"

#include "Entity/Player.h"
#include "Entity/GreenEnemy.h"
#include "Entity/BlueEnemy.h"
#include "Entity/Frog.h"
#include "Entity/TextCounter.h"
#include "Entity/EnemyEntity.h"
#include "Background.h"


class Scene
{
public:
	Scene(sf::RenderWindow& window);
	~Scene();

	void Update(const float dt);
	void CheckCollisions();
	void Draw();

	void RegisterForRendering(SceneNode* Node);
	void UnregisterFromRendering(SceneNode* Node);

	void RegisterForUpdate(SceneNode* Node);
	void UnregisterFromUpdate(SceneNode* Node);

private:
	std::unique_ptr<SceneNode> SceneRoot = nullptr;

	std::vector<SceneNode*> updateGroup;
	std::vector<SceneNode*> renderGroup;

	sf::RenderWindow& renderWindow;

	std::unique_ptr<Background> bg;

	bool EntitiesIntersect(CircleCollisionComponent* component1, CircleCollisionComponent* component2);
};

