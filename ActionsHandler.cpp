#include "ActionsHandler.h"
#include "Exception.h"
#include <string>
#include <sstream>

namespace mplay{


void ActionsHandler::registerAction(std::shared_ptr<ActionBase> action){
    
    actions.emplace(action->keyword(), action);
}   


// Perform the (registered) action passed in the command line.
// The command line needs to start with an action keyword, then its arguments (if any)
// Any argument after expected arguments are lost
void ActionsHandler::perform(const std::string & cmdLine){
    if(actions.empty())
        throw Exception("No actions have been registers. Command line ignored.");

    std::istringstream iss(cmdLine);
    std::string keyword;
    
    if(iss && (iss >> keyword)){
        auto found = actions.find(keyword);
        if(found == actions.end())
            throw Exception("Unrecognized keyword. Available keywords are :\n"+keywordList());
        found->second->perform(iss);
    }
    else
        throw Exception("Failed to parse the command line");
}

// Get a string of all the registered actions for help
std::string ActionsHandler::keywordList() const{
    std::string keywords;
    for(auto const & action : actions){
        keywords+=action.first;
        keywords+=" "; // trailing space at the end. Do we care ?
    }

    return keywords;
}

// Get the help strin for a specific action
std::string ActionsHandler::help(const std::string& action){
    if(actions.empty())
        throw Exception("No actions have been registers. Command line ignored.");
    
    auto found = actions.find(action);
    if(found == actions.end())
        throw Exception("Unrecognized keyword. Available keywords are :\n"+keywordList());
    return found->second->help();
}

    
};

