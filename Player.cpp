#include "Player.h"

#include "Stoped.h"
#include "Paused.h"
#include "Playing.h"

#include <cassert>

namespace mplay{

Player::Player():history{}, playlist{}{
    // start from the Stoped state
    stop();
}

void Player::stop(){
    state.reset(new Stoped{});
}

void Player::pause(){
    assert(state);
    state.reset(new Paused{*state});
}

void Player::play(){
    assert(state);
    state.reset(new Playing{*state, history, playlist});
}

History& Player::getHistory(){
    return history;
}

PlayList& Player::getPlayList(){
    return playlist;
}






}
