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
	DisplayGrid.DisplayGird();
	LOG("Actual Value");
	DisplayGrid.DisplayValue();
	DisplayGrid.GenerateBombs();
	LOG("Actual Value after bomb seed");
	DisplayGrid.DisplayValue();
#endif // 0

	
	return 0;
}