#include "HashTable.h"
#include "Entry.h"
#include <string>
#include <cassert>
#include <vector>
#include <list>
#include <iostream>

using std::string;
using std::vector;
using std::list;
using std::cout;
using std::endl;

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
/*
template <typename V>
bool HashTable<V>::findEntry(string k, int hash, int& index) {
  
  list<Entry<V> >& hList = vecTable[hash];
  typename list<Entry<V> >&::iterator it;
  index = 0;

  for (it = hList.begin(); it != hList.end(); it++) {
    if (it->getKey() == k) { // k is in the hash table
      return true;
    }
    index++;
  }
  
  return false; // k was not found in the hash table

}
*/
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
  list<Entry<V> > &hList = vecTable[hash];
  typename list<Entry<V> >::iterator it;

  for (it=hList.begin(); it!=hList.end(); it++) {
    if (it->getKey() == k) {
      // return &(it->getValue());
      return it->getValuePtr();
    }
  }

  // if no key == k in the hash table
  return 0;

}

template <typename V>
void HashTable<V>::insert(string k, V v) {

  int hash = hashFunction(k);
  list<Entry<V> > &hList = vecTable[hash];
  typename list<Entry<V> >::iterator it;

  for (it=hList.begin(); it!=hList.end(); it++) {
    if (it->getKey() == k) {
      it->setValue(v);
      return;
    }
  }

  // if no key == k in the hash table create a new Entry
  Entry<V> newEntry(k,v);
  hList.push_back(newEntry); 
  return;

}

template <typename V>
void HashTable<V>::remove(string k) {

  int hash = hashFunction(k);
  list<Entry<V> > &hList = vecTable[hash];
  typename list<Entry<V> >::iterator it;

  for (it=hList.begin(); it!=hList.end(); it++) {
    if (it->getKey() == k) {
      hList.erase(it);
      return;
    }
  }

  // if no key == k in the hash table return
  return;

}

template <typename V>
void HashTable<V>::print() {

  typename list<Entry<V> >::iterator it;

  cout << endl;
  for (int i=0; i<SIZE; i++) {
    
    cout << i << ": ";
    list<Entry<V> > &hList = vecTable[i];
    for (it=hList.begin(); it!=hList.end(); it++) {
      cout << "[" << it->getKey() << "," << it->getValue() << "]";
    }
    cout << endl;
  }
  cout << endl;

  return;
}


template class HashTable<int>;
template class HashTable<double>;
template class HashTable<string>;
