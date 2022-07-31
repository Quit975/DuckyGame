#pragma once
#include "ScriptEntity.h"
#include "Scene/IUpdateable.h"

class CircleCollisionComponent;

class EnemyEntity : public ScriptEntity, public IUpdateable
{
public:
	EnemyEntity(SceneNode* Parent) :
		ScriptEntity(Parent),
		IUpdateable(Parent->GetScene()) {};

	virtual ~EnemyEntity() {};

protected:
	CircleCollisionComponent* enemyShapeComp;
};