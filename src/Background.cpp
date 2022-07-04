#include "Background.h"
#include "ResourceManager.h"

Background::Background(){
	bg.setTexture(ResourceManager::Get().GetTexture("Meadow"));
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
}