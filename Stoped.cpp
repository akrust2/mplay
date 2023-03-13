#include "Stoped.h"
#include "StateVisitor.h"

namespace mplay{

void Stoped::accept(StateVisitor& visitor) {

    visitor.visitStoped(*this);
}


}
