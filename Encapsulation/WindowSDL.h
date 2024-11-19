#pragma once
#include "Window.h"
#include "Sprite.h"
#include "SDL2/SDL.h"

class WindowSDL : public Window
{
	public :
	void CreateWindow(const char*, int, int) override;
	void Clear() override;
	bool IsOpen() override;
	void DrawSprite() override;

private:
	SDL_Window* window;
	SDL_Surface* winSurface;
};

