#include "SpriteComponent.h"
#include "DuckyMath.h"
#include "ResourceManager.h"


SpriteComponent::SpriteComponent(SceneNode* Parent) :
	EntityComponent(Parent)
{
}

void SpriteComponent::SetTexture(const char* name)
{
	Sprite.setTexture(ResourceManager::Get().GetTexture(name));
	Sprite.setOrigin(static_cast<sf::Vector2f>(ResourceManager::Get().GetTexture(name).getSize() / 2));
}

void SpriteComponent::SetScale(float scale)
{
	Sprite.setScale(scale, scale);
}

void SpriteComponent::SetPosition(float x, float y)
{
	Sprite.setPosition(x, y);
}

void SpriteComponent::SetSmooth(const char* name, bool smooth)
{
	ResourceManager::Get().GetTexture(name).setSmooth(smooth);
}
