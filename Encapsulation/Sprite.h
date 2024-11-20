#pragma once

#include "raylib.h"
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
	virtual void LoadSprite(const char* path)=0;
	virtual void* GetData() = 0;
	virtual void SetPosition(int x, int y);
	virtual void SetSpeed(float x, float y);
	virtual void SetRad();
	virtual void Move();
	virtual void CheckColision();

	Ball* GetBall();

	Ball* ball = new Ball;

protected:

private:

};

