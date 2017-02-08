#include <SDL.h>
#include "app.h"

using namespace std;

int main(int argc, char* args[])
{
	//
	bool done = false;

	app* game = new app;

	game->appLoop();

	delete game;

	return 0;
}