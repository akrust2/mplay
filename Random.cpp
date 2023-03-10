#include "Random.h"


namespace mplay{

bool Random::isActive = false;


bool Random::isRandomModeActive(){
    return isActive;
}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Random::perform(std::istream& args) {

    // type random again desactivates the random mode
    isActive= !isActive;
    
    std::cout << "Random mode is "<< (isActive?"active":"desactivated")<<std::endl;
}

const std::string & Random::help() const {
    static const std::string msg = "Activates the random mode. Once the random mode is active, call type it again to desactive the random mode. Syntax : "+keyword();
    return msg;
}

const std::string & Random::keyword() const {
    static const std::string key = "random";
    return key;
}


}
