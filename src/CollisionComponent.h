#pragma once
#include <SFML/Graphics.hpp>
class CollisionComponent
{
public:
	void CircleInit(sf::Color color, float radius, float x = 0.f, float y = 0.f);
	void SquareInit(sf::Color color, float size, float x = 0.f, float y = 0.f);

	void SetPosition(sf::Vector2f position);
	void SetProperties(float size);

	sf::Vector2f GetPosition();
	sf::FloatRect GetBounds();

	inline sf::CircleShape &GetCircleCollision() { return CircleCollision; }
	inline sf::RectangleShape &GetSquareCollision() { return SquareCollision; }

private:
	sf::CircleShape CircleCollision;
	sf::RectangleShape SquareCollision;
	bool isCircle;
};
