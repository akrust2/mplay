#ifndef Quit_h
#define Quit_h

#include "ActionBase.h"

namespace mplay{

class PlayList;

class Quit : public ActionBase{
public:

    //virtual void accept(ActionVisitor& visitor) = 0;
 
    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

};

}

#endif
