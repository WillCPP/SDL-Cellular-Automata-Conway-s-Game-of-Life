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

bool player::moveUp()
{
	setShadow();
	if (this->getY() - this->getLength() < 0)
	{
		return false;
	}
	this->setY(this->getY() - this->getLength());
	return true;
}

bool player::moveDown()
{
	setShadow();
	if (this->getY() + this->getLength() >= 608)
	{
		return false;
	}
	this->setY(this->getY() + this->getLength());
	return true;
}

bool player::moveLeft()
{
	setShadow();
	if (this->getX() - this->getWidth() < 0)
	{
		return false;
	}
	this->setX(this->getX() - this->getWidth());
	return true;
}

bool player::moveRight()
{
	setShadow();
	if (this->getX() + this->getWidth() >= 800)
	{
		return false;
	}
	this->setX(this->getX() + this->getWidth());
	return true;
}

void player::setShadow()
{
	this->setShadowX(this->getX());
	this->setShadowY(this->getY());
	return;
}
