#include "Playing.h"
#include "PauseToken.h"
#include "Paused.h"
#include "History.h"
#include "PlayList.h"
#include "Exception.h"
#include "Next.h"

#include <chrono>
namespace mplay{

Playing::Playing(State& previousState, History& history, PlayList& playlist): pauseToken(new PauseToken{0}), history(history), playlist(playlist), keepPlaying(true){

    PlayList::Container::iterator track = playlist.begin();
    if(history.hasCurrent())
        track = history.current();

    if(track == playlist.end())
        throw Exception("No track left to play");

    // spawn a thread to play the track
    doPlay(track);   

}

Playing::Playing(Paused& previousState, History& history, PlayList& playlist): pauseToken(new PauseToken{previousState.currentTime()}), history(history), playlist(playlist), keepPlaying(true){

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
               return; // nothing to do, reached end of playList               
           }

       }
    }
    ));
}



std::shared_ptr<PauseToken> Playing::sharePause(){
    return pauseToken;
}





}
