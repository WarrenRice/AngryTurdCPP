#pragma once

#include "Blit3D.h"
#include "Physics.h"

class Cannon
{
public:
	b2Vec2 positionPixels;
	float angle;
	Sprite *sprite;
	float rotateDir;

	Cannon() 
	{
		positionPixels = b2Vec2(0, 0);
		angle = 0;
		sprite = NULL;
		rotateDir = 0;
	}

	void Draw()
	{
		sprite->angle = angle;
		sprite->Blit(positionPixels.x, positionPixels.y);
	}

	void Update(float seconds)
	{
		angle += rotateDir * seconds * 20;

		if (angle < -10) angle = -10;
		if (angle > 90) angle = 90;
	}
};