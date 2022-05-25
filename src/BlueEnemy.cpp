#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(float x, float y)
{
    enemy = sf::CircleShape(30.f);
    enemy.setFillColor(sf::Color::Blue);
    enemy.setPosition(x, y);
    enemy.setOrigin(15.f, 15.f);
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
    bool shouldCloseLua = false;
    if (!L)
    {
        shouldCloseLua = true;
        L = luaL_newstate();
        luaL_openlibs(L);
    }

	luaL_loadfile(L, "scripts/blueEnemy.lua");
	lua_pcall(L, 0, 0, 0);

	lua_getglobal(L, "blueEnemy");


	if (lua_istable(L, -1)) {
		lua_getfield(L, -1, "speed");
        speed = lua_tonumber(L, -1);
		lua_settop(L, 0);
	}

    if (shouldCloseLua)
    {
        lua_close(L);
        L = nullptr;
    }
}
