#pragma once
#include <unordered_map> //HashMap
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager;

class ResourceManager {
private:
	ResourceManager(); //constructor
	void LoadResources();

public:
	ResourceManager(const ResourceManager&) = delete; // copy constructor cannot be used
	void operator = (const ResourceManager&) = delete;  //assignmnent is locked
	~ResourceManager();  // destructor

	static ResourceManager& Get() {
		static ResourceManager instance;
		return instance;
	}

	sf::Texture GetTexture(const char);
	sf::Font GetFont(const char);
	sf::Sound GetSound(const char);

private:
	sf::Texture duckyTexture;

	std::unordered_map<const char, sf::Texture> TextureMap = {
		{'duck', duckyTexture}
	};

	std::unordered_map<const char, sf::Font> FontMap;
	std::unordered_map<const char, sf::Sound> SoundMap;

};