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
#include "boid.h"
#include <cstring>




//############################################################################
//                                                                           #
//                           Class boid                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
boid::boid(void)
{
	flock=NULL;
	nb_agents=0;
	pred_flock=NULL;
	nb_pred=0;
	time_add=0;
}

boid::boid(int a_size, int p_size)
{
	flock=new agent[NMAX];
	pred_flock=new pred[p_size];

	/*
	int i=0;
	for(i=0;i<a_size;i++)
	{
		flock[i].print_coord();
	}
	*/
	nb_agents=a_size;
	nb_pred=p_size;
	time_add=0;

	/*
	for(i=0;i<a_size;i++)
	{
		flock[i].print_coord();
	}
	*/
}


boid::boid(const boid &model)
{
	flock=new agent[NMAX];
	pred_flock=new pred[model.get_nb_pred()];
	nb_agents=model.get_nb_agents();
	nb_pred=model.get_nb_pred();

	int i=0;
	for(i=0;i<NMAX;i++)
	{
		flock[i]=model.get_flock()[i];
	}
	for(i=0;i<nb_pred;i++)
	{
		pred_flock[i]=model.get_pred_flock()[i];
	}

	time_add=model.get_time_add();

	//memcpy(flock, model.get_flock(), model.get_nb_agents());
	//memcpy(pred_flock, model.get_pred_flock(), model.get_nb_pred());
	
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
boid::~boid(void)
{
	delete[] flock;
	flock=NULL;
	nb_agents=0;

}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

agent* boid::get_flock(void) const 
{
	return flock;
}

int boid::get_nb_agents(void) const
{
	return nb_agents;
}

pred* boid::get_pred_flock(void) const 
{
	return pred_flock;
}

int boid::get_nb_pred(void) const
{
	return nb_pred;
}

int boid::get_time_add(void) const
{
	return time_add;
}




void boid::update( objet* obj, int nb_obj)
{

	int i=0;
	int k=0;
	double* vpred=new double[(2*nb_pred)];

		for(i=0;i<nb_pred;i++)
	{
		pred_flock[i].up_coord(flock, nb_agents, obj, nb_obj);
		vpred[k]=pred_flock[i].get_coord()[0];
		vpred[k+1]=pred_flock[i].get_coord()[1];
		k=k+2;
	}


	for(i=0;i<nb_agents;i++)
	{
		flock[i].new_coord(flock, nb_agents, i, obj, nb_obj,vpred, nb_pred);
		//flock[i].print_coord();
	}

	time_add++;
	int adder=MU*nb_agents*(1-nb_agents/NMAX);
	if(time_add==adder)
	{
		add_agent();
		time_add=0;
	}


	//printf("UPDATE DONE\n");
}

void boid::add_agent()
{
	nb_agents++;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
