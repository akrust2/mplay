#include "Next.h"
#include "History.h"
#include "PlayList.h"
#include "Random.h"
#include "Repeat.h"
#include "Track.h"
#include "Exception.h"

namespace mplay {

Next::Next(History& history, PlayList& playlist):history(history), playList(playlist){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Next::perform(std::istream& args) {

    if(playList.begin() == playList.end())
        throw Exception("The playlist is empty");

    PlayList::Container::iterator trackIt = playList.end();

    // first, look at the history if we need to play a track that has already been played
    if(history.hasNext())
        trackIt = history.next();

    // second, if random mode is active, find a next tack randomly
    else if(Random::isRandomModeActive()){

        // Todo : handle random
        

        // move history    
        if(trackIt != playList.end())
            history.push_back(trackIt);
    }
    // last, just choose the next track on the play list
    else{
        
        // if nothing in the history, start at the first track of the playList
        PlayList::Container::iterator current = playList.begin();
        if(history.hasCurrent())
            history.current();

        if(current != playList.end())
            current++;
        // else, nothing to do, trackIt will point at the end of the playList

        trackIt = current;

        // move history    
        if(trackIt != playList.end())
            history.push_back(trackIt);
    }

    // Handle repeat mode here
    if(trackIt == playList.end() && Repeat::isRepeatModeActive()){
        trackIt = playList.begin();
        
        // move history        
        if(trackIt != playList.end())
            history.push_back(trackIt);
    }

    if(trackIt == playList.end())
        std::cout << "Reached the end of playList"<<std::endl;
    else
        std::cout << "Current track is :"<<std::endl<< *trackIt;
}

const std::string & Next::help() const {
    static const std::string msg = "Syntax : "+keyword();
    return msg;
}

const std::string & Next::keyword() const {
    static const std::string key = "next";
    return key;
}

}

