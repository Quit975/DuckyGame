#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"

class Player : public ScriptEntity
{
public:
	Player();

	void Quack();
	bool Hit();
	void ResetHit();
	void KeepPlayerInBounds();

	// Entity
	virtual void Update(const float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual sf::FloatRect GetBounds() override;

	// Scriptable
	virtual void LoadData() override;

private:
	sf::Texture duckyTexture;
	sf::Sprite duckySprite;
	sf::SoundBuffer quackBuffer;
	sf::Sound quackSound;

	sf::CircleShape collisionShape;

	bool gequacked = false;
	float speed = 220.f;
};