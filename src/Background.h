#pragma once
#include <SFML/Graphics.hpp>

class Background
{
public:
	Background();
	void Draw(sf::RenderWindow& window);

private:
	sf::Sprite bg;
	sf::Texture texture;
};
