#include "CommandProcessor.h"

 CommandProcessor::CommandProcessor(string _commandFile,string _logFile):
 commandFile(_commandFile),logFile(_logFile),UNDERLINE("------------------------------------------------------------------------------------------")
 {
     log = Logger::getLog(logFile);
 }
  
 CommandProcessor:: ~CommandProcessor(){}

 vector<vector<string> > CommandProcessor::readCommandFile(){
    vector<vector<string> > list;
    vector<vector<string> > listA;
    
    vector<string> test;
     string line;
      
     file.open(commandFile);
     if(file.is_open()){
        while(getline(file, line)){
            if(line[0]!= ';' ){
                istringstream iss(line);
                string token;
                string quit = "quit";
                vector<string> temp;
                //while(getline(iss, token)){
                while(iss>>token){
                    temp.push_back(token);  
                }
                listA.push_back(temp);
            }
        }
     }

    int pos;
     for(int i =0; i<listA.size(); i++){
         if(listA[i][0] == "quit"){
             pos = i+1;
         }
     }
    
     for(int j=0; j< pos;j++){
         list.push_back(listA[j]);
     }

     return list;
}

void CommandProcessor::debugHash(int cmdNum){
    int tableSize = nameIndex->getTableSize();
    int elements = gisRecordList.size()-1;
    log->out("Command "+to_string(cmdNum)+ ": debug hash\n"
        + "\nFormat of display is"
        + "\nSlot number: data record\nCurrent table size is "  
        + to_string(tableSize)+
        + "\nNumber of elements in table is "+to_string(elements)+"\n");



    log->out("\n"+UNDERLINE);
}

void CommandProcessor::import(int cmdNum, string dataFile){
    getGISRecord(dataFile);
   
    int total =0;
    int size = gisRecordList.size();
    for(auto a: gisRecordList){
        total += a.getFeatureName().size();
    }
     int aveNameLength = total/size;
    log->out("Command " + to_string(cmdNum)+ ":  import   " + dataFile);
    log->out("Imported Features by name:  "+to_string(size-1));
    //log->out("Longest probe sequence:     3");
    createHashtable(gisRecordList);
    log->out("Imported Location:          " + to_string(size-1));
    log->out("Average name length:        " + to_string(aveNameLength));
    // int i=1;
    //  for(auto gis:list){
    //      log->out(to_string(i)+": Prime latitude = "+gis.getPrimeLatDms());
    //      i++;
    //  }
    log->out(UNDERLINE);
}

//vector<GISRecord> CommandProcessor::getGISRecord(string dataFile){
void CommandProcessor::getGISRecord(string dataFile){
     buffer = new BufferPool(dataFile);
     gisRecordList = buffer->readDataFile();
}

//vector<Hash> CommandProcessor::createHashtable(vector<GISRecord> list){
void CommandProcessor::createHashtable(vector<GISRecord> list){
     nameIndex = new NameIndex();
     Hash hash;
     string key;
     unsigned int hashVal;
     for(int i =0; i<list.size();i++){
         key = list[i].getFeatureName()+ " " + list[i].getStateAlpha();
         //hashVal = nameIndex->insert(key);
         hash.featureName = list[i].getFeatureName();
         hash.state = list[i].getStateAlpha();
         hash.offset = i;
         if(hashVal != -1){
            hash.index = nameIndex->insert(key);
              hashTable.push_back(hash);
         }
     }
     unsigned int maxProbe = nameIndex->getProbe();
     log->out("Longest probe sequence:     " + to_string(maxProbe));
}


void CommandProcessor::quit(int cmdNum,string cmd){
    log->out("Command " + to_string(cmdNum)+ ":  "+cmd);
    log->printEnd();
}

void CommandProcessor::printHeader(string dataFile){
   log->printHeader(dataFile,commandFile,logFile);
}

 void CommandProcessor::world(string west, string east, string south, string north){
      int westL = toDec(west);
      int eastL = toDec(east);
      int northL = toDec(north);
      int southL = toDec(south);

    log->out("world " + west + " " + east +" " + north + " " + south+ "\n"+UNDERLINE);
      string header="\nLatitude/longitude values in index entries are shown as signed integers, in total seconds\n"+UNDERLINE
      +"\nWorld boundaries are set to:\n";
     string output = header+space(48)+to_string(northL)+"\n"
                     +space(38)+to_string(westL)+space(10)+to_string(eastL)+"\n"
                     +space(48)+to_string(southL)+"\n"+UNDERLINE+"\n";
     log->out(output);
 } 
 
int CommandProcessor::toDec(string input){
     int decResult;
     int degree;
     int min;
     int second;
     string::size_type sz;

     int size = input.size();
     char end = input[size-1];
     switch(end){
        case 'N':
            degree = stoi(input.substr(0,2));
            min = stoi(input.substr(2,2));
            second = stoi(input.substr(4,2));
            decResult = (degree*3600+min*60+second);
        break;
        case 'W':
            if(input[0]=='0'){
                degree = stoi(input.substr(1,2));
            }else{
                degree = stoi(input.substr(0,3));
            }
            min = stoi(input.substr(3,2));
            second = stoi(input.substr(5,2));
            decResult = -(degree*3600+min*60+second);
           
            break;
        default:
            break;

     }
     return decResult;

 }

 string CommandProcessor::space(int n){
    string spaces=" ";
     for(int i=0; i <n;i++){
         spaces +=" ";
     }
     return spaces;
 }