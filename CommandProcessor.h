#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <sstream>
#include <ctype.h>

#include "Logger.h"
#include "BufferPool.h"
#include "NameIndex.h"
 

using namespace std;
typedef struct Hash{
    unsigned int index;
    string featureName;
    string state;
    int offset;
}hash;

class CommandProcessor{
public:

    CommandProcessor(string _commandFile,string _logFile);
    ~CommandProcessor();
   vector<vector<string> > readCommandFile();
   
   //command process method
    void quit(int cmdNum,string cmd);
    void world(string west, string east, string north, string south);
    void import(int cmdNum, string dataFile);
    void printHeader(string dataFile);
    void debugHash(int cmdNum);

    //utility method
    int toDec(string input);
    string space(int n);
 
   //data
    void getGISRecord(string dataFile);
    void createHashtable(vector<GISRecord> list);

private:
    ifstream file;
    string commandFile;
    string UNDERLINE;
    string logFile;
    
    vector<Hash> hashTable;
    vector<GISRecord> gisRecordList;

    BufferPool* buffer;
    Logger* log;
    NameIndex* nameIndex;
};