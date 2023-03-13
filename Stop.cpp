#include "Stop.h"
#include "Player.h"


namespace mplay{


Stop::Stop(Player& player):player(player){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Stop::perform(std::istream& args) {

    player.stop();
        
}

const std::string & Stop::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & Stop::keyword() const {
    static const std::string key = "stop";
    return key;
}




}
