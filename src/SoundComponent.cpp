#include "SoundComponent.h"


void SoundComponent::SetSound(const char* path, bool looping)
{
	Buffer.loadFromFile(path);
	Sound.setBuffer(Buffer);
	Sound.setAttenuation(0);
	if (looping)
	{
		Sound.setLoop(true);
		Sound.play();
	}
}

void SoundComponent::Play()
{
	Sound.play();
}

void SoundComponent::SetVolume(float volume)
{
	Sound.setVolume(volume);
}

void SoundComponent::SetAttenuation(float attenuation, float distance)
{
	Sound.setAttenuation(attenuation);
	if (attenuation != 0.f)
		Sound.setMinDistance(distance);
}


void SoundComponent::SetPosition(sf::Vector2f position)
{
	Sound.setPosition(position.x, position.y, 0.f);
}