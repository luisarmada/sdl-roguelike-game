#include "Game.h"
#include "TextureManager.h"
#include "Player.h"

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

Player* player;

void Game::Initialise(const char* title, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Successfully Initialised SDL!" << std::endl;

		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 34, 35, 35, 255);

		player = new Player(renderer);

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
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_w: case SDLK_UP:
				player->Move(player->DIR_UP);
				break;
			case SDLK_a: case SDLK_LEFT:
				player->Move(player->DIR_LEFT);
				break;
			case SDLK_s: case SDLK_DOWN:
				player->Move(player->DIR_DOWN);
				break;
			case SDLK_d: case SDLK_RIGHT:
				player->Move(player->DIR_RIGHT);
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
				case SDLK_w: case SDLK_UP:
					player->ResetMove(player->DIR_UP);
					break;
				case SDLK_a: case SDLK_LEFT:
					player->ResetMove(player->DIR_LEFT);
					break;
				case SDLK_s: case SDLK_DOWN:
					player->ResetMove(player->DIR_DOWN);
					break;
				case SDLK_d: case SDLK_RIGHT:
					player->ResetMove(player->DIR_RIGHT);
					break;
			}
			break;
		default:

			break;
		}
	}

	
}

void Game::Update()
{
	
}

void Game::Render()
{
	SDL_RenderClear(renderer);

	// Add Stuff to Render
	player->Update();

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
	Initialise("My Roguelike", false);

	while (Running())
	{
		HandleEvents();
		Update();
		Render();
	}

	Clean();
}
