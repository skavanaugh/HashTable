#include "gtest/gtest.h"
#include "../include/HashTable.h"
#include "../include/Entry.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
// #include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;

TEST(HashTableTest, ConstructDestruct) {

  HashTable<int> iS;
  // iS.print();
  HashTable<int>* iH = new HashTable<int>();
  // iH->print();
  delete iH;

  HashTable<int> iS7(7);
  iS7.print();
  HashTable<int>* iH13 = new HashTable<int>(13);
  iH13->print();
  delete iH13;

  HashTable<double> dS;
  // dS.print();
  HashTable<double>* dH = new HashTable<double>();
  // dH->print();
  delete dH;
 
  HashTable<int> dS7(7);
  dS7.print();
  HashTable<int>* dH13 = new HashTable<int>(13);
  dH13->print();
  delete dH13;

  HashTable<string> sS;
  // sS.print();
  HashTable<string>* sH = new HashTable<string>();
  // sH->print();
  delete sH;
 
  HashTable<string> sS7(7);
  sS7.print();
  HashTable<string>* sH13 = new HashTable<string>(13);
  sH13->print();
  delete sH13;

}

TEST(HashTableTest, insert) {
 
  HashTable<int> hi(5);
  HashTable<double> di(5);
  HashTable<string> si(5);
 
  hi.insert("sylvan",1);
  di.insert("sylvan",1.1);
  si.insert("sylvan","lora");

  EXPECT_EQ(1,*(hi.find("sylvan")));
  EXPECT_EQ(1.1,*(di.find("sylvan")));
  EXPECT_EQ("lora",*(si.find("sylvan")));

}

TEST(HashTableTest, insertCollisions) {

  vector<string > v;
  srand(time(0));
  int randLength = rand() % 20 + 1;
  string curStr = "";
  int randChar = 0;
  int numStrings = 10;  

  for (int i=0; i<numStrings; i++) {

    for (int j=0; j<randLength; j++) {
      randChar = rand() % 223 + 32;
        while (!isgraph(randChar)) {
          randChar = rand() % 223 + 32;
        }
      curStr += (char) randChar;
    }
    v.push_back(curStr);
    randLength = rand() % 20 + 1;
    curStr = "";
  }

  HashTable<int> hi(7);
  HashTable<double> di(7);
  HashTable<string> si(7);
  
  int i = 0;
  double d = 0.1;
  string s = "s";  

  for (int j=0; j<numStrings; j++){
    hi.insert(v[j],i+j);
    di.insert(v[j],d+j);
    s += (char)(j+48);
    si.insert(v[j],s);
    
    // if (hi.find(v[j])!=0)
    EXPECT_EQ(i+j,*(hi.find(v[j])));
    // if (di.find(v[j])!=0)
    EXPECT_EQ(d+j,*(di.find(v[j])));
    // if (si.find(v[j])!=0)
    EXPECT_EQ(s,*(si.find(v[j])));

    s = "s";
  }
  hi.print();
  di.print();
  si.print();
}

TEST (HashTableTest, insertOverwrite) {
 
  HashTable<int> hi(7);
  HashTable<double> di(7);
  HashTable<string> si(7);
 
  hi.insert("sylvan",1);
  di.insert("sylvan",1.1);
  si.insert("sylvan","lora");

  hi.insert("sylvan",22);
  di.insert("sylvan",22.1);
  si.insert("sylvan","lora22");
  
  EXPECT_EQ(22,*(hi.find("sylvan")));
  EXPECT_EQ(22.1,*(di.find("sylvan")));
  EXPECT_EQ("lora22",*(si.find("sylvan")));

}

TEST (HashTableTest, remove) {

  HashTable<int> hi(7);
  HashTable<double> di(7);
  HashTable<string> si(7);
 
  hi.insert("sylvan",1);
  di.insert("sylvan",1.1);
  si.insert("sylvan","lora");

  hi.remove("sylvan");
  di.remove("sylvan");
  si.remove("sylvan");

  EXPECT_EQ(0,hi.find("sylvan"));
  EXPECT_EQ(0,di.find("sylvan"));
  EXPECT_EQ(0,si.find("sylvan"));

}

TEST (HashTableTest, removeDNE) {

  HashTable<int> hi(7);
  HashTable<double> di(7);
  HashTable<string> si(7);

  hi.remove("sylvan");
  di.remove("sylvan");
  si.remove("sylvan");

  EXPECT_EQ(0,hi.find("sylvan"));
  EXPECT_EQ(0,di.find("sylvan"));
  EXPECT_EQ(0,si.find("sylvan"));

}

TEST (HashTableTest, find) {

  HashTable<int> hi(3);
  HashTable<double> di(3);
  HashTable<string> si(3);
 
  hi.insert("test",32);
  di.insert("test",32.7);
  si.insert("test","data");

  EXPECT_EQ(32,*(hi.find("test")));
  EXPECT_EQ(32.7,*(di.find("test")));
  EXPECT_EQ("data",*(si.find("test")));

}

TEST (HashTableTest, findDNE) {

  HashTable<int> hi(3);
  HashTable<double> di(3);
  HashTable<string> si(3);
 
  EXPECT_EQ(0,hi.find("test"));
  EXPECT_EQ(0,di.find("test"));
  EXPECT_EQ(0,si.find("test"));

}

TEST (HashTableTest, print) {

  HashTable<int> hi(9);
  HashTable<double> di(9);
  HashTable<string> si(9);

  hi.insert("sylvan",41);
  di.insert("sylvan",41.5);
  si.insert("sylvan","daddy");

  hi.insert("lora",39);
  di.insert("lora",39.5);
  si.insert("lora","mommy");

  hi.insert("jake",6);
  di.insert("jake",6.5);
  si.insert("jake","school");

  hi.print();
  di.print();
  si.print();

}

 
