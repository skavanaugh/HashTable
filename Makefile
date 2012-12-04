TEST = ./test
CPP = g++
CFLAGS = -Wall -Wextra -Werror

all:
	cd $(TEST); $(MAKE)	

clean:
	cd $(TEST); $(MAKE) clean
	rm -f *.o;
	rm -f *~;
