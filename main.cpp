#include "PlayList.h"
#include "Track.h"
#include "ActionsHandler.h"
#include "Exception.h"
#include "AddTrack.h"
#include "PrintPlayList.h"
#include "Quit.h"
#include "Help.h"
#include "Random.h"
#include "Repeat.h"
#include "Next.h"
#include "Previous.h"
#include "History.h"
#include "Play.h"
#include "Pause.h"
#include "Stop.h"
#include "Player.h"
#include "RemoveTrack.h"
#include "RemoveDuplicates.h"

int main(int argc, char *argv[]){

    try{
        mplay::Player player;
        mplay::PlayList& playList = player.getPlayList();
        mplay::History& history = player.getHistory();


        mplay::ActionsHandler actions;
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::AddTrack(playList)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::RemoveTrack(playList, history)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::RemoveDuplicates(playList, history)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::PrintPlayList(playList)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Random()));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Repeat()));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Play(player)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Pause(player)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Stop(player)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Previous(history, playList)));
        actions.registerAction(std::shared_ptr<mplay::ActionBase>(new mplay::Next(history, playList)));
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
