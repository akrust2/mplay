#ifndef Track_h
#define Track_h

#include <iostream>

namespace mplay{

class Track{
public:

    using LengthType = unsigned int;
    using Codec = std::string;
    Track(const std::string& title, const Codec& codec, LengthType length);

    // constructor used to read track info from the command line
    Track(std::istream& is);

    void print(std::ostream& os) const;

    const std::string& getTitle() const;
    const Codec& getCodec() const;
    LengthType getLenth() const;
    
private:

    std::string title;
    Codec codec;
    LengthType length;
    

};
}

std::ostream& operator<<(std::ostream& os, const mplay::Track& track);

#endif
