#include "Previous.h"
#include "History.h"
#include "PlayList.h"
#include "Random.h"
#include "Repeat.h"
#include "Track.h"
#include "Exception.h"

namespace mplay {

Previous::Previous(History& history, PlayList& playlist):history(history), playList(playlist){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Previous::perform(std::istream& args) {

    if(playList.begin() == playList.end())
        throw Exception("The playlist is empty");

    PlayList::Container::iterator trackIt = playList.end();

    // first, look at the history if we need to play a track that has already been played
    if(history.hasPrevious()){
        trackIt = history.previous();
    }

    if(trackIt != playList.end())
        std::cout << "Current track is :"<<std::endl<< *trackIt;
    else
        std::cout << "No previous track could be found"<<std::endl;
}

const std::string & Previous::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & Previous::keyword() const {
    static const std::string key = "previous";
    return key;
}

}

