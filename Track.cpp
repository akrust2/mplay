#include "Track.h"
#include "Exception.h"

namespace mplay{

Track::Track(const std::string& title, const Codec& codec, LengthType length): title(title), codec(codec), length(length){

}

// constructor used to read track info from the command line
Track::Track(std::istream& is){

    // known limitation: title is read up to a space character ' '.
    // having a title like "my long title" will lead to an error, 
    // as the title string will be "my  ...only
    // needs to be reworked
    if(!is || !(is >> title))
        throw Exception("Can't read title from the command line.");
    if(!is || !(is >> codec))
        throw Exception("Can't read codec from the command line");
    if(!is || !(is >> length))
        throw Exception("Can't read track length from the command line");        
}

void Track::print(std::ostream& os) const{
    os << "Title: "<< title<<"\nCodec: "<<codec<<"\nLength: "<<length<<"\n"; 
}


const std::string& Track::getTitle() const{
    return title;
}

const Track::Codec& Track::getCodec() const{
    return codec;
}

Track::LengthType Track::getLenth() const{
    return length;
}
    
}


std::ostream& operator<<(std::ostream& os, const mplay::Track& track){
    track.print(os);   
    return os;
}
