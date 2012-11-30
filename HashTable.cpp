#include "HashTable.h"
#include "Entry.h"
#include <string>
#include <cassert>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;


template <typename V>
int HashTable<V>::hashFunction(string k) {

  int sum = 0;
  int hash = 0;

  for (unsigned int i = 0; i < k.size(); i++) {
    sum += (int) k[i];
  }

  hash = sum % SIZE;
  return hash;  
}

template <typename V>
Entry<V>* HashTable<V>::findEntry(string k, int hash) {
  
  list<Entry<V> > hList = vecTable[hash];
  typename list<Entry<V> >::iterator it;

  for (it = hList.begin(); it != hList.end(); it++) {
    if (it->getKey() == k) { // k is in the hash table
      return &(*it);
    }
  }
  
  return 0; // k was not found in the hash table

}

template <typename V>
HashTable<V>::HashTable() {
  vecTable.resize(SIZE);
}

template <typename V>
HashTable<V>::~HashTable<V>() {
}

template <typename V>
V* HashTable<V>::find(string k) {
  
  int hash = hashFunction(k);
  Entry<V>* e = findEntry(k,hash);
  V v;

  if (e == 0)
    return 0;
  else {
    v = e->getValue();
    return &v;
  }
}

template <typename V>
void HashTable<V>::insert(string k, V v) {

  int hash = hashFunction(k);
  Entry<V>* e = findEntry(k,hash);
 
  if (e != 0 ) {
    e->setValue(v);
    return;
  }
  else {
    Entry<V> newEntry(k,v);
    list<Entry<V> > hList = vecTable[hash];
    hList.push_back(newEntry);
    return;
  }
}

template <typename V>
void HashTable<V>::remove(string k) {

  int hash = hashFunction(k);
  Entry<V>* e = findEntry(k,hash);

  if (e == 0)
    return;
  else {
    list<Entry<V> > hList = vecTable[hash];
    hList.remove(*e);
    return;
  }
}

template <typename V>
void HashTable<V>::print() {

}


template class HashTable<int>;
template class HashTable<double>;
template class HashTable<string>;
