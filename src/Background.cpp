#include "Background.h"
#include <SFML/Graphics/Sprite.hpp>

Background::Background()
{
	texture.loadFromFile("Res/quackMeadowBG.png");

	bg.setTexture(texture);
	
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
}