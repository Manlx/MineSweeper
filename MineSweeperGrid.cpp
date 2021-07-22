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
		if (x == Length)
		{
			Length--;
			arr[Length] = 0;
		}
		else
		{
			for (; x < Length; x++)
				arr[x] = arr[x + 1];
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
	unsigned int OutLenght = ColCount * 3 + 1, OutIndex = 0;
	char* OutputLine = new char[OutLenght];
	for (unsigned int x = 0; x < ColCount; x++)
	{
		OutputLine[OutIndex++] = '|';
		OutputLine[OutIndex++] = 'A' + x;
		OutputLine[OutIndex++] = '|';
	}

	OutputLine[OutLenght - 1] = 0;
	printf("%s%s\n", "__", OutputLine);
	delete[] OutputLine;
}
void MineGrid::PrintRules()
{
	printf("In this game + is a bomb, # is a covered square.\nYou can select the square to be uncovered by entering the colum and row ID\nPlease enter the size of the grid you would like to unmine.\nColums and Rows: ");
}

void MineGrid::IncreaseL(unsigned int Index)
{
	GridMemoryValue[Index - 1]++;
}
void MineGrid::IncreaseR(unsigned int Index)
{
	GridMemoryValue[Index +1]++;
}
//Row Below Manipulation
void MineGrid::IncreaseD(unsigned int Index)
{
	GridMemoryValue[Index + RowCount]++;
}
void MineGrid::IncreaseDL(unsigned int Index)
{
	GridMemoryValue[Index + RowCount-1]++;
}
void MineGrid::IncreaseDR(unsigned int Index)
{
	GridMemoryValue[Index + RowCount + 1]++;
}
//Row Above Manipulation
void MineGrid::IncreaseU(unsigned int Index)
{
	GridMemoryValue[Index - RowCount]++;
}
void MineGrid::IncreaseUR(unsigned int Index)
{
	GridMemoryValue[Index - RowCount + 1]++;
}
void MineGrid::IncreaseUL(unsigned int Index)
{
	GridMemoryValue[Index - RowCount - 1]++;
}

void MineGrid::GenerateBombs()
{
	//unsigned int BomCount = MeSize * 0.25;
	unsigned int BomCount = 1;
	srand(time(NULL));
	bool Top, Bot, Rig, Lef;
	char TopArr[] = "123", BotArr[] = "876", LefArr[] = "";
	for (unsigned int x = 0; x < BomCount; x++)
	{
		unsigned int ActiveCell = rand() % MeSize;
		//Assign the value 10 which indicates that there is a bomb placed
		GridMemoryValue[ActiveCell] = 10;
		ActiveCell++;
		//Checks if the effected cell is in the top row
		Top = ActiveCell <= ColCount;
		//Checks if effected cell is in the bottom row
		Bot = MeSize - ColCount <= ActiveCell;
		//Check if Cell is in left and right most colum
		Lef = ActiveCell % ColCount == 0;
		Rig = ActiveCell % ColCount == 1;
		ActiveCell--;
		char ArrEffected[] = "12354678";
		if (Top)
		{

		}
	//	if (Top)
	//	{
	//		if (Lef)
	//		{
	//			//One cell to the right
	//			GridMemoryValue[ActiveCell + 1]++;
	//			//One cell down to the right
	//			GridMemoryValue[ActiveCell + RowCount + 1]++;
	//			//One cell down
	//			GridMemoryValue[ActiveCell + RowCount]++;
	//		}
	//		else  if (Rig)
	//		{
	//			//One Cell to left
	//			GridMemoryValue[ActiveCell -1 ]++;
	//			//One cell to the left and down
	//			GridMemoryValue[ActiveCell + RowCount-2]++;
	//			//One cell down
	//			GridMemoryValue[ActiveCell + RowCount - 1]++;
	//		}
	//		else
	//		{
	//			//Cells right and left
	//			GridMemoryValue[ActiveCell - 1]++;
	//			GridMemoryValue[ActiveCell + 1]++;
	//			//Cells right left and below
	//			GridMemoryValue[ActiveCell + RowCount]++;
	//			GridMemoryValue[ActiveCell + RowCount-1]++;
	//			GridMemoryValue[ActiveCell + RowCount + 1]++;
	//		}
	//	}
	//	else if (Bot)
	//	{
	//		if (Lef)
	//		{
	//			//One cell to the right
	//			GridMemoryValue[ActiveCell + 1]++;
	//			//One cell up to the right
	//			GridMemoryValue[ActiveCell - RowCount]++;
	//			//One cell up
	//			GridMemoryValue[ActiveCell - RowCount - 1]++;
	//		}
	//		else  if (Rig)
	//		{
	//			//One Cell to left
	//			GridMemoryValue[ActiveCell - 1]++;
	//			//One cell to the left and up
	//			GridMemoryValue[ActiveCell - RowCount - 2]++;
	//			//One cell up
	//			GridMemoryValue[ActiveCell - RowCount - 1]++;
	//		}
	//		else
	//		{
	//			//Cells right and left
	//			GridMemoryValue[ActiveCell - 1]++;
	//			GridMemoryValue[ActiveCell + 1]++;
	//			//Cells right left and above
	//			GridMemoryValue[ActiveCell - RowCount]++;
	//			GridMemoryValue[ActiveCell - RowCount - 1]++;
	//			GridMemoryValue[ActiveCell - RowCount - 2]++;
	//		}
	//	}
	//	else 
	//	{
	//		GridMemoryValue[ActiveCell - 1 + RowCount]++;
	//		GridMemoryValue[ActiveCell - 2 + RowCount]++;
	//		GridMemoryValue[ActiveCell + 1 + RowCount]++;

	//		GridMemoryValue[ActiveCell - 1]++;
	//		GridMemoryValue[ActiveCell + 1]++;

	//		GridMemoryValue[ActiveCell - 1 - RowCount]++;
	//		GridMemoryValue[ActiveCell + 1 - RowCount]++;
	//		GridMemoryValue[ActiveCell + 2 - RowCount]++;
	//	}
	}
}

void MineGrid::DisplayGird()
{
	//Creates output string size. +1 for null character termenation
	unsigned int OutSize = ColCount * 3 + 1;
	char* OutputLine = new char[OutSize];
	unsigned int OutIndex;
	//Loops through rows and then colums
	for (unsigned int x = 0; x < RowCount; x++)
	{
		OutIndex = 0;
		for (unsigned int y = 0; y < ColCount; y++)
		{
			OutputLine[OutIndex++] = '|';
			OutputLine[OutIndex++] = GridMemoryDisplay[x* ColCount +y];
			OutputLine[OutIndex++] = '|';
		}
		OutputLine[OutSize - 1] = 0;
		//prints compiled row
		printf("%-2d%s\n",x,OutputLine);
	}
	//Deletes allocated memory
	delete[] OutputLine;
}

void MineGrid::DisplayValue()
{
	//Creates output string size. +1 for null character termenation
	unsigned int OutSize = ColCount * 3 + 1;
	char* OutputLine = new char[OutSize];
	unsigned int OutIndex;
	//Loops through rows and then colums
	for (unsigned int x = 0; x < RowCount; x++)
	{
		OutIndex = 0;
		for (unsigned int y = 0; y < ColCount; y++)
		{
			OutputLine[OutIndex++] = '|';
			OutputLine[OutIndex++] = ( (GridMemoryValue[x * ColCount + y] >= 9)?'+' : '0'+ GridMemoryValue[x * ColCount + y]);
			OutputLine[OutIndex++] = '|';
		}
		OutputLine[OutSize - 1] = 0;
		//prints compiled row
		printf("%-2d%s\n", x, OutputLine);
	}
	//Deletes allocated memory
	delete[] OutputLine;
}