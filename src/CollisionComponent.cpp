#include "CollisionComponent.h"

void CollisionComponent::CircleInit(sf::Color color, float radius, float x, float y)
{
	CircleCollision.setRadius(radius);
	CircleCollision.setOrigin(radius, radius);
	CircleCollision.setFillColor(color);
	CircleCollision.setPosition(x, y);

	isCircle = true;
	SquareCollision.setSize({ 0.f, 0.f });
}
void CollisionComponent::SquareInit(sf::Color color, float size, float x, float y)
{
	SquareCollision.setSize({ size, size });
	SquareCollision.setOrigin(size / 2, size / 2);
	SquareCollision.setFillColor(color);
	SquareCollision.setPosition(x, y);

	isCircle = false;
	CircleCollision.setRadius(0.f);
}

void CollisionComponent::SetPosition(sf::Vector2f position)
{
	CircleCollision.setPosition(position);
	SquareCollision.setPosition(position);
}

void CollisionComponent::SetProperties(float size)
{
	if (isCircle)
	{
		CircleCollision.setRadius(size);
		CircleCollision.setOrigin(size, size);
	}
	else
	{
		SquareCollision.setSize({size, size});
		SquareCollision.setOrigin(size / 2, size / 2);
	}
}

sf::Vector2f CollisionComponent::GetPosition()
{
	if (isCircle)
		return CircleCollision.getPosition();
	else
		return SquareCollision.getPosition();
}

sf::FloatRect CollisionComponent::GetBounds()
{
	if (isCircle)
		return CircleCollision.getGlobalBounds();
	else
		return SquareCollision.getGlobalBounds();
}
