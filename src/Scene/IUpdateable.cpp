#include "IUpdateable.h"
#include "Scene.h"

IUpdateable::IUpdateable(Scene* ScnPtr, bool Enabled)
{
	ScenePointer = ScnPtr;
	if(Enabled)
		EnableUpdating();
}

IUpdateable::~IUpdateable()
{
	DisableUpdating();
}

void IUpdateable::EnableUpdating()
{
	ScenePointer->RegisterForUpdate(this);
	UpdateEnabled = true;
}

void IUpdateable::DisableUpdating()
{
	ScenePointer->UnregisterFromUpdate(this);
	UpdateEnabled = false;
}
