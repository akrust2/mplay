#include "Repeat.h"


namespace mplay{

bool Repeat::isActive = false;


bool Repeat::isRepeatModeActive(){
    return isActive;
}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Repeat::perform(std::istream& args) {

    // type Repeat again desactivates the Repeat mode
    isActive= !isActive;
    
    std::cout << "Repeat mode is "<< (isActive?"active":"desactivated")<<std::endl;
}

const std::string & Repeat::help() const {
    static const std::string msg = "Activates the Repeat mode. Once the Repeat mode is active, call type it again to desactive the Repeat mode. Syntax : "+keyword();
    return msg;
}

const std::string & Repeat::keyword() const {
    static const std::string key = "repeat";
    return key;
}


}
