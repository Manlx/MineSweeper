#include <iostream>
#include <time.h>  
#include "Color.h"
#include "MineSweeperGirdHeader.h"

void DeleteCharFromArray(char* arr, unsigned int& Length, char Target)
{
	bool bFound = false;
	unsigned int x = 0;
	while (!bFound && x < Length)
	{
		bFound = arr[x++] == Target;
	}
	x--;
	if (bFound)
	{
		if (x == Length)
			arr[Length-1] = 0;
		else
			for (; x < Length; x++)
				arr[x] = arr[x + 1];
		Length--;
	}

}
MineGrid::MineGrid(unsigned int ColumCounter, unsigned int RowCounter): ColCount(ColumCounter), RowCount(RowCounter)
{
	MeSize = ColumCounter * RowCounter;
	GridMemoryDisplay = new char[MeSize];
	GridMemoryValue = new unsigned char[MeSize];
	for (unsigned int x = 0; x < MeSize; x++)
	{
		GridMemoryDisplay[x] = '#';
		GridMemoryValue[x] = 0;
	}
}
MineGrid::~MineGrid()
{
	delete[] GridMemoryValue;
	delete[] GridMemoryDisplay;
}
void MineGrid::MakeTitle()
{
	std::cout << "__";
	for (unsigned int x = 0; x < ColCount; x++)
		printf("|%c|",'A'+x);
	std::cout << std::endl;
}
void MineGrid::PrintRules()
{
	printf("In this game + is a bomb, # is a covered square.\nYou can select the square to be uncovered by entering the colum and row ID\nPlease enter the size of the grid you would like to unmine.\nColums and Rows: ");
}

void MineGrid::GenerateBombs()
{
#define DebugFix 1;
#if DebugFix
	//This seeds the bombs to a 1/8 Density of the grid size
	unsigned int BombCount = (unsigned int)(MeSize * BombDensity);
	//Bomblist is used to prevent bombs generating on the same spot
	unsigned int* BombList = new unsigned int[BombCount];
	unsigned int BLIndex = 0;
	//List of effected Cells
	
#else
	unsigned int BombCount = 1;
#endif // 0
	//Seeds Random
	srand(time(NULL));
	//The list of cells effect acording to active cell placement
	char TopArr[] = "123", BotArr[] = "876", LefArr[] = "146",RigArr[] = "358";
	unsigned int ActiveCell;
	//Iterator to loop through the bomblist array
	unsigned int iIter;
	bool Found;
	for (unsigned int x = 0; x < BombCount; x++)
	{
#if DebugFix
//Yes I use GoTo and no I don't care This is used in a correct and simple way
//This keeps generating bomb locations till it finds a spot that has not been used
		char ArrEffected[] = "12354678";
		unsigned int ArrEffLength = 8;
		GenerateRandomAgain:
		ActiveCell = rand() % MeSize;
		Found = false;
		iIter = 0;

		while (!Found && iIter < BLIndex)//Check each Value for duplication
			Found = BombList[iIter++] == ActiveCell;
		if (Found)//Checks if the value is a dup
			goto GenerateRandomAgain;
		else//Adds new bomb Location
			BombList[BLIndex++] = ActiveCell;
#else
		//Debug used to create static bomb spawns
		unsigned int TestArray[] = {89,87,55,1 };
		unsigned int ActiveCell = TestArray[x];
#endif
		//Assign the value 10 which indicates that there is a bomb placed
		GridMemoryValue[ActiveCell] = 10;
		ActiveCell++;
		
		//Checks if the effected cell is in the top row
		if (ActiveCell <= ColCount)
		{
			for (unsigned int x = 0; x < 3; x++)
				DeleteCharFromArray(ArrEffected, ArrEffLength,TopArr[x]);
		}
		//Checks if effected cell is in the bottom row
		else if (MeSize - ColCount < ActiveCell)
		{
			for (unsigned int x = 0; x < 3; x++)
				DeleteCharFromArray(ArrEffected, ArrEffLength, BotArr[x]);
		}
		
		//Check if Cell is in left and right most colum
		if (ActiveCell % ColCount == 0)
		{
			for (unsigned int x = 0; x < 3; x++)
				DeleteCharFromArray(ArrEffected, ArrEffLength, RigArr[x]);
		}
		else if (ActiveCell % ColCount == 1)
		{
			for (unsigned int x = 0; x < 3; x++)
				DeleteCharFromArray(ArrEffected, ArrEffLength, LefArr[x]);
				
		}
		ActiveCell--;
		
		for (unsigned int x = 0;x < ArrEffLength; x++)
		{//Executes for all cells that need to be effected
			switch (ArrEffected[x])
			{
			case '1': GridMemoryValue[ActiveCell - ColCount - 1]++;
				break;
			case '2': GridMemoryValue[ActiveCell - ColCount]++;
				break;
			case '3': GridMemoryValue[ActiveCell - ColCount + 1]++;
				break;
			case '4': GridMemoryValue[ActiveCell - 1]++;
				break;
			case '5': GridMemoryValue[ActiveCell + 1]++;
				break;
			case '6': GridMemoryValue[ActiveCell + ColCount - 1]++;
				break;
			case '7': GridMemoryValue[ActiveCell + ColCount]++;
				break;
			case '8': GridMemoryValue[ActiveCell + ColCount + 1]++;
				break;
			default:
				break;
			}
		}
	}
#if 0 //Debug used to check for the Overwriting bug
	for (unsigned int x = 0; x < BombCount; x++)
		std::cout << BombList[x] << std::endl;
#endif
}
void MineGrid::GameOver(bool Success)
{

}
void MineGrid::RevealCell(unsigned int uRow, char cCol)
{
	unsigned int uCol = cCol - 'A';
	char NewValue = (GridMemoryValue[uRow * ColCount + uCol] > 8) ? '+' : '0' + GridMemoryValue[uRow * ColCount + uCol];
	if (NewValue == '+')
		GameOver(false);
	else
		GridMemoryDisplay[uRow * ColCount + uCol] =NewValue ;
	DisplayGrid();
}
void MineGrid::DisplayGrid()
{
	//Loops through rows and then colums
	for (unsigned int x = 0; x < RowCount; x++)
	{
		printf("%-2d",x);
		for (unsigned int y = 0; y < ColCount; y++)
			PriorityConverter(GridMemoryDisplay[y + ColCount*x]);
		std::cout << std::endl;
	}
}
void MineGrid::PriorityConverter(char Value)
{
	const char* Color;
	switch (Value)
	{//Color to value Corrispondents 
	case '1': Color = GREEN;
		break;
	case '2': Color = BLUE;
		break;
	case '3': Color = CYAN;
		break;
	case '4': Color = MAGENTA;
		break;
	case '5': Color = YELLOW;
		break;
	case '6': Color = RED;
		break;
	case '7': Color = RED;
		break;
	case '8': Color = RED;
		break;
	case '+': Color = RED;
		break;
	default: Color = WHITE;
		break;
	}
	printf("|%s%c%s|", Color, Value, RESET);
}
void MineGrid::DisplayValue()
{
	MakeTitle();
	for (unsigned int x = 0; x < RowCount; x++)
	{
		printf("%-2d",x);
		for (unsigned int y = 0; y < ColCount; y++)
			PriorityConverter( ((GridMemoryValue[y+x*ColCount] > 9)? '+' :'0'+ GridMemoryValue[y + x * ColCount]));
		std::cout << std::endl;
	}
}