#include "PlayList.h"
#include "Track.h"
#include "ActionsHandler.h"
#include "Exception.h"
#include "AddTrack.h"
#include "PrintPlayList.h"
#include "Quit.h"
#include "Help.h"

int main(int argc, char *argv[]){

    try{
        mplay::PlayList playList{mplay::Track("track1", "codec1", 10), mplay::Track("track2", "codec2", 100)};

        mplay::ActionsHandler actions;
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::AddTrack(playList)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::PrintPlayList(playList)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Quit()));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Help(actions)));

        while(true){

            // commad line prompt
            std::cout <<">>>"<<std::flush;

            std::string line;

            // read till end of line
            if(std::getline(std::cin, line)){

                try{
                    actions.perform(line);
                }
                // handle non fatal exceptions
                catch(mplay::Exception& e){
                    std::cout << e.what()<<std::endl;                                        
                }            
            }
            else
                throw mplay::Exception("Failed to read line");
        }
    }
    // User command to quit
    catch(mplay::QuitException& e){
        std::cout << e.what()<<std::endl;    
    }
    catch(mplay::Exception& e){
        std::cout << e.what()<<std::endl;
        return 1;    
    }
    catch(std::exception& e){
        std::cout << e.what()<<std::endl;
        return 1;
    }

    return 0;
}
