#ifndef StateVisitor_H
#define StateVisitor_H

namespace mplay{

class State;
class Playing;
class Paused;
class Stoped;

class StateVisitor{
public:
    
    virtual void visit(State& state);
    virtual void visitPlaying(Playing& state);
    virtual void visitPaused(Paused& state);
    virtual void visitStoped(Stoped& state);

};


}

#endif
