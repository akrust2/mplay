#include "PrintPlayList.h"
#include "PlayList.h"
#include "Track.h"
#include "Exception.h"

#include <iostream>
#include <sstream>

namespace mplay{

PrintPlayList::PrintPlayList(PlayList& playList):playList(playList){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void PrintPlayList::perform(std::istream& args) {

    std::cout << playList<<std::endl;
    
}

const std::string & PrintPlayList::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & PrintPlayList::keyword() const {
    static const std::string key = "playlist";
    return key;
}




}
