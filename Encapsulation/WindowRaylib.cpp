#include "WindowRaylib.h"
#include "SpriteRaylib.h"
#include "raylib.h"
#include <iostream>
#include <vector>
#include "const.h"

void WindowRaylib::CreateWindow(const char* name, int height, int width)
{
	InitWindow(width, height, name);

	font = LoadFont(FONT_PATH);

	int frameCounter = 0;
	SetTargetFPS(FPS_CAP);
}

bool WindowRaylib::IsOpen()
{
	return !WindowShouldClose();
}

void WindowRaylib::Clear()
{
	ClearBackground(GRAY);
}

void WindowRaylib::Draw(Sprite* s)
{
	BeginDrawing();
	std::string fpsText = "FPS Counter : " + std::to_string(GetFPS());
	DrawTextEx(font, fpsText.c_str(), FPS_TEXT_POSITION, FPS_TEXT_SIZE, FPS_TEXT_SPACING, MAROON);
	DrawTextureEx(*((Texture2D*)s->GetData()), s->GetBall()->pos, 0, SPRITE_SCALE, MAROON);
	EndDrawing();
}

Sprite* WindowRaylib::CreateSprite()
{
	return new SpriteRaylib;
}
