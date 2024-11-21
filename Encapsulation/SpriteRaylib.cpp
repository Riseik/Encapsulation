#include "SpriteRaylib.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void SpriteRaylib::LoadSprite(const char* path)
{
	texBall = LoadTexture(path);
}

void* SpriteRaylib::GetData()
{
	return &texBall;
}

void SpriteRaylib::SetRad()
{
	ball->rad = texBall.height * SPRITE_SCALE / 2;
}
