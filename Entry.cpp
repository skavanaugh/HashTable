#include <string>
#include <cassert>
#include "Entry.h"

using std::string;

template <typename V>
Entry<V>::Entry(string k, V v) {
  key = k;
  value = v;
}

template <typename V>
string Entry<V>::getKey() {
  return key;
}

template <typename V>
V Entry<V>::getValue() {
  // assert(this!=0);
  return value;
}

template <typename V>
void Entry<V>::setValue(V v) {
  // assert(this!=0);
  value = v;
}


template class Entry<int>;
template class Entry<double>;
template class Entry<string>;

