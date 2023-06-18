all: main

main: main.o Board.o Issue.o LinkedList.o SearchAlgorithms.o SortingAlgorithms.o Stack.o
	g++ -o main main.o Board.o Issue.o LinkedList.o SearchAlgorithms.o SortingAlgorithms.o Stack.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Issue.o: Issue.cpp Issue.h
	g++ -c Issue.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

SearchAlgorithms.o: SearchAlgorithms.cpp SearchAlgorithms.h
	g++ -c SearchAlgorithms.cpp

SortingAlgorithms.o: SortingAlgorithms.cpp SortingAlgorithms.h
	g++ -c SortingAlgorithms.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp