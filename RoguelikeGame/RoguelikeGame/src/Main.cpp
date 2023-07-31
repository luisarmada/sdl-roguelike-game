#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	game->GameLoop();

	return 0;
}