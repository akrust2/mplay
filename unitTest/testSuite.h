#include <string>

class testSuite{
public:
    static void runAll(){

        testPlayListInitilize();

        testAddTrack();
    }

    static void testPlayListInitilize();
    static void testAddTrack();
    
private:
    static void assert(bool check, std::string msg, const std::string);

};
