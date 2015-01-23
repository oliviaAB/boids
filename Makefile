all: test.out 
#main


#main: main.cpp agent.o boid.o
#	g++ -Wall -o main main.cpp agent.o boid.o

agent.o: agent.h agent.cpp parameters.h objet.h
	g++ -Wall -o agent.o agent.cpp -c


boid.o: boid.h boid.cpp agent.h pred.h
	g++ -Wall -o boid.o boid.cpp -c

#--------------------------------------------------------------

test.out: mainbwindows.o bwindow.o agent.o boid.o objet.o pred.o
	g++ -o test.out mainbwindows.o bwindow.o agent.o boid.o objet.o pred.o -lX11 -L/usr/X11R6/lib

#test.out: mainbwindows.cpp bwindow.o agent.o boid.o 
#	g++ -o test.out mainbwindows.cpp bwindow.o agent.o boid.o  -lX11 -L/usr/X11R6/lib


mainbwindows.o: mainbwindows.cpp agent.h boid.h objet.h pred.h
	g++ -Wall -c mainbwindows.cpp

bwindow.o: bwindow.cpp bwindow.h agent.h boid.h pred.h
	g++ -Wall -c bwindow.cpp

objet.o: objet.h objet.cpp parameters.h
	g++ -Wall objet.cpp -c

predator.o: predator.cpp predator.h parameters.h
	g++ -Wall predator.cpp -c

pred.o: pred.cpp pred.h parameters.h
	g++ -Wall pred.cpp -c























	







#boid.o: boid.h boid.cpp agent.h
#	g++ -Wall -o boid.o boid.cpp -c

#--------------------------------------------------------------

#test.out: mainbwindows.o bwindow.o agent.o boid.o objet.o
#	g++ -o test.out mainbwindows.o bwindow.o agent.o boid.o objet.o -lX11 -L/usr/X11R6/lib

#test.out: mainbwindows.cpp bwindow.o agent.o boid.o 
#	g++ -o test.out mainbwindows.cpp bwindow.o agent.o boid.o  -lX11 -L/usr/X11R6/lib


#mainbwindows.o: mainbwindows.cpp agent.h boid.h objet.h
#	g++ -Wall -c mainbwindows.cpp 

#bwindow.o: bwindow.cpp bwindow.h agent.h boid.h
#	g++ -Wall -c bwindow.cpp

#objet.o: objet.h objet.cpp parameters.h
#	g++ -Wall objet.cpp -c