#pragma once
#include "EntityComponent.h"
#include <SFML/Graphics.hpp>

class SpriteComponent : public EntityComponent
{
public:
	SpriteComponent(SceneNode* Parent);

	void SetTexture(const char* path);
	void SetScale(float scale);
	void SetPosition(float x, float y);
	void SetSmooth(const char* name, bool smooth);

	inline sf::Sprite &GetSprite() { return Sprite; }
	inline sf::Vector2f GetPosition() { return Sprite.getPosition(); }

private:
	sf::Sprite Sprite;
};