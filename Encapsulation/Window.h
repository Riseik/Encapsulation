#pragma once

class Window
{
public:
	virtual void Init();
	virtual void CreateWindow();
	virtual bool IsOpen();
	virtual void Clear();
	virtual void DrawSprite();

private:

};

