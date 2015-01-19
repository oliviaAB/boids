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
#include "objet.h"
//############################################################################
// #
// Class objet #
// #
//############################################################################
// ===========================================================================
// Definition of static attributes
// ===========================================================================
// ===========================================================================
// Constructors
// ===========================================================================
objet::objet(void)
{
	coord=new double[2];
	//coord[0]=(rand()/(double)RAND_MAX) *WIDTH;
	//coord[1]=(rand()/(double)RAND_MAX) * HEIGHT;
	coord[0]=(rand()/(double)RAND_MAX) * (WIDTHCRE +100)+100;
	coord[1]=(rand()/(double)RAND_MAX) * (HEIGHTCRE +100)+100;

}
// ===========================================================================
// Destructor
// ===========================================================================
objet::~objet(void)
{
	delete coord;
	coord=NULL;

}
// ===========================================================================
// Public Methods
// ===========================================================================
double* objet::get_coord(void) const
{
	return coord;
}


void objet::print_coord(void) const
{
	printf("x= %lf, y= %lf\n", coord[0], coord[1]);
}
// ===========================================================================
// Protected Methods
// ===========================================================================
// ===========================================================================
// Non inline accessors
// ===========================================================================