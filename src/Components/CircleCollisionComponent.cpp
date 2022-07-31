#include "CircleCollisionComponent.h"

CircleCollisionComponent::CircleCollisionComponent(SceneNode* Parent) :
	CollisionComponent(Parent),
	IRenderable(Parent->GetScene(), false)
{
	SetOuter(Parent);
	CircleCollision.setOutlineThickness(5.f);
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
	CircleCollision.setOutlineColor(color);
	CircleCollision.setFillColor(sf::Color::Transparent);
}

void CircleCollisionComponent::SetRadius(float radius)
{
	collisionRadius = radius;
	// minus thickness
	CircleCollision.setRadius(collisionRadius - 5);
	LocalTransform.setOrigin(collisionRadius - 5, collisionRadius - 5);
}