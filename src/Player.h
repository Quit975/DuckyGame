#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	virtual void Update(const float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual sf::FloatRect GetBounds() override;
	virtual sf::Vector2f GetLocation() override;
	void Quack();
	bool Hit();
	void ResetHit();
	void KeepPlayerInBounds();
	

private:
	sf::Texture duckyTexture;
	sf::Sprite duckySprite;
	sf::SoundBuffer quackBuffer;
	sf::Sound quackSound;
	sf::CircleShape collisionShape;
	
	float duckyRadius = 45.f; //desired ducky radius, this can be temporary, but I haven't yet figured out how to get the right size from sprite or texture
	bool gequacked = false;
	const float speed = 220.f;

};