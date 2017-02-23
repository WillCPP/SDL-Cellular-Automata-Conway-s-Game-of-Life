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

	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
	void setShadow();

	void setDrawPlayerFlagX(bool flag) { this->drawPlayerFlagX = flag; return; }
	bool getDrawPlayerFlagX() { return drawPlayerFlagX; }

	void setDrawShadowFlagX(bool flag) { this->drawShadowFlagX = flag; return; }
	bool getDrawShadowFlagX() { return drawShadowFlagX; }

	void setDrawPlayerFlagY(bool flag) { this->drawPlayerFlagY = flag; return; }
	bool getDrawPlayerFlagY() { return drawPlayerFlagY; }

	void setDrawShadowFlagY(bool flag) { this->drawShadowFlagY = flag; return; }
	bool getDrawShadowFlagY() { return drawShadowFlagY; }

private:
	bool drawPlayerFlagX;
	bool drawShadowFlagX;
	bool drawPlayerFlagY;
	bool drawShadowFlagY;
};

