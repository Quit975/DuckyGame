#pragma once
#include <lua.hpp>

class Scriptable
{
public:
	Scriptable() : L(nullptr) {};

	void SetLuaState(lua_State* state) { L = state; }
	virtual void LoadData() {};

protected:
	lua_State* L;
};