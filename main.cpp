#include <iostream>
#include <stdio.h>
#include <string>
//#include "CommandProcessor.h"
#include "SystemManager.h"

using namespace std;
#define DATAFILE "data/VA_Monterey.txt"
#define COMMANDFILE "data/script01.txt"
#define LOGGERFILE "gis_log.txt"

int main(int arc, char *argv[]){
    
    vector<string> command;
    SystemManager manager;

    for(int i = 1; i < arc; ++i){
         command.push_back(argv[i]);
    }
    if(command.size() == 3){
        manager.processCommandFile(command[0],command[1],command[2]);
    }else{
        cout<<"Input the data file name, command file name, log file name\n./GIS ./VA_Monterey.txt ./script01/txt gis_log.txt"<<endl;
    }

    return 0;
}