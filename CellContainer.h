#pragma once
#include "cell.h"
#include <vector>
using namespace std;

class CellContainer
{
public:
	CellContainer();
	~CellContainer();

	void initializeVector();

	void checkNeighbors();

	vector<cell> cell_vec;
};

