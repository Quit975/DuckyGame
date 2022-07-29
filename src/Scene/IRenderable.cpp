#include "IRenderable.h"
#include "Scene.h"

IRenderable::IRenderable(Scene* ScnPtr, bool Enabled)
{
	ScenePointer = ScnPtr;
	if(Enabled)
		EnableRendering();
}

IRenderable::~IRenderable()
{
	DisableRendering();
}

void IRenderable::EnableRendering()
{
	ScenePointer->RegisterForRendering(this);
	RenderingEnabled = true;
}

void IRenderable::DisableRendering()
{
	ScenePointer->UnregisterFromRendering(this);
	RenderingEnabled = false;
}
