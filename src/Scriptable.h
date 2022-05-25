#pragma once

class Scriptable
{
public:
	Scriptable();
	virtual ~Scriptable();

	virtual void LoadData() {};
	virtual void OnScriptReload() {};
};