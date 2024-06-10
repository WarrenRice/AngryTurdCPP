#pragma once

#include "Entity.h"

class AlienEntity : public Entity
{
public:
	int hp;
	int maxHP;
	std::vector<Sprite *> spriteList;

	AlienEntity()
	{
		typeID = ENTITYALIEN;
		hp = 127;
		maxHP = 127;
	}

	//Damage() returns true if we should kill this object
	bool Damage(int damage)
	{
		hp -= damage;
		if (hp < 1) return true;
		if (hp < maxHP / 3) sprite = spriteList[1];
		else if (hp < maxHP * 0.66) sprite = spriteList[0];

		return false;
	}
};

AlienEntity* MakeAlien(b2Vec2 pixelCoords, float angleInDegrees, int maximumHP);

