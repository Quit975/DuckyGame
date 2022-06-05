#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    music.openFromFile("Res/PPPolka.ogg");
    music.setVolume(10.f);
    music.pause();
    music.play();
    
}

void MusicPlayer::Toggle() {
    

    if (music.getStatus() == sf::SoundSource::Status::Playing) {
        music.pause();
      
    }
    else {
        music.play();
   
    }
}
