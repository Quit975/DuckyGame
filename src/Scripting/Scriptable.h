#pragma once
#include <lua.hpp>

class Scriptable
{
public:
	Scriptable();
	virtual ~Scriptable();

	virtual void LoadData() {};
	virtual void OnScriptReload() {};

	void ReadFloat(lua_State* L, const char* tableName, const char* valueName, float& valueRef);
};