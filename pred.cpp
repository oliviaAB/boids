
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

pred::~pred(void)
{
        time_eaten=0;
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

void pred::up_speed(void)
{
        
}

void pred::up_coord(void)
{
        vrand();
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
}