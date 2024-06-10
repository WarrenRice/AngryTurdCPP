#pragma once

#include "Entity.h"

class ShotEntity : public Entity
{
public:
	ShotEntity()
	{
		typeID = ENTITYSHOT;
	}
};

ShotEntity * MakeShot();