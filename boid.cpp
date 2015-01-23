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
	time_delete=0;
}

boid::boid(int a_size, int p_size)
{
	flock=new agent[NMAX];
	pred_flock=new pred[p_size+NMAX];

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
	time_delete=0;

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
	pred_flock=new pred[model.get_nb_pred()+NMAX];
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
	time_delete=model.get_time_delete();

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

int boid::get_time_delete(void) const
{
	return time_delete;
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
	int adder=(int)(10000/(MU*nb_agents*(1-nb_agents/NMAX)));
	//printf("adder %d\n",adder);
/*
	if(time_add==adder)
	{
		add_agent();
		time_add=0;
		printf("ADD PIOUPIOU\n");
	}

	time_delete++;
	if(time_delete==(1000/nb_pred) && nb_pred>1)
	{
		delete_pred();
		printf("ET BIM UN EN MOINS!!! \n");
	}
	
	int ag_to_add=0;
	for(i=0;i<nb_pred;i++)
	{
		if(pred_flock[i].get_time_eaten()==1)
		{
			ag_to_add++;
		}
	}


	nb_pred=nb_pred+ag_to_add;
	printf("%d\n",nb_pred);
*/
	//printf("UPDATE DONE\n");
}

void boid::add_agent()
{
	nb_agents++;
}


void boid::delete_pred()
{
	nb_pred--;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
