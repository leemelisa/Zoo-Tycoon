/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     Turtle.cpp is the Turtle class function implemenation
		    file.
*********************************************************************/

#include "Zoo.hpp"
#include "validate.hpp"
#include "Animal.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;
using std::string;

/*********************************************************************
** Description: This default constructor accepts no parameter. Set the
		private memember variables bankAcc to 100,000, number 
		of each animal to zero, and the array size for each
		animal to 10.
**********************************************************************/
Zoo::Zoo()
{
	bankAcc = 100000;
	numTigers = numPenguins = numTurtle = 0;
	tigerArrSize = penguinArrSize = turtleArrSize = 10;
}

/*********************************************************************
** Description: This function accepts no parameter. Display instructions
		and cost of each animal to the user.
**********************************************************************/
void Zoo::welcomeMsg()
{
	cout << "-------------------------------------------------------\n"
	     << "\t\tWelcome to Zoo Tycoon!\n"
	     << "-------------------------------------------------------\n"
	     << "Instructions: \n"
	     << "At least one type of each animal is required to sart the zoo.\n"
	     << "Please enter either 1 or 2 for each animal you would like to"
	     << " purchase.\n\n"
	     << "Bank Account: " << bankAcc << "$\n"
	     << "Tiger Cost: 10,000$\n"
	     << "Penguin Cost: 1,000$\n"
	     << "Tutle Cost: 100$\n\n";
		
	buyNewAnimal();
}

/*********************************************************************
** Description: This function accepts no parameter. Add all animal 
		bought by user to the dynamically allocated array zoo.
**********************************************************************/
void Zoo::buyNewAnimal()
{
	zoo = new Animal*[zooSize];
	string userInput;

	//ask and store number of tigers purchased 
	cout << "How many tigers would you like to purchase?\n";
	cin >> userInput;
	numTigers = validate(userInput, 1, 2);
	//add tiger to zoo
	zoo[0] = new Tiger[tigerArrSize];
	for (int i = 0; i < numTigers; i++)
	{	
		zoo[0][i] = Tiger(1);	//set newly bought animal age to 1
	}

	//ask and store number of penguins purchased
	cout << "How many penguins would you like to purchase?\n";
	cin >> userInput;
	numPenguins = validate(userInput, 1, 2);
	zoo[1] = new Penguin[penguinArrSize];
	for (int i = 0; i < numPenguins; i++)
	{
		zoo[1][i] = Penguin(1);
	}

	//ask and store number of turtles purchased
	cout << "How many turtles would you like to purchase?\n";
	cin >> userInput;
	numTurtle = validate(userInput, 1, 2);
	zoo[2] = new Turtle[turtleArrSize];
	for (int i = 0; i < numTurtle; i++)
	{
		zoo[2][i] = Turtle(1);
	}

	//subtract cost of bought animals from bank acc
	bankAcc -= ((numTigers * 10000) + (numPenguins * 1000) 
				+ (numTurtle * 100));
	cout << "\nBank Account: " << bankAcc << "$" << endl;

	dayIteration();
}

/*********************************************************************
** Description: This function accepts no parameter. Begins each day
		by feeding each animal and aging each animal by 1.
		Initiate a random event to occur. At the end of the day
		calculate/display the profit for the day and prompt user
		if they would like to buy an adult animal.
 **********************************************************************/
void Zoo::dayIteration()
{
	if (feedAnimals() == true)
	{
		startEvent();
		profitCalc();
		adultAnimal();
		while ((playMore() == 1) && (feedAnimals() == true))
		{
			//increase animal age for the day by 1
			animalAges(0, numTigers);
			animalAges(1, numPenguins);
			animalAges(2, numTurtle);
			//random even occurs
			startEvent();
			//calculate profit end of the day
			profitCalc();
			adultAnimal();
		}
		cout << "The game is over. Good-Bye.\n";
	}
}

/*********************************************************************
** Description: This function accepts no parameter. Calculated and
		determine if the user can afford the feeding cost
		per animal. If the user can afford to feed their animal
		return true otherwise false.
*********************************************************************/
bool Zoo::feedAnimals()
{
	int total = (numTigers * 50) + (numPenguins * 10) + (numTurtle * 5);

	if (total < bankAcc)
	{
		//display feeding cost to user
		cout << "-----------------------------------------------------\n"
		     << "\t\tStart of day " << dayNum << "\n"
		     << "-----------------------------------------------------\n"
		     << "Required Feeding Cost: \n"
		     << "Total cost of Animal food: " << total << "$\n\n";

		//display and calculate new account balance
		bankAcc -= total;
		cout << "Current Account balance: " << bankAcc << "$\n";
		//display number of animals to user
		printNumOfAnimals();
		dayNum++;

		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Description: This function accept two integer: representing type of
		animal, and current number of animal. Ages each animal
		time by 1 day.
*********************************************************************/
void Zoo::animalAges(int type, int numOfAnimals)
{
	for (int j = 0; j < numOfAnimals; j++)
	{
		zoo[type][j].setAge();
	}
}

/*********************************************************************
** Description: This function accepts no parameter and randomly
		start a event: sickness of an animal, attendance bonus,
		birth of an animal or nothing occurs.
*********************************************************************/
void Zoo::startEvent()
{
	srand((unsigned)time(0));
	
	cout << "*******************************************************\n"
	     << "\t\tRANDOM EVENT OCCURENCE\n"
	     << "*******************************************************\n";
	switch (randoNum(1, 4))
	{
	case 1:
	{
		cout << "A sickness occurs to an animal in the zoo.\n";
		sickEvent();
		break;
	}
	case 2:
	{
		cout << "It's your lucky day! A boom in zoo attendance occurs.\n";
		boomEvent();
		cout << "Your bonus amount is " << bonus << "$\n";
		break;
	}
	case 3:
	{
		cout << "A random baby animal will be born.\n";
		birthEvent();
		break;
	}
	default: cout << "Nothing happens... " << endl;
	}
	printNumOfAnimals();
}

/*********************************************************************
** Description: This function accepts two integer a min and max. Return
		a randomly generated number between those ranges.
*********************************************************************/
int Zoo::randoNum(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

/*********************************************************************
** Description: This function accepts a no parameter. Randomly
		select an animal to die and remove last animal of that
		type from the dynamic array zoo.
*********************************************************************/
void Zoo::sickEvent()
{
	int animalType = randoNum(0, 2);

	if (animalType == 0)
	{
		numTigers--;
		//copy all elements of a previous array but the last element 
		//and move all elements to a new array of increase size
		Animal *tempArray = new Tiger[tigerArrSize];
		for (int i = 0; i < numTigers; i++)
		{
			tempArray[i] = zoo[animalType][i];
		}
		delete[] zoo[animalType];
		zoo[animalType] = tempArray;

		//reset num of tiger if it falls below 0
		if (numTigers < 0)
		{
			numTigers = 0;
		}

		cout << "Oh dear.. one of your tiger has gotten sick and died :C.\n";
	}
	else if (animalType == 1)
	{
		numPenguins--;
		//copy all elements of a previous array but the last element 
		//and move all elements to a new array of increase size
		Animal *tempArray = new Penguin[penguinArrSize];
		for (int i = 0; i < numPenguins; i++)
		{
			tempArray[i] = zoo[animalType][i];
		}
		delete[] zoo[animalType];
		zoo[animalType] = tempArray;

		//reset num of penguin if it falls below 0
		if (numPenguins < 0)
		{
			numPenguins = 0;
		}

		cout << "Oh dear.. one of your penguin has gotten sick and died :C.\n";
	}
	else
	{
		numTurtle--;
		//copy all elements of a previous array but the last element 
		//and move all elements to a new array of increase size
		Animal *tempArray = new Turtle[turtleArrSize];
		for (int i = 0; i < numTurtle; i++)
		{
			tempArray[i] = zoo[animalType][i];
		}
		delete[] zoo[animalType];
		zoo[animalType] = tempArray;

		//reset num of tutle if it falls below 0
		if (numTurtle < 0)
		{
			numTurtle = 0;
		}

		cout << "Oh dear.. one of your turtle has gotten sick and died :C.\n";
	}
}

/*********************************************************************
** Description: This function accepts no parameter. Randomly generate
		a bonus between 250 and 500 per tiger in the zoo.
*********************************************************************/
void Zoo::boomEvent()
{
	bonus = (randoNum(250, 500) * numTigers);
	bankAcc += bonus;
}

/*********************************************************************
** Description: This function accepts no parameter. Randomly pick an
		animal to have a baby. If the randomly picked animal
		is not of age 3 or greater another animal will be chosen.
*********************************************************************/
void Zoo::birthEvent()
{
	//chose a random animal to have a baby
	int animalType = randoNum(0, 2);
	bool adultCheck = false;
	bool toContinue = true;

	while (toContinue == true)
	{
		if (animalType == 0)
		{
			int numAdult = 0;

			//iterate through tiger array for an adult
			for (int i = 0; i < numTigers; i++)
			{
				//if an adult is found add baby tiger
				if (zoo[animalType][i].getAge() >= 3)
				{
					numAdult++;
					if (numAdult == 1)
					{
						numTigers++;
						//check tiger array size if not large enough double size
						if (numTigers > tigerArrSize)
						{
							tigerArrSize *= 2;
							//copy all elements of a previous array and move 
							//all elements to a new array of increase size
							Animal *tempArray = new Tiger[tigerArrSize];
							for (int i = 0; i < numTigers; i++)
							{
								tempArray[i] = zoo[animalType][i];
							}
							delete[] zoo[animalType];
							zoo[animalType] = tempArray;
						}

						//add baby to array starting age at 0
						zoo[animalType][numTigers - 1] = Tiger(0);
						cout << "Congratulation! A baby tiger is born.\n";
						toContinue = false;
					}
				}
			}
			if (numAdult == 0)
			{
				//if no adult is found and if another type of animal was chosen
				if (adultCheck == true)
				{
					cout << "Too bad.. No tigers are old enough to give birth.\n";
					toContinue = false;
				}
				if (adultCheck == false)
				{
					cout << "No tigers are old enough to give birth.\n"
					     << ". . . picking another animal to give birth.\n";
					//pick another type of animal
					animalType = 1;
					adultCheck = true;
				}
			}
		}

		if (animalType == 1)
		{
			int numAdult = 0;

			//iterate through penguin array for an adult
			for (int i = 0; i < numPenguins; i++)
			{
				//if an adult is found add baby penguin
				if (zoo[animalType][i].getAge() >= 3)
				{
					numAdult++;
					if (numAdult == 1)
					{
						numPenguins++;
						//check penguin array size if not large enough double size
						if (numPenguins > penguinArrSize)
						{
							penguinArrSize *= 2;
							//copy all elements of a previous array and move 
							//all elements to a new array of increase size
							Animal *tempArray = new Penguin[penguinArrSize];
							for (int i = 0; i < numPenguins; i++)
							{
								tempArray[i] = zoo[animalType][i];
							}
							delete[] zoo[animalType];
							zoo[animalType] = tempArray;
						}

						//add baby to array starting age at 0
						zoo[animalType][numPenguins - 1] = Penguin(0);
						cout << "Congratulation! A baby penguin is born.\n";
						toContinue = false;
					}
				}
			}
			if (numAdult == 0)
			{
				if (adultCheck == true)
				{
					cout << "Too bad.. No penguins are old enough to give birth.\n";
					toContinue = false;
				}

				if (adultCheck == false)
				{
					//pick another type of animal
					animalType = 2;
					adultCheck = true;
					cout << "No penguins are old enough to give birth.\n"
					     << ". . . picking another animal to give birth.\n";
				}

			}
		}

		if (animalType == 2)
		{
			int numAdult = 0;

			//iterate through turtle array for an adult
			for (int i = 0; i < numTurtle; i++)
			{
				//if an adult is found add baby penguin
				if (zoo[animalType][i].getAge() >= 3)
				{
					numAdult++;
					if (numAdult == 1)
					{
						numTurtle++;
						//check penguin array size if not large enough double size
						if (numTurtle > turtleArrSize)
						{
							turtleArrSize *= 2;
							//copy all elements of a previous array and move 
							//all elements to a new array of increase size
							Animal *tempArray = new Turtle[turtleArrSize];
							for (int i = 0; i < numTurtle; i++)
							{
								tempArray[i] = zoo[animalType][i];
							}
							delete[] zoo[animalType];
							zoo[animalType] = tempArray;
						}

						//add baby to array starting age at 0
						zoo[animalType][numTurtle - 1] = Turtle(0);
						cout << "Congratulation! A baby turtle is born.\n";
						toContinue = false;
					}
				}
			}
			if (numAdult == 0)
			{
				//if no adult is found and if another type of animal was chosen
				if (adultCheck == true)
				{
					cout << "Too bad.. No turtles are old enough to give birth.\n";
					toContinue = false;
				}
				if (adultCheck == false)
				{
					//pick another type of animal
					animalType = 0;
					adultCheck = true;
					cout << "No turtles are old enough to give birth.\n"
					     << ". . . picking another animal to give birth.\n";
				}
			}
		}
	}
}

/*********************************************************************
** Description: This function accepts no parameter. Ask the user if
		they would like to purchase an animal. If funds are
		sufficent add adult animal type to the zoo.
**********************************************************************/
void Zoo::adultAnimal()
{
	string userChoice;
	cout << "Would you like to purchase one adult animal?\n"
	     << "1. Yes\n"
	     << "2. No\n";
	cin >> userChoice;

	if (validate(userChoice, 1, 2) == 1)
	{
		cout << "What type of animal would you like to purchase?\n"
		     << "1. Tiger Cost: 10,000$\n"
		     << "2. Penguin Cost: 1,000$\n"
		     << "3. Turtle Cost: 100\n";
		cin >> userChoice;
		int animalType = validate(userChoice, 1, 3) - 1;

		//add adult tiger to the end of the array
		if (animalType == 0)
		{
			//check and store new balance
			bool balanceResult = checkBankAcc(10000);

			if (balanceResult)
			{
				numTigers++;

				//check tiger array size if not large enough double size
				if (numTigers > tigerArrSize)
				{
					//copy all elements of a previous array and move 
					//all elements to a new array of increase size
					tigerArrSize *= 2;
					Animal *tempArray = new Tiger[tigerArrSize];
					for (int i = 0; i < numTigers; i++)
					{
						tempArray[i] = zoo[animalType][i];
					}
					delete[] zoo[animalType];
					zoo[animalType] = tempArray;
				}
				zoo[animalType][numTigers - 1] = Tiger(3);
			}
			else
			{
				cout << "You do not have enough money!\n";
			}
		}
		//add adult penguin to the end of the array
		else if (animalType == 1)
		{
			bool balanceResult = checkBankAcc(1000);

			if (balanceResult)
			{
				numPenguins++;

				//check penguin array size if not large enough double size
				if (numPenguins > penguinArrSize)
				{
					penguinArrSize *= 2;
					//copy all elements of a previous array and move 
					//all elements to a new array of increase size
					Animal *tempArray = new Penguin[penguinArrSize];
					for (int i = 0; i < numPenguins; i++)
					{
						tempArray[i] = zoo[animalType][i];
					}
					delete[] zoo[animalType];
					zoo[animalType] = tempArray;
				}
				zoo[animalType][numPenguins - 1] = Penguin(3);
			}
			else
			{
				cout << "You do not have enough money!\n";
			}
		}
		//add adult turtle to the end of the array
		else if (animalType == 2)
		{
			bool balanceResult = checkBankAcc(10000);

			if (balanceResult)
			{
				numTurtle++;

				//check turtle array size if not large enough double size
				if (numTurtle > turtleArrSize)
				{
					//copy all elements of a previous array and move 
					//all elements to a new array of increase size	
					turtleArrSize *= 2;
					Animal *tempArray = new Turtle[turtleArrSize];
					for (int i = 0; i < numTurtle; i++)
					{
						tempArray[i] = zoo[animalType][i];
					}
					delete[] zoo[animalType];
					zoo[animalType] = tempArray;
				}
				zoo[animalType][numTurtle - 1] = Turtle(3);
			}
			else
			{
				cout << "You do not have enough money!\n";
			}
		}
	}
	cout << "Current Balance: " << bankAcc << endl;
}


/*********************************************************************
** Description: This function accepts a integer representing intended
		purchase. If the current bank account has enough funds  
		to support the purchase calculate new account balance
		and return true otherwise false.
*********************************************************************/
bool Zoo::checkBankAcc(int value)
{
	int bank = bankAcc;
	
	if ((bank - value) > 0)
	{
		bankAcc -= value;
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Description: This function accepts a no parameter. Calculates and 
		display the total profit for the day.
*********************************************************************/
void Zoo::profitCalc()
{
	//calculate profit for each animal type
	int tigerProfit = (numTigers * 2000);
	int penguinProfit = (numPenguins * 100);
	int turtleProfit = (numTurtle * 5);

	//calculate total profit and current account balance
	int totalProfit = (tigerProfit + penguinProfit + turtleProfit + bonus);
	bankAcc += (totalProfit - bonus);

	//display proft to the user
	cout << "-----------------------------------------------------\n"
	     << "\t\tTotal Profit for the day\n"
	     << "-----------------------------------------------------\n"
	     << "Tiger Profit: " << tigerProfit << "$\n"
	     << "Penguin Profit: " << penguinProfit << "$\n"
	     << "Turtle Profit: " << turtleProfit << "$\n"
	     << "Bonus: " << bonus << "$\n"
	     << "Total Profit: " << totalProfit << "$\n"
	     << "Bank Account: " << bankAcc << "$\n"
	     << "-----------------------------------------------------" << endl;

	//reset bonus
	bonus = 0;
}

/*********************************************************************
** Description: This function accept no parameter and print the
		current number of animals for each type.
*********************************************************************/
void Zoo::printNumOfAnimals()
{
	cout << "\n\nCurrent Number of Tigers: " << numTigers
	     << "\nCurrent Number of Penguins: " << numPenguins 
	     << "\nCurrent Number of Turtles: " << numTurtle << endl;
}

/*********************************************************************
** Description: This function accepts no parameter and ask the user
		if they would like to play again. Returns and validates
		the user choice.
*********************************************************************/

int Zoo::playMore()
{
	string userInput;

	cout << "1. Would you like to keep playing?\n"
		<< "2. Quit Game\n"
		<< "Enter your choice: ";
	cin >> userInput;
	return validate(userInput, 1, 2);
}

/*********************************************************************
** Description: This destructor free up dynamically allocated memory.
*********************************************************************/
Zoo::~Zoo()
{
	//free up memory for each sub array
	for (int i = 0; i < zooSize; i++)
	{
		delete[] zoo[i];
	}
	//free up for array of pointers
	delete[] zoo;	
}
