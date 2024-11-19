#include "WindowRaylib.h"
#include "raylib.h"
#include <iostream>
#include <vector>

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
	ClearBackground(RAYWHITE);
}

void WindowRaylib::DrawSprite(Sprite* s)
{
	if (s == nullptr || s->GetBall() == nullptr) {
		return;
	}
	BeginDrawing();
	DrawTextureEx(texBall, s->GetBall()->pos, 0, scale, MAROON);
	EndDrawing();
}
