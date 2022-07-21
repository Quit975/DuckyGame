#pragma once
#include "Scene/SceneNode.h"
#include "Scene/Scene.h"

class EntityComponent : public SceneNode
{
public:
	EntityComponent(SceneNode* Parent) :
		SceneNode(Parent) {};

	virtual ~EntityComponent() {};
};
