#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class MusicPlayer
{
public:
	MusicPlayer();
	void Toggle();
	void Play();
	void Pause();

private:
	sf::Music music;
};