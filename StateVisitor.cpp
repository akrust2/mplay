#include "StateVisitor.h"
#include "State.h"
#include "Playing.h"
#include "Paused.h"
#include "Stoped.h"

namespace mplay{

void StateVisitor::visit(State& state){

}

void StateVisitor::visitPlaying(Playing& state){
    visit(state);
}

void StateVisitor::visitPaused(Paused& state){
    visit(state);
}

void StateVisitor::visitStoped(Stoped& state){
    visit(state);
}

}
