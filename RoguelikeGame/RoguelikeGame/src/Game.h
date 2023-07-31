#pragma once

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>

#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void Initialise(const char* title, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	void GameLoop();

	bool Running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

