#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	LoadData();
}

void ResourceManager::LoadData() {
	duckyTexture.loadFromFile("Res/JanitorDuck.png");
}


sf::Texture ResourceManager::GetTexture(const char name) {
	for (auto [key, value] : ResourceManager::TextureMap) {
		if (name == key) {
			return value;
		}
	}
}

sf::Font ResourceManager::GetFont(const char name) {
	for (auto [key, value] : ResourceManager::FontMap) {
		if (name == key) {
			return value;
		}
	}
}

sf::Sound ResourceManager::GetSound(const char name) {
	for (auto [key, value] : ResourceManager::SoundMap) {
		if (name == key) {
			return value;
		}
	}
}
