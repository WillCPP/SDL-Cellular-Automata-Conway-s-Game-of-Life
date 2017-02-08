#include "entity.h"

entity::entity()
{
}

entity::entity(int x, int y, int l, int w)
{
	this->x = x;
	this->y = y;
	this->length = l;
	this->width = w;
	this->color = 0xFF000000;
}

entity::entity(int x, int y, int l, int w, Uint32 c)
{
	this->x = x;
	this->y = y;
	this->length = l;
	this->width = w;
	this->color = c;
}


entity::~entity()
{
}
