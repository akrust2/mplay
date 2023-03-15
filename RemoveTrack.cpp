#include "RemoveTrack.h"
#include "PlayList.h"
#include "History.h"
#include "Track.h"
#include "Exception.h"

#include <iostream>
#include <sstream>

namespace mplay{

RemoveTrack::RemoveTrack(PlayList& playList, History& history):playList(playList), history(history){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void RemoveTrack::perform(std::istream& args) {

    try{
        std::string title;
        if(!args || !(args >> title))
            throw Exception("Can't read title from the command line.");

        auto it = playList.find(title);
        if(it != playList.end()){
            history.invalidate();
            playList.erase(it);
            std::cout << "Track removed"<<std::endl;
        }
        else
            std::cout <<"No track found with title "<< title<<std::endl;
    }
    catch(Exception& e){
        std::cout << "Unable to remove the track. Error : "
                  <<std::string(e.what())<< " "
                  <<help()
                  <<std::endl;
    }
}

const std::string & RemoveTrack::help() const {
    static const std::string msg = "Syntax : "+keyword()+" title";
    return msg;
}

const std::string & RemoveTrack::keyword() const {
    static const std::string key = "remove_track";
    return key;
}




}
