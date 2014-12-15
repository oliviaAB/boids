//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include <ctime>
#include "agent.h"


//############################################################################
//                                                                           #
//                           Class agent                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
agent::agent(void)
{
	coord=new double[2];
	coord[0]=(rand()/(double)RAND_MAX) * WIDTH;
	coord[1]=(rand()/(double)RAND_MAX) * HEIGHT;

	//Initial speed: vx=1; vy=1
	speed=new double[2];
	speed[0]=1;
	speed[1]=1;

	width=WIDTH;
	height=HEIGHT;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
agent::~agent(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
