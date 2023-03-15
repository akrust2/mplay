#include "Playing.h"
#include "PauseToken.h"
#include "Stoped.h"
#include "Paused.h"
#include "History.h"
#include "PlayList.h"
#include "Exception.h"
#include "Next.h"
#include "StateVisitor.h"
#include "Player.h"


#include <chrono>
namespace mplay{

Playing::Playing(Stoped& previousState,Player& player): pauseToken(new PauseToken{0}), player(player), keepPlaying(true){

    History& history = player.getHistory();
    PlayList& playlist = player.getPlayList();

    PlayList::Container::iterator track = playlist.begin();
    if(history.hasCurrent())
        track = history.current();

    if(track == playlist.end())
        throw Exception("No track left to play");

    // spawn a thread to play the track
    doPlay(track);   

}

Playing::Playing(Paused& previousState,Player& player): pauseToken(new PauseToken{previousState.currentTime()}), player(player), keepPlaying(true){

    History& history = player.getHistory();
    PlayList& playlist = player.getPlayList();

    PlayList::Container::iterator track = playlist.begin();
    if(history.hasCurrent())
        track = history.current();

    if(track == playlist.end())
        throw Exception("No track left to play");

    // spawn a thread to play the track
    doPlay(track);   
}

Playing::~Playing(){
    
    // shared with the thread. 
    // tell it to stop    
    keepPlaying = false;

    if(playingThread)
        playingThread->join();
}


void Playing::doPlay(PlayList::Container::iterator track){

    using namespace std::chrono_literals;

    playingThread.reset(new std::thread(
        [&, track/* capture by value because the object is deleted at end of scope*/](){

       History& history = player.getHistory();
       PlayList& playlist = player.getPlayList();

       PlayList::Container::iterator trackIt(track);

       while(trackIt != playlist.end()){

           std::cout << "Start playing track "<< trackIt->getTitle()<<std::endl;
            
           for(;pauseToken->currentTime < trackIt->getLenth(); pauseToken->currentTime++){
             
               if(!keepPlaying)
                   return;
 
               // Fake play
               std::this_thread::sleep_for(1s);
           }               
           std::cout << "Finished playing track "<<trackIt->getTitle()<<std::endl;
                                
           pauseToken->currentTime = 0;

           Next next(history, playlist);

           try{
               next.perform();  
               trackIt = history.current();     
           }
           catch(Exception& e){
               // end playing and return to stoped state
               // Do not call stop() directly, else it would crash the software with a Deadlock avoided exception
               player.stopDelayed();
               return;              
           }

       }
    }
    ));
}



std::shared_ptr<PauseToken> Playing::sharePause(){
    return pauseToken;
}


void Playing::accept(StateVisitor& visitor) {
    visitor.visitPlaying(*this);
}



}
