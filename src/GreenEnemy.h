#pragma once
#include "Entity.h"

class GreenEnemy : public Entity
{
public:
	GreenEnemy(float x, float y);
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Update(const float dt) override;
	virtual sf::FloatRect GetBounds() override;
	virtual sf::Vector2f GetLocation() override;

private:
	sf::RectangleShape enemy;
	int xMovementDir = 1;
	int yMovementDir = 1;
	const float speed = 180.f;

};

