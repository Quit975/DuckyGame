#pragma once
#include <vector>
#include <memory>
#include "SceneNode.h"
#include "Background.h"

class Scene
{
public:
	Scene(sf::RenderWindow& window);
	~Scene();

	void Update(const float dt);
	void Draw();

	void RegisterForRendering(SceneNode* Node);
	void UnregisterFromRendering(SceneNode* Node);

	void RegisterForUpdate(SceneNode* Node);
	void UnregisterFromUpdate(SceneNode* Node);

	sf::RenderWindow& GetRenderWindow() { return renderWindow; }

private:
	std::unique_ptr<SceneNode> SceneRoot = nullptr;

	std::vector<SceneNode*> updateGroup;
	std::vector<SceneNode*> renderGroup;

	sf::RenderWindow& renderWindow;

	std::unique_ptr<Background> bg;
};

