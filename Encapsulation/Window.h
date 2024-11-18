#pragma once
#include <string>

class Window
{
public:
	virtual void Init();
	virtual bool IsOpen();
	virtual void CreateWindow(const char*, int, int);
	virtual void Clear();
	virtual void DrawSprite();

private:

};

