#ifndef Paused_H
#define Paused_H

#include "State.h"
#include "Track.h"
#include <memory>

namespace mplay{

class Playing;
struct PauseToken;

class Paused : public State{
public:

    Paused(State& state);
    Paused(Playing& playing);

    Track::LengthType currentTime() const;

private:

    std::shared_ptr<PauseToken> pauseToken;


};

}

#endif
