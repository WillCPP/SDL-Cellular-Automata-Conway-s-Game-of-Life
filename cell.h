#pragma once
#include "entity.h"
class cell :
	public entity
{
public:
	cell();
	~cell();

	bool getPop() { return isPopulated; }
	void setPop(bool p) { this->isPopulated = p; return; }

	bool getNextPop() { return nextIsPopulated; }
	void setNextPop(bool p) { this->nextIsPopulated = p; return; }

	bool isPopulated;
	bool nextIsPopulated;
};

