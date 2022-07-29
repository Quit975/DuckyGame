#include "Player.h"
#include "DuckyMath.h"
#include "Components/CircleCollisionComponent.h"
#include "Components/SoundComponent.h"
#include "Components/SpriteComponent.h"

#include "Entity/Frog.h"
#include "Entity/TextCounter.h"

Player::Player(SceneNode* Parent) :
	ScriptEntity(Parent),
	IUpdateable(Parent->GetScene())
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
	collisionComp->SetCollisionProfile(CollisionMask::PLAYER);
	collisionComp->AddToActiveCollisionsMask(CollisionMask::ENEMY);
	collisionComp->AddToActiveCollisionsMask(CollisionMask::FROG);

#ifndef _RELEASE
	collisionComp->EnableRendering();
#endif // !_RELEASE


	collisionComp->BindOnOverlapBegin([this](ICollideable* Other) {
		OnCollisionBegin(Other);
		});

	UpdateData();
}

Player::~Player()
{
}

void Player::OnSceneReady()
{
	QuackCounterCache = static_cast<TextCounter*>(ScenePtr->FindNodeByID("HitCounter"));
	FrogCounterCache = static_cast<TextCounter*>(ScenePtr->FindNodeByID("CatchCounter"));
}

void Player::LoadData()
{
	lua_State* L = ScriptManager::Get().GetState();

	ReadFloat(L, "player", "speed", speed);
	ReadFloat(L, "player", "quackVolume", quackVolume);
}

void Player::OnCollisionBegin(ICollideable* Other)
{
	switch (Other->GetCollisionProfile())
	{
	case CollisionMask::ENEMY:
	{
		Hit();
		break;
	}

	case CollisionMask::FROG:
	{
		Frog* frog = static_cast<Frog*>(Other->GetOuter());
		if (frog)
		{
			frog->Catch();
			frog->TeleportAwayFromPlayer(GetWorldPosition());
			FrogCounterCache->Increase();
		}
		break;
	}

	default:
		break;
	}
}

void Player::OnCollisionEnd(ICollideable* Other)
{
	switch (Other->GetCollisionProfile())
	{
	case CollisionMask::ENEMY:
		break;

	case CollisionMask::FROG:
		break;

	default:
		break;
	}
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

void Player::Hit()
{
	Quack();
	QuackCounterCache->Increase();
}

void Player::KeepPlayerInBounds()
{	
	sf::Vector2f WorldPosition = GetWorldPosition();
	sf::Vector2u WindowSize = ScenePtr->GetRenderWindow().getSize();

	if (WorldPosition.x > (WindowSize.x - duckyRadius)) {
		WorldPosition.x = WindowSize.x - duckyRadius;
	}

	else if (WorldPosition.x < duckyRadius){
		WorldPosition.x = duckyRadius;
	}

	if (WorldPosition.y > (WindowSize.y - duckyRadius)){
		WorldPosition.y = WindowSize.y - duckyRadius;
	}

	else if (WorldPosition.y < duckyRadius){
		WorldPosition.y = duckyRadius;
	}

	SetWorldPosition(WorldPosition);
}
