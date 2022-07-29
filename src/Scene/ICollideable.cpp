#include "ICollideable.h"
#include "Scene.h"

ICollideable::ICollideable(Scene* ScnPtr, bool Enabled)
{
	ScenePointer = ScnPtr;
	if (Enabled)
		EnableCollision();
}

ICollideable::~ICollideable()
{
	DisableCollision();
}

void ICollideable::CacheCollisions()
{
	CachedOverlapsSet = ActiveOverlapsSet;
	ActiveOverlapsSet.clear();
}

void ICollideable::ResolveCollisions()
{
	// first check for new collisions and remove existing ones from cache
	for (auto it = ActiveOverlapsSet.begin(); it != ActiveOverlapsSet.end(); it++)
	{
		auto cached = CachedOverlapsSet.find(*it);

		// we have already been overlapping with it in the previous frame, clear it from cache and don't do anything
		if (cached != CachedOverlapsSet.end())
		{
			CachedOverlapsSet.erase(*it);
		}
		// this is initial collision with an object, inform
		else
		{
			if (OnOverlapBeginCallback)
			{
				OnOverlapBeginCallback(*it);
			}
		}
	}

	// now the cache should only contain objects that we collided with in the previous frame, but not anymore
	for (auto it = CachedOverlapsSet.begin(); it != CachedOverlapsSet.end(); it++)
	{
		if (OnOverlapEndCallback)
		{
			OnOverlapEndCallback(*it);
		}
	}
}

void ICollideable::Collide(ICollideable* Other)
{
	if (CollidesWithProfile(Other->GetCollisionProfile()))
	{
		ActiveOverlapsSet.emplace(Other);
	}
}

void ICollideable::EnableCollision()
{
	ScenePointer->RegisterForCollisions(this);
	CollisionEnabled = true;
}

void ICollideable::DisableCollision()
{
	ScenePointer->UnregisterFromCollisions(this);
	CollisionEnabled = false;
}

void ICollideable::AddToActiveCollisionsMask(CollisionMask NewCollision)
{
	ActiveCollisionsMask.set(static_cast<size_t>(NewCollision), true);
}

void ICollideable::RemoveFromActiveCollisionsMask(CollisionMask Collision)
{
	ActiveCollisionsMask.set(static_cast<size_t>(Collision), false);
}

bool ICollideable::CollidesWithProfile(CollisionMask Collision) const
{
	return ActiveCollisionsMask.test(static_cast<size_t>(Collision));
}
