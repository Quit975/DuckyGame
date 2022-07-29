#include "SpriteComponent.h"
#include "DuckyMath.h"
#include "ResourceManager.h"

SpriteComponent::SpriteComponent(SceneNode* Parent) :
	EntityComponent(Parent),
	IRenderable(Parent->GetScene())
{
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::OnDraw(sf::RenderTarget& target)
{
	target.draw(Sprite, GetWorldTransform().getTransform());
}

void SpriteComponent::SetTexture(const char* name)
{
	sf::Texture& tex = ResourceManager::Get().GetTexture(name);
	Sprite.setTexture(tex);
	LocalTransform.setOrigin(static_cast<sf::Vector2f>(tex.getSize() / 2));
}

void SpriteComponent::SetSmooth(const char* name, bool smooth)
{
	ResourceManager::Get().GetTexture(name).setSmooth(smooth);
}
