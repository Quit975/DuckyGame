#pragma once
#include "ScriptEntity.h"

class GreenEnemy : public ScriptEntity
{
public:
	GreenEnemy(float x, float y);

	// Entity
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Update(const float dt) override;
	virtual sf::FloatRect GetBounds() override;

	// Scriptable
	virtual void LoadData() override;

private:
	sf::RectangleShape enemy;
	int xMovementDir = 1;
	int yMovementDir = 1;
	float speed = 150.f;
};

