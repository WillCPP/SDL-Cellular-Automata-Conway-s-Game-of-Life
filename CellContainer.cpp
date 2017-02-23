#include "CellContainer.h"
#include <vector>
using namespace std;

CellContainer::CellContainer()
{
	this->initializeVector();
}

CellContainer::~CellContainer()
{
}

void CellContainer::initializeVector()
{
	cell* new_cell = new cell;

	new_cell->setColor(0xFFFFFFFF); // change to 0xFFFFFFFF
	new_cell->setPop(false);
	new_cell->setNextPop(false);

	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			new_cell->setX(j * 16);
			new_cell->setY(i * 16);
			new_cell->setLength(16);
			new_cell->setWidth(16);
			cell_vec.push_back(*new_cell);
		}
	}
}

void CellContainer::checkNeighbors()
{
	int count;
	for (int i = 0; i < this->cell_vec.size(); i++)
	{
		count = 0;
		//check if cell is top row, bottom row, first column or last column
		//check neighbors
		if (i > 0 && i < 49) //top row
		{
			if (this->cell_vec[i - 1].getPop() == true) //check left
			{
				count++;
			}
			if (this->cell_vec[i + 1].getPop() == true) //check right
			{
				count++;
			}
			if (this->cell_vec[i + 50].getPop() == true) //check beneath
			{
				count++;
			}
			if (this->cell_vec[i + 49].getPop() == true) //check beneath diagonal left
			{
				count++;
			}
			if (this->cell_vec[i + 51].getPop() == true) //check beneath diagonal right
			{
				count++;
			}
		}
		else if (i > 1850 && i < 1899) //bottom row
		{
			if (this->cell_vec[i - 1].getPop() == true) //check left
			{
				count++;
			}
			if (this->cell_vec[i + 1].getPop() == true) //check right
			{
				count++;
			}
			if (this->cell_vec[i - 50].getPop() == true) //check above
			{
				count++;
			}
			if (this->cell_vec[i - 49].getPop() == true) //check above diagonal right
			{
				count++;
			}
			if (this->cell_vec[i - 51].getPop() == true) //check above diagonal left
			{
				count++;
			}
		}
		else if (i%50 == 0 && (i != 0 && i != 1850)) //first column
		{
			if (this->cell_vec[i + 1].getPop() == true) //check right
			{
				count++;
			}
			if (i > 49 && this->cell_vec[i - 49].getPop() == true) //check above diagonal right
			{
				count++;
			}
			if (this->cell_vec[i + 51].getPop() == true) //check beneath diagonal right
			{
				count++;
			}
		}
		else if (i%50 == 49 && (i != 49 && i != 1899)) //last column //something in here causes abort
		{
			if (this->cell_vec[i - 1].getPop() == true) //check left
			{
				count++;
			}
			if (i > 51 && this->cell_vec[i - 51].getPop() == true) //check above diagonal left
			{
				count++;
			}
			if (this->cell_vec[i + 49].getPop() == true) //check beneath diagonal left
			{
				count++;
			}
		}
		else if (i == 0) //upper left corner
		{
			if (this->cell_vec[i + 1].getPop() == true) //check right
			{
				count++;
			}
			if (this->cell_vec[i + 50].getPop() == true) //check beneath
			{
				count++;
			}
			if (this->cell_vec[i + 51].getPop() == true) //check beneath diagonal right
			{
				count++;
			}
		}
		else if (i == 49) //upper right corner
		{
			if (this->cell_vec[i - 1].getPop() == true) //check left
			{
				count++;
			}
			if (this->cell_vec[i + 50].getPop() == true) //check beneath
			{
				count++;
			}
			if (this->cell_vec[i + 49].getPop() == true) //check beneath diagonal left
			{
				count++;
			}

		}
		else if (i == 1850) //lower left corner
		{
			if (this->cell_vec[i + 1].getPop() == true) //check right
			{
				count++;
			}
			if (this->cell_vec[i - 50].getPop() == true) //check above
			{
				count++;
			}
			if (this->cell_vec[i - 49].getPop() == true) //check above diagonal right
			{
				count++;
			}
		}
		else if (i == 1899) //lower right corner
		{
			if (this->cell_vec[i - 1].getPop() == true) //check left
			{
				count++;
			}
			if (this->cell_vec[i - 50].getPop() == true) //check above
			{
				count++;
			}
			if (this->cell_vec[i - 51].getPop() == true) //check above diagonal left
			{
				count++;
			}
		}
		else //every other cell
		{
			if (this->cell_vec[i - 1].getPop() == true) //check left
			{
				count++;
			}
			if (this->cell_vec[i + 1].getPop() == true) //check right
			{
				count++;
			}
			if (this->cell_vec[i + 50].getPop() == true) //check beneath
			{
				count++;
			}
			if (this->cell_vec[i + 49].getPop() == true) //check beneath diagonal left
			{
				count++;
			}
			if (this->cell_vec[i + 51].getPop() == true) //check beneath diagonal right
			{
				count++;
			}
			if (this->cell_vec[i - 50].getPop() == true) //check above
			{
				count++;
			}
			if (this->cell_vec[i - 49].getPop() == true) //check above diagonal right
			{
				count++;
			}
			if (this->cell_vec[i - 51].getPop() == true) //check above diagonal left
			{
				count++;
			}
		}
		if ((count == 2 || count == 3) && this->cell_vec[i].getPop() == true) //change pop rules
		{
			this->cell_vec[i].setNextPop(true);
		}
		else if (count < 2 && this->cell_vec[i].getPop() == true)
		{
			this->cell_vec[i].setNextPop(false);
		}
		else if (count > 3 && this->cell_vec[i].getPop() == true)
		{
			this->cell_vec[i].setNextPop(false);
		}
		else if(count == 3 && this->cell_vec[i].getPop() == false)
		{
			this->cell_vec[i].setNextPop(true);
		}
	}

	for (int i = 0; i < this->cell_vec.size(); i++)
	{
		this->cell_vec[i].setPop(this->cell_vec[i].getNextPop());
	}
}

void CellContainer::setVecColor()
{
	for (int i = 0; i < this->cell_vec.size(); i++)
	{
		if (cell_vec[i].getPop() == true)
		{
			cell_vec[i].setColor(0xFF000000);
		}
		else
		{
			cell_vec[i].setColor(0xFFFFFFFF);
		}
	}
}

void CellContainer::setCellPop(entity* ent)
{
	int index = (ent->getY()/16)*50 + (ent->getX()/16);

	if (cell_vec[index].getPop() == false)
	{
		cell_vec[index].setPop(true);
	}
	else
	{
		cell_vec[index].setPop(false);
	}
}
