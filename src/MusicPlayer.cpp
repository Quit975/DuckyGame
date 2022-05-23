#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    music.openFromFile("Res/PPPolka.ogg");
    music.setVolume(10.f);
    music.play();
}

void MusicPlayer::ShouldBeMusicPlaying(bool &PlayMusic){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        PreviosKeyState = true;
    }
    else {
        if (PreviosKeyState) {
            PlayMusic = !PlayMusic;
            PreviosKeyState = false;
        }
    }

    if ((PlayMusic == false) && (music.getStatus() == sf::SoundSource::Playing)) {
        music.pause();
    } 
    else if ((PlayMusic == true) && (music.getStatus() == sf::SoundSource::Paused)) {
        music.play();
    }
}