#pragma once
#include "Window.h"
#include "SpriteSDL.h"
#include "SDL2/SDL.h"

class WindowSDL : public Window
{
	public :
	void CreateWindow(const char*, int, int) override;
	void Clear() override;
	bool IsOpen() override;
	void DrawSprite(Sprite* s) override;
	Sprite* CreateSprite() override;

	SDL_Renderer* getRenderer() const { return render; }

private:
	SDL_Window* window;
	SDL_Renderer* render;

	float frameDelay = 1000 / FPS_CAP;
};

