#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    music.openFromFile("Res/PPPolka.ogg");
    music.setVolume(15.f);
    music.play();
}
