#ifndef ActionsHandler_h
#define ActionsHandler_h

#include <unordered_map>
#include <memory>

#include "ActionBase.h"

namespace mplay{

class ActionsHandler {
public:

    void registerAction(std::shared_ptr<ActionBase> action);

    // Perform the (registered) action passed in the command line.
    // The command line needs to start with an action keyword, then its arguments (if any)
    // Any argument after expected arguments are lost
    void perform(const std::string & cmdLine);
    
    // Get the help strin for a specific action
    std::string help(const std::string& action);

    // Get a string of all the registered actions for help
    std::string keywordList() const;

private:

    std::unordered_map<std::string, std::shared_ptr<ActionBase> > actions; 
};

}

#endif
