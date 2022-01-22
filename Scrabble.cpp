/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Dimitar Avramov
* @idnumber 9MI0600058
* @compiler VC
*
* <main file>
*
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include "Constants.h"
#include "HelperFunctions.h"

using namespace std;

void run();

int main()
{
	run();
	return 0;
}

void run()
{
	showMenu();

	int lettersCount = DEFAULT_LETTERS_COUNT;
	int maxShuffles = DEFAULT_SHUFFLES;
	int maxRounds = DEFAULT_ROUNDS_NUMBER;

	while (true)
	{
		cout << "Enter the number of the corresponding option: ";
		string input;
		cin >> input;
		cout << endl;

		if (input == NEW_GAME_BUTTON)
		{
			startGame(lettersCount, maxShuffles, maxRounds);
		}
		else if (input == NEW_LETTERS_COUNT_BUTTON)
		{
			cout << "Enter the new number of letters: ";
			cin >> lettersCount;
			cout << endl;
		}
		else if (input == NEW_ROUNDS_COUNT_BUTTON)
		{
			cout << "Enter the new number of rounds: ";
			cin >> maxRounds;
			cout << endl;
		}
		else if (input == NEW_SHUFFLES_COUNT_BUTTON)
		{
			cout << "Enter the new number of shuffles: ";
			cin >> maxShuffles;
			cout << endl;
		}
		else if (input == NEW_WORD_BUTTON)
		{
			addNewWord();
		}
		else if (input == EXIT_BUTTON)
		{
			return;
		}
		else
		{
			cout << "Invalid input format. Try again with 1, 2.a, 2.b, 2.c, 3 or 4" << endl;
			continue;
		}
		
		showMenu();
	}
}

