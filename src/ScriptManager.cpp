#include "ScriptManager.h"
#include "Scriptable.h"
#include <cassert>

ScriptManager::~ScriptManager()
{
	if (L)
	{
		lua_close(L);
		L = nullptr;
	}
}

void ScriptManager::Initialize()
{
	L = luaL_newstate();
	luaL_openlibs(L);

	LoadScripts();
}

void ScriptManager::ReloadScripts()
{
	lua_close(L);
	L = luaL_newstate();
	luaL_openlibs(L);

	LoadScripts();

	for (Scriptable* e : scriptables)
	{
		e->OnScriptReload();
	}
}

void ScriptManager::LoadScripts()
{
	bool failDuringLoad = luaL_loadfile(L, "scripts/master.lua");
	if (failDuringLoad)
	{
		PrintScriptStack();
	}
	assert(!failDuringLoad);

	bool failDuringCall = lua_pcall(L, 0, 0, 0);
	if (failDuringCall)
	{
		PrintScriptStack();
	}
	assert(!failDuringCall);
}

void ScriptManager::Register(Scriptable* entity)
{
	scriptables.insert(entity);
}

void ScriptManager::Unregister(Scriptable* entity)
{
	scriptables.erase(entity);
}

#ifndef _RELEASE
void ScriptManager::PrintScriptStack()
{
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
#endif