#include "State.h"
#include "StateVisitor.h"

namespace mplay{

void State::accept(StateVisitor& visitor){
    visitor.visit(*this);
}


}
