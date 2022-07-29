#include "SoundComponent.h"
#include "ResourceManager.h"

SoundComponent::SoundComponent(SceneNode* Parent) :
	EntityComponent(Parent),
	IUpdateable(Parent->GetScene(), false)
{
}

void SoundComponent::SetSound(const char* name, bool looping)
{
	Sound.setBuffer(ResourceManager::Get().GetBuffer(name));

	Sound.setAttenuation(0);
	if (looping)
	{
		Sound.setLoop(true);
	}
}

void SoundComponent::OnUpdate(const float dt)
{
	sf::Vector2f WorldPosition = GetWorldPosition();
	Sound.setPosition(WorldPosition.x, WorldPosition.y, 0.f);
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
	{
		Sound.setMinDistance(distance);
		EnableUpdating();
	}
	else
	{
		DisableUpdating();
	}
}
