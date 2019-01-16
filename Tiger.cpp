/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     Tiger.cpp is the Tiger class function implemenation
		    file.
*********************************************************************/

#include "Animal.hpp"
#include "Tiger.hpp"

/*********************************************************************
** Description: Default constructor.
**********************************************************************/
Tiger::Tiger()
{

}

/*********************************************************************
** Description: This constructor accepts five integers relating to the
		animal: age, cost, number of possible babies, base food
		cost and payoff. Set parameter to private member variables.
**********************************************************************/
Tiger::Tiger(int age):Animal(age, 10000, 1, 50, 2000)
{

}
