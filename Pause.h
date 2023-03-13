#ifndef Pause_h
#define Pause_h

#include "ActionBase.h"

namespace mplay{

class Player;

class Pause : public ActionBase{
public:

    Pause(Player& player);

    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

private:

    Player& player;
};

}

#endif
