/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     Animal.cpp is the Animal class function implemenation 
		    file.
*********************************************************************/

#include "Animal.hpp"

/*********************************************************************
** Description: Default constructor.
**********************************************************************/
Animal::Animal()
{

}

/*********************************************************************
** Description: This constructor accepts five integers relating to the
		animal: age, cost, number of possible babies, base food
		cost and payoff. Set parameter to private member variables.
**********************************************************************/
Animal::Animal(int animalAge, int animalCost, int babyNum, int food, int pay)
{
	
	age = animalAge;
	cost = animalCost;
	numberOfBabies = babyNum;
	baseFoodCost = food;
	payoff = pay;
}

/*********************************************************************
** Description: This function accepts no parameter and increment the
		the age of the animal.
**********************************************************************/
void Animal::setAge()
{
	age ++;
}

/*********************************************************************
** Description: This function accepts no parameter and returns the age
		of the animal as integer.
**********************************************************************/
int Animal::getAge()
{
	return age;
}
