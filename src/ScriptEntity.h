#pragma once
#include "Entity.h"
#include "Scriptable.h"
#include "ScriptManager.h"

class ScriptEntity : public Entity, public Scriptable
{
public:
	ScriptEntity() {};
	virtual ~ScriptEntity() {};

	virtual void OnScriptReload() override { LoadData(); };
};