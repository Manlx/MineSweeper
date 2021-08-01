#include <iostream>
#include "Color.h"
#include "MineSweeperGirdHeader.h"

#define LOG(x) std::cout << x << std::endl
int main()
{
//#if 0
//	char MyString[] = "Welcome";
//	unsigned int Length = 7;
//	LOG(MyString);
//	DeleteCharFromArray(MyString, Length, 'e');
//	LOG(MyString);
//	DeleteCharFromArray(MyString, Length, 'e');
//	LOG(MyString);
//#else
//	MineGrid::PrintRules();
//	unsigned int Rows, Cols;
//	std::cin >> Cols;
//	std::cin >> Rows;
//
//	MineGrid DisplayGrid(Cols, Rows);
//	DisplayGrid.MakeTitle();
//	DisplayGrid.DisplayGrid();
//	DisplayGrid.GenerateBombs();
//	LOG("Actual Value after bomb seed");
//	DisplayGrid.DisplayValue();
//	
//
//	unsigned int iRow;
//	char cCol;
//	std::cout << "Colum and Row: " << std::endl;
//	std::cin >> cCol;
//	std::cin >> iRow;
//	DisplayGrid.RevealCell(iRow,cCol);
//#endif // 0

	//Opening code to get grid size and explain game;
	MineGrid::Setup();
	unsigned int Rows, Cols;
	std::cin >> Cols;
	std::cin >> Rows;
	
	MineGrid PlayGrid(Cols,Rows);
	PlayGrid.GenerateBombs();
	PlayGrid.CompleteDisplay();

	char cCol;
	while (!PlayGrid.isGameOver)
	{
		printf("Cell to reveal Colum Row (A,0) : ");
		std::cin >> cCol;
		std::cin >> Rows;
		PlayGrid.RevealCell(Rows,cCol);
	}
	PlayGrid.GameOver();
	return 0;
}