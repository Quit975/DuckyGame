#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"

class Frog : public Entity
{
public:
	Frog();
	virtual void Update() override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual sf::FloatRect GetBounds() override;

	void Catch();

private:
	sf::SoundBuffer frogBuffer;
	sf::Sound frogSound;
	sf::SoundBuffer frogCatchBuffer;
	sf::Sound frogCatchSound;
	sf::RectangleShape frogShape;
	int xMovementDir = 1;
	int yMovementDir = 1;
};

