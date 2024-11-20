#pragma once

#include "Sprite.h"
#include "const.h"

class SpriteRaylib : public Sprite
{
public:
	void LoadSprite(std::string path) override;
	void* GetData() override;
	void SetRad() override;
	void SetPosition(int x, int y) override;
	void SetSpeed(float x, float y) override;
	void Move() override;
	void CheckColision() override;
	

private:
	Texture2D texBall;

};

