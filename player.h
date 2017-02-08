#pragma once
#include <SDL.h>
#include "entity.h"
class player :
	public entity
{
public:
	player();
	player(int, int, int, int);
	player(int, int, int, int, Uint32);
	~player();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setShadow();

};

