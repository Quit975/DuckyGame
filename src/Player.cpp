#include "Player.h"

Player::Player()
{
	quackBuffer.loadFromFile("Res/quack.wav");
	quackSound.setBuffer(quackBuffer);
	quackSound.setVolume(50.f);
	duckyTexture.loadFromFile("Res/JanitorDuck.png");
	duckyTexture.setSmooth(true);
	duckySprite.setTexture(duckyTexture);
	duckySprite.setScale(0.5f, 0.5f);

	collisionShape = sf::CircleShape(45.f);
	collisionShape.setFillColor(sf::Color::Cyan);
	collisionShape.setOrigin(-20.f, -20.f);
}

void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		duckySprite.move(-1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		duckySprite.move(1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		duckySprite.move(0.f, -1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		duckySprite.move(0.f, 1.f);

	collisionShape.setPosition(duckySprite.getPosition().x, duckySprite.getPosition().y);
	sf::Listener::setPosition(duckySprite.getPosition().x, duckySprite.getPosition().y, 0.f);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(duckySprite);

#ifdef _DEBUG
	window.draw(collisionShape);	//Where does the duck go in the configuration Debug? Maybe Duck doesn't like him :thinking: I don't know *kwa*
#endif // _DEBUG
}

sf::FloatRect Player::GetBounds()
{
	return collisionShape.getGlobalBounds();
}

void Player::Quack()
{
	quackSound.play();
}

bool Player::Hit()
{
	if (!gequacked)
	{
		gequacked = true;
		Quack();
		return true;
	}
	return false;
}

void Player::ResetHit()
{
	gequacked = false;
}
