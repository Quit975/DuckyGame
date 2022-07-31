#pragma once
#include <SFML/Audio.hpp>
#include "EntityComponent.h"
#include "Scene/IUpdateable.h"

class SoundComponent : public EntityComponent, public IUpdateable
{
public:
	SoundComponent(SceneNode* Parent);

	//Scene Node
	virtual void OnUpdate(const float dt) override;

	void Play();
	void SetSound(const char* path, bool looping = false);
	void SetVolume(float volume);
	void SetAttenuation(float attenuation, float distance);

private:
	sf::Sound Sound;
};

