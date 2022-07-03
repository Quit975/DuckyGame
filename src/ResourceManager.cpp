#include "ResourceManager.h"

ResourceManager::ResourceManager(){}
ResourceManager::~ResourceManager(){}

void ResourceManager::LoadResources() {
	LoadTexture("Duck", "Res/JanitorDuck.png");
	LoadTexture("Meadow", "Res/quackMeadowBG.png");

	LoadSound("Quack", "Res/quack.wav");
	LoadSound("Frog", "Res/froggy.wav");
	LoadSound("Catch", "Res/frogCatch.wav");

	LoadFont("Text", "Res/consola.ttf");
}

void ResourceManager::LoadTexture(const char* name, const char* path) {
    sf::Texture& tex = TextureMap[name]; 
	tex.loadFromFile(path);
};

void ResourceManager::LoadSound(const char* name, const char* path) {
	sf::SoundBuffer& Buffer = BufferMap[name];
	Buffer.loadFromFile(path);
	
	sf::Sound& Sound = SoundMap[name];
	Sound.setBuffer(Buffer);
};

void ResourceManager::LoadFont(const char* name, const char* path) {
	sf::Font& font = FontMap[name];
	font.loadFromFile(path);
};


sf::Texture& ResourceManager::GetTexture(const char* name) {
	return TextureMap.at(name);
}

sf::Font& ResourceManager::GetFont(const char* name) {
	return FontMap.at(name);
}

sf::Sound& ResourceManager::GetSound(const char* name) {
	return SoundMap.at(name);
}
