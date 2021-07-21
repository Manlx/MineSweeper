#pragma once
class MineGrid
{

public:
	unsigned int ColCount, RowCount, MeSize;
	//GridMemoryValue holds the accurate data of what is actually bombs and what are not
	unsigned char* GridMemoryValue;
	char* GridMemoryDisplay;
	static void PrintRules();
	MineGrid(unsigned int ColumCounter = 0, unsigned int RowCounter = 0);
	void MakeTitle();
	void DisplayGird();
	void GenerateBoms();
	~MineGrid();
}; 
