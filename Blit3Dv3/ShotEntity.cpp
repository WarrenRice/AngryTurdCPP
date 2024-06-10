#include "ShotEntity.h"
#include "Blit3D.h"
#include "CollisionMask.h"

extern Blit3D *blit3D;
extern b2World *world;
extern Sprite *cannonballSprite;

ShotEntity * MakeShot()
{
	//make a shot entity
	ShotEntity *shotEntity = new ShotEntity();

	// Define the Shot body. 
	//We set its position and call the body factory.
	b2BodyDef ShotBodyDef;
	ShotBodyDef.bullet = true; //shots move fast: make sure Continuos Collision Detection (CCD) is on
	ShotBodyDef.type = b2_dynamicBody; //make it a dynamic body i.e. one moved by physics
	ShotBodyDef.position.Set(0.0f, 0.0f); //set its position in the world

	//friction won't work on a rolling circle in Box2D, so apply angular damping to the body
	//to make it slow down as it rolls
	ShotBodyDef.angularDamping = 1.8f;

	//make the userdata point back to this entity
	ShotBodyDef.userData.pointer = reinterpret_cast<uintptr_t>(shotEntity);

	shotEntity->body = world->CreateBody(&ShotBodyDef); //create the body and add it to the world

	// Define a shot shape for our body.
	//A circle shape for our shot
	b2CircleShape dynamicShot;
	dynamicShot.m_radius = 36.f / (2 * PTM_RATIO); //shot has diameter of 9 pixels

	//create the fixture definition - we don't need to save this
	b2FixtureDef fixtureDef;

	//collison masking
	fixtureDef.filter.categoryBits = CMASK_SHOT;  //this is a shot
	fixtureDef.filter.maskBits = CMASK_SHOT | CMASK_EDGES | CMASK_BLOCK | CMASK_GROUND | CMASK_ALIEN;//it collides wth lotsa stuff

	// Define the dynamic body fixture.
	fixtureDef.shape = &dynamicShot;

	// Set the shot density to be non-zero, so it will be dynamic.
	//Remember, density * area determines the mass of the object
	fixtureDef.density = 2.0f;

	// Override the default friction.
	fixtureDef.friction = 0.4f;

	//restitution makes us bounce; use 0 for no bounce, 1 for perfect bounce
	fixtureDef.restitution = 0.2f;

	// Add the shape to the body. 
	shotEntity->body->CreateFixture(&fixtureDef);

	//add a sprite to the shot entity
	shotEntity->sprite = cannonballSprite;	

	return shotEntity;
}