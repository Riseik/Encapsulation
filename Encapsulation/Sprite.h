#pragma once

#include "raylib.h"
#include <iostream>
#include <vector>

typedef struct Ball {
	Vector2 pos;
	Vector2 speed;
	float rad;
};

class Sprite
{
public:
	virtual void LoadSprite();
	virtual void GetData();
	virtual void SetPosition(int x, int y);
	virtual void SetSpeed();
	virtual void SetRad();

	Ball* GetBall();

	Ball* ball;

protected:

private:

};

