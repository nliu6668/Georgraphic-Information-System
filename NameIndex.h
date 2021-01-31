/*
    Reference: COMP 8042 lab6
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <random>

using namespace std;

class NameIndex{
    enum BucketStatus {EMPTY, OCCUPIED, DELETED};
    int numCollisions;
    int c; // Capacity of the hashtable
    int size;  //the total number of occupied buckets
    int rehash;
    unsigned int maxProbe;
    vector<string> buckets;  // All the buckets in the hashtable
    vector<BucketStatus> status; // Status of all the buckets
     void expandAndRehash();
public:
     NameIndex();
    ~NameIndex();

    unsigned int hash(const string& key) const;
    inline bool isFull(){ return size > c*7/10; };
    inline int getTableSize(){ return c; };
    inline int getRehash(){ return rehash; };
    inline int getProbe(){ return maxProbe; };
    unsigned int insert(const string& key);
    unsigned int search(string key);
};