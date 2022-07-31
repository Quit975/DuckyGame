#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"
#include "Scene/IUpdateable.h"

class CircleCollisionComponent;
class SpriteComponent;
class SoundComponent;

class TextCounter;

class Player : public ScriptEntity, public IUpdateable
{
public:
	Player(SceneNode* Parent);
	virtual ~Player();

	void OnEnemyHit();
	void KeepPlayerInBounds();

	// SceneNode
	virtual void OnSceneReady() override;

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

	TextCounter* QuackCounterCache = nullptr;
	TextCounter* FrogCounterCache = nullptr;

	void OnCollisionBegin(ICollideable* Other);
	
	//Ducky Texture is 90x90
	float duckyRadius = 45.f;

	// scriptable properties
	float speed = 220.f;
	float quackVolume = 50.f;
};