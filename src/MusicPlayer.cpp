#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    music.openFromFile("Res/PPPolka.ogg");
    music.setVolume(5.f);
    music.play();
}
