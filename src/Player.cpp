#include "Player.h"
#include "DuckyMath.h"
#include "CircleCollisionComponent.h"


Player::Player()
{
	LoadData();

	quackComp = CreateComponent<SoundComponent>("quackComp");
	spriteComp = CreateComponent<SpriteComponent>("spriteComp");
	collisionComp = CreateComponent<CircleCollisionComponent>("collisionComp");

	quackComp->SetSound("Res/quack.wav");
	spriteComp->SetTexture("Res/JanitorDuck.png");
	spriteComp->SetScale(0.5f);
	collisionComp->SetColor(sf::Color::Cyan);
	collisionComp->SetRadius(45.f);

	UpdateData();
}

void Player::LoadData()
{
	lua_State* L = ScriptManager::Get().GetState();

	ReadFloat(L, "player", "speed", speed);
	ReadFloat(L, "player", "quackVolume", quackVolume);
}

void Player::UpdateData()
{
	quackComp->SetVolume(quackVolume);
}

void Player::Update(const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		spriteComp->GetSprite().move(-speed * dt, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		spriteComp->GetSprite().move(speed * dt, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
		spriteComp->GetSprite().move(0.f, -speed * dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
		spriteComp->GetSprite().move(0.f, speed * dt);

	KeepPlayerInBounds();
	collisionComp->SetPosition(spriteComp->GetPosition());
	sf::Listener::setPosition(spriteComp->GetPosition().x, spriteComp->GetPosition().y, 0.f);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(spriteComp->GetSprite());

#ifndef _RELEASE
	window.draw(collisionComp->GetShape());	//Where does the duck go in the configuration Debug? Maybe Duck doesn't like him :thinking: I don't know *kwa*
#endif // _RELEASE
}

sf::FloatRect Player::GetBounds()
{
	return collisionComp->GetBounds();
}

void Player::Quack()
{
	quackComp->Play();
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
	return spriteComp->GetPosition();
}


void Player::KeepPlayerInBounds()
{	
	if (spriteComp->GetPosition().x > (WindowWidth - duckyRadius)){
		spriteComp->SetPosition((WindowWidth - duckyRadius), (spriteComp->GetPosition().y));
	}

	else if (spriteComp->GetPosition().x < duckyRadius){
		spriteComp->SetPosition(duckyRadius, (spriteComp->GetPosition().y));
	}

	if (spriteComp->GetPosition().y > (WindowHeight - duckyRadius)){
		spriteComp->SetPosition(spriteComp->GetPosition().x, (WindowHeight - duckyRadius));
	}

	else if (spriteComp->GetPosition().y < duckyRadius){
		spriteComp->SetPosition((spriteComp->GetPosition().x), duckyRadius);
	}
}
