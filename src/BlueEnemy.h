#pragma once
#include "ScriptEntity.h"

class CircleCollisionComponent;

class BlueEnemy : public ScriptEntity
{
public:
	BlueEnemy(float x, float y);

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
	CircleCollisionComponent* enemyShapeComp;
	int xMovementDir = 1;
	int yMovementDir = 1;

	// scriptable properties
	float speed = 150.f;
	float size = 30.f;
};

