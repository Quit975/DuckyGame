#include "Scriptable.h"
#include "ScriptManager.h"

Scriptable::Scriptable()
{
	ScriptManager::Get().Register(this);
}

Scriptable::~Scriptable()
{
	ScriptManager::Get().Unregister(this);
}
