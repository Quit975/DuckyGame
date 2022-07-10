#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include "Components/EntityComponent.h"	//to avoid "use of undefined type" error, otherwise occuring when using unique_ptr instead of raw
#include "Scene/SceneNode.h"



extern const int WindowWidth;
extern const int WindowHeight;

class Entity : public SceneNode
{
public:
	Entity(SceneNode* Parent):
		SceneNode(Parent) {};

	virtual ~Entity() {};
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Update(const float dt) = 0;
	virtual sf::Vector2f GetLocation() = 0;

	template <class T>
	T* CreateComponent(const char* componentName)
	{
		Components.emplace(componentName, std::make_unique<T>(this));
		return static_cast<T*>(Components.at(componentName).get());
	}

private:
	std::unordered_map<const char*, std::unique_ptr<EntityComponent>> Components;
};

