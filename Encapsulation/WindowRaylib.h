#pragma once

#include "Window.h"

class WindowRaylib : public Window
{
public:
	void CreateWindow(const char*, int, int) override;
	bool IsOpen() override;
	void Clear() override;
	void Draw(Sprite* s) override;
	Sprite* CreateSprite() override;
	bool Event() override;
	void DestroyWindow() override;
	bool CheckCloseWindow() override;


private:
	Font font;
	bool open = true;

};

