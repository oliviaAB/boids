//****************************************************************************
//
//
//
//****************************************************************************
// ===========================================================================
// Libraries
// ===========================================================================
// ===========================================================================
// Project Files
// ===========================================================================
#include <ctime>
#include <cmath>
#include "agent.h"
//############################################################################
// #
// Class agent #
// #
//############################################################################
// ===========================================================================
// Definition of static attributes
// ===========================================================================
// ===========================================================================
// Constructors
// ===========================================================================
agent::agent(void)
{
	coord=new double[2];
	//coord[0]=(rand()/(double)RAND_MAX) *WIDTH;
	//coord[1]=(rand()/(double)RAND_MAX) * HEIGHT;
	coord[0]=(rand()/(double)RAND_MAX) * (WIDTHCRE +100)+100;
	coord[1]=(rand()/(double)RAND_MAX) * (HEIGHTCRE +100)+100;
	//Initial speed: vx=1; vy=1
	speed=new double[2];
	speed[0]=10;
	speed[1]=0;
	alive=1;
}

agent::agent(const agent &model)
{
	coord=new double[2];
	speed=new double[2];
	coord[0]=model.get_coord()[0];
	coord[1]=model.get_coord()[1];
	speed[0]=model.get_speed()[0];
	speed[1]=model.get_speed()[1];
}

// ===========================================================================
// Destructor
// ===========================================================================
agent::~agent(void)
{
	delete coord;
	coord=NULL;
	delete speed;
	speed=NULL;
}
// ===========================================================================
// Public Methods
// ===========================================================================
double* agent::get_coord(void) const
{
	return coord;
}

double* agent::get_speed(void) const
{
	return speed;
}

bool agent::is_alive(void) const
{
	return alive;
}


bool agent::near(const agent &other) const
{
	bool res=0;
	//double norm=sqrt(coord[0]*other.get_coord()[0]+ coord[1]*other.get_coord()[1]);
	double norm=sqrt((coord[0]-other.get_coord()[0])*(coord[0]-other.get_coord()[0])+(coord[1]-other.get_coord()[1])*(coord[1]-other.get_coord()[1]));
	if(norm<RADIUS)
	{
		res=1;
	}

	//printf("radius: %d\n",res);
	return res;
}



bool agent::near_contact(const agent &other) const
{
	bool res=0;
	double norm=sqrt((coord[0]-other.get_coord()[0])*(coord[0]-other.get_coord()[0])+(coord[1]-other.get_coord()[1])*(coord[1]-other.get_coord()[1]));
	if(norm<CONTACT)
	{
		res=1;
	}
	return res;
}

bool agent::near_obs(const objet &my_obj) const
{
	bool res=0;
	double norm=sqrt((coord[0]-my_obj.get_coord()[0])*(coord[0]-my_obj.get_coord()[0])+(coord[1]-my_obj.get_coord()[1])*(coord[1]-my_obj.get_coord()[1]));
	if(norm<(CONTACT+10))
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
	int test=0;
	for(i=0;i<size;i++)
	{	
		if(this->near(birds[i])==1 && i!=pos)
		{
			v1[0]=v1[0]+birds[i].get_speed()[0]-speed[0];
			v1[1]=v1[1]+birds[i].get_speed()[1]-speed[1];
			nb++;
		}
	test++;
	}

	//printf("%d\n",test);

	if(nb!=0)
	{
		v1[0]=v1[0]/nb;
		v1[1]=v1[1]/nb;
	}
	
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
			nb++;
		}	
	}
	if(nb!=0)
	{
		v2[0]=v2[0]/nb;
		v2[1]=v2[1]/nb;
	}

	//printf("v2: %lf, %lf\n", v2[0], v2[1]);
	return v2;
}


double* agent::speed3(agent* birds, int size, int pos, objet* obj, int nb_obj)
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
			nb++;
		}
	}

	if(nb!=0)
	{
		v3[0]=-v3[0]/nb;
		v3[1]=-v3[1]/nb;
	}

	nb=0;
	double* vo=new double[2];
	vo[0]=0;
	vo[1]=0;


	for(i=0;i<nb_obj;i++)
	{
		if(this->near_obs(obj[i])==1 && i!=pos)
		{
			vo[0]=vo[0]+obj[i].get_coord()[0]-coord[0];
			vo[1]=vo[1]+obj[i].get_coord()[1]-coord[1];
			nb++;
		}
	}

		if(nb!=0)
	{
		vo[0]=-vo[0]/nb;
		vo[1]=-vo[1]/nb;
	}

	v3[0]=v3[0]+vo[0];
	v3[1]=v3[1]+vo[1];

	//printf("v3: %lf, %lf\n", v3[0], v3[1]);
	return v3;
}

double* agent::speed4(double* vpred, int nb_pred)
{
	double* v4=new double[2];
	v4[0]=0;
	v4[1]=0;
	int i=0;
	int nb=0;
	for(i=0;i<(2*nb_pred);i++)
	{
		double norm=sqrt((coord[0]-vpred[i])*(coord[0]-vpred[i])+(coord[1]-vpred[i+1])*(coord[1]-vpred[i+1]));
		if(norm<RADIUS)
		{
			v4[0]=v4[0]-(vpred[i]-coord[0])/norm;
			v4[1]=v4[1]-(vpred[i+1]-coord[1])/norm;
			nb++;
		}	
	}
	if(nb!=0)
	{
		v4[0]=v4[0]/nb;
		v4[1]=v4[1]/nb;
	}

	//printf("v2: %lf, %lf\n", v2[0], v2[1]);
	return v4;

}



void agent::new_speed(agent* birds, int size, int pos, objet* obj, int nb_obj, double* vpred, int nb_pred)
{
	double* v1=speed1(birds, size, pos);
	double* v2=speed2(birds, size, pos);
	double* v3=speed3(birds, size, pos, obj, nb_obj);
	double* v4=speed4(vpred, nb_pred);
	speed[0]=speed[0]+TIME*(GAMMA1*v1[0]+GAMMA2*v2[0]+GAMMA3*v3[0]+GAMMA4*v4[0]);
	speed[1]=speed[1]+TIME*(GAMMA1*v1[1]+GAMMA2*v2[1]+GAMMA3*v3[1]+GAMMA4*v4[1]);

	//norm max = VMAX

	double norm=sqrt(speed[0]*speed[0]+speed[1]*speed[1]);

	if(norm>VMAX)
	{
		double max=(norm/VMAX);
		speed[0]=speed[0]/max;
		speed[1]=speed[1]/max;
	}
	
}


void agent::new_coord(agent* birds, int size, int pos, objet* obj, int nb_obj,double* vpred, int nb_pred)
{
	
	if(alive==1)
	{
		new_speed(birds, size, pos, obj, nb_obj, vpred, nb_pred);
		coord[0]=coord[0]+TIME*speed[0];
		coord[1]=coord[1]+TIME*speed[1];



	//if the agent reaches the superior border
		if(coord[1]<(H)) //+50
		{
			speed[1]=speed[1]+1;
		}

		//if the agent reaches the inferior border
		if(coord[1]>(WIDTH-H))
		{
			speed[1]=speed[1]-1;
		}	

		//if the agent reaches the left border
		if(coord[0]<(V)) //+50
		{
			speed[0]=speed[0]+1;
		}

		//if the agent reaches the right border
		if(coord[0]>(HEIGHT-V))
		{
			speed[0]=speed[0]-1;
		}
	}
	

/*
		new_speed(birds, size, pos, obj, nb_obj, vpred, nb_pred);
		coord[0]=coord[0]+TIME*speed[0];
		coord[1]=coord[1]+TIME*speed[1];



	//if the agent reaches the superior border
		if(coord[1]<(H)) //+50
		{
			speed[1]=speed[1]+1;
		}

		//if the agent reaches the inferior border
		if(coord[1]>(WIDTH-H))
		{
			speed[1]=speed[1]-1;
		}	

		//if the agent reaches the left border
		if(coord[0]<(V)) //+50
		{
			speed[0]=speed[0]+1;
		}

		//if the agent reaches the right border
		if(coord[0]>(HEIGHT-V))
		{
			speed[0]=speed[0]-1;
		}
		*/

}

void agent::print_coord(void) const
{
	printf("x= %lf, y= %lf\n", coord[0], coord[1]);
}

void agent::death(void)
{
	coord[0]=-100;
	coord[1]=-100;
	speed[0]=0;
	speed[0]=0;
	alive=0;
}
// ===========================================================================
// Protected Methods
// ===========================================================================
// ===========================================================================
// Non inline accessors
// ===========================================================================