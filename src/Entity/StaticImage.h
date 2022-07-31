#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class SpriteComponent;

class StaticImage : public Entity
{
public:
	StaticImage(SceneNode* Parent);
	virtual ~StaticImage();

	StaticImage* SetImageTexture(const char* TexID);

private:
	SpriteComponent* spriteComp;
};