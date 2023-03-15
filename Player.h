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

    // call that when you need to move to stop state inside another state
    void stopDelayed();
    void playDelayed();

    bool isPlaying();


private:

    std::shared_ptr<State> state;
    History history;
    PlayList playlist;

    // thread used to stop / play from the playing thread
    std::unique_ptr<std::thread> watcherThread;
    bool stopPending;
    bool playPending;

    // can be removed if we switch to jthread
    bool forceJoin;
    std::mutex m;
};

}


#endif
