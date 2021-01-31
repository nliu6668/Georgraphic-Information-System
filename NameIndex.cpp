#include "NameIndex.h"

NameIndex::NameIndex() : numCollisions(0),size(0),rehash(0),c(1024),maxProbe(0){
    buckets.resize(c);
    status.resize(c);
}

 NameIndex::~NameIndex() {}

 void NameIndex::expandAndRehash(){
    c = 2*c;
    vector<string> biggerBuckets(c);
    vector<BucketStatus> biggerStatus(c);
    biggerBuckets.swap(buckets);
    biggerStatus.swap(status);
    size =0;
    
    for(int i =0; i<biggerStatus.size(); i++){
        if(biggerStatus.at(i) == OCCUPIED){
            insert(biggerBuckets.at(i));
        }
    }
 }

//elfhash, key is concate the feature name and state alpha
unsigned int NameIndex::hash(const string& key) const{   
     unsigned int hash =0;
    unsigned int x = 0;
    unsigned int i = 0;
    unsigned int len = key.length();

    for(i =0; i <len; i++){
        hash = (hash << 4) + (key[i]);
        if((x=hash & 0xF0000000L) != 0){
            hash ^= (x >> 24);
        }
        hash &= ~x;
    }
    return hash;
}

 unsigned int NameIndex::insert( const string& key) {
        if(isFull()){
            expandAndRehash();
            rehash++;
        }
        unsigned int h = hash(key) % c;
        unsigned int i = 0;
        unsigned int hi = h;
        unsigned int probe;
        while (status[hi] == OCCUPIED) {
            if (buckets[hi].compare(key))
                return -1; // Key already exists
            numCollisions++;
            ++i;
            probe = (i*i + i)/2;
            if(probe > maxProbe){
                maxProbe = probe;
            }
            hi = (hi + probe) % c;
        }

        status[hi] = OCCUPIED;
        buckets[hi] = key;          
        size++;

        return hi; // Key inserted successfully
}

    unsigned int NameIndex::search(string key){
        unsigned int h = hash(key) % c;
        unsigned int i = 0;
        unsigned int hi = h;
        while (status[hi] != EMPTY) {
            if (status[hi] == OCCUPIED && buckets[hi].compare(key)) {
                // Key found
                return hi;
            }
            numCollisions++;
            ++i;
            hi = ((int)pow(hi,2)+hi)/2 % c;
        }
        // Key not found. Hit an empty bucket.
        return -1;
    }