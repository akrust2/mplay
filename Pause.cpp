#include "Pause.h"
#include "Player.h"


namespace mplay{


Pause::Pause(Player& player):player(player){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Pause::perform(std::istream& args) {

    player.pause();
        
}

const std::string & Pause::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & Pause::keyword() const {
    static const std::string key = "pause";
    return key;
}




}
