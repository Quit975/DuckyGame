#pragma once
#include "Entity.h"

class BlueEnemy : public Entity
{
public:
	BlueEnemy(float x, float y);
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Update(int WindowWidth, int WindowHeight) override;
	virtual sf::FloatRect GetBounds() override;

private:
	sf::CircleShape enemy;
	int xMovementDir = 1;
	int yMovementDir = 1;
};

