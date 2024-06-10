#pragma once

#include "Entity.h"

enum class BlockType {LARGE_TRIANGLE = 0, SMALL_CIRCLE, BOX, END};

enum class MaterialType {WOOD = 0, METAL, ICE, ROCK, GEL, END};

class BlockEntity : public Entity
{
public:
	BlockType blockType;
	MaterialType materialType;
	int hp;
	int maxHP;
	std::vector<Sprite *> spriteList;

	BlockEntity()
	{
		typeID = ENTITYBLOCK;
		blockType = BlockType::LARGE_TRIANGLE;
		materialType = MaterialType::WOOD;
		//maxHP = hp = 100;
		hp = 100;
		maxHP = 100;
	}

	//Damage() returns true if we should kill this object
	bool Damage(int damage)
	{
		hp -= damage;
		if (hp < 1) return true;
		if (hp < maxHP/3) sprite = spriteList[1];
		else if (hp < maxHP * 0.66) sprite = spriteList[0];

		return false;
	}
};

BlockEntity * MakeBlock(BlockType btype, MaterialType mtype, b2Vec2 pixelCoords, 
	float angleInDegrees, int maximumHP);

