#pragma once
#include "Window.h"
#include "SpriteSDL.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class WindowSDL : public Window
{
	public :
	void CreateWindow(const char*, int, int) override;
	void Clear() override;
	bool IsOpen() override;
	void Draw(Sprite* s) override;
	bool Event() override;
	void DestroyWindow() override;

	void InitVariable();
	void DisplayText(const char*);
	int CalculFps(Uint32);


	Sprite* CreateSprite() override;
	SDL_Renderer* getRenderer() const { return render; }
	float frameDelay = 1000 / FPS_CAP;

private:
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;

	TTF_Font* font;
	SDL_Color fontColor = { 0, 121, 241, 255 };
	std::string fps;

	SDL_Rect spritePos;
	SDL_Rect fpsPos;
	SDL_Rect textPos;
	Uint32 frameStart;
	SDL_Event event;
};

