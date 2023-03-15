#include "PlayList.h"
#include "Track.h"
#include <mutex>
#include <vector>
#include <set>

namespace mplay{

PlayList::PlayList(std::initializer_list<Track> l): trackList(l){
    s = trackList.size();
}

void PlayList::push_back(const Track& track){
    std::scoped_lock lock(mutex);

    trackList.push_back(track);
    s++;
}

void PlayList::push_back(const Track&& track){
    std::scoped_lock lock(mutex);

    trackList.push_back(track);
    s++;
}


PlayList::Container::iterator PlayList::find(const std::string& title){

    return std::find_if(begin(), end(), [&title](const Track& track){return !track.getTitle().compare(title);});
}
void PlayList::erase(Container::iterator track){
    std::scoped_lock lock(mutex);
    if(track != trackList.end())
        s--;    
    trackList.erase(track);
    
}


//Remove duplicates based on title    
void PlayList::removeDuplicates(){
    std::scoped_lock lock(mutex);
    std::vector<Container::iterator> toBeErased;

    // If a string is already present in the set, it means it is a duplicate and needs to be remove
    std::set<std::string> set;
    for(auto it = begin(); it != end(); ++it){
        auto inserted = set.insert(it->getTitle());
        if(!inserted.second)
            toBeErased.push_back(it);
    }

    for(auto it : toBeErased){
        trackList.erase(it);
        s--;
    }
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


std::size_t PlayList::size() const{
    return s;
}

}


std::ostream& operator<<(std::ostream& os, const mplay::PlayList& playList){    
    
    for(const auto & track : playList){
        os << track << "\n\n";
    }

    return os;
}
