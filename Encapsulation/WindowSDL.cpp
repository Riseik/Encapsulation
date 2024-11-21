#include "WindowSDL.h"

void WindowSDL::CreateWindow(const char* name, int height, int width)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Init();
}

void WindowSDL::Clear()
{
	SDL_UpdateWindowSurface(window);
}

bool WindowSDL::IsOpen()
{
	return window;
}

void WindowSDL::Draw(Sprite* s)
{
	Uint32 frameStart = SDL_GetTicks();
	const SDL_Rect a = { s->GetBall()->pos.x, s->GetBall()->pos.y, ((SDL_Surface*)s->GetSurface())->h * SPRITE_SCALE, ((SDL_Surface*)s->GetSurface())->w * SPRITE_SCALE};
	const SDL_Rect textPos = {FPS_TEXT_POSITION_X, FPS_TEXT_POSITION_Y, FPS_TEXT_SIZE, FPS_TEXT_SIZE };


	SDL_SetRenderDrawColor(render, 255, 255, 0, 255);
	SDL_RenderClear(render);

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	std::string fps = std::to_string(CalculFps(frameStart));
	DisplayText(("fps : " + fps).c_str());
	SDL_RenderCopy(render, (SDL_Texture*)s->GetData(), NULL, &a);
	SDL_RenderCopy(render, textTexture, NULL, &textPos);
	SDL_RenderPresent(render);
}

int WindowSDL::CalculFps(Uint32 Start)
{
	int frameTime = SDL_GetTicks() - Start;
	if (Start > frameTime) {
		SDL_Delay(frameDelay - frameTime);
		return FPS_CAP;
	}
	else {
		return 1000 / frameTime;
	}
}

void WindowSDL::DisplayText(const char* text)
{
	font = TTF_OpenFont("../Daydream.ttf", 24);
	textSurface = TTF_RenderText_Solid(font, text, fontColor);
	textTexture = SDL_CreateTextureFromSurface(render, textSurface);
}

Sprite* WindowSDL::CreateSprite()
{

	return new SpriteSDL;
}





