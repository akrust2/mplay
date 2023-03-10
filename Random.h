#ifndef Random_H
#define Random_H

#include "ActionBase.h"

namespace mplay{


class Random : public ActionBase{
public:
    static bool isRandomModeActive();

    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

private:

    // just a simple bool to hold the random state. 
    static bool isActive;

};
}
#endif
