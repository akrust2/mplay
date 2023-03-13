#include "PlayList.h"
#include "Track.h"
#include <mutex>

namespace mplay{

PlayList::PlayList(std::initializer_list<Track> l): trackList(l){

}

void PlayList::push_back(const Track& track){
    std::scoped_lock lock(mutex);

    trackList.push_back(track);
}

void PlayList::push_back(const Track&& track){
    std::scoped_lock lock(mutex);

    trackList.push_back(track);
}

void PlayList::remove(const Track& track){
    std::scoped_lock lock(mutex);
}

void PlayList::removeByTitle(const std::string& title){
    std::scoped_lock lock(mutex);
}

void PlayList::removeByPosition(std::size_t position){
    std::scoped_lock lock(mutex);
}
    
void PlayList::removeDuplicates(){
    std::scoped_lock lock(mutex);
}

PlayList::Container::iterator PlayList::begin(){
    return trackList.begin();
}

PlayList::Container::iterator PlayList::end(){
    return trackList.end();
}

PlayList::Container::const_iterator PlayList::cbegin() const{
    return trackList.cbegin();
}

PlayList::Container::const_iterator PlayList::cend() const{
    return trackList.cend();
}

PlayList::Container::const_iterator PlayList::begin() const{
    return trackList.cbegin();
}

PlayList::Container::const_iterator PlayList::end() const{
    return trackList.cend();
}
    
PlayList::Container::reverse_iterator PlayList::rbegin(){
    return trackList.rbegin();
}

PlayList::Container::reverse_iterator PlayList::rend(){
    return trackList.rend();
}

PlayList::Container::const_reverse_iterator PlayList::crbegin() const{
    return trackList.crbegin();
}

PlayList::Container::const_reverse_iterator PlayList::crend() const{
    return trackList.crend();
}

PlayList::Container::const_reverse_iterator PlayList::rbegin() const{
    return trackList.crbegin();
}

PlayList::Container::const_reverse_iterator PlayList::rend() const{
    return trackList.crend();
}

}


std::ostream& operator<<(std::ostream& os, const mplay::PlayList& playList){    
    
    for(const auto & track : playList){
        os << track << "\n\n";
    }

    return os;
}
