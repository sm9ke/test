#include <iostream>


//Struct
struct S_FieldInfo
{
	bool bOccupied;
	char chName[20];
};

//Variables
const int nWidth = 5;
const int nHeigth = 5;
S_FieldInfo Playfield[nWidth][nHeigth];

//Functions
void ShowField();
void OccupateField();
void ShowData();
void ClearField();



//Menu
//
int main()
{
	int nMenuSelect = 0;

	do
	{
		std::cout << "1 - Show Playfield" << std::endl;
		std::cout << "2 - Select Field" << std::endl;
		std::cout << "3 - Show Field-Data" << std::endl;
		std::cout << "4 - Clear" << std::endl;
		std::cout << "5 - Exit" << std::endl;
		std::cout << "-------------------" << std::endl;

		std::cout << "Select: ";
		std::cin >> nMenuSelect;
		std::cout << "\n\n";

		switch (nMenuSelect)
		{
			case(1):
			{
				ShowField();
			} break;
			
			case(2):
			{
				OccupateField();
			} break;

			case(3):
			{
				ShowData();
			} break;

			case(4):
			{
				ClearField();
			} break;

			case(5):
			{
				std::cout << "Exiting..." << std::endl;
			} break;

			default:
			{
				std::cout << "Invalid" << std::endl;
			}
		} 
		
		std::cout << "\n\n";

	} while (nMenuSelect != 5);

	return 0;
} //Menu



//Show Field
void ShowField()
{
	std::cout << "-------------------" << std::endl;

	for (int y = 0; y < nHeigth; y++)
	{
		for (int x = 0; x < nWidth; x++)
		{
			if (Playfield[x][y].bOccupied == false)
			{
				std::cout << "O";
			}
			else
			{
				std::cout << "X";
			}
		}
		std::cout << std::endl;
	}

	std::cout << "-------------------" << std::endl;
} //Show Field


//Select Field
void OccupateField()
{
	int x = 0;
	int y = 0;

	std::cout << "-------------------" << std::endl;

	//Ask for coordinates
	do
	{
		std::cout << "x-Position (1 - " << nWidth << "): ";
		std::cin >> x;
	} while (x<1 || x>nWidth);

	do
	{
		std::cout << "y-Position (1- " << nHeigth << "): ";
		std::cin >> y;
	} while (y<1 || y>nHeigth);

	//Ask for Name Input
	std::cout << "Name: ";
	std::cin.ignore();
	std::cin.get(Playfield[x - 1][y - 1].chName, 19);
	Playfield[x - 1][y - 1].bOccupied = true;

	std::cout << "-------------------" << std::endl;
} //Occupate Field


//Field Information
void ShowData()
{
	std::cout << "-------------------" << std::endl;

	int x = 0;
	int y = 0;

	do
	{
		std::cout << "x-Position (1 - " << nWidth << "): ";
		std::cin >> x;
	} while (x<1 || x>nWidth);

	do
	{
		std::cout << "y-Position (1- " << nHeigth << "): ";
		std::cin >> y;
	} while (y<1 || y>nHeigth);

	if (Playfield[x - 1][y - 1].bOccupied == false)
	{
		std::cout << "Field Is Not Occupied." << std::endl;
	}
	else
	{
		std::cout << "Field Is Selected By: ";
		std::cout << Playfield[x - 1][y - 1].chName << std::endl;
	}
	
	std::cout << "-------------------" << std::endl;
} //Field Information


//Clear
void ClearField()
{
	for (int y = 0; y < nHeigth; y++)
	{
		for (int x = 0; x < nWidth; x++)
		{
			Playfield[x][y].bOccupied = false;
		}
		
	}
	std::cout << "|----------|" << std::endl;
	std::cout << "|Cleared...|" << std::endl;
	std::cout << "|----------|" << std::endl;
} //Clear

