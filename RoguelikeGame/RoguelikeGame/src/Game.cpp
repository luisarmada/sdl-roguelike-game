#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

Game::Game()
{
	isRunning = false;
	window = nullptr;
	renderer = nullptr;
}

Game::~Game()
{
	Clean();
}

void Game::Initialise(const char* title, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Successfully Initialised SDL!" << std::endl;

		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 34, 35, 35, 255);

		SDL_Surface* tmpSurface = IMG_Load("sprites/player_sprite.png");
		playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);

		isRunning = true;
	}
	else
	{
		std::cout << "Failed SDL Initialise!" << std::endl;
		isRunning = false;
	}


}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:

			break;
	}
}

void Game::Update()
{
	destR.h = 64;
	destR.w = 64;
}

void Game::Render()
{
	SDL_RenderClear(renderer);

	// Add Stuff to Render
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);

	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

void Game::GameLoop()
{
	Initialise("My Roguelike", 1600, 900, false);

	while (Running())
	{
		HandleEvents();
		Update();
		Render();
	}

	Clean();
}
