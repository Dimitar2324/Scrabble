
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
* <file with helper functions>
*
*/

#pragma once

using namespace std;

#include <vector>
#include "Constants.h"
#include <iostream>
#include <fstream>

void generateRandomLetters(vector<char>& letters, int lettersCount)
{
	srand(time(0));

	for (int i = 0; i < lettersCount; i++)
	{
		int randomNum = rand() % ENGLISH_LETTERS_COUNT;
		char letter = 'a' + randomNum;
		letters.push_back(letter);
	}
}

void printLetters(vector<char>& letters)
{
	int size = letters.size();

	for (int i = 0; i < size; i++)
	{
		cout << letters[i] << " ";
	}

	cout << endl;
}

bool dictionaryContains(string searchedWord)
{
	ifstream file;
	file.open("englishDictionary.txt");

	string word;
	while (!file.eof())
	{
		file >> word;

		if (word == searchedWord)
		{
			return true;
		}
	}

	file.close();
	return false;

}

bool areUsedValidLetters(vector<char>& letters, string word)
{
	int length = word.size();

	for (int i = 0; i < length; i++)
	{
		char currentLetter = word[i];

		int countInTheWord = count(word.begin(), word.end(), currentLetter);
		int countInLetters = count(letters.begin(), letters.end(), currentLetter);

		if (countInTheWord > countInLetters)
		{
			return false;
		}
	}

	return true;
}

void showMenu()
{
	cout << "1. Start new game" << endl;
	cout << "2. Settings" << endl;
	cout << "  a. Change number of letters" << endl;
	cout << "  b. Change number of rounds" << endl;
	cout << "  c. Change number of shuffles" << endl;
	cout << "3. Add new word" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
}

void addNewWord()
{
	ofstream file;
	file.open("englishDictionary.txt", ios_base::app);

	cout << "Enter the word you want to be added: ";
	string word;
	cin >> word;
	cout << endl;

	if (!dictionaryContains(word))
	{
		file << word << endl;
	}

	file.close();
}

void startGame(int lettersCount, int maxShufflesCount, int rounds)
{
	vector<char> letters;

	int points = INITIAL_POINTS;
	int maxAttempts = MAX_TRIES_PER_ROUND;
	int maxShuffles = maxShufflesCount;

	for (int round = 1; round <= rounds; round++)
	{
		int currentAttemptsCount = maxAttempts;
		generateRandomLetters(letters, lettersCount);
		cout << "Round " << round << endl;
		cout << "Available letters: ";
		printLetters(letters);

		while (true)
		{
			cout << "Try with word or type 0 for new letters:" << endl;

			string word;
			cin >> word;

			if (word == "0")
			{
				if (maxShuffles == 0)
				{
					cout << "No shuffles remained! Think harder and don't give up." << endl;
					continue;
				}
				else
				{
					letters.clear();
					generateRandomLetters(letters, lettersCount);
					maxShuffles--;
					cout << "Remaining shuffles: " << maxShuffles << endl;
					cout << "Available letters: ";
					printLetters(letters);
					continue;
				}
			}

			if (!dictionaryContains(word)
				|| !areUsedValidLetters(letters, word))
			{
				currentAttemptsCount--;

				if (currentAttemptsCount == 0)
				{
					cout << "Invalid word.No remaining tries!" << endl;
					break;
				}

				cout << "Invalid word. Remaining tries: " << currentAttemptsCount << endl;
				cout << "Try again with: ";
				printLetters(letters);
			}
			else
			{
				points += word.size();
				break;
			}
		}

		letters.clear();
	}

	cout << endl;
	cout << "Game over!" << endl;
	cout << "Your total points are " << points << endl;
	cout << endl;
}