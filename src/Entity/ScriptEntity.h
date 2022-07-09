#pragma once
#include "Entity.h"
#include "Scripting/Scriptable.h"
#include "Scripting/ScriptManager.h"

class ScriptEntity : public Entity, public Scriptable
{
public:
	ScriptEntity() {};
	virtual ~ScriptEntity() {};

	virtual void UpdateData() {};

	// Scriptable
	virtual void OnScriptReload() override { LoadData(); UpdateData(); };

};