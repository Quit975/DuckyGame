#pragma once
#include <SFML/Graphics.hpp>
#include "EntityComponent.h"
#include "Scene/IRenderable.h"

class SpriteComponent : public EntityComponent, public IRenderable
{
public:
	SpriteComponent(SceneNode* Parent);
	virtual ~SpriteComponent();

	virtual void OnDraw(sf::RenderTarget& target) override;

	void SetTexture(const char* path);
	void SetSmooth(const char* name, bool smooth);

private:
	sf::Sprite Sprite;
};