#ifndef Stoped_H
#define Stoped_H

#include "State.h"

namespace mplay{

class Stoped : public State{
public:
    void accept(StateVisitor& visitor) override;


};

}

#endif
