#pragma once

#include "raylib.h"
#include "const.h"
#include <iostream>
#include <vector>

struct Ball {
	Vector2 pos;
	Vector2 speed;
	float rad;
};

class Sprite
{
public:
	virtual void LoadSprite(const char* path) = 0;
	virtual void* GetData() = 0;
	virtual void* GetSurface();
	virtual void SetRad();

	void SetPosition(int x, int y);
	void SetSpeed(float x, float y);
	void Move();
	void CheckColision();

	Ball* GetBall();

	Ball* ball = new Ball;

protected:

private:

};

