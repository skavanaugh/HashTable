CPP = g++
CFLAGS = -Wall -Wextra 
# -Werror

#all: htest etest

#htest: hash_test.cpp HashTable.o Entry.o
#	$(CPP) $(CFLAGS) -o htest $^

HashTable.o: HashTable.h HashTable.cpp
	$(CPP) $(CFLAGS) -c HashTable.cpp

etest: entry_test.cpp Entry.o
	$(CPP) $(CFLAGS) -o etest entry_test.cpp Entry.o

Entry.o: Entry.h Entry.cpp
	$(CPP) $(CFLAGS) -c Entry.cpp

clean:
	rm -f *.o;
	rm -f etest; rm -f htest;
	rm -f *~;
