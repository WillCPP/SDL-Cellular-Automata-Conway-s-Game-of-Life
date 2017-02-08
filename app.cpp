#include "app.h"
#include <SDL.h>
#include "entity.h"
#include "player.h"
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
	bool draw_shadow = false;
	SDL_Event e;
	
	//test entity and drawing
	//entity* bob = new entity(100,100,16,16);
	//this->draw(bob);

	//test cellContainer and cell
	CellContainer* cells = new CellContainer;
	this->drawCellVec(cells);

	//test player drawing
	player* player_one = new player(0, 0, 16, 16);
	this->draw(player_one);

	while (!done) //switch to do while
	{
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
					player_one->moveUp();
					if (player_one->getY() - player_one->getLength() < 0) { draw_shadow = true; } //problem with shadow
					else { draw_shadow == false; }
					break;
				case SDLK_DOWN:
					player_one->moveDown();
					if (player_one->getY() + player_one->getLength() >= 608) { draw_shadow = true; }
					else { draw_shadow == false; }
					break;
				case SDLK_LEFT:
					player_one->moveLeft();
					if (player_one->getX() - player_one->getWidth() < 0) { draw_shadow = true; }
					else { draw_shadow == false; }
					break;
				case SDLK_RIGHT:
					player_one->moveRight();
					if (player_one->getX() + player_one->getWidth() >= 800) { draw_shadow = true; }
					else { draw_shadow == false; }
					break;
				default:
					break;
				}
			}
		}
		this->draw(player_one);
		if (draw_shadow == true)
		{
			this->drawShadow(player_one); // this is broken
		}
	}
	delete player_one;
}

void app::setPixel(SDL_Surface* surface,int x,int y, Uint32 color)
{
	Uint8 *pixel = (Uint8*)surface->pixels;
	pixel += (y * surface->pitch) + (x * sizeof(Uint32));
	*((Uint32*)pixel) = color;
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
			this->setPixel(this->screenSurface, (x + j), (y + i), 0xFF000000);
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
			this->setPixel(this->screenSurface, (x + j), (y + i), 0xFFFFFFFF);
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

		SDL_UpdateWindowSurface(this->window);
	}
}
