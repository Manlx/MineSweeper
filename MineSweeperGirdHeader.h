#pragma once
class MineGrid
{

public:
	unsigned int ColCount, RowCount, MeSize;
	//GridMemoryValue holds the accurate data of what is actually bombs and what are not
	unsigned char* GridMemoryValue;
	char* GridMemoryDisplay;
	static void PrintRules();
	//Bomb Density must be between 0 and 1;
	double BombDensity = 0.125;
	MineGrid(unsigned int ColumCounter = 0, unsigned int RowCounter = 0);
	void MakeTitle();
	void DisplayGird();
	void GenerateBombs();
	void DisplayValue();
	static void PriorityConverter(char Value);
	
	~MineGrid();
}; 
void DeleteCharFromArray(char* arr, unsigned int& Length, char Target);
