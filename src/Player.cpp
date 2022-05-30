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

void Player::Update(const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		duckySprite.move(-speed * dt, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		duckySprite.move(speed * dt, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
		duckySprite.move(0.f, -speed * dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
		duckySprite.move(0.f, speed * dt);

	collisionShape.setPosition(duckySprite.getPosition().x, duckySprite.getPosition().y);
	KeepPlayerInBounds();
	sf::Listener::setPosition(duckySprite.getPosition().x, duckySprite.getPosition().y, 0.f);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(duckySprite);

#ifndef _RELEASE
	window.draw(collisionShape);	//Where does the duck go in the configuration Debug? Maybe Duck doesn't like him :thinking: I don't know *kwa*
#endif // _RELEASE
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

sf::Vector2<float> Player::GetLocation()
{
	return sf::Vector2<float>(collisionShape.getPosition());
}

float Player::GetRadius()
{
	return collisionShape.getRadius();
}

void Player::KeepPlayerInBounds()
{	
	if (collisionShape.getPosition().x > (WindowWidth - (duckyTexture.getSize().x)/2)){
		duckySprite.setPosition((WindowWidth - (duckyTexture.getSize().x) / 2), (collisionShape.getPosition().y));
		collisionShape.setPosition((WindowWidth - (duckyTexture.getSize().x) / 2), (collisionShape.getPosition().y));
	}

	else if (collisionShape.getPosition().x < 0.f){
		duckySprite.setPosition(0.f, (collisionShape.getPosition().y));
		collisionShape.setPosition(0.f, (collisionShape.getPosition().y));
	}

	if (collisionShape.getPosition().y > (WindowHeight - (duckyTexture.getSize().y) / 2)){
		duckySprite.setPosition(collisionShape.getPosition().x, (WindowHeight - (duckyTexture.getSize().y) / 2));
		collisionShape.setPosition(collisionShape.getPosition().x, (WindowHeight - (duckyTexture.getSize().y) / 2));
	}

	else if (collisionShape.getPosition().y < 0.f){
		duckySprite.setPosition((collisionShape.getPosition().x), 0.f);
		collisionShape.setPosition((collisionShape.getPosition().x), 0.f);
	}
}
