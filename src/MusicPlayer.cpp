#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    music.openFromFile("Res/PPPolka.ogg");
    music.setVolume(10.f);
    music.play();
}

void MusicPlayer::Toggle(bool& PlayMusic) {
    PlayMusic = !PlayMusic;

    if ((PlayMusic == false) && (music.getStatus() == sf::SoundSource::Playing)) {
        music.pause();
    }
    else if ((PlayMusic == true) && (music.getStatus() == sf::SoundSource::Paused)) {
        music.play();
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