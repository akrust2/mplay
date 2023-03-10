#ifndef Help_h
#define Help_h

#include "ActionBase.h"

namespace mplay{

class ActionsHandler;

class Help : public ActionBase{
public:

    Help(ActionsHandler& actions);

    //virtual void accept(ActionVisitor& visitor) = 0;
 
    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

private:
    ActionsHandler& actions; 
};

}

#endif
