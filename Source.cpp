#include <iostream>
#include "Color.h"
#include "MineSweeperGirdHeader.h"

#define LOG(x) std::cout << x << std::endl
int main()
{
	
#if 0
	char MyString[] = "Welcome";
	unsigned int Length = 7;
	LOG(MyString);
	DeleteCharFromArray(MyString, Length, 'e');
	LOG(MyString);
	DeleteCharFromArray(MyString, Length, 'e');
	LOG(MyString);
#else
	MineGrid::PrintRules();
	unsigned int Rows, Cols;
	std::cin >> Cols;
	std::cin >> Rows;

	MineGrid DisplayGrid(Cols, Rows);
	DisplayGrid.MakeTitle();
	DisplayGrid.DisplayGrid();
	DisplayGrid.GenerateBombs();
	LOG("Actual Value after bomb seed");
	DisplayGrid.DisplayValue();
	

	unsigned int iRow;
	char cCol;
	std::cout << "Colum and Row: " << std::endl;
	std::cin >> cCol;
	std::cin >> iRow;
	DisplayGrid.RevealCell(iRow,cCol);
#endif // 0
	return 0;
}