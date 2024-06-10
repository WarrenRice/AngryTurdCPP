#pragma once

#include "Blit3D.h"
#include "Physics.h"

class Meter
{
public:
	b2Vec2 positionPixels;	
	Sprite *sprite;
	float scale;
	int dir;
	bool shooting;

	Meter()
	{
		positionPixels = b2Vec2(0, 0);
		scale = 1;
		sprite = NULL;
		dir = -1;
		shooting = false;
	}

	void Draw()
	{
		sprite->Blit(positionPixels.x, positionPixels.y,scale, scale);
	}

	void Update(float seconds)
	{
		if (shooting)
		{
			scale += seconds * dir;

			if (scale < 0.1f)
			{
				scale = 0.1f;
				dir = 1;
			}
			else if (scale > 1.f)
			{
				scale = 1.f;
				dir = -1;
			}
		}
	}
};