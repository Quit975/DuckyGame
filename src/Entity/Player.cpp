#include "Player.h"
#include "DuckyMath.h"
#include "Components/CircleCollisionComponent.h"
#include "Components/SoundComponent.h"
#include "Components/SpriteComponent.h"

Player::Player(SceneNode* Parent) :
	ScriptEntity(Parent)
{
	LoadData();

	quackComp = CreateComponent<SoundComponent>("quackComp");
	spriteComp = CreateComponent<SpriteComponent>("spriteComp");
	collisionComp = CreateComponent<CircleCollisionComponent>("collisionComp");

	quackComp->SetSound("Quack");
	spriteComp->SetTexture("Duck");

	spriteComp->SetLocalScale({ 0.5f, 0.5f });
	collisionComp->SetColor(sf::Color::Cyan);
	collisionComp->SetRadius(45.f);

	UpdateData();

	RegisterForUpdate();
}

Player::~Player()
{
	UnregisterFromUpdate();
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

void Player::OnUpdate(const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		Move({ -speed * dt, 0.f });

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		Move({ speed * dt, 0.f });

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
		Move({ 0.f, -speed * dt });

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
		Move({ 0.f, speed * dt });

	KeepPlayerInBounds();

	sf::Vector2f WorldPosition = GetWorldPosition();
	sf::Listener::setPosition(WorldPosition.x, WorldPosition.y, 0.f);
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


void Player::KeepPlayerInBounds()
{	
	sf::Vector2f WorldPosition = GetWorldPosition();

	if (WorldPosition.x > (WindowWidth - duckyRadius)) {
		SetWorldPosition({ (WindowWidth - duckyRadius), (WorldPosition.y) });
	}

	else if (WorldPosition.x < duckyRadius){
		SetWorldPosition({ duckyRadius, (WorldPosition.y) });
	}

	if (WorldPosition.y > (WindowHeight - duckyRadius)){
		SetWorldPosition({ WorldPosition.x, (WindowHeight - duckyRadius) });
	}

	else if (WorldPosition.y < duckyRadius){
		SetWorldPosition({ (WorldPosition.x), duckyRadius });
	}
}
