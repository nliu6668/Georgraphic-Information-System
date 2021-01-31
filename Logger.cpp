#include <ctime>
#include "Logger.h"
#include <string>

Logger::Logger(string fileName){
     file.open(fileName,std::ofstream::out|std::ofstream::trunc);
     
    if(!file.is_open())
    {
        file <<  "[error]" <<" fileName "<<", log file can't open" <<std::endl;
    }
}

Logger::~Logger(){
    if(file.is_open()){
        file.close();
    }
 }

void Logger::printHeader(string dataFile, string commandFile,string loggerFile){
      
      if(file.is_open())
        {
            std::time_t t = std::time(0);
            
            file << "Georgraphic Information System (GIS)\nChunli Liu \nBegin of GIS Program log:\n"
            "dbFile: " <<dataFile.substr(2)<< "\nscript:  " << commandFile.substr(2)<<"\nlog:  " <<loggerFile<<
            "\nstart Time:  " << std::put_time(localtime(&t),"%c %Z")<< "\n"<<std::endl;
        }
}

Logger* Logger::getLog(string filename){
    static Logger logger(filename);
    return &logger;
}

void Logger::out(std::string msg){
    
    file << msg<<std::endl;
}

  // time format http://en.cppreference.com/w/cpp/chrono/c/strftime
const std::string Logger::getTime()
{
     time_t     now = time(0);
    struct tm  tstruct;
    char   buf[80];

    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}

 void Logger::printEnd(){
     std::time_t t = std::time(0);
     file<<"\nTerminating execution of commands\n"
     "-------------------------------------------------------------------------------------------\n"
     "End time:  "<< std::put_time(localtime(&t),"%c %Z")<< std::endl;
 }