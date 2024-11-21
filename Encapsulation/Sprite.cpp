#include "Sprite.h"

void Sprite::LoadSprite(const char* path)
{
}

void* Sprite::GetData()
{
	return 0;
}

void* Sprite::GetSurface()
{
	return 0;
}

void Sprite::SetPosition(int x, int y)
{
	std::cout << x << " ||| " << y << std::endl;

	if (x - ball->rad <= 0) x = ball->rad + 1;
	if (x - ball->rad >= WINDOW_WIDTH) x = WINDOW_WIDTH - 1;

	if (y - ball->rad <= 0) y = ball->rad + 1;
	if (y - ball->rad >= WINDOW_HEIGHT) y = WINDOW_HEIGHT - 1;

	ball->pos = { x - ball->rad, y - ball->rad };
}

void Sprite::SetSpeed(float x, float y)
{
	std::cout << x << " ||| " << y << std::endl;
	ball->speed = { x, y };
}

void Sprite::SetRad()
{
}

void Sprite::Move()
{
	ball->pos = { ball->pos.x + ball->speed.x, ball->pos.y + ball->speed.y };
	CheckColision();
}

void Sprite::CheckColision()
{
	if (((ball->pos.x + 2 * ball->rad) >= WINDOW_WIDTH) || (ball->pos.x <= 0)) ball->speed.x *= -1;
	if (((ball->pos.y + 2 * ball->rad) >= WINDOW_HEIGHT) || (ball->pos.y <= 0)) ball->speed.y *= -1;
}

Ball* Sprite::GetBall()
{
	return ball;
}
