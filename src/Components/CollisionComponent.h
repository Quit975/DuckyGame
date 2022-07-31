#pragma once
#include <SFML/Graphics.hpp>
#include "EntityComponent.h"
#include "Scene/ICollideable.h"

// For now DuckyEngine supports only CircleCollisions
// This proxy class exists in case we ever figure out how to make cube/rect collisions work
// This will require adjusting the way ICollideable passes info about physics object also
class CollisionComponent : public EntityComponent, public ICollideable
{
public:
	CollisionComponent(SceneNode* Parent):
		EntityComponent(Parent),
		ICollideable(Parent->GetScene()) {};
};
