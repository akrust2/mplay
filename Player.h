#ifndef Player_H
#define Player_H

#include <memory>
#include <mutex>
#include <thread>
#include "History.h"
#include "PlayList.h"


namespace mplay{

class State;

// The Player Class holds the current state of the state machine
class Player{
public:

    Player();
    ~Player();

    void stop();
    void pause();
    void play();

    History& getHistory();
    PlayList& getPlayList();

    // call that when you need to move to stop state indide another state
    void stopDelayed();

private:

    std::shared_ptr<State> state;
    History history;
    PlayList playlist;

    // thread used to force stop 
    std::unique_ptr<std::thread> watcherThread;
    bool stopPending;
    // used to stop the thread
    // can be removed if we switch to jthread
    bool forceJoin;
    std::mutex m;
};

}


#endif
