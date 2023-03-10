#include "testSuite.h"
#include <iostream>

int main(int argc, char *argv[]){


    try{

        testSuite::runAll();
    }
    catch(std::exception& e){
        std::cout << "Exception caught : "<< std::string(e.what())<< std::endl;
        return 1;
    }
    catch(...){
        std::cout << "Unknown exception caught"<<std::endl;
        return 1;
    }


    return 0;
}
