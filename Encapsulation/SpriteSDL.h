#pragma once
#include <iostream>
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class SpriteSDL : public Sprite
{
public :
	void LoadSprite(const char* path) override;
	void* GetData() override;

	SDL_Surface* tmpSurface;
	SDL_Rect pos;
	SDL_Texture* Img;
};

