#ifndef Previous_H
#define Previous_H

#include "ActionBase.h"

namespace mplay{

class History;
class PlayList;

class Previous : public ActionBase{
public:
    Previous(History& history, PlayList& playlist);

    // assume the stringstream contains the commad line, 
    // except the action keyword at the time perform is called
    virtual void perform(std::istream& args) override;

    virtual const std::string & help() const override;

    virtual const std::string & keyword() const override;

private:

    History& history;
    PlayList& playList; 
};


}
#endif
