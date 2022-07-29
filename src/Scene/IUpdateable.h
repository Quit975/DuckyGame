#pragma once

class Scene;

class IUpdateable
{
public:
	IUpdateable(Scene* ScnPtr, bool Enabled = true);
	virtual ~IUpdateable();

	virtual void OnUpdate(const float dt) = 0;
	void EnableUpdating();
	void DisableUpdating();
	bool IsUpdating() const { return UpdateEnabled; }

private:
	Scene* ScenePointer;
	bool UpdateEnabled = false;
};