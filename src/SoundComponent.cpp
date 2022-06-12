#include "SoundComponent.h"


void SoundComponent::Init(const char* path, bool looping)
{
	Buffer.loadFromFile(path);
	Sound.setBuffer(Buffer);
	Sound.setAttenuation(0);
	if (looping)
	{
		Sound.setLoop(true);
		Sound.play();
		srand(time(NULL));		//no idea what it's supposed to do, but it was just below looping in Frog.cpp, so I chose to keep it here :)
	}
}

void SoundComponent::Play()
{
	Sound.play();
}

void SoundComponent::SetProperties(float volume, float attenuation, float distance)
{
	Sound.setVolume(volume);
	Sound.setAttenuation(attenuation);
	if (attenuation != 0.f)
		Sound.setMinDistance(distance);
}


void SoundComponent::SetPosition(sf::Vector2f position)
{
	Sound.setPosition(position.x, position.y, 0.f);
}
