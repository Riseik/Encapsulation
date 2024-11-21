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
	Uint32 frameStart = SDL_GetTicks();
	const SDL_Rect a = { s->GetBall()->pos.x, s->GetBall()->pos.y, ((SDL_Surface*)s->GetSurface())->h * SPRITE_SCALE, ((SDL_Surface*)s->GetSurface())->w * SPRITE_SCALE};

	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_RenderCopy(render, (SDL_Texture*)s->GetData(), NULL, &a);
	SDL_RenderPresent(render);
	int frameTime = SDL_GetTicks() - frameStart;

	if (frameDelay > frameTime) {
		SDL_Delay(frameDelay - frameTime);
		std::cout << FPS_CAP << std::endl;
	}
	else {
		std::cout << 1000 / frameTime << std::endl;
	}
}

Sprite* WindowSDL::CreateSprite()
{

	return new SpriteSDL;
}





