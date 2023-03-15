#include "Player.h"

#include "Stoped.h"
#include "Paused.h"
#include "Playing.h"
#include "StateVisitor.h"

#include <cassert>
#include <chrono>

namespace mplay{

Player::Player():history{}, playlist{}, forceJoin(false){

    using namespace std::chrono_literals;

    // start from the Stoped state
    stop();
    watcherThread.reset(new std::thread([&](){
            while(!forceJoin){
                if(stopPending)
                    stop();

               std::this_thread::sleep_for(200ms);
            }
        }
    ));
}

Player::~Player(){
    // break the thread loop, else the join would never end    
    forceJoin = true;
    // join before delete
    watcherThread->join();
}

void Player::stop(){
    std::scoped_lock lock(m);
    stopPending = false;
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

    std::scoped_lock lock(m);
    state->accept(visitor);
}

void Player::play(){
    assert(state);

    // This visitor changes the state to playing if it was either paused or stoped
    struct PlayVisitor : public StateVisitor{

        PlayVisitor(std::shared_ptr<State>& state, Player& player): state(state), player(player){}

        void visitPaused(Paused& paused) override{
             if(state)
                state.reset(new Playing(paused, player));
        }
        
        void visitStoped(Stoped& stoped) override{
             if(state)
                state.reset(new Playing(stoped, player));
        }
        // ref, so reset affects caller
        std::shared_ptr<State>& state;
        Player& player;
    };

    PlayVisitor visitor(state, *this);

    std::scoped_lock lock(m);
    state->accept(visitor);
}

History& Player::getHistory(){
    return history;
}

PlayList& Player::getPlayList(){
    return playlist;
}

// call that when you need to move to stop state indide another state
void Player::stopDelayed(){

    // this flag will be read by the watcher thread
    stopPending = true;
}






}
