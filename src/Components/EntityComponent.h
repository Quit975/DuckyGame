#pragma once
#include "Scene/SceneNode.h"

class EntityComponent : public SceneNode
{
public:
	EntityComponent(SceneNode* Parent) :
		SceneNode(Parent) {};

	virtual ~EntityComponent() {};
};
