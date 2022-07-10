#pragma once
#include <SFML/Graphics.hpp>
#include "EntityComponent.h"

class CollisionComponent : public EntityComponent
{
public:
	CollisionComponent(SceneNode* Parent):
		EntityComponent(Parent) {};
};
