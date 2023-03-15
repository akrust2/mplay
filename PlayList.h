#ifndef PlayList_h
#define PlayList_h

#include <initializer_list>
#include <string>
#include <list>
#include <mutex>

namespace mplay{

class Track;


class PlayList{
public:

    using Container = std::list<Track>;

    PlayList(std::initializer_list<Track> l);

    void push_back(const Track& track);
    void push_back(const Track&& track);

    Container::iterator find(const std::string& title);
    void erase(Container::iterator track);
    void removeDuplicates();

    Container::iterator begin();
    Container::iterator end();

    Container::const_iterator begin() const;
    Container::const_iterator end() const;

    Container::const_iterator cbegin() const;
    Container::const_iterator cend() const;
    
    Container::reverse_iterator rbegin();
    Container::reverse_iterator rend();

    Container::const_reverse_iterator rbegin() const;
    Container::const_reverse_iterator rend() const;

    Container::const_reverse_iterator crbegin() const;
    Container::const_reverse_iterator crend() const;

    std::size_t size() const;

private:
    std::mutex mutex;

    Container trackList;
    std::size_t s; // cache the size
    

};


}

std::ostream& operator<<(std::ostream& os, const mplay::PlayList& playList);

#endif
