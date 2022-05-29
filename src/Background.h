#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Background
{
public:
	Background();
	void Draw(sf::RenderWindow& window);

private:
	sf::Sprite bg;
	sf::Texture texture;
	
};
