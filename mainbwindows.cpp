#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "bwindow.h"
#include "agent.h"
#include "boid.h"
#include "parameters.h"
#include "objet.h"


int main()
{

	srand(time(NULL));

    bwindow win((WIDTH + 100),(HEIGHT+100));
    printf("%d\n",win.init());
    win.map();
	boid my_boid=boid(100);
	objet* obj=new objet[5];
	int nb_obj=5;
    for(;;)
    {
		int ev = win.parse_event();
		switch(ev)
		{
	    	case BKPRESS :
			printf("keypressed\n"); 
			printf("key : %s\n",win.get_lastkey());
			break;
	    	case BBPRESS:
			printf("buttonpressed\n"); break;
	   		case BEXPOSE:
			printf("expose\n"); break;
	    	case BCONFIGURE:
			printf("configure\n"); break;
		}
	
		
		win.draw_fsquare(0,0,(WIDTH+100),(HEIGHT+100),0xACD1E9);
		//win.draw_fsquare(0,400,0,400,0x00FF00);
		win.draw_boid(my_boid, obj, nb_obj);
		my_boid.update(obj, nb_obj);
		

		usleep(50000); //50000


		//printf("!!!!!!!!!!\n");
		//printf("\n");

		//win.draw_square(200,200,202,202,0xFF00);

		/*
		win.draw_point(100,100,0xFF00);
		win.draw_line(100,100,200,200,0xFF0000);
		win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
		win.draw_square(200,200,220,220,0xFF00);
		win.draw_fsquare(400,400,440,440,0xFF00);
		*/

    }
    return 0;
}
	