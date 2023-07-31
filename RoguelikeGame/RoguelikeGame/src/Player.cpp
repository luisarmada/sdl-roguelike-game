#include "Player.h"

Player::Player(SDL_Renderer* ren)
{
	renderer = ren;
	playerTex = TextureManager::LoadTexture("sprites/player_sprite.png", renderer);
	destR = { 0, 0, tilesize, tilesize };
	canMoveUp = true;
	canMoveDown = true;
	canMoveLeft = true;
	canMoveRight = true;
}

Player::~Player()
{
}

void Player::Move(Direction direction)
{
	switch (direction)
	{
		case DIR_UP:
			if (canMoveUp && destR.y - tilesize >= 0)
			{
				destR.y -= tilesize;
				canMoveUp = false;
			}
			
			break;
		case DIR_LEFT:
			if (canMoveLeft && destR.x - tilesize >= 0)
			{
				destR.x -= tilesize;
				canMoveLeft = false;
			}
			break;
		case DIR_DOWN:
			if (canMoveDown && destR.y + (2 * tilesize) <= Game::screenHeight)
			{
				destR.y += tilesize;
				canMoveDown = false;
			}
			break;
		case DIR_RIGHT:
			if (canMoveRight && destR.x + (2*tilesize) <= Game::screenWidth)
			{
				destR.x += tilesize;
				canMoveRight = false;
			}
			break;
	}
}

void Player::ResetMove(Direction direction)
{
	switch (direction)
	{
		case DIR_UP:
			canMoveUp = true;
			break;
		case DIR_LEFT:
			canMoveLeft = true;
			break;
		case DIR_DOWN:
			canMoveDown = true;
			break;
		case DIR_RIGHT:
			canMoveRight = true;
			break;
	}
}


void Player::Update()
{
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);

}
