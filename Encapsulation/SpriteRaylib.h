#pragma once

#include "Sprite.h"
#include "const.h"

class SpriteRaylib : public Sprite
{
public:
	void LoadSprite(const char* path) override;
	void* GetData() override;
	void SetRad() override;

private:
	Texture2D texBall;

};

