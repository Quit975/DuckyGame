#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Scene;

class SceneNode
{
public:
	//For Scene to create the root node
	SceneNode(Scene* Scene);
	//For everything else, to add to the Scene
	SceneNode(SceneNode* Parent);
	virtual ~SceneNode() {};

	//////////////////////////////////// TRANSFORMS ////////////////////////////////////////
	sf::Transformable GetLocalTransform();
	void SetLocalTransform(const sf::Transformable& t);
	sf::Vector2f GetLocalPosition();
	void SetLocalPosition(const sf::Vector2f& p);
	float GetLocalRotation();
	void SetLocalRotation(float r);
	sf::Vector2f GetLocalScale();
	void SetLocalScale(const sf::Vector2f& s);

	sf::Transformable GetWorldTransform();
	void SetWorldTransform(const sf::Transformable& t);
	sf::Vector2f GetWorldPosition();
	void SetWorldPosition(const sf::Vector2f& p);
	float GetWorldRotation();
	void SetWorldRotation(float r);
	sf::Vector2f GetWorldScale();
	void SetWorldScale(const sf::Vector2f& s);

	void Move(const sf::Vector2f& vec);
	void Rotate(float angle);
	void Scale(const sf::Vector2f& scale);
	////////////////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////// SCENE  //////////////////////////////////////////
	virtual void OnUpdate(const float dt) {};
	virtual void OnDraw(sf::RenderTarget& target) {};

	void RegisterForUpdate();
	void UnregisterFromUpdate();
	void RegisterForRendering();
	void UnregisterFromRendering();

	Scene* GetScene();
	SceneNode* GetParentNode();

	template<typename T>
	T* SpawnNodeAsChild()
	{
		std::unique_ptr<T> entity = std::make_unique<T>(this);
		T* RetPtr = entity.get();
		AttachNodeAsChild(std::move(entity));
		return RetPtr;
	}

	std::unique_ptr<SceneNode> DetachFromParent();
	void AttachNodeAsChild(std::unique_ptr<SceneNode> Node);
	////////////////////////////////////////////////////////////////////////////////////////

protected:
	SceneNode* ParentNode = nullptr;
	Scene* ScenePtr = nullptr;
	std::vector<std::unique_ptr<SceneNode>> ChildNodes;

	sf::Transformable LocalTransform = sf::Transformable();

	std::unique_ptr<SceneNode> DetachChildNode(SceneNode* Node);
};