#include "ResourceManager.h"

ResourceManager::ResourceManager() {
}

void ResourceManager::LoadResources() {
	duckyTexture.loadFromFile("Res/JanitorDuck.png");
}


sf::Texture ResourceManager::GetTexture(const char name) {

}

sf::Font ResourceManager::GetFont(const char name) {

}

sf::Sound ResourceManager::GetSound(const char name) {

}
