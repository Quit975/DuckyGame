#include "Scene.h"
#include "MusicPlayer.h"
#include "lua.hpp"
#include <iostream>

const int WindowWidth = 800.f;
const int WindowHeight = 600.f;

void dumpstack(lua_State* L) {
	int top = lua_gettop(L);
	int topIdx = -1;
	for (int i = top; i > 0; i--) {
		printf("%d (%d)\t%s\t", i, topIdx, luaL_typename(L, i));
		switch (lua_type(L, i)) {
		case LUA_TNUMBER:
			printf("%g\n", lua_tonumber(L, i));
			break;
		case LUA_TSTRING:
			printf("%s\n", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			printf("%s\n", (lua_toboolean(L, i) ? "true" : "false"));
			break;
		case LUA_TNIL:
			printf("%s\n", "nil");
			break;
		default:
			printf("%p\n", lua_topointer(L, i));
			break;
		}
		topIdx--;
	}
}

void loadLua(lua_State*& s)
{
	lua_close(s);
	s = luaL_newstate();
	luaL_openlibs(s);

	if (luaL_loadfile(s, "test.lua"))
	{
		std::cout << "dupa\n";
	}

	dumpstack(s);

	if (lua_pcall(s, 0, 0, 0))
	{
		std::cout << "ble\n";
	}

	dumpstack(s);
}

void printLua(lua_State* s)
{
	lua_getglobal(s, "printMe");
	lua_pushstring(s, "huehuehue");
	lua_pcall(s, 1, 1, 0);
	std::cout << "A tu ju¿ z C! " << lua_tostring(s, -1) << "\n";
	lua_settop(s, 0);
}

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

    float dt;
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Ducky Game!");

    //MusicPlayer music;
    Scene scene(window);
    
    //frame rate management
    sf::Clock clock;
    constexpr float desiredFrameRate = 60.f;
    constexpr float desiredDt = 1 / desiredFrameRate;

    while (window.isOpen())
    {
        dt = clock.getElapsedTime().asSeconds();
        while (dt >= desiredDt)
        {
            clock.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::T)
					{
						scene.ReloadScripts();
					}

					if (event.key.code == sf::Keyboard::O)
					{
						loadLua(L);
					}

					if (event.key.code == sf::Keyboard::P)
					{
						printLua(L);
					}
				}
            }

            scene.Update(dt);
            scene.CheckCollisions();
            scene.Draw();

            dt -= desiredDt;
        }
    }
}


/*
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, "test.lua") || lua_pcall(L, 0, 0, 0))
	{
		std::cout << "dupa\n";
	}


	lua_getglobal(L, "foo");


	if (lua_isfunction(L, -1))
	{
		std::cout << "Mamy lua funkcje!" << std::endl;
		lua_pcall(L, 0, LUA_MULTRET, 0);
	}

	lua_settop(L, 0);

	lua_getglobal(L, "numerek");
	std::cout << "Tutaj z C: " << lua_tonumber(L, -1) << "\n";

	lua_settop(L, 0);

	lua_getglobal(L, "tableexample");
	//lua_pushstring(L, "x");

	int x, y, z;

	if (lua_istable(L, -1)) {
		lua_getfield(L, -1, "x");
		x = lua_tonumber(L, -1);
		lua_pop(L, 1);

		lua_getfield(L, -1, "y");
		y = lua_tonumber(L, -1);
		lua_pop(L, 1);

		lua_getfield(L, -1, "z");
		z = lua_tonumber(L, -1);
		lua_settop(L, 0);
	}

	std::cout << x << "  " << y << "   " << z << "\n";

	lua_close(L);
	*/