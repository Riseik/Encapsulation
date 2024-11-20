#include "WindowRaylib.h"
#include "raylib.h"
#include <iostream>
#include <vector>
#include "const.h"

void WindowRaylib::CreateWindow(const char* name, int height, int width)
{
	InitWindow(width, height, name);

	int frameCounter = 0;
	SetTargetFPS(60);

	texBall = LoadTexture("../SCP.png");
}

bool WindowRaylib::IsOpen()
{
	return !WindowShouldClose();
}

void WindowRaylib::Clear()
{
	ClearBackground(GRAY);
}

void WindowRaylib::DrawSprite(Sprite* s)
{
	BeginDrawing();
	DrawTextureEx(texBall, s->GetBall()->pos, 0, SPRITE_SCALE, MAROON);
	EndDrawing();
}
