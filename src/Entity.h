#pragma once
#include <SFML/Graphics.hpp>

extern const int WindowWidth;
extern const int WindowHeight;

class Entity
{
public:
	Entity() {};
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Update() = 0;
	virtual sf::FloatRect GetBounds() = 0;
};

