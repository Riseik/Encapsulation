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

void WindowRaylib::Draw(std::vector<Sprite*> sList)
{
	BeginDrawing();
	std::string fpsText = "FPS Counter : " + std::to_string(GetFPS());
	Vector2 pos = { FPS_TEXT_POSITION_X, FPS_TEXT_POSITION_Y };
	DrawTextEx(font, fpsText.c_str(), pos, FPS_TEXT_SIZE, FPS_TEXT_SPACING, BLUE);
	DrawTextEx(font, "'SPACE' to switch to SDL", SWITCH_TEXT_POSITION, SWITCH_TEXT_SIZE, SWITCH_TEXT_SPACING, BLUE);
	for (Sprite* s : sList) {
   		DrawTextureEx(*((Texture2D*)s->GetData()), s->GetBall()->pos, 0, SPRITE_SCALE, MAROON);
	}
	EndDrawing();
}

bool WindowRaylib::Event()
{
	if (IsKeyPressed(KEY_SPACE)) return true;

	return false;
}

void WindowRaylib::DestroyWindow()
{
	WindowShouldClose();
}

bool WindowRaylib::CheckCloseWindow()
{
	if (IsKeyPressed(KEY_ESCAPE)) {
		CloseWindow();
		return false;
	}
	return true;
}

Sprite* WindowRaylib::CreateSprite()
{
	return new SpriteRaylib;
}
