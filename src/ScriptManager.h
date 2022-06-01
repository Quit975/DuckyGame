#pragma once
#include <lua.hpp>
#include <unordered_set>

class Scriptable;

class ScriptManager
{
public:
	ScriptManager(const ScriptManager&) = delete;
	void operator = (const ScriptManager&) = delete;
	~ScriptManager();

private:
	ScriptManager():
		L(nullptr) {}

public:
	static ScriptManager& Get()
	{
		static ScriptManager instance;
		return instance;
	}

	void Initialize();
	lua_State* GetState() { return L; }

	void ReloadScripts();
	void Register(Scriptable* entity);
	void Unregister(Scriptable* entity);
	
	void PrintScriptStack();

private:
	void LoadScripts();

	lua_State* L;
	std::unordered_set<Scriptable*> scriptables;
};