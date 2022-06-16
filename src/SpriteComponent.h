#pragma once
#include "EntityComponent.h"
#include <SFML/Graphics.hpp>

class SpriteComponent : public EntityComponent
{
public:
	void SetTexture(const char* path);
	void SetScale(float scale);
	void SetPosition(float x, float y);
	void SetSmooth(bool smooth);

	inline sf::Sprite &GetSprite() { return Sprite; }
	inline sf::Vector2f GetPosition() { return Sprite.getPosition(); }

private:
	sf::Texture Texture;
	sf::Sprite Sprite;
};