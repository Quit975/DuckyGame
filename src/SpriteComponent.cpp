#include "SpriteComponent.h"
#include "DuckyMath.h"

void SpriteComponent::Init(const char* path, float scale, bool smooth)
{
	Texture.loadFromFile(path);
	Texture.setSmooth(smooth);

	Sprite.setOrigin(static_cast<sf::Vector2f>(Texture.getSize() / 2));
	Sprite.setTexture(Texture);
	Sprite.setScale(scale, scale);
}

void SpriteComponent::SetPosition(float x, float y)
{
	Sprite.setPosition(x, y);
}
