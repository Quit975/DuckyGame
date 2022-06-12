#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"
#include "SoundComponent.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

class Player : public ScriptEntity
{
public:
	Player();

	void Quack();
	bool Hit();
	void ResetHit();
	void KeepPlayerInBounds();

	// ScriptEntity
	virtual void UpdateData() override;

	// Entity
	virtual void Update(const float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual sf::FloatRect GetBounds() override;
	virtual sf::Vector2f GetLocation() override;

	// Scriptable
	virtual void LoadData() override;

private:
	SpriteComponent spriteComp;
	SoundComponent quackComp;
	CollisionComponent collisionComp;
	
	float duckyRadius = 45.f; //desired ducky radius, this can be temporary, but I haven't yet figured out how to get the right size from sprite or texture
	bool gequacked = false;

	// scriptable properties
	float speed = 220.f;
	float quackVolume = 50.f;
};