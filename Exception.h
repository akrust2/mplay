#ifndef Exception_h
#define Exception_h
#include <string>
#include <exception>

namespace mplay{
class Exception : public std::exception{
public:

    Exception(const std::string& errorMsg);
    Exception(const std::string&& errorMsg);
    
    const char* what() const noexcept;

private:
    std::string msg;
};

class QuitException : public std::exception{
public:

    const char* what() const noexcept;

};

}
#endif
