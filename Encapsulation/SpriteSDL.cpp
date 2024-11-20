#include "SpriteSDL.h"
#include "WindowSDL.h"

void SpriteSDL::LoadSprite(const char* path)
{
	extern Window* win;
	tmpSurface = IMG_Load(path);
	Img = SDL_CreateTextureFromSurface(((WindowSDL*) win)->getRenderer(), tmpSurface);
}

void* SpriteSDL::GetData()
{
	return Img;
}