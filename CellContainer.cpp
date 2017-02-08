#include "CellContainer.h"



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
		else if (i%50 == 0) //first column
		{
			if (this->cell_vec[i + 1].getPop() == true) //check right
			{
				count++;
			}
			if (this->cell_vec[i - 49].getPop() == true) //check above diagonal right
			{
				count++;
			}
			if (this->cell_vec[i + 51].getPop() == true) //check beneath diagonal right
			{
				count++;
			}
		}
		else if (i%50 == 49) //last column
		{
			if (this->cell_vec[i - 1].getPop() == true) //check left
			{
				count++;
			}
			if (this->cell_vec[i - 51].getPop() == true) //check above diagonal left
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
		if (count >= 3) //change pop rules
		{
			this->cell_vec[i].setPop(true);
		}
		else
		{
			this->cell_vec[i].setPop(false);
		}
	}
}
