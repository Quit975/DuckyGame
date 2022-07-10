#include "SceneNode.h"
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

sf::Transform SceneNode::GetLocalTransform()
{
	return LocalTransform;
}

sf::Transform SceneNode::GetWorldTransform()
{
	if (ParentNode)
	{
		return LocalTransform * ParentNode->GetWorldTransform();
	}
	return LocalTransform;
}

Scene* SceneNode::GetScene()
{
	return ScenePtr;
}

SceneNode* SceneNode::GetParentNode()
{
	return ParentNode;
}

void SceneNode::MoveNode(sf::Vector2f vec)
{
	LocalTransform.translate(vec);
	for (std::unique_ptr<SceneNode>& Child : ChildNodes)
	{
		Child->MoveNode(vec);
	}
}

void SceneNode::RotateNode(float angle)
{
	LocalTransform.rotate(angle);
	for (std::unique_ptr<SceneNode>& Child : ChildNodes)
	{
		Child->RotateNode(angle);
	}
}

void SceneNode::ScaleNode(sf::Vector2f scale)
{
	LocalTransform.scale(scale);
	for (std::unique_ptr<SceneNode>& Child : ChildNodes)
	{
		Child->ScaleNode(scale);
	}
}

std::unique_ptr<SceneNode> SceneNode::DetachFromParent()
{
	assert(ParentNode && "Can't detach a root node!");
	return std::move(ParentNode->DetachChildNode(this));
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
