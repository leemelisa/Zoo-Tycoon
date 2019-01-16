/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     Animal.hpp is the Animal class header file.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	private:
		int age;
		int cost;
		int numberOfBabies;
		int baseFoodCost;
		int payoff;

	public:
		Animal();
		Animal(int, int, int, int, int);
		void setAge();
		int getAge();
};
#endif
