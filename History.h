#ifndef History_H
#define History_H

#include "PlayList.h"
#include <list>
#include <mutex>

namespace mplay{

class History {
public:
    using PlayedTrack = PlayList::Container::iterator; 

    History();

    void push_back(PlayedTrack track);

    PlayedTrack current();

    // throws if no previous
    PlayedTrack previous();

    // throws if no next
    PlayedTrack next();

    bool hasCurrent() const;
    bool hasPrevious() const;
    bool hasNext() const;    

    // called to loose history
    void invalidate();


private:
    std::mutex mutex;

    std::list<PlayedTrack> tracks;

    // this is because we want to cap the size
    std::size_t size;
    std::list<PlayedTrack>::iterator currentTrack; 

    static const std::size_t maxHistorySize;
};

}
#endif
