#pragma once
#include "Entity.h"

class BlueEnemy : public Entity
{
public:
	BlueEnemy(float x, float y);
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Update(const float dt) override;
	virtual sf::FloatRect GetBounds() override;
	virtual sf::Vector2f GetLocation() override;

private:
	sf::CircleShape enemy;
	int xMovementDir = 1;
	int yMovementDir = 1;
	const float speed = 150.f;
};

