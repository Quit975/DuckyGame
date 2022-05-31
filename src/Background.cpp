#include "Background.h"

Background::Background()
{
	texture.loadFromFile("Res/quackMeadowBG.png");

	bg.setTexture(texture);
	
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
}