#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>
using std::string;

template <typename V>
class Entry {
 private:
  string key;
  V value;

 public:
  Entry<V>(string k, V v);

  string getKey();
  V getValue();
  V* getValuePtr();
  
  void setValue(V v);

};

#endif
