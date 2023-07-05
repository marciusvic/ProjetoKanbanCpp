all: main

main: main.o semiIssue.o Issue.o Board.o Strings.o
	g++ -o main main.o semiIssue.o Issue.o Board.o Strings.o

semiIssue: semiIssue.cpp semiIssue.h
	g++ -c semiIssue.cpp

Issue.o: Issue.cpp Issue.h
	g++ -c Issue.cpp

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Strings.o: Strings.cpp Strings.h
	g++ -c Strings.cpp