#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"
#include "SoundComponent.h"

class CircleCollisionComponent;

class Frog : public ScriptEntity
{
public:
	Frog();
	
	void Catch();
	void TeleportAwayFromPlayer(sf::Vector2f playerLoc);

	// ScriptEntity
	virtual void UpdateData() override;

	// Entity
	virtual void Update(const float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual sf::Vector2f GetLocation() override;

	// Scriptable
	virtual void LoadData() override;

	CircleCollisionComponent* frogShapeComp;

private:
	SoundComponent* frogSoundComp;
	SoundComponent* catchSoundComp;
	
	int xMovementDir = 1;
	int yMovementDir = 1;

	// scriptable properties
	float speed = 250.f;
	float size = 20.f;
	float croakAttenuation = 80.f;
	float croakMinDistance = 600.f;
	float catchVolume = 100.f;
	float safeDistance = 250.f;	/*min distance between the frog and the player during teleport*/
};

