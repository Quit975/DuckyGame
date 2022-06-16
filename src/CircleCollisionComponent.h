#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionComponent.h"

class CircleCollisionComponent : public CollisionComponent
{
public:
	void SetColor(sf::Color color);
	void SetRadius(float radius);
	void SetPosition(sf::Vector2f position);
	void SetPosition(float x, float y);
	void SetDimensions(float size);
	
	sf::Vector2f GetPosition();
	sf::FloatRect GetBounds();

	inline sf::CircleShape &GetCircleCollision() { return CircleCollision; }

private:
	sf::CircleShape CircleCollision;
};
