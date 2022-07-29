#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"

class CircleCollisionComponent;
class SpriteComponent;
class SoundComponent;

class Player : public ScriptEntity
{
public:
	Player(SceneNode* Parent);
	virtual ~Player();

	void Quack();
	void Hit();
	void KeepPlayerInBounds();

	// ScriptEntity
	virtual void UpdateData() override;

	// Updateable
	virtual void OnUpdate(const float dt) override;

	// Scriptable
	virtual void LoadData() override;

private:
	SpriteComponent* spriteComp;
	SoundComponent* quackComp;
	CircleCollisionComponent* collisionComp;

	void OnCollisionBegin(ICollideable* Other);
	void OnCollisionEnd(ICollideable* Other);
	
	float duckyRadius = 45.f; //desired ducky radius, this can be temporary, but I haven't yet figured out how to get the right size from sprite or texture

	// scriptable properties
	float speed = 220.f;
	float quackVolume = 50.f;
};