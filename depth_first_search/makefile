GXX = g++ -g -std=c++0x

all: DepthFirstSearch

DepthFirstSearch: main.o
	$(GXX) main.o -o DepthFirstSearch

main.o: main.cpp
	$(GXX) -c main.cpp

clean:
	rm *.o DepthFirstSearch