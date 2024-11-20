#include "SpriteRaylib.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void SpriteRaylib::LoadSprite(const char* path)
{
	texBall = LoadTexture(path);

	Color = { (float)GetRandomValue(0, 255), (float)GetRandomValue(0, 255), (float)GetRandomValue(0, 255), 255 };
}

void* SpriteRaylib::GetData()
{
	return &texBall;
}

Vector4* SpriteRaylib::GetColor()
{
	return &Color;
}

void SpriteRaylib::SetRad()
{
	ball->rad = texBall.height * SPRITE_SCALE / 2;
}

void SpriteRaylib::SetPosition(int x, int y)
{
	if (x - ball->rad <= 0) x = ball->rad + 1;
	if (x - ball->rad >= WINDOW_WIDTH) x = WINDOW_WIDTH - 1;

	if (y - ball->rad <= 0) y = ball->rad + 1;
	if (y - ball->rad >= WINDOW_HEIGHT) y = WINDOW_HEIGHT - 1;

	ball->pos = { x - ball->rad, y - ball->rad };
}

void SpriteRaylib::SetSpeed(float x, float y)
{
	ball->speed = { x, y };
}

void SpriteRaylib::Move()
{
	std::cout << Color.x << " ||| " << Color.y << " ||| " << Color.z << " ||| " << Color.w << std::endl;
	ball->pos = { ball->pos.x + ball->speed.x, ball->pos.y + ball->speed.y };
	CheckColision();
}

void SpriteRaylib::CheckColision()
{
	if (((ball->pos.x + 2 * ball->rad) >= WINDOW_WIDTH) || (ball->pos.x <= 0)) {
		Color = { (float)GetRandomValue(0, 255), (float)GetRandomValue(0, 255), (float)GetRandomValue(0, 255), 255 };
		ball->speed.x *= -1;
	}

	if (((ball->pos.y + 2 * ball->rad) >= WINDOW_HEIGHT) || (ball->pos.y <= 0)) {
		Color = { (float)GetRandomValue(0, 255), (float)GetRandomValue(0, 255), (float)GetRandomValue(0, 255), 255 };
		ball->speed.y *= -1;
	}
}
