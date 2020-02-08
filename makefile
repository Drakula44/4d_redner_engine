all: matrix.o main.o
	g++ -g -o all matrix.o main.o
matrix.o: ./src/matrix.cpp ./headers/matrix.h
	g++ -g -c -pthread -I/sw/include/root src/matrix.cpp
main.o: ./src/main.cpp
	g++ -g -c -pthread -I/sw/include/root src/main.cpp
