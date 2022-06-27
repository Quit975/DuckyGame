#include "ResourceManager.h"

ResourceManager::~ResourceManager() {
}

void ResourceManager::LoadResources() {
	// textures
	sf::Texture DuckTexture;
	DuckTexture.loadFromFile("Res / JanitorDuck.png");

	sf::Texture BackgroundTexture;
	BackgroundTexture.loadFromFile("Res/quackMeadowBG.png");


	//fonts
	sf::Font TextCounter;
	TextCounter.loadFromFile("Res/consola.ttf");


	// sounds
	sf::SoundBuffer QuackBuffer;
	sf::Sound QuackSound;
	QuackBuffer.loadFromFile("Res/quack.wav");
	QuackSound.setBuffer(QuackBuffer);

	sf::SoundBuffer FrogBuffer;
	sf::Sound FrogSound;
	FrogBuffer.loadFromFile("Res/froggy.wav");
	FrogSound.setBuffer(FrogBuffer);

	sf::SoundBuffer CatchBuffer;
	sf::Sound CatchSound;
	CatchBuffer.loadFromFile("Res/frogCatch.wav");
	CatchSound.setBuffer(CatchBuffer);
}

sf::Texture& ResourceManager::GetTexture(const char name) {
	return TextureMap.at(name);
}

sf::Font& ResourceManager::GetFont(const char name) {
	return FontMap.at(name);
}

sf::Sound& ResourceManager::GetSound(const char name) {
	return SoundMap.at(name);
}
