#include "BufferPool.h"
#include <sstream>


BufferPool::BufferPool(string _dataFile):dataFile(_dataFile),size(15),front(0),rear(0){
    file.open(_dataFile);
    q = new vector<GISRecord>(size);
}

BufferPool::~BufferPool(){
    file.close();
}

vector<GISRecord> BufferPool::readDataFile(){
    vector<GISRecord> list;
    string line, token;
    GISRecord gis;
    if(file.is_open()){
        while(getline(file,line)){
            if(isdigit(line[0])){  
                istringstream iss(line);
                vector<string> temp;
                string a;
                while(getline(iss,a,'|')){
                    temp.push_back(a);
                }

                if(!temp[8].empty() && !temp[9].empty()){
                    if(temp.size() == 20){
                        gis= GISRecord(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],
                        temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[15],temp[16],temp[17],
                        temp[18],temp[19]);
                    }else{
                        gis= GISRecord(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],
                        temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[15],temp[16],temp[17],
                        temp[18],"");
                    }
                
                if(!isFull()){
                    enque(gis);
                }

                if(!isEmpty()){
                    GISRecord record = deque();
                    list.push_back(record);
                }
                }
            }

        }
    }
    return list;
}



void BufferPool::enque(GISRecord gis){
    //if ((rear +1) % size != front ){
        (*q)[rear] = gis;
        rear = (rear + 1) % size;
    //}
}

GISRecord BufferPool::deque(){
    GISRecord gis;
   // if(front != rear){
        //gis = &(*q)[front];
        gis = (*q)[front];
        front = (front + 1)% size;
   // }
    return gis;
}

bool BufferPool::isFull(){
    return (rear+1) % size == front;
}
bool BufferPool::isEmpty(){
    return front == rear;
}

 vector<GISRecord> BufferPool::str(){
     return *q;
 }

Date BufferPool::createDate(string s){
    int year = atoi(s.substr(6).c_str());

    int month;
    string monthS = s.substr(3,2);
    monthS[0] == '0' ?  month = atoi(monthS.substr(1).c_str()) : month = atoi(monthS.c_str());

    int day;
    string dayS = s.substr(0,2);
    dayS[0] == '0' ? day = atoi(dayS.substr(1).c_str()) : day = atoi(dayS.c_str());

    Date date(year,month,day);
    return date;
}

bool BufferPool::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
