#pragma once
#include "EnemyEntity.h"

class BlueEnemy : public EnemyEntity
{
public:
	BlueEnemy(SceneNode* Parent);

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
	float size = 30.f;
};

