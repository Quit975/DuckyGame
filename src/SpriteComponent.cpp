#include "SpriteComponent.h"
#include "DuckyMath.h"


void SpriteComponent::SetTexture(const char* path)
{
	Texture.loadFromFile(path);
	Sprite.setTexture(Texture);
	Sprite.setOrigin(static_cast<sf::Vector2f>(Texture.getSize() / 2));
}

void SpriteComponent::SetScale(float scale)
{
	Sprite.setScale(scale, scale);
}

void SpriteComponent::SetPosition(float x, float y)
{
	Sprite.setPosition(x, y);
}

void SpriteComponent::SetSmooth(bool smooth)
{
	Texture.setSmooth(smooth);
}
