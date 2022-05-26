#include "Scriptable.h"
#include "ScriptManager.h"
#include <cassert>

Scriptable::Scriptable()
{
	ScriptManager::Get().Register(this);
}

Scriptable::~Scriptable()
{
	ScriptManager::Get().Unregister(this);
}

void Scriptable::ReadFloat(lua_State* L, const char* tableName, const char* valueName, float& valueRef)
{
	bool valueFound = false;
	lua_getglobal(L, tableName);

	if (lua_istable(L, -1))
	{
		lua_getfield(L, -1, valueName);
		if (lua_isnumber(L, -1))
		{
			valueRef = static_cast<float>(lua_tonumber(L, -1));
			valueFound = true;
		}
	}

	lua_settop(L, 0);
	assert(valueFound);
}
