#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity() {};
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Update(int WindowWidth, int WindowHeight) = 0;
	virtual sf::FloatRect GetBounds() = 0;
};

