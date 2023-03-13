#include "Paused.h"
#include "PauseToken.h"
#include "Playing.h"
#include "StateVisitor.h"


namespace mplay{

Paused::Paused(Playing& playing): pauseToken(playing.sharePause()){

}

Track::LengthType Paused::currentTime()const{

    return pauseToken->currentTime;
}



void Paused::accept(StateVisitor& visitor) {

    visitor.visitPaused(*this);
}

}
