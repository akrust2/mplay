#include "History.h"
#include "Exception.h"

namespace mplay{

const std::size_t History::maxHistorySize = 100;

History::History():size(0), currentTrack(tracks.begin()){

}

void History::push_back(History::PlayedTrack track){
    tracks.push_back(track);

    // if the max size is reached, we drop the oldest element
    if(size == maxHistorySize)
        tracks.pop_front(); 
    else
        ++size;

    // move the current track to the newly added track
    currentTrack = std::prev(tracks.end());
    
}

History::PlayedTrack History::current(){
    if(!hasCurrent())
        throw Exception("Current track undefined");

    return *currentTrack;
}


History::PlayedTrack History::previous(){
    if(!hasPrevious())
        throw Exception("Previous from History cannot be called if the current track is already at the begining of history");

    return *(--currentTrack);    
}

History::PlayedTrack History::next(){
    if(!hasNext())
        throw Exception("Next from History should not be called if the current track is already at the end of history");

    return *(++currentTrack);
}

bool History::hasCurrent() const{
    return currentTrack != tracks.end();
}

bool History::hasPrevious() const{
    return currentTrack != tracks.begin();
}

bool History::hasNext() const{
    return currentTrack != tracks.end() && std::next(currentTrack) != tracks.end();
}

// called to loose history
void History::invalidate(){
    size = 0;
    tracks.clear();
    currentTrack = tracks.begin();
}


}
