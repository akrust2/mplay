#ifndef Playing_H
#define Playing_H

#include "State.h"
#include "PlayList.h"
#include <memory>
#include <thread>

namespace mplay{

class Stoped;
class Paused;
class History;
struct PauseToken;

class Playing : public State{
public:

    Playing(Stoped& previousState, History& history, PlayList& playlist);
    Playing(Paused& previousState, History& history, PlayList& playlist);

    ~Playing();

    std::shared_ptr<PauseToken> sharePause();

    void accept(StateVisitor& visitor) override;

private:

    void doPlay(PlayList::Container::iterator trackIt);

    std::shared_ptr<PauseToken> pauseToken;
    std::unique_ptr<std::thread> playingThread;

    History& history;
    PlayList& playlist;

    // used to stop the thread
    // can be removed if we switch to jthread
    bool keepPlaying;
    
};

}

#endif
