#pragma once
#include <vector>
#include "Player.h"
#include "Frog.h"
#include "TextCounter.h"

class CollisionCheckManager
{
public:
	void Check(std::unique_ptr<Player>& player
		, std::unique_ptr<Frog>& frog
		, std::vector<std::unique_ptr<Entity>>& enemies
		, std::unique_ptr<TextCounter>& quackCounter
		, std::unique_ptr<TextCounter>& frogCounter
		, sf::RenderWindow& renderWindow);

private:
	float CalculateDistanceSquared(sf::Vector2f position1, sf::Vector2f position2);
	float MaxDistanceNeededToIntersectSquared(float radius1, float radius2);
	void OnPlayerHitEnemy(std::unique_ptr<TextCounter>& quackCounter);
	void OnPlayerHitFrog(std::unique_ptr<Player>& player, std::unique_ptr<Frog>& frog, std::unique_ptr<TextCounter>& frogCounter);
};

