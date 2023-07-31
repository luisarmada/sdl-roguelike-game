#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filepath, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(filepath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return texture;
}
