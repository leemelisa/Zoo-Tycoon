/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     Penguin.cpp is the Penguin class function implemenation
		    file.
*********************************************************************/

#include "Animal.hpp"
#include "Penguin.hpp"

/*********************************************************************
** Description: Default constructor.
**********************************************************************/
Penguin::Penguin()
{

}

/*********************************************************************
** Description: This constructor accepts five integers relating to the
		animal: age, cost, number of possible babies, base food
		cost and payoff. Set parameter to private member variables.
**********************************************************************/
Penguin::Penguin(int age):Animal(age, 1000, 5, 10, 100)
{
	
}

