#Makefile for BestFirstSearch

#Macros
GXX = g++ -g -Wall
OBJS = main.o Node.o priority_queue.o heap.o

all: BestFirstSearch

BestFirstSearch: main.o Node.o priority_queue.o heap.o
	g++ $(OBJS) -o BestFirstSearch

main.o: main.cpp
	$(GXX) -c main.cpp

Node.o: Node.cpp
	$(GXX) -c Node.cpp

priority_queue.o: priority_queue.cpp
	$(GXX) -c priority_queue.cpp

heap.o: heap.cpp
	$(GXX) -c heap.cpp

clean:
	rm *.o BestFirstSearch