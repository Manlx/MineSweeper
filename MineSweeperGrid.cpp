#include <iostream>
#include <time.h>  
#include "Color.h"
#include "MineSweeperGirdHeader.h"

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
void MineGrid::GenerateBoms()
{
	unsigned int BomCount = MeSize * 0.25;
	srand(time(NULL));
	bool Top, Bot, Rig, Lef;
	for (unsigned int x = 0; x < BomCount; x++)
	{
		unsigned int ActiveCell = rand() % MeSize;
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