#pragma once
#include "Entity.h"

class GreenEnemy : public Entity
{
public:
	GreenEnemy(float x, float y);
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Update() override;
	virtual sf::FloatRect GetBounds() override;

private:
	sf::RectangleShape enemy;
	int xMovementDir = 1;
	int yMovementDir = 1;
};

