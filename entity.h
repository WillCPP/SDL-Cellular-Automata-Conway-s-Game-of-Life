#pragma once
#include <SDL.h>
class entity
{
public:
	entity();
	entity(int,int,int,int);
	entity(int, int, int, int, Uint32);
	virtual ~entity();

	int getX() { return x; }
	int getY() { return y; }

	void setX(int x) { this->x = x; return; }
	void setY(int y) { this->y = y; return; }

	int getShadowX() { return shadow_x; }
	int getShadowY() { return shadow_y; }

	void setShadowX(int x) { this->shadow_x = x; return; }
	void setShadowY(int y) { this->shadow_y = y; return; }

	int getLength() { return length; }
	int getWidth() { return width; }

	void setLength(int length) { this->length = length; return; }
	void setWidth(int width) { this->width = width; return; }

	Uint32 getColor() { return color; }

	void setColor(Uint32 color) { this->color = color; return; }

private:
	int x;
	int y;

	int shadow_x;
	int shadow_y;

	int length;
	int width;

	Uint32 color;
};

