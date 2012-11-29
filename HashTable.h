#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "Entry.h"
#include <string>
#include <cassert>
#include <vector>
// #include <list>

using std::string;
using std::vector;
// using std::list;


template <typename V>
class HashTable {
  private:
    static const int SIZE = 97;  // hashing function mods this prime #
    vector<vector<Entry<V> > >(SIZE) vecTable;
  
  public:
    HashTable<V>();
    ~HashTable<V>();

    V find(string k);
    void insert(string k, V v);
    void remove(string k);
    void print();
};


#endif
