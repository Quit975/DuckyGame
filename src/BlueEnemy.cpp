#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(float x, float y)
{
    enemy = sf::CircleShape(30.f);
    enemy.setFillColor(sf::Color::Blue);
    enemy.setPosition(x, y);
    enemy.setOrigin(15.f, 15.f);

    LoadData();
}

void BlueEnemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemy);
}

void BlueEnemy::Update(const float dt)
{
    enemy.move(0.f, speed * yMovementDir * dt);
    if (enemy.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (enemy.getPosition().y >= WindowHeight)
        yMovementDir = -1;
}

sf::FloatRect BlueEnemy::GetBounds()
{
    return enemy.getGlobalBounds();
}

void BlueEnemy::LoadData()
{
    lua_State* L = ScriptManager::Get().GetState();

	lua_getglobal(L, "blueEnemy");

	if (lua_istable(L, -1)) {
		lua_getfield(L, -1, "speed");
        speed = static_cast<float>(lua_tonumber(L, -1));
		lua_settop(L, 0);
	}
}
