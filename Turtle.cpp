/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     Turtle.cpp is the Turtle class function implemenation
		    file.
*********************************************************************/

#include "Animal.hpp"
#include "Turtle.hpp"

/*********************************************************************
** Description: Default constructor.
**********************************************************************/
Turtle::Turtle()
{

}

/*********************************************************************
** Description: This constructor accepts five integers relating to the
		animal: age, cost, number of possible babies, base food
		cost and payoff. Set parameter to private member variables.
**********************************************************************/
Turtle::Turtle(int age):Animal(age, 100, 10, 5, 5)
{

}


