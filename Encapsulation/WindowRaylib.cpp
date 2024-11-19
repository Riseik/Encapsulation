#include "WindowRaylib.h"
#include "raylib.h"
#include <iostream>
#include <vector>

typedef struct Ball {
	Vector2 pos;
	float rad;
	Vector2 speed;
};

void WindowRaylib::CreateWindow(const char* name, int height, int width)
{
	InitWindow(width, height, name);

	int frameCounter = 0;
	SetTargetFPS(60);
}

bool WindowRaylib::IsOpen()
{
	return !WindowShouldClose();
}

void WindowRaylib::Clear()
{
	ClearBackground(RAYWHITE);
}

void WindowRaylib::DrawSprite()
{
	Texture2D texBall;
	texBall = LoadTexture("../SCP.png");

	Ball ball;
	ball.rad = texBall.height * scale / 2;
	ball.pos = { 0 - ball.rad, 0 - ball.rad };
	ball.speed = { 0, 0 };

	BeginDrawing();
	DrawTextureEx(texBall, ball.pos, 0, scale, MAROON);
	EndDrawing();
}
