#ifndef Repeat_H
#define Repeat_H

#include "ActionBase.h"

namespace mplay{


class Repeat : public ActionBase{
public:
    static bool isRepeatModeActive();

    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

private:

    // just a simple bool to hold the Repeat state. 
    static bool isActive;

};
}
#endif
