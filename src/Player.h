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
	void Quack();
	bool Hit();
	void ResetHit();

private:
	sf::Texture duckyTexture;
	sf::Sprite duckySprite;
	sf::SoundBuffer quackBuffer;
	sf::Sound quackSound;

	sf::CircleShape collisionShape;

	bool gequacked = false;
	const float vel = 220.f;

};