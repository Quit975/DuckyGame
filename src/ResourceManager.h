#pragma once
#include <unordered_map> //HashMap
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager;

class ResourceManager {
private:
	ResourceManager() {}; //constructor

	void LoadTexture(const char* name, const char* path);
	void LoadBuffer(const char* name, const char* path);
	void LoadFont(const char* name, const char* path);

	std::unordered_map<const char*, sf::Texture> TextureMap;
	std::unordered_map<const char*, sf::Font> FontMap;
	std::unordered_map<const char*, sf::SoundBuffer> BufferMap;

public:
	ResourceManager(const ResourceManager&) = delete; // copy constructor cannot be used
	void operator = (const ResourceManager&) = delete;  //assignmnent is locked
	~ResourceManager() {};  // destructor

	static ResourceManager& Get() {
		static ResourceManager instance;
		return instance;
	}

	void LoadResources();

	sf::Texture& GetTexture(const char*);
	sf::Font& GetFont(const char*);
	sf::SoundBuffer& GetBuffer(const char*);
};