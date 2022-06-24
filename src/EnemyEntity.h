#pragma once
#include "ScriptEntity.h"

class CircleCollisionComponent;

class EnemyEntity : public ScriptEntity
{
public:
	EnemyEntity() {};
	virtual ~EnemyEntity() {};

	CircleCollisionComponent* enemyShapeComp;
};