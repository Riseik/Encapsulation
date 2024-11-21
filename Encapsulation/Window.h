#pragma once
#include <string>
#include "const.h"
#include "Sprite.h"

class Window
{
public:
	virtual bool IsOpen() = 0;
	virtual void CreateWindow(const char*, int, int) = 0;
	virtual void Clear() = 0;
	virtual void Draw(std::vector<Sprite*>) = 0;
	virtual Sprite* CreateSprite() = 0;
	virtual void SwitchLanguage();
	virtual bool Event() = 0;
	virtual void DestroyWindow() = 0;
	virtual bool CheckCloseWindow() = 0;

protected:

};

