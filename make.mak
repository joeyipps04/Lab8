CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: matrices

matrices: matrices.o
	$(CC) $(CFLAGS) -o matrices matrices.o

matrices.o: matrices.cpp
	$(CC) $(CFLAGS) -c matrices.cpp

clean:
	rm -f *.o matrices
