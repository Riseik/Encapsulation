#pragma once
#include <iostream>
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_test_images.h>

class SpriteSDL : public Sprite
{
public :
	void LoadSprite() override;
	SDL_Surface* tmpSurface;
};

