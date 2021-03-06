#include "SceneNode.h"
#include "Scene.h"
#include <cassert>

SceneNode::SceneNode(Scene* Scene)
{
	ScenePtr = Scene;
}

SceneNode::SceneNode(SceneNode* Parent)
{
	assert(Parent && "Can't attach SceneNode to a nullptr!");
	ParentNode = Parent;
	ScenePtr = ParentNode->GetScene();
}

void SceneNode::PropagateOnSceneReady()
{
	OnSceneReady();
	for (std::unique_ptr<SceneNode>& Child : ChildNodes)
	{
		Child->PropagateOnSceneReady();
	}
}

sf::Transformable SceneNode::GetLocalTransform() const
{
	return LocalTransform;
}

void SceneNode::SetLocalTransform(const sf::Transformable& t)
{
	LocalTransform = t;
}

sf::Vector2f SceneNode::GetLocalPosition() const
{
	return LocalTransform.getPosition();
}

void SceneNode::SetLocalPosition(const sf::Vector2f& p)
{
	LocalTransform.setPosition(p);
}

float SceneNode::GetLocalRotation() const
{
	return LocalTransform.getRotation();
}

void SceneNode::SetLocalRotation(float r)
{
	LocalTransform.setRotation(r);
}

sf::Vector2f SceneNode::GetLocalScale() const
{
	return LocalTransform.getScale();
}

void SceneNode::SetLocalScale(const sf::Vector2f& s)
{
	LocalTransform.setScale(s);
}

sf::Transformable SceneNode::GetWorldTransform() const
{
	if (ParentNode)
	{
		sf::Transformable r = LocalTransform;
		sf::Transformable p = ParentNode->GetWorldTransform();

		r.move(p.getPosition());
		r.rotate(p.getRotation());
		r.scale(p.getScale());
		
		return r;
	}
	return LocalTransform;
}

void SceneNode::SetWorldTransform(const sf::Transformable& t)
{
	if (ParentNode)
	{
		sf::Transformable p = ParentNode->GetWorldTransform();
		sf::Transformable n = sf::Transformable();

		n.setPosition(t.getPosition() - p.getPosition());
		n.setRotation(t.getRotation() - p.getRotation());
		n.setScale(t.getScale() - p.getScale());
	}
	else
	{
		LocalTransform = t;
	}
}

sf::Vector2f SceneNode::GetWorldPosition() const
{
	return GetWorldTransform().getPosition();
}

void SceneNode::SetWorldPosition(const sf::Vector2f& p)
{
	LocalTransform.setPosition(p - ParentNode->GetWorldPosition());
}

float SceneNode::GetWorldRotation() const
{
	return GetWorldTransform().getRotation();
}

void SceneNode::SetWorldRotation(float r)
{
	LocalTransform.setRotation(r - ParentNode->GetWorldRotation());
}

sf::Vector2f SceneNode::GetWorldScale() const
{
	return GetWorldTransform().getScale();
}

void SceneNode::SetWorldScale(const sf::Vector2f& s)
{
	LocalTransform.setScale(s - ParentNode->GetWorldScale());
}

Scene* SceneNode::GetScene() const
{
	return ScenePtr;
}

SceneNode* SceneNode::GetParentNode() const
{
	return ParentNode;
}

SceneNode* SceneNode::FindNodeByID(const char* ID)
{
	if (NodeID == ID)
	{
		return this;
	}

	SceneNode* foundNode = nullptr;
	
	for (std::unique_ptr<SceneNode>& Child : ChildNodes)
	{
		foundNode = Child->FindNodeByID(ID);
		if (foundNode)
		{
			return foundNode;
		}
	}
	
	return foundNode;
}

void SceneNode::Move(const sf::Vector2f& vec)
{
	LocalTransform.move(vec);
}

void SceneNode::Rotate(float angle)
{
	LocalTransform.rotate(angle);
}

void SceneNode::Scale(const sf::Vector2f& scale)
{
	LocalTransform.scale(scale);
}

std::unique_ptr<SceneNode> SceneNode::DetachFromParent()
{
	assert(ParentNode && "Can't detach a root node!");
	return std::move(ParentNode->DetachChildNode(this));
}

void SceneNode::AttachNodeAsChild(std::unique_ptr<SceneNode> Node)
{
	ChildNodes.emplace_back(std::move(Node));
}

std::unique_ptr<SceneNode> SceneNode::DetachChildNode(SceneNode* Node)
{
	for(auto it = ChildNodes.begin(); it != ChildNodes.end(); it++)
	{
		if (it->get() == Node)
		{
			std::unique_ptr<SceneNode> temp = std::move(*it);
			ChildNodes.erase(it);
			return std::move(temp);
		}
	}
	assert(false && "ChildNode for detach not found!");
	return nullptr;
}
