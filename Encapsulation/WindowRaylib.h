#pragma once

#include "Window.h"

class WindowRaylib : public Window
{
public:
	void CreateWindow(const char*, int, int) override;
	bool IsOpen() override;
	void Clear() override;
	void DrawSprite(Sprite* s) override;
	Sprite* CreateSprite() override;

private:

};

