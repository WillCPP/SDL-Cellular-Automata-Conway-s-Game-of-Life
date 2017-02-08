#include "player.h"



player::player()
{
}

player::player(int x, int y, int l, int w): entity(x, y, l, w)
{
	
}

player::player(int x, int y, int l, int w, Uint32 c) : entity(x, y, l, w, c)
{
}


player::~player()
{
}

void player::moveUp()
{
	setShadow();
	if (this->getY() - this->getLength() < 0)
	{
		return;
	}
	this->setY(this->getY() - this->getLength());
	return;
}

void player::moveDown()
{
	setShadow();
	if (this->getY() + this->getLength() >= 600)
	{
		return;
	}
	this->setY(this->getY() + this->getLength());
	return;
}

void player::moveLeft()
{
	setShadow();
	if (this->getX() - this->getWidth() < 0)
	{
		return;
	}
	this->setX(this->getX() - this->getWidth());
	return;
}

void player::moveRight()
{
	setShadow();
	if (this->getX() + this->getWidth() >= 800)
	{
		return;
	}
	this->setX(this->getX() + this->getWidth());
	return;
}

void player::setShadow()
{
	this->setShadowX(this->getX());
	this->setShadowY(this->getY());
	return;
}
