#include "Exception.h"

namespace mplay{

Exception::Exception(const std::string& errorMsg): msg(errorMsg){
    
}

Exception::Exception(const std::string&& errorMsg): msg(errorMsg){

}
    
const char* Exception::what() const noexcept{
    return msg.c_str();
}

    
const char* QuitException::what() const noexcept{
    static const std::string msg = "Program has been properly quit.";
    return msg.c_str();
}

}
