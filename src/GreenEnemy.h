#pragma once
#include "ScriptEntity.h"

class GreenEnemy : public ScriptEntity
{
public:
	GreenEnemy(float x, float y);

	// ScriptEntity
	virtual void UpdateData() override;

	// Entity
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Update(const float dt) override;
	virtual sf::FloatRect GetBounds() override;
	virtual sf::Vector2f GetLocation() override;

	// Scriptable
	virtual void LoadData() override;

private:
	sf::RectangleShape enemy;
	sf::CircleShape collisionShape;
	int xMovementDir = 1;
	int yMovementDir = 1;

	// scriptable properties
	float speed = 150.f;
	float size = 50.f;
	float rotationSpeed = 0.05;
};

