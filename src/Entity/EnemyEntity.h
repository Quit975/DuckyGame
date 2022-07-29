#pragma once
#include "ScriptEntity.h"

class CircleCollisionComponent;

class EnemyEntity : public ScriptEntity
{
public:
	EnemyEntity(SceneNode* Parent) :
		ScriptEntity(Parent) {};

	virtual ~EnemyEntity() {};

protected:
	CircleCollisionComponent* enemyShapeComp;
};