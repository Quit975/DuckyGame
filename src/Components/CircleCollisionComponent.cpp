#include "CircleCollisionComponent.h"

CircleCollisionComponent::CircleCollisionComponent(SceneNode* Parent) :
	CollisionComponent(Parent),
	IRenderable(Parent->GetScene(), false)
{
	SetOuter(Parent);
}

CollisionInfo CircleCollisionComponent::GetCollisionInfo() const
{
	sf::Vector2f WorldPosition = GetWorldPosition();
	return CollisionInfo(WorldPosition.x, WorldPosition.y, collisionRadius);
}

void CircleCollisionComponent::OnDraw(sf::RenderTarget& target)
{
	target.draw(CircleCollision, GetWorldTransform().getTransform());
}

void CircleCollisionComponent::SetColor(sf::Color color)
{
	CircleCollision.setFillColor(color);
}

void CircleCollisionComponent::SetRadius(float radius)
{
	collisionRadius = radius;
	CircleCollision.setRadius(radius);
	//CircleCollision.setOrigin(radius, radius);
	LocalTransform.setOrigin(radius, radius);
}