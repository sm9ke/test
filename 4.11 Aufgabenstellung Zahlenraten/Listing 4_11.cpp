#include <iostream>
#include <windows.h>

#pragma comment (lib, "winmm.lib")

//Funktionsprototypen

int Play(int nLevel);
int ChooseLevel(int nLevel);
int TestHighscore(int nPoints, int nHighscore);
void ShowInfo();

//main

int main()
{
	//Variables

	char chSelection;				//Selected fak
	int nLevel = 5;					//Current Level
	int nHighscore = 100;			//Current Highscore

	//Initialize Randomizer
	srand(timeGetTime());

	//Menu
	do
	{
		//Show Menu

		std::cout << "Guess the Number - Menu" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "(N)ew Game" << std::endl;
		std::cout << "(C)hange Level" << std::endl;
		std::cout << "(S)how Highscore" << std::endl;
		std::cout << "(I)nformation" << std::endl;
		std::cout << "(E)xit Game\n\n" << std::endl;

		//Ask for input
		std::cout << "Please Select: ";
		std::cin >> chSelection;

		//Husesucksdickallday
		switch (chSelection)
		{
			//New Game
			case('n'):
			case('N'):
			{
				//Play
				int nPoints;
				nPoints = Play(nLevel);

				nHighscore = TestHighscore(nPoints, nHighscore);

			} break;

			//Choose Level
			case('c'):
			case('C'):
			{
				nLevel = ChooseLevel(nLevel);

			} break;

			//Show Highscore
			case('s'):
			case('S'):
			{
				std::cout << "Current Highscore ";
				std::cout << nHighscore << "Points\n\n";

			} break;

			//Information
			case('i'):
			case('I'):
			{
				ShowInfo();

			} break;

			//Exit Game
			case('e'):
			case('E'):
			{
				std::cout << "Exiting Game..." << std::endl;

			} break;

			//Invalid
			default:
			{
				std::cout << ">Invalid!<\n\n";

			}
		}

	} while (chSelection != 'e' && chSelection != 'E'); //Exit game?

	std::cout << "Bye cunt" << std::endl;

	return 0;
}

//ShowInfo

void ShowInfo()
{
	std::cout << "Guess The Number 1.0" << std::endl;
	std::cout << "\n\n";
}

//ChooseLevel

int ChooseLevel(int nLevel)
{
	int nNewLevel;

	do
	{
		//Select new level
		std::cout << "Current Level: " << nLevel << std::endl;
		std::cout << "New Level (1 - 10): ";
		std::cin >> nNewLevel;

		//Invalid
		if (nNewLevel < 10 || nNewLevel > 1)
		{
			std::cout << ">Invalid!<" << std::endl;
		} 
	} while (nNewLevel < 1 || nNewLevel > 10);

	//Return Selected Level
	return nNewLevel;
}

//Play

int Play(int nLevel)
{
	int nRandomNumber;
	int nGuessedNumber = 0;
	int nRange = nLevel * 10;
	int nTry = 0;
	int nPoints = 0;

	//Randomizer

	nRandomNumber = (rand() % nRange) + 1;

	//Put out range
	std::cout << "\nThe Number is between 1 and ";
	std::cout << nRange << std::endl;

	//Guess
	while (nGuessedNumber != nRandomNumber)
	{
		std::cout << "Your guess: ";
		std::cin >> nGuessedNumber;

		nTry++;

		//Wrong Number - Hint
		if (nGuessedNumber < nRandomNumber)
			std::cout << "The number you are looking for is bigger" << std::endl;
		if (nGuessedNumber > nRandomNumber)
			std::cout << "The number you are looking for is smaller" << std::endl;
	}
	
	//Right Number
	std::cout << "\nGood Job!" << std::endl;
	std::cout << "You've guessed the number after " << nTry;
	std::cout << " trys!\n\n";

	//GetPoints
	nPoints = nRange - nTry + 1;
	nPoints *= nLevel;

	//More trys than numbers
	if (nPoints < 0)
		nPoints = 0;

	//Output
	std::cout << "Points: " << nPoints << std::endl;

	//Return Points
	return nPoints;
}

//TestHighscore

int TestHighscore(int nPoints, int nHighscore)
{
	//Test if new highscore
	if (nPoints > nHighscore)
	{ 
		std::cout << "New Highscore!\n\n";
		nHighscore = nPoints;
	}
	else
	{
		std::cout << "Not A New Highscore\n\n";
	}

	//Return Highscore
	return nHighscore;
}