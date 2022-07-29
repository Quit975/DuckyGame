#pragma once
#include <vector>
#include <memory>
#include "SceneNode.h"
#include "Background.h"

class IRenderable;
class IUpdateable;
class ICollideable;

class Scene
{
public:
	Scene(sf::RenderWindow& window);
	~Scene();

	template<typename T>
	T* SpawnNodeOnScene(float x = 0.f, float y = 0.f)
	{
		T* Node = SceneRoot->SpawnNodeAsChild<T>();
		Node->SetWorldPosition({ x, y });

		return Node;
	}

	SceneNode* FindNodeByID(const char* ID);

	void Update(const float dt);
	void CheckCollisions();
	void Draw();

	void RegisterForRendering(IRenderable* Renderable);
	void UnregisterFromRendering(IRenderable* Renderable);

	void RegisterForUpdate(IUpdateable* Updateable);
	void UnregisterFromUpdate(IUpdateable* Updateable);

	void RegisterForCollisions(ICollideable* Collideable);
	void UnregisterFromCollisions(ICollideable* Collideable);

	sf::RenderWindow& GetRenderWindow() { return renderWindow; }

private:
	std::unique_ptr<SceneNode> SceneRoot = nullptr;

	std::vector<IUpdateable*> updateGroup;
	std::vector<IRenderable*> renderGroup;
	std::vector<ICollideable*> collisionGroup;

	sf::RenderWindow& renderWindow;

	std::unique_ptr<Background> bg;
};

