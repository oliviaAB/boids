all: main

main: main.cpp agent.o
	g++ -Wall -o main main.cpp agent.o

agent.o: agent.h agent.cpp
	g++ -Wall -o agent.o agent.cpp -c