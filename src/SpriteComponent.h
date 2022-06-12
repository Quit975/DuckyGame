#pragma once
#include <SFML/Graphics.hpp>
class SpriteComponent
{
public:
	void Init(const char* path, float scale = 1.f, bool smooth = true);

	void SetPosition(float x, float y);

	inline sf::Sprite &GetSprite() { return Sprite; }
	inline sf::Vector2f GetPosition() { return Sprite.getPosition(); }

private:
	sf::Texture Texture;
	sf::Sprite Sprite;
};