#include "Help.h"
#include "Exception.h"
#include "ActionsHandler.h"

#include <iostream>

namespace mplay{

Help::Help(ActionsHandler& actions):actions(actions){

}

// assume the stringstream contains the commad line, 
// except the action keyword at the time perform is called
void Help::perform(std::istream& args) {

    std::string option;
    if(args && args >> option){
        std::cout << actions.help(option)<<std::endl;
    }
    else{
        std::cout << "You can type commands in the prompt with the folowing keywords: "<<actions.keywordList()<<std::endl;
        std::cout << "To get more help on a specific key word, type help [keyword]"<<std::endl;
    }    
}

const std::string & Help::help() const {
    static const std::string msg = "Syntax : "+keyword()+" [keyword]";
    return msg;
}

const std::string & Help::keyword() const {
    static const std::string key = "help";
    return key;
}




}
