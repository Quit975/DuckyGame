#pragma once
#include <vector>
#include "Player.h"
#include "GreenEnemy.h"
#include "BlueEnemy.h"
#include "Frog.h"
#include "TextCounter.h"

class Scene
{
public:
	Scene(sf::RenderWindow& window);
	~Scene();
	void Update();
	void CheckCollisions();
	void Draw();

	void ClearStuff();

private:
	Player* player;
	Frog* frog;
	TextCounter* frogCounter;
	TextCounter* quackCounter;

	std::vector<Entity*> updateGroup;
	std::vector<Entity*> drawGroup;
	std::vector<Entity*> enemies;

	sf::RenderWindow& renderWindow;
};

