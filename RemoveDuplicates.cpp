#include "RemoveDuplicates.h"
#include "PlayList.h"
#include "History.h"
#include "Track.h"
#include "Exception.h"

#include <iostream>
#include <sstream>

namespace mplay{

RemoveDuplicates::RemoveDuplicates(PlayList& playList, History& history):playList(playList), history(history){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void RemoveDuplicates::perform(std::istream& args) {    
    history.invalidate();
    playList.removeDuplicates();
}

const std::string & RemoveDuplicates::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & RemoveDuplicates::keyword() const {
    static const std::string key = "removeDuplicates";
    return key;
}




}
