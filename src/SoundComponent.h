#pragma once
#include <SFML/Audio.hpp>
#include "EntityComponent.h"

class SoundComponent : public EntityComponent
{
public:
	SoundComponent() = default;

	void Play();

	void SetSound(const char* path, bool looping = false);
	void SetVolume(float volume);
	void SetAttenuation(float attenuation, float distance);
	void SetPosition(sf::Vector2f position);

private:
	sf::Sound Sound;
};

