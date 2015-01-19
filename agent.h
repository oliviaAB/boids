//****************************************************************************
//
//
//
//****************************************************************************
#ifndef __AGENT_H__
#define __AGENT_H__
// ===========================================================================
// Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include "parameters.h"
#include "objet.h"
// ===========================================================================
// Project Files
// ===========================================================================
// ===========================================================================
// Class declarations
// ===========================================================================
class agent
{
    public :
    // =======================================================================
    // Enums
    // =======================================================================
    // =======================================================================
    // Constructors
    // =======================================================================
    agent(void);
    // =======================================================================
    // Destructor
    // =======================================================================
    virtual ~agent(void);
    // =======================================================================
    // Accessors: getters
    // =======================================================================
    double* get_coord(void) const;
    double* get_speed(void) const;
    // =======================================================================
    // Accessors: setters
    // =======================================================================
    // =======================================================================
    // Operators
    // =======================================================================
    // =======================================================================
    // Public Methods
    // =======================================================================
    bool near(const agent &other) const;
    bool near_contact(const agent &other) const;
    bool near_obs(const objet &my_obj) const;
    double* speed1(agent* birds, int size, int pos);
    double* speed2(agent* birds, int size, int pos);
    double* speed3(agent* birds, int size, int pos, objet* obj, int nb_obj);
    void new_speed(agent* birds, int size, int pos,  objet* obj, int nb_obj);
    void new_coord(agent* birds, int size, int pos,  objet* obj, int nb_obj);
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
    double* speed;
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
    #endif // __AGENT_H__