#pragma once
#include <SDL.h>
#include "entity.h"
#include "player.h"
#include "CellContainer.h"
class app
{
public:
	app();
	~app();

	void initialize();
	void appLoop();
	void playLoop(CellContainer*);
	void setPixel(SDL_Surface*,int,int,Uint32);
	Uint32 getPixelColor(SDL_Surface*,int,int);
	void draw(entity*);
	void drawShadow(entity*);
	void drawCellVec(CellContainer*);
	void checkDrawPlayer(player*);
	void underColorer(CellContainer*, entity*);

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
};

