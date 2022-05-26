#pragma once
#include <SFML/Audio.hpp>
#include "ScriptEntity.h"

class Frog : public ScriptEntity
{
public:
	Frog();
	
	void Catch();

	// Entity
	virtual void Update(const float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual sf::FloatRect GetBounds() override;

	// Scriptable
	virtual void LoadData() override;

private:
	sf::SoundBuffer frogBuffer;
	sf::Sound frogSound;
	sf::SoundBuffer frogCatchBuffer;
	sf::Sound frogCatchSound;
	sf::RectangleShape frogShape;
	int xMovementDir = 1;
	int yMovementDir = 1;
	float speed = 250.f;

};

