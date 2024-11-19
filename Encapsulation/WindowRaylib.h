#pragma once

#include "Window.h"

class WindowRaylib : public Window
{
public:
	void CreateWindow(const char*, int, int) override;
	bool IsOpen() override;
	void Clear() override;
	void DrawSprite() override;

private:
	float scale = 0.5;
};

