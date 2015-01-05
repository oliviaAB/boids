all: main

main: main.cpp agent.o boid.o
	g++ -Wall -o main main.cpp agent.o boid.o

agent.o: agent.h agent.cpp parameters.h
	g++ -Wall -o agent.o agent.cpp -c

boid.o: boid.h boid.cpp agent.h
	g++ -Wall -o boid.o boid.cpp -c

