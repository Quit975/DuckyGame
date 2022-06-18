#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class EntityComponent;

extern const int WindowWidth;
extern const int WindowHeight;

class Entity
{
private:
	std::unordered_map<const char*,EntityComponent*> Components;

public:
	Entity() {};
	virtual ~Entity() {};
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Update(const float dt) = 0;
	virtual sf::FloatRect GetBounds() = 0;
	virtual sf::Vector2f GetLocation() = 0;

	template <class T>
	T* CreateComponent(const char* componentName)
	{
		Components.emplace(componentName, new T());
		return static_cast<T*>(Components.at(componentName));
	}
};

