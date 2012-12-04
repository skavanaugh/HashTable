csci333-HashTable
=================

In this project we implemented a simple hash table in C++ using strings as keys.  The public 
API contains insert, remove, find and print.

Here are a few points to note:

1) The return type of find is V* rather than V because you need to return something from the find method if nothing is found.  Another approach that was talked about was to pass the appropriate NOT FOUND value into the constructor of a hash table object.  I like this less because this forces you to check every inserted value to see if it is this NOT FOUND value.  For example in an int hash table, suppose the value 100 is the not found value.  Now you need to screen the input values for 100 as you enter them into the hash table.  This is a small detail of little consequence.

2) When I initially implemented this, I created a find helper method that returned a Entry<V>*.  I thought that I would call this for find, insert and remove and then return to the appropriate Entry reference and do whatever needed to be done.  The design sounded good but in pursuing this, the STL list is based on iterators which have much in common with pointers but my design did not work well with this.  Next I thought I would return an index from my helper method and use the std::advance method offset by this index for find, insert and remove.  I need to check on this how the advance method works but I think it will have to traverse the list in order to arrive at the appropriate entry.

3)  I considered using a vector which would allow me to immediately return to the appropriate element with a helper function as described above.  But it didn't seem a sensible choice as removing from the front or middle of the vector is an expensive operation.

4) So I just used the iterator individually in each method.  I simplified the syntax slightly by using a local list reference in each method as follows: 

  list<Entry<V> > &hList = vecTable[hash];
  typename list<Entry<V> >::iterator it;

5) To store the hash table I used a vector of lists of Entries.  Most would say that it would have been better to use Entry pointers instead of Entries here but the difference is tiny and I decided not to tinker. 

6) I ran the testing through Valgrind in order to check for memory leaks and it reported none.

7) I created a getValuePtr method in the Entry class for the find method as the code return &(it->getValue()); creates an lvalue compile error.

8) I used a default size of 257 for the hash table but you can send in any positive integer into the constructor.  I used an initialization list in the constructor as described by Scott Meyers.

9) In the google testing, I started creating random strings of random length but I only used them in the test for insert collisions.
