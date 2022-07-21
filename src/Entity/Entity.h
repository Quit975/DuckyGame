#pragma once
#include <SFML/System/Vector2.hpp>
#include <unordered_map>
#include "Scene/SceneNode.h"

extern const int WindowWidth;
extern const int WindowHeight;

class EntityComponent;

class Entity : public SceneNode
{
public:
	Entity(SceneNode* Parent) :
		SceneNode(Parent) {};
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

