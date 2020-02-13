all: matrix.o main.o vector.o
	g++ -g -o all matrix.o main.o vector.o
matrix.o: ./src/matrix.cpp ./headers/matrix.h
	g++ -g -c -pthread -I/sw/include/root src/matrix.cpp
vector.o: ./src/vector.cpp ./headers/vector.h
	g++ -g -c -pthread -I/sw/include/root src/vector.cpp
main.o: ./src/main.cpp
	g++ -g -c -pthread -I/sw/include/root src/main.cpp
