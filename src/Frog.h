#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"

class Frog : public Entity
{
public:
	Frog();
	virtual void Update(const float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual sf::FloatRect GetBounds() override;
	virtual sf::Vector2f GetLocation() override;

	void Catch();
	void TeleportAwayFromPlayer(sf::Vector2f playerLoc);  

private:
	sf::SoundBuffer frogBuffer;
	sf::Sound frogSound;
	sf::SoundBuffer frogCatchBuffer;
	sf::Sound frogCatchSound;
	sf::RectangleShape frogShape;
	int xMovementDir = 1;
	int yMovementDir = 1;
	const float speed = 250.f;
	const float safeDistance = 250.f;	/*min distance between the frog and the player during teleport*/

};

