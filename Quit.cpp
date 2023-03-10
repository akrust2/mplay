#include "Quit.h"
#include "Exception.h"


namespace mplay{

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Quit::perform(std::istream& args) {

    throw QuitException();
    
}

const std::string & Quit::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & Quit::keyword() const {
    static const std::string key = "quit";
    return key;
}




}
