#include "testSuite.h"
#include "../PlayList.h"
#include "../Track.h"
#include "../AddTrack.h"
#include "../Next.h"
#include "../History.h"
#include "../Random.h"
#include "../Repeat.h"
#include "../Player.h"

#include <sstream>


void testSuite::assert(bool check, std::string msg, const std::string functionName){

    class Exception : public std::exception{
    public:
        Exception(const std::string & m):msg(m){}
        Exception(const std::string && m):msg(m){}
        const char* what() const noexcept{return msg.c_str();}
        std::string msg;
    };

    if(!check){

        std::ostringstream oss;
        oss << "Failed test "<< functionName << std::endl
              <<"Reason : "
              << msg << std::endl;
        throw Exception{oss.str()};
    }
}


void testSuite::testPlayListInitilize(){
    std::cout << "***************"<< std::endl<< "Running "<<__FUNCTION__ <<std::endl;

    mplay::PlayList playList{mplay::Track("track1", "codec1", 10), mplay::Track("track2", "codec2", 100)};

    assert(std::distance(playList.begin(), playList.end()) == 2, "The playlist should contain two tracks",  __FUNCTION__);    

    std::cout << __FUNCTION__ << " succeeded"<<std::endl;
}

void testSuite::testAddTrack(){
    std::cout << "***************"<< std::endl<< "Running "<<__FUNCTION__ <<std::endl;

    mplay::PlayList playList{};
    mplay::AddTrack addAction(playList);

    std::string trackDescription = "trackname codecname 10";
    std::istringstream iss(trackDescription);

    addAction.perform(iss);
    
    assert(std::distance(playList.begin(), playList.end()) == 1, "The playlist should contain 1 track",  __FUNCTION__);

    std::cout << __FUNCTION__ << " succeeded"<<std::endl;

}

void testSuite::testNext(){
    std::cout << "***************"<< std::endl<< "Running "<<__FUNCTION__ <<std::endl;

    // make sure random is desactivated
    if(mplay::Random::isRandomModeActive()){
        std::istringstream iss("");
        mplay::Random random;
        random.perform(iss);
    }
         
    // make sure repeat is desactivated
    if(mplay::Repeat::isRepeatModeActive()){
        std::istringstream iss("");
        mplay::Repeat repeat;
        repeat.perform(iss);
    }

    mplay::Player player;
    mplay::PlayList& playList = player.getPlayList();
    mplay::History& history = player.getHistory();
    mplay::Next next(player);

    // next has no arguments
    std::istringstream iss("");

    // corner case: next on empty playlist should throw
    bool hasThrown = false;
    try{
        next.perform(iss);
    }
    catch(...){
        hasThrown = true;
    }
    assert(hasThrown, "Next on an empty playList should throw", __FUNCTION__);
     
    playList.push_back(mplay::Track{"track1", "codec1", 10});
    playList.push_back(mplay::Track{"track2", "codec2", 100});
    

    // should select track2
    next.perform(iss);

    assert(history.current()->getTitle().compare("track2") == 0, "Next should have selected the second track in the playlist", __FUNCTION__);

    std::cout << __FUNCTION__ << " succeeded"<<std::endl;

}
