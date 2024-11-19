#pragma once
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_test_images.h>

class SpriteSDL : public Sprite
{
	void LoadSprite() override;
	SDL_Surface* tmpSurface;
};

