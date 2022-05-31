#pragma once
#include <SFML/Graphics.hpp>

extern const int WindowWidth;
extern const int WindowHeight;

class Entity
{
public:
	Entity() {};
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Update(const float dt) = 0;
	virtual sf::FloatRect GetBounds() = 0;
	virtual sf::Vector2f GetLocation() = 0;
	
};

