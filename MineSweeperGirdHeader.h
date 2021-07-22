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
	void GenerateBombs();
	void DisplayValue();
	//Functions to adjust Cell memory
	void IncreaseU(unsigned int Index);
	void IncreaseD(unsigned int Index);
	void IncreaseL(unsigned int Index);
	void IncreaseR(unsigned int Index);
	void IncreaseUL(unsigned int Index);
	void IncreaseUR(unsigned int Index);
	void IncreaseDR(unsigned int Index);
	void IncreaseDL(unsigned int Index);
	~MineGrid();
}; 
void DeleteCharFromArray(char* arr, unsigned int& Length, char Target);
