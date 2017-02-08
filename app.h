#pragma once
#include <SDL.h>
#include "entity.h"
#include "CellContainer.h"
class app
{
public:
	app();
	~app();

	void initialize();
	void appLoop();
	void setPixel(SDL_Surface*,int,int,Uint32);
	void draw(entity*);
	void drawShadow(entity*);
	void drawCellVec(CellContainer*);

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
};

