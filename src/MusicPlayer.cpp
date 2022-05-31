#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    music.openFromFile("Res/PPPolka.ogg");
    music.setVolume(10.f);
    music.play();
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