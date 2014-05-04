#Makefile for BestFirstSearch

#Macros
GXX = g++ -g -Wall
OBJS = main.o node.o priority_queue.o

all: BestFirstSearch

BestFirstSearch: main.o node.o priority_queue.o
	g++ $(OBJS) -o BestFirstSearch

main.o: main.cpp
	$(GXX) -c main.cpp

node.o: node.cpp
	$(GXX) -c node.cpp

priority_queue.o: priority_queue.cpp
	$(GXX) -c priority_queue.cpp

clean:
	rm *.o BestFirstSearch