#pragma once

#include "Sprite.h"

class SpriteRaylib : public Sprite
{
public:
	void LoadSprite() override;
	void SetRad() override;
	void SetPosition(int x, int y) override;
	

private:
	Texture2D texBall;
	float scale = 0.02;

};

