#include "AddTrack.h"
#include "PlayList.h"
#include "Track.h"
#include "Exception.h"

#include <iostream>
#include <sstream>

namespace mplay{

AddTrack::AddTrack(PlayList& playList):playList(playList){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void AddTrack::perform(std::istream& args) {

    try{
        Track newTrack(args);
        playList.push_back(newTrack);
        std::cout << "Track Added"<<std::endl<< newTrack;
    }
    catch(Exception& e){
        std::cout << "Unable to add the track. Error : "
                  <<std::string(e.what())<< " "
                  <<help()
                  <<std::endl;
    }
}

const std::string & AddTrack::help() const {
    static const std::string msg = "Syntax : "+keyword()+" title codec length";
    return msg;
}

const std::string & AddTrack::keyword() const {
    static const std::string key = "add_track";
    return key;
}




}
