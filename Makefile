all: main test.out

main: main.cpp agent.o boid.o
	g++ -Wall -o main main.cpp agent.o boid.o

agent.o: agent.h agent.cpp parameters.h
	g++ -Wall -o agent.o agent.cpp -c

boid.o: boid.h boid.cpp agent.h
	g++ -Wall -o boid.o boid.cpp -c

#--------------------------------------------------------------

test.out: mainbwindows.o bwindow.o agent.o boid.o 
	g++ -o test.out mainbwindows.o bwindow.o agent.o boid.o  -lX11 -L/usr/X11R6/lib

#test.out: mainbwindows.cpp bwindow.o agent.o boid.o 
#	g++ -o test.out mainbwindows.cpp bwindow.o agent.o boid.o  -lX11 -L/usr/X11R6/lib


mainbwindows.o: mainbwindows.cpp agent.h boid.h
	g++ -c mainbwindows.cpp 

bwindow.o: bwindow.cpp bwindow.h agent.h boid.h
	g++ -c bwindow.cpp
