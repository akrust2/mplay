#ifndef Player_H
#define Player_H

#include <memory>
#include "History.h"
#include "PlayList.h"


namespace mplay{

class State;

// The Player Class holds the current state of the state machine
class Player{
public:

    Player();

    void stop();
    void pause();
    void play();

    History& getHistory();
    PlayList& getPlayList();

private:

    std::shared_ptr<State> state;
    History history;
    PlayList playlist;
};

}


#endif
