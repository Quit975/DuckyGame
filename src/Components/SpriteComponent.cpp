#include "SpriteComponent.h"
#include "DuckyMath.h"
#include "ResourceManager.h"
#include "Scene/Scene.h"


SpriteComponent::SpriteComponent(SceneNode* Parent) :
	EntityComponent(Parent)
{
	RegisterForRendering();
}

SpriteComponent::~SpriteComponent()
{
	UnregisterFromRendering();
}

void SpriteComponent::OnDraw(sf::RenderTarget& target)
{
	sf::Transform combinedTransform = GetWorldTransform().getTransform();

	target.draw(Sprite, combinedTransform);
}

void SpriteComponent::SetTexture(const char* name)
{
	Sprite.setTexture(ResourceManager::Get().GetTexture(name));
	LocalTransform.setOrigin(static_cast<sf::Vector2f>(ResourceManager::Get().GetTexture(name).getSize() / 2));
}

void SpriteComponent::SetSmooth(const char* name, bool smooth)
{
	ResourceManager::Get().GetTexture(name).setSmooth(smooth);
}
