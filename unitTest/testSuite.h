#include <string>

class testSuite{
public:
    static void runAll(){

        testPlayListInitilize();

        testAddTrack();

        testNext();
    }

    static void testPlayListInitilize();
    static void testAddTrack();
    static void testNext();
    
private:
    static void assert(bool check, std::string msg, const std::string);

};
