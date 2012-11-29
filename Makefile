CPP = g++
CFLAGS = -Wall -Wextra 
# -Werror

#all: htest etest

#atest: avl_test.cpp AVL.o Node.o
#	$(CPP) $(CFLAGS) -o atest $^

#AVL.o: AVL.h AVL.cpp
#	$(CPP) $(CFLAGS) -c AVL.cpp

etest: entry_test.cpp Entry.o
	$(CPP) $(CFLAGS) -o etest entry_test.cpp Entry.o

Entry.o: Entry.h Entry.cpp
	$(CPP) $(CFLAGS) -c Entry.cpp

clean:
	rm -f *.o;
	rm -f etest; rm -f htest;
	rm -f *~;
