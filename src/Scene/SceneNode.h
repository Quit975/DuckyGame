#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class SceneNode
{
	friend class Scene;

private:
	const char* NodeID = "";

public:
	//For Scene to create the root node
	SceneNode(Scene* Scene);
	//For everything else, to add to the Scene
	SceneNode(SceneNode* Parent);
	virtual ~SceneNode() {};

	//////////////////////////////////// TRANSFORMS ////////////////////////////////////////
	sf::Transformable GetLocalTransform() const;
	void SetLocalTransform(const sf::Transformable& t);
	sf::Vector2f GetLocalPosition() const;
	void SetLocalPosition(const sf::Vector2f& p);
	float GetLocalRotation() const;
	void SetLocalRotation(float r);
	sf::Vector2f GetLocalScale() const;
	void SetLocalScale(const sf::Vector2f& s);

	sf::Transformable GetWorldTransform() const;
	void SetWorldTransform(const sf::Transformable& t);
	sf::Vector2f GetWorldPosition() const;
	void SetWorldPosition(const sf::Vector2f& p);
	float GetWorldRotation() const;
	void SetWorldRotation(float r);
	sf::Vector2f GetWorldScale() const;
	void SetWorldScale(const sf::Vector2f& s);

	void Move(const sf::Vector2f& vec);
	void Rotate(float angle);
	void Scale(const sf::Vector2f& scale);
	////////////////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////// SCENE  //////////////////////////////////////////
	Scene* GetScene() const;
	SceneNode* GetParentNode() const;

	void SetNodeID(const char* NewID) { NodeID = NewID; }
	const char* GetNodeID() const { return NodeID; }
	SceneNode* FindNodeByID(const char* ID);

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

	virtual void OnSceneReady() {};

	std::unique_ptr<SceneNode> DetachChildNode(SceneNode* Node);

private:
	void PropagateOnSceneReady();
};