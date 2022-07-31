#pragma once
#include <unordered_set>
#include <bitset>
#include <functional>

class Scene;

enum class CollisionMask
{
	PLAYER = 0,
	ENEMY,
	FROG
};

// For now we support only Circular collisions
// Don't know the math for collisions between cubes 0_0
struct CollisionInfo
{
	float X = 0.f;
	float Y = 0.f;
	float radius = 0.f;
};

class ICollideable;

typedef std::function<void(ICollideable*)> OverlapCallback;

class ICollideable
{
public:
	ICollideable(Scene* ScnPtr, bool Enabled = true);
	virtual ~ICollideable();

	virtual CollisionInfo GetCollisionInfo() const = 0;
	void* GetOuter() const { return Outer; }
	
	void CacheCollisions();
	void ResolveCollisions();

	void Collide(ICollideable* Other);
	void BindOnOverlapBegin(OverlapCallback Callback) { OnOverlapBeginCallback = Callback; };
	void BindOnOverlapEnd(OverlapCallback Callback) { OnOverlapEndCallback = Callback; };

	void EnableCollision();
	void DisableCollision();
	bool IsCollisionEnabled() const { return CollisionEnabled; }

	void SetCollisionProfile(CollisionMask Profile) { CollisionProfile = Profile; }
	const CollisionMask GetCollisionProfile() const { return CollisionProfile; }
	void AddToActiveCollisionsMask(CollisionMask NewCollision);
	void RemoveFromActiveCollisionsMask(CollisionMask Collision);
	bool CollidesWithProfile(CollisionMask Collision) const;

protected:
	void SetOuter(void* OuterObject) { Outer = OuterObject; }

private:
	Scene* ScenePointer;
	bool CollisionEnabled = false;

	std::unordered_set<ICollideable*> ActiveOverlapsSet;
	std::unordered_set<ICollideable*> CachedOverlapsSet;
	CollisionMask CollisionProfile;
	std::bitset<8> ActiveCollisionsMask;

	void* Outer;
	OverlapCallback OnOverlapBeginCallback;
	OverlapCallback OnOverlapEndCallback;
};