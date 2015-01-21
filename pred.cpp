
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
#include "pred.h"
#include <ctime>
#include <cmath>
#include "parameters.h"


//############################################################################
//                                                                           #
//                           Class pred                                      #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================

pred::pred()
{
        agent();
        time_eaten=0;
}  

pred::pred(const pred &model)
{
        coord=new double[2];
        speed=new double[2];
        coord[0]=model.get_coord()[0];
        coord[1]=model.get_coord()[1];
        speed[0]=model.get_speed()[0];
        speed[1]=model.get_speed()[1];
        time_eaten=model.get_time_eaten();
}

pred::~pred(void)
{
        time_eaten=0;
}

int pred::get_time_eaten(void) const
{
        return time_eaten;
}

void pred::vrand(void)
{
        speed[0]=speed[0]+(rand()/(double)RAND_MAX) +1;
        speed[1]=speed[1]+(rand()/(double)RAND_MAX) +1;
        double norm=sqrt(speed[0]*speed[0]+speed[1]*speed[1]);

       
        double max=(norm/VPRED);
        speed[0]=speed[0]/max;
        speed[1]=speed[1]/max;
        
}

void pred::up_speed(agent* flock, int size)
{
        int i=0;
        double* nearest=new double[2];
        double norm =0;
        double norm_min=RPRED;
        int isnear=0;
        for(i=0;i<size;i++)
        {
                if(flock[i].is_alive()==1)
                {
                        norm=sqrt((coord[0]-flock[i].get_coord()[0])*(coord[0]-flock[i].get_coord()[0])  -   (coord[1]-flock[i].get_coord()[1])*(coord[1]-flock[i].get_coord()[1]));
                        printf("%lf\n", norm);
                        if(norm<=CPRED)
                        {       
                                flock[i].death();
                                time_eaten=1;
                                printf("BOUFFE\n");
                        }else if(norm<norm_min)
                        {
                                norm_min=norm;
                                nearest[0]=flock[i].get_coord()[0];
                                nearest[1]=flock[i].get_coord()[1];
                                isnear++;
                        }
                }
        }

        if(isnear!=0)
        {
                speed[0]=nearest[0]-coord[0];
                speed[1]=nearest[1]-coord[1];
                 norm=sqrt(speed[0]*speed[0]+speed[1]*speed[1]);

                double max=(norm/VPRED);
                speed[0]=speed[0]/max;
                speed[1]=speed[1]/max;
        }else
        {
                vrand();
        }



}

void pred::up_coord(agent* flock, int size)
{

        if(time_eaten==0)
        {
                up_speed(flock, size);
                coord[0]=coord[0]+TIME*speed[0];
                coord[1]=coord[1]+TIME*speed[1];

                //if the agent reaches the superior border
                if(coord[1]<(H)) //+50
                {
                        speed[1]=speed[1]+10;
                }

                //if the agent reaches the inferior border
                if(coord[1]>(WIDTH-H))
                {
                        speed[1]=speed[1]-10;
                }

                //if the agent reaches the left border
                if(coord[0]<(V)) //+50
                {
                        speed[0]=speed[0]+10;
                }

                //if the agent reaches the right border
                if(coord[0]>(HEIGHT-V))
                {
                        speed[0]=speed[0]-10;
                }
        }else if(time_eaten==PREDSLEEP)
        {
                time_eaten=0;
        }else 
        {
                time_eaten++;
        }
}