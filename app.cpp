#include "app.h"
#include <SDL.h>
#include "entity.h"
#include "player.h"
#include <windows.h>
using namespace std;

app::app()
{
	this->initialize();
}

app::~app()
{
	SDL_DestroyWindow(window);
}

void app::initialize()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL Sandbox",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 608, 0);

	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
}

void app::appLoop()
{
	bool done = false;
	bool moving = false;
	SDL_Event e;

	CellContainer* cells = new CellContainer;
	this->drawCellVec(cells);

	player* player_one = new player(0, 0, 16, 16, 0xFFFF0000);
	this->draw(player_one);
	underColorer(cells, player_one);

	while (!done) //switch to do while
	{
		player_one->setDrawPlayerFlagX(false);
		player_one->setDrawShadowFlagX(false);
		player_one->setDrawPlayerFlagY(false);
		player_one->setDrawShadowFlagY(false);
		moving = false;
		//add initial draw here
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				done = true;
			}
			//put switch in an if (playing)
			//handle keypress events
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					moving = player_one->moveUp();
					break;
				case SDLK_DOWN:
					moving = player_one->moveDown();
					break;
				case SDLK_LEFT:
					moving = player_one->moveLeft();
					break;
				case SDLK_RIGHT:
					moving = player_one->moveRight();
					break;
				case SDLK_RETURN:
					moving = false;
					cells->setCellPop(player_one);
					break;
				case SDLK_q:
					done = true;
					break;
				default:
					moving = false;
					break;
				}

				//check player draw
				checkDrawPlayer(player_one);

				if ((player_one->getDrawPlayerFlagX() == true && player_one->getDrawPlayerFlagY()) && moving)
				{
					this->draw(player_one);
				}
				if ((player_one->getDrawShadowFlagX() == true && player_one->getDrawShadowFlagY() == true) && moving)
				{	
					this->drawShadow(player_one);
				}
				underColorer(cells, player_one);
			}
		}
	}
	playLoop(cells);
	delete player_one;
}

void app::playLoop(CellContainer* cells)
{
	bool done = false;
	SDL_Event e;
	while (!done)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				done = true;
			}
		}
		cells->setVecColor();
		drawCellVec(cells);
		SDL_UpdateWindowSurface(this->window);
		cells->checkNeighbors();
		Sleep(200);
	}
}

void app::setPixel(SDL_Surface* surface,int x,int y, Uint32 color)
{
	Uint8 *pixel = (Uint8*)surface->pixels;
	pixel += (y * surface->pitch) + (x * sizeof(Uint32));
	*((Uint32*)pixel) = color;
}

Uint32 app::getPixelColor(SDL_Surface *, int x, int y)
{
	Uint32* pixels = (Uint32*)this->screenSurface->pixels;
	return pixels[(y*this->screenSurface->w) + x];
}

void app::draw(entity* ent)
{
	int length, width, x, y;

	//get position and dimensions
	length = ent->getLength();
	width = ent->getWidth();
	x = ent->getX();
	y = ent->getY();

	//loop
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			this->setPixel(this->screenSurface, (x + j), (y + i), ent->getColor());
		}
	}

	SDL_UpdateWindowSurface(this->window); //remove this for when there are multiple entities being drawn so that everytime there is a draw call you are not updating every single time, update surface after all entites have been altered
}

void app::drawShadow(entity* ent)
{
	int length, width, x, y;

	//get position and dimensions
	length = ent->getLength();
	width = ent->getWidth();
	x = ent->getShadowX();
	y = ent->getShadowY();

	//loop
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			this->setPixel(this->screenSurface, (x + j), (y + i), ent->getUnderColor());
		}
	}

	SDL_UpdateWindowSurface(this->window); //remove this for when there are multiple entities being drawn so that everytime there is a draw call you are not updating every single time, update surface after all entites have been altered
}

void app::drawCellVec(CellContainer* vec)
{
	int length, width, x, y;
	Uint32 c;

	for (cell ent : vec->cell_vec)
	{
		length = ent.getLength();
		width = ent.getWidth();
		x = ent.getX();
		y = ent.getY();
		c = ent.getColor();

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				this->setPixel(this->screenSurface, (x + j), (y + i), c);
			}
		}
	}
	SDL_UpdateWindowSurface(this->window);
}

void app::checkDrawPlayer(player *ent)
{
	//up and down // works
	if (ent->getY() >= 0 && ent->getY() <= 608) { ent->setDrawPlayerFlagY(true); ent->setDrawShadowFlagY(true); }
	else { ent->setDrawPlayerFlagY(false); ent->setDrawShadowFlagY(false); }

	//left and right // works
	if (ent->getX() >= 0 && ent->getX() <= 800) { ent->setDrawPlayerFlagX(true); ent->setDrawShadowFlagX(true); }
	else { ent->setDrawPlayerFlagX(false); ent->setDrawShadowFlagX(false); }

	if (ent->getX() == ent->getShadowX() && ent->getY() == ent->getShadowY()) 
	{
		ent->setDrawPlayerFlagX(false); 
		ent->setDrawShadowFlagX(false); 
		ent->setDrawPlayerFlagY(false); 
		ent->setDrawShadowFlagY(false); 
	}

	return;
}

void app::underColorer(CellContainer* cells, entity* player_one)
{
	if (cells->cell_vec[(player_one->getY() / 16) * 50 + (player_one->getX() / 16)].getPop() == true) { player_one->setUnderColor(0xFF000000); }
	else { player_one->setUnderColor(0xFFFFFFFF); }
}
