#include "CircleCollisionComponent.h"

void CircleCollisionComponent::SetColor(sf::Color color)
{
	CircleCollision.setFillColor(color);
}

void CircleCollisionComponent::SetRadius(float radius)
{
	CircleCollision.setRadius(radius);
}


void CircleCollisionComponent::SetPosition(sf::Vector2f position)
{
	CircleCollision.setPosition(position);
}

void CircleCollisionComponent::SetPosition(float x, float y)
{
	CircleCollision.setPosition(x, y);
}

void CircleCollisionComponent::SetDimensions(float size)
{
	CircleCollision.setRadius(size);
	CircleCollision.setOrigin(size, size);
}

sf::Vector2f CircleCollisionComponent::GetPosition()
{
	return CircleCollision.getPosition();

}

sf::FloatRect CircleCollisionComponent::GetBounds()
{
	return CircleCollision.getGlobalBounds();
}
