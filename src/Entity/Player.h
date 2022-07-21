#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"

class CircleCollisionComponent;

class Player : public ScriptEntity
{
public:
	Player(SceneNode* Parent);
	virtual ~Player();

	void Quack();
	bool Hit();
	void ResetHit();
	void KeepPlayerInBounds();

	// ScriptEntity
	virtual void UpdateData() override;

	// Entity
	virtual void OnUpdate(const float dt) override;

	// Scriptable
	virtual void LoadData() override;

	class CircleCollisionComponent* collisionComp;

private:
	class SpriteComponent* spriteComp;
	class SoundComponent* quackComp;
	
	float duckyRadius = 45.f; //desired ducky radius, this can be temporary, but I haven't yet figured out how to get the right size from sprite or texture
	bool gequacked = false;

	// scriptable properties
	float speed = 220.f;
	float quackVolume = 50.f;
};