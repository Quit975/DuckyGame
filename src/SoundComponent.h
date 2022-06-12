#pragma once
#include <SFML/Audio.hpp>
class SoundComponent
{
public:
	SoundComponent() = default;
	void Init(const char* path, bool looping = false);
	void Play();

	void SetProperties(float volume, float attenuation = 0.f, float distance = 1.f);
	void SetPosition(sf::Vector2f position);

private:
	sf::SoundBuffer Buffer;
	sf::Sound Sound;

};

