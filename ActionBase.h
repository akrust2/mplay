#ifndef ActionBase_h
#define ActionBase_h

#include <iostream>

namespace mplay{

class ActionBase{
public:

    //virtual void accept(ActionVisitor& visitor) = 0;
 
    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) = 0;

    virtual const std::string & help() const = 0;

    virtual const std::string & keyword() const = 0;
 
};

}
#endif
