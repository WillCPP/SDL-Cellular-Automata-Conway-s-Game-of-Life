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
	void setVecColor();
	void setCellPop(entity*);

	vector<cell> cell_vec;
};

