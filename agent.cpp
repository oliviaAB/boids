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
#include <cmath>
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
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
agent::~agent(void)
{
	delete coord;
	coord=NULL;
	delete speed;
	speed=NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

double* agent::get_coord(void) const
{
	return coord;
}

double* agent::get_speed(void) const
{
	return speed;
}

bool agent::near(const agent &other) const
{
	bool res=0;
	double norm=sqrt(coord[0]*other.get_coord()[0]+coord[1]*other.get_coord()[1]);
	if(norm<RADIUS)
	{
		res=1;
	}
	return res;
}

bool agent::near_contact(const agent &other) const
{
	bool res=0;
	double norm=sqrt(coord[0]*other.get_coord()[0]+coord[1]*other.get_coord()[1]);
	if(norm<CONTACT)
	{
		res=1;
	}
	return res;
}

double* agent::speed1(agent* birds, int size, int pos)
{
	double* v1=new double[2];
	v1[0]=0;
	v1[1]=0;

	int i=0;
	int nb=0;
	for(i=0;i<size;i++)
	{
		if(this->near(birds[i])==1 && i!=pos)
		{
			v1[0]=v1[0]+birds[i].get_speed()[0]-speed[0];
			v1[1]=v1[1]+birds[i].get_speed()[1]-speed[1];
		}
		nb++;
	}
		v1[0]=v1[0]/nb;
		v1[1]=v1[1]/nb;

	//printf("v1: %lf, %lf\n", v1[0], v1[1]);
	return v1;
}

double* agent::speed2(agent* birds, int size, int pos)
{
	double* v2=new double[2];
	v2[0]=0;
	v2[1]=0;

	int i=0;
	int nb=0;
	for(i=0;i<size;i++)
	{
		if(this->near(birds[i])==1 && i!=pos)
		{
			v2[0]=v2[0]+birds[i].get_coord()[0]-coord[0];
			v2[1]=v2[1]+birds[i].get_coord()[1]-coord[1];
		}
		nb++;
	}
	v2[0]=v2[0]/nb;
	v2[1]=v2[1]/nb;

	//printf("v2: %lf, %lf\n", v2[0], v2[1]);
	return v2;
}

double* agent::speed3(agent* birds, int size, int pos)
{
	double* v3=new double[2];
	v3[0]=0;
	v3[1]=0;

	int i=0;
	int nb=0;
	for(i=0;i<size;i++)
	{
		if(this->near_contact(birds[i])==1 && i!=pos)
		{
			v3[0]=v3[0]+birds[i].get_coord()[0]-coord[0];
			v3[1]=v3[1]+birds[i].get_coord()[1]-coord[1];
		}
		nb++;
	}
	v3[0]=-v3[0]/nb;
	v3[1]=-v3[1]/nb;

	//printf("v3: %lf, %lf\n", v3[0], v3[1]);
	return v3;
}

void agent::new_speed(agent* birds, int size, int pos)
{
	double* v1=speed1(birds, size, pos);
	double* v2=speed2(birds, size, pos);
	double* v3=speed3(birds, size, pos);
	speed[0]=speed[0]+TIME*(GAMMA1*v1[0]+GAMMA2*v2[0]+GAMMA3*v3[0]);
	speed[1]=speed[1]+TIME*(GAMMA1*v1[1]+GAMMA2*v2[1]+GAMMA3*v3[1]);
}

void agent::new_coord(agent* birds, int size, int pos)
{
	new_speed(birds, size, pos);
	coord[0]=coord[0]+TIME*speed[0];
	coord[1]=coord[1]+TIME*speed[1];
}


// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
