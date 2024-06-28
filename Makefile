all: main

DEBUG = -g

main: main.o
	$(CXX) $(DEBUG) -std=c++14 -o main main.o

main.o: main.cpp graph.h
	$(CXX) $(DEBUG) -std=c++14 -c main.cpp

clean: 
	rm -f main.o main
