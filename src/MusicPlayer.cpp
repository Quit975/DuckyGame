#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    music.openFromFile("Res/PPPolka.ogg");
    music.setVolume(10.f);
}

void MusicPlayer::Toggle() {
    if (isPlaying) {
        music.pause();
        isPlaying = false;
    }
    else {
        music.play();
        isPlaying = true;
    }
}

void MusicPlayer::DrawMessage(sf::RenderWindow& window) {
    #ifndef _RELEASE

    extern const int WindowHeight;

    font.loadFromFile("Res/consola.ttf");

    text.setString("To pause music press M");
    text.setFont(font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Red);
    text.setPosition(30.f, WindowHeight-50);

    window.draw(text);

    #endif
}