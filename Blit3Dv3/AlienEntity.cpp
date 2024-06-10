#include "AlienEntity.h"

extern b2World* world;
extern std::vector<Sprite*> alienSprites;

AlienEntity* MakeAlien(b2Vec2 pixelCoords, float angleInDegrees, int maximumHP) {

	AlienEntity* alienEntity = new AlienEntity();

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody; //make it a dynamic body i.e. one moved by physics
	bodyDef.position = Pixels2Physics(pixelCoords); //set its position in the world
	bodyDef.angle = deg2rad(angleInDegrees);

	bodyDef.userData.pointer = reinterpret_cast<uintptr_t> (alienEntity);

	alienEntity->body = world->CreateBody(&bodyDef); //create the body and add it to the world

	b2FixtureDef fixtureDef;
	b2CircleShape circle;

	circle.m_radius = 70.f / (2 * PTM_RATIO);
	fixtureDef.shape = &circle;
	fixtureDef.density = 0.8f;
	fixtureDef.restitution = 0.05;
	fixtureDef.friction = 0.8;

	alienEntity->body->CreateFixture(&fixtureDef);
	
	alienEntity->sprite = alienSprites[0];
	alienEntity->spriteList.push_back(alienSprites[1]);
	alienEntity->spriteList.push_back(alienSprites[2]);

	alienEntity->maxHP = maximumHP;
	alienEntity->hp = maximumHP;

	return alienEntity;
}