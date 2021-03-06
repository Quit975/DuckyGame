#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"
#include "Scene/IUpdateable.h"

class CircleCollisionComponent;
class SoundComponent;

class Frog : public ScriptEntity, public IUpdateable
{
public:
	Frog(SceneNode* Parent);
	
	void Catch();
	void TeleportAwayFromPlayer(sf::Vector2f playerLoc);

	// ScriptEntity
	virtual void UpdateData() override;

	// Updateable
	virtual void OnUpdate(const float dt) override;

	// Scriptable
	virtual void LoadData() override;


private:
	SoundComponent* frogSoundComp;
	SoundComponent* catchSoundComp;
	CircleCollisionComponent* frogShapeComp;
	
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

