/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     Zoo.hpp is the Zoo class header file. 
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP
#include "Animal.hpp"

class Zoo
{
	private:
		Animal **zoo;
		int bankAcc;
		int numTigers;
		int numPenguins;
		int numTurtle;
		const int zooSize = 3;
		int dayNum = 1;
		int bonus = 0;
		int tigerArrSize;
		int penguinArrSize;
		int turtleArrSize;

	public:
		Zoo();
		void welcomeMsg();
		void buyNewAnimal();
		void dayIteration();
		bool feedAnimals();
		void animalAges(int, int);
		void startEvent();
		int randoNum(int min, int max);
		void sickEvent();
		void boomEvent();
		void birthEvent();
		void adultAnimal();
		bool checkBankAcc(int);
		void profitCalc();
		void printNumOfAnimals();
		int playMore();
		~Zoo();
};
#endif
