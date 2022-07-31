#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionComponent.h"
#include "Scene/IRenderable.h"

class CircleCollisionComponent : public CollisionComponent, public IRenderable
{
public:
	CircleCollisionComponent(SceneNode* Parent);

	virtual CollisionInfo GetCollisionInfo() const override;
	virtual void OnDraw(sf::RenderTarget& target) override;

	void SetColor(sf::Color color);
	void SetRadius(float radius);

private:
	float collisionRadius;
	sf::CircleShape CircleCollision;
};
