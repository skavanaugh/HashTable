BUILD = ../build
TEST = ../test
LIB = ../lib
SRC = ../src
INC = ../include

GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a

GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra

all: $(TEST)/HashTest

$(TEST)/HashTest: $(TEST)/hash_test.cpp $(SRC)/HashTable.o $(INC)/HashTable.h $(INC)/Entry.h $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o HashTest $(TEST)/hash_test.cpp $(SRC)/HashTable.o $(SRC)/Entry.o $(GTEST_MAINA)

$(SRC)/HashTable.o: $(SRC)/HashTable.cpp $(SRC)/HashTable.h $(SRC)/Entry.cpp $(SRC)/Entry.h
	cd $(SRC); $(MAKE)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

clean:
	rm -f $(TEST)/*Test
	rm -f $(GTEST_MAINA)
	cd $(SRC); $(MAKE) clean
	cd $(GTEST)/make; $(MAKE) clean
	cd $(TEST)

