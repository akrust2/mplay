#ifndef RemoveTrack_h
#define RemoveTrack_h

#include "ActionBase.h"

namespace mplay{

class PlayList;
class History;

class RemoveTrack : public ActionBase{
public:

    RemoveTrack(PlayList& playList, History& history);

    //virtual void accept(ActionVisitor& visitor) = 0;
 
    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

private:
    PlayList& playList; 
    History& history;
};

}

#endif
