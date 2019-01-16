/*********************************************************************
** Program name:    Zoo Tycoon
** Author:          Melisa Lee
** Date:            10/17/2018
** Description:     validate.hpp is the function validate header file.
*********************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include "validate.hpp"

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::istringstream;

/*********************************************************************
** Description: This function accepts a userinput as a string, a max
		and min integer. Validate if the user input is 
		between the min and max range. Returns user input as a
		integer.
*********************************************************************/

int validate(string input, int min, int max)
{
	int value;
	bool isNum = true;

	while (isNum == true)
	{
		int nonInt = 0;
		//loop over input string if a non int is found exit loop
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				nonInt++;	//increase nonInt num 
			}
		}
		if (nonInt > 0)	//if a non digit is found ask user to reenter
		{
			nonInt = 0;		//reset counter after string iteration
			cout << "Please re-enter a valid input: ";
			cin >> input;
		}
		else
		{
			//convert string to integer
			istringstream stringToNum(input);
			stringToNum >> value;
			//if the number is inbetween 2-51 break out of loop and return num
			if (value >= min && value <= max)
			{
				isNum = false;
				return value;
			}
			else
			{
				nonInt = 0;		//reset counter after string iteration
				cout << "Re-enter: ";
				cin >> input;
			}
		}
	}
}
