#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include "Components/EntityComponent.h"	//to avoid "use of undefined type" error, otherwise occuring when using unique_ptr instead of raw



extern const int WindowWidth;
extern const int WindowHeight;

class Entity
{
private:
	std::unordered_map<const char*,std::unique_ptr<EntityComponent>> Components;

public:
	Entity() {};
	virtual ~Entity() {};
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Update(const float dt) = 0;
	virtual sf::Vector2f GetLocation() = 0;

	template <class T>
	T* CreateComponent(const char* componentName)
	{
		Components.emplace(componentName, std::make_unique<T>());
		return static_cast<T*>(Components.at(componentName).get());
	}
};

