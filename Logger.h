#include <string>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#define LOGFILENAME "gis_log.txt"
using namespace std;
class Logger
{
public :

 Logger(string fileName);
 void out(std::string msg);
 const std::string getTime();
 static Logger* getLog(string filename);
 void printHeader(string dataFile, string commandFile,string loggerFile);
 void printEnd();
 ~Logger();

private:
    std::ofstream file;

};
