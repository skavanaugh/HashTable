#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "Entry.h"
#include <string>
#include <cassert>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;


template <typename V>
class HashTable {
  private:
    const int SIZE;  // hashing function mods this number (which is typically prime)
    vector<list<Entry<V> > > vecTable;

    int hashFunction(string k);    
  
  public:
    HashTable(const int s = 257);  // can either use default SIZE or set SIZE in constructor
    ~HashTable();

    V* find(string k);
    string strFind(string k);
    void insert(string k, V v);
    void remove(string k);
    void print();
};


#endif
