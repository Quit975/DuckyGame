#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class MusicPlayer
{
public:
	MusicPlayer();
	void Toggle(bool &PlayMusic);
	void DrawMessage(sf::RenderWindow& window);

private:
	sf::Text text;
	sf::Music music;
	sf::Font font;
	bool PreviosKeyState = false;
};

