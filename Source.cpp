#include <iostream>
#include "Color.h"
#include "MineSweeperGirdHeader.h"

//#define LOG(x) std::cout << x << std::endl
int main()
{
	MineGrid::PrintRules();
	unsigned int Rows, Cols;
	std::cin >> Cols;
	std::cin >> Rows;

	MineGrid DisplayGrid(Cols, Rows);
	DisplayGrid.MakeTitle();
	DisplayGrid.DisplayGird();
	return 0;
}