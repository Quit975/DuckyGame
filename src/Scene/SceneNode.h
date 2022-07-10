#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Scene;

class SceneNode
{
	//For Scene to create the root node
private:
	SceneNode(Scene* Scene);

public:
	//For everything else, to add to the Scene
	SceneNode(SceneNode* Parent);
	virtual ~SceneNode() {};

	sf::Transform GetLocalTransform();
	sf::Transform GetWorldTransform();
	Scene* GetScene();
	SceneNode* GetParentNode();

	void MoveNode(sf::Vector2f vec);
	void RotateNode(float angle);
	void ScaleNode(sf::Vector2f scale);

	std::unique_ptr<SceneNode> DetachFromParent();

private:
	std::unique_ptr<SceneNode> DetachChildNode(SceneNode* Node);
	SceneNode* ParentNode = nullptr;
	std::vector<std::unique_ptr<SceneNode>> ChildNodes;

	Scene* ScenePtr = nullptr;

	sf::Transform LocalTransform = sf::Transform();

	friend class Scene;
};