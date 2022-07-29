#pragma once
#include "EnemyEntity.h"

class GreenEnemy : public EnemyEntity
{
public:
	GreenEnemy(SceneNode* Parent);

	// ScriptEntity
	virtual void UpdateData() override;

	// Updateable
	virtual void OnUpdate(const float dt) override;

	// Scriptable
	virtual void LoadData() override;

private:
	int xMovementDir = 1;
	int yMovementDir = 1;

	// scriptable properties
	float speed = 150.f;
	float size = 50.f;
	float rotationSpeed = 0.05f;
};

