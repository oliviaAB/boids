//****************************************************************************
//
//
//
//****************************************************************************
#ifndef __OBJET_H__
#define __OBJET_H__
// ===========================================================================
// Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include "parameters.h"
// ===========================================================================
// Project Files
// ===========================================================================
// ===========================================================================
// Class declarations
// ===========================================================================
class objet
{
    public :
    // =======================================================================
    // Enums
    // =======================================================================
    // =======================================================================
    // Constructors
    // =======================================================================
    objet(void);
    // =======================================================================
    // Destructor
    // =======================================================================
    virtual ~objet(void);
    // =======================================================================
    // Accessors: getters
    // =======================================================================
    double* get_coord(void) const;
    // =======================================================================
    // Accessors: setters
    // =======================================================================
    // =======================================================================
    // Operators
    // =======================================================================
    // =======================================================================
    // Public Methods
    // =======================================================================
    void print_coord(void) const;
    // =======================================================================
    // Public Attributes
    // =======================================================================
    protected :
    // =======================================================================
    // Forbidden Constructors
    // =======================================================================
    /*boids(void)
    {
    printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    };*/
    /*
    agent(const agent &model)
    {
        printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    };
    */
    // =======================================================================
    // Protected Methods
    // =======================================================================
    // =======================================================================
    // Protected Attributes
    // =======================================================================
    double* coord;
    /*
    static double R;
    static double* GAMMA;
    static int WIDTH;
    static int HEIGHT;
    static double time;
    */
};
// ===========================================================================
// Getters' definitions
// ===========================================================================
// ===========================================================================
// Setters' definitions
// ===========================================================================
// ===========================================================================
// Operators' definitions
// ===========================================================================
// ===========================================================================
// Inline functions' definition
// ===========================================================================
    #endif // __OBJET_H__