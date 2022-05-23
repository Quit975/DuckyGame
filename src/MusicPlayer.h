#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class MusicPlayer
{
public:
	MusicPlayer();
	void ShouldBeMusicPlaying(bool &PlayMusic);

private:
	sf::Music music;
	bool PreviosKeyState = false;
};

