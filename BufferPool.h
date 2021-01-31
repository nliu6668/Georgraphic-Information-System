#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

#include "GISRecord.h"

using namespace std;

class BufferPool{
    public:
        BufferPool(string _dataFile);
        ~BufferPool();

        //queue<GISRecord> str();
       vector<GISRecord> str();
        bool is_number(const std::string& s);
        Date createDate(string s);

        //bufferpool
        void enque(GISRecord gis);
        GISRecord deque();
    
        bool isFull();
        bool isEmpty();

        //read data file
        vector<GISRecord> readDataFile();

    private: 
        ifstream file; 
        string dataFile;
        vector<GISRecord> *q;
        int size;
        int front;
        int rear;
        

};