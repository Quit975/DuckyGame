#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class MusicPlayer
{
public:
	MusicPlayer();
	void Toggle();
	void Pause();
	void Play();
private:
	sf::Music music;
};