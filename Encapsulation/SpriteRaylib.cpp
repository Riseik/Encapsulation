#include "SpriteRaylib.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void SpriteRaylib::LoadSprite()
{
	texBall = LoadTexture("../SCP.png");
}

void SpriteRaylib::SetRad()
{
	std::cout << texBall.height * scale / 2;
	ball->rad = texBall.height * scale / 2;
	std::cout << ball->rad;
}

void SpriteRaylib::SetPosition(int x, int y)
{
	std::cout << x;
	std::cout << y;
	ball->pos = { x - ball->rad, y - ball->rad };
}
