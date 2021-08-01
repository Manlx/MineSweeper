#pragma once
class MineGrid
{

public:
	unsigned int ColCount, RowCount, MeSize;
	//GridMemoryValue holds the accurate data of what is actually bombs and what are not
	unsigned char* GridMemoryValue;
	char* GridMemoryDisplay;
	bool isGameOver = false;
	static void PrintRules();
	//Bomb Density must be between 0 and 1;
	double BombDensity = 0.125;
	MineGrid(unsigned int RowCounter,unsigned int ColumCounter);
	void RevealCell(unsigned int uRow, char cCol);
	void MakeTitle();
	void DisplayGrid();
	void GenerateBombs();
	void DisplayValue();
	void CompleteDisplay();
	void GameOver();

	static void PriorityConverter(char Value);
	static void Setup();
	static void GetInput();
	~MineGrid();
}; 
void DeleteCharFromArray(char* arr, unsigned int& Length, char Target);
