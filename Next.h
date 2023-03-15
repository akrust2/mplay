#ifndef Next_H
#define Next_H

#include "ActionBase.h"

namespace mplay{

class Player;

class Next : public ActionBase{
public:
    Next(Player& player);

    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;
    void perform();

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

private:

    Player& player;    
};


}
#endif
