#ifndef State_H
#define State_H

namespace mplay{

class StateVisitor;

// Base class for a state in the state machine
class State{
public:

    virtual void accept(StateVisitor& visitor);
    
};

}

#endif
