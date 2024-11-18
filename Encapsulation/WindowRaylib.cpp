#include "WindowRaylib.h"
#include "raylib.h"
#include <iostream>

void WindowRaylib::CreateWindow(const char* name, int height, int width)
{
	InitWindow(width, height, name);

	int frameCounter = 0;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		
	}

	CloseWindow();
}
