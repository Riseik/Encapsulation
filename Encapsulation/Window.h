#pragma once
#include <string>
#include "Sprite.h"

class Window
{
public:
	virtual void Init() = 0;
	virtual bool IsOpen() = 0;
	virtual void CreateWindow(const char*, int, int) = 0;
	virtual void Clear() = 0;
	virtual void DrawSprite(Sprite* s) = 0;
	virtual Sprite* CreateSprite() = 0;

private:

};

