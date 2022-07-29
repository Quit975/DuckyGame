#pragma once
#include "SFML/Graphics.hpp"

class Scene;

class IRenderable
{
public:
	IRenderable(Scene* ScnPtr, bool Enabled = true);
	virtual ~IRenderable();

	virtual void OnDraw(sf::RenderTarget& target) = 0;
	void EnableRendering();
	void DisableRendering();
	bool IsRendered() const { return RenderingEnabled; }

private:
	Scene* ScenePointer;
	bool RenderingEnabled = false;
};