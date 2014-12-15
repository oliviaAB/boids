//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "agent.h"


// ===========================================================================
//                             Include Project Files
// ===========================================================================



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
	srand(time(NULL));
 	agent my_agent1;
 	printf("x: %lf, y:%lf\n", my_agent1.get_coord()[0], my_agent1.get_coord()[1]);
 	agent my_agent2;
 	printf("x: %lf, y:%lf\n", my_agent2.get_coord()[0], my_agent2.get_coord()[1]);
 	printf("%d\n", my_agent1.near(my_agent2));

 	return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

