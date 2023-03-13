#include "Player.h"

#include "Stoped.h"
#include "Paused.h"
#include "Playing.h"
#include "StateVisitor.h"

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

    // This visitor changes the state to Pause if it was playing
    struct PauseVisitor : public StateVisitor{

        PauseVisitor(std::shared_ptr<State>& state): state(state){}

        void visitPlaying(Playing& playing) override{
             if(state)
                state.reset(new Paused{playing});
        }
        
        // ref, so reset affects caller
        std::shared_ptr<State>& state;
    };

    PauseVisitor visitor(state);
    state->accept(visitor);
}

void Player::play(){
    assert(state);

    // This visitor changes the state to playing if it was either paused or stoped
    struct PlayVisitor : public StateVisitor{

        PlayVisitor(std::shared_ptr<State>& state, History& history, PlayList& playlist): state(state), history(history), playlist(playlist){}

        void visitPaused(Paused& paused) override{
             if(state)
                state.reset(new Playing(paused, history, playlist));
        }
        
        void visitStoped(Stoped& stoped) override{
             if(state)
                state.reset(new Playing(stoped, history, playlist));
        }
        // ref, so reset affects caller
        std::shared_ptr<State>& state;
        History& history;
        PlayList& playlist;
    };

    PlayVisitor visitor(state, history, playlist);
    state->accept(visitor);
}

History& Player::getHistory(){
    return history;
}

PlayList& Player::getPlayList(){
    return playlist;
}






}
