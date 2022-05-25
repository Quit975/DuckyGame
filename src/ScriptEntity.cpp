#include "ScriptEntity.h"

ScriptEntity::ScriptEntity():
	Scriptable()
{
	
}

void ScriptEntity::OnScriptReload()
{
	this->LoadData();
}
