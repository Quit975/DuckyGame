#include "ResourceManager.h"
#include <cassert>

void ResourceManager::LoadResources() {
	LoadTexture("Duck", "Res/JanitorDuck.png");
	LoadTexture("Meadow", "Res/quackMeadowBG.png");

	LoadBuffer("Quack", "Res/quack.wav");
	LoadBuffer("Frog", "Res/froggy.wav");
	LoadBuffer("Catch", "Res/frogCatch.wav");

	LoadFont("Text", "Res/consola.ttf");
}

void ResourceManager::UnloadResources()
{
	TextureMap.clear();
	FontMap.clear();
	BufferMap.clear();
}

void ResourceManager::LoadTexture(const char* name, const char* path) {
#ifndef _RELEASE
	auto found = TextureMap.find(name);
	assert(found == TextureMap.end() && "Trying to load a texture under already existing key!");
#endif

    sf::Texture& tex = TextureMap[name]; 
	tex.loadFromFile(path);
};

void ResourceManager::LoadBuffer(const char* name, const char* path) {
#ifndef _RELEASE
	auto found = BufferMap.find(name);
	assert(found == BufferMap.end() && "Trying to load a sound buffer under already existing key!");
#endif

	sf::SoundBuffer& Buffer = BufferMap[name];
	Buffer.loadFromFile(path);
};

void ResourceManager::LoadFont(const char* name, const char* path) {
#ifndef _RELEASE
	auto found = FontMap.find(name);
	assert(found == FontMap.end() && "Trying to load a font under already existing key!");
#endif

	sf::Font& font = FontMap[name];
	font.loadFromFile(path);
};


sf::Texture& ResourceManager::GetTexture(const char* name) {
	return TextureMap.at(name);
}

sf::Font& ResourceManager::GetFont(const char* name) {
	return FontMap.at(name);
}

sf::SoundBuffer& ResourceManager::GetBuffer(const char* name) {
	return BufferMap.at(name);
}
