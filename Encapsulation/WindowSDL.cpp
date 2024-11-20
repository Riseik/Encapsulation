#include "WindowSDL.h"

void WindowSDL::CreateWindow(const char* name, int height, int width)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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
	const SDL_Rect a = { 0, 0, 100, 100 };

	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_RenderCopy(render, (SDL_Texture*)s->GetData(), NULL, &a);
	SDL_RenderPresent(render);

}

Sprite* WindowSDL::CreateSprite()
{

	return new SpriteSDL;
}





