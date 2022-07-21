#pragma once
#include "EntityComponent.h"
#include <SFML/Graphics.hpp>

class SpriteComponent : public EntityComponent
{
public:
	SpriteComponent(SceneNode* Parent);
	virtual ~SpriteComponent();

	virtual void OnDraw(sf::RenderTarget& target) override;

	void SetTexture(const char* path);
	void SetSmooth(const char* name, bool smooth);

	inline sf::Sprite &GetSprite() { return Sprite; }

private:
	sf::Sprite Sprite;
};