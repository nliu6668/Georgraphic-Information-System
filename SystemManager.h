#include <iostream>
#include <string>
#include "CommandProcessor.h"

using namespace std;
enum Command{
    WORLD,
    IMPORT,
    QUIT,
    WHAT_IS,
    WHAT_IS_AT,
    DEBUG_QUAD,
    DEBUG_HASH,
    DEBUG_POOL,
    DEBUG_WORLD,   
    WHAT_IS_IN_SIMPLE,
    WHAT_IS_IN_LONG,
    WHAT_IS_IN_POP,
    WHAT_IS_IN_WATER,
    WHAT_IS_IN_STRUCTURE
};

class SystemManager{
    public:
        SystemManager();
        ~SystemManager();

        int getCommandType(vector<string> input);
        void processCommandFile(string dataFile, string commandFile, string logFile);
        void processCommand(vector<string> input);

    private:
        CommandProcessor* command;
        string commandFile;
        string logFile;
};