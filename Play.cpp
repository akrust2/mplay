#include "Play.h"
#include "Player.h"


namespace mplay{


Play::Play(Player& player):player(player){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Play::perform(std::istream& args) {

    player.play();
        
}

const std::string & Play::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & Play::keyword() const {
    static const std::string key = "play";
    return key;
}




}
