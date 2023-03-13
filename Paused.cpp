#include "Paused.h"
#include "PauseToken.h"
#include "Playing.h"

namespace mplay{

Paused::Paused(State& state): pauseToken(new PauseToken{0}){

}
Paused::Paused(Playing& playing): pauseToken(playing.sharePause()){

}

Track::LengthType Paused::currentTime()const{

    return pauseToken->currentTime;
}




}
