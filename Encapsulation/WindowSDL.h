#pragma once
#include "Window.h"
#include "Sprite.h"
#include "SDL2/SDL.h"

class WindowSDL : public Window
{
	void CreateWindow(const char*, int, int) override;
};

