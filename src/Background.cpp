#include "Background.h"
#include "ResourceManager.h"

Background::Background()
{
	texture = ResourceManager::Get().GetTexture("Meadow");
	bg.setTexture(texture);
	
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
}