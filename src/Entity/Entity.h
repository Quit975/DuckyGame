#pragma once
#include <SFML/System/Vector2.hpp>
#include <unordered_map>
#include "Scene/SceneNode.h"
#include "Scene/Scene.h"
#include "Scene/IUpdateable.h"

class EntityComponent;

class Entity : public SceneNode, public IUpdateable
{
public:
	Entity(SceneNode* Parent) :
		SceneNode(Parent),
		IUpdateable(Parent->GetScene()) {};
	virtual ~Entity() {};

	template <class T>
	T* CreateComponent(const char* componentName)
	{
		T* component = SpawnNodeAsChild<T>();
		Components.emplace(componentName, component);
		return component;
	}

private:
	std::unordered_map<const char*, EntityComponent*> Components;
};

