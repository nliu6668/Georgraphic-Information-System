#include "SystemManager.h"

  SystemManager::SystemManager(){
    
  }

   SystemManager::~SystemManager(){}
  

   int SystemManager::getCommandType(vector<string> input){
      Command command;
      for(auto i: input){
        if(input[0] == "quit"){
            command = QUIT;
        }
        if(input[0] == "debug" ){
            if(input[1]=="quad"){
                command = DEBUG_QUAD;
            }else if(input[1]=="hash"){
                command = DEBUG_HASH;
            }else if( input[1]=="pool"){
                command = DEBUG_POOL;
            }else if(input[1]=="world"){
                command = DEBUG_WORLD;
            }
        }

        if(input[0] == "world"){
            command = WORLD;
        } 

        if(input.size() == 3){
            if(input[0] == "what_is"){
                command = WHAT_IS;
            }else if(input[0] == "what_is_at"){
                command = WHAT_IS_AT;
            }
        }

        if(input[0] == "import"){
            command = IMPORT;
        }
 
        if(input[0] == "what_is_in"){
            if(input.size() == 5){
                command = WHAT_IS_IN_SIMPLE;
            }else if(input[1] == "-long"){
                command = WHAT_IS_IN_LONG;
            }else if(input[2] == "-pop"){
                command = WHAT_IS_IN_POP;
            }else if(input[2] == "water"){
                command = WHAT_IS_IN_WATER;
            }else if(input[2] == "structure"){
                command = WHAT_IS_IN_STRUCTURE;
            }
        }
      }
        return command;
   }

  void SystemManager::processCommandFile(string dataFile,string commandFile,string logFile){  
     
      command = new CommandProcessor(commandFile,logFile);
      command->printHeader(dataFile);
       int type;
       vector<vector<string> > list = command->readCommandFile();
       for(int j=0; j<list.size(); j++){
           type = getCommandType(list[j]);
           switch(type){
               case WORLD:
                    command->world(list[j][1],list[j][2],list[j][3],list[j][4]);
                    break;
               case QUIT:
                    command->quit(j,list[j][0]);
                    break;
               case IMPORT:
                    command->import(j,list[j][1]);
                    break;
               case DEBUG_HASH:
                    command->debugHash(j);

           }
       }
       
  }

  


  

