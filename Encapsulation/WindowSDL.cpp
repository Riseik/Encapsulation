#include "WindowSDL.h"

void WindowSDL::CreateWindow(const char* name, int height, int width)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_SHOWN);
	winSurface = SDL_GetWindowSurface(window);
	sprite.LoadSprite();
}

void WindowSDL::Clear()
{
	SDL_UpdateWindowSurface(window);
}

bool WindowSDL::IsOpen()
{
	return window;
}

void WindowSDL::DrawSprite(Sprite* s)
{
	SDL_BlitSurface(sprite.tmpSurface, NULL, winSurface, NULL);
	//const SDL_Rect a = { 50, 50, 100, 100 };
	//SDL_FillRect(sprite.tmpSurface, &a, SDL_MapRGB(winSurface->format, 255, 255, 255));
}





