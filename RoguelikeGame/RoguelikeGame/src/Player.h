#pragma once

#include <SDL\SDL_Image.h>
#include "TextureManager.h"

class Player
{
public:
	Player(SDL_Renderer* renderer);
	~Player();
	enum Direction { DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT };
	void Move(Direction direction);
	void ResetMove(Direction direction);

	void Update();

private:
	const int tilesize = 64;
	bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;

	SDL_Texture* playerTex;
	SDL_Rect destR;
	SDL_Renderer* renderer;

};

