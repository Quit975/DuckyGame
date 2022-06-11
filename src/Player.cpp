#include "Player.h"
#include "DuckyMath.h"

Player::Player()
{
	LoadData();

	quackBuffer.loadFromFile("Res/quack.wav");

	quackSound.setBuffer(quackBuffer);

	duckyTexture.loadFromFile("Res/JanitorDuck.png");
	duckyTexture.setSmooth(true);

	duckySprite.setOrigin(static_cast<sf::Vector2f>(duckyTexture.getSize() / 2));
	duckySprite.setTexture(duckyTexture);
	duckySprite.setScale(0.5f, 0.5f);

	collisionShape = sf::CircleShape(collisionRadius);
	collisionShape.setFillColor(sf::Color{ 0, 255, 255, 100 });
	collisionShape.setOrigin(collisionRadius, collisionRadius);

	UpdateData();
}

void Player::LoadData()
{
	lua_State* L = ScriptManager::Get().GetState();

	ReadFloat(L, "player", "speed", speed);
	ReadFloat(L, "player", "quackVolume", quackVolume);
	ReadFloat(L, "player", "collisionRadius", collisionRadius);
}

void Player::UpdateData()
{
	quackSound.setVolume(quackVolume);
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

	KeepPlayerInBounds();
	collisionShape.setPosition(duckySprite.getPosition().x, duckySprite.getPosition().y);
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

sf::Vector2f Player::GetLocation()
{
	return collisionShape.getPosition();
}


void Player::KeepPlayerInBounds()
{	
	if (duckySprite.getPosition().x > (WindowWidth - duckyRadius)){
		duckySprite.setPosition((WindowWidth - duckyRadius), (duckySprite.getPosition().y));
	}

	else if (duckySprite.getPosition().x < duckyRadius){
		duckySprite.setPosition(duckyRadius, (duckySprite.getPosition().y));
	}

	if (duckySprite.getPosition().y > (WindowHeight - duckyRadius)){
		duckySprite.setPosition(duckySprite.getPosition().x, (WindowHeight - duckyRadius));
	}

	else if (duckySprite.getPosition().y < duckyRadius){
		duckySprite.setPosition((duckySprite.getPosition().x), duckyRadius);
	}
}
